/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name:Elan Miller
 *  WUSTL Key:elanbmiller
 *  
 *  Name:Nikki Wines
 *  WUSTL Key:catherinewines
 *  
 */

#define sw1 12
#define sw2 13
#define sw3 16
#define sw4 15

//#define ledPin 8

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include "font.h"

ST7036 lcd = ST7036 ( 2, 16, 0x7c );


const int col[5] = {7, 8, 9, 10, 11};
const int row[7] = {0,1,2,3,4,5,6};


int input = 1;
int input2 = 1;
int input3 = 1;
int input4 = 1;

String lastInput= "";

int c = 0x00;  // '#'

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);

  
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);

 // pinMode(ledPin, INPUT_PULLUP);
 // pinMode(8,INPUT_PULLUP);
  
    
    pinMode(col[0], OUTPUT);
    pinMode(col[1], OUTPUT);
    pinMode(col[2], OUTPUT);
    pinMode(col[3], OUTPUT);
    pinMode(col[4], OUTPUT);

    pinMode(row[0], OUTPUT);
    pinMode(row[1], OUTPUT);
    pinMode(row[2], OUTPUT);
    pinMode(row[3], OUTPUT);
    pinMode(row[4], OUTPUT);
    pinMode(row[5], OUTPUT);
    pinMode(row[6], OUTPUT);

 /* 
    digitalWrite(col[0], LOW);
    digitalWrite(col[1], LOW);
    digitalWrite(col[2], LOW);
    digitalWrite(col[3], LOW);
    digitalWrite(col[4], LOW);

    digitalWrite(row[0], HIGH);
    digitalWrite(row[1], HIGH);
    digitalWrite(row[2], HIGH);
    digitalWrite(row[3], HIGH);
    digitalWrite(row[4], HIGH);
    digitalWrite(row[5], HIGH);
    digitalWrite(row[6], HIGH);
*/
//digitalWrite(col[0], LOW);
}

void loop () {
lcd.clear ();

input = digitalRead(sw1);    //when pressed, digitalRead value is 0, otherwise, it's 1
input2 = digitalRead(sw2);
input3 = digitalRead(sw3);
input4 = digitalRead(sw4);

if(input == 0 && lastInput != "input"){
  delay(50);
  if(input == 0){
    c = c - 16;
    lastInput = "input";
  }
}
else if(input == 1 && lastInput == "input"){
  delay(50);
  if(input == 1){
    lastInput = "";
  }
}


else if(input4 == 0 && lastInput != "input4"){
  delay(50);
  if(input4 == 0){
    if(c > 80){
      c = c - 81;
    }
    else{
    c = c + 16;
    }
    lastInput = "input4";
  }
}
else if(input4 == 1 && lastInput == "input4"){
  delay(50);
  if(input4 == 1){
    lastInput = "";
  }
}


else if(input2 == 0 && lastInput != "input2"){
  delay(50);
  if(input2 == 0){
    if(c == 95){
    c = 0;
    }
    else{
      c = c + 1;
    }
    lastInput = "input2";
  }
}
else if(input2 == 1 && lastInput == "input2"){
  delay(50);
  if(input2 == 1){
    lastInput = "";
  }
}


else if(input3 == 0 && lastInput != "input3"){
  delay(50);
  if(input3 == 0){
    c = c - 1;
    lastInput = "input3";
  }
}
else if(input3 == 1 && lastInput == "input3"){
  delay(50);
  if(input3 == 1){
    lastInput = "";
  }
}

if(c < 0){
  c = 96 + c;
}

  

  for(int i = 0; i < 5; ++i){
  digitalWrite(col[i], HIGH);
  for(int j = 0; j < 7; ++j){
    int bitVal = 1 & (font_5x7[c][i] >> (7 - j));
    if(bitVal == 1){
      digitalWrite(row[j], LOW);
    }
    else{
      digitalWrite(row[j],HIGH);
    }

  }
  
  delay(1);
  //digitalWrite(col[0],LOW);
  for(int k = 0; k < 7; ++k){
    digitalWrite(row[k],HIGH);
  }
  digitalWrite(col[i], LOW);
  }
  
  
  
  lcd.print(((char)(c + 32)));

  delay(1);
}

