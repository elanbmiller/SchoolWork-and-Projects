/* mirror
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

#define sw1 12
#define sw2 13
#define sw3 16
#define sw4 15

#define ledPin 7

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

int input = 1;
int input2 = 1;
int input3 = 1;
int input4 = 1;

int pushCount = 0;

int lastButtonState = LOW;//reading = 1;
int ledState = HIGH;
int buttonState;
long hold = 0;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
  // insert code here as needed
  
  //Serial.begin(9600);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, ledState);

}

void loop ()
{

// Serial.print("input : ");Serial.println(input);//when pressed, digitalRead value is 0, otherwise, it's 1
// digitalWrite(ledPin, input);

 
 //Serial.print("input2 : ");Serial.println(input2);
// digitalWrite(ledPin, input2);
 
// Serial.print("input3 : ");Serial.println(input3);
// digitalWrite(ledPin, input3);
 
// Serial.print("input4 : ");Serial.println(input4);
// digitalWrite(ledPin, input4);
  
  input = digitalRead(sw1);
  input2 = digitalRead(sw2);
  input3 = digitalRead(sw3);
  input4 = digitalRead(sw4);

  /*
  if(input != lastButtonState || input2 != lastButtonState || input3 != lastButtonState || input4 != lastButtonState){
    lastDebounceTime = millis();
  }
  */
  if(input != lastButtonState){
    lastDebounceTime = millis();
    hold = input;
  }

  /*
  else if(input2 != lastButtonState){
    lastDebounceTime = millis();
    hold = input2;
  }
  

  
  else if(input3 != lastButtonState){
    lastDebounceTime = millis();
    hold = input3;
  }
  

  
  else if(input4 != lastButtonState){
    lastDebounceTime = millis();
    hold = input4;
  }
  */
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if(hold != buttonState){
      buttonState = hold;

      if(buttonState == HIGH){
        ledState = !ledState;
      }
    }
  }
  
 /*
 if((input == 0 || input2 == 0 || input3 == 0 || input4 == 0)){
 pushCount++;
 lcd.clear ();
 lcd.print(pushCount);
 }

 lcd.clear ();
 lcd.print(pushCount);
  */

digitalWrite(ledPin, ledState);
lastButtonState = hold;
}
