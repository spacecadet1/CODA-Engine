// BaseTrait.cpp: implementation of the BaseTrait class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseTrait.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BaseTrait::BaseTrait()
{

}

BaseTrait::~BaseTrait()
{

}

void BaseTrait::SetName(string input)
{
	name = input;		
}

string BaseTrait::GetName()
{
	return name;
}
