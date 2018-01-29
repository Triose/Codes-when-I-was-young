import numpy as np
import cv2

cap = cv2.VideoCapture(0)

fourcc = cv2.VideoWriter_fourcc(*'XVID')        # FourCC is a 4-byte code used to specify the video codec
out = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))   
# VideoWriter's arguments are output filename; FourCC code; number of frame per second(fps); isColor flag--True->color frame, otherwise it works with grayscale frame

while cap.isOpened():
    ret, frame = cap.read()
    if ret == True:
        frame = cv2.flip(frame, 0)      # 倒过来

        out.write(frame)

        cv2.imshow('frame', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    
    else :
        break

# After you finished your job, don't forget release them all
cap.release()
out.release()
cv2.destroyAllWindows()


