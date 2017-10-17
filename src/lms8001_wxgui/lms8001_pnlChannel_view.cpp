#include "lms8001_pnlChannel_view.h"
#include "LMS8001.h"
#include <map>
#include "lms8001_gui_utilities.h"

#include <wx/msgdlg.h>

#include <wx/dc.h>

#include "channel_image.h"

lms8001_pnlChannel_view::lms8001_pnlChannel_view( wxWindow* parent )
:
pnlChannel_view( parent )
{

}

lms8001_pnlChannel_view::lms8001_pnlChannel_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
    : pnlChannel_view(parent, id, pos, size, style), lmsControl(nullptr)
{
//	wndId2Enum[cmbCHx_MIXA_ICT] = CHx_MIXA_ICT;
//	wndId2Enum[cmbCHx_MIXB_ICT] = CHx_MIXB_ICT;

	wndId2Enum[chkCHx_PA_ILIN2X] = CHx_PA_ILIN2X;
	wndId2Enum[cmbCHx_PA_ICT_LIN] = CHx_PA_ICT_LIN;
	wndId2Enum[cmbCHx_PA_ICT_MAIN] = CHx_PA_ICT_MAIN;
	
	wndId2Enum[chkCHx_PA_R50_EN0] = CHx_PA_R50_EN0;
	wndId2Enum[chkCHx_PA_BYPASS0] = CHx_PA_BYPASS0;
	wndId2Enum[chkCHx_PA_PD0] = CHx_PA_PD0;
	wndId2Enum[chkCHx_MIXB_LOBUFF_PD0] = CHx_MIXB_LOBUFF_PD0;
//	wndId2Enum[chkCHx_MIXB_BIAS_PD0] = CHx_MIXB_BIAS_PD0;
	wndId2Enum[chkCHx_MIXA_LOBUFF_PD0] = CHx_MIXA_LOBUFF_PD0;
//	wndId2Enum[chkCHx_MIXA_BIAS_PD0] = CHx_MIXA_BIAS_PD0;
	wndId2Enum[chkCHx_LNA_PD0] = CHx_LNA_PD0;

	wndId2Enum[cmbCHx_LNA_ICT_LIN0] = CHx_LNA_ICT_LIN0;
	wndId2Enum[cmbCHx_LNA_ICT_MAIN0] = CHx_LNA_ICT_MAIN0;
	wndId2Enum[cmbCHx_LNA_CGSCTRL0] = CHx_LNA_CGSCTRL0;
	wndId2Enum[cmbCHx_LNA_GCTRL0] = CHx_LNA_GCTRL0;

	wndId2Enum[cmbCHx_PA_LIN_LOSS0] = CHx_PA_LIN_LOSS0;
	wndId2Enum[cmbCHx_PA_MAIN_LOSS0] = CHx_PA_MAIN_LOSS0;

	wndId2Enum[chkCHx_PA_R50_EN1] = CHx_PA_R50_EN1;
	wndId2Enum[chkCHx_PA_BYPASS1] = CHx_PA_BYPASS1;
	wndId2Enum[chkCHx_PA_PD1] = CHx_PA_PD1;
	wndId2Enum[chkCHx_MIXB_LOBUFF_PD1] = CHx_MIXB_LOBUFF_PD1;
//	wndId2Enum[chkCHx_MIXB_BIAS_PD1] = CHx_MIXB_BIAS_PD1;
	wndId2Enum[chkCHx_MIXA_LOBUFF_PD1] = CHx_MIXA_LOBUFF_PD1;
//	wndId2Enum[chkCHx_MIXA_BIAS_PD1] = CHx_MIXA_BIAS_PD1;
	wndId2Enum[chkCHx_LNA_PD1] = CHx_LNA_PD1;

	wndId2Enum[cmbCHx_LNA_ICT_LIN1] = CHx_LNA_ICT_LIN1;
	wndId2Enum[cmbCHx_LNA_ICT_MAIN1] = CHx_LNA_ICT_MAIN1;
	wndId2Enum[cmbCHx_LNA_CGSCTRL1] = CHx_LNA_CGSCTRL1;
	wndId2Enum[cmbCHx_LNA_GCTRL1] = CHx_LNA_GCTRL1;

	wndId2Enum[cmbCHx_PA_LIN_LOSS1] = CHx_PA_LIN_LOSS1;
	wndId2Enum[cmbCHx_PA_MAIN_LOSS1] = CHx_PA_MAIN_LOSS1;

	wndId2Enum[chkCHx_PA_R50_EN2] = CHx_PA_R50_EN2;
	wndId2Enum[chkCHx_PA_BYPASS2] = CHx_PA_BYPASS2;
	wndId2Enum[chkCHx_PA_PD2] = CHx_PA_PD2;
	wndId2Enum[chkCHx_MIXB_LOBUFF_PD2] = CHx_MIXB_LOBUFF_PD2;
//	wndId2Enum[chkCHx_MIXB_BIAS_PD2] = CHx_MIXB_BIAS_PD2;
	wndId2Enum[chkCHx_MIXA_LOBUFF_PD2] = CHx_MIXA_LOBUFF_PD2;
//	wndId2Enum[chkCHx_MIXA_BIAS_PD2] = CHx_MIXA_BIAS_PD2;
	wndId2Enum[chkCHx_LNA_PD2] = CHx_LNA_PD2;

	wndId2Enum[cmbCHx_LNA_ICT_LIN2] = CHx_LNA_ICT_LIN2;
	wndId2Enum[cmbCHx_LNA_ICT_MAIN2] = CHx_LNA_ICT_MAIN2;
	wndId2Enum[cmbCHx_LNA_CGSCTRL2] = CHx_LNA_CGSCTRL2;
	wndId2Enum[cmbCHx_LNA_GCTRL2] = CHx_LNA_GCTRL2;

	wndId2Enum[cmbCHx_PA_LIN_LOSS2] = CHx_PA_LIN_LOSS2;
	wndId2Enum[cmbCHx_PA_MAIN_LOSS2] = CHx_PA_MAIN_LOSS2;

	wndId2Enum[chkCHx_PA_R50_EN3] = CHx_PA_R50_EN3;
	wndId2Enum[chkCHx_PA_BYPASS3] = CHx_PA_BYPASS3;
	wndId2Enum[chkCHx_PA_PD3] = CHx_PA_PD3;
	wndId2Enum[chkCHx_MIXB_LOBUFF_PD3] = CHx_MIXB_LOBUFF_PD3;
//	wndId2Enum[chkCHx_MIXB_BIAS_PD3] = CHx_MIXB_BIAS_PD3;
	wndId2Enum[chkCHx_MIXA_LOBUFF_PD3] = CHx_MIXA_LOBUFF_PD3;
//	wndId2Enum[chkCHx_MIXA_BIAS_PD3] = CHx_MIXA_BIAS_PD3;
	wndId2Enum[chkCHx_LNA_PD3] = CHx_LNA_PD3;

	wndId2Enum[cmbCHx_LNA_ICT_LIN3] = CHx_LNA_ICT_LIN3;
	wndId2Enum[cmbCHx_LNA_ICT_MAIN3] = CHx_LNA_ICT_MAIN3;
	wndId2Enum[cmbCHx_LNA_CGSCTRL3] = CHx_LNA_CGSCTRL3;
	wndId2Enum[cmbCHx_LNA_GCTRL3] = CHx_LNA_GCTRL3;

	wndId2Enum[cmbCHx_PA_LIN_LOSS3] = CHx_PA_LIN_LOSS3;
	wndId2Enum[cmbCHx_PA_MAIN_LOSS3] = CHx_PA_MAIN_LOSS3;

	wndId2Enum[chkCHx_PA_R50_EN_RB] = CHx_PA_R50_EN_RB;
	wndId2Enum[chkCHx_PA_BYPASS_RB] = CHx_PA_BYPASS_RB;
	wndId2Enum[chkCHx_PA_PD_RB] = CHx_PA_PD_RB;
	wndId2Enum[chkCHx_MIXB_LOBUFF_PD_RB] = CHx_MIXB_LOBUFF_PD_RB;
//	wndId2Enum[chkCHx_MIXB_BIAS_PD_RB] = CHx_MIXB_BIAS_PD_RB;
	wndId2Enum[chkCHx_MIXA_LOBUFF_PD_RB] = CHx_MIXA_LOBUFF_PD_RB;
//	wndId2Enum[chkCHx_MIXA_BIAS_PD_RB] = CHx_MIXA_BIAS_PD_RB;
	wndId2Enum[chkCHx_LNA_PD_RB] = CHx_LNA_PD_RB;

	wndId2Enum[cmbCHx_LNA_ICT_LIN_RB] = CHx_LNA_ICT_LIN_RB;
	wndId2Enum[cmbCHx_LNA_ICT_MAIN_RB] = CHx_LNA_ICT_MAIN_RB;
	wndId2Enum[cmbCHx_LNA_CGSCTRL_RB] = CHx_LNA_CGSCTRL_RB;
	wndId2Enum[cmbCHx_LNA_GCTRL_RB] = CHx_LNA_GCTRL_RB;

	wndId2Enum[cmbCHx_PA_LIN_LOSS_RB] = CHx_PA_LIN_LOSS_RB;
	wndId2Enum[cmbCHx_PA_MAIN_LOSS_RB] = CHx_PA_MAIN_LOSS_RB;

	wndId2Enum[chkCHx_PD_SEL0_INTERNAL] = CHx_PD_SEL0_INTERNAL;
	wndId2Enum[chkCHx_PD_SEL0_INVERT] = CHx_PD_SEL0_INVERT;
	wndId2Enum[chkCHx_PD_SEL0_MASK0] = CHx_PD_SEL0_MASK0;
	wndId2Enum[chkCHx_PD_SEL0_MASK1] = CHx_PD_SEL0_MASK1;
	wndId2Enum[chkCHx_PD_SEL0_MASK2] = CHx_PD_SEL0_MASK2;
	wndId2Enum[chkCHx_PD_SEL0_MASK3] = CHx_PD_SEL0_MASK3;
	wndId2Enum[chkCHx_PD_SEL0_MASK4] = CHx_PD_SEL0_MASK4;
	wndId2Enum[chkCHx_PD_SEL0_MASK5] = CHx_PD_SEL0_MASK5;
	wndId2Enum[chkCHx_PD_SEL0_MASK6] = CHx_PD_SEL0_MASK6;
	wndId2Enum[chkCHx_PD_SEL0_MASK7] = CHx_PD_SEL0_MASK7;
	wndId2Enum[chkCHx_PD_SEL0_MASK8] = CHx_PD_SEL0_MASK8;

	wndId2Enum[chkCHx_PD_SEL1_INTERNAL] = CHx_PD_SEL1_INTERNAL;
	wndId2Enum[chkCHx_PD_SEL1_INVERT] = CHx_PD_SEL1_INVERT;
	wndId2Enum[chkCHx_PD_SEL1_MASK0] = CHx_PD_SEL1_MASK0;
	wndId2Enum[chkCHx_PD_SEL1_MASK1] = CHx_PD_SEL1_MASK1;
	wndId2Enum[chkCHx_PD_SEL1_MASK2] = CHx_PD_SEL1_MASK2;
	wndId2Enum[chkCHx_PD_SEL1_MASK3] = CHx_PD_SEL1_MASK3;
	wndId2Enum[chkCHx_PD_SEL1_MASK4] = CHx_PD_SEL1_MASK4;
	wndId2Enum[chkCHx_PD_SEL1_MASK5] = CHx_PD_SEL1_MASK5;
	wndId2Enum[chkCHx_PD_SEL1_MASK6] = CHx_PD_SEL1_MASK6;
	wndId2Enum[chkCHx_PD_SEL1_MASK7] = CHx_PD_SEL1_MASK7;
	wndId2Enum[chkCHx_PD_SEL1_MASK8] = CHx_PD_SEL1_MASK8;

	wndId2Enum[chkCHx_LNA_SEL0_INTERNAL] = CHx_LNA_SEL0_INTERNAL;
	wndId2Enum[chkCHx_LNA_SEL0_INVERT] = CHx_LNA_SEL0_INVERT;
	wndId2Enum[chkCHx_LNA_SEL0_MASK0] = CHx_LNA_SEL0_MASK0;
	wndId2Enum[chkCHx_LNA_SEL0_MASK1] = CHx_LNA_SEL0_MASK1;
	wndId2Enum[chkCHx_LNA_SEL0_MASK2] = CHx_LNA_SEL0_MASK2;
	wndId2Enum[chkCHx_LNA_SEL0_MASK3] = CHx_LNA_SEL0_MASK3;
	wndId2Enum[chkCHx_LNA_SEL0_MASK4] = CHx_LNA_SEL0_MASK4;
	wndId2Enum[chkCHx_LNA_SEL0_MASK5] = CHx_LNA_SEL0_MASK5;
	wndId2Enum[chkCHx_LNA_SEL0_MASK6] = CHx_LNA_SEL0_MASK6;
	wndId2Enum[chkCHx_LNA_SEL0_MASK7] = CHx_LNA_SEL0_MASK7;
	wndId2Enum[chkCHx_LNA_SEL0_MASK8] = CHx_LNA_SEL0_MASK8;

	wndId2Enum[chkCHx_LNA_SEL1_INTERNAL] = CHx_LNA_SEL1_INTERNAL;
	wndId2Enum[chkCHx_LNA_SEL1_INVERT] = CHx_LNA_SEL1_INVERT;
	wndId2Enum[chkCHx_LNA_SEL1_MASK0] = CHx_LNA_SEL1_MASK0;
	wndId2Enum[chkCHx_LNA_SEL1_MASK1] = CHx_LNA_SEL1_MASK1;
	wndId2Enum[chkCHx_LNA_SEL1_MASK2] = CHx_LNA_SEL1_MASK2;
	wndId2Enum[chkCHx_LNA_SEL1_MASK3] = CHx_LNA_SEL1_MASK3;
	wndId2Enum[chkCHx_LNA_SEL1_MASK4] = CHx_LNA_SEL1_MASK4;
	wndId2Enum[chkCHx_LNA_SEL1_MASK5] = CHx_LNA_SEL1_MASK5;
	wndId2Enum[chkCHx_LNA_SEL1_MASK6] = CHx_LNA_SEL1_MASK6;
	wndId2Enum[chkCHx_LNA_SEL1_MASK7] = CHx_LNA_SEL1_MASK7;
	wndId2Enum[chkCHx_LNA_SEL1_MASK8] = CHx_LNA_SEL1_MASK8;

	wndId2Enum[chkCHx_PA_SEL0_INTERNAL] = CHx_PA_SEL0_INTERNAL;
	wndId2Enum[chkCHx_PA_SEL0_INVERT] = CHx_PA_SEL0_INVERT;
	wndId2Enum[chkCHx_PA_SEL0_MASK0] = CHx_PA_SEL0_MASK0;
	wndId2Enum[chkCHx_PA_SEL0_MASK1] = CHx_PA_SEL0_MASK1;
	wndId2Enum[chkCHx_PA_SEL0_MASK2] = CHx_PA_SEL0_MASK2;
	wndId2Enum[chkCHx_PA_SEL0_MASK3] = CHx_PA_SEL0_MASK3;
	wndId2Enum[chkCHx_PA_SEL0_MASK4] = CHx_PA_SEL0_MASK4;
	wndId2Enum[chkCHx_PA_SEL0_MASK5] = CHx_PA_SEL0_MASK5;
	wndId2Enum[chkCHx_PA_SEL0_MASK6] = CHx_PA_SEL0_MASK6;
	wndId2Enum[chkCHx_PA_SEL0_MASK7] = CHx_PA_SEL0_MASK7;
	wndId2Enum[chkCHx_PA_SEL0_MASK8] = CHx_PA_SEL0_MASK8;

	wndId2Enum[chkCHx_PA_SEL1_INTERNAL] = CHx_PA_SEL1_INTERNAL;
	wndId2Enum[chkCHx_PA_SEL1_INVERT] = CHx_PA_SEL1_INVERT;
	wndId2Enum[chkCHx_PA_SEL1_MASK0] = CHx_PA_SEL1_MASK0;
	wndId2Enum[chkCHx_PA_SEL1_MASK1] = CHx_PA_SEL1_MASK1;
	wndId2Enum[chkCHx_PA_SEL1_MASK2] = CHx_PA_SEL1_MASK2;
	wndId2Enum[chkCHx_PA_SEL1_MASK3] = CHx_PA_SEL1_MASK3;
	wndId2Enum[chkCHx_PA_SEL1_MASK4] = CHx_PA_SEL1_MASK4;
	wndId2Enum[chkCHx_PA_SEL1_MASK5] = CHx_PA_SEL1_MASK5;
	wndId2Enum[chkCHx_PA_SEL1_MASK6] = CHx_PA_SEL1_MASK6;
	wndId2Enum[chkCHx_PA_SEL1_MASK7] = CHx_PA_SEL1_MASK7;
	wndId2Enum[chkCHx_PA_SEL1_MASK8] = CHx_PA_SEL1_MASK8;

	wndId2Enum[chkCHx_PD_INT_SEL0] = CHx_PD_INT_SEL0;
	wndId2Enum[chkCHx_PD_INT_SEL1] = CHx_PD_INT_SEL1;
	wndId2Enum[chkCHx_LNA_INT_SEL0] = CHx_LNA_INT_SEL0;
	wndId2Enum[chkCHx_LNA_INT_SEL1] = CHx_LNA_INT_SEL1;
	wndId2Enum[chkCHx_PA_INT_SEL0] = CHx_PA_INT_SEL0;
	wndId2Enum[chkCHx_PA_INT_SEL1] = CHx_PA_INT_SEL1;

    LMS8001_WXGUI::UpdateTooltips(wndId2Enum, true);

//	bmpChannel.LoadFile("./Channel_small.bmp", wxBITMAP_TYPE_BMP);
//	bmpChannel.LoadFile("./Channel.bmp", wxBITMAP_TYPE_BMP);

//	wxBitmap splashBitmap = wxBITMAP_PNG_FROM_DATA(Channel);
	bmpChannel = wxBITMAP_PNG_FROM_DATA(Channel);
//	imgLogo->SetBitmap(splashBitmap);
}

