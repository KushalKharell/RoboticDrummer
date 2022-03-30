
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
      Serial.print("\n\nFun_called is: ");
      Serial.print(Fun_called);
      Serial.print("\n Tempo function");

      //If encoder is rotated counterclockwise and not at low limit of 50 bpm
      if ((digitalRead(DT) == currentStateCLK) && (Tempo > 50))
      {
          rotaryCounter--; //decrease rotaryCounter 
          currentDir ="CCW";
  
          Tempo -= 1; //decrement the tempo by 1
          Serial.print(Tempo);
          Serial.print("\n\n");

      } 

      //If encoder is rotated clockwise and not at high limit of 250 bpm
      else if((digitalRead(DT) != currentStateCLK) && (Tempo < 250))
      {
          rotaryCounter++; //increment rotaryCounter
          currentDir ="CW";
  
          Tempo += 1; //increment Tempo by 1
          Serial.print(Tempo);
          Serial.print("\n\n");
          
      }
//      Serial.print("\nTempo:" );
//      Serial.print(Tempo);
//      Serial.print(" Direction: ");
//      Serial.print(currentDir);
//      Serial.print(" | rotaryCounter: ");
//      Serial.println(rotaryCounter);
//      Serial.print("\ntime signature is: ");
//      Serial.print(timeSig);
//      Serial.print("\n");
//  
//      Serial.print("\n");
//      Serial.print("6/8 delay: ");
//      Serial.print(delay_val6_8);
//      Serial.print("\n");
//      Serial.print("4/4 delay: ");
//      Serial.print(delay_val_4);
//      Serial.print("\n\n");
      
    }
  

    //if on Time Signature selection
    else if(Fun_called == 2)
    {
      
      Serial.print("\n\nFun_called is: ");
      Serial.print(Fun_called);
      Serial.print("\n Time Sig function");
      
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
          Serial.print(timeSig);
          Serial.print("\n\n");
        
      } 
      
      //if encoder is rotated counterclockwise, round robin backwards through time sig options
      else if(digitalRead(DT) != currentStateCLK)
      {
        // Encoder is rotating CW so increment
          rotaryCounter++; //increase rotaryCounter for CW direction
          currentDir ="CW";
          timeSig += 1; //increment timeSig by 1
          //check that timeSig is not greater than num elements in timeSigValues array. If so, go back to first element in timeSigValues array
          if(timeSig >= 4)
          {
            timeSig = 0;
          }
          Serial.print(timeSig);
          Serial.print("\n\n");
  
      }
    }

  //if on Hi-Hat selection
    else if(Fun_called == 3)
    {
      Serial.print("\n\nFun_called is: ");
      Serial.print(Fun_called);
      Serial.print("\n hi Hat function");

      //if encoder is rotated CCW or CW, change state of Hi_Hat_Sig
      if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
      {
        Hi_Hat_Sig = !Hi_Hat_Sig; //invert Hi_Hat Sig
        Serial.print("Hi_Hat_Sig is: ");
        Serial.print(Hi_Hat_Sig);
        Serial.print("\n\n");
      }

    }

    //if on Drums selection
      else if(Fun_called == 4)
      {
        Serial.print("\n\nFun_called is: ");
        Serial.print(Fun_called);
        Serial.print("\n Drums Hat function");


        //if encoder is rotated CCW or CW, change state of Drums_Sig
      if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
      {
        Kick_Sig = !Kick_Sig; //invert Drums_Sig
        Serial.print("Kick Sig is: ");
        Serial.print(Kick_Sig);
        Serial.print("\n\n");
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
}
