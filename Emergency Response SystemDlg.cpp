// Emergency Response SystemDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Emergency Response System.h"
#include "Emergency Response SystemDlg.h"
#include ".\emergency response Systemdlg.h"
#include "SupplyClass.h"
#include "ServiceClass.h"
#include "Password.h"
#include "Help.h"
#include "Manual_Server.h"
#include "directoryconfirm.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include ".\emergency response systemdlg.h"
#pragma comment(lib, "ws2_32.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#define WIN32_LEAN_AND_MEAN

#endif
using namespace std;

const VERSION_MAJOR = 1;
const VERSION_MINOR = 1;
#define CRLF "\r\n"

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CEmergencyResponseSystemDlg dialog



CEmergencyResponseSystemDlg::CEmergencyResponseSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmergencyResponseSystemDlg::IDD, pParent)
	, thunderstorm(false)
	, blizzard(false)
	, hail(false)
	, hurricane(0)
	, earthquake(false)
	, flood(false)
	, tornado(false)
	, no_alert(false)
	, disp_server(_T(""))
	, show_supply(_T(""))
	, show_service(_T(""))
	, supply_check(FALSE)
	, service_check(FALSE)
	, date(COleDateTime::GetCurrentTime())
	, regioncheck1(FALSE)
	, regioncheck2(FALSE)
	, regioncheck3(FALSE)
	, regioncheck4(FALSE)
	, regioncheck5(FALSE)
	, regioncheck6(FALSE)
	, regioncheck7(FALSE)
	, regioncheck8(FALSE)
	, regioncheck9(FALSE)
	, regioncheck10(FALSE)
	, regioncheck11(FALSE)
	, regioncheck12(FALSE)
	, regioncheck13(FALSE)
	, regioncheck14(FALSE)
	, regioncheck15(FALSE)
	, evac_check(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CEmergencyResponseSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISP_SERVER, disp_server);
	DDX_Text(pDX, IDC_DISP_MESSAGE, show_supply);
	DDX_Text(pDX, IDC_DISP_MESSAGE2, show_service);
	DDX_Check(pDX, IDC_SUPPLY_LOC, supply_check);
	DDX_Check(pDX, IDC_SERVICE_LOC, service_check);
	DDX_Control(pDX, IDC_DISP_MESSAGE, supply_control);
	DDX_Control(pDX, IDC_DISP_MESSAGE2, service_control);
	DDX_Control(pDX, IDC_DISP_SERVER, server_control);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, date_control);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, date);
	DDX_Check(pDX, IDC_CHECK1, regioncheck1);
	DDX_Check(pDX, IDC_CHECK2, regioncheck2);
	DDX_Check(pDX, IDC_CHECK3, regioncheck3);
	DDX_Check(pDX, IDC_CHECK4, regioncheck4);
	DDX_Check(pDX, IDC_CHECK5, regioncheck5);
	DDX_Check(pDX, IDC_CHECK6, regioncheck6);
	DDX_Check(pDX, IDC_CHECK7, regioncheck7);
	DDX_Check(pDX, IDC_CHECK8, regioncheck8);
	DDX_Check(pDX, IDC_CHECK9, regioncheck9);
	DDX_Check(pDX, IDC_CHECK10, regioncheck10);
	DDX_Check(pDX, IDC_CHECK11, regioncheck11);
	DDX_Check(pDX, IDC_CHECK12, regioncheck12);
	DDX_Check(pDX, IDC_CHECK13, regioncheck13);
	DDX_Check(pDX, IDC_CHECK14, regioncheck14);
	DDX_Check(pDX, IDC_CHECK15, regioncheck15);
	DDX_Check(pDX, IDC_CHECK16, evac_check);
}

