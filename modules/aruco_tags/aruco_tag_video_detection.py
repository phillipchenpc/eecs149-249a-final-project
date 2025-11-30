"""
Follows simple tutorial on how to detect AR tags in video
Source: https://docs.opencv.org/4.x/d5/dae/tutorial_aruco_detection.html
https://www.geeksforgeeks.org/python/python-opencv-capture-video-from-camera/#
"""

#############
## Imports ##
#############
import cv2 as cv
import numpy as np
import time

##########
## Main ##
##########

# Grab the dictionary and create a detector
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Open the camera
print("Opening Camera...", end='\r')
start = time.time()
cam = cv.VideoCapture(2)
# Adjusting exposure time
cam.set(cv.CAP_PROP_FRAME_WIDTH, 1920)
cam.set(cv.CAP_PROP_FRAME_HEIGHT, 1080)
end = time.time()
print(f"Camera opened in {end - start} s")

print("Press q to end the program (when the video window is selected)")

# Reading from the camera
while True:
    start = time.time()
    ret, frame = cam.read()

    # Gray out the image
    frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    # Detect the tags
    corners, ids, rejected = detector.detectMarkers(frame_gray)

    # Draw out detections
    if ids is not None:
        cv.aruco.drawDetectedMarkers(frame, corners, ids)
    else:
        cv.aruco.drawDetectedMarkers(frame, rejected, ids)
    cv.imshow("Detected Markers (press q to close)", frame)

    end = time.time()
    print(f"Time: {end - start}", end='\r')
    # Ends the loop if you press 'q'
<<<<<<< HEAD
    if cv.waitKey(1) == ord('q'):
=======
    if cv.waitKey(33) == ord('q'):
>>>>>>> 5d1a7ac ([AR Tags] Moved to new folder. Video detection)
        break


# Release camera
cam.release()
# Destroy the window
cv.destroyAllWindows()