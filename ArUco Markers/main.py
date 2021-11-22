import math
import numpy as np
import cv2
import cv2.aruco as aruco
import pathlib
import csv

# import UdpComms as U
# import time
#
# # Create UDP socket to use for sending (and receiving)
# sock = U.UdpComms(udpIP="127.0.0.1", portTX=8000, portRX=8001, enableRX=True, suppressWarnings=True)

cap = cv2.VideoCapture(0)

cap.set(3, 640)
cap.set(4, 480)

dir_path = 'C:/Users/Haashim Shahzada/OneDrive - Ryerson University/UHN/PostureCoach/Aruco Marker Detection'
image_format = 'jpg'
square_size = 2.7
width = 6
height = 9

def rotationMatrixToEulerAngles(R):

    sy = math.sqrt(R[0,0]*R[0,0] + R[1,0]*R[1,0])
    singular = sy < 1e-6

    if not singular:
        x = math.atan2(R[2, 1], R[2, 2])
        y = math.atan2(-R[2, 0], sy)
        z = math.atan2(R[1, 0], R[0, 0])
    else:
        x = math.atan2(-R[1, 2], R[1, 1])
        y = math.atan2(-R[2, 0], sy)
        z = 0

    return np.array([x, y, z])

def CameraCalibration(dir_path, image_format, square_size, width, height):

    # termination criteria
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

    # prepare object points
    objp = np.zeros((height*width, 3), np.float32)
    objp[:, :2] = np.mgrid[0:width, 0:height].T.reshape(-1, 2)

    objp = objp * square_size

    # arrays to store object points and image points from all the images
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane

    images = pathlib.Path(dir_path).glob(f'*.{image_format}')

    # iterate through all images
    for fname in images:

        img = cv2.imread(str(fname))
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # find the chessboard corners
        ret, corners = cv2.findChessboardCorners(gray, (width, height))

        # if found, add object points, image points (after refining them)
        if ret:
            objpoints.append(objp)

            corners2 = cv2.cornerSubPix(gray, corners, (11,11), (-1, -1), criteria)
            imgpoints.append(corners2)

    ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)
    return [mtx, dist]

while (cap.isOpened() == True):

    calibVal = CameraCalibration(dir_path, image_format, square_size, width, height)
    success, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    aruco_dict = aruco.Dictionary_get(aruco.DICT_6X6_250)
    parameters = aruco.DetectorParameters_create()
    corners, ids, rejectedImgPoints = aruco.detectMarkers(gray, aruco_dict, parameters=parameters)

    if (ids != None):

        # # x and y corner tracking, placed into list for ease of access
        # cleanuptl = corners[0][0][0]  # getting rid of the multi nested return value
        # cleanuptr = corners[0][0][1]  # getting rid of the multi nested return value
        # cleanupbl = corners[0][0][2]  # getting rid of the multi nested return value
        # cleanupbr = corners[0][0][3]  # getting rid of the multi nested return value
        #
        # # add exact items, try and solve pitch and yaw first, they are most important
        # cornercord = [cleanuptl, cleanuptr, cleanupbl, cleanupbr]

        # camera needs to be calibrated (specific camera would be the Raspberry Pi Camera)

        cameraMatrix = calibVal[0]
        distCoeffs = calibVal[1][0]

        rvec, tvec, _ = aruco.estimatePoseSingleMarkers(corners[0], 0.6, cameraMatrix, distCoeffs)

        rmtx = cv2.Rodrigues(rvec)

        # data = sock.ReadReceivedData()  # read data
        #
        # if data != None:  # if NEW data has been received since last ReadReceivedData function call
        #     print(data)  # print new received data
        #     time.sleep(1)

        radians = rotationMatrixToEulerAngles(rmtx[0]) # x,y,z angles in RADIANS

        degrees = radians*(180/math.pi)

        print(radians)
        print(degrees)

        aruco.drawAxis(gray, cameraMatrix, distCoeffs, rvec, tvec, square_size)

        with open(dir_path + "/result.csv", 'a', newline='') as result_file:
            wr = csv.writer(result_file)
            wr.writerow(degrees)

    gray = aruco.drawDetectedMarkers(gray, corners)
    cv2.imshow('frame', gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()