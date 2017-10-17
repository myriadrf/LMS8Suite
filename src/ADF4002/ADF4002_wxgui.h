#ifndef __ADS4002_wxgui__
#define __ADS4002_wxgui__

#include "ADF4002_wxgui_view.h"

class ADF4002;
class LMScomms;


/** Implementing ADF4002_wxgui */
class ADF4002_wxgui : public ADF4002_wxgui_view
{
protected:
	// Handlers for dlgConnectionSettings events.
//	void GetDeviceList(wxInitDialogEvent& event);

public:
	/** Constructor */
	ADF4002_wxgui(wxWindow* parent);
	ADF4002_wxgui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString &title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int styles = wxDEFAULT_FRAME_STYLE, wxString idname = "");
	//// end generated class members
//	void SetConnectionManager(ConnectionManager* lms8ctr);

	void Initialize(ADF4002* pModule, LMScomms* pSerPort);

	void SetGuiDefaults();

	void OnbtnCalcSendClick(wxCommandEvent& event);
	void OnbtnUploadClick(wxCommandEvent& event);


protected:
//	ConnectionManager* lms8port;
	//		ConnectionManager* streamBrdPort;

private:
	ADF4002* m_pModule;
	LMScomms* serPort;
};

#endif // __ADS4002_wxgui__

