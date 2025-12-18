"""
Follows simple tutorial on how to detect AR tags
Source: https://www.geeksforgeeks.org/computer-vision/detecting-aruco-markers-with-opencv-and-python-1/
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
# Read image
image = cv.imread("./detect_images/test7.png")# modules\aruco_tags\detect_images\IMG_8416.png

# Step 1: Convert to grayscale
gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

# Step 2: Load dictionary of tags (need to know which one to look for)
aruco_dict = cv.aruco.getPredefinedDictionary(cv.aruco.DICT_4X4_50)
parameters = cv.aruco.DetectorParameters()

# Step 3: Create the detector
detector = cv.aruco.ArucoDetector(aruco_dict, parameters)

# Step 4: Detection
start = time.time()
corners, ids, rejected = detector.detectMarkers(gray)
end = time.time()

# Step 5: Printing
print("Detected markers: ", ids, "\nTime Elapsed: ", end - start, "s")
print("Corners: ", corners)
cv.namedWindow("Detected Markers", cv.WINDOW_NORMAL)
cv.resizeWindow("Detected Markers", 1200, 900)
if ids is not None:
    cv.aruco.drawDetectedMarkers(image, corners, ids)
    cv.imshow("Detected Markers", image)
    cv.waitKey(0)
    cv.destroyAllWindows()
else:
    cv.aruco.drawDetectedMarkers(image, rejected, ids)
    cv.imshow("Detected Markers", image)
    cv.waitKey(0)
    cv.destroyAllWindows()