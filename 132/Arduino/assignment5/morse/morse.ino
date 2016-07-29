/* morse

    CSE 132 - Assignment 5

    Fill this out so we know whose assignment this is.

    Name: Elan Miller
    WUSTL Key: elanbmiller

    and if two are partnered together

    Name:
    WUSTL Key:
*/

#include "morse.h"
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
ST7036 lcd = ST7036 ( 2, 16, 0x7c );

#define ledPin 7

int readVal = 0;
String holder = "";
int hold = 0;
int converted = 0;
int locationCount = 1;


void setup() {
  Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);


  pinMode(ledPin, OUTPUT);
}


bool isFirst = false;
void loop() {

  if (Serial.available() > 0) {

    holder = "";
    readVal = Serial.read();
    converted = convertByte(readVal);
    
   
    while (converted != -1) {
      holder += (char)readVal;
      Serial.print("holder 1 :");
      Serial.println(holder);
      Serial.flush();
      hold = Serial.read();
      readVal = (char)hold;
      Serial.print("hold");
      Serial.println(hold);

      flashLight(converted);

      converted = convertByte(hold);
      Serial.print("Converted Byte : ");
      Serial.println(converted);
    }

   

    if (converted == -1) {
      Serial.print("holder 2: ");
      Serial.println(holder);
      if ( (locationCount % 2) == 1) {
        lcdClearLine(0);
        lcd.setCursor(0, 0);
        lcd.print(holder);
        locationCount++;
      }

      else {
        
        Serial.print("NEW HOLDER");
        Serial.println(holder);
        lcdClearLine(1);
        lcd.setCursor(1, 0);
        lcd.print(holder);
        locationCount++;
      }

    }

  }




/**if (Serial.available()>0){
    readVal = Serial.read();
    converted = convertByte(readVal);
    flashLight(converted);
    lcd.print((char)readVal);
  }**/

}
void lcdClearLine(int r) {
  lcd.setCursor(r, 0);
  for (int i = 0; i < 16; ++i) {
    lcd.print(" ");
  }
}

void flashLight(int convertByteVal) {
  for (int i = 0; i < 5; ++i) {
    if (morse_chars[convertByteVal][i] != 0) {
      if (morse_chars[convertByteVal][i] == 1) {
        dot();
        off();
      }
      else {
        dash();
        off();
      }
    }
    else {
      offLetter();
      break;

    }
  }
}

void dot() {
  unsigned long dotTime = millis();
  while ( (dotTime + 500) > millis() ) {
    digitalWrite(ledPin, HIGH);
  }
  digitalWrite(ledPin, LOW);
}

void dash() {
  unsigned long dashTime = millis();
  while ( (dashTime + 1500) > millis() ) {
    digitalWrite(ledPin, HIGH);
  }
  digitalWrite(ledPin, LOW);
}

void off() {
  unsigned long offTime = millis();
  while (offTime + 500 > millis()) {
    digitalWrite(ledPin, LOW);
  }
}

void offLetter() {
  unsigned long offTime = millis();
  while (offTime + 1500 > millis()) {
    digitalWrite(ledPin, LOW);
  }
}

void offWord() {
  unsigned long offTime = millis();
  while (offTime + 3500 > millis()) {
    digitalWrite(ledPin, LOW);
  }
}


/** 

 if (converted == -1) {
      Serial.print("holder 2: ");
      Serial.println(holder);
      if ( (locationCount % 2) == 1) {
        lcdClearLine(0);
        lcd.setCursor(0, 0);
        lcd.print(holder);
        locationCount++;
      }

      else {
        Serial.print("NEW HOLDER");
        Serial.println(holder);
        lcdClearLine(1);
        lcd.setCursor(1, 0);
        lcd.print(holder);
        locationCount++;
      }

    }

  }

  }
**/
