#include "Motor_Functions.h" //include the header file

void motor(int dirPin,int stepsPerRevolution,int stepPin,int delay_val)
{
  // clockwise
    digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) 
  {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay_val);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay_val);
  }

delay(50); 
  //counter-clockwise
    digitalWrite(dirPin, LOW);

  for (int i = 0; i < stepsPerRevolution; i++) 
  {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(delay_val);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delay_val);
  }
}
