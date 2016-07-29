/* cricket
 *  
 *  CSE 132 - Assignment 3
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Elan Miller
 *  WUSTL Key: elanbmiller
 *  
 *  and if two are partnered together
 *  
 *  Name:Nikki Wines
 *  WUSTL Key:catherinewines
 */
#define redPin 2 
#define analogPin 0
#define FILTER_COUNTS 5
#define BLINK_DURATION 200

float temperatures[FILTER_COUNTS];
int count = 0;
float avg = 0;

int val = 0;

float msPerChirp = 0;
//float chirpEnd = 0;

bool on = false;    //keep track of whether LED is on

long int end = 250;//used to print vals 4 times a second

void setup() {
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  pinMode(redPin, OUTPUT);
  analogReference(INTERNAL);
}



  int Firstval = analogRead(analogPin);
  float Firsttemp = ((1.1 * Firstval * 100.0) / 1024) - 50;
  float FirstmsPerChirp = (1.0 / (( (7.0*Firsttemp)/60.0 - 0.5))) * 1000.0;
  float chirpEnd = FirstmsPerChirp;


void loop() {
 
  
  
  /*
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  delay(1000);
*/
  val = analogRead(analogPin);
  float temp = ((1.1 * val * 100.0) / 1024) - 50;
  msPerChirp = (1.0 / (( (7.0*temp)/60.0 - 0.5))) * 1000.0;

  if(millis() > chirpEnd){
    

    int waitTimeOne = msPerChirp - BLINK_DURATION;
    int waitTimeTwo = BLINK_DURATION;
    if(on == false){
      if((millis() - chirpEnd) >= waitTimeOne){
        digitalWrite(redPin, HIGH);
        chirpEnd += msPerChirp; //increase chirpEnd by msPerChirp 
        on = true;
      }
    }
    else{
      if((millis() - chirpEnd) >= waitTimeTwo){
      digitalWrite(redPin, LOW);
      chirpEnd += msPerChirp; //increase chirpEnd by msPerChirp
      on = false;
      }
    }
  }
  
  //code for average temp values
  if(millis() > end){
    end += 250;
    
  float sum = 0;
    
    if(count < 5){
      temperatures[count % FILTER_COUNTS] = temp;
      count++;
      for(int i = 0; i < count; ++i){
        sum += temperatures[i];
      }
      avg = sum/count;
    }
    else{
      temperatures[count % FILTER_COUNTS] = temp;
      count++;
      for(int i = 0; i < FILTER_COUNTS; ++i){
        sum += temperatures[i];
      }
      avg = sum/5;
    }
    
    Serial.print(temp);Serial.print(", ");Serial.println(avg);
    //Serial.write((int)temp);
    //Serial.println("Normal temp");Serial.println(temp);
}
 
}
