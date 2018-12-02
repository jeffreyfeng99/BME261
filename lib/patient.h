#ifndef __PATIENT_H
#define __PATIENT_H

class PatientID
{
  public:
    PatientID();
    
    PatientID(int volumeRequired, double concentrationRequired, int drugID);
    
    int getVolumeRequired();
    
    void setVolumeRequired(int volumeRequired);
    
    double getConcentrationRequired();
	
    void setConcentrationRequired(double concentrationRequired);
    
    int getDrugType();
    
    void setDrugType(int drugID);
	
    int getID();
    
    void setID(int patientID);
  
    private:
      int volumeRequired_;
      double concentrationRequired_;
      int drugID_;
	  int patientID_;
};

#endif  //__DRUG_H