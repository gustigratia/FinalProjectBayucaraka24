import rclpy 
from rclpy.node import Node 
from griddata.msg import GameState
import cv2 



class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('vision')
        self.timer_ = self.create_timer(0.1, self.publish_message)
        self.subscriber_ = self.create_subscription(GameState, 'control', self.timer_callback, 10)
        self.publisher_ = self.create_publisher(GameState, 'vision', 10)
        self.cell = [0,0,0,0,0,0,0,0,0]
        self.GameOver = 0
        self.move = 5
        self.Terminate = True
        self.isTied = True
        self.wincond = 0
        self.turn = 0
        self.cap = cv2.VideoCapture(1)

    def timer_callback(self, msg):
        for i in range(0,9):
            self.cell[i] = msg.cell[i]
        
    def publish_message(self):
        msg = GameState()
        for i in range(0,9):
            msg.cell[i] = self.cell[i]   
        msg.gameturn = self.turn     
        msg.over = self.Terminate
        ret, frame = self.cap.read()
        if ret == True:
            
            # Draw Circles
            if(msg.cell[0] == 2):
                cv2.circle(frame, (220,87), 55, (255,0,0), -1)
            if(msg.cell[1] == 2):
                cv2.circle(frame, (365,87), 55, (255,0,0), -1)
            if(msg.cell[2] == 2):
                cv2.circle(frame, (515,87), 55, (255,0,0), -1)
            if(msg.cell[3] == 2):
                cv2.circle(frame, (220,235), 55, (255,0,0), -1)
            if(msg.cell[4] == 2):
                cv2.circle(frame, (365,235), 55, (255,0,0), -1)
            if(msg.cell[5] == 2):
                cv2.circle(frame, (515,235), 55, (255,0,0), -1)
            if(msg.cell[6] == 2):
                cv2.circle(frame, (220,390), 55, (255,0,0), -1)
            if(msg.cell[7] == 2):
                cv2.circle(frame, (365,390), 55, (255,0,0), -1)
            if(msg.cell[8] == 2):
                cv2.circle(frame, (515,390), 55, (255,0,0), -1)
                
            if self.move!=0:
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
                elif(msg.cell[0] == msg.cell[4] and msg.cell[4] == msg.cell[8] and msg.cell[0] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 7
                elif(msg.cell[2] == msg.cell[4] and msg.cell[4] == msg.cell[6] and msg.cell[2] == 2):
                    self.isTied = False
                    self.Terminate = False
                    self.wincond = 8

            # Game Over
            if(self.isTied==False):    
                if(self.wincond == 1):
                    cv2.line(frame, (215,95), (515, 95), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 2):
                    cv2.line(frame, (215,245), (515, 245), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)                    
                elif(self.wincond == 3):
                    cv2.line(frame, (215,395), (515, 395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)                
                elif(self.wincond == 4):
                    cv2.line(frame, (215,95), (215, 395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 5):
                    cv2.line(frame, (365,95), (365, 395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 6):
                    cv2.line(frame, (515,95), (515, 395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 7):
                    cv2.line(frame, (215,95), (515,395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                elif(self.wincond == 8):
                    cv2.line(frame, (515,95), (215,395), (0,255,255), 30)
                    cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                    cv2.putText(frame, "(YOU LOSE)", (50,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
            elif (self.isTied == True and self.move == 0):
                cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
                cv2.putText(frame, "(TIED)", (205,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)
                self.Terminate = False
                
            cv2.putText(frame, "Press 'p'", (5,30), cv2.FONT_HERSHEY_DUPLEX, 1.2, (0,0,0), 2)
            cv2.putText(frame, "to proceed", (2,60), cv2.FONT_HERSHEY_DUPLEX, 1, (0,0,0), 1)
            cv2.imshow("frame", frame)
            if cv2.waitKey(1) & 0xFF == ord('p'):
                self.process_imagered(frame)
                self.process_imageblue(frame)
                self.turn += 2
                self.move-=1
        self.publisher_.publish(msg)

    def process_imagered(self, image):
        hsvred = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
        maskred = cv2.inRange(hsvred, (0,80,120), (200,242,200))
        redcontours, hierarchy = cv2.findContours(maskred, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if len(redcontours) != 0:
            for i in redcontours:
                if cv2.contourArea(i)>500:
                    x1,y1,w,h = cv2.boundingRect(i)
                    # Left Column
                    if(x1 > 140 and (x1+w) < 290):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[0] = 1                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[3] = 1
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[6] = 1
                    # Center Column                         
                    if(x1 > 290 and (x1+w) < 440):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[1] = 1                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[4] = 1
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[7] = 1
                    # Right Column
                    if(x1 > 440 and (x1+w) < 590):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[2] = 1                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[5] = 1
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[8] = 1
        self.get_logger().info("Processing Red . . .")
        
    def process_imageblue(self, image):
        hsvblue = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
        maskblue = cv2.inRange(hsvblue, (110,100,100), (130,255,255))
        bluecontours, hierarchy = cv2.findContours(maskblue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if len(bluecontours) != 0:
            for i in bluecontours:
                if cv2.contourArea(i)>500:
                    x1,y1,w,h = cv2.boundingRect(i)
                    # Left Column
                    if(x1 > 140 and (x1+w) < 290):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[0] = 2                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[3] = 2
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[6] = 2
                    # Center Column                         
                    if(x1 > 290 and (x1+w) < 440):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[1] = 2                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[4] = 2
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[7] = 2
                    # Right Column
                    if(x1 > 440 and (x1+w) < 590):
                        if(y1 > 20 and (y1+h) < 170):
                            self.cell[2] = 2                    
                        if(y1 > 170 and (y1+h) < 320):
                            self.cell[5] = 2
                        if(y1 > 320 and (y1+h) < 470):
                            self.cell[8] = 2
        self.get_logger().info("Processing Blue . . .")
        
    
def main(args=None):
    rclpy.init(args=args)
    publisher = MinimalPublisher()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()