// SkillData.cpp: implementation of the SkillData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SkillData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SkillData::SkillData()
{

}

SkillData::~SkillData()
{

}

string SkillData::GetSkill()
{
	return skill;

}

void SkillData::EnterData(string Skill, string SubSkill, string Speciality)
{
	skill = Skill;
	subskill = SubSkill;
	speciality = Speciality;

}

void SkillData::EnterData(string Skill, string SubSkill, string Speciality, int Level)
{
	skill = Skill;
	subskill = SubSkill;
	speciality = Speciality;
	level = Level;

}

int SkillData::GetLevel()
{
	return level;

}

string SkillData::GetSubSkill()
{
	return subskill;
}

string SkillData::GetSpeciality()
{
	return speciality;
}
