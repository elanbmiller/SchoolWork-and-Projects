/* pulseox

    CSE 132 - Studio 10

    Fill this out so we know whose studio this is.

    Name:Elan Miller
    WUSTL Key:elanbmiller

    Name:sophie elliott
    WUSTL Key:sophie.elliott

    Name:
    WUSTL Key:

    Name:
    WUSTL Key:

*/

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

#define analogPin 3

long deltaTime = 1;
int val = 0;
long endTime = 1;

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);

  pinMode(analogPin, INPUT);

  Serial.begin(115200);
}

void loop ()
{
  //if(micros() > endTime){

  val = analogRead(analogPin);
  Serial.println(val);
  // endTime += deltaTime;
  // }

}




