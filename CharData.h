// CharData.h: interface for the CharData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARDATA_H__018D1572_1299_4516_85AC_E7E2BF42863E__INCLUDED_)
#define AFX_CHARDATA_H__018D1572_1299_4516_85AC_E7E2BF42863E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
#include <string>

using namespace std;



class CharData  
{
public:
	int GetSkillCount();
	string GetSkill(int index);
	string GetEdge(int index);
	int GetEdgeCount();
	int GetFlawCount();
	string GetFlaw(int index);
	CharData();
	virtual ~CharData();
	vector <string> edges;
	vector <string> skills;
private:
	void Skills();
	void Edges();
	void Flaws();
	vector <string> flaws;
	
};

#endif // !defined(AFX_CHARDATA_H__018D1572_1299_4516_85AC_E7E2BF42863E__INCLUDED_)
