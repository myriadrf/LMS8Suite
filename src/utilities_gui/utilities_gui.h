///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __UTILITIES_GUI_H__
#define __UTILITIES_GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/radiobox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class dlgConnectionSettings_view
///////////////////////////////////////////////////////////////////////////////
class dlgConnectionSettings_view : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* usic;
		wxListBox* mListLMS8ports;
		wxButton* btnConnect;
		wxButton* btnCancel;
		wxButton* btnDisconnect;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetDeviceList( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnConnect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisconnect( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgConnectionSettings_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Connection Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgConnectionSettings_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgConnectionSettingsLMS7_view
///////////////////////////////////////////////////////////////////////////////
class dlgConnectionSettingsLMS7_view : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* usic;
		wxListBox* mListLMS7ports;
		wxButton* btnConnect;
		wxButton* btnCancel;
		wxButton* btnDisconnect;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetDeviceList( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnConnect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisconnect( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgConnectionSettingsLMS7_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Connection Settings LMS7"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgConnectionSettingsLMS7_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgMeasurements_view
///////////////////////////////////////////////////////////////////////////////
class dlgMeasurements_view : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText403;
		wxStaticText* m_staticText413;
		wxStaticText* m_staticText423;
		wxStaticText* m_staticText433;
		wxStaticText* m_staticText442;
		wxCheckBox* chkLMS7FreqEnable;
		wxStaticText* m_staticText83;
		wxTextCtrl* txtLMS7FreqMin;
		wxTextCtrl* txtLMS7FreqMax;
		wxTextCtrl* txtLMS7FreqStep;
		wxButton* btnLMS7Connect;
		wxStaticText* m_staticText402;
		wxStaticText* m_staticText412;
		wxStaticText* m_staticText422;
		wxStaticText* m_staticText432;
		wxStaticText* m_staticText441;
		wxCheckBox* chkLMS7ParEnable1;
		wxTextCtrl* txtLMS7ParField1;
		wxTextCtrl* txtLMS7ParMin1;
		wxTextCtrl* txtLMS7ParMax1;
		wxTextCtrl* txtLMS7ParStep1;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* txtLMSreadAddr;
		wxButton* btnLMSread;
		wxStaticText* ID_STATICTEXT3;
		wxStaticText* lblLMSreadValue;
		wxStaticText* ID_STATICTEXT7;
		wxStaticText* lblLMSreadStatus;
		wxButton* ID_BUTTON23;
		wxCheckBox* ID_CHECKBOX5;
		wxStaticText* m_staticText40;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText42;
		wxStaticText* m_staticText43;
		wxStaticText* m_staticText44;
		wxCheckBox* chkParEnable1;
		wxTextCtrl* txtParField1;
		wxTextCtrl* txtParMin1;
		wxTextCtrl* txtParMax1;
		wxTextCtrl* txtParStep1;
		wxCheckBox* chkParEnable2;
		wxTextCtrl* txtParField2;
		wxTextCtrl* txtParMin2;
		wxTextCtrl* txtParMax2;
		wxTextCtrl* txtParStep2;
		wxStaticText* m_staticText421;
		wxStaticText* m_staticText431;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText401;
		wxStaticText* m_staticText411;
		wxStaticText* m_staticText4111;
		wxStaticText* m_staticText41111;
		wxCheckBox* chkMeasFindPeakEnable;
		wxStaticText* m_staticText38;
		wxTextCtrl* txtMeasFindPeakStartFreq;
		wxTextCtrl* txtMeasFindPeakStartSpan;
		wxTextCtrl* txtMeasFindPeakStopSpan;
		wxCheckBox* chkMeasUseBandMarker;
		wxTextCtrl* txtMeasBandMarkerBand;
		wxButton* btnMeasure;
		wxButton* btnStop;
		wxButton* btnLoadSetup;
		wxButton* btnSaveSetup;
		wxTextCtrl* txtField_log;
		wxGrid* gridMeasResults;
		wxButton* btnMeasSaveAsCSV;
		wxStaticText* lblStatusLabel;
		wxStaticText* lblStatus;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDlgMeasurementsClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnLMS7Connect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLMS7read( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateUIChkMeasUseBandMarker( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void onMeasMeasure( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMeasStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMeasLoadSetup( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMeasSaveSetup( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMeasSaveAsCSV( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgMeasurements_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Measurements"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgMeasurements_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlMiniLog_view
///////////////////////////////////////////////////////////////////////////////
class pnlMiniLog_view : public wxPanel 
{
	private:
	
	protected:
		wxTextCtrl* txtMessageField;
		wxButton* btnClear;
		wxButton* btnFullLog;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnUpdateGUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnBtnClearClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnShowFullLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLogDataClicked( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxCheckBox* chkLogData;
		
		pnlMiniLog_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~pnlMiniLog_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgFullMessageLog_view
///////////////////////////////////////////////////////////////////////////////
class dlgFullMessageLog_view : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* txtMessageField;
	
	public:
		
		dlgFullMessageLog_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Message log"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~dlgFullMessageLog_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgDeviceInfo_view
///////////////////////////////////////////////////////////////////////////////
class dlgDeviceInfo_view : public wxDialog 
{
	private:
	
	protected:
		wxButton* btnGetInfo;
		wxStaticText* m_staticText6;
		wxStaticText* lblDeviceCtr;
		wxStaticText* m_staticText8;
		wxStaticText* lblExpansionCtr;
		wxStaticText* m_staticText10;
		wxStaticText* lblFirmwareCtr;
		wxStaticText* m_staticText12;
		wxStaticText* lblHardwareCtr;
		wxStaticText* m_staticText14;
		wxStaticText* lblProtocolCtr;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnGetInfo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgDeviceInfo_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Device Info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgDeviceInfo_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class dlgTempCalibrate_view
///////////////////////////////////////////////////////////////////////////////
class dlgTempCalibrate_view : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText6;
		wxTextCtrl* txtValue;
		wxStaticText* m_staticText8;
		wxTextCtrl* txtTemperature;
		wxStaticText* m_staticText10;
		wxStaticText* sttxtT0;
		wxButton* btnCalibrate;
		wxButton* btnReset;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClick_btnCalibrate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_btnReset( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dlgTempCalibrate_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Device Info"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~dlgTempCalibrate_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SPI_view
///////////////////////////////////////////////////////////////////////////////
class SPI_view : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* ID_STATICTEXT1;
		wxTextCtrl* txtLMSwriteAddr;
		wxStaticText* ID_STATICTEXT9;
		wxTextCtrl* txtLMSwriteValue;
		wxButton* btnLMSwrite;
		wxStaticText* ID_STATICTEXT5;
		wxStaticText* lblLMSwriteStatus;
		wxStaticText* ID_STATICTEXT2;
		wxTextCtrl* txtLMSreadAddr;
		wxButton* btnLMSread;
		wxStaticText* ID_STATICTEXT3;
		wxStaticText* lblLMSreadValue;
		wxStaticText* ID_STATICTEXT7;
		wxStaticText* lblLMSreadStatus;
		wxButton* ID_BUTTON23;
		wxCheckBox* ID_CHECKBOX5;
		wxTextCtrl* txtSPIfield_log;
		wxTextCtrl* txtSPIfield;
		wxButton* btnSPIstep;
		wxButton* btnClear;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onLMSwrite( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLMSread( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSPIstep( wxCommandEvent& event ) { event.Skip(); }
		virtual void onClear( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SPI_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SPI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~SPI_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GPIO_view
///////////////////////////////////////////////////////////////////////////////
class GPIO_view : public wxFrame 
{
	private:
	
	protected:
		wxRadioBox* rgr_GPIO03_DIR;
		wxRadioBox* rgr_GPIO47_DIR;
		wxStaticText* lblGPIOstatus;
		wxButton* btnUpdateClear;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChangeGPIODirection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxCheckBox* chkGPIO0;
		wxCheckBox* chkGPIO1;
		wxCheckBox* chkGPIO2;
		wxCheckBox* chkGPIO3;
		wxCheckBox* chkGPIO4;
		wxCheckBox* chkGPIO5;
		wxCheckBox* chkGPIO6;
		wxCheckBox* chkGPIO7;
		wxCheckBox* chkGPIO8;
		wxCheckBox* chkCORE_LDO_EN;
		
		GPIO_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GPIO"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GPIO_view();
	
};

#endif //__UTILITIES_GUI_H__
