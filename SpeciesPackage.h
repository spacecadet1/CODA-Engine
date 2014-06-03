// SpeciesPackage.h: interface for the SpeciesPackage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPECIESPACKAGE_H__10BA3519_4CE4_49FD_A0ED_A5E39AD3A9C9__INCLUDED_)
#define AFX_SPECIESPACKAGE_H__10BA3519_4CE4_49FD_A0ED_A5E39AD3A9C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream>
#include <string>
#include <vector>
#include "SpeciesData.h"
#include "SkillData.h"

using namespace std;

class SpeciesPackage  
{
public:
	string RemoveComma(string statement);
	string Trim( string str);
	int GetRenown();
	int GetCourage();
	void SetSpecies();
	int GetProAbCount();
	int GetEdgeCount();
	int GetFlawCount();
	int GetSpeciesCount();
	int GetSpeciesPsionics (int x);
	int GetSpeciesPerception (int x);
	int GetSpeciesPrescence (int x);
	int GetSpeciesVitality (int x);
	int GetSpeciesIntellect (int x);
	int GetSpeciesAgility (int x);
	int GetSpeciesStrength (int x);
	string GetSpeciesId(int x);
	void Species(string type);
	string GetEdge(int index);
	string GetFlaw(int index);
	string GetProAbility(int index);
	int GetWillpower();
	int GetStamina();
	int GetHealth();
	int GetSavvy();
	int GetSkillCount();
	string GetSkill(int index);
	int GetSkillLevel(int index);
	string GetSubSkill(int index);
	string GetSkillSpeciality(int index);
	SpeciesPackage();
	virtual ~SpeciesPackage();

private:
	void CustomSkills( string str);
	
	void CustomFlaws(string str);
	void CustomEdges(string str);
	void AddCustomData();
	int willpower, stamina, savvy, health,courage,renown;
	string species;
	vector <string> pro_ability;
	vector <string> flaws;
	vector <string> edges;
	int speciesCount; 

	vector <SpeciesData> speciesArray;
	vector <SkillData> skillArray;

	SpeciesData speciesData;
	SkillData speciesSkill;

	ifstream fin; //for custom data input
	

	struct _alien //custom alien structure
	{

		int str;
		int agl;
		int vit;
		int intl;
		int pre;
		int per;
		int psi;
		int savv;
		int hlth;
		int quik;
		int stam;
		int will;
		int cour;
		int rnwn;
		string skills;
		string edges;
		string flaws;
		string id;
		void clear()
		{
			str =0; agl=0;
			vit =0; intl=0;
			pre =0; per =0;
			psi =0; savv =0;
			hlth =0; quik =0;
			stam =0; will =0;
			cour =0; rnwn =0;
			skills ="";
			edges = "";
			flaws = "";
			id = "";
		};

	} alien;

	vector<_alien> aliens; //container for custom aliens
	
	
};

#endif // !defined(AFX_SPECIESPACKAGE_H__10BA3519_4CE4_49FD_A0ED_A5E39AD3A9C9__INCLUDED_)
