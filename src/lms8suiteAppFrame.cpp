#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "lms8001_mainPanel.h"

#include "lms8suiteAppFrame.h"
#include "LMS8001.h"
#include "lmsComms.h"
#include "dlgAbout.h"
#include "dlgConnectionSettings.h"
#include "lms8suiteEvents.h"
//#include "LMS_StreamBoard.h"
#include "ADF4002.h"
#include "ADF4002_wxgui.h"
#include "Si5351C.h"
#include "Si5351C_wxgui.h"
//#include "LMS_Programing_wxgui.h"
#include "pnlMiniLog.h"
#include "SPI_wxgui.h"
#include "GPIO_wxgui.h"
#include <wx/string.h>
#include "dlgDeviceInfo.h"
#include <functional>

//#include "lms8001_pnlTRF_view.h"
//#include "lms8001_pnlRFE_view.h"

///////////////////////////////////////////////////////////////////////////

const wxString LMS8SuiteAppFrame::cWindowTitle = _("LMS8Suite");

void LMS8SuiteAppFrame::HandleLMSevent(wxCommandEvent& event)
{
/*
	if (event.GetEventType() == CGEN_FREQUENCY_CHANGED)
	{
		liblms8_status status = lmsControl->SetInterfaceFrequency(lmsControl->GetFrequencyCGEN_MHz(), lmsControl->Get_SPI_Reg_bits(HBI_OVR_TXTSP), lmsControl->Get_SPI_Reg_bits(HBD_OVR_RXTSP));
		if (status == LIBLMS7_SUCCESS)
		{
			wxCommandEvent evt;
			evt.SetEventType(LOG_MESSAGE);
			wxString msg;
			msg += _("Parameters modified: ");
			msg += wxString::Format(_("HBI_OVR: %i "), lmsControl->Get_SPI_Reg_bits(HBI_OVR_TXTSP, false));
			msg += wxString::Format(_("TXTSPCLKA_DIV: %i "), lmsControl->Get_SPI_Reg_bits(TXTSPCLKA_DIV, false));
			msg += wxString::Format(_("TXDIVEN: %i "), lmsControl->Get_SPI_Reg_bits(TXDIVEN, false));
			msg += wxString::Format(_("MCLK1SRC: %i "), lmsControl->Get_SPI_Reg_bits(MCLK1SRC, false));
			msg += wxString::Format(_("HBD_OVR: %i "), lmsControl->Get_SPI_Reg_bits(HBD_OVR_RXTSP, false));
			msg += wxString::Format(_("RXTSPCLKA_DIV: %i "), lmsControl->Get_SPI_Reg_bits(RXTSPCLKA_DIV, false));
			msg += wxString::Format(_("RXDIVEN: %i "), lmsControl->Get_SPI_Reg_bits(RXDIVEN, false));
			msg += wxString::Format(_("MCLK2SRC: %i "), lmsControl->Get_SPI_Reg_bits(MCLK2SRC, false));
			evt.SetString(msg);
			wxPostEvent(this, evt);
		}
		if (streamBoardPort->IsOpen())
		{
			LMS_StreamBoard::Status status = LMS_StreamBoard::ConfigurePLL(streamBoardPort, lmsControl->GetReferenceClk_TSP_MHz(LMS7002M::Tx), lmsControl->GetReferenceClk_TSP_MHz(LMS7002M::Rx), 90);
			if (status != LMS_StreamBoard::SUCCESS)
				wxMessageBox(_("Failed to configure Stream board PLL"), _("Warning"));
			else
			{
				wxCommandEvent evt;
				evt.SetEventType(LOG_MESSAGE);
				evt.SetString(wxString::Format(_("Stream board PLL configured Tx: %.3f MHz Rx: %.3f MHz Angle: %.0f deg"), lmsControl->GetReferenceClk_TSP_MHz(LMS7002M::Tx), lmsControl->GetReferenceClk_TSP_MHz(LMS7002M::Rx), 90.0));
				wxPostEvent(this, evt);
			}
		}
		if (fftviewer)
			fftviewer->SetNyquistFrequency(lmsControl->GetReferenceClk_TSP_MHz(LMS7002M::Rx));
	}

	//in case of Novena board, need to update GPIO
	if (lms7controlPort->GetInfo().device == LMS_DEV_NOVENA &&
		(event.GetEventType() == LMS7_TXBAND_CHANGED || event.GetEventType() == LMS7_RXPATH_CHANGED))
	{
		uint16_t regValue = lmsControl->SPI_read(0x0806) & 0xFFF8;
		//lms_gpio2 - tx output selection:
		//		0 - TX1_A and TX1_B (Band 1),
		//		1 - TX2_A and TX2_B (Band 2)
		regValue |= lmsControl->Get_SPI_Reg_bits(SEL_BAND2_TRF, false) << 2; //gpio2
																			 //RX active paths
																			 //lms_gpio0 | lms_gpio1      	RX_A		RX_B
																			 //  0 			0       =>  	no active path
																			 //  1   		0 		=>	LNAW_A  	LNAW_B
																			 //  0			1		=>	LNAH_A  	LNAH_B
																			 //  1			1		=>	LNAL_A 	 	LNAL_B
		switch (lmsControl->Get_SPI_Reg_bits(SEL_PATH_RFE, false))
		{
			//set gpio1:gpio0
		case 0: regValue |= 0x0; break;
		case 1: regValue |= 0x2; break;
		case 2: regValue |= 0x3; break;
		case 3: regValue |= 0x1; break;
		}
		lmsControl->SPI_write(0x0806, regValue);
		if (novenaGui)
			novenaGui->UpdatePanel();
	}

	if (event.GetEventType() == LMS7_TXBAND_CHANGED)
	{
		const wxObject* eventSource = event.GetEventObject();
		const int bandIndex = event.GetInt();
		//update HPM7 if changes were made outside of it
		if (lms7controlPort->GetInfo().expansion == EXP_BOARD_HPM7 && eventSource != hpm7)
			hpm7->SelectBand(bandIndex);
		if (eventSource == hpm7)
		{
			lmsControl->Modify_SPI_Reg_bits(SEL_BAND1_TRF, bandIndex == 0);
			lmsControl->Modify_SPI_Reg_bits(SEL_BAND2_TRF, bandIndex == 1);
			mContent->mTabTRF->UpdateGUI();
		}
	}
	if (event.GetEventType() == LMS7_RXPATH_CHANGED)
	{
		const wxObject* eventSource = event.GetEventObject();
		const int pathIndex = event.GetInt();
		//update HPM7 if changes were made outside of it
		if (lms7controlPort->GetInfo().expansion == EXP_BOARD_HPM7 && eventSource != hpm7)
			hpm7->SelectRxPath(pathIndex);
		if (eventSource == hpm7)
		{
			lmsControl->Modify_SPI_Reg_bits(SEL_PATH_RFE, pathIndex);
			mContent->mTabRFE->UpdateGUI();
		}
	}
*/
}

