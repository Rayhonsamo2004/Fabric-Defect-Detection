# Fabric-Defect-Detection
Project Workflow:
The system begins when the fabric is placed on a conveyor belt for inspection. This belt serves as a transport mechanism, moving the fabric under the inspection devices.
As the fabric moves along the conveyor belt, it pasess across the camera.the cam captures the image of fabric for defect identification. 
The captured images are sent to a server running the YOLOv8 algorithm. The YOLOv8 (You Only Look Once) algorithm is an advanced object detection model that classifies the images to detect any anomalies or defects in the fabric.
•	If no defect is detected, the fabric continues moving along the conveyor belt, and the process loops back to further inspection (as shown by the red arrow).
Once a defect is detected the msg is send thorough wifi to nodemcu microcontroller Which is equipped with servo motor.The servo motor is responsible for making a identification mark on fabric section where defect is found for further handling or inspection.
After the marking is made the defect details like defect type,area of defect and image of defect portion is uploaded to aws dynamo db for further analysis and quality assurance purposes.
After the marking and uploading details the defected fabric is removed from conveyor belt ans process continues for further fabric in belt.
 
![image](https://github.com/user-attachments/assets/ff725acf-9006-445f-9575-870afba25e40)
