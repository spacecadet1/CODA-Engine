// Skills.cpp: implementation of the Skills class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Skills.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Skills::Skills()
{

}

Skills::~Skills()
{

}

void Skills::SetLevel(string name, int level)
{
	//BaseSkill pSkill;
	
	for(pos = skills.begin(); pos!= skills.end(); ++pos)
	{
		//pSkill=*pos;
		if(pos->GetName() == name)
		{
			pos->SetLevel(level);
			break;
		}
	}

}

void Skills::SetLevel(int index, int level)
{
	skills[index].SetLevel(level);
	//skills.at(index).SetSkill(level);
}

int Skills::GetLevel(int index)
{
	//return skills[index].GetLevel();
	return skills.at(index).GetLevel();
}

string Skills::GetSpecific(int index)
{
	return skills[index].GetSpecific();
}

string Skills::GetName(int index)
{
	return skills[index].GetName();
}

int Skills::GetCount()
{
	return skills.size();
}

int Skills::GetLevelB(string name, string specific)
{
	int level;
	BaseSkill pSkill;
	
	for(pos = skills.begin(); pos!= skills.end(); ++pos)
	{
		pSkill=*pos;
		if(pSkill.GetName() == name)
		{
			if(pSkill.GetSpecific() == specific)
			{
				level = pSkill.GetLevel();
				break;
			}
		}
	}

	
	return level;
}

int Skills::GetLevelA(string name)
{
	int level;
	//BaseSkill pSkill;
	
	for(pos = skills.begin(); pos!= skills.end(); ++pos)
	{
		//pSkill=*pos;
		
		if(pos->GetName() == name)
		{
			level=pos->GetLevel();
			break;
		}
	}

	return level;
}



void Skills::Modify(string name, int level)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
			pos->Increment(level);
	}

}

void Skills::Modify(string name, string specific, int level)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
		{
			if(pos->GetSpecific() == specific)
			{
				pos->Increment(level); break;
			}
		}
	}

}

void Skills::Add(string name, string specific, int level)
{
	BaseSkill skill;
	
	skill.SetSkill(name,specific,level);
	skills.push_back(skill);
}

void Skills::Remove(string name, string specific)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
			if(pos->GetSpecific() == specific)
			{
				skills.erase(pos);break;
			}
	}
}

void Skills::Remove(string name)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
		{
			skills.erase(pos); break;
		}
	}
}

void Skills::RemoveAll()
{
	skills.clear();
}

BOOL Skills::IsExist(string name, string specific)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
		{
			if(pos->GetSpecific() == specific)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL Skills::IsExist(string name)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
			return TRUE;
			
	}
	
	return FALSE;
}

void Skills::SetLevel(string name, string specific, int level)
{
	
	for(pos = skills.begin(); pos != skills.end(); ++pos)
	{
		if (pos->GetName() == name)
		{
			if(pos->GetSpecific() == specific)
			{
				pos->SetLevel(level);break;
			}
		}
	}
}
