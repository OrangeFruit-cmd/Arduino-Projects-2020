void setup() {
Serial.begin(9600);

}

void loop() {
  int a;
  int b;
  float result;


  Serial.print("Enter a side value: ");
  while(!Serial.available());
  a = readSerial();

  Serial.print("Enter the other side value: ");
  while(!Serial.available());
  b = readSerial();

  findSide(a, b);
  Serial.println();

}

int readSerial()
{
  int i = Serial.parseInt();
  if (i < 1)
  {
    return;
  }
  Serial.println(i);
  Serial.parseInt();
  return i;
}
int findSide(int x, int y)
{
  float hypotenuse = sqrt(x*x + y*y);
  Serial.print("Hypotenuse = ");
  Serial.println(hypotenuse);
}
