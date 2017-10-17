///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "utilities_gui.h"

///////////////////////////////////////////////////////////////////////////

dlgConnectionSettings_view::dlgConnectionSettings_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer211;
	fgSizer211 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer211->SetFlexibleDirection( wxBOTH );
	fgSizer211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer212;
	fgSizer212 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer212->AddGrowableCol( 0 );
	fgSizer212->SetFlexibleDirection( wxBOTH );
	fgSizer212->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	usic = new wxStaticText( this, wxID_ANY, wxT("LMS8 control:"), wxDefaultPosition, wxDefaultSize, 0 );
	usic->Wrap( -1 );
	fgSizer212->Add( usic, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	mListLMS8ports = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,150 ), 0, NULL, 0 ); 
	fgSizer212->Add( mListLMS8ports, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer211->Add( fgSizer212, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer213;
	fgSizer213 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer213->AddGrowableCol( 0 );
	fgSizer213->AddGrowableCol( 1 );
	fgSizer213->AddGrowableCol( 2 );
	fgSizer213->SetFlexibleDirection( wxBOTH );
	fgSizer213->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnConnect = new wxButton( this, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnConnect, 0, wxALL, 5 );
	
	btnCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnCancel, 0, wxALL, 5 );
	
	btnDisconnect = new wxButton( this, wxID_ANY, wxT("Disconnect"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnDisconnect, 0, wxALL, 5 );
	
	
	fgSizer211->Add( fgSizer213, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer211 );
	this->Layout();
	fgSizer211->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( dlgConnectionSettings_view::GetDeviceList ) );
	btnConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnConnect ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnCancel ), NULL, this );
	btnDisconnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnDisconnect ), NULL, this );
}

dlgConnectionSettings_view::~dlgConnectionSettings_view()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( dlgConnectionSettings_view::GetDeviceList ) );
	btnConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnConnect ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnCancel ), NULL, this );
	btnDisconnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettings_view::OnDisconnect ), NULL, this );
	
}

dlgConnectionSettingsLMS7_view::dlgConnectionSettingsLMS7_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer211;
	fgSizer211 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer211->SetFlexibleDirection( wxBOTH );
	fgSizer211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer212;
	fgSizer212 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer212->AddGrowableCol( 0 );
	fgSizer212->SetFlexibleDirection( wxBOTH );
	fgSizer212->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	usic = new wxStaticText( this, wxID_ANY, wxT("LMS7 control:"), wxDefaultPosition, wxDefaultSize, 0 );
	usic->Wrap( -1 );
	fgSizer212->Add( usic, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	mListLMS7ports = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,150 ), 0, NULL, 0 ); 
	fgSizer212->Add( mListLMS7ports, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer211->Add( fgSizer212, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer213;
	fgSizer213 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer213->AddGrowableCol( 0 );
	fgSizer213->AddGrowableCol( 1 );
	fgSizer213->AddGrowableCol( 2 );
	fgSizer213->SetFlexibleDirection( wxBOTH );
	fgSizer213->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnConnect = new wxButton( this, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnConnect, 0, wxALL, 5 );
	
	btnCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnCancel, 0, wxALL, 5 );
	
	btnDisconnect = new wxButton( this, wxID_ANY, wxT("Disconnect"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer213->Add( btnDisconnect, 0, wxALL, 5 );
	
	
	fgSizer211->Add( fgSizer213, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer211 );
	this->Layout();
	fgSizer211->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( dlgConnectionSettingsLMS7_view::GetDeviceList ) );
	btnConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnConnect ), NULL, this );
	btnCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnCancel ), NULL, this );
	btnDisconnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnDisconnect ), NULL, this );
}

dlgConnectionSettingsLMS7_view::~dlgConnectionSettingsLMS7_view()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( dlgConnectionSettingsLMS7_view::GetDeviceList ) );
	btnConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnConnect ), NULL, this );
	btnCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnCancel ), NULL, this );
	btnDisconnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgConnectionSettingsLMS7_view::OnDisconnect ), NULL, this );
	
}

