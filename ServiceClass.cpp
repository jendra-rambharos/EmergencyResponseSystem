// ServiceClass.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "ServiceClass.h"
#include ".\serviceclass.h"


// ServiceClass dialog

IMPLEMENT_DYNAMIC(ServiceClass, CDialog)
ServiceClass::ServiceClass(CWnd* pParent /*=NULL*/)
	: CDialog(ServiceClass::IDD, pParent)
	, enter_service(_T(""))
{
}

ServiceClass::~ServiceClass()
{
}

void ServiceClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERVICE, enter_service);
}


BEGIN_MESSAGE_MAP(ServiceClass, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// ServiceClass message handlers

void ServiceClass::OnBnClickedOk()
{
	UpdateData(true);
	OnOK();
}
