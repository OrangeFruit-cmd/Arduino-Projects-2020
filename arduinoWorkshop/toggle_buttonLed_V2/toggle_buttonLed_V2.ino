int ledPin = 13;
int buttonPin = 2;

int ledState = HIGH;
int buttonCurrent;
int buttonPrevious = LOW;



void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonCurrent = digitalRead(buttonPin);

  if (buttonCurrent == HIGH && buttonPrevious == LOW)
  {
    if (ledState == HIGH)
    {
      ledState = LOW;
    }
    else
    {
      ledState = HIGH;
    }
  }

  digitalWrite(ledPin, ledState);
  

}
