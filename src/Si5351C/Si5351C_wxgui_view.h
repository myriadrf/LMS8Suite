///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SI5351C_WXGUI_VIEW_H__
#define __SI5351C_WXGUI_VIEW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Si5351C_wxgui_view
///////////////////////////////////////////////////////////////////////////////
class Si5351C_wxgui_view : public wxFrame 
{
	private:
	
	protected:
		wxButton* btnLoadFile;
		wxButton* btnResetToDefaults;
		wxTextCtrl* txtCLKIN_MHz;
		wxStaticText* lblStatus;
		wxButton* btnReadStatus;
		wxButton* btnClearStatus;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxCheckBox* chkEN_CLK;
		wxTextCtrl* txtFreq_CLK;
		wxCheckBox* chkInvert_CLK;
		wxButton* btnConfigure;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnbtnLoadFileClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnResetToDefaultsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnReadStatusClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnClearStatusClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnConfigureClockClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Si5351C_wxgui_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Si5351C"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Si5351C_wxgui_view();
	
};

#endif //__SI5351C_WXGUI_VIEW_H__
