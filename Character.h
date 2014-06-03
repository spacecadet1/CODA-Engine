// Character.h : Declaration of the CCharacter

#ifndef __CHARACTER_H_
#define __CHARACTER_H_

#include "resource.h"       // main symbols
#include "Skills.h"	// Added by ClassView
#include "SpeciesPackage.h"	// Added by ClassView
#include "resource.h"       // main symbols
#include <vector>
#include <string>
#include <algorithm>
#include "ProPackage.h"	// Added by ClassView
#include "Background.h"	// Added by ClassView
#include "Traits.h"	// Added by ClassView
#include "DlgRetrieve.h"	// Added by ClassView
#include "DlgMessage.h"	// Added by ClassView

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CCharacter
class ATL_NO_VTABLE CCharacter : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCharacter, &CLSID_Character>,
	public ISupportErrorInfo,
	public IDispatchImpl<ITrekCharacter, &IID_ITrekCharacter, &LIBID_CODALib>
{
public:
	CCharacter()
	{
		elite="none";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CHARACTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCharacter)
	COM_INTERFACE_ENTRY(ITrekCharacter)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ITrekCharacter
public:
	STDMETHOD(get_Species_List)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Species_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(SetSpecies)();
	STDMETHOD(get_Edge)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Flaw)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Edge_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_Flaw_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_Edge_Exist)(BSTR name, /*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_Flaw_Exist)(BSTR name, /*[out, retval]*/ BOOL *pVal);
	STDMETHOD(Edge_Add)(BSTR name);
	STDMETHOD(Flaw_Add)(BSTR name);
	STDMETHOD(get_Skill_Specific)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Skill_Name)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_Skill_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_Skill_Level)(int index, /*[out, retval]*/ int *pVal);
	STDMETHOD(Skill_Modify)(BSTR name, BSTR specific, int level);
	STDMETHOD(Skill_Add)(BSTR name, BSTR specific, int level);
	STDMETHOD(Skill_Remove)(BSTR name, BSTR specific);
	STDMETHOD(Skill_RemoveAll)();
	STDMETHOD(get_Skill_Exist)(BSTR name, BSTR specific, /*[out, retval]*/ BOOL *pVal);
	STDMETHOD(Skill_ReplaceLevel)(BSTR name, BSTR specific, int level);
	STDMETHOD(get_Attributes)(int index, /*[out, retval]*/ int *pVal);
	STDMETHOD(put_Attributes)(int index, /*[in]*/ int newVal);
	STDMETHOD(RecordSpeciesModifiers)();
	STDMETHOD(RecordReactionModifiers)();
	STDMETHOD(put_Background)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_PickOneCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_PickThreeCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_PickEdgeCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_PickFlawCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_PickOneItem)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_PickThreeItem)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_PickEdgeItem)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_PickFlawItem)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(LoadChoices)();
	STDMETHOD(LoadPackage)(BSTR newVal);
	STDMETHOD(get_ProfessionalSkill)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ProfessionalSubSkill)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ProfessionalSpeciality)(int index, BSTR skill, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ProfessionalCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_AutoSkill)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_AutoSubSkill)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_AutoSpeciality)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_AutoLevel)(int index, /*[out, retval]*/ int *pVal);
	STDMETHOD(get_AutoCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_Gender)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Gender)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Rank)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Rank)(/*[in]*/ int newVal);
	STDMETHOD(get_Age)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Age)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Profession)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Profession)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Elite)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Elite)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Species)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Species)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Health)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Health)(/*[in]*/ int newVal);
	STDMETHOD(get_Courage)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Courage)(/*[in]*/ int newVal);
	STDMETHOD(get_Renown)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Renown)(/*[in]*/ int newVal);
	STDMETHOD(Age_Effects)();
	STDMETHOD(Rank_Assign)();
	STDMETHOD(LoadTier)();
	STDMETHOD(get_TierList_Count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_TierList)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(Elite_Upgrade)();
	STDMETHOD(get_FaveReaction)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_FaveReaction)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Fave1Attribute)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Fave1Attribute)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Fave2Attribute)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Fave2Attribute)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Dice)(int index, /*[out, retval]*/ int *pVal);
	STDMETHOD(Dice_Rolls)();
	STDMETHOD(LoadEliteTier)();
	STDMETHOD(Background_Entry)(BSTR skill, int level);
	STDMETHOD(get_ProfEdgesCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(get_ProfEdges)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(LoadProfSkills)();
	STDMETHOD(get_ProfPackages)(int index, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(get_ProfPackagesCount)(/*[out, retval]*/ int *pVal);
	STDMETHOD(ProfPackage_Entry)(BSTR skill, BSTR speciality, int level);
	STDMETHOD(get_UserSpeciality)(BSTR skill, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(Traits_RemoveAll)();
	STDMETHOD(get_Defense)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_Defense)(/*[in]*/ int newVal);
	STDMETHOD(get_Reactions)(int index, /*[out, retval]*/ int *pVal);
	STDMETHOD(DepartmentHead_Add)(int choice, int index);
	
	STDMETHOD(get_IsProfessionalSkill)(BSTR skill, /*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_IsFavorite)(BSTR name, /*[out, retval]*/ BOOL *pVal);
	STDMETHOD(ShowMessage)(BSTR caption);
	STDMETHOD(ShowInfo)(BSTR caption);
	STDMETHOD(get_AttributeModifier)(int number, /*[out, retval]*/ int *pVal);
	STDMETHOD(put_Language)(/*[in]*/ BSTR newVal);
	
	STDMETHOD(Untrained_Add)();
	
private:
	DlgMessage msg;
	//DlgRetrieve retr;
	string ToString(BSTR str);
	string Trim(string str);
	Traits flaws, edges;
	Skills skills;
	Background background;
	ProPackage package;
	SpeciesPackage pkSpecies;
	
	int GetMod(int score);
	string Capitialize(string statement);
	string UserSpecify(string skill);
	string UserSelectSkill(string skill);
	string FindMaxedSpec(string skill);
	void SetLevel(string skill, int level);
	void SetLevel(int index, int level);
	void AddUpgrade(string skill, int level);
	void AddUpgrade(string skill, string spec, int level);
	void LoadSpeciesTraits();
	void LoadEliteSkills();
	void LoadSpeciesSkills();
	void VortaBonus();
	vector<string> FindSampleSpec(string skill);
	string RemoveComma(string statement);
	
	vector <int> dice;
	int health;
	int courage;
	int renown;
	int rank;
	int defense;
	string favAttribute2;
	string favAttribute1;
	string favReaction;
	string profession;
	string elite;
	string species;
	string age;
	string gender;

	struct Attributes
	{
	int score;
	int mod;
	}attributes[7];

	int reactions[4];

	vector <string> languages;
	vector <string> eliteProSkills;
	vector <string> tierList;
};

#endif //__CHARACTER_H_
