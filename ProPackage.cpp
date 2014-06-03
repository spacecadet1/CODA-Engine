// ProPackage.cpp: implementation of the ProPackage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ProPackage::ProPackage()
{
	//input data
	AddCustomData();
	
}

ProPackage::~ProPackage()
{

}

void ProPackage::AddProSkill(string skill, string subskill)
{
		BOOL found=FALSE;
		for(int i=0;i<proSkillArray.size();i++)
		{
			if(proSkillArray[i].GetSkill() == skill)
			{
				if(proSkillArray[i].GetSubSkill()==subskill)
					found = TRUE;
			}
		}
		if(!found)
		{
			proSkillData.EnterData(skill,subskill,"");
			proSkillArray.push_back(proSkillData);
		}
}

int ProPackage::GetPackageCount()
{
	return packageTypes.size();
}

string ProPackage::PackageTypes(int index)
{
	return packageTypes[index];
}

string ProPackage::GetProEdges(int index)
{
	return edges[index];
}

int ProPackage::ProEdgesCount()
{
	return edges.size();
}

void ProPackage::LoadPackage(string package) //loads package's skills and edges
{
	typedef struct tag_cfskills
	{
		LPCTSTR skill;
		LPCTSTR subskill;
		LPCTSTR speciality;
		int level;
	} cfskills;
	int i;

	autoSkillArray.clear();

	if(package == "Aesthetic")
	{
		cfskills g_skills[] =
		{
			{"Armed Combat","","x",2},
			{"Craft","x","",2},
			{"First Aid","","",2},
			{"Observe","","",4},
			{"Persuade","","Debate",2},
			{"Knowledge","Religion","x",4},
			{"Unarmed Combat","","x",3}

		};
		cfskills_count=7;
		
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Speed");
		edges.push_back("Fit");
		edges.push_back("Quick Draw");
		edges.push_back("Weapon Mastery");

		
	
	}
	else if(package == "A & A Officer")
	{
		cfskills g_skills[] =
		{
			{"Computer Use","","Retrieve",2},
			{"Knowledge","Culture","x",1},
			{"Knowledge","History","x",3},
			{"Investigate","","Research",2},
			{"Knowledge","Religion","x",1},
			{"Science","Social","Anthropology",3},
			{"Science","Social","Archaeology",3},
			{"Knowledge","Specific World","x",2},
			{"Survival","","",2}
			
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		edges.clear();
		edges.push_back("Cultural Flexibility");
		edges.push_back("Curious");
		edges.push_back("Everyman");
		edges.push_back("Excellent Metabolism");
		edges.push_back("Likeable");


	}
	else if(package == "Alien Specialist")
	{
		cfskills g_skills[] =
		{
			{"Computer Use","","Retrieve",2},
			{"Knowledge","Culture","x",1},
			{"Ranged Combat","Energy","",1},
			{"First Aid","","",2},
			{"Medicine","","x",4},
			{"Science","Life","Exobiology",2},
			{"Knowledge","Specific World","x",1},
			{"System Operation","","Medical",3}

		};

		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		
		edges.clear();
		edges.push_back("Ally");
		edges.push_back("Contacts");
		edges.push_back("Cultural Flexibility");
		edges.push_back("Famous Event");
		edges.push_back("Skill Focus:Compassionate");

	}

	else if(package == "Astrometrics")
	{
		cfskills g_skills[] =
		{
			{"Computer Use","","Retrieve",3},
			{"Construct","","Probes",2},
			{"Ranged Combat","Energy","",1},
			{"Science","Physical","Physics",2},
			{"Repair","","",1},
			{"Science","Space","Stellar Cartography",3},
			{"System Operation","","Sensors",3}

		};

		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		
		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Curious");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:3D Thinking");
		edges.push_back("Thinker");
		
	}
	else if(package== "Basic Commander")
	{
		cfskills g_skills[] =
		{
			{"Enterprise","Administration","",2},
			{"Computer Use","","Retrieve",2},
			{"Ranged Combat","Energy","",3},
			{"Knowledge","x","x",2},
			{"Negotiate","","",1},
			{"Repair","","",1},
			{"System Operation","","Command",2},
			{"Tactics","","Space",2},
			{"Unarmed Combat","","x",2}

		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Command");
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Iron Willed");
		

	}
	else if(package == "Basic Science Officer")
	{
		cfskills g_skills []=
		{
			{"Computer Use","","Retrieve",2},
			{"Ranged Combat","Energy","",1},
			{"Science","Life","",3},
			{"Science","Physical","",3},
			{"Science","Planetary","",3},
			{"Repair","","",2},
			{"Science","Space","",2},
			{"System Operation","","Sensors",2}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Curious");
		edges.push_back("Innovative");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Unyielding");
	}
	else if(package=="Basic Security Officer")
	{
		cfskills g_skills []=
		{
			{"Athletics","","x",2},
			{"Ranged Combat","Energy","x",3},
			{"First Aid","","",1},
			{"Inquire","","Interrogate",2},
			{"Investigate","","Search",2},
			{"Repair","","",1},
			{"System Operation","","Security Systems",2},
			{"Tactics","","",1},
			{"Unarmed Combat","","x",2}

		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Bold");
		edges.push_back("Dodge");
		edges.push_back("High Pain Threshold");
		edges.push_back("Skill Focus:Attentive");
	}
	else if(package=="Basic System Operator")
	{
		cfskills g_skills []=
		{
			{"Athletics","","",2},
			{"Computer Use","","",2},
			{"Ranged Combat","Energy","",2},
			{"First Aid","","",1},
			{"Repair","","",1},
			{"Survival","","",1},
			{"Engineering","Systems","x",3},
			{"System Operation","","x",4},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Bold");
		edges.push_back("Confident");
		edges.push_back("Likeable");
		edges.push_back("Skill Focus");
	}

	else if(package=="Bureaucrat")
	{
		cfskills g_skills []=
		{
			{"Enterprise","Administration","",3},
			{"Computer Use","","Retrieve",1},
			{"Inquire","","Interview",2},
			{"Knowledge","Law","x",3},
			{"Negotiate","","Mediate",1},
			{"Persuade","","Oratory",2},
			{"Knowledge","Politics","x",4}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Eidetic Memory");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Diplomatic");
		edges.push_back("Skill Focus:Eloquent");
	}

	else if(package=="Cleric")
	{
		cfskills g_skills [] =
		{
			{"Knowledge","Culture","x",3},
			{"First Aid","","",3},
			{"Knowledge","History","x",2},
			{"Inquire","","Interview",2},
			{"Persuade","","Oratory",2},
			{"Knowledge","Religion","x",4},
			{"Entertain","Sing","",2}

		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Meticulous");
		edges.push_back("Resolute");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Skill Focus:Eloquent");
		
	}
	else if(package == "Communications Officer")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Encryption",2},
			{"Observe","","Listen",2},
			{"Science","Physical","Mathematics",1},
			{"Repair","","Communications",2},
			{"Engineering","Systems","Communications",3},
			{"System Operation","","Communications",4}
			
		};
		cfskills_count = 6;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		edges.clear();
		edges.push_back("Ambidextrous");
		edges.push_back("Confident");
		edges.push_back("Eidetic Memory");
		edges.push_back("Exceptional Concentration");
		edges.push_back("Skill Focus:Keen Hearing");


	}
	else if(package == "Emergency Medic")
	{
		cfskills g_skills[] =
		{
			{"Athletics","","",2},
			{"Computer Use","","Retrieve",1},
			{"Ranged Combat","Energy","",1},
			{"First Aid","","",4},
			{"Knowledge","x","x",1},
			{"Medicine","","",4},
			{"System Operation","","Medical",2},
			{"Survival","","x",2}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Speed");
		edges.push_back("Iron Willed");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Thinker");
	}

	else if(package=="Entrepreneur")
	{
		cfskills g_skills []=
		{
			{"Appraise","","",2},
			{"Enterprise","Business","",3},
			{"Computer Use","","",1},
			{"Knowledge","Culture","x",2},
			{"Influence","","Charm",1},
			{"Influence","","Fast Talk",1},
			{"Inquire","","Fraternize",2},
			{"Negotiate","","",3},
			{"Knowledge","Specific World","x",2}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Meticulous");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Persuasive");
		edges.push_back("Wealth");
	}

	else if(package=="Exchange Student")
	{
		cfskills g_skills[]=
		{
			{"Computer Use","","x",3},
			{"Construct","","x",3},
			{"Knowledge","Culture","x",2},
			{"Language","","x",2},
			{"Repair","","x",1},
			{"Science","x","",4},
			{"Knowledge","Specific World","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Cultural Flexibility");
		edges.push_back("Curious");
		edges.push_back("Unyielding");
	}
	else if (package=="Exocultural Specialist")
	{
		cfskills g_skills[]=
		{
			{"Enterprise","Administration","",2},
			{"Computer Use","","Retrieve",2},
			{"Knowledge","Culture","x",4},
			{"Knowledge","History","x",3},
			{"Language","","x",2},
			{"Science","Social","x",2},
			{"Knowledge","Specific World","x",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Cultural Flexibility");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Eloquent");
		edges.push_back("Skill Focus:Persuasive");
	}

	else if(package=="Field Scientist")
	{
		cfskills g_skills[] =
		{
			{"Computer Use","","",3},
			{"Construct","","x",1},
			{"First Aid","","",3},
			{"Knowledge","x","x",2},
			{"Repair","","x",1},
			{"Science","x","",4},
			{"System Operation","","x",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Eidetic Memory");
		edges.push_back("Fit");
		edges.push_back("Meticulous");
		edges.push_back("Unyielding");
	}

	else if(package=="Foot Soldier")
	{
		cfskills g_skills []=
		{
			{"Armed Combat","","x",3},
			{"Athletics","","",2},
			{"Ranged Combat","Energy","",4},
			{"First Aid","","",1},
			{"Observe","","x",2},
			{"Repair","","",1},
			{"Survival","","",2},
			{"Tactics","","Ground",1},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Dodge");
		edges.push_back("High Pain Threshold");
		edges.push_back("Skill Focus:Keen Hearing");
		edges.push_back("Skill Focus:Keen Sight");
		edges.push_back("Weapon Mastery");
	}
	else if(package=="Guerrilla")
	{
		cfskills g_skills []=
		{
			{"Armed Combat","","x",2},
			{"Athletics","","x",3},
			{"Demolitions","","",2},
			{"First Aid","","",1},
			{"Observe","","x",2},
			{"Ranged Combat","x","",3},
			{"Ranged Combat","x","",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Dead Aim");
		edges.push_back("Speed");
		edges.push_back("Great Stamina");
		edges.push_back("Lightning Relfexes");
		edges.push_back("Weapon Mastery");
	}
	else if(package=="Helmsman/Navigator")
	{
		cfskills g_skills[]=
		{
			{"Enterprise","Administration","",1},
			{"Computer Use","","",2},
			{"Ranged Combat","Energy","",2},
			{"Repair","","",2},
			{"Science","Space","Astrogation",3},
			{"Engineering","Systems","Flight Control",2},
			{"System Operation","","Flight Control",3},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Confident");
		edges.push_back("Speed");
		edges.push_back("Sense of Direction");
		edges.push_back("Unyielding");
	}
	else if(package=="Hot-shot Pilot")
	{
		cfskills g_skills []=
		{
			{"Athletics","","",1},
			{"Computer Use","","",1},
			{"Ranged Combat","Energy","",1},
			{"Repair","","",1},
			{"Science","Space","Astrogation",4},
			{"Survival","","",2},
			{"Engineering","Systems","Flight Control",4},
			{"System Operation","","Flight Control",4},
			{"Unarmed Combat","","x",1}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Famous Event");
		edges.push_back("Lightning Reflexes");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:3D Thinking");
	}
	else if(package=="Interspecies Relations")
	{
		cfskills g_skills []=
		{
			{"Knowledge","History","x",2},
			{"Medicine","","Psychology",3},
			{"Knowledge","Specific World","x",3},
			{"System Operation","","Command",1},
			{"Computer Use","","Retrieve",1},
			{"Inquire","","Fraternize",3},
			{"Knowledge","Culture","x",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Cultural Flexibility");
		edges.push_back("Friendly");
		edges.push_back("Innovative");
		edges.push_back("Likeable");
		edges.push_back("Skill Focus:Diplomatic");
	}
	else if(package == "Investigator")
	{
		cfskills g_skills []=
		{
			{"Computer Use","","Hacking",2},
			{"Ranged Combat","Energy","",2},
			{"Inquire","","Interrogation",3},
			{"Investigate","","x",3},
			{"Observe","","Spot",2},
			{"Repair","","",1},
			{"System Operation","","Security Systems",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}
		
		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Dodge");
		edges.push_back("Meticulous");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Attentive");

	}
	else if(package == "Law Enforcement")
	{
		cfskills g_skills []=
		{
			{"Athletics","","",1},
			{"Inquire","","Interrogate",4},
			{"Investigate","","Search",3},
			{"Observe","","Spot",4},
			{"Ranged Combat","x","",2},
			{"Repair","","",1},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Attentive");
		edges.push_back("Skill Focus:Keen Sight");
		edges.push_back("Unyielding");
	}
	else if(package == "Liaison")
	{
		cfskills g_skills []=
		{
			{"Computer Use","","Retrieve",1},
			{"Knowledge","Culture","x",3},
			{"Inquire","","Fraternize",2},
			{"Language","","x",2},
			{"Knowledge","Law","x",2},
			{"Negotiate","","Mediate",4},
			{"Knowledge","Specific World","x",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Ally");
		edges.push_back("Cultural Flexibility");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Diplomatic");
		edges.push_back("Skill Focus:Eloquent");
	}
	else if(package=="Manager")
	{
		cfskills g_skills []=
		{
			{"Enterprise","Administration","",3},
			{"Computer Use","","Retrieve",2},
			{"Ranged Combat","Energy","",2},
			{"Inquire","","",1},
			{"Knowledge","x","x",1},
			{"Negotiate","","",3},
			{"Persuade","","",2},
			{"Repair","","",1},
			{"System Operation","","Command",3}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Command");
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Diplomatic");
	}
	else if(package =="Manufacturing")
	{
		cfskills g_skills [] =
		{
			{"Appraise","","",2},
			{"Enterprise","Business","",3},
			{"Craft","x","",4},
			{"Knowledge","Culture","x",2},
			{"Influence","","x",3},
			{"Negotiate","","",2},
			{"Knowledge","Specific World","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Cultural Flexibility");
		edges.push_back("Likeable");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Craftsman");
		edges.push_back("Wealth");
	}
	else if (package == "Medical Doctor")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",1},
			{"First Aid","","",2},
			{"Investigate","","",2},
			{"Medicine","","x",3},
			{"Science","Life","x",2},
			{"Science","Physical","x",1},
			{"System Operation","","Medical",3},
			{"Knowledge","Specific World","x",1}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Curious");
		edges.push_back("Healthy");
		edges.push_back("Likeable");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Thinker");
	}
	else if( package == "Mendicant")
	{
		cfskills g_skills [] =
		{
			{"Craft","x","",2},
			{"Knowledge","Culture","x",2},
			{"Knowledge","History","x",2},
			{"Inquire","","Fraternize",3},
			{"Persuade","","x",4},
			{"Knowledge","Religion","x",3},
			{"Survival","","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Curious");
		edges.push_back("Likeable");
		edges.push_back("Skill Focus:Compassionate");
	}
	else if (package == "Operations Manager")
	{
		cfskills g_skills [] =
		{
			{"Athletics","","",2},
			{"Computer Use","","x",3},
			{"Ranged Combat","Energy","",2},
			{"Repair","","",1},
			{"Engineering","Systems","Electroplasma System",3},
			{"System Operation","","Operations Management",4},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Athletic");
		edges.push_back("Bold");
		edges.push_back("Contacts");
		edges.push_back("Skill Focus:Attentive");
		edges.push_back("Skill Focus:Persuasive");
	}
	else if (package == "Planetary Survey")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",2},
			{"Ranged Combat","Energy","",1},
			{"Knowledge","x","x",2},
			{"Science","Planetary","x",3},
			{"Science","Life","x",2},
			{"Repair","","",1},
			{"System Operation","","Sensors",2},
			{"Survival","","x",2}
		};
		cfskills_count= 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Fit");
		edges.push_back("Great Stamina");
		edges.push_back("Meticulous");
		edges.push_back("Thinker");
	}
	else if(package == "Professional")
	{
		cfskills g_skills [] =
		{
			{"Armed Combat","","x",2},
			{"Conceal","","",3},
			{"Observe","","x",3},
			{"Ranged Combat","x","",4},
			{"Stealth","","x",3},
			{"Enterprise","Streetwise","",3}
		};
		cfskills_count = 6;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Friendly");
		edges.push_back("Iron Willed");
		edges.push_back("Martial Artist");
		edges.push_back("Sklll Focus:Attentive");
	}
	else if(package == "Representative")
	{
		cfskills g_skills [] =
		{
			{"Enterprise","Administration","",2},
			{"Computer Use","","Retrieve",1},
			{"Ranged Combat","Energy","",1},
			{"Inquire","","Fraternize",2},
			{"Knowledge","x","x",2},
			{"Negotiate","","Mediate",3},
			{"Persuade","","Oratory",2},
			{"System Operation","","Command",2}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Command");
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Skill Focus:Eloquent");
		edges.push_back("Skill Focus:Persuasive");
	}
	else if(package == "Researcher")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",2},
			{"Construct","","",2},
			{"Investigate","","Research",1},
			{"Knowledge","x","x",2},
			{"Persuade","","",2},
			{"Repair","","",2},
			{"Science","x","x",3},
			{"Science","x","x",1},
			{"System Operation","","Sensors",2}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Ally");
		edges.push_back("Eidetic Memory");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Unyielding");
	}
	else if(package == "Scoundrel")
	{
		cfskills g_skills [] =
		{
			{"Armed Combat","","x",2},
			{"Conceal","","",2},
			{"Influence","","Intimidate",3},
			{"Observe","","x",3},
			{"Sleight of Hand","","",2},
			{"Stealth","","x",2},
			{"Enterprise","Streetwise","",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Blends In");
		edges.push_back("Innovative");
		edges.push_back("Skill Focus:Furtive");
		edges.push_back("Speed");
		//edges.push_back();
	}
	else if (package == "Shaman")
	{
		cfskills g_skills []=
		{
			{"Craft","x","",1},
			{"First Aid","","Herbalism",4},
			{"Observe","","x",2},
			{"Entertain","Play","",2},
			{"Knowledge","Religion","x",3},
			{"Entertain","Sing","",2},
			{"Survival","","x",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Friendly");
		edges.push_back("Innovative");
		edges.push_back("Skill Focus:Eloquent");
		edges.push_back("Thinker");
	}
	else if (package == "Ship Counselor")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",1},
			{"Knowledge","Culture","x",2},
			{"Ranged Combat","Energy","",1},
			{"First Aid","","",2},
			{"Influence","","Charm",1},
			{"Inquire","","Interview",3},
			{"Medicine","","Psychology",3},
			{"Knowledge","Specific World","x",2},
			{"System Operation","","",1}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Curious");
		edges.push_back("Skill Focus:Compassionate");
		edges.push_back("Skill Focus:Eloquent");
		edges.push_back("Skill Focus:Persuasive");
	}
	else if (package == "Ship Doctor")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",2},
			{"Ranged Combat","Energy","",1},
			{"First Aid","","",3},
			{"Science","Life","x",2},
			{"Medicine","","x",4},
			{"Repair","","",1},
			{"System Operation","","Medical",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Confident");
		edges.push_back("Famous Event");
		edges.push_back("Innovative");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Compassionate");
	}
	else if (package == "Social Survey")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Retrieve",3},
			{"Knowledge","Culture","x",2},
			{"Ranged Combat","Energy","",1},
			{"Knowledge","History","x",2},
			{"Repair","","",1},
			{"Science","Social","x",3},
			{"Science","Social","x",1},
			{"Knowledge","Specific World","x",2},
			{"System Operation","","Sensors",2}
		};
		cfskills_count = 9;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Cultural Flexibility");
		edges.push_back("Friendly");
		edges.push_back("Meticulous");
		edges.push_back("Thinker");
	}
	else if ( package == "Sophisticate")
	{
		cfskills g_skills []=
		{
			{"Conceal","","Cache",3},
			{"Forgery","","",2},
			{"Impersonate","","",3},
			{"Inquire","","Fraternize",2},
			{"Observe","","x",2},
			{"Ranged Combat","x","",2},
			{"Stealth","","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Alert");
		edges.push_back("Contacts");
		edges.push_back("Friendly");
		edges.push_back("Skill Focus:Seductive");
		edges.push_back("Wealth");
	}
	else if ( package == "Specialist")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Programming",3},
			{"Construct","","x",3},
			{"Ranged Combat","Energy","",1},
			{"Science","Physical","Mathematics",2},
			{"Repair","","",2},
			{"Engineering","Systems","Computer",3},
			{"System Operation","","",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Curious");
		edges.push_back("Innovative");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Craftsman");
		edges.push_back("Unyielding");
	}
	else if (package == "Starship Designer")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","Modeling",2},
			{"Construct","","Starship",3},
			{"Ranged Combat","Energy","",1},
			{"Engineering","Propulsion","",2},
			{"Repair","","",3},
			{"Engineering","Structural","",3},
			{"Engineering","Systems","",3},
			{"System Operation","","",1}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Ambidextrous");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Craftsman");
		edges.push_back("Suit Trained");
		edges.push_back("Zero-G Trained");
	}
	else if ( package == "System Specialist")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","",2},
			{"Construct","","x",3},
			{"Ranged Combat","Energy","",2},
			{"Science","Physical","",1},
			{"Repair","","x",2},
			{"Engineering","Systems","x",3},
			{"System Operation","","x",2},
			{"Unarmed Combat","","x",1}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Competitive");
		edges.push_back("Exceptional Concentration");
		edges.push_back("Innovative");
		edges.push_back("Shrewd");
		edges.push_back("Skill Focus:Craftsman");
	}
	else if( package == "Tactical Officer")
	{
		cfskills g_skills []=
		{
			{"Computer Use","","Hacking",2},
			{"Knowledge","Culture","x",2},
			{"Ranged Combat","Energy","",3},
			{"Repair","","",2},
			{"System Operation","","Tactical",4},
			{"Tactics","","Space",2},
			{"Unarmed Combat","","x",2}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Confident");
		edges.push_back("Contacts");
		edges.push_back("Dodge");
		edges.push_back("Resolute");
	}
	else if ( package == "Trader")
	{
		cfskills g_skills [] =
		{
			{"Appraise","","x",3},
			{"Enterprise","Business","",3},
			{"Knowledge","Culture","x",2},
			{"Language","","x",1},
			{"Negotiate","","",4},
			{"Knowledge","Specific World","x",2},
			{"System Operation","","Flight Control",3}
		};
		cfskills_count = 7;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Contacts");
		edges.push_back("Curious");
		edges.push_back("Skill Focus:Eloquent");
		edges.push_back("Skill Focus:Persuasive");
		edges.push_back("Wealth");
	}
	else if ( package == "Troubleshooter")
	{
		cfskills g_skills [] =
		{
			{"Computer Use","","",2},
			{"Construct","","",2},
			{"Ranged Combat","Energy","",1},
			{"Engineering","Propulsion","",3},
			{"Repair","","",2},
			{"Engineering","Structural","",3},
			{"Engineering","Systems","",2},
			{"Unarmed Combat","","x",1}
		};
		cfskills_count = 8;
		for(i=0; i< cfskills_count;i++)
		{
			jobSkillData.EnterData(g_skills[i].skill,g_skills[i].subskill,
				g_skills[i].speciality, g_skills[i].level);
			autoSkillArray.push_back(jobSkillData);
		}

		edges.clear();
		edges.push_back("Bold");
		edges.push_back("Curious");
		edges.push_back("Innovative");
		edges.push_back("Skill Focus:Craftsman");
		edges.push_back("Unyielding");
	}
	else
	{
		edges.clear();
		vector<_profession>::iterator it;
		for(it = professions.begin(); it != professions.end(); ++it)
		{
			if(it->package == package)
			{
				CustomEdges(it->edges);
				CustomSkills(it->skills);

			}

		}

	}

}

void ProPackage::LoadChoices(string profession) //loads package choices based on profession
{
	typedef struct tag_prskills
	{
		LPCTSTR skill;
		LPCTSTR subskill;
		LPCTSTR speciality;
	} prskills;

	proSkillArray.clear();
	int i;
	
	if (!packageTypes.empty())
		packageTypes.clear();

	if (profession == "Diplomat")
	{
		packageTypes.push_back("Bureaucrat");
		packageTypes.push_back("Liaison");
		packageTypes.push_back("Exocultural Specialist");

		prskills g_prskills[]=
		{
			{"Enterprise","Administration",""},
			{"Computer Use","",""},
			{"Knowledge","Culture","x"},
			{"Knowledge","History","x"},
			{"Inquire","",""},
			{"Language","","x"},
			{"Knowledge","Law","x"},
			{"Negotiate","",""},
			{"Persuade","",""},
			{"Knowledge","Politics","x"},
			{"Science","Social",""},
			{"Knowledge","Specific World","x"}
		};
		prskills_count = 12;
		
		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}

				
	}
	else if (profession == "Merchant")
	{
		packageTypes.push_back("Trader");
		packageTypes.push_back("Manufacturing");
		packageTypes.push_back("Entrepreneur");

		prskills g_prskills[]=
		{
			{"Appraise","",""},
			{"Enterprise","Business",""},
			{"Computer Use","",""},
			{"Craft","x",""},
			{"Knowledge","Culture","x"},
			{"Influence","",""},
			{"Inquire","",""},
			{"Language","","x"},
			{"Negotiate","",""},
			{"Repair","",""},
			{"Knowledge","Specific World","x"},
			{"System Operation","",""}
		};
		prskills_count =12;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Mystic")
	{
		packageTypes.push_back("Aesthetic");
		packageTypes.push_back("Cleric");
		packageTypes.push_back("Mendicant");
		packageTypes.push_back("Shaman");

		prskills g_prskills[]=
		{
			{"Armed Combat","","x"},
			{"Craft","x",""},
			{"Knowledge","Culture","x"},
			{"First Aid","",""},
			{"Knowledge","History","x"},
			{"Inquire","",""},
			{"Observe","",""},
			{"Persuade","",""},
			{"Entertain","Play",""},
			{"Knowledge","Religion","x"},
			{"Entertain","Sing",""},
			{"Knowledge","Specific World","x"},
			{"Survival","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 14;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Rogue")
	{
		packageTypes.push_back("Scoundrel");
		packageTypes.push_back("Professional");
		packageTypes.push_back("Sophisticate");

		prskills g_prskills[]=
		{
			{"Appraise","",""},
			{"Armed Combat","","x"},
			{"Conceal","",""},
			{"Forgery","",""},
			{"Impersonate","",""},
			{"Influence","",""},
			{"Inquire","",""},
			{"Observe","",""},
			{"Ranged Combat","x",""},
			{"Sleight of Hand","",""},
			{"Stealth","",""},
			{"Enterpirse","Streetwise",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 13;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Scientist")
	{
		packageTypes.push_back("Exchange Student");
		packageTypes.push_back("Medical Doctor");
		packageTypes.push_back("Field Scientist");
		packageTypes.push_back("Researcher");

		prskills g_prskills[]=
		{
			{"Computer Use","",""},
			{"Construct","",""},
			{"First Aid","",""},
			{"Investigate","",""},
			{"Knowledge","x","x"},
			{"Language","","x"},
			{"Medicine","",""},
			{"Persuade","",""},
			{"Repair","",""},
			{"Science","x",""},
			{"System Operation","",""}
		};

		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Soldier")
	{
		packageTypes.push_back("Foot Soldier");
		packageTypes.push_back("Guerrilla");
		packageTypes.push_back("Law Enforcement");

		prskills g_prskills[]=
		{
			{"Armed Combat","","x"},
			{"Athletics","",""},
			{"Demolitions","",""},
			{"First Aid","",""},
			{"Inquire","",""},
			{"Investigate","",""},
			{"Observe","",""},
			{"Ranged Combat","x",""},
			{"Repair","",""},
			{"Survival","",""},
			{"Tactics","",""}
		};

		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Command")
	{
		packageTypes.push_back("Basic Commander");
		packageTypes.push_back("Representative");
		packageTypes.push_back("Manager");

		prskills g_prskills[]=
		{
			{"Enterprise","Administration",""},
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Ranged Combat","Energy",""},
			{"Inquire","",""},
			{"Knowledge","x","x"},
			{"Negotiate","",""},
			{"Persuade","",""},
			{"Repair","",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Tactics","",""},
			{"Unarmed Combat","","x"}
		};
		
		prskills_count = 13;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Engineering")
	{
		packageTypes.push_back("Troubleshooter");
		packageTypes.push_back("Specialist");
		packageTypes.push_back("Starship Designer");
		packageTypes.push_back("System Specialist");

		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Construct","",""},
			{"Ranged Combat","Energy",""},
			{"Engineering","x",""},
			{"Knowledge","x",""},
			{"Science","Physical",""},
			{"Repair","",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Operations")
	{
		packageTypes.push_back("Basic System Operator");
		packageTypes.push_back("Operations Manager");
		packageTypes.push_back("Communications Officer");
		
		
		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Ranged Combat","Energy",""},
			{"First Aid","",""},
			{"Knowledge","x","x"},
			{"Observe","",""},
			{"Repair","",""},
			{"Survival","",""},
			{"Engineering","System",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Security")
	{
		packageTypes.push_back("Basic Security Officer");
		packageTypes.push_back("Investigator");
		packageTypes.push_back("Tactical Officer");
		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Ranged Combat","Energy",""},
			{"First Aid","",""},
			{"Inquire","",""},
			{"Investigate","",""},
			{"Knowledge","x","x"},
			{"Observe","",""},
			{"Repair","",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Tactics","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 13;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Flight")
	{
		packageTypes.push_back("Helmsman/Navigator");
		packageTypes.push_back("Hot-shot Pilot");
		prskills g_prskills[]=
		{
			{"Enterprise","Administration",""},
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Ranged Combat","Energy",""},
			{"Knowledge","x","x"},
			{"Repair","",""},
			{"Science","Space",""},
			{"Survival","",""},
			{"Engineering","Systems",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Counselor")
	{
		packageTypes.push_back("Interspecies Relations");
		packageTypes.push_back("Ship Counselor");
		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"First Aid","",""},
			{"Influence","",""},
			{"Inquire","",""},
			{"Knowledge","x","x"},
			{"Medicine","",""},
			{"Ranged Combat","Energy",""},
			{"Repair","",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 12;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Medicine")
	{
		packageTypes.push_back("Alien Specialist");
		packageTypes.push_back("Emergency Medic");
		packageTypes.push_back("Ship Doctor");
		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Ranged Combat","Energy",""},
			{"First Aid","",""},
			{"Knowledge","x","x"},
			{"Science","Life",""},
			{"Medicine","",""},
			{"Science","Physical",""},
			{"Repair","",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 12;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	else if (profession == "Starship Science")
	{
		packageTypes.push_back("Astrometrics");
		packageTypes.push_back("Basic Science Officer");
		packageTypes.push_back("Social Survey");
		packageTypes.push_back("Planetary Survey");
		packageTypes.push_back("A & A Officer");

		prskills g_prskills[]=
		{
			{"Athletics","",""},
			{"Computer Use","",""},
			{"Construct","",""},
			{"Investigate","",""},
			{"Knowledge","x","x"},
			{"Ranged Combat","Energy",""},
			{"Repair","",""},
			{"Science","x",""},
			{"Survival","",""},
			{"System Operation","",""},
			{"Unarmed Combat","","x"}
		};
		prskills_count = 11;

		for(i=0; i<prskills_count; i++)
		{
			proSkillData.EnterData(g_prskills[i].skill,
				g_prskills[i].subskill, g_prskills[i].speciality);
			proSkillArray.push_back(proSkillData);
		}
	}
	
	CustomPackages(profession);
	

}

int ProPackage::GetProCount()
{
	return proSkillArray.size();
}

int ProPackage::GetAutoCount()
{
	return autoSkillArray.size();
}

int ProPackage::GetAutoLevel(int index)
{
	return autoSkillArray[index].GetLevel();
}

string ProPackage::GetAutoSpeciality(int index)
{
	return autoSkillArray[index].GetSpeciality();
}

string ProPackage::GetAutoSubSkill(int index)
{
	return autoSkillArray[index].GetSubSkill();
}

string ProPackage::GetAutoSkill(int index)
{
	return autoSkillArray[index].GetSkill();
}

string ProPackage::GetProSpeciality(int index)
{
	return proSkillArray[index].GetSpeciality();
}

string ProPackage::GetProSubSkill(int index)
{
	return proSkillArray[index].GetSubSkill();
}

string ProPackage::GetProSkill(int index)
{
	return proSkillArray[index].GetSkill();
}

void ProPackage::AddCustomData()
{
	
	string line, data, tag;
	char dummy[1001];
	fin.open("professions.txt");

	if(!fin)
		return;

	while(!fin.eof())
	{
		fin.getline(dummy,1000);
		line = dummy;
		
		line = Trim(line);

		if(line == "<")
		{
			profession.clear();
		}
		else if(line == ">")
		{
			
			professions.push_back(profession);
		}
		else
		{
			if(line.find(':') != string::npos)
			{
				int position = line.find(':');
				tag = line.substr(0,position);
				tag = Trim(tag);
				
				if(tag == "PACKAGE")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					profession.package = data;
				}
				else if(tag == "PROFESSION")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					profession.profession =data;
				}
				else if(tag == "SKILL")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					profession.skills += data + ',';
				}
				else if(tag == "EDGE")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					profession.edges += data + ',';
				}

			}


		}

	}

}

string ProPackage::Trim(string str)
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

string ProPackage::RemoveComma(string statement)
{
	if(statement == "")
		return statement;

	int x = statement.length()-1;

	
	for(int i=0; i< statement.size();i++)
	{
		if(statement[i] == ',')
			statement[i] = ' ';
	}

	statement = Trim(statement);
	return statement;

}

void ProPackage::CustomPackages(string str)
{
	
	if(professions.size() < 1)
		return;
	
	vector<_profession>::iterator it;
	for(it = professions.begin(); it != professions.end(); ++it)
	{
	
		if(it->profession == str)
		{
			packageTypes.push_back(it->package);
		}

	}
	

}

void ProPackage::CustomEdges(string str)
{
	if(str == "")
		return;

	string stredge;
	int startpos = 0;
	int nextpos=0,prevpos=0;

	while(str[startpos] != '\0')
	{
		stredge = "";
		if((str[startpos] == ',') || (startpos == str.length()-1))
		{
			stredge = str.substr(prevpos, startpos-prevpos+1);
			stredge = RemoveComma(stredge);
			edges.push_back(stredge);
			prevpos = startpos;
		}
		startpos++;

	}

}

void ProPackage::CustomSkills(string str)
{
	string skill, subskill, speciality,number;
	int startpos = 0;
	int nextpos=0,prevpos=0;

		
	
	while (str[startpos] != '\0')
	{
		subskill =speciality= "";
			
		if((str[startpos] == ',') || (startpos == str.length()-1))
		{
			
			skill = str.substr(prevpos, startpos-prevpos+1);
			
			int x,y,z;
			//****************** gettting speciality ***************************
			x = skill.find('(');
			y = skill.find(')');
			if((x != string::npos) && (y != string::npos))
			{
				speciality = skill.substr(x+1, y-x-1);
				
			}
			//***************** getting number *********************************
			z = skill.find('+');
			if (z == -1)
				z = skill.find('-');
			number = skill.substr(z);
			
			//****************** getting subskill **********************************
			if(skill.find(':') != string::npos){
			if ( x != string::npos)
			{
				int endpos = x;
				subskill = skill.substr(skill.find(':')+1, endpos- skill.find(':')-1);
				skill = skill.substr(0, skill.find(':'));
			}
			else
			{
				int endpos = z;
				subskill = skill.substr(skill.find(':')+1, endpos - skill.find(':')-1);
				skill = skill.substr(0, skill.find(':'));
			}}
				//****************** getting skill ********************************
				
			else
			{
				if (x  != string::npos)
				{
					skill = skill.substr(0, x);
				}
				else
				{
					skill = skill.substr(0, z);
				}
					
			}
				
			skill = RemoveComma(skill);
			subskill = RemoveComma(subskill);
			if (subskill == "*")
				subskill = "x";
			speciality = RemoveComma(speciality);
			if (speciality == "choose")
				speciality = "x";
			number = RemoveComma(number);
			
			jobSkillData.EnterData(skill,subskill,speciality, atoi(number.c_str()));
			autoSkillArray.push_back(jobSkillData);
			prevpos = startpos;


		}

		startpos++;


	}

}
