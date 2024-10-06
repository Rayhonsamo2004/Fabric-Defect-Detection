#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "env.h"
#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi credentials
const char WIFI_SSID[] = "Jaison";
const char WIFI_PASSWORD[] = "comrade131";

// Device name from AWS
const char THINGNAME[] = "ESP8266";

// MQTT broker host address from AWS
const char MQTT_HOST[] = "a3h02dnb8fgs3a-ats.iot.ap-southeast-2.amazonaws.com";  // settings ->endpoint available

// MQTT topics
const char AWS_IOT_PUBLISH_TOPIC[] = "esp8266/pub";  //publish sensor data to iot core
const char AWS_IOT_SUBSCRIBE_TOPIC[] = "esp8266/sub";  // send iot core msg to serial monitor

// Publishing interval
const long interval = 5000;

// Timezone offset from UTC
const int8_t TIME_ZONE = -5;

// Last time message was sent
unsigned long lastMillis = 0;

// WiFiClientSecure object for secure communication
WiFiClientSecure net;

// X.509 certificate for the CA
BearSSL::X509List cert(cacert);

// X.509 certificate for the client
BearSSL::X509List client_crt(client_cert);

// RSA private key
BearSSL::PrivateKey key(privkey);

// MQTT client instance
PubSubClient client(net);

// DHT sensor pin and object
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Gas sensor pin
#define GAS_PIN A0

// OLED display object
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Function to connect to NTP server and set time
void NTPConnect() {
  // Set time using SNTP
  Serial.print("Setting time using SNTP");
  configTime(TIME_ZONE * 3600, 0, "pool.ntp.org", "time.nist.gov");
  time_t now = time(nullptr);
  while (now < 1510592825) { // January 13, 2018
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("done!");
}

// Callback function for message reception
void messageReceived(char *topic, byte *payload, unsigned int length) {
  Serial.print("Received [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

// Function to connect to AWS IoT Core
void connectAWS() {
  delay(3000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println(String("Attempting to connect to SSID: ") + String(WIFI_SSID));

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  // Connect to NTP server to set time
  NTPConnect();

  // Set CA and client certificate for secure communication
  net.setTrustAnchors(&cert);
  net.setClientRSACert(&client_crt, &key);

  // Connect MQTT client to AWS IoT Core
  client.setServer(MQTT_HOST, 8883);
  client.setCallback(messageReceived);

  Serial.println("Connecting to AWS IoT");

  // Attempt to connect to AWS IoT Core
  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(1000);
  }

  // Check if connection is successful
  if (!client.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }

  // Subscribe to MQTT topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
  Serial.println("AWS IoT Connected!");
}

// Function to publish message to AWS IoT Core
void publishMessage() {
  // Read sensor values
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  float gasValue = analogRead(GAS_PIN); // Convert ADC reading to voltage
  // Map the voltage to a meaningful gas concentration range
  float gasConcentration = gasValue;

  // Display sensor readings on the OLED display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Humidity: ");
  display.println(h);
  display.print("Temperature: ");
  display.println(t);
  display.print("Gas Concentration: ");
  display.println(gasConcentration);
  display.display(); // Update the display with new values

  // Print sensor readings to Serial monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C  Gas Concentration: ");
  Serial.println(gasConcentration);

  // Create JSON document for message
  StaticJsonDocument<200> doc;
  doc["time"] = millis();
  doc["humidity"] = h;
  doc["temperature"] = t;
  doc["gas_concentration"] = gasConcentration;

  // Serialize JSON document to string
  char jsonBuffer[200];
  serializeJson(doc, jsonBuffer);

  // Publish message to MQTT topic
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.display(); // Show initial display
  
  // Connect to AWS IoT Core
  connectAWS();
}

void loop() {
  // Check if it's time to publish a message
  if (millis() - lastMillis > interval) {
    lastMillis = millis();
    if (client.connected()) {
      // Publish message
      publishMessage();
    }
  }
  // Maintain MQTT connection
  client.loop();
}