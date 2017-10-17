/**
@file LMS8001.cpp
@author Lime Microsystems (www.limemicro.com)
@brief Implementation of LMS8001 transceiver configuring
*/

#include "LMS8001.h"
#include <stdio.h>
#include <set>
#include "lmsComms.h"
#include "INI.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include "LMS8001_RegistersMap.h"

#include <chrono>
#include <thread>

//float_type LMS8001::gVCO_frequency_table[3][2] = { { 3800, 5222 }, { 4961, 6754 }, {6306, 7714} };
//float_type LMS8001::gCGEN_VCO_frequencies[2] = {2000, 2700};

///define for parameter enumeration if prefix might be needed
#define LMS8param(id) id

//module addresses needs to be sorted in ascending order
//msavic: readOnlyRegisters -- FILL THESE VALUES!!!
//const uint16_t LMS8001::readOnlyRegisters[] =      { 0x002F, 0x008C, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x0123, 0x0209, 0x020A, 0x020B, 0x040E, 0x040F };
//const uint16_t LMS8001::readOnlyRegistersMasks[] = { 0x0000, 0x0FFF, 0x007F, 0x0000, 0x0000, 0x0000, 0x0000, 0x003F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };
const uint16_t LMS8001::readOnlyRegisters[] =      { 0x0008, 0x000C, 0x000F, 0x0010, 0x101D, 0x103D, 0x105D, 0x107D, 0x101E, 0x103E, 0x105E, 0x107E, 0x101F, 0x103F, 0x105F, 0x107F, 0x200E, 0x201E, 0x202E, 0x203E, 0x4002, 0x4006, 0x400C, 0x4010, 0x4011 };
const uint16_t LMS8001::readOnlyRegistersMasks[] = { 0x0000, 0xFF00, 0x0000, 0xF7FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF000, 0xFFC3, 0x0000, 0x00FF, 0x0000 };

/** @brief Simple logging function to print status messages
    @param text message to print
    @param type message type for filtering specific information
*/
void LMS8001::Log(const char* text, LogType type)
{
    switch(type)
    {
    case LOG_INFO:
        printf("%s\n", text);
        break;
    case LOG_WARNING:
        printf("Warning: %s\n", text);
        break;
    case LOG_ERROR:
        printf("ERROR: %s\n", text);
        break;
    case LOG_DATA:
        printf("DATA: %s\n", text);
        break;
    }
}

LMS8001::LMS8001() : controlPort(NULL), mRegistersMap(new LMS8001_RegistersMap())
{
//    mRefClkSXR_MHz = 30.72;
//    mRefClkSXT_MHz = 30.72;

    mRefClk_MHz = REF_CLK_MHZ;

	tempSens_T0 = TEMPSENS_T0;
}

/** @brief Creates LMS8001 main control object, it requires LMScomms to communicate with chip
    @param controlPort data connection for controlling LMS8001 chip registers
*/

LMS8001::LMS8001(LMScomms* controlPort) :
    controlPort(controlPort), mRegistersMap(new LMS8001_RegistersMap())
{
//    mRefClkSXR_MHz = 30.72;
//    mRefClkSXT_MHz = 30.72;

    mRefClk_MHz = REF_CLK_MHZ;

	tempSens_T0 = TEMPSENS_T0;

//msavic here
    //memory intervals for registers tests and calibration algorithms
	MemorySectionAddresses[MS_ChipConfig][0] = 0x0000;
	MemorySectionAddresses[MS_ChipConfig][1] = 0x000F;
    MemorySectionAddresses[MS_BiasLDOConfig][0] = 0x0010;
	MemorySectionAddresses[MS_BiasLDOConfig][1] = 0x001F;
	MemorySectionAddresses[MS_Channel][0] = 0x1000;
	MemorySectionAddresses[MS_Channel][1] = 0x107F;
	MemorySectionAddresses[MS_HLMIX][0] = 0x2000;
	MemorySectionAddresses[MS_HLMIX][1] = 0x203F;
	MemorySectionAddresses[MS_PLLConfig][0] = 0x4000;
	MemorySectionAddresses[MS_PLLConfig][1] = 0x401F;
	MemorySectionAddresses[MS_PLLProfiles][0] = 0x4100;
	MemorySectionAddresses[MS_PLLProfiles][1] = 0x417F;

    mRegistersMap->InitializeDefaultValues(LMS8parameterList);
}

LMS8001::~LMS8001()
{

}

/** @brief Sends reset signal to chip, after reset enables B channel controls
    @return 0-success, other-failure
*/
liblms8_status LMS8001::ResetChip()
{
    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_RST;
    pkt.outBuffer.push_back(LMS_RST_PULSE);
    controlPort->TransferPacket(pkt);
    if (pkt.status == STATUS_COMPLETED_CMD)
    {
// msavic
//        Modify_SPI_Reg_bits(LMS8param(MIMO_SISO), 0); //enable B channel after reset
        return LIBLMS8_SUCCESS;
    }
    else
        return LIBLMS8_FAILURE;
}

