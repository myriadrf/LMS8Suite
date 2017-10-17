#include "dlgMeasurements.h"
#include "dlgConnectionSettingsLMS7.h"
//#include "../measurements/LMS7002M_statuses.h"
//#include "../measurements/LMS7002M_parameters.h"
////#include "../measurements/lms7002_defines.h"
#include "lmsComms.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>

#include "INI.h"

#include "lms8suiteEvents.h"

double dlgMeasurements::gVCO_frequency_tableLMS7[3][2] = { { 3800, 5222 },{ 4961, 6754 },{ 6306, 7714 } };

//****************************************************************************
//
// Error handling
//
//****************************************************************************

void WINAPI GPIB_error(C8 *msg, S32 ibsta, S32 iberr, S32 ibcntl)
{
	MessageBoxA(NULL, msg, "GPIB Error", MB_OK);
//	SAL_alert_box("GPIB Error", msg);

	exit(1);
}

dlgMeasurements::dlgMeasurements(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long styles)
:
dlgMeasurements_view( parent, id, title, pos, size, styles)
{
	lms7controlPort = new LMScomms();
}

void dlgMeasurements::Initialize(LMScomms* pCtrPort, LMS8001* pControl)
{
	ctrPort = pCtrPort;
	//	dataPort = pDataPort;
	assert(ctrPort != nullptr);
	//	assert(dataPort != nullptr);
	lmsControl = pControl;

//	threadMeasure = std::thread();
}

void dlgMeasurements::SPIwrite(char* field, int idata) {

	int icmd = 1;
	int iaddress;
	char comment[200] = "";
	char command[200] = "";

	sprintf(command, "SPI: WR %s 0x%X", field, idata);

	int paramFound = 0;
	LMS8Parameter parameter = lmsControl->findLMS8Param(field);

	if (strcmp(parameter.name, "NOT_FOUND") != 0)
	{
		sprintf(comment, "Field %s found\n", parameter.name);
		iaddress = parameter.address;
		paramFound = 1;
	}
	else {
		//		int tmp = sprintf(field, "%X", iaddress);
		int tmp = sscanf(field, "%i", &iaddress);
		if (tmp == 0) {
			sprintf(comment, "Invalid address %s\n", field);
			icmd = 0; //Do not perform write
		}
	}

	uint16_t addr = 0;
	uint16_t data = 0;
	LMScomms::GenericPacket pkt;
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
			sprintf(comment, "%s%s", comment, liblms8_status2string(status));
		}
		else
			sprintf(comment, "%sWrite failed", comment);
	}
	appendLog(command);
	appendLog(comment);
}

void dlgMeasurements::appendLog(char* line)
{
	wxString wxText_log;
	std::string text_log;

	wxText_log = txtField_log->GetValue();
	text_log = wxText_log.ToStdString();

	text_log += line;
	text_log += "\n";
	txtField_log->Clear();
	txtField_log->AppendText(text_log);

//	txtField_log->Refresh();
//	InvalidateRect(this->m_hWnd, NULL, TRUE);
}

void dlgMeasurements::onMeasMeasure(wxCommandEvent& event)
{
	if (threadMeasure.joinable()) threadMeasure.join();
	stopThreadMeasure.store(false);
	threadMeasure = std::thread(DoMeasure, this);
//	threadMeasure.join();
}

void dlgMeasurements::onMeasStop(wxCommandEvent& event)
{
	stopThreadMeasure.store(true);
//	threadMeasure.detach();
}

