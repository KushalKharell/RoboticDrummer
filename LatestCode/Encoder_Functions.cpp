#include "Encoder_Functions.h" //include the header file

void updateEncoder(int CLK, int currentStateCLK,int lastStateCLK,int DT, int Tempo,int rotaryCounter,String currentDir, int delay_val_4, int delay_val6_8, int timeSig, int SW, int lastButtonPressR, bool startMet){
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if ((digitalRead(DT) == currentStateCLK) && (Tempo > 60))
    {
        rotaryCounter--;
        currentDir ="CCW";

        Tempo -= 1; //decrement the tempo by 1

        delay_val_4 = 60000/Tempo; //get new delay value for x/4 time sig
        delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig

       /* if(timeSig != 1)
        {
          delay_val = delay_val_4;
        }
        else
        {
          delay_val = delay_val6_8;
        }*/
    } 
    
    else if((digitalRead(DT) != currentStateCLK) && (Tempo < 250))
    {
      // Encoder is rotating CW so increment
        rotaryCounter++;
        currentDir ="CW";

        Tempo += 1;
        delay_val_4 = 60000/Tempo; //get new delay value fpr x/4 time sig
        delay_val6_8 = 20040/Tempo; //get new delay value for x/8 time sig
        
       /* if(timeSig != 1)
        {
          delay_val = delay_val_4;
        }
        else
        {
          delay_val = delay_val6_8;
        }*/
      
    }
    Serial.print("Tempo:" );
    Serial.print(Tempo);
    Serial.print("Direction: ");
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
