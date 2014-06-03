// Traits.h: interface for the Traits class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAITS_H__6043F1AE_FBE8_4541_B878_9090C97CFCF9__INCLUDED_)
#define AFX_TRAITS_H__6043F1AE_FBE8_4541_B878_9090C97CFCF9__INCLUDED_

#include "BaseTrait.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>

using namespace std;

class Traits  
{
public:
	void Add(string input);
	BOOL IsExist(string input);
	void GetData(int index, string& name);
	int Count();
	void RemoveAll();
	Traits();
	virtual ~Traits();

private:
	int number;
	vector <BaseTrait> traits;
};

#endif // !defined(AFX_TRAITS_H__6043F1AE_FBE8_4541_B878_9090C97CFCF9__INCLUDED_)
