// ProPackage.h: interface for the ProPackage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPACKAGE_H__186F81B3_8938_4DB6_801D_61CA7F1877B0__INCLUDED_)
#define AFX_PROPACKAGE_H__186F81B3_8938_4DB6_801D_61CA7F1877B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <vector>
#include <fstream>
#include "SkillData.h"
#include "CharData.h"

using namespace std;

class ProPackage  
{
public:
	string GetProSkill(int index);
	string GetProSubSkill(int index);
	string GetProSpeciality(int index);
	string GetAutoSkill(int index);
	string GetAutoSubSkill(int index);
	string GetAutoSpeciality(int index);
	int GetAutoLevel(int index);
	int GetAutoCount();
	int GetProCount();
	void LoadChoices(string profession);
	void LoadPackage(string package);
	int ProEdgesCount();
	string GetProEdges(int index);
	string PackageTypes(int index);
	int GetPackageCount();
	void AddProSkill(string skill, string subskill);
	ProPackage();
	virtual ~ProPackage();

private:
	void CustomSkills(string str);
	void CustomEdges(string str);
	void CustomPackages(string str);
	string RemoveComma(string statement);
	string Trim(string str);
	void AddCustomData();
	int prskills_count,cfskills_count;
	vector <string> packageTypes;
	vector <SkillData> proSkillArray;
	vector <SkillData> autoSkillArray;
	vector <string> edges;
	CharData trekRef;
	SkillData jobSkillData;
	SkillData proSkillData;
	
	//customized data
	struct _profession
	{
		string package;
		string profession;
		string skills;
		string edges;

		void clear()
		{
			package ="";
			profession ="";
			skills = "";
			edges = "";
		};

	};
	vector<_profession> professions;
	_profession profession;

	ifstream fin;
	

};

#endif // !defined(AFX_PROPACKAGE_H__186F81B3_8938_4DB6_801D_61CA7F1877B0__INCLUDED_)