/** @brief Reads configuration file and uploads registers to chip
    @param filename Configuration source file
    @return 0-success, other-failure
*/
liblms8_status LMS8001::LoadConfig(const char* filename)
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
//	uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC)); //remember used channel

	liblms8_status status;
	typedef INI<string, string, string> ini_t;
	ini_t parser(filename, true);
	parser.select("file_info");
	string type = "";
	//msavic 151023
	//    type = parser.get("type", "undefined");
	type = parser.get("type", string("undefined"));
	//    type = parser.get("type", 0);
	stringstream ss;
	if (type.find("lms8001_minimal_config") == string::npos)
	{
		ss << "File " << filename << " not recognized" << endl;
		return LIBLMS8_FAILURE;
	}

	int fileVersion = 0;
	fileVersion = parser.get("version", 0);

	vector<uint16_t> addrToWrite;
	vector<uint16_t> dataToWrite;

	if (fileVersion == 1)
	{
		parser.select("reference_clock");
		mRefClk_MHz = parser.get("ref_clk_mhz", REF_CLK_MHZ);

		parser.select("temp_sens_coeff");
		tempSens_T0 = parser.get("T0", TEMPSENS_T0);

		ini_t::sectionsit_t section = parser.sections.find("lms8001_registers");

		for (ini_t::keysit_t pairs = section->second->begin(); pairs != section->second->end(); pairs++)
		{
			sscanf(pairs->first.c_str(), "%hx", &addr);
			sscanf(pairs->second.c_str(), "%hx", &value);
			addrToWrite.push_back(addr);
			dataToWrite.push_back(value);
		}

		status = SPI_write_batch(&addrToWrite[0], &dataToWrite[0], addrToWrite.size());
		if (status != LIBLMS8_SUCCESS)
			return status;
	}

//	Modify_SPI_Reg_bits(MAC, 1);
	if (controlPort == NULL)
		return LIBLMS8_NO_CONNECTION_MANAGER;
	if (controlPort->IsOpen() == false)
		return LIBLMS8_NOT_CONNECTED;
    return LIBLMS8_SUCCESS;
}

/** @brief Reads all registers from chip and saves to file
    @param filename destination filename
    @return 0-success, other failure
*/
liblms8_status LMS8001::SaveConfig(const char* filename)
{
/*	*/	
	liblms8_status status;
	typedef INI<> ini_t;
	ini_t parser(filename, true);
	parser.create("file_info");
	parser.set("type", "lms8001_minimal_config");
	parser.set("version", 1);

	char addr[80];
	char value[80];

//	uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC));

	vector<uint16_t> addrToRead;
	for (uint8_t i = 0; i < MEMORY_SECTIONS_COUNT; ++i)
		for (uint16_t addr = MemorySectionAddresses[i][0]; addr <= MemorySectionAddresses[i][1]; ++addr)
			addrToRead.push_back(addr);
	vector<uint16_t> dataReceived;
	dataReceived.resize(addrToRead.size(), 0);

	parser.create("lms8001_registers");
//	Modify_SPI_Reg_bits(LMS8param(MAC), 1);
//msavic I commented this out so I can write the data from the GUI instead from the Board
	status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());

	for (uint16_t i = 0; i < addrToRead.size(); ++i)
	{
		sprintf(addr, "0x%04X", addrToRead[i]);

//msavic Added line to Save from GUI
		uint16_t data_tmp = mRegistersMap->GetValue(addrToRead[i]);

		sprintf(value, "0x%04X", dataReceived[i]);

		parser.set(addr, value);
	}
/*
	parser.create("lms7002_registers_b");
	addrToRead.clear(); //add only B channel addresses
	for (uint8_t i = 0; i < MEMORY_SECTIONS_COUNT; ++i)
		for (uint16_t addr = MemorySectionAddresses[i][0]; addr <= MemorySectionAddresses[i][1]; ++addr)
			if (addr >= 0x0100)
				addrToRead.push_back(addr);

	Modify_SPI_Reg_bits(LMS7param(MAC), 2);
	status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());

	for (uint16_t i = 0; i < addrToRead.size(); ++i)
	{
		sprintf(addr, "0x%04X", addrToRead[i]);
		sprintf(value, "0x%04X", dataReceived[i]);
		parser.set(addr, value);
	}

	Modify_SPI_Reg_bits(LMS7param(MAC), ch); //retore previously used channel

	parser.create("reference_clocks");
	parser.set("sxt_ref_clk_mhz", mRefClkSXT_MHz);
	parser.set("sxr_ref_clk_mhz", mRefClkSXR_MHz);
*/
	//msavic ovdi!!!
	parser.create("reference_clock");
	parser.set("ref_clk_mhz", mRefClk_MHz);

	parser.create("temp_sens_coeff");
	parser.set("T0", tempSens_T0);

	parser.save(filename);

    return LIBLMS8_SUCCESS;
}

/** @brief Returns given parameter value from chip register
    @param param LMS8001 control parameter
    @param fromChip read directly from chip
    @return parameter value
*/
/*
uint16_t LMS8001::Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip)
{
	return Get_SPI_Reg_bits(param.address, param.msb, param.lsb, fromChip);
}
*/

/*
uint16_t LMS8001::Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip, uint8_t channel)
{
//msavic ABCD
	uint16_t address = param.address;
	if ((address >= 0x1000) && (address < 0x1020)) //Channel A
		address = address + channel * 0x0020;
	if ((address >= 0x2000) && (address < 0x2010)) //HLMIX A
		address = address + channel * 0x0010;

//	return Get_SPI_Reg_bits(param.address, param.msb, param.lsb, fromChip);
	return Get_SPI_Reg_bits(address, param.msb, param.lsb, fromChip);
}
*/

