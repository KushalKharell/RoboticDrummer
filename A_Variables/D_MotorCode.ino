void motor()
{
  //if the hi-hat selection is set to "ON" (Hi_Hat_Sig is 1)
  if(Hi_Hat_Sig == 1)
  {
    
  
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

      if (count >= beatsPerMeasure)
      {
        count = 0;
      }
  }
}

//{
//
//
//
//  // clockwise
//    digitalWrite(dirPin, HIGH);
//
//  // Spin the stepper motor 1 revolution slowly:
//  for (int i = 0; i < stepsPerRevolution; i++) 
//  {
//    // These four lines result in 1 step:
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(delay_val);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(delay_val);
//  }
//
//delay(50);
//
//  //counter-clockwise
//    digitalWrite(dirPin, LOW);
//
//  for (int i = 0; i < stepsPerRevolution; i++) 
//  {
//      // These four lines result in 1 step:
//      digitalWrite(stepPin, HIGH);
//      delayMicroseconds(delay_val);
//      digitalWrite(stepPin, LOW);
//      delayMicroseconds(delay_val);
//  }
//}