#ifndef __MASTER_H
#define __MASTER_H

#include <patient.h>
#include <drug.h>

Drug drugList[6];
PatientID patientList[6];
int drugPositionIndex[2];
PatientID patientSelection_;

#define VIALTABLESPEED 2000
#define PLUNGERSPEED 500

#define ROTARY_ANGLE_SENSOR A0
#define BUTTON 6// Used to select the desired patient
#define ADC_REF 5 //reference voltage of ADC is 5v.
#define LCD_VCC 5 //VCC of the LCD interface is normally 5v
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees
#define LIST_SIZE 6

//Pins for LCD
const int rs = 0;
const int en = 1;
const int d4 = 2;
const int d5 = 3;
const int d6 = 4;
const int d7 = 5;

//Motor mixing1
const int mixingMotor1Enable = 48;
const int mixingMotor1Step = 50;
const int mixingMotor1Direction = 52;
const int mixingSleeperPin = 22;

//Motor leftPlunger
const int leftPlungerEnable = 42;
const int leftPlungerStep = 44;
const int leftPlungerDirection = 46;
const int plungerLimit = 4; //Plugs into 3
const int leftSleeperPin = 26;

//Motor rightPlunger
const int rightPlungerEnable = 36;
const int rightPlungerStep = 38;
const int rightPlungerDirection = 40;
const int rightSleeperPin = 24;

//Motor table
const int tableEnable = 30;
const int tableStep = 32;
const int tableDirection = 34;
const int tableLimit = 3; //Plugs into 4
const int tableSleeperPin = 28;

//Plunger
int prevStep_ = 8;
bool isHomedPlunger_ = false;
bool needleIn_ = true;

//Table
int currentLocation_ = 0;
bool isHomedTable_ = false;

//Solenoid
bool pistonUp_ = false;
const int solenoidPin = 53;

void initializePins()
{
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(BUTTON,INPUT);
  
  pinMode(solenoidPin, OUTPUT);
  
  pinMode(tableStep,OUTPUT); 
  pinMode(tableDirection,OUTPUT);
  pinMode(tableEnable,OUTPUT);
  pinMode(tableSleeperPin, OUTPUT);
  digitalWrite(tableEnable, LOW);
  digitalWrite(tableSleeperPin, HIGH);
  
  pinMode(mixingMotor1Step,OUTPUT); 
  pinMode(mixingMotor1Direction,OUTPUT);
  pinMode(mixingMotor1Enable,OUTPUT);
  pinMode(mixingSleeperPin, OUTPUT);
  digitalWrite(mixingMotor1Enable, LOW);
  digitalWrite(mixingSleeperPin, HIGH);

  pinMode(leftPlungerStep,OUTPUT); 
  pinMode(leftPlungerDirection,OUTPUT);
  pinMode(leftPlungerEnable,OUTPUT);
  pinMode(leftSleeperPin, OUTPUT);
  digitalWrite(leftPlungerEnable, LOW);
  digitalWrite(leftSleeperPin, HIGH);

  pinMode(rightPlungerStep,OUTPUT); 
  pinMode(rightPlungerDirection,OUTPUT);
  pinMode(rightPlungerEnable,OUTPUT);
  pinMode(rightSleeperPin, OUTPUT);
  digitalWrite(rightPlungerEnable, LOW);
  digitalWrite(rightSleeperPin, HIGH);

}

void initializeDrugList()
{
  drugPositionIndex[0] = -1;
  drugPositionIndex[1] = -1;
  
  drugList[0].setConcentration(8.0);
  drugList[0].setMixingSequence(4);
  drugList[0].setMixingSequenceSize(4);
  drugList[0].setDrugType(0);
  drugList[0].setEmpty(false);
  drugList[0].setMixed(false);
  drugList[0].setConstituent(false);

  // Constituent 1
  drugList[1].setConcentration(8.0);
  drugList[1].setMixingSequence(100);
  drugList[1].setMixingSequenceSize(20000);
  drugList[1].setDrugType(1);
  drugList[1].setEmpty(false);
  drugList[1].setMixed(false);
  drugList[1].setConstituent(true);
  
  drugList[3].setConcentration(8.0);
  drugList[3].setMixingSequence(100);
  drugList[3].setMixingSequenceSize(20000);
  drugList[3].setDrugType(1);
  drugList[3].setEmpty(false);
  drugList[3].setMixed(false);
  drugList[3].setConstituent(false);

  
  drugList[2].setConcentration(9.0); 
  drugList[2].setMixingSequence(150);
  drugList[2].setMixingSequenceSize(22500);
  drugList[2].setDrugType(3);
  drugList[2].setEmpty(false);
  drugList[2].setMixed(false);
  drugList[2].setConstituent(false);
  
  // Constituent 2
  drugList[4].setConcentration(9.0);
  drugList[4].setMixingSequence(2);
  drugList[4].setMixingSequenceSize(4);
  drugList[4].setDrugType(3);
  drugList[4].setEmpty(false);
  drugList[4].setMixed(false);
  drugList[4].setConstituent(true);
  
  drugList[5].setConcentration(1.0);
  drugList[5].setMixingSequence(2);
  drugList[5].setMixingSequenceSize(4);
  drugList[5].setDrugType(5);
  drugList[5].setEmpty(false);
  drugList[5].setMixed(false);
  drugList[5].setConstituent(false);
}

void initializePatientList()
{
  patientList[0].setVolumeRequired(3);
  patientList[0].setConcentrationRequired(7.0);
  patientList[0].setDrugType(0);
  patientList[0].setID(153);
  
  patientList[1].setVolumeRequired(4);
  patientList[1].setConcentrationRequired(8.0);
  patientList[1].setDrugType(1);
  patientList[1].setID(265);
  
  patientList[2].setVolumeRequired(4);
  patientList[2].setConcentrationRequired(6.0);
  patientList[2].setDrugType(2);
  patientList[2].setID(134);
  
  patientList[3].setVolumeRequired(3);
  patientList[3].setConcentrationRequired(9.0);
  patientList[3].setDrugType(3);
  patientList[3].setID(945);
  
  patientList[4].setVolumeRequired(2);
  patientList[4].setConcentrationRequired(8.0);
  patientList[4].setDrugType(4);
  patientList[4].setID(563);
  
  patientList[5].setVolumeRequired(4);
  patientList[5].setConcentrationRequired(7.0);
  patientList[5].setDrugType(5);
  patientList[5].setID(456);

}

#endif  //__MASTER_H
