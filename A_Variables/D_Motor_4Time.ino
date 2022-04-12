
//motor code for 4/4 and 2/4 time
void motor_4Time()
{
  //if the hi-hat selection is set to "ON" (Hi_Hat_Sig is 1), turn motor on
  if(Hi_Hat_Sig == 1 && Kick_Sig == 0)
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
     
     timeBeginHiHat = millis();
      //  Serial.print("Beat 1");
      //  Serial.print("\n\n");
        
        digitalWrite(HiHat_dirPinPos, LOW); //cw
        //digitalWrite(Solonoid1, HIGH); //cw
      // Spin the stepper motor 1 revolution quickly:
        for (int i = 0; i < stepsPerRevolution; i++) 
        {
          currentTime = micros();
          //delay for step interval
          digitalWrite(HiHat_stepPin, HIGH);
          digitalWrite(Solonoid1, HIGH); //cw
          while(micros() - currentTime < stepInterval)
          {
            
          }
          
          //delayMicroseconds(1200);
          digitalWrite(HiHat_stepPin, LOW);
          digitalWrite(Solonoid1, LOW); //cw
        }
        
        timeEndHiHat = millis();
        while(timeEndHiHat - timeBeginHiHat < delay_val)
        {
          timeEndHiHat = millis();
          if(timeEndHiHat - timeBeginHiHat == delay_val)
          {
           
            break;
          }
        }
       
      //  Serial.print("Beat 2");
      //  Serial.print("\n\n");
        timeBeginHiHat = millis();
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
  
        timeEndHiHat = millis();
        while(timeEndHiHat - timeBeginHiHat < delay_val)
        {
          timeEndHiHat = millis();
          if(timeEndHiHat - timeBeginHiHat == delay_val)
          {
           
            break;
          }
        }
  
    
  }


  if(Kick_Sig == 1 && Hi_Hat_Sig == 0)
  {
   Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);
   Serial.print("\n\n");
   
   timeBeginKick = millis();
      Serial.print("Beat 1");
      Serial.print("\n\n");
      
      digitalWrite(Kick_dirPinPos, LOW); //cw
      

    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        currentTime = micros();
        //delay for step interval
        digitalWrite(Kick_stepPin, HIGH);
        digitalWrite(Solonoid1, HIGH); //just for testing solonoid
        while(micros() - currentTime < stepInterval)
        {
          
        }
        
        //delayMicroseconds(1200);
        digitalWrite(Kick_stepPin, LOW);
        digitalWrite(Solonoid1, LOW); //just for testing solonoid

      }
      
      timeEndKick = millis();
      while(timeEndKick - timeBeginKick < delay_val)
      {
        timeEndKick = millis();
        if(timeEndKick - timeBeginKick == delay_val)
        {
         
          break;
        }
      }
     
      Serial.print("Beat 2");
      Serial.print("\n\n");
      timeBeginKick = millis();
      digitalWrite(Kick_dirPinPos, HIGH); //cw

//    // Spin the stepper motor 1 revolution quickly:

      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These lines result in 1 step:
        currentTime = micros();
        //delay for step interval
        digitalWrite(Kick_stepPin, HIGH);
        digitalWrite(Solonoid1, HIGH); //just for testing solonoid
        while(micros() - currentTime < stepInterval)
        {
          
        }
        //delayMicroseconds(1200);
        digitalWrite(Kick_stepPin, LOW);
        digitalWrite(Solonoid1, LOW); //just for testing solonoid

      }

      timeEndKick = millis();
      while(timeEndKick - timeBeginKick < delay_val)
      {
        timeEndKick = millis();
        if(timeEndKick - timeBeginKick == delay_val)
        {
         
          break;
        }
      }

  }
  
  if(Hi_Hat_Sig == 1 && Kick_Sig == 1)
  {

   Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);
   Serial.print("\n\n");
   
   timeBeginHiHat = millis();
     // Serial.print("Beat 1");
    //  Serial.print("\n\n");
      
      digitalWrite(HiHat_dirPinPos, LOW); //cw
      digitalWrite(Kick_dirPinPos, HIGH);
      //digitalWrite(Solonoid1, HIGH); //cw

    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        digitalWrite(Kick_stepPin, LOW);
        while(micros() - currentTime < stepInterval)
        {
          
        }
        
        //delayMicroseconds(1200);
        digitalWrite(HiHat_stepPin, LOW);
        digitalWrite(Kick_stepPin, HIGH);
      }
      
      timeEndHiHat = millis();
      while(timeEndHiHat - timeBeginHiHat < delay_val)
      {
        timeEndHiHat = millis();
        if(timeEndHiHat - timeBeginHiHat == delay_val)
        {
         
          break;
        }
      }
     
    //  Serial.print("Beat 2");
   //   Serial.print("\n\n");
      timeBeginHiHat = millis();
      digitalWrite(HiHat_dirPinPos, HIGH); //cw
      digitalWrite(Kick_dirPinPos, LOW);
//    // Spin the stepper motor 1 revolution quickly:

      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        // These lines result in 1 step:
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        digitalWrite(Kick_stepPin, LOW);
        while(micros() - currentTime < stepInterval)
        {
          
        }
        //delayMicroseconds(1200);
        digitalWrite(HiHat_stepPin, LOW);
        digitalWrite(Kick_stepPin, HIGH);
      }

      timeEndHiHat = millis();
      while(timeEndHiHat - timeBeginHiHat < delay_val)
      {
        timeEndHiHat = millis();
        if(timeEndHiHat - timeBeginHiHat == delay_val)
        {
         
          break;
        }
      }

  }



}
