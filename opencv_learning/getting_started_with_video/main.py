import numpy as np
import cv2

# VideoCapture object
# The argument of this function can be either the device index or the name of a video file
cap = cv2.VideoCapture(0)

while cap.isOpened():               # 别用while true
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Our operations on the frame come here
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    cv2.imshow('result', gray)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# After you finished your job, don't forget to release it
cap.release()
cv2.destroyAllWindows()











