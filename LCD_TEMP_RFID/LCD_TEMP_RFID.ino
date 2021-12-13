#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0 , 4, 5, 6, 7, 3, POSITIVE);

#define DHTPIN 7
#define SS_PIN 10
#define RST_PIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}
void intro(){
  lcd.print("SCAN RFID");
  lcd.setCursor(0,1);
  lcd.print("FOR TEMP & HUMID  ");
}
void loop() {
  // put your main code here, to run repeatedly:
  intro();
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "F4 BE 8A 2A" || "E9 BD 83 C1")
  {
    lcd.clear();
    lcd.print("Card Accepted");
    delay(2000);
    lcd.clear();
    lcd.print("Temp : Humidity:");
    int h = dht.readHumidity();
    float f = dht.readTemperature(true);
    float f1 = (((f) - 32) * 5/9);
    if (isnan(h) || isnan(f1)){
      lcd.print("Error");
      return;
    }
    lcd.setCursor(0,1);
    lcd.print(f1);
    lcd.setCursor(7,1);
    lcd.print(h);
    delay(5000);
    lcd.clear();
    intro();
    }
   else {
    lcd.clear();
    lcd.print("Card Denied");
    delay(2000);
    lcd.clear();
    intro();
    
    
  }
  
  }
