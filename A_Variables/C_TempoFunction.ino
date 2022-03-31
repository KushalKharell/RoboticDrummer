
void timeSigTempo()
{

//This function is the brain of ths system
//Bascially, updateEncoder and button() are interrupts that interrupt the system anytime a signal is received from the encoder/button
//encoder and button update what they need to update. 
//timeSigTempo() updates the delay values based on the Tempo value and determines the correct timeSignature. These variables are used by every other function
//it also calls the motor() function, which currently is blinking LED's to mimic the motor. They currently only blink when Hi_Hat_Sig is set to 1 
//If you look at the Serial Monitor, you can see what the Fun_called value is from the button (1 is tempo, 2 is time sig, 3 is hi hat, 4 is drums, which will be modified later)
//For each Fun_called, you can also see the update of the values on the Serial Monitor. From there I can see that everything is updating correctly

    
    //updating tempo
    //delay_val_4 = (60000/Tempo)-timeToRun; //subtracting time for LCD_Menu() to run to get accurate tempo //try changing 60000 to 37500 -> x*75 = 500-> 37500
    delay_val6_8 = (20040/Tempo)-timeToRun; //subtracting time for LCD_Menu() to run to get accurate tempo //try changing to 12525 -> x*12525 = 167-> 12525

  //Determine the appropriate delay value based on the selected time signature and tempo
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

    //call motor() function
      motor();
      //KickMotor();

  
}
