
//motor code for 3/4 and 6/8 time
//note: upper limit for 6/8 time is 82 bpm. can increase limit by changing the delay between steps
void motor_3Time()
{
  //hi hat in 3/4 time - plays on beats 2 and 3
  if(Kick_Sig == 0 && Hi_Hat_Sig == 0)
  {
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
       Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");
       
       timeBeginHiHat_CW = millis();
     //     Serial.print("Beat 1");
     //     Serial.print("\n\n");
          
          timeEndHiHat_CW = millis();
          while(timeEndHiHat_CW - timeBeginHiHat_CW < delay_val)
          {
            timeEndHiHat_CW = millis();
            if(timeEndHiHat_CW - timeBeginHiHat_CW == delay_val)
            {
             
              break;
            }
          }
         
          
    
          for(int j = 0; j < 2; j++)
          {
        //    Serial.print("Beat ");
         //   Serial.print(j+2);
        //    Serial.print("\n\n");
            timeBeginHiHat_CW = millis();
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
    
          timeEndHiHat_CW = millis();
          while(timeEndHiHat_CW - timeBeginHiHat_CW < delay_val/2)
          {
            timeEndHiHat_CW = millis();
            if(timeEndHiHat_CW - timeBeginHiHat_CW == delay_val/2)
            {
             
              break;
            }
          }
      
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
            while(timeEndHiHat_CCW - timeBeginHiHat_CCW < delay_val/2)
            {
              timeEndHiHat_CCW = millis();
              if(timeEndHiHat_CCW - timeBeginHiHat_CCW == delay_val/2)
              {
               
                break;
              }
            }
          }
      }
  }
}
