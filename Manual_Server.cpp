// Manual_Server.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "Manual_Server.h"
#include ".\manual_server.h"


// Manual_Server dialog

IMPLEMENT_DYNAMIC(Manual_Server, CDialog)
Manual_Server::Manual_Server(CWnd* pParent /*=NULL*/)
	: CDialog(Manual_Server::IDD, pParent)
	, text_server(_T(""))
{
}

Manual_Server::~Manual_Server()
{
}

void Manual_Server::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text_server_control);
	DDX_Text(pDX, IDC_EDIT1, text_server);
}


BEGIN_MESSAGE_MAP(Manual_Server, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// Manual_Server message handlers

void Manual_Server::OnBnClickedOk()
{
	UpdateData(true);
	OnOK();
}
