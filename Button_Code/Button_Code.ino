const int ledPin = 2;
const int buttonPin = 4;

int buttonState = 0;
int piezoPin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {

    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON +++++++");
    tone(piezoPin, 1000,500);
  }
    else{

      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF ------");
      
    }

  }
