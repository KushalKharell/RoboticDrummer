

void snare()
{
  if(Snare_Sig == 1 && Kick_Sig == 0 && Hi_Hat_Sig == 0)
  {
     timeBeginSnare = millis();
      //  Serial.print("Beat 1");
      //  Serial.print("\n\n");
        
        digitalWrite(Solenoid1, HIGH); //cw

        while(micros() - currentTime < stepInterval)
        { 
            
        }
     
        digitalWrite(Solenoid1, LOW); //cw
        
        
        timeEndSnare = millis();
        while(timeEndSnare - timeBeginSnare < 2*delay_val)
        {
          timeEndSnare = millis();
          if(timeEndSnare - timeBeginSnare == 2*delay_val)
          {
           
            break;
          }
        }
  }


  
}
