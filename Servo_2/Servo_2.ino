#include <Servo.h>

Servo servo;
int angle = 10;

void setup() {
  // put your setup code here, to run once:
  servo.attach(1);
  servo.write(angle);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (angle = 10; angle < 180; angle ++)
    {
      servo.write(angle);
      delay(15);
    }
  for (angle = 180; angle > 10; angle--){
    servo.write(angle);
    delay(15);
  }
}
