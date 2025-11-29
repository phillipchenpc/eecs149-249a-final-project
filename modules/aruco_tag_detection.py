"""
Follows simple tutorial on how to detect AR tags
"""

#############
## Imports ##
#############
import cv2 as cv
import numpy as np

##########
## Main ##
##########
# Read image
image = cv.imread("./detect_images/test.jpg")

# Step 1: Convert to grayscale
gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

# Step 2: Load dictionary of tags (need to know which one to look for)
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_6X6_250)
parameters = cv.aruco.DetectorParameters()

# Step 3: Create the detector
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Step 4: Detection
corners, ids, rejected = detector.detectMarkers(gray)

# Step 5: Printing
print("Detected markers: ", ids)
if ids is not None:
    cv.aruco.drawDetectedMarkers(image, corners, ids)
    cv.imshow("Detected Markers", image)
    cv.waitKey(0)
    cv.destroyAllWindows()