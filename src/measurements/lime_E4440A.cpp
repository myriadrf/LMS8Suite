#include <lime_E4440A.h>

std::wstring my_A2WS(char* astr) {
	size_t newsize = strlen(astr) + 1;
	wchar_t * wcstring = new wchar_t[newsize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize, astr, _TRUNCATE);
	std::wstring r(wcstring);
	delete[] wcstring;
	return r;
}

void E4440A::debug_log(char* message){

#ifdef E4440A_DEBUG
	time_t timer;
	char buffer[26];
	struct tm* tm_info;

	time(&timer);
	tm_info = localtime(&timer);

	strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
	
	fprintf(log_fp, "%s: %s\n", buffer, message);
#endif

}

void E4440A::getInfo() {
	strcpy(info, GPIB_query("*IDN?"));
}

float E4440A::getRFAttenuation() {
	float att;
	C8 *span_text = GPIB_query(":SENS:POW:RF:ATT?");
	sscanf(span_text, "%f", &att);
	return att;
}

void E4440A::setRFAttenuation(float att) {
	char command[512] = "";
	sprintf(command, ":SENS:POW:RF:ATT %f;*OPC?", att);
	GPIB_query(command);
}

void E4440A::getDetectorType(char* detType) {
	strcpy(detType, GPIB_query(":SENS:DET?"));
}

void E4440A::setDetectorType(char* detType) {
	char command[512] = "";
	sprintf(command, ":SENS:DET %s;*OPC?", detType);
	GPIB_query(command);
}

/****************************************************************
*   Spectrum analyzer phase noise optimization options
****************************************************************/

int E4440A::getPhaseNoiseOpt() {
	int phaseNoiseOpt;
	C8 *span_text = GPIB_query(":SENS:FREQ:SYNT?");
	sscanf(span_text, "%d", &phaseNoiseOpt);
	return phaseNoiseOpt;
}

void E4440A::setPhaseNoiseOpt(int phaseNoiseOpt) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:SYNT %d;*OPC?", phaseNoiseOpt);
	GPIB_query(command);
}

void E4440A::getPhaseNoiseOptAuto(char* phaseNoiseOptAuto) {
	strcpy(phaseNoiseOptAuto, GPIB_query(":SENS:FREQ:SYNT:AUTO?"));
}

void E4440A::setPhaseNoiseOptAuto(char* phaseNoiseOptAuto) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:SYNT:AUTO %s;*OPC?", phaseNoiseOptAuto);
	GPIB_query(command);
}

/****************************************************************
*     Center, start, stop frequency; Frequency span
*     Number of sweep points, sweep time
****************************************************************/

int E4440A::getNumberOfSweepPoints() {
	int numberOfSweepPoints;
	C8 *span_text = GPIB_query(":SENS:SWEEP:POINTS?");
	sscanf(span_text, "%d", &numberOfSweepPoints);
	return numberOfSweepPoints;
}

void E4440A::setNumberOfSweepPoints(int nPoints) {
	char command[512] = "";
	sprintf(command, ":SENS:SWEEP:POINTS %d;*OPC?", nPoints);
	GPIB_query(command);
}

S64 E4440A::getCenterFrequency() {
	S64 centerFrequency;
	F64 fCenterFrequency;
	C8 *span_text = GPIB_query(":SENS:FREQ:CENT?");
	sscanf(span_text, "%Lg", &fCenterFrequency);
	centerFrequency = fCenterFrequency;
	return centerFrequency;
}

void E4440A::setCenterFrequency(S64 centerFrequency) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:CENT %I64d HZ;*OPC?", centerFrequency);
	GPIB_query(command);

	char debug_message[2048];
	sprintf(debug_message, "setCenterFrequency: Sent: %s", command);
	debug_log(debug_message);
}

S64 E4440A::getStartFrequency() {
	S64 startFrequency;
	F64 fStartFrequency;
	C8 *span_text = GPIB_query(":SENS:FREQ:STAR?");
	sscanf(span_text, "%Lg", &fStartFrequency);
	startFrequency = fStartFrequency;
	return startFrequency;
}

void E4440A::setStartFrequency(S64 startFrequency) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:STAR %I64d HZ;*OPC?", startFrequency);
	GPIB_query(command);
}

S64 E4440A::getStopFrequency() {
	S64 stopFrequency;
	F64 fStopFrequency;
	C8 *span_text = GPIB_query(":SENS:FREQ:STOP?");
	sscanf(span_text, "%Lg", &fStopFrequency);
	stopFrequency = fStopFrequency;
	return stopFrequency;
}

void E4440A::setStopFrequency(S64 stopFrequency) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:STOP %I64d HZ;*OPC?", stopFrequency);
	GPIB_query(command);
}

S64 E4440A::getFrequencySpan() {
	S64 frequencySpan;
	F64 fFrequencySpan;
	C8 *span_text = GPIB_query(":SENS:FREQ:SPAN?");
	sscanf(span_text, "%Lg", &fFrequencySpan);
	frequencySpan = fFrequencySpan;
	return frequencySpan;
}

