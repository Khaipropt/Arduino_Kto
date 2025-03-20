import cv2
import serial
from cvzone.HandTrackingModule import HandDetector

# port = serial.Serial("COM3",9600)

detector = HandDetector(detectionCon = 0.75, maxHands = 2)


cap = cv2.VideoCapture(0)
while True:
    success,img = cap.read()
    hands,img = detector.findHands(img)
    
    if hands:
        hand1 = hands[0]
        finger1=detector.fingersUp(hand1)
        
        totalfinger1= finger1.count(1)
            
        print(totalfinger1)
            
        # if totalfinger1 == 1:
        #     port.write('1'.encode()) #send 1
        #     print("1 BULD ON")
        # elif totalfinger1==2:
        #     port.write('2'.encode())
        #     print("2 BULD ON")
        # elif totalfinger1==3:
        #     port.write('3'.encode())
        #     print("3 BULD ON")
        # elif totalfinger1==4:
        #     port.write('4'.encode())
        #     print("4 BULD ON")
        # else:
        #     port.write('5'.encode())
        #     print("0 BULD ON")
            
    cv2.imshow("HAND",img)
    if(cv2.waitKey(1) & 0xFF == ord('c')):
        break