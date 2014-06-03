// Character.cpp : Implementation of CCharacter
#include "stdafx.h"
#include "Coda.h"
#include "Character.h"
#include <cctype>
#include <list>
#include <comutil.h>

#pragma comment(lib, "comsupp.lib")

/////////////////////////////////////////////////////////////////////////////
// CCharacter

STDMETHODIMP CCharacter::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITrekCharacter
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

string CCharacter::RemoveComma(string statement)
{
	if(statement == "")
		return statement;

	int x = statement.length()-1;

	char c = statement[x-1];
	if(c == ',')
		statement[x-1] = ' ';

	statement = Trim(statement);
	return statement;

}

vector<string> CCharacter::FindSampleSpec(string skill)
{
	//string samples;
	vector<string> samples;
	for(int i=0; i< skills.GetCount(); i++)
	{
		if(skills.GetName(i) == skill)
		{
			int j = skills.GetLevel(i);
			if((j<6) && (skills.GetSpecific(i)!=""))
				//samples = samples+ skills.GetSpecific(i)+", ";
				samples.push_back(skills.GetSpecific(i));
		}

	}

	if (skill == "Language")
	{
		
		for(int i=0;i<languages.size();i++)
		{
			
			if(skills.GetLevelA(languages[i]) <6)
				//samples = samples + languages[i] +", ";
				samples.push_back(languages[i]);
		}
	}
	

	
	return samples;

}

void CCharacter::VortaBonus()
{
	if (species == "Vorta")
	{
		//specific world
		if(skills.IsExist("Knowledge:Specific World","Dominion"))
			skills.Modify("Knowledge:Specific World","Dominion",1);
		else
			skills.Add("Knowledge:Specific World","Dominion",1);

		//culture
		if(skills.IsExist("Knowledge:Culture","Dominion"))
			skills.Modify("Knowledge:Culture","Dominion",1);
		else
			skills.Add("Knowledge:Culture","Dominion",1);
		//history
		if(skills.IsExist("Knowledge:History","Dominion"))
			skills.Modify("Knowledge:History","Dominion",1);
		else
			skills.Add("Knowledge:History","Dominion",1);

	}
}

void CCharacter::LoadSpeciesSkills()
{
	if(pkSpecies.GetSkillCount()>0)
	{
		for(int i=0;i<pkSpecies.GetSkillCount();i++)
		{
			if(pkSpecies.GetSubSkill(i) != "") //where the subskill has data or an "x"
			{
				string tempspec = pkSpecies.GetSkillSpeciality(i);
				string tempskill = pkSpecies.GetSkill(i);
				string tempsub = pkSpecies.GetSubSkill(i);

				if(tempsub != "x")
				{
					if (tempspec == "x")
						tempspec = UserSpecify(tempskill);

					skills.Add(tempskill+":"+tempsub,tempspec,
						pkSpecies.GetSkillLevel(i));

				}
				else
				{
					tempskill = UserSelectSkill(tempskill);
					if (tempspec == "x")
						tempspec = UserSpecify(tempskill);

					skills.Add(tempskill, tempspec, pkSpecies.GetSkillLevel(i));

				}
							
				
			}
			else  //where the subskill is blank
			{
				string tempspec = pkSpecies.GetSkillSpeciality(i);
				string tempskill = pkSpecies.GetSkill(i);
				if (tempspec == "x")
					tempspec = UserSpecify(tempskill);
				skills.Add(tempskill,tempspec,pkSpecies.GetSkillLevel(i));
			}
		
		}
	}
	//Add Nausican and Andorian dialogs here
	if(species == "Andorian")
	{
		//DlgKeth keth; CString skill;
		DlgRetrieve keth;
		string skill; 
		keth.Set("Select your Andorian clan","Keth"); 
andor:
		if(keth.DoModal()==IDOK)
		{
			
			if(keth.GetResult() == "Aldin")
			{
				skill = UserSelectSkill("Science");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else if(keth.GetResult() == "Athrun")
			{
				skills.Add("System Operation","Flight Control",1);
			}
			else if(keth.GetResult() == "Birev")
			{
				skill = UserSelectSkill("Engineering");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else if(keth.GetResult() == "Dara")
			{
				skill = UserSelectSkill("Dara");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else if(keth.GetResult() == "Dovoro")
			{
				skill = UserSelectSkill("Dovoro");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else if(keth.GetResult() == "Idrani")
			{
				skill = UserSelectSkill("Armed & Ranged");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else if(keth.GetResult() == "Idisha")
			{
				skills.Add("Entertain:Drama",UserSpecify("Entertain:Drama"),1);
			}
			else if(keth.GetResult() == "Kor")
			{
				skills.Add("Negotiate","Mediate",1);
			}
			else if(keth.GetResult() == "P'Trell")
			{
				skill = UserSelectSkill("P'Trell");
				skills.Add(skill,UserSpecify(skill),1);
			}
			else
			{
				//AfxMessageBox("Error on Andorian");
				msg.SetWarning("You must select a clan from the choices given");
				msg.DoModal();
				goto andor;
			}

			
		}
		else
		{
			//keth.m_prompt = "You must select a clan";
			goto andor;
		}


	}
	if(species == "Nausicaan")
	{
		string skill,spec;
		skill = UserSelectSkill("Combat");
		spec = UserSpecify(skill);
		skills.Add(skill,spec,1);
naus:
		skill = UserSelectSkill("Combat");
		spec = UserSpecify(skill);
		if(skills.IsExist(skill,spec))
		{
			msg.SetWarning("The skill/speciality you have chosen already exists. Choose another");
			msg.DoModal();
			goto naus;
		}
		skills.Add(skill,spec,1);

	}

}

void CCharacter::LoadEliteSkills()
{
	if (elite=="Adept")
	{
		eliteProSkills.clear();
		eliteProSkills.push_back("Empathy");
		eliteProSkills.push_back("Mind Control");
		eliteProSkills.push_back("Mind Shield");
		eliteProSkills.push_back("Knowledge:Religion");
		eliteProSkills.push_back("Telepathy");
		eliteProSkills.push_back("Unarmed Combat");
		
	}
	else if(elite=="Ambassador")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Enterprise:Administration");
		eliteProSkills.push_back("Knowledge:Culture");
		eliteProSkills.push_back("Knowledge:Law");
		eliteProSkills.push_back("Negotiate");
		eliteProSkills.push_back("Persuade");
		eliteProSkills.push_back("Knowledge:Specific World");
		

	}
	else if(elite=="Assassin")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Armed Combat");
		eliteProSkills.push_back("Conceal");
		eliteProSkills.push_back("Impersonate");
		eliteProSkills.push_back("Science:Physical");
		eliteProSkills.push_back("Ranged Combat");
		eliteProSkills.push_back("Stealth");

		
	}
	else if(elite=="Envoy")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Impersonate");
		eliteProSkills.push_back("Inquire");
		eliteProSkills.push_back("Knowledge:Culture");
		eliteProSkills.push_back("Knowledge:Specific World");
		eliteProSkills.push_back("Language");
		eliteProSkills.push_back("Science:Social");
		eliteProSkills.push_back("Stealth");

		
	}
	else if(elite=="Explorer")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("First Aid");
		eliteProSkills.push_back("Investigate");
		eliteProSkills.push_back("Observe");
		eliteProSkills.push_back("Repair");
		eliteProSkills.push_back("Science:Life");
		eliteProSkills.push_back("Science:Physical");
		eliteProSkills.push_back("Science:Planetary");
		eliteProSkills.push_back("Science:Social");
		eliteProSkills.push_back("Science:Space");
		eliteProSkills.push_back("Survival");

		
	}
	else if(elite=="Free Trader")
	{
	
		eliteProSkills.clear();
		eliteProSkills.push_back("Enterprise:Administration");
		eliteProSkills.push_back("Appraise");
		eliteProSkills.push_back("Enterprise:Business");
		eliteProSkills.push_back("Influence");
		eliteProSkills.push_back("Negotiate");
		eliteProSkills.push_back("System Operation");

		

	}
	else if(elite=="Inventor")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Enterprise:Administration");
		eliteProSkills.push_back("Computer Use");
		eliteProSkills.push_back("Construct");
		eliteProSkills.push_back("Engineering:Systems");
		eliteProSkills.push_back("Engineering:Propulsion");
		eliteProSkills.push_back("Engineering:Structural");
		eliteProSkills.push_back("Repair");
		eliteProSkills.push_back("Science:Life");
		eliteProSkills.push_back("Science:Physical");
		eliteProSkills.push_back("Science:Planetary");
		eliteProSkills.push_back("Science:Social");
		eliteProSkills.push_back("Science:Space");
	}
	else if(elite=="Mercenary")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Armed Combat");
		eliteProSkills.push_back("Athletics");
		eliteProSkills.push_back("Negotiate");
		eliteProSkills.push_back("Observe");
		eliteProSkills.push_back("Ranged Combat:Archaic");
		eliteProSkills.push_back("Ranged Combat:Energy");
		eliteProSkills.push_back("Ranged Combat:Projectile");
		eliteProSkills.push_back("Unarmed Combat");
	}
	else if(elite=="Smuggler")
	{
	
		eliteProSkills.clear();
		eliteProSkills.push_back("Enterprise:Business");
		eliteProSkills.push_back("Conceal");
		eliteProSkills.push_back("Forgery");
		eliteProSkills.push_back("Influence");
		eliteProSkills.push_back("Negotiate");
		eliteProSkills.push_back("Enterprise:Streetwise");

	}
	else if(elite=="Special Forces")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Enterprise:Administration");
		eliteProSkills.push_back("Demolitions");
		eliteProSkills.push_back("Ranged Combat:Archaic");
		eliteProSkills.push_back("Ranged Combat:Energy");
		eliteProSkills.push_back("Ranged Combat:Projectile");
		eliteProSkills.push_back("Stealth");
		eliteProSkills.push_back("Survival");
		eliteProSkills.push_back("Unarmed Combat");
	}
	else if(elite=="Spy")
	{
		eliteProSkills.clear();
		eliteProSkills.push_back("Computer Use");
		eliteProSkills.push_back("Forgery");
		eliteProSkills.push_back("Impersonate");
		eliteProSkills.push_back("Inquire");
		eliteProSkills.push_back("Investigate");
		eliteProSkills.push_back("Observe");
	}
	else if(elite=="Weaponmaster")
	{
		
		eliteProSkills.clear();
		eliteProSkills.push_back("Armed Combat");
		eliteProSkills.push_back("Construct");
		eliteProSkills.push_back("Gymnastics");
		eliteProSkills.push_back("Ranged Combat:Archaic");
		eliteProSkills.push_back("Ranged Combat:Energy");
		eliteProSkills.push_back("Ranged Combat:Projectile");
		eliteProSkills.push_back("Knowledge:Religion");
		eliteProSkills.push_back("Stealth");
	}

	if(elite != "none")
	{
		string skill;
		if(pkSpecies.GetSkillCount()>0)
		{
			for(int i=0;i<pkSpecies.GetSkillCount();i++)
			{
				if(pkSpecies.GetSubSkill(i) != "")
				{
					skill = pkSpecies.GetSkill(i)+":"+pkSpecies.GetSubSkill(i);
					eliteProSkills.push_back(skill);
				}
				else
				{
					skill = pkSpecies.GetSkill(i);
					eliteProSkills.push_back(skill);
				}
				
				
			}
		}
	}

}

