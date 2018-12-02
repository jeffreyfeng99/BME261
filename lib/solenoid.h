#ifndef __SOLENOID_H
#define __SOLENOID_H

#include <Arduino.h>
#include <master.h>

void movePistonIn()
{
  if (pistonUp_ == false)
  {
    digitalWrite(solenoidPin, true);
    pistonUp_ = true;
  }
}

void movePistonOut()
{
  if (pistonUp_ == true)
  {
    digitalWrite(solenoidPin, false);
    pistonUp_ = false;
  }
}

#endif