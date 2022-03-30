void setup() {

  //starting the lcd 
  lcd.init();                    
  lcd.backlight();  
  
  //Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  //set up test LEDs
  pinMode(LED_Beat1, OUTPUT);
  pinMode(LED_Others, OUTPUT);

  //Set up motors
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  /*  pinMode(stepPin, OUTPUT);
  pinMode(dirPinPos, OUTPUT);
  pinMode(dirPinNeg, OUTPUT);*/

  //Setup Serial Monitor
  Serial.begin(9600);


  
  // Call updateEncoder(), button() when any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3), interrup 5 (pin 18), interrupt 4 (pin 19)
  attachInterrupt(1, updateEncoder, CHANGE); //encoder clk
  attachInterrupt(5, updateEncoder, CHANGE); //encoder button interrupt
  attachInterrupt(4, button, HIGH); //time sig button interrupt

  // Read the initial state of CLK on encoder
  lastStateCLK = digitalRead(CLK);
}

void loop() 
{   

  //added a timer to figure out how long the LCD_Menu() takes to run for tempo calculation
   timeBegin = millis(); //record current time before LCD_Menu()
   LCD_Menu(); //calling the lcd
   timeEnd = millis(); //record current time after LCD_Menu()
   timeToRun = timeEnd - timeBegin; //determine time between timeEnd and timeBegin. Subtracted from tempo calculations in timeSignature function
    
   timeSigTempo(); //calling tempo function 

}