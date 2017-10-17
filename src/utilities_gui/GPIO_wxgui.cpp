#include "GPIO_wxgui.h"
#include "lmsComms.h"

static unsigned char setbit(const unsigned char src, const int pos, const bool value)
{
	int val = src;
	val = val & ~(0x1 << pos);
	val |= value << pos;
	return val;
}
static bool getbit(const unsigned char src, const int pos)
{
	return (src >> pos) & 0x01;
}

GPIO_wxgui::GPIO_wxgui(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long styles)
:
GPIO_view( parent )
{
    ctrPort = nullptr;
//    dataPort = nullptr;
}

/*
void GPIO_wxgui::Initialize(LMScomms* pCtrPort, LMScomms* pDataPort)
{
    ctrPort = pCtrPort;
//    dataPort = pDataPort;
    assert(ctrPort != nullptr);
//    assert(dataPort != nullptr);
}
*/

void GPIO_wxgui::Initialize(LMScomms* pCtrPort)
{
	ctrPort = pCtrPort;
	//    dataPort = pDataPort;
	assert(ctrPort != nullptr);
	//    assert(dataPort != nullptr);
}

void GPIO_wxgui::OnUpdateClick ( wxCommandEvent& event )
{
/*
	//	CMD_GPIO_STP
//	***********************
//	Data:
//	0 - GPIO03_DIR
//	1 - GPIO47_DIR
//	************************
	uint16_t value = 0;
	value = setbit(value, 0, rgr_GPIO03_DIR->GetSelection());
	value = setbit(value, 1, rgr_GPIO47_DIR->GetSelection());

	LMScomms::GenericPacket pkt;
	pkt.cmd = CMD_GPIO_STP;
	pkt.outBuffer.clear();
	pkt.outBuffer.push_back(value);

	assert(ctrPort != nullptr);
	if (ctrPort == nullptr)
		return;
	LMScomms::TransferStatus status = ctrPort->TransferPacket(pkt);

	if (status == LMScomms::TRANSFER_SUCCESS)
		lblGPIOstatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
	else {
		lblGPIOstatus->SetLabel(_("Setup failed"));
		return;
	}
*/

	uint8_t GPIO_states[] = {0, 0};
	LMScomms::GenericPacket pkt;
	LMScomms::TransferStatus status;

	//	CMD_GPIO_WR or CMD_GPIO_RD
	/***********************
	Data:
	*** GPIO_states[0] ***
	bit 0 - GPIO0
	bit 1 - GPIO1
	...
	bit 7 - GPIO7
	*** GPIO_states[1] ***
	bit 0 - GPIO8
	bit 1 - GPIO03_DIR
	bit 2 - GPIO47_DIR
	bit 3 - CORE_LDO_EN
	************************/

	/******      WRITE      ******/
	GPIO_states[0] = setbit(GPIO_states[0], 0, chkGPIO0->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 1, chkGPIO1->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 2, chkGPIO2->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 3, chkGPIO3->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 4, chkGPIO4->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 5, chkGPIO5->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 6, chkGPIO6->GetValue());
	GPIO_states[0] = setbit(GPIO_states[0], 7, chkGPIO7->GetValue());

	GPIO_states[1] = setbit(GPIO_states[1], 0, chkGPIO8->GetValue());
	GPIO_states[1] = setbit(GPIO_states[1], 1, rgr_GPIO03_DIR->GetSelection());
	GPIO_states[1] = setbit(GPIO_states[1], 2, rgr_GPIO47_DIR->GetSelection());
	GPIO_states[1] = setbit(GPIO_states[1], 3, chkCORE_LDO_EN->GetValue());

	pkt.cmd = CMD_GPIO_WR;
	pkt.outBuffer.clear();
	pkt.outBuffer.push_back(GPIO_states[0]);
	pkt.outBuffer.push_back(GPIO_states[1]);

	assert(ctrPort != nullptr);
	if (ctrPort == nullptr)
		return;
	status = ctrPort->TransferPacket(pkt);

	if (status == LMScomms::TRANSFER_SUCCESS)
		lblGPIOstatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
	else {
		lblGPIOstatus->SetLabel(_("Write failed"));
		return;
	}

	/******      READ      ******/

	pkt.cmd = CMD_GPIO_RD;
	pkt.outBuffer.clear();

	assert(ctrPort != nullptr);
	if (ctrPort == nullptr)
		return;
	status = ctrPort->TransferPacket(pkt);

	if (status == LMScomms::TRANSFER_SUCCESS)
	{
		lblGPIOstatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
//		unsigned short value = (pkt.inBuffer[2] * 256) | pkt.inBuffer[3];
//		value = (pkt.inBuffer[0] * 256) | pkt.inBuffer[1];
		GPIO_states[0] = pkt.inBuffer[0];
		GPIO_states[1] = pkt.inBuffer[1];
		lblGPIOstatus->SetLabel(wxString::Format(_("Read values: 0x%02X 0x%02X"), GPIO_states[0], GPIO_states[1]));
	}
	else {
		lblGPIOstatus->SetLabel(_("Read failed"));
		return;
	}

	chkGPIO0->SetValue(getbit(GPIO_states[0], 0));
	chkGPIO1->SetValue(getbit(GPIO_states[0], 1));
	chkGPIO2->SetValue(getbit(GPIO_states[0], 2));
	chkGPIO3->SetValue(getbit(GPIO_states[0], 3));
	chkGPIO4->SetValue(getbit(GPIO_states[0], 4));
	chkGPIO5->SetValue(getbit(GPIO_states[0], 5));
	chkGPIO6->SetValue(getbit(GPIO_states[0], 6));
	chkGPIO7->SetValue(getbit(GPIO_states[0], 7));

	chkGPIO8->SetValue(getbit(GPIO_states[1], 0));
	rgr_GPIO03_DIR->SetSelection(getbit(GPIO_states[1], 1));
	rgr_GPIO47_DIR->SetSelection(getbit(GPIO_states[1], 2));
	chkCORE_LDO_EN->SetValue(getbit(GPIO_states[1], 3));
}

void GPIO_wxgui::OnChangeGPIODirection ( wxCommandEvent& event )
{
	wxRadioBox* object  = reinterpret_cast<wxRadioBox*>(event.GetEventObject());
//	wxObject* object = event.GetEventObject();
	bool enable = false;
	if (object == rgr_GPIO03_DIR) {
//	if (object->IsSameAs((const wxObject&)rgr_GPIO03_DIR)) {
//	if (rgr_GPIO03_DIR->GetId() == reinterpret_cast<wxWindow*>(object)) {
//	if (rgr_GPIO03_DIR->GetId() == object->GetId()) {
		enable = (rgr_GPIO03_DIR->GetSelection() == 1);
		chkGPIO0->Enable(enable);
		chkGPIO1->Enable(enable);
		chkGPIO2->Enable(enable);
		chkGPIO3->Enable(enable);
	}
	else {
		enable = (rgr_GPIO47_DIR->GetSelection() == 1);
		chkGPIO4->Enable(enable);
		chkGPIO5->Enable(enable);
		chkGPIO6->Enable(enable);
		chkGPIO7->Enable(enable);
	}
/*
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
*/
}