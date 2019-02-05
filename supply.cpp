// supply.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "supply.h"


// supply dialog

IMPLEMENT_DYNCREATE(supply, CDHtmlDialog)

supply::supply(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(supply::IDD, supply::IDH, pParent)
{
}

supply::~supply()
{
}

void supply::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BOOL supply::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(supply, CDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(supply)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// supply message handlers

HRESULT supply::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;  // return TRUE  unless you set the focus to a control
}

HRESULT supply::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;  // return TRUE  unless you set the focus to a control
}
