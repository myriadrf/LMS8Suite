#include <assert.h>
#include "lms8001_mainPanel.h"
//msavic here
#include "lms8001_pnlConfig_view.h"
#include "lms8001_pnlLDO_view.h"
#include "lms8001_pnlChannel_view.h"
#include "lms8001_pnlHLMIX_view.h"
#include "lms8001_pnlPLLConfig_view.h"
#include "lms8001_pnlPLLProfiles_view.h"

#include "LMS8001.h"
#include <wx/time.h>
#include <wx/msgdlg.h>
#include <iostream>
#include <wx/filedlg.h>
#include "lms8suiteEvents.h"
using namespace std;

lms8001_mainPanel::lms8001_mainPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    :
    mainPanel(parent, id, pos, size, style), lmsControl(nullptr), mcuControl(nullptr)
{
//    mTabMCU = new lms7002_pnlMCU_BD_view(tabsNotebook);
//    tabsNotebook->AddPage(mTabMCU, _("MCU"));
//    mcuControl = new MCU_BD();    
}

lms8001_mainPanel::~lms8001_mainPanel()
{   
    delete mcuControl;
}

void lms8001_mainPanel::UpdateVisiblePanel()
{
    wxLongLong t1, t2;
    t1 = wxGetUTCTimeMillis();
    long visibleTabId = tabsNotebook->GetCurrentPage()->GetId();
    switch (visibleTabId)
    {
//msavic
    case ID_TAB_CHIP_CONFIG:
        mTabChipConfig->UpdateGUI();
        break;
	case ID_TAB_LDO:
		mTabLDO->UpdateGUI();
		break;
	case ID_TAB_CHANNEL:
		mTabChannel->UpdateGUI();
		break;
	case ID_TAB_HLMIX:
		mTabHLMIX->UpdateGUI();
		break;
	case ID_TAB_PLLCONFIG:
		mTabPLLConfig->UpdateGUI();
		break;
	case ID_TAB_PLLPROFILES:
		mTabPLLProfiles->UpdateGUI();
		break;
    }
    t2 = wxGetUTCTimeMillis();
#ifndef NDEBUG
    cout << "Visible GUI update time: " << (t2 - t1).ToString() << endl;
#endif
}

void lms8001_mainPanel::Initialize(LMS8001* pControl)
{
    assert(pControl != nullptr);
    lmsControl = pControl;
//msavic ABCD
	lmsControl->channel = rgrChannel->GetSelection();
//msavic PLLprofile
	lmsControl->PLLprofile = 0;
//msavic here
	mTabChipConfig->Initialize(lmsControl);
	mTabLDO->Initialize(lmsControl);
	mTabChannel->Initialize(lmsControl);
	mTabHLMIX->Initialize(lmsControl);
	mTabPLLConfig->Initialize(lmsControl);
	mTabPLLProfiles->Initialize(lmsControl);
    UpdateGUI();
}

void lms8001_mainPanel::OnResetChip(wxCommandEvent &event)
{
    liblms8_status status = lmsControl->ResetChip();
    if (status != LIBLMS8_SUCCESS)
        wxMessageBox(wxString::Format(_("Chip reset: %s"), wxString::From8BitData(liblms8_status2string(status))), _("Warning"));
    wxNotebookEvent evt;
    Onnotebook_modulesPageChanged(evt); //after reset chip active channel might change, this refresh channel for active tab
}

void lms8001_mainPanel::UpdateGUI()
{
    wxLongLong t1, t2;
    t1 = wxGetUTCTimeMillis();
    lmsControl->IsSynced();
    t2 = wxGetUTCTimeMillis();
//    int channel = lmsControl->Get_SPI_Reg_bits(MAC);

//    rgrChannel->SetSelection(channel);
/*
    if (channel == 1)
    {
        rbChannelA->SetValue(true);
        rbChannelB->SetValue(false);
    }
    else if (channel == 2)
    {
        rbChannelA->SetValue(false);
        rbChannelB->SetValue(true);
    }
    else
    {
        lmsControl->Modify_SPI_Reg_bits(MAC, 1);
        rbChannelA->SetValue(true);
        rbChannelB->SetValue(false);
    }
*/
    UpdateVisiblePanel();
#ifndef NDEBUG
    cout << "GUI update time: " << (t2 - t1).ToString() << endl;
#endif
}

void lms8001_mainPanel::OnNewProject( wxCommandEvent& event )
{
    lmsControl->ResetChip();
    lmsControl->DownloadAll();
//msavic ABCD
//    lmsControl->Modify_SPI_Reg_bits(MAC, rbChannelA->GetValue() == 1 ? 1 : 2);
//    lmsControl->Modify_SPI_Reg_bits(MAC, rgrChannel->GetSelection());
    UpdateGUI();
}

