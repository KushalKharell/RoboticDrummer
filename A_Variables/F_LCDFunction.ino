//update LCD Screen

void LCD_Menu()
{   

//left side 
  lcd.setCursor(0,0);           
  lcd.print("Tempo");
  lcd.setCursor(0,1);           
  lcd.print(Tempo);
  
  if(Fun_called == 1)
  { //if the selector is on tempo
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
    if(Fun_called == 2)
    { //if the selector is on time sig

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

//commented out because this will be changed later
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
      if(Fun_called == 3)
      { //if the selector is on tempo


      lcd.setCursor(4,1);           
      lcd.print("  ");
      lcd.setCursor(4,3);           
      lcd.print("  ");
      lcd.setCursor(16,1);           
      lcd.print(Curr_Selection);
      lcd.setCursor(16,3);           
      lcd.print("  ");
    }
  
  //commented out because this will be changed later
  lcd.setCursor(12,2);           
  lcd.print("Kick");
  lcd.setCursor(12,3);           
  lcd.print(Kick_Status);
  
   if(Fun_called == 4)
   { //if the selector is on tempo
      lcd.setCursor(4,1);           
      lcd.print("  ");
      lcd.setCursor(4,3);           
      lcd.print("  ");
      lcd.setCursor(16,1);           
      lcd.print("  ");
      lcd.setCursor(16,3);           
      lcd.print(Curr_Selection);
    }
  

  
 }
