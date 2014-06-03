// BaseSkill.cpp: implementation of the BaseSkill class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseSkill.h"
//#include "DlgMessage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BaseSkill::BaseSkill()
{

}

BaseSkill::~BaseSkill()
{

}

void BaseSkill::SetLevel(int num)
{
	level = num;
}

void BaseSkill::Increment(int num)
{
	level +=num;
}

void BaseSkill::SetSkill(string skill, string special, int lev)
{
	
	level = lev;
	name=skill;
	specific = special;

}

string BaseSkill::GetSpecific() const
{
	return specific;
}

int BaseSkill::GetLevel() const
{
	return level;
}

string BaseSkill::GetName() const
{
	return name;
}
