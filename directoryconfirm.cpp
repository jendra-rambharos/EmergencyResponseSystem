// directoryconfirm.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "directoryconfirm.h"
#include ".\directoryconfirm.h"


// directoryconfirm dialog

IMPLEMENT_DYNAMIC(directoryconfirm, CDialog)
directoryconfirm::directoryconfirm(CWnd* pParent /*=NULL*/)
	: CDialog(directoryconfirm::IDD, pParent)
{
}

directoryconfirm::~directoryconfirm()
{
}

void directoryconfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(directoryconfirm, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// directoryconfirm message handlers

void directoryconfirm::OnBnClickedOk()
{
	confirm_create = true;
	// TODO: Add your control notification handler code here
	OnOK();
}

void directoryconfirm::OnBnClickedCancel()
{
	confirm_create = false;
	// TODO: Add your control notification handler code here
	OnOK();
}
