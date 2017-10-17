#include "dlgConnectionSettings.h"
#include "connectionManager/ConnectionManager.h"
#include <wx/msgdlg.h>
#include <vector>
#include "lms8suiteEvents.h"
using namespace std;

dlgConnectionSettings::dlgConnectionSettings( wxWindow* parent )
	: dlgConnectionSettings_view( parent )
{
	lms8port = nullptr;
//	streamBrdPort = nullptr;
}

/*
void dlgConnectionSettings::SetConnectionManagers(ConnectionManager* lms8ctr, ConnectionManager* streamBrdctr)
{
	lms8port = lms8ctr;
//	streamBrdPort = streamBrdctr;
}
*/

void dlgConnectionSettings::SetConnectionManager(ConnectionManager* lms8ctr)
{
	lms8port = lms8ctr;
}

void dlgConnectionSettings::GetDeviceList( wxInitDialogEvent& event )
{
	mListLMS8ports->Clear();
	if (lms8port)
	{
		lms8port->RefreshDeviceList();
		vector<string> deviceNames = lms8port->GetDeviceList();
		for (unsigned i = 0; i<deviceNames.size(); ++i)
			mListLMS8ports->Append(deviceNames[i]);
		int openedIndex = lms8port->GetOpenedIndex();
        if (openedIndex >= 0 && openedIndex < mListLMS8ports->GetCount())
			mListLMS8ports->SetSelection(openedIndex);
	}
	else
		mListLMS8ports->Append("Connection Manager not initialized");
}

void dlgConnectionSettings::OnConnect( wxCommandEvent& event )
{
	if(lms8port)
	{
        if(mListLMS8ports->GetSelection() != wxNOT_FOUND)
        {
            if (lms8port->Open(mListLMS8ports->GetSelection()) != IConnection::SUCCESS)
                wxMessageBox("Failed to open LMS8 control device", "Error", wxICON_STOP);
            else
            {
                wxCommandEvent evt;
                evt.SetInt(mListLMS8ports->GetSelection());
                evt.SetEventType(CONTROL_PORT_CONNECTED);
                evt.SetString(mListLMS8ports->GetString(event.GetInt()));
                if(GetParent())
                    wxPostEvent(GetParent(), evt);
            }
        }
	}
    Destroy();
}

void dlgConnectionSettings::OnCancel( wxCommandEvent& event )
{
	Destroy();
}

void dlgConnectionSettings::OnDisconnect( wxCommandEvent& event )
{
	if (lms8port)
	{
		lms8port->Close();
        wxCommandEvent evt;
        evt.SetEventType(CONTROL_PORT_DISCONNECTED);
        if(GetParent())
            wxPostEvent(GetParent(), evt);
	}
	mListLMS8ports->SetSelection(-1);
}
