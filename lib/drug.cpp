#include "drug.h"
#include "Arduino.h"

Drug::Drug()
{
	concentration_ = 0.0;
	mixingSequence_ = 0;
	mixingSequenceSize_ = 0;
	drugID_ = 0;
	empty_ = false;
	mixed_ = false;
	constituent_ = false;
}

Drug::Drug(double concentration, int mixingSequence, int mixingSequenceSize, int drugID, bool empty, bool mixed, bool constituent)
{
	concentration_ = concentration;
	mixingSequence_ = mixingSequence;
	mixingSequenceSize_ = mixingSequenceSize;
	drugID_ = drugID;
	empty_ = empty;
	mixed_ = mixed;
	constituent_ = constituent;
}

double Drug::getConcentration()
{
	return concentration_;
}

void Drug::setConcentration(double concentration)
{
	concentration_ = concentration;
}

int Drug::getMixingSequence()
{
	return mixingSequence_;
}

void Drug::setMixingSequence(int mixingSequence)
{
	mixingSequence_ = mixingSequence;
}

void Drug::setMixingSequenceSize(int mixingSequenceSize)
{
	mixingSequenceSize_ = mixingSequenceSize;
}


int Drug::getMixingSequenceSize()
{
	return mixingSequenceSize_;
}

int Drug::getDrugType()
{
	return drugID_;
}

void Drug::setDrugType(int drugID)
{
	drugID_ = drugID;
}

bool Drug::getEmpty()
{
	return empty_;
}

void Drug::setEmpty(bool empty)
{
	empty_ = empty;
}

bool Drug::getMixed()
{
	return mixed_;
}

void Drug::setMixed(bool mix)
{
	mixed_ = mix;
}

bool Drug::getConstituent()
{
	return constituent_;
}

void Drug::setConstituent(bool constituent)
{
	constituent_ = constituent;
}


