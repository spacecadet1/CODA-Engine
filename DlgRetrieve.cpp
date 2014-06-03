// DlgRetrieve.cpp : Implementation of DlgRetrieve
#include "stdafx.h"
#include "DlgRetrieve.h"


/////////////////////////////////////////////////////////////////////////////
// DlgRetrieve

BOOL DlgRetrieve::CheckResult()
{
	//fin<<"Line 11"<<endl;	
	char nomen1[64]; 
	CWindow c;  //CComboBox c; 
	c = GetDlgItem(IDC_COMBO1);
	//fin<<"Line 15"<<endl;
	c.GetWindowText(nomen1, sizeof(nomen1));
	
	//MessageBox(nomen1);
	result = nomen1;
	//MessageBox(result.c_str());
	//fin<<"Line 21"<<endl;
	if(result == "")
	{
		//fin<<"Line 24"<<endl;
		MessageBox("Please type in or select data");
		return FALSE;
	}
	else
	{
		//fin<<"Line 30"<<endl;
		ClearComboBox();
		
		return TRUE;
	}
}

void DlgRetrieve::AddItems()
{
	CComboBox box; vector <string> ::iterator pos;
	box = GetDlgItem(IDC_COMBO1);
		
	for(pos = items.begin(); pos != items.end(); ++pos)
	{
		box.AddString(pos->c_str());
			
	}
}

void DlgRetrieve::Set(string prompt, string id)
{	
	m_prompt = prompt; m_id = id;

}

void DlgRetrieve::Set(string id)
{
	
	m_prompt = "Enter entry or choose samples from the box";
	m_id = id;	
	
}

void DlgRetrieve::Release()
{

}

void DlgRetrieve::AddSkillItems(string skill)
{
	if(skill == "Craft")
	{
		items.push_back("Sculpture");
		items.push_back("Pottery");
		items.push_back("Painting");
		items.push_back("Cooking");
		items.push_back("Calligraphy");
		items.push_back("Carpentery");
		items.push_back("Gem Cutting");
		items.push_back("Modeling");
		items.push_back("Sewing");
		items.push_back("Weaving");
		items.push_back("Viticulture");
	}
	else if(skill == "Knowledge")
	{
		items.push_back("Culture");
		items.push_back("History");
		items.push_back("Law");
		items.push_back("Politics");
		items.push_back("Religion");
		items.push_back("Specific World");
		items.push_back("Trivia");
			
	}
	else if(skill == "Dara")
	{
		//Conceal,Stealth
		items.push_back("Conceal");
		items.push_back("Stealth");
	}
	else if(skill == "Dovoro")
	{
		//Appraise, Enterprise:Business
		items.push_back("Appraise");
		items.push_back("Enterprise:Business");
	}
	else if(skill == "P'Trell")
	{
		//Inquire, First Aid
		items.push_back("Inquire");
		items.push_back("First Aid");
	}
	else if(skill == "Armed & Ranged")
	{
		//Armed Combat, Ranged Combat:Archaic, Ranged Combat:Energy, Ranged Combat:Projectile
		items.push_back("Armed Combat");
		items.push_back("Ranged Combat:Archaic");
		items.push_back("Ranged Combat:Energy");
		items.push_back("Ranged Combat:Projectile");
	}
	else if (skill == "Armed & Unarmed")
	{
		//Armed Combat, Unarmed Combat
		items.push_back("Armed Combat");
		items.push_back("Unarmed Combat");
		
	}
	else if(skill == "Combat")
	{
		//Armed Combat,Unarmed Combat,Ranged Combat:Archaic,Ranged Combat:Energy,Ranged Combat:Projectile
		items.push_back("Armed Combat");
		items.push_back("Unarmed Combat");
		items.push_back("Ranged Combat:Archaic");
		items.push_back("Ranged Combat:Energy");
		items.push_back("Ranged Combat:Projectile");
	}
	else if(skill == "Psionic")
	{
		//Mind Control,Telepathy,Empathy
		items.push_back("Mind Control");
		items.push_back("Telepathy");
		items.push_back("Empathy");
	}

	else if (skill == "Engineering")
	{
		//Propulsion,Structural,Systems
		items.push_back("Propulsion");
		items.push_back("Structural");
		items.push_back("Systems");
	}
	else if(skill == "Enterprise")
	{
		items.push_back("Administration");
		items.push_back("Business");
		items.push_back("Streetwise");

	}
	else if(skill == "Entertain")
	{
		items.push_back("Dance");
		items.push_back("Drama");
		items.push_back("Sing");
		items.push_back("Play Instrument");
	}
	else if (skill == "Ranged Combat")
	{
		//Archaic, Energy, Projectile
		items.push_back("Archaic");
		items.push_back("Energy");
		items.push_back("Projectile");
	}
	else if(skill == "Science")
	{
		items.push_back("Life");
		items.push_back("Physical");
		items.push_back("Planetary");
		items.push_back("Social");
		items.push_back("Space");
	}
	else if(skill == "Adaptability")
	{
		items.push_back("Stamina");
		items.push_back("Quickness");
		items.push_back("Willpower");
	}
	else if(skill == "Keth")
	{
		items.push_back("Aldin");
		items.push_back("Athrun");
		items.push_back("Birev");
		items.push_back("Dara");
		items.push_back("Dovoro");
		items.push_back("Idrani");
		items.push_back("Idisha");
		items.push_back("Kor");
		items.push_back("P'Trell");
	}
	
}

void DlgRetrieve::ClearComboBox()
{
	CComboBox box;
	box = GetDlgItem(IDC_COMBO1);
	box.ResetContent();
}



void DlgRetrieve::SetItems(vector <string> &x)
{
	items = x;
}

string DlgRetrieve::GetResult()
{
	return result;
	
}
