
//motor code for 4/4 and 2/4 time
//hi hat and snare play on 2 and 4. kick plays on 1 and 3
void motor_4Time()
{   

  //if the hi-hat selection is set to "ON" (Hi_Hat_Sig is 1), turn motor on
  if(Hi_Hat_Sig == 1 && Kick_Sig == 0)
  {
    //to properly set the pulley and cable so there is no slack
      if(hiHatFlag == 1)
      {
        setHiHat();
        hiHatFlag = 0;
      }

        //delay for beat 1
        timeEndHiHat = millis();
        while(timeEndHiHat - timeBeginHiHat < delay_val)
        {
          timeEndHiHat = millis();
          if(timeEndHiHat - timeBeginHiHat == delay_val)
          {
           
            break;
          }
        }
     /*
     Serial.print("Delay val in seconds: ");
     Serial.print(delay_val);
     Serial.print("\n\n");*/

     //play hi hat on beat 2 or 4
     timeBeginHiHat = millis();
        //move stepper in cw directio to close hi hat
        digitalWrite(HiHat_dirPinPos, LOW); 
        for (int i = 0; i < 90; i++) //modify i value to change step size (or replace with stepsPerRevolution if a constant value)
        {
          currentTime = micros(); //getting current time for calculating delay between steps
          digitalWrite(HiHat_stepPin, HIGH);
          
          //check if snare is also on. if so, fire the solenoid
          //this is only checked in this first "for" loop because it only needs to fire on beats 2 and 4
          if(Snare_Sig == 1)
          {
            digitalWrite(Solenoid1, HIGH); 
          }
          
          //delay stepInterval ms
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

       //move pulley opposite direction (CCW) to release hi hat
       //notice there is no if-statement to check if the snare is on in this "for" loop
        timeBeginHiHat = millis();
        digitalWrite(HiHat_dirPinPos, HIGH); //cw
      // Spin the stepper motor 1 revolution quickly:
  
        for (int i = 0; i < 100; i++) //modify i value to change step size (or use stepsPerRevolution if a constant value)
        {
          
          currentTime = micros(); //get current time to calculate delay between steps
          //delay for step interval
          digitalWrite(HiHat_stepPin, HIGH);

          //delay stepInterval ms
          while(micros() - currentTime < stepInterval)
          {
            
          }
          digitalWrite(HiHat_stepPin, LOW);

        }

  }


  //if kick is on
  if(Kick_Sig == 1 && Hi_Hat_Sig == 0)
  {
    /*
   Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);
   Serial.print("\n\n");*/
   
   //immediately play kick since we want it to play on beat 1
   //kick moves clockwise
   //snare signal is checked in the first "for" loop - again, we only want it to play on beats 2 and 4
   timeBeginKick = millis(); 
   digitalWrite(Kick_dirPinPos, HIGH); //cw
    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < 90; i++) 
      {
        currentTime = micros(); //get current time to calculate delay between steps
        //delay for step interval
        digitalWrite(Kick_stepPin, HIGH);
        //check if snare is on and fire solenoid on beat 2 or 4 
        if(Snare_Sig == 1)
        {
            digitalWrite(Solenoid1, HIGH); //cw
        }
        //delay stepInterval ms
        while(micros() - currentTime < stepInterval)
        {
          
        }
        
        digitalWrite(Kick_stepPin, LOW);
        //reverse solenoid direction so current is not high
        if(Snare_Sig == 1)
        {
            digitalWrite(Solenoid1, LOW); //cw
        }

      }

      //delay rest of previous beat
      timeEndKick = millis();
      while(timeEndKick - timeBeginKick < delay_val)
      {
        timeEndKick = millis();
        if(timeEndKick - timeBeginKick == delay_val)
        {
         
          break;
        }
      }
     
      //move kick motor in opposite direction 
      timeBeginKick = millis();
      digitalWrite(Kick_dirPinPos, LOW);
      for (int i = 0; i < 100; i++) //modify i value to change steps (or replace with stepsPerRevolution if a constant value)
      {
        currentTime = micros();
        //delay for step interval
        digitalWrite(Kick_stepPin, HIGH);
        
        //delay stepInterval ms 
        while(micros() - currentTime < stepInterval)
        {
          
        }
        digitalWrite(Kick_stepPin, LOW);
        

      }

    //delay rest of previous beat
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

  //if both hi hat and kick are on
  if(Hi_Hat_Sig == 1 && Kick_Sig == 1)
  {

 /*  Serial.print("Delay val in seconds: ");
   Serial.print(delay_val);
   Serial.print("\n\n");*/

      //set the hi hat to pull pulley cable tight
      if(hiHatFlag == 1)
      {
        setHiHat(); 
        hiHatFlag = 0;
      }

   //this part of the code combines the code for kick and hi hat (previous two code blocks)
   //essentially, the kick and hi hat are told to move opposite each other so that they play on opposite beats
   //kick on 1 and 3, hi hat on 2 and 4
   //snare signal is checked in the first "for" loop - again, we only want it to play on beats 2 and 4
      timeBeginHiHat = millis();   
      //kick and hi hat start in opposite directions
      digitalWrite(HiHat_dirPinPos, LOW);
      digitalWrite(Kick_dirPinPos, HIGH);

    // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < 90; i++) 
      {
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        digitalWrite(Kick_stepPin, LOW);
        if(Snare_Sig == 1)
        {
             digitalWrite(Solenoid1, HIGH); //cw
        }        
        while(micros() - currentTime < stepInterval)
        {
          
        }
        digitalWrite(HiHat_stepPin, LOW);
        digitalWrite(Kick_stepPin, HIGH);
        if(Snare_Sig == 1)
        {
           digitalWrite(Solenoid1, LOW); //cw
        }
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

      //move kick and hi hat into opposite directions
      timeBeginHiHat = millis();
      digitalWrite(HiHat_dirPinPos, HIGH); //cw
      digitalWrite(Kick_dirPinPos, LOW);
//    // Spin the stepper motor 1 revolution quickly:

      for (int i = 0; i < 100; i++) 
      {
        // These lines result in 1 step:
        currentTime = micros();
        //delay for step interval
        digitalWrite(HiHat_stepPin, HIGH);
        digitalWrite(Kick_stepPin, LOW);

        while(micros() - currentTime < stepInterval)
        {
          
        }
        digitalWrite(HiHat_stepPin, LOW);
        digitalWrite(Kick_stepPin, HIGH);

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

  }

//if only the snare is on
//NOTE: The delay in this if-statement is INCORRECT
//if you turn on only the snare and play a metronome with it, it will be too slow
//additionally, the solenoid will not fire unless there are Serial.print()'s in the while loops (explained further below)
  if(Snare_Sig == 1 && Kick_Sig == 0 && Hi_Hat_Sig == 0)
  {
    //timing for delay of beat 1
     timeBeginSnare = millis();
      timeEndSnare = millis();
      //we need the snare to wait 1 full beat before firing, since we only want the snare to play on beats 2 and 4
      //for some reason, the solenoid will not fire unless there are some Serial.print()'s listed in the while loop below
      //We are not sure if it is Serial.print()'s specifically or if it can be something else
      //if there is nothing printed and it's just an empty while loop, the solenoid will not fire.
      //this also needs to be further investigated and fixed
        while(timeEndSnare - timeBeginSnare < delay_val)
        {
          Serial.print("inside the condition!!!!\n");
          Serial.print("Time begin snare");
          Serial.print(timeBeginSnare);
          Serial.print("\n");
          Serial.print("Time end snare");
          Serial.print(timeEndSnare);
          Serial.print("\n");
          timeEndSnare = millis();
          if(timeEndSnare - timeBeginSnare == delay_val)
          {
           
            break;
          }
        }

        //timer for beat 2
        currentTime = millis();
        timeBeginSnare = millis();
        digitalWrite(Solenoid1, HIGH); //cw

        //this is the delay between beats 2 and 3. It is currently not correct.
        //the value after "currentTime <" needs modified.
        //it's also possible that the order of these loops and/or the lines that get the current time in millis is not correct
        while(millis() - currentTime < 50)
        {   
 //           Serial.print("micros");
//            Serial.print(micros()); 
//            Serial.print("\n");
//            Serial.print("Current time");
//            Serial.print(currentTime); 
//            Serial.print("\n");
        }

      
        //reverse direction of the solenoid
        digitalWrite(Solenoid1, LOW); //cw

        //delay the rest of previous beat
        //timeBeginSnare = millis();
        timeEndSnare = millis();
        while(timeEndSnare - timeBeginSnare < delay_val)
        {
          timeEndSnare = millis();
          if(timeEndSnare - timeBeginSnare == delay_val)
          {
           
            break;
          }
        }





  }

}
