void setup() {

  //starting the lcd 
  //lcd.begin();
  lcd.init();                    

  // Print a message to the LCD.

  lcd.backlight();  
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  
  pinMode(LED_Beat1, OUTPUT);
  pinMode(LED_Others, OUTPUT);

  

  // Setup Serial Monitor
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  /*  pinMode(stepPin, OUTPUT);
  pinMode(dirPinPos, OUTPUT);
  pinMode(dirPinNeg, OUTPUT);*/
  
  Serial.begin(9600);


  
  // Call updateEncoder() and timeSigUpdatewhen any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3), interrup 5 (pin 18), interrupt 4 (pin 19)
  attachInterrupt(1, updateEncoder, CHANGE); //encoder clk
  attachInterrupt(5, updateEncoder, CHANGE); //encoder button interrupt
  attachInterrupt(4, button, CHANGE); //time sig button interrupt

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

}

void loop() 
{   

  //need to figure out how to update the LCD screen without calling it here
  //Calling multiple functions at once causes a delay- how can we update the LCD?
   //LCD_Menu(); //calling the lcd
   timeSignature(); //calling tempo function 
  //  motor();
}
