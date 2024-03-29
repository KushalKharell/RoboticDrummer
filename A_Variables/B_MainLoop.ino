void setup() {
//-------------------------------------------------------------------------
  //starting the lcd 
  lcd.init();                    
  lcd.backlight();  
  
  //Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
//  pinMode(SW, INPUT_PULLUP);

  //set up test LEDs
  pinMode(LED_Beat1, OUTPUT);
  pinMode(LED_Others, OUTPUT);

  //hi hat motor setup
  pinMode(HiHat_stepPin, OUTPUT);
  pinMode(HiHat_dirPinPos, OUTPUT);
  pinMode(HiHat_dirPinNeg, OUTPUT);

  //kick motor setup
  pinMode(Kick_stepPin, OUTPUT);
  pinMode(Kick_dirPinPos, OUTPUT);
  pinMode(Kick_dirPinNeg, OUTPUT);

  pinMode(Solenoid1, OUTPUT);

  //Setup Serial Monitor
  Serial.begin(9600);

  //LCD Setup
  lcd.setCursor(0,0);           
  lcd.print("Tempo");
  lcd.setCursor(0,1);           
  lcd.print(Tempo);
  lcd.setCursor(0,2);           
  lcd.print("Time Sig");
  lcd.setCursor(0,3);           
  lcd.print(timeSigValues[timeSig]);
  lcd.setCursor(12,0);           
  lcd.print("Hi-Hat");
  lcd.setCursor(12,1);           
  lcd.print(Hi_Hat_Status);
  lcd.setCursor(12,2);           
  lcd.print("Kick");
  lcd.setCursor(12,3);           
  lcd.print(Kick_Status);
  lcd.setCursor(4,1);           
  lcd.print(Curr_Selection);
  lcd.setCursor(4,3);           
  lcd.print("  ");
  lcd.setCursor(16,1);           
  lcd.print("  ");
  lcd.setCursor(16,3);           
  lcd.print("  ");
 
  // Call updateEncoder(), button() when any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3), interrup 5 (pin 18), interrupt 4 (pin 19)
  attachInterrupt(1, updateEncoder, CHANGE); //encoder clk
  //attachInterrupt(5, updateEncoder, CHANGE); //encoder button interrupt
  attachInterrupt(4, button, HIGH); //time sig button interrupt

  // Read the initial state of CLK on encoder
  lastStateCLK = digitalRead(CLK);

  //-------------------------------------------------------------------------

}



void loop() 
{   


  //check if lcd changed and call LCD_Menu() if so
  if(lcdChange == true || buttonUpdate == true)
  {
    LCD_Menu();
    if(lcdChange == true)
    {
      lcdChange = false;      
    }

    if(buttonUpdate == true)
    {
      buttonUpdate = false;
    }
  }
  
   timeSigTempo(); //calling tempo function 
   


}
