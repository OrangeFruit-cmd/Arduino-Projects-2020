void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int remainder = 11 % 3;
  Serial.println(remainder);
  delay(2000);
}
