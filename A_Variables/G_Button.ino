//interrupt function for time signature button - need to debounce this because sometimes it skips beatsPerMeasure
void button()
{
  if (digitalRead(buttonPin) == HIGH)
  {
    if (millis() - lastButtonPressB > 50) 
    {
      
      Fun_called++;
      Serial.print("FunCalled: ");
      Serial.print(Fun_called);
      Serial.print("\n");
      Serial.print("ButtonPin: ");
      Serial.print(digitalRead(buttonPin));
      Serial.print("\n");

    }

    
      //if timeSig is greater than number of possible time signatures, reset it back to first time signature option
      if(Fun_called > 4) 
      {
        Fun_called = 1;
      }
      lastButtonPressB = millis();
      
  }

  
  

}
