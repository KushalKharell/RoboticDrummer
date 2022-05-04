//this function sets the hi-hat so that the pulley is in its correct initial state
//this is so the cable is pulled tight so that there is no slack
//this works by turning the motor one direction (direction that pulls the cable tight)
//it delays a full measure before actually starting to play. This ensures every drum component plays together and on the appropriate beats
int setHiHat()
{
        // one beat to set the hi hat
        timeBeginHiHat = millis();
        digitalWrite(HiHat_dirPinPos, HIGH); //cw
        for (int i = 0; i < stepsPerRevolution; i++) 
        {
          currentTime = micros();
          //delay for step interval
          digitalWrite(HiHat_stepPin, HIGH);
          //delay between steps
          while(micros() - currentTime < stepInterval)
          {
            
          }
          digitalWrite(HiHat_stepPin, LOW);

        }        

        //delay rest of previous beat
        timeEndHiHat = millis();
        while(timeEndHiHat - timeBeginHiHat < delay_val)
        {
          timeEndHiHat = millis();
          if(timeEndHiHat - timeBeginHiHat == delay_val)
          {
           
            break;
          }
        }

    //delay the rest of the measure
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
