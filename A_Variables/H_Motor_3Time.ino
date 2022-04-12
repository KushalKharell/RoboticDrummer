
//motor code for 3/4 and 6/8 time
//note: upper limit for 6/8 time is 82 bpm. can increase limit by changing the delay between steps
void motor_3Time()
{
  //hi hat in 3/4 time - plays on beats 2 and 3
  if(Kick_Sig == 0 && Hi_Hat_Sig == 1)
  {
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
       Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");
       
       timeBeginHiHat = millis();
     //     Serial.print("Beat 1");
     //     Serial.print("\n\n");
          
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val)
            {
             
              break;
            }
          }
         
          
    
          for(int j = 0; j < 2; j++)
          {
        //    Serial.print("Beat ");
         //   Serial.print(j+2);
        //    Serial.print("\n\n");
            timeBeginHiHat = millis();
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
              
              digitalWrite(HiHat_stepPin, LOW);
      
            }
    
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val/2)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val/2)
            {
             
              break;
            }
          }
      
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
            while(timeEndHiHat - timeBeginHiHat < delay_val/2)
            {
              timeEndHiHat = millis();
              if(timeEndHiHat - timeBeginHiHat == delay_val/2)
              {
               
                break;
              }
            }
          }
      }
  }



//just kick
   if(Kick_Sig == 1 && Hi_Hat_Sig == 0)
  {
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
       Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");
       
            timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, LOW); //cw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < stepsPerRevolution; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }
    
          timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick == delay_val/2)
            {
             
              break;
            }
          }
         
          timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, HIGH); //ccw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < stepsPerRevolution; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }
    

          timeEndKick = millis();
          while(timeEndKick - timeBeginKick < 2.5*delay_val)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick >= 2.5*delay_val)
            {
             
              break;
            }
          }
         }
      }


      //both
  if(Kick_Sig == 1 && Hi_Hat_Sig == 1)
  {
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
       Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");
       
            timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, LOW); //cw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < stepsPerRevolution; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }
    
          timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick == delay_val/2)
            {
             
              break;
            }
          }
         
          timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, HIGH); //ccw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < stepsPerRevolution; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }

            timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick >= delay_val/2)
            {
             
              break;
            }
          }
          
        for(int j = 0; j < 2; j++)
          {
        //    Serial.print("Beat ");
         //   Serial.print(j+2);
        //    Serial.print("\n\n");
            timeBeginHiHat = millis();
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
              
              digitalWrite(HiHat_stepPin, LOW);
      
            }
    
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val/2)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val/2)
            {
             
              break;
            }
          }
      
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
            while(timeEndHiHat - timeBeginHiHat < delay_val/2)
            {
              timeEndHiHat = millis();
              if(timeEndHiHat - timeBeginHiHat == delay_val/2)
              {
               
                break;
              }
            }
          }
      }
  }
          
  
  }



  
