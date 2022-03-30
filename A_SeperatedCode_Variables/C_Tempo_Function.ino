
void timeSignature()
{

//This function is the brain of ths system
//Bascially, updateEncoder and button() are interrupts that interrupt the system anytime a signal is received from the encoder/button
//encoder and button update what they need to update. But timeSignature() is the only function called in loop() continuously
//timeSignature() updates the delay values based on the Tempo value and determines the correct timeSignature. These variables are used by every other function
//it also calls the motor() function, which currently is blinking LED's to mimic the motor. They currently only blink when Hi_Hat_Sig is set to 1 
//If you look at the Serial Monitor, you can see what the Fun_called value is from the button (1 is tempo, 2 is time sig, 3 is hi hat, 4 is drums but drums doesn't work rn bc i didn't program it)
//For each Fun_called, you can also see the update of the values on the Serial Monitor. From there I can see that everything is updating correctly
//However, I'm not sure how to implement the LCD_Menu() function. If I call LCD_Menu, the LED's blink slower than they're supposed to. 
//There has to be a way to update the LCD screen as the encoders are updating the variables. Almost as if the LCD screen is being interrupted when the button/encoder sends a signal

    
    //updating tempo
    delay_val_4 = 60000/Tempo;
    delay_val6_8 = 20040/Tempo;
  
    switch(timeSig)
    {
      case 0: //4/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 4;
        break;
      case 1: //6/8 time
        delay_val = delay_val6_8;
        beatsPerMeasure = 6;
        break;
      case 2: //3/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 3;
        break;
      case 3: //2/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 2;
        break;
    }

//This code is now in motor() for testing purposes
/*    if on beat 1
    if(count == 0)
    {
      Serial.print("\n delay_val is: ");
      Serial.print(delay_val);
      Serial.print("\n\n");
      digitalWrite(LED_Beat1, HIGH);
      delay(50);
      digitalWrite(LED_Beat1, LOW);
      delay(delay_val-50);
      count++;
    }

    //if on any other beat
   else
    {
      digitalWrite(LED_Others, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(50);                       // wait for a second
      digitalWrite(LED_Others, LOW);    // turn the LED off by making the voltage LOW
      delay(delay_val-50);
      count++;
    }
      if at max number of beats per measure
      if (count >= beatsPerMeasure)
      {
        count = 0;
      }
  }
*/
      //LCD_Menu(); Try commenting and uncommenting this to see the difference in the LED's blinking. Use a metronome app if you need to really see the difference
      motor();

  
}
