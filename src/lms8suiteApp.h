/***************************************************************
 * Name:      lms8projectApp.h
 * Purpose:   Defines Application Class
 * Author:    Lime Microsystems ()
 * Created:   2015-03-05
 * Copyright: Lime Microsystems (limemicro.com)
 * License:
 **************************************************************/

#ifndef LMS8PROJECTAPP_H
#define LMS8PROJECTAPP_H

#include <wx/app.h>

class ConnectionManager;

class lms8suiteApp : public wxApp
{
    public:
        virtual bool OnInit();		
};

#endif // LMS8PROJECTAPP_H