void E4440A::setFrequencySpan(S64 frequencySpan) {
	char command[512] = "";
	sprintf(command, ":SENS:FREQ:SPAN %I64d HZ;*OPC?", frequencySpan);
	GPIB_query(command);

	char debug_message[2048];
	sprintf(debug_message, "setFrequencySpan: Sent: %s", command);
	debug_log(debug_message);
}

/****************************************************************
*     Sweep time
****************************************************************/

float E4440A::getSweepTime() {
	float sweepTime;
	C8 *span_text = GPIB_query(":SENS:SWEEP:TIME?");
	sscanf(span_text, "%f", &sweepTime);
	return sweepTime;
}

void E4440A::setSweepTime(float sweepTimeInMs) {
	char command[512] = "";
	sprintf(command, ":SENS:SWEEP:TIME %f ms;*OPC?", sweepTimeInMs);
	GPIB_query(command);
}

void E4440A::getSweepTimeAuto(char* sweepTimeAuto) {
	strcpy(sweepTimeAuto, GPIB_query(":SENS:SWEEP:TIME:AUTO?"));
}

void E4440A::setSweepTimeAuto(char* sweepTimeAuto) {
	char command[512] = "";
	sprintf(command, ":SENS:SWEEP:TIME:AUTO %s;*OPC?", sweepTimeAuto);
	GPIB_query(command);
}

/****************************************************************
*     Video bandwidth
****************************************************************/

int E4440A::getVideoBandwidth() {
	int videoBandwidth;
	C8 *span_text = GPIB_query(":SENS:BAND:VID?");
	sscanf(span_text, "%d", &videoBandwidth);
	return videoBandwidth;
}

void E4440A::setVideoBandwidth(int videoBandwidth) {
	char command[512] = "";
	sprintf(command, ":SENS:BAND:VID %d HZ;*OPC?", videoBandwidth);
	GPIB_query(command);
}

void E4440A::getVideoBandwidthAuto(char* videoBandwidthAuto) {
	strcpy(videoBandwidthAuto, GPIB_query(":SENS:BAND:VID:AUTO?"));
}

void E4440A::setVideoBandwidthAuto(char* videoBandwidthAuto) {
	char command[512] = "";
	sprintf(command, ":SENS:BAND:VID:AUTO %s;*OPC?", videoBandwidthAuto);
	GPIB_query(command);
}

/****************************************************************
*     Resolution bandwidth
****************************************************************/

int E4440A::getResolutionBandwidth() {
	int resolutionBandwidth;
	C8 *span_text = GPIB_query(":SENS:BAND:RES?");
	sscanf(span_text, "%d", &resolutionBandwidth);
	return resolutionBandwidth;
}

void E4440A::setResolutionBandwidth(int resolutionBandwidth) {
	char command[512] = "";
	sprintf(command, ":SENS:BAND:RES %d HZ;*OPC?", resolutionBandwidth);
	GPIB_query(command);
}

void E4440A::getResolutionBandwidthAuto(char* resolutionBandwidthAuto) {
	strcpy(resolutionBandwidthAuto, GPIB_query(":SENS:BAND:RES:AUTO?"));
}

void E4440A::setResolutionBandwidthAuto(char* resolutionBandwidthAuto) {
	char command[512] = "";
	sprintf(command, ":SENS:BAND:RES:AUTO %s;*OPC?", resolutionBandwidthAuto);
	GPIB_query(command);
}

/****************************************************************
*     Y scale settings
****************************************************************/

int E4440A::getYdiv() {
	int ydiv;
	C8 *span_text = GPIB_query(":DISP:WIND:TRAC:Y:PDIV?");
	sscanf(span_text, "%d", &ydiv);
	return ydiv;
}

void E4440A::setYdiv(int ydiv) {
	char command[512] = "";
	sprintf(command, ":DISP:WIND:TRAC:Y:PDIV %d DB;*OPC?", ydiv);
	GPIB_query(command);
}

float E4440A::getReferenceLevel() {
	float referenceLevel;
	C8 *span_text = GPIB_query(":DISP:WIND:TRAC:Y:RLEV?");
	sscanf(span_text, "%f", &referenceLevel);
	return referenceLevel;
}

void E4440A::setReferenceLevel(double referenceLevel) {
	char command[512] = "";
	sprintf(command, "DISP:WIND:TRAC:Y:RLEV %f DBM;*OPC?", referenceLevel);
	GPIB_query(command);
}

/****************************************************************
*     Markers
****************************************************************/

float E4440A::getMarkerState(int markerNo) {
	float markerState;
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:STAT?", markerNo);
	C8 *span_text = GPIB_query(command);
	sscanf(span_text, "%f", &markerState);
	return markerState;
}

