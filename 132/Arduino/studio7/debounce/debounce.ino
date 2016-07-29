/* debounce
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

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
ST7036 lcd = ST7036 ( 2, 16, 0x7c );



#define ledPin 7
#define sw1 12
#define sw2 13
#define sw3 16
#define sw4 15
int input = 0;



int lastButtonState = LOW;//reading = 1;
int ledState = HIGH;
int buttonState;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);

  pinMode(sw1, INPUT_PULLUP);//12
  pinMode(sw2, INPUT_PULLUP);//13
  pinMode(sw3, INPUT_PULLUP);//16
  pinMode(sw4, INPUT_PULLUP);//15
  
  pinMode(ledPin, OUTPUT);//7

  digitalWrite(ledPin, ledState);
}

void loop ()
{
 int reading = digitalRead(sw1);
 int reading2 = digitalRead(sw2);
 int reading3 = digitalRead(sw3);
 int reading4 = digitalRead(sw3);

  if(reading != lastButtonState){
    lastDebounceTime = millis();
  }

  /*
  else if(reading2 != lastButtonState){
    lastDebounceTime = millis();
  }
  */

  /*
  else if(reading3 != lastButtonState){
    lastDebounceTime = millis();
  }
  */

  /*
  else if(reading4 != lastButtonState){
    lastDebounceTime = millis();
  }
  */
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the readinging is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }

    /*
    else if (reading2 != buttonState) {
      buttonState = reading2;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
    */

    /*
    else if (reading3 != buttonState) {
      buttonState = reading3;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
    */

    /*
    else if (reading4 != buttonState) {
      buttonState = reading4;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
    */

    
  }

  
  // set the LED:
  //lcd.clear ();
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
  
  
