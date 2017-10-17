#include "lms8001_pnlLDO_view.h"
#include "LMS8001.h"
#include <map>
#include <iostream>
#include "lms8001_gui_utilities.h"

lms8001_pnlLDO_view::lms8001_pnlLDO_view( wxWindow* parent )
:
pnlLDO_view( parent )
{

}

lms8001_pnlLDO_view::lms8001_pnlLDO_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
    : pnlLDO_view(parent, id, pos, size, style), lmsControl(nullptr)
{
	wndId2Enum[chkPD_CALIB_COMP] = PD_CALIB_COMP;
	wndId2Enum[chkRP_CALIB_COMP] = RP_CALIB_COMP;
//msavic: I had problems with wxSpinCtrl, it was not invoking handler for wxEVT_COMMAND_SPINCTRL_UPDATED, so I also added handlers for wxEVT_COMMAND_TEXT_UPDATED and wxEVT_COMMAND_TEXT_ENTER
	wndId2Enum[cmbRP_CALIB_BIAS] = RP_CALIB_BIAS;
	wndId2Enum[chkPD_FRP_BIAS] = PD_FRP_BIAS;
	wndId2Enum[chkPD_F_BIAS] = PD_F_BIAS;
	wndId2Enum[chkPD_PTRP_BIAS] = PD_PTRP_BIAS;
	wndId2Enum[chkPD_PT_BIAS] = PD_PT_BIAS;
	wndId2Enum[chkPD_BIAS] = PD_BIAS;
	
    wndId2Enum[chkEN_LDO_LOBUFA] = EN_LDO_LOBUFA;
	wndId2Enum[chkEN_LDO_LOBUFB] = EN_LDO_LOBUFB;
	wndId2Enum[chkEN_LDO_LOBUFC] = EN_LDO_LOBUFC;
	wndId2Enum[chkEN_LDO_LOBUFD] = EN_LDO_LOBUFD;

	wndId2Enum[chkEN_LDO_HFLNAA] = EN_LDO_HFLNAA;
	wndId2Enum[chkEN_LDO_HFLNAB] = EN_LDO_HFLNAB;
	wndId2Enum[chkEN_LDO_HFLNAC] = EN_LDO_HFLNAC;
	wndId2Enum[chkEN_LDO_HFLNAD] = EN_LDO_HFLNAD;

	wndId2Enum[chkEN_LDO_CLK_BUF] = EN_LDO_CLK_BUF;
	wndId2Enum[chkEN_LDO_PLL_DIV] = EN_LDO_PLL_DIV;
	wndId2Enum[chkEN_LDO_PLL_CP] = EN_LDO_PLL_CP;
	wndId2Enum[chkPD_LDO_DIG_CORE] = PD_LDO_DIG_CORE;
	
	wndId2Enum[chkSPDUP_LDO_LOBUFA] = SPDUP_LDO_LOBUFA;
	wndId2Enum[chkSPDUP_LDO_LOBUFB] = SPDUP_LDO_LOBUFB;
	wndId2Enum[chkSPDUP_LDO_LOBUFC] = SPDUP_LDO_LOBUFC;
	wndId2Enum[chkSPDUP_LDO_LOBUFD] = SPDUP_LDO_LOBUFD;

	wndId2Enum[chkSPDUP_LDO_HFLNAA] = SPDUP_LDO_HFLNAA;
	wndId2Enum[chkSPDUP_LDO_HFLNAB] = SPDUP_LDO_HFLNAB;
	wndId2Enum[chkSPDUP_LDO_HFLNAC] = SPDUP_LDO_HFLNAC;
	wndId2Enum[chkSPDUP_LDO_HFLNAD] = SPDUP_LDO_HFLNAD;

	wndId2Enum[chkSPDUP_LDO_CLK_BUF] = SPDUP_LDO_CLK_BUF;
	wndId2Enum[chkSPDUP_LDO_PLL_DIV] = SPDUP_LDO_PLL_DIV;
	wndId2Enum[chkSPDUP_LDO_PLL_CP] = SPDUP_LDO_PLL_CP;
	wndId2Enum[chkSPDUP_LDO_DIG_CORE] = SPDUP_LDO_DIG_CORE;

	wndId2Enum[chkEN_LOADIMP_LDO_LOBUFA] = EN_LOADIMP_LDO_LOBUFA;
	wndId2Enum[chkEN_LOADIMP_LDO_LOBUFB] = EN_LOADIMP_LDO_LOBUFB;
	wndId2Enum[chkEN_LOADIMP_LDO_LOBUFC] = EN_LOADIMP_LDO_LOBUFC;
	wndId2Enum[chkEN_LOADIMP_LDO_LOBUFD] = EN_LOADIMP_LDO_LOBUFD;

	wndId2Enum[chkEN_LOADIMP_LDO_HFLNAA] = EN_LOADIMP_LDO_HFLNAA;
	wndId2Enum[chkEN_LOADIMP_LDO_HFLNAB] = EN_LOADIMP_LDO_HFLNAB;
	wndId2Enum[chkEN_LOADIMP_LDO_HFLNAC] = EN_LOADIMP_LDO_HFLNAC;
	wndId2Enum[chkEN_LOADIMP_LDO_HFLNAD] = EN_LOADIMP_LDO_HFLNAD;

	wndId2Enum[chkEN_LOADIMP_LDO_CLK_BUF] = EN_LOADIMP_LDO_CLK_BUF;
	wndId2Enum[chkEN_LOADIMP_LDO_PLL_DIV] = EN_LOADIMP_LDO_PLL_DIV;
	wndId2Enum[chkEN_LOADIMP_LDO_PLL_CP] = EN_LOADIMP_LDO_PLL_CP;
	wndId2Enum[chkEN_LOADIMP_LDO_DIG_CORE] = EN_LOADIMP_LDO_DIG_CORE;

	wndId2Enum[cmbRDIV_LOBUFA] = RDIV_LOBUFA;
	wndId2Enum[cmbRDIV_LOBUFB] = RDIV_LOBUFB;
	wndId2Enum[cmbRDIV_LOBUFC] = RDIV_LOBUFC;
	wndId2Enum[cmbRDIV_LOBUFD] = RDIV_LOBUFD;
	
	wndId2Enum[cmbRDIV_HFLNAA] = RDIV_HFLNAA;
	wndId2Enum[cmbRDIV_HFLNAB] = RDIV_HFLNAB;
	wndId2Enum[cmbRDIV_HFLNAC] = RDIV_HFLNAC;
	wndId2Enum[cmbRDIV_HFLNAD] = RDIV_HFLNAD;

	wndId2Enum[cmbRDIV_CLK_BUF] = RDIV_CLK_BUF;
	wndId2Enum[cmbRDIV_PLL_DIV] = RDIV_PLL_DIV;
	wndId2Enum[cmbRDIV_PLL_CP] = RDIV_PLL_CP;
	wndId2Enum[cmbRDIV_DIG_CORE] = RDIV_DIG_CORE;

    wxArrayString temp;
    temp.clear();
    for (int i = 0; i<256; ++i)
    {
        temp.push_back(wxString::Format(_("%.3f V"), (860.0 + 3.92*i) / 1000.0));
    }
    cmbRDIV_LOBUFA->Append(temp);
	cmbRDIV_LOBUFB->Append(temp);
	cmbRDIV_LOBUFC->Append(temp);
	cmbRDIV_LOBUFD->Append(temp);

	cmbRDIV_HFLNAA->Append(temp);
	cmbRDIV_HFLNAB->Append(temp);
	cmbRDIV_HFLNAC->Append(temp);
	cmbRDIV_HFLNAD->Append(temp);

	cmbRDIV_CLK_BUF->Append(temp);
	cmbRDIV_PLL_DIV->Append(temp);
	cmbRDIV_PLL_CP->Append(temp);
	cmbRDIV_DIG_CORE->Append(temp);

    LMS8001_WXGUI::UpdateTooltips(wndId2Enum, true);
}

void lms8001_pnlLDO_view::Initialize(LMS8001* pControl)
{
    lmsControl = pControl;
    assert(lmsControl != nullptr);
}

void lms8001_pnlLDO_view::ParameterChangeHandler(wxCommandEvent& event)
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
    lmsControl->Modify_SPI_Reg_bits(parameter, event.GetInt());
}

void lms8001_pnlLDO_view::UpdateGUI()
{
    LMS8001_WXGUI::UpdateControlsByMap(this, lmsControl, wndId2Enum);
}