LMS8SuiteAppFrame::LMS8SuiteAppFrame( wxWindow* parent ) : AppFrame_view( parent )
{
#ifndef __unix__
    SetIcon(wxIcon(_("aaaaAPPicon")));
#endif
//    programmer = nullptr;
//    fftviewer = nullptr;
    adfGUI = nullptr;
    si5351gui = nullptr;
//    rfspark = nullptr;
//    hpm7 = nullptr;
//    fpgaControls = nullptr;
//    myriad7 = nullptr;
    deviceInfo = nullptr;
    spi = nullptr;
	gpio = nullptr;
//    novenaGui = nullptr;

    lms8controlPort = new LMScomms();
//    streamBoardPort = new LMScomms();
    lmsControl = new LMS8001(lms8controlPort);
	mContent->Initialize(lmsControl);
    Connect(CGEN_FREQUENCY_CHANGED, wxCommandEventHandler(LMS8SuiteAppFrame::HandleLMSevent), NULL, this);
//    Connect(LMS8_TXBAND_CHANGED, wxCommandEventHandler(LMS8SuiteAppFrame::HandleLMSevent), NULL, this);
//    Connect(LMS8_RXPATH_CHANGED, wxCommandEventHandler(LMS8SuiteAppFrame::HandleLMSevent), NULL, this);
    mMiniLog = new pnlMiniLog(this, wxNewId());
    Connect(LOG_MESSAGE, wxCommandEventHandler(LMS8SuiteAppFrame::OnLogMessage), 0, this);

    //bind callbacks for spi data logging
    lms8controlPort->SetDataLogCallback(bind(&LMS8SuiteAppFrame::OnLogDataTransfer, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
//    streamBoardPort->SetDataLogCallback(bind(&LMS8SuiteAppFrame::OnLogDataTransfer, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    contentSizer->Add(mMiniLog, 1, wxEXPAND, 5);

    adfModule = new ADF4002();
	//msavic 160530
	adfModule->Initialize(lms8controlPort);

    si5351module = new Si5351C();
    si5351module->Initialize(lms8controlPort);

	Layout();
	Fit();

    SetMinSize(GetSize());

	wxCommandEvent evt;
//	OnDataBoardConnect(evt);
	OnControlBoardConnect(evt);
}

LMS8SuiteAppFrame::~LMS8SuiteAppFrame()
{
    Disconnect(CGEN_FREQUENCY_CHANGED, wxCommandEventHandler(LMS8SuiteAppFrame::HandleLMSevent), NULL, this);
	delete lms8controlPort;
//	delete streamBoardPort;

}

void LMS8SuiteAppFrame::OnClose( wxCloseEvent& event )
{
    Destroy();
}

void LMS8SuiteAppFrame::OnQuit( wxCommandEvent& event )
{
    Destroy();
}

void LMS8SuiteAppFrame::OnShowConnectionSettings(wxCommandEvent& event)
{
	dlgConnectionSettings dlg(this);

//	if (fftviewer)
//		fftviewer->StopStreaming();

//	dlg.SetConnectionManagers(lms8controlPort, streamBoardPort);
	dlg.SetConnectionManager(lms8controlPort);
	Bind(CONTROL_PORT_CONNECTED, wxCommandEventHandler(LMS8SuiteAppFrame::OnControlBoardConnect), this);
//	Bind(DATA_PORT_CONNECTED, wxCommandEventHandler(LMS8SuiteAppFrame::OnDataBoardConnect), this);
	Bind(CONTROL_PORT_DISCONNECTED, wxCommandEventHandler(LMS8SuiteAppFrame::OnControlBoardConnect), this);
//	Bind(DATA_PORT_DISCONNECTED, wxCommandEventHandler(LMS8SuiteAppFrame::OnDataBoardConnect), this);
	dlg.ShowModal();
}

void LMS8SuiteAppFrame::OnAbout( wxCommandEvent& event )
{
	dlgAbout dlg(this);
    dlg.ShowModal();
}


void LMS8SuiteAppFrame::OnControlBoardConnect(wxCommandEvent& event)
{
    const int controlCollumn = 1;
    if (lms8controlPort->IsOpen())
    {
        LMSinfo info = lms8controlPort->GetInfo();
        wxString controlDev = _("Control port: ");
        controlDev.Append(wxString::From8BitData(GetDeviceName(info.device)));
        controlDev.Append(wxString::Format(_(" FW:%i HW:%i Protocol:%i"), (int)info.firmware, (int)info.hardware, (int)info.protocol));
        statusBar->SetStatusText(controlDev, controlCollumn);

        wxCommandEvent evt;
        evt.SetEventType(LOG_MESSAGE);
        evt.SetString(_("Connected ") + controlDev);
        wxPostEvent(this, evt);

//msavic 160530
// Here, the ADF4002 should be set to default state, since it looks like sometimes (?) on the start-up it changes the frequency (???)
//msavic ovdi!!!
		liblms8_status status = adfModule->UploadReset();
		if(status != LIBLMS8_SUCCESS){
			wxCommandEvent evt;
			evt.SetEventType(LOG_MESSAGE);
			evt.SetString(_("Failed to reset ADF4002!"));
			wxPostEvent(this, evt);
		}

//        if (si5351gui)
//            si5351gui->ModifyClocksGUI(info.device);
    }
    else
    {
        statusBar->SetStatusText(_("Control port: Not Connected"), controlCollumn);
        wxCommandEvent evt;
        evt.SetEventType(LOG_MESSAGE);
        evt.SetString(_("Disconnected control port"));
        wxPostEvent(this, evt);
    }

	//msavic 160725
	mContent->UpdateVisiblePanel();
}

/*
void LMS8SuiteAppFrame::OnDataBoardConnect(wxCommandEvent& event)
{
    assert(streamBoardPort != nullptr);
    const int dataCollumn = 2;
    if (streamBoardPort->IsOpen())
    {
        LMSinfo info = streamBoardPort->GetInfo();
        wxString controlDev = _("Data port: ");
        controlDev.Append(wxString::From8BitData(GetDeviceName(info.device)));
        controlDev.Append(wxString::Format(_(" FW:%i HW:%i Protocol:%i"), (int)info.firmware, (int)info.hardware, (int)info.protocol));
        statusBar->SetStatusText(controlDev, dataCollumn);

        wxCommandEvent evt;
        evt.SetEventType(LOG_MESSAGE);
        evt.SetString(_("Connected ") + controlDev);
        wxPostEvent(this, evt);
    }
    else
    {
        statusBar->SetStatusText(_("Data port: Not Connected"), dataCollumn);
        wxCommandEvent evt;
        evt.SetEventType(LOG_MESSAGE);
        evt.SetString(_("Disconnected data port"));
        wxPostEvent(this, evt);
    }
}
*/

void LMS8SuiteAppFrame::OnLogMessage(wxCommandEvent &event)
{
	if (mMiniLog)
		mMiniLog->HandleMessage(event);
}

void LMS8SuiteAppFrame::OnDeviceInfoClose(wxCloseEvent& event)
{
	deviceInfo->Destroy();
	deviceInfo = nullptr;
}

void LMS8SuiteAppFrame::OnShowDeviceInfo(wxCommandEvent& event)
{
	if (deviceInfo) //it's already opened
		deviceInfo->Show();
	else
	{
		deviceInfo = new dlgDeviceInfo(this, wxNewId(), _("Device Info"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE);
//		deviceInfo->Initialize(lms8controlPort, streamBoardPort);
		deviceInfo->Initialize(lms8controlPort);
		deviceInfo->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LMS8SuiteAppFrame::OnDeviceInfoClose), NULL, this);
		deviceInfo->Show();
	}
}

void LMS8SuiteAppFrame::OnSPIClose(wxCloseEvent& event)
{
    spi->Destroy();
    spi = nullptr;
}

void LMS8SuiteAppFrame::OnGPIOClose(wxCloseEvent& event)
{
	gpio->Destroy();
	gpio = nullptr;
}

void LMS8SuiteAppFrame::OnShowSPI(wxCommandEvent& event)
{
    if (spi) //it's already opened
        spi->Show();
    else
    {
        spi = new SPI_wxgui(this, wxNewId(), _("Device Info"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE);
//        spi->Initialize(lms8controlPort, streamBoardPort);
//        spi->Initialize(lms8controlPort);
        spi->Initialize(lms8controlPort, lmsControl);
        spi->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LMS8SuiteAppFrame::OnSPIClose), NULL, this);
        spi->Show();
    }
}

