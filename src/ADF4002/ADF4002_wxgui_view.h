///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ADF4002_WXGUI_VIEW_H__
#define __ADF4002_WXGUI_VIEW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ADF4002_wxgui_view
///////////////////////////////////////////////////////////////////////////////
class ADF4002_wxgui_view : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText111;
		wxComboBox* cmbLDP;
		wxComboBox* cmbABW;
		wxSpinCtrl* spinRCnt;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxComboBox* cmbCPG;
		wxSpinCtrl* spinNCnt;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText112;
		wxComboBox* cmbCS1_f;
		wxComboBox* cmbTC_f;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxComboBox* cmbCS2_f;
		wxComboBox* cmbFL_f;
		wxStaticText* m_staticText15;
		wxComboBox* cmbMOC_f;
		wxRadioBox* rgrPDP_f;
		wxRadioBox* rgrPD1_f;
		wxRadioBox* rgrCR_f;
		wxRadioBox* rgrPD2_f;
		wxRadioBox* rgrCPS_f;
		wxStaticText* m_staticText101;
		wxStaticText* m_staticText1121;
		wxComboBox* cmbCS1_i;
		wxComboBox* cmbTC_i;
		wxStaticText* m_staticText131;
		wxStaticText* m_staticText141;
		wxComboBox* cmbCS2_i;
		wxComboBox* cmbFL_i;
		wxStaticText* m_staticText151;
		wxComboBox* cmbMOC_i;
		wxRadioBox* rgrPDP_i;
		wxRadioBox* rgrPD1_i;
		wxRadioBox* rgrCR_i;
		wxRadioBox* rgrPD2_i;
		wxRadioBox* rgrCPS_i;
		wxStaticText* m_staticText26;
		wxStaticText* m_staticText27;
		wxTextCtrl* txtFref;
		wxTextCtrl* txtFvco;
		wxStaticText* m_staticText28;
		wxStaticText* m_staticText29;
		wxStaticText* lblFvco;
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText32;
		wxStaticText* lblFcomp;
		wxButton* btnCalcSend;
		wxButton* btnUpload;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnbtnCalcSendClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnUploadClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ADF4002_wxgui_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("ADF4002"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ADF4002_wxgui_view();
	
};

#endif //__ADF4002_WXGUI_VIEW_H__
