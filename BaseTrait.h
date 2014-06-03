// BaseTrait.h: interface for the BaseTrait class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASETRAIT_H__4748A13B_E184_4A3A_88C5_CFD2EC933116__INCLUDED_)
#define AFX_BASETRAIT_H__4748A13B_E184_4A3A_88C5_CFD2EC933116__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

using namespace std;

class BaseTrait  
{
public:
	string GetName();
	void SetName(string input);
	BaseTrait();
	virtual ~BaseTrait();

private:
	string name;
};

#endif // !defined(AFX_BASETRAIT_H__4748A13B_E184_4A3A_88C5_CFD2EC933116__INCLUDED_)
