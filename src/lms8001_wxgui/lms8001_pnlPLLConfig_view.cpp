#include "lms8001_pnlPLLConfig_view.h"
#include "LMS8001.h"
#include <map>
#include "lms8001_gui_utilities.h"

lms8001_pnlPLLConfig_view::lms8001_pnlPLLConfig_view( wxWindow* parent )
:
pnlPLLConfig_view( parent )
{

}

lms8001_pnlPLLConfig_view::lms8001_pnlPLLConfig_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
    : pnlPLLConfig_view(parent, id, pos, size, style), lmsControl(nullptr)
{
	wndId2Enum[chkEN_VCOBIAS] = EN_VCOBIAS;
	wndId2Enum[chkBYP_VCOREG] = BYP_VCOREG;
	wndId2Enum[chkCURLIM_VCOREG] = CURLIM_VCOREG;
	wndId2Enum[chkSPDUP_VCOREG] = SPDUP_VCOREG;
	wndId2Enum[cmbVDIV_VCOREG] = VDIV_VCOREG;

	wndId2Enum[chkPLL_XBUF_SLFBEN] = PLL_XBUF_SLFBEN;
	wndId2Enum[chkPLL_XBUF_BYPEN] = PLL_XBUF_BYPEN;
	wndId2Enum[chkPLL_XBUF_EN] = PLL_XBUF_EN;

	wndId2Enum[chkFCAL_START] = FCAL_START;
	wndId2Enum[chkVCO_SEL_FINAL_VAL] = VCO_SEL_FINAL_VAL;
	wndId2Enum[cmbVCO_SEL_FINAL] = VCO_SEL_FINAL;
	wndId2Enum[chkFREQ_FINAL_VAL] = FREQ_FINAL_VAL;
	wndId2Enum[cmbFREQ_FINAL] = FREQ_FINAL;
	wndId2Enum[chkVCO_SEL_FORCE] = VCO_SEL_FORCE;
	wndId2Enum[cmbVCO_SEL_INIT] = VCO_SEL_INIT;
	wndId2Enum[cmbFREQ_INIT_POS] = FREQ_INIT_POS;
	wndId2Enum[cmbFREQ_INIT] = FREQ_INIT;
	wndId2Enum[cmbFREQ_SETTLING_N] = FREQ_SETTLING_N;
	wndId2Enum[cmbVTUNE_WAIT_N] = VTUNE_WAIT_N;
	wndId2Enum[cmbVCO_SEL_FREQ_MAX] = VCO_SEL_FREQ_MAX;
	wndId2Enum[cmbVCO_SEL_FREQ_MIN] = VCO_SEL_FREQ_MIN;

	wndId2Enum[cmbVCO_FREQ_MAN] = VCO_FREQ_MAN;
	wndId2Enum[cmbVCO_SEL_MAN] = VCO_SEL_MAN;
	wndId2Enum[chkFREQ_LOW] = FREQ_LOW;
	wndId2Enum[chkFREQ_EQUAL] = FREQ_EQUAL;
	wndId2Enum[chkFREQ_HIGH] = FREQ_HIGH;
	wndId2Enum[chkCTUNE_STEP_DONE] = CTUNE_STEP_DONE;
	wndId2Enum[chkCTUNE_START] = CTUNE_START;
	wndId2Enum[chkCTUNE_EN] = CTUNE_EN;

	wndId2Enum[chkPLL_CFG_SEL0_INTERNAL] = PLL_CFG_SEL0_INTERNAL;
	wndId2Enum[chkPLL_CFG_SEL0_INVERT] = PLL_CFG_SEL0_INVERT;
	wndId2Enum[chkPLL_CFG_SEL0_MASK0] = PLL_CFG_SEL0_MASK0;
	wndId2Enum[chkPLL_CFG_SEL0_MASK1] = PLL_CFG_SEL0_MASK1;
	wndId2Enum[chkPLL_CFG_SEL0_MASK2] = PLL_CFG_SEL0_MASK2;
	wndId2Enum[chkPLL_CFG_SEL0_MASK3] = PLL_CFG_SEL0_MASK3;
	wndId2Enum[chkPLL_CFG_SEL0_MASK4] = PLL_CFG_SEL0_MASK4;
	wndId2Enum[chkPLL_CFG_SEL0_MASK5] = PLL_CFG_SEL0_MASK5;
	wndId2Enum[chkPLL_CFG_SEL0_MASK6] = PLL_CFG_SEL0_MASK6;
	wndId2Enum[chkPLL_CFG_SEL0_MASK7] = PLL_CFG_SEL0_MASK7;
	wndId2Enum[chkPLL_CFG_SEL0_MASK8] = PLL_CFG_SEL0_MASK8;

	wndId2Enum[chkPLL_CFG_SEL1_INTERNAL] = PLL_CFG_SEL1_INTERNAL;
	wndId2Enum[chkPLL_CFG_SEL1_INVERT] = PLL_CFG_SEL1_INVERT;
	wndId2Enum[chkPLL_CFG_SEL1_MASK0] = PLL_CFG_SEL1_MASK0;
	wndId2Enum[chkPLL_CFG_SEL1_MASK1] = PLL_CFG_SEL1_MASK1;
	wndId2Enum[chkPLL_CFG_SEL1_MASK2] = PLL_CFG_SEL1_MASK2;
	wndId2Enum[chkPLL_CFG_SEL1_MASK3] = PLL_CFG_SEL1_MASK3;
	wndId2Enum[chkPLL_CFG_SEL1_MASK4] = PLL_CFG_SEL1_MASK4;
	wndId2Enum[chkPLL_CFG_SEL1_MASK5] = PLL_CFG_SEL1_MASK5;
	wndId2Enum[chkPLL_CFG_SEL1_MASK6] = PLL_CFG_SEL1_MASK6;
	wndId2Enum[chkPLL_CFG_SEL1_MASK7] = PLL_CFG_SEL1_MASK7;
	wndId2Enum[chkPLL_CFG_SEL1_MASK8] = PLL_CFG_SEL1_MASK8;

	wndId2Enum[chkPLL_CFG_SEL2_INTERNAL] = PLL_CFG_SEL2_INTERNAL;
	wndId2Enum[chkPLL_CFG_SEL2_INVERT] = PLL_CFG_SEL2_INVERT;
	wndId2Enum[chkPLL_CFG_SEL2_MASK0] = PLL_CFG_SEL2_MASK0;
	wndId2Enum[chkPLL_CFG_SEL2_MASK1] = PLL_CFG_SEL2_MASK1;
	wndId2Enum[chkPLL_CFG_SEL2_MASK2] = PLL_CFG_SEL2_MASK2;
	wndId2Enum[chkPLL_CFG_SEL2_MASK3] = PLL_CFG_SEL2_MASK3;
	wndId2Enum[chkPLL_CFG_SEL2_MASK4] = PLL_CFG_SEL2_MASK4;
	wndId2Enum[chkPLL_CFG_SEL2_MASK5] = PLL_CFG_SEL2_MASK5;
	wndId2Enum[chkPLL_CFG_SEL2_MASK6] = PLL_CFG_SEL2_MASK6;
	wndId2Enum[chkPLL_CFG_SEL2_MASK7] = PLL_CFG_SEL2_MASK7;
	wndId2Enum[chkPLL_CFG_SEL2_MASK8] = PLL_CFG_SEL2_MASK8;

	wndId2Enum[chkPLL_CFG_INT_SEL0] = PLL_CFG_INT_SEL0;
	wndId2Enum[chkPLL_CFG_INT_SEL1] = PLL_CFG_INT_SEL1;
	wndId2Enum[chkPLL_CFG_INT_SEL2] = PLL_CFG_INT_SEL2;

	wndId2Enum[chkPLL_CFG_INT_SEL] = PLL_CFG_INT_SEL;

	wndId2Enum[rgrPLL_RSTN] = PLL_RSTN;

//	wndId2Enum[chkPLL_RSTN] = PLL_RSTN;
	wndId2Enum[cmbCTUNE_RES] = CTUNE_RES;
	wndId2Enum[chkPLL_CALIBRATION_MODE] = PLL_CALIBRATION_MODE;
	wndId2Enum[chkPLL_CALIBRATION_EN] = PLL_CALIBRATION_EN;
	wndId2Enum[chkPLL_FLOCK_INTERNAL] = PLL_FLOCK_INTERNAL;
	wndId2Enum[chkPLL_FLOCK_INTVAL] = PLL_FLOCK_INTVAL;

	wndId2Enum[chkVTUNE_HIGH] = VTUNE_HIGH;
	wndId2Enum[chkVTUNE_LOW] = VTUNE_LOW;
	wndId2Enum[chkPLL_LOCK] = PLL_LOCK;

	wndId2Enum[chkSEL_BIAS_CORE] = SEL_BIAS_CORE;
	wndId2Enum[cmbPLL_LODIST_ICT_CORE] = PLL_LODIST_ICT_CORE;
	wndId2Enum[cmbPLL_LODIST_ICT_BUF] = PLL_LODIST_ICT_BUF;
	wndId2Enum[choPLL_ICT_OUT0] = PLL_ICT_OUT0;
	wndId2Enum[choPLL_ICT_OUT1] = PLL_ICT_OUT1;
	wndId2Enum[choPLL_ICT_OUT2] = PLL_ICT_OUT2;
	wndId2Enum[choPLL_ICT_OUT3] = PLL_ICT_OUT3;

	wndId2Enum[cmbBSIGL] = BSIGL;
	wndId2Enum[chkBSTATE] = BSTATE;
	wndId2Enum[chkEN_SDM_TSTO] = EN_SDM_TSTO;
	wndId2Enum[chkBEN] = BEN;
	wndId2Enum[chkBSTART] = BSTART;

	wndId2Enum[cmbBSIGH] = BSIGH;

	wxArrayString temp;
	temp.clear();
	for (int i = 0; i<256; ++i)
	{
//		temp.push_back(wxString::Format(_("%.3f V"), (860.0 + 3.92*i) / 1000.0));
		temp.push_back(wxString::Format(_("%.3f V"), 1.8*(257 - i)/(265 - i)));
	}
	cmbVDIV_VCOREG->Append(temp);

	temp.clear();
	temp.push_back("10 MHz");
	temp.push_back("5 MHz");
	temp.push_back("2.5 MHz");
	temp.push_back("1.25 MHz");

	cmbCTUNE_RES->Append(temp);


	LMS8001_WXGUI::UpdateTooltips(wndId2Enum, true);
}

