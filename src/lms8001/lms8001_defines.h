/**
@file	lms8001_defines.h
@author Lime Microsystems
@brief	enumerations of available LMS8001 commands and statuses
*/
#pragma once

const int LMS_RST_DEACTIVATE = 0;
const int LMS_RST_ACTIVATE = 1;
const int LMS_RST_PULSE = 2;

enum eLMS_DEV
{
	LMS_DEV_UNKNOWN,
	LMS_DEV_EVB8,

	LMS_DEV_COUNT
};

const char LMS_DEV_NAMES[][80] = 
{
	"UNKNOWN",
	"EVB8"
};

static const char* GetDeviceName(const eLMS_DEV device)
{
    if (LMS_DEV_UNKNOWN < device && device < LMS_DEV_COUNT)
        return LMS_DEV_NAMES[device];
    else
        return LMS_DEV_NAMES[LMS_DEV_UNKNOWN];
}

enum eCMD_LMS
{
    CMD_GET_INFO = 0x00,
    ///Writes data to SI5351 synthesizer via I2C
    CMD_SI5351_WR = 0x13,
    ///Reads data from SI5351 synthesizer via I2C
    CMD_SI5351_RD = 0x14,
    ///Sets new LMS8001 chip’s RESET pin level (0, 1, pulse)

//    CMD_LMS8001_RST = 0x20,
    ///Writes data to LMS8001 chip via SPI
	CMD_LMS7002_WR = 0x21,
    ///Reads data from LMS8001 chip via SPI
	CMD_LMS7002_RD = 0x22,

	CMD_LMS8001_RST = 0x20,
	///Writes data to LMS8001 chip via SPI
	CMD_LMS8001_WR = 0x25,
	///Reads data from LMS8001 chip via SPI
	CMD_LMS8001_RD = 0x26,

    CMD_LMS_LNA = 0x2A,
    CMD_LMS_PA = 0x2B,

    CMD_PROG_MCU = 0x2C,

	///Writes data to ADF4002 chip via SPI
	CMD_ADF4002_WR = 0x31,

    CMD_USB_FIFO_RST = 0x40,

//	CMD_GPIO_STP = 0x50,
	CMD_GPIO_WR = 0x51,
	CMD_GPIO_RD = 0x52,

	CMD_BRDSPI_WR = 0x55,//16 bit spi for stream, dataspark control
	CMD_BRDSPI_RD = 0x56 //16 bit spi for stream, dataspark control
};

enum eCMD_STATUS
{
    STATUS_UNDEFINED,
    STATUS_COMPLETED_CMD,
    STATUS_UNKNOWN_CMD,
    STATUS_BUSY_CMD,
    STATUS_MANY_BLOCKS_CMD,
    STATUS_ERROR_CMD,
    STATUS_WRONG_ORDER_CMD,
	STATUS_RESOURCE_DENIED_CMD,
    STATUS_COUNT
};

static const char  status_text[][32]=
{
    "Undefined/Failure",
    "Completed",
    "Unknown command",
    "Busy",
    "Too many blocks",
    "Error",
    "Wrong order",
    "Resource denied"
};

static const char* status2string(const int status)
{
    if(status >= 0 && status < STATUS_COUNT)
        return status_text[status];
    else
        return "Unknown status";
}