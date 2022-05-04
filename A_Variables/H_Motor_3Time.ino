
//motor code for 3/4 and 6/8 time
//this code is very similar to motor_4Time, but each drum component plays on a different beat
//note: upper limit for 6/8 time is 82 bpm. can increase limit by changing the delay between steps
//      can also increase this is the step size is changed (on motor drivers). All code for motors will have to be modified to account 
//      for the new delay between steps if the step size of the motors is changed
void motor_3Time()
{
  //hi hat in 3/4 time - plays on beats 2 and 3
  if(Kick_Sig == 0 && Hi_Hat_Sig == 1)
  {
    //checking if 3/4 time or 6/8 time. if 6/8 time, the tempo must be <= to 82
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
      //set hi-hat so pulley cable is pulled tightly
      if(hiHatFlag == 1)
      {
        setHiHat();
        hiHatFlag = 0;
      }
       /*Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");*/

          //delay hi-hat on beat 1
          timeBeginHiHat = millis();
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val)
            {
             
              break;
            }
          }

          //play hi-hat on beats 2 and 3
          for(int j = 0; j < 2; j++)
          {
            timeBeginHiHat = millis();
            digitalWrite(HiHat_dirPinPos, LOW); 
            for (int i = 0; i < 90; i++) //adjust i to change step size (or set to stepsPerRevolution if a constant value)
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(HiHat_stepPin, HIGH);
              
              //check if snare is on and fire solenoid if so
              if(Snare_Sig == 1)
              {
                digitalWrite(Solenoid1, HIGH); 
              }

              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(HiHat_stepPin, LOW);
              //reverse solenoid direction so current is not high
              if(Snare_Sig == 1)
              {
                digitalWrite(Solenoid1, LOW); //cw                
              }

            }

          //delay rest of previous half beat
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val/2)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val/2)
            {
             
              break;
            }
          }

            //reverse motor direction
            timeBeginHiHat = millis();
            digitalWrite(HiHat_dirPinPos, HIGH); 
            for (int i = 0; i < 100; i++) //change value of i to adjust step size of motor (or set to stepsPerRevolution if a constant value)
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

            //delay rest of previous half beat
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



//if only kick is on
//kick only plays on beat 1
//NOTE: if snare and kick are on and hi-hat is off, the delay is incorrect for the snare
//      i.e., the solenoid does not fire at the correct time
//      Further testing and modification to the delay is needed to fix this

   if(Kick_Sig == 1 && Hi_Hat_Sig == 0)
   {
    //checking if 3/4 time or 6/8 time. if 6/8 time, the tempo must be <= to 82
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
      /* Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");*/

            //play kick on beat 1
            timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, HIGH); //cw
            for (int i = 0; i < 90; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }
          //delay rest of previous half beat
          timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick == delay_val/2)
            {
             
              break;
            }
          }
            //reverse kick direction         
            timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, LOW); //ccw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < 100; i++) //change i to modify step size
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }

          //checking if snare is on so it can play on beats 2 and 3
          //the delay in this part is not correct. There is a similar issue to when the snare is playing by itself
          //further testing is needed to fix this
          if(Snare_Sig == 1)
          {
              timeBeginHiHat = millis();
            // Spin the stepper motor 1 revolution quickly:

                currentTime = micros();
                //delay for step interval

                  digitalWrite(Solenoid1, HIGH);

                //we are still unsure why Serial.print() is needed here - the solenoid will not fire without it
                  while(micros() - currentTime < stepInterval)
                  {
                    Serial.print("TEST");
                    Serial.print("TEST");
                    Serial.print("TEST");Serial.print("TEST");Serial.print("TEST");Serial.print("TEST");
                  }
                  

                  digitalWrite(Solenoid1, LOW);         

                

          
          /*
              while(timeEndHiHat - timeBeginHiHat < delay_val/2)
              {
                timeEndHiHat = millis();
                if(timeEndHiHat - timeBeginHiHat == delay_val/2)
                {
                 
                  break;
                }
              }*/
              
            
             
          }

          //delay rest of previous beat
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


 
   //this part of the code combines the code for kick and hi hat (previous two code blocks)
   //essentially, the kick and hi hat are told to move opposite each other so that they play on opposite beats
   //kick on 1, hi hat on 3 and 4
   //snare signal is checked in the first "for" loop - again, we only want it to play on beats 3 and 4
  if(Kick_Sig == 1 && Hi_Hat_Sig == 1)
  {
    if(timeSig == 2 || (timeSig == 1 && Tempo <= 82))
    {
       /*Serial.print("Delay val in seconds: ");
       Serial.print(delay_val);
       Serial.print("\n\n");*/
       //set hi hat so cable on pulley is pulled tightly
      if(hiHatFlag == 1)
      {
        setHiHat();
        hiHatFlag = 0;
      }
            //only play kick on beat 1
            timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, LOW); //cw
            for (int i = 0; i < 90; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }
          //delay rest of previous half a beat
          timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick == delay_val/2)
            {
             
              break;
            }
          }

         //reverse direction of kick
          timeBeginKick = millis();
            digitalWrite(Kick_dirPinPos, HIGH); //ccw
          // Spin the stepper motor 1 revolution quickly:
            for (int i = 0; i < 100; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(Kick_stepPin, HIGH);
              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(Kick_stepPin, LOW);
      
            }

          //delay rest of previous half a beat
            timeEndKick = millis();
          while(timeEndKick - timeBeginKick < delay_val/2)
          {
            timeEndKick = millis();
            if(timeEndKick - timeBeginKick >= delay_val/2)
            {
             
              break;
            }
          }

          //play hi hat on beats 2 and 3
        for(int j = 0; j < 2; j++)
          {
            timeBeginHiHat = millis();
            digitalWrite(HiHat_dirPinPos, LOW);
            for (int i = 0; i < 90; i++) 
            {
              currentTime = micros();
              //delay for step interval
              digitalWrite(HiHat_stepPin, HIGH);    
              //check if snare is on and fire solenoid if so
              if(Snare_Sig == 1)
              {
                digitalWrite(Solenoid1, HIGH);        
              }
              //delay between steps
              while(micros() - currentTime < stepInterval)
              {
                
              }
              
              digitalWrite(HiHat_stepPin, LOW);  
              //reverse direction of solenoid to cut current
              if(Snare_Sig == 1)
              {
                digitalWrite(Solenoid1, LOW);        
              }
            }

          //delay rest of previous half a beat
          timeEndHiHat = millis();
          while(timeEndHiHat - timeBeginHiHat < delay_val/2)
          {
            timeEndHiHat = millis();
            if(timeEndHiHat - timeBeginHiHat == delay_val/2)
            {
             
              break;
            }
          }

            //reverse direction of hi hat
            timeBeginHiHat = millis();
            digitalWrite(HiHat_dirPinPos, HIGH); 
            for (int i = 0; i < 100; i++) 
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

          //delay rest of previous half beat
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



  