void E4440A::setReferenceLevel(int markerNo, float markerState) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:STAT %f;*OPC?", markerNo, markerState);
	GPIB_query(command);

	char debug_message[2048];
	sprintf(debug_message, "setReferenceLevel: Sent: %s", command);
	debug_log(debug_message);
}

void E4440A::getMarkerMode(int markerNo, char* markerMode) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:MODE?", markerNo);
	strcpy(markerMode, GPIB_query(command));
}

void E4440A::setMarkerMode(int markerNo, char* markerMode) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:MODE %s;*OPC?", markerNo, markerMode);
	GPIB_query(command);
}

S64 E4440A::getMarkerX(int markerNo) {
	S64 markerX;
	F64 fMarkerX;
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:X?", markerNo);
	C8 *span_text = GPIB_query(command);
	sscanf(span_text, "%Lg", &fMarkerX);
	markerX = fMarkerX;
	return markerX;

	char debug_message[2048];
	sprintf(debug_message, "getMarkerX: Sent: %s", command);
	debug_log(debug_message);
	sprintf(debug_message, "getMarkerX: Received: %s", span_text);
	debug_log(debug_message);
}

void E4440A::setMarkerX(int markerNo, S64 markerX) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:X %I64d;*OPC?", markerNo, markerX);
	GPIB_query(command);
}

int E4440A::getMarkerXPos(int markerNo) {
	int markerXPos;
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:X:POS?", markerNo);
	C8 *span_text = GPIB_query(command);
	sscanf(span_text, "%d", &markerXPos);
	return markerXPos;
}

void E4440A::setMarkerXPos(int markerNo, int markerXPos) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:X:POS %d;*OPC?", markerNo, markerXPos);
	GPIB_query(command);
}

float E4440A::getMarkerY(int markerNo) {
	float markerY;
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:Y?", markerNo);
	C8 *span_text = GPIB_query(command);
	sscanf(span_text, "%g", &markerY);

	char debug_message[2048];
	sprintf(debug_message, "getMarkerY: Sent: %s", command);
	debug_log(debug_message);
	sprintf(debug_message, "getMarkerY: Received: %s", span_text);
	debug_log(debug_message);

	return markerY;
}

void E4440A::peakSearch(int markerNo) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:MAX;*OPC?", markerNo);
	GPIB_query(command);
}

void E4440A::getMarkerFn(int markerNo, char* markerFn) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:FUNC?", markerNo);
	strcpy(markerFn, GPIB_query(command));
}

void E4440A::setMarkerFn(int markerNo, char* markerFn) {
	char command[512] = "";
	sprintf(command, ":CALC:MARK%d:FUNC %s;*OPC?", markerNo, markerFn);
	GPIB_query(command);
}

/****************************************************************
*     Complex functions
****************************************************************/
//void E4440A::findCarrier(S64 startFreq, S64 startSpan, S64 stopSpan, S64* X, double* Y) {
void E4440A::findCarrier(S64 startFreq, S64 startSpan, S64 stopSpan, S64* X, double* Y, bool bandMarker, long bandMarkerBW)
{
	S64 Xintern;
	double Yintern;

	setRFAttenuation(0);
	setDetectorType("RMS");
	setReferenceLevel(0.0);
	setCenterFrequency(startFreq);
	setFrequencySpan(startSpan);
	setMarkerMode(1, "POS");
	S64 freqSpan = startSpan;

//	while (freqSpan>10e3) {
	while (freqSpan>stopSpan) {
		Sleep(1000);
		peakSearch(1);
		Xintern = getMarkerX(1);
		Yintern = getMarkerY(1);
		setCenterFrequency(Xintern);
		setReferenceLevel(Yintern + 1.0);
		freqSpan = freqSpan / 10;
		setFrequencySpan(freqSpan);
	}
	peakSearch(1);
	Sleep(1000);
	peakSearch(1);

	if (bandMarker)
	{
		setMarkerMode(1, "BAND");
		char command[512] = "";
		sprintf(command, ":CALC:MARK1:X:START %I64d;*OPC?", Xintern - bandMarkerBW/2);
		GPIB_query(command);
		sprintf(command, ":CALC:MARK1:X:STOP %I64d;*OPC?", Xintern + bandMarkerBW / 2);
		GPIB_query(command);
		GPIB_query(":CALC:MARK:FUNC BPOW;*OPC?");

//		instrument.setMarkerMode(1, "BAND")
//		instrument._send(":CALC:MARK1:X:START " + str(x - integrationBand / 2))
//		instrument._send(":CALC:MARK1:X:STOP " + str(x + integrationBand / 2))
//		instrument._send(":CALC:MARK:FUNC BPOW")
	}

	GPIB_query("AVER:COUN 10;*OPC?");
	GPIB_query("AVER ON;*OPC?");
	Xintern = getMarkerX(1);
	Yintern = getMarkerY(1);

	*X = Xintern;
	*Y = Yintern;
}

