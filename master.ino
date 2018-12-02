#include <solenoid.h>
#include <patient.h>
#include <drug.h>
#include <master.h>
#include <math.h>
#include <Arduino.h>
#include <lcd.h>
#include <plunger.h>
#include <table.h>

void setup() {
  initializePins();
  initializeDrugList();
  initializePatientList();
  lcd.begin(16, 2);
  attachInterrupt(plungerLimit, doneHomingPlunger, RISING);
  attachInterrupt(tableLimit, doneHomingTable, RISING);
}

void loop() {
	  printToLCD(patientList);

//  if (patientSelection(patientList) == true) {
//      homeMotorTable();
//  }

//  if (patientSelection(patientList) == true) {
//      PatientID currentPatient = patientSelection_;
//      drugPositions(currentPatient, drugList); 
//      lcd.print(drugPositionIndex[0]);
//      lcd.print(drugPositionIndex[1]);
//  }
  
//  if (patientSelection(patientList) == true) {
//      homeMotorPlunger();
//  }

//  if (patientSelection(patientList) == true) {
//      homeMotorTable();
//      while(digitalRead(BUTTON) == LOW){
//      moveTableIncrement(VIALTABLESPEED, 533, true);
//      delay(3000);
//      moveTableIncrement(VIALTABLESPEED, 533, false);
//      delay(3000);
//  }

//  if (patientSelection(patientList) == true) {
//      movePistonIn();
//      delay(1500);
//      movePistonOut();     
//  }

//  if (patientSelection(patientList) == true) {
//      homeMotorTable();
//      moveTable(VIALTABLESPEED, 1);
//      mix();    
//  }
  
//  if (patientSelection(patientList) == true) {
//        PatientID currentPatient = getPatientSelection();
//        moveNeedleSequence(5, PLUNGERSPEED, currentPatient.getVolumeRequired(), true);
//  }
  

//  if (patientSelection(patientList) == true) {
//        PatientID currentPatient = patientSelection_;
//        moveNeedleSequence(5, PLUNGERSPEED, currentPatient.getVolumeRequired(), false);
//  }
  
	if (patientSelection(patientList) == false)
	{
	}
	else if (patientSelection(patientList) == true){
		PatientID currentPatient = patientSelection_;
		
		drugPositions(currentPatient, drugList);
		
		if(drugPositionIndex[0] == -1 || drugPositionIndex[1] == -1)
		{
       clearLCD();
       lcd.print("Drug not present");
       lcd.setCursor(0, 1);
       lcd.print("or empty");
       delay(3000);
		}
		else {
      clearLCD();
      lcd.print("Drug found");
      lcd.setCursor(0, 1);
      lcd.print("Commence homing");
      delay(1000);
			homeMotorPlunger();
			homeMotorTable();
			for (int i = 0; i < 2; i++){
				if (i == 0)
				{
          clearLCD();
          lcd.print("Moving to");
          lcd.setCursor(0, 1);
          lcd.print("solvent");
          delay(750);
					moveTable(VIALTABLESPEED, drugPositionIndex[i]);
          clearLCD();
          lcd.print("Extract solvent");
          delay(750);
					movePistonIn();
          delay(750);
					moveNeedleSequence(5, PLUNGERSPEED, currentPatient.getVolumeRequired(), true);
					delay(750);
					movePistonOut();
          delay(750);
				}
				if (i == 1)
				{
          clearLCD();
          lcd.print("Moving to");
          lcd.setCursor(0, 1);
          lcd.print("constituent");
          delay(750);
					moveTable(VIALTABLESPEED, drugPositionIndex[i]);
          clearLCD();
          lcd.print("Insert solvent");
          lcd.setCursor(0, 1);
          lcd.print("into constituent");
          delay(750);
					movePistonIn();
          delay(750);
					moveNeedleSequence(5, PLUNGERSPEED, currentPatient.getVolumeRequired(), false);
					delay(750);
					movePistonOut();
          clearLCD();
          lcd.print("Mixing");
          delay(750);
					mix();
          clearLCD();
          lcd.print("Extract solution");
          delay(750);
					movePistonIn();
          delay(750);
					moveNeedleSequence(5, PLUNGERSPEED, currentPatient.getVolumeRequired(), true);
					delay(750);
					movePistonOut();
          delay(750);
				}
			}
     clearLCD();
     lcd.print("Solution ready");
     delay(3000);
     isHomedPlunger_ = false;
     isHomedTable_ = false;
		}
	}
  resetTable();
}
