#include "SPI_wxgui.h"
#include "lmsComms.h"
#include <sstream>
#include <iostream>

#include "../lms8suiteAppFrame.h"
#include "lms8001_mainPanel.h"

SPI_wxgui::SPI_wxgui(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long styles)
:
SPI_view( parent )
{
    ctrPort = nullptr;
//    dataPort = nullptr;
}

/*
void SPI_wxgui::Initialize(LMScomms* pCtrPort, LMScomms* pDataPort)
{
    ctrPort = pCtrPort;
    dataPort = pDataPort;
    assert(ctrPort != nullptr);
    assert(dataPort != nullptr);
}
*/
/*
void SPI_wxgui::Initialize(LMScomms* pCtrPort)
{
	ctrPort = pCtrPort;
//	dataPort = pDataPort;
	assert(ctrPort != nullptr);
//	assert(dataPort != nullptr);
}
*/
void SPI_wxgui::Initialize(LMScomms* pCtrPort, LMS8001* pControl)
{
	ctrPort = pCtrPort;
	//	dataPort = pDataPort;
	assert(ctrPort != nullptr);
	//	assert(dataPort != nullptr);
	lmsControl = pControl;
}

void SPI_wxgui::onLMSwrite( wxCommandEvent& event )
{
    wxString address = txtLMSwriteAddr->GetValue();
    long addr = 0;
    address.ToLong(&addr, 16);
    wxString value = txtLMSwriteValue->GetValue();
    long data = 0;
    value.ToLong(&data, 16);

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_WR;
    pkt.outBuffer.push_back((addr >> 8) & 0xFF);
    pkt.outBuffer.push_back(addr & 0xFF);
    pkt.outBuffer.push_back((data >> 8) & 0xFF);
    pkt.outBuffer.push_back(data & 0xFF);

    assert(ctrPort != nullptr);
    if (ctrPort == nullptr)
        return;
    LMScomms::TransferStatus status = ctrPort->TransferPacket(pkt);

    if (status == LMScomms::TRANSFER_SUCCESS)
        lblLMSwriteStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
    else
        lblLMSwriteStatus->SetLabel(_("Write failed"));
}

void SPI_wxgui::onLMSread( wxCommandEvent& event )
{
    wxString address = txtLMSreadAddr->GetValue();
    long addr = 0;
    address.ToLong(&addr, 16);

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_RD;
    pkt.outBuffer.push_back((addr >> 8) & 0xFF);
    pkt.outBuffer.push_back(addr & 0xFF);
    assert(ctrPort != nullptr);
    if (ctrPort == nullptr)
        return;
    LMScomms::TransferStatus status = ctrPort->TransferPacket(pkt);

    if (status == LMScomms::TRANSFER_SUCCESS)
    {
        lblLMSreadStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
        unsigned short value = (pkt.inBuffer[2] * 256) | pkt.inBuffer[3];
		unsigned short value2 = (pkt.inBuffer[6] * 256) | pkt.inBuffer[7];
//        lblLMSreadValue->SetLabel(wxString::Format(_("0x%04X"), value));
        lblLMSreadValue->SetLabel(wxString::Format(_("0x%04X 0x%04X"), value, value2));
    }
    else
        lblLMSreadStatus->SetLabel(_("Read failed"));
}

void SPI_wxgui::onSPIstep(wxCommandEvent& event)
{
	wxString wxText, wxText_log;
//	txtMessageField->Clear();
//	txtMessageField->AppendText(text);

	std::string line;
	std::string tmp;
	std::string text;
	std::string text_log;
	std::string new_text = "";

	int icmd = 0;

	wxText = txtSPIfield->GetValue();
	text = wxText.ToStdString();

	std::istringstream iss(text);
//	std::istringstream new_iss();

	std::getline(iss, line);
	while (std::getline(iss, tmp)) {
		new_text += tmp;
		new_text += "\n";
	}

	txtSPIfield->Clear();
	txtSPIfield->AppendText(new_text);

	int iaddress, idata;
	char cmd[200];
	char field[200];
	char comment[200] = "";

	int tokens;
//	tokens = sscanf(line.c_str(), "%s %X %X", cmd, &iaddress, &idata);
//	tokens = sscanf(line.c_str(), "%s %s %X", cmd, field, &idata);
	tokens = sscanf(line.c_str(), "%s %s %i", cmd, field, &idata);

	if ((strcmp(cmd, "WR") == 0) && (tokens == 3))
		icmd = 1;

	if ((strcmp(cmd, "RD") == 0) && (tokens == 2))
		icmd = 2;

	if (icmd == 0)
		sprintf(comment, "Syntax error");

	int paramFound = 0;
	LMS8Parameter parameter = lmsControl->findLMS8Param(field);

	if (strcmp(parameter.name, "NOT_FOUND") != 0)
	{
//		sprintf(comment, "Field %s found; Address = 0x%04X\n", parameter.name, parameter.address);
		sprintf(comment, "Field %s found\n", parameter.name);
		iaddress = parameter.address;
		paramFound = 1;
	}
	else {
//		int tmp = sprintf(field, "%X", iaddress);
		int tmp = sscanf(field, "%i", &iaddress);
		if (tmp == 0) icmd = 0;
	}

//	long addr = 0;
//	long data = 0;
	uint16_t addr = 0;
	uint16_t data = 0;
	LMScomms::GenericPacket pkt;
//	LMScomms::TransferStatus status;
	liblms8_status status;

	addr = iaddress;
	data = idata;

	if (icmd == 1) //WRITE
	{
		if (paramFound)
			status = lmsControl->Modify_SPI_Reg_bits(parameter, data);
		else
			status = lmsControl->Modify_SPI_Reg_bits(addr, 15, 0, data);

		if (status == LIBLMS8_SUCCESS)
		{
//			sprintf(comment, "%s%s", comment, status2string(pkt.status));
			sprintf(comment, "%s%s", comment, liblms8_status2string(status));
		}
		else
			sprintf(comment, "%sWrite failed", comment);

		//msavic - Update the visible panel
		// Probably not the best way to do it, but it works so far!
		AppFrame_view* appFrame = (AppFrame_view*)GetParent();
//msavic ovdi!
		appFrame->mContent->UpdateVisiblePanel();

//		lms8001_mainPanel* mainPanel = (lms8001_mainPanel*)GetParent();
//		mainPanel->UpdateVisiblePanel();

/*
		pkt.cmd = CMD_LMS8001_WR;
		pkt.outBuffer.push_back((addr >> 8) & 0xFF);
		pkt.outBuffer.push_back(addr & 0xFF);
		pkt.outBuffer.push_back((data >> 8) & 0xFF);
		pkt.outBuffer.push_back(data & 0xFF);

		assert(ctrPort != nullptr);
		if (ctrPort == nullptr)
			return;
		status = ctrPort->TransferPacket(pkt);

		if (status == LMScomms::TRANSFER_SUCCESS) {
			sprintf(comment, "%s%s", comment, status2string(pkt.status));
			//Change the 
			lmsControl->Modify_SPI_Reg_bits((uint16_t)addr, 15, 0, (uint16_t)data);
		}
		else {
			sprintf(comment, "%sWrite failed", comment);
			//msavic - DELETE THIS, TEMP !!!
//			lmsControl->Modify_SPI_Reg_bits((uint16_t)addr, 15, 0, (uint16_t)data);
		}
*/
	}

	if (icmd == 2) //READ
	{
		

		if (paramFound)
			data = lmsControl->Get_SPI_Reg_bits(parameter, true, 0, 0, &status);
		else
			data = lmsControl->Get_SPI_Reg_bits(addr, 15, 0, true, &status);

		if (status == LIBLMS8_SUCCESS)
		{
			//			sprintf(comment, "%s%s", comment, status2string(pkt.status));
			sprintf(comment, "%s%s", comment, liblms8_status2string(status));
		}
		else
			sprintf(comment, "%sRead failed", comment);

		sprintf(comment, "%s\tValue = 0x%04X", comment, data);

/*
		addr = iaddress;

		pkt.cmd = CMD_LMS8001_RD;
		pkt.outBuffer.push_back((addr >> 8) & 0xFF);
		pkt.outBuffer.push_back(addr & 0xFF);
		assert(ctrPort != nullptr);
		if (ctrPort == nullptr)
			return;
		status = ctrPort->TransferPacket(pkt);

		if (status == LMScomms::TRANSFER_SUCCESS)
		{
//			lblLMSreadStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
			unsigned short value = (pkt.inBuffer[2] * 256) | pkt.inBuffer[3];
//			lblLMSreadValue->SetLabel(wxString::Format(_("0x%04X"), value));
			sprintf(comment, "%s\tValue: 0x%04X", status2string(pkt.status), value);
		}
		else
			sprintf(comment, "Read failed");
*/
	}

	wxText_log = txtSPIfield_log->GetValue();
	text_log = wxText_log.ToStdString();

	text_log += line;
	text_log += "\n";
	text_log += comment;
	text_log += "\n";
	txtSPIfield_log->Clear();
	txtSPIfield_log->AppendText(text_log);
}

void SPI_wxgui::onClear(wxCommandEvent& event)
{
	txtSPIfield->Clear();
	txtSPIfield_log->Clear();
}

/*
void SPI_wxgui::onBoardWrite( wxCommandEvent& event )
{
    wxString address = txtBoardwriteAddr->GetValue();
    long addr = 0;
    address.ToLong(&addr, 16);
    wxString value = txtBoardwriteValue->GetValue();
    long data = 0;
    value.ToLong(&data, 16);

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_BRDSPI_WR;
    pkt.outBuffer.push_back((addr >> 8) & 0xFF);
    pkt.outBuffer.push_back(addr & 0xFF);
    pkt.outBuffer.push_back((data >> 8) & 0xFF);
    pkt.outBuffer.push_back(data & 0xFF);

    assert(dataPort != nullptr);
    if (dataPort == nullptr)
        return;
    LMScomms::TransferStatus status = dataPort->TransferPacket(pkt);

    if (status == LMScomms::TRANSFER_SUCCESS)
        lblBoardwriteStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
    else
        lblBoardwriteStatus->SetLabel(_("Write failed"));
}
*/
/*
void SPI_wxgui::OnBoardRead( wxCommandEvent& event )
{
    wxString address = txtBoardreadAddr->GetValue();
    long addr = 0;
    address.ToLong(&addr, 16);

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_BRDSPI_RD;
    pkt.outBuffer.push_back((addr >> 8) & 0xFF);
    pkt.outBuffer.push_back(addr & 0xFF);
    assert(dataPort != nullptr);
    if (dataPort == nullptr)
        return;
    LMScomms::TransferStatus status = dataPort->TransferPacket(pkt);

    if (status == LMScomms::TRANSFER_SUCCESS)
    {
        lblBoardreadStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
        unsigned short value = (pkt.inBuffer[2] * 256) | pkt.inBuffer[3];
        lblBoardreadValue->SetLabel(wxString::Format(_("0x%04X"), value));
    }
    else
        lblBoardreadStatus->SetLabel(_("Read failed"));
}
*/
