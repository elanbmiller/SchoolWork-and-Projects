/* indicator
 *  
 *  CSE 132 - Assignment 2
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Elan Miller
 *  WUSTL Key: elanbmiller
 *  
 *  and if two are partnered together
 *  
 *  Name: Nikki Wines
 *  WUSTL Key: catherinewines
 */

#define greenPin 3
#define redPin 5
#define bluePin 6
#define analogPin 0
int val = 0;

//variables for rgb values
int green = 0;  
int red = 0;
int blue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
}

void loop() {
  val = analogRead(analogPin);    //read the pin

  if(val <= 682){
    val = (int)((((float)val)/682) * 255);
    red = 0;
    green = 255 - val;
    blue = val;

  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  }

  //make red pin flash
  else{
    red = 255;
    green = 0;
    blue = 0;
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, red);
    delay(1000);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
    delay(1000);
  }
}
