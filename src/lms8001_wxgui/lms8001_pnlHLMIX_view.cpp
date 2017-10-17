#include "lms8001_pnlHLMIX_view.h"
#include "LMS8001.h"
#include <map>
#include "lms8001_gui_utilities.h"

lms8001_pnlHLMIX_view::lms8001_pnlHLMIX_view( wxWindow* parent )
:
pnlHLMIX_view( parent )
{

}

lms8001_pnlHLMIX_view::lms8001_pnlHLMIX_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
    : pnlHLMIX_view(parent, id, pos, size, style), lmsControl(nullptr)
{
	wndId2Enum[cmbHLMIXx_VGCAS0] = HLMIXx_VGCAS0;
	wndId2Enum[cmbHLMIXx_ICT_BIAS0] = HLMIXx_ICT_BIAS0;
	wndId2Enum[chkHLMIXx_BIAS_PD0] = HLMIXx_BIAS_PD0;
	wndId2Enum[chkHLMIXx_LOBUF_PD0] = HLMIXx_LOBUF_PD0;
	wndId2Enum[cmbHLMIXx_MIXLOSS0] = HLMIXx_MIXLOSS0;

	wndId2Enum[cmbHLMIXx_VGCAS1] = HLMIXx_VGCAS1;
	wndId2Enum[cmbHLMIXx_ICT_BIAS1] = HLMIXx_ICT_BIAS1;
	wndId2Enum[chkHLMIXx_BIAS_PD1] = HLMIXx_BIAS_PD1;
	wndId2Enum[chkHLMIXx_LOBUF_PD1] = HLMIXx_LOBUF_PD1;
	wndId2Enum[cmbHLMIXx_MIXLOSS1] = HLMIXx_MIXLOSS1;

	wndId2Enum[cmbHLMIXx_VGCAS2] = HLMIXx_VGCAS2;
	wndId2Enum[cmbHLMIXx_ICT_BIAS2] = HLMIXx_ICT_BIAS2;
	wndId2Enum[chkHLMIXx_BIAS_PD2] = HLMIXx_BIAS_PD2;
	wndId2Enum[chkHLMIXx_LOBUF_PD2] = HLMIXx_LOBUF_PD2;
	wndId2Enum[cmbHLMIXx_MIXLOSS2] = HLMIXx_MIXLOSS2;

	wndId2Enum[cmbHLMIXx_VGCAS3] = HLMIXx_VGCAS3;
	wndId2Enum[cmbHLMIXx_ICT_BIAS3] = HLMIXx_ICT_BIAS3;
	wndId2Enum[chkHLMIXx_BIAS_PD3] = HLMIXx_BIAS_PD3;
	wndId2Enum[chkHLMIXx_LOBUF_PD3] = HLMIXx_LOBUF_PD3;
	wndId2Enum[cmbHLMIXx_MIXLOSS3] = HLMIXx_MIXLOSS3;

	wndId2Enum[cmbHLMIXx_VGCAS_RB] = HLMIXx_VGCAS_RB;
	wndId2Enum[cmbHLMIXx_ICT_BIAS_RB] = HLMIXx_ICT_BIAS_RB;
	wndId2Enum[chkHLMIXx_BIAS_PD_RB] = HLMIXx_BIAS_PD_RB;
	wndId2Enum[chkHLMIXx_LOBUF_PD_RB] = HLMIXx_LOBUF_PD_RB;
	wndId2Enum[cmbHLMIXx_MIXLOSS_RB] = HLMIXx_MIXLOSS_RB;

	wndId2Enum[chkHLMIXx_CONFIG_SEL0_INTERNAL] = HLMIXx_CONFIG_SEL0_INTERNAL;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_INVERT] = HLMIXx_CONFIG_SEL0_INVERT;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK0] = HLMIXx_CONFIG_SEL0_MASK0;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK1] = HLMIXx_CONFIG_SEL0_MASK1;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK2] = HLMIXx_CONFIG_SEL0_MASK2;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK3] = HLMIXx_CONFIG_SEL0_MASK3;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK4] = HLMIXx_CONFIG_SEL0_MASK4; 
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK5] = HLMIXx_CONFIG_SEL0_MASK5;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK6] = HLMIXx_CONFIG_SEL0_MASK6;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK7] = HLMIXx_CONFIG_SEL0_MASK7;
	wndId2Enum[chkHLMIXx_CONFIG_SEL0_MASK8] = HLMIXx_CONFIG_SEL0_MASK8;

	wndId2Enum[chkHLMIXx_CONFIG_SEL1_INTERNAL] = HLMIXx_CONFIG_SEL1_INTERNAL;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_INVERT] = HLMIXx_CONFIG_SEL1_INVERT;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK0] = HLMIXx_CONFIG_SEL1_MASK0;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK1] = HLMIXx_CONFIG_SEL1_MASK1;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK2] = HLMIXx_CONFIG_SEL1_MASK2;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK3] = HLMIXx_CONFIG_SEL1_MASK3;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK4] = HLMIXx_CONFIG_SEL1_MASK4;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK5] = HLMIXx_CONFIG_SEL1_MASK5;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK6] = HLMIXx_CONFIG_SEL1_MASK6;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK7] = HLMIXx_CONFIG_SEL1_MASK7;
	wndId2Enum[chkHLMIXx_CONFIG_SEL1_MASK8] = HLMIXx_CONFIG_SEL1_MASK8;

	wndId2Enum[chkHLMIXx_CONFIG_INT_SEL0] = HLMIXx_CONFIG_INT_SEL0;
	wndId2Enum[chkHLMIXx_CONFIG_INT_SEL1] = HLMIXx_CONFIG_INT_SEL1;
	
	wndId2Enum[chkHLMIXx_LOSS_SEL0_INTERNAL] = HLMIXx_LOSS_SEL0_INTERNAL;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_INVERT] = HLMIXx_LOSS_SEL0_INVERT;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK0] = HLMIXx_LOSS_SEL0_MASK0;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK1] = HLMIXx_LOSS_SEL0_MASK1;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK2] = HLMIXx_LOSS_SEL0_MASK2;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK3] = HLMIXx_LOSS_SEL0_MASK3;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK4] = HLMIXx_LOSS_SEL0_MASK4;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK5] = HLMIXx_LOSS_SEL0_MASK5;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK6] = HLMIXx_LOSS_SEL0_MASK6;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK7] = HLMIXx_LOSS_SEL0_MASK7;
	wndId2Enum[chkHLMIXx_LOSS_SEL0_MASK8] = HLMIXx_LOSS_SEL0_MASK8;

	wndId2Enum[chkHLMIXx_LOSS_SEL1_INTERNAL] = HLMIXx_LOSS_SEL1_INTERNAL;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_INVERT] = HLMIXx_LOSS_SEL1_INVERT;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK0] = HLMIXx_LOSS_SEL1_MASK0;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK1] = HLMIXx_LOSS_SEL1_MASK1;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK2] = HLMIXx_LOSS_SEL1_MASK2;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK3] = HLMIXx_LOSS_SEL1_MASK3;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK4] = HLMIXx_LOSS_SEL1_MASK4;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK5] = HLMIXx_LOSS_SEL1_MASK5;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK6] = HLMIXx_LOSS_SEL1_MASK6;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK7] = HLMIXx_LOSS_SEL1_MASK7;
	wndId2Enum[chkHLMIXx_LOSS_SEL1_MASK8] = HLMIXx_LOSS_SEL1_MASK8;

	wndId2Enum[chkHLMIXx_LOSS_INT_SEL0] = HLMIXx_LOSS_INT_SEL0;
	wndId2Enum[chkHLMIXx_LOSS_INT_SEL1] = HLMIXx_LOSS_INT_SEL1;

	
	LMS8001_WXGUI::UpdateTooltips(wndId2Enum, true);
}

void lms8001_pnlHLMIX_view::Initialize(LMS8001* pControl)
{
    lmsControl = pControl;
    assert(lmsControl != nullptr);
}

void lms8001_pnlHLMIX_view::ParameterChangeHandler(wxCommandEvent& event)
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

void lms8001_pnlHLMIX_view::UpdateGUI()
{
    LMS8001_WXGUI::UpdateControlsByMap(this, lmsControl, wndId2Enum);
}
