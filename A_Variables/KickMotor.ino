

void KickMotor()
{
  

  //if the kick selection is set to "ON" (Kick_Sig is 1), turn motor on
   if(Kick_Sig == 1)
   {
        digitalWrite(Kick_dirPinPos, LOW);
        Serial.print("stepper 1 rev quickly counterclockwise");
        Serial.print("\n");
      // Spin the stepper motor 1 revolution quickly:
        for (int i = 0; i < stepsPerRevolution; i++) 
        {
          // These four lines result in 1 step:
          digitalWrite(Kick_stepPin, HIGH);
          delayMicroseconds(delay_val);
          digitalWrite(Kick_stepPin, LOW);
          delayMicroseconds(delay_val);
        }
  
        digitalWrite(Kick_dirPinPos, HIGH);
        Serial.print("stepper 1 rev quickly counterclockwise");
        Serial.print("\n");
      // Spin the stepper motor 1 revolution quickly:
        for (int i = 0; i < stepsPerRevolution; i++) 
        {
          // These four lines result in 1 step:
          digitalWrite(Kick_stepPin, HIGH);
          delayMicroseconds(delay_val);
          digitalWrite(Kick_stepPin, LOW);
          delayMicroseconds(delay_val);
        }
   }
}