void CCharacter::LoadSpeciesTraits()
{
	//Flaws
	if(pkSpecies.GetFlawCount()>0)
	{
		for(int i=0;i<pkSpecies.GetFlawCount();i++)
		{
			flaws.Add(pkSpecies.GetFlaw(i));
		}
	}

	//Edges
	if(pkSpecies.GetEdgeCount()>0)
	{
		for(int i=0;i<pkSpecies.GetEdgeCount();i++)
		{
			edges.Add(pkSpecies.GetEdge(i));
		}
	}

}

void CCharacter::AddUpgrade(string skill, string spec, int level)
{
	skill = UserSelectSkill(skill);
	spec = UserSpecify(skill);
	skills.Add(skill,spec,level);
}

void CCharacter::AddUpgrade(string skill, int level)
{
	skill = UserSelectSkill(skill);
	skills.Add(skill,"",level);
}

void CCharacter::SetLevel(int index, int level)
{
	int x=skills.GetLevel(index);
	if(x<level)
			skills.SetLevel(index,level);

}

void CCharacter::SetLevel(string skill, int level)
{
	BOOL found;
	int i, tempx,count;
	found = FALSE;

	for(i=0;i<skills.GetCount();i++)
	{
		if(skill == skills.GetName(i))
		{
			if(skills.GetLevel(i)>= level)
			{
				found = TRUE;
			}
		}
	}
	if(found==FALSE)
	{
		for(i=0;i<skills.GetCount();i++)
		{
			if(skill == skills.GetName(i))
			{
				count++;
				tempx = i;
			}
		}
		if(count == 1)
		{
			skills.SetLevel(tempx,level);
		}
		
		else if(count>1)
		{
			int max =0;
			for(i=0;i<skills.GetCount();i++)
			{
				if(skill == skills.GetName(i))
				{
					if(max<= skills.GetLevel(i))
					{
						max = skills.GetLevel(i);
						tempx = i;
					}
				}
			}
			skills.SetLevel(skills.GetName(i),
				skills.GetSpecific(i),level);

		}
	}

}

string CCharacter::FindMaxedSpec(string skill)
{
	string maxed;
	
	for(int i=0; i< skills.GetCount(); i++)
	{
		if(skills.GetName(i) == skill)
		{
			int j = skills.GetLevel(i);
			if(j>=6)
				maxed = maxed+ skills.GetSpecific(i)+", ";
		}

	}

	if (skill == "Language")
	{
		
		for(int i=0;i<languages.size();i++)
		{
			
			if(skills.GetLevelA(languages[i]) >=6)
				maxed = maxed + languages[i] +", ";
		}
	}

	//maxed = Trim(maxed);
	//maxed = RemoveComma(maxed);
	return maxed;
}

string CCharacter::UserSelectSkill(string skill)
{
	DlgRetrieve retr;
	
	if(skill == "Craft")
	{
		//set craft skills
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
		
	}
	else if(skill == "Knowledge")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if(skill == "Dara")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if(skill == "Dovoro")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if(skill == "P'Trell")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if(skill == "Armed & Ranged")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if (skill == "Armed & Unarmed")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if(skill == "Combat")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}
	else if(skill == "Psionic")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		if(retr.GetResult().find(':') == string::npos)
			return Capitialize(retr.GetResult());
		else
			return retr.GetResult();
	}

	else if (skill == "Engineering")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if (skill == "Ranged Combat")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if(skill == "Science")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if(skill == "Enterprise")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if(skill == "Entertain")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill + ":" + Capitialize(retr.GetResult());
	}
	else if (skill == "Adaptability")
	{
		retr.Set("Select a skill from box",skill);
		retr.DoModal();
		return skill;
	}
	else
		retr.MessageBox("Missing skill");
	return "";
}

string CCharacter::UserSpecify(string skill)
{
	DlgRetrieve retr;
	string specific;
	//vector <string> maxedSkills;
	vector <string> samples;
	//maxedSkills = FindMaxedSpec(skill);
	samples = FindSampleSpec(skill);
	if(samples.size() > 0)
		//retr.items = samples;
		retr.SetItems(samples);
	retr.Set(skill);
	retr.DoModal();
	specific = Capitialize(retr.GetResult());
	

	return specific;
}

string CCharacter::Capitialize(string statement)
{
	char c;
	statement = Trim(statement);
	c = statement[0];
	statement[0] = toupper(c);
	for(int i=1;i< statement.length();i++)
	{
		c = statement[i]; statement[i] = tolower(c);
	}

	for(i=0;i<statement.length();i++)
	{
		c = statement[i];
		if (isspace(c))
		{
			c = statement[i+1];
			statement[i+1] = toupper(c);
		}
	}

	return statement;
	
}

int CCharacter::GetMod(int score)
{
	int mod;

	if (score>5)
	{
		
		int x;
		x= score/2;
		mod = x - 3;
		return mod;
	}

	else if ((score <5) && (score>0))
		return (score-4);
	else
		return -3;
}

string CCharacter::Trim(string str)
{
	
	int num = str.length()-1; int i=0;
	char c = ' ';
		
	while(true)
	{
		char c =str[i];
		if(isspace(c))
			i++;
		else
			break;
	}

	while(true)
	{
		char c=str[num];
		if(isspace(c))
			num--;
		else
			break;
	}

	str = str.substr(i, num-(i-1));

	return str;


}

string CCharacter::ToString(BSTR str)
{
	string temp;
	temp = _com_util::ConvertBSTRToString(str);
	::SysFreeString(str);
	return temp;

}


STDMETHODIMP CCharacter::Untrained_Add()
{
	// TODO: Add your implementation code here

	if(!skills.IsExist("Armed Combat"))
		skills.Add("Armed Combat",UserSpecify("Armed Combat"),0);
	if(!skills.IsExist("Athletics"))
		skills.Add("Athletics","",0);
	if(!skills.IsExist("Conceal"))
		skills.Add("Conceal","",0);
	if(!skills.IsExist("Enterprise:Administration"))
		skills.Add("Enterprise:Administration","",0);
	if(!skills.IsExist("Enterprise:Business"))
		skills.Add("Enterprise:Business","",0);
	if(!skills.IsExist("Enterprise:Streetwise"))
		skills.Add("Enterprise:Streetwise","",0);
	if(!skills.IsExist("First Aid"))
		skills.Add("First Aid","",0);
	if(!skills.IsExist("Gaming"))
		skills.Add("Gaming","",0);
	if(!skills.IsExist("Gymnastics"))
		skills.Add("Gymnastics","",0);
	if(!skills.IsExist("Impersonate"))
		skills.Add("Impersonate","",0);
	if(!skills.IsExist("Influence"))
		skills.Add("Influence","",0);
	if(!skills.IsExist("Inquire"))
		skills.Add("Inquire","",0);
	if(!skills.IsExist("Investigate"))
		skills.Add("Investigate","",0);
	if(!skills.IsExist("Negotiate"))
		skills.Add("Negotiate","",0);
	if(!skills.IsExist("Observe"))
		skills.Add("Observe","",0);
	if(!skills.IsExist("Persuade"))
		skills.Add("Persuade","",0);
	if(!skills.IsExist("Ranged Combat:Energy"))
		skills.Add("Ranged Combat:Energy","",0);
	if(!skills.IsExist("Ranged Combat:Archaic"))
		skills.Add("Ranged Combat:Archaic","",0);
	if(!skills.IsExist("Ranged Combat:Projectile"))
		skills.Add("Ranged Combat:Projectile","",0);
	if(!skills.IsExist("Sport"))
		skills.Add("Sport","",0);
	if(!skills.IsExist("Stealth"))
		skills.Add("Stealth","",0);
	if(!skills.IsExist("Survival"))
		skills.Add("Survival","",0);
	if(!skills.IsExist("Unarmed Combat"))
		skills.Add("Unarmed Combat",UserSpecify("Unarmed Combat"),0);

	return S_OK;
}



