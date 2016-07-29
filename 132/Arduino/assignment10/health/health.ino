/* health

    CSE 132 - Assignment 10

    Fill this out so we know whose studio this is.

    Name:Elan Miller
    WUSTL Key:elanbmiller

    Name: Nikki Wines
    WUSTL Key:catherinewines

*/

#define sw1 12

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>


#define FILTER_COUNTS 5

#define analogPin 3

#define stepsValue 0x30
#define pulseValue 0x34


#define tempPin  0
#define potentPin 1


Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );


float temperatures[FILTER_COUNTS];
float avg = 0;

long int deltaTime = 2000;

double val = 0;

int input;
int steps = 0;
double pulseCount = 0;
double previousStep = 0;
double currentStep = 0;
double nextStep = 0;


bool goingDown = false;

double xVals[3] = {350, 350, 350};
double yVals[3] = {350, 350, 350};
double x3 = 350;
double x2 = 350;
double x1 = 350;
double y3 = 0;
double y2 = 0;
double y1 = 0;
double b0 = 0.01036382;
double b1 = 0.0;
double b2 = -0.01036382;
double a1 = -1.9789467705;
double a2 = 0.97927235;

void setup(void) {
  //Serial.begin(115200);
  Serial.begin(9600);

  pinMode(analogPin, INPUT);
  pinMode(sw1, INPUT_PULLUP);
  lcd.init();
  lcd.setContrast(0);
  lcd.setCursor(0, 0);

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    lcd.print("Couldnt start");
    while (1);
  }
  mma.setRange(MMA8451_RANGE_8_G);
}


double hold = 0;
int count = 0;
double prevy2 = 1;
double prevY = 1;
double y = 0;
String line = "";


double prevPulse = 0;
double currPulse = 0;
double nextPulse = 0;
bool goingDownPulse = false;

double prevMillis = 0;
double currentMillis = 0;

void loop() {

  val = (double)analogRead(analogPin);
  x1 = x2;
  x2 = x3;
  x3 = val;

  y1 = y2;
  y2 = y3;
  y3 = y;

  double firstTerm = b0 * x3;
  double secondTerm = b2 * x1;
  double thirdTerm = a1 * y2;
  double fourthTerm = a2 * y2;

  y = firstTerm + secondTerm - thirdTerm - fourthTerm;

  Serial.print("Y VALUE: "); Serial.println(y);

  prevPulse = currPulse;
  currPulse = nextPulse;
  nextPulse = y;

  //if (millis() > deltaTime) {
  //deltaTime += deltaTime;
  if (y > 0) {
    if ( (prevPulse  < currPulse) && (currPulse > nextPulse)  ) {
      //        currentMillis = millis() - prevMillis;
      //        pulseCount = (double)60000.0/currentMillis;
      //        Serial.print("PULSECOUNT : ");Serial.println(pulseCount);
      //        prevMillis = millis();
      ++count;
    }
  }
  //}
  pulseCount = (count * 60000 / millis()) / 2;




  //        Serial.print("PrevPulse : ");Serial.println(prevPulse);
  //        Serial.print("currPulse : ");Serial.println(currPulse);
  //        Serial.print("nextPulse : ");Serial.println(nextPulse);


  //  Serial.print("PULSECOUNT : "); Serial.println(pulseCount);
  //  Serial.print("PULSE : "); Serial.println(pulseCount);


  //step stuff
  input = digitalRead(sw1);
  if (input == 0) {
    steps = 0;
  }
  // Read the 'raw' data in 14-bit counts
  mma.read();


  sensors_event_t event;
  mma.getEvent(&event);

  double xNum = event.acceleration.x;
  double zNum = event.acceleration.z;
  double yNum = event.acceleration.y;

  uint8_t o = mma.getOrientation();

  previousStep = currentStep;
  currentStep = nextStep;
  nextStep = xNum;
  if ( (currentStep < -.7) && (currentStep < previousStep) && (currentStep < nextStep) && (!goingDown) ) {
    goingDown = true;
    steps++;
  }
  else if (goingDown) {
    if (xNum > -.03) {
      goingDown = false;
    }
  }
  lcd.clear();
  lcd.print("steps: "); lcd.print(steps);
  lcd.setCursor(1, 0);
  lcd.print("pulse: "); lcd.print(pulseCount);
  delay(100);

  sendSteps(steps);
  sendPulse(pulseCount);

}



void sendSteps(int x) { //long is 4 bytes
  Serial.write("!"); Serial.write(stepsValue);

  unsigned long mSec = x;
  unsigned long mSec2 = mSec >> 8;
  unsigned long mSec3 = mSec >> 16;
  unsigned long mSec4 = mSec >> 24;

  Serial.write(mSec4); Serial.write(mSec3); Serial.write(mSec2); Serial.write(mSec);
}

void sendPulse(int y) { //long is 4 bytes
  Serial.write("!"); Serial.write(pulseValue);
  unsigned long mSec = y;
  unsigned long mSec2 = mSec >> 8;
  unsigned long mSec3 = mSec >> 16;
  unsigned long mSec4 = mSec >> 24;

  Serial.write(mSec4); Serial.write(mSec3); Serial.write(mSec2); Serial.write(mSec);
}





/*
  // if(micros() > deltaTime){
  delay(2);

  //deltaTime += deltaTime;

  val = analogRead(analogPin);

  xVals[0] = xVals[1];
  xVals[1] = xVals[2];
  xVals[2] = val;


  Serial.print("val: "); Serial.println(val);

  y = 0.01 * (xVals[2]);
  //y += 0*xVals[1];
  hold = (0.01 * xVals[0]);
  y = y - hold;
  y += 2 * yVals[1];
  y = y - yVals[0];

  yVals[0] = yVals[1];
  yVals[1] = yVals[2];
  yVals[2] = y;


  Serial.print("y : "); Serial.println(y);

  Serial.print("0 : "); Serial.print(xVals[0]); Serial.print("    "); Serial.println(yVals[0]);
  Serial.print("1 : "); Serial.print(xVals[1]); Serial.print("    "); Serial.println(yVals[1]);
  Serial.print("2 : "); Serial.print(xVals[2]); Serial.print("    "); Serial.println(yVals[2]);
  //}
*/

