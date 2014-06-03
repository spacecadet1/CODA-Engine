// Background.cpp: implementation of the Background class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Background.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Background::Background()
{

}

Background::~Background()
{

}

void Background::Enterprise(int x)
{
	if(x==1)
	{
		pickOne.push_back("Enterprise:Administration");
		pickOne.push_back("Enterprise:Business");
		pickOne.push_back("Enterprise:Streetwise");
	}
	else
	{
		pickThree.push_back("Enterprise:Administration");
		pickThree.push_back("Enterprise:Business");
		pickThree.push_back("Enterprise:Streetwise");
	}
}

void Background::Engineering(int x)
{
	if(x==1)
	{
		pickOne.push_back("Engineering:Propulsion");
		pickOne.push_back("Engineering:Structural");
		pickOne.push_back("Engineering:Systems");
	}
	else
	{
		pickThree.push_back("Engineering:Propulsion");
		pickThree.push_back("Engineering:Structural");
		pickThree.push_back("Engineering:Systems");
	}
}

void Background::Entertain(int x)
{
	if (x==1)
	{
		pickOne.push_back("Entertain:Dance");
		pickOne.push_back("Entertain:Drama");
		pickOne.push_back("Entertain:Sing");
		pickOne.push_back("Entertain:Play Instrument");
		
	}
	else
	{
		pickThree.push_back("Entertain:Dance");
		pickThree.push_back("Entertain:Drama");
		pickThree.push_back("Entertain:Sing");
		pickThree.push_back("Entertain:Play Instrument");
	}

}

void Background::Craft(int x)
{
	if(x==1)
	{
		pickOne.push_back("Craft:Sculpture");
		pickOne.push_back("Craft:Pottery");
		pickOne.push_back("Craft:Painting");
		pickOne.push_back("Craft:Cooking");
		pickOne.push_back("Craft:Calligraphy");
		pickOne.push_back("Craft:Carpentery");
		pickOne.push_back("Craft:Gem Cutting");
		pickOne.push_back("Craft:Modeling");
		pickOne.push_back("Craft:Sewing");
		pickOne.push_back("Craft:Weaving");
		pickOne.push_back("Craft:Viticulture");
		
	}
	else
	{
		pickThree.push_back("Craft:Sculpture");
		pickThree.push_back("Craft:Pottery");
		pickThree.push_back("Craft:Painting");
		pickThree.push_back("Craft:Cooking");
		pickThree.push_back("Craft:Calligraphy");
		pickThree.push_back("Craft:Carpentery");
		pickThree.push_back("Craft:Gem Cutting");
		pickThree.push_back("Craft:Modeling");
		pickThree.push_back("Craft:Sewing");
		pickThree.push_back("Craft:Weaving");
		pickThree.push_back("Craft:Viticulture");
	}

}

void Background::Science(int x)
{
	if(x==1)
	{
		pickOne.push_back("Science:Life");
		pickOne.push_back("Science:Physical");
		pickOne.push_back("Science:Planetary");
		pickOne.push_back("Science:Social");
		pickOne.push_back("Science:Space");
	}
	else
	{
		pickThree.push_back("Science:Life");
		pickThree.push_back("Science:Physical");
		pickThree.push_back("Science:Planetary");
		pickThree.push_back("Science:Social");
		pickThree.push_back("Science:Space");

	}

}

void Background::Knowledge(int x)
{
	if(x==1)
	{
		pickOne.push_back("Knowledge:Culture");
		pickOne.push_back("Knowledge:History");
		pickOne.push_back("Knowledge:Law");
		pickOne.push_back("Knowledge:Politics");
		pickOne.push_back("Knowledge:Religion");
		pickOne.push_back("Knowledge:Specific World");
		pickOne.push_back("Knowledge:Trivia");
	}
	else
	{
		pickThree.push_back("Knowledge:Culture");
		pickThree.push_back("Knowledge:History");
		pickThree.push_back("Knowledge:Law");
		pickThree.push_back("Knowledge:Politics");
		pickThree.push_back("Knowledge:Religion");
		pickThree.push_back("Knowledge:Specific World");
		pickThree.push_back("Knowledge:Trivia");
	}

}

string Background::GetPickFlawItem(int index)
{
	return ref.GetFlaw(index);
}

string Background::GetPickEdgeItem(int index)
{
	return pickEdge[index];
}

string Background::GetPickThreeItem(int index)
{
	return pickThree[index];
}

string Background::GetPickOneItem(int index)
{
	return pickOne[index];
}

int Background::GetPickFlawCount()
{
	return ref.GetFlawCount();
}

int Background::GetPickEdgeCount()
{
	return pickEdge.size();
}

int Background::GetPickThreeCount()
{
	return pickThree.size();
}

