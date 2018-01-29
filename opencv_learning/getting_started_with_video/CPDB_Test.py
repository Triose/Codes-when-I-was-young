import numpy as np
import cv2
import time

# 这个文件不是教程的一部分
# 我试着用opencv读Caltech Pedestrain Detection Benchmark的.seq格式的视频
cap = cv2.VideoCapture("/home/triose/CPDB/seq/set01/V000.seq")      # 原来CPDB这个数据集的seq格式是这么读的

while cap.isOpened():
    ret, frame = cap.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('frame', gray)
    time.sleep(0.1)         # 因为视频速度太快 所以减慢一点

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
    

cap.release()
cv2.destroyAllWindows()




