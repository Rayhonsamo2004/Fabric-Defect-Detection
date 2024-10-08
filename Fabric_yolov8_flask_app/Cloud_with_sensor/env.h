
//Amazon trust services endpoint
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

//Device certificate
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAOn2fycslBv4soBs+hBaIMzY7UR4MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDA1MTUwNjM2
MjdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDT2cChHeevBYl+rCf0
UzadhusoH343VCnbhE0kNXeMHif2pHpzrYSjXeenAmvyoDFZKsV471rhKvL8Wp9H
bWabKkDTgL1DCTvHVekD0900KzbCbF6Vncg8tx4a2oPjR2VtR1CseodtxZJev+fT
7kx6ueClUYejQ2omI0+pWRYoKxrvV7XULgEqu+2zhzE9VIsvZ+cS2jC0FOmj2zk5
L//nkJkGQCc9tZq26ZlzNSxka4piQD1YcpCZoc901OXJj7TWoOXgYLp1MBfzGOuG
MAQnt21oO5TO3gpxe+kuXnQ8m4AYfQ+FSj6TqHLGPpV+WzG2MsuagZxaNik3+3wk
2k31AgMBAAGjYDBeMB8GA1UdIwQYMBaAFPIIh0EghPjNzwxSZgm7L9LwSwnTMB0G
A1UdDgQWBBTmtjTL0ar+lUGS9NO9zL58gemr2jAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAAiRyURb60wAHIH62YQpqQPkp
8432b0khDhn0Z2i6+CT4PSebJr7Rw/EEI3XiTEvdyPf6W5OHliBnr8Naa0ODqJUB
51G0KxmzowyvNaSA0T3gfKs8qgh28kXYrjvdCJjKOA/+52xaTgU1ofEMo8I8Nruz
4hu0SYxw5tQt64IXPMe44we9rTwkTPisLIy5VQ+ngYsJP49D7arTAl4q66z+mXEv
2wOkpxynsee5OzqHFBc+fHilDOjv9RR1JQwabwJAlcwVi0k45tUBCHjh7XlYMxgU
nI/6xh9Kqo10nTr2FiT4tcoFsGDLz3dT3bA2ORfKAb0Rurt5aVXLLi93+eEviQ==
-----END CERTIFICATE-----
)KEY";


//Private key file
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEA09nAoR3nrwWJfqwn9FM2nYbrKB9+N1Qp24RNJDV3jB4n9qR6
c62Eo13npwJr8qAxWSrFeO9a4Sry/FqfR21mmypA04C9Qwk7x1XpA9PdNCs2wmxe
lZ3IPLceGtqD40dlbUdQrHqHbcWSXr/n0+5MerngpVGHo0NqJiNPqVkWKCsa71e1
1C4BKrvts4cxPVSLL2fnEtowtBTpo9s5OS//55CZBkAnPbWatumZczUsZGuKYkA9
WHKQmaHPdNTlyY+01qDl4GC6dTAX8xjrhjAEJ7dtaDuUzt4KcXvpLl50PJuAGH0P
hUo+k6hyxj6VflsxtjLLmoGcWjYpN/t8JNpN9QIDAQABAoIBAFPKX38aNeWqufwp
GVBwjTx2/ZGMCz7VAg054cz9fMAluUa7PVd9fOWkoZgTxCBdrccHvL0dZoOCmkKn
kTIOGjQq3SMKW1ElWMh5uUTzSh11Lh5uAGcK1gT1pGmYneuJ9JrpRwZBHEmViFQD
cS0IpqUv2aNpgM1ZP6W/96USgEn4MkIWb4EDrNcbFlJBCciyw6zPbik8FPDdE3EH
ndi0wW0xvBsMQ353Oa4KA+/fDg7uzFMFkgrlVuDS6gv9n/qvdWTqg9+f1/a3vMsT
CqgK4lrX5o2ghXcBqXZ3E9CMuhnPGAyYkwGCtXJ8IO4SmGBuFDPoQPfJ5olOqkbA
e4VHkKECgYEA8ZMv2NmvO70rsgYIAm5GYJeAgRUYxqnZgIqHEevoikYPXagkZ9xd
Pej6Rjz7tql79lD9ovOPXGaRYxQDoEfOKB8h02rNUWrlUWFaHYv41T15ozxsi8Oc
mr0TUaV/NXjuuK5fZvjOL1xp4M+SuN9OFkZR+M9HkHuYIe2xXJg1JH0CgYEA4IAv
3e6aP4TuXlRuFjrJ+kiMQu8lcri+Ypv4U4Eff83HLopmOm4Wk3JWItlwIAjt6CKV
gMLGw0YY+jXwO8unsW7CY936wi/QiIn7+u7QKT0outaOlSRZhQk1t5EVa1wcjwtg
pv9T0wnWh9QhE9k6J+41pqgoZPrrnqXsRvo14NkCgYBo0FbbPJ/mSI6z4CALhfMt
J67O0ut8Dufa+L/gC75KeFlkZnbdRWSDXxlv7je8qk6psbxKvmh+S9Za6a0lFuKg
z9kqVNWetMWoiJfD6B5fzxt+stHZ1laVYOIH88l81uqk4KtuDxfOvscFjqp3YhQM
YBhi3vSLAMUiO3JP3Y55NQKBgGENiaP7/prvMM1+2oipqZ+VtW1KTXom+8dNfjE7
ZQ6vOyiXlFI2PXRIvYwbTCnNMmxkZxVfHuZUa3/fyZdQF5LROyBJWpqQaSpd3J1C
mKL7WZxMHR/Esx6cOKi/A++BxqbgWExZnTdizWezAQm/ozCX/oGpuKzO/QV83YRh
ruEhAoGAZpOLVIPiAbvK3nuov/doEQZVNv4od9DNF1EHXd8IxLoQbp/EsZZUQldd
Tzc53sjfEHgX/OR51vcbqPWsVWyCTYQG2fKZwq6bncdnpqpa1rEpWhZBWFITYPl+
jxhovzsobvEVl+hN6OBxAA9FaXERvk/E82HbPEL+JjGFGVRaRs4=
-----END RSA PRIVATE KEY-----
)KEY";