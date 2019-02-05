#pragma once


// SupplyClass dialog

class SupplyClass : public CDialog
{
	DECLARE_DYNAMIC(SupplyClass)

public:
	SupplyClass(CWnd* pParent = NULL);   // standard constructor
	virtual ~SupplyClass();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString enter_supply;
	afx_msg void OnBnClickedOk();
};
