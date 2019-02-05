#pragma once
#include "afxwin.h"


// Manual_Server dialog

class Manual_Server : public CDialog
{
	DECLARE_DYNAMIC(Manual_Server)

public:
	Manual_Server(CWnd* pParent = NULL);   // standard constructor
	virtual ~Manual_Server();

// Dialog Data
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit text_server_control;
	CString text_server;
	afx_msg void OnBnClickedOk();
};