void lms8001_pnlPLLConfig_view::Initialize(LMS8001* pControl)
{
    lmsControl = pControl;
    assert(lmsControl != nullptr);
}

void lms8001_pnlPLLConfig_view::ParameterChangeHandler(wxCommandEvent& event)
{
    assert(lmsControl != nullptr);
    LMS8Parameter parameter;
    try
    {
        parameter = wndId2Enum.at(reinterpret_cast<wxWindow*>(event.GetEventObject()));
    }
    catch (std::exception & e)
    {
        std::cout << "Control element(ID = " << event.GetId() << ") don't have assigned LMS parameter." << std::endl;
        return;
    }

	//msavic
	lmsControl->Modify_SPI_Reg_bits(parameter, event.GetInt(), true, lmsControl->channel);
}

void lms8001_pnlPLLConfig_view::UpdateGUI()
{
    LMS8001_WXGUI::UpdateControlsByMap(this, lmsControl, wndId2Enum);
}

void lms8001_pnlPLLConfig_view::OnSelectProfileClick(wxCommandEvent& event)
{
	bool simple = chkSelectProfile->GetValue();
	chkPLL_CFG_INT_SEL->Enable(simple);
	ID_NOTEBOOK_MUX_CONTROL_PLL->Enable(!simple);
	chkPLL_CFG_INT_SEL0->Enable(!simple);
	chkPLL_CFG_INT_SEL1->Enable(!simple);
	chkPLL_CFG_INT_SEL2->Enable(!simple);

	if (simple) {
		lmsControl->Modify_SPI_Reg_bits(PLL_CFG_INT_SEL, PLL_CFG_INT_SEL.defaultValue, true, lmsControl->channel);
		lmsControl->Modify_SPI_Reg_bits(PLL_CFG_SEL0, PLL_CFG_SEL0.defaultValue, true, lmsControl->channel);
		lmsControl->Modify_SPI_Reg_bits(PLL_CFG_SEL1, PLL_CFG_SEL1.defaultValue, true, lmsControl->channel);
		lmsControl->Modify_SPI_Reg_bits(PLL_CFG_SEL2, PLL_CFG_SEL2.defaultValue, true, lmsControl->channel);
	}

	UpdateGUI();
}