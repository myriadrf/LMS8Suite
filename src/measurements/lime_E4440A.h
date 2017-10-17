#ifndef _INC_LIME_E4440A
#define _INC_LIME_E4440A

//#define E4440A_DEBUG

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "gpiblib.h"
#include <string>
#include <cstring>

std::wstring my_A2WS(char* astr);

class E4440A {
	public:
		char info[512] = "";
		
		FILE* log_fp;
		
		E4440A(){
#ifdef E4440A_DEBUG
			log_fp = fopen("msavic_debug_E4440A.log", "a");					
#endif /* E4440A_DEBUG */
		}
		
		~E4440A(){
#ifdef E4440A_DEBUG
			fclose(log_fp);
#endif /* E4440A_DEBUG */
		}
		
		void debug_log(char* message);
		void getInfo();
		float getRFAttenuation();
		void setRFAttenuation(float att);
		void getDetectorType(char* detType);
		void setDetectorType(char* detType);
		
/****************************************************************
*   Spectrum analyzer phase noise optimization options
****************************************************************/    
    
		int getPhaseNoiseOpt();
		void setPhaseNoiseOpt(int phaseNoiseOpt);
		void getPhaseNoiseOptAuto(char* phaseNoiseOptAuto);
		void setPhaseNoiseOptAuto(char* phaseNoiseOptAuto);
		
/****************************************************************
*     Center, start, stop frequency; Frequency span
*     Number of sweep points, sweep time
****************************************************************/    

		int getNumberOfSweepPoints();
		void setNumberOfSweepPoints(int nPoints);
		S64 getCenterFrequency();
		void setCenterFrequency(S64 centerFrequency);
		S64 getStartFrequency();
		void setStartFrequency(S64 startFrequency);
		S64 getStopFrequency();
		void setStopFrequency(S64 stopFrequency);
		S64 getFrequencySpan();
		void setFrequencySpan(S64 frequencySpan);

/****************************************************************
*     Sweep time
****************************************************************/    

		float getSweepTime();
		void setSweepTime(float sweepTimeInMs);
		void getSweepTimeAuto(char* sweepTimeAuto);
		void setSweepTimeAuto(char* sweepTimeAuto);

/****************************************************************
*     Video bandwidth
****************************************************************/    

		int getVideoBandwidth();
		void setVideoBandwidth(int videoBandwidth);
		void getVideoBandwidthAuto(char* videoBandwidthAuto);
		void setVideoBandwidthAuto(char* videoBandwidthAuto);

/****************************************************************
*     Resolution bandwidth
****************************************************************/    

		int getResolutionBandwidth();
		void setResolutionBandwidth(int resolutionBandwidth);
		void getResolutionBandwidthAuto(char* resolutionBandwidthAuto);
		void setResolutionBandwidthAuto(char* resolutionBandwidthAuto);

/****************************************************************
*     Y scale settings
****************************************************************/    

		int getYdiv();
		void setYdiv(int ydiv);
		float getReferenceLevel();
		void setReferenceLevel(double referenceLevel);
		
/****************************************************************
*     Markers
****************************************************************/    

		float getMarkerState(int markerNo);
		void setReferenceLevel(int markerNo, float markerState);
		void getMarkerMode(int markerNo, char* markerMode);
		void setMarkerMode(int markerNo, char* markerMode);
		S64 getMarkerX(int markerNo);
		void setMarkerX(int markerNo, S64 markerX);
		int getMarkerXPos(int markerNo);
		void setMarkerXPos(int markerNo, int markerXPos);
		float getMarkerY(int markerNo);
		void peakSearch(int markerNo);
		void getMarkerFn(int markerNo, char* markerFn);
		void setMarkerFn(int markerNo, char* markerFn);

/****************************************************************
*     Complex functions
****************************************************************/
		void findCarrier(S64 startFreq, S64 startSpan, S64 stopSpan, S64* X, double* Y, bool bandMarker = false, long bandMarkerBW = 1000);
};

#endif /* _INC_LIME_E4440A */