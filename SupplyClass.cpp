// SupplyClass.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "SupplyClass.h"
#include ".\supplyclass.h"


// SupplyClass dialog

IMPLEMENT_DYNAMIC(SupplyClass, CDialog)
SupplyClass::SupplyClass(CWnd* pParent /*=NULL*/)
	: CDialog(SupplyClass::IDD, pParent)
	, enter_supply(_T(""))
{
}

SupplyClass::~SupplyClass()
{
}

void SupplyClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUPPLY, enter_supply);
}


BEGIN_MESSAGE_MAP(SupplyClass, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// SupplyClass message handlers

void SupplyClass::OnBnClickedOk()
{
	UpdateData(true);
	OnOK();
}
