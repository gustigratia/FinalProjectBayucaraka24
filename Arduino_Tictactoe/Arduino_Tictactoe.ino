#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup(){
  Serial.begin(115200);

  servo1.attach();
  servo2.attach();
  servo3.attach();
  servo4.attach();

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    int code = Serial.parseInt();
      if(code == 1){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 2){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 3){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 4){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 5){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 6){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 7){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 8){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
      if(code == 9){
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        servo4.write()
        delay(2000)
        servo3.write()
        delay(2000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo4.write()
        delay(1000)
        servo1.write()
        servo2.write()
        delay(2000)
        servo3.write(90)
        delay(2000)
      }
  }

}