/*
uint16_t LMS8001::Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip, uint8_t channel, uint8_t PLLprofile)
{
	//msavic ABCD
	uint16_t address = param.address;
	if ((address >= 0x1000) && (address < 0x1020)) //Channel A
		address = address + channel * 0x0020;
	if ((address >= 0x2000) && (address < 0x2010)) //HLMIX A
		address = address + channel * 0x0010;
	if ((address >= 0x4100) && (address < 0x4110)) //PLL Profile 0
		address = address + PLLprofile * 0x0010;

	//	return Get_SPI_Reg_bits(param.address, param.msb, param.lsb, fromChip);
	return Get_SPI_Reg_bits(address, param.msb, param.lsb, fromChip);
}
*/

uint16_t LMS8001::Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip, uint8_t channel, uint8_t PLLprofile, liblms8_status* status)
{
	//msavic ABCD
	uint16_t address = param.address;
	if ((address >= 0x1000) && (address < 0x1020)) //Channel A
		address = address + channel * 0x0020;
	if ((address >= 0x2000) && (address < 0x2010)) //HLMIX A
		address = address + channel * 0x0010;
	if ((address >= 0x4100) && (address < 0x4110)) //PLL Profile 0
		address = address + PLLprofile * 0x0010;

	//	return Get_SPI_Reg_bits(param.address, param.msb, param.lsb, fromChip);
	return Get_SPI_Reg_bits(address, param.msb, param.lsb, fromChip, status);
}

/** @brief Returns given parameter value from chip register
    @param address register address
    @param msb most significant bit index
    @param lsb least significant bit index
    @param fromChip read directly from chip
    @return register bits from selected interval, shifted to right by lsb bits
*/

uint16_t LMS8001::Get_SPI_Reg_bits(uint16_t address, uint8_t msb, uint8_t lsb, bool fromChip, liblms8_status* status)
{
//	return (SPI_read(address, fromChip) & (~(~0 << (msb + 1)))) >> lsb; //shift bits to LSB
	return (SPI_read(address, fromChip, status) & (~(~0 << (msb + 1)))) >> lsb; //shift bits to LSB
}

/*
uint16_t LMS8001::Get_SPI_Reg_bits(uint16_t address, uint8_t msb, uint8_t lsb, bool fromChip)
{
    return (SPI_read(address, fromChip) & (~(~0<<(msb+1)))) >> lsb; //shift bits to LSB
}
*/

/** @brief Change given parameter value
    @param param LMS8001 control parameter
    @param fromChip read initial value directly from chip
    @param value new parameter value
*/
/*
liblms8_status LMS8001::Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip)
{
    return Modify_SPI_Reg_bits(param.address, param.msb, param.lsb, value, fromChip);
}
*/

/*
liblms8_status LMS8001::Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip, uint8_t channel)
{
//msavic ABCD
	uint16_t address = param.address;
	if ((address >= 0x1000) && (address < 0x1020)) //Channels
		address = address + channel * 0x0020;
	if ((address >= 0x2000) && (address < 0x2010)) //Channels
		address = address + channel * 0x0010;

//	return Modify_SPI_Reg_bits(param.address, param.msb, param.lsb, value, fromChip);
	return Modify_SPI_Reg_bits(address, param.msb, param.lsb, value, fromChip);
}
*/

liblms8_status LMS8001::Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip, uint8_t channel, uint8_t PLLprofile)
{
	//msavic ABCD
	uint16_t address = param.address;
	if ((address >= 0x1000) && (address < 0x1020)) //Channel A
		address = address + channel * 0x0020;
	if ((address >= 0x2000) && (address < 0x2010)) //HLMIX A
		address = address + channel * 0x0010;
	if ((address >= 0x4100) && (address < 0x4110)) //PLL Profile 0
		address = address + PLLprofile * 0x0010;

	//	return Modify_SPI_Reg_bits(param.address, param.msb, param.lsb, value, fromChip);
	return Modify_SPI_Reg_bits(address, param.msb, param.lsb, value, fromChip);
}

/** @brief Change given parameter value
    @param address register address
    @param value new bits value, the value is shifted left by lsb bits
    @param fromChip read initial value directly from chip
*/
liblms8_status LMS8001::Modify_SPI_Reg_bits(const uint16_t address, const uint8_t msb, const uint8_t lsb, const uint16_t value, bool fromChip)
{
    uint16_t spiDataReg = SPI_read(address, fromChip); //read current SPI reg data
    uint16_t spiMask = (~(~0 << (msb - lsb + 1))) << (lsb); // creates bit mask
    spiDataReg = (spiDataReg & (~spiMask)) | ((value << lsb) & spiMask);//clear bits
    return SPI_write(address, spiDataReg); //write modified data back to SPI reg
}

/** @brief Modifies given registers with values applied using masks
    @param addr array of register addresses
    @param masks array of applied masks
    @param values array of values to be written
    @param start starting index of given arrays
    @param stop end index of given arrays
*/
liblms8_status LMS8001::Modify_SPI_Reg_mask(const uint16_t *addr, const uint16_t *masks, const uint16_t *values, uint8_t start, uint8_t stop)
{
    liblms8_status status;
    uint16_t reg_data;
    vector<uint16_t> addresses;
    vector<uint16_t> data;
    while (start <= stop)
    {
        reg_data = SPI_read(addr[start], true, &status); //read current SPI reg data
        reg_data &= ~masks[start];//clear bits
        reg_data |= (values[start] & masks[start]);
        addresses.push_back(addr[start]);
        data.push_back(reg_data);
        ++start;
    }
    if (status != LIBLMS8_SUCCESS)
        return status;
    SPI_write_batch(&addresses[0], &data[0], addresses.size());
    return status;
}

