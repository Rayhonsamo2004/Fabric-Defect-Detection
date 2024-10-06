from flask import Flask, render_template, request, jsonify
from ultralytics import YOLO
import cv2
import numpy as np
import firebase_admin
from firebase_admin import credentials, firestore, storage
import os
from datetime import datetime

app = Flask(__name__, static_url_path='/static')
model = YOLO('best.pt')

# Initialize Firebaseq Admin SDK (Firestore and Storage)
cred = credentials.Certificate('account_key.json')
firebase_admin.initialize_app(cred, {
    'storageBucket': 'textile-anamoly.appspot.com'
})

db = firestore.client()
bucket = storage.bucket()

def calculate_area(box):
    # box format: [x_min, y_min, x_max, y_max]
    width, height = box.xywh[0][2].item(), box.xywh[0][3].item()
    area = width * height
    return area

@app.route('/')
def index():
    return render_template('index.html')

def take_screenshot_and_annotated_frame(frame, annotated_frame, filename):
    # Save frame and annotated frame locally
    cv2.imwrite(filename, frame)
    cv2.imwrite("annotated_" + filename, annotated_frame)
    
    # Upload the screenshot to Firebase Storage (in the 'defects' folder)
    screenshot_url = upload_to_firebase_storage(filename, folder='defects')
    annotated_screenshot_url = upload_to_firebase_storage("annotated_" + filename, folder='Defects')

    return screenshot_url, annotated_screenshot_url

def upload_to_firebase_storage(file_path, folder=''):
    # Add folder to the file path
    if folder:
        blob = bucket.blob(f"{folder}/{os.path.basename(file_path)}")
    else:
        blob = bucket.blob(os.path.basename(file_path))
    
    # Upload the file to Firebase Storage
    blob.upload_from_filename(file_path)
    
    # Make the file publicly accessible and get its URL
    blob.make_public()
    return blob.public_url

@app.route('/detect', methods=['POST'])
def detect():
    cap = cv2.VideoCapture(0)
    detected_defects = []  # List to hold detected defect information

    # Loop through the video frames
    while cap.isOpened():
        # Read a frame from the video
        success, frame = cap.read()

        if success:
            # Run YOLOv8 inference on the frame
            results = model.predict(frame, conf=0.8)
            
            # Visualize the results on the frame
            annotated_frame = results[0].plot()
            boxes = []
            class_ids = []
            for result in results:
                if result.boxes:
                    box = result.boxes[0]
                    class_id = int(box.cls)
                    boxes.append(box)
                    class_ids.append(class_id)
            
            # Display the annotated frame
            cv2.imshow("YOLOv8 Inference", annotated_frame)

            # Take a screenshot if objects are detected
            if len(boxes) > 0:
                for box, class_id in zip(boxes, class_ids):
                    defect_type = model.names[class_id]
                    accuracy = (box.conf).item()
                    area = calculate_area(box)

                    # Store defect information in Firestore
                    store_defect_info(defect_type, accuracy, area)

                    # Take a screenshot and upload to Firebase Storage (in the 'defects' folder)
                    screenshot_url, annotated_screenshot_url = take_screenshot_and_annotated_frame(
                        frame, annotated_frame, f"screenshot_{datetime.now().strftime('%Y%m%d_%H%M%S')}.jpg")
                    
                    # Add defect information to the list
                    detected_defects.append({
                        'defect_type': defect_type,
                        'accuracy': accuracy,
                        'area': area,
                        'screenshot_url': screenshot_url,
                        'annotated_screenshot_url': annotated_screenshot_url
                    })
            
            # Break the loop if 'q' is pressed
            if cv2.waitKey(1) & 0xFF == ord("q"):
                break
        else:
            # Break the loop if the end of the video is reached
            break

    # Release the video capture object and close the display window
    cap.release()
    cv2.destroyAllWindows()

    # Return detected defects as a JSON response
    if len(detected_defects) > 0:
        return jsonify(detected_defects=detected_defects), 200
    else:
        return jsonify(message="No defects detected"), 200

def store_defect_info(defect_type, accuracy, area):
    # Store defect information in Firestore
    doc_ref = db.collection(u'defects').add({
        u'defect_type': defect_type,
        u'accuracy': accuracy,
        u'area': area
    })

if __name__ == '__main__':
    app.run(debug=True)
