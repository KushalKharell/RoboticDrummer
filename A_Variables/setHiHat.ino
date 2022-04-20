int setHiHat()
{
        // one beat to set the hi hat
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

    
       timeEndHiHat = millis();
        while(timeEndHiHat - timeBeginHiHat < 4*delay_val)
        {
          timeEndHiHat = millis();
          if(timeEndHiHat - timeBeginHiHat == 4*delay_val)
          {
           
            break;
          }
        }

        
        return 0;
}