/** @brief Write given data value to whole register
    @param address SPI address
    @param data new register value
    @return 0-succes, other-failure
*/
liblms8_status LMS8001::SPI_write(uint16_t address, uint16_t data)
{
    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
//    mRegistersMap->SetValue(1, address, data);
    mRegistersMap->SetValue(address, data);

//    if ((mRegistersMap->GetValue(0, LMS8param(MAC).address) & 0x0003) > 1 && address >= 0x0100)
//        mRegistersMap->SetValue(1, address, data);
//    else
//        mRegistersMap->SetValue(0, address, data);

	//msavic - UNCOMMENT, TEMP, DEBUG ONLY!!!!!!!!!
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_WR;
    pkt.outBuffer.push_back(address >> 8);
    pkt.outBuffer.push_back(address & 0xFF);
    pkt.outBuffer.push_back(data >> 8);
    pkt.outBuffer.push_back(data & 0xFF);
    controlPort->TransferPacket(pkt);
    if (pkt.status == STATUS_COMPLETED_CMD)
        return LIBLMS8_SUCCESS;
    else
        return LIBLMS8_FAILURE;
}

/** @brief Reads whole register value from given address
    @param address SPI address
    @param status operation status(optional)
    @param fromChip read value directly from chip
    @return register value
*/
uint16_t LMS8001::SPI_read(uint16_t address, bool fromChip, liblms8_status *status)
{
    if (controlPort == NULL)
    {
        if (status)
            *status = LIBLMS8_NO_CONNECTION_MANAGER;
    }
    if (controlPort->IsOpen() == false || fromChip == false)
    {
//        if ((mRegistersMap->GetValue(0, LMS8param(MAC).address) & 0x0003) > 1 && address >= 0x0100)
//            return mRegistersMap->GetValue(1, address);
//        else
//            return mRegistersMap->GetValue(0, address);

		//msavic - UNCOMMENT, TEMP, DEBUG ONLY!!!!!!!!!
//ovdi!!!
//        return mRegistersMap->GetValue(address);
    }

    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_RD;
    pkt.outBuffer.push_back(address >> 8);
    pkt.outBuffer.push_back(address & 0xFF);
    if (controlPort->TransferPacket(pkt) == LMScomms::TRANSFER_SUCCESS)
    {
        if (status)
            *status = (pkt.status == STATUS_COMPLETED_CMD ? LIBLMS8_SUCCESS : LIBLMS8_FAILURE);
        return (pkt.inBuffer[2] << 8) | pkt.inBuffer[3];
    }
	else {
		//msavic - UNCOMMENT, TEMP, DEBUG ONLY!!!!!!!!!
		return 0;
		//msavic - DELETE, TEMP, DEBUG ONLY!!!!!!!!!
//		return mRegistersMap->GetValue(address);
	}
}

/** @brief Batches multiple register writes into least ammount of transactions
    @param spiAddr spi register addresses to be written
    @param spiData registers data to be written
    @param cnt number of registers to write
    @return 0-success, other-failure
*/
liblms8_status LMS8001::SPI_write_batch(const uint16_t* spiAddr, const uint16_t* spiData, uint16_t cnt)
{
    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_WR;
    uint32_t index = 0;
    for (uint32_t i = 0; i < cnt; ++i)
    {
        pkt.outBuffer.push_back(spiAddr[i] >> 8);
        pkt.outBuffer.push_back(spiAddr[i] & 0xFF);
        pkt.outBuffer.push_back(spiData[i] >> 8);
        pkt.outBuffer.push_back(spiData[i] & 0xFF);

//        if ((mRegistersMap->GetValue(0, LMS8param(MAC).address) & 0x0003) > 1)
//            mRegistersMap->SetValue(1, spiAddr[i], spiData[i]);
//        else
//            mRegistersMap->SetValue(0, spiAddr[i], spiData[i]);

        mRegistersMap->SetValue(spiAddr[i], spiData[i]);
    }

    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

    controlPort->TransferPacket(pkt);
    if (pkt.status == STATUS_COMPLETED_CMD)
        return LIBLMS8_SUCCESS;
    else
        return LIBLMS8_FAILURE;
}

