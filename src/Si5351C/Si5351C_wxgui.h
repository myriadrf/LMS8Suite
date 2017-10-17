#ifndef __Si5351C_wxgui__
#define __Si5351C_wxgui__

#include "Si5351C_wxgui_view.h"

class Si5351C;

/** Implementing Si5351C_wxgui */
class Si5351C_wxgui : public Si5351C_wxgui_view
{
protected:
	// Handlers for Si5351C_wxgui events.

public:
	/** Constructor */
	Si5351C_wxgui(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString &title = _(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int styles = wxDEFAULT_FRAME_STYLE, wxString idname = "");

	void Initialize(Si5351C* pModule);

protected:

private:
	Si5351C *m_pModule;
	//(*Handlers(Si5351C_wxgui)
	void OnbtnLoadFileClick(wxCommandEvent& event);
	void OnbtnConfigureClockClick(wxCommandEvent& event);
	void OnbtnResetToDefaultsClick(wxCommandEvent& event);
	void OnbtnReadStatusClick(wxCommandEvent& event);
	void OnbtnClearStatusClick(wxCommandEvent& event);
};

#endif // __Si5351C_wxgui__