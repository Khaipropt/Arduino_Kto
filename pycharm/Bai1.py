import cv2
import serial
from cvzone.HandTrackingModule import HandDetector

port = serial.Serial("COM3",9600)

detector = HandDetector(detectionCon = 0.75, maxHands = 2)


cap = cv2.VideoCapture(0)
while True:
    success,img = cap.read()
    hands,img = detector.findHands(img)
    
    if hands:
        hand1 = hands[0]
        finger1=detector.fingersUp(hand1)
        if len(hands) == 2:
            hand2 = hands[1]
            finger2 = detector.fingersUp(hand2)
            totalfinger1= finger1.count(1)
            totalfinger2 = finger2.count(1)
            print(finger1,finger2)
            
            if totalfinger1 & totalfinger2 == 5:
                port.write('1'.encode()) #send 1
                print("BOTH BULD ON")
            elif totalfinger1==5:
                port.write('2'.encode())
                print("LEFT BULD ON")
            elif totalfinger2==5:
                port.write('3'.encode())
                print("RIGHT BULD ON")
            else:
                port.write('4'.encode())
                print("BOTH BULD ON")
            
    cv2.imshow("HAND",img)
    if(cv2.waitKey(1) & 0xFF == ord('c')):
        break