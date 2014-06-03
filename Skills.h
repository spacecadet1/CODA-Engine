// Skills.h: interface for the Skills class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILLS_H__EFC1F2A1_D5D0_469E_851C_D11C410203B6__INCLUDED_)
#define AFX_SKILLS_H__EFC1F2A1_D5D0_469E_851C_D11C410203B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <vector>
#include "BaseSkill.h"

using namespace std;

class Skills  
{
public:
	void SetLevel(string name, string specific, int level);
	BOOL IsExist(string name);
	BOOL IsExist(string name, string specific);
	void RemoveAll();
	void Remove(string name);
	void Remove(string name, string specific);
	void Add(string name, string specific, int level);
	void Modify(string name, string specific, int level);
	void Modify(string name, int level);
	int GetLevelA(string name);
	int GetLevelB(string name, string specific);
	int GetLevel(int index);
	int GetCount();
	string GetName(int index);
	string GetSpecific(int index);	
	void SetLevel(int index, int level);
	void SetLevel(string name, int level);
	Skills();
	virtual ~Skills();

private:
	int number;
	vector <BaseSkill> skills;
	vector <BaseSkill> ::iterator pos;
	
};

#endif // !defined(AFX_SKILLS_H__EFC1F2A1_D5D0_469E_851C_D11C410203B6__INCLUDED_)
