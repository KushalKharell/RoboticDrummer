

void snare()
{
  if(Snare_Sig == 0 && Kick_Sig == 1 && Hi_Hat_Sig == 1)
  {
     
     timeBeginSnare = millis();
      //  Serial.print("Beat 1");
      //  Serial.print("\n\n");
        
        digitalWrite(Solonoid1, HIGH); //cw
     
        digitalWrite(Solonoid1, LOW); //cw
        
        
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
