const int dataPin = 6;
const int clockPin = 7;
const int latchPin = 8;

byte ledMap = 0b11111111;
int delayTime = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
  shiftWrite(0x00);
  Serial.println("Enter a number between 0 - 255");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    int inputVal = Serial.parseInt();

    if (inputVal > 255)
    {
      Serial.println("Uh oh, try again!");
      Serial.println("Enter a number between 0 - 255");
      return;
    }

    Serial.print("DECIMAL: ");
    Serial.println(inputVal);
    Serial.println("BINARY: ");
    Serial.println(inputVal, BIN); //BIN Stands for BINARY
    Serial.println();

    Serial.print("AND result: ");
    Serial.println(ledMap & inputVal, BIN);
    shiftWrite(ledMap & inputVal);
    delay(delayTime);

    Serial.print("OR result: ");
    Serial.println(ledMap | inputVal, BIN);
    shiftWrite(ledMap | inputVal);
    delay(delayTime);

    Serial.print("XOR result: ");
    Serial.println(ledMap ^ inputVal, BIN);
    shiftWrite(ledMap ^ inputVal);
    delay(delayTime);
    Serial.println();
    Serial.println("Entr a number between 0-255");
  }
}
void shiftWrite(byte value)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
