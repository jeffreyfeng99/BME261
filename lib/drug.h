#ifndef __DRUG_H
#define __DRUG_H

class Drug
{
public:
  // Default constructor.
  Drug();
  Drug(double concentration, int mixingSequence, int mixingSequenceSize, int drugID, bool empty, bool mixed, bool constituent);
  
  double getConcentration();
  void setConcentration(double concentration);
  
  int getMixingSequence();
  void setMixingSequence(int mixingSequence);
  
  int getMixingSequenceSize();
  void setMixingSequenceSize(int mixingSequenceSize);
  
  int getDrugType();
  void setDrugType(int drugID);
  
  bool getEmpty();
  void setEmpty(bool empty);
  
  bool getMixed();
  void setMixed(bool mix);
  
  bool getConstituent();
  void setConstituent(bool constituent);
  
private:
  double concentration_;
  int mixingSequence_;
  int mixingSequenceSize_;
  int drugID_;
  bool empty_;
  bool mixed_;
  bool constituent_;
  

};

#endif  //__DRUG_H