STDMETHODIMP CCharacter::put_Language(BSTR newVal)
{
	// TODO: Add your implementation code here
	languages.push_back(ToString(newVal));

	return S_OK;
}

STDMETHODIMP CCharacter::get_AttributeModifier(int number, int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = GetMod(number);

	return S_OK;
}

STDMETHODIMP CCharacter::ShowInfo(BSTR caption)
{
	// TODO: Add your implementation code here

	msg.SetInformation(ToString(caption));
	msg.DoModal();

	return S_OK;
}

STDMETHODIMP CCharacter::ShowMessage(BSTR caption)
{
	// TODO: Add your implementation code here

	msg.SetWarning(ToString(caption));
	msg.DoModal();

	return S_OK;
}

STDMETHODIMP CCharacter::get_IsFavorite(BSTR name, BOOL *pVal)
{
	// TODO: Add your implementation code here

	string nomen = ToString(name);
	if((nomen == favAttribute1) || (nomen==favAttribute2)||(nomen==favReaction))
	{
		*pVal = TRUE;
	}
	else
		*pVal = FALSE;

	return S_OK;
}

STDMETHODIMP CCharacter::get_IsProfessionalSkill(BSTR skill, BOOL *pVal)
{
	// TODO: Add your implementation code here

	//vector <string> ::iterator pos;
	string nomen = ToString(skill);
	*pVal = FALSE;
	if(elite =="none")
	{
	for(int i=0;i<package.GetProCount();i++)
	{
		string skll= package.GetProSkill(i);
		string sub = package.GetProSubSkill(i);
		
		if(skll == "Language")
		{
			if(binary_search(languages.begin(),languages.end(),nomen))
			//if(languages.Find(nomen) != NULL)
				*pVal = TRUE;
		}		
		else if(sub != "x")
		{
			if(sub != "")
			{
				skll = skll +":" +sub;
				if(skll == nomen)
					*pVal = TRUE;
			}
			else
			{
				if(skll == nomen)
					*pVal = TRUE;
			}
		}
		else
		{
			string temp = nomen;
			int i=temp.find(':');
			//int i = temp.Find(":");
			//temp= temp.Left(i);
			temp = temp.substr(i+1,temp.size()-1);
			if(temp == skll)
				*pVal = TRUE;

		}

	}
	}
	else
	{
		//add species skills to elite
		if(!binary_search(eliteProSkills.begin(),eliteProSkills.end(),nomen))
			*pVal = TRUE;
		//if(eliteProSkills.Find(nomen) != NULL)
		//	*pVal = TRUE;
		else if(!binary_search(languages.begin(),languages.end(),nomen))
			*pVal = TRUE;
		//else if(languages.Find(nomen) != NULL)
		//	*pVal = TRUE;		

	}

	return S_OK;
}



