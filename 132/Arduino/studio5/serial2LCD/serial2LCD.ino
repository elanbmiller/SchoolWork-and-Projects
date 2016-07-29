/* serial2LCD
 *  
 *  CSE 132 - Studio 5
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
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );


void setup() {
  lcd.init();
  lcd.setContrast(0);
  Serial.begin(9600);
}


int count = 0;  
int lineCount = 0; 
void loop() {
  char ch = ' ';
  char holder[16];

  
     while(Serial.available()){
      ch = Serial.read(); 
      if(lineCount % 2 == 1){
         lineCount++;
         lcd.setCursor (1,0);
         while(ch != '\r'){
          holder[count] = ch;
          count++;
          ch = Serial.read();
          }
          for(int i = 0; i < sizeof(holder); ++i){
            lcd.print(holder[i]);
          }
      }
      else{
          lineCount++;
          while(ch != '\r'){
          holder[count] = ch;
          count++;
          ch = Serial.read();
          }
          for(int i = 0; i < sizeof(holder); ++i){
            lcd.print(holder[i]);
          }
      }
          
//          holder = "";
//          
//            lcd.setCursor (1,0);
//            ch = Serial.read();
//            while(ch != '\r'){
//            holder += (String)ch;
//            ch = Serial.read();
//            }
//            lcd.print(holder);
//            holder = "";
         
//         if(ch == '\r'){
//            count++;
//           
//            if((count % 2) == 1){
//            lcd.setCursor (1,0);
//             ch2 = Serial.read(); 
//             lcd.print(ch2);
//            }
//            else{
//              lcd.clear();
//               ch3 = Serial.read(); 
//                lcd.print(ch3);
//            }
//          
//          }
       }



 
}


