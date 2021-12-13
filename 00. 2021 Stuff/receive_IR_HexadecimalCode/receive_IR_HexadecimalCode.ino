/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////

//left most node (D5)
//middle node (GROUND)
//right node (3V)

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

unsigned long  MyData;
IRrecv irrecv(14);
decode_results results;
void setup()
{
  MyData = 0;
Serial.begin(9600);
pinMode(2, OUTPUT);
  irrecv.enableIRIn();  // Start the receiver
   while (!Serial){  // Wait for the serial connection to be establised.
      delay(50);
  Serial.println();
  Serial.print("IRrecv is now running and waiting for IR message on Pin ");
  Serial.println(14);
  }

}


void loop()
{

    if (irrecv.decode(&results)) {
      MyData = int((results.value));
      Serial.println("You received this data:");
      Serial.println(MyData);
      irrecv.resume();
      if (MyData == 551524965) {
        Serial.println("Right Arrow Pressed");
        digitalWrite(2,HIGH);

      }
      if (MyData == 551492325) {
        Serial.println("Left Arrow Pressed");
        digitalWrite(2,LOW);

      }

    }

}
