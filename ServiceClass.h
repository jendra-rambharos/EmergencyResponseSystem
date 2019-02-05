#pragma once


// ServiceClass dialog

class ServiceClass : public CDialog
{
	DECLARE_DYNAMIC(ServiceClass)

public:
	ServiceClass(CWnd* pParent = NULL);   // standard constructor
	virtual ~ServiceClass();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString enter_service;
	afx_msg void OnBnClickedOk();
};
