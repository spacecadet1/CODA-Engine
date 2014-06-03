// BaseSkill.h: interface for the BaseSkill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASESKILL_H__52890DBC_9DCF_4930_B686_52B7017A375A__INCLUDED_)
#define AFX_BASESKILL_H__52890DBC_9DCF_4930_B686_52B7017A375A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class BaseSkill  
{
public:
	string GetName() const;
	int GetLevel() const;
	string GetSpecific() const;
	void SetSkill(string skill, string special, int lev);
	void Increment(int num);
	void SetLevel(int num);
	BaseSkill();
	virtual ~BaseSkill();

private:
	string name;
	string specific;
	int level;
};

#endif // !defined(AFX_BASESKILL_H__52890DBC_9DCF_4930_B686_52B7017A375A__INCLUDED_)
