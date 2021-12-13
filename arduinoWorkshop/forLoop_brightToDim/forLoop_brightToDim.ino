int ledPin = 3;

int rampTime = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i; i < 256; i++)
  {
    analogWrite(ledPin, i);
    delay(rampTime);
    Serial.println(i);
  }

  for (int i = 255; i>0; i--)
  {
    analogWrite(ledPin, i);
    delay(rampTime);
    Serial.println(i);
  }
}
