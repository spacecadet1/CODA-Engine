// DlgRetrieve.h : Declaration of the DlgRetrieve

#ifndef __DLGRETRIEVE_H_
#define __DLGRETRIEVE_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <atlapp.h>
#include <atlctrls.h>
#include <string>
#include <vector>
//#include <fstream>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
// DlgRetrieve
class DlgRetrieve : 
	public CDialogImpl<DlgRetrieve>
{
public:
	string GetResult();
	void SetItems(vector <string> & x);
	
	void AddSkillItems( string skill);
	void Set (string prompt, string id);
	void Set (string id);
	string prompt;
	vector <string> items;
	
	DlgRetrieve()
	{
		
	}

	~DlgRetrieve()
	{
	}

	enum { IDD = IDD_DLGRETRIEVE };

BEGIN_MSG_MAP(DlgRetrieve)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		//
		
		CenterWindow();
		
		CWindow p;
		
		p = GetDlgItem(IDC_PROMPT);
		p.SetWindowText(m_prompt.c_str());

		p = GetDlgItem(IDC_ID);
		p.SetWindowText(m_id.c_str());
		//fin.open("log.txt");

		
		
		
		
		AddSkillItems(m_id);
		AddItems();
		return 1;  // Let the system set the focus
	}

	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		//MessageBox("xxx");
		//fin
		if (CheckResult())
		{
			//fin<<"End on 83"<<endl;
			//MessageBox("xxx");
			items.clear();
			EndDialog(wID);
			return 0;
		}
		else
		{
			//fin<<"End on 91"<<endl;
			return 1;
		}
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		MessageBox("Please enter data and click OK");
		return 1;
	}
private:
	//ofstream fin;
	string result;
	void ClearComboBox();
	void Release();
	void AddItems();
	BOOL CheckResult();
	string m_prompt, m_id;
};

#endif //__DLGRETRIEVE_H_
