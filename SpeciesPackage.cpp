// SpeciesPackage.cpp: implementation of the SpeciesPackage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpeciesPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SpeciesPackage::SpeciesPackage()
{
	typedef struct tag_speciesMod
	{
		char* species;
		int strength;
		int agility;
		int intellect;
		int vitality;
		int prescence;
		int preception;
		int psionics;
	}speciesMod;

	speciesMod g_speciesMod[] =
		{
			{"Bajoran",0,0,0,0,0,0,0},
			{"Betazoid",0,0,0,0,1,0,4},
			{"Cardassian",0,-1,0,1,-1,1,0},
			{"Ferengi",-2,0,0,0,1,1,0},
			{"Human",0,0,0,0,0,0,0},
			{"Klingon",1,0,-1,1,0,-1,0},
			{"Ocampa",0,0,1,-2,0,1,4},
			{"Talaxian",0,1,0,0,0,0,0},
			{"Trill",0,0,1,0,0,0,0},
			{"Vulcan",2,0,1,0,-3,0,4},
			{"Andorian",0,0,-1,1,0,1,0},
			{"Antican",0,0,-1,1,0,0,0},
			{"Atreonid",-1,-1,1,0,1,0,0},
			{"Benzite",-1,0,0,1,0,0,0},
			{"Betelgeusean",0,0,0,1,-1,0,0},
			{"Bolian",-1,1,0,0,0,0,0},
			{"Bynar",-3,1,2,0,0,0,0},
			{"Capellan",0,0,0,0,0,0,0},
			{"Deltan",0,0,0,-1,1,1,4},
			{"Ekosian",0,0,0,0,0,0,0},
			{"Elasian",1,-1,0,0,0,0,0},
			{"El-Aurian",-1,0,0,1,0,1,0},
			{"Gorn",3,-2,0,1,0,0,0},
			{"Kazon",0,1,0,0,0,0,0},
			{"Ktarian",0,0,-1,0,0,1,0},
			{"Ligonian",1,0,-1,0,0,0,0},
			{"Lurian",0,-1,0,1,0,0,0},
			{"Malon",0,0,2,0,0,-2,0},
			{"Nausicaan",1,0,-2,1,0,0,0},
			{"Orion",0,0,0,0,1,0,0},
			{"Romulan",1,0,0,0,-1,0,0},
			{"Selay",1,-1,0,0,0,0,0},
			{"Tellarite",0,0,0,1,-1,0,0},
			{"Yridian",0,0,0,0,-1,2,0},
			{"Zakdorn",0,0,2,0,-3,1,0},
			{"Zaranite",0,0,0,0,0,0,0},
			{"Centauran",0,0,0,0,1,0,0},
			{"Grazerite",0,0,0,0,1,0,0},
			{"Regulan",0,1,0,-1,0,2,0},
			{"Tiburonese",0,0,0,-1,1,0,0},
			{"Zaldan",1,0,0,2,-3,0,0},
			{"Borg",2,-2,0,2,-2,0,0},
			{"Breen",0,0,0,1,-1,0,0},
			{"Flaxian",1,0,0,1,0,0,0},
			{"Founder",-1,0,1,0,-1,1,0},
			{"Hirogen",3,1,0,0,-3,1,0},
			{"Horta",0,0,0,2,-2,0,4},
			{"Jem'Hadar",2,1,-2,2,-2,0,0},
			{"Kelvan",6,-4,2,4,-3,-3,4},
			{"Medusan",-2,0,4,0,-2,2,4},
			{"Pakled",0,0,-1,0,-1,2,0},
			{"Species 8472",6,1,0,3,-3,0,4},
			{"Suliban",0,1,0,0,-1,0,0},
			{"Talosian",-4,0,2,-4,0,0,8},
			{"Tholian",0,0,1,0,-2,2,4},
			{"Vian",0,0,2,-1,-1,0,10},
			{"Vidiian",0,0,1,-1,-1,0,0},
			{"Vorgon",0,0,0,-1,-1,2,0},
			{"Vorta",-1,-1,0,0,1,1,0},
			{"Napean",0,0,2,0,-2,0,4}
			
		};
		//speciesCount=60;

	for(int i =0; i<60;i++)
		{
			speciesData.EnterData(g_speciesMod[i].species, 
				g_speciesMod[i].strength, g_speciesMod[i].agility,
				g_speciesMod[i].intellect,g_speciesMod[i].vitality, g_speciesMod[i].prescence,
				g_speciesMod[i].preception, g_speciesMod[i].psionics);
			speciesArray.push_back(speciesData);
		}

	willpower =0;
	stamina =0;
	savvy =0;
	health =0;
	courage =3;
	renown =3;

	//**********include user's customization here *************
	//store in container and then include attributes in skillArray
	fin.open("aliens.txt");
	if(fin)
	{
		AddCustomData();
	}

}

