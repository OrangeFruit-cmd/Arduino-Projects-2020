int potPin = A0;

int lastPotValue;



void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPin) / 255;

  if (potValue != lastPotValue)
  {
    switch(potValue)
    {
     case 0:
        Serial.println("Very Low");
        break;
     case 1:
        Serial.println("Low");
        break;
     case 2:
        Serial.println("Moderate");
        break;
     case 3:
        Serial.println("HIGH");
        break;
     case 4:
        Serial.println("Extreme");
        break;
     default:
        Serial.println("error!");
        break;
    }
    lastPotValue = potValue;
  }
}