int Background::GetPickOneCount()
{
	return pickOne.size();
}

void Background::SetBackground(string Background)
{
	pickOne.clear();
	pickThree.clear();
	pickEdge.clear();
	pickFlaw.clear();
	if (Background == "Academic")
	{
		
		pickOne.push_back("Computer Use");
		Knowledge(1);
		Science(1);
	
		Craft(3);
		Entertain(3);
		Engineering(3);
		pickThree.push_back("Language");

		pickEdge.push_back("Cultural Flexibility");
		pickEdge.push_back("Curious");
		pickEdge.push_back("Eidetic Memory");
		pickEdge.push_back("Meticulous");
		pickEdge.push_back("Thinker");
		
	}
	else if (Background == "Alien Upbringing")
	{
		pickOne.push_back("Impersonate");
		pickOne.push_back("Knowledge:Culture");
		pickOne.push_back("Knowledge:History");
		pickOne.push_back("Survival");

		pickThree.push_back("Armed Combat");
		Craft(3);
		Entertain(3);
		pickThree.push_back("Gaming");
		Knowledge(3);
		pickThree.push_back("Observe");
		pickThree.push_back("Persuade");
		pickThree.push_back("Sport");

		pickEdge.push_back("Ally");
		pickEdge.push_back("Competitive");
		pickEdge.push_back("Cultural Flexibility");
		pickEdge.push_back("Friendly");
		pickEdge.push_back("Innovative");
		pickEdge.push_back("Psionics");
		pickEdge.push_back("Species Friend");
	}
	else if (Background == "Artistic")
	{
		Craft(1);
		Entertain(1);
		Knowledge(1);

		pickThree.push_back("Appraise");
		pickThree.push_back("Computer Use");
		pickThree.push_back("Construct");
		pickThree.push_back("Forgery");
		pickThree.push_back("Gaming");
		pickThree.push_back("Language");
		Science(3);

		pickEdge.push_back("Cultural Flexibility");
		pickEdge.push_back("Skill Focus:Compassionate");
		pickEdge.push_back("Skill Focus:Craftsman");
		pickEdge.push_back("Unyielding");
		pickEdge.push_back("Wealth");

	}
	else if (Background == "Athletic")
	{
		pickOne.push_back("Athletics");
		pickOne.push_back("Gymnastics");
		pickOne.push_back("Sport");

		pickThree.push_back("Armed Combat");
		Entertain(3);
		pickThree.push_back("Gaming");
		Knowledge(3);
		pickThree.push_back("Ranged Combat:Archaic");
		pickThree.push_back("Ranged Combat:Energy");

		pickEdge.push_back("Ambidextrous");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Fit");
		pickEdge.push_back("Fast On Your Feet");
		pickEdge.push_back("Speed");

	}
	else if (Background == "Colony/Frontier")
	{
		pickOne.push_back("Construct");
		Science(1);
		pickOne.push_back("Survival");

		pickThree.push_back("Athletics");
		pickThree.push_back("Computer Use");
		Engineering(3);
		Entertain(3);
		pickThree.push_back("First Aid");
		pickThree.push_back("Gaming");
		Knowledge(3);
		pickThree.push_back("Repair");
		Science(3);

		pickEdge.push_back("Alert");
		pickEdge.push_back("Curious");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Innovative");
		pickEdge.push_back("Unyielding");
	}
	else if (Background == "Criminal")
	{
		pickOne.push_back("Gaming");
		pickOne.push_back("Stealth");
		pickOne.push_back("Enterprise:Streetwise");

		pickThree.push_back("Armed Combat");
		pickThree.push_back("Appraise");
		pickThree.push_back("Athletics");
		pickThree.push_back("Forgery");
		pickThree.push_back("Impersonate");
		pickThree.push_back("Influence");
		Knowledge(3);
		pickThree.push_back("Repair");
		pickThree.push_back("Sleight of Hand");

		pickEdge.push_back("Alert");
		pickEdge.push_back("Ambidextrous");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Lighning Reflexes");
		pickEdge.push_back("Skill Focus:Furtive");

	}
	else if (Background == "Diplomat's Child")
	{
		pickOne.push_back("Enterprise:Administration");
		Knowledge(1);
		pickOne.push_back("Negotiate");

		pickThree.push_back("Computer Use");
		pickThree.push_back("Influence");
		Knowledge(3);
		pickThree.push_back("Language");
		Science(3);
		pickThree.push_back("System Operation");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Meticulous");
		pickEdge.push_back("Skill Focus:Diplomatic");
		pickEdge.push_back("Skill Focus:Eloquent");
		pickEdge.push_back("Skill Focus:Persuasive");
		
	}
	else if (Background == "Engineering Brat")
	{
		pickOne.push_back("Construct");
		Engineering(1);
		pickOne.push_back("Repair");

		pickThree.push_back("Computer Use");
		pickThree.push_back("Conceal");
		pickThree.push_back("System Operation");
		Engineering(3);
		Science(3);

		pickEdge.push_back("Curious");
		pickEdge.push_back("Innovative");
		pickEdge.push_back("Skill Focus:3D Thinking");
		pickEdge.push_back("Skill Focus:Attentive");
		pickEdge.push_back("Suit Trained");
		

	}
	else if (Background == "Famous Parents")
	{
		Enterprise(1);
		pickOne.push_back("Influence");
		Knowledge(1);

		pickThree.push_back("Computer Use");
		Entertain(3);
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Science:Social");
		pickThree.push_back("Sport");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Fit");
		pickEdge.push_back("Skill Focus:Diplomatic");
		pickEdge.push_back("Skill Focus:Persuasvie");
		pickEdge.push_back("Wealth");

	}
	else if (Background == "Genetic Resequencing")
	{
		pickOne.push_back("Athletics");
		Knowledge(1);
		Science(1);

		pickThree.push_back("Computer Use");
		Craft(3);
		Entertain(3);
		pickThree.push_back("Gymnastics");
		Knowledge(3);
		Science(3);
		pickThree.push_back("Sport");

		pickEdge.push_back("Ambidextrous");
		pickEdge.push_back("Eidetic Memory");
		pickEdge.push_back("Excellent Metabolism");
		pickEdge.push_back("Exceptional Concentration");
		pickEdge.push_back("Exceptional Fortitude");
		pickEdge.push_back("Fit");
		pickEdge.push_back("Great Stamina");
		pickEdge.push_back("Great Vitality");
		pickEdge.push_back("Healthy");
		pickEdge.push_back("Multitasking");
		pickEdge.push_back("Sense of Direction");
		pickEdge.push_back("Sense of Time");
		pickEdge.push_back("Skill Focus:Keen Hearing");
		pickEdge.push_back("Skill Focus:Keen Sight");
		pickEdge.push_back("Speed");
		pickEdge.push_back("Thinker");
		//two edges must be selected

		pickFlaw.push_back("Dark Secret");


	}
	else if (Background == "Mercantile Upbringing")
	{
		pickOne.push_back("Enterprise:Business");
		pickOne.push_back("Negotiate");
		pickOne.push_back("Persuade");

		pickThree.push_back("Enterprise:Administration");
		pickThree.push_back("Appraise");
		pickThree.push_back("Computer Use");
		Entertain(3);
		pickThree.push_back("Influence");
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("System Operation");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Cultural Flexibility");
		pickEdge.push_back("Shrewd");
		pickEdge.push_back("Skill Focus:Eloquent");
		pickEdge.push_back("Wealth");

	}
	else if (Background == "Military Brat")
	{
		pickOne.push_back("Athletics");
		pickOne.push_back("Ranged Combat:Energy");
		pickOne.push_back("First Aid");

		pickThree.push_back("Armed Combat");
		pickThree.push_back("Computer Use");
		pickThree.push_back("Gaming");
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Ranged Combat:Energy");
		pickThree.push_back("Ranged Combat:Archaic");
		pickThree.push_back("Ranged Combat:Projectile");
		pickThree.push_back("Repair");
		pickThree.push_back("Survival");
		pickThree.push_back("System Operation");

		pickEdge.push_back("Alert");
		pickEdge.push_back("Bold");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Fit");
		pickEdge.push_back("Sherpa");

	}
	else if (Background == "Nomadic Childhood")
	{
		pickOne.push_back("Gaming");
		pickOne.push_back("Language");
		pickOne.push_back("Knowledge:Specific World");
		pickOne.push_back("Sport");

		pickThree.push_back("Computer Use");
		Engineering(3);
		Enterprise(3);
		Entertain(3);
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Negotiate");
		pickThree.push_back("Repair");
		pickThree.push_back("System Operation");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Cultural Flexibility");
		pickEdge.push_back("Curious");
		pickEdge.push_back("Shrewd");
		pickEdge.push_back("Skill Focus:Persuasive");


	}
	else if (Background == "Occupation Upbringing")
	{
		pickOne.push_back("Brawling");
		pickOne.push_back("Stealth");
		pickOne.push_back("Enterprise:Streetwise");

		pickThree.push_back("Athletics");
		Craft(3);
		pickThree.push_back("Demolitions");
		pickThree.push_back("Ranged Combat:Energy");
		pickThree.push_back("Influence");
		pickThree.push_back("Inquire");
		pickThree.push_back("Persuade");
		pickThree.push_back("Simple Weapon");
		pickThree.push_back("Sport");
		pickThree.push_back("Survival");

		pickEdge.push_back("Alert");
		pickEdge.push_back("Bold");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Skill Focus:Furtive");
		pickEdge.push_back("Sneaky");

	}
	else if (Background == "Orphan")
	{
		Craft(1);
		pickOne.push_back("Stealth");
		pickOne.push_back("Enterprise:Streetwise");

		pickThree.push_back("Brawling");
		pickThree.push_back("Computer Use");
		Entertain(3);
		pickThree.push_back("Influence");
		Knowledge(3);
		pickThree.push_back("Survival");

		pickEdge.push_back("Blends In");
		pickEdge.push_back("Contacts");
		pickEdge.push_back("Dodge");
		pickEdge.push_back("Shrewd");
		pickEdge.push_back("Skill Focus:Furtive");


	}
	else if (Background == "Political Upbringing")
	{
		pickOne.push_back("Enterprise:Administration");
		pickOne.push_back("Influence");
		Knowledge(1);

		pickThree.push_back("Enterprise:Business");
		pickThree.push_back("Computer Use");
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Negotiate");
		pickThree.push_back("Persuade");
		pickThree.push_back("Science:Social");
		pickThree.push_back("Sport");

		pickEdge.push_back("Shrewd");//check this one
		pickEdge.push_back("Skill Focus:Diplomatic");
		pickEdge.push_back("Skill Focus:Eloquent");
		pickEdge.push_back("Skill Focus:Persuasive");
		pickEdge.push_back("Wealth");
		

	}
	else if (Background == "Psionic Potential")
	{
		
		pickOne.push_back("Empathy");
		pickOne.push_back("Mind Control");
		pickOne.push_back("Mind Shield");
		pickOne.push_back("Telepathy");

		pickThree.push_back("Computer Use");
		pickThree.push_back("Gaming");
		pickThree.push_back("Influence");
		pickThree.push_back("Empathy");
		pickThree.push_back("Mind Control");
		pickThree.push_back("Mind Shield");
		pickThree.push_back("Telepathy");
		

		pickEdge.push_back("Psionics");
		pickEdge.push_back("Eidetic Memory");
		pickEdge.push_back("High Pain Threshold");
		pickEdge.push_back("Iron Willed");
		pickEdge.push_back("Skill Focus:3D Thinking");
		pickEdge.push_back("Thinker");

	}
	else if (Background == "Religious")
	{
		Craft(1);
		pickOne.push_back("Knowledge:Religion");
		pickOne.push_back("Science:Social");

		pickThree.push_back("Enterprise:Administration");
		pickThree.push_back("Computer Use");
		Entertain(3);
		pickThree.push_back("Influence");
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Persuade");
		pickThree.push_back("Unarmed Combat");

		pickEdge.push_back("Eidetic Memory");
		pickEdge.push_back("Meticulous");
		pickEdge.push_back("Skill Focus:Attentive");
		pickEdge.push_back("Skill Focus:Compassionate");
		pickEdge.push_back("Skill Focus:Diplomatic");
		

	}
	else if (Background == "Scientific")
	{
		pickOne.push_back("Computer Use");
		Knowledge(1);
		Science(1);

		pickThree.push_back("Construct");
		Engineering(3);
		Enterprise(3);
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Repair");
		pickThree.push_back("System Operation");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Curious");
		pickEdge.push_back("Eidetic Memory");
		pickEdge.push_back("Meticulous");
		pickEdge.push_back("Unyielding");

	}
	else if (Background == "Starfleet Brat")
	{
		pickOne.push_back("Enterprise:Administration");
		pickOne.push_back("Computer Use");
		Science(1);

		pickThree.push_back("Athletics");
		pickThree.push_back("Construct");
		Engineering(3);
		Entertain(3);
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Repair");
		pickThree.push_back("Sport");
		pickThree.push_back("System Operation");

		pickEdge.push_back("Bold");
		pickEdge.push_back("Contacts");
		pickEdge.push_back("Fit");
		pickEdge.push_back("Resolute");
		pickEdge.push_back("Skill Focus:Eloquent");


	}
	else if (Background == "Wealthy Family")
	{
		pickOne.push_back("Enterprise:Business");
		pickOne.push_back("Influence");
		pickOne.push_back("Sport");

		Entertain(3);
		pickThree.push_back("Gymnastics");
		Knowledge(3);
		pickThree.push_back("Language");
		pickThree.push_back("Negotiate");
		pickThree.push_back("Persuade");

		pickEdge.push_back("Contacts");
		pickEdge.push_back("Iron Willed");
		pickEdge.push_back("Skill Focus:Seductive");
		pickEdge.push_back("Unyielding");
		pickEdge.push_back("Wealth");

	}
	else if (Background == "[Custom]")
	{
		pickOne= ref.skills;
		pickThree=ref.skills;
		pickEdge=ref.edges;
		
	}
}
