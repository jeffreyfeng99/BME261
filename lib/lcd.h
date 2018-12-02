#ifndef __LCD_H
#define __LCD_H

#include <LiquidCrystal.h>
#include <math.h>
#include <Arduino.h>
#include <master.h>
#include <table.h>

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int getIndexFromDegrees()
{
  // convert reading to degrees
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  float voltage = (float) sensor_value * ADC_REF / 1023;
  float degrees = (voltage * FULL_ANGLE) / LCD_VCC;

  int index;
  int intervalSwitch = FULL_ANGLE / LIST_SIZE; 

  index = LIST_SIZE - 1;
  if(degrees < 300) {
    index =  floor(degrees / intervalSwitch); // ex.  299 deg / 100 deg/switch = 2
  }

  return index;
}

void printToLCD(PatientID list[])
{
  int index = getIndexFromDegrees();

  lcd.setCursor(0, 0);
  if(list[index].getDrugType() == 0)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:CAF");
  }
  else if(list[index].getDrugType() == 1)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:CHOP");
  }
  else if(list[index].getDrugType() == 2)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:DICE");
  }
  else if(list[index].getDrugType() == 3)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:FLAG");
  }
  else if(list[index].getDrugType() == 4)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:IVA");
  }
  else if(list[index].getDrugType() == 5)
  {
	lcd.print("ID:" + String(list[index].getID()) + " Drug:VAC");
  }
  
  lcd.setCursor(0, 1);
  lcd.print(String(list[index].getVolumeRequired()) + "mL " + String(list[index].getConcentrationRequired()) + "M");
  delay(100);
  lcd.clear();
}

bool patientSelection(PatientID list[])
{
  int index = getIndexFromDegrees();
  while(digitalRead(BUTTON) == HIGH) {
    patientSelection_ = list[index];
    Serial.print(patientSelection_.getVolumeRequired());
    return true;
  }
  return false;
}

void clearLCD()
{  
  lcd.clear();
  lcd.setCursor(0, 0);
}

//General check helper method
bool checkEmpty()
{
  bool viablePair = false;
  for (int i = 0; i < 6; i++)
  {
    drugPositions(patientList[i], drugList);
    if(drugPositionIndex[0] > -1 && drugPositionIndex[1] > -1) viablePair = true;
  }
  return !viablePair;
//  bool empty = true;
//  for (int i = 0; i < 6; i++)
//  {
//    if(drugList[i].getEmpty() == false) empty = false;
//  }
//  return empty;
}

void resetTable()
{	
  if (checkEmpty() == true)
  { 
	while(digitalRead(BUTTON) == LOW)
	{
	  clearLCD();
	  lcd.print("Need refill");
	  lcd.setCursor(0, 1);
	  lcd.print("Press Button");
	  delay(100);
	}
	  
	clearLCD();
    lcd.print("Starting");
    lcd.setCursor(0, 1);
    lcd.print("process");
    homeMotorTable();
    isHomedTable_ = false;
			
	for(int j = 0; j < 6; j++)
	{
	  moveTable(VIALTABLESPEED, j);

	  while(digitalRead(BUTTON) == LOW)
	  {
		clearLCD();
		if(drugList[j].getDrugType() == 0)
		{
		  lcd.print("Drug: CAF " + String(drugList[j].getConcentration()) + "M");
		}	  
		else if(drugList[j].getDrugType() == 1)
		{
		  lcd.print("Drug: CHOP " + String(drugList[j].getConcentration()) + "M");
		}
		else if(drugList[j].getDrugType() == 2)
		{
		  lcd.print("Drug: DICE " + String(drugList[j].getConcentration()) + "M");
		}
		else if(drugList[j].getDrugType() == 3)
		{
		  lcd.print("Drug: FLAG " + String(drugList[j].getConcentration()) + "M");
		}
		else if(drugList[j].getDrugType() == 4)
		{
		  lcd.print("Drug: IVA " + String(drugList[j].getConcentration()) + "M");
		}
		else if(drugList[j].getDrugType() == 5)
		{
		  lcd.print("Drug: VAC " + String(drugList[j].getConcentration()) + "M");
		}
		  
		lcd.setCursor(0, 1);
		if(drugList[j].getConstituent())
		{
		  lcd.print("Constituent");
		}
		else 
		{
		  lcd.print("Solvent");
		}
		delay(100);
	  }
		
	  clearLCD();
	  lcd.print("Drug refilled");
	  delay(2000);
      drugList[j].setEmpty(false);
	}
	  
	clearLCD();
	lcd.print("All");
	lcd.setCursor(0, 1);
	lcd.print("Refilled");
	delay(2000);
	homeMotorTable();
	isHomedTable_ = false;
  }
}


#endif