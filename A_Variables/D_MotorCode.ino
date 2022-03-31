void motor()
{
  //if the hi-hat selection is set to "ON" (Hi_Hat_Sig is 1), turn motor on
  if(Hi_Hat_Sig == 0)
  {
    
    //LED Testing - uncomment to test tempo with LED's
    /*
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

      if (count >= beatsPerMeasure)
      {
        count = 0;
      }

   */
   
      //Hi Hat motor code
      digitalWrite(HiHat_dirPinPos, LOW);
      //digitalWrite(Kick_dirPinPos, HIGH);
      Serial.print("stepper 1 rev quickly counterclockwise");
      Serial.print("\n");
    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These four lines result in 1 step:
        digitalWrite(HiHat_stepPin, HIGH);
        //digitalWrite(Kick_stepPin, HIGH);
        delayMicroseconds(delay_val);
        digitalWrite(HiHat_stepPin, LOW);
        //digitalWrite(Kick_stepPin, LOW);
        delayMicroseconds(delay_val);
      }

      digitalWrite(HiHat_dirPinPos, HIGH);
      //digitalWrite(Kick_dirPinPos, LOW);
      
      Serial.print("stepper 1 rev quickly counterclockwise");
      Serial.print("\n");
    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These four lines result in 1 step:
        digitalWrite(HiHat_stepPin, HIGH);
        //digitalWrite(Kick_stepPin, HIGH);
        delayMicroseconds(delay_val);
        digitalWrite(HiHat_stepPin, LOW);
        //digitalWrite(Kick_stepPin, LOW);
        delayMicroseconds(delay_val);
      }
      
  }

  
}

//{
//
//
//
//  // clockwise
//    digitalWrite(dirPin, HIGH);
//
//  // Spin the stepper motor 1 revolution slowly:
//  for (int i = 0; i < stepsPerRevolution; i++) 
//  {
//    // These four lines result in 1 step:
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(delay_val);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(delay_val);
//  }
//
//delay(50);
//
//  //counter-clockwise
//    digitalWrite(dirPin, LOW);
//
//  for (int i = 0; i < stepsPerRevolution; i++) 
//  {
//      // These four lines result in 1 step:
//      digitalWrite(stepPin, HIGH);
//      delayMicroseconds(delay_val);
//      digitalWrite(stepPin, LOW);
//      delayMicroseconds(delay_val);
//  }
//}
