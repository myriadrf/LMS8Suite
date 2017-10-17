#include "Si5351C.h"
#include "Si5351C_wxgui.h"

#include <wx/filedlg.h>

Si5351C_wxgui::Si5351C_wxgui(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, int styles, wxString idname)
	: Si5351C_wxgui_view(parent, id, title, pos, size, styles)
{
	
}

void Si5351C_wxgui::Initialize(Si5351C* pModule)
{
	m_pModule = pModule;
}

void Si5351C_wxgui::OnbtnLoadFileClick(wxCommandEvent& event)
{
	wxFileDialog openFileDialog(this, _("Open project file"), "", "", "Register Files (*.h)|*.h|Text files (*.txt)|*.TXT", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;

	m_pModule->LoadRegValuesFromFile(openFileDialog.GetPath().ToStdString().c_str());
	m_pModule->UploadConfiguration();
}

void Si5351C_wxgui::OnbtnConfigureClockClick(wxCommandEvent& event)
{
	double refFreq;
	double freq;

	txtCLKIN_MHz->GetValue().ToDouble(&refFreq);
	m_pModule->SetPLL(0, refFreq * 1000000);
	m_pModule->SetPLL(1, refFreq * 1000000);

	txtFreq_CLK->GetValue().ToDouble(&freq);

	m_pModule->SetClock(0, freq * 1000000, false, false);
	m_pModule->SetClock(1, freq * 1000000, false, false);
	m_pModule->SetClock(2, freq * 1000000, false, false);
	m_pModule->SetClock(3, freq * 1000000, false, false);
	m_pModule->SetClock(4, freq * 1000000, chkEN_CLK->GetValue(), chkInvert_CLK->GetValue());
	m_pModule->SetClock(5, freq * 1000000, false, false);
	m_pModule->SetClock(6, freq * 1000000, false, false);
	m_pModule->SetClock(7, freq * 1000000, false, false);

	if (m_pModule->ConfigureClocks() == Si5351C::SUCCESS)
		m_pModule->UploadConfiguration();
}

void Si5351C_wxgui::OnbtnResetToDefaultsClick(wxCommandEvent& event)
{
	m_pModule->Reset();
	m_pModule->UploadConfiguration();
}

void Si5351C_wxgui::OnbtnReadStatusClick(wxCommandEvent& event)
{
	Si5351C::StatusBits stat = m_pModule->GetStatusBits();
	wxString text = wxString::Format("\
SYS_INIT:  %i    SYS_INIT_STKY:  %i\n\
LOL_B:     %i    LOL_B_STKY:     %i\n\
LOL_A:     %i    LOL_A_STKY:     %i\n\
LOS:       %i    LOS_STKY:       %i", stat.sys_init, stat.sys_init_stky, stat.lol_b, stat.lol_b_stky, stat.lol_a, stat.lol_a_stky, stat.los, stat.los_stky);
	lblStatus->SetLabel(text);
}

void Si5351C_wxgui::OnbtnClearStatusClick(wxCommandEvent& event)
{
	m_pModule->ClearStatus();
	wxString text = wxString::Format("\
SYS_INIT:  %i    SYS_INIT_STKY:  %i\n\
LOL_B:     %i    LOL_B_STKY:     %i\n\
LOL_A:     %i    LOL_A_STKY:     %i\n\
LOS:       %i    LOS_STKY:       %i", 0, 0, 0, 0, 0, 0, 0, 0);
	lblStatus->SetLabel(text);
}

