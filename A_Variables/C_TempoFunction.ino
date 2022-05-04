
void timeSigTempo()
{

//This function is the brain of ths system
//updateEncoder and button() are interrupts that interrupt the system anytime a signal is received from the encoder/button
//encoder and button update what they need to update
//timeSigTempo() updates the delay values based on the Tempo value and determines the correct timeSignature. These variables are used by every other function
//it also calls the motor functions depending on what time sig is chosen

    
    //updating tempo
    delay_val_4 = (60000/Tempo); //subtracting time for LCD_Menu() to run to get accurate tempo //try changing 60000 to 37500 -> x*75 = 500-> 37500
    delay_val6_8 = (20040/Tempo); //subtracting time for LCD_Menu() to run to get accurate tempo //try changing to 12525 -> x*12525 = 167-> 12525

  //Determine the appropriate delay value based on the selected time signature and tempo
  //in the case of 2/4 and 4/4 time, call the motor_4Time() function
  //in the case of 3/4 and 6/8 time, call the motor_3Time() function
    switch(timeSig)
    {
      case 0: //4/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 4;
        motor_4Time(); 
        //snare();
        break;
      case 1: //6/8 time
        delay_val = delay_val6_8;
        beatsPerMeasure = 6;
        motor_3Time();
        //snare();
        break;
      case 2: //3/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 3;
        motor_3Time();
        //snare();
        break;
      case 3: //2/4 time
        delay_val = delay_val_4;
        beatsPerMeasure = 2;
        motor_4Time();
        //snare();
        break;
    }



  
}
