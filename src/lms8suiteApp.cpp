/***************************************************************
 * Name:      lms8projectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Lime Microsystems ()
 * Created:   2015-03-05
 * Copyright: Lime Microsystems (limemicro.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "lms8suiteApp.h"
#include "lms8suiteAppFrame.h"
#include <wx/time.h>
#include <wx/splash.h>
#include <iostream>
 //msavic 151106
 /*
 #ifndef NDEBUG
 IMPLEMENT_APP_CONSOLE(lms8suiteApp);
 #else
 IMPLEMENT_APP(lms8suiteApp);
 #endif
 */

 //msavic 151106 {
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
	char *buf;

	buf = new char[wcslen(lpCmdLine) + 1];

	wcstombs(buf, lpCmdLine, wcslen(lpCmdLine) + 1);

	wxApp::SetInstance(new lms8suiteApp());

	wxEntry(hInstance, prevInstance, buf, nShowCmd);

	wxEntryCleanup();
}
//msavic 151106 }


#include "splash_image.h"

bool lms8suiteApp::OnInit()
{
    wxInitAllImageHandlers();
    wxBitmap splashBitmap = wxBITMAP_PNG_FROM_DATA(splash);
    wxSplashScreen* splash = new wxSplashScreen(splashBitmap,
        wxSPLASH_CENTRE_ON_SCREEN,
        6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxSIMPLE_BORDER | wxSTAY_ON_TOP);
    wxYield(); //linux needs this to load splash image
    wxLongLong t1 = wxGetUTCTimeMillis();
    LMS8SuiteAppFrame* frame = new LMS8SuiteAppFrame(0L);
#ifndef NDEBUG
    std::cout << "Create time " << (wxGetUTCTimeMillis() - t1).ToString() << " ms\n";
#endif
    splash->Destroy();
    frame->Show();
    return true;
}
