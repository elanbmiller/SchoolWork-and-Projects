/* sender
 *  
 *  CSE 132 - Assignment 4
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Elan Miller
 *  WUSTL Key: elanbmiller
 *  
 *  and if two are partnered together
 *  
 *  Name:
 *  WUSTL Key:
 */

#define FILTER_COUNTS 5
 
#define debugString 0x30
#define errorString 0x31
#define timeStamp 0x32
#define potentiometerRead 0x33
#define rawTemp 0x34
#define convertedTemp 0x35
#define filteredTemp 0x36

#define tempPin  0
#define potentPin 1

int count = 0;
float temperatures[FILTER_COUNTS];
float avg = 0;

long int oneHerz = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  pinMode(potentPin, INPUT);
  analogReference(DEFAULT);
}

void loop() {

  
  if(millis() > oneHerz){
    
    unsigned long mSec = millis();    //4 bytes

    debug("This is the debug function");//send debug
    errorMessage("This is the error function");
    time(mSec);//send time
    //potent();  //send potentiometer value
    if(potent() > 800){
      errorMessage("Potentiometer is high and needs to be turned down!");
    }
    
    rawTempFunction(); //send raw temp value
    convertedTempFunction();

    //filtered temp code:
    Serial.write("!");Serial.write(filteredTemp);
    float sum = 0;
    float volt = (5.0 * analogRead(tempPin))/1024.0;
    float celsiusTemp = ((volt - 0.5)*100.0);
    
    if(count < 5){
      temperatures[count % FILTER_COUNTS] = celsiusTemp;
      count++;
      for(int i = 0; i < count; ++i){
        sum += temperatures[i];
      }
      avg = sum/count;
    }
    else{
      temperatures[count % FILTER_COUNTS] = celsiusTemp;
      count++;
      for(int i = 0; i < FILTER_COUNTS; ++i){
        sum += temperatures[i];
      }
      avg = sum/5;
    }

    unsigned long rawBits;
    rawBits = avg;

  unsigned long temp2 = rawBits >> 8;
  unsigned long temp3 = rawBits >> 16;
  unsigned long temp4 = rawBits >> 24;

  Serial.write(temp4);Serial.write(temp3);Serial.write(temp2);Serial.write(rawBits);
    
    oneHerz += 1000;
  }
}

String debug(char * arg){
    Serial.write("!");Serial.write(debugString);
    while(*arg != '\0'){
      Serial.write(*arg);
      arg++;
    }
 }

String errorMessage(char * arg){
    Serial.write("!");Serial.write(errorString);
    while(*arg != '\0'){
      Serial.write(*arg);
      arg++;
    }
 } 

 String time(unsigned long mSec){
    Serial.write("!");Serial.write(timeStamp);
    
    unsigned long mSec2 = mSec >> 8;
    unsigned long mSec3 = mSec >> 16;
    unsigned long mSec4 = mSec >> 24;
    
    Serial.write(mSec4);Serial.write(mSec3);Serial.write(mSec2);Serial.write(mSec);
} 

int potent(){
  Serial.write("!");Serial.write(potentiometerRead);
  int byteOne = analogRead(potentPin);
  int byteTwo = byteOne >> 8;
  Serial.write(byteTwo);Serial.write(byteOne);
  return byteOne;
}

String rawTempFunction(){
  Serial.write("!");Serial.write(rawTemp);
  int byteOne = analogRead(tempPin);
  int byteTwo = byteOne >> 8;
  Serial.write(byteTwo);Serial.write(byteOne);
}

String convertedTempFunction(){
  Serial.write("!");Serial.write(convertedTemp);
  float volt = (5.0 * analogRead(tempPin))/1024.0;
  float celsiusTemp = ((volt - 0.5)*100.0);
  
  unsigned long rawBits;
  //rawBits = *(unsigned long*) &celsiusTemp;

  rawBits = celsiusTemp;

  unsigned long temp2 = rawBits >> 8;
  unsigned long temp3 = rawBits >> 16;
  unsigned long temp4 = rawBits >> 24;

  Serial.write(temp4);Serial.write(temp3);Serial.write(temp2);Serial.write(rawBits);
}





