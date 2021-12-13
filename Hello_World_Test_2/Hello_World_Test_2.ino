#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0 , 4, 5, 6, 7, 3, POSITIVE);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");

  delay(1000);

  //print on second row

  lcd.setCursor (0,1);
  lcd.print("How are you?");
  delay (8000);

  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Backlight demo");
  lcd.setCursor(0,1);
  lcd.print("Flash 4 times");
  delay(3000);
  lcd.clear();

  //Flash backlight 4 times
  for( int i= 0; i < 4; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  //turn backlight back on
  lcd.backlight();
  //demo 2 - scroll
  lcd.setCursor (0,0);
  lcd.print("Scroll demo - ");
  delay(1500);
  // set the dispaly to automaitcally scroll:

  lcd.autoscroll();
  // print from 0 to 9
  for (int thisChar = 0; thisChar < 10; thisChar++)
  {
    lcd.print(thisChar);
    delay(500);
    
  }
  lcd.noAutoscroll();
  lcd.clear();
  delay(1000);
  
}