SpeciesPackage::~SpeciesPackage()
{

}

string SpeciesPackage::GetSkillSpeciality(int index)
{
	return skillArray[index].GetSpeciality();
}

string SpeciesPackage::GetSubSkill(int index)
{
	return skillArray[index].GetSubSkill();
}

int SpeciesPackage::GetSkillLevel(int index)
{
	return skillArray[index].GetLevel();
}

string SpeciesPackage::GetSkill(int index)
{
	return skillArray[index].GetSkill();
}

int SpeciesPackage::GetSkillCount()
{
	return skillArray.size();
}

int SpeciesPackage::GetSavvy()
{
	return savvy;
}

int SpeciesPackage::GetHealth()
{
	return health;
}

int SpeciesPackage::GetStamina()
{
	return stamina;
}

int SpeciesPackage::GetWillpower()
{
	return willpower;
}

string SpeciesPackage::GetProAbility(int index)
{
	return pro_ability[index];
}

string SpeciesPackage::GetFlaw(int index)
{
	return flaws[index];
}

string SpeciesPackage::GetEdge(int index)
{
	return edges[index];
}

void SpeciesPackage::Species(string type)
{
	species = type;
	edges.clear();
	flaws.clear();
	pro_ability.clear();
	skillArray.clear();

}

string SpeciesPackage::GetSpeciesId(int x)
{
	return speciesArray[x].id;
}

int SpeciesPackage::GetSpeciesStrength(int x)
{
	return speciesArray[x].strength;
}

int SpeciesPackage::GetSpeciesAgility(int x)
{
	return speciesArray[x].agility;
}

int SpeciesPackage::GetSpeciesIntellect(int x)
{
	return speciesArray[x].intellect;
}

int SpeciesPackage::GetSpeciesVitality(int x)
{
	return speciesArray[x].vitality;
}

int SpeciesPackage::GetSpeciesPrescence(int x)
{
	return speciesArray[x].prescence;
}

int SpeciesPackage::GetSpeciesPerception(int x)
{
	return speciesArray[x].perception;
}

int SpeciesPackage::GetSpeciesPsionics(int x)
{
	return speciesArray[x].psionics;
}

int SpeciesPackage::GetSpeciesCount()
{
	return speciesArray.size();
}

int SpeciesPackage::GetFlawCount()
{
	return flaws.size();
}

int SpeciesPackage::GetEdgeCount()
{
	return edges.size();
}

int SpeciesPackage::GetProAbCount()
{
	return pro_ability.size();
}

