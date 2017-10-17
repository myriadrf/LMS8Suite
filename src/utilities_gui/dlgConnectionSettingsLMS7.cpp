#include "dlgConnectionSettingsLMS7.h"
#include "connectionManager/ConnectionManager.h"
#include <wx/msgdlg.h>
#include <vector>
#include "lms8suiteEvents.h"
using namespace std;

dlgConnectionSettingsLMS7::dlgConnectionSettingsLMS7( wxWindow* parent )
	: dlgConnectionSettingsLMS7_view( parent )
{
	lms7port = nullptr;
//	streamBrdPort = nullptr;
}

/*
void dlgConnectionSettingsLMS7::SetConnectionManagers(ConnectionManager* lms7ctr, ConnectionManager* streamBrdctr)
{
	lms7port = lms7ctr;
//	streamBrdPort = streamBrdctr;
}
*/

void dlgConnectionSettingsLMS7::SetConnectionManager(ConnectionManager* lms7ctr)
{
	lms7port = lms7ctr;
}

void dlgConnectionSettingsLMS7::GetDeviceList( wxInitDialogEvent& event )
{
	mListLMS7ports->Clear();
	if (lms7port)
	{
		lms7port->RefreshDeviceList();
		vector<string> deviceNames = lms7port->GetDeviceList();
		for (unsigned i = 0; i<deviceNames.size(); ++i)
			mListLMS7ports->Append(deviceNames[i]);
		int openedIndex = lms7port->GetOpenedIndex();
        if (openedIndex >= 0 && openedIndex < mListLMS7ports->GetCount())
			mListLMS7ports->SetSelection(openedIndex);
	}
	else
		mListLMS7ports->Append("Connection Manager not initialized");
}

void dlgConnectionSettingsLMS7::OnConnect( wxCommandEvent& event )
{
	if(lms7port)
	{
        if(mListLMS7ports->GetSelection() != wxNOT_FOUND)
        {
            if (lms7port->Open(mListLMS7ports->GetSelection()) != IConnection::SUCCESS)
                wxMessageBox("Failed to open LMS7 control device", "Error", wxICON_STOP);
            else
            {
                wxCommandEvent evt;
                evt.SetInt(mListLMS7ports->GetSelection());
                evt.SetEventType(LMS7_CONTROL_PORT_CONNECTED);
                evt.SetString(mListLMS7ports->GetString(event.GetInt()));
                if(GetParent())
                    wxPostEvent(GetParent(), evt);
            }
        }
	}
    Destroy();
}

void dlgConnectionSettingsLMS7::OnCancel( wxCommandEvent& event )
{
	Destroy();
}

void dlgConnectionSettingsLMS7::OnDisconnect( wxCommandEvent& event )
{
	if (lms7port)
	{
		lms7port->Close();
        wxCommandEvent evt;
        evt.SetEventType(CONTROL_PORT_DISCONNECTED);
        if(GetParent())
            wxPostEvent(GetParent(), evt);
	}
	mListLMS7ports->SetSelection(-1);
}
