//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0 , 4, 5, 6, 7, 3, POSITIVE);

 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  lcd.begin(16,2);
  Serial.println();



}

void intro(){
  lcd.print("  PUT YOUR ID  ");
  lcd.setCursor(0,1);
  lcd.print("      HERE     ");
  }
void loop() 
{
  intro();
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
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
  if (content.substring(1) == "F4 BE 8A 2A") //change here the UID of the card/cards that you want to give access
  //  || content.substring(1) == "E9 BD 83 C1" may be added above to add 1 more card
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);

    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    myServo.write(180);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    ACCEPTED"); 
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    lcd.clear();
    intro();
    
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    lcd.clear();
    lcd.print("     DENIED");
    delay(1500);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
    lcd.clear();
    intro();
  }
} 