STDMETHODIMP CCharacter::DepartmentHead_Add(int choice, int index)
{
	// TODO: Add your implementation code here

	string skill=package.GetProSkill(index);
	string spec;
	string sub=package.GetProSubSkill(index);

	if(skill == "Language")
	{
		skill = UserSpecify(skill);
		sub = "";
	}

	if(edges.IsExist("Command"))
	{
		edges.Add("Command 2");
	}
	else
	{
		edges.Add("Command");
	}

	if(choice == 0)//add +1 to professional skill
	{
		if(sub=="x")
		{
	
			skill = UserSelectSkill(skill);
			
		}
		else if (sub != "")
		{
			skill = skill+":"+sub;
		}
		
		if(skills.IsExist(skill))
			skills.Modify(skill,1);
		else
		{
			if(package.GetProSpeciality(index) !="x")
				skills.Add(skill,"",1);
			else
				skills.Add(skill,UserSpecify(skill),1);
		}
	}
	else //add new speciality
	{
respecify:
		if(sub=="x")
		{
	
			skill = UserSelectSkill(skill);
			spec = UserSpecify(skill);
		
		}	
		else 
		{
			if(sub !="")
				skill = skill+":"+sub;
			spec = UserSpecify(skill);
			
	
		}
		if(!skills.IsExist(skill,spec))
			skills.Add(skill,spec,0);
		else
		{
			
			msg.SetWarning("This speciality already exist, select another");
			if(msg.DoModal() == IDOK)
				goto respecify;
		}
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_Reactions(int index, int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = reactions[index];

	return S_OK;
}

STDMETHODIMP CCharacter::get_Defense(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = attributes[1].mod + 7;

	return S_OK;
}

STDMETHODIMP CCharacter::put_Defense(int newVal)
{
	// TODO: Add your implementation code here

	//defense = newVal;

	return S_OK;
}

STDMETHODIMP CCharacter::Traits_RemoveAll()
{
	// TODO: Add your implementation code here

	edges.RemoveAll();
	flaws.RemoveAll();

	return S_OK;
}

STDMETHODIMP CCharacter::get_UserSpeciality(BSTR skill, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(UserSpecify(ToString(skill)).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::ProfPackage_Entry(BSTR skill, BSTR speciality, int level)
{
	// TODO: Add your implementation code here

	string nomen1 = ToString(skill);
	string nomen2 = ToString(speciality);

	if (nomen2 == "NA")
		nomen2 = "";
	else
		nomen2 =Capitialize(nomen2);

	if(!skills.IsExist(nomen1,nomen2))
		skills.Add(nomen1,nomen2,0);

	for(int i=0;i<skills.GetCount();i++)
	{
		if(skills.GetName(i) == nomen1)
		{
			if(6< skills.GetLevel(i) + level)
			{
				if(skills.GetLevel(i)<6)
				{
					skills.Modify(nomen1,skills.GetSpecific(i),
						6-skills.GetLevel(i));
				}
				
			}
			else
				skills.Modify(nomen1,skills.GetSpecific(i),level);
		}

	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfPackagesCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = package.GetPackageCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfPackages(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(package.PackageTypes(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::LoadProfSkills()
{
	// TODO: Add your implementation code here

	string skill,subskill,specific;
	int level;

	for(int i=0;i<package.GetAutoCount();i++)
	{

		
		skill = package.GetAutoSkill(i);
		subskill = package.GetAutoSubSkill(i);
		specific = package.GetAutoSpeciality(i);
		level = package.GetAutoLevel(i);

		if(skill == "Language")
		{
			skill = UserSpecify(skill);
			subskill = "";
			specific = "";
			languages.push_back(skill);
		}

		if((package.GetAutoSubSkill(i)=="x")||(package.GetAutoSpeciality(i)=="x"))
		{
			
			if(subskill == "x")
			{
				skill = UserSelectSkill(skill);
				
			}

			if((specific == "x") && (subskill==""))
			{
				specific = UserSpecify(skill);

			}
			else if((specific == "x") && (subskill !=""))
			{
				if (subskill != "x")
					skill = skill+":"+subskill;
				specific = UserSpecify(skill);
			}
			
			if(!skills.IsExist(skill,specific))
				skills.Add(skill,specific,0);

			int rem;
			for(int q=0;q<skills.GetCount();q++)
			{
				if(skills.GetName(q)==skill)
				{
					if(6<(skills.GetLevel(q)+level))
					{
						if(skills.GetLevel(q)<6)
						{
							rem = 6-skills.GetLevel(q);
							skills.Modify(skill, skills.GetSpecific(q),rem);
							
						}
						
					}
					else
						skills.Modify(skill, skills.GetSpecific(q),level);
				}

			}
		}

		else
		{
			if (subskill != "")
				skill = skill +":"+subskill;

			if(!skills.IsExist(skill,specific))
			{
				skills.Add(skill,specific,0);
				
			}
			for(int j=0;j<skills.GetCount();j++)
			{
				
				if(skills.GetName(j)==skill)
				{
					if(6<(skills.GetLevel(j)+level))
					{
						if(skills.GetLevel(j)<6)
						{
							skills.Modify(skill,skills.GetSpecific(j),
								6-skills.GetLevel(j));
						}
					}
					else
						skills.Modify(skill, skills.GetSpecific(j),level);
				}

			}

		}

	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfEdges(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(package.GetProEdges(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfEdgesCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = package.ProEdgesCount();

	return S_OK;
}

STDMETHODIMP CCharacter::Background_Entry(BSTR skill, int level)
{
	// TODO: Add your implementation code here

	string nomen = ToString(skill);
	BOOL found;
	string temp,specific;
	found=FALSE;

	if (nomen == "Brawling")
	{
		temp= nomen;
		nomen = "Unarmed Combat";
	}

	else if (nomen == "Simple Weapon")
	{
		temp = nomen;
		nomen = "Armed Combat";
	}
	else if(nomen == "Language")
	{
		nomen = UserSpecify(nomen);
		languages.push_back(nomen);

	}

	for(int i=0;i<skills.GetCount();i++)
	{
		if(skills.GetName(i)==nomen)
		{
			found=TRUE;
			specific = skills.GetSpecific(i);
		}
	}

	if(found)
	{
		//skills.Modify(nomen,specific,level);
		for(int i=0;i<skills.GetCount();i++)
		{
		if(skills.GetName(i) == nomen)
		{
			if(6< skills.GetLevel(i) + level)
			{
				if(skills.GetLevel(i)<6)
				{
					skills.Modify(nomen,skills.GetSpecific(i),
						6-skills.GetLevel(i));
				}
				
			}
			else
				skills.Modify(nomen,skills.GetSpecific(i),level);
		}

		}
	}

	else
	{
		if(nomen== "Language")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		
		else if (nomen == "Knowledge:Culture")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:History")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:Religion")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:Specific World")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:Politics")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:Law")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Knowledge:Trivia")
		{
			specific = UserSpecify(nomen);
			skills.Add(nomen,specific,level);
		}
		else if (nomen == "Armed Combat")
		{
			if(temp != "Simple Weapon")
			{
				specific = UserSpecify(nomen);
				skills.Add(nomen,specific,level);
			}
			else
				skills.Add(nomen, temp, level);
		}
		else if (nomen == "Unarmed Combat")
		{
			if(temp != "Brawling")
			{
				specific = UserSpecify(nomen);
				skills.Add(nomen,specific,level);
			}
			else
				skills.Add(nomen, temp, level);
		}
		else
		{
			skills.Add(nomen,"",level);
		}
	}

	VortaBonus();

	return S_OK;
}

STDMETHODIMP CCharacter::LoadEliteTier()
{
	// TODO: Add your implementation code here

	if (elite=="Adept")
	{
		tierList.clear();
		tierList.push_back("Baffling Mysticism");
		tierList.push_back("Impenetrable Mind");		

	}
	else if(elite=="Ambassador")
	{
		tierList.clear();
		tierList.push_back("Adamant Resolve");
		tierList.push_back("Magnanimous");
		
	}
	else if(elite=="Assassin")
	{
		tierList.clear();
		tierList.push_back("Arms Proficiency");
		tierList.push_back("Stalking");

	}
	else if(elite=="Envoy")
	{
		tierList.clear();
		tierList.push_back("Cultural Proficiency");
		tierList.push_back("Diplomatic Tact");

	}
	else if(elite=="Explorer")
	{
		tierList.clear();
		tierList.push_back("Planetary Surveyor");
		tierList.push_back("Planetside Survivor");

	}
	else if(elite=="Free Trader")
	{
		tierList.clear();
		tierList.push_back("Business Savvy");
		tierList.push_back("Stanglehold");

	}
	else if(elite=="Inventor")
	{
		tierList.clear();
		tierList.push_back("Applied Engineering");
		tierList.push_back("Technophile");

	}
	else if(elite=="Mercenary")
	{
		tierList.clear();
		tierList.push_back("Recon");
		tierList.push_back("Tough Negotiator");

	}
	else if(elite=="Smuggler")
	{
		tierList.clear();
		tierList.push_back("False Credentials");
		tierList.push_back("Smuggler's Trade");


	}
	else if(elite=="Special Forces")
	{
		tierList.clear();
		tierList.push_back("Covert Ops");
		tierList.push_back("Demolition Expert");

	}
	else if(elite=="Spy")
	{
		tierList.clear();
		tierList.push_back("Gather Intelligence");
		tierList.push_back("Perspicacious");

	}
	else if(elite=="Weaponmaster")
	{
		tierList.clear();
		tierList.push_back("Sacred Weapon");
		tierList.push_back("Weaponcraft");

		
	}

	return S_OK;
}

STDMETHODIMP CCharacter::Dice_Rolls()
{
	// TODO: Add your implementation code here

	srand(GetTickCount());
	
	dice.clear();
	for(int i=0;i<9;i++)
	{
		//dice[i]= ;
		dice.push_back((rand ()%6+ 1) + (rand ()%6+ 1));
	}
	

	sort(dice.begin(),dice.end(), greater <int>());

	return S_OK;
}

STDMETHODIMP CCharacter::get_Dice(int index, int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = dice[index];

	return S_OK;
}

STDMETHODIMP CCharacter::get_Fave2Attribute(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(favAttribute2.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Fave2Attribute(BSTR newVal)
{
	// TODO: Add your implementation code here

	favAttribute2 = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Fave1Attribute(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(favAttribute1.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Fave1Attribute(BSTR newVal)
{
	// TODO: Add your implementation code here

	favAttribute1 = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_FaveReaction(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(favReaction.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_FaveReaction(BSTR newVal)
{
	// TODO: Add your implementation code here

	favReaction = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::Elite_Upgrade()
{
	// TODO: Add your implementation code here

	int j;
	int limit = skills.GetCount();
	int tempx;
	int num;
	int count;
	//DlgInfo dlg;
	if(profession=="Starship Command")
	{
		
		if(!skills.IsExist("Enterprise:Administration"))
			skills.Add("Enterprise:Administration","",4);
		else
		{
			SetLevel("Enterprise:Administration",4);
		}

		if(!skills.IsExist("Persuade"))
			skills.Add("Persuade","",3);
		else
		{
			SetLevel("Persuade",3);
			
		}

		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",2);
		else
		{
			SetLevel("System Operation",2);
		}

		if(reactions[3]<1)
			reactions[3] = 1;
		
		//dlg.m_prompt = profession + " upgrade complete";
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}
	else if(profession=="Starship Flight")
	{
		
		if(!skills.IsExist("System Operation","Flight Control"))
			skills.Add("System Operation","Flight Control",4);
		else
		{
			j=skills.GetLevelB("System Operation","Flight Control");
			if(j<4)
				skills.SetLevel("System Operation","Flight Control",4);
		}

		if(!skills.IsExist("Science:Space","Astronomy"))
			skills.Add("Science:Space","Astronomy",3);
		else
		{
			j=skills.GetLevelB("Science:Space","Astronomy");
			if(j<3)
				skills.SetLevel("Science:Space","Astronomy",3);
		}

		if(!skills.IsExist("Computer Use"))
			skills.Add("Computer Use","",2);
		else
		{
			SetLevel("Computer Use",2);
		}
		
		if(!skills.IsExist("Enterprise:Administration"))
			skills.Add("Enterprise:Administration","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
		
	}
	else if(profession == "Starship Engineering")
	{
		
		//***********one Engineering 4

		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Engineering:Propulsion") ||
				(skills.GetName(count)== "Engineering:Structural") ||
				(skills.GetName(count)== "Engineering:Systems"))
			{
				num++;
				tempx = count;
			}
		}

		if(num==0)
		{
			AddUpgrade("Engineering",4);
			//skills.Add("Engineering:Systems","",4);
		}
		else if(num == 1)
		{
				
			SetLevel(tempx,4);
				
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)== "Engineering:Systems") ||
				(skills.GetName(f)== "Engineering:Propulsion") ||
				(skills.GetName(f)== "Engineering:Structural"))&&
					(skills.GetLevel(f)>=4))
				{
					goto eng1;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)== "Engineering:Systems") ||
				(skills.GetName(k)== "Engineering:Propulsion") ||
				(skills.GetName(k)== "Engineering:Structural"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<4)))
					{
					level=skills.GetLevel(k);
					tempSkill = skills.GetName(k);
					tempSubSkill = skills.GetSpecific(k);

					}
			}
			skills.SetLevel(tempSkill,tempSubSkill,level);
		}
eng1:

		//***********end one Engineering 4

		if(!skills.IsExist("Science:Physical"))
			skills.Add("Science:Physical","",3);
		else
		{
			SetLevel("Science:Physical",3);
		}

		if(!skills.IsExist("Repair"))
			skills.Add("Repair","",3);
		else
		{
			SetLevel("Repair",3);
		}

		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}
	else if(profession == "Starship Operations")
	{
		
		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",4);
		else
		{
			SetLevel("System Operation",4);
		}

		if(!skills.IsExist("Engineering:Systems"))
			skills.Add("Engineering:Systems","",3);
		else
		{
			SetLevel("Engineering:Systems",3);
		}

		if(!skills.IsExist("Repair"))
			skills.Add("Repair","",3);
		else
		{
			SetLevel("Repair",3);
		}

		if(!skills.IsExist("Computer Use"))
			skills.Add("Computer Use","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();

	}
	else if(profession == "Starship Security")
	{
		
	
		if(!skills.IsExist("Observe"))
			skills.Add("Observe","",4);
		else
		{
			SetLevel("Observe",4);
		}

		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",3);
		else
		{
			SetLevel("Investigate",3);
		}

		//************Unarmed Combat 3
		int num=0;int count;
		for(count =0; count<skills.GetCount();count++)
		{
			if(skills.GetName(count)== "Unarmed Combat")
			{
				num++;
				tempx = count;
			}
		}

		if(num==0)
		{
			//AddUpgrade("Unarmed Combat","",3);
			skills.Add("Unarmed Combat",UserSpecify("Unarmed Combat"),
				3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(f)=="Unarmed Combat")&&
					(skills.GetLevel(f)>=3))
				{
					goto secur;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(k)=="Unarmed Combat")&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetSpecific(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
secur:

		/////***Unarmed Combat 3

		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}
	else if(profession == "Starship Counselor")
	{
		
		if(!skills.IsExist("Science:Social"))
			skills.Add("Science:Social","",4);
		else
		{
			SetLevel("Science:Social",4);
		}

		if(!skills.IsExist("Medicine","Psychology"))
			skills.Add("Medicine","Psychology",3);
		else
		{
			j=skills.GetLevelB("Medicine","Psychology");
			if(j<3)
				skills.SetLevel("Medicine","Psychology",3);
		}

		if(!skills.IsExist("Inquire","Interview"))
			skills.Add("Inquire","Interview",2);
		else
		{
			j=skills.GetLevelB("Inquire","Interview");
			if(j<2)
				skills.SetLevel("Inquire","Interview",2);
		}
		if(reactions[1]<1)
			reactions[1]=1;

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}
	else if(profession == "Starship Medicine")
	{
		
		if(!skills.IsExist("First Aid"))
			skills.Add("First Aid","",4);
		else
		{
			SetLevel("First Aid",4);
		}

		if(!skills.IsExist("Medicine"))
			skills.Add("Medicine","",3);
		else
		{
			SetLevel("Medicine",3);
		}

		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",3);
		else
		{
			SetLevel("System Operation",3);
		}

		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}

	else if(profession=="Starship Science")
	{
		
		if(!skills.IsExist("System Operation"))
			skills.Add("System Operation","",4);
		else
		{
			SetLevel("System Operation",4);
		}

		//Science skill 3

		if(!skills.IsExist("Computer Use"))
			skills.Add("Computer Use","",3);
		else
		{
			SetLevel("Computer Use",3);
		}

		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(profession + " upgrade complete");
		msg.DoModal();
	}

	if(elite == "Adept")
	{
		if(attributes[6].score<4)
		{
			
			
			msg.SetWarning("Only psionic based species");
			msg.DoModal();
			return S_FALSE;
		}
		if(attributes[2].score<7)
			attributes[2].score =7;
		if(!skills.IsExist("Mind Shield"))
			skills.Add("Mind Shield","",4);
		else
		{
			SetLevel("Mind Shield",4);
		}

		///*********psoinc skill 3 except mind shield

		int num=0;int count;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Mind Control") ||
				(skills.GetName(count)== "Empathy") ||
				(skills.GetName(count)== "Telepathy"))
			{
				num++;
				tempx = count;
			}
		}

		if(num==0)
		{
			skills.Add(UserSelectSkill("Psionic"),"",3);
			
		}
		else if(num == 1)
		{
				
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
				
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)== "Mind Control") ||
				(skills.GetName(f)== "Empathy") ||
				(skills.GetName(f)== "Telepathy"))&&
					(skills.GetLevel(f)>=3))
				{
					goto adept;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)== "Mind Control") ||
				(skills.GetName(k)== "Empathy") ||
				(skills.GetName(k)== "Telepathy"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
					{
					level=skills.GetLevel(k);
					tempSkill = skills.GetName(k);
					tempSubSkill = skills.GetSpecific(k);

					}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
adept:

		///****psionic

	

		//**********Religion 3
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if(skills.GetName(count)== "Knowledge:Religion")
				num++;
		}

		if(num==0)
		{
			string rel = UserSpecify("Knowledge:Religion");
			
			skills.Add("Knowledge:Religion",rel,3);
		}

		else if(num == 1)
		{
			j=skills.GetLevelA("Knowledge:Religion");
			if(j<3)
				skills.SetLevel("Knowledge:Religion",3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(f)=="Knowledge:Religion")&&
					(skills.GetLevel(f)>=3))
				{
					goto spacedock2;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(k)=="Knowledge:Religion")&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
spacedock2:
		///*********End Religion 3
			
		//Unarmed Combat 1
		if(!skills.IsExist("Unarmed Combat"))
			skills.Add("Unarmed Combat",UserSpecify("Unarmed Combat"),1);

		//dlg.m_prompt = ;
		msg.SetInformation(elite + " upgrade complete");
		msg.DoModal();
	}
	else if(elite == "Ambassador")
	{
		if(!edges.IsExist("Promotion"))
			edges.Add("Promotion");

		if(attributes[4].score<8)
			attributes[4].score = 8;

		if(!skills.IsExist("Negotiate","Mediate"))
			skills.Add("Negotiate","Mediate",4);
		else
		{
			j = skills.GetLevelB("Negotiate","Mediate");
			if(j<4)
			skills.SetLevel("Negotiate","Mediate",4);
		}

		if(!skills.IsExist("Knowledge:Law"))
			skills.Add("Knowledge:Law",UserSpecify("Knowledge:Law"),3);
		else
		{
			SetLevel("Knowledge:Law",3);
		}

		if(!skills.IsExist("Persuade"))
			skills.Add("Persuade","",2);
		else
		{
			SetLevel("Persuade",2);
		}

		//*******Knowledge 1
		if(!skills.IsExist("Knowledge:Specific World"))
			skills.Add("Knowledge:Specific World",UserSpecify("Knowledge:Specific World"),
			1);
		
		///*******
		//dlg.m_prompt = ;
		msg.SetInformation(elite + " upgrade complete");
		msg.DoModal();
	}
	else if(elite == "Assassin")
	{
		if(!edges.IsExist("Fame"))
			edges.Add("Fame");

		if(attributes[1].score<8)
			attributes[1].score=8;

		if(!skills.IsExist("Stealth"))
			skills.Add("Stealth","",4);
		else
		{
			SetLevel("Stealth",4);
		}

		//*****Armed Combat or Ranged Combat(speciality) 3
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Armed Combat") ||
				(skills.GetName(count)=="Ranged Combat:Archaic")||
				(skills.GetName(count)=="Ranged Combat:Energy") ||
				(skills.GetName(count)=="Ranged Combat:Projectile"))
			{
				num++;
				tempx=count;
			}
		}

		if(num==0)
		{
			string ar = UserSelectSkill("Armed & Ranged");
			skills.Add(ar,UserSpecify(ar),3);
			
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)=="Armed Combat") ||
					(skills.GetName(f)=="Ranged Combat:Archaic") ||
					(skills.GetName(f)=="Ranged Combat:Energy") ||
					(skills.GetName(f)=="Ranged Combat:Projectile")) &&
					(skills.GetLevel(f)>=3))
				{
					goto assasisn;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)=="Armed Combat") ||
					(skills.GetName(k)=="Ranged Combat:Archaic") ||
					(skills.GetName(k)=="Ranged Combat:Energy") ||
					(skills.GetName(k)=="Ranged Combat:Projectile"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
assasisn:

		//******End Armed Combat or Ranged Combat(speciality) 3
		if(!skills.IsExist("Science:Physical","Chemistry"))
			skills.Add("Science:Physical","Chemistry",1);

		if(!skills.IsExist("Impersonate"))
			skills.Add("Impersonate","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(elite + " upgrade complete");
		msg.DoModal();
	}
	else if(elite == "Envoy")
	{
		if(!edges.IsExist("Cultural Flexibility"))
			edges.Add("Cultural Flexibility");

		if(attributes[5].score<8)
			attributes[5].score = 8;

		if(!skills.IsExist("Science:Social"))
			skills.Add("Social:Science","",4);
		else
		{
			SetLevel("Science:Social", 4);
		}

		//********Culture 3
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if(skills.GetName(count)== "Knowledge:Culture")
			{
			num++;
			tempx=count;
			}
		}

		if(num==0)
		{
			skills.Add("Knowledge:Culture",UserSpecify("Knowledge:Culture"),
				3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(f)=="Knowledge:Culture")&&
					(skills.GetLevel(f)>=3))
				{
					goto envoy;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if((skills.GetName(k)=="Knowledge:Culture")&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
envoy:
		//********End Culture 3
		
		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",3);
		else
		{
			SetLevel("Investigate",3);
		}

		if(!skills.IsExist("Stealth"))
			skills.Add("Stealth","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(elite + " upgrade complete");
		msg.DoModal();

	}
	else if(elite == "Explorer")
	{
		
		if(!edges.IsExist("Curious"))
			edges.Add("Curious");

		if(attributes[3].score<8)
			attributes[3].score=8;

		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",1);
		
		if(!skills.IsExist("Survival"))
			skills.Add("Survival","",3);
		else
		{
			SetLevel("Survival",3);
		}

		if((!skills.IsExist("Science:Life"))&&(!skills.IsExist("Science:Physical"))
			&&(!skills.IsExist("Science:Planetary"))
			&&(!skills.IsExist("Science:Social"))&&(!skills.IsExist("Science:Space")))
		{
			string xSkill = UserSelectSkill("Science");
			skills.Add(xSkill,"",4);
			xSkill = UserSelectSkill("Science");
			skills.Add(xSkill,"",3);
		}

		//DlgMessage dlg1;
		//dlg1.m_warning = ;
		msg.SetWarning("Explorer class is not fully supported. Refer to pg 161 in Player's Guide");
		msg.DoModal();
		
		// Two science skills 3 or above
	}
	else if(elite == "Free Trader")
	{
		if(!edges.IsExist("Shrewd"))
			edges.Add("Shrewd");
		if(reactions[1]<2)
			reactions[1]=2;
		if(!skills.IsExist("Enterprise:Business"))
			skills.Add("Enterprise:Business","",4);
		else
		{
			SetLevel("Enterprise:Business",4);
		}

		if(!skills.IsExist("System Operation", "Flight Control"))
			skills.Add("System Operation","Flight Control",3);
		else
		{
			 j= skills.GetLevelB("System Operation","Flight Control");
			 if(j<3)
				 skills.SetLevel("System Operation","Flight Control",3);
		}

		if(!skills.IsExist("Negotiate"))
			skills.Add("Negotiate","",3);
		else
		{
			SetLevel("Negotiate",3);
		}

		if(!skills.IsExist("Appraise"))
			skills.Add("Appraise","",1);

		//dlg.m_prompt = ;
		msg.SetInformation(elite + " upgrade complete");
		msg.DoModal();

	}
	else if(elite == "Inventor")
	{
		if(!edges.IsExist("Innovative"))
			edges.Add("Innovative");
		if(attributes[2].score<8)
			attributes[2].score=8;
		if(!skills.IsExist("Construct"))
			skills.Add("Construct","",4);
		else
		{
			SetLevel("Construct",4);
		}

		//***********one Engineering 4

		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Engineering:Propulsion") ||
				(skills.GetName(count)== "Engineering:Structural") ||
				(skills.GetName(count)== "Engineering:Systems"))
			{
				num++;
				tempx = count;
			}
		}

		if(num==0)
		{
			AddUpgrade("Engineering",4);
			//skills.Add("Engineering:Systems","",4);
		}
		else if(num == 1)
		{
				
			j=skills.GetLevel(tempx);
			if(j<4)
				skills.SetLevel(tempx,4);
			
				
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)== "Engineering:Systems") ||
				(skills.GetName(f)== "Engineering:Propulsion") ||
				(skills.GetName(f)== "Engineering:Structural"))&&
					(skills.GetLevel(f)>=4))
				{
					goto inv;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)== "Engineering:Systems") ||
				(skills.GetName(k)== "Engineering:Propulsion") ||
				(skills.GetName(k)== "Engineering:Structural"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<4)))
					{
					level=skills.GetLevel(k);
					tempSkill = skills.GetName(k);
					tempSubSkill = skills.GetSpecific(k);

					}
			}
			skills.SetLevel(tempSkill,tempSubSkill,level);
		}
