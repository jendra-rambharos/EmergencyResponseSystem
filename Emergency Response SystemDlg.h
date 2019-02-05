// Emergency Response SystemDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "atlcomtime.h"

// CEmergencyResponseSystemDlg dialog
class CEmergencyResponseSystemDlg : public CDialog
{
// Construction
public:
	CEmergencyResponseSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_EMERGENCYRESPONSESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	bool thunderstorm;
	bool blizzard;
	bool hail;
	bool hurricane;
	bool earthquake;
	bool flood;
	bool tornado;
	bool no_alert;
	bool no_selected_alert;
	bool no_selected_server;
	bool badserver1;
	bool badserver2;
	bool nomessageflag;
	BOOL supply_check;
	BOOL service_check;
	BOOL regioncheck1;
	BOOL regioncheck2;
	BOOL regioncheck3;
	BOOL regioncheck4;
	BOOL regioncheck5;
	BOOL regioncheck6;
	BOOL regioncheck7;
	BOOL regioncheck8;
	BOOL regioncheck9;
	BOOL regioncheck10;
	BOOL regioncheck11;
	BOOL regioncheck12;
	BOOL regioncheck13;
	BOOL regioncheck14;
	BOOL regioncheck15;
	BOOL evac_check;
	CString alert;
	CString user_server;
	CString recipient_address;
	CString send_message;
	CString date_disp;
	CString user_selected_server;
	CString show_supply;	
	CString show_service;
	CString disp_server;
	CString evacroute;
	FILE * pFile;
	char str [10];
	char strevac [20000];

	CEdit supply_control;
	CEdit service_control;
	CEdit server_control;
	CDateTimeCtrl date_control;
	COleDateTime date;

	afx_msg void OnBnClickedTcAlert();
	afx_msg void OnBnClickedBlizzAlert();
	afx_msg void OnBnClickedHailAlert();
	afx_msg void OnBnClickedHurrAlert();
	afx_msg void OnBnClickedEqAlert();
	afx_msg void OnBnClickedFloodAlert();
	afx_msg void OnBnClickedTornadoAlert();
	afx_msg void OnBnClickedSendMessage();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedTornadoAlert2();
	afx_msg void OnSelectmailserverRR();
	afx_msg void OnSelectmailserverPegasus();
	afx_msg void OnSelectmailserverEarthlink();
	afx_msg void OnSelectmailserverATT();
	afx_msg void OnSelectmailserverMail();
	afx_msg void OnSelectmailserverBellSouth();
	afx_msg void OnSelectmailserververizon();
	afx_msg void OnSelectmailserveryahoo();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnAboutAboutems();
	afx_msg void OnFileExit();
	afx_msg void OnAboutHelp();
	afx_msg void OnSelectmailserverServernotlisted();
	void Meat();
	afx_msg void OnOptionsCreateregionalinformationdirectories();
	afx_msg void OnBnClickedCheck1();
};
