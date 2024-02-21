import rclpy 
from rclpy.node import Node 
from griddata.msg import GameState
import cv2 



class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('vision')
        self.subscriber_ = self.create_subscription(GameState, 'control', self.timer_callback, 10)
        self.publisher_ = self.create_publisher(GameState, 'vision', 10)
        self.timer = self.create_timer(0.1, self.publish_message)
        self.cell = [0,0,0,0,0,0,0,0,0]
        self.GameOver = False
        self.wincond = 0
        self.cap = cv2.VideoCapture(1)

    def timer_callback(self, msg):
        for i in range(0,9):
            self.cell[i] = msg.cell[i]

        
    def publish_message(self):
        msg = GameState()
        for i in range(0,9):
            msg.cell[i] = self.cell[i]        
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
                
            # Game Over
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
            # if(self.GameOver == False):
            #     cv2.putText(frame, "GAME OVER", (50,245), cv2.FONT_HERSHEY_TRIPLEX, 3, (7,17,20), 8)
            #     cv2.putText(frame, "(TIED)", (205,400), cv2.FONT_HERSHEY_SIMPLEX, 3, (36,45,48), 8)

            cv2.imshow("frame", frame)
            if cv2.waitKey(1) & 0xFF == ord('m'):
                self.process_imagered(frame)
                self.process_imageblue(frame)
                # self.check_win()
        self.publisher_.publish(msg)
        self.get_logger().info("Processing cell3 = %d %d" % (msg.cell[2], msg.cell[0]))

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
        
    def check_win(self, msg):
        if(msg.cell1 == msg.cell2 and msg.cell2 == msg.cell3):
            self.GameOver = True
            self.wincond = 1
        elif(msg.cell4 == msg.cell5 and msg.cell5 == msg.cell6):
            self.GameOver = True
            self.wincond = 2
        elif(msg.cell7 == msg.cell8 and msg.cell8 == msg.cell9):
            self.GameOver = True
            self.wincond = 3
        elif(msg.cell1 == msg.cell4 and msg.cell4 == msg.cell7):
            self.GameOver = True
            self.wincond = 4
        elif(msg.cell2 == msg.cell5 and msg.cell5 == msg.cell8):
            self.GameOver = True
            self.wincond = 5
        elif(msg.cell3 == msg.cell6 and msg.cell6 == msg.cell9):
            self.GameOver = True
            self.wincond = 6
        elif(msg.cell1 == msg.cell5 and msg.cell5 == msg.cell9):
            self.GameOver = True
            self.wincond = 7
        elif(msg.cell3 == msg.cell5 and msg.cell5 == msg.cell7):
            self.GameOver = True
            self.wincond = 8
        
            
        
    
        
def main(args=None):
    rclpy.init(args=args)
    publisher = MinimalPublisher()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()