inv:

		//***********end one Engineering 4

		if(!skills.IsExist("Science:Physical"))
			skills.Add("Science:Physical","",3);
		else
		{
			SetLevel("Science:Physical",3);
		}

		if(!skills.IsExist("Repair"))
			skills.Add("Repair","",1);

		msg.SetInformation( elite + " upgrade complete");
		msg.DoModal();
	}
	else if(elite == "Mercenary")
	{
		if(!edges.IsExist("Bold"))
			edges.Add("Bold");
		if(reactions[2]<2)
			reactions[2] = 2;

		//////*****Armed Combat or Unarmed Combat 3
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Armed Combat") ||
				(skills.GetName(count)=="Unarmed Combat"))
			{
				num++;
				tempx=count;
			}
		}

		if(num==0)
		{
			//Automatically adds Ranged Engery..user should have a choice
			string arc;
			arc = UserSelectSkill("Armed & Unarmed");
			
			skills.Add(arc,UserSpecify(arc),3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)=="Armed Combat") ||
					(skills.GetName(f)=="Unarmed Combat")) &&
					(skills.GetLevel(f)>=3))
				{
					goto merc1;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)=="Armed Combat") ||
					(skills.GetName(k)=="Unarmed Combat"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
merc1:
		///*****end Armed and Unarmed 3

		///*******Ranged Combat 4
				
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)=="Ranged Combat:Archaic")||
				(skills.GetName(count)=="Ranged Combat:Energy") ||
				(skills.GetName(count)=="Ranged Combat:Projectile"))
			{
				num++;
				tempx=count;
			}
		}

		if(num==0)
		{
			AddUpgrade("Ranged Combat",4);
			//Automatically adds Ranged Engery..user should have a choice
			//skills.Add("Ranged Combat:[Energy,Archaic,Projectile]","",3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,4);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)=="Ranged Combat:Archaic") ||
					(skills.GetName(f)=="Ranged Combat:Energy") ||
					(skills.GetName(f)=="Ranged Combat:Projectile")) &&
					(skills.GetLevel(f)>=4))
				{
					goto merc2;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)=="Ranged Combat:Archaic") ||
					(skills.GetName(k)=="Ranged Combat:Energy") ||
					(skills.GetName(k)=="Ranged Combat:Projectile"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<4)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,4);
		}
