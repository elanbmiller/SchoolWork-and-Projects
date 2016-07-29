/* sequence
 *  
 *  CSE 132 - Studio 9
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name:Elan Miller
 *  WUSTL Key: elanbmiller
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
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>


#define FILTER_COUNTS 5
 
#define xVal 0x34
#define yVal 0x35
#define zVal 0x36

#define tempPin  0
#define potentPin 1


Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );

int count = 0;
float temperatures[FILTER_COUNTS];
float avg = 0;

long int oneHerz = 1000;


void setup(void) {
  Serial.begin(115200);
  
  Serial.println("Adafruit MMA8451 test!");

  lcd.init();
  lcd.setContrast(0);  
  lcd.setCursor(0,0);

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    lcd.print("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_8_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  lcd.print("Orientation");
}

void loop() {
  // Read the 'raw' data in 14-bit counts
  mma.read();

  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);

  Serial.print(event.acceleration.x);Serial.print(",");Serial.print(event.acceleration.y);Serial.print(",");Serial.println(event.acceleration.z);
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
 lcd.setCursor (1,0);

   if(millis() > oneHerz){
    oneHerz += oneHerz;
    sendXval();
    sendYval();
    sendZval();
  
}


long sendXval(){//long is 4 bytes
  Serial.write("!");Serial.write(xVal);
  int byteOne = event.acceleceration.x;
  int byteTwo = byteOne >> 8;
  int byteThree = byteOne >> 16;
  int byteFour = byteOne >> 24;
  Serial.write(byteFour);Serial.write(bytethree);Serial.write(byteTwo);Serial.write(byteOne);
}

long sendYval(){//long is 4 bytes
  Serial.write("!");Serial.write(yVal);
  int byteOne = event.acceleceration.x;
  int byteTwo = byteOne >> 8;
  int byteThree = byteOne >> 16;
  int byteFour = byteOne >> 24;
  Serial.write(byteFour);Serial.write(bytethree);Serial.write(byteTwo);Serial.write(byteOne);
}

long sendZval(){//long is 4 bytes
  Serial.write("!");Serial.write(zVal);
  int byteOne = event.acceleceration.x;
  int byteTwo = byteOne >> 8;
  int byteThree = byteOne >> 16;
  int byteFour = byteOne >> 24;
  Serial.write(byteFour);Serial.write(bytethree);Serial.write(byteTwo);Serial.write(byteOne);
}




