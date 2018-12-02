#ifndef __TABLE_H
#define __TABLE_H

#include <master.h>

void moveMotor(int motorSpeed, int numSteps, bool motorDirection, int directionPin_, int enablePin_, int stepPin_)
{
  // Enables the motor to move in a particular direction
    digitalWrite(directionPin_, motorDirection);
    digitalWrite(enablePin_, HIGH);

    for(int x = 0; x < numSteps; x++) {
      // Makes 3200 pulses for making one full cycle rotation
      digitalWrite(stepPin_,HIGH); 
      delayMicroseconds(motorSpeed); 
      digitalWrite(stepPin_,LOW); 
      delayMicroseconds(motorSpeed); 
    }
    if(enablePin_ == mixingMotor1Enable) {
      digitalWrite(enablePin_, LOW);
    }
}

void drugPositions(PatientID patient, Drug currentDrugs_[])
{
  drugPositionIndex[0] = -1;
  drugPositionIndex[1] = -1;
  for (int i = 0; i < 6; i++)
  {
    if (currentDrugs_[i].getConcentration() == patient.getConcentrationRequired() && currentDrugs_[i].getDrugType() == patient.getDrugType())
    {
      if(currentDrugs_[i].getConstituent() == false)
      {
        if(currentDrugs_[i].getEmpty() == false)
          {
            drugPositionIndex[0] = i;
          }
      }
      else if (currentDrugs_[i].getConstituent() == true)
      {
        if(currentDrugs_[i].getEmpty() == false)
        {
          drugPositionIndex[1] = i;
        }
      }
    }
  }
} 

void moveTable(int speed1, int nextLocation)
{
  if (nextLocation > currentLocation_) 
  {
    bool direction1 = true;
    int steps = (nextLocation - currentLocation_)*200*16/6; ////////////////TESTING REQUIRED 
    moveMotor(speed1, steps, direction1, tableDirection, tableEnable, tableStep);
    currentLocation_ = nextLocation;
	drugList[nextLocation].setEmpty(true);
    return true;
  }
  else if (nextLocation < currentLocation_) 
  {
    bool direction1 = false;
    int steps = (currentLocation_ - nextLocation)*200*16/6; ////////////////TESTING REQUIRED
    moveMotor(speed1, steps, direction1, tableDirection, tableEnable, tableStep);
    currentLocation_ = nextLocation;    
	drugList[nextLocation].setEmpty(true);
    return true;
  }
  return false;
}

void moveTableIncrement(int speed1, int nextLocation, bool direction1)
{ 
    moveMotor(speed1, nextLocation, direction1, tableDirection, tableEnable, tableStep);
}

void mix()
{
  if (currentLocation_ == 1 || currentLocation_ == 4)
  {
    if (drugList[currentLocation_].getMixed() == false)
    {
      
        moveMotor(drugList[currentLocation_].getMixingSequence() , drugList[currentLocation_].getMixingSequenceSize(), true, mixingMotor1Direction, mixingMotor1Enable, mixingMotor1Step);
    
      drugList[currentLocation_].setMixed(true);
    }
  }
}


void homeMotorTable()
{
  while(!isHomedTable_) {
    moveTableIncrement(VIALTABLESPEED, 1, false);
  }
}

void doneHomingTable()
{
  isHomedTable_ = true;
  // 1mL of syringe liquid is 200 steps
  moveTableIncrement(VIALTABLESPEED, 55, true);
  currentLocation_ = 0;
}

#endif