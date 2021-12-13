int ledPin = 3;
int buttonPin = 2;

int toggleState;
int buttonState = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  while( buttonState == 0)
  {
    toggleState =! toggleState;
    digitalWrite (ledPin, toggleState);
    delay(50);
    buttonState = digitalRead(buttonPin);
  }
  toggleState =! toggleState;
  digitalWrite(ledPin, toggleState);
  delay(200);

}
