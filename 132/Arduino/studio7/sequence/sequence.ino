/* sequence
 *  
 *  CSE 132 - Studio 7
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name:Elan Miller
 *  WUSTL Key:elanbmiller
 *  
 *  Name:
 *  WUSTL Key:
 *  
 *  Name:
 *  WUSTL Key:
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */
//rows are pins 0-6
//columns are pins 7-11
//to light, a column pin is set high and its corresponding row is low

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );


#define ledPinSeven 7
#define ledPinEight 8
#define ledPinNine 9
#define ledPinTen 10
#define ledPinEleven 11

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);

  pinMode(0,INPUT);
  pinMode(ledPinSeven, OUTPUT);
  pinMode(ledPinEight, OUTPUT);
  pinMode(ledPinNine, OUTPUT);
  pinMode(ledPinTen, OUTPUT);
  pinMode(ledPinEleven, OUTPUT);

}

void loop ()
{
  digitalWrite(ledPinSeven, HIGH);
  digitalWrite(0, LOW);

}
