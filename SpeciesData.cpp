// SpeciesData.cpp: implementation of the SpeciesData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpeciesData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SpeciesData::SpeciesData()
{

}

SpeciesData::~SpeciesData()
{

}

void SpeciesData::EnterData(string idt, int str, int agl, int intl, int vit, int pre, 
							int per, int psi)
{
	id = idt;
	strength = str;
	agility = agl;
	intellect = intl;
	vitality = vit;
	prescence = pre;
	perception = per;
	psionics = psi;

}
