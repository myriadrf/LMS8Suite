/**
@file	lms7002_defines.h
@author Lime Microsystems
@brief	enumerations of available LMS7002M commands and statuses
*/
#pragma once

enum eCMD_LMS_LMS7
{
    LMS7_CMD_GET_INFO = 0x00,
	LMS7_CMD_LMS6002_RST = 0x10,
    ///Writes data to SI5356 synthesizer via I2C
	LMS7_CMD_SI5356_WR = 0x11,
    ///Reads data from SI5356 synthesizer via I2C
	LMS7_CMD_SI5356_RD = 0x12,
    ///Writes data to SI5351 synthesizer via I2C
	LMS7_CMD_SI5351_WR = 0x13,
    ///Reads data from SI5351 synthesizer via I2C
	LMS7_CMD_SI5351_RD = 0x14,
    ///PanelBus DVI (HDMI) Transmitter control
	LMS7_CMD_TFP410_WR = 0x15,
    ///PanelBus DVI (HDMI) Transmitter control
	LMS7_CMD_TFP410_RD = 0x16,
    ///Sets new LMS7002M chip’s RESET pin level (0, 1, pulse)
	LMS7_CMD_LMS7002_RST = 0x20,
    ///Writes data to LMS7002M chip via SPI
	LMS7_CMD_LMS7002_WR = 0x21,
    ///Reads data from LMS7002M chip via SPI
	LMS7_CMD_LMS7002_RD = 0x22,
    ///Writes data to LMS6002 chip via SPI
	LMS7_CMD_LMS6002_WR = 0x23,
    ///Reads data from LMS6002 chip via SPI
	LMS7_CMD_LMS6002_RD = 0x24,

	LMS7_CMD_LMS_LNA = 0x2A,
	LMS7_CMD_LMS_PA = 0x2B,

	LMS7_CMD_PROG_MCU = 0x2C,
    ///Writes data to ADF4002 chip via SPI
	LMS7_CMD_ADF4002_WR = 0x31,

	LMS7_CMD_USB_FIFO_RST = 0x40,
	LMS7_CMD_PE636040_WR = 0x41,
	LMS7_CMD_PE636040_RD = 0x42,

	LMS7_CMD_GPIO_WR = 0x51,
	LMS7_CMD_GPIO_RD = 0x52,

	LMS7_CMD_ALTERA_FPGA_GW_WR = 0x53,
	LMS7_CMD_ALTERA_FPGA_GW_RD = 0x54,

	LMS7_CMD_BRDSPI_WR = 0x55,//16 bit spi for stream, dataspark control
	LMS7_CMD_BRDSPI_RD = 0x56,//16 bit spi for stream, dataspark control
	LMS7_CMD_BRDSPI8_WR = 0x57, //8 + 8 bit spi for stream, dataspark control
	LMS7_CMD_BRDSPI8_RD = 0x58, //8 + 8 bit spi for stream, dataspark control
	
	LMS7_CMD_BRDCONF_WR = 0x5D, //write config data to board
	LMS7_CMD_BRDCONF_RD = 0x5E, //read config data from board
	
	LMS7_CMD_ANALOG_VAL_WR = 0x61, //write analog value
	LMS7_CMD_ANALOG_VAL_RD = 0x62, //read analog value

	LMS7_CMD_MYRIAD_RST = 0x80,
	LMS7_CMD_MYRIAD_WR = 0x81,
	LMS7_CMD_MYRIAD_RD = 0x82,
	LMS7_CMD_MYRIAD_PROG = 0x8C
};

enum eCMD_STATUS_LMS7
{
	LMS7_STATUS_UNDEFINED,
	LMS7_STATUS_COMPLETED_CMD,
	LMS7_STATUS_UNKNOWN_CMD,
	LMS7_STATUS_BUSY_CMD,
	LMS7_STATUS_MANY_BLOCKS_CMD,
	LMS7_STATUS_ERROR_CMD,
	LMS7_STATUS_WRONG_ORDER_CMD,
	LMS7_STATUS_RESOURCE_DENIED_CMD,
	LMS7_STATUS_COUNT
};

static const char  status_text_LMS7[][32]=
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

static const char* status2string_LMS7(const int status)
{
    if(status >= 0 && status < LMS7_STATUS_COUNT)
        return status_text_LMS7[status];
    else
        return "Unknown status";
}

enum eADC_UNITS_LMS7
{
	LMS7_RAW,
	LMS7_VOLTAGE,
	LMS7_CURRENT,
	LMS7_RESISTANCE,
	LMS7_POWER,
	LMS7_ADC_UNITS_COUNT
};

static const char  adc_units_text_LMS7[][8] = {"", "V", "A", "Ohm", "W"};

static const char* adcUnits2string_LMS7(const unsigned units)
{
	if (units < LMS7_ADC_UNITS_COUNT)
		return adc_units_text_LMS7[units];
	else
		return " unknown";
}
