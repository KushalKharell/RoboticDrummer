
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
    if(Fun_called == 1)
    {
      Serial.print("\nDT is: ");
      Serial.print(digitalRead(DT));
      Serial.print("\n");
      Serial.print("current CLK is: ");
      Serial.print(currentStateCLK);
      Serial.print("\n\n");
    
      if ((digitalRead(DT) == currentStateCLK) && (Tempo > 60))
      {
          rotaryCounter--;
          currentDir ="CCW";
  
          Tempo -= 1; //decrement the tempo by 1

          //This is now in timeSignature()
          /*delay_val_4 = 60000/Tempo; //get new delay value for x/4 time sig
          delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig*/
  
      
      } 
      
      else if((digitalRead(DT) != currentStateCLK) && (Tempo < 250))
      {
        // Encoder is rotating CW so increment
          rotaryCounter++;
          currentDir ="CW";
  
          Tempo += 1;
          
          //This is now in timeSignature()
         /* delay_val_4 = 60000/Tempo; //get new delay value fpr x/4 time sig
          delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig*/
          
      }
      Serial.print("\nTempo:" );
      Serial.print(Tempo);
      Serial.print(" Direction: ");
      Serial.print(currentDir);
      Serial.print(" | rotaryCounter: ");
      Serial.println(rotaryCounter);
      Serial.print("\ntime signature is: ");
      Serial.print(timeSig);
      Serial.print("\n");
  
      Serial.print("\n");
      Serial.print("6/8 delay: ");
      Serial.print(delay_val6_8);
      Serial.print("\n");
      Serial.print("4/4 delay: ");
      Serial.print(delay_val_4);
      Serial.print("\n\n");
      
    }
  

    else if(Fun_called == 2)
    {
      
    
      if (digitalRead(DT) == currentStateCLK)
      {
          rotaryCounter--;
          currentDir ="CCW";
          timeSig -= 1;
        
      } 
      
      else if(digitalRead(DT) != currentStateCLK)
      {
        // Encoder is rotating CW so increment
          rotaryCounter++;
          currentDir ="CW";
          timeSig += 1;
  
          
        
      }

      if(timeSig >= 4)
      {
        timeSig = 0;
      }
      
    }

    else if(Fun_called == 3)
    {
      if ((digitalRead(DT) == currentStateCLK) || (digitalRead(DT) != currentStateCLK))
      {
        Hi_Hat_Sig = !Hi_Hat_Sig;
        Serial.print("Hi_Hat_Sig is: ");
        Serial.print(Hi_Hat_Sig);
        Serial.print("\n\n");
      }

    }

  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK; 

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
}
