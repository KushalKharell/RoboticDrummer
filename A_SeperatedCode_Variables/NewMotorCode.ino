/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: number of revolutions, speed and direction. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:


//-----------------


/*
//void loop() {
  // Set the spinning direction clockwise:
  


// Set the spinning direction counterclockwise:
   digitalWrite(dirPinPos, LOW);
Serial.print("stepper 1 rev quickly counterclockwise");
Serial.print("\n");
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
  //---------------------------------
*/
/*
  digitalWrite(dirPinPos1, LOW);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(100);
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(100);
    Serial.print("stepper 1 rev slowly clockwise");
Serial.print("\n");
  }

  delay(1000); //delay set 50 ms

  digitalWrite(dirPinPos, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
    Serial.print("stepper 1 rev slowly clockwise");
Serial.print("\n");
  }


  

  delay(1000); //delay set 50 ms
*/
  //--------------------------------
/*
   digitalWrite(dirPinPos1, HIGH);
Serial.print("stepper 1 rev quickly counterclockwise");
Serial.print("\n");
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(100);
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(100);
  }
*/

  
/*

  
  delay(1000);

  // Set the spinning direction clockwise:
  digitalWrite(dirPinPos, HIGH);

Serial.print("stepper 1 rev quickly clockwise");
Serial.print("\n");
  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  // Set the spinning direction counterclockwise:
     digitalWrite(dirPinPos, LOW);
Serial.print("stepper 1 rev quickly counterclockwise");
Serial.print("\n");
  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(50);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(50);
  }

  delay(1000);
  */
//}
