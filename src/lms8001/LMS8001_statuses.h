/**
@file	LMS8001_statuses.h
@author Lime Microsystems (www.limemicro.com)
@brief 	LMS8001 control library statuses enumerations
*/

#ifndef LMS8API_STATUSES_H
#define LMS8API_STATUSES_H

const char liblms8_status_strings[][64] =
{
"success",
"failure",
"index out of range",
"too many values",
"connection manager is NULL",
"port not connected",
"frequency out of range",
"cannot deliver frequency",
"VCO is powered down",
"Bad SEL_PATH_RFE",
"Band not selected",
"file not found"
};

enum liblms8_status
{
	LIBLMS8_SUCCESS = 0,
	LIBLMS8_FAILURE,
	LIBLMS8_INDEX_OUT_OF_RANGE,
    LIBLMS8_TOO_MANY_VALUES,
    LIBLMS8_NO_CONNECTION_MANAGER,
    LIBLMS8_NOT_CONNECTED,
    LIBLMS8_FREQUENCY_OUT_OF_RANGE,    
    LIBLMS8_CANNOT_DELIVER_FREQUENCY,
    LIBLMS8_VCO_IS_POWERED_DOWN,
    LIBLMS8_BAD_SEL_PATH,
    LIBLMS8_BAND_NOT_SELECTED,
    LIBLMS8_FILE_NOT_FOUND,

    LIBLMS8_STATUS_COUNT
};

const char* liblms8_status2string(liblms8_status status);

#endif