/** @brief Batches multiple register reads into least amount of transactions
    @param spiAddr SPI addresses to read
    @param spiData array for read data
    @param cnt number of registers to read
    @return 0-success, other-failure
*/
liblms8_status LMS8001::SPI_read_batch(const uint16_t* spiAddr, uint16_t* spiData, uint16_t cnt)
{
    LMScomms::GenericPacket pkt;
    pkt.cmd = CMD_LMS8001_RD;
    uint32_t index = 0;
    for (uint32_t i = 0; i < cnt; ++i)
    {
        pkt.outBuffer.push_back(spiAddr[i] >> 8);
        pkt.outBuffer.push_back(spiAddr[i] & 0xFF);
    }

    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

    LMScomms::TransferStatus status = controlPort->TransferPacket(pkt);
    if (status != LMScomms::TRANSFER_SUCCESS)
        return LIBLMS8_FAILURE;

    for (uint32_t i = 0; i < cnt; ++i)
    {
        spiData[i] = (pkt.inBuffer[2*sizeof(uint16_t)*i + 2] << 8) | pkt.inBuffer[2*sizeof(uint16_t)*i + 3];
//        if ((mRegistersMap->GetValue(0, LMS8param(MAC).address) & 0x0003) > 1)
//            mRegistersMap->SetValue(1, spiAddr[i], spiData[i]);
//        else
//            mRegistersMap->SetValue(0, spiAddr[i], spiData[i]);

        mRegistersMap->SetValue(spiAddr[i], spiData[i]);
    }
    return pkt.status == STATUS_COMPLETED_CMD ? LIBLMS8_SUCCESS : LIBLMS8_FAILURE;

    /*
    for(int i=0; i<cnt; ++i)
    {
        spiData[i] = Get_SPI_Reg_bits(spiAddr[i], 15, 0);
        if ((mRegistersMap->GetValue(0, LMS8param(MAC).address) & 0x0003) > 1)
            mRegistersMap->SetValue(1, spiAddr[i], spiData[i]);
        else
            mRegistersMap->SetValue(0, spiAddr[i], spiData[i]);
    }
    return LIBLMS8_SUCCESS;*/
}

/** @brief Performs registers test by writing known data and confirming readback data
    @return 0-registers test passed, other-failure
*/
liblms8_status LMS8001::RegistersTest()
{
    char chex[16];
    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

    liblms8_status status;

/*
    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC));

    //backup both channel data for restoration after test
    vector<uint16_t> ch1Addresses;
    for (uint8_t i = 0; i < MEMORY_SECTIONS_COUNT; ++i)
        for (uint16_t addr = MemorySectionAddresses[i][0]; addr <= MemorySectionAddresses[i][1]; ++addr)
            ch1Addresses.push_back(addr);
    vector<uint16_t> ch1Data;
    ch1Data.resize(ch1Addresses.size(), 0);

    //backup A channel
    Modify_SPI_Reg_bits(LMS8param(MAC), 1);
    status = SPI_read_batch(&ch1Addresses[0], &ch1Data[0], ch1Addresses.size());
    if (status != LIBLMS8_SUCCESS)
        return status;

    vector<uint16_t> ch2Addresses;
    for (uint8_t i = 0; i < MEMORY_SECTIONS_COUNT; ++i)
        for (uint16_t addr = MemorySectionAddresses[i][0]; addr <= MemorySectionAddresses[i][1]; ++addr)
            if (addr >= 0x0100)
                ch2Addresses.push_back(addr);
    vector<uint16_t> ch2Data;
    ch2Data.resize(ch2Addresses.size(), 0);

    Modify_SPI_Reg_bits(LMS8param(MAC), 2);
    status = SPI_read_batch(&ch2Addresses[0], &ch2Data[0], ch2Addresses.size());
    if (status != LIBLMS8_SUCCESS)
        return status;
*/
//msavic: Is this OK?
	vector<uint16_t> regMapAddresses;
	for (uint8_t i = 0; i < MEMORY_SECTIONS_COUNT; ++i)
		for (uint16_t addr = MemorySectionAddresses[i][0]; addr <= MemorySectionAddresses[i][1]; ++addr)
			if (addr >= 0x0100)
				regMapAddresses.push_back(addr);
	vector<uint16_t> regMapData;
	regMapData.resize(regMapAddresses.size(), 0);

	status = SPI_read_batch(&regMapAddresses[0], &regMapData[0], regMapAddresses.size());
	if (status != LIBLMS8_SUCCESS)
		return status;


    //test registers
    ResetChip();
/* msavic
    Modify_SPI_Reg_bits(LMS8param(MIMO_SISO), 0);
    Modify_SPI_Reg_bits(LMS8param(PD_RX_AFE2), 0);
    Modify_SPI_Reg_bits(LMS8param(PD_TX_AFE2), 0);
    Modify_SPI_Reg_bits(LMS8param(MAC), 1);
*/
    stringstream ss;

    //check single channel memory sections
//msavic
	vector<MemorySection> modulesToCheck = { MS_ChipConfig, MS_BiasLDOConfig, MS_Channel, MS_HLMIX, MS_PLLConfig, MS_PLLProfiles };
	const char* moduleNames[] = { "Chip Config", "Bias LDO Config", "Channel", "HLMIX", "PLL Config", "PLL Profiles" };

/*
    vector<MemorySection> modulesToCheck = { AFE, BIAS, XBUF, CGEN, LDO, BIST, CDS, TRF, TBB, RFE, RBB, SX,
        TxTSP, TxNCO, TxGFIR1, TxGFIR2, TxGFIR3a, TxGFIR3b, TxGFIR3c,
        RxTSP, RxNCO, RxGFIR1, RxGFIR2, RxGFIR3a, RxGFIR3b, RxGFIR3c, LimeLight };
    const char* moduleNames[] = { "AFE", "BIAS", "XBUF", "CGEN", "LDO", "BIST", "CDS", "TRF", "TBB", "RFE", "RBB", "SX",
        "TxTSP", "TxNCO", "TxGFIR1", "TxGFIR2", "TxGFIR3a", "TxGFIR3b", "TxGFIR3c",
        "RxTSP", "RxNCO", "RxGFIR1", "RxGFIR2", "RxGFIR3a", "RxGFIR3b", "RxGFIR3c", "LimeLight" };
*/

    const uint16_t patterns[] = { 0xAAAA, 0x5555 };
    const uint8_t patternsCount = 2;

    bool allTestSuccess = true;

    for (unsigned i = 0; i < modulesToCheck.size(); ++i)
    {
        bool moduleTestsSuccess = true;
        uint16_t startAddr = MemorySectionAddresses[modulesToCheck[i]][0];
        uint16_t endAddr = MemorySectionAddresses[modulesToCheck[i]][1];
//        uint8_t channelCount = startAddr >= 0x0100 ? 2 : 1;
//        for (int cc = 1; cc <= channelCount; ++cc)
//        {
//            Modify_SPI_Reg_bits(LMS8param(MAC), cc);
            sprintf(chex, "0x%04X", startAddr);
            ss << moduleNames[i] << "  [" << chex << ":";
            sprintf(chex, "0x%04X", endAddr);
            ss << chex << "]";
//            if (startAddr >= 0x0100)
//                ss << " Ch." << (cc == 1 ? "A" : "B");
                ss << endl;
            for (uint8_t p = 0; p < patternsCount; ++p)
                moduleTestsSuccess &= RegistersTestInterval(startAddr, endAddr, patterns[p], ss) == LIBLMS8_SUCCESS;
//        }
        allTestSuccess &= moduleTestsSuccess;
    }

    //restore register values
//    Modify_SPI_Reg_bits(LMS8param(MAC), 1);
//    SPI_write_batch(&ch1Addresses[0], &ch1Data[0], ch1Addresses.size());
//    Modify_SPI_Reg_bits(LMS8param(MAC), 2);
//    SPI_write_batch(&ch2Addresses[0], &ch2Data[0], ch2Addresses.size());
//    Modify_SPI_Reg_bits(LMS8param(MAC), ch);

    SPI_write_batch(&regMapAddresses[0], &regMapData[0], regMapAddresses.size());

    fstream fout;
    fout.open("registersTest.txt", ios::out);
    fout << ss.str() << endl;
    fout.close();

    return allTestSuccess ? LIBLMS8_SUCCESS : LIBLMS8_FAILURE;
}