void lms8001_mainPanel::OnOpenProject( wxCommandEvent& event )
{
    wxFileDialog dlg(this, _("Open config file"), "", "", "Project-File (*.ini)|*.ini", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (dlg.ShowModal() == wxID_CANCEL)
        return;
    liblms8_status status = lmsControl->LoadConfig(dlg.GetPath().To8BitData());
    if (status != LIBLMS8_SUCCESS)
    {
        if (status != LIBLMS8_NOT_CONNECTED)
            wxMessageBox(_("Failed to load file"), _("Warning"));
    }
    wxCommandEvent tevt;
//msavic ABCD
//    lmsControl->Modify_SPI_Reg_bits(MAC, rbChannelA->GetValue() == 1 ? 1 : 2);
//    lmsControl->Modify_SPI_Reg_bits(MAC, rgrChannel->GetSelection());
    UpdateGUI();  
    wxCommandEvent evt;
    evt.SetEventType(CGEN_FREQUENCY_CHANGED);
    wxPostEvent(this, evt);
}

void lms8001_mainPanel::OnSaveProject( wxCommandEvent& event )
{
    wxFileDialog dlg(this, _("Save config file"), "", "", "Project-File (*.ini)|*.ini", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (dlg.ShowModal() == wxID_CANCEL)
        return;
    liblms8_status status = lmsControl->SaveConfig(dlg.GetPath().To8BitData());
    if (status != LIBLMS8_SUCCESS)
        wxMessageBox(_("Failed to save file"), _("Warning"));
}

void lms8001_mainPanel::OnRegistersTest( wxCommandEvent& event )
{
    liblms8_status status = lmsControl->RegistersTest();
    if (status != LIBLMS8_SUCCESS)
        wxMessageBox(_("Registers test failed!"), _("WARNING"));
    else
        wxMessageBox(_("Registers test passed!"), _("INFO"));
}

void lms8001_mainPanel::OnSwitchChannel(wxCommandEvent& event)
{
//	lmsControl->Modify_SPI_Reg_bits(MAC, 1);
	lmsControl->channel = rgrChannel->GetSelection();
	UpdateVisiblePanel();
}

/*
void lms8001_mainPanel::OnSwitchToChannelA(wxCommandEvent& event)
{
    lmsControl->Modify_SPI_Reg_bits(MAC, 1);
    UpdateVisiblePanel();
}

void lms8001_mainPanel::OnSwitchToChannelB(wxCommandEvent& event)
{
    lmsControl->Modify_SPI_Reg_bits(MAC, 2);
    UpdateVisiblePanel();
}
*/
void lms8001_mainPanel::Onnotebook_modulesPageChanged( wxNotebookEvent& event )
{
    wxNotebookPage* page = tabsNotebook->GetCurrentPage();
//msavic
	if (page == mTabChannel || page == mTabHLMIX)
		rgrChannel->Enable();
	else
		rgrChannel->Disable();
/*
//   if (page == mTabAFE || page == mTabBIAS || page == mTabLDO || page == mTabXBUF || page == mTabCGEN || page == mTabCDS || page == mTabBIST)
	if (page == mTabLDO)
    {
        rbChannelA->Disable();
        rbChannelB->Disable();
    }
    else if (page == mTabSXR) //change active channel to A
    {
        lmsControl->Modify_SPI_Reg_bits(MAC, 1);
        rbChannelA->Disable();
        rbChannelB->Disable();
    }
    else if (page == mTabSXT) //change active channel to B
    {
        lmsControl->Modify_SPI_Reg_bits(MAC, 2);
        rbChannelA->Disable();
        rbChannelB->Disable();
    }
    else
    {
        lmsControl->Modify_SPI_Reg_bits(MAC, rbChannelA->GetValue() == 1 ? 1 : 2);
        rbChannelA->Enable();
        rbChannelB->Enable();
    }
*/
    UpdateVisiblePanel();
}

void lms8001_mainPanel::OnDownloadAll(wxCommandEvent& event)
{
    liblms8_status status = lmsControl->DownloadAll();
    if (status != LIBLMS8_SUCCESS)
        wxMessageBox(wxString::Format(_("Download all registers: %s"), wxString::From8BitData(liblms8_status2string(status))), _("Warning"));
    UpdateVisiblePanel();
}

void lms8001_mainPanel::OnUploadAll(wxCommandEvent& event)
{
    liblms8_status status = lmsControl->UploadAll();
    if (status != LIBLMS8_SUCCESS)
        wxMessageBox(wxString::Format(_("Upload all registers: %s"), wxString::From8BitData(liblms8_status2string(status))), _("Warning"));
    UpdateVisiblePanel();
}
//mb added:
void lms8001_mainPanel::OnUploadPanel(wxCommandEvent& event)
{
	UpdateVisiblePanel();
}