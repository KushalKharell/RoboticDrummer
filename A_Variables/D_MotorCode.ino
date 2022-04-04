void motor()
{

  
  //if the hi-hat selection is set to "ON" (Hi_Hat_Sig is 1), turn motor on
  if(Hi_Hat_Sig == 0)
  {
    /*
   Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);
   Serial.print("\n\n");
    //LED Testing - uncomment to test tempo with LED's
    
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
   
   timeBeginHiHat_CW = millis();
      Serial.print("Beat 1");
      Serial.print("\n\n");
      
      digitalWrite(HiHat_dirPinPos, LOW); //cw

    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        while(micros() - currentTime < stepInterval)
        {
          
        }
        
        //delayMicroseconds(1200);
        digitalWrite(HiHat_stepPin, LOW);

      }
      
      timeEndHiHat_CW = millis();
      while(timeEndHiHat_CW - timeBeginHiHat_CW < delay_val)
      {
        timeEndHiHat_CW = millis();
        if(timeEndHiHat_CW - timeBeginHiHat_CW == delay_val)
        {
         
          break;
        }
      }
     
      Serial.print("Beat 2");
      Serial.print("\n\n");
      timeBeginHiHat_CCW = millis();
      digitalWrite(HiHat_dirPinPos, HIGH); //cw

//    // Spin the stepper motor 1 revolution quickly:

      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These lines result in 1 step:
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        while(micros() - currentTime < stepInterval)
        {
          
        }
        //delayMicroseconds(1200);
        digitalWrite(HiHat_stepPin, LOW);

      }

      timeEndHiHat_CCW = millis();
      while(timeEndHiHat_CCW - timeBeginHiHat_CCW < delay_val)
      {
        timeEndHiHat_CCW = millis();
        if(timeEndHiHat_CCW - timeBeginHiHat_CCW == delay_val)
        {
         
          break;
        }
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
