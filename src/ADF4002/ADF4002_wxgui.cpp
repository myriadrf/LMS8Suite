#include "ADF4002.h"
#include "ADF4002_wxgui.h"
#include "lmsComms.h"
#include <wx/msgdlg.h>

ADF4002_wxgui::ADF4002_wxgui(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, int styles, wxString idname)
	: ADF4002_wxgui_view(parent, id, title, pos, size, styles)
{
	m_pModule = NULL;
}

ADF4002_wxgui::ADF4002_wxgui(wxWindow* parent)
	: ADF4002_wxgui_view(parent)
{
	m_pModule = NULL;
}

void ADF4002_wxgui::Initialize(ADF4002* pModule, LMScomms* pSerPort)
{
	assert(pSerPort != nullptr);
	m_pModule = pModule;
	serPort = pSerPort;
}

void ADF4002_wxgui::SetGuiDefaults()
{
	//Reference Counter Latch
	cmbLDP->SetSelection(0);
	cmbABW->SetSelection(0);
	spinRCnt->SetValue(125);

	//N Counter Latch
	cmbCPG->SetSelection(0);
	spinNCnt->SetValue(384);

	//Function Latch
	rgrPD2_f->SetSelection(0);
	cmbCS2_f->SetSelection(7);
	cmbCS1_f->SetSelection(7);
	cmbTC_f->SetSelection(0);
	cmbFL_f->SetSelection(0);
	rgrCPS_f->SetSelection(0);
	rgrPDP_f->SetSelection(1);
	cmbMOC_f->SetSelection(1);
	rgrPD1_f->SetSelection(0);
	rgrCR_f->SetSelection(0);

	//Initialization Latch
	rgrPD2_i->SetSelection(0);
	cmbCS2_i->SetSelection(7);
	cmbCS1_i->SetSelection(7);
	cmbTC_i->SetSelection(0);
	cmbFL_i->SetSelection(0);
	rgrCPS_i->SetSelection(0);
	rgrPDP_i->SetSelection(1);
	cmbMOC_i->SetSelection(1);
	rgrPD1_i->SetSelection(0);
	rgrCR_i->SetSelection(0);
}

void ADF4002_wxgui::OnbtnUploadClick(wxCommandEvent& event)
{
	//reference counter latch
	int ldp = cmbLDP->GetSelection();
	int abw = cmbABW->GetSelection();
	int rCount = spinRCnt->GetValue();
	m_pModule->SetReferenceCounterLatch(ldp, abw, rCount);

	//n counter latch
	int cpGain = cmbCPG->GetSelection();
	int nCounter = spinNCnt->GetValue();
	m_pModule->SetNCounterLatch(cpGain, nCounter);

	//function latch
	int currSetting1 = cmbCS1_f->GetSelection();
	int currSetting2 = cmbCS2_f->GetSelection();
	int tCounter = cmbTC_f->GetSelection();
	int fastLock = cmbFL_f->GetSelection();
	int muxControl = cmbMOC_f->GetSelection();

	int pdPol = rgrPDP_f->GetSelection();
	int pd1 = rgrPD1_f->GetSelection();
	int pd2 = rgrPD2_f->GetSelection();
	int counterReset = rgrCR_f->GetSelection();
	int cpState = rgrCPS_f->GetSelection();
	m_pModule->SetFunctionLatch(currSetting1, currSetting2, tCounter, fastLock, muxControl);
	m_pModule->SetFunctionLatchRgr(pdPol, pd1, pd2, counterReset, cpState);

	//Initialization latch
	currSetting1 = cmbCS1_i->GetSelection();
	currSetting2 = cmbCS2_i->GetSelection();
	tCounter = cmbTC_i->GetSelection();
	fastLock = cmbFL_i->GetSelection();
	muxControl = cmbMOC_i->GetSelection();

	pdPol = rgrPDP_i->GetSelection();
	pd1 = rgrPD1_i->GetSelection();
	pd2 = rgrPD2_i->GetSelection();
	counterReset = rgrCR_i->GetSelection();
	cpState = rgrCPS_i->GetSelection();
	m_pModule->SetInitializationLatch(currSetting1, currSetting2, tCounter, fastLock, muxControl);
	m_pModule->SetInitializationLatchRgr(pdPol, pd1, pd2, counterReset, cpState);

	double fref = 0;
	txtFref->GetValue().ToDouble(&fref);
	double fvco = 0;
	txtFvco->GetValue().ToDouble(&fvco);
	spinNCnt->SetValue(nCounter);
	spinRCnt->SetValue(rCount);
	unsigned char data[12];
	m_pModule->GetConfig(data);

	LMScomms::GenericPacket pkt;
	pkt.cmd = CMD_ADF4002_WR;
	pkt.outBuffer.resize(12, 0);
	memcpy(&pkt.outBuffer[0], data, 12);
	LMScomms::TransferStatus status;
	status = serPort->TransferPacket(pkt);
	if (status != LMScomms::TRANSFER_SUCCESS || pkt.status != STATUS_COMPLETED_CMD)
	{
		wxMessageBox(_("ADF configuration failed"), _("Error"));
	}
}