/** @brief Performs registers test for given address interval by writing given pattern data
    @param startAddr first register address
    @param endAddr last reigster address
    @param pattern data to be written into registers
    @return 0-register test passed, other-failure
*/
liblms8_status LMS8001::RegistersTestInterval(uint16_t startAddr, uint16_t endAddr, uint16_t pattern, stringstream &ss)
{
    vector<uint16_t> addrToWrite;
    vector<uint16_t> dataToWrite;
    vector<uint16_t> dataReceived;
    vector<uint16_t> dataMasks;

    for (uint16_t addr = startAddr; addr <= endAddr; ++addr)
    {
        addrToWrite.push_back(addr);
    }
    dataMasks.resize(addrToWrite.size(), 0xFFFF);
    for (uint16_t j = 0; j < sizeof(readOnlyRegisters)/sizeof(uint16_t); ++j)
        for (uint16_t k = 0; k < addrToWrite.size(); ++k)
            if (readOnlyRegisters[j] == addrToWrite[k])
            {
                dataMasks[k] = readOnlyRegistersMasks[j];
                break;
            }

    dataToWrite.clear();
    dataReceived.clear();
    for (uint16_t j = 0; j < addrToWrite.size(); ++j)
    {
        if (addrToWrite[j] == 0x00A6)
            dataToWrite.push_back(0x1 | pattern & ~0x2);
        else if (addrToWrite[j] == 0x0084)
            dataToWrite.push_back(pattern & ~0x19);
        else
            dataToWrite.push_back(pattern & dataMasks[j]);
    }
    dataReceived.resize(addrToWrite.size(), 0);
    liblms8_status status;
    status = SPI_write_batch(&addrToWrite[0], &dataToWrite[0], addrToWrite.size());
    if (status != LIBLMS8_SUCCESS)
        return status;
    status = SPI_read_batch(&addrToWrite[0], &dataReceived[0], addrToWrite.size());
    if (status != LIBLMS8_SUCCESS)
        return status;
    bool registersMatch = true;
    char ctemp[16];
    for (uint16_t j = 0; j < dataToWrite.size(); ++j)
    {
        if (dataToWrite[j] != (dataReceived[j] & dataMasks[j]))
        {
            registersMatch = false;
            sprintf(ctemp, "0x%04X", addrToWrite[j]);
            ss << "\t" << ctemp << "(wr/rd): ";
            sprintf(ctemp, "0x%04X", dataToWrite[j]);
            ss << ctemp << "/";
            sprintf(ctemp, "0x%04X", dataReceived[j]);
            ss << ctemp << endl;
        }
    }
    if (registersMatch)
    {
        sprintf(ctemp, "0x%04X", pattern);
        ss << "\tRegisters OK (" << ctemp << ")\n";
    }
    return registersMatch ? LIBLMS8_SUCCESS : LIBLMS8_FAILURE;
}

/** @brief Sets given module registers to default values
    @return 0-success, other-failure
*/
liblms8_status LMS8001::SetDefaults(MemorySection module)
{
    liblms8_status status = LIBLMS8_SUCCESS;
    vector<uint16_t> addrs;
    vector<uint16_t> values;
    for(uint32_t address = MemorySectionAddresses[module][0]; address <= MemorySectionAddresses[module][1]; ++address)
    {
        addrs.push_back(address);
        values.push_back(mRegistersMap->GetDefaultValue(address));
    }
    status = SPI_write_batch(&addrs[0], &values[0], addrs.size());
    return status;
}

/*
const uint16_t backupAddrs[] = {
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028,
    0x0029, 0x002A, 0x002B, 0x002C, 0x002E, 0x0081, 0x0082, 0x0084, 0x0085,
    0x0086, 0x0087, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x0092, 0x0093, 0x0094,
    0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E,
    0x009F, 0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8,
    0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0100, 0x0101, 0x0102, 0x0103,
    0x0104, 0x0105, 0x0106, 0x0107, 0x0108, 0x0109, 0x010A, 0x010C, 0x010D, 0x010E,
    0x010F, 0x0110, 0x0111, 0x0112, 0x0113, 0x0114, 0x0115, 0x0116, 0x0117, 0x0118,
    0x0119, 0x011A, 0x011C, 0x011D, 0x011E, 0x011F, 0x0120, 0x0121, 0x0122, 0x0123,
    0x0124, 0x0200, 0x0201, 0x0202, 0x0203, 0x0204, 0x0205, 0x0206, 0x0207, 0x0208,
    0x0240, 0x0242, 0x0243, 0x0400, 0x0401, 0x0402,
    0x0403, 0x0404, 0x0405, 0x0406, 0x0407, 0x0408, 0x0409, 0x040A, 0x040B, 0x040C,
    0x0440, 0x0442, 0x0443 };
uint16_t backupRegs[sizeof(backupAddrs) / 2];
const uint16_t backupSXAddr[] = { 0x011C, 0x011D, 0x011E, 0x011F, 0x01200, 0x0121, 0x0122, 0x0123, 0x0124 };
uint16_t backupRegsSXR[sizeof(backupSXAddr) / 2];
uint16_t backupRegsSXT[sizeof(backupSXAddr) / 2];
*/
/** @brief Stores chip current registers state into memory for later restoration
*/
/*
void LMS8001::BackupAllRegisters()
{
    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC));
    SPI_read_batch(backupAddrs, backupRegs, sizeof(backupAddrs) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), 1); // channel A
    SPI_read_batch(backupSXAddr, backupRegsSXR, sizeof(backupRegsSXR) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), 2); // channel B
    SPI_read_batch(backupSXAddr, backupRegsSXT, sizeof(backupRegsSXR) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), ch);
}
*/
/** @brief Sets chip registers to state that was stored in memory using BackupAllRegisters()
*/
/*
void LMS8001::RestoreAllRegisters()
{
    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC));
    SPI_write_batch(backupAddrs, backupRegs, sizeof(backupAddrs) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), 1); // channel A
    SPI_write_batch(backupSXAddr, backupRegsSXR, sizeof(backupRegsSXR) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), 2); // channel B
    SPI_write_batch(backupSXAddr, backupRegsSXT, sizeof(backupRegsSXR) / sizeof(uint16_t));
    Modify_SPI_Reg_bits(LMS8param(MAC), ch);
}
*/
/** @brief Reads all chip configuration and checks if it matches with local registers copy
*/
bool LMS8001::IsSynced()
{
    if (controlPort->IsOpen() == false)
        return false;
    bool isSynced = true;
    liblms8_status status;

//    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC));

//    vector<uint16_t> addrToRead = mRegistersMap->GetUsedAddresses(0);
    vector<uint16_t> addrToRead = mRegistersMap->GetUsedAddresses();
    vector<uint16_t> dataReceived;
    dataReceived.resize(addrToRead.size(), 0);

//    Modify_SPI_Reg_bits(LMS8param(MAC), 1);
    status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());
    if (status != LIBLMS8_SUCCESS)
    {
        isSynced = false;
        goto isSyncedEnding;
    }

    //mask out readonly bits
    for (uint16_t j = 0; j < sizeof(readOnlyRegisters) / sizeof(uint16_t); ++j)
        for (uint16_t k = 0; k < addrToRead.size(); ++k)
            if (readOnlyRegisters[j] == addrToRead[k])
            {
                dataReceived[k] &= readOnlyRegistersMasks[j];
                break;
            }

    //check if local copy matches chip
    for (uint16_t i = 0; i < addrToRead.size(); ++i)
    {
//        if (dataReceived[i] != mRegistersMap->GetValue(0, addrToRead[i]))
        if (dataReceived[i] != mRegistersMap->GetValue(addrToRead[i]))
        {
            isSynced = false;
//            goto isSyncedEnding;
			break;
        }
    }