dlgMeasurements_view::dlgMeasurements_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 5, 5 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer48;
	fgSizer48 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer48->SetFlexibleDirection( wxBOTH );
	fgSizer48->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizerLMS8SweepParams1;
	sbSizerLMS8SweepParams1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS7 Sweep frequency") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer362;
	fgSizer362 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer362->SetFlexibleDirection( wxBOTH );
	fgSizer362->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText403 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText403->Wrap( -1 );
	fgSizer362->Add( m_staticText403, 0, wxALL, 5 );
	
	m_staticText413 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText413->Wrap( -1 );
	fgSizer362->Add( m_staticText413, 0, wxALL, 5 );
	
	m_staticText423 = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText423->Wrap( -1 );
	fgSizer362->Add( m_staticText423, 0, wxALL, 5 );
	
	m_staticText433 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText433->Wrap( -1 );
	fgSizer362->Add( m_staticText433, 0, wxALL, 5 );
	
	m_staticText442 = new wxStaticText( this, wxID_ANY, wxT("Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText442->Wrap( -1 );
	fgSizer362->Add( m_staticText442, 0, wxALL, 5 );
	
	chkLMS7FreqEnable = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer362->Add( chkLMS7FreqEnable, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText83 = new wxStaticText( this, wxID_ANY, wxT("SXT Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText83->Wrap( -1 );
	fgSizer362->Add( m_staticText83, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7FreqMin = new wxTextCtrl( this, wxID_ANY, wxT("1E9"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7FreqMin->SetMaxLength( 0 ); 
	txtLMS7FreqMin->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer362->Add( txtLMS7FreqMin, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7FreqMax = new wxTextCtrl( this, wxID_ANY, wxT("2E9"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7FreqMax->SetMaxLength( 0 ); 
	txtLMS7FreqMax->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer362->Add( txtLMS7FreqMax, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7FreqStep = new wxTextCtrl( this, wxID_ANY, wxT("100E6"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7FreqStep->SetMaxLength( 0 ); 
	txtLMS7FreqStep->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer362->Add( txtLMS7FreqStep, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerLMS8SweepParams1->Add( fgSizer362, 0, 0, 5 );
	
	
	fgSizer48->Add( sbSizerLMS8SweepParams1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerLMS7SweepParams;
	sbSizerLMS7SweepParams = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS7 Sweep parameters") ), wxVERTICAL );
	
	btnLMS7Connect = new wxButton( this, wxID_ANY, wxT("LMS7 Connect..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerLMS7SweepParams->Add( btnLMS7Connect, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer361;
	fgSizer361 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer361->SetFlexibleDirection( wxBOTH );
	fgSizer361->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText402 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText402->Wrap( -1 );
	fgSizer361->Add( m_staticText402, 0, wxALL, 5 );
	
	m_staticText412 = new wxStaticText( this, wxID_ANY, wxT("Field"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText412->Wrap( -1 );
	fgSizer361->Add( m_staticText412, 0, wxALL, 5 );
	
	m_staticText422 = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText422->Wrap( -1 );
	fgSizer361->Add( m_staticText422, 0, wxALL, 5 );
	
	m_staticText432 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText432->Wrap( -1 );
	fgSizer361->Add( m_staticText432, 0, wxALL, 5 );
	
	m_staticText441 = new wxStaticText( this, wxID_ANY, wxT("Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText441->Wrap( -1 );
	fgSizer361->Add( m_staticText441, 0, wxALL, 5 );
	
	chkLMS7ParEnable1 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer361->Add( chkLMS7ParEnable1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7ParField1 = new wxTextCtrl( this, wxID_ANY, wxT("VCO_FREQ_n"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtLMS7ParField1->SetMaxLength( 0 ); 
	fgSizer361->Add( txtLMS7ParField1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7ParMin1 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7ParMin1->SetMaxLength( 0 ); 
	txtLMS7ParMin1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer361->Add( txtLMS7ParMin1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7ParMax1 = new wxTextCtrl( this, wxID_ANY, wxT("0x11"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7ParMax1->SetMaxLength( 0 ); 
	txtLMS7ParMax1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer361->Add( txtLMS7ParMax1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtLMS7ParStep1 = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMS7ParStep1->SetMaxLength( 0 ); 
	txtLMS7ParStep1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer361->Add( txtLMS7ParStep1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerLMS7SweepParams->Add( fgSizer361, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer305;
	fgSizer305 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer305->SetFlexibleDirection( wxBOTH );
	fgSizer305->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS Read - For testing purposes") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer307;
	fgSizer307 = new wxFlexGridSizer( 0, 7, 5, 5 );
	fgSizer307->SetFlexibleDirection( wxBOTH );
	fgSizer307->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("Address(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( 0 );
	fgSizer307->Add( ID_STATICTEXT2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtLMSreadAddr = new wxTextCtrl( this, wxID_ANY, wxT("FFFF"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMSreadAddr->SetMaxLength( 0 ); 
	txtLMSreadAddr->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer307->Add( txtLMSreadAddr, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnLMSread = new wxButton( this, wxID_ANY, wxT("CMD Read"), wxDefaultPosition, wxDefaultSize, 0 );
	btnLMSread->SetDefault(); 
	fgSizer307->Add( btnLMSread, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer308;
	fgSizer308 = new wxFlexGridSizer( 0, 2, 0, 5 );
	fgSizer308->SetFlexibleDirection( wxBOTH );
	fgSizer308->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("Read Value(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer308->Add( ID_STATICTEXT3, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	lblLMSreadValue = new wxStaticText( this, wxID_ANY, wxT("????"), wxDefaultPosition, wxDefaultSize, 0 );
	lblLMSreadValue->Wrap( 0 );
	fgSizer308->Add( lblLMSreadValue, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_STATICTEXT7 = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT7->Wrap( -1 );
	fgSizer308->Add( ID_STATICTEXT7, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	lblLMSreadStatus = new wxStaticText( this, wxID_ANY, wxT("???"), wxDefaultPosition, wxSize( 143,13 ), 0 );
	lblLMSreadStatus->Wrap( 0 );
	fgSizer308->Add( lblLMSreadStatus, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer307->Add( fgSizer308, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer309;
	fgSizer309 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer309->SetFlexibleDirection( wxBOTH );
	fgSizer309->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_BUTTON23 = new wxButton( this, wxID_ANY, wxT("PurgeCOM"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON23->SetDefault(); 
	ID_BUTTON23->Hide();
	
	fgSizer309->Add( ID_BUTTON23, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_CHECKBOX5 = new wxCheckBox( this, wxID_ANY, wxT("Test written data"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECKBOX5->SetValue(true); 
	ID_CHECKBOX5->Hide();
	ID_CHECKBOX5->SetToolTip( wxT("After writing register, reads back the same register and checks if values match") );
	
	fgSizer309->Add( ID_CHECKBOX5, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer307->Add( fgSizer309, 1, wxALIGN_LEFT|wxALIGN_TOP, 5 );
	
	
	sbSizer161->Add( fgSizer307, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer305->Add( sbSizer161, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_TOP|wxEXPAND, 5 );
	
	
	sbSizerLMS7SweepParams->Add( fgSizer305, 0, wxEXPAND, 5 );
	
	
	fgSizer48->Add( sbSizerLMS7SweepParams, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerLMS8SweepParams;
	sbSizerLMS8SweepParams = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS8 Sweep parameters") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer36;
	fgSizer36 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer36->SetFlexibleDirection( wxBOTH );
	fgSizer36->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText40 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	fgSizer36->Add( m_staticText40, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Field"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer36->Add( m_staticText41, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer36->Add( m_staticText42, 0, wxALL, 5 );
	
	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	fgSizer36->Add( m_staticText43, 0, wxALL, 5 );
	
	m_staticText44 = new wxStaticText( this, wxID_ANY, wxT("Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	fgSizer36->Add( m_staticText44, 0, wxALL, 5 );
	
	chkParEnable1 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer36->Add( chkParEnable1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParField1 = new wxTextCtrl( this, wxID_ANY, wxT("VCO_FREQ_n"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtParField1->SetMaxLength( 0 ); 
	fgSizer36->Add( txtParField1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParMin1 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParMin1->SetMaxLength( 0 ); 
	txtParMin1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParMin1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParMax1 = new wxTextCtrl( this, wxID_ANY, wxT("0x11"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParMax1->SetMaxLength( 0 ); 
	txtParMax1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParMax1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParStep1 = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParStep1->SetMaxLength( 0 ); 
	txtParStep1->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParStep1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	chkParEnable2 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer36->Add( chkParEnable2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParField2 = new wxTextCtrl( this, wxID_ANY, wxT("VCO_FREQ_n"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtParField2->SetMaxLength( 0 ); 
	fgSizer36->Add( txtParField2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParMin2 = new wxTextCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParMin2->SetMaxLength( 0 ); 
	txtParMin2->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParMin2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParMax2 = new wxTextCtrl( this, wxID_ANY, wxT("0x11"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParMax2->SetMaxLength( 0 ); 
	txtParMax2->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParMax2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtParStep2 = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtParStep2->SetMaxLength( 0 ); 
	txtParStep2->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer36->Add( txtParStep2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizerLMS8SweepParams->Add( fgSizer36, 0, 0, 5 );
	
	
	fgSizer48->Add( sbSizerLMS8SweepParams, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer15;
	sbSizer15 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Measurements") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer40;
	fgSizer40 = new wxFlexGridSizer( 0, 7, 0, 0 );
	fgSizer40->SetFlexibleDirection( wxBOTH );
	fgSizer40->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText421 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText421->Wrap( -1 );
	fgSizer40->Add( m_staticText421, 0, wxALL, 5 );
	
	m_staticText431 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431->Wrap( -1 );
	fgSizer40->Add( m_staticText431, 0, wxALL, 5 );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("Start f:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	fgSizer40->Add( m_staticText39, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText401 = new wxStaticText( this, wxID_ANY, wxT("Start span:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText401->Wrap( -1 );
	fgSizer40->Add( m_staticText401, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText411 = new wxStaticText( this, wxID_ANY, wxT("Stop span:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText411->Wrap( -1 );
	fgSizer40->Add( m_staticText411, 0, wxALL, 5 );
	
	m_staticText4111 = new wxStaticText( this, wxID_ANY, wxT("Band marker"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4111->Wrap( -1 );
	fgSizer40->Add( m_staticText4111, 0, wxALL, 5 );
	
	m_staticText41111 = new wxStaticText( this, wxID_ANY, wxT("Band:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41111->Wrap( -1 );
	fgSizer40->Add( m_staticText41111, 0, wxALL, 5 );
	
	chkMeasFindPeakEnable = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer40->Add( chkMeasFindPeakEnable, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT("Find Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	m_staticText38->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer40->Add( m_staticText38, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtMeasFindPeakStartFreq = new wxTextCtrl( this, wxID_ANY, wxT("4.0E9"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeasFindPeakStartFreq->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer40->Add( txtMeasFindPeakStartFreq, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtMeasFindPeakStartSpan = new wxTextCtrl( this, wxID_ANY, wxT("100E6"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeasFindPeakStartSpan->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer40->Add( txtMeasFindPeakStartSpan, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	txtMeasFindPeakStopSpan = new wxTextCtrl( this, wxID_ANY, wxT("100E3"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeasFindPeakStopSpan->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer40->Add( txtMeasFindPeakStopSpan, 0, wxALL, 5 );
	
	chkMeasUseBandMarker = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer40->Add( chkMeasUseBandMarker, 0, wxALIGN_CENTER|wxALL, 5 );
	
	txtMeasBandMarkerBand = new wxTextCtrl( this, wxID_ANY, wxT("1000"), wxDefaultPosition, wxDefaultSize, 0 );
	txtMeasBandMarkerBand->Enable( false );
	txtMeasBandMarkerBand->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer40->Add( txtMeasBandMarkerBand, 0, wxALL, 5 );
	
	
	sbSizer15->Add( fgSizer40, 1, wxEXPAND, 5 );
	
	
	fgSizer48->Add( sbSizer15, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer38;
	fgSizer38 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer38->SetFlexibleDirection( wxBOTH );
	fgSizer38->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnMeasure = new wxButton( this, wxID_ANY, wxT("Measure"), wxDefaultPosition, wxDefaultSize, 0 );
	btnMeasure->SetDefault(); 
	fgSizer38->Add( btnMeasure, 0, wxALL|wxRIGHT, 5 );
	
	btnStop = new wxButton( this, wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	btnStop->SetDefault(); 
	fgSizer38->Add( btnStop, 0, wxALL, 5 );
	
	btnLoadSetup = new wxButton( this, wxID_ANY, wxT("Load Setup..."), wxDefaultPosition, wxDefaultSize, 0 );
	btnLoadSetup->SetDefault(); 
	fgSizer38->Add( btnLoadSetup, 0, wxALL, 5 );
	
	btnSaveSetup = new wxButton( this, wxID_ANY, wxT("Save Setup..."), wxDefaultPosition, wxDefaultSize, 0 );
	btnSaveSetup->SetDefault(); 
	fgSizer38->Add( btnSaveSetup, 0, wxALL, 5 );
	
	
	fgSizer48->Add( fgSizer38, 1, wxALIGN_CENTER, 5 );
	
	
	fgSizer7->Add( fgSizer48, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer50;
	fgSizer50 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer50->SetFlexibleDirection( wxBOTH );
	fgSizer50->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Log") ), wxVERTICAL );
	
	sbSizer16->SetMinSize( wxSize( 400,-1 ) ); 
	txtField_log = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	txtField_log->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	txtField_log->SetMinSize( wxSize( -1,100 ) );
	
	sbSizer16->Add( txtField_log, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer50->Add( sbSizer16, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer17;
	sbSizer17 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Results") ), wxVERTICAL );
	
	gridMeasResults = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gridMeasResults->CreateGrid( 1, 3 );
	gridMeasResults->EnableEditing( true );
	gridMeasResults->EnableGridLines( true );
	gridMeasResults->EnableDragGridSize( false );
	gridMeasResults->SetMargins( 0, 0 );
	
	// Columns
	gridMeasResults->AutoSizeColumns();
	gridMeasResults->EnableDragColMove( false );
	gridMeasResults->EnableDragColSize( true );
	gridMeasResults->SetColLabelSize( 30 );
	gridMeasResults->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gridMeasResults->EnableDragRowSize( true );
	gridMeasResults->SetRowLabelSize( 80 );
	gridMeasResults->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gridMeasResults->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	gridMeasResults->SetMinSize( wxSize( -1,200 ) );
	
	sbSizer17->Add( gridMeasResults, 0, wxALL|wxEXPAND, 5 );
	
	btnMeasSaveAsCSV = new wxButton( this, wxID_ANY, wxT("Save as CSV..."), wxDefaultPosition, wxDefaultSize, 0 );
	btnMeasSaveAsCSV->SetDefault(); 
	sbSizer17->Add( btnMeasSaveAsCSV, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer50->Add( sbSizer17, 1, wxEXPAND, 5 );
	
	
	fgSizer7->Add( fgSizer50, 0, wxEXPAND, 5 );
	
	
	fgSizer12->Add( fgSizer7, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer37;
	fgSizer37 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer37->SetFlexibleDirection( wxBOTH );
	fgSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lblStatusLabel = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	lblStatusLabel->Wrap( -1 );
	fgSizer37->Add( lblStatusLabel, 0, wxALL, 5 );
	
	lblStatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	lblStatus->Wrap( -1 );
	fgSizer37->Add( lblStatus, 0, wxALL, 5 );
	
	
	fgSizer12->Add( fgSizer37, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer12 );
	this->Layout();
	fgSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( dlgMeasurements_view::OnDlgMeasurementsClose ) );
	btnLMS7Connect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::OnLMS7Connect ), NULL, this );
	btnLMSread->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onLMS7read ), NULL, this );
	chkMeasUseBandMarker->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( dlgMeasurements_view::OnUpdateUIChkMeasUseBandMarker ), NULL, this );
	btnMeasure->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasMeasure ), NULL, this );
	btnStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasStop ), NULL, this );
	btnLoadSetup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasLoadSetup ), NULL, this );
	btnSaveSetup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasSaveSetup ), NULL, this );
	btnMeasSaveAsCSV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasSaveAsCSV ), NULL, this );
}

dlgMeasurements_view::~dlgMeasurements_view()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( dlgMeasurements_view::OnDlgMeasurementsClose ) );
	btnLMS7Connect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::OnLMS7Connect ), NULL, this );
	btnLMSread->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onLMS7read ), NULL, this );
	chkMeasUseBandMarker->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( dlgMeasurements_view::OnUpdateUIChkMeasUseBandMarker ), NULL, this );
	btnMeasure->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasMeasure ), NULL, this );
	btnStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasStop ), NULL, this );
	btnLoadSetup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasLoadSetup ), NULL, this );
	btnSaveSetup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasSaveSetup ), NULL, this );
	btnMeasSaveAsCSV->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgMeasurements_view::onMeasSaveAsCSV ), NULL, this );
	
}

pnlMiniLog_view::pnlMiniLog_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 0 );
	fgSizer4->AddGrowableRow( 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtMessageField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	txtMessageField->SetMinSize( wxSize( 300,48 ) );
	
	fgSizer4->Add( txtMessageField, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnClear = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	btnClear->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer5->Add( btnClear, 0, wxEXPAND, 5 );
	
	btnFullLog = new wxButton( this, wxID_ANY, wxT("Show Log"), wxDefaultPosition, wxDefaultSize, 0 );
	btnFullLog->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer5->Add( btnFullLog, 0, wxEXPAND, 5 );
	
	chkLogData = new wxCheckBox( this, wxID_ANY, wxT("Log data"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( chkLogData, 0, 0, 5 );
	
	
	fgSizer4->Add( fgSizer5, 1, 0, 5 );
	
	
	this->SetSizer( fgSizer4 );
	this->Layout();
	fgSizer4->Fit( this );
	
	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlMiniLog_view::OnUpdateGUI ) );
	btnClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnBtnClearClicked ), NULL, this );
	btnFullLog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnShowFullLog ), NULL, this );
	chkLogData->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnLogDataClicked ), NULL, this );
}

pnlMiniLog_view::~pnlMiniLog_view()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlMiniLog_view::OnUpdateGUI ) );
	btnClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnBtnClearClicked ), NULL, this );
	btnFullLog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnShowFullLog ), NULL, this );
	chkLogData->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlMiniLog_view::OnLogDataClicked ), NULL, this );
	
}

dlgFullMessageLog_view::dlgFullMessageLog_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,200 ), wxDefaultSize );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer19->AddGrowableCol( 0 );
	fgSizer19->AddGrowableRow( 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	txtMessageField = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	txtMessageField->SetMinSize( wxSize( 300,100 ) );
	
	fgSizer19->Add( txtMessageField, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer19 );
	this->Layout();
	fgSizer19->Fit( this );
	
	this->Centre( wxBOTH );
}

dlgFullMessageLog_view::~dlgFullMessageLog_view()
{
}

dlgDeviceInfo_view::dlgDeviceInfo_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnGetInfo = new wxButton( this, wxID_ANY, wxT("GET INFO"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( btnGetInfo, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 5, 5 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizerControlPort;
	sbSizerControlPort = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Control port") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Device:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer8->Add( m_staticText6, 0, wxALL, 5 );
	
	lblDeviceCtr = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	lblDeviceCtr->Wrap( -1 );
	fgSizer8->Add( lblDeviceCtr, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Expansion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer8->Add( m_staticText8, 0, wxALL, 5 );
	
	lblExpansionCtr = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	lblExpansionCtr->Wrap( -1 );
	fgSizer8->Add( lblExpansionCtr, 0, wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Firmware:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer8->Add( m_staticText10, 0, wxALL, 5 );
	
	lblFirmwareCtr = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	lblFirmwareCtr->Wrap( -1 );
	fgSizer8->Add( lblFirmwareCtr, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Hardware:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer8->Add( m_staticText12, 0, wxALL, 5 );
	
	lblHardwareCtr = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	lblHardwareCtr->Wrap( -1 );
	fgSizer8->Add( lblHardwareCtr, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Protocol:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer8->Add( m_staticText14, 0, wxALL, 5 );
	
	lblProtocolCtr = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	lblProtocolCtr->Wrap( -1 );
	fgSizer8->Add( lblProtocolCtr, 0, wxALL, 5 );
	
	
	sbSizerControlPort->Add( fgSizer8, 1, wxEXPAND, 5 );
	
	
	fgSizer7->Add( sbSizerControlPort, 1, wxEXPAND, 5 );
	
	
	fgSizer12->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer12 );
	this->Layout();
	fgSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnGetInfo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgDeviceInfo_view::OnGetInfo ), NULL, this );
}

dlgDeviceInfo_view::~dlgDeviceInfo_view()
{
	// Disconnect Events
	btnGetInfo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgDeviceInfo_view::OnGetInfo ), NULL, this );
	
}

dlgTempCalibrate_view::dlgTempCalibrate_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->AddGrowableCol( 1 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer8->Add( m_staticText6, 0, wxALL, 4 );
	
	txtValue = new wxTextCtrl( this, wxID_ANY, wxT("113"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( txtValue, 0, wxALL, 0 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Temperature  [°C]:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer8->Add( m_staticText8, 0, wxALL, 4 );
	
	txtTemperature = new wxTextCtrl( this, wxID_ANY, wxT("25.5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( txtTemperature, 0, wxALL, 0 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Coeff. T0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer8->Add( m_staticText10, 0, wxALL, 5 );
	
	sttxtT0 = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtT0->Wrap( -1 );
	fgSizer8->Add( sttxtT0, 0, wxALL, 5 );
	
	
	fgSizer12->Add( fgSizer8, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer38;
	fgSizer38 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer38->SetFlexibleDirection( wxBOTH );
	fgSizer38->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnCalibrate = new wxButton( this, wxID_ANY, wxT("Calibrate"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( btnCalibrate, 0, wxALL, 5 );
	
	btnReset = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer38->Add( btnReset, 0, wxALL, 5 );
	
	
	fgSizer12->Add( fgSizer38, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( fgSizer12 );
	this->Layout();
	fgSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnCalibrate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgTempCalibrate_view::OnClick_btnCalibrate ), NULL, this );
	btnReset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgTempCalibrate_view::OnClick_btnReset ), NULL, this );
}

dlgTempCalibrate_view::~dlgTempCalibrate_view()
{
	// Disconnect Events
	btnCalibrate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgTempCalibrate_view::OnClick_btnCalibrate ), NULL, this );
	btnReset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dlgTempCalibrate_view::OnClick_btnReset ), NULL, this );
	
}

SPI_view::SPI_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxFlexGridSizer* fgSizer305;
	fgSizer305 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer305->SetFlexibleDirection( wxBOTH );
	fgSizer305->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer160;
	sbSizer160 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS Write ") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer306;
	fgSizer306 = new wxFlexGridSizer( 0, 7, 5, 5 );
	fgSizer306->SetFlexibleDirection( wxBOTH );
	fgSizer306->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_STATICTEXT1 = new wxStaticText( this, wxID_ANY, wxT("Address(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT1->Wrap( 0 );
	fgSizer306->Add( ID_STATICTEXT1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtLMSwriteAddr = new wxTextCtrl( this, wxID_ANY, wxT("000A"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	txtLMSwriteAddr->SetMaxLength( 0 ); 
	txtLMSwriteAddr->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer306->Add( txtLMSwriteAddr, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_STATICTEXT9 = new wxStaticText( this, wxID_ANY, wxT("Value(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT9->Wrap( 0 );
	fgSizer306->Add( ID_STATICTEXT9, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtLMSwriteValue = new wxTextCtrl( this, wxID_ANY, wxT("01FF"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMSwriteValue->SetMaxLength( 0 ); 
	txtLMSwriteValue->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer306->Add( txtLMSwriteValue, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnLMSwrite = new wxButton( this, wxID_ANY, wxT("CMD Write"), wxDefaultPosition, wxDefaultSize, 0 );
	btnLMSwrite->SetDefault(); 
	fgSizer306->Add( btnLMSwrite, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_STATICTEXT5 = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT5->Wrap( 0 );
	fgSizer306->Add( ID_STATICTEXT5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lblLMSwriteStatus = new wxStaticText( this, wxID_ANY, wxT("???"), wxDefaultPosition, wxSize( 134,13 ), 0 );
	lblLMSwriteStatus->Wrap( 0 );
	fgSizer306->Add( lblLMSwriteStatus, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer160->Add( fgSizer306, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer305->Add( sbSizer160, 1, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_TOP, 5 );
	
	wxStaticBoxSizer* sbSizer161;
	sbSizer161 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LMS Read") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer307;
	fgSizer307 = new wxFlexGridSizer( 0, 7, 5, 5 );
	fgSizer307->SetFlexibleDirection( wxBOTH );
	fgSizer307->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_STATICTEXT2 = new wxStaticText( this, wxID_ANY, wxT("Address(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT2->Wrap( 0 );
	fgSizer307->Add( ID_STATICTEXT2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtLMSreadAddr = new wxTextCtrl( this, wxID_ANY, wxT("000A"), wxDefaultPosition, wxDefaultSize, 0 );
	txtLMSreadAddr->SetMaxLength( 0 ); 
	txtLMSreadAddr->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer307->Add( txtLMSreadAddr, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btnLMSread = new wxButton( this, wxID_ANY, wxT("CMD Read"), wxDefaultPosition, wxDefaultSize, 0 );
	btnLMSread->SetDefault(); 
	fgSizer307->Add( btnLMSread, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer308;
	fgSizer308 = new wxFlexGridSizer( 0, 2, 0, 5 );
	fgSizer308->SetFlexibleDirection( wxBOTH );
	fgSizer308->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_STATICTEXT3 = new wxStaticText( this, wxID_ANY, wxT("Read Value(Hex):"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT3->Wrap( -1 );
	fgSizer308->Add( ID_STATICTEXT3, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	lblLMSreadValue = new wxStaticText( this, wxID_ANY, wxT("????"), wxDefaultPosition, wxDefaultSize, 0 );
	lblLMSreadValue->Wrap( 0 );
	fgSizer308->Add( lblLMSreadValue, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_STATICTEXT7 = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_STATICTEXT7->Wrap( -1 );
	fgSizer308->Add( ID_STATICTEXT7, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	lblLMSreadStatus = new wxStaticText( this, wxID_ANY, wxT("???"), wxDefaultPosition, wxSize( 143,13 ), 0 );
	lblLMSreadStatus->Wrap( 0 );
	fgSizer308->Add( lblLMSreadStatus, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer307->Add( fgSizer308, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer309;
	fgSizer309 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer309->SetFlexibleDirection( wxBOTH );
	fgSizer309->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_BUTTON23 = new wxButton( this, wxID_ANY, wxT("PurgeCOM"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON23->SetDefault(); 
	ID_BUTTON23->Hide();
	
	fgSizer309->Add( ID_BUTTON23, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	ID_CHECKBOX5 = new wxCheckBox( this, wxID_ANY, wxT("Test written data"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_CHECKBOX5->SetValue(true); 
	ID_CHECKBOX5->Hide();
	ID_CHECKBOX5->SetToolTip( wxT("After writing register, reads back the same register and checks if values match") );
	
	fgSizer309->Add( ID_CHECKBOX5, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer307->Add( fgSizer309, 1, wxALIGN_LEFT|wxALIGN_TOP, 5 );
	
	
	sbSizer161->Add( fgSizer307, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer305->Add( sbSizer161, 1, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_TOP|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer17;
	sbSizer17 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("SPI Commands") ), wxVERTICAL );
	
	txtSPIfield_log = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	txtSPIfield_log->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	txtSPIfield_log->SetMinSize( wxSize( -1,100 ) );
	
	sbSizer17->Add( txtSPIfield_log, 0, wxEXPAND, 0 );
	
	txtSPIfield = new wxTextCtrl( this, wxID_ANY, wxT("RD GPIO_DS\nWR GPIO_DS 0x01FF\nRD 0x000A\n"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH2 );
	txtSPIfield->SetMinSize( wxSize( -1,200 ) );
	
	sbSizer17->Add( txtSPIfield, 1, wxEXPAND, 0 );
	
	wxFlexGridSizer* fgSizer29;
	fgSizer29 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer29->SetFlexibleDirection( wxBOTH );
	fgSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnSPIstep = new wxButton( this, wxID_ANY, wxT("SPI Step"), wxDefaultPosition, wxDefaultSize, 0 );
	btnSPIstep->SetDefault(); 
	fgSizer29->Add( btnSPIstep, 0, wxALIGN_CENTER|wxALL, 5 );
	
	btnClear = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	btnClear->SetDefault(); 
	fgSizer29->Add( btnClear, 0, wxALL, 5 );
	
	
	sbSizer17->Add( fgSizer29, 0, wxALIGN_CENTER, 5 );
	
	
	fgSizer305->Add( sbSizer17, 1, wxALIGN_LEFT|wxALIGN_TOP|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( fgSizer305 );
	this->Layout();
	fgSizer305->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnLMSwrite->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onLMSwrite ), NULL, this );
	btnLMSread->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onLMSread ), NULL, this );
	btnSPIstep->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onSPIstep ), NULL, this );
	btnClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onClear ), NULL, this );
}

SPI_view::~SPI_view()
{
	// Disconnect Events
	btnLMSwrite->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onLMSwrite ), NULL, this );
	btnLMSread->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onLMSread ), NULL, this );
	btnSPIstep->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onSPIstep ), NULL, this );
	btnClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SPI_view::onClear ), NULL, this );
	
}

GPIO_view::GPIO_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxFlexGridSizer* fgSizer305;
	fgSizer305 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer305->SetFlexibleDirection( wxBOTH );
	fgSizer305->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer160;
	sbSizer160 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO 0 - 3") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer57;
	fgSizer57 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer57->SetFlexibleDirection( wxBOTH );
	fgSizer57->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer58;
	fgSizer58 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer58->SetFlexibleDirection( wxBOTH );
	fgSizer58->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer28;
	sbSizer28 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer63;
	fgSizer63 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer63->SetFlexibleDirection( wxBOTH );
	fgSizer63->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO0 = new wxCheckBox( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO0->Enable( false );
	
	fgSizer63->Add( chkGPIO0, 0, wxALL, 5 );
	
	chkGPIO1 = new wxCheckBox( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO1->Enable( false );
	
	fgSizer63->Add( chkGPIO1, 0, wxALL, 5 );
	
	chkGPIO2 = new wxCheckBox( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO2->Enable( false );
	
	fgSizer63->Add( chkGPIO2, 0, wxALL, 5 );
	
	chkGPIO3 = new wxCheckBox( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO3->Enable( false );
	
	fgSizer63->Add( chkGPIO3, 0, wxALL, 5 );
	
	
	sbSizer28->Add( fgSizer63, 1, wxEXPAND, 5 );
	
	
	fgSizer58->Add( sbSizer28, 1, wxEXPAND, 5 );
	
	wxString rgr_GPIO03_DIRChoices[] = { wxT("OUT"), wxT("IN") };
	int rgr_GPIO03_DIRNChoices = sizeof( rgr_GPIO03_DIRChoices ) / sizeof( wxString );
	rgr_GPIO03_DIR = new wxRadioBox( this, wxID_ANY, wxT("Direction LMS8"), wxDefaultPosition, wxDefaultSize, rgr_GPIO03_DIRNChoices, rgr_GPIO03_DIRChoices, 1, wxRA_SPECIFY_ROWS );
	rgr_GPIO03_DIR->SetSelection( 0 );
	fgSizer58->Add( rgr_GPIO03_DIR, 0, wxEXPAND, 5 );
	
	
	fgSizer57->Add( fgSizer58, 1, wxEXPAND, 5 );
	
	
	sbSizer160->Add( fgSizer57, 1, wxEXPAND, 5 );
	
	
	fgSizer305->Add( sbSizer160, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1601;
	sbSizer1601 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO 4 - 7") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer571;
	fgSizer571 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer571->SetFlexibleDirection( wxBOTH );
	fgSizer571->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer581;
	fgSizer581 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer581->SetFlexibleDirection( wxBOTH );
	fgSizer581->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer281;
	sbSizer281 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer631;
	fgSizer631 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer631->SetFlexibleDirection( wxBOTH );
	fgSizer631->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO4 = new wxCheckBox( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO4->Enable( false );
	
	fgSizer631->Add( chkGPIO4, 0, wxALL, 5 );
	
	chkGPIO5 = new wxCheckBox( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO5->Enable( false );
	
	fgSizer631->Add( chkGPIO5, 0, wxALL, 5 );
	
	chkGPIO6 = new wxCheckBox( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO6->Enable( false );
	
	fgSizer631->Add( chkGPIO6, 0, wxALL, 5 );
	
	chkGPIO7 = new wxCheckBox( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	chkGPIO7->Enable( false );
	
	fgSizer631->Add( chkGPIO7, 0, wxALL, 5 );
	
	
	sbSizer281->Add( fgSizer631, 1, wxEXPAND, 5 );
	
	
	fgSizer581->Add( sbSizer281, 1, wxEXPAND, 5 );
	
	wxString rgr_GPIO47_DIRChoices[] = { wxT("OUT"), wxT("IN") };
	int rgr_GPIO47_DIRNChoices = sizeof( rgr_GPIO47_DIRChoices ) / sizeof( wxString );
	rgr_GPIO47_DIR = new wxRadioBox( this, wxID_ANY, wxT("Direction LMS8"), wxDefaultPosition, wxDefaultSize, rgr_GPIO47_DIRNChoices, rgr_GPIO47_DIRChoices, 1, wxRA_SPECIFY_ROWS );
	rgr_GPIO47_DIR->SetSelection( 0 );
	fgSizer581->Add( rgr_GPIO47_DIR, 0, wxEXPAND, 5 );
	
	
	fgSizer571->Add( fgSizer581, 1, wxEXPAND, 5 );
	
	
	sbSizer1601->Add( fgSizer571, 1, wxEXPAND, 5 );
	
	
	fgSizer305->Add( sbSizer1601, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer16011;
	sbSizer16011 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO 8") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer5711;
	fgSizer5711 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5711->SetFlexibleDirection( wxBOTH );
	fgSizer5711->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer5811;
	fgSizer5811 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer5811->SetFlexibleDirection( wxBOTH );
	fgSizer5811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer2811;
	sbSizer2811 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("GPIO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6311;
	fgSizer6311 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer6311->SetFlexibleDirection( wxBOTH );
	fgSizer6311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO8 = new wxCheckBox( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6311->Add( chkGPIO8, 0, wxALL, 5 );
	
	
	sbSizer2811->Add( fgSizer6311, 1, wxEXPAND, 5 );
	
	
	fgSizer5811->Add( sbSizer2811, 1, wxEXPAND, 5 );
	
	
	fgSizer5711->Add( fgSizer5811, 1, wxEXPAND, 5 );
	
	
	sbSizer16011->Add( fgSizer5711, 1, wxEXPAND, 5 );
	
	
	fgSizer305->Add( sbSizer16011, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer160111;
	sbSizer160111 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Other") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer57111;
	fgSizer57111 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer57111->SetFlexibleDirection( wxBOTH );
	fgSizer57111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer58111;
	fgSizer58111 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer58111->SetFlexibleDirection( wxBOTH );
	fgSizer58111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer28111;
	sbSizer28111 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Enable Core LDO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer63111;
	fgSizer63111 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer63111->SetFlexibleDirection( wxBOTH );
	fgSizer63111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCORE_LDO_EN = new wxCheckBox( this, wxID_ANY, wxT("CORE_LDO_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer63111->Add( chkCORE_LDO_EN, 1, wxALL, 5 );
	
	
	sbSizer28111->Add( fgSizer63111, 1, wxEXPAND, 5 );
	
	
	fgSizer58111->Add( sbSizer28111, 1, wxEXPAND, 5 );
	
	
	fgSizer57111->Add( fgSizer58111, 1, wxEXPAND, 5 );
	
	
	sbSizer160111->Add( fgSizer57111, 1, wxEXPAND, 5 );
	
	
	fgSizer305->Add( sbSizer160111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer46;
	sbSizer46 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Status") ), wxVERTICAL );
	
	lblGPIOstatus = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	lblGPIOstatus->Wrap( -1 );
	sbSizer46->Add( lblGPIOstatus, 0, wxALL, 5 );
	
	
	fgSizer305->Add( sbSizer46, 1, wxEXPAND, 5 );
	
	btnUpdateClear = new wxButton( this, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	btnUpdateClear->SetMinSize( wxSize( 48,-1 ) );
	
	fgSizer305->Add( btnUpdateClear, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	this->SetSizer( fgSizer305 );
	this->Layout();
	fgSizer305->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	rgr_GPIO03_DIR->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GPIO_view::OnChangeGPIODirection ), NULL, this );
	rgr_GPIO47_DIR->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GPIO_view::OnChangeGPIODirection ), NULL, this );
	btnUpdateClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GPIO_view::OnUpdateClick ), NULL, this );
}

GPIO_view::~GPIO_view()
{
	// Disconnect Events
	rgr_GPIO03_DIR->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GPIO_view::OnChangeGPIODirection ), NULL, this );
	rgr_GPIO47_DIR->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( GPIO_view::OnChangeGPIODirection ), NULL, this );
	btnUpdateClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GPIO_view::OnUpdateClick ), NULL, this );
	
}
