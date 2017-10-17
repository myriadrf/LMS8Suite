/**
@file	LMS8001_statuses.cpp
@author Lime Microsystems (www.limemicro.com)
*/

#include "LMS8001_statuses.h"

const char* undefinedStatusStr = "undefined status";

const char* liblms8_status2string(liblms8_status status)
{
    if (status >= 0 && status < LIBLMS8_STATUS_COUNT)
        return liblms8_status_strings[status];
    else
        return undefinedStatusStr;
}
