#pragma once
#include "afxwin.h"


// Password dialog

class Password : public CDialog
{
	DECLARE_DYNAMIC(Password)

public:
	Password(CWnd* pParent = NULL);   // standard constructor
	virtual ~Password();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString entered_password;
	CEdit entered_password_control;
	int times_tried;
	bool open_main_dialog;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
