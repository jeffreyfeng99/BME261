#include "patient.h"
#include "Arduino.h"

PatientID::PatientID()
{
  volumeRequired_ = 0;
  concentrationRequired_ = 0.0;
  drugID_ = NULL;
}
    
PatientID::PatientID(int volumeRequired, double concentrationRequired, int drugID)
{
  volumeRequired_ = volumeRequired;
  concentrationRequired_ = concentrationRequired;
  drugID_ = drugID;
}

int PatientID::getVolumeRequired()
{
  return volumeRequired_;
}

void PatientID::setVolumeRequired(int volumeRequired)
{
  volumeRequired_ = volumeRequired;
}

double PatientID::getConcentrationRequired()
{
  return concentrationRequired_;
}

void PatientID::setConcentrationRequired(double concentrationRequired)
{
  concentrationRequired_ = concentrationRequired;
}

int PatientID::getDrugType()
{
  return drugID_;
}

void PatientID::setDrugType(int drugID)
{
  drugID_ = drugID;
}

int PatientID::getID()
{
  return patientID_;
}

void PatientID::setID(int patientID)
{
  patientID_ = patientID;
}