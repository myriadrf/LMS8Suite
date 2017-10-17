///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Si5351C_wxgui_view.h"

///////////////////////////////////////////////////////////////////////////

Si5351C_wxgui_view::Si5351C_wxgui_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Si5351C") ), wxVERTICAL );
	
	btnLoadFile = new wxButton( this, wxID_ANY, wxT("Upload register map from file"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( btnLoadFile, 0, wxALL|wxEXPAND, 5 );
	
	btnResetToDefaults = new wxButton( this, wxID_ANY, wxT("Reset register map to default"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( btnResetToDefaults, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("CLKIN Frequency [MHz]") ), wxVERTICAL );
	
	txtCLKIN_MHz = new wxTextCtrl( this, wxID_ANY, wxT("40.00"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( txtCLKIN_MHz, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Status") ), wxVERTICAL );
	
	lblStatus = new wxStaticText( this, wxID_ANY, wxT("SYS_INIT:  ?    SYS_INIT_STKY:  ?\nLOL_B:     ?    LOL_B_STKY:     ?\nLOL_A:     ?    LOL_A_STKY:     ?\nLOS:       ?    LOS_STKY:       ?"), wxDefaultPosition, wxSize( 250,70 ), 0 );
	lblStatus->Wrap( -1 );
	lblStatus->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 76, 90, 90, false, wxEmptyString ) );
	
	sbSizer3->Add( lblStatus, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnReadStatus = new wxButton( this, wxID_ANY, wxT("Read Status"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( btnReadStatus, 0, wxALL, 5 );
	
	btnClearStatus = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( btnClearStatus, 0, wxALL, 5 );
	
	
	sbSizer3->Add( fgSizer2, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer4->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	
	fgSizer1->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output Clock") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Pin Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer6->Add( m_staticText6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Enable Channel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer6->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Output Frequency [MHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer6->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Invert Output"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer6->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("PLL_CLK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer6->Add( m_staticText10, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	chkEN_CLK = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( chkEN_CLK, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	txtFreq_CLK = new wxTextCtrl( this, wxID_ANY, wxT("27.0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( txtFreq_CLK, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	chkInvert_CLK = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( chkInvert_CLK, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	fgSizer5->Add( fgSizer6, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 0, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnConfigure = new wxButton( this, wxID_ANY, wxT("Configure Clock"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( btnConfigure, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer5->Add( fgSizer7, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	
	fgSizer1->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnLoadFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnLoadFileClick ), NULL, this );
	btnResetToDefaults->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnResetToDefaultsClick ), NULL, this );
	btnReadStatus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnReadStatusClick ), NULL, this );
	btnClearStatus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnClearStatusClick ), NULL, this );
	btnConfigure->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnConfigureClockClick ), NULL, this );
}

Si5351C_wxgui_view::~Si5351C_wxgui_view()
{
	// Disconnect Events
	btnLoadFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnLoadFileClick ), NULL, this );
	btnResetToDefaults->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnResetToDefaultsClick ), NULL, this );
	btnReadStatus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnReadStatusClick ), NULL, this );
	btnClearStatus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnClearStatusClick ), NULL, this );
	btnConfigure->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Si5351C_wxgui_view::OnbtnConfigureClockClick ), NULL, this );
	
}