void SpeciesPackage::SetSpecies()
{

	
	if (species =="Andorian")
	{
		
		edges.push_back("High Pain Threshold");
		

	}
	else if(species == "Antican")
	{
		speciesSkill.EnterData("Unarmed Combat","","Brawling",2);
		skillArray.push_back(speciesSkill);

	}
	else if(species == "Atreonid")
	{
		edges.push_back("Confident");
		edges.push_back("Thinker");

	}
	else if(species == "Benzite")
	{
		edges.push_back("Meticulous");
		edges.push_back("Famous Event");

	}
	else if(species == "Betazoid")
	{
		speciesSkill.EnterData("Telepathy","","",1);
		skillArray.push_back(speciesSkill);
		edges.push_back("Psionics");
	}
	else if(species == "Betelgeusean")
	{

		edges.push_back("Archetypal");
		health = 2;
	}
	else if(species == "Bolian")
	{
		edges.push_back("Coordinator");
		edges.push_back("Ally 2");
	}
	else if(species == "Borg")
	{
		flaws.push_back("Slow");
	}
	else if(species == "Breen")
	{
		edges.push_back("Suit Trained");
		savvy =1;
	}
	else if(species == "Bynar")
	{
		edges.push_back("Exceptional Concentration");
	}
	else if(species == "Capellan")
	{
		edges.push_back("Quick Draw");
		flaws.push_back("Bloodlust");
		speciesSkill.EnterData("Armed Combat","","Kilgat",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Cardassian")
	{
		edges.push_back("Eidetic Memory");
		edges.push_back("High Pain Threshold");
	}
	else if(species == "Deltan")
	{
		speciesSkill.EnterData("Empathy","","",2);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Pain Reduction","","",1);
		skillArray.push_back(speciesSkill);
		edges.push_back("Psionics");
	}
	else if(species == "Ekosian")
	{
		edges.push_back("Bold");
		edges.push_back("Courageous");
	}
	else if(species == "Elasian")
	{
		edges.push_back("Resolute");
	}
	else if(species == "El-Aurian")
	{
		edges.push_back("Cultural Flexibilty");
	}
	else if(species == "Flaxian")
	{
		edges.push_back("Meticulous 2");
	}
	else if(species == "Gorn")
	{
		edges.push_back("Competitive");
		edges.push_back("Resolute");
	}
	else if(species == "Hirogen")
	{
		edges.push_back("Deliberate Attack");
		edges.push_back("Skill Focus:Hunting");
	}
	else if(species == "Jem'Hadar")
	{
		edges.push_back("Exceptional Fortitude");
		edges.push_back("High Pain Threshold");
		flaws.push_back("Addiction 2");
		speciesSkill.EnterData("Armed Combat","","Simple Weapon",1);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Ranged Combat:Energy","","",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Kazon")
	{
		edges.push_back("Everyman");
		edges.push_back("Shrewd");
		flaws.push_back("Species Enimity");
		speciesSkill.EnterData("Demolitions","","",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Kelvan")
	{
		edges.push_back("Multitasking");
		edges.push_back("Psionics");
		flaws.push_back("Arrogant");
	}
	else if(species == "Klingon")
	{
		edges.push_back("High Pain Threshold");
		speciesSkill.EnterData("Armed Combat","","Klingon Traditional Weapons",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Ktarian")
	{
		edges.push_back("Alert");
		edges.push_back("Bold");
	}
	else if(species == "Ligonian")
	{
		edges.push_back("Competitive");
		edges.push_back("Ambidextrous");
	}
	else if(species == "Lurian")
	{
		edges.push_back("Likeable");
		stamina = 1;
	}
	else if(species == "Malon")
	{
		edges.push_back("Curious");
		edges.push_back("Excellent Metablolism");
	}
	else if(species == "Medusan")
	{
		speciesSkill.EnterData("Empathy","","",4);
		skillArray.push_back(speciesSkill);
		edges.push_back("Psionics");
	}
	else if(species == "Nausicaan")
	{
		edges.push_back("High Pain Threshold");
		//choose two skills from Armed,Unarmed,or Ranged
	}
	else if(species == "Napean")
	{
		speciesSkill.EnterData("Empathy","","",1);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Mind Shield","","",1);
		skillArray.push_back(speciesSkill);
		edges.push_back("Psionics");
	}
	else if(species == "Ocampa")
	{
		edges.push_back("Eidetic Memory");
		edges.push_back("Psionics");
		speciesSkill.EnterData("Telepathy","","",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Orion")
	{
		savvy = 2;
	}
	else if(species == "Pakled")
	{
		edges.push_back("Sherpa");
		edges.push_back("Thick Skull");
	}
	else if(species == "Romulan")
	{
		edges.push_back("Skill Focus:Keen Hearing");
	}
	else if(species == "Selay")
	{
		speciesSkill.EnterData("Unarmed Combat","","Fangs",1);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Observe","","Track",2);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Species 8472")
	{
		edges.push_back("Increased Range");
		edges.push_back("Psionics");
		speciesSkill.EnterData("Telepathy","","",6);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Suliban")
	{
		edges.push_back("Night Vision");
		//Nomadic ???
	}
	else if(species == "Talaxian")
	{
		edges.push_back("Night Vision");
		savvy = 1;
	}
	else if(species == "Talosian")
	{
		flaws.push_back("Addiction 3");
		edges.push_back("Psionics");
	}
	else if(species == "Tellarite")
	{
		edges.push_back("Exceptional Fortitude");
		edges.push_back("Meticulous");
		edges.push_back("Skill Focus:Exhuastive");
	}
	else if(species == "Tholian")
	{
		edges.push_back("Ambidextrous");
		edges.push_back("Psionics");
		edges.push_back("Everyman");
		edges.push_back("Exceptional Concentration");
		edges.push_back("Multitasking");
		edges.push_back("Sense of Time 2");
		edges.push_back("Unyielding");
	}
	else if(species == "Vidiian")
	{
		edges.push_back("Courageous");
		edges.push_back("Skill Focus:Organ Harvesting");
		flaws.push_back("Sickly");
		flaws.push_back("Slow Healing");
		speciesSkill.EnterData("Knowledge","Anatomy","",1);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Medicine","","",2);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Vorgon")
	{
		edges.push_back("Night Vision");
		edges.push_back("Rapid Healing");
	}
	else if(species == "Vorta")
	{
		edges.push_back("Confident");
		edges.push_back("Skill Focus:Keen Hearing");
	}
	else if(species == "Centauran")
	{
		willpower = 2;
	}
	else if(species == "Grazerite")
	{
		speciesSkill.EnterData("Unarmed Combat","","Palava",1);
		skillArray.push_back(speciesSkill);
		edges.push_back("Exceptional Concentration");
		edges.push_back("Thick Skull");
	}
	else if(species == "Regulan")
	{
		edges.push_back("Night Vision");
	}
	else if(species == "Zaldan")
	{
		edges.push_back("Exceptional Metabolism");
		edges.push_back("Unyielding");
	}
	else if(species == "Vulcan")
	{
		edges.push_back("Skill Focus:Keen Hearing");
		edges.push_back("Enhanced Rapid Healing");
		edges.push_back("Psionics");
	}
	else if(species == "Yridian")
	{
		edges.push_back("Eidetic Memory");
		
	}
	else if(species == "Zakdorn")
	{
		edges.push_back("Competitive");
		edges.push_back("Meticulous");
	}
	else if(species == "Zaranite")
	{
		edges.push_back("Night Vision");
		speciesSkill.EnterData("Science","Physical","Mathematics",1);
		skillArray.push_back(speciesSkill);
		speciesSkill.EnterData("Psychohistory","","",1);
		skillArray.push_back(speciesSkill);
	}
	else if(species == "Vian")
	{
		edges.push_back("Psionics");
	}
	else if(species == "Horta")
	{
		edges.push_back("Psionics");
	}
	else if(species == "Human")
	{
		courage += 1;
	}
	else if(species == "Bajoran")
	{
		courage += 1;
	}
	else  // custom data
	{
		vector<_alien>::iterator it;
				
		for(it = aliens.begin(); it != aliens.end(); ++it)
		{
			if(it->id == species)
			{
				willpower += it->will;
				stamina += it->stam;
				savvy += it->savv;
				health += it->hlth;
				courage += it->cour;
				renown += it->rnwn;
				CustomEdges(it->edges);
				CustomFlaws(it->flaws);
				CustomSkills(it->skills);
			}
		}
		

	}
	
}

int SpeciesPackage::GetCourage()
{
	return courage;
}

int SpeciesPackage::GetRenown()
{
	return renown;
}

string SpeciesPackage::Trim(string str)
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

string SpeciesPackage::RemoveComma(string statement)
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

void SpeciesPackage::AddCustomData()
{
	string line, data, tag;
	char dummy[1001];
	vector<_alien>::iterator it;
	
		
	while(!fin.eof())
	{
		fin.getline(dummy,1000);
		line = dummy;		
		line = Trim(line);
		if(line == "<")
		{
			alien.clear();
		}
		else if(line == ">")
		{			
			aliens.push_back(alien);
		}
		else
		{
			if(line.find(':') != string::npos)
			{
				int position = line.find(':');
				tag = line.substr(0,position);
				tag = Trim(tag);
				
				if (tag == "STR")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.str= atoi(data.c_str());
				}
				else if(tag == "VIT")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.vit = atoi(data.c_str());
				}
				else if(tag == "INT")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.intl = atoi(data.c_str());
				}
				else if(tag == "PSI")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.psi = atoi(data.c_str());
				}
				else if(tag == "PRE")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.pre = atoi(data.c_str());
				}
				else if(tag == "PER")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.per = atoi(data.c_str());
				}
				else if(tag == "AGL")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.agl = atoi(data.c_str());
				}
				else if(tag == "SAVV")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.savv = atoi(data.c_str());
				}
				else if(tag == "QUIK")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.quik = atoi(data.c_str());
				}
				else if(tag == "COUR")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.cour = atoi(data.c_str());
				}
				else if(tag == "RNWN")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.rnwn = atoi(data.c_str());
				}
				else if(tag == "HLTH")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.hlth = atoi(data.c_str());
				}
				else if(tag == "WILL")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.will = atoi(data.c_str());
				}
				else if(tag == "STAM")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.stam = atoi(data.c_str());
				}
				else if(tag == "SKILL")
				{					
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.skills += data + ',';
				
				}
				else if(tag == "EDGE")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.edges= alien.edges + data + ',';
				}
				else if(tag == "FLAW")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.flaws  = alien.flaws+ data + ',';
				}
				else if(tag == "SPECIES")
				{
					data = line.substr(line.find(':')+1);
					data = Trim(data);
					alien.id = data;
										
				}
			}
		}
	}
	
	for(it = aliens.begin(); it != aliens.end(); ++it)
	{
		speciesData.EnterData(it->id,
			it->str,it->agl,it->intl,
			it->vit,it->pre,it->per,it->psi);
		speciesArray.push_back(speciesData);
		
	}
	
}

void SpeciesPackage::CustomEdges(string str)
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

void SpeciesPackage::CustomFlaws(string str)
{
	if(str == "")
		return;

	string strflaw;
	int startpos = 0;
	int nextpos=0,prevpos=0;

	while(str[startpos] != '\0')
	{
		strflaw = "";
		if((str[startpos] == ',') || (startpos == str.length()-1))
		{
			strflaw = str.substr(prevpos, startpos-prevpos+1);
			strflaw = RemoveComma(strflaw);
			flaws.push_back(strflaw);
			prevpos = startpos;
		}
		startpos++;

	}

}



void SpeciesPackage::CustomSkills(string str)
{
	string skill, subskill, speciality,number;
	int startpos = 0;
	int nextpos=0,prevpos=0;

	if (str == "")
		return;
		
	
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
			speciesSkill.EnterData(skill, subskill, speciality, atoi(number.c_str()));
			skillArray.push_back(speciesSkill);
			prevpos = startpos;


		}

		startpos++;


	}

}
