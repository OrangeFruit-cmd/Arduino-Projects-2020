int pinLed[] {2,3,4,5};
int delayTime = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 5; i++)
  {
    pinMode(pinLed[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 4; i++)
  {
   digitalWrite(pinLed[i],HIGH);
   delay(delayTime);
   Serial.println("Working " +  String(i));
  }
/*  
  for (int i = 0; i <= 4; i++)
  {
   digitalWrite(pinLed[i],LOW);
   delay(delayTime);
  }  
*/ 
  for (int i = 4; i >= 0; i--)
  {
    digitalWrite(pinLed[i], LOW);
    delay(delayTime*5);
   Serial.println("OFF " +  String(i));
  }

}