void dlgMeasurements::DoMeasure(dlgMeasurements* pthis)
{
	bool lms7SweepFreq = pthis->chkLMS7FreqEnable->GetValue();

	bool sweepPar1 = pthis->chkParEnable1->GetValue();
	bool sweepPar2 = pthis->chkParEnable2->GetValue();

	bool measFindPeak = pthis->chkMeasFindPeakEnable->GetValue();

	S64 measFindPeakStartFreq;
	F64 fMeasFindPeakStartFreq;
	sscanf((const char*)(pthis->txtMeasFindPeakStartFreq->GetValue()).mb_str(wxConvUTF8), "%Lg", &fMeasFindPeakStartFreq);
	measFindPeakStartFreq = fMeasFindPeakStartFreq;

	S64 measFindPeakStartSpan;
	F64 fMeasFindPeakStartSpan;
	sscanf((const char*)(pthis->txtMeasFindPeakStartSpan->GetValue()).mb_str(wxConvUTF8), "%Lg", &fMeasFindPeakStartSpan);
	measFindPeakStartSpan = fMeasFindPeakStartSpan;

	S64 measFindPeakStopSpan;
	F64 fMeasFindPeakStopSpan;
	sscanf((const char*)(pthis->txtMeasFindPeakStopSpan->GetValue()).mb_str(wxConvUTF8), "%Lg", &fMeasFindPeakStopSpan);
	measFindPeakStopSpan = fMeasFindPeakStopSpan;

	bool bandMarker = pthis->chkMeasUseBandMarker->GetValue();
	long bandMarkerBW = 0;
//	pthis->txtMeasBandMarkerBand->GetValue().ToLong(&bandMarkerBW, 16);
	pthis->txtMeasBandMarkerBand->GetValue().ToLong(&bandMarkerBW);

	S64 lms7FreqMin;
	F64 fLms7FreqMin;

	S64 lms7FreqMax;
	F64 fLms7FreqMax;

	S64 lms7FreqStep;
	F64 fLms7FreqStep;

	S64 lms7FreqValues[1024];
	long lms7FreqValuesNo = 0;

	if (lms7SweepFreq) {
		sscanf((const char*)(pthis->txtLMS7FreqMin->GetValue()).mb_str(wxConvUTF8), "%Lg", &fLms7FreqMin);
		lms7FreqMin = fLms7FreqMin;

		sscanf((const char*)(pthis->txtLMS7FreqMax->GetValue()).mb_str(wxConvUTF8), "%Lg", &fLms7FreqMax);
		lms7FreqMax = fLms7FreqMax;

		sscanf((const char*)(pthis->txtLMS7FreqStep->GetValue()).mb_str(wxConvUTF8), "%Lg", &fLms7FreqStep);
		lms7FreqStep = fLms7FreqStep;

//		for (long i = lms7FreqMin; i <= lms7FreqMax; i += lms7FreqStep) {
		for (S64 i = lms7FreqMin; i <= lms7FreqMax; i += lms7FreqStep) {
			lms7FreqValues[lms7FreqValuesNo] = i;
			lms7FreqValuesNo++;
		}
		if ((lms7FreqValuesNo > 0) && (lms7FreqValues[lms7FreqValuesNo - 1] != lms7FreqMax)) {
			lms7FreqValues[lms7FreqValuesNo] = lms7FreqMax;
			lms7FreqValuesNo++;
		}
	}

	char parField1[256];
	long parMin1 = 0;
	long parMax1 = 0;
	long parStep1 = 0;
	long parValues1[1024];
	long parValuesNo1 = 0;

	char parField2[256];
	long parMin2 = 0;
	long parMax2 = 0;
	long parStep2 = 0;
	long parValues2[1024];
	long parValuesNo2 = 0;

	if (sweepPar1) {
		strcpy(parField1, (pthis->txtParField1->GetValue()).ToStdString().c_str());
		sscanf((pthis->txtParMin1->GetValue()).c_str(), "%i", &parMin1);
		sscanf((pthis->txtParMax1->GetValue()).c_str(), "%i", &parMax1);
		sscanf((pthis->txtParStep1->GetValue()).c_str(), "%i", &parStep1);

		for (long i = parMin1; i <= parMax1; i += parStep1) {
			parValues1[parValuesNo1] = i;
			parValuesNo1++;
		}
		if ((parValuesNo1 > 0) && (parValues1[parValuesNo1 - 1] != parMax1)) {
			parValues1[parValuesNo1] = parMax1;
			parValuesNo1++;
		}
	}

	if (sweepPar2) {
		strcpy(parField2, (pthis->txtParField2->GetValue()).ToStdString().c_str());
		sscanf((pthis->txtParMin2->GetValue()).c_str(), "%i", &parMin2);
		sscanf((pthis->txtParMax2->GetValue()).c_str(), "%i", &parMax2);
		sscanf((pthis->txtParStep2->GetValue()).c_str(), "%i", &parStep2);

		for (long i = parMin2; i <= parMax2; i += parStep2) {
			parValues2[parValuesNo2] = i;
			parValuesNo2++;
		}
		if ((parValuesNo2 > 0) && (parValues2[parValuesNo2 - 1] != parMax2)) {
			parValues2[parValuesNo2] = parMax2;
			parValuesNo2++;
		}
	}

	char status[256] = "";
	char log_line[512];

	int measPoints = 0;

	std::vector<S64> lms7FreqValuesVec;
	std::vector<long> parValuesVec1;
	std::vector<long> parValuesVec2;
	std::vector<S64> resS64Vec1;
	std::vector<S64> resS64Vec2;
	std::vector<double> resDoubleVec1;
	std::vector<double> resDoubleVec2;

	int lms7SweepFreqLimit = (lms7SweepFreq) ? lms7FreqValuesNo : 1;
	int sweepPar1Limit = (sweepPar1) ? parValuesNo1 : 1;
	int sweepPar2Limit = (sweepPar2) ? parValuesNo2 : 1;

	for (int k = 0; k < lms7SweepFreqLimit; k++) {
		for (int i = 0; i < sweepPar1Limit; i++) {
			for (int j = 0; j < sweepPar2Limit; j++) {
				if (lms7SweepFreq) lms7FreqValuesVec.push_back(lms7FreqValues[k]);
				if (sweepPar1) parValuesVec1.push_back(parValues1[i]);
				if (sweepPar2) parValuesVec2.push_back(parValues2[j]);
				measPoints++;
			}
		}
	}
/*
	for (int i = 0; i < parValuesNo1; i++) {
		parValuesVec1.push_back(parValues1[i]);
		measPoints++;
		for (int j = 0; j < parValuesNo2; j++) {
			parValuesVec2.push_back(parValues2[j]);
			if (j != 0) {
				parValuesVec1.push_back(parValues1[i]);
				measPoints++;
			}
		}
	}

	if (!sweepPar1) {
		for (int j = 0; j < parValuesNo2; j++) {
			parValuesVec2.push_back(parValues2[j]);
			measPoints++;
		}
	}
*/
	int rowNo = pthis->gridMeasResults->GetRows();
	pthis->gridMeasResults->DeleteRows(0, rowNo);

	int colNo = pthis->gridMeasResults->GetCols();
	pthis->gridMeasResults->DeleteCols(0, colNo);

	colNo = 0;
	if (lms7SweepFreq) colNo++;
	if (sweepPar1) colNo++;
	if (sweepPar2) colNo++;
	colNo += 2; //For the results

	pthis->gridMeasResults->InsertCols(0, colNo);

	int currCol = 0;
	if (lms7SweepFreq) {
		pthis->gridMeasResults->SetColLabelValue(currCol, "LMS7 Freq.");
		currCol++;
	}
	if (sweepPar1) {
		pthis->gridMeasResults->SetColLabelValue(currCol, wxString(parField1));
		currCol++;
	}
	if (sweepPar2) {
		pthis->gridMeasResults->SetColLabelValue(currCol, wxString(parField2));
		currCol++;
	}

	GPIB_connect(18, GPIB_error, 0, 1000000);
	GPIB_set_EOS_mode(10);
	GPIB_set_serial_read_dropout(500);

	E4440A myE4440A;

	//Preset the spectrum analyzer
	GPIB_query(":SYST:PRES;*OPC?");

	for (int i = 0; i < measPoints; i++)
	{
		rowNo = pthis->gridMeasResults->GetRows();
		pthis->gridMeasResults->InsertRows(rowNo);

		sprintf(status, "Measuring %d/%d", i + 1, measPoints);
		pthis->lblStatus->SetLabel(status);

		int currCol = 0;

		wxString wxsCellValue;

		if (lms7SweepFreq) {
			sprintf(log_line, "LMS7 Frequency = 0x%X", lms7FreqValuesVec.at(i));
			pthis->appendLog(log_line);
			wxsCellValue.Printf("%I64d", lms7FreqValuesVec.at(i));
			pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
			currCol++;
//			pthis->SetLMS7Frequency(lms7FreqValuesVec.at(i));
//msavic 170213
//			float refClk_MHz = 30.72;
			float refClk_MHz = 40.00;

			float freq_MHz = lms7FreqValuesVec.at(i) / 1.0e6;
			liblms7_status status;
			status = pthis->SetFrequencySXLMS7(true, freq_MHz, refClk_MHz);
			// Sleep for 10 ms - to stabilize frequency, probably could be much shorter...
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		if (sweepPar1) {
			sprintf(log_line, "Parameter #1: %s = 0x%X", parField1, parValuesVec1.at(i));
			pthis->appendLog(log_line);
			wxsCellValue.Printf("%ld", parValuesVec1.at(i));
			pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
			currCol++;
			pthis->SPIwrite(parField1, parValuesVec1.at(i));
		}
		if (sweepPar2) {
			sprintf(log_line, "Parameter #2: %s = 0x%X", parField2, parValuesVec2.at(i));
			pthis->appendLog(log_line);
			wxsCellValue.Printf("%ld", parValuesVec2.at(i));
			pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
			currCol++;
			pthis->SPIwrite(parField2, parValuesVec2.at(i));
		}

		//Here do the measurement!

//		resS64Vec1.push_back(myE4440A.getCenterFrequency());
//		wxsCellValue.Printf("%I64d", resS64Vec1.at(i));
//		pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
//		currCol++;

		if (measFindPeak) {
			S64 X;
			double Y;

//			myE4440A.findCarrier(measFindPeakStartFreq, measFindPeakStartSpan, measFindPeakStopSpan, &X, &Y);
			myE4440A.findCarrier(measFindPeakStartFreq, measFindPeakStartSpan, measFindPeakStopSpan, &X, &Y, bandMarker, bandMarkerBW);
//			X = 3800000000; Y = -40.1234;

			resS64Vec1.push_back(X);
			wxsCellValue.Printf("%I64d", resS64Vec1.at(i));
			pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
			currCol++;

			resDoubleVec2.push_back(Y);
			wxsCellValue.Printf("%f", resDoubleVec2.at(i));
			pthis->gridMeasResults->SetCellValue(wxsCellValue, i, currCol);
			currCol++;
		}

		if (pthis->stopThreadMeasure.load() == true)
		{
			pthis->lblStatus->SetLabel("Measurement canceled");
			GPIB_disconnect(FALSE);
			return;
		}
	}

	pthis->lblStatus->SetLabel("Measurement complete");

	GPIB_disconnect(FALSE);
}

dlgMeasurements::~dlgMeasurements()
{
	if (threadMeasure.joinable()) threadMeasure.join();
}

void dlgMeasurements::OnDlgMeasurementsClose(wxCloseEvent& event)
{
}

void dlgMeasurements::onMeasSaveAsCSV(wxCommandEvent& event)
{
	wxFileDialog dlg(this, _("Save measurement results"), "", "", "Comma Separated Values (*.csv)|*.csv", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() == wxID_CANCEL)
		return;
	int status = SaveCSV(dlg.GetPath().To8BitData());
	if (status != 0)
		wxMessageBox(_("Failed to save file"), _("Warning"));
}

int dlgMeasurements::SaveCSV(const char* filename)
{
	int result = 0;

	FILE* out_fp;
	out_fp = fopen(filename, "w");

	if (out_fp == NULL) {
		return 1;
	}

	int rowNo = gridMeasResults->GetRows();
	int colNo = gridMeasResults->GetCols();

	for (int j = 0; j < colNo; j++) {
//		fprintf(out_fp, "%ls", (gridMeasResults->GetColLabelValue(j)).mb_str());
		fprintf(out_fp, "%s", (const char*)(gridMeasResults->GetColLabelValue(j)).mb_str(wxConvUTF8));

//		mystring.mb_str()
//		(const char*)mystring.mb_str(wxConvUTF8),

		if(j != colNo-1)
			fprintf(out_fp, ",");
		else
			fprintf(out_fp, "\n");
	}

	for (int i = 0; i < rowNo; i++) {
		for (int j = 0; j < colNo; j++) {
//			fprintf(out_fp, "%s", (gridMeasResults->GetCellValue(i, j)).To8BitData());
			fprintf(out_fp, "%s", (const char*)(gridMeasResults->GetCellValue(i, j)).mb_str(wxConvUTF8));
			if (j != colNo - 1)
				fprintf(out_fp, ",");
			else
				fprintf(out_fp, "\n");
		}
	}

	fclose(out_fp);

	return result;
}

void dlgMeasurements::onMeasSaveSetup(wxCommandEvent& event)
{ 
	wxFileDialog dlg(this, _("Save measurement setup"), "", "", "Measurement Setup (*.mes)|*.mes", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() == wxID_CANCEL)
		return;
	int status = SaveMeasSetup(dlg.GetPath().To8BitData());
	if (status != LIBLMS8_SUCCESS)
		wxMessageBox(_("Failed to save file"), _("Warning"));
}

liblms8_status dlgMeasurements::SaveMeasSetup(const char* filename)
{
	typedef INI<> ini_t;
	ini_t parser(filename, true);
	parser.create("file_info");
	parser.set("type", "lms8001_measurement_setup");
	parser.set("version", 1);

	parser.create("lms8001_parameters");

	
	parser.set("LMS7FreqEnable", chkLMS7FreqEnable->GetValue());
	parser.set("LMS7FreqMin", txtLMS7FreqMin->GetValue());
	parser.set("LMS7FreqMax", txtLMS7FreqMax->GetValue());
	parser.set("LMS7FreqStep", txtLMS7FreqStep->GetValue());
	
	parser.set("LMS7parEnable1", chkLMS7ParEnable1->GetValue());
	parser.set("LMS7parMin1", txtLMS7ParMin1->GetValue());
	parser.set("LMS7parMax1", txtLMS7ParMax1->GetValue());
	parser.set("LMS7parStep1", txtLMS7ParStep1->GetValue());

	parser.set("parEnable1", chkParEnable1->GetValue());
	parser.set("parMin1", txtParMin1->GetValue());
	parser.set("parMax1", txtParMax1->GetValue());
	parser.set("parStep1", txtParStep1->GetValue());

	parser.set("parEnable2", chkParEnable2->GetValue());
	parser.set("parMin2", txtParMin2->GetValue());
	parser.set("parMax2", txtParMax2->GetValue());
	parser.set("parStep2", txtParStep2->GetValue());

	parser.create("lms8001_measurements");

	parser.set("measFindPeakEnable", chkMeasFindPeakEnable->GetValue());
	parser.set("measFindPeakStartFreq", txtMeasFindPeakStartFreq->GetValue());
	parser.set("measFindPeakStartSpan", txtMeasFindPeakStartSpan->GetValue());
	parser.set("measFindPeakStopSpan", txtMeasFindPeakStopSpan->GetValue());

	parser.set("measUseBandMarker", chkMeasUseBandMarker->GetValue());
	parser.set("measBandMarkerBand", txtMeasBandMarkerBand->GetValue());

	parser.save(filename);

	return LIBLMS8_SUCCESS;
}

void dlgMeasurements::onMeasLoadSetup(wxCommandEvent& event)
{
	wxFileDialog dlg(this, _("Load measurement setup"), "", "", "Measurement Setup (*.mes)|*.mes", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (dlg.ShowModal() == wxID_CANCEL)
		return;
	int status = LoadMeasSetup(dlg.GetPath().To8BitData());
	if (status != LIBLMS8_SUCCESS)
		wxMessageBox(_("Failed to load file"), _("Warning"));
}

liblms8_status dlgMeasurements::LoadMeasSetup(const char* filename)
{
	ifstream f(filename);
	if (f.good() == false) //file not found
	{
		f.close();
		return LIBLMS8_FILE_NOT_FOUND;
	}
	f.close();
	uint16_t addr = 0;
	uint16_t value = 0;

	liblms8_status status;
	typedef INI<string, string, string> ini_t;
	ini_t parser(filename, true);
	parser.select("file_info");
	string type = "";
	type = parser.get("type", string("undefined"));
	stringstream ss;
	if (type.find("lms8001_measurement_setup") == string::npos)
	{
		ss << "File " << std::string(filename) << " not recognized" << endl;
		return LIBLMS8_FAILURE;
	}

	int fileVersion = 0;
	fileVersion = parser.get("version", 0);

	parser.select("lms8001_parameters");

	chkLMS7FreqEnable->SetValue(parser.get("LMS7FreqEnable", false));
	txtLMS7FreqMin->SetValue(parser.get("LMS7FreqMin", string("undefined")));
	txtLMS7FreqMax->SetValue(parser.get("LMS7FreqMax", string("undefined")));
	txtLMS7FreqStep->SetValue(parser.get("LMS7FreqStep", string("undefined")));

	chkLMS7ParEnable1->SetValue(parser.get("LMS7parEnable1", false));
	txtLMS7ParMin1->SetValue(parser.get("LMS7parMin1", string("undefined")));
	txtLMS7ParMax1->SetValue(parser.get("LMS7parMax1", string("undefined")));
	txtLMS7ParStep1->SetValue(parser.get("LMS7parStep1", string("undefined")));

	chkParEnable1->SetValue(parser.get("parEnable1", false));
	txtParMin1->SetValue(parser.get("parMin1", string("undefined")));
	txtParMax1->SetValue(parser.get("parMax1", string("undefined")));
	txtParStep1->SetValue(parser.get("parStep1", string("undefined")));

	chkParEnable2->SetValue(parser.get("parEnable2", false));
	txtParMin2->SetValue(parser.get("parMin2", string("undefined")));
	txtParMax2->SetValue(parser.get("parMax2", string("undefined")));
	txtParStep2->SetValue(parser.get("parStep2", string("undefined")));

	parser.select("lms8001_measurements");

	chkMeasFindPeakEnable->SetValue(parser.get("measFindPeakEnable", false));
	txtMeasFindPeakStartFreq->SetValue(parser.get("measFindPeakStartFreq", string("undefined")));
	txtMeasFindPeakStartSpan->SetValue(parser.get("measFindPeakStartSpan", string("undefined")));
	txtMeasFindPeakStopSpan->SetValue(parser.get("measFindPeakStopSpan", string("undefined")));

	chkMeasUseBandMarker->SetValue(parser.get("measUseBandMarker", false));
	txtMeasBandMarkerBand->SetValue(parser.get("measBandMarkerBand", string("undefined")));

	return LIBLMS8_SUCCESS;
}

void dlgMeasurements::OnLMS7Connect(wxCommandEvent& event) {

	dlgConnectionSettingsLMS7 dlg(this);

	dlg.SetConnectionManager(lms7controlPort);
	Bind(LMS7_CONTROL_PORT_CONNECTED, wxCommandEventHandler(dlgMeasurements::OnLMS7ControlBoardConnect), this);
	Bind(LMS7_CONTROL_PORT_DISCONNECTED, wxCommandEventHandler(dlgMeasurements::OnLMS7ControlBoardConnect), this);
	dlg.ShowModal();
}

/*
void dlgMeasurements::onLMS7write(wxCommandEvent& event)
{
	wxString address = txtLMSwriteAddr->GetValue();
	long addr = 0;
	address.ToLong(&addr, 16);
	wxString value = txtLMSwriteValue->GetValue();
	long data = 0;
	value.ToLong(&data, 16);

	LMScomms::GenericPacket pkt;
//	pkt.cmd = CMD_LMS8001_WR;
	pkt.cmd = CMD_LMS7002_WR;
	pkt.outBuffer.push_back((addr >> 8) & 0xFF);
	pkt.outBuffer.push_back(addr & 0xFF);
	pkt.outBuffer.push_back((data >> 8) & 0xFF);
	pkt.outBuffer.push_back(data & 0xFF);

	assert(lms7controlPort != nullptr);
	if (lms7controlPort == nullptr)
		return;
	LMScomms::TransferStatus status = lms7controlPort->TransferPacket(pkt);

	if (status == LMScomms::TRANSFER_SUCCESS)
		lblLMSwriteStatus->SetLabel(wxString::FromUTF8(status2string(pkt.status)));
	else
		lblLMSwriteStatus->SetLabel(_("Write failed"));
}
*/

void dlgMeasurements::onLMS7read(wxCommandEvent& event)
{
	wxString address = txtLMSreadAddr->GetValue();
	long addr = 0;
	address.ToLong(&addr, 16);

	LMScomms::GenericPacket pkt;
//	pkt.cmd = CMD_LMS8001_RD;
	pkt.cmd = CMD_LMS7002_RD;
	pkt.outBuffer.push_back((addr >> 8) & 0xFF);
	pkt.outBuffer.push_back(addr & 0xFF);
	assert(lms7controlPort != nullptr);
	if (lms7controlPort == nullptr)
		return;
	LMScomms::TransferStatus status = lms7controlPort->TransferPacket(pkt);

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

void dlgMeasurements::SPIwriteLMS7(char* field, int idata) {

	int icmd = 1;
	int iaddress;
	char comment[200] = "";
	char command[200] = "";

	sprintf(command, "LMS7 SPI: WR %s 0x%X", field, idata);

	int paramFound = 0;
	LMS7Parameter parameter = findLMS7Param(field);

	if (strcmp(parameter.name, "NOT_FOUND") != 0)
	{
		sprintf(comment, "LMS7 Field %s found\n", parameter.name);
		iaddress = parameter.address;
		paramFound = 1;
	}
	else {
		//		int tmp = sprintf(field, "%X", iaddress);
		int tmp = sscanf(field, "%i", &iaddress);
		if (tmp == 0) {
			sprintf(comment, "LMS7 Invalid address %s\n", field);
			icmd = 0; //Do not perform write
		}
	}

	uint16_t addr = 0;
	uint16_t data = 0;
	LMScomms::GenericPacket pkt;
	liblms7_status status;

	addr = iaddress;
	data = idata;

	if (icmd == 1) //WRITE
	{
		if (paramFound)
//			status = lmsControl->Modify_SPI_Reg_bits(parameter, data);
			status = Modify_SPI_Reg_bitsLMS7(parameter, data);
		else
//			status = lmsControl->Modify_SPI_Reg_bits(addr, 15, 0, data);
			status = Modify_SPI_Reg_bitsLMS7(addr, 15, 0, data);


		if (status == LIBLMS8_SUCCESS)
		{
			sprintf(comment, "%s%s", comment, liblms8_status2string((liblms8_status)status));
		}
		else
			sprintf(comment, "%sWrite failed", comment);
	}
	appendLog(command);
	appendLog(comment);
}

LMS7Parameter dlgMeasurements::findLMS7Param(char* field)
{
	LMS7Parameter parameter = { 0xFFFF, 0, 0, 0, "NOT_FOUND", "" };
	int found = 0;
	//	LMS8Parameter element;
	for (const LMS7Parameter* iter : LMS7parameterList)
	{
		if (strcmp(iter->name, field) == 0) {
			parameter = *iter;
			break;
		}
	}

	return parameter;
}

liblms7_status dlgMeasurements::Modify_SPI_Reg_bitsLMS7(const LMS7Parameter &param, const uint16_t value, bool fromChip)
{
	return Modify_SPI_Reg_bitsLMS7(param.address, param.msb, param.lsb, value, fromChip);
}

liblms7_status dlgMeasurements::Modify_SPI_Reg_bitsLMS7(const uint16_t address, const uint8_t msb, const uint8_t lsb, const uint16_t value, bool fromChip)
{
	uint16_t spiDataReg = SPI_readLMS7(address, fromChip); //read current SPI reg data
	uint16_t spiMask = (~(~0 << (msb - lsb + 1))) << (lsb); // creates bit mask
	spiDataReg = (spiDataReg & (~spiMask)) | ((value << lsb) & spiMask);//clear bits
	return SPI_writeLMS7(address, spiDataReg); //write modified data back to SPI reg
}

uint16_t dlgMeasurements::Get_SPI_Reg_bitsLMS7(const LMS7Parameter &param, bool fromChip)
{
	return Get_SPI_Reg_bitsLMS7(param.address, param.msb, param.lsb, fromChip);
}

uint16_t dlgMeasurements::Get_SPI_Reg_bitsLMS7(uint16_t address, uint8_t msb, uint8_t lsb, bool fromChip)
{
	return (SPI_readLMS7(address, fromChip) & (~(~0 << (msb + 1)))) >> lsb; //shift bits to LSB
}


liblms7_status dlgMeasurements::SPI_writeLMS7(uint16_t address, uint16_t data)
{
	if (lms7controlPort == NULL)
		return LIBLMS7_NO_CONNECTION_MANAGER;

	if (lms7controlPort->IsOpen() == false)
		return LIBLMS7_NOT_CONNECTED;

	LMScomms::GenericPacket pkt;
	pkt.cmd = CMD_LMS7002_WR;
	pkt.outBuffer.push_back(address >> 8);
	pkt.outBuffer.push_back(address & 0xFF);
	pkt.outBuffer.push_back(data >> 8);
	pkt.outBuffer.push_back(data & 0xFF);
	lms7controlPort->TransferPacket(pkt);
	if (pkt.status == STATUS_COMPLETED_CMD)
		return LIBLMS7_SUCCESS;
	else
		return LIBLMS7_FAILURE;
}

uint16_t dlgMeasurements::SPI_readLMS7(uint16_t address, bool fromChip, liblms7_status *status)
{
	if (lms7controlPort == NULL)
	{
		if (status)
			*status = LIBLMS7_NO_CONNECTION_MANAGER;
	}

	LMScomms::GenericPacket pkt;
	pkt.cmd = CMD_LMS7002_RD;
	pkt.outBuffer.push_back(address >> 8);
	pkt.outBuffer.push_back(address & 0xFF);
	if (lms7controlPort->TransferPacket(pkt) == LMScomms::TRANSFER_SUCCESS)
	{
		if (status)
			*status = (pkt.status == STATUS_COMPLETED_CMD ? LIBLMS7_SUCCESS : LIBLMS7_FAILURE);
		return (pkt.inBuffer[2] << 8) | pkt.inBuffer[3];
	}
	else
		return 0;
}

//Copied from lms7suite
liblms7_status dlgMeasurements::SetFrequencySXLMS7(bool tx, float_type freq_MHz, float_type refClk_MHz)
{
	if (lms7controlPort == NULL)
		return LIBLMS7_NO_CONNECTION_MANAGER;
	if (lms7controlPort->IsOpen() == false)
		return LIBLMS7_NOT_CONNECTED;
	const uint8_t sxVCO_N = 2; //number of entries in VCO frequencies
	const float_type m_dThrF = 5500; //threshold to enable additional divider
	uint8_t ch; //remember used channel
	float_type VCOfreq;
	int8_t div_loch;
	int8_t sel_vco;
	bool canDeliverFrequency = false;
	uint16_t integerPart;
	uint32_t fractionalPart;

	//find required VCO frequency
	for (div_loch = 6; div_loch >= 0; --div_loch)
	{
		VCOfreq = (1 << (div_loch + 1)) * freq_MHz;
		if ((VCOfreq >= gVCO_frequency_tableLMS7[0][0]) && (VCOfreq <= gVCO_frequency_tableLMS7[2][sxVCO_N - 1]))
		{
			canDeliverFrequency = true;
			break;
		}
	}
	if (canDeliverFrequency == false)
		return LIBLMS7_CANNOT_DELIVER_FREQUENCY;

	integerPart = (uint16_t)(VCOfreq / (refClk_MHz * (1 + (VCOfreq > m_dThrF))) - 4);
	fractionalPart = (uint32_t)((VCOfreq / (refClk_MHz * (1 + (VCOfreq > m_dThrF))) - (uint32_t)(VCOfreq / (refClk_MHz * (1 + (VCOfreq > m_dThrF))))) * 1048576);

	ch = (uint8_t)Get_SPI_Reg_bitsLMS7(LMS7param(MAC));
	Modify_SPI_Reg_bitsLMS7(LMS7param(MAC), tx + 1);
	Modify_SPI_Reg_bitsLMS7(LMS7param(INT_SDM), integerPart); //INT_SDM
	Modify_SPI_Reg_bitsLMS7(0x011D, 15, 0, fractionalPart & 0xFFFF); //FRAC_SDM[15:0]
	Modify_SPI_Reg_bitsLMS7(0x011E, 3, 0, (fractionalPart >> 16)); //FRAC_SDM[19:16]
	Modify_SPI_Reg_bitsLMS7(LMS7param(DIV_LOCH), div_loch); //DIV_LOCH
	Modify_SPI_Reg_bitsLMS7(LMS7param(EN_DIV2_DIVPROG), (VCOfreq > m_dThrF)); //EN_DIV2_DIVPROG

																		  //find which VCO supports required frequency
	int cswBackup = Get_SPI_Reg_bitsLMS7(LMS7param(CSW_VCO)); //remember to restore previous tune value
	canDeliverFrequency = false;
	for (sel_vco = 0; sel_vco < 3; ++sel_vco)
	{
		Modify_SPI_Reg_bitsLMS7(LMS7param(SEL_VCO), sel_vco);
		Modify_SPI_Reg_bitsLMS7(LMS7param(CSW_VCO), 0);
		uint8_t cmp0 = Get_SPI_Reg_bitsLMS7(0x0123, 13, 12, true);
		Modify_SPI_Reg_bitsLMS7(LMS7param(CSW_VCO), 255);
		uint8_t cmp255 = Get_SPI_Reg_bitsLMS7(0x0123, 13, 12, true);
		if (cmp0 != cmp255)
		{
			canDeliverFrequency = true;
			break;
		}
	}
	Modify_SPI_Reg_bitsLMS7(LMS7param(CSW_VCO), cswBackup);
	Modify_SPI_Reg_bitsLMS7(LMS7param(MAC), ch); //restore used channel
/*
	if (tx)
		mRefClkSXT_MHz = refClk_MHz;
	else
		mRefClkSXR_MHz = refClk_MHz;
*/
	if (canDeliverFrequency == false)
		return LIBLMS7_CANNOT_DELIVER_FREQUENCY;
	return TuneVCOLMS7(tx ? VCO_SXT : VCO_SXR); //Rx-1, Tx-2
}

//Copied from lms7suite
liblms7_status dlgMeasurements::TuneVCOLMS7(VCO_ModuleLMS7 module) // 0-cgen, 1-SXR, 2-SXT
{
	if (lms7controlPort == NULL)
		return LIBLMS7_NO_CONNECTION_MANAGER;
	if (lms7controlPort->IsOpen() == false)
		return LIBLMS7_NOT_CONNECTED;
	int8_t i;
	uint8_t cmphl; //comparators
	int16_t csw_lowest = -1;
	uint16_t addrVCOpd; // VCO power down address
	uint16_t addrCSW_VCO;
	uint16_t addrCMP; //comparator address
	uint8_t lsb; //SWC lsb index
	uint8_t msb; //SWC msb index

	uint8_t ch = (uint8_t)Get_SPI_Reg_bitsLMS7(LMS7param(MAC)); //remember used channel

	if (module != VCO_CGEN) //set addresses to SX module
	{
		Modify_SPI_Reg_bitsLMS7(LMS7param(MAC), module);
		addrVCOpd = LMS7param(PD_VCO).address;
		addrCSW_VCO = LMS7param(CSW_VCO).address;
		lsb = LMS7param(CSW_VCO).lsb;
		msb = LMS7param(CSW_VCO).msb;
		addrCMP = LMS7param(VCO_CMPHO).address;
	}
	else //set addresses to CGEN module
	{
		addrVCOpd = LMS7param(PD_VCO_CGEN).address;
		addrCSW_VCO = LMS7param(CSW_VCO_CGEN).address;
		lsb = LMS7param(CSW_VCO_CGEN).lsb;
		msb = LMS7param(CSW_VCO_CGEN).msb;
		addrCMP = LMS7param(VCO_CMPHO_CGEN).address;
	}
	// Initialization
	Modify_SPI_Reg_bitsLMS7(addrVCOpd, 2, 1, 0); //activate VCO and comparator
	if (Get_SPI_Reg_bitsLMS7(addrVCOpd, 2, 1) != 0)
		return LIBLMS7_VCO_IS_POWERED_DOWN;
	if (module == VCO_CGEN)
		Modify_SPI_Reg_bitsLMS7(LMS7param(SPDUP_VCO_CGEN), 1); //SHORT_NOISEFIL=1 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
	else
		Modify_SPI_Reg_bitsLMS7(LMS7param(SPDUP_VCO), 1); //SHORT_NOISEFIL=1 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
	Modify_SPI_Reg_bitsLMS7(addrCSW_VCO, msb, lsb, 0); //Set SWC_VCO<7:0>=<00000000>

	i = 7;
	while (i >= 0)
	{
		Modify_SPI_Reg_bitsLMS7(addrCSW_VCO, lsb + i, lsb + i, 1); // CSW_VCO<i>=1
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		cmphl = (uint8_t)Get_SPI_Reg_bitsLMS7(addrCMP, 13, 12);
		if ((cmphl & 0x01) == 1) // reduce CSW
			Modify_SPI_Reg_bitsLMS7(addrCSW_VCO, lsb + i, lsb + i, 0); // CSW_VCO<i>=0
		if (cmphl == 2 && csw_lowest < 0)
			csw_lowest = Get_SPI_Reg_bitsLMS7(addrCSW_VCO, msb, lsb);
		--i;
	}
	if (csw_lowest >= 0)
	{
		uint16_t csw_highest = Get_SPI_Reg_bitsLMS7(addrCSW_VCO, msb, lsb);
		if (csw_lowest == csw_highest)
		{
			while (csw_lowest >= 0)
			{
				Modify_SPI_Reg_bitsLMS7(addrCSW_VCO, msb, lsb, csw_lowest);
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
				if (Get_SPI_Reg_bitsLMS7(addrCMP, 13, 12) == 0)
				{
					++csw_lowest;
					break;
				}
				else
					--csw_lowest;
			}
		}
		Modify_SPI_Reg_bitsLMS7(addrCSW_VCO, msb, lsb, csw_lowest + (csw_highest - csw_lowest) / 2);
	}
	if (module == VCO_CGEN)
		Modify_SPI_Reg_bitsLMS7(LMS7param(SPDUP_VCO_CGEN), 0); //SHORT_NOISEFIL=1 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
	else
		Modify_SPI_Reg_bitsLMS7(LMS7param(SPDUP_VCO), 0); //SHORT_NOISEFIL=1 SPDUP_VCO_ Short the noise filter resistor to speed up the settling time
	cmphl = (uint8_t)Get_SPI_Reg_bitsLMS7(addrCMP, 13, 12);
	Modify_SPI_Reg_bitsLMS7(LMS7param(MAC), ch); //restore previously used channel
	if (cmphl == 2)
		return LIBLMS7_SUCCESS;
	else
		return LIBLMS7_FAILURE;
}

//Alternative implementation - not finished
liblms7_status dlgMeasurements::SetLMS7Frequency(S64 LMS7LOFreq)
{
	if ((LMS7LOFreq <= 0.24e9) || (LMS7LOFreq >= 3.8e9))
		return LIBLMS7_FREQUENCY_OUT_OF_RANGE;

	liblms7_status status;

	S64 LMS7VCOFreq;
	int FF_MOD = 0;

	LMS7VCOFreq = 2*LMS7LOFreq*pow(2, FF_MOD);

	while (!((LMS7VCOFreq > 3.8e9) && (LMS7VCOFreq < 7.6e9))) {
		FF_MOD += 1;
		LMS7VCOFreq = 2*LMS7LOFreq*pow(2, FF_MOD);
	}

	SPIwriteLMS7("LMS7_DIV_LOCH", FF_MOD);

	status = LMS7VCOCoarseTune(LMS7VCOFreq);

/*
"""
Calculates FF-DIV Modulus. Calls VCO Corse Tuning Method. Configures PLL in LMS7002.
"""
if not (0.24e9<=F_LO<=3.8e9):
raise ValueError("Not Valid LO Frequency. 240 MHz< F_LO < 3.8 GHz")

FF_MOD=0.0
F_VCO=2*F_LO*(2**FF_MOD)

while (not(3.8e9<F_VCO<=7.6e9)):
FF_MOD+=1
F_VCO=2*F_LO*(2**FF_MOD)

print ''
print 'FF-DIV Modulus'
print '-'*60
print 'FFDIV-MOD=%d ' %(2**FF_MOD)
print ''
print ''
self.DIV_LOCH=int(FF_MOD)
self.VCO_CTUNE(F_VCO=F_VCO, F_REF=F_REF, IntN_MODE=IntN_MODE)
return 0
*/
}

//Alternative implementation - not finished
liblms7_status dlgMeasurements::LMS7VCOCoarseTune(S64 LMS7VCOFreq)
{
	return LIBLMS7_FAILURE;
/*
	//Reset PLL
	SPIwriteLMS7("LMS7_RESET_N", 0);
	//Enable PLL Blocks
	SPIwriteLMS7("LMS7_SPDUP_VCO", 0);
	SPIwriteLMS7("LMS7_BYPLDO_VCO", 1);
	SPIwriteLMS7("LMS7_EN_COARSEPLL", 0);
	SPIwriteLMS7("LMS7_CURLIM_VCO", 1);
	if(LMS7VCOFreq > 5.5e9)
		SPIwriteLMS7("LMS7_EN_DIV2_DIVPROG", 1);
	else
		SPIwriteLMS7("LMS7_EN_DIV2_DIVPROG", 0);
	SPIwriteLMS7("LMS7_EN_INTONLY_SDM", 0);
	SPIwriteLMS7("LMS7_EN_SDM_CLK", 1);

	SPIwriteLMS7("LMS7_PD_FBDIV", 0);
	SPIwriteLMS7("LMS7_PD_LOCH_T2RBUF", 1);
	SPIwriteLMS7("LMS7_PD_CP", 0);
	SPIwriteLMS7("LMS7_PD_FDIV", 0);
	SPIwriteLMS7("LMS7_PD_SDM", 0);
	SPIwriteLMS7("LMS7_PD_VCO_COMP", 0);
	SPIwriteLMS7("LMS7_PD_VCO", 0);
	SPIwriteLMS7("LMS7_EN_G", 1);

	int INTMOD, FRACMOD;
	int refClock = 30.72e6;
	uint16_t div2 = Get_SPI_Reg_bitsLMS7(LMS7_EN_DIV2_DIVPROG);
	INTMOD = floor(LMS7VCOFreq / (refClock*pow(2, div2)));
	FRACMOD = round(pow(2, 20) * (LMS7VCOFreq / (refClock*pow(2, div2))));

// FINISH THE IMPLEMENTATION !!! ...

//	FRACMODL = FRACMOD % (int)pow(2, 16);
//	FRACMODH = FRACMOD / (int)pow(2, 16);
*/
	/*

	# Calculate FB-DIV Configuration
	if (IntN_MODE):
	N_INT=round((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)
	N_FRAC=0
	F_VCO=2.0**self.EN_DIV2_DIVPROG*N_INT*F_REF
	else:
	N_INT=floor((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)
	N_FRAC=(2.0**20)*(((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)-N_INT)

	# Set PLL to operate in IntN-Mode if targeted frequency is integer multiple of reference frequency and user did not set IntN_MODE argument to True
	if (N_FRAC==0 and IntN_MODE==False):
	self.EN_INTONLY_SDM=1
	self.EN_SDM_CLK=0

	# Activate PLL
	self.RESET_N=1

	# Write FB-DIV Configuration
	self.INT_SDM=(int(N_INT)-4)
	#print N_FRAC
	self.FRAC_SDM=int(N_FRAC)

	# Scale VCO Bias Current to maximum value
	self.ICT_VCO=255


	# Start VCO Coarse-Tuning Algo.

	# Find optimal VCO core for targeted frequency
	self.SEL_VCO=1
	self.CSW_VCO=7

	sleep(0.01)

	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	if (VTUNE_LOW):
	self.SEL_VCO=0
	else:
	self.CSW_VCO=247
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	if (VTUNE_HIGH):
	self.SEL_VCO=2
	else:
	self.SEL_VCO=1

	# Find inital CSW_VCO for targeted frequency
	csw_low=0
	csw_high=255
	csw=int((csw_high+csw_low+1)/2.0)
	iter_num=0
	while(csw_low<csw_high and iter_num<=8):
	iter_num+=1
	self.CSW_VCO=csw
	sleep(0.01)

	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO


	if (VTUNE_HIGH):
	#print 'VTUNE HIGH'
	csw_low=csw
	csw=int((csw_high+csw_low+1)/2.0)
	elif (VTUNE_LOW):
	csw_high=csw
	csw=int((csw_high+csw_low+1)/2.0)
	else:
	break

	print "1st step of VCO Coarse Tuning Finished."
	print '-'*60
	print 'SEL_VCO= %d' %(int(self.SEL_VCO))
	print 'CSW_VCO= %d' %(int(self.CSW_VCO))
	print '-'*60
	print ''
	print ''

	csw_init=csw
	# Find 1st CSW_VCO where VTUNE_LOW=1
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	while (VTUNE_LOW==0):
	csw+=1
	if (csw>=255):
	break
	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	csw_max=csw

	# Find 1st CSW_VCO where VTUNE_HIGH=1
	csw=csw_init
	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	while (VTUNE_HIGH==0):
	csw=csw-1
	if (csw<=0):
	break

	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	csw_min=csw

	csw_opt=int((csw_min+csw_max)/2.0)
	self.CSW_VCO=csw_opt
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	print 'VCO Coarse Frequency Tuning Done.'
	print '-'*60
	print 'SEL_VCO= %d' %(self.SEL_VCO)
	print 'CSW_VCO= %d' %(self.CSW_VCO)
	print 'min(CSW_VCO)= %d' %(csw_min)
	print 'max(CSW_VCO)= %d' %(csw_max)
	print 'VTUNE_HIGH=%d, VTUNE_LOW=%d' %(VTUNE_HIGH, VTUNE_LOW)
	print '-'*60
	print ''
	print ''

	return 0
	*/

	/*
	def VCO_CTUNE(self, F_VCO, F_REF=30.72e6, IntN_MODE=False):
	"""
	VCO Coarse Tuning. In closed-loop mode, based on feedback from VTUNE monitoring circuit.
	F_VCO - desired VCO frequency
	F_REF - value of PLL reference frequency
	"""
	# Reset PLL
	self.RESET_N=0



	# Enable PLL Blocks
	self.SPDUP_VCO=0
	self.BYPLDO_VCO=1
	self.EN_COARSEPLL=0
	self.CURLIM_VCO=1
	if (F_VCO>5.5e9):
	self.EN_DIV2_DIVPROG=1
	else:
	self.EN_DIV2_DIVPROG=0
	if (IntN_MODE):
	self.EN_INTONLY_SDM=1
	self.EN_SDM_CLK=0
	else:
	self.EN_INTONLY_SDM=0
	self.EN_SDM_CLK=1

	self.PD_FBDIV=0
	self.PD_LOCH_T2RBUF=1
	self.PD_CP=0
	self.PD_FDIV=0
	self.PD_SDM=0
	self.PD_VCO_COMP=0
	self.PD_VCO=0
	self.EN_G=1



	# Calculate FB-DIV Configuration
	if (IntN_MODE):
	N_INT=round((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)
	N_FRAC=0
	F_VCO=2.0**self.EN_DIV2_DIVPROG*N_INT*F_REF
	else:
	N_INT=floor((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)
	N_FRAC=(2.0**20)*(((F_VCO/2.0**self.EN_DIV2_DIVPROG)/F_REF)-N_INT)

	# Set PLL to operate in IntN-Mode if targeted frequency is integer multiple of reference frequency and user did not set IntN_MODE argument to True
	if (N_FRAC==0 and IntN_MODE==False):
	self.EN_INTONLY_SDM=1
	self.EN_SDM_CLK=0

	# Activate PLL
	self.RESET_N=1

	# Write FB-DIV Configuration
	self.INT_SDM=(int(N_INT)-4)
	#print N_FRAC
	self.FRAC_SDM=int(N_FRAC)

	# Scale VCO Bias Current to maximum value
	self.ICT_VCO=255


	# Start VCO Coarse-Tuning Algo.

	# Find optimal VCO core for targeted frequency
	self.SEL_VCO=1
	self.CSW_VCO=7

	sleep(0.01)

	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	if (VTUNE_LOW):
	self.SEL_VCO=0
	else:
	self.CSW_VCO=247
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	if (VTUNE_HIGH):
	self.SEL_VCO=2
	else:
	self.SEL_VCO=1

	# Find inital CSW_VCO for targeted frequency
	csw_low=0
	csw_high=255
	csw=int((csw_high+csw_low+1)/2.0)
	iter_num=0
	while(csw_low<csw_high and iter_num<=8):
	iter_num+=1
	self.CSW_VCO=csw
	sleep(0.01)

	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO


	if (VTUNE_HIGH):
	#print 'VTUNE HIGH'
	csw_low=csw
	csw=int((csw_high+csw_low+1)/2.0)
	elif (VTUNE_LOW):
	csw_high=csw
	csw=int((csw_high+csw_low+1)/2.0)
	else:
	break

	print "1st step of VCO Coarse Tuning Finished."
	print '-'*60
	print 'SEL_VCO= %d' %(int(self.SEL_VCO))
	print 'CSW_VCO= %d' %(int(self.CSW_VCO))
	print '-'*60
	print ''
	print ''

	csw_init=csw
	# Find 1st CSW_VCO where VTUNE_LOW=1
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	while (VTUNE_LOW==0):
	csw+=1
	if (csw>=255):
	break
	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	csw_max=csw

	# Find 1st CSW_VCO where VTUNE_HIGH=1
	csw=csw_init
	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO
	while (VTUNE_HIGH==0):
	csw=csw-1
	if (csw<=0):
	break

	self.CSW_VCO=csw
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	csw_min=csw

	csw_opt=int((csw_min+csw_max)/2.0)
	self.CSW_VCO=csw_opt
	sleep(0.01)
	VTUNE_HIGH=1-self.VCO_CMPHO
	VTUNE_LOW=self.VCO_CMPLO

	print 'VCO Coarse Frequency Tuning Done.'
	print '-'*60
	print 'SEL_VCO= %d' %(self.SEL_VCO)
	print 'CSW_VCO= %d' %(self.CSW_VCO)
	print 'min(CSW_VCO)= %d' %(csw_min)
	print 'max(CSW_VCO)= %d' %(csw_max)
	print 'VTUNE_HIGH=%d, VTUNE_LOW=%d' %(VTUNE_HIGH, VTUNE_LOW)
	print '-'*60
	print ''
	print ''

	return 0
	*/
}

void dlgMeasurements::OnUpdateUIChkMeasUseBandMarker(wxUpdateUIEvent& event)
{
	txtMeasBandMarkerBand->Enable(chkMeasUseBandMarker->GetValue());
}

void dlgMeasurements::OnLMS7ControlBoardConnect(wxCommandEvent& event)
{
	//msavic ovdi!!!
//	const int controlCollumn = 1;
	if (lms7controlPort->IsOpen())
	{
		LMSinfo info = lms7controlPort->GetInfo();
		wxString controlDev = _("Control port LMS7: ");
		controlDev.Append(wxString::From8BitData(GetDeviceName(info.device)));
		controlDev.Append(wxString::Format(_(" FW:%i HW:%i Protocol:%i"), (int)info.firmware, (int)info.hardware, (int)info.protocol));
//		statusBar->SetStatusText(controlDev, controlCollumn);
		lblStatus->SetLabelText(controlDev);

		wxCommandEvent evt;
		evt.SetEventType(LOG_MESSAGE);
		evt.SetString(_("Connected LMS7 ") + controlDev);
		wxPostEvent(this, evt);

		//msavic ovdi!!!
		// Here setup the LMS7
		// Set DC REG for I & Q
		long value = 0x7fff;
		Modify_SPI_Reg_bitsLMS7(LMS7_DC_REG_TXTSP, value);
		// Load to I
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDI_TXTSP, 0);
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDI_TXTSP, 1);
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDI_TXTSP, 0);
		// Load to Q
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDQ_TXTSP, 0);
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDQ_TXTSP, 1);
		Modify_SPI_Reg_bitsLMS7(LMS7_TSGDCLDQ_TXTSP, 0);
	}
	else
	{
//		statusBar->SetStatusText(_("Control port: Not Connected"), controlCollumn);
		lblStatus->SetLabelText(_("Control port LMS7: Not Connected"));
		wxCommandEvent evt;
		evt.SetEventType(LOG_MESSAGE);
		evt.SetString(_("Disconnected control port LMS7"));
		wxPostEvent(this, evt);
	}
}