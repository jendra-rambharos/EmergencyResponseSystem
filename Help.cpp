// Help.cpp : implementation file
//

#include "stdafx.h"
#include "Emergency Response System.h"
#include "Help.h"
#include ".\help.h"


// Help dialog

IMPLEMENT_DYNAMIC(Help, CDialog)
Help::Help(CWnd* pParent /*=NULL*/)
	: CDialog(Help::IDD, pParent)
	, selected_help_item(_T(""))
	, hlep_display_string(_T(""))
{
}

Help::~Help()
{

}

void Help::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, help_list);
	DDX_CBString(pDX, IDC_COMBO1, selected_help_item);

	help_list.AddString("Selecting a Message Type");
	help_list.AddString("Choosing a Transmission Region");
	help_list.AddString("Choosing a Mail Server");
	help_list.AddString("Adding a Date Tag");
	help_list.AddString("Adding Supply Location Information");
	help_list.AddString("Adding Service Location Information");
	help_list.AddString("Sending the Final Message");
	help_list.AddString("Exiting the Program");
	help_list.AddString("Creating and Accessing Phone Number Database");
	help_list.AddString("Appending Evacuation Information to Message");

	DDX_Control(pDX, IDC_EDIT1, help_display_control);
	DDX_Text(pDX, IDC_EDIT1, hlep_display_string);
}


BEGIN_MESSAGE_MAP(Help, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// Help message handlers

void Help::OnBnClickedButton1()
{
	help_list.GetWindowText(selected_help_item);

	//::AfxMessageBox(selected_help_item);
	if (selected_help_item == "Selecting a Message Type")
	{
		hlep_display_string = "The alert buttons include the following:\r\n•	Severe Thunderstorm Alert\r\n•	Blizzard Alert\r\n•	Hail Storm Alert\r\n•	Hurricane Alert\r\n•	Earthquake Alert\r\n•	Flood Alert\r\n•	Tornado Alert\r\n•	Do Not Send Alert\r\n\r\nWhen a button is selected it will add the proper alert to the message being sent to the cellular phones \r\n(ex. Flood Alert is selected, message sent will be “Your area is under a Flood Alert”).  \r\n\r\nThe “Do Not Send Alert” button does not add any text to the message.	\r\n\r\nThe check buttons include the following;\r\n•	Supply Locations\r\n•	Service Locations\r\n\r\nWhen selected the message will append the text shown in the corresponding shaded windows.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Choosing a Transmission Region")
	{
		hlep_display_string = "Each region represents a cellular tower, and the phones connected to it.  You may select any number of regions and the cellular phones listed under those regions will receive the text message.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Choosing a Mail Server")
	{
		hlep_display_string = "This is the mail server used to send out the text messages.  You must select the mail server of the network your computer is located on (If unsure of your mail server contact your network administrator).  \r\nTo choose your mail server go into the “Options” menu, and select “Select Mail Server” This will bring down a list of frequently used servers.  If your server is listed select it, if not select “Server Not Listed”.  \r\nThe server chosen will now appear in the shaded box beneath “Selected Mail”.  If your server was not listed and “Server Not Listed” was selected a window will appear that allows you to enter your server manually.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Adding a Date Tag")
	{
		hlep_display_string = "The date selected is the date that is added to the text message being sent.  \r\nThis is by default set to the current date. ";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Adding Supply Location Information")
	{
		hlep_display_string = "This contains the data that will be added to the text message if the “Supply Location” box is checked.  To edit the information contained in the box click “Click Here to enter Supply Locations”.  A window will then open and allow you to add/modify the data.  When you are finished entering the data click “Ok” to close the window and get back to the main software interface.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Adding Service Location Information")
	{
		hlep_display_string = "This contains the data that will be added to the text message if the “Service Location” box is checked.  To edit the information contained in the box click “Click Here to enter Service Locations”.  A window will then open and allow you to add/modify the data.  When you are finished entering the data click “Ok” to close the window and get back to the main software interface.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Sending the Final Message")
	{
		hlep_display_string = "To send the completed message click “Send” located at the bottom center of the interface.  A window will open displaying the data sent in the message.";
		help_display_control.SetWindowText(hlep_display_string);
	}

	else if (selected_help_item == "Exiting the Program")
	{
		hlep_display_string = "To exit the program click “Exit” located on the bottom center of the interface, Under “File” menu select “Exit”, or click the “X” button on the top right of the window.";
		help_display_control.SetWindowText(hlep_display_string);
	}	

	else if (selected_help_item == "Creating and Accessing Phone Number Database")
	{
		hlep_display_string = "Phone numbers are accessed via text files. The phone numbers are divided into separate regions. These files can be created automatically by selecting the Create Information Directory item from the Options menu. This will create all of the files needed on the programs directory. \r\n\r\nIf you want to create and edit the files manually, the text files must be located in the directory where the program is located. The text files must be titled region1.txt, region2.txt, and so on until region 15. \r\n\r\nIn the text files, the numbers must be listed one number per line, with no spaces or dashes. Example (1234567890). After the last number, the last line must have the word END in all capital letters. The END must have it's own line. After the file is saved, the phone numbers for a specific region will receive the message when the check box for that region is clicked.";
		help_display_control.SetWindowText(hlep_display_string);
	}	

	else if (selected_help_item == "Appending Evacuation Information to Message")
	{
		hlep_display_string = "Evacuation routes are accessed via text files. The evacuation route files are divided into separate regions. These files can be created automatically by selecting the Create Information Directory item from the Options menu. This will create all of the files needed on the programs directory. \r\n\r\nIf you want to create and edit the files manually, the text files must be located in the directory where the program is located. The text files must be titled evac1.txt, evac2.txt, and so on until evac 15. \r\n\r\nThese files must have the entire evacuation route typed in one line. There must be no carriage returns. Appending of the evac routed to a specific region can be done by simply checking the Append Evacuation Route Data checkbox located on the right side of the main program window.";
		help_display_control.SetWindowText(hlep_display_string);
	}	

	// TODO: Add your control notification handler code here
}
