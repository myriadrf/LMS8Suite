///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "lms8001_pnlChannel_view.h"
#include "lms8001_pnlConfig_view.h"
#include "lms8001_pnlHLMIX_view.h"
#include "lms8001_pnlLDO_view.h"
#include "lms8001_pnlPLLConfig_view.h"
#include "lms8001_pnlPLLProfiles_view.h"

#include "lms8001_wxgui.h"

///////////////////////////////////////////////////////////////////////////

mainPanel::mainPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer298;
	fgSizer298 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer298->AddGrowableCol( 0 );
	fgSizer298->AddGrowableRow( 1 );
	fgSizer298->SetFlexibleDirection( wxBOTH );
	fgSizer298->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer299;
	fgSizer299 = new wxFlexGridSizer( 0, 8, 0, 0 );
	fgSizer299->AddGrowableCol( 3 );
	fgSizer299->SetFlexibleDirection( wxBOTH );
	fgSizer299->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnNew = new wxButton( this, wxID_ANY, wxT("New"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btnNew->SetDefault(); 
	fgSizer299->Add( btnNew, 1, wxEXPAND, 0 );
	
	btnOpen = new wxButton( this, wxID_ANY, wxT("Open"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btnOpen->SetDefault(); 
	fgSizer299->Add( btnOpen, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
	
	btnSave = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	btnSave->SetDefault(); 
	fgSizer299->Add( btnSave, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
	
	wxString rgrChannelChoices[] = { wxT("A"), wxT("B"), wxT("C"), wxT("D") };
	int rgrChannelNChoices = sizeof( rgrChannelChoices ) / sizeof( wxString );
	rgrChannel = new wxRadioBox( this, wxID_ANY, wxT("CHANNEL"), wxDefaultPosition, wxDefaultSize, rgrChannelNChoices, rgrChannelChoices, 1, wxRA_SPECIFY_ROWS );
	rgrChannel->SetSelection( 0 );
	rgrChannel->Enable( false );
	
	fgSizer299->Add( rgrChannel, 0, wxALIGN_CENTER|wxALL, 0 );
	
	btnResetChip = new wxButton( this, ID_BTN_RESET_CHIP, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer299->Add( btnResetChip, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 0 );
	
	btnDownloadAll = new wxButton( this, ID_BTN_CHIP_TO_GUI, wxT("Chip-->GUI"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer299->Add( btnDownloadAll, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 0 );
	
	btnUploadAll = new wxButton( this, wxID_ANY, wxT("GUI-->Chip"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer299->Add( btnUploadAll, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 0 );
	
	btnUploadPanel = new wxButton( this, ID_BTN_UPLOAD_PANEL, wxT("Reload Panel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer299->Add( btnUploadPanel, 0, wxALL|wxEXPAND, 0 );
	
	
	fgSizer298->Add( fgSizer299, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP|wxBOTTOM, 5 );
	
	tabsNotebook = new wxNotebook( this, ID_TABS_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0 );
	mTabChipConfig = new lms8001_pnlConfig_view( tabsNotebook, ID_TAB_CHIP_CONFIG, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabChipConfig, wxT("Chip Configuration"), true );
	mTabLDO = new lms8001_pnlLDO_view( tabsNotebook, ID_TAB_LDO, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabLDO, wxT("LDOs Configuration"), false );
	mTabChannel = new lms8001_pnlChannel_view( tabsNotebook, ID_TAB_CHANNEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabChannel, wxT("LMS8001A - Channel"), false );
	mTabHLMIX = new lms8001_pnlHLMIX_view( tabsNotebook, ID_TAB_HLMIX, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabHLMIX, wxT("LMS8001B - High-Linearity Mixer"), false );
	mTabPLLConfig = new lms8001_pnlPLLConfig_view( tabsNotebook, ID_TAB_PLLCONFIG, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabPLLConfig, wxT("PLL Configuration"), false );
	mTabPLLProfiles = new lms8001_pnlPLLProfiles_view( tabsNotebook, ID_TAB_PLLPROFILES, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	tabsNotebook->AddPage( mTabPLLProfiles, wxT("PLL Profiles"), false );
	
	fgSizer298->Add( tabsNotebook, 1, wxALIGN_LEFT|wxALIGN_TOP|wxEXPAND, 0 );
	
	
	this->SetSizer( fgSizer298 );
	this->Layout();
	fgSizer298->Fit( this );
	
	// Connect Events
	btnNew->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnNewProject ), NULL, this );
	btnOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnOpenProject ), NULL, this );
	btnSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnSaveProject ), NULL, this );
	rgrChannel->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainPanel::OnSwitchChannel ), NULL, this );
	btnResetChip->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnResetChip ), NULL, this );
	btnDownloadAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnDownloadAll ), NULL, this );
	btnUploadAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnUploadAll ), NULL, this );
	btnUploadPanel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnUploadPanel ), NULL, this );
	tabsNotebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( mainPanel::Onnotebook_modulesPageChanged ), NULL, this );
}

mainPanel::~mainPanel()
{
	// Disconnect Events
	btnNew->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnNewProject ), NULL, this );
	btnOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnOpenProject ), NULL, this );
	btnSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnSaveProject ), NULL, this );
	rgrChannel->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainPanel::OnSwitchChannel ), NULL, this );
	btnResetChip->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnResetChip ), NULL, this );
	btnDownloadAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnDownloadAll ), NULL, this );
	btnUploadAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnUploadAll ), NULL, this );
	btnUploadPanel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainPanel::OnUploadPanel ), NULL, this );
	tabsNotebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( mainPanel::Onnotebook_modulesPageChanged ), NULL, this );
	
}

