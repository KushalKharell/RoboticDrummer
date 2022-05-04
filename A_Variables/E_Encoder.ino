

//interrupt function for encoder
//NOTE: sometimes the rotary encoder does not update the LCD properly
//      It is sometimes late to change, and sometimes it waits to update until the button is pressed
//      Further testing is needed to determine if it is an LCD issue or encoder issue

void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  //If last and current state of CLK are different, then pulse occurred
  //React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
    
    //If the DT state is different than the CLK state then
    //the encoder is rotating CCW so decrement
    
    //Tempo selection
    //NOTE: sometimes when all the motors/solenoids are off, and the encoder tries to increase the tempo (CW movement), it will actually 
    //      decrease it.  Further testing is needed to determine why this issue occurs. It is not always consistent, either, so it's possible 
    //      it is a hardware issue.
    if(Fun_called == 1)
    {
      //If encoder is rotated counterclockwise and not at low limit of 50 bpm
      if ((digitalRead(DT) == currentStateCLK) && (Tempo > 50))
      {
          rotaryCounter--; //decrease rotaryCounter 
          currentDir ="CCW";
  
          Tempo -= 1; //decrement the tempo by 1


      } 

      //If encoder is rotated clockwise and not at high limit of 250 bpm
      else if((digitalRead(DT) != currentStateCLK) && (Tempo < 250))
      {
          rotaryCounter++; //increment rotaryCounter
          currentDir ="CW";
  
          Tempo += 1; //increment Tempo by 1

          
      }
  
    
      
    }
  

    //if on Time Signature selection
    //NOTE: sometimes a time signature is skipped when using the encoder to select a time signature
    //      Further testing is needed to determine why this is the case. This mainly happens when turning the encoder CW
    else if(Fun_called == 2)
    {

      
      //if encoder is rotated counterclockwise, round robin backwards through time sig options
      if (digitalRead(DT) == currentStateCLK)
      {
          rotaryCounter--; //decrease rotaryCounter for CCW direction
          currentDir ="CCW";
          timeSig -= 1; //decrease timeSig value by 1
          //check that timeSig is not a negative number. If so, go back to last element in timeSigValues array
          if(timeSig < 0) 
          {
            timeSig = 3;
          }

        
      } 
      
      //if encoder is rotated CW ckwise, round robin backwards through time sig options
      //for some reason it's not updating correctly on the LCD or timeSig when moving this direction
      else if(digitalRead(DT) != currentStateCLK)
      {     
          rotaryCounter++; //increase rotaryCounter for CW direction
          currentDir ="CW";


          
          timeSig += 1; //increment timeSig by 1
          //check that timeSig is not greater than num elements in timeSigValues array. If so, go back to first element in timeSigValues array
          if(timeSig >= 4)
          {
            
            timeSig = 0;
           
          }

      }
      
    }

  //if on Hi-Hat ON/OFF selection
    else if(Fun_called == 3)
    {


      //if encoder is rotated CCW or CW, change state of Hi_Hat_Sig
      if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
      {
       // Hi_Hat_Sig = !Hi_Hat_Sig; //invert Hi_Hat Sig

        if(Hi_Hat_Sig == 0)
        {
          Hi_Hat_Sig = 1;
          hiHatFlag = 1;
        }

        else if(Hi_Hat_Sig == 1)
         {
            Hi_Hat_Sig = 0;
         }
      }

    }

    //if on Kick ON/OFF selection
      else if(Fun_called == 4)
      {
          //if encoder is rotated CCW or CW, change state of Drums_Sig
        if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
        {
          Kick_Sig = !Kick_Sig; //invert Drums_Sig
  
        }
      }

      
      //if on snare ON/OFF selection
      else if(Fun_called == 5)
      {
        //if encoder is rotated CCW or CW, change state of Drums_Sig
        if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
        {
          Snare_Sig = !Snare_Sig; //invert Drums_Sig
          digitalWrite(Solenoid1, LOW); //cw
  
        }

    }

  }
  

  // Remember last CLK state
  lastStateCLK = currentStateCLK; 

/* //for encoder button
  // Read the button state
  int btnState = digitalRead(SW);

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
    //if 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPressR > 50) {
     
      Serial.println("Button pressed!");
      startMet = !startMet;
    }

    // Remember last button press event
    lastButtonPressR = millis();
  }

  // Put in a slight delay to help debounce the reading
  delay(1);
  */

  lcdChange = true; //if encoder is turned, set lcdChange to true so LCD can be updated
  
}
