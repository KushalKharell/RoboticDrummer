//interrupt function for time signature button - need to debounce this because sometimes it skips beatsPerMeasure
void timeSigUpdate()
{
  if (digitalRead(timeSigButton) == HIGH)
  {
    if (millis() - lastButtonPressB > 50) 
    {
      timeSig++;
      Serial.print("Time sig button pressed");
      Serial.print("\n");
      Serial.print("Time sig is: ");
      Serial.print(timeSig);
      Serial.print("\n");
      Serial.print(sizeof(timeSigValues));
      Serial.print("\n");
    }
      //if timeSig is greater than number of possible time signatures, reset it back to first time signature option
      if(timeSig >= 4) //need to replace "4" with number of time signature options - think about how to do this
      {
        timeSig = 0;
      }
      lastButtonPressB = millis();
  }
  

}