void ADF4002_wxgui::OnbtnCalcSendClick(wxCommandEvent& event)
{
	//reference counter latch
	int ldp = cmbLDP->GetSelection();
	int abw = cmbABW->GetSelection();
	int rCount = spinRCnt->GetValue();
	m_pModule->SetReferenceCounterLatch(ldp, abw, rCount);

	//n counter latch
	int cpGain = cmbCPG->GetSelection();
	int nCounter = spinNCnt->GetValue();
	m_pModule->SetNCounterLatch(cpGain, nCounter);

	//function latch
	int currSetting1 = cmbCS1_f->GetSelection();
	int currSetting2 = cmbCS2_f->GetSelection();
	int tCounter = cmbTC_f->GetSelection();
	int fastLock = cmbFL_f->GetSelection();
	int muxControl = cmbMOC_f->GetSelection();

	int pdPol = rgrPDP_f->GetSelection();
	int pd1 = rgrPD1_f->GetSelection();
	int pd2 = rgrPD2_f->GetSelection();
	int counterReset = rgrCR_f->GetSelection();
	int cpState = rgrCPS_f->GetSelection();
	m_pModule->SetFunctionLatch(currSetting1, currSetting2, tCounter, fastLock, muxControl);
	m_pModule->SetFunctionLatchRgr(pdPol, pd1, pd2, counterReset, cpState);

	//Initialization latch
	currSetting1 = cmbCS1_i->GetSelection();
	currSetting2 = cmbCS2_i->GetSelection();
	tCounter = cmbTC_i->GetSelection();
	fastLock = cmbFL_i->GetSelection();
	muxControl = cmbMOC_i->GetSelection();

	pdPol = rgrPDP_i->GetSelection();
	pd1 = rgrPD1_i->GetSelection();
	pd2 = rgrPD2_i->GetSelection();
	counterReset = rgrCR_i->GetSelection();
	cpState = rgrCPS_i->GetSelection();
	m_pModule->SetInitializationLatch(currSetting1, currSetting2, tCounter, fastLock, muxControl);
	m_pModule->SetInitializationLatchRgr(pdPol, pd1, pd2, counterReset, cpState);

	double fref = 0;
	txtFref->GetValue().ToDouble(&fref);

	double fvco = 0;
	txtFvco->GetValue().ToDouble(&fvco);
	m_pModule->SetFrefFvco(fref, fvco, rCount, nCounter);
	spinNCnt->SetValue(nCounter);
	spinRCnt->SetValue(rCount);

	lblFcomp->SetLabel(wxString::Format("%f", m_pModule->lblFcomp));
	lblFvco->SetLabel(wxString::Format("%f", m_pModule->lblFvco));

	unsigned char data[12];
	m_pModule->GetConfig(data);

	LMScomms::GenericPacket pkt;
	pkt.cmd = CMD_ADF4002_WR;
	pkt.outBuffer.resize(12, 0);
	memcpy(&pkt.outBuffer[0], data, 12);
	LMScomms::TransferStatus status;
	status = serPort->TransferPacket(pkt);
	if (status != LMScomms::TRANSFER_SUCCESS || pkt.status != STATUS_COMPLETED_CMD)
	{
		wxMessageBox(_("ADF configuration failed"), _("Error"));
	}
}