/*
    addrToRead.clear(); //add only B channel addresses
    addrToRead = mRegistersMap->GetUsedAddresses(1);

    //mask out readonly bits
    for (uint16_t j = 0; j < sizeof(readOnlyRegisters) / sizeof(uint16_t); ++j)
        for (uint16_t k = 0; k < addrToRead.size(); ++k)
            if (readOnlyRegisters[j] == addrToRead[k])
            {
                dataReceived[k] &= readOnlyRegistersMasks[j];
                break;
            }

    Modify_SPI_Reg_bits(LMS8param(MAC), 2);
    status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());
    if (status != LIBLMS8_SUCCESS)
        return false;
    //check if local copy matches chip
    for (uint16_t i = 0; i < addrToRead.size(); ++i)
        if (dataReceived[i] != mRegistersMap->GetValue(1, addrToRead[i]))
        {
            isSynced = false;
            break;
        }
*/
isSyncedEnding:
//    Modify_SPI_Reg_bits(LMS8param(MAC), ch); //restore previously used channel
    return isSynced;
}

/** @brief Writes all registers from host to chip

When used on Novena board, also changes gpios to match rx path and tx band selections
*/
liblms8_status LMS8001::UploadAll()
{
    if (controlPort == NULL)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;

//    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC)); //remember used channel

    liblms8_status status;

    vector<uint16_t> addrToWrite;
    vector<uint16_t> dataToWrite;

//    uint16_t x0020_value = mRegistersMap->GetValue(0, 0x0020);
//    Modify_SPI_Reg_bits(LMS8param(MAC), 1); //select A channel

//    addrToWrite = mRegistersMap->GetUsedAddresses(0);
    addrToWrite = mRegistersMap->GetUsedAddresses();
    //remove 0x0020 register from list, to not change MAC
//    addrToWrite.erase( find(addrToWrite.begin(), addrToWrite.end(), 0x0020) );
    for (auto address : addrToWrite)
//        dataToWrite.push_back(mRegistersMap->GetValue(0, address));
        dataToWrite.push_back(mRegistersMap->GetValue(address));

	//msavic ovdi!!!
    status = SPI_write_batch(&addrToWrite[0], &dataToWrite[0], addrToWrite.size());
    status = LIBLMS8_SUCCESS;
    if (status != LIBLMS8_SUCCESS)
        return status;
    //after all channel A registers have been written, update 0x0020 register value
//    status = SPI_write(0x0020, x0020_value);
//    if (status != LIBLMS8_SUCCESS)
//        return status;
//    Modify_SPI_Reg_bits(LMS8param(MAC), 2);
//    if (status != LIBLMS8_SUCCESS)
//       return status;
/*
    addrToWrite = mRegistersMap->GetUsedAddresses(1);
    dataToWrite.clear();
    for (auto address : addrToWrite)
    {
        dataToWrite.push_back(mRegistersMap->GetValue(1, address));
    }
    Modify_SPI_Reg_bits(LMS8param(MAC), 2); //select B channel
    status = SPI_write_batch(&addrToWrite[0], &dataToWrite[0], addrToWrite.size());
    if (status != LIBLMS8_SUCCESS)
        return status;
    Modify_SPI_Reg_bits(LMS8param(MAC), ch); //restore last used channel
*/
    return LIBLMS8_SUCCESS;
}

/** @brief Reads all registers from the chip to host

When used on Novena board, also updates gpios to match rx path and tx band selections
*/
liblms8_status LMS8001::DownloadAll()
{
    if (controlPort == nullptr)
        return LIBLMS8_NO_CONNECTION_MANAGER;
    if (controlPort->IsOpen() == false)
        return LIBLMS8_NOT_CONNECTED;
    liblms8_status status;
//    uint8_t ch = (uint8_t)Get_SPI_Reg_bits(LMS8param(MAC), false);

//    vector<uint16_t> addrToRead = mRegistersMap->GetUsedAddresses(0);
    vector<uint16_t> addrToRead = mRegistersMap->GetUsedAddresses();
    vector<uint16_t> dataReceived;
    dataReceived.resize(addrToRead.size(), 0);
//    Modify_SPI_Reg_bits(LMS8param(MAC), 1);
    status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());
    if (status != LIBLMS8_SUCCESS)
        return status;

    for (uint16_t i = 0; i < addrToRead.size(); ++i)
    {
        uint16_t adr = addrToRead[i];
        uint16_t val = dataReceived[i];
//        mRegistersMap->SetValue(0, addrToRead[i], dataReceived[i]);
        mRegistersMap->SetValue(addrToRead[i], dataReceived[i]);
    }
/*
    addrToRead.clear(); //add only B channel addresses
    addrToRead = mRegistersMap->GetUsedAddresses(1);
    dataReceived.resize(addrToRead.size(), 0);

    Modify_SPI_Reg_bits(LMS8param(MAC), 2);
    status = SPI_read_batch(&addrToRead[0], &dataReceived[0], addrToRead.size());
    if (status != LIBLMS8_SUCCESS)
        return status;
    for (uint16_t i = 0; i < addrToRead.size(); ++i)
        mRegistersMap->SetValue(1, addrToRead[i], dataReceived[i]);

    Modify_SPI_Reg_bits(LMS8param(MAC), ch); //retore previously used channel
*/
    return LIBLMS8_SUCCESS;
}

LMS8Parameter LMS8001::findLMS8Param(char* field)
{
	LMS8Parameter parameter = { 0xFFFF, 0, 0, 0, "NOT_FOUND", "" };
	int found = 0;
	//	LMS8Parameter element;
	for (const LMS8Parameter* iter : LMS8parameterList)
	{
		if (strcmp(iter->name, field) == 0) {
			parameter = *iter;
			break;
		}
	}

	return parameter;
}