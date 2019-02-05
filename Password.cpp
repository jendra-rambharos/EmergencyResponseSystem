// Password.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "Password.h"
#include ".\password.h"


// Password dialog

IMPLEMENT_DYNAMIC(Password, CDialog)
Password::Password(CWnd* pParent /*=NULL*/)
	: CDialog(Password::IDD, pParent)
	, entered_password(_T(""))
{
	times_tried = 0;
}

Password::~Password()
{
}

void Password::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, entered_password);
	DDX_Control(pDX, IDC_EDIT1, entered_password_control);
}


BEGIN_MESSAGE_MAP(Password, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// Password message handlers

void Password::OnBnClickedOk()
{

	CString set_password = "eel4884";
	entered_password_control.GetWindowText(entered_password);
	
	if (entered_password == set_password)
	{
		//::AfxMessageBox("Password Accepted");
		open_main_dialog = true;
		OnOK();
	}

	else
	{
		::AfxMessageBox("Password Invalid");
		open_main_dialog = false;
		OnCancel();
	}

	
}

void Password::OnBnClickedCancel()
{
	open_main_dialog = false;
	OnCancel();

}
