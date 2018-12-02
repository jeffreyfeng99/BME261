#ifndef __PLUNGER_H
#define __PLUNGER_H

#include <Arduino.h>
#include <master.h>

void moveNeedleIn(int speed4, double steps)
{
  steps = steps * 500.0/1.1;
//  if (prevStep_ + steps/200 > 12) return; 
  
  // Enables the motor to move in a particular direction
    digitalWrite(leftPlungerDirection, LOW);
    digitalWrite(rightPlungerDirection, HIGH);
    digitalWrite(leftPlungerEnable, HIGH);
    digitalWrite(rightPlungerEnable, HIGH);
    
    for(int x = 0; x < steps; x++) {
      // Makes 3200 pulses for making one full cycle rotation
      digitalWrite(leftPlungerStep,HIGH);
      digitalWrite(rightPlungerStep,HIGH); 
      delayMicroseconds(speed4); 
      digitalWrite(leftPlungerStep,LOW);
      digitalWrite(rightPlungerStep,LOW);
      delayMicroseconds(speed4); 
    }
    digitalWrite(leftPlungerEnable, LOW);
    digitalWrite(rightPlungerEnable, LOW);
    prevStep_ = prevStep_ + steps/200;
}


void moveNeedleInIterative(int speed4, double steps)
{
  steps = steps;
//  if (prevStep_ + steps/200 > 12) return; 
  
  // Enables the motor to move in a particular direction
    digitalWrite(leftPlungerDirection, LOW);
    digitalWrite(rightPlungerDirection, HIGH);
    digitalWrite(leftPlungerEnable, HIGH);
    digitalWrite(rightPlungerEnable, HIGH);
    
    for(int x = 0; x < steps; x++) {
      // Makes 3200 pulses for making one full cycle rotation
      digitalWrite(leftPlungerStep,HIGH);
      digitalWrite(rightPlungerStep,HIGH); 
      delayMicroseconds(speed4); 
      digitalWrite(leftPlungerStep,LOW);
      digitalWrite(rightPlungerStep,LOW);
      delayMicroseconds(speed4); 
    }
    digitalWrite(leftPlungerEnable, LOW);
    digitalWrite(rightPlungerEnable, LOW);
    prevStep_ = prevStep_ + steps/200;
}

void moveNeedleOut(double speed2, int steps)
{
  steps = steps * 500.0/1.1;
//  if (prevStep_ - steps/200 < 0) return;
    digitalWrite(leftPlungerDirection, HIGH);
    digitalWrite(rightPlungerDirection, LOW);
    digitalWrite(leftPlungerEnable, HIGH);
    digitalWrite(rightPlungerEnable, HIGH);
    
    for(int x = 0; x < steps; x++) {
      // Makes 3200 pulses for making one full cycle rotation
      digitalWrite(leftPlungerStep,HIGH);
      digitalWrite(rightPlungerStep,HIGH); 
      delayMicroseconds(speed2); 
      digitalWrite(leftPlungerStep,LOW);
      digitalWrite(rightPlungerStep,LOW);
      delayMicroseconds(speed2); 
    }
    digitalWrite(leftPlungerEnable, LOW);
    digitalWrite(rightPlungerEnable, LOW);
    prevStep_ = prevStep_ - steps/200;
  
}

void moveNeedleSequence(int iterations, int speed3, double steps, bool extract)
{
  for (int i = 0; i < iterations; i++)
  {
    if (needleIn_ == true) 
    {
      moveNeedleOut(speed3, steps);
	  delay(1000);
      needleIn_ = false;
    }
    else 
    {
      moveNeedleIn(speed3, steps);
	  delay(1000);
      needleIn_ = true;
    }
  }
  
  if(needleIn_ == true && extract == true)
  {
    moveNeedleOut(speed3, steps);
    needleIn_ = false;
  }
  else if(needleIn_ == false && extract == false)
  {
    moveNeedleIn(speed3, steps);
    needleIn_ = true;
  }
  return true;
}


void homeMotorPlunger()
{
  while(!isHomedPlunger_) {
    moveNeedleOut(500, 1);
  }
}

void doneHomingPlunger()
{
  isHomedPlunger_ = true;
  
  // 1mL of syringe liquid is 500 steps
  moveNeedleInIterative(300, 2500);
  prevStep_ = 12;
  needleIn_ = true;
}

#endif
