#pragma once


// directoryconfirm dialog

class directoryconfirm : public CDialog
{
	DECLARE_DYNAMIC(directoryconfirm)

public:
	directoryconfirm(CWnd* pParent = NULL);   // standard constructor
	virtual ~directoryconfirm();

// Dialog Data
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	bool confirm_create;
};
