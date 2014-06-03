// DlgMessage.h : Declaration of the CDlgMessage

#ifndef __DLGMESSAGE_H_
#define __DLGMESSAGE_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// DlgMessage
class DlgMessage : 
	public CDialogImpl<DlgMessage>
{
public:
	void SetInformation(string str);
	void SetWarning(string str);
	DlgMessage()
	{
	}

	~DlgMessage()
	{
	}

	enum { IDD = IDD_DLGMESSAGE };

BEGIN_MSG_MAP(DlgMessage)
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
		if(flag)
		{
			CWindow cc;
			cc = GetDlgItem(IDC_RED);
			cc.ShowWindow(1);
			cc = GetDlgItem(IDC_MESSAGE);
			cc.SetWindowText(m_str.c_str());

		}
		else
		{
			CWindow cc;
			cc = GetDlgItem(IDC_BLUE);
			cc.ShowWindow(1);
			cc = GetDlgItem(IDC_MESSAGE);
			cc.SetWindowText(m_str.c_str());
		}
		return 1;  // Let the system set the focus
	}

	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}
private:
	BOOL flag;
	string m_str;
};

#endif //__DLGMESSAGE_H_
