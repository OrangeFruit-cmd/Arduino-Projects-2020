#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 7
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0 , 4, 5, 6, 7, 3, POSITIVE);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int piezoPin = 8;

void setup(){
  lcd.begin(16,2);
  dht.begin();
  lcd.print("Temp : Humidity:");
}


void loop(){
  delay(500);
  lcd.setCursor(0, 1);
  int h = dht.readHumidity();
  float f = dht.readTemperature(true);
  float f1 = (((f) -32)*5/9);
  Serial.println(f1);
  if (isnan(h) || isnan(f1)) {
    lcd.print("ERROR");
    return;
  }
  lcd.print(f1);
  lcd.setCursor(7,1);
  lcd.print(h);

  if (f1 < 27.00){
    tone(piezoPin, 1000, 500);
    delay(1000);
  }
  }