void lms8001_pnlChannel_view::Initialize(LMS8001* pControl)
{
    lmsControl = pControl;
    assert(lmsControl != nullptr);
}

void lms8001_pnlChannel_view::ParameterChangeHandler(wxCommandEvent& event)
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

void lms8001_pnlChannel_view::UpdateGUI()
{
    LMS8001_WXGUI::UpdateControlsByMap(this, lmsControl, wndId2Enum);
}

void lms8001_pnlChannel_view::OnClick_chkCHx_PA_PD0(wxCommandEvent& event)
{
	bool pa_pd = chkCHx_PA_PD0->GetValue();
	bool pa_bypass = chkCHx_PA_BYPASS0->GetValue();

	if (!pa_pd && pa_bypass) {
		wxString str;
		str = wxString::Format("It is not allowed to have Power Amplifier enabled and bypassed at the same time!");
		wxMessageBox(str, "ERROR!");
		chkCHx_PA_PD0->SetValue(true);
	} else
		ParameterChangeHandler(event);
}

void lms8001_pnlChannel_view::OnClick_chkCHx_PA_BYPASS0(wxCommandEvent& event)
{
	bool pa_pd = chkCHx_PA_PD0->GetValue();
	bool pa_bypass = chkCHx_PA_BYPASS0->GetValue();

	if (!pa_pd && pa_bypass) {
		wxString str;
		str = wxString::Format("It is not allowed to have Power Amplifier enabled and bypassed at the same time!");
		wxMessageBox(str, "ERROR!");
		chkCHx_PA_BYPASS0->SetValue(false);
	}
	else
		ParameterChangeHandler(event);
}