void LMS8SuiteAppFrame::OnShowGPIO(wxCommandEvent& event)
{
	if (gpio) //it's already opened
		gpio->Show();
	else
	{
		gpio = new GPIO_wxgui(this, wxNewId(), _("Device Info"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE);
//		gpio->Initialize(lms8controlPort, streamBoardPort);
		gpio->Initialize(lms8controlPort);
		gpio->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LMS8SuiteAppFrame::OnGPIOClose), NULL, this);
		gpio->Show();
	}
}

#include <iomanip>
void LMS8SuiteAppFrame::OnLogDataTransfer(bool Tx, const unsigned char* data, const unsigned int length)
{
	if (mMiniLog == nullptr || mMiniLog->chkLogData->IsChecked() == false)
		return;
	stringstream ss;
	ss << (Tx ? "Wr(" : "Rd(");
	ss << length << "): ";
	ss << std::hex << std::setfill('0');
	int repeatedZeros = 0;
	for (int i = length - 1; i >= 0; --i)
		if (data[i] == 0)
			++repeatedZeros;
		else
			break;
	if (repeatedZeros == 2)
		repeatedZeros = 0;
	repeatedZeros = repeatedZeros - (repeatedZeros & 0x1);
	for (int i = 0; i<length - repeatedZeros; ++i)
		//casting to short to print as numbers
		ss << " " << std::setw(2) << (unsigned short)data[i];
	if (repeatedZeros > 2)
		ss << " (00 x " << std::dec << repeatedZeros << " times)";
	cout << ss.str() << endl;
	wxCommandEvent *evt = new wxCommandEvent();
	evt->SetString(ss.str());
	evt->SetEventObject(this);
	evt->SetEventType(LOG_MESSAGE);
	wxQueueEvent(this, evt);
}

void LMS8SuiteAppFrame::OnADF4002Close(wxCloseEvent& event)
{
	adfGUI->Destroy();
	adfGUI = nullptr;
}

void LMS8SuiteAppFrame::OnShowADF4002(wxCommandEvent& event)
{
	if (adfGUI) //it's already opened
		adfGUI->Show();
	else
	{
		adfGUI = new ADF4002_wxgui(this, wxNewId(), _("ADF4002"));
		adfGUI->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LMS8SuiteAppFrame::OnADF4002Close), NULL, this);
		adfGUI->Initialize(adfModule, lms8controlPort);
		adfGUI->Show();
	}
}

void LMS8SuiteAppFrame::OnSi5351Close(wxCloseEvent& event)
{
	si5351gui->Destroy();
	si5351gui = nullptr;
}

void LMS8SuiteAppFrame::OnShowSi5351C(wxCommandEvent& event)
{
	if (si5351gui) //it's already opened
		si5351gui->Show();
	else
	{
		si5351gui = new Si5351C_wxgui(this, wxNewId(), _("Si5351C"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE);
		si5351gui->Initialize(si5351module);
		si5351gui->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(LMS8SuiteAppFrame::OnSi5351Close), NULL, this);
		si5351gui->Show();
	}
}
