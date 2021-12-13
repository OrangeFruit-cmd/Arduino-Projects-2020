#include <DHT.h>

#define DHT11_PIN 8;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(2000);
}