void lms8001_pnlChannel_view::OnEraseBackground_pnlChannel(wxEraseEvent& event)
{
//	wxDC * TheDC = event.GetDC();
//	wxColour BGColor = GetBackgroundColour();
//	wxBrush MyBrush(BGColor, wxSOLID);
//	TheDC->SetBackground(MyBrush);


	wxDC* dc = event.GetDC();
	wxCoord width, height;
	dc->GetSize(&width, &height);
	wxCoord x, y, w, h;

//		dc = wx->ClientDC(this);
//	wxRect rect = this->GetUpdateRegion().GetBox();

	dc->SetClippingRegion(0, 0, width, height);
	dc->Clear();

//	wxBitmap* bmp = wx.Bitmap("butterfly.jpg");
//	dc->DrawBitmap(bmp, 0, 0);

//	dc->DrawBitmap(wxBitmap("Channel_small.bmp"), 0, 0);
	dc->DrawBitmap(bmpChannel, 0, 0);

//	dc->DrawBitmap(bmpChannel, 0, 0);

//		wxCoord width, height;
//		TheDC->GetSize(&width, &height);
//		wxCoord x, y, w, h;


//		TheDC->SetClippingRegion(0, 0, width, height);
//		TheDC->GetClippingBox(&x, &y, &w, &h);
//		bmp = wx.Bitmap("butterfly.jpg");
//		dc.DrawBitmap(bmp, 0, 0);
//	}
}