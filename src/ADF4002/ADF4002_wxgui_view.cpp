///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ADF4002_wxgui_view.h"

///////////////////////////////////////////////////////////////////////////

ADF4002_wxgui_view::ADF4002_wxgui_view( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("ADF4002") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Reference Counter Latch") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Lock Detect Precision:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer3->Add( m_staticText1, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Anti-Backlash:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer3->Add( m_staticText11, 0, wxALL, 5 );
	
	m_staticText111 = new wxStaticText( this, wxID_ANY, wxT("Reference Counter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer3->Add( m_staticText111, 0, wxALL, 5 );
	
	cmbLDP = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbLDP->Append( wxT("Three Cycles") );
	cmbLDP->Append( wxT("Five Cycles") );
	cmbLDP->SetSelection( 0 );
	fgSizer3->Add( cmbLDP, 1, wxALL|wxEXPAND, 5 );
	
	cmbABW = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbABW->Append( wxT("2.9ns") );
	cmbABW->Append( wxT("6.0ns") );
	cmbABW->Append( wxT("2.9ns") );
	cmbABW->SetSelection( 0 );
	fgSizer3->Add( cmbABW, 1, wxALL|wxEXPAND, 5 );
	
	spinRCnt = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 16383, 125 );
	fgSizer3->Add( spinRCnt, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizer2->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("N Counter Latch") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("CP Gain:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer4->Add( m_staticText8, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("N Counter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer4->Add( m_staticText9, 0, wxALL, 5 );
	
	cmbCPG = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbCPG->Append( wxT("0") );
	cmbCPG->Append( wxT("1") );
	cmbCPG->SetSelection( 0 );
	cmbCPG->SetMinSize( wxSize( 65,-1 ) );
	
	fgSizer4->Add( cmbCPG, 0, wxALL, 5 );
	
	spinNCnt = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 8191, 384 );
	spinNCnt->SetMinSize( wxSize( 70,-1 ) );
	
	fgSizer4->Add( spinNCnt, 0, wxALL, 5 );
	
	
	sbSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	
	sbSizer1->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Function Latch") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Current Setting 1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer6->Add( m_staticText10, 0, wxALL, 5 );
	
	m_staticText112 = new wxStaticText( this, wxID_ANY, wxT("Time Counter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112->Wrap( -1 );
	fgSizer6->Add( m_staticText112, 0, wxALL, 5 );
	
	cmbCS1_f = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbCS1_f->Append( wxT("0") );
	cmbCS1_f->Append( wxT("1") );
	cmbCS1_f->Append( wxT("2") );
	cmbCS1_f->Append( wxT("3") );
	cmbCS1_f->Append( wxT("4") );
	cmbCS1_f->Append( wxT("5") );
	cmbCS1_f->Append( wxT("6") );
	cmbCS1_f->Append( wxT("7") );
	cmbCS1_f->SetSelection( 7 );
	fgSizer6->Add( cmbCS1_f, 1, wxALL|wxEXPAND, 5 );
	
	cmbTC_f = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbTC_f->Append( wxT("3") );
	cmbTC_f->Append( wxT("7") );
	cmbTC_f->Append( wxT("11") );
	cmbTC_f->Append( wxT("15") );
	cmbTC_f->Append( wxT("19") );
	cmbTC_f->Append( wxT("23") );
	cmbTC_f->Append( wxT("27") );
	cmbTC_f->Append( wxT("31") );
	cmbTC_f->Append( wxT("35") );
	cmbTC_f->Append( wxT("39") );
	cmbTC_f->Append( wxT("43") );
	cmbTC_f->Append( wxT("47") );
	cmbTC_f->Append( wxT("51") );
	cmbTC_f->Append( wxT("55") );
	cmbTC_f->Append( wxT("59") );
	cmbTC_f->Append( wxT("63") );
	cmbTC_f->SetSelection( 0 );
	fgSizer6->Add( cmbTC_f, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Current Setting 2:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer6->Add( m_staticText13, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Fastlock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer6->Add( m_staticText14, 0, wxALL, 5 );
	
	cmbCS2_f = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbCS2_f->Append( wxT("0") );
	cmbCS2_f->Append( wxT("1") );
	cmbCS2_f->Append( wxT("2") );
	cmbCS2_f->Append( wxT("3") );
	cmbCS2_f->Append( wxT("4") );
	cmbCS2_f->Append( wxT("5") );
	cmbCS2_f->Append( wxT("6") );
	cmbCS2_f->Append( wxT("7") );
	cmbCS2_f->SetSelection( 7 );
	fgSizer6->Add( cmbCS2_f, 1, wxALL|wxEXPAND, 5 );
	
	cmbFL_f = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbFL_f->Append( wxT("Disabled") );
	cmbFL_f->Append( wxT("Mode 1") );
	cmbFL_f->Append( wxT("Mode 2") );
	cmbFL_f->SetSelection( 0 );
	fgSizer6->Add( cmbFL_f, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer5->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Muxout Control:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer7->Add( m_staticText15, 0, wxALL, 5 );
	
	cmbMOC_f = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbMOC_f->Append( wxT("Three-State Output") );
	cmbMOC_f->Append( wxT("Digital Lock Detect") );
	cmbMOC_f->Append( wxT("N Divider Output") );
	cmbMOC_f->Append( wxT("DVdd") );
	cmbMOC_f->Append( wxT("R Divider Output") );
	cmbMOC_f->Append( wxT("N-Chan OD Lock Detect") );
	cmbMOC_f->Append( wxT("Serial Data Output") );
	cmbMOC_f->Append( wxT("DGND`") );
	cmbMOC_f->SetSelection( 1 );
	fgSizer7->Add( cmbMOC_f, 0, wxALL, 5 );
	
	wxString rgrPDP_fChoices[] = { wxT("Negative"), wxT("Positive") };
	int rgrPDP_fNChoices = sizeof( rgrPDP_fChoices ) / sizeof( wxString );
	rgrPDP_f = new wxRadioBox( this, wxID_ANY, wxT("PD Polarity"), wxDefaultPosition, wxDefaultSize, rgrPDP_fNChoices, rgrPDP_fChoices, 1, wxRA_SPECIFY_COLS );
	rgrPDP_f->SetSelection( 1 );
	fgSizer7->Add( rgrPDP_f, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer5->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rgrPD1_fChoices[] = { wxT("0"), wxT("1") };
	int rgrPD1_fNChoices = sizeof( rgrPD1_fChoices ) / sizeof( wxString );
	rgrPD1_f = new wxRadioBox( this, wxID_ANY, wxT("PD1"), wxDefaultPosition, wxDefaultSize, rgrPD1_fNChoices, rgrPD1_fChoices, 1, wxRA_SPECIFY_COLS );
	rgrPD1_f->SetSelection( 0 );
	fgSizer8->Add( rgrPD1_f, 0, wxALL, 5 );
	
	wxString rgrCR_fChoices[] = { wxT("Normal"), wxT("R && N Reset") };
	int rgrCR_fNChoices = sizeof( rgrCR_fChoices ) / sizeof( wxString );
	rgrCR_f = new wxRadioBox( this, wxID_ANY, wxT("Counter Reset"), wxDefaultPosition, wxDefaultSize, rgrCR_fNChoices, rgrCR_fChoices, 1, wxRA_SPECIFY_COLS );
	rgrCR_f->SetSelection( 0 );
	fgSizer8->Add( rgrCR_f, 0, wxALL, 5 );
	
	wxString rgrPD2_fChoices[] = { wxT("0"), wxT("1") };
	int rgrPD2_fNChoices = sizeof( rgrPD2_fChoices ) / sizeof( wxString );
	rgrPD2_f = new wxRadioBox( this, wxID_ANY, wxT("PD2"), wxDefaultPosition, wxDefaultSize, rgrPD2_fNChoices, rgrPD2_fChoices, 1, wxRA_SPECIFY_COLS );
	rgrPD2_f->SetSelection( 0 );
	fgSizer8->Add( rgrPD2_f, 0, wxALL, 5 );
	
	wxString rgrCPS_fChoices[] = { wxT("Normal"), wxT("Three-State") };
	int rgrCPS_fNChoices = sizeof( rgrCPS_fChoices ) / sizeof( wxString );
	rgrCPS_f = new wxRadioBox( this, wxID_ANY, wxT("CP State"), wxDefaultPosition, wxDefaultSize, rgrCPS_fNChoices, rgrCPS_fChoices, 1, wxRA_SPECIFY_COLS );
	rgrCPS_f->SetSelection( 0 );
	fgSizer8->Add( rgrCPS_f, 0, wxALL, 5 );
	
	
	fgSizer5->Add( fgSizer8, 1, wxEXPAND, 5 );
	
	
	sbSizer4->Add( fgSizer5, 0, wxEXPAND, 5 );
	
	
	sbSizer1->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Initialization Latch") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText101 = new wxStaticText( this, wxID_ANY, wxT("Current Setting 1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer61->Add( m_staticText101, 0, wxALL, 5 );
	
	m_staticText1121 = new wxStaticText( this, wxID_ANY, wxT("Time Counter:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1121->Wrap( -1 );
	fgSizer61->Add( m_staticText1121, 0, wxALL, 5 );
	
	cmbCS1_i = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbCS1_i->Append( wxT("0") );
	cmbCS1_i->Append( wxT("1") );
	cmbCS1_i->Append( wxT("2") );
	cmbCS1_i->Append( wxT("3") );
	cmbCS1_i->Append( wxT("4") );
	cmbCS1_i->Append( wxT("5") );
	cmbCS1_i->Append( wxT("6") );
	cmbCS1_i->Append( wxT("7") );
	cmbCS1_i->SetSelection( 7 );
	fgSizer61->Add( cmbCS1_i, 1, wxALL|wxEXPAND, 5 );
	
	cmbTC_i = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbTC_i->Append( wxT("3") );
	cmbTC_i->Append( wxT("7") );
	cmbTC_i->Append( wxT("11") );
	cmbTC_i->Append( wxT("15") );
	cmbTC_i->Append( wxT("19") );
	cmbTC_i->Append( wxT("23") );
	cmbTC_i->Append( wxT("27") );
	cmbTC_i->Append( wxT("31") );
	cmbTC_i->Append( wxT("35") );
	cmbTC_i->Append( wxT("39") );
	cmbTC_i->Append( wxT("43") );
	cmbTC_i->Append( wxT("47") );
	cmbTC_i->Append( wxT("51") );
	cmbTC_i->Append( wxT("55") );
	cmbTC_i->Append( wxT("59") );
	cmbTC_i->Append( wxT("63") );
	cmbTC_i->SetSelection( 0 );
	fgSizer61->Add( cmbTC_i, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText131 = new wxStaticText( this, wxID_ANY, wxT("Current Setting 2:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	fgSizer61->Add( m_staticText131, 0, wxALL, 5 );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, wxT("Fastlock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	fgSizer61->Add( m_staticText141, 0, wxALL, 5 );
	
	cmbCS2_i = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbCS2_i->Append( wxT("0") );
	cmbCS2_i->Append( wxT("1") );
	cmbCS2_i->Append( wxT("2") );
	cmbCS2_i->Append( wxT("3") );
	cmbCS2_i->Append( wxT("4") );
	cmbCS2_i->Append( wxT("5") );
	cmbCS2_i->Append( wxT("6") );
	cmbCS2_i->Append( wxT("7") );
	cmbCS2_i->SetSelection( 7 );
	fgSizer61->Add( cmbCS2_i, 1, wxALL|wxEXPAND, 5 );
	
	cmbFL_i = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbFL_i->Append( wxT("Disabled") );
	cmbFL_i->Append( wxT("Mode 1") );
	cmbFL_i->Append( wxT("Mode 2") );
	cmbFL_i->SetSelection( 0 );
	fgSizer61->Add( cmbFL_i, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer51->Add( fgSizer61, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer71;
	fgSizer71 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer71->SetFlexibleDirection( wxBOTH );
	fgSizer71->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText151 = new wxStaticText( this, wxID_ANY, wxT("Muxout Control:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	fgSizer71->Add( m_staticText151, 0, wxALL, 5 );
	
	cmbMOC_i = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbMOC_i->Append( wxT("Three-State Output") );
	cmbMOC_i->Append( wxT("Digital Lock Detect") );
	cmbMOC_i->Append( wxT("N Divider Output") );
	cmbMOC_i->Append( wxT("DVdd") );
	cmbMOC_i->Append( wxT("R Divider Output") );
	cmbMOC_i->Append( wxT("N-Chan OD Lock Detect") );
	cmbMOC_i->Append( wxT("Serial Data Output") );
	cmbMOC_i->Append( wxT("DGND`") );
	cmbMOC_i->SetSelection( 1 );
	fgSizer71->Add( cmbMOC_i, 0, wxALL, 5 );
	
	wxString rgrPDP_iChoices[] = { wxT("Negative"), wxT("Positive") };
	int rgrPDP_iNChoices = sizeof( rgrPDP_iChoices ) / sizeof( wxString );
	rgrPDP_i = new wxRadioBox( this, wxID_ANY, wxT("PD Polarity"), wxDefaultPosition, wxDefaultSize, rgrPDP_iNChoices, rgrPDP_iChoices, 1, wxRA_SPECIFY_COLS );
	rgrPDP_i->SetSelection( 1 );
	fgSizer71->Add( rgrPDP_i, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer51->Add( fgSizer71, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer81;
	fgSizer81 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer81->SetFlexibleDirection( wxBOTH );
	fgSizer81->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rgrPD1_iChoices[] = { wxT("0"), wxT("1") };
	int rgrPD1_iNChoices = sizeof( rgrPD1_iChoices ) / sizeof( wxString );
	rgrPD1_i = new wxRadioBox( this, wxID_ANY, wxT("PD1"), wxDefaultPosition, wxDefaultSize, rgrPD1_iNChoices, rgrPD1_iChoices, 1, wxRA_SPECIFY_COLS );
	rgrPD1_i->SetSelection( 0 );
	fgSizer81->Add( rgrPD1_i, 0, wxALL, 5 );
	
	wxString rgrCR_iChoices[] = { wxT("Normal"), wxT("R && N Reset") };
	int rgrCR_iNChoices = sizeof( rgrCR_iChoices ) / sizeof( wxString );
	rgrCR_i = new wxRadioBox( this, wxID_ANY, wxT("Counter Reset"), wxDefaultPosition, wxDefaultSize, rgrCR_iNChoices, rgrCR_iChoices, 1, wxRA_SPECIFY_COLS );
	rgrCR_i->SetSelection( 0 );
	fgSizer81->Add( rgrCR_i, 0, wxALL, 5 );
	
	wxString rgrPD2_iChoices[] = { wxT("0"), wxT("1") };
	int rgrPD2_iNChoices = sizeof( rgrPD2_iChoices ) / sizeof( wxString );
	rgrPD2_i = new wxRadioBox( this, wxID_ANY, wxT("PD2"), wxDefaultPosition, wxDefaultSize, rgrPD2_iNChoices, rgrPD2_iChoices, 1, wxRA_SPECIFY_COLS );
	rgrPD2_i->SetSelection( 0 );
	fgSizer81->Add( rgrPD2_i, 0, wxALL, 5 );
	
	wxString rgrCPS_iChoices[] = { wxT("Normal"), wxT("Three-State") };
	int rgrCPS_iNChoices = sizeof( rgrCPS_iChoices ) / sizeof( wxString );
	rgrCPS_i = new wxRadioBox( this, wxID_ANY, wxT("CP State"), wxDefaultPosition, wxDefaultSize, rgrCPS_iNChoices, rgrCPS_iChoices, 1, wxRA_SPECIFY_COLS );
	rgrCPS_i->SetSelection( 0 );
	fgSizer81->Add( rgrCPS_i, 0, wxALL, 5 );
	
	
	fgSizer51->Add( fgSizer81, 1, wxEXPAND, 5 );
	
	
	sbSizer41->Add( fgSizer51, 0, wxEXPAND, 5 );
	
	
	sbSizer1->Add( sbSizer41, 0, wxEXPAND, 5 );
	
	
	fgSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Calculation of R && N") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Fref [MHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer17->Add( m_staticText26, 0, wxALL, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Fvco [MHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer17->Add( m_staticText27, 0, wxALL, 5 );
	
	txtFref = new wxTextCtrl( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer17->Add( txtFref, 0, wxALL, 5 );
	
	txtFvco = new wxTextCtrl( this, wxID_ANY, wxT("40.00"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer17->Add( txtFvco, 0, wxALL, 5 );
	
	
	sbSizer5->Add( fgSizer17, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Fvco [MHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer18->Add( m_staticText28, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer18->Add( m_staticText29, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	lblFvco = new wxStaticText( this, wxID_ANY, wxT("Fvco"), wxDefaultPosition, wxDefaultSize, 0 );
	lblFvco->Wrap( -1 );
	fgSizer18->Add( lblFvco, 0, wxALIGN_LEFT|wxALL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("LCM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer18->Add( m_staticText31, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer18->Add( m_staticText32, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	lblFcomp = new wxStaticText( this, wxID_ANY, wxT("Fcomp"), wxDefaultPosition, wxDefaultSize, 0 );
	lblFcomp->Wrap( -1 );
	fgSizer18->Add( lblFcomp, 0, wxALIGN_LEFT|wxALL, 5 );
	
	
	sbSizer5->Add( fgSizer18, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnCalcSend = new wxButton( this, wxID_ANY, wxT("Calculate R, N && Upload"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( btnCalcSend, 0, wxALL|wxEXPAND, 5 );
	
	btnUpload = new wxButton( this, wxID_ANY, wxT("Upload"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( btnUpload, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer5->Add( fgSizer19, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer1->Add( sbSizer5, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnCalcSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ADF4002_wxgui_view::OnbtnCalcSendClick ), NULL, this );
	btnUpload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ADF4002_wxgui_view::OnbtnUploadClick ), NULL, this );
}

ADF4002_wxgui_view::~ADF4002_wxgui_view()
{
	// Disconnect Events
	btnCalcSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ADF4002_wxgui_view::OnbtnCalcSendClick ), NULL, this );
	btnUpload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ADF4002_wxgui_view::OnbtnUploadClick ), NULL, this );
	
}
