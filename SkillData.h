// SkillData.h: interface for the SkillData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILLDATA_H__955E7C7E_14F3_4907_8EDA_96236452CA86__INCLUDED_)
#define AFX_SKILLDATA_H__955E7C7E_14F3_4907_8EDA_96236452CA86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class SkillData  
{
public:
	string GetSpeciality();
	string GetSubSkill();
	int GetLevel();
	void EnterData(string Skill, string SubSkill, string Speciality, int Level);
	void EnterData(string Skill, string SubSkill, string Speciality);
	string GetSkill();
	SkillData();
	virtual ~SkillData();

private:
	
	int level;
	string speciality;
	string subskill;
	string skill;
};

#endif // !defined(AFX_SKILLDATA_H__955E7C7E_14F3_4907_8EDA_96236452CA86__INCLUDED_)
