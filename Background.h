// Background.h: interface for the Background class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BACKGROUND_H__5FE6A1EC_FEFD_458D_AF62_215E7F72DAE8__INCLUDED_)
#define AFX_BACKGROUND_H__5FE6A1EC_FEFD_458D_AF62_215E7F72DAE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<string>
#include <vector>
#include "CharData.h"

using namespace std;

class Background  
{
public:
	void SetBackground(string Background);
	int GetPickOneCount();
	int GetPickThreeCount();
	int GetPickEdgeCount();
	int GetPickFlawCount();
	string GetPickOneItem(int index);
	string GetPickThreeItem(int index);
	string GetPickEdgeItem(int index);
	string GetPickFlawItem(int index);
	Background();
	virtual ~Background();

private:
	int pickOneCount;
	int pickThreeCount;
	int pickEdgeCount;
	int pickFlawCount;
	void Knowledge(int x);
	void Science(int x);
	void Craft(int x);
	void Entertain(int x);
	void Engineering(int x);
	void Enterprise(int x);

	vector <string> pickFlaw;
	vector <string> pickEdge;
	vector <string> pickThree;
	vector <string> pickOne;
	CharData ref;
};

#endif // !defined(AFX_BACKGROUND_H__5FE6A1EC_FEFD_458D_AF62_215E7F72DAE8__INCLUDED_)
