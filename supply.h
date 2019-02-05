#pragma once


// supply dialog

class supply : public CDHtmlDialog
{
	DECLARE_DYNCREATE(supply)

public:
	supply(CWnd* pParent = NULL);   // standard constructor
	virtual ~supply();
// Overrides
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Dialog Data
	enum { IDD = IDD_DIALOG1, IDH = IDR_HTML_SUPPLY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};
