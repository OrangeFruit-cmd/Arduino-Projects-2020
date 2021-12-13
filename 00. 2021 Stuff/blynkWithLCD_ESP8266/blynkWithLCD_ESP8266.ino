/***
 * WIRING LCD TO THE ESP8266
 * GND TO GND
 * VCC TO VIN
 * SDA TO GPIO4(D2)
 * SCL TO GPIO5(D1)
 */


/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - ESP8266 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "07dTWgjSLiIhLQSBmGJZlvNIZsAfapeS";
String Text1;
String Text2;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "R1B_Access_Point";
char pass[] = "Qwerty162231";

void setup()
{
  // Debug console
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

BLYNK_WRITE(V5)
{
//  int pinValue = param.asInt();
  lcd.clear();
  Serial.println(param.asStr());
  Text1 = param.asStr();
}

BLYNK_WRITE(V6)
{
  lcd.clear();
  Serial.println(param.asStr());
  Text2 = param.asStr();

}

void loop()
{
  Blynk.run();
// fix this code first
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Connected!");
//  delay(2000);
  lcd.setCursor(0,0);
  lcd.print(Text1);
  lcd.setCursor(0,1);
  lcd.print(Text2);

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