BEGIN_MESSAGE_MAP(CEmergencyResponseSystemDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_TC_ALERT, OnBnClickedTcAlert)
	ON_BN_CLICKED(IDC_BLIZZ_ALERT, OnBnClickedBlizzAlert)
	ON_BN_CLICKED(IDC_HAIL_ALERT, OnBnClickedHailAlert)
	ON_BN_CLICKED(IDC_HURR_ALERT, OnBnClickedHurrAlert)
	ON_BN_CLICKED(IDC_EQ_ALERT, OnBnClickedEqAlert)
	ON_BN_CLICKED(IDC_FLOOD_ALERT, OnBnClickedFloodAlert)
	ON_BN_CLICKED(IDC_TORNADO_ALERT, OnBnClickedTornadoAlert)
	ON_BN_CLICKED(IDC_SEND_MESSAGE, OnBnClickedSendMessage)
	ON_BN_CLICKED(IDC_RESET, OnBnClickedReset)
	ON_BN_CLICKED(IDC_TORNADO_ALERT2, OnBnClickedTornadoAlert2)
	ON_COMMAND(ID_SELECTMAILSERVER_SMTP32779, OnSelectmailserverRR)
	ON_COMMAND(ID_SELECTMAILSERVER_PEGASUS, OnSelectmailserverPegasus)
	ON_COMMAND(ID_SELECTMAILSERVER_SMTP, OnSelectmailserverEarthlink)
	ON_COMMAND(ID_SELECTMAILSERVER_SMTP2, OnSelectmailserverATT)
	ON_COMMAND(ID_SELECTMAILSERVER_MAIL, OnSelectmailserverMail)
	ON_COMMAND(ID_SELECTMAILSERVER_MAIL32781, OnSelectmailserverBellSouth)
	ON_COMMAND(ID_SELECTMAILSERVER_SMTP32782, OnSelectmailserververizon)
	ON_COMMAND(ID_SELECTMAILSERVER_SMTP32783, OnSelectmailserveryahoo)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_COMMAND(ID_ABOUT_ABOUTEMS, OnAboutAboutems)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_ABOUT_HELP, OnAboutHelp)
	ON_COMMAND(ID_SELECTMAILSERVER_SERVERNOTLISTED, OnSelectmailserverServernotlisted)
	ON_COMMAND(ID_OPTIONS_CREATEREGIONALINFORMATIONDIRECTORIES, OnOptionsCreateregionalinformationdirectories)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
END_MESSAGE_MAP()


// CEmergencyResponseSystemDlg message handlers

BOOL CEmergencyResponseSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	///////////////////////////////////////////////
	//Checks the bool variable of the password class. if the password
	//checks out wrong , the bool variable is set to false and the cancel 
	//function is called
	Password get_open;
	get_open.DoModal();
	if(get_open.open_main_dialog == false)
	{
		OnCancel();
	}	
	/////////////////////////////////////////////////////////////////////
	//Initialize the user selected server to the server retrieval message
	user_server = "Select server from Options Menu";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
	/////////////////////////////////////////////////////////////////////

	return TRUE;
}

void CEmergencyResponseSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEmergencyResponseSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEmergencyResponseSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Check(int iStatus, char *szFunction)
{
  if((iStatus != SOCKET_ERROR) && (iStatus))
    return;
 
  cerr << "Error during call to " << szFunction << ": " << iStatus << " - " << GetLastError() << endl;
}
///////////////////////////////////////////////////////
//Radio buttons to select the type of weather hazard
void CEmergencyResponseSystemDlg::OnBnClickedTcAlert()
{
	thunderstorm = true;
	blizzard = false;
	hail = false;
	hurricane = false;
	earthquake = false;
	flood = false;
	tornado = false;
	no_alert = false;
	alert = "Your area is under a Severe Thunderstorm Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedBlizzAlert()
{
	thunderstorm = false;
	blizzard = true;
	hail = false;
	hurricane = false;
	earthquake = false;
	flood = false;
	tornado = false;
	no_alert = false;
	alert = "Your area is under a Blizzard Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedHailAlert()
{
	thunderstorm = false;
	blizzard = false;
	hail = true;
	hurricane = false;
	earthquake = false;
	flood = false;
	tornado = false;
	no_alert = false;
	alert = "Your area is under a Severe Hailstorm Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedHurrAlert()
{
	thunderstorm = false;
	blizzard = false;
	hail = false;
	hurricane = true;
	earthquake = false;
	flood = false;
	tornado = false;
	no_alert = false;
	alert = "Your area is under a Hurricane Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedEqAlert()
{
	thunderstorm = false;
	blizzard = false;
	hail = false;
	hurricane = false;
	earthquake = true;
	flood = false;
	tornado = false;
	no_alert = false;
	alert = "Your area is under an Earthquake Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedFloodAlert()
{
	thunderstorm = false;
	blizzard = false;
	hail = false;
	hurricane = false;
	earthquake = false;
	flood = true;
	tornado = false;
	no_alert = false;
	alert = "Your area is under a Flood Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedTornadoAlert()
{
	thunderstorm = false;
	blizzard = false;
	hail = false;
	hurricane = false;
	earthquake = false;
	flood = false;
	tornado = true;
	no_alert = false;
	alert = "Your area is under a Tornado Alert!";
}

void CEmergencyResponseSystemDlg::OnBnClickedTornadoAlert2()
{
	no_alert = true;
	thunderstorm = false;
	blizzard = false;
	hail = false;
	hurricane = false;
	earthquake = false;
	flood = false;
	tornado = false;
	alert = " ";
}

void CEmergencyResponseSystemDlg::Meat()
{
	CString date_disp;
	date_control.GetWindowText(date_disp);
	UpdateData(true);
	CString sender_address = "Emergency_Response@Communications.Net";
	CString user_selected_server = user_server;
	CString send_message;

	

	////////////////////////////////////////////////////////////////////////////////
	//Creates the message based on the user's message selections
	if (evac_check == 1)
	{
		if (service_check == 1 && supply_check == 1)
		{
			send_message.Format(_T("%s \n%s \n%s \n%s \nTransmission Date : %s" ), alert, show_supply, show_service, evacroute, date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (service_check == 1)
		{
			send_message.Format(_T("%s\n%s \n%s\nTransmission Date : %s" ), alert, show_service, evacroute,date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (supply_check == 1)
		{
			send_message.Format(_T("%s\n%s \n%s\nTransmission Date : %s" ), alert, show_supply, evacroute,date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (supply_check == 0 && service_check == 0)
		{
			send_message.Format(_T("%s\n%s\nTransmission Date : %s"), alert, evacroute,date_disp);
			//::AfxMessageBox(send_message);
		}	
	}

	else if (evac_check == 0)
	{
		if (service_check == 1 && supply_check == 1)
		{
			send_message.Format(_T("%s \n%s \n%s \nTransmission Date : %s" ), alert, show_supply, show_service, date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (service_check == 1)
		{
			send_message.Format(_T("%s\n%s\nTransmission Date : %s" ), alert, show_service, date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (supply_check == 1)
		{
			send_message.Format(_T("%s\n%s\nTransmission Date : %s" ), alert, show_supply, date_disp);
			//::AfxMessageBox(send_message);
		}

		else if (supply_check == 0 && service_check == 0)
		{
			send_message.Format(_T("%s\nTransmission Date : %s"), alert, date_disp);
			//::AfxMessageBox(send_message);
		}	
	}
	
	///////////////////////////////////////////////////////////////////////////////////
	//Checks if the fields are selected or left blank

	if(user_selected_server == "Select server from Options Menu")
	{
		AfxMessageBox("No Server Has Been Chosen.\nPlease Select a Server from the\nOptions Menu.");
		no_selected_server = true ;
		return;
	}
	else
		no_selected_server = false ;

	if (alert.IsEmpty())
	{
		AfxMessageBox("No Alert Has Been Chosen");
		no_selected_alert = true;
		return;
	}
	else
		no_selected_alert = false ;

	////////////////////////////////////////////////////////////////////////////////////////////////
	//Once all information is valid, prepare message to be sent

	if (no_selected_server == false && no_selected_alert == false)
	{
		int         iProtocolPort        = 0;
		CString     szLine				 = send_message;
		char        szBuffer[4096]       = "";
		char        szMsgLine[255]       = "";
		SOCKET      hServer;
		WSADATA     WSData;
		LPHOSTENT   lpHostEntry;
		LPSERVENT   lpServEntry;
		SOCKADDR_IN SockAddr;

		badserver1 = false;
		badserver2 = false;

		// Attempt to intialize WinSock (1.1 or later)
		if(WSAStartup(MAKEWORD(VERSION_MAJOR, VERSION_MINOR), &WSData))
		{
			CString message0;
			message0.Format(_T("Cannot find Winsock v %s . %s or later!" ), VERSION_MAJOR, VERSION_MINOR);
			AfxMessageBox(message0);
			badserver1 = true;
			nomessageflag = true;
			return;
		}

		// Lookup email server's IP address.
		lpHostEntry = gethostbyname(user_server);
		if(!lpHostEntry)
		{
			CString message1;
			message1.Format(_T("Cannot find SMTP mail server %s"), user_server);
			AfxMessageBox(message1);
			badserver2 = true;
			nomessageflag = true;
			return;
		}

		// Create a TCP/IP socket, no specific protocol
		hServer = socket(PF_INET, SOCK_STREAM, 0);
		if(hServer == INVALID_SOCKET)
		{
			CString message2;
			message2.Format(_T("Cannot open mail server socket"));
			AfxMessageBox(message2);
			badserver2 = true;
			nomessageflag = true;
			return;
		}

		// Get the mail service port
		lpServEntry = getservbyname("mail", 0);

		// Use the SMTP default port if no other port is specified
		if(!lpServEntry)
			iProtocolPort = htons(IPPORT_SMTP);
		else
			iProtocolPort = lpServEntry->s_port;

		// Setup a Socket Address structure
		SockAddr.sin_family = AF_INET;
		SockAddr.sin_port   = iProtocolPort;
		SockAddr.sin_addr   = *((LPIN_ADDR)*lpHostEntry->h_addr_list);

		// Connect the Socket
		if(connect(hServer, (PSOCKADDR) &SockAddr, sizeof(SockAddr)))
		{
			CString message3;
			message3.Format(_T("Error connecting to Server socket"));
			AfxMessageBox(message3);
			badserver1 = true;
			nomessageflag = true;
			return;
		}

		// Receive initial response from SMTP server
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() Reply");

		// Send HELO server.com
		sprintf(szMsgLine, "HELO %s%s", user_selected_server, CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() HELO");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() HELO");

		// Send MAIL FROM: <sender@mydomain.com>
		sprintf(szMsgLine, "MAIL FROM:<%s>%s", sender_address, CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() MAIL FROM");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() MAIL FROM");

		// Send RCPT TO: <receiver@domain.com>
		sprintf(szMsgLine, "RCPT TO:<%s>%s", recipient_address, CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() RCPT TO");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() RCPT TO");

		// Send DATA
		sprintf(szMsgLine, "DATA%s", CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() DATA");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() DATA");
		sprintf(szMsgLine, "%s%s", szLine, CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() message-line");

		// Send blank line and a period
		sprintf(szMsgLine, "%s.%s", CRLF, CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() end-message");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() end-message");

		// Send QUIT
		sprintf(szMsgLine, "QUIT%s", CRLF);
		Check(send(hServer, szMsgLine, (int)strlen(szMsgLine), 0), "send() QUIT");
		Check(recv(hServer, szBuffer, sizeof(szBuffer), 0), "recv() QUIT");

		// Close server socket and prepare to exit.
		closesocket(hServer);

		WSACleanup();
	}
}
///////////////////////////////////////////////////////////////////////////////////
void CEmergencyResponseSystemDlg::OnBnClickedSendMessage()
{
	CString number;
	CString provider_list[7] = {"@mmode.com", "@tmomail.net", "@vmobl.com", "@cingularme.com", "@messaging.sprintpcs.com", "@vtext.com", "@messaging.nextel.com"};
	UpdateData(true);
	int limiter = 0;
	nomessageflag = false;
	
	
	while ((CString)str != "END")
	{
		limiter++;
		if(limiter > 5)
			return;

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck1 == 1)
		{
			fstream file_op("evac1.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			file_op.close();
			evacroute = (CString)strevac;

			pFile = fopen ("region1.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
					else if((badserver1 || badserver2) == true)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
				else if((badserver1 || badserver2) == true)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck2 == 1)
		{
			fstream file_op("evac2.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region2.txt", "r");
			
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
					else if((badserver1 || badserver2) == true)
					{
						break;
					}
				}
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
				else if((badserver1 || badserver2) == true)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck3 == 1)
		{
			fstream file_op("evac3.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region3.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck4 == 1)
		{
			fstream file_op("evac4.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region4.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck5 == 1)
		{
			fstream file_op("evac5.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region5.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck6 == 1)
		{
			fstream file_op("evac6.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region6.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck7 == 1)
		{
			fstream file_op("evac7.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region7.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck8 == 1)
		{
			fstream file_op("evac8.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region8.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck9 == 1)
		{
			fstream file_op("evac9.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region9.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck10 == 1)
		{
			fstream file_op("evac10.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region10.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck11 == 1)
		{
			fstream file_op("evac11.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region11.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck12 == 1)
		{
			fstream file_op("evac12.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region12.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck13 == 1)
		{
			fstream file_op("evac13.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region13.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck14 == 1)
		{
			fstream file_op("evac14.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region14.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
			str[0] = '\0';
		}

		if((badserver1 || badserver2) == true)
			return;

		if (regioncheck15 == 1)
		{
			fstream file_op("evac15.txt",ios::in);
			file_op.getline(strevac, sizeof(strevac), '\n');
			 
			file_op.close();
			evacroute = (CString)strevac;

            pFile = fopen ("region15.txt", "r");
			while (fscanf (pFile, "%s", &str), (CString)str != "END")
			{
				number = (CString)str;

				for (int i=0; i<6; i++)
				{	
					recipient_address.Format(_T("%s%s" ), number, provider_list[i]);
					Meat();

					if(no_selected_server)
					{
						break;
					}
					else if(no_selected_alert)
					{
						break;
					}
				}
				
				if(no_selected_server)
				{
					break;
				}
				else if(no_selected_alert)
				{
					break;
				}
			}
			fclose(pFile);
		}
		str[0] = 'E';
		str[1] = 'N';
		str[2] = 'D';

	}

	if(!(no_selected_server||no_selected_alert||badserver1||badserver2))
	{
		if(nomessageflag == true)
		{
			AfxMessageBox("There was a Server error, Please check your Server selection");
			return;
		}
		if(nomessageflag == false)
		{
			AfxMessageBox("Message Transmission \nSuccessful!");
		}
	}
	str[0] = '\0';
	
	return;
}
///////////////////////////////////////////////////////////////
//Terminate button
void CEmergencyResponseSystemDlg::OnBnClickedReset()
{
	OnCancel();
}

////////////////////////////////////////////////////////////////
//assign functionality to menu selection from menu item
void CEmergencyResponseSystemDlg::OnSelectmailserverRR()
{
	user_server = "smtp-server.cfl.rr.com";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverPegasus()
{
	user_server = "pegasus.cc.ucf.edu";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverEarthlink()
{
	user_server = "smtp.earthlink.net";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverATT()
{
	user_server = "smtp1.attglobal.net";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverMail()
{
	user_server = "mail.adelphia.net";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverBellSouth()
{
	user_server = "mail.bellsouth.net";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserververizon()
{
	user_server = "smtp.verizon.net";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserveryahoo()
{
	user_server = "smtp.mail.yahoo.com";
	disp_server.SetString(user_server);
	server_control.SetWindowText(user_server);
}
void CEmergencyResponseSystemDlg::OnSelectmailserverServernotlisted()
{
	Manual_Server get_server;

	if(get_server.DoModal() == IDOK)
		{
			user_server = get_server.text_server;
			server_control.SetWindowText(user_server);
		}	
}
void CEmergencyResponseSystemDlg::OnAboutAboutems()
{
	CAboutDlg get_about;
	get_about.DoModal();
}

void CEmergencyResponseSystemDlg::OnAboutHelp()
{
	Help get_help;
	get_help.DoModal();
}

void CEmergencyResponseSystemDlg::OnFileExit()
{
	OnCancel();
}
////////////////////////////////////////////////////////////////////////
//Buttons for entering supply and service locations
void CEmergencyResponseSystemDlg::OnBnClickedButton1()
{
	SupplyClass get_supply;

	if(get_supply.DoModal() == IDOK)
		{
			show_supply = get_supply.enter_supply;
			supply_control.SetWindowText(show_supply);
		}
}

void CEmergencyResponseSystemDlg::OnBnClickedButton2()
{
	ServiceClass get_service;

	if(get_service.DoModal() == IDOK)
		{
			show_service = get_service.enter_service;
			service_control.SetWindowText(show_service);
		}
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void CEmergencyResponseSystemDlg::OnOptionsCreateregionalinformationdirectories()
{
	
	directoryconfirm getbool;
	getbool.DoModal();
	if(getbool.confirm_create == true)
	{
		pFile = fopen ("region1.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region2.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region3.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region4.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region5.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region6.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region7.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region8.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region9.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region10.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region11.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region12.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region13.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region14.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("region15.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);


		pFile = fopen ("evac1.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac2.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac3.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac4.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac5.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac6.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac7.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac8.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac9.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac10.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac11.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac12.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac13.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac14.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);
		pFile = fopen ("evac15.txt","w+");
		fprintf (pFile, "%s", "\r\nEND");
		fclose (pFile);

		::AfxMessageBox("DataBase Creation Completed. \r\nFiles are Located in the Program's Home Directory");
	}

	else
		return;

}

void CEmergencyResponseSystemDlg::OnBnClickedCheck1()
{



	// TODO: Add your control notification handler code here
}

