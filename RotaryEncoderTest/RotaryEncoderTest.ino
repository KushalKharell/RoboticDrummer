

//defining pins
#define CLK 3 //clock pin on rotary encoder
#define DT 20 //pin for direction of rotary encoder
#define SW 18 //button on rotary encoder
#define LED_Others 9 //for any beat that is not beat 1
#define LED_Beat1 10 //for beat 1
#define timeSigButton 19 //button to change time signature

//motor pins
#define dirPin 4
#define stepPin 5
#define stepsPerRevolution 600

int rotaryCounter = 0; //for keeping track of rotary position
int currentStateCLK; //rotary CLK pin state
int lastStateCLK; //last state of CLK pin
bool startMet = 0; //flag to start the metronome
String currentDir =""; //current direction of enncoder
unsigned long lastButtonPressR = 0; //last press of rotary encoder button
unsigned long lastButtonPressB = 0; //last press of time signature button

int Tempo = 120; //holds the starting tempo
int delay_val_4 = 500; //initial delay for tempo of 120 and quarter note gets beat (x/4 time)
int delay_val6_8 = 167; //initial delay for tempo of 120 and 1/8 note triplet gets beat (x/8 time)
int delay_val = delay_val_4; //holds value for LED's
int beatsPerMeasure = 4; //starting beats per measure
int count = 0; //counter for number of beats played in a measure
String timeSigValues[4] = {"4/4", "6/8", "3/4", "2/4"}; //time signature values - might be needed for lcd
int timeSig = 0; //starting time signature case

void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED_Beat1, OUTPUT);
  pinMode(LED_Others, OUTPUT);

  // Setup Serial Monitor
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);


  
  // Call updateEncoder() and timeSigUpdatewhen any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3), interrup 5 (pin 18), interrupt 4 (pin 19)
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
  attachInterrupt(5, updateEncoder, CHANGE); //encoder button interrupt
  attachInterrupt(4, timeSigUpdate, CHANGE); //time sig button interrupt

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

}

void loop() {
    tempo(); //calling tempo function 
}

//LED's light up to tempo - will control motors here
//this function also switches time signature from timeSig variable set in timeSigUpdate();
void tempo()
{
  if(startMet == 1) //if rotary button is pressed, start blinking to the tempo
  {
    //getting time signature
    switch(timeSig)
    {
      case 0: //4/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 4;
        break;
      case 1: //6/8 time
        delay_val = delay_val6_8;
        beatsPerMeasure = 6;
        break;
      case 2: //3/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 3;
        break;
      case 3: //2/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 2;
         break;
    }

    
    //motor();
    
    //if on beat 1
    if(count == 0)
    {
      Serial.print("\n delay_val is: ");
      Serial.print(delay_val);
      Serial.print("\n\n");
      digitalWrite(LED_Beat1, HIGH);
      delay(50);
      digitalWrite(LED_Beat1, LOW);
      delay(delay_val-50);
      count++;
    }

    //if on any other beat
   else
    {
      digitalWrite(LED_Others, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(LED_Others, LOW);    // turn the LED off by making the voltage LOW
      delay(delay_val-50);
      count++;
    }
      //if at max number of beats per measure
      if (count >= beatsPerMeasure)
      {
        count = 0;
      }
  }

  
}

/*void motor()
{
  // clockwise
    digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) 
  {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay_val);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay_val);
  }

  //counter-clockwise
    digitalWrite(dirPin, LOW);

  for (int i = 0; i < stepsPerRevolution; i++) 
  {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(delay_val);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delay_val);
  }
}*/


//interrupt function for encoder
void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if ((digitalRead(DT) == currentStateCLK) && (Tempo > 60))
    {
        rotaryCounter--;
        currentDir ="CCW";

        Tempo -= 1; //decrement the tempo by 1

        delay_val_4 = 60000/Tempo; //get new delay value for x/4 time sig
        delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig

       /* if(timeSig != 1)
        {
          delay_val = delay_val_4;
        }
        else
        {
          delay_val = delay_val6_8;
        }*/
    } 
    
    else if((digitalRead(DT) != currentStateCLK) && (Tempo < 250))
    {
      // Encoder is rotating CW so increment
        rotaryCounter++;
        currentDir ="CW";

        Tempo += 1;
        delay_val_4 = 60000/Tempo; //get new delay value fpr x/4 time sig
        delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig
        
       /* if(timeSig != 1)
        {
          delay_val = delay_val_4;
        }
        else
        {
          delay_val = delay_val6_8;
        }*/
      
    }
    Serial.print("Tempo:" );
    Serial.print(Tempo);
    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | rotaryCounter: ");
    Serial.println(rotaryCounter);
    Serial.print("\ntime signature is: ");
    Serial.print(timeSig);
    Serial.print("\n");

    Serial.print("\n");
    Serial.print("6/8 delay: ");
    Serial.print(delay_val6_8);
    Serial.print("\n");
    Serial.print("4/4 delay: ");
    Serial.print(delay_val_4);
    Serial.print("\n\n");
    
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK; 

  // Read the button state
  int btnState = digitalRead(SW);

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPressR > 50) {
      Serial.println("Button pressed!");
      startMet = !startMet;
    }

    // Remember last button press event
    lastButtonPressR = millis();
  }

  // Put in a slight delay to help debounce the reading
  delay(1);
}

//interrupt function for time signature button - need to debounce this because sometimes it skips beatsPerMeasure
void timeSigUpdate()
{
  if (digitalRead(timeSigButton) == HIGH)
  {
    if (millis() - lastButtonPressB > 50) 
    {
      timeSig++;
      Serial.print("Time sig button pressed");
      Serial.print("\n");
      Serial.print("Time sig is: ");
      Serial.print(timeSig);
      Serial.print("\n");
      Serial.print(sizeof(timeSigValues));
      Serial.print("\n");
    }
      //if timeSig is greater than number of possible time signatures, reset it back to first time signature option
      if(timeSig >= 4) //need to replace "4" with number of time signature options - think about how to do this
      {
        timeSig = 0;
      }
      lastButtonPressB = millis();
  }
  

}
