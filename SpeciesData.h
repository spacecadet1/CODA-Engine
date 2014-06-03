// SpeciesData.h: interface for the SpeciesData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPECIESDATA_H__0F84FE82_0569_4161_BE88_4210B79644DC__INCLUDED_)
#define AFX_SPECIESDATA_H__0F84FE82_0569_4161_BE88_4210B79644DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class SpeciesData  
{
public:
	void EnterData(string idt, int str, int agl, int intl,int vit,int pre,int per, int psi);
	string id;
	int psionics;
	int perception;
	int prescence;
	int vitality;
	int intellect;
	int agility;
	int strength;
	SpeciesData();
	virtual ~SpeciesData();

};

#endif // !defined(AFX_SPECIESDATA_H__0F84FE82_0569_4161_BE88_4210B79644DC__INCLUDED_)