merc2:
		if(!skills.IsExist("Athletics"))
			skills.Add("Athletics","",3);
		else
		{
			SetLevel("Athletics",3);
		}

		if(!skills.IsExist("Observe"))
			skills.Add("Observe","",1);

		msg.SetInformation( elite + " upgrade complete");
		msg.DoModal();

	}
	else if(elite == "Smuggler")
	{
		if(!edges.IsExist("Connections"))
			edges.Add("Connections");
		if(attributes[5].score<8)
			attributes[5].score=8;
		
		if(!skills.IsExist("Conceal"))
			skills.Add("Conceal","",4);
		else
		{
			SetLevel("Conceal",4);
		}

		if(!skills.IsExist("Enterprise:Streetwise"))
			skills.Add("Enterprise:Streetwise","",3);
		else
		{
			SetLevel("Enterprise:Streetwise",3);
		}

		if(!skills.IsExist("Enterprise:Business"))
			skills.Add("Enterprise:Business","",3);
		else
		{
			SetLevel("Enterprise:Business",3);
		}

		if(!skills.IsExist("Influence"))
			skills.Add("Influence","",1);
		
		msg.SetInformation( elite + " upgrade complete");
		msg.DoModal();

	}
	else if(elite == "Special Forces")
	{
		if(!edges.IsExist("Fit"))
			edges.Add("Fit");

		if(reactions[0]<2)
			reactions[0] = 2;

		//*****Armed Combat or Unarmed Combat 3
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)== "Armed Combat") ||
				(skills.GetName(count)=="Unarmed Combat"))
			{
				num++;
				tempx=count;
			}
		}

		if(num==0)
		{
			string auc = UserSelectSkill("Armed & Unarmed");
			skills.Add(auc,UserSpecify(auc),3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,3);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)=="Armed Combat") ||
					(skills.GetName(f)=="Unarmed Combat")) &&
					(skills.GetLevel(f)>=3))
				{
					goto sforces1;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)=="Armed Combat") ||
					(skills.GetName(k)=="Unarmed Combat"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<3)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,3);
		}
sforces1:
		///*****end Armed and Unarmed 3

		///*******Ranged Combat 4
				
		num=0;
		for(count =0; count<skills.GetCount();count++)
		{
			if((skills.GetName(count)=="Ranged Combat:Archaic")||
				(skills.GetName(count)=="Ranged Combat:Energy") ||
				(skills.GetName(count)=="Ranged Combat:Projectile"))
			{
				num++;
				tempx=count;
			}
		}

		if(num==0)
		{
			AddUpgrade("Ranged Combat",4);
			//Automatically adds Ranged Engery..user should have a choice
			//skills.Add("Ranged Combat:[Energy,Archaic,Projectile]","",3);
		}

		else if(num == 1)
		{
			j=skills.GetLevel(tempx);
			if(j<3)
				skills.SetLevel(tempx,4);
		}
		else
		{
			for(int f=0;f<skills.GetCount();f++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(f)=="Ranged Combat:Archaic") ||
					(skills.GetName(f)=="Ranged Combat:Energy") ||
					(skills.GetName(f)=="Ranged Combat:Projectile")) &&
					(skills.GetLevel(f)>=4))
				{
					goto sforces2;
				}
			}			
			
			int level=0;
			string tempSkill;
			string tempSubSkill;

			for(int k=0; k<skills.GetCount();k++)
			{
				//**********BEWARE OF LAZY EVALUATION**********
				if(((skills.GetName(k)=="Ranged Combat:Archaic") ||
					(skills.GetName(k)=="Ranged Combat:Energy") ||
					(skills.GetName(k)=="Ranged Combat:Projectile"))&&
					((skills.GetLevel(k)>level) && 
					(skills.GetLevel(k)<4)))
				{
					level=skills.GetLevel(k);
					tempSubSkill = skills.GetSpecific(k);
					tempSkill = skills.GetName(k);
				}
			}
			skills.SetLevel(tempSkill,tempSubSkill,4);
		}
