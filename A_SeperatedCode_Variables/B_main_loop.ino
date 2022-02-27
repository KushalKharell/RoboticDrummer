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

void loop() 
{
    tempo(); //calling tempo function 
    motor();
}
