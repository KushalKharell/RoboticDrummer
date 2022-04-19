

//interrupt function for encoder
void updateEncoder(){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
    
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    //Tempo selection
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
    else if(Fun_called == 2)
    {

      
      //if encoder is rotated counterclockwise, round robin backwards through time sig options
      if (digitalRead(DT) == currentStateCLK)
      {
          rotaryCounter--; //decrease rotaryCounter for CCW direction
          currentDir ="CCW";
          timeSig -= 1; //decrease timeSig value by 1
          //check that timeSig is not a negative number. If so, go back to last element in timeSigValues array
          if(timeSig < 0) //so far putting the "=" sign gets you 2/4, but skips the 3/4 completely in CCW
          {
            timeSig = 3;
          }

        
      } 
      
      //if encoder is rotated counterclockwise, round robin backwards through time sig options
      //for some reason it's not updating correctly on the LCD or timeSig when moving CW - check this
      else if(digitalRead(DT) != currentStateCLK)
      {     
         // timeSig = 0;
        // Encoder is rotating CW so increment
            
          //int flag =rotaryCounter; 
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

  //if on Hi-Hat selection
    else if(Fun_called == 3)
    {


      //if encoder is rotated CCW or CW, change state of Hi_Hat_Sig
      if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
      {
        Hi_Hat_Sig = !Hi_Hat_Sig; //invert Hi_Hat Sig

      }

    }

    //if on Kick selection


      else if(Fun_called == 4)
      {



          //if encoder is rotated CCW or CW, change state of Drums_Sig
        if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
        {
          Kick_Sig = !Kick_Sig; //invert Drums_Sig
  
        }
      }
      //if on snare selection
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

  lcdChange = true;
  
}