sforces2:
		///******* end Ranged Combat 4
		if(!skills.IsExist("Stealth"))
			skills.Add("Stealth","",3);
		else
		{
			SetLevel("Stealth",3);
		}

		if(!skills.IsExist("Demolitions"))
			skills.Add("Demolitions","",1);

		msg.SetInformation( elite + " upgrade complete");
		msg.DoModal();
		
	}
	else if(elite == "Spy")
	{
		if(!edges.IsExist("Confident"))
			edges.Add("Confident");
		if(attributes[5].score<8)
			attributes[5].score=8;
		if(!skills.IsExist("Computer Use"))
			skills.Add("Computer Use","",4);
		else
		{
			SetLevel("Computer Use",4);
		}

		if(!skills.IsExist("Investigate"))
			skills.Add("Investigate","",3);
		else
		{
			SetLevel("Investigate",3);
		}

		if(!skills.IsExist("Observe"))
			skills.Add("Observe","",3);
		else
		{
			SetLevel("Observe",3);
		}

		if(!skills.IsExist("Forgery"))
			skills.Add("Forgery","",1);

		msg.SetInformation( elite + " upgrade complete");
		msg.DoModal();
	}
	else if(elite == "Weaponmaster")
	{
		if(!edges.IsExist("Weapon Mastery"))
			edges.Add("Weapon Mastery");
		if(attributes[1].score < 8)
			attributes[1].score=8;
		if(!skills.IsExist("Armed Combat")&& !skills.IsExist("Unarmed Combat"))
		{
			string wSkill = UserSelectSkill("Armed & Unarmed");
			skills.Add(wSkill,UserSpecify(wSkill),3);
		}
		else
			SetLevel("Unarmed Combat",3);

		if(!skills.IsExist("Armed Combat"))
			skills.Add("Armed Combat",UserSpecify("Armed Combat"),4);
		else
			SetLevel("Armed Combat",4);

		if(!skills.IsExist("Religion"))
			skills.Add("Religion",UserSpecify("Religion"),3);
		else
			SetLevel("Religion",3);

		if(!skills.IsExist("Athletics"))
			skills.Add("Athletics","",1);
		
		
		msg.SetWarning("Weaponmaster class is not fully supported. Refer to pg 161 in Player's Guide");
		msg.DoModal();
		
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_TierList(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(tierList[index].c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_TierList_Count(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = tierList.size();

	return S_OK;
}

STDMETHODIMP CCharacter::LoadTier()
{
	// TODO: Add your implementation code here

	if(profession == "Diplomat")
	{
		tierList.clear();
		tierList.push_back("Bluff");
		tierList.push_back("Gain Trust");
		tierList.push_back("Insight");
		tierList.push_back("Educated");

	}
	else if(profession=="Merchant")
	{
		tierList.clear();
		tierList.push_back("Business Acumen");
		tierList.push_back("Connections");
		tierList.push_back("Horse-Trading");
		tierList.push_back("Pandering");

	}
	else if(profession=="Mystic")
	{
		tierList.clear();
		tierList.push_back("Conviction");
		tierList.push_back("Inquisition");
		tierList.push_back("Mind over Body");
		tierList.push_back("Wandering");
	}
	else if(profession=="Rogue")
	{
		tierList.clear();
		tierList.push_back("Con Artist");
		tierList.push_back("Fleet of Foot");
		tierList.push_back("Lurking in Shadows");
		tierList.push_back("Scoundrel's Fortune");

	}
	else if(profession=="Scientist")
	{
		tierList.clear();
		tierList.push_back("Area of Expertise");
		tierList.push_back("Focus");
		tierList.push_back("Secretive");
		tierList.push_back("Technophile");
	}
	else if(profession=="Soldier")
	{
		tierList.clear();
		tierList.push_back("Evasion");
		tierList.push_back("Favored Weapon");
		tierList.push_back("Reconnaissance");
	}
	else if(profession=="Starship Officer")
	{
		tierList.clear();
		//tier.Add("Starship Duty");
	}		
	else if(profession=="Starship Command")
	{
		tierList.clear();
		tierList.push_back("Commanding Prescence");
		tierList.push_back("Starship/Starbase Protocol");
	}
	else if(profession=="Starship Engineering")
	{
		tierList.clear();
		tierList.push_back("Engineering Certification");
		tierList.push_back("Engineering Expertise");
	}
	else if(profession=="Starship Operations")
	{
		tierList.clear();
		tierList.push_back("Duty Officer");
		tierList.push_back("Station Proficiency");

	}
	else if(profession=="Starship Security")
	{
		tierList.clear();
		tierList.push_back("Security Ops");
		tierList.push_back("Security Protocols");
	}
	else if(profession=="Starship Flight")
	{
		tierList.clear();
		tierList.push_back("Astrogation");
		tierList.push_back("Atmospheric Craft");
	}
	else if(profession=="Starship Counselor")
	{
		tierList.clear();
		tierList.push_back("Pathos");
		tierList.push_back("Ship's Counselor");
	}
	else if(profession=="Starship Medicine")
	{
		tierList.clear();
		tierList.push_back("Field Medicine");
		tierList.push_back("General Medicine");
	}
	else if(profession=="Starship Science")
	{
		tierList.clear();
		tierList.push_back("Journeyman");
		tierList.push_back("Field Research");
	}

	return S_OK;
}

STDMETHODIMP CCharacter::Rank_Assign()
{
	// TODO: Add your implementation code here

	if(rank >=0)
	{
		char chill[2];
		string cRank;
		sprintf(chill,"%d",rank);
		cRank = chill;
		cRank = "Promotion:"+cRank;
		
		if(!edges.IsExist(cRank))
		{
			edges.Add(cRank);
		}
	}

	return S_OK;
}

STDMETHODIMP CCharacter::Age_Effects()
{
	// TODO: Add your implementation code here

	int i;
	if(age == "Child")
	{
		attributes[0].score = attributes[0].score-2;
		attributes[3].score = attributes[3].score-2;
		attributes[4].score = attributes[4].score-2;

		attributes[2].score = attributes[2].score-1;
		attributes[1].score = attributes[1].score-1;
		attributes[5].score = attributes[5].score-1;

		for(i=0;i<4;i++)
		{
			reactions[i] = reactions[i]-1;
		}
	}
	else if(age == "Young")
	{
		for(i=0;i<7;i++)
			attributes[i].score = attributes[i].score-1;
	}
	else if(age == "Old")
	{
		attributes[0].score = attributes[0].score-1;
		attributes[3].score = attributes[3].score-1;
		attributes[1].score = attributes[1].score-1;

		attributes[2].score = attributes[2].score+1;
		attributes[4].score = attributes[4].score+1;
		attributes[5].score = attributes[5].score+1;

		reactions[2] = reactions[2]-1;
		reactions[0] = reactions[0]-1;
		reactions[1] = reactions[1]+1;
	}
	else if(age == "Very Old")
	{
		attributes[0].score = attributes[0].score-2;
		attributes[3].score = attributes[3].score-2;
		attributes[1].score = attributes[1].score-2;

		attributes[4].score = attributes[4].score+1;
		attributes[5].score = attributes[5].score+1;

		reactions[2] = reactions[2]-2;
		reactions[0] = reactions[0]-2;
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_Renown(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = pkSpecies.GetRenown();

	return S_OK;
}

STDMETHODIMP CCharacter::put_Renown(int newVal)
{
	// TODO: Add your implementation code here
	
	//renown = newVal;

	return S_OK;
}

STDMETHODIMP CCharacter::get_Courage(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = pkSpecies.GetCourage();

	return S_OK;
}

STDMETHODIMP CCharacter::put_Courage(int newVal)
{
	// TODO: Add your implementation code here

	courage = newVal;

	return S_OK;
}

STDMETHODIMP CCharacter::get_Health(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = attributes[3].score + attributes[0].mod + pkSpecies.GetHealth();

	return S_OK;
}

STDMETHODIMP CCharacter::put_Health(int newVal)
{
	// TODO: Add your implementation code here

	health = newVal;

	return S_OK;
}

STDMETHODIMP CCharacter::get_Species(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(species.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Species(BSTR newVal)
{
	// TODO: Add your implementation code here

	species = ToString(newVal);
	pkSpecies.Species(ToString(newVal));

	return S_OK;
}

STDMETHODIMP CCharacter::get_Elite(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal= _com_util::ConvertStringToBSTR(elite.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Elite(BSTR newVal)
{
	// TODO: Add your implementation code here

	elite = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Profession(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(profession.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Profession(BSTR newVal)
{
	// TODO: Add your implementation code here

	profession = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Age(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(age.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Age(BSTR newVal)
{
	// TODO: Add your implementation code here

	age = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Rank(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = rank;

	return S_OK;
}

STDMETHODIMP CCharacter::put_Rank(int newVal)
{
	// TODO: Add your implementation code here

	rank = newVal;

	return S_OK;
}

STDMETHODIMP CCharacter::get_Gender(BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(gender.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::put_Gender(BSTR newVal)
{
	// TODO: Add your implementation code here

	gender = ToString(newVal);

	return S_OK;
}

STDMETHODIMP CCharacter::get_AutoCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = package.GetAutoCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_AutoLevel(int index, int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = package.GetAutoLevel(index);

	return S_OK;
}

STDMETHODIMP CCharacter::get_AutoSpeciality(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(package.GetAutoSpeciality(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_AutoSubSkill(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(package.GetAutoSubSkill(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_AutoSkill(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(package.GetAutoSkill(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfessionalCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = package.GetProCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfessionalSpeciality(int index, BSTR skill, BSTR *pVal)
{
	// TODO: Add your implementation code here

	if(package.GetProSpeciality(index)=="x")
	{
				
		string spec= ToString(skill);
		spec = UserSpecify(spec);
		*pVal = _com_util::ConvertStringToBSTR(spec.c_str());
	}
	else
	{
		*pVal = _com_util::ConvertStringToBSTR(package.GetProSpeciality(index).c_str());
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfessionalSubSkill(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	string skill;
	if(package.GetProSubSkill(index)=="x")
	{
		
		skill = package.GetProSkill(index);
		skill = UserSelectSkill(skill);
		*pVal = _com_util::ConvertStringToBSTR(skill.c_str());
	}
	else
	{
		skill ="";
		*pVal = _com_util::ConvertStringToBSTR(skill.c_str());
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_ProfessionalSkill(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	if((package.GetProSubSkill(index) !="") && (package.GetProSubSkill(index) !="x"))
	{
		string skill;
		skill= package.GetProSkill(index)+":"+package.GetProSubSkill(index);
		*pVal = _com_util::ConvertStringToBSTR(skill.c_str());
		return S_OK;
	}
	else
		*pVal = _com_util::ConvertStringToBSTR(package.GetProSkill(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::LoadPackage(BSTR newVal)
{
	// TODO: Add your implementation code here

	package.LoadPackage(ToString(newVal));

	return S_OK;
}

STDMETHODIMP CCharacter::LoadChoices()
{
	// TODO: Add your implementation code here

	package.LoadChoices(profession);

	if(pkSpecies.GetSkillCount()>0)
	{
		for(int i=0;i<pkSpecies.GetSkillCount();i++)
		{
			package.AddProSkill(pkSpecies.GetSkill(i),pkSpecies.GetSubSkill(i));
		}
	}

	LoadEliteSkills();

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickFlawItem(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(background.GetPickFlawItem(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickEdgeItem(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(background.GetPickEdgeItem(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickThreeItem(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(background.GetPickThreeItem(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickOneItem(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(background.GetPickOneItem(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickFlawCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = background.GetPickFlawCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickEdgeCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = background.GetPickEdgeCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickThreeCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = background.GetPickThreeCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_PickOneCount(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = background.GetPickOneCount();

	return S_OK;
}

STDMETHODIMP CCharacter::put_Background(BSTR newVal)
{
	// TODO: Add your implementation code here

	background.SetBackground(ToString(newVal));

	return S_OK;
}

STDMETHODIMP CCharacter::RecordReactionModifiers()
{
	// TODO: Add your implementation code here

	int r;

	//Quickness
	r = (attributes[1].score >= attributes[5].score) ?
		attributes[1].mod : attributes[5].mod;
	reactions[0] = r;
	

	//Saavy
	r = (attributes[4].score>= attributes[5].score) ?
		attributes[4].mod : attributes[5].mod;
	reactions[1] = r + pkSpecies.GetSavvy();

	//Stamina
	r = (attributes[3].score>=attributes[0].score)?
		attributes[3].mod : attributes[0].mod;
	reactions[2] = r + pkSpecies.GetStamina();

	//Willpower
	r = (attributes[2].score>=attributes[3].score)?
		attributes[2].mod : attributes[3].mod;
	reactions[3] = r + pkSpecies.GetWillpower();
	
	if(species == "Human")
	{
		DlgRetrieve adpt;
		
		adpt.Set("Humans get +2 on reactions","Adaptability");
adapt:
		if(adpt.DoModal()==IDOK)
		{
			if(adpt.GetResult() == "Stamina")
				reactions[2] += 2;
			if(adpt.GetResult() == "Quickness")
				reactions[0] += 2;
			if(adpt.GetResult() == "Willpower")
				reactions[3] += 2;
			
		}
		else
		{
			goto adapt;
		}
			

	}

	return S_OK;
}

STDMETHODIMP CCharacter::RecordSpeciesModifiers()
{
	// TODO: Add your implementation code here

	if(species == "")
	{		
		msg.SetWarning( "Species not selected. Select species");
		msg.DoModal();
		return S_FALSE;
	}
	else
	{
		//**** call SetSpecies to for edges and skill data here****
		for(int i=0;i<pkSpecies.GetSpeciesCount();i++)
		{
			if(species == pkSpecies.GetSpeciesId(i))
			{
				attributes[0].score+= pkSpecies.GetSpeciesStrength(i);
				attributes[1].score+= pkSpecies.GetSpeciesAgility(i);
				attributes[2].score+= pkSpecies.GetSpeciesIntellect(i);
				attributes[3].score+= pkSpecies.GetSpeciesVitality(i);
				attributes[4].score+= pkSpecies.GetSpeciesPrescence(i);
				attributes[5].score+= pkSpecies.GetSpeciesPerception(i);
				attributes[6].score+= pkSpecies.GetSpeciesPsionics(i);
				
			}
		}

		LoadSpeciesTraits();
		LoadSpeciesSkills();
		
	}

	return S_OK;
}

STDMETHODIMP CCharacter::get_Attributes(int index, int *pVal)
{
	// TODO: Add your implementation code here

	if(index>7) return S_FALSE;
	*pVal=attributes[index].score;

	return S_OK;
}

STDMETHODIMP CCharacter::put_Attributes(int index, int newVal)
{
	// TODO: Add your implementation code here

	if(index>7) return S_FALSE;
	if(newVal>12)
	{
		attributes[index].score = 12;
		attributes[index].mod = GetMod(12);
	}
	else
	{
		attributes[index].score = newVal;
		attributes[index].mod = GetMod(newVal);
	}

	return S_OK;
}

STDMETHODIMP CCharacter::Skill_ReplaceLevel(BSTR name, BSTR specific, int level)
{
	// TODO: Add your implementation code here

	skills.SetLevel(ToString(name),ToString(specific),level);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Skill_Exist(BSTR name, BSTR specific, BOOL *pVal)
{
	// TODO: Add your implementation code here

	if(ToString(specific)!="NA")
		*pVal = skills.IsExist(ToString(name),ToString(specific));
	else
		*pVal = skills.IsExist(ToString(name));

	return S_OK;
}

STDMETHODIMP CCharacter::Skill_RemoveAll()
{
	// TODO: Add your implementation code here

	skills.RemoveAll();
	languages.clear();

	return S_OK;
}

STDMETHODIMP CCharacter::Skill_Remove(BSTR name, BSTR specific)
{
	// TODO: Add your implementation code here

	if(ToString(specific) != "NA")
		skills.Remove(ToString(name),ToString(specific));
	else
		skills.Remove(ToString(name));

	return S_OK;
}

STDMETHODIMP CCharacter::Skill_Add(BSTR name, BSTR specific, int level)
{
	// TODO: Add your implementation code here

	string nomen1, nomen2;

	nomen1 = ToString(name);
	
	nomen2 = ToString(specific);

	nomen2 =Capitialize(nomen2);

	

	if (nomen1 == "Language")
	{
		nomen1 = nomen2;
		nomen2 = "";
		languages.push_back(nomen1);
	}

	skills.Add(nomen1, nomen2, level);

	return S_OK;
}

STDMETHODIMP CCharacter::Skill_Modify(BSTR name, BSTR specific, int level)
{
	// TODO: Add your implementation code here

	skills.Modify(ToString(name), ToString(specific), level);

	return S_OK;
}

STDMETHODIMP CCharacter::get_Skill_Level(int index, int *pVal)
{
	// TODO: Add your implementation code here

	
	*pVal = skills.GetLevel(index);
	

	return S_OK;
}

STDMETHODIMP CCharacter::get_Skill_Count(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = skills.GetCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_Skill_Name(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(skills.GetName(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_Skill_Specific(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(skills.GetSpecific(index).c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::Flaw_Add(BSTR name)
{
	// TODO: Add your implementation code here

	flaws.Add(ToString(name));

	return S_OK;
}

STDMETHODIMP CCharacter::Edge_Add(BSTR name)
{
	// TODO: Add your implementation code here

	edges.Add(ToString(name));

	return S_OK;
}

STDMETHODIMP CCharacter::get_Flaw_Exist(BSTR name, BOOL *pVal)
{
	// TODO: Add your implementation code here

	*pVal = flaws.IsExist(ToString(name));

	return S_OK;
}

STDMETHODIMP CCharacter::get_Edge_Exist(BSTR name, BOOL *pVal)
{
	// TODO: Add your implementation code here
	
	*pVal = edges.IsExist(ToString(name));
	
	
	return S_OK;
}

STDMETHODIMP CCharacter::get_Flaw_Count(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = flaws.Count();

	return S_OK;
}

STDMETHODIMP CCharacter::get_Edge_Count(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = edges.Count();

	return S_OK;
}

STDMETHODIMP CCharacter::get_Flaw(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	string flaw;
	flaws.GetData(index, flaw);
	*pVal = _com_util::ConvertStringToBSTR(flaw.c_str());

	return S_OK;
}

STDMETHODIMP CCharacter::get_Edge(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	string edge;
	edges.GetData(index,edge);
	*pVal = _com_util::ConvertStringToBSTR(edge.c_str());

	return S_OK;
}



STDMETHODIMP CCharacter::SetSpecies()
{
	// TODO: Add your implementation code here

	pkSpecies.SetSpecies();

	return S_OK;
}

STDMETHODIMP CCharacter::get_Species_Count(int *pVal)
{
	// TODO: Add your implementation code here

	*pVal = pkSpecies.GetSpeciesCount();

	return S_OK;
}

STDMETHODIMP CCharacter::get_Species_List(int index, BSTR *pVal)
{
	// TODO: Add your implementation code here

	*pVal = _com_util::ConvertStringToBSTR(pkSpecies.GetSpeciesId(index).c_str());

	return S_OK;
}
