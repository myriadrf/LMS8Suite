#include "dlgTempCalibrate.h"
#include "lmsComms.h"

dlgTempCalibrate::dlgTempCalibrate(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long styles)
:
dlgTempCalibrate_view( parent, id, title, pos, size, styles)
{

}

void dlgTempCalibrate::Initialize(LMS8001* pControl)
{
	lmsControl = pControl;

	double tempSens_T0 = lmsControl->tempSens_T0;
	sttxtT0->SetLabel(wxString::Format(_("%.2f"), tempSens_T0));
}

void dlgTempCalibrate::OnClick_btnCalibrate(wxCommandEvent& event)
{
	double code;
	txtValue->GetValue().ToDouble(&code);
	double temperature;
	txtTemperature->GetValue().ToDouble(&temperature);

	double tempSens_T1 = TEMPSENS_T1;
	double tempSens_T2 = TEMPSENS_T2;
	double tempSens_T0;

	tempSens_T0 = temperature - tempSens_T1*code - tempSens_T2*pow(code, 2);

	lmsControl->tempSens_T0 = tempSens_T0;
	sttxtT0->SetLabel(wxString::Format(_("%.2f"), tempSens_T0));
}

void dlgTempCalibrate::OnClick_btnReset(wxCommandEvent& event)
{
	double tempSens_T0 = TEMPSENS_T0;
	lmsControl->tempSens_T0 = tempSens_T0;
	sttxtT0->SetLabel(wxString::Format(_("%.2f"), tempSens_T0));
}