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

   Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);

   Serial.print("\n\n");
   
      //Hi Hat motor code
      digitalWrite(HiHat_dirPinPos, LOW); //ccw
      //digitalWrite(Kick_dirPinPos, HIGH);
     
    // Spin the stepper motor 1 revolution quickly:
      timeBeginHiHat_CCW = millis();
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These four lines result in 1 step:
        digitalWrite(HiHat_stepPin, HIGH);
        //digitalWrite(Kick_stepPin, HIGH);
        delayMicroseconds(2500);
        digitalWrite(HiHat_stepPin, LOW);
        //digitalWrite(Kick_stepPin, LOW);
        //delayMicroseconds(5000);
      }
   
      timeEndHiHat_CCW = millis();
      timeToRunHiHat_CCW = timeEndHiHat_CCW-timeBeginHiHat_CCW;

    Serial.print("Hi Hat CCW time is: ");
    Serial.print(timeToRunHiHat_CCW);
    Serial.print("\n\n");

   
      
//      Serial.print("Time to turn is: ");
//      Serial.print(timeToRunHiHat);
//      Serial.print("\n");
      
      timeBeginHiHat_Switch = micros();
      digitalWrite(HiHat_dirPinPos, HIGH); //cw
      timeEndHiHat_Switch = micros();
      
      
      timeToSwitch_HiHat = (timeEndHiHat_Switch - timeBeginHiHat_Switch);
          Serial.print("Time to switch states: ");
          Serial.print(timeToSwitch_HiHat);
          Serial.print("\n\n");
          
//      //digitalWrite(Kick_dirPinPos, LOW);

    // delay(delay_val-timeToRunHiHat_CCW);
     
    Serial.print("Total delay between beats 1 and 2: ");
    Serial.print(delay_val-timeToRunHiHat_CCW-timeToSwitch_HiHat/1000);
    Serial.print("\n\n");
        timeBeginHiHat_CW = millis();
//    // Spin the stepper motor 1 revolution quickly:

      if(millis()-previousMillis == delay_val)
      {
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These four lines result in 1 step:
        digitalWrite(HiHat_stepPin, HIGH);
        //digitalWrite(Kick_stepPin, HIGH);
        delayMicroseconds(2500);
        digitalWrite(HiHat_stepPin, LOW);
        //digitalWrite(Kick_stepPin, LOW);
        //delayMicroseconds(5000);
      }
      }
       timeEndHiHat_CW = millis();
      timeToRunHiHat_CW= timeEndHiHat_CW-timeBeginHiHat_CW;

      Serial.print("Time to run HiHat CW: ");
      Serial.print(timeToRunHiHat_CW);
      Serial.print("\n\n");
     // delay(delay_val-timeToRunHiHat_CW);
      //delay(delay_val);
      Serial.print("Total time between beats 2 and 3: ");
      Serial.print(delay_val-timeToRunHiHat_CW);
      Serial.print("\n\n");
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
