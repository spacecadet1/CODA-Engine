// CharData.cpp: implementation of the CharData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CharData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CharData::CharData()
{
	Flaws();
	Edges();
	Skills();
}

CharData::~CharData()
{

}

string CharData::GetFlaw(int index)
{
	return flaws[index];

}

void CharData::Flaws()
{
	string temp[] ={
		"Addiction", //1
			"Arrogant",	//2
			"Bloodlust",  //3
			"Coward",  //4
			"Dark Secret",  //5
			"Devotion",  //6
			"Dim-witted",  //7
			"Dullard",  //8
			"Easily Distracted",  //9
			"Easily Winded",  //10
			"Enemy",  //11
			"Familiar Face",  //12
			"Flat-Footed",  //13
			"Gullible",  //14
			"Infamy",  //15
			"Intolerant",  //16
			"Low Energy Level",  //17
			"Low Pain Threshold",  //18
			"Night Blind",  //19
			"Pacifist",  //20
			"Proud",  //21
			"Reckless",  //22
			"Rival",  //23
			"Shaky",  //24
			"Sickly",  //25
			"Slow",  //26
			"Slow Healing",  //27
			"Species Enmity",  //28
			"Thin-blooded",  //29
			"Weak Willed"  //30
	};

	for(int i=0;i<30;i++)
		flaws.push_back(temp[i]);

}

int CharData::GetFlawCount()
{
	return flaws.size();
}



void CharData::Edges()
{


	string temp []= {
	"Alert", //1
	"Ally",  //2
	"Ambidextrous",//3
	"Blends In",  //4
	"Blunt Attack",  //5
	"Bold",  //6
	"Command",   //7
	"Commendation",   //8
	"Competitive",   //9
	"Confident",  //10
	"Contacts", //11
	"Coordinator",  //12
	"Courageous",  //13
	"Cultural Flexibility",  //14
	"Curious",  //15
	"Dead Aim",  //16
	"Defensive Attack",  //17
	"Deliberate Attack",  //18
	"Dodge",  //19
	"Eidetic Memory",  //20
	"Everyman",  //21
	"Excellent Metabolism",  //22
	"Exceptional Concentration",  //23
	"Exceptional Fortitude",  //24
	"Fame",  //25
	"Famous Event",  //26
	"Fit",  //27
	"Friendly",  //28
	"Great Stamina",  //29
	"Great Vitality",  //30
	"Healthy",  //31
	"High Pain Threshold",  //32
	"Increased Range",  //33
	"Innovative",  //34
	"Iron Willed",  //35
	"Lighning Reflexes",  //36
	"Likeable",  //37
	"Martial Artist",  //38 
	"Meticulous",  //39
	"Multi-tasking",  //40
	"Night Vision",  //41
	"Promotion",  //42
	"Psionic",  //43
	"Psionic Coverage",  //44
	"Psionic Focus",  //45
	"Quick Draw",  //46
	"Quick Shot",  //47
	"Rapid Healing",  //48
	"Resolute",  //49
	"Sense of Direction",  //50
	"Sense of Time",  //51
	"Sherpa",  //52
	"Skill Focus:3D Thinking",  //53
	"Skill Focus:Compassionate",
	"Skill Focus:Craftman",
	"Skill Focus:Diplomatic",
	"Skill Focus:Eloquent",
	"Skill Focus:Furitive",
	"Skill Focus:Keen Hearing",
	"Skill Focus:Keen Sight",
	"Skill Focus:Persuasive",
	"Skill Focus:Seductive",
	"Species Friend",  //54
	"Speed",  //55
	"Suit Trained",  //56
	"Thick Skull",  //57
	"Thinker",  //58
	"Throw Weapon",  //59
	"Trait Upgrade",  //60
	"Two-Handed Fighting",  //61
	"Unyielding",  //62
	"Wealth",   //63
	"Weapon Mastery",  //64
	"Zero-G Trained"//65
	};

	for(int i=0;i<74;i++)
		edges.push_back(temp[i]);

}



void CharData::Skills()
{
	string temp []={ 
		"Appraise",		//1		
		"Armed Combat",//2
		"Athletics",//3
		"Computer Use",//4
		"Conceal",//5
		"Construct", //6
		"Craft:Sculpture",  //7
		"Craft:Pottery",	//8
		"Craft:Painting",	//9
		"Craft:Cooking",	//10
		"Craft:Calligraphy",	//11
		"Craft:Carpentery",	//12
		"Craft:Gem Cutting", //13
		"Craft:Modeling",  //14
		"Craft:Sewing",   //15
		"Craft:Weaving",  //16
		"Craft:Viticulture",  //17
		"Demolitions",   //18
		"Engineering:Propulsion",  //19
		"Engineering:Structural",  //20
		"Engineering:Systems",  //21
		"Enterprise:Administration",  //22
		"Enterprise:Business",  //23
		"Enterprise:Streetwise",  //24
		"Entertain:Dance",  //25
		"Entertain:Drama",  //26
		"Entertain:Sing",  //27
		"Entertain:Play Instrument",  //28
		"First Aid",  //29
		"Forgery",  //30
		"Gaming",  //31
		"Gymnastics",  //32
		"Impersonate",  //33
		"Indoctrinate",  //34
		"Influence",  //35
		"Inquire",  //36
		"Investigate",  //37
		"Knowledge:Culture",  //38
		"Knowledge:History",   //39
		"Knowledge:Law",  //40
		"Knowledge:Politics",  //41
		"Knowledge:Religion",   //42
		"Knowledge:Specific World",  //43
		"Knowledge:Trivia",   //44
		"Language",   //45
		"Medicine",   //46
		"Negotiate",   //47
		"Observe",   //48
		"Persuade",   //49
		"Ranged Combat:Archaic",	//50
		"Ranged Combat:Energy",	//51
		"Ranged Combat:Projectile",	//52
		"Repair",	//53
		"Science:Life",	//54
		"Science:Physical",	//55
		"Science:Planetary",	//56
		"Science:Social",	//57
		"Science:Space",	//58
		"Sleight of Hand",	//59
		"Sport",	//60
		"Stealth",	//61
		"Survival",	//62
		"System Operation",		//63
		"Tactics",	//64
		"Unarmed Combat",  //65
		"Empathy",	//66
		"Mind Control",  //67
		"Mind Shield",   //68
		"Telepathy",  //69
		"Vehicle Operation"
	};
	for(int i=0;i<70;i++)
	{
		skills.push_back(temp[i]);
	}


}


