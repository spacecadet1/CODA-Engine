// Traits.cpp: implementation of the Traits class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Traits.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Traits::Traits()
{

}

Traits::~Traits()
{

}

void Traits::RemoveAll()
{
	traits.clear();
}

int Traits::Count()
{
	return traits.size();
}

void Traits::GetData(int index, string &name)
{
	name=traits[index].GetName();
}

BOOL Traits::IsExist(string input)
{
	vector <BaseTrait> ::iterator pos;
	for(pos = traits.begin(); pos != traits.end();++pos)
	{
		if(pos->GetName() == input)
			return TRUE;
	}
	return FALSE;
}

void Traits::Add(string input)
{
	BaseTrait trait;
	trait.SetName(input);
	traits.push_back(trait);
}
