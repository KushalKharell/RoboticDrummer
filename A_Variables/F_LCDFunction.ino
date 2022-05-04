//update LCD Screen

void LCD_Menu()
{   


//left side 
  lcd.setCursor(0,0);           
  lcd.print("Tempo");
  lcd.setCursor(0,1);           

  if(Tempo < 100)
  {
    lcd.print(" ");
  }
  lcd.print(Tempo);

  //if the selector is on tempo
  if(Fun_called == 1)
  { 
      lcd.setCursor(4,1);           
      lcd.print(Curr_Selection);
      lcd.setCursor(4,3);           
      lcd.print("  ");
      lcd.setCursor(16,1);           
      lcd.print("  ");
      lcd.setCursor(16,3);           
      lcd.print("  ");
    }

  lcd.setCursor(0,2);           
  lcd.print("Time Sig");
  lcd.setCursor(0,3);           
  lcd.print(timeSigValues[timeSig]);

  //if the selector is on time sig
    if(Fun_called == 2)
    { 

      lcd.setCursor(4,1);           
      lcd.print("  ");
      lcd.setCursor(4,3);           
      lcd.print(Curr_Selection);
      lcd.setCursor(16,1);           
      lcd.print("  ");
      lcd.setCursor(16,3);           
      lcd.print("  ");
    }

//right side 
  if(Hi_Hat_Sig == 1)
  {
      Hi_Hat_Status = "ON "; 
    }
    else
    {
      
      Hi_Hat_Status = "OFF"; 
    }

  if(Kick_Sig == 1)
  {
      Kick_Status = "ON "; 
    }
    
    else
    {
      
      Kick_Status = "OFF"; 
    }
  lcd.setCursor(12,0);           
  lcd.print("Hi-Hat");
  lcd.setCursor(12,1);           
  lcd.print(Hi_Hat_Status);

  //if the selector is on hi-hat ON/OFF
    if(Fun_called == 3)
    { 
      lcd.setCursor(4,1);           
      lcd.print("  ");
      lcd.setCursor(4,3);           
      lcd.print("  ");
      lcd.setCursor(16,1);           
      lcd.print(Curr_Selection);
      lcd.setCursor(16,3);           
      lcd.print("  ");
    }
  
  lcd.setCursor(12,2);           
  lcd.print("Kick");
  lcd.setCursor(12,3);           
  lcd.print(Kick_Status);

  //if the selector is on kick ON/OFF
   if(Fun_called == 4)
   { 
      lcd.setCursor(4,1);           
      lcd.print("  ");
      lcd.setCursor(4,3);           
      lcd.print("  ");
      lcd.setCursor(16,1);           
      lcd.print("  ");
      lcd.setCursor(16,3);           
      lcd.print(Curr_Selection);
    }
  
      
  //next page
  ////if the selector is on snare ON/OFF   
   if(Fun_called == 5)
   { 
      lcd.clear();
      lcd.setCursor(0,0);           
      lcd.print("Snare");
      lcd.setCursor(0,1);      
     
      if(Snare_Sig == 1)
      {
          Snare_Status = "ON "; 
      }
        
      else
      {
        
        Snare_Status = "OFF"; 
      }  

      lcd.print(Snare_Status);
      lcd.setCursor(16,3);          
      lcd.print("  ");
      lcd.setCursor(4,1); 
      lcd.print(Curr_Selection);
    }
  
 }
