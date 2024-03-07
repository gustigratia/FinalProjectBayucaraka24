# Import Libraries
import rclpy 
import serial
import time
from rclpy.node import Node 
from griddata.msg import GameState
import cv2 

# Create Node
class MyNode(Node):
    def __init__(self):
        super().__init__('vision')
        
        # Periodic Timer
        self.timer_ = self.create_timer(0.1, self.publish_message)
        # Create Subscription and subscribe topic 'control'
        self.subscriber_ = self.create_subscription(GameState, 'control', self.timer_callback, 10)
        # Create Publisher and publish topic 'vision'
        self.publisher_ = self.create_publisher(GameState, 'vision', 10)
        
        # Serial Port Comms
        self.serial_port = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
        time.sleep(2)
        
        # Data members
        self.cell = [0,0,0,0,0,0,0,0,0]
        self.player = 1
        self.cellmove = [True, True, True, True, True, True, True, True, True]
        self.xcorner = 0
        self.ycorner = 0
        self.width = 0
        self.height = 0
        self.GameOver = 0
        self.move = 5
        self.Terminate = True
        self.isTied = True
        self.wincond = 0
        self.turn = 0

        # Open Webcam with external device
        self.cap = cv2.VideoCapture(3)

    # Subscribption Callback, store data from Gamestate.msg
    def timer_callback(self, msg):
        for i in range(0,9):
            self.cell[i] = msg.cell[i]
    
    # Image data (frame) publisher
    def publish_message(self):
        # send data from data member into GameState.msg
        msg = GameState()
        for i in range(0,9):
            msg.cell[i] = self.cell[i]   
        msg.gameturn = self.turn     
        msg.over = self.Terminate

        # Read frame by frame
        ret, frame = self.cap.read()

        if ret == True:
            # Grid Detect
            cv2.rectangle(frame, (self.xcorner, self.ycorner), (self.xcorner+self.width, self.ycorner+self.height), (0,255,255), 3)
            
            # Move Servo
            if(msg.cell[0] == 2 and self.cellmove[0] == True):
                cpointx = self.width/6 + self.xcorner
                cpointy = self.height/6 + self.ycorner
                frame = cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "1"
                self.serial_port.write(signal.encode())
                self.cellmove[0] = False
            if(msg.cell[1] == 2 and self.cellmove[1] == True):
                cpointx = self.width/2 + self.xcorner
                cpointy = self.height/6 + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "2"
                self.serial_port.write(signal.encode())
                self.cellmove[1] = False
            if(msg.cell[2] == 2 and self.cellmove[2] == True):
                cpointx = (self.width - (self.width/6)) + self.xcorner
                cpointy = self.height/6 + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "3"
                self.serial_port.write(signal.encode())
                self.cellmove[2] = False
            if(msg.cell[3] == 2 and self.cellmove[3] == True):
                cpointx = self.height/6 + self.xcorner
                cpointy = self.height/2 + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "4"
                self.serial_port.write(signal.encode())
                self.cellmove[3] = False
            if(msg.cell[4] == 2 and self.cellmove[4] == True):
                cpointx = cpointx = self.width/2 + self.xcorner
                cpointy = self.height/2 + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "5"
                self.serial_port.write(signal.encode())
                self.cellmove[4] = False
            if(msg.cell[5] == 2 and self.cellmove[5] == True):
                cpointx = (self.width - (self.width/6)) + self.xcorner
                cpointy = self.height/2 + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "6"
                self.serial_port.write(signal.encode())
                self.cellmove[5] = False
            if(msg.cell[6] == 2 and self.cellmove[6] == True):
                cpointx = self.width/6 + self.xcorner
                cpointy = (self.height - (self.height/6)) + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "7"
                self.serial_port.write(signal.encode())
                self.cellmove[6] = False
            if(msg.cell[7] == 2 and self.cellmove[7] == True):
                cpointx = self.width/2 + self.xcorner
                cpointy = (self.height - (self.height/6)) + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "8"
                self.serial_port.write(signal.encode())
                self.cellmove[7] = False
            if(msg.cell[8] == 2 and self.cellmove[8] == True):
                cpointx = (self.width - (self.width/6)) + self.xcorner
                cpointy = (self.height - (self.height/6)) + self.ycorner
                cv2.circle(frame, (int(cpointx),int(cpointy)), 55, (255,0,0), -1)
                signal = "9"
                self.serial_port.write(signal.encode())
                self.cellmove[8] = False
            
            # Check Win (continuous line of three in a row, column, or diagonal)
            if self.move!=0:
                # Row
                if(msg.cell[0] == msg.cell[1] and msg.cell[1] == msg.cell[2] and msg.cell[0] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 1
                elif(msg.cell[3] == msg.cell[4] and msg.cell[4] == msg.cell[5] and msg.cell[3] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 2
                elif(msg.cell[6] == msg.cell[7] and msg.cell[7] == msg.cell[8] and msg.cell[6] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 3
                # Column
                elif(msg.cell[0] == msg.cell[3] and msg.cell[3] == msg.cell[6] and msg.cell[0] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 4
                elif(msg.cell[1] == msg.cell[4] and msg.cell[4] == msg.cell[7] and msg.cell[1] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 5
                elif(msg.cell[2] == msg.cell[5] and msg.cell[5] == msg.cell[8] and msg.cell[2] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 6
                # Diagonal
                elif(msg.cell[0] == msg.cell[4] and msg.cell[4] == msg.cell[8] and msg.cell[0] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 7
                elif(msg.cell[2] == msg.cell[4] and msg.cell[4] == msg.cell[6] and msg.cell[2] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 8

            # Game Over (Lose)
            if(self.isTied==False):    
                if(self.wincond == 1):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 2):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)                    
                elif(self.wincond == 3):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)                
                elif(self.wincond == 4):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 5):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 6):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 7):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 8):
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
            # Game over (Tied)
            elif (self.isTied == True and self.move == 0):
                cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                cv2.putText(frame, "(TIED)", (205,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                self.Terminate = False
            
            # Add text
            cv2.putText(frame, "Press 'm'", (5,30), cv2.FONT_HERSHEY_DUPLEX, 1.2, (0,0,0), 1)
            cv2.putText(frame, "to proceed", (2,60), cv2.FONT_HERSHEY_DUPLEX, 1, (0,0,0), 1)
            # Show the window
            cv2.imshow("Autonomous Tic-Tac-Toe", frame)
            pressed_key = cv2.waitKey(1) & 0xFF
            # Make the 'm' button as proceed button
            if pressed_key == ord('p'):
                self.player = 2
            elif pressed_key == ord('m'):
                self.process_image(frame)
                self.turn += 2
                self.move -= 1
        self.publisher_.publish(msg)
    
    def process_image(self, image):
        # Find the grid using contour detection
        hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, (0,0,0), (255,255,120))
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
        for contour in contours:
            area = cv2.contourArea(contour)
            x_corner, y_corner, width, height = cv2.boundingRect(contour)

            # Save the grid points
            if area > 5000 and width > 100:
                self.xcorner = x_corner
                self.ycorner = y_corner
                self.width = width
                self.height = height

        # Detecting color red inside the grid
        maskred = cv2.inRange(hsv, (0,145,30), (235,255,163))
        redcontours, hierarchy = cv2.findContours(maskred, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if len(redcontours) != 0:
            for i in redcontours:
                if cv2.contourArea(i)>500:
                    x1,y1,w,h = cv2.boundingRect(i)
                    # Left Column
                    if(x1 > self.xcorner and (x1+w) < (self.xcorner+(self.width/3))):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[0] = 1
                            else:
                                self.cell[0] = 2                    
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[3] = 1
                            else:
                                self.cell[3] = 2
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[6] = 1
                            else:
                                self.cell[6] = 2
                    # Center Column                         
                    if(x1 > (self.xcorner+(self.width/3)) and (x1+w) < (self.xcorner+(2*self.width/3))):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[1] = 1
                            else:
                                self.cell[1] = 2                    
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[4] = 1
                            else:
                                self.cell[4] = 2
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[7] = 1
                            else:
                                self.cell[7] = 2
                    # Right Column
                    if(x1 > (self.xcorner+(2*self.width/3)) and (x1+w) < (self.x_corner+self.width)):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[2] = 1
                            else:
                                self.cell[2] = 2                   
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[5] = 1
                            else:
                                self.cell[5] = 2
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[8] = 1
                            else:
                                self.cell[8] = 2
        self.get_logger().info("Processing Red . . .")
        
        # Detecting color blue inside the grid
        maskblue = cv2.inRange(hsv, (66,150,0), (166,255,230))
        # maskblue = cv2.inRange(hsv, (110,100,100), (130,255,255)) 
        bluecontours, hierarchy = cv2.findContours(maskblue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if len(bluecontours) != 0:
            for i in bluecontours:
                if cv2.contourArea(i)>500:
                    x1,y1,w,h = cv2.boundingRect(i)
                    # Left Column
                    if(x1 > self.xcorner and (x1+w) < (self.xcorner+(self.width/3))):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[0] = 2
                            else:
                                self.cell[0] = 1                    
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[3] = 2
                            else:
                                self.cell[3] = 1
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[6] = 2
                            else:
                                self.cell[6] = 1
                    # Center Column                         
                    if(x1 > (self.xcorner+(self.width/3)) and (x1+w) < (self.xcorner+(2*self.width/3))):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[1] = 2
                            else:
                                self.cell[1] = 1                   
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[4] = 2
                            else:
                                self.cell[4] = 1
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[7] = 2
                            else:
                                self.cell[7] = 1
                    # Right Column
                    if(x1 > (self.xcorner+(2*self.width/3)) and (x1+w) < (self.x_corner+self.width)):
                        if(y1 > self.ycorner and (y1+h) < self.ycorner+(self.height/3)):
                            if(self.player==1):
                                self.cell[2] = 2
                            else:
                                self.cell[2] = 1                    
                        if(y1 > self.ycorner+(self.height/3) and (y1+h) < self.ycorner+(2*self.height/3)):
                            if(self.player==1):
                                self.cell[5] = 2
                            else:
                                self.cell[5] = 1
                        if(y1 > self.ycorner+(2*self.height/3) and (y1+h) < self.ycorner+self.height):
                            if(self.player==1):
                                self.cell[8] = 2
                            else:
                                self.cell[8] = 1
        self.get_logger().info("Processing Blue . . .")
        
# Spin the node
def main(args=None):
    rclpy.init(args=args)
    publisher = MyNode()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    
