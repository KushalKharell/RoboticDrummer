//LED's light up to tempo - will control motors here
//this function also switches time signature from timeSig variable set in timeSigUpdate();
void tempo()
{
  if(startMet == 1) //if rotary button is pressed, start blinking to the tempo
  {
    //getting time signature
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
    
    //if on beat 1
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
      //if at max number of beats per measure
      if (count >= beatsPerMeasure)
      {
        count = 0;
      }
  }

  
}
