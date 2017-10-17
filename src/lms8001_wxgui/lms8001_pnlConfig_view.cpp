#include "lms8001_wxgui.h"
#include "lms8001_pnlConfig_view.h"
#include "LMS8001.h"
#include <map>
#include "lms8001_gui_utilities.h"
#include <iostream>
#include <wx/event.h>

#include <chrono>
#include <thread>

//#include "../utilities_gui/dlgTempCalibrate.h"
#include "dlgTempCalibrate.h"

lms8001_pnlConfig_view::lms8001_pnlConfig_view( wxWindow* parent ):pnlConfig_view( parent )
{
}

lms8001_pnlConfig_view::lms8001_pnlConfig_view( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
    : pnlConfig_view(parent, id, pos, size, style), lmsControl(nullptr)
{
	tempCalibrate = nullptr;

    //ids for updating from chip
    wndId2Enum[rgrSPI_SDIO_DS] = SPI_SDIO_DS;
	wndId2Enum[rgrSPI_SDO_DS] = SPI_SDO_DS;
	wndId2Enum[chkSPI_SDIO_PE] = SPI_SDIO_PE;
	wndId2Enum[chkSPI_SDO_PE] = SPI_SDO_PE;
	wndId2Enum[chkSPI_SCLK_PE] = SPI_SCLK_PE;
	wndId2Enum[chkSPI_SEN_PE] = SPI_SEN_PE;
	wndId2Enum[rgrSPIMODE] = SPIMODE;
	wndId2Enum[chkGPIO_OUT_SPI_0] = GPIO_OUT_SPI_0;
	wndId2Enum[chkGPIO_OUT_SPI_1] = GPIO_OUT_SPI_1;
	wndId2Enum[chkGPIO_OUT_SPI_2] = GPIO_OUT_SPI_2;
	wndId2Enum[chkGPIO_OUT_SPI_3] = GPIO_OUT_SPI_3;
	wndId2Enum[chkGPIO_OUT_SPI_4] = GPIO_OUT_SPI_4;
	wndId2Enum[chkGPIO_OUT_SPI_5] = GPIO_OUT_SPI_5;
	wndId2Enum[chkGPIO_OUT_SPI_6] = GPIO_OUT_SPI_6;
	wndId2Enum[chkGPIO_OUT_SPI_7] = GPIO_OUT_SPI_7;
	wndId2Enum[chkGPIO_OUT_SPI_8] = GPIO_OUT_SPI_8;
	wndId2Enum[cmbGPIO0_SEL] = GPIO0_SEL;
	wndId2Enum[cmbGPIO1_SEL] = GPIO1_SEL;
	wndId2Enum[cmbGPIO2_SEL] = GPIO2_SEL;
	wndId2Enum[cmbGPIO3_SEL] = GPIO3_SEL;
	wndId2Enum[cmbGPIO4_SEL] = GPIO4_SEL;
	wndId2Enum[cmbGPIO5_SEL] = GPIO5_SEL;
	wndId2Enum[cmbGPIO6_SEL] = GPIO6_SEL;
	wndId2Enum[cmbGPIO7_SEL] = GPIO7_SEL;
	wndId2Enum[cmbGPIO8_SEL] = GPIO8_SEL;
	wndId2Enum[chkGPIO_IN_0] = GPIO_IN_0;
	wndId2Enum[chkGPIO_IN_1] = GPIO_IN_1;
	wndId2Enum[chkGPIO_IN_2] = GPIO_IN_2;
	wndId2Enum[chkGPIO_IN_3] = GPIO_IN_3;
	wndId2Enum[chkGPIO_IN_4] = GPIO_IN_4;
	wndId2Enum[chkGPIO_IN_5] = GPIO_IN_5;
	wndId2Enum[chkGPIO_IN_6] = GPIO_IN_6;
	wndId2Enum[chkGPIO_IN_7] = GPIO_IN_7;
	wndId2Enum[chkGPIO_IN_8] = GPIO_IN_8;
	wndId2Enum[chkGPIO_PE_0] = GPIO_PE_0;
	wndId2Enum[chkGPIO_PE_1] = GPIO_PE_1;
	wndId2Enum[chkGPIO_PE_2] = GPIO_PE_2;
	wndId2Enum[chkGPIO_PE_3] = GPIO_PE_3;
	wndId2Enum[chkGPIO_PE_4] = GPIO_PE_4;
	wndId2Enum[chkGPIO_PE_5] = GPIO_PE_5;
	wndId2Enum[chkGPIO_PE_6] = GPIO_PE_6;
	wndId2Enum[chkGPIO_PE_7] = GPIO_PE_7;
	wndId2Enum[chkGPIO_PE_8] = GPIO_PE_8;
	wndId2Enum[chkGPIO_DS_0] = GPIO_DS_0;
	wndId2Enum[chkGPIO_DS_1] = GPIO_DS_1;
	wndId2Enum[chkGPIO_DS_2] = GPIO_DS_2;
	wndId2Enum[chkGPIO_DS_3] = GPIO_DS_3;
	wndId2Enum[chkGPIO_DS_4] = GPIO_DS_4;
	wndId2Enum[chkGPIO_DS_5] = GPIO_DS_5;
	wndId2Enum[chkGPIO_DS_6] = GPIO_DS_6;
	wndId2Enum[chkGPIO_DS_7] = GPIO_DS_7;
	wndId2Enum[chkGPIO_DS_8] = GPIO_DS_8;
	wndId2Enum[chkGPIO_InO_0] = GPIO_InO_0;
	wndId2Enum[chkGPIO_InO_1] = GPIO_InO_1;
	wndId2Enum[chkGPIO_InO_2] = GPIO_InO_2;
	wndId2Enum[chkGPIO_InO_3] = GPIO_InO_3;
	wndId2Enum[chkGPIO_InO_4] = GPIO_InO_4;
	wndId2Enum[chkGPIO_InO_5] = GPIO_InO_5;
	wndId2Enum[chkGPIO_InO_6] = GPIO_InO_6;
	wndId2Enum[chkGPIO_InO_7] = GPIO_InO_7;
	wndId2Enum[chkGPIO_InO_8] = GPIO_InO_8;
	wndId2Enum[chkTEMP_SENS_EN] = TEMP_SENS_EN;
	wndId2Enum[chkTEMP_SENS_CLKEN] = TEMP_SENS_CLKEN;
	wndId2Enum[chkTEMP_START_CONV] = TEMP_START_CONV;
	wndId2Enum[sttxtTEMP_READ] = TEMP_READ;
//	wndId2Enum[txtVER] = VER;
//	wndId2Enum[txtREV] = REV;
//	wndId2Enum[txtMASK] = MASK;

	wndId2Enum[sttxtVER] = VER;
	wndId2Enum[sttxtREV] = REV;
	wndId2Enum[sttxtMASK] = MASK;

    LMS8001_WXGUI::UpdateTooltips(wndId2Enum, true);
}

void lms8001_pnlConfig_view::Initialize(LMS8001* pControl)
{
    lmsControl = pControl;
    assert(lmsControl != nullptr);
}
//msavic ???
/*
void lms8001_pnlConfig_view::ParameterChangeHandler(wxSpinEvent& event)
{

    wxCommandEvent evt;
    evt.SetInt(event.GetInt());
    evt.SetId(event.GetId());
    evt.SetEventObject(event.GetEventObject());
    ParameterChangeHandler(evt);
}
*/

void lms8001_pnlConfig_view::ParameterChangeHandler(wxCommandEvent& event)
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

void lms8001_pnlConfig_view::UpdateGUI()
{
    LMS8001_WXGUI::UpdateControlsByMap(this, lmsControl, wndId2Enum);
}

void lms8001_pnlConfig_view::OnClick_btnTempRead(wxCommandEvent& event)
{
	int enable, clock_enable, pll_xbuf_en;

	enable = lmsControl->Get_SPI_Reg_bits(TEMP_SENS_EN, true);
	clock_enable = lmsControl->Get_SPI_Reg_bits(TEMP_SENS_CLKEN, true);
	pll_xbuf_en = lmsControl->Get_SPI_Reg_bits(PLL_XBUF_EN, true);

	if (!enable) lmsControl->Modify_SPI_Reg_bits(TEMP_SENS_EN, 1);
	if (!clock_enable) lmsControl->Modify_SPI_Reg_bits(TEMP_SENS_CLKEN, 1);
	if (!pll_xbuf_en) lmsControl->Modify_SPI_Reg_bits(PLL_XBUF_EN, 1);

	lmsControl->Modify_SPI_Reg_bits(TEMP_START_CONV, 1);

	//  Wait - 5ms?
	std::this_thread::sleep_for(std::chrono::milliseconds(5));

	if (!enable) lmsControl->Modify_SPI_Reg_bits(TEMP_SENS_EN, 0);
	if (!clock_enable) lmsControl->Modify_SPI_Reg_bits(TEMP_SENS_CLKEN, 0);
	if (!pll_xbuf_en) lmsControl->Modify_SPI_Reg_bits(PLL_XBUF_EN, 0);

	int value = lmsControl->Get_SPI_Reg_bits(TEMP_READ, true);

	sttxtTEMP_READ->SetLabelText(wxString::Format(_("%d"), value));
}

void lms8001_pnlConfig_view::OnUpdateUI_sttxtTemp(wxUpdateUIEvent& event)
{
	long code;
	sttxtTEMP_READ->GetLabel().ToLong(&code);
	double temperature;
	double tempSens_T1 = TEMPSENS_T1;
	double tempSens_T2 = TEMPSENS_T2;

	temperature = lmsControl->tempSens_T0 + tempSens_T1*code + tempSens_T2*pow(code, 2);

	wxString newValue = wxString::Format(_("%.1f"), temperature);
	wxString oldValue = sttxtTemp->GetLabelText();

	if(oldValue != newValue)
		sttxtTemp->SetLabelText(newValue);
}

void lms8001_pnlConfig_view::OnClick_btnTempCalibrate(wxCommandEvent& event)
{
	if (tempCalibrate) //it's already opened
		tempCalibrate->Show();
	else
	{
		tempCalibrate = new dlgTempCalibrate(this, wxNewId(), _("Temp. Calibrate"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE);
		tempCalibrate->Initialize(lmsControl);
		tempCalibrate->Show();
	}
}