#pragma once
#include "afxwin.h"


// Help dialog

class Help : public CDialog
{
	DECLARE_DYNAMIC(Help)

public:
	Help(CWnd* pParent = NULL);   // standard constructor
	virtual ~Help();

// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox help_list;
	CString selected_help_item;
	CEdit help_display_control;
	CString hlep_display_string;
	afx_msg void OnBnClickedButton1();
};