pnlConfig_view::pnlConfig_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_CONFIG = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_CONFIG = new wxPanel( ID_NOTEBOOK_CONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer20;
	sbSizer20 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO") ), wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer211;
	sbSizer211 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Value OUT") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer241;
	fgSizer241 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer241->SetFlexibleDirection( wxBOTH );
	fgSizer241->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO_OUT_SPI_0 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_OUT_SPI_0, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_0, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_1 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_OUT_SPI_1, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_1, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_2 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_OUT_SPI_2, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_2, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_3 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_OUT_SPI_3, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_3, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_4 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_OUT_SPI_4, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_4, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_5 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_OUT_SPI_5, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_5, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_6 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_OUT_SPI_6, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_6, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_7 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_OUT_SPI_7, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_7, 0, wxALL, 4 );
	
	chkGPIO_OUT_SPI_8 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_OUT_SPI_8, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241->Add( chkGPIO_OUT_SPI_8, 0, wxALL, 4 );
	
	
	sbSizer211->Add( fgSizer241, 0, wxEXPAND, 0 );
	
	
	sbSizer20->Add( sbSizer211, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer21;
	sbSizer21 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Source select") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer24->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 0 );
	
	cmbGPIO0_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO0_SEL->Append( wxT("from SPI") );
	cmbGPIO0_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO0_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO0_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO0_SEL->Append( wxT("Fast lock active") );
	cmbGPIO0_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO0_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText11 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer24->Add( m_staticText11, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );
	
	cmbGPIO1_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO1_SEL->Append( wxT("from SPI") );
	cmbGPIO1_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO1_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO1_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO1_SEL->Append( wxT("Fast lock active") );
	cmbGPIO1_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO1_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer24->Add( m_staticText111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO2_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO2_SEL->Append( wxT("from SPI") );
	cmbGPIO2_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO2_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO2_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO2_SEL->Append( wxT("Fast lock active") );
	cmbGPIO2_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO2_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText1111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1111->Wrap( -1 );
	fgSizer24->Add( m_staticText1111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO3_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO3_SEL->Append( wxT("from SPI") );
	cmbGPIO3_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO3_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO3_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO3_SEL->Append( wxT("Fast lock active") );
	cmbGPIO3_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO3_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText11111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11111->Wrap( -1 );
	fgSizer24->Add( m_staticText11111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO4_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO4_SEL->Append( wxT("from SPI") );
	cmbGPIO4_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO4_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO4_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO4_SEL->Append( wxT("Fast lock active") );
	cmbGPIO4_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO4_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText111111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111111->Wrap( -1 );
	fgSizer24->Add( m_staticText111111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO5_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO5_SEL->Append( wxT("from SPI") );
	cmbGPIO5_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO5_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO5_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO5_SEL->Append( wxT("Fast lock active") );
	cmbGPIO5_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO5_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText1111111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1111111->Wrap( -1 );
	fgSizer24->Add( m_staticText1111111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO6_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO6_SEL->Append( wxT("from SPI") );
	cmbGPIO6_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO6_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO6_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO6_SEL->Append( wxT("Fast lock active") );
	cmbGPIO6_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO6_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText11111111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11111111->Wrap( -1 );
	fgSizer24->Add( m_staticText11111111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO7_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO7_SEL->Append( wxT("from SPI") );
	cmbGPIO7_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO7_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO7_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO7_SEL->Append( wxT("Fast lock active") );
	cmbGPIO7_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO7_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	m_staticText111111111 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111111111->Wrap( -1 );
	fgSizer24->Add( m_staticText111111111, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	cmbGPIO8_SEL = new wxComboBox( ID_PANEL_CONFIG, ID_GPIO0_SEL, wxT("from SPI"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbGPIO8_SEL->Append( wxT("from SPI") );
	cmbGPIO8_SEL->Append( wxT("PLL_LOCK") );
	cmbGPIO8_SEL->Append( wxT("VTUNE_LOW") );
	cmbGPIO8_SEL->Append( wxT("VTUNE_HIGH") );
	cmbGPIO8_SEL->Append( wxT("Fast lock active") );
	cmbGPIO8_SEL->SetSelection( 0 );
	fgSizer24->Add( cmbGPIO8_SEL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 0 );
	
	
	sbSizer21->Add( fgSizer24, 0, wxEXPAND, 0 );
	
	
	sbSizer20->Add( sbSizer21, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer2111;
	sbSizer2111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Value IN") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2411;
	fgSizer2411 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer2411->SetFlexibleDirection( wxBOTH );
	fgSizer2411->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO_IN_0 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_IN_0, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_0, 0, wxALL, 4 );
	
	chkGPIO_IN_1 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_IN_1, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_1, 0, wxALL, 4 );
	
	chkGPIO_IN_2 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_IN_2, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_2, 0, wxALL, 4 );
	
	chkGPIO_IN_3 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_IN_3, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_3, 0, wxALL, 4 );
	
	chkGPIO_IN_4 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_IN_4, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_4, 0, wxALL, 4 );
	
	chkGPIO_IN_5 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_IN_5, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_5, 0, wxALL, 4 );
	
	chkGPIO_IN_6 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_IN_6, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_6, 0, wxALL, 4 );
	
	chkGPIO_IN_7 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_IN_7, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_7, 0, wxALL, 4 );
	
	chkGPIO_IN_8 = new wxCheckBox( ID_PANEL_CONFIG, IID_GPIO_IN_8, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411->Add( chkGPIO_IN_8, 0, wxALL, 4 );
	
	
	sbSizer2111->Add( fgSizer2411, 0, wxEXPAND, 0 );
	
	
	sbSizer20->Add( sbSizer2111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer21111;
	sbSizer21111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Pull-up") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer24111;
	fgSizer24111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer24111->SetFlexibleDirection( wxBOTH );
	fgSizer24111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO_PE_0 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_0, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_0, 0, wxALL, 4 );
	
	chkGPIO_PE_1 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_1, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_1, 0, wxALL, 4 );
	
	chkGPIO_PE_2 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_2, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_2, 0, wxALL, 4 );
	
	chkGPIO_PE_3 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_3, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_3, 0, wxALL, 4 );
	
	chkGPIO_PE_4 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_4, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_4, 0, wxALL, 4 );
	
	chkGPIO_PE_5 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_5, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_5, 0, wxALL, 4 );
	
	chkGPIO_PE_6 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_6, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_6, 0, wxALL, 4 );
	
	chkGPIO_PE_7 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_7, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_7, 0, wxALL, 4 );
	
	chkGPIO_PE_8 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_PE_8, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24111->Add( chkGPIO_PE_8, 0, wxALL, 4 );
	
	
	sbSizer21111->Add( fgSizer24111, 0, wxEXPAND, 0 );
	
	
	sbSizer20->Add( sbSizer21111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer211111;
	sbSizer211111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Driver strength") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer241111;
	fgSizer241111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer241111->SetFlexibleDirection( wxBOTH );
	fgSizer241111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO_DS_0 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_0, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_0, 0, wxALL, 4 );
	
	chkGPIO_DS_1 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_1, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_1, 0, wxALL, 4 );
	
	chkGPIO_DS_2 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_2, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_2, 0, wxALL, 4 );
	
	chkGPIO_DS_3 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_3, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_3, 0, wxALL, 4 );
	
	chkGPIO_DS_4 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_4, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_4, 0, wxALL, 4 );
	
	chkGPIO_DS_5 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_5, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_5, 0, wxALL, 4 );
	
	chkGPIO_DS_6 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_6, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_6, 0, wxALL, 4 );
	
	chkGPIO_DS_7 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_7, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_7, 0, wxALL, 4 );
	
	chkGPIO_DS_8 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_DS_8, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer241111->Add( chkGPIO_DS_8, 0, wxALL, 4 );
	
	
	sbSizer211111->Add( fgSizer241111, 0, wxEXPAND, 0 );
	
	m_staticText37 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("0 - 4 mA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	sbSizer211111->Add( m_staticText37, 0, wxALL, 4 );
	
	m_staticText372 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("1 - 8 mA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText372->Wrap( -1 );
	sbSizer211111->Add( m_staticText372, 0, wxALL, 5 );
	
	
	sbSizer20->Add( sbSizer211111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2111111;
	sbSizer2111111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Input/Output") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2411111;
	fgSizer2411111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer2411111->SetFlexibleDirection( wxBOTH );
	fgSizer2411111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkGPIO_InO_0 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_0, wxT("GPIO 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_0, 0, wxALL, 4 );
	
	chkGPIO_InO_1 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_1, wxT("GPIO 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_1, 0, wxALL, 4 );
	
	chkGPIO_InO_2 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_2, wxT("GPIO 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_2, 0, wxALL, 4 );
	
	chkGPIO_InO_3 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_3, wxT("GPIO 3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_3, 0, wxALL, 4 );
	
	chkGPIO_InO_4 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_4, wxT("GPIO 4"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_4, 0, wxALL, 4 );
	
	chkGPIO_InO_5 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_5, wxT("GPIO 5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_5, 0, wxALL, 4 );
	
	chkGPIO_InO_6 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_6, wxT("GPIO 6"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_6, 0, wxALL, 4 );
	
	chkGPIO_InO_7 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_7, wxT("GPIO 7"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_7, 0, wxALL, 4 );
	
	chkGPIO_InO_8 = new wxCheckBox( ID_PANEL_CONFIG, ID_GPIO_InO_8, wxT("GPIO 8"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2411111->Add( chkGPIO_InO_8, 0, wxALL, 4 );
	
	
	sbSizer2111111->Add( fgSizer2411111, 0, wxEXPAND, 0 );
	
	m_staticText371 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("0 - Out"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText371->Wrap( -1 );
	sbSizer2111111->Add( m_staticText371, 0, wxALL, 4 );
	
	m_staticText3711 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("1 - In"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3711->Wrap( -1 );
	sbSizer2111111->Add( m_staticText3711, 0, wxALL, 5 );
	
	
	sbSizer20->Add( sbSizer2111111, 1, wxEXPAND, 5 );
	
	
	fgSizer22->Add( sbSizer20, 0, wxEXPAND, 0 );
	
	wxFlexGridSizer* fgSizer27;
	fgSizer27 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer27->AddGrowableCol( 2 );
	fgSizer27->SetFlexibleDirection( wxBOTH );
	fgSizer27->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("SPI") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer143;
	fgSizer143 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer143->SetFlexibleDirection( wxBOTH );
	fgSizer143->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Driver strength") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer69;
	fgSizer69 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer69->SetFlexibleDirection( wxBOTH );
	fgSizer69->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rgrSPI_SDIO_DSChoices[] = { wxT("4 mA"), wxT("8 mA") };
	int rgrSPI_SDIO_DSNChoices = sizeof( rgrSPI_SDIO_DSChoices ) / sizeof( wxString );
	rgrSPI_SDIO_DS = new wxRadioBox( ID_PANEL_CONFIG, ID_SPI_SDIO_DS, wxT("SDIO pad"), wxDefaultPosition, wxDefaultSize, rgrSPI_SDIO_DSNChoices, rgrSPI_SDIO_DSChoices, 1, wxRA_SPECIFY_COLS );
	rgrSPI_SDIO_DS->SetSelection( 0 );
	fgSizer69->Add( rgrSPI_SDIO_DS, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	wxString rgrSPI_SDO_DSChoices[] = { wxT("4 mA"), wxT("8 mA") };
	int rgrSPI_SDO_DSNChoices = sizeof( rgrSPI_SDO_DSChoices ) / sizeof( wxString );
	rgrSPI_SDO_DS = new wxRadioBox( ID_PANEL_CONFIG, ID_SPI_SDO_DS, wxT("SDO pad"), wxPoint( -1,-1 ), wxDefaultSize, rgrSPI_SDO_DSNChoices, rgrSPI_SDO_DSChoices, 1, wxRA_SPECIFY_COLS );
	rgrSPI_SDO_DS->SetSelection( 0 );
	fgSizer69->Add( rgrSPI_SDO_DS, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	
	sbSizer7->Add( fgSizer69, 1, wxEXPAND, 5 );
	
	
	fgSizer143->Add( sbSizer7, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer144;
	fgSizer144 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer144->SetFlexibleDirection( wxBOTH );
	fgSizer144->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizerEngagePullUp;
	sbSizerEngagePullUp = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Pull-up") ), wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer691;
	fgSizer691 = new wxFlexGridSizer( 3, 0, 0, 0 );
	fgSizer691->SetFlexibleDirection( wxBOTH );
	fgSizer691->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkSPI_SDIO_PE = new wxCheckBox( ID_PANEL_CONFIG, ID_SPI_SDIO_PE, wxT("SDIO pad"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSPI_SDIO_PE->SetValue(true); 
	fgSizer691->Add( chkSPI_SDIO_PE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	chkSPI_SDO_PE = new wxCheckBox( ID_PANEL_CONFIG, ID_SPI_SDO_PE, wxT("SDO pad"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSPI_SDO_PE->SetValue(true); 
	fgSizer691->Add( chkSPI_SDO_PE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	chkSPI_SCLK_PE = new wxCheckBox( ID_PANEL_CONFIG, ID_SPI_SDO_PE, wxT("SCLK pad"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSPI_SCLK_PE->SetValue(true); 
	fgSizer691->Add( chkSPI_SCLK_PE, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	chkSPI_SEN_PE = new wxCheckBox( ID_PANEL_CONFIG, ID_SPI_SEN_PE, wxT("SEN pad"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSPI_SEN_PE->SetValue(true); 
	fgSizer691->Add( chkSPI_SEN_PE, 0, wxALL, 0 );
	
	
	sbSizerEngagePullUp->Add( fgSizer691, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL|wxEXPAND, 0 );
	
	
	fgSizer144->Add( sbSizerEngagePullUp, 0, wxALIGN_LEFT|wxALIGN_TOP|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer692;
	fgSizer692 = new wxFlexGridSizer( 0, 0, 0, 0 );
	fgSizer692->AddGrowableCol( 0 );
	fgSizer692->SetFlexibleDirection( wxBOTH );
	fgSizer692->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rgrSPIMODEChoices[] = { wxT("3 wire"), wxT("4 wire") };
	int rgrSPIMODENChoices = sizeof( rgrSPIMODEChoices ) / sizeof( wxString );
	rgrSPIMODE = new wxRadioBox( ID_PANEL_CONFIG, ID_SPI_SDIO_DS, wxT("SPI Mode"), wxDefaultPosition, wxDefaultSize, rgrSPIMODENChoices, rgrSPIMODEChoices, 2, wxRA_SPECIFY_COLS );
	rgrSPIMODE->SetSelection( 1 );
	fgSizer692->Add( rgrSPIMODE, 0, wxALIGN_LEFT|wxEXPAND, 0 );
	
	
	fgSizer144->Add( fgSizer692, 0, wxEXPAND, 0 );
	
	
	fgSizer143->Add( fgSizer144, 1, wxEXPAND, 5 );
	
	
	sbSizer11->Add( fgSizer143, 0, wxEXPAND, 5 );
	
	
	fgSizer27->Add( sbSizer11, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer28;
	sbSizer28 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Temp. Sensor") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer29;
	sbSizer29 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Control") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 3, 0, 0, 0 );
	fgSizer26->SetFlexibleDirection( wxBOTH );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkTEMP_SENS_EN = new wxCheckBox( ID_PANEL_CONFIG, ID_TEMP_SENS_EN, wxT("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer26->Add( chkTEMP_SENS_EN, 0, wxALL, 0 );
	
	chkTEMP_SENS_CLKEN = new wxCheckBox( ID_PANEL_CONFIG, ID_TEMP_SENS_CLKEN, wxT("Clock enable"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer26->Add( chkTEMP_SENS_CLKEN, 0, wxALL, 0 );
	
	chkTEMP_START_CONV = new wxCheckBox( ID_PANEL_CONFIG, ID_TEMP_START_CONV, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer26->Add( chkTEMP_START_CONV, 0, wxALL, 0 );
	
	
	sbSizer29->Add( fgSizer26, 1, wxALIGN_TOP|wxEXPAND, 5 );
	
	
	sbSizer28->Add( sbSizer29, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer154;
	fgSizer154 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer154->SetFlexibleDirection( wxBOTH );
	fgSizer154->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer153;
	fgSizer153 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer153->SetFlexibleDirection( wxBOTH );
	fgSizer153->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText280 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer153->Add( m_staticText280, 0, wxALL, 5 );
	
	sttxtTEMP_READ = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtTEMP_READ->Wrap( -1 );
	fgSizer153->Add( sttxtTEMP_READ, 0, wxLEFT|wxTOP, 5 );
	
	m_staticText2801 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("T [°C]:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2801->Wrap( -1 );
	fgSizer153->Add( m_staticText2801, 0, wxALIGN_TOP|wxLEFT, 5 );
	
	sttxtTemp = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("000.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtTemp->Wrap( -1 );
	fgSizer153->Add( sttxtTemp, 0, wxALIGN_TOP|wxLEFT, 5 );
	
	
	fgSizer154->Add( fgSizer153, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155;
	fgSizer155 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer155->SetFlexibleDirection( wxBOTH );
	fgSizer155->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	btnTempRead = new wxButton( ID_PANEL_CONFIG, wxID_ANY, wxT("Measure"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155->Add( btnTempRead, 0, wxLEFT, 5 );
	
	btnTempCalibrate = new wxButton( ID_PANEL_CONFIG, wxID_ANY, wxT("Calibrate"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155->Add( btnTempCalibrate, 0, wxALL, 5 );
	
	
	fgSizer154->Add( fgSizer155, 1, wxEXPAND, 5 );
	
	
	sbSizer28->Add( fgSizer154, 1, wxEXPAND, 5 );
	
	
	fgSizer27->Add( sbSizer28, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CONFIG, wxID_ANY, wxT("Chip Info") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer28;
	fgSizer28 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer28->AddGrowableCol( 0 );
	fgSizer28->SetFlexibleDirection( wxBOTH );
	fgSizer28->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText40 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("Version:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	fgSizer28->Add( m_staticText40, 0, wxALL, 5 );
	
	sttxtVER = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtVER->Wrap( -1 );
	fgSizer28->Add( sttxtVER, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("Revision:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer28->Add( m_staticText41, 0, wxALL, 5 );
	
	sttxtREV = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtREV->Wrap( -1 );
	fgSizer28->Add( sttxtREV, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("Mask:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer28->Add( m_staticText42, 0, wxALL, 5 );
	
	sttxtMASK = new wxStaticText( ID_PANEL_CONFIG, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtMASK->Wrap( -1 );
	fgSizer28->Add( sttxtMASK, 0, wxALL, 5 );
	
	
	sbSizer31->Add( fgSizer28, 0, wxEXPAND, 5 );
	
	
	fgSizer27->Add( sbSizer31, 1, wxEXPAND, 5 );
	
	
	fgSizer22->Add( fgSizer27, 0, wxEXPAND, 5 );
	
	
	ID_PANEL_CONFIG->SetSizer( fgSizer22 );
	ID_PANEL_CONFIG->Layout();
	fgSizer22->Fit( ID_PANEL_CONFIG );
	ID_NOTEBOOK_CONFIG->AddPage( ID_PANEL_CONFIG, wxT("Config"), false );
	
	fgSizer68->Add( ID_NOTEBOOK_CONFIG, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	chkGPIO_OUT_SPI_0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO0_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO1_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO2_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO3_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO4_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO5_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO6_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO7_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO8_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPI_SDIO_DS->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPI_SDO_DS->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SDIO_PE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SDO_PE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SCLK_PE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SEN_PE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPIMODE->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_SENS_EN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_SENS_CLKEN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_START_CONV->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	sttxtTemp->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlConfig_view::OnUpdateUI_sttxtTemp ), NULL, this );
	btnTempRead->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlConfig_view::OnClick_btnTempRead ), NULL, this );
	btnTempCalibrate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlConfig_view::OnClick_btnTempCalibrate ), NULL, this );
}

pnlConfig_view::~pnlConfig_view()
{
	// Disconnect Events
	chkGPIO_OUT_SPI_0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_OUT_SPI_8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO0_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO1_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO2_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO3_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO4_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO5_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO6_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO7_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	cmbGPIO8_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_IN_8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_PE_8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_DS_8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkGPIO_InO_8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPI_SDIO_DS->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPI_SDO_DS->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SDIO_PE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SDO_PE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SCLK_PE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPI_SEN_PE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	rgrSPIMODE->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_SENS_EN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_SENS_CLKEN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	chkTEMP_START_CONV->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlConfig_view::ParameterChangeHandler ), NULL, this );
	sttxtTemp->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlConfig_view::OnUpdateUI_sttxtTemp ), NULL, this );
	btnTempRead->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlConfig_view::OnClick_btnTempRead ), NULL, this );
	btnTempCalibrate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlConfig_view::OnClick_btnTempCalibrate ), NULL, this );
	
}

pnlLDO_view::pnlLDO_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_LDO = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_LDO = new wxPanel( ID_NOTEBOOK_LDO, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer69;
	fgSizer69 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer69->SetFlexibleDirection( wxBOTH );
	fgSizer69->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer29;
	fgSizer29 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer29->SetFlexibleDirection( wxBOTH );
	fgSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer45;
	sbSizer45 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Power Controls") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer35;
	sbSizer35 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Bias") ), wxVERTICAL );
	
	chkPD_FRP_BIAS = new wxCheckBox( ID_PANEL_LDO, ID_PD_FRP_BIAS, wxT("PD_FRP_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer35->Add( chkPD_FRP_BIAS, 0, wxALL, 0 );
	
	chkPD_F_BIAS = new wxCheckBox( ID_PANEL_LDO, ID_PD_F_BIAS, wxT("PD_F_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer35->Add( chkPD_F_BIAS, 0, wxALL, 0 );
	
	chkPD_PTRP_BIAS = new wxCheckBox( ID_PANEL_LDO, ID_PD_PTRP_BIAS, wxT("PD_PTRP_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer35->Add( chkPD_PTRP_BIAS, 0, wxALL, 0 );
	
	chkPD_PT_BIAS = new wxCheckBox( ID_PANEL_LDO, ID_PD_PT_BIAS, wxT("PD_PT_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer35->Add( chkPD_PT_BIAS, 0, wxALL, 0 );
	
	chkPD_BIAS = new wxCheckBox( ID_PANEL_LDO, ID_PD_BIAS, wxT("PD_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer35->Add( chkPD_BIAS, 0, wxALL, 0 );
	
	
	sbSizer45->Add( sbSizer35, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer481;
	sbSizer481 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("LOBUF") ), wxVERTICAL );
	
	chkEN_LDO_LOBUFA = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_LOBUFA, wxT("EN_LDO_LOBUFA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer481->Add( chkEN_LDO_LOBUFA, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0 );
	
	chkEN_LDO_LOBUFB = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_LOBUFB, wxT("EN_LDO_LOBUFB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer481->Add( chkEN_LDO_LOBUFB, 0, wxALL, 0 );
	
	chkEN_LDO_LOBUFC = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_LOBUFC, wxT("EN_LDO_LOBUFC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer481->Add( chkEN_LDO_LOBUFC, 0, wxALL, 0 );
	
	chkEN_LDO_LOBUFD = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_LOBUFC, wxT("EN_LDO_LOBUFD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer481->Add( chkEN_LDO_LOBUFD, 0, wxALL, 0 );
	
	
	sbSizer45->Add( sbSizer481, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4811;
	sbSizer4811 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	chkEN_LDO_HFLNAA = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_HFLNAA, wxT("EN_LDO_HFLNAA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4811->Add( chkEN_LDO_HFLNAA, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0 );
	
	chkEN_LDO_HFLNAB = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_HFLNAB, wxT("EN_LDO_HFLNAB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4811->Add( chkEN_LDO_HFLNAB, 0, wxALL, 0 );
	
	chkEN_LDO_HFLNAC = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_HFLNAC, wxT("EN_LDO_HFLNAC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4811->Add( chkEN_LDO_HFLNAC, 0, wxALL, 0 );
	
	chkEN_LDO_HFLNAD = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_HFLNAD, wxT("EN_LDO_HFLNAD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4811->Add( chkEN_LDO_HFLNAD, 0, wxALL, 0 );
	
	
	sbSizer45->Add( sbSizer4811, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer48111;
	sbSizer48111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("PLL") ), wxVERTICAL );
	
	chkEN_LDO_CLK_BUF = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_CLK_BUF, wxT("EN_LDO_CLK_BUF"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer48111->Add( chkEN_LDO_CLK_BUF, 0, wxALL, 0 );
	
	chkEN_LDO_PLL_DIV = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_PLL_DIV, wxT("EN_LDO_PLL_DIV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer48111->Add( chkEN_LDO_PLL_DIV, 0, wxALL, 0 );
	
	chkEN_LDO_PLL_CP = new wxCheckBox( ID_PANEL_LDO, ID_EN_LDO_PLL_CP, wxT("EN_LDO_PLL_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer48111->Add( chkEN_LDO_PLL_CP, 0, wxALL, 0 );
	
	
	sbSizer45->Add( sbSizer48111, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer481111;
	sbSizer481111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Digital core") ), wxVERTICAL );
	
	chkPD_LDO_DIG_CORE = new wxCheckBox( ID_PANEL_LDO, ID_PD_LDO_DIG_CORE, wxT("PD_LDO_DIG_CORE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer481111->Add( chkPD_LDO_DIG_CORE, 0, wxALL, 0 );
	
	
	sbSizer45->Add( sbSizer481111, 0, wxEXPAND, 5 );
	
	
	fgSizer29->Add( sbSizer45, 1, wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer29, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer30;
	fgSizer30 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer30->SetFlexibleDirection( wxBOTH );
	fgSizer30->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer46;
	sbSizer46 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Short noise filter resistor") ), wxVERTICAL );
	
	chkSPDUP_LDO_LOBUFA = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_LOBUFA, wxT("SPDUP_LDO_LOBUFA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_LOBUFA, 0, wxALL, 0 );
	
	chkSPDUP_LDO_LOBUFB = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_LOBUFB, wxT("SPDUP_LDO_LOBUFB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_LOBUFB, 0, wxALL, 0 );
	
	chkSPDUP_LDO_LOBUFC = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_LOBUFC, wxT("SPDUP_LDO_LOBUFC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_LOBUFC, 0, wxALL, 0 );
	
	chkSPDUP_LDO_LOBUFD = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_LOBUFD, wxT("SPDUP_LDO_LOBUFD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_LOBUFD, 0, wxALL, 0 );
	
	chkSPDUP_LDO_HFLNAA = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_HFLNAA, wxT("SPDUP_LDO_HFLNAA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_HFLNAA, 0, wxALL, 0 );
	
	chkSPDUP_LDO_HFLNAB = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_HFLNAB, wxT("SPDUP_LDO_HFLNAB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_HFLNAB, 0, wxALL, 0 );
	
	chkSPDUP_LDO_HFLNAC = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_HFLNAC, wxT("SPDUP_LDO_HFLNAC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_HFLNAC, 0, wxALL, 0 );
	
	chkSPDUP_LDO_HFLNAD = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_HFLNAD, wxT("SPDUP_LDO_HFLNAD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_HFLNAD, 0, wxALL, 0 );
	
	chkSPDUP_LDO_CLK_BUF = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_CLK_BUF, wxT("SPDUP_LDO_CLK_BUF"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_CLK_BUF, 0, wxALL, 0 );
	
	chkSPDUP_LDO_PLL_DIV = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_PLL_DIV, wxT("SPDUP_LDO_PLL_DIV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_PLL_DIV, 0, wxALL, 0 );
	
	chkSPDUP_LDO_PLL_CP = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_PLL_CP, wxT("SPDUP_LDO_PLL_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_PLL_CP, 0, wxALL, 0 );
	
	chkSPDUP_LDO_DIG_CORE = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_DIG_CORE, wxT("SPDUP_LDO_DIG_CORE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer46->Add( chkSPDUP_LDO_DIG_CORE, 0, wxALL, 0 );
	
	
	fgSizer30->Add( sbSizer46, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer461;
	sbSizer461 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Bias") ), wxVERTICAL );
	
	chkEN_LOADIMP_LDO_LOBUFA = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_LOBUFA, wxT("EN_LOADIMP_LDO_LOBUFA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_LOBUFA, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_LOBUFB = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_LOBUFB, wxT("EN_LOADIMP_LDO_LOBUFB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_LOBUFB, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_LOBUFC = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_LOBUFC, wxT("EN_LOADIMP_LDO_LOBUFC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_LOBUFC, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_LOBUFD = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_LOBUFD, wxT("EN_LOADIMP_LDO_LOBUFD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_LOBUFD, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_HFLNAA = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_HFLNAA, wxT("EN_LOADIMP_LDO_HFLNAA"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_HFLNAA, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_HFLNAB = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_HFLNAB, wxT("EN_LOADIMP_LDO_HFLNAB"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_HFLNAB, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_HFLNAC = new wxCheckBox( ID_PANEL_LDO, ID_SPDUP_LDO_HFLNAC, wxT("EN_LOADIMP_LDO_HFLNAC"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_HFLNAC, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_HFLNAD = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_HFLNAD, wxT("EN_LOADIMP_LDO_HFLNAD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_HFLNAD, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_CLK_BUF = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_CLK_BUF, wxT("EN_LOADIMP_LDO_CLK_BUF"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_CLK_BUF, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_PLL_DIV = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_PLL_DIV, wxT("EN_LOADIMP_LDO_PLL_DIV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_PLL_DIV, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_PLL_CP = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_PLL_CP, wxT("EN_LOADIMP_LDO_PLL_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_PLL_CP, 0, wxALL, 0 );
	
	chkEN_LOADIMP_LDO_DIG_CORE = new wxCheckBox( ID_PANEL_LDO, ID_EN_LOADIMP_LDO_DIG_CORE, wxT("EN_LOADIMP_LDO_DIG_CORE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer461->Add( chkEN_LOADIMP_LDO_DIG_CORE, 0, wxALL, 0 );
	
	
	fgSizer30->Add( sbSizer461, 1, wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer30, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer31;
	fgSizer31 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer31->SetFlexibleDirection( wxBOTH );
	fgSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer50;
	sbSizer50 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Output Voltage") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer32;
	fgSizer32 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer32->SetFlexibleDirection( wxBOTH );
	fgSizer32->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText44 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_LOBUFA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	fgSizer32->Add( m_staticText44, 0, wxALL, 4 );
	
	cmbRDIV_LOBUFA = new wxComboBox( ID_PANEL_LDO, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_LOBUFA, 0, wxALL, 0 );
	
	m_staticText441 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_LOBUFB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText441->Wrap( -1 );
	fgSizer32->Add( m_staticText441, 0, wxALL, 4 );
	
	cmbRDIV_LOBUFB = new wxComboBox( ID_PANEL_LDO, ID_RDIV_LOBUFB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_LOBUFB, 0, wxALL, 0 );
	
	m_staticText4411 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_LOBUFC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4411->Wrap( -1 );
	fgSizer32->Add( m_staticText4411, 0, wxALL, 4 );
	
	cmbRDIV_LOBUFC = new wxComboBox( ID_PANEL_LDO, ID_RDIV_LOBUFC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_LOBUFC, 0, wxALL, 0 );
	
	m_staticText44111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_LOBUFD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44111->Wrap( -1 );
	fgSizer32->Add( m_staticText44111, 0, wxALL, 4 );
	
	cmbRDIV_LOBUFD = new wxComboBox( ID_PANEL_LDO, ID_RDIV_LOBUFD, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_LOBUFD, 0, wxALL, 0 );
	
	m_staticText442 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_HFLNAA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText442->Wrap( -1 );
	fgSizer32->Add( m_staticText442, 0, wxALL, 5 );
	
	cmbRDIV_HFLNAA = new wxComboBox( ID_PANEL_LDO, ID_RDIV_HFLNAA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_HFLNAA, 0, wxALL, 0 );
	
	m_staticText4421 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_HFLNAB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4421->Wrap( -1 );
	fgSizer32->Add( m_staticText4421, 0, wxALL, 4 );
	
	cmbRDIV_HFLNAB = new wxComboBox( ID_PANEL_LDO, ID_RDIV_HFLNAB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_HFLNAB, 0, wxALL, 0 );
	
	m_staticText44211 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_HFLNAC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44211->Wrap( -1 );
	fgSizer32->Add( m_staticText44211, 0, wxALL, 4 );
	
	cmbRDIV_HFLNAC = new wxComboBox( ID_PANEL_LDO, ID_RDIV_HFLNAC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_HFLNAC, 0, wxALL, 0 );
	
	m_staticText442111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_HFLNAD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText442111->Wrap( -1 );
	fgSizer32->Add( m_staticText442111, 0, wxALL, 4 );
	
	cmbRDIV_HFLNAD = new wxComboBox( ID_PANEL_LDO, ID_RDIV_HFLNAD, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_HFLNAD, 0, wxALL, 0 );
	
	m_staticText4421111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_CLK_BUF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4421111->Wrap( -1 );
	fgSizer32->Add( m_staticText4421111, 0, wxALL, 4 );
	
	cmbRDIV_CLK_BUF = new wxComboBox( ID_PANEL_LDO, ID_RDIV_CLK_BUF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_CLK_BUF, 0, wxALL, 0 );
	
	m_staticText44211111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_PLL_DIV"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44211111->Wrap( -1 );
	fgSizer32->Add( m_staticText44211111, 0, wxALL, 4 );
	
	cmbRDIV_PLL_DIV = new wxComboBox( ID_PANEL_LDO, ID_RDIV_PLL_DIV, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_PLL_DIV, 0, wxALL, 0 );
	
	m_staticText442111111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_PLL_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText442111111->Wrap( -1 );
	fgSizer32->Add( m_staticText442111111, 0, wxALL, 4 );
	
	cmbRDIV_PLL_CP = new wxComboBox( ID_PANEL_LDO, ID_RDIV_PLL_CP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_PLL_CP, 0, wxALL, 0 );
	
	m_staticText4421111111 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("RDIV_DIG_CORE"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4421111111->Wrap( -1 );
	fgSizer32->Add( m_staticText4421111111, 0, wxALL, 4 );
	
	cmbRDIV_DIG_CORE = new wxComboBox( ID_PANEL_LDO, ID_RDIV_DIG_CORE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer32->Add( cmbRDIV_DIG_CORE, 0, wxALL, 0 );
	
	
	sbSizer50->Add( fgSizer32, 1, wxEXPAND, 5 );
	
	
	fgSizer31->Add( sbSizer50, 1, wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer31, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer34;
	fgSizer34 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer34->SetFlexibleDirection( wxBOTH );
	fgSizer34->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer48;
	sbSizer48 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_LDO, wxID_ANY, wxT("Calibration rppolywo") ), wxVERTICAL );
	
	chkPD_CALIB_COMP = new wxCheckBox( ID_PANEL_LDO, ID_PD_CALIB_COMP, wxT("PD_CALIB_COMP"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPD_CALIB_COMP->SetValue(true); 
	sbSizer48->Add( chkPD_CALIB_COMP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0 );
	
	chkRP_CALIB_COMP = new wxCheckBox( ID_PANEL_LDO, ID_PD_CALIB_COMP, wxT("RP_CALIB_COMP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer48->Add( chkRP_CALIB_COMP, 0, wxALL, 0 );
	
	m_staticText43 = new wxStaticText( ID_PANEL_LDO, wxID_ANY, wxT("Code"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	sbSizer48->Add( m_staticText43, 0, wxALL, 0 );
	
	cmbRP_CALIB_BIAS = new wxSpinCtrl( ID_PANEL_LDO, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer48->Add( cmbRP_CALIB_BIAS, 0, wxALL, 0 );
	
	
	fgSizer34->Add( sbSizer48, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer69->Add( fgSizer34, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_LDO->SetSizer( fgSizer69 );
	ID_PANEL_LDO->Layout();
	fgSizer69->Fit( ID_PANEL_LDO );
	ID_NOTEBOOK_LDO->AddPage( ID_PANEL_LDO, wxT("Bias"), false );
	
	fgSizer68->Add( ID_NOTEBOOK_LDO, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	chkPD_FRP_BIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_F_BIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_PTRP_BIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_PT_BIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_BIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_CLK_BUF->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_PLL_DIV->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_PLL_CP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_LDO_DIG_CORE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_CLK_BUF->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_PLL_DIV->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_PLL_CP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_DIG_CORE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAA->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_CLK_BUF->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_PLL_DIV->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_PLL_CP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_DIG_CORE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFA->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFB->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFC->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFD->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAA->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAB->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAC->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAD->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_CLK_BUF->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_PLL_DIV->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_PLL_CP->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_DIG_CORE->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_CALIB_COMP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkRP_CALIB_COMP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
}

pnlLDO_view::~pnlLDO_view()
{
	// Disconnect Events
	chkPD_FRP_BIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_F_BIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_PTRP_BIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_PT_BIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_BIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_LOBUFD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_HFLNAD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_CLK_BUF->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_PLL_DIV->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LDO_PLL_CP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_LDO_DIG_CORE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_LOBUFD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_HFLNAD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_CLK_BUF->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_PLL_DIV->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_PLL_CP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_LDO_DIG_CORE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_LOBUFD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAA->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_HFLNAD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_CLK_BUF->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_PLL_DIV->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_PLL_CP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkEN_LOADIMP_LDO_DIG_CORE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFA->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFB->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFC->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_LOBUFD->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAA->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAB->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAC->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_HFLNAD->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_CLK_BUF->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_PLL_DIV->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_PLL_CP->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRDIV_DIG_CORE->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkPD_CALIB_COMP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	chkRP_CALIB_COMP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	cmbRP_CALIB_BIAS->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlLDO_view::ParameterChangeHandler ), NULL, this );
	
}

pnlChannel_view::pnlChannel_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_CHANNEL = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_CHANNEL = new wxPanel( ID_NOTEBOOK_CHANNEL, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer69;
	fgSizer69 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer69->SetFlexibleDirection( wxBOTH );
	fgSizer69->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer125;
	fgSizer125 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer125->SetFlexibleDirection( wxBOTH );
	fgSizer125->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer29;
	fgSizer29 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer29->SetFlexibleDirection( wxBOTH );
	fgSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer35;
	sbSizer35 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("HFPAD Reference Current") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer83;
	fgSizer83 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer83->SetFlexibleDirection( wxBOTH );
	fgSizer83->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PA_ILIN2X = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Double LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer83->Add( chkCHx_PA_ILIN2X, 0, wxALL, 4 );
	
	
	sbSizer35->Add( fgSizer83, 1, wxEXPAND, 0 );
	
	wxFlexGridSizer* fgSizer84;
	fgSizer84 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer84->SetFlexibleDirection( wxBOTH );
	fgSizer84->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4311 = new wxStaticText( ID_PANEL_CHANNEL, wxID_ANY, wxT("LIN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311->Wrap( -1 );
	fgSizer84->Add( m_staticText4311, 0, wxALL, 4 );
	
	cmbCHx_PA_ICT_LIN = new wxSpinCtrl( ID_PANEL_CHANNEL, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer84->Add( cmbCHx_PA_ICT_LIN, 0, wxALL, 0 );
	
	m_staticText43111 = new wxStaticText( ID_PANEL_CHANNEL, wxID_ANY, wxT("MAIN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111->Wrap( -1 );
	fgSizer84->Add( m_staticText43111, 0, wxALL, 4 );
	
	cmbCHx_PA_ICT_MAIN = new wxSpinCtrl( ID_PANEL_CHANNEL, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer84->Add( cmbCHx_PA_ICT_MAIN, 0, wxALL, 0 );
	
	
	sbSizer35->Add( fgSizer84, 0, wxEXPAND, 5 );
	
	
	fgSizer29->Add( sbSizer35, 0, wxEXPAND, 5 );
	
	
	fgSizer125->Add( fgSizer29, 1, wxEXPAND, 5 );
	
	ID_NOTEBOOK_CH_PROGRAM = new wxNotebook( ID_PANEL_CHANNEL, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_CH_P0 = new wxPanel( ID_NOTEBOOK_CH_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88;
	fgSizer88 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88->SetFlexibleDirection( wxBOTH );
	fgSizer88->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer115;
	sbSizer115 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P0, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85;
	fgSizer85 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer85->SetFlexibleDirection( wxBOTH );
	fgSizer85->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlChannel = new wxPanel( ID_PANEL_CH_P0, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxRAISED_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bsChannel;
	bsChannel = new wxBoxSizer( wxVERTICAL );
	
	bsChannel->SetMinSize( wxSize( 400,187 ) ); 
	wxFlexGridSizer* fgSizer156;
	fgSizer156 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer156->SetFlexibleDirection( wxBOTH );
	fgSizer156->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer156->Add( 30, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155;
	fgSizer155 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155->SetFlexibleDirection( wxBOTH );
	fgSizer155->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_LNA_PD0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("LNA_PD"), wxPoint( 50,-1 ), wxDefaultSize, 0 );
	fgSizer155->Add( chkCHx_LNA_PD0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156->Add( fgSizer155, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer1551;
	fgSizer1551 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1551->SetFlexibleDirection( wxBOTH );
	fgSizer1551->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551->Add( 0, 10, 0, 0, 5 );
	
	chkCHx_MIXB_LOBUFF_PD0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("MIXB_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551->Add( chkCHx_MIXB_LOBUFF_PD0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156->Add( fgSizer1551, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15511;
	fgSizer15511 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15511->SetFlexibleDirection( wxBOTH );
	fgSizer15511->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15511->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15511->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_MIXA_LOBUFF_PD0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("MIXA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15511->Add( chkCHx_MIXA_LOBUFF_PD0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156->Add( fgSizer15511, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155111;
	fgSizer155111 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155111->SetFlexibleDirection( wxBOTH );
	fgSizer155111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155111->Add( 60, 165, 0, 0, 5 );
	
	chkCHx_PA_R50_EN0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("PA_R50"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155111->Add( chkCHx_PA_R50_EN0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156->Add( fgSizer155111, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1551111;
	fgSizer1551111 = new wxFlexGridSizer( 4, 0, 0, 0 );
	fgSizer1551111->SetFlexibleDirection( wxBOTH );
	fgSizer1551111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551111->Add( 60, 10, 0, 0, 5 );
	
	chkCHx_PA_BYPASS0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("PA_BYPASS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551111->Add( chkCHx_PA_BYPASS0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1551111->Add( 60, 95, 1, wxEXPAND, 5 );
	
	chkCHx_PA_PD0 = new wxCheckBox( pnlChannel, ID_CHx_PA_ILIN2X, wxT("PA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551111->Add( chkCHx_PA_PD0, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156->Add( fgSizer1551111, 1, wxEXPAND, 5 );
	
	
	bsChannel->Add( fgSizer156, 1, wxEXPAND, 5 );
	
	
	pnlChannel->SetSizer( bsChannel );
	pnlChannel->Layout();
	bsChannel->Fit( pnlChannel );
	fgSizer85->Add( pnlChannel, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer115->Add( fgSizer85, 1, wxEXPAND, 5 );
	
	
	fgSizer88->Add( sbSizer115, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer118;
	sbSizer118 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P0, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer851;
	fgSizer851 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer851->SetFlexibleDirection( wxBOTH );
	fgSizer851->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText431111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111->Wrap( -1 );
	fgSizer851->Add( m_staticText431111, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_LIN0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer851->Add( cmbCHx_LNA_ICT_LIN0, 0, wxALL, 0 );
	
	m_staticText4311111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("MAIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111->Wrap( -1 );
	fgSizer851->Add( m_staticText4311111, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_MAIN0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer851->Add( cmbCHx_LNA_ICT_MAIN0, 0, wxALL, 0 );
	
	m_staticText43111111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("Cgs additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111->Wrap( -1 );
	fgSizer851->Add( m_staticText43111111, 0, wxALL, 0 );
	
	cmbCHx_LNA_CGSCTRL0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4, 2 );
	fgSizer851->Add( cmbCHx_LNA_CGSCTRL0, 0, wxALL, 0 );
	
	m_staticText431111111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("Gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111111->Wrap( -1 );
	fgSizer851->Add( m_staticText431111111, 0, wxALL, 0 );
	
	cmbCHx_LNA_GCTRL0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 8 );
	fgSizer851->Add( cmbCHx_LNA_GCTRL0, 0, wxALL, 0 );
	
	
	sbSizer118->Add( fgSizer851, 1, wxEXPAND, 5 );
	
	
	fgSizer88->Add( sbSizer118, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer119;
	sbSizer119 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P0, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8511;
	fgSizer8511 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8511->SetFlexibleDirection( wxBOTH );
	fgSizer8511->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4311111111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("LIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111111->Wrap( -1 );
	fgSizer8511->Add( m_staticText4311111111, 0, wxALL, 0 );
	
	cmbCHx_PA_LIN_LOSS0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	fgSizer8511->Add( cmbCHx_PA_LIN_LOSS0, 0, wxALL, 0 );
	
	m_staticText43111111111 = new wxStaticText( ID_PANEL_CH_P0, wxID_ANY, wxT("MAIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111111->Wrap( -1 );
	fgSizer8511->Add( m_staticText43111111111, 0, wxALL, 0 );
	
	cmbCHx_PA_MAIN_LOSS0 = new wxSpinCtrl( ID_PANEL_CH_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	fgSizer8511->Add( cmbCHx_PA_MAIN_LOSS0, 0, wxALL, 0 );
	
	
	sbSizer119->Add( fgSizer8511, 1, wxEXPAND, 5 );
	
	
	fgSizer88->Add( sbSizer119, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CH_P0->SetSizer( fgSizer88 );
	ID_PANEL_CH_P0->Layout();
	fgSizer88->Fit( ID_PANEL_CH_P0 );
	ID_NOTEBOOK_CH_PROGRAM->AddPage( ID_PANEL_CH_P0, wxT("Program 0"), true );
	ID_PANEL_CH_P1 = new wxPanel( ID_NOTEBOOK_CH_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer881;
	fgSizer881 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer881->SetFlexibleDirection( wxBOTH );
	fgSizer881->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1151;
	sbSizer1151 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P1, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer852;
	fgSizer852 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer852->SetFlexibleDirection( wxBOTH );
	fgSizer852->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlChannel1 = new wxPanel( ID_PANEL_CH_P1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxRAISED_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bsChannel1;
	bsChannel1 = new wxBoxSizer( wxVERTICAL );
	
	bsChannel1->SetMinSize( wxSize( 400,187 ) ); 
	wxFlexGridSizer* fgSizer1561;
	fgSizer1561 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer1561->SetFlexibleDirection( wxBOTH );
	fgSizer1561->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer1561->Add( 30, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1552;
	fgSizer1552 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1552->SetFlexibleDirection( wxBOTH );
	fgSizer1552->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1552->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1552->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_LNA_PD1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("LNA_PD"), wxPoint( 50,-1 ), wxDefaultSize, 0 );
	fgSizer1552->Add( chkCHx_LNA_PD1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561->Add( fgSizer1552, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer15512;
	fgSizer15512 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15512->SetFlexibleDirection( wxBOTH );
	fgSizer15512->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15512->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15512->Add( 0, 10, 0, 0, 5 );
	
	chkCHx_MIXB_LOBUFF_PD1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("MIXB_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15512->Add( chkCHx_MIXB_LOBUFF_PD1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561->Add( fgSizer15512, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155112;
	fgSizer155112 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155112->SetFlexibleDirection( wxBOTH );
	fgSizer155112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155112->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155112->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_MIXA_LOBUFF_PD1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("MIXA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155112->Add( chkCHx_MIXA_LOBUFF_PD1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561->Add( fgSizer155112, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1551112;
	fgSizer1551112 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1551112->SetFlexibleDirection( wxBOTH );
	fgSizer1551112->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551112->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551112->Add( 60, 165, 0, 0, 5 );
	
	chkCHx_PA_R50_EN1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("PA_R50"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551112->Add( chkCHx_PA_R50_EN1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561->Add( fgSizer1551112, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15511111;
	fgSizer15511111 = new wxFlexGridSizer( 4, 0, 0, 0 );
	fgSizer15511111->SetFlexibleDirection( wxBOTH );
	fgSizer15511111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15511111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15511111->Add( 60, 10, 0, 0, 5 );
	
	chkCHx_PA_BYPASS1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("PA_BYPASS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15511111->Add( chkCHx_PA_BYPASS1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15511111->Add( 60, 95, 1, wxEXPAND, 5 );
	
	chkCHx_PA_PD1 = new wxCheckBox( pnlChannel1, ID_CHx_PA_ILIN2X, wxT("PA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15511111->Add( chkCHx_PA_PD1, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561->Add( fgSizer15511111, 1, wxEXPAND, 5 );
	
	
	bsChannel1->Add( fgSizer1561, 1, wxEXPAND, 5 );
	
	
	pnlChannel1->SetSizer( bsChannel1 );
	pnlChannel1->Layout();
	bsChannel1->Fit( pnlChannel1 );
	fgSizer852->Add( pnlChannel1, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer1151->Add( fgSizer852, 1, wxEXPAND, 5 );
	
	
	fgSizer881->Add( sbSizer1151, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1181;
	sbSizer1181 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P1, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8512;
	fgSizer8512 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8512->SetFlexibleDirection( wxBOTH );
	fgSizer8512->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4311112 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311112->Wrap( -1 );
	fgSizer8512->Add( m_staticText4311112, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_LIN1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer8512->Add( cmbCHx_LNA_ICT_LIN1, 0, wxALL, 0 );
	
	m_staticText43111112 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("MAIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111112->Wrap( -1 );
	fgSizer8512->Add( m_staticText43111112, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_MAIN1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer8512->Add( cmbCHx_LNA_ICT_MAIN1, 0, wxALL, 0 );
	
	m_staticText431111112 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("Cgs additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111112->Wrap( -1 );
	fgSizer8512->Add( m_staticText431111112, 0, wxALL, 0 );
	
	cmbCHx_LNA_CGSCTRL1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4, 2 );
	fgSizer8512->Add( cmbCHx_LNA_CGSCTRL1, 0, wxALL, 0 );
	
	m_staticText4311111112 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("Gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111112->Wrap( -1 );
	fgSizer8512->Add( m_staticText4311111112, 0, wxALL, 0 );
	
	cmbCHx_LNA_GCTRL1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 8 );
	fgSizer8512->Add( cmbCHx_LNA_GCTRL1, 0, wxALL, 0 );
	
	
	sbSizer1181->Add( fgSizer8512, 1, wxEXPAND, 5 );
	
	
	fgSizer881->Add( sbSizer1181, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1191;
	sbSizer1191 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P1, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85111;
	fgSizer85111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer85111->SetFlexibleDirection( wxBOTH );
	fgSizer85111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText43111111112 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("LIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111112->Wrap( -1 );
	fgSizer85111->Add( m_staticText43111111112, 0, wxALL, 0 );
	
	cmbCHx_PA_LIN_LOSS1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer85111->Add( cmbCHx_PA_LIN_LOSS1, 0, wxALL, 0 );
	
	m_staticText431111111111 = new wxStaticText( ID_PANEL_CH_P1, wxID_ANY, wxT("MAIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111111111->Wrap( -1 );
	fgSizer85111->Add( m_staticText431111111111, 0, wxALL, 0 );
	
	cmbCHx_PA_MAIN_LOSS1 = new wxSpinCtrl( ID_PANEL_CH_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer85111->Add( cmbCHx_PA_MAIN_LOSS1, 0, wxALL, 0 );
	
	
	sbSizer1191->Add( fgSizer85111, 1, wxEXPAND, 5 );
	
	
	fgSizer881->Add( sbSizer1191, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CH_P1->SetSizer( fgSizer881 );
	ID_PANEL_CH_P1->Layout();
	fgSizer881->Fit( ID_PANEL_CH_P1 );
	ID_NOTEBOOK_CH_PROGRAM->AddPage( ID_PANEL_CH_P1, wxT("Program 1"), false );
	ID_PANEL_CH_P2 = new wxPanel( ID_NOTEBOOK_CH_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8811;
	fgSizer8811 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8811->SetFlexibleDirection( wxBOTH );
	fgSizer8811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer11511;
	sbSizer11511 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P2, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8521;
	fgSizer8521 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8521->SetFlexibleDirection( wxBOTH );
	fgSizer8521->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlChannel11 = new wxPanel( ID_PANEL_CH_P2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxRAISED_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bsChannel11;
	bsChannel11 = new wxBoxSizer( wxVERTICAL );
	
	bsChannel11->SetMinSize( wxSize( 400,187 ) ); 
	wxFlexGridSizer* fgSizer15611;
	fgSizer15611 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer15611->SetFlexibleDirection( wxBOTH );
	fgSizer15611->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer15611->Add( 30, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15521;
	fgSizer15521 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15521->SetFlexibleDirection( wxBOTH );
	fgSizer15521->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15521->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15521->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_LNA_PD2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("LNA_PD"), wxPoint( 50,-1 ), wxDefaultSize, 0 );
	fgSizer15521->Add( chkCHx_LNA_PD2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15611->Add( fgSizer15521, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer155121;
	fgSizer155121 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155121->SetFlexibleDirection( wxBOTH );
	fgSizer155121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155121->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155121->Add( 0, 10, 0, 0, 5 );
	
	chkCHx_MIXB_LOBUFF_PD2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("MIXB_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155121->Add( chkCHx_MIXB_LOBUFF_PD2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15611->Add( fgSizer155121, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1551121;
	fgSizer1551121 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1551121->SetFlexibleDirection( wxBOTH );
	fgSizer1551121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551121->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551121->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_MIXA_LOBUFF_PD2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("MIXA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551121->Add( chkCHx_MIXA_LOBUFF_PD2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15611->Add( fgSizer1551121, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15511121;
	fgSizer15511121 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15511121->SetFlexibleDirection( wxBOTH );
	fgSizer15511121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15511121->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15511121->Add( 60, 165, 0, 0, 5 );
	
	chkCHx_PA_R50_EN2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("PA_R50"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15511121->Add( chkCHx_PA_R50_EN2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15611->Add( fgSizer15511121, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155111111;
	fgSizer155111111 = new wxFlexGridSizer( 4, 0, 0, 0 );
	fgSizer155111111->SetFlexibleDirection( wxBOTH );
	fgSizer155111111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155111111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155111111->Add( 60, 10, 0, 0, 5 );
	
	chkCHx_PA_BYPASS2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("PA_BYPASS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155111111->Add( chkCHx_PA_BYPASS2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer155111111->Add( 60, 95, 1, wxEXPAND, 5 );
	
	chkCHx_PA_PD2 = new wxCheckBox( pnlChannel11, ID_CHx_PA_ILIN2X, wxT("PA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155111111->Add( chkCHx_PA_PD2, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15611->Add( fgSizer155111111, 1, wxEXPAND, 5 );
	
	
	bsChannel11->Add( fgSizer15611, 1, wxEXPAND, 5 );
	
	
	pnlChannel11->SetSizer( bsChannel11 );
	pnlChannel11->Layout();
	bsChannel11->Fit( pnlChannel11 );
	fgSizer8521->Add( pnlChannel11, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer11511->Add( fgSizer8521, 1, wxEXPAND, 5 );
	
	
	fgSizer8811->Add( sbSizer11511, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11811;
	sbSizer11811 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P2, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85121;
	fgSizer85121 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer85121->SetFlexibleDirection( wxBOTH );
	fgSizer85121->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText43111121 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111121->Wrap( -1 );
	fgSizer85121->Add( m_staticText43111121, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_LIN2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer85121->Add( cmbCHx_LNA_ICT_LIN2, 0, wxALL, 0 );
	
	m_staticText431111121 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("MAIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111121->Wrap( -1 );
	fgSizer85121->Add( m_staticText431111121, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_MAIN2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer85121->Add( cmbCHx_LNA_ICT_MAIN2, 0, wxALL, 0 );
	
	m_staticText4311111121 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("Cgs additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111121->Wrap( -1 );
	fgSizer85121->Add( m_staticText4311111121, 0, wxALL, 0 );
	
	cmbCHx_LNA_CGSCTRL2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4, 2 );
	fgSizer85121->Add( cmbCHx_LNA_CGSCTRL2, 0, wxALL, 0 );
	
	m_staticText43111111121 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("Gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111121->Wrap( -1 );
	fgSizer85121->Add( m_staticText43111111121, 0, wxALL, 0 );
	
	cmbCHx_LNA_GCTRL2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 8 );
	fgSizer85121->Add( cmbCHx_LNA_GCTRL2, 0, wxALL, 0 );
	
	
	sbSizer11811->Add( fgSizer85121, 1, wxEXPAND, 5 );
	
	
	fgSizer8811->Add( sbSizer11811, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11911;
	sbSizer11911 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P2, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer851111;
	fgSizer851111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer851111->SetFlexibleDirection( wxBOTH );
	fgSizer851111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText431111111121 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("LIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111111121->Wrap( -1 );
	fgSizer851111->Add( m_staticText431111111121, 0, wxALL, 0 );
	
	cmbCHx_PA_LIN_LOSS2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer851111->Add( cmbCHx_PA_LIN_LOSS2, 0, wxALL, 0 );
	
	m_staticText4311111111111 = new wxStaticText( ID_PANEL_CH_P2, wxID_ANY, wxT("MAIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111111111->Wrap( -1 );
	fgSizer851111->Add( m_staticText4311111111111, 0, wxALL, 0 );
	
	cmbCHx_PA_MAIN_LOSS2 = new wxSpinCtrl( ID_PANEL_CH_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer851111->Add( cmbCHx_PA_MAIN_LOSS2, 0, wxALL, 0 );
	
	
	sbSizer11911->Add( fgSizer851111, 1, wxEXPAND, 5 );
	
	
	fgSizer8811->Add( sbSizer11911, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CH_P2->SetSizer( fgSizer8811 );
	ID_PANEL_CH_P2->Layout();
	fgSizer8811->Fit( ID_PANEL_CH_P2 );
	ID_NOTEBOOK_CH_PROGRAM->AddPage( ID_PANEL_CH_P2, wxT("Program 2"), false );
	ID_PANEL_CH_P3 = new wxPanel( ID_NOTEBOOK_CH_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88111;
	fgSizer88111 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88111->SetFlexibleDirection( wxBOTH );
	fgSizer88111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer115111;
	sbSizer115111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P3, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85211;
	fgSizer85211 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer85211->SetFlexibleDirection( wxBOTH );
	fgSizer85211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlChannel111 = new wxPanel( ID_PANEL_CH_P3, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxRAISED_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bsChannel111;
	bsChannel111 = new wxBoxSizer( wxVERTICAL );
	
	bsChannel111->SetMinSize( wxSize( 400,187 ) ); 
	wxFlexGridSizer* fgSizer156111;
	fgSizer156111 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer156111->SetFlexibleDirection( wxBOTH );
	fgSizer156111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer156111->Add( 30, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155211;
	fgSizer155211 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155211->SetFlexibleDirection( wxBOTH );
	fgSizer155211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155211->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155211->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_LNA_PD3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("LNA_PD"), wxPoint( 50,-1 ), wxDefaultSize, 0 );
	fgSizer155211->Add( chkCHx_LNA_PD3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156111->Add( fgSizer155211, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer1551211;
	fgSizer1551211 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1551211->SetFlexibleDirection( wxBOTH );
	fgSizer1551211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551211->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551211->Add( 0, 10, 0, 0, 5 );
	
	chkCHx_MIXB_LOBUFF_PD3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("MIXB_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551211->Add( chkCHx_MIXB_LOBUFF_PD3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156111->Add( fgSizer1551211, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15511211;
	fgSizer15511211 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15511211->SetFlexibleDirection( wxBOTH );
	fgSizer15511211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15511211->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15511211->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_MIXA_LOBUFF_PD3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("MIXA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15511211->Add( chkCHx_MIXA_LOBUFF_PD3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156111->Add( fgSizer15511211, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155111211;
	fgSizer155111211 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155111211->SetFlexibleDirection( wxBOTH );
	fgSizer155111211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155111211->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155111211->Add( 60, 165, 0, 0, 5 );
	
	chkCHx_PA_R50_EN3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("PA_R50"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer155111211->Add( chkCHx_PA_R50_EN3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156111->Add( fgSizer155111211, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1551111111;
	fgSizer1551111111 = new wxFlexGridSizer( 4, 0, 0, 0 );
	fgSizer1551111111->SetFlexibleDirection( wxBOTH );
	fgSizer1551111111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551111111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551111111->Add( 60, 10, 0, 0, 5 );
	
	chkCHx_PA_BYPASS3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("PA_BYPASS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551111111->Add( chkCHx_PA_BYPASS3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1551111111->Add( 60, 95, 1, wxEXPAND, 5 );
	
	chkCHx_PA_PD3 = new wxCheckBox( pnlChannel111, ID_CHx_PA_ILIN2X, wxT("PA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1551111111->Add( chkCHx_PA_PD3, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer156111->Add( fgSizer1551111111, 1, wxEXPAND, 5 );
	
	
	bsChannel111->Add( fgSizer156111, 1, wxEXPAND, 5 );
	
	
	pnlChannel111->SetSizer( bsChannel111 );
	pnlChannel111->Layout();
	bsChannel111->Fit( pnlChannel111 );
	fgSizer85211->Add( pnlChannel111, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer115111->Add( fgSizer85211, 1, wxEXPAND, 5 );
	
	
	fgSizer88111->Add( sbSizer115111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer118111;
	sbSizer118111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P3, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer851211;
	fgSizer851211 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer851211->SetFlexibleDirection( wxBOTH );
	fgSizer851211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText431111211 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111211->Wrap( -1 );
	fgSizer851211->Add( m_staticText431111211, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_LIN3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer851211->Add( cmbCHx_LNA_ICT_LIN3, 0, wxALL, 0 );
	
	m_staticText4311111211 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("MAIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111211->Wrap( -1 );
	fgSizer851211->Add( m_staticText4311111211, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_MAIN3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	fgSizer851211->Add( cmbCHx_LNA_ICT_MAIN3, 0, wxALL, 0 );
	
	m_staticText43111111211 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("Cgs additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111211->Wrap( -1 );
	fgSizer851211->Add( m_staticText43111111211, 0, wxALL, 0 );
	
	cmbCHx_LNA_CGSCTRL3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4, 2 );
	fgSizer851211->Add( cmbCHx_LNA_CGSCTRL3, 0, wxALL, 0 );
	
	m_staticText431111111211 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("Gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111111211->Wrap( -1 );
	fgSizer851211->Add( m_staticText431111111211, 0, wxALL, 0 );
	
	cmbCHx_LNA_GCTRL3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 8 );
	fgSizer851211->Add( cmbCHx_LNA_GCTRL3, 0, wxALL, 0 );
	
	
	sbSizer118111->Add( fgSizer851211, 1, wxEXPAND, 5 );
	
	
	fgSizer88111->Add( sbSizer118111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer119111;
	sbSizer119111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_P3, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8511111;
	fgSizer8511111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8511111->SetFlexibleDirection( wxBOTH );
	fgSizer8511111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4311111111211 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("LIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111111211->Wrap( -1 );
	fgSizer8511111->Add( m_staticText4311111111211, 0, wxALL, 0 );
	
	cmbCHx_PA_LIN_LOSS3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer8511111->Add( cmbCHx_PA_LIN_LOSS3, 0, wxALL, 0 );
	
	m_staticText43111111111111 = new wxStaticText( ID_PANEL_CH_P3, wxID_ANY, wxT("MAIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111111111->Wrap( -1 );
	fgSizer8511111->Add( m_staticText43111111111111, 0, wxALL, 0 );
	
	cmbCHx_PA_MAIN_LOSS3 = new wxSpinCtrl( ID_PANEL_CH_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	fgSizer8511111->Add( cmbCHx_PA_MAIN_LOSS3, 0, wxALL, 0 );
	
	
	sbSizer119111->Add( fgSizer8511111, 1, wxEXPAND, 5 );
	
	
	fgSizer88111->Add( sbSizer119111, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CH_P3->SetSizer( fgSizer88111 );
	ID_PANEL_CH_P3->Layout();
	fgSizer88111->Fit( ID_PANEL_CH_P3 );
	ID_NOTEBOOK_CH_PROGRAM->AddPage( ID_PANEL_CH_P3, wxT("Program 3"), false );
	ID_PANEL_CH_RB = new wxPanel( ID_NOTEBOOK_CH_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer881111;
	fgSizer881111 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer881111->SetFlexibleDirection( wxBOTH );
	fgSizer881111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1151111;
	sbSizer1151111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_RB, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer852111;
	fgSizer852111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer852111->SetFlexibleDirection( wxBOTH );
	fgSizer852111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pnlChannel1111 = new wxPanel( ID_PANEL_CH_RB, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxRAISED_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bsChannel1111;
	bsChannel1111 = new wxBoxSizer( wxVERTICAL );
	
	bsChannel1111->SetMinSize( wxSize( 400,187 ) ); 
	wxFlexGridSizer* fgSizer1561111;
	fgSizer1561111 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer1561111->SetFlexibleDirection( wxBOTH );
	fgSizer1561111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer1561111->Add( 30, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1552111;
	fgSizer1552111 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1552111->SetFlexibleDirection( wxBOTH );
	fgSizer1552111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1552111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1552111->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_LNA_PD_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("LNA_PD"), wxPoint( 50,-1 ), wxDefaultSize, 0 );
	chkCHx_LNA_PD_RB->Enable( false );
	
	fgSizer1552111->Add( chkCHx_LNA_PD_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561111->Add( fgSizer1552111, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer15512111;
	fgSizer15512111 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer15512111->SetFlexibleDirection( wxBOTH );
	fgSizer15512111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15512111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15512111->Add( 0, 10, 0, 0, 5 );
	
	chkCHx_MIXB_LOBUFF_PD_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("MIXB_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCHx_MIXB_LOBUFF_PD_RB->Enable( false );
	
	fgSizer15512111->Add( chkCHx_MIXB_LOBUFF_PD_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561111->Add( fgSizer15512111, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer155112111;
	fgSizer155112111 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer155112111->SetFlexibleDirection( wxBOTH );
	fgSizer155112111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer155112111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer155112111->Add( 0, 120, 0, 0, 5 );
	
	chkCHx_MIXA_LOBUFF_PD_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("MIXA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCHx_MIXA_LOBUFF_PD_RB->Enable( false );
	
	fgSizer155112111->Add( chkCHx_MIXA_LOBUFF_PD_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561111->Add( fgSizer155112111, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1551112111;
	fgSizer1551112111 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1551112111->SetFlexibleDirection( wxBOTH );
	fgSizer1551112111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer1551112111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer1551112111->Add( 60, 165, 0, 0, 5 );
	
	chkCHx_PA_R50_EN_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("PA_R50"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCHx_PA_R50_EN_RB->Enable( false );
	
	fgSizer1551112111->Add( chkCHx_PA_R50_EN_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561111->Add( fgSizer1551112111, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15511111111;
	fgSizer15511111111 = new wxFlexGridSizer( 4, 0, 0, 0 );
	fgSizer15511111111->SetFlexibleDirection( wxBOTH );
	fgSizer15511111111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer15511111111->SetMinSize( wxSize( -1,50 ) ); 
	
	fgSizer15511111111->Add( 60, 10, 0, 0, 5 );
	
	chkCHx_PA_BYPASS_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("PA_BYPASS"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCHx_PA_BYPASS_RB->Enable( false );
	
	fgSizer15511111111->Add( chkCHx_PA_BYPASS_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer15511111111->Add( 60, 95, 1, wxEXPAND, 5 );
	
	chkCHx_PA_PD_RB = new wxCheckBox( pnlChannel1111, ID_CHx_PA_ILIN2X, wxT("PA_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCHx_PA_PD_RB->Enable( false );
	
	fgSizer15511111111->Add( chkCHx_PA_PD_RB, 0, wxALIGN_CENTER|wxALL, 0 );
	
	
	fgSizer1561111->Add( fgSizer15511111111, 1, wxEXPAND, 5 );
	
	
	bsChannel1111->Add( fgSizer1561111, 1, wxEXPAND, 5 );
	
	
	pnlChannel1111->SetSizer( bsChannel1111 );
	pnlChannel1111->Layout();
	bsChannel1111->Fit( pnlChannel1111 );
	fgSizer852111->Add( pnlChannel1111, 1, wxEXPAND | wxALL, 5 );
	
	
	sbSizer1151111->Add( fgSizer852111, 1, wxEXPAND, 5 );
	
	
	fgSizer881111->Add( sbSizer1151111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1181111;
	sbSizer1181111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_RB, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8512111;
	fgSizer8512111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8512111->SetFlexibleDirection( wxBOTH );
	fgSizer8512111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4311112111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("LIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311112111->Wrap( -1 );
	fgSizer8512111->Add( m_staticText4311112111, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_LIN_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	cmbCHx_LNA_ICT_LIN_RB->Enable( false );
	
	fgSizer8512111->Add( cmbCHx_LNA_ICT_LIN_RB, 0, wxALL, 0 );
	
	m_staticText43111112111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("MAIN ref. current"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111112111->Wrap( -1 );
	fgSizer8512111->Add( m_staticText43111112111, 0, wxALL, 0 );
	
	cmbCHx_LNA_ICT_MAIN_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	cmbCHx_LNA_ICT_MAIN_RB->Enable( false );
	
	fgSizer8512111->Add( cmbCHx_LNA_ICT_MAIN_RB, 0, wxALL, 0 );
	
	m_staticText431111112111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("Cgs additional"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111112111->Wrap( -1 );
	fgSizer8512111->Add( m_staticText431111112111, 0, wxALL, 0 );
	
	cmbCHx_LNA_CGSCTRL_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4, 2 );
	cmbCHx_LNA_CGSCTRL_RB->Enable( false );
	
	fgSizer8512111->Add( cmbCHx_LNA_CGSCTRL_RB, 0, wxALL, 0 );
	
	m_staticText4311111112111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("Gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4311111112111->Wrap( -1 );
	fgSizer8512111->Add( m_staticText4311111112111, 0, wxALL, 0 );
	
	cmbCHx_LNA_GCTRL_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 8 );
	cmbCHx_LNA_GCTRL_RB->Enable( false );
	
	fgSizer8512111->Add( cmbCHx_LNA_GCTRL_RB, 0, wxALL, 0 );
	
	
	sbSizer1181111->Add( fgSizer8512111, 1, wxEXPAND, 5 );
	
	
	fgSizer881111->Add( sbSizer1181111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1191111;
	sbSizer1191111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CH_RB, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85111111;
	fgSizer85111111 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer85111111->SetFlexibleDirection( wxBOTH );
	fgSizer85111111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText43111111112111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("LIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43111111112111->Wrap( -1 );
	fgSizer85111111->Add( m_staticText43111111112111, 0, wxALL, 0 );
	
	cmbCHx_PA_LIN_LOSS_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	cmbCHx_PA_LIN_LOSS_RB->Enable( false );
	
	fgSizer85111111->Add( cmbCHx_PA_LIN_LOSS_RB, 0, wxALL, 0 );
	
	m_staticText431111111111111 = new wxStaticText( ID_PANEL_CH_RB, wxID_ANY, wxT("MAIN gain control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText431111111111111->Wrap( -1 );
	fgSizer85111111->Add( m_staticText431111111111111, 0, wxALL, 0 );
	
	cmbCHx_PA_MAIN_LOSS_RB = new wxSpinCtrl( ID_PANEL_CH_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 0 );
	cmbCHx_PA_MAIN_LOSS_RB->Enable( false );
	
	fgSizer85111111->Add( cmbCHx_PA_MAIN_LOSS_RB, 0, wxALL, 0 );
	
	
	sbSizer1191111->Add( fgSizer85111111, 1, wxEXPAND, 5 );
	
	
	fgSizer881111->Add( sbSizer1191111, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CH_RB->SetSizer( fgSizer881111 );
	ID_PANEL_CH_RB->Layout();
	fgSizer881111->Fit( ID_PANEL_CH_RB );
	ID_NOTEBOOK_CH_PROGRAM->AddPage( ID_PANEL_CH_RB, wxT("Readback"), false );
	
	fgSizer125->Add( ID_NOTEBOOK_CH_PROGRAM, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer125, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer126;
	fgSizer126 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer126->SetFlexibleDirection( wxBOTH );
	fgSizer126->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer143;
	sbSizer143 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("MUX Control") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer161;
	fgSizer161 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer161->SetFlexibleDirection( wxBOTH );
	fgSizer161->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer171;
	sbSizer171 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("Power-down") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer369;
	fgSizer369 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer369->SetFlexibleDirection( wxBOTH );
	fgSizer369->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_MUX_CONTROL_PD = new wxNotebook( ID_PANEL_CHANNEL, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_MUX_PD_SEL0 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PD, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer882;
	fgSizer882 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer882->SetFlexibleDirection( wxBOTH );
	fgSizer882->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer160;
	fgSizer160 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer160->SetFlexibleDirection( wxBOTH );
	fgSizer160->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer168;
	sbSizer168 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer159;
	fgSizer159 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer159->SetFlexibleDirection( wxBOTH );
	fgSizer159->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PD_SEL0_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer159->Add( chkCHx_PD_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer159->Add( chkCHx_PD_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer168->Add( fgSizer159, 1, wxEXPAND, 5 );
	
	
	fgSizer160->Add( sbSizer168, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1152;
	sbSizer1152 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer853;
	fgSizer853 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer853->SetFlexibleDirection( wxBOTH );
	fgSizer853->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText265 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265->Wrap( -1 );
	fgSizer853->Add( m_staticText265, 0, wxALL, 5 );
	
	m_staticText2651 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2651->Wrap( -1 );
	fgSizer853->Add( m_staticText2651, 0, wxALL, 5 );
	
	m_staticText2652 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2652->Wrap( -1 );
	fgSizer853->Add( m_staticText2652, 0, wxALL, 5 );
	
	m_staticText2653 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2653->Wrap( -1 );
	fgSizer853->Add( m_staticText2653, 0, wxALL, 5 );
	
	m_staticText2654 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2654->Wrap( -1 );
	fgSizer853->Add( m_staticText2654, 0, wxALL, 5 );
	
	m_staticText2655 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2655->Wrap( -1 );
	fgSizer853->Add( m_staticText2655, 0, wxALL, 5 );
	
	m_staticText2656 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2656->Wrap( -1 );
	fgSizer853->Add( m_staticText2656, 0, wxALL, 5 );
	
	m_staticText2657 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2657->Wrap( -1 );
	fgSizer853->Add( m_staticText2657, 0, wxALL, 5 );
	
	m_staticText2658 = new wxStaticText( ID_PANEL_MUX_PD_SEL0, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2658->Wrap( -1 );
	fgSizer853->Add( m_staticText2658, 0, wxALL, 5 );
	
	chkCHx_PD_SEL0_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK0, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK1, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK2, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK3, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK4, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK5, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK6, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK7, 0, wxALL, 0 );
	
	chkCHx_PD_SEL0_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkCHx_PD_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer1152->Add( fgSizer853, 1, wxEXPAND, 5 );
	
	
	fgSizer160->Add( sbSizer1152, 1, wxEXPAND, 5 );
	
	
	fgSizer882->Add( fgSizer160, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL0->SetSizer( fgSizer882 );
	ID_PANEL_MUX_PD_SEL0->Layout();
	fgSizer882->Fit( ID_PANEL_MUX_PD_SEL0 );
	ID_NOTEBOOK_MUX_CONTROL_PD->AddPage( ID_PANEL_MUX_PD_SEL0, wxT("Bit 0"), true );
	ID_PANEL_MUX_PD_SEL01 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PD, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8821;
	fgSizer8821 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8821->SetFlexibleDirection( wxBOTH );
	fgSizer8821->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1601;
	fgSizer1601 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1601->SetFlexibleDirection( wxBOTH );
	fgSizer1601->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1681;
	sbSizer1681 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1591;
	fgSizer1591 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1591->SetFlexibleDirection( wxBOTH );
	fgSizer1591->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PD_SEL1_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1591->Add( chkCHx_PD_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1591->Add( chkCHx_PD_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1681->Add( fgSizer1591, 1, wxEXPAND, 5 );
	
	
	fgSizer1601->Add( sbSizer1681, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11521;
	sbSizer11521 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8531;
	fgSizer8531 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8531->SetFlexibleDirection( wxBOTH );
	fgSizer8531->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2659 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2659->Wrap( -1 );
	fgSizer8531->Add( m_staticText2659, 0, wxALL, 5 );
	
	m_staticText26511 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26511->Wrap( -1 );
	fgSizer8531->Add( m_staticText26511, 0, wxALL, 5 );
	
	m_staticText26521 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26521->Wrap( -1 );
	fgSizer8531->Add( m_staticText26521, 0, wxALL, 5 );
	
	m_staticText26531 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26531->Wrap( -1 );
	fgSizer8531->Add( m_staticText26531, 0, wxALL, 5 );
	
	m_staticText26541 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26541->Wrap( -1 );
	fgSizer8531->Add( m_staticText26541, 0, wxALL, 5 );
	
	m_staticText26551 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26551->Wrap( -1 );
	fgSizer8531->Add( m_staticText26551, 0, wxALL, 5 );
	
	m_staticText26561 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26561->Wrap( -1 );
	fgSizer8531->Add( m_staticText26561, 0, wxALL, 5 );
	
	m_staticText26571 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26571->Wrap( -1 );
	fgSizer8531->Add( m_staticText26571, 0, wxALL, 5 );
	
	m_staticText26581 = new wxStaticText( ID_PANEL_MUX_PD_SEL01, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26581->Wrap( -1 );
	fgSizer8531->Add( m_staticText26581, 0, wxALL, 5 );
	
	chkCHx_PD_SEL1_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK0, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK1, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK2, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK3, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK4, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK5, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK6, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK7, 0, wxALL, 0 );
	
	chkCHx_PD_SEL1_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL01, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkCHx_PD_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11521->Add( fgSizer8531, 1, wxEXPAND, 5 );
	
	
	fgSizer1601->Add( sbSizer11521, 1, wxEXPAND, 5 );
	
	
	fgSizer8821->Add( fgSizer1601, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL01->SetSizer( fgSizer8821 );
	ID_PANEL_MUX_PD_SEL01->Layout();
	fgSizer8821->Fit( ID_PANEL_MUX_PD_SEL01 );
	ID_NOTEBOOK_MUX_CONTROL_PD->AddPage( ID_PANEL_MUX_PD_SEL01, wxT("Bit 1"), false );
	
	fgSizer369->Add( ID_NOTEBOOK_MUX_CONTROL_PD, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer304;
	sbSizer304 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer370;
	fgSizer370 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer370->SetFlexibleDirection( wxBOTH );
	fgSizer370->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PD_INT_SEL0 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer370->Add( chkCHx_PD_INT_SEL0, 0, wxALL, 5 );
	
	chkCHx_PD_INT_SEL1 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer370->Add( chkCHx_PD_INT_SEL1, 0, wxALL, 5 );
	
	
	sbSizer304->Add( fgSizer370, 1, wxEXPAND, 5 );
	
	
	fgSizer369->Add( sbSizer304, 1, wxEXPAND, 5 );
	
	
	sbSizer171->Add( fgSizer369, 1, wxEXPAND, 5 );
	
	
	fgSizer161->Add( sbSizer171, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1711;
	sbSizer1711 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("LNA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer372;
	fgSizer372 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer372->SetFlexibleDirection( wxBOTH );
	fgSizer372->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_MUX_CONTROL_LNA = new wxNotebook( ID_PANEL_CHANNEL, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_MUX_PD_SEL02 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_LNA, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8822;
	fgSizer8822 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8822->SetFlexibleDirection( wxBOTH );
	fgSizer8822->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1602;
	fgSizer1602 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1602->SetFlexibleDirection( wxBOTH );
	fgSizer1602->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1682;
	sbSizer1682 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1592;
	fgSizer1592 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1592->SetFlexibleDirection( wxBOTH );
	fgSizer1592->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_LNA_SEL0_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1592->Add( chkCHx_LNA_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1592->Add( chkCHx_LNA_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1682->Add( fgSizer1592, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer1682, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11522;
	sbSizer11522 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8532;
	fgSizer8532 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8532->SetFlexibleDirection( wxBOTH );
	fgSizer8532->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26510 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26510->Wrap( -1 );
	fgSizer8532->Add( m_staticText26510, 0, wxALL, 5 );
	
	m_staticText26512 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26512->Wrap( -1 );
	fgSizer8532->Add( m_staticText26512, 0, wxALL, 5 );
	
	m_staticText26522 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26522->Wrap( -1 );
	fgSizer8532->Add( m_staticText26522, 0, wxALL, 5 );
	
	m_staticText26532 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26532->Wrap( -1 );
	fgSizer8532->Add( m_staticText26532, 0, wxALL, 5 );
	
	m_staticText26542 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26542->Wrap( -1 );
	fgSizer8532->Add( m_staticText26542, 0, wxALL, 5 );
	
	m_staticText26552 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26552->Wrap( -1 );
	fgSizer8532->Add( m_staticText26552, 0, wxALL, 5 );
	
	m_staticText26562 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26562->Wrap( -1 );
	fgSizer8532->Add( m_staticText26562, 0, wxALL, 5 );
	
	m_staticText26572 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26572->Wrap( -1 );
	fgSizer8532->Add( m_staticText26572, 0, wxALL, 5 );
	
	m_staticText26582 = new wxStaticText( ID_PANEL_MUX_PD_SEL02, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26582->Wrap( -1 );
	fgSizer8532->Add( m_staticText26582, 0, wxALL, 5 );
	
	chkCHx_LNA_SEL0_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK0, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK1, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK2, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK3, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK4, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK5, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK6, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK7, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL0_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL02, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkCHx_LNA_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11522->Add( fgSizer8532, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer11522, 1, wxEXPAND, 5 );
	
	
	fgSizer8822->Add( fgSizer1602, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL02->SetSizer( fgSizer8822 );
	ID_PANEL_MUX_PD_SEL02->Layout();
	fgSizer8822->Fit( ID_PANEL_MUX_PD_SEL02 );
	ID_NOTEBOOK_MUX_CONTROL_LNA->AddPage( ID_PANEL_MUX_PD_SEL02, wxT("Bit 0"), true );
	ID_PANEL_MUX_PD_SEL011 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_LNA, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88211;
	fgSizer88211 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88211->SetFlexibleDirection( wxBOTH );
	fgSizer88211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer16011;
	fgSizer16011 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer16011->SetFlexibleDirection( wxBOTH );
	fgSizer16011->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer16811;
	sbSizer16811 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15911;
	fgSizer15911 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer15911->SetFlexibleDirection( wxBOTH );
	fgSizer15911->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_LNA_SEL1_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15911->Add( chkCHx_LNA_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15911->Add( chkCHx_LNA_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer16811->Add( fgSizer15911, 1, wxEXPAND, 5 );
	
	
	fgSizer16011->Add( sbSizer16811, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer115211;
	sbSizer115211 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85311;
	fgSizer85311 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer85311->SetFlexibleDirection( wxBOTH );
	fgSizer85311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26591 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26591->Wrap( -1 );
	fgSizer85311->Add( m_staticText26591, 0, wxALL, 5 );
	
	m_staticText265111 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265111->Wrap( -1 );
	fgSizer85311->Add( m_staticText265111, 0, wxALL, 5 );
	
	m_staticText265211 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265211->Wrap( -1 );
	fgSizer85311->Add( m_staticText265211, 0, wxALL, 5 );
	
	m_staticText265311 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265311->Wrap( -1 );
	fgSizer85311->Add( m_staticText265311, 0, wxALL, 5 );
	
	m_staticText265411 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265411->Wrap( -1 );
	fgSizer85311->Add( m_staticText265411, 0, wxALL, 5 );
	
	m_staticText265511 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265511->Wrap( -1 );
	fgSizer85311->Add( m_staticText265511, 0, wxALL, 5 );
	
	m_staticText265611 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265611->Wrap( -1 );
	fgSizer85311->Add( m_staticText265611, 0, wxALL, 5 );
	
	m_staticText265711 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265711->Wrap( -1 );
	fgSizer85311->Add( m_staticText265711, 0, wxALL, 5 );
	
	m_staticText265811 = new wxStaticText( ID_PANEL_MUX_PD_SEL011, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265811->Wrap( -1 );
	fgSizer85311->Add( m_staticText265811, 0, wxALL, 5 );
	
	chkCHx_LNA_SEL1_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK0, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK1, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK2, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK3, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK4, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK5, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK6, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK7, 0, wxALL, 0 );
	
	chkCHx_LNA_SEL1_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL011, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkCHx_LNA_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer115211->Add( fgSizer85311, 1, wxEXPAND, 5 );
	
	
	fgSizer16011->Add( sbSizer115211, 1, wxEXPAND, 5 );
	
	
	fgSizer88211->Add( fgSizer16011, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL011->SetSizer( fgSizer88211 );
	ID_PANEL_MUX_PD_SEL011->Layout();
	fgSizer88211->Fit( ID_PANEL_MUX_PD_SEL011 );
	ID_NOTEBOOK_MUX_CONTROL_LNA->AddPage( ID_PANEL_MUX_PD_SEL011, wxT("Bit 1"), false );
	
	fgSizer372->Add( ID_NOTEBOOK_MUX_CONTROL_LNA, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3041;
	sbSizer3041 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3701;
	fgSizer3701 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3701->SetFlexibleDirection( wxBOTH );
	fgSizer3701->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_LNA_INT_SEL0 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkCHx_LNA_INT_SEL0, 0, wxALL, 5 );
	
	chkCHx_LNA_INT_SEL1 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkCHx_LNA_INT_SEL1, 0, wxALL, 5 );
	
	
	sbSizer3041->Add( fgSizer3701, 1, wxEXPAND, 5 );
	
	
	fgSizer372->Add( sbSizer3041, 1, wxEXPAND, 5 );
	
	
	sbSizer1711->Add( fgSizer372, 1, wxEXPAND, 5 );
	
	
	fgSizer161->Add( sbSizer1711, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1712;
	sbSizer1712 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("PA") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer375;
	fgSizer375 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer375->SetFlexibleDirection( wxBOTH );
	fgSizer375->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_MUX_CONTROL_PA = new wxNotebook( ID_PANEL_CHANNEL, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_MUX_PD_SEL03 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PA, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8823;
	fgSizer8823 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8823->SetFlexibleDirection( wxBOTH );
	fgSizer8823->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1603;
	fgSizer1603 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1603->SetFlexibleDirection( wxBOTH );
	fgSizer1603->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1683;
	sbSizer1683 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1593;
	fgSizer1593 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1593->SetFlexibleDirection( wxBOTH );
	fgSizer1593->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PA_SEL0_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1593->Add( chkCHx_PA_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1593->Add( chkCHx_PA_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1683->Add( fgSizer1593, 1, wxEXPAND, 5 );
	
	
	fgSizer1603->Add( sbSizer1683, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11523;
	sbSizer11523 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8533;
	fgSizer8533 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8533->SetFlexibleDirection( wxBOTH );
	fgSizer8533->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26513 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26513->Wrap( -1 );
	fgSizer8533->Add( m_staticText26513, 0, wxALL, 5 );
	
	m_staticText26514 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26514->Wrap( -1 );
	fgSizer8533->Add( m_staticText26514, 0, wxALL, 5 );
	
	m_staticText26523 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26523->Wrap( -1 );
	fgSizer8533->Add( m_staticText26523, 0, wxALL, 5 );
	
	m_staticText26533 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26533->Wrap( -1 );
	fgSizer8533->Add( m_staticText26533, 0, wxALL, 5 );
	
	m_staticText26543 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26543->Wrap( -1 );
	fgSizer8533->Add( m_staticText26543, 0, wxALL, 5 );
	
	m_staticText26553 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26553->Wrap( -1 );
	fgSizer8533->Add( m_staticText26553, 0, wxALL, 5 );
	
	m_staticText26563 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26563->Wrap( -1 );
	fgSizer8533->Add( m_staticText26563, 0, wxALL, 5 );
	
	m_staticText26573 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26573->Wrap( -1 );
	fgSizer8533->Add( m_staticText26573, 0, wxALL, 5 );
	
	m_staticText26583 = new wxStaticText( ID_PANEL_MUX_PD_SEL03, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26583->Wrap( -1 );
	fgSizer8533->Add( m_staticText26583, 0, wxALL, 5 );
	
	chkCHx_PA_SEL0_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK0, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK1, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK2, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK3, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK4, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK5, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK6, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK7, 0, wxALL, 0 );
	
	chkCHx_PA_SEL0_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL03, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8533->Add( chkCHx_PA_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11523->Add( fgSizer8533, 1, wxEXPAND, 5 );
	
	
	fgSizer1603->Add( sbSizer11523, 1, wxEXPAND, 5 );
	
	
	fgSizer8823->Add( fgSizer1603, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL03->SetSizer( fgSizer8823 );
	ID_PANEL_MUX_PD_SEL03->Layout();
	fgSizer8823->Fit( ID_PANEL_MUX_PD_SEL03 );
	ID_NOTEBOOK_MUX_CONTROL_PA->AddPage( ID_PANEL_MUX_PD_SEL03, wxT("Bit 0"), true );
	ID_PANEL_MUX_PD_SEL012 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PA, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88212;
	fgSizer88212 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88212->SetFlexibleDirection( wxBOTH );
	fgSizer88212->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer16012;
	fgSizer16012 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer16012->SetFlexibleDirection( wxBOTH );
	fgSizer16012->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer16812;
	sbSizer16812 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15912;
	fgSizer15912 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer15912->SetFlexibleDirection( wxBOTH );
	fgSizer15912->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PA_SEL1_INTERNAL = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15912->Add( chkCHx_PA_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_INVERT = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15912->Add( chkCHx_PA_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer16812->Add( fgSizer15912, 1, wxEXPAND, 5 );
	
	
	fgSizer16012->Add( sbSizer16812, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer115212;
	sbSizer115212 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85312;
	fgSizer85312 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer85312->SetFlexibleDirection( wxBOTH );
	fgSizer85312->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26592 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26592->Wrap( -1 );
	fgSizer85312->Add( m_staticText26592, 0, wxALL, 5 );
	
	m_staticText265112 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265112->Wrap( -1 );
	fgSizer85312->Add( m_staticText265112, 0, wxALL, 5 );
	
	m_staticText265212 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265212->Wrap( -1 );
	fgSizer85312->Add( m_staticText265212, 0, wxALL, 5 );
	
	m_staticText265312 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265312->Wrap( -1 );
	fgSizer85312->Add( m_staticText265312, 0, wxALL, 5 );
	
	m_staticText265412 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265412->Wrap( -1 );
	fgSizer85312->Add( m_staticText265412, 0, wxALL, 5 );
	
	m_staticText265512 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265512->Wrap( -1 );
	fgSizer85312->Add( m_staticText265512, 0, wxALL, 5 );
	
	m_staticText265612 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265612->Wrap( -1 );
	fgSizer85312->Add( m_staticText265612, 0, wxALL, 5 );
	
	m_staticText265712 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265712->Wrap( -1 );
	fgSizer85312->Add( m_staticText265712, 0, wxALL, 5 );
	
	m_staticText265812 = new wxStaticText( ID_PANEL_MUX_PD_SEL012, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265812->Wrap( -1 );
	fgSizer85312->Add( m_staticText265812, 0, wxALL, 5 );
	
	chkCHx_PA_SEL1_MASK0 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK0, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK1 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK1, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK2 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK2, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK3 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK3, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK4 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK4, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK5 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK5, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK6 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK6, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK7 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK7, 0, wxALL, 0 );
	
	chkCHx_PA_SEL1_MASK8 = new wxCheckBox( ID_PANEL_MUX_PD_SEL012, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85312->Add( chkCHx_PA_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer115212->Add( fgSizer85312, 1, wxEXPAND, 5 );
	
	
	fgSizer16012->Add( sbSizer115212, 1, wxEXPAND, 5 );
	
	
	fgSizer88212->Add( fgSizer16012, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_PD_SEL012->SetSizer( fgSizer88212 );
	ID_PANEL_MUX_PD_SEL012->Layout();
	fgSizer88212->Fit( ID_PANEL_MUX_PD_SEL012 );
	ID_NOTEBOOK_MUX_CONTROL_PA->AddPage( ID_PANEL_MUX_PD_SEL012, wxT("Bit 1"), false );
	
	fgSizer375->Add( ID_NOTEBOOK_MUX_CONTROL_PA, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer30411;
	sbSizer30411 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_CHANNEL, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer37011;
	fgSizer37011 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer37011->SetFlexibleDirection( wxBOTH );
	fgSizer37011->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkCHx_PA_INT_SEL0 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer37011->Add( chkCHx_PA_INT_SEL0, 0, wxALL, 5 );
	
	chkCHx_PA_INT_SEL1 = new wxCheckBox( ID_PANEL_CHANNEL, ID_CHx_PA_ILIN2X, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer37011->Add( chkCHx_PA_INT_SEL1, 0, wxALL, 5 );
	
	
	sbSizer30411->Add( fgSizer37011, 1, wxEXPAND, 5 );
	
	
	fgSizer375->Add( sbSizer30411, 1, wxEXPAND, 5 );
	
	
	sbSizer1712->Add( fgSizer375, 1, wxEXPAND, 5 );
	
	
	fgSizer161->Add( sbSizer1712, 1, wxEXPAND, 5 );
	
	
	sbSizer143->Add( fgSizer161, 1, wxEXPAND, 5 );
	
	
	fgSizer126->Add( sbSizer143, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer126, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_CHANNEL->SetSizer( fgSizer69 );
	ID_PANEL_CHANNEL->Layout();
	fgSizer69->Fit( ID_PANEL_CHANNEL );
	ID_NOTEBOOK_CHANNEL->AddPage( ID_PANEL_CHANNEL, wxT("Channel"), false );
	
	fgSizer68->Add( ID_NOTEBOOK_CHANNEL, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	chkCHx_PA_ILIN2X->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel1->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel11->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel111->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel1111->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
}

pnlChannel_view::~pnlChannel_view()
{
	// Disconnect Events
	chkCHx_PA_ILIN2X->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_LIN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_ICT_MAIN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel1->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel11->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel111->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	pnlChannel1111->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( pnlChannel_view::OnEraseBackground_pnlChannel ), NULL, this );
	chkCHx_LNA_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXB_LOBUFF_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_MIXA_LOBUFF_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_R50_EN_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_BYPASS_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_BYPASS0 ), NULL, this );
	chkCHx_PA_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::OnClick_chkCHx_PA_PD0 ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_LIN_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_ICT_MAIN_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_CGSCTRL_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_LNA_GCTRL_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_LIN_LOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	cmbCHx_PA_MAIN_LOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PD_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_LNA_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	chkCHx_PA_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlChannel_view::ParameterChangeHandler ), NULL, this );
	
}

pnlHLMIX_view::pnlHLMIX_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_HLMIX = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_HLMIX = new wxPanel( ID_NOTEBOOK_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer69;
	fgSizer69 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer69->SetFlexibleDirection( wxBOTH );
	fgSizer69->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_HLMIX_PROGRAM = new wxNotebook( ID_PANEL_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_HLMIX_P0 = new wxPanel( ID_NOTEBOOK_HLMIX_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer378;
	fgSizer378 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer378->SetFlexibleDirection( wxBOTH );
	fgSizer378->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer312;
	sbSizer312 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P0, wxID_ANY, wxT("Configuration") ), wxVERTICAL );
	
	m_staticText6493 = new wxStaticText( ID_PANEL_HLMIX_P0, wxID_ANY, wxT("LO bias voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6493->Wrap( -1 );
	sbSizer312->Add( m_staticText6493, 0, wxALL, 0 );
	
	cmbHLMIXx_VGCAS0 = new wxSpinCtrl( ID_PANEL_HLMIX_P0, ID_HLMIXx_VGCAS0, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 64 );
	sbSizer312->Add( cmbHLMIXx_VGCAS0, 0, wxALL, 0 );
	
	m_staticText649 = new wxStaticText( ID_PANEL_HLMIX_P0, wxID_ANY, wxT("Bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText649->Wrap( -1 );
	sbSizer312->Add( m_staticText649, 0, wxALL, 0 );
	
	cmbHLMIXx_ICT_BIAS0 = new wxSpinCtrl( ID_PANEL_HLMIX_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer312->Add( cmbHLMIXx_ICT_BIAS0, 0, wxALL, 0 );
	
	chkHLMIXx_BIAS_PD0 = new wxCheckBox( ID_PANEL_HLMIX_P0, ID_CHx_PA_ILIN2X, wxT("BIAS_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer312->Add( chkHLMIXx_BIAS_PD0, 0, wxALL, 0 );
	
	chkHLMIXx_LOBUF_PD0 = new wxCheckBox( ID_PANEL_HLMIX_P0, ID_CHx_PA_ILIN2X, wxT("LOBUF_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer312->Add( chkHLMIXx_LOBUF_PD0, 0, wxALL, 0 );
	
	
	fgSizer378->Add( sbSizer312, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3121;
	sbSizer3121 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P0, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	m_staticText6491 = new wxStaticText( ID_PANEL_HLMIX_P0, wxID_ANY, wxT("Loss control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6491->Wrap( -1 );
	sbSizer3121->Add( m_staticText6491, 0, wxALL, 0 );
	
	cmbHLMIXx_MIXLOSS0 = new wxSpinCtrl( ID_PANEL_HLMIX_P0, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	sbSizer3121->Add( cmbHLMIXx_MIXLOSS0, 0, wxALL, 0 );
	
	
	fgSizer378->Add( sbSizer3121, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX_P0->SetSizer( fgSizer378 );
	ID_PANEL_HLMIX_P0->Layout();
	fgSizer378->Fit( ID_PANEL_HLMIX_P0 );
	ID_NOTEBOOK_HLMIX_PROGRAM->AddPage( ID_PANEL_HLMIX_P0, wxT("Prog. 0"), true );
	ID_PANEL_HLMIX_P1 = new wxPanel( ID_NOTEBOOK_HLMIX_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer3781;
	fgSizer3781 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3781->SetFlexibleDirection( wxBOTH );
	fgSizer3781->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3122;
	sbSizer3122 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P1, wxID_ANY, wxT("Config") ), wxVERTICAL );
	
	m_staticText64922 = new wxStaticText( ID_PANEL_HLMIX_P1, wxID_ANY, wxT("LO bias voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64922->Wrap( -1 );
	sbSizer3122->Add( m_staticText64922, 0, wxALL, 0 );
	
	cmbHLMIXx_VGCAS1 = new wxSpinCtrl( ID_PANEL_HLMIX_P1, ID_HLMIXx_VGCAS1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 64 );
	sbSizer3122->Add( cmbHLMIXx_VGCAS1, 0, wxALL, 0 );
	
	m_staticText6492 = new wxStaticText( ID_PANEL_HLMIX_P1, wxID_ANY, wxT("Bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6492->Wrap( -1 );
	sbSizer3122->Add( m_staticText6492, 0, wxALL, 0 );
	
	cmbHLMIXx_ICT_BIAS1 = new wxSpinCtrl( ID_PANEL_HLMIX_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer3122->Add( cmbHLMIXx_ICT_BIAS1, 0, wxALL, 0 );
	
	chkHLMIXx_BIAS_PD1 = new wxCheckBox( ID_PANEL_HLMIX_P1, ID_CHx_PA_ILIN2X, wxT("BIAS_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3122->Add( chkHLMIXx_BIAS_PD1, 0, wxALL, 0 );
	
	chkHLMIXx_LOBUF_PD1 = new wxCheckBox( ID_PANEL_HLMIX_P1, ID_CHx_PA_ILIN2X, wxT("LOBUF_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3122->Add( chkHLMIXx_LOBUF_PD1, 0, wxALL, 0 );
	
	
	fgSizer3781->Add( sbSizer3122, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer31211;
	sbSizer31211 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P1, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	m_staticText64912 = new wxStaticText( ID_PANEL_HLMIX_P1, wxID_ANY, wxT("Loss control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64912->Wrap( -1 );
	sbSizer31211->Add( m_staticText64912, 0, wxALL, 0 );
	
	cmbHLMIXx_MIXLOSS1 = new wxSpinCtrl( ID_PANEL_HLMIX_P1, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	sbSizer31211->Add( cmbHLMIXx_MIXLOSS1, 0, wxALL, 0 );
	
	
	fgSizer3781->Add( sbSizer31211, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX_P1->SetSizer( fgSizer3781 );
	ID_PANEL_HLMIX_P1->Layout();
	fgSizer3781->Fit( ID_PANEL_HLMIX_P1 );
	ID_NOTEBOOK_HLMIX_PROGRAM->AddPage( ID_PANEL_HLMIX_P1, wxT("Prog. 1"), false );
	ID_PANEL_HLMIX_P2 = new wxPanel( ID_NOTEBOOK_HLMIX_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer37811;
	fgSizer37811 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer37811->SetFlexibleDirection( wxBOTH );
	fgSizer37811->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer31221;
	sbSizer31221 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P2, wxID_ANY, wxT("Config") ), wxVERTICAL );
	
	m_staticText649212 = new wxStaticText( ID_PANEL_HLMIX_P2, wxID_ANY, wxT("LO bias voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText649212->Wrap( -1 );
	sbSizer31221->Add( m_staticText649212, 0, wxALL, 0 );
	
	cmbHLMIXx_VGCAS2 = new wxSpinCtrl( ID_PANEL_HLMIX_P2, ID_HLMIXx_VGCAS2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 64 );
	sbSizer31221->Add( cmbHLMIXx_VGCAS2, 0, wxALL, 0 );
	
	m_staticText64921 = new wxStaticText( ID_PANEL_HLMIX_P2, wxID_ANY, wxT("Bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64921->Wrap( -1 );
	sbSizer31221->Add( m_staticText64921, 0, wxALL, 0 );
	
	cmbHLMIXx_ICT_BIAS2 = new wxSpinCtrl( ID_PANEL_HLMIX_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer31221->Add( cmbHLMIXx_ICT_BIAS2, 0, wxALL, 0 );
	
	chkHLMIXx_BIAS_PD2 = new wxCheckBox( ID_PANEL_HLMIX_P2, ID_CHx_PA_ILIN2X, wxT("BIAS_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer31221->Add( chkHLMIXx_BIAS_PD2, 0, wxALL, 0 );
	
	chkHLMIXx_LOBUF_PD2 = new wxCheckBox( ID_PANEL_HLMIX_P2, ID_CHx_PA_ILIN2X, wxT("LOBUF_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer31221->Add( chkHLMIXx_LOBUF_PD2, 0, wxALL, 0 );
	
	
	fgSizer37811->Add( sbSizer31221, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer312111;
	sbSizer312111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P2, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	m_staticText649121 = new wxStaticText( ID_PANEL_HLMIX_P2, wxID_ANY, wxT("Loss control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText649121->Wrap( -1 );
	sbSizer312111->Add( m_staticText649121, 0, wxALL, 0 );
	
	cmbHLMIXx_MIXLOSS2 = new wxSpinCtrl( ID_PANEL_HLMIX_P2, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	sbSizer312111->Add( cmbHLMIXx_MIXLOSS2, 0, wxALL, 0 );
	
	
	fgSizer37811->Add( sbSizer312111, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX_P2->SetSizer( fgSizer37811 );
	ID_PANEL_HLMIX_P2->Layout();
	fgSizer37811->Fit( ID_PANEL_HLMIX_P2 );
	ID_NOTEBOOK_HLMIX_PROGRAM->AddPage( ID_PANEL_HLMIX_P2, wxT("Prog. 2"), false );
	ID_PANEL_HLMIX_P3 = new wxPanel( ID_NOTEBOOK_HLMIX_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer378111;
	fgSizer378111 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer378111->SetFlexibleDirection( wxBOTH );
	fgSizer378111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer312211;
	sbSizer312211 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P3, wxID_ANY, wxT("Config") ), wxVERTICAL );
	
	m_staticText6492121 = new wxStaticText( ID_PANEL_HLMIX_P3, wxID_ANY, wxT("LO bias voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6492121->Wrap( -1 );
	sbSizer312211->Add( m_staticText6492121, 0, wxALL, 0 );
	
	cmbHLMIXx_VGCAS3 = new wxSpinCtrl( ID_PANEL_HLMIX_P3, ID_HLMIXx_VGCAS3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 64 );
	sbSizer312211->Add( cmbHLMIXx_VGCAS3, 0, wxALL, 0 );
	
	m_staticText649211 = new wxStaticText( ID_PANEL_HLMIX_P3, wxID_ANY, wxT("Bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText649211->Wrap( -1 );
	sbSizer312211->Add( m_staticText649211, 0, wxALL, 0 );
	
	cmbHLMIXx_ICT_BIAS3 = new wxSpinCtrl( ID_PANEL_HLMIX_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer312211->Add( cmbHLMIXx_ICT_BIAS3, 0, wxALL, 0 );
	
	chkHLMIXx_BIAS_PD3 = new wxCheckBox( ID_PANEL_HLMIX_P3, ID_CHx_PA_ILIN2X, wxT("BIAS_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer312211->Add( chkHLMIXx_BIAS_PD3, 0, wxALL, 0 );
	
	chkHLMIXx_LOBUF_PD3 = new wxCheckBox( ID_PANEL_HLMIX_P3, ID_CHx_PA_ILIN2X, wxT("LOBUF_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer312211->Add( chkHLMIXx_LOBUF_PD3, 0, wxALL, 0 );
	
	
	fgSizer378111->Add( sbSizer312211, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3121111;
	sbSizer3121111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_P3, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	m_staticText6491211 = new wxStaticText( ID_PANEL_HLMIX_P3, wxID_ANY, wxT("Loss control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6491211->Wrap( -1 );
	sbSizer3121111->Add( m_staticText6491211, 0, wxALL, 0 );
	
	cmbHLMIXx_MIXLOSS3 = new wxSpinCtrl( ID_PANEL_HLMIX_P3, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	sbSizer3121111->Add( cmbHLMIXx_MIXLOSS3, 0, wxALL, 0 );
	
	
	fgSizer378111->Add( sbSizer3121111, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX_P3->SetSizer( fgSizer378111 );
	ID_PANEL_HLMIX_P3->Layout();
	fgSizer378111->Fit( ID_PANEL_HLMIX_P3 );
	ID_NOTEBOOK_HLMIX_PROGRAM->AddPage( ID_PANEL_HLMIX_P3, wxT("Prog. 3"), false );
	ID_PANEL_HLMIX_RB = new wxPanel( ID_NOTEBOOK_HLMIX_PROGRAM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer3781111;
	fgSizer3781111 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3781111->SetFlexibleDirection( wxBOTH );
	fgSizer3781111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3122111;
	sbSizer3122111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_RB, wxID_ANY, wxT("Config") ), wxVERTICAL );
	
	m_staticText64921211 = new wxStaticText( ID_PANEL_HLMIX_RB, wxID_ANY, wxT("LO bias voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64921211->Wrap( -1 );
	sbSizer3122111->Add( m_staticText64921211, 0, wxALL, 0 );
	
	cmbHLMIXx_VGCAS_RB = new wxSpinCtrl( ID_PANEL_HLMIX_RB, ID_HLMIXx_VGCAS3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 64 );
	cmbHLMIXx_VGCAS_RB->Enable( false );
	
	sbSizer3122111->Add( cmbHLMIXx_VGCAS_RB, 0, wxALL, 0 );
	
	m_staticText6492111 = new wxStaticText( ID_PANEL_HLMIX_RB, wxID_ANY, wxT("Bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6492111->Wrap( -1 );
	sbSizer3122111->Add( m_staticText6492111, 0, wxALL, 0 );
	
	cmbHLMIXx_ICT_BIAS_RB = new wxSpinCtrl( ID_PANEL_HLMIX_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	cmbHLMIXx_ICT_BIAS_RB->Enable( false );
	
	sbSizer3122111->Add( cmbHLMIXx_ICT_BIAS_RB, 0, wxALL, 0 );
	
	chkHLMIXx_BIAS_PD_RB = new wxCheckBox( ID_PANEL_HLMIX_RB, ID_CHx_PA_ILIN2X, wxT("BIAS_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	chkHLMIXx_BIAS_PD_RB->Enable( false );
	
	sbSizer3122111->Add( chkHLMIXx_BIAS_PD_RB, 0, wxALL, 0 );
	
	chkHLMIXx_LOBUF_PD_RB = new wxCheckBox( ID_PANEL_HLMIX_RB, ID_CHx_PA_ILIN2X, wxT("LOBUF_PD"), wxDefaultPosition, wxDefaultSize, 0 );
	chkHLMIXx_LOBUF_PD_RB->Enable( false );
	
	sbSizer3122111->Add( chkHLMIXx_LOBUF_PD_RB, 0, wxALL, 0 );
	
	
	fgSizer3781111->Add( sbSizer3122111, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer31211111;
	sbSizer31211111 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX_RB, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	m_staticText64912111 = new wxStaticText( ID_PANEL_HLMIX_RB, wxID_ANY, wxT("Loss control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64912111->Wrap( -1 );
	sbSizer31211111->Add( m_staticText64912111, 0, wxALL, 0 );
	
	cmbHLMIXx_MIXLOSS_RB = new wxSpinCtrl( ID_PANEL_HLMIX_RB, ID_RP_CALIB_BIAS, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	cmbHLMIXx_MIXLOSS_RB->Enable( false );
	
	sbSizer31211111->Add( cmbHLMIXx_MIXLOSS_RB, 0, wxALL, 0 );
	
	
	fgSizer3781111->Add( sbSizer31211111, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX_RB->SetSizer( fgSizer3781111 );
	ID_PANEL_HLMIX_RB->Layout();
	fgSizer3781111->Fit( ID_PANEL_HLMIX_RB );
	ID_NOTEBOOK_HLMIX_PROGRAM->AddPage( ID_PANEL_HLMIX_RB, wxT("Readback"), false );
	
	fgSizer69->Add( ID_NOTEBOOK_HLMIX_PROGRAM, 1, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer126;
	fgSizer126 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer126->SetFlexibleDirection( wxBOTH );
	fgSizer126->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer171;
	sbSizer171 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX, wxID_ANY, wxT("MUX Control") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer369;
	fgSizer369 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer369->SetFlexibleDirection( wxBOTH );
	fgSizer369->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3941;
	sbSizer3941 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX, wxID_ANY, wxT("Configuration") ), wxVERTICAL );
	
	ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG = new wxNotebook( ID_PANEL_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_MUX_HLMIX_CONFIG_SEL0 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8822;
	fgSizer8822 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8822->SetFlexibleDirection( wxBOTH );
	fgSizer8822->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1602;
	fgSizer1602 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1602->SetFlexibleDirection( wxBOTH );
	fgSizer1602->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1682;
	sbSizer1682 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1592;
	fgSizer1592 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1592->SetFlexibleDirection( wxBOTH );
	fgSizer1592->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_CONFIG_SEL0_INTERNAL = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1592->Add( chkHLMIXx_CONFIG_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_INVERT = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1592->Add( chkHLMIXx_CONFIG_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1682->Add( fgSizer1592, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer1682, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11522;
	sbSizer11522 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8532;
	fgSizer8532 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8532->SetFlexibleDirection( wxBOTH );
	fgSizer8532->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26510 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26510->Wrap( -1 );
	fgSizer8532->Add( m_staticText26510, 0, wxALL, 5 );
	
	m_staticText26512 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26512->Wrap( -1 );
	fgSizer8532->Add( m_staticText26512, 0, wxALL, 5 );
	
	m_staticText26522 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26522->Wrap( -1 );
	fgSizer8532->Add( m_staticText26522, 0, wxALL, 5 );
	
	m_staticText26532 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26532->Wrap( -1 );
	fgSizer8532->Add( m_staticText26532, 0, wxALL, 5 );
	
	m_staticText26542 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26542->Wrap( -1 );
	fgSizer8532->Add( m_staticText26542, 0, wxALL, 5 );
	
	m_staticText26552 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26552->Wrap( -1 );
	fgSizer8532->Add( m_staticText26552, 0, wxALL, 5 );
	
	m_staticText26562 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26562->Wrap( -1 );
	fgSizer8532->Add( m_staticText26562, 0, wxALL, 5 );
	
	m_staticText26572 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26572->Wrap( -1 );
	fgSizer8532->Add( m_staticText26572, 0, wxALL, 5 );
	
	m_staticText26582 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26582->Wrap( -1 );
	fgSizer8532->Add( m_staticText26582, 0, wxALL, 5 );
	
	chkHLMIXx_CONFIG_SEL0_MASK0 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK0, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK1 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK1, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK2 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK2, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK3 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK3, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK4 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK4, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK5 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK5, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK6 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK6, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK7 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK7, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL0_MASK8 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkHLMIXx_CONFIG_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11522->Add( fgSizer8532, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer11522, 1, wxEXPAND, 5 );
	
	
	fgSizer8822->Add( fgSizer1602, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_HLMIX_CONFIG_SEL0->SetSizer( fgSizer8822 );
	ID_PANEL_MUX_HLMIX_CONFIG_SEL0->Layout();
	fgSizer8822->Fit( ID_PANEL_MUX_HLMIX_CONFIG_SEL0 );
	ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG->AddPage( ID_PANEL_MUX_HLMIX_CONFIG_SEL0, wxT("Bit 0"), true );
	ID_PANEL_MUX_HLMIX_CONFIG_SEL1 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88211;
	fgSizer88211 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88211->SetFlexibleDirection( wxBOTH );
	fgSizer88211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer16011;
	fgSizer16011 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer16011->SetFlexibleDirection( wxBOTH );
	fgSizer16011->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer16811;
	sbSizer16811 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15911;
	fgSizer15911 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer15911->SetFlexibleDirection( wxBOTH );
	fgSizer15911->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_CONFIG_SEL1_INTERNAL = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15911->Add( chkHLMIXx_CONFIG_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_INVERT = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15911->Add( chkHLMIXx_CONFIG_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer16811->Add( fgSizer15911, 1, wxEXPAND, 5 );
	
	
	fgSizer16011->Add( sbSizer16811, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer115211;
	sbSizer115211 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85311;
	fgSizer85311 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer85311->SetFlexibleDirection( wxBOTH );
	fgSizer85311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26591 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26591->Wrap( -1 );
	fgSizer85311->Add( m_staticText26591, 0, wxALL, 5 );
	
	m_staticText265111 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265111->Wrap( -1 );
	fgSizer85311->Add( m_staticText265111, 0, wxALL, 5 );
	
	m_staticText265211 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265211->Wrap( -1 );
	fgSizer85311->Add( m_staticText265211, 0, wxALL, 5 );
	
	m_staticText265311 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265311->Wrap( -1 );
	fgSizer85311->Add( m_staticText265311, 0, wxALL, 5 );
	
	m_staticText265411 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265411->Wrap( -1 );
	fgSizer85311->Add( m_staticText265411, 0, wxALL, 5 );
	
	m_staticText265511 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265511->Wrap( -1 );
	fgSizer85311->Add( m_staticText265511, 0, wxALL, 5 );
	
	m_staticText265611 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265611->Wrap( -1 );
	fgSizer85311->Add( m_staticText265611, 0, wxALL, 5 );
	
	m_staticText265711 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265711->Wrap( -1 );
	fgSizer85311->Add( m_staticText265711, 0, wxALL, 5 );
	
	m_staticText265811 = new wxStaticText( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265811->Wrap( -1 );
	fgSizer85311->Add( m_staticText265811, 0, wxALL, 5 );
	
	chkHLMIXx_CONFIG_SEL1_MASK0 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK0, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK1 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK1, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK2 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK2, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK3 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK3, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK4 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK4, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK5 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK5, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK6 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK6, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK7 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK7, 0, wxALL, 0 );
	
	chkHLMIXx_CONFIG_SEL1_MASK8 = new wxCheckBox( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85311->Add( chkHLMIXx_CONFIG_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer115211->Add( fgSizer85311, 1, wxEXPAND, 5 );
	
	
	fgSizer16011->Add( sbSizer115211, 1, wxEXPAND, 5 );
	
	
	fgSizer88211->Add( fgSizer16011, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_HLMIX_CONFIG_SEL1->SetSizer( fgSizer88211 );
	ID_PANEL_MUX_HLMIX_CONFIG_SEL1->Layout();
	fgSizer88211->Fit( ID_PANEL_MUX_HLMIX_CONFIG_SEL1 );
	ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG->AddPage( ID_PANEL_MUX_HLMIX_CONFIG_SEL1, wxT("Bit 1"), false );
	
	sbSizer3941->Add( ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3041;
	sbSizer3041 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3701;
	fgSizer3701 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3701->SetFlexibleDirection( wxBOTH );
	fgSizer3701->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_CONFIG_INT_SEL0 = new wxCheckBox( ID_PANEL_HLMIX, ID_CHx_PA_ILIN2X, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkHLMIXx_CONFIG_INT_SEL0, 0, wxALL, 5 );
	
	chkHLMIXx_CONFIG_INT_SEL1 = new wxCheckBox( ID_PANEL_HLMIX, ID_CHx_PA_ILIN2X, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkHLMIXx_CONFIG_INT_SEL1, 0, wxALL, 5 );
	
	
	sbSizer3041->Add( fgSizer3701, 1, wxEXPAND, 5 );
	
	
	sbSizer3941->Add( sbSizer3041, 0, wxEXPAND, 5 );
	
	
	fgSizer369->Add( sbSizer3941, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer394;
	sbSizer394 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX, wxID_ANY, wxT("Loss") ), wxVERTICAL );
	
	ID_NOTEBOOK_MUX_CONTROL_HLMIX = new wxNotebook( ID_PANEL_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_MUX_HLMIX_SEL0 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer882;
	fgSizer882 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer882->SetFlexibleDirection( wxBOTH );
	fgSizer882->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer160;
	fgSizer160 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer160->SetFlexibleDirection( wxBOTH );
	fgSizer160->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer168;
	sbSizer168 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer159;
	fgSizer159 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer159->SetFlexibleDirection( wxBOTH );
	fgSizer159->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_LOSS_SEL0_INTERNAL = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer159->Add( chkHLMIXx_LOSS_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_INVERT = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer159->Add( chkHLMIXx_LOSS_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer168->Add( fgSizer159, 1, wxEXPAND, 5 );
	
	
	fgSizer160->Add( sbSizer168, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1152;
	sbSizer1152 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer853;
	fgSizer853 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer853->SetFlexibleDirection( wxBOTH );
	fgSizer853->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText265 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265->Wrap( -1 );
	fgSizer853->Add( m_staticText265, 0, wxALL, 5 );
	
	m_staticText2651 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2651->Wrap( -1 );
	fgSizer853->Add( m_staticText2651, 0, wxALL, 5 );
	
	m_staticText2652 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2652->Wrap( -1 );
	fgSizer853->Add( m_staticText2652, 0, wxALL, 5 );
	
	m_staticText2653 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2653->Wrap( -1 );
	fgSizer853->Add( m_staticText2653, 0, wxALL, 5 );
	
	m_staticText2654 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2654->Wrap( -1 );
	fgSizer853->Add( m_staticText2654, 0, wxALL, 5 );
	
	m_staticText2655 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2655->Wrap( -1 );
	fgSizer853->Add( m_staticText2655, 0, wxALL, 5 );
	
	m_staticText2656 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2656->Wrap( -1 );
	fgSizer853->Add( m_staticText2656, 0, wxALL, 5 );
	
	m_staticText2657 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2657->Wrap( -1 );
	fgSizer853->Add( m_staticText2657, 0, wxALL, 5 );
	
	m_staticText2658 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL0, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2658->Wrap( -1 );
	fgSizer853->Add( m_staticText2658, 0, wxALL, 5 );
	
	chkHLMIXx_LOSS_SEL0_MASK0 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK0, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK1 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK1, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK2 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK2, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK3 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK3, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK4 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK4, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK5 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK5, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK6 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK6, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK7 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK7, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL0_MASK8 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL0, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853->Add( chkHLMIXx_LOSS_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer1152->Add( fgSizer853, 1, wxEXPAND, 5 );
	
	
	fgSizer160->Add( sbSizer1152, 1, wxEXPAND, 5 );
	
	
	fgSizer882->Add( fgSizer160, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_HLMIX_SEL0->SetSizer( fgSizer882 );
	ID_PANEL_MUX_HLMIX_SEL0->Layout();
	fgSizer882->Fit( ID_PANEL_MUX_HLMIX_SEL0 );
	ID_NOTEBOOK_MUX_CONTROL_HLMIX->AddPage( ID_PANEL_MUX_HLMIX_SEL0, wxT("Bit 0"), true );
	ID_PANEL_MUX_HLMIX_SEL1 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_HLMIX, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8821;
	fgSizer8821 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8821->SetFlexibleDirection( wxBOTH );
	fgSizer8821->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1601;
	fgSizer1601 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1601->SetFlexibleDirection( wxBOTH );
	fgSizer1601->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1681;
	sbSizer1681 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1591;
	fgSizer1591 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1591->SetFlexibleDirection( wxBOTH );
	fgSizer1591->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_LOSS_SEL1_INTERNAL = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1591->Add( chkHLMIXx_LOSS_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_INVERT = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1591->Add( chkHLMIXx_LOSS_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1681->Add( fgSizer1591, 1, wxEXPAND, 5 );
	
	
	fgSizer1601->Add( sbSizer1681, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11521;
	sbSizer11521 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8531;
	fgSizer8531 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8531->SetFlexibleDirection( wxBOTH );
	fgSizer8531->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2659 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2659->Wrap( -1 );
	fgSizer8531->Add( m_staticText2659, 0, wxALL, 5 );
	
	m_staticText26511 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26511->Wrap( -1 );
	fgSizer8531->Add( m_staticText26511, 0, wxALL, 5 );
	
	m_staticText26521 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26521->Wrap( -1 );
	fgSizer8531->Add( m_staticText26521, 0, wxALL, 5 );
	
	m_staticText26531 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26531->Wrap( -1 );
	fgSizer8531->Add( m_staticText26531, 0, wxALL, 5 );
	
	m_staticText26541 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26541->Wrap( -1 );
	fgSizer8531->Add( m_staticText26541, 0, wxALL, 5 );
	
	m_staticText26551 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26551->Wrap( -1 );
	fgSizer8531->Add( m_staticText26551, 0, wxALL, 5 );
	
	m_staticText26561 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26561->Wrap( -1 );
	fgSizer8531->Add( m_staticText26561, 0, wxALL, 5 );
	
	m_staticText26571 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26571->Wrap( -1 );
	fgSizer8531->Add( m_staticText26571, 0, wxALL, 5 );
	
	m_staticText26581 = new wxStaticText( ID_PANEL_MUX_HLMIX_SEL1, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26581->Wrap( -1 );
	fgSizer8531->Add( m_staticText26581, 0, wxALL, 5 );
	
	chkHLMIXx_LOSS_SEL1_MASK0 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK0, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK1 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK1, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK2 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK2, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK3 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK3, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK4 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK4, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK5 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK5, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK6 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK6, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK7 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK7, 0, wxALL, 0 );
	
	chkHLMIXx_LOSS_SEL1_MASK8 = new wxCheckBox( ID_PANEL_MUX_HLMIX_SEL1, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8531->Add( chkHLMIXx_LOSS_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11521->Add( fgSizer8531, 1, wxEXPAND, 5 );
	
	
	fgSizer1601->Add( sbSizer11521, 1, wxEXPAND, 5 );
	
	
	fgSizer8821->Add( fgSizer1601, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_MUX_HLMIX_SEL1->SetSizer( fgSizer8821 );
	ID_PANEL_MUX_HLMIX_SEL1->Layout();
	fgSizer8821->Fit( ID_PANEL_MUX_HLMIX_SEL1 );
	ID_NOTEBOOK_MUX_CONTROL_HLMIX->AddPage( ID_PANEL_MUX_HLMIX_SEL1, wxT("Bit 1"), false );
	
	sbSizer394->Add( ID_NOTEBOOK_MUX_CONTROL_HLMIX, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer304;
	sbSizer304 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_HLMIX, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer370;
	fgSizer370 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer370->SetFlexibleDirection( wxBOTH );
	fgSizer370->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkHLMIXx_LOSS_INT_SEL0 = new wxCheckBox( ID_PANEL_HLMIX, ID_CHx_PA_ILIN2X, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer370->Add( chkHLMIXx_LOSS_INT_SEL0, 0, wxALL, 5 );
	
	chkHLMIXx_LOSS_INT_SEL1 = new wxCheckBox( ID_PANEL_HLMIX, ID_CHx_PA_ILIN2X, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer370->Add( chkHLMIXx_LOSS_INT_SEL1, 0, wxALL, 5 );
	
	
	sbSizer304->Add( fgSizer370, 1, wxEXPAND, 5 );
	
	
	sbSizer394->Add( sbSizer304, 0, wxEXPAND, 5 );
	
	
	fgSizer369->Add( sbSizer394, 1, wxEXPAND, 5 );
	
	
	sbSizer171->Add( fgSizer369, 1, wxEXPAND, 5 );
	
	
	fgSizer126->Add( sbSizer171, 1, wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer126, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_HLMIX->SetSizer( fgSizer69 );
	ID_PANEL_HLMIX->Layout();
	fgSizer69->Fit( ID_PANEL_HLMIX );
	ID_NOTEBOOK_HLMIX->AddPage( ID_PANEL_HLMIX, wxT("HLMIX"), false );
	
	fgSizer68->Add( ID_NOTEBOOK_HLMIX, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	cmbHLMIXx_VGCAS0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD_RB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
}

pnlHLMIX_view::~pnlHLMIX_view()
{
	// Disconnect Events
	cmbHLMIXx_VGCAS0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_VGCAS_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_ICT_BIAS_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_BIAS_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOBUF_PD_RB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	cmbHLMIXx_MIXLOSS_RB->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_CONFIG_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	chkHLMIXx_LOSS_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlHLMIX_view::ParameterChangeHandler ), NULL, this );
	
}

pnlPLLConfig_view::pnlPLLConfig_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ID_NOTEBOOK_PLLCONFIG = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_PANEL_PLLCONFIG = new wxPanel( ID_NOTEBOOK_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer69;
	fgSizer69 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer69->SetFlexibleDirection( wxBOTH );
	fgSizer69->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer126;
	fgSizer126 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer126->SetFlexibleDirection( wxBOTH );
	fgSizer126->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer642;
	fgSizer642 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer642->SetFlexibleDirection( wxBOTH );
	fgSizer642->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer454;
	sbSizer454 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO LDO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer564;
	fgSizer564 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer564->SetFlexibleDirection( wxBOTH );
	fgSizer564->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkEN_VCOBIAS = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("EN_VCOBIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer564->Add( chkEN_VCOBIAS, 0, wxALL, 0 );
	
	chkBYP_VCOREG = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("BYP_VCOREG"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer564->Add( chkBYP_VCOREG, 0, wxALL, 0 );
	
	chkCURLIM_VCOREG = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("CURLIM_VCOREG"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer564->Add( chkCURLIM_VCOREG, 0, wxALL, 0 );
	
	chkSPDUP_VCOREG = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("SPDUP_VCOREG"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer564->Add( chkSPDUP_VCOREG, 0, wxALL, 0 );
	
	m_staticText991 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO LDO Voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText991->Wrap( -1 );
	fgSizer564->Add( m_staticText991, 0, wxALL, 0 );
	
	cmbVDIV_VCOREG = new wxComboBox( ID_PANEL_PLLCONFIG, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer564->Add( cmbVDIV_VCOREG, 0, wxALL, 0 );
	
	
	sbSizer454->Add( fgSizer564, 1, wxEXPAND, 5 );
	
	
	fgSizer642->Add( sbSizer454, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer455;
	sbSizer455 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Clock Buffer") ), wxVERTICAL );
	
	chkPLL_XBUF_SLFBEN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_XBUF_SLFBEN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer455->Add( chkPLL_XBUF_SLFBEN, 0, wxALL, 0 );
	
	chkPLL_XBUF_BYPEN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_XBUF_BYPEN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer455->Add( chkPLL_XBUF_BYPEN, 0, wxALL, 0 );
	
	chkPLL_XBUF_EN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_XBUF_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer455->Add( chkPLL_XBUF_EN, 0, wxALL, 0 );
	
	
	fgSizer642->Add( sbSizer455, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer457;
	sbSizer457 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Manual Calibration") ), wxVERTICAL );
	
	m_staticText99211 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Cap. bank value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99211->Wrap( -1 );
	sbSizer457->Add( m_staticText99211, 0, wxALL, 0 );
	
	cmbVCO_FREQ_MAN = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 128 );
	sbSizer457->Add( cmbVCO_FREQ_MAN, 0, wxALL, 0 );
	
	m_staticText9923 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO Core"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9923->Wrap( -1 );
	sbSizer457->Add( m_staticText9923, 0, wxALL, 0 );
	
	cmbVCO_SEL_MAN = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 3, 0 );
	sbSizer457->Add( cmbVCO_SEL_MAN, 0, wxALL, 0 );
	
	wxFlexGridSizer* fgSizer565;
	fgSizer565 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer565->SetFlexibleDirection( wxBOTH );
	fgSizer565->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText99231 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("LOW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99231->Wrap( -1 );
	fgSizer565->Add( m_staticText99231, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText99232 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("EQ"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99232->Wrap( -1 );
	fgSizer565->Add( m_staticText99232, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText99233 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("HIGH"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99233->Wrap( -1 );
	fgSizer565->Add( m_staticText99233, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	chkFREQ_LOW = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	chkFREQ_LOW->Enable( false );
	
	fgSizer565->Add( chkFREQ_LOW, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	chkFREQ_EQUAL = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	chkFREQ_EQUAL->Enable( false );
	
	fgSizer565->Add( chkFREQ_EQUAL, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	chkFREQ_HIGH = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	chkFREQ_HIGH->Enable( false );
	
	fgSizer565->Add( chkFREQ_HIGH, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	
	sbSizer457->Add( fgSizer565, 0, wxEXPAND, 5 );
	
	chkCTUNE_STEP_DONE = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("CTUNE_STEP_DONE"), wxDefaultPosition, wxDefaultSize, 0 );
	chkCTUNE_STEP_DONE->Enable( false );
	
	sbSizer457->Add( chkCTUNE_STEP_DONE, 0, wxALL, 0 );
	
	chkCTUNE_START = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("CTUNE_START"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer457->Add( chkCTUNE_START, 0, wxALL, 0 );
	
	chkCTUNE_EN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("CTUNE_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer457->Add( chkCTUNE_EN, 0, wxALL, 0 );
	
	
	fgSizer642->Add( sbSizer457, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer505;
	sbSizer505 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Status") ), wxVERTICAL );
	
	m_staticText1184 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO voltage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1184->Wrap( -1 );
	sbSizer505->Add( m_staticText1184, 0, wxALL, 0 );
	
	wxFlexGridSizer* fgSizer5651;
	fgSizer5651 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer5651->SetFlexibleDirection( wxBOTH );
	fgSizer5651->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkVTUNE_HIGH = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_VTUNE_HIGH, wxT("High"), wxDefaultPosition, wxDefaultSize, 0 );
	chkVTUNE_HIGH->Enable( false );
	
	fgSizer5651->Add( chkVTUNE_HIGH, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	chkVTUNE_LOW = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_VTUNE_LOW, wxT("Low"), wxDefaultPosition, wxDefaultSize, 0 );
	chkVTUNE_LOW->Enable( false );
	
	fgSizer5651->Add( chkVTUNE_LOW, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 0 );
	
	chkPLL_LOCK = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_PLL_LOCK, wxT("PLL Lock"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPLL_LOCK->Enable( false );
	
	fgSizer5651->Add( chkPLL_LOCK, 0, wxALL, 0 );
	
	
	sbSizer505->Add( fgSizer5651, 1, wxEXPAND, 5 );
	
	
	fgSizer642->Add( sbSizer505, 1, wxEXPAND, 5 );
	
	
	fgSizer126->Add( fgSizer642, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer456;
	sbSizer456 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Auto Calibration") ), wxVERTICAL );
	
	chkFCAL_START = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("FCAL_START"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer456->Add( chkFCAL_START, 0, wxALL, 0 );
	
	chkVCO_SEL_FINAL_VAL = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("VCO_SEL_FINAL_VAL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkVCO_SEL_FINAL_VAL->Enable( false );
	
	sbSizer456->Add( chkVCO_SEL_FINAL_VAL, 0, wxALL, 0 );
	
	m_staticText992 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO Core"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText992->Wrap( -1 );
	sbSizer456->Add( m_staticText992, 0, wxALL, 0 );
	
	cmbVCO_SEL_FINAL = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 3, 0 );
	cmbVCO_SEL_FINAL->Enable( false );
	
	sbSizer456->Add( cmbVCO_SEL_FINAL, 0, wxALL, 0 );
	
	chkFREQ_FINAL_VAL = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("FREQ_FINAL_VAL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkFREQ_FINAL_VAL->Enable( false );
	
	sbSizer456->Add( chkFREQ_FINAL_VAL, 0, wxALL, 0 );
	
	m_staticText9921 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Cap. bank value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9921->Wrap( -1 );
	sbSizer456->Add( m_staticText9921, 0, wxALL, 0 );
	
	cmbFREQ_FINAL = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	cmbFREQ_FINAL->Enable( false );
	
	sbSizer456->Add( cmbFREQ_FINAL, 0, wxALL, 0 );
	
	chkVCO_SEL_FORCE = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("VCO_SEL_FORCE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer456->Add( chkVCO_SEL_FORCE, 0, wxALL, 0 );
	
	m_staticText9922 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO Core Initial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9922->Wrap( -1 );
	sbSizer456->Add( m_staticText9922, 0, wxALL, 0 );
	
	cmbVCO_SEL_INIT = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 3, 2 );
	sbSizer456->Add( cmbVCO_SEL_INIT, 0, wxALL, 0 );
	
	m_staticText99221 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Cap. bank search start bit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99221->Wrap( -1 );
	sbSizer456->Add( m_staticText99221, 0, wxALL, 0 );
	
	cmbFREQ_INIT_POS = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 7, 7 );
	sbSizer456->Add( cmbFREQ_INIT_POS, 0, wxALL, 0 );
	
	m_staticText992211 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Cap. bank initial value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText992211->Wrap( -1 );
	sbSizer456->Add( m_staticText992211, 0, wxALL, 0 );
	
	cmbFREQ_INIT = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	sbSizer456->Add( cmbFREQ_INIT, 0, wxALL, 0 );
	
	m_staticText9922111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO settling time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9922111->Wrap( -1 );
	sbSizer456->Add( m_staticText9922111, 0, wxALL, 0 );
	
	cmbFREQ_SETTLING_N = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	sbSizer456->Add( cmbFREQ_SETTLING_N, 0, wxALL, 0 );
	
	m_staticText99221111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("VCO intial settling time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99221111->Wrap( -1 );
	sbSizer456->Add( m_staticText99221111, 0, wxALL, 0 );
	
	cmbVTUNE_WAIT_N = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 64 );
	sbSizer456->Add( cmbVTUNE_WAIT_N, 0, wxALL, 0 );
	
	m_staticText992211111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Max. cap. bank in VCO sel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText992211111->Wrap( -1 );
	sbSizer456->Add( m_staticText992211111, 0, wxALL, 0 );
	
	cmbVCO_SEL_FREQ_MAX = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 250 );
	sbSizer456->Add( cmbVCO_SEL_FREQ_MAX, 0, wxALL, 0 );
	
	m_staticText9922111111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Min. cap. bank in VCO sel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9922111111->Wrap( -1 );
	sbSizer456->Add( m_staticText9922111111, 0, wxALL, 0 );
	
	cmbVCO_SEL_FREQ_MIN = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 5 );
	sbSizer456->Add( cmbVCO_SEL_FREQ_MIN, 0, wxALL, 0 );
	
	
	fgSizer126->Add( sbSizer456, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer643;
	fgSizer643 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer643->SetFlexibleDirection( wxBOTH );
	fgSizer643->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer369;
	fgSizer369 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer369->SetFlexibleDirection( wxBOTH );
	fgSizer369->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3941;
	sbSizer3941 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("PLL Profile Select") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer118;
	sbSizer118 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Simple") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer152;
	fgSizer152 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer152->SetFlexibleDirection( wxBOTH );
	fgSizer152->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkSelectProfile = new wxCheckBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Select Profile"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer152->Add( chkSelectProfile, 0, wxALL, 3 );
	
	chkPLL_CFG_INT_SEL = new wxComboBox( ID_PANEL_PLLCONFIG, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	chkPLL_CFG_INT_SEL->Append( wxT("0") );
	chkPLL_CFG_INT_SEL->Append( wxT("1") );
	chkPLL_CFG_INT_SEL->Append( wxT("2") );
	chkPLL_CFG_INT_SEL->Append( wxT("3") );
	chkPLL_CFG_INT_SEL->Append( wxT("4") );
	chkPLL_CFG_INT_SEL->Append( wxT("5") );
	chkPLL_CFG_INT_SEL->Append( wxT("6") );
	chkPLL_CFG_INT_SEL->Append( wxT("7") );
	chkPLL_CFG_INT_SEL->SetSelection( 0 );
	chkPLL_CFG_INT_SEL->Enable( false );
	
	fgSizer152->Add( chkPLL_CFG_INT_SEL, 0, wxALL, 0 );
	
	
	sbSizer118->Add( fgSizer152, 1, wxEXPAND, 5 );
	
	
	sbSizer3941->Add( sbSizer118, 0, wxEXPAND, 5 );
	
	ID_NOTEBOOK_MUX_CONTROL_PLL = new wxNotebook( ID_PANEL_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PLL, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8822;
	fgSizer8822 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8822->SetFlexibleDirection( wxBOTH );
	fgSizer8822->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer1602;
	fgSizer1602 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer1602->SetFlexibleDirection( wxBOTH );
	fgSizer1602->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1682;
	sbSizer1682 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1592;
	fgSizer1592 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1592->SetFlexibleDirection( wxBOTH );
	fgSizer1592->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkPLL_CFG_SEL0_INTERNAL = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPLL_CFG_SEL0_INTERNAL->SetValue(true); 
	fgSizer1592->Add( chkPLL_CFG_SEL0_INTERNAL, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_INVERT = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1592->Add( chkPLL_CFG_SEL0_INVERT, 0, wxALL, 0 );
	
	
	sbSizer1682->Add( fgSizer1592, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer1682, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11522;
	sbSizer11522 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8532;
	fgSizer8532 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer8532->SetFlexibleDirection( wxBOTH );
	fgSizer8532->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText26510 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26510->Wrap( -1 );
	fgSizer8532->Add( m_staticText26510, 0, wxALL, 5 );
	
	m_staticText26512 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26512->Wrap( -1 );
	fgSizer8532->Add( m_staticText26512, 0, wxALL, 5 );
	
	m_staticText26522 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26522->Wrap( -1 );
	fgSizer8532->Add( m_staticText26522, 0, wxALL, 5 );
	
	m_staticText26532 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26532->Wrap( -1 );
	fgSizer8532->Add( m_staticText26532, 0, wxALL, 5 );
	
	m_staticText26542 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26542->Wrap( -1 );
	fgSizer8532->Add( m_staticText26542, 0, wxALL, 5 );
	
	m_staticText26552 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26552->Wrap( -1 );
	fgSizer8532->Add( m_staticText26552, 0, wxALL, 5 );
	
	m_staticText26562 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26562->Wrap( -1 );
	fgSizer8532->Add( m_staticText26562, 0, wxALL, 5 );
	
	m_staticText26572 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26572->Wrap( -1 );
	fgSizer8532->Add( m_staticText26572, 0, wxALL, 5 );
	
	m_staticText26582 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26582->Wrap( -1 );
	fgSizer8532->Add( m_staticText26582, 0, wxALL, 5 );
	
	chkPLL_CFG_SEL0_MASK0 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK0, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK1 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK1, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK2 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK2, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK3 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK3, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK4 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK4, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK5 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK5, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK6 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK6, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK7 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK7, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL0_MASK8 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, ID_PLL_CFG_SEL0_MASK8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8532->Add( chkPLL_CFG_SEL0_MASK8, 0, wxALL, 0 );
	
	
	sbSizer11522->Add( fgSizer8532, 1, wxEXPAND, 5 );
	
	
	fgSizer1602->Add( sbSizer11522, 1, wxEXPAND, 5 );
	
	
	fgSizer8822->Add( fgSizer1602, 1, wxEXPAND, 5 );
	
	
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0->SetSizer( fgSizer8822 );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0->Layout();
	fgSizer8822->Fit( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0 );
	ID_NOTEBOOK_MUX_CONTROL_PLL->AddPage( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0, wxT("Bit 0"), true );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PLL, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer88221;
	fgSizer88221 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer88221->SetFlexibleDirection( wxBOTH );
	fgSizer88221->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer16021;
	fgSizer16021 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer16021->SetFlexibleDirection( wxBOTH );
	fgSizer16021->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer16821;
	sbSizer16821 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15921;
	fgSizer15921 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer15921->SetFlexibleDirection( wxBOTH );
	fgSizer15921->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkPLL_CFG_SEL1_INTERNAL = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_CHx_PA_ILIN2X, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPLL_CFG_SEL1_INTERNAL->SetValue(true); 
	fgSizer15921->Add( chkPLL_CFG_SEL1_INTERNAL, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_INVERT = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_CHx_PA_ILIN2X, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer15921->Add( chkPLL_CFG_SEL1_INVERT, 0, wxALL, 0 );
	
	
	sbSizer16821->Add( fgSizer15921, 1, wxEXPAND, 5 );
	
	
	fgSizer16021->Add( sbSizer16821, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer115221;
	sbSizer115221 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer85321;
	fgSizer85321 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer85321->SetFlexibleDirection( wxBOTH );
	fgSizer85321->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText265101 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265101->Wrap( -1 );
	fgSizer85321->Add( m_staticText265101, 0, wxALL, 5 );
	
	m_staticText265121 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265121->Wrap( -1 );
	fgSizer85321->Add( m_staticText265121, 0, wxALL, 5 );
	
	m_staticText265221 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265221->Wrap( -1 );
	fgSizer85321->Add( m_staticText265221, 0, wxALL, 5 );
	
	m_staticText265321 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265321->Wrap( -1 );
	fgSizer85321->Add( m_staticText265321, 0, wxALL, 5 );
	
	m_staticText265421 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265421->Wrap( -1 );
	fgSizer85321->Add( m_staticText265421, 0, wxALL, 5 );
	
	m_staticText265521 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265521->Wrap( -1 );
	fgSizer85321->Add( m_staticText265521, 0, wxALL, 5 );
	
	m_staticText265621 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265621->Wrap( -1 );
	fgSizer85321->Add( m_staticText265621, 0, wxALL, 5 );
	
	m_staticText265721 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265721->Wrap( -1 );
	fgSizer85321->Add( m_staticText265721, 0, wxALL, 5 );
	
	m_staticText265821 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265821->Wrap( -1 );
	fgSizer85321->Add( m_staticText265821, 0, wxALL, 5 );
	
	chkPLL_CFG_SEL1_MASK0 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK0, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK1 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK1, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK2 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK2, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK3 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK3, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK4 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK4, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK5 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK5, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK6 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK6, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK7 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK7, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL1_MASK8 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, ID_PLL_CFG_SEL1_MASK8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer85321->Add( chkPLL_CFG_SEL1_MASK8, 0, wxALL, 0 );
	
	
	sbSizer115221->Add( fgSizer85321, 1, wxEXPAND, 5 );
	
	
	fgSizer16021->Add( sbSizer115221, 1, wxEXPAND, 5 );
	
	
	fgSizer88221->Add( fgSizer16021, 1, wxEXPAND, 5 );
	
	
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1->SetSizer( fgSizer88221 );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1->Layout();
	fgSizer88221->Fit( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1 );
	ID_NOTEBOOK_MUX_CONTROL_PLL->AddPage( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1, wxT("Bit 1"), false );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2 = new wxPanel( ID_NOTEBOOK_MUX_CONTROL_PLL, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer882211;
	fgSizer882211 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer882211->SetFlexibleDirection( wxBOTH );
	fgSizer882211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer160211;
	fgSizer160211 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer160211->SetFlexibleDirection( wxBOTH );
	fgSizer160211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer168211;
	sbSizer168211 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer159211;
	fgSizer159211 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer159211->SetFlexibleDirection( wxBOTH );
	fgSizer159211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkPLL_CFG_SEL2_INTERNAL = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_INTERNAL, wxT("INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPLL_CFG_SEL2_INTERNAL->SetValue(true); 
	fgSizer159211->Add( chkPLL_CFG_SEL2_INTERNAL, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_INVERT = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_INVERT, wxT("INVERT"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer159211->Add( chkPLL_CFG_SEL2_INVERT, 0, wxALL, 0 );
	
	
	sbSizer168211->Add( fgSizer159211, 1, wxEXPAND, 5 );
	
	
	fgSizer160211->Add( sbSizer168211, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1152211;
	sbSizer1152211 = new wxStaticBoxSizer( new wxStaticBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("GPIO Mask") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer853211;
	fgSizer853211 = new wxFlexGridSizer( 2, 9, 0, 0 );
	fgSizer853211->SetFlexibleDirection( wxBOTH );
	fgSizer853211->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2651011 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2651011->Wrap( -1 );
	fgSizer853211->Add( m_staticText2651011, 0, wxALL, 5 );
	
	m_staticText2651211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2651211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2651211, 0, wxALL, 5 );
	
	m_staticText2652211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2652211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2652211, 0, wxALL, 5 );
	
	m_staticText2653211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2653211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2653211, 0, wxALL, 5 );
	
	m_staticText2654211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2654211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2654211, 0, wxALL, 5 );
	
	m_staticText2655211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2655211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2655211, 0, wxALL, 5 );
	
	m_staticText2656211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2656211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2656211, 0, wxALL, 5 );
	
	m_staticText2657211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2657211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2657211, 0, wxALL, 5 );
	
	m_staticText2658211 = new wxStaticText( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2658211->Wrap( -1 );
	fgSizer853211->Add( m_staticText2658211, 0, wxALL, 5 );
	
	chkPLL_CFG_SEL2_MASK0 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK0, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK1 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK1, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK2 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK2, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK3 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK3, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK4 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK4, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK5 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK5, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK6 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK6, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK7 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK7, 0, wxALL, 0 );
	
	chkPLL_CFG_SEL2_MASK8 = new wxCheckBox( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, ID_PLL_CFG_SEL2_MASK8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer853211->Add( chkPLL_CFG_SEL2_MASK8, 0, wxALL, 0 );
	
	
	sbSizer1152211->Add( fgSizer853211, 1, wxEXPAND, 5 );
	
	
	fgSizer160211->Add( sbSizer1152211, 1, wxEXPAND, 5 );
	
	
	fgSizer882211->Add( fgSizer160211, 1, wxEXPAND, 5 );
	
	
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2->SetSizer( fgSizer882211 );
	ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2->Layout();
	fgSizer882211->Fit( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2 );
	ID_NOTEBOOK_MUX_CONTROL_PLL->AddPage( ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2, wxT("Bit 2"), false );
	
	sbSizer3941->Add( ID_NOTEBOOK_MUX_CONTROL_PLL, 1, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3041;
	sbSizer3041 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Internal") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3701;
	fgSizer3701 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer3701->SetFlexibleDirection( wxBOTH );
	fgSizer3701->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkPLL_CFG_INT_SEL0 = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_PLL_CFG_INT_SEL0, wxT("Bit 0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkPLL_CFG_INT_SEL0, 0, wxALL, 3 );
	
	chkPLL_CFG_INT_SEL1 = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_PLL_CFG_INT_SEL1, wxT("Bit 1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkPLL_CFG_INT_SEL1, 0, wxALL, 3 );
	
	chkPLL_CFG_INT_SEL2 = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_PLL_CFG_INT_SEL2, wxT("Bit 2"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3701->Add( chkPLL_CFG_INT_SEL2, 0, wxALL, 3 );
	
	
	sbSizer3041->Add( fgSizer3701, 1, wxEXPAND, 5 );
	
	
	sbSizer3941->Add( sbSizer3041, 0, wxEXPAND, 5 );
	
	
	fgSizer369->Add( sbSizer3941, 1, wxEXPAND, 5 );
	
	
	fgSizer643->Add( fgSizer369, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4571;
	sbSizer4571 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Configuration") ), wxVERTICAL );
	
	wxString rgrPLL_RSTNChoices[] = { wxT("On"), wxT("Off") };
	int rgrPLL_RSTNNChoices = sizeof( rgrPLL_RSTNChoices ) / sizeof( wxString );
	rgrPLL_RSTN = new wxRadioBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("PLL Reset"), wxDefaultPosition, wxDefaultSize, rgrPLL_RSTNNChoices, rgrPLL_RSTNChoices, 2, wxRA_SPECIFY_COLS );
	rgrPLL_RSTN->SetSelection( 0 );
	sbSizer4571->Add( rgrPLL_RSTN, 0, wxEXPAND, 0 );
	
	m_staticText992111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Automatic freq. cal. res."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText992111->Wrap( -1 );
	sbSizer4571->Add( m_staticText992111, 0, wxALL, 0 );
	
	cmbCTUNE_RES = new wxComboBox( ID_PANEL_PLLCONFIG, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbCTUNE_RES->SetSelection( 0 );
	sbSizer4571->Add( cmbCTUNE_RES, 0, wxALL, 0 );
	
	chkPLL_CALIBRATION_MODE = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_CALIBRATION_MODE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4571->Add( chkPLL_CALIBRATION_MODE, 0, wxALL, 0 );
	
	chkPLL_CALIBRATION_EN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_CALIBRATION_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4571->Add( chkPLL_CALIBRATION_EN, 0, wxALL, 0 );
	
	chkPLL_FLOCK_INTERNAL = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_FLOCK_INTERNAL"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4571->Add( chkPLL_FLOCK_INTERNAL, 0, wxALL, 0 );
	
	chkPLL_FLOCK_INTVAL = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_CHx_PA_ILIN2X, wxT("PLL_FLOCK_INTVAL"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4571->Add( chkPLL_FLOCK_INTVAL, 0, wxALL, 0 );
	
	
	fgSizer643->Add( sbSizer4571, 1, wxEXPAND, 5 );
	
	
	fgSizer126->Add( fgSizer643, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer647;
	fgSizer647 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer647->SetFlexibleDirection( wxBOTH );
	fgSizer647->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer506;
	sbSizer506 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("LO Distribution Config.") ), wxVERTICAL );
	
	chkSEL_BIAS_CORE = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_PLL_LOCK, wxT("SEL_BIAS_CORE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer506->Add( chkSEL_BIAS_CORE, 0, wxALL, 0 );
	
	m_staticText1191 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Core bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1191->Wrap( -1 );
	sbSizer506->Add( m_staticText1191, 0, wxALL, 0 );
	
	cmbPLL_LODIST_ICT_CORE = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_PLL_LODIST_ICT_CORE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer506->Add( cmbPLL_LODIST_ICT_CORE, 0, wxALL, 0 );
	
	m_staticText11911 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Buffer bias current control"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11911->Wrap( -1 );
	sbSizer506->Add( m_staticText11911, 0, wxALL, 0 );
	
	cmbPLL_LODIST_ICT_BUF = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_PLL_LODIST_ICT_BUF, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	sbSizer506->Add( cmbPLL_LODIST_ICT_BUF, 0, wxALL, 0 );
	
	wxStaticBoxSizer* sbSizer507;
	sbSizer507 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Drive-strength") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer648;
	fgSizer648 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer648->SetFlexibleDirection( wxBOTH );
	fgSizer648->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString choPLL_ICT_OUT0Choices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3") };
	int choPLL_ICT_OUT0NChoices = sizeof( choPLL_ICT_OUT0Choices ) / sizeof( wxString );
	choPLL_ICT_OUT0 = new wxChoice( ID_PANEL_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, choPLL_ICT_OUT0NChoices, choPLL_ICT_OUT0Choices, 0 );
	choPLL_ICT_OUT0->SetSelection( 0 );
	fgSizer648->Add( choPLL_ICT_OUT0, 0, wxALL, 0 );
	
	m_staticText1195 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Channel A"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1195->Wrap( -1 );
	fgSizer648->Add( m_staticText1195, 0, wxALL, 4 );
	
	wxString choPLL_ICT_OUT1Choices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3") };
	int choPLL_ICT_OUT1NChoices = sizeof( choPLL_ICT_OUT1Choices ) / sizeof( wxString );
	choPLL_ICT_OUT1 = new wxChoice( ID_PANEL_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, choPLL_ICT_OUT1NChoices, choPLL_ICT_OUT1Choices, 0 );
	choPLL_ICT_OUT1->SetSelection( 0 );
	fgSizer648->Add( choPLL_ICT_OUT1, 0, wxALL, 0 );
	
	m_staticText11951 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Channel B"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11951->Wrap( -1 );
	fgSizer648->Add( m_staticText11951, 0, wxALL, 4 );
	
	wxString choPLL_ICT_OUT2Choices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3") };
	int choPLL_ICT_OUT2NChoices = sizeof( choPLL_ICT_OUT2Choices ) / sizeof( wxString );
	choPLL_ICT_OUT2 = new wxChoice( ID_PANEL_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, choPLL_ICT_OUT2NChoices, choPLL_ICT_OUT2Choices, 0 );
	choPLL_ICT_OUT2->SetSelection( 0 );
	fgSizer648->Add( choPLL_ICT_OUT2, 0, wxALL, 0 );
	
	m_staticText119511 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Channel C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText119511->Wrap( -1 );
	fgSizer648->Add( m_staticText119511, 0, wxALL, 4 );
	
	wxString choPLL_ICT_OUT3Choices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3") };
	int choPLL_ICT_OUT3NChoices = sizeof( choPLL_ICT_OUT3Choices ) / sizeof( wxString );
	choPLL_ICT_OUT3 = new wxChoice( ID_PANEL_PLLCONFIG, wxID_ANY, wxDefaultPosition, wxDefaultSize, choPLL_ICT_OUT3NChoices, choPLL_ICT_OUT3Choices, 0 );
	choPLL_ICT_OUT3->SetSelection( 0 );
	fgSizer648->Add( choPLL_ICT_OUT3, 0, wxALL, 0 );
	
	m_staticText1195111 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Channel D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1195111->Wrap( -1 );
	fgSizer648->Add( m_staticText1195111, 0, wxALL, 4 );
	
	
	sbSizer507->Add( fgSizer648, 1, wxEXPAND, 5 );
	
	
	sbSizer506->Add( sbSizer507, 1, wxEXPAND, 5 );
	
	
	fgSizer647->Add( sbSizer506, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer508;
	sbSizer508 = new wxStaticBoxSizer( new wxStaticBox( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("BIST") ), wxVERTICAL );
	
	m_staticText1205 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Signature"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1205->Wrap( -1 );
	sbSizer508->Add( m_staticText1205, 0, wxALL, 0 );
	
	cmbBSIGL = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_PLL_LODIST_ICT_BUF, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 0 );
	cmbBSIGL->Enable( false );
	
	sbSizer508->Add( cmbBSIGL, 0, wxALL, 0 );
	
	chkBSTATE = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_BSTATE, wxT("BSTATE"), wxDefaultPosition, wxDefaultSize, 0 );
	chkBSTATE->Enable( false );
	
	sbSizer508->Add( chkBSTATE, 0, wxALL, 0 );
	
	chkEN_SDM_TSTO = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_EN_SDM_TSTO, wxT("EN_SDM_TSTO"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer508->Add( chkEN_SDM_TSTO, 0, wxALL, 0 );
	
	chkBEN = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_EN_SDM_TSTO, wxT("BEN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer508->Add( chkBEN, 0, wxALL, 0 );
	
	chkBSTART = new wxCheckBox( ID_PANEL_PLLCONFIG, ID_EN_SDM_TSTO, wxT("BSTART"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer508->Add( chkBSTART, 0, wxALL, 0 );
	
	m_staticText1206 = new wxStaticText( ID_PANEL_PLLCONFIG, wxID_ANY, wxT("Output"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1206->Wrap( -1 );
	sbSizer508->Add( m_staticText1206, 0, wxALL, 0 );
	
	cmbBSIGH = new wxSpinCtrl( ID_PANEL_PLLCONFIG, ID_PLL_LODIST_ICT_BUF, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	cmbBSIGH->Enable( false );
	
	sbSizer508->Add( cmbBSIGH, 0, wxALL, 0 );
	
	
	fgSizer647->Add( sbSizer508, 1, wxEXPAND, 5 );
	
	
	fgSizer126->Add( fgSizer647, 1, wxEXPAND, 5 );
	
	
	fgSizer69->Add( fgSizer126, 1, wxEXPAND, 5 );
	
	
	ID_PANEL_PLLCONFIG->SetSizer( fgSizer69 );
	ID_PANEL_PLLCONFIG->Layout();
	fgSizer69->Fit( ID_PANEL_PLLCONFIG );
	ID_NOTEBOOK_PLLCONFIG->AddPage( ID_PANEL_PLLCONFIG, wxT("PLL Configuration"), false );
	
	fgSizer68->Add( ID_NOTEBOOK_PLLCONFIG, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	chkEN_VCOBIAS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBYP_VCOREG->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCURLIM_VCOREG->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_VCOREG->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVDIV_VCOREG->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_SLFBEN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_BYPEN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_EN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_LOW->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_EQUAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_HIGH->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_STEP_DONE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_START->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_EN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_HIGH->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_LOW->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LOCK->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFCAL_START->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVCO_SEL_FINAL_VAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_FINAL_VAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVCO_SEL_FORCE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSelectProfile->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::OnSelectProfileClick ), NULL, this );
	chkPLL_CFG_INT_SEL->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_INVERT->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	rgrPLL_RSTN->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbCTUNE_RES->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbCTUNE_RES->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLConfig_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_CALIBRATION_MODE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CALIBRATION_EN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_FLOCK_INTERNAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_FLOCK_INTVAL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSEL_BIAS_CORE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT3->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBSTATE->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkEN_SDM_TSTO->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBEN->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBSTART->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
}

pnlPLLConfig_view::~pnlPLLConfig_view()
{
	// Disconnect Events
	chkEN_VCOBIAS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBYP_VCOREG->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCURLIM_VCOREG->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_VCOREG->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVDIV_VCOREG->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_SLFBEN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_BYPEN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_XBUF_EN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_MAN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_MAN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_LOW->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_EQUAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_HIGH->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_STEP_DONE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_START->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkCTUNE_EN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_HIGH->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_LOW->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LOCK->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFCAL_START->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVCO_SEL_FINAL_VAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FINAL->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkFREQ_FINAL_VAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_FINAL->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkVCO_SEL_FORCE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_INIT->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT_POS->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_INIT->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbFREQ_SETTLING_N->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_WAIT_N->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MAX->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_FREQ_MIN->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSelectProfile->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::OnSelectProfileClick ), NULL, this );
	chkPLL_CFG_INT_SEL->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL0_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL1_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_INVERT->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_SEL2_MASK8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CFG_INT_SEL2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	rgrPLL_RSTN->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbCTUNE_RES->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbCTUNE_RES->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLConfig_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_CALIBRATION_MODE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_CALIBRATION_EN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_FLOCK_INTERNAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkPLL_FLOCK_INTVAL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkSEL_BIAS_CORE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_CORE->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_ICT_BUF->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	choPLL_ICT_OUT3->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGL->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBSTATE->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkEN_SDM_TSTO->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBEN->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	chkBSTART->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	cmbBSIGH->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLConfig_view::ParameterChangeHandler ), NULL, this );
	
}

pnlPLLProfiles_view::pnlPLLProfiles_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 1, 3, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer154;
	fgSizer154 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer154->SetFlexibleDirection( wxBOTH );
	fgSizer154->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rgrPLLProfileChoices[] = { wxT("0"), wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5"), wxT("6"), wxT("7") };
	int rgrPLLProfileNChoices = sizeof( rgrPLLProfileChoices ) / sizeof( wxString );
	rgrPLLProfile = new wxRadioBox( this, wxID_ANY, wxT("Profile"), wxDefaultPosition, wxDefaultSize, rgrPLLProfileNChoices, rgrPLLProfileChoices, 8, wxRA_SPECIFY_ROWS );
	rgrPLLProfile->SetSelection( 0 );
	fgSizer154->Add( rgrPLLProfile, 0, wxALL|wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer505;
	sbSizer505 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5651;
	fgSizer5651 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer5651->SetFlexibleDirection( wxBOTH );
	fgSizer5651->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText272 = new wxStaticText( this, wxID_ANY, wxT("Active\nProfile\nStatus:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText272->Wrap( -1 );
	fgSizer5651->Add( m_staticText272, 0, wxBOTTOM, 5 );
	
	chkVTUNE_HIGH = new wxCheckBox( this, ID_VTUNE_HIGH, wxT("High"), wxDefaultPosition, wxDefaultSize, 0 );
	chkVTUNE_HIGH->Enable( false );
	
	fgSizer5651->Add( chkVTUNE_HIGH, 0, wxALL, 0 );
	
	chkVTUNE_LOW = new wxCheckBox( this, ID_VTUNE_LOW, wxT("Low"), wxDefaultPosition, wxDefaultSize, 0 );
	chkVTUNE_LOW->Enable( false );
	
	fgSizer5651->Add( chkVTUNE_LOW, 0, wxALL, 0 );
	
	chkPLL_LOCK = new wxCheckBox( this, ID_PLL_LOCK, wxT("Lock"), wxDefaultPosition, wxDefaultSize, 0 );
	chkPLL_LOCK->Enable( false );
	
	fgSizer5651->Add( chkPLL_LOCK, 0, wxALL, 0 );
	
	
	sbSizer505->Add( fgSizer5651, 1, wxEXPAND, 5 );
	
	
	fgSizer154->Add( sbSizer505, 1, wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer115;
	sbSizer115 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("PLL Freq.") ), wxVERTICAL );
	
	sttxtPLLFreq = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtPLLFreq->Wrap( -1 );
	sbSizer115->Add( sttxtPLLFreq, 0, wxALL, 0 );
	
	sttxtPLLFreq1 = new wxStaticText( this, wxID_ANY, wxT("GHz"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtPLLFreq1->Wrap( -1 );
	sbSizer115->Add( sttxtPLLFreq1, 0, wxALIGN_TOP, 0 );
	
	
	fgSizer154->Add( sbSizer115, 1, wxEXPAND, 5 );
	
	
	fgSizer68->Add( fgSizer154, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer697;
	fgSizer697 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer697->SetFlexibleDirection( wxBOTH );
	fgSizer697->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer543;
	sbSizer543 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Profile Configuration") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer698;
	fgSizer698 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer698->SetFlexibleDirection( wxBOTH );
	fgSizer698->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer545;
	sbSizer545 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Enable") ), wxVERTICAL );
	
	chkPLL_LODIST_EN_BIAS_n = new wxCheckBox( this, ID_TEST, wxT("LODIST_EN_BIAS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_LODIST_EN_BIAS_n, 0, wxALL, 0 );
	
	chkPLL_LODIST_EN_DIV2IQ_n = new wxCheckBox( this, ID_TEST, wxT("LODIST_EN_DIV2IQ"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_LODIST_EN_DIV2IQ_n, 0, wxALL, 0 );
	
	chkPLL_EN_VTUNE_COMP_n = new wxCheckBox( this, ID_TEST, wxT("EN_VTUNE_COMP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_VTUNE_COMP_n, 0, wxALL, 0 );
	
	chkPLL_EN_LD_n = new wxCheckBox( this, ID_TEST, wxT("EN_LD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_LD_n, 0, wxALL, 0 );
	
	chkPLL_EN_PFD_n = new wxCheckBox( this, ID_TEST, wxT("EN_PFD"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_PFD_n, 0, wxALL, 0 );
	
	chkPLL_EN_CP_n = new wxCheckBox( this, ID_TEST, wxT("EN_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_CP_n, 0, wxALL, 0 );
	
	chkPLL_EN_CPOFS_n = new wxCheckBox( this, ID_TEST, wxT("EN_CPOFS"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_CPOFS_n, 0, wxALL, 0 );
	
	chkPLL_EN_VCO_n = new wxCheckBox( this, ID_TEST, wxT("EN_VCO"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_VCO_n, 0, wxALL, 0 );
	
	chkPLL_EN_FFDIV_n = new wxCheckBox( this, ID_TEST, wxT("EN_FFDIV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_FFDIV_n, 0, wxALL, 0 );
	
	chkPLL_EN_FB_PDIV2_n = new wxCheckBox( this, ID_TEST, wxT("EN_FB_PDIV2"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_FB_PDIV2_n, 0, wxALL, 0 );
	
	chkPLL_EN_FFCORE_n = new wxCheckBox( this, ID_TEST, wxT("EN_FFCORE"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_FFCORE_n, 0, wxALL, 0 );
	
	chkPLL_EN_FBDIV_n = new wxCheckBox( this, ID_TEST, wxT("EN_FBDIV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_EN_FBDIV_n, 0, wxALL, 0 );
	
	chkPLL_SDM_CLK_EN_n = new wxCheckBox( this, ID_TEST, wxT("SDM_CLK_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer545->Add( chkPLL_SDM_CLK_EN_n, 0, wxALL, 0 );
	
	
	fgSizer698->Add( sbSizer545, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer547;
	sbSizer547 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Charge Pump") ), wxVERTICAL );
	
	chkFLIP_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("FLIP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer547->Add( chkFLIP_n, 0, wxALL, 0 );
	
	m_staticText1328 = new wxStaticText( this, wxID_ANY, wxT("DEL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1328->Wrap( -1 );
	sbSizer547->Add( m_staticText1328, 0, wxALL, 0 );
	
	cmbDEL_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 3, 0 );
	cmbDEL_n->SetMinSize( wxSize( 70,-1 ) );
	
	sbSizer547->Add( cmbDEL_n, 0, wxALL, 0 );
	
	m_staticText13281 = new wxStaticText( this, wxID_ANY, wxT("PULSE [µA]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13281->Wrap( -1 );
	sbSizer547->Add( m_staticText13281, 0, wxALL, 0 );
	
	cmbPULSE_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbPULSE_n->SetSelection( 0 );
	sbSizer547->Add( cmbPULSE_n, 0, wxALL, 0 );
	
	m_staticText132811 = new wxStaticText( this, wxID_ANY, wxT("OFS  [µA]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText132811->Wrap( -1 );
	sbSizer547->Add( m_staticText132811, 0, wxALL, 0 );
	
	cmbOFS_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbOFS_n->SetSelection( 0 );
	sbSizer547->Add( cmbOFS_n, 0, wxALL, 0 );
	
	m_staticText1328111 = new wxStaticText( this, wxID_ANY, wxT("LD_VCT [mV]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1328111->Wrap( -1 );
	sbSizer547->Add( m_staticText1328111, 0, wxALL, 0 );
	
	cmbLD_VCT_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbLD_VCT_n->Append( wxT("600") );
	cmbLD_VCT_n->Append( wxT("700") );
	cmbLD_VCT_n->Append( wxT("800") );
	cmbLD_VCT_n->Append( wxT("900") );
	cmbLD_VCT_n->SetSelection( 1 );
	sbSizer547->Add( cmbLD_VCT_n, 0, wxALL, 0 );
	
	m_staticText13281111 = new wxStaticText( this, wxID_ANY, wxT("ICT_CP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13281111->Wrap( -1 );
	sbSizer547->Add( m_staticText13281111, 0, wxALL, 0 );
	
	cmbICT_CP_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 31, 16 );
	cmbICT_CP_n->SetMinSize( wxSize( 70,-1 ) );
	
	sbSizer547->Add( cmbICT_CP_n, 0, wxALL, 0 );
	
	
	fgSizer698->Add( sbSizer547, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer548;
	sbSizer548 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("VCO") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer701;
	fgSizer701 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer701->SetFlexibleDirection( wxBOTH );
	fgSizer701->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1341 = new wxStaticText( this, wxID_ANY, wxT("VCO_FREQ"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1341->Wrap( -1 );
	fgSizer701->Add( m_staticText1341, 0, wxALL, 0 );
	
	cmbVCO_FREQ_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 128 );
	fgSizer701->Add( cmbVCO_FREQ_n, 0, wxALL, 0 );
	
	chkSPDUP_VCO_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("SPDUP_VCO"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer701->Add( chkSPDUP_VCO_n, 0, wxALL, 0 );
	
	chkVCO_AAC_EN_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("VCO_AAC_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer701->Add( chkVCO_AAC_EN_n, 0, wxALL, 0 );
	
	m_staticText1342 = new wxStaticText( this, wxID_ANY, wxT("VDIV_SWVDD [mV]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1342->Wrap( -1 );
	fgSizer701->Add( m_staticText1342, 0, wxALL, 0 );
	
	cmbVDIV_SWVDD_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbVDIV_SWVDD_n->Append( wxT("600") );
	cmbVDIV_SWVDD_n->Append( wxT("800") );
	cmbVDIV_SWVDD_n->Append( wxT("1000") );
	cmbVDIV_SWVDD_n->Append( wxT("1200") );
	cmbVDIV_SWVDD_n->SetSelection( 2 );
	fgSizer701->Add( cmbVDIV_SWVDD_n, 0, wxALL, 0 );
	
	m_staticText1343 = new wxStaticText( this, wxID_ANY, wxT("VCO_SEL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1343->Wrap( -1 );
	fgSizer701->Add( m_staticText1343, 0, wxALL, 0 );
	
	cmbVCO_SEL_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbVCO_SEL_n->Append( wxT("External") );
	cmbVCO_SEL_n->Append( wxT("Core 1") );
	cmbVCO_SEL_n->Append( wxT("Core 2") );
	cmbVCO_SEL_n->Append( wxT("Core 3") );
	cmbVCO_SEL_n->SetSelection( 3 );
	fgSizer701->Add( cmbVCO_SEL_n, 0, wxALL, 0 );
	
	m_staticText1344 = new wxStaticText( this, wxID_ANY, wxT("VCO_AMP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1344->Wrap( -1 );
	fgSizer701->Add( m_staticText1344, 0, wxALL, 0 );
	
	cmbVCO_AMP_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 127, 1 );
	fgSizer701->Add( cmbVCO_AMP_n, 0, wxALL, 0 );
	
	
	sbSizer548->Add( fgSizer701, 1, wxEXPAND, 5 );
	
	
	fgSizer698->Add( sbSizer548, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer553;
	sbSizer553 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Fast Lock") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer703;
	fgSizer703 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer703->SetFlexibleDirection( wxBOTH );
	fgSizer703->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText13113 = new wxStaticText( this, wxID_ANY, wxT("R3 [kΩ]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13113->Wrap( -1 );
	fgSizer703->Add( m_staticText13113, 0, wxALL, 4 );
	
	cmbFLOCK_R3_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_R3_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_R3_n, 0, wxALL, 0 );
	
	m_staticText131111 = new wxStaticText( this, wxID_ANY, wxT("R2 [kΩ]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131111->Wrap( -1 );
	fgSizer703->Add( m_staticText131111, 0, wxALL, 4 );
	
	cmbFLOCK_R2_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_R2_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_R2_n, 0, wxALL, 0 );
	
	m_staticText1311221 = new wxStaticText( this, wxID_ANY, wxT("C3 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1311221->Wrap( -1 );
	fgSizer703->Add( m_staticText1311221, 0, wxALL, 4 );
	
	cmbFLOCK_C3_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_C3_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_C3_n, 0, wxALL, 0 );
	
	m_staticText131123 = new wxStaticText( this, wxID_ANY, wxT("C2 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131123->Wrap( -1 );
	fgSizer703->Add( m_staticText131123, 0, wxALL, 4 );
	
	cmbFLOCK_C2_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_C2_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_C2_n, 0, wxALL, 0 );
	
	m_staticText1311211 = new wxStaticText( this, wxID_ANY, wxT("C1 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1311211->Wrap( -1 );
	fgSizer703->Add( m_staticText1311211, 0, wxALL, 4 );
	
	cmbFLOCK_C1_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_C1_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_C1_n, 0, wxALL, 0 );
	
	m_staticText132812 = new wxStaticText( this, wxID_ANY, wxT("PULSE [µA]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText132812->Wrap( -1 );
	fgSizer703->Add( m_staticText132812, 0, wxALL, 4 );
	
	cmbFLOCK_PULSE_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_PULSE_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_PULSE_n, 0, wxALL, 0 );
	
	m_staticText1328112 = new wxStaticText( this, wxID_ANY, wxT("OFS  [µA]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1328112->Wrap( -1 );
	fgSizer703->Add( m_staticText1328112, 0, wxALL, 4 );
	
	cmbFLOCK_OFS_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbFLOCK_OFS_n->SetSelection( 0 );
	fgSizer703->Add( cmbFLOCK_OFS_n, 0, wxALL, 0 );
	
	
	sbSizer553->Add( fgSizer703, 1, wxEXPAND, 5 );
	
	chkFLOCK_VCO_SPDUP_n = new wxCheckBox( this, ID_FLOCK_VCO_SPDUP_n, wxT("VCO_SPDUP"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer553->Add( chkFLOCK_VCO_SPDUP_n, 0, wxLEFT, 4 );
	
	wxFlexGridSizer* fgSizer186;
	fgSizer186 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer186->SetFlexibleDirection( wxBOTH );
	fgSizer186->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText134211221 = new wxStaticText( this, wxID_ANY, wxT("FLOCK_N   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134211221->Wrap( -1 );
	fgSizer186->Add( m_staticText134211221, 0, wxALL, 4 );
	
	cmbFLOCK_N_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1023, 400 );
	cmbFLOCK_N_n->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer186->Add( cmbFLOCK_N_n, 0, wxALL, 0 );
	
	sttxtFLockN = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtFLockN->Wrap( -1 );
	fgSizer186->Add( sttxtFLockN, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_staticText1328122 = new wxStaticText( this, wxID_ANY, wxT("[µs]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1328122->Wrap( -1 );
	fgSizer186->Add( m_staticText1328122, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	
	sbSizer553->Add( fgSizer186, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer151;
	fgSizer151 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer151->SetFlexibleDirection( wxBOTH );
	fgSizer151->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer116;
	sbSizer116 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LO Distr. Enable Ch.") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer152;
	fgSizer152 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer152->SetFlexibleDirection( wxBOTH );
	fgSizer152->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	chkFLOCK_LODIST_EN_OUT0_n = new wxCheckBox( this, ID_FLOCK_VCO_SPDUP_n, wxT("A "), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer152->Add( chkFLOCK_LODIST_EN_OUT0_n, 0, wxALL, 0 );
	
	chkFLOCK_LODIST_EN_OUT1_n = new wxCheckBox( this, ID_FLOCK_VCO_SPDUP_n, wxT("B "), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer152->Add( chkFLOCK_LODIST_EN_OUT1_n, 0, wxALL, 0 );
	
	chkFLOCK_LODIST_EN_OUT2_n = new wxCheckBox( this, ID_FLOCK_VCO_SPDUP_n, wxT("C "), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer152->Add( chkFLOCK_LODIST_EN_OUT2_n, 0, wxALL, 0 );
	
	chkFLOCK_LODIST_EN_OUT3_n = new wxCheckBox( this, ID_FLOCK_VCO_SPDUP_n, wxT("D"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer152->Add( chkFLOCK_LODIST_EN_OUT3_n, 0, wxALL, 0 );
	
	
	sbSizer116->Add( fgSizer152, 1, wxEXPAND, 0 );
	
	
	fgSizer151->Add( sbSizer116, 0, wxEXPAND, 0 );
	
	
	sbSizer553->Add( fgSizer151, 0, wxEXPAND, 0 );
	
	
	fgSizer698->Add( sbSizer553, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer546;
	sbSizer546 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LPF Configuration") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer699;
	fgSizer699 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer699->SetFlexibleDirection( wxBOTH );
	fgSizer699->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1311 = new wxStaticText( this, wxID_ANY, wxT("R3 [kΩ]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1311->Wrap( -1 );
	fgSizer699->Add( m_staticText1311, 0, wxALL, 4 );
	
	cmbR3_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbR3_n->SetSelection( 0 );
	fgSizer699->Add( cmbR3_n, 0, wxALL, 0 );
	
	m_staticText13111 = new wxStaticText( this, wxID_ANY, wxT("R2 [kΩ]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13111->Wrap( -1 );
	fgSizer699->Add( m_staticText13111, 0, wxALL, 4 );
	
	cmbR2_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbR2_n->SetSelection( 0 );
	fgSizer699->Add( cmbR2_n, 0, wxALL, 0 );
	
	m_staticText131122 = new wxStaticText( this, wxID_ANY, wxT("C3 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131122->Wrap( -1 );
	fgSizer699->Add( m_staticText131122, 0, wxALL, 4 );
	
	cmbC3_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbC3_n->SetSelection( 0 );
	fgSizer699->Add( cmbC3_n, 0, wxALL, 0 );
	
	m_staticText13112 = new wxStaticText( this, wxID_ANY, wxT("C2 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13112->Wrap( -1 );
	fgSizer699->Add( m_staticText13112, 0, wxALL, 4 );
	
	cmbC2_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbC2_n->SetSelection( 0 );
	fgSizer699->Add( cmbC2_n, 0, wxALL, 0 );
	
	m_staticText131121 = new wxStaticText( this, wxID_ANY, wxT("C1 [pF]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131121->Wrap( -1 );
	fgSizer699->Add( m_staticText131121, 0, wxALL, 4 );
	
	cmbC1_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	cmbC1_n->SetSelection( 0 );
	fgSizer699->Add( cmbC1_n, 0, wxALL, 0 );
	
	
	sbSizer546->Add( fgSizer699, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer700;
	fgSizer700 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer700->SetFlexibleDirection( wxBOTH );
	fgSizer700->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1324 = new wxStaticText( this, wxID_ANY, wxT("VTUNE_VCT [mV]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1324->Wrap( -1 );
	fgSizer700->Add( m_staticText1324, 0, wxALL, 5 );
	
	cmbVTUNE_VCT_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbVTUNE_VCT_n->Append( wxT("300") );
	cmbVTUNE_VCT_n->Append( wxT("600") );
	cmbVTUNE_VCT_n->Append( wxT("750") );
	cmbVTUNE_VCT_n->Append( wxT("900") );
	cmbVTUNE_VCT_n->SetSelection( 1 );
	fgSizer700->Add( cmbVTUNE_VCT_n, 0, wxALL, 0 );
	
	chkLPFSW_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("LPFSW"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer700->Add( chkLPFSW_n, 0, wxLEFT, 4 );
	
	
	sbSizer546->Add( fgSizer700, 1, wxALL|wxEXPAND, 0 );
	
	
	fgSizer698->Add( sbSizer546, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer549;
	sbSizer549 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Feed-forward divider") ), wxVERTICAL );
	
	m_staticText134211 = new wxStaticText( this, wxID_ANY, wxT("FF_MOD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134211->Wrap( -1 );
	sbSizer549->Add( m_staticText134211, 0, wxALL, 0 );
	
	cmbFF_MOD_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbFF_MOD_n->Append( wxT("No division") );
	cmbFF_MOD_n->Append( wxT("Div by 2") );
	cmbFF_MOD_n->Append( wxT("Div by 4") );
	cmbFF_MOD_n->Append( wxT("Div by 8") );
	cmbFF_MOD_n->SetSelection( 0 );
	sbSizer549->Add( cmbFF_MOD_n, 0, wxALL, 0 );
	
	m_staticText1342112 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1342112->Wrap( -1 );
	sbSizer549->Add( m_staticText1342112, 0, wxALL, 0 );
	
	chkEnableFFDIVDebug = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("Enable debug"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer549->Add( chkEnableFFDIVDebug, 0, wxALL, 0 );
	
	wxStaticBoxSizer* sbSizer117;
	sbSizer117 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Debug") ), wxVERTICAL );
	
	chkFFDIV_SEL_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("FFDIV_SEL"), wxDefaultPosition, wxDefaultSize, 0 );
	chkFFDIV_SEL_n->Enable( false );
	
	sbSizer117->Add( chkFFDIV_SEL_n, 0, wxALL, 0 );
	
	m_staticText13421 = new wxStaticText( this, wxID_ANY, wxT("Modulus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13421->Wrap( -1 );
	sbSizer117->Add( m_staticText13421, 0, wxALL, 0 );
	
	cmbFFCORE_MOD_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbFFCORE_MOD_n->Append( wxT("No division") );
	cmbFFCORE_MOD_n->Append( wxT("Div by 2") );
	cmbFFCORE_MOD_n->Append( wxT("Div by 4") );
	cmbFFCORE_MOD_n->Append( wxT("Div by 8") );
	cmbFFCORE_MOD_n->SetSelection( 0 );
	cmbFFCORE_MOD_n->Enable( false );
	
	sbSizer117->Add( cmbFFCORE_MOD_n, 0, wxALL, 0 );
	
	
	sbSizer549->Add( sbSizer117, 1, wxEXPAND, 5 );
	
	
	fgSizer698->Add( sbSizer549, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer551;
	sbSizer551 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Sigma-Delta Modulator") ), wxVERTICAL );
	
	chkINTMOD_EN_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("INTMOD_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer551->Add( chkINTMOD_EN_n, 0, wxALL, 0 );
	
	chkDITHER_EN_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("DITHER_EN"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer551->Add( chkDITHER_EN_n, 0, wxALL, 0 );
	
	chkSEL_SDMCLK_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("SEL_SDMCLK"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer551->Add( chkSEL_SDMCLK_n, 0, wxALL, 0 );
	
	chkREV_SDMCLK_n = new wxCheckBox( this, ID_CHx_PA_ILIN2X, wxT("REV_SDMCLK"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer551->Add( chkREV_SDMCLK_n, 0, wxALL, 0 );
	
	wxFlexGridSizer* fgSizer145;
	fgSizer145 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer145->SetFlexibleDirection( wxBOTH );
	fgSizer145->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1342111 = new wxStaticText( this, wxID_ANY, wxT("INTMOD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1342111->Wrap( -1 );
	fgSizer145->Add( m_staticText1342111, 0, wxALL, 0 );
	
	cmbINTMOD_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1023, 216 );
	cmbINTMOD_n->SetMinSize( wxSize( 80,-1 ) );
	
	fgSizer145->Add( cmbINTMOD_n, 0, wxALL, 0 );
	
	m_staticText13421111 = new wxStaticText( this, wxID_ANY, wxT("FRACMODL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13421111->Wrap( -1 );
	fgSizer145->Add( m_staticText13421111, 0, wxALL, 0 );
	
	cmbFRACMODL_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 22320 );
	cmbFRACMODL_n->SetMinSize( wxSize( 80,-1 ) );
	
	fgSizer145->Add( cmbFRACMODL_n, 0, wxALL, 0 );
	
	m_staticText134211111 = new wxStaticText( this, wxID_ANY, wxT("FRACMODH"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134211111->Wrap( -1 );
	fgSizer145->Add( m_staticText134211111, 0, wxALL, 0 );
	
	cmbFRACMODH_n = new wxSpinCtrl( this, ID_VCO_SEL_FINAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 5 );
	cmbFRACMODH_n->SetMinSize( wxSize( 80,-1 ) );
	
	fgSizer145->Add( cmbFRACMODH_n, 0, wxALL, 0 );
	
	
	sbSizer551->Add( fgSizer145, 1, wxEXPAND|wxTOP, 5 );
	
	
	fgSizer698->Add( sbSizer551, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5521;
	sbSizer5521 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("LO Distribution") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1421;
	fgSizer1421 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer1421->AddGrowableCol( 0 );
	fgSizer1421->SetFlexibleDirection( wxBOTH );
	fgSizer1421->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText13421123 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13421123->Wrap( -1 );
	fgSizer1421->Add( m_staticText13421123, 0, wxALL, 0 );
	
	m_staticText134211231 = new wxStaticText( this, wxID_ANY, wxT("EN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134211231->Wrap( -1 );
	fgSizer1421->Add( m_staticText134211231, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	m_staticText1342112311 = new wxStaticText( this, wxID_ANY, wxT("Div by:\n0 - /2\n1 - /1"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText1342112311->Wrap( -1 );
	fgSizer1421->Add( m_staticText1342112311, 0, wxALL, 5 );
	
	m_staticText1342112312 = new wxStaticText( this, wxID_ANY, wxT("Phase"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1342112312->Wrap( -1 );
	fgSizer1421->Add( m_staticText1342112312, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	m_staticText262 = new wxStaticText( this, wxID_ANY, wxT("f [GHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText262->Wrap( -1 );
	fgSizer1421->Add( m_staticText262, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	m_staticText13421123111 = new wxStaticText( this, wxID_ANY, wxT("Ch. A"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13421123111->Wrap( -1 );
	fgSizer1421->Add( m_staticText13421123111, 0, wxALL, 4 );
	
	chkPLL_LODIST_EN_OUT0_n = new wxCheckBox( this, ID_TEST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_EN_OUT0_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	chkPLL_LODIST_FSP_OUT02_n = new wxCheckBox( this, ID_chkPLL_LODIST_FSP_OUT02_n, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_FSP_OUT02_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	cmbPLL_LODIST_FSP_OUT010_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbPLL_LODIST_FSP_OUT010_n->Append( wxT("0") );
	cmbPLL_LODIST_FSP_OUT010_n->Append( wxT("90") );
	cmbPLL_LODIST_FSP_OUT010_n->Append( wxT("180") );
	cmbPLL_LODIST_FSP_OUT010_n->Append( wxT("270") );
	cmbPLL_LODIST_FSP_OUT010_n->SetSelection( 0 );
	fgSizer1421->Add( cmbPLL_LODIST_FSP_OUT010_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	sttxtLODistrChAFreq = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtLODistrChAFreq->Wrap( -1 );
	fgSizer1421->Add( sttxtLODistrChAFreq, 0, wxALL, 4 );
	
	m_staticText134211231111 = new wxStaticText( this, wxID_ANY, wxT("Ch. B"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134211231111->Wrap( -1 );
	fgSizer1421->Add( m_staticText134211231111, 0, wxALL, 4 );
	
	chkPLL_LODIST_EN_OUT1_n = new wxCheckBox( this, ID_TEST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_EN_OUT1_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	chkPLL_LODIST_FSP_OUT12_n = new wxCheckBox( this, ID_chkPLL_LODIST_FSP_OUT02_n, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_FSP_OUT12_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	cmbPLL_LODIST_FSP_OUT110_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbPLL_LODIST_FSP_OUT110_n->Append( wxT("0") );
	cmbPLL_LODIST_FSP_OUT110_n->Append( wxT("90") );
	cmbPLL_LODIST_FSP_OUT110_n->Append( wxT("180") );
	cmbPLL_LODIST_FSP_OUT110_n->Append( wxT("270") );
	cmbPLL_LODIST_FSP_OUT110_n->SetSelection( 0 );
	fgSizer1421->Add( cmbPLL_LODIST_FSP_OUT110_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	sttxtLODistrChBFreq = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtLODistrChBFreq->Wrap( -1 );
	fgSizer1421->Add( sttxtLODistrChBFreq, 0, wxALL, 4 );
	
	m_staticText1342112311111 = new wxStaticText( this, wxID_ANY, wxT("Ch. C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1342112311111->Wrap( -1 );
	fgSizer1421->Add( m_staticText1342112311111, 0, wxALL, 4 );
	
	chkPLL_LODIST_EN_OUT2_n = new wxCheckBox( this, ID_TEST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_EN_OUT2_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	chkPLL_LODIST_FSP_OUT22_n = new wxCheckBox( this, ID_chkPLL_LODIST_FSP_OUT02_n, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_FSP_OUT22_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	cmbPLL_LODIST_FSP_OUT210_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbPLL_LODIST_FSP_OUT210_n->Append( wxT("0") );
	cmbPLL_LODIST_FSP_OUT210_n->Append( wxT("90") );
	cmbPLL_LODIST_FSP_OUT210_n->Append( wxT("180") );
	cmbPLL_LODIST_FSP_OUT210_n->Append( wxT("270") );
	cmbPLL_LODIST_FSP_OUT210_n->SetSelection( 0 );
	fgSizer1421->Add( cmbPLL_LODIST_FSP_OUT210_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	sttxtLODistrChCFreq = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtLODistrChCFreq->Wrap( -1 );
	fgSizer1421->Add( sttxtLODistrChCFreq, 0, wxALL, 4 );
	
	m_staticText13421123111111 = new wxStaticText( this, wxID_ANY, wxT("Ch. D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13421123111111->Wrap( -1 );
	fgSizer1421->Add( m_staticText13421123111111, 0, wxALL, 4 );
	
	chkPLL_LODIST_EN_OUT3_n = new wxCheckBox( this, ID_TEST, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_EN_OUT3_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	chkPLL_LODIST_FSP_OUT32_n = new wxCheckBox( this, ID_chkPLL_LODIST_FSP_OUT02_n, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1421->Add( chkPLL_LODIST_FSP_OUT32_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 4 );
	
	cmbPLL_LODIST_FSP_OUT310_n = new wxComboBox( this, ID_RDIV_LOBUFA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cmbPLL_LODIST_FSP_OUT310_n->Append( wxT("0") );
	cmbPLL_LODIST_FSP_OUT310_n->Append( wxT("90") );
	cmbPLL_LODIST_FSP_OUT310_n->Append( wxT("180") );
	cmbPLL_LODIST_FSP_OUT310_n->Append( wxT("270") );
	cmbPLL_LODIST_FSP_OUT310_n->SetSelection( 0 );
	fgSizer1421->Add( cmbPLL_LODIST_FSP_OUT310_n, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	sttxtLODistrChDFreq = new wxStaticText( this, wxID_ANY, wxT("0.0000"), wxDefaultPosition, wxDefaultSize, 0 );
	sttxtLODistrChDFreq->Wrap( -1 );
	fgSizer1421->Add( sttxtLODistrChDFreq, 0, wxALL, 4 );
	
	
	sbSizer5521->Add( fgSizer1421, 1, wxEXPAND, 5 );
	
	
	fgSizer698->Add( sbSizer5521, 1, wxEXPAND, 5 );
	
	
	sbSizer543->Add( fgSizer698, 1, wxEXPAND, 0 );
	
	wxFlexGridSizer* fgSizer147;
	fgSizer147 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer147->SetFlexibleDirection( wxBOTH );
	fgSizer147->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	sbSizer543->Add( fgSizer147, 0, wxEXPAND, 5 );
	
	
	fgSizer697->Add( sbSizer543, 1, wxEXPAND, 5 );
	
	
	fgSizer68->Add( fgSizer697, 0, wxEXPAND, 0 );
	
	wxFlexGridSizer* fgSizer185;
	fgSizer185 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer185->SetFlexibleDirection( wxBOTH );
	fgSizer185->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1151;
	sbSizer1151 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Tuning") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1131;
	sbSizer1131 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Ref. Clock [MHz]") ), wxVERTICAL );
	
	txtRefClock = new wxTextCtrl( this, wxID_ANY, wxT("40.00"), wxDefaultPosition, wxDefaultSize, 0 );
	txtRefClock->SetToolTip( wxT("Reference clock frequency [MHz]") );
	txtRefClock->SetMinSize( wxSize( 90,-1 ) );
	
	sbSizer1131->Add( txtRefClock, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizer1151->Add( sbSizer1131, 0, wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer113;
	sbSizer113 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Simple Tune") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer148;
	fgSizer148 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer148->SetFlexibleDirection( wxBOTH );
	fgSizer148->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText273 = new wxStaticText( this, wxID_ANY, wxT("VCO Freq. [GHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText273->Wrap( -1 );
	fgSizer148->Add( m_staticText273, 0, wxLEFT|wxTOP, 5 );
	
	txtVCOFrequency = new wxTextCtrl( this, wxID_ANY, wxT("1.2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtVCOFrequency->SetToolTip( wxT("VCO frequency [GHz]") );
	txtVCOFrequency->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer148->Add( txtVCOFrequency, 0, wxBOTTOM|wxLEFT, 5 );
	
	btnTune = new wxButton( this, wxID_ANY, wxT("Simple Tune"), wxDefaultPosition, wxDefaultSize, 0 );
	btnTune->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer148->Add( btnTune, 0, wxALL, 5 );
	
	
	sbSizer113->Add( fgSizer148, 0, wxEXPAND, 5 );
	
	
	sbSizer1151->Add( sbSizer113, 0, wxEXPAND, 0 );
	
	wxStaticBoxSizer* sbSizer1132;
	sbSizer1132 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Smart Tune") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1481;
	fgSizer1481 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer1481->SetFlexibleDirection( wxBOTH );
	fgSizer1481->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2731 = new wxStaticText( this, wxID_ANY, wxT("LO Freq. [GHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2731->Wrap( -1 );
	fgSizer1481->Add( m_staticText2731, 0, wxLEFT|wxTOP, 5 );
	
	txtSmartTunePLLFrequency = new wxTextCtrl( this, wxID_ANY, wxT("4.5"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSmartTunePLLFrequency->SetToolTip( wxT("LO frequency [GHz]") );
	txtSmartTunePLLFrequency->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer1481->Add( txtSmartTunePLLFrequency, 0, wxBOTTOM|wxLEFT, 5 );
	
	chkSmartTuneGenIQ = new wxCheckBox( this, ID_PLL_LOCK, wxT("Generate IQ"), wxDefaultPosition, wxDefaultSize, 0 );
	chkSmartTuneGenIQ->SetToolTip( wxT("Generate quadrature in LO distribution") );
	
	fgSizer1481->Add( chkSmartTuneGenIQ, 0, wxALL, 5 );
	
	m_staticText27311 = new wxStaticText( this, wxID_ANY, wxT("Loop BW [kHz]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27311->Wrap( -1 );
	fgSizer1481->Add( m_staticText27311, 0, wxLEFT|wxTOP, 5 );
	
	txtSmartTuneLoopBW = new wxTextCtrl( this, wxID_ANY, wxT("300"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSmartTuneLoopBW->SetToolTip( wxT("PLL loop bandwidth") );
	txtSmartTuneLoopBW->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer1481->Add( txtSmartTuneLoopBW, 0, wxBOTTOM|wxLEFT, 5 );
	
	m_staticText273111 = new wxStaticText( this, wxID_ANY, wxT("Phase Margin [°]"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText273111->Wrap( -1 );
	fgSizer1481->Add( m_staticText273111, 0, wxLEFT|wxTOP, 5 );
	
	txtSmartTunePhaseMargin = new wxTextCtrl( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSmartTunePhaseMargin->SetToolTip( wxT("PLL phase margin") );
	txtSmartTunePhaseMargin->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer1481->Add( txtSmartTunePhaseMargin, 0, wxBOTTOM|wxLEFT, 5 );
	
	m_staticText2731111 = new wxStaticText( this, wxID_ANY, wxT("BWEF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2731111->Wrap( -1 );
	fgSizer1481->Add( m_staticText2731111, 0, wxLEFT|wxTOP, 5 );
	
	txtSmartTuneBWEF = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	txtSmartTuneBWEF->SetToolTip( wxT("Bandwidth extension factor in fast lock mode") );
	txtSmartTuneBWEF->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer1481->Add( txtSmartTuneBWEF, 0, wxBOTTOM|wxLEFT, 5 );
	
	btnSmartTune = new wxButton( this, wxID_ANY, wxT("Smart Tune"), wxDefaultPosition, wxDefaultSize, 0 );
	btnSmartTune->SetMinSize( wxSize( 90,-1 ) );
	
	fgSizer1481->Add( btnSmartTune, 0, wxALL, 5 );
	
	
	sbSizer1132->Add( fgSizer1481, 0, wxEXPAND, 5 );
	
	
	sbSizer1151->Add( sbSizer1132, 0, wxEXPAND, 5 );
	
	
	fgSizer185->Add( sbSizer1151, 1, wxEXPAND, 5 );
	
	
	fgSizer68->Add( fgSizer185, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer68 );
	this->Layout();
	fgSizer68->Fit( this );
	
	// Connect Events
	rgrPLLProfile->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::OnSwitchPLLProfile ), NULL, this );
	chkVTUNE_HIGH->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_LOW->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LOCK->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	sttxtPLLFreq->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnupdateUI_sttxtPLLFreq ), NULL, this );
	sttxtPLLFreq1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnupdateUI_sttxtPLLFreq ), NULL, this );
	chkPLL_LODIST_EN_BIAS_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_EN_DIV2IQ_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_VTUNE_COMP_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_LD_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_PFD_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_CP_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_CPOFS_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_VCO_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FFDIV_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FB_PDIV2_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FFCORE_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FBDIV_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_SDM_CLK_EN_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLIP_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPULSE_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPULSE_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbOFS_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbOFS_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbLD_VCT_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_VCO_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkVCO_AAC_EN_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVDIV_SWVDD_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_R3_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_R2_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C3_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C2_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C1_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_PULSE_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_PULSE_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbFLOCK_OFS_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_OFS_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	chkFLOCK_VCO_SPDUP_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	sttxtFLockN->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_sttxtFLockN ), NULL, this );
	chkFLOCK_LODIST_EN_OUT0_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT1_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT2_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT3_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbR3_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbR2_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC3_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC2_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC1_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_VCT_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkLPFSW_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFF_MOD_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::On_FF_MOD_Change ), NULL, this );
	chkEnableFFDIVDebug->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::On_FF_MOD_Change ), NULL, this );
	chkFFDIV_SEL_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFFCORE_MOD_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkINTMOD_EN_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkDITHER_EN_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkSEL_SDMCLK_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkREV_SDMCLK_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_EN_OUT0_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT02_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT010_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT010_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT1_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT12_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT110_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT110_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT2_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT22_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT210_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT210_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT3_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT32_n->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT310_n->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT310_n->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	txtRefClock->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::OnTextRefClock ), NULL, this );
	btnTune->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::OnTuneClick ), NULL, this );
	chkSmartTuneGenIQ->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	btnSmartTune->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::OnSmartTuneClick ), NULL, this );
}

pnlPLLProfiles_view::~pnlPLLProfiles_view()
{
	// Disconnect Events
	rgrPLLProfile->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::OnSwitchPLLProfile ), NULL, this );
	chkVTUNE_HIGH->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkVTUNE_LOW->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LOCK->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	sttxtPLLFreq->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnupdateUI_sttxtPLLFreq ), NULL, this );
	sttxtPLLFreq1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnupdateUI_sttxtPLLFreq ), NULL, this );
	chkPLL_LODIST_EN_BIAS_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_EN_DIV2IQ_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_VTUNE_COMP_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_LD_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_PFD_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_CP_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_CPOFS_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_VCO_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FFDIV_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FB_PDIV2_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FFCORE_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_EN_FBDIV_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_SDM_CLK_EN_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLIP_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbDEL_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPULSE_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPULSE_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbOFS_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbOFS_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbLD_VCT_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbICT_CP_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_FREQ_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkSPDUP_VCO_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkVCO_AAC_EN_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVDIV_SWVDD_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_SEL_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVCO_AMP_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_R3_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_R2_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C3_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C2_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_C1_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_PULSE_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_PULSE_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	cmbFLOCK_OFS_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_OFS_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbFLOCK_PULSE_n ), NULL, this );
	chkFLOCK_VCO_SPDUP_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFLOCK_N_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	sttxtFLockN->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_sttxtFLockN ), NULL, this );
	chkFLOCK_LODIST_EN_OUT0_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT1_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT2_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkFLOCK_LODIST_EN_OUT3_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbR3_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbR2_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC3_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC2_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbC1_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbVTUNE_VCT_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkLPFSW_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFF_MOD_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::On_FF_MOD_Change ), NULL, this );
	chkEnableFFDIVDebug->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::On_FF_MOD_Change ), NULL, this );
	chkFFDIV_SEL_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFFCORE_MOD_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkINTMOD_EN_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkDITHER_EN_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkSEL_SDMCLK_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkREV_SDMCLK_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbINTMOD_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODL_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbFRACMODH_n->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_EN_OUT0_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT02_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT010_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT010_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT1_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT12_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT110_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT110_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT2_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT22_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT210_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT210_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	chkPLL_LODIST_EN_OUT3_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	chkPLL_LODIST_FSP_OUT32_n->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::chkPLL_LODIST_FSP_OUTCH2_n_Change ), NULL, this );
	cmbPLL_LODIST_FSP_OUT310_n->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	cmbPLL_LODIST_FSP_OUT310_n->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( pnlPLLProfiles_view::OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n ), NULL, this );
	txtRefClock->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( pnlPLLProfiles_view::OnTextRefClock ), NULL, this );
	btnTune->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::OnTuneClick ), NULL, this );
	chkSmartTuneGenIQ->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::ParameterChangeHandler ), NULL, this );
	btnSmartTune->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( pnlPLLProfiles_view::OnSmartTuneClick ), NULL, this );
	
}
