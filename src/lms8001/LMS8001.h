/**
@file	LMS8001.h
@author Lime Microsystems (www.limemicro.com)
@brief	LMS8001 transceiver configuration interface
*/

#ifndef LMS8API_H
#define LMS8API_H

//#define REF_CLK_MHZ 30.72
#define REF_CLK_MHZ 40.00

//Temperature Sensor Default Coefficients
#define TEMPSENS_T0 -105.45
#define TEMPSENS_T1 1.2646
#define TEMPSENS_T2 -0.000548

#include "LMS8001_statuses.h"
#include "LMS8001_parameters.h"
#include "typedefs.h"

#include <sstream>

class LMScomms;
class LMS8001_RegistersMap;

class LMS8001
{
public:
    enum
    {
        Rx, Tx
    };

	LMS8001();
    LMS8001(LMScomms* controlPort);
	virtual ~LMS8001();

    ///@name Registers writing and reading
    liblms8_status UploadAll();
    liblms8_status DownloadAll();
    bool IsSynced();

	liblms8_status ResetChip();
	liblms8_status LoadConfig(const char* filename);
	liblms8_status SaveConfig(const char* filename);
    ///@}

    ///@name Registers writing and reading
//    uint16_t Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip = true);
//    uint16_t Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip = true, uint8_t channel = 0);

//    uint16_t Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip = true, uint8_t channel = 0, uint8_t PLLprofile = 0);
//    uint16_t Get_SPI_Reg_bits(uint16_t address, uint8_t msb, uint8_t lsb, bool fromChip = true);

    uint16_t Get_SPI_Reg_bits(const LMS8Parameter &param, bool fromChip = true, uint8_t channel = 0, uint8_t PLLprofile = 0, liblms8_status* status = nullptr);
    uint16_t Get_SPI_Reg_bits(uint16_t address, uint8_t msb, uint8_t lsb, bool fromChip = true, liblms8_status* status = nullptr);

//    liblms8_status Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip = true);
//    liblms8_status Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip = true, uint8_t channel = 0);
	liblms8_status Modify_SPI_Reg_bits(const LMS8Parameter &param, const uint16_t value, bool fromChip = true, uint8_t channel = 0, uint8_t PLLprofile = 0);
    liblms8_status Modify_SPI_Reg_bits(uint16_t address, uint8_t msb, uint8_t lsb, uint16_t value, bool fromChip = true);
    liblms8_status SPI_write(uint16_t address, uint16_t data);
    uint16_t SPI_read(uint16_t address, bool fromChip = true, liblms8_status *status = 0);
    liblms8_status RegistersTest();
    ///@}

	LMS8Parameter findLMS8Param(char* field);

	uint8_t channel;
//msavic PLLprofile
	uint8_t PLLprofile;

//msavic
    ///enumeration to indicate module registers intervals
    enum MemorySection
    {
		MS_ChipConfig = 0, MS_BiasLDOConfig, MS_Channel, MS_HLMIX, MS_PLLConfig, MS_PLLProfiles, 
		MEMORY_SECTIONS_COUNT
/*
        LimeLight = 0, EN_DIR, AFE, BIAS, XBUF, CGEN, LDO, BIST, CDS,
        TRF, TBB, RFE, RBB, SX, TxTSP,
        TxNCO, TxGFIR1, TxGFIR2, TxGFIR3a, TxGFIR3b, TxGFIR3c,
        RxTSP, RxNCO, RxGFIR1, RxGFIR2, RxGFIR3a, RxGFIR3b, RxGFIR3c,
        MEMORY_SECTIONS_COUNT
*/
    };
    virtual liblms8_status SetDefaults(MemorySection module);
	LMScomms* GetControlPort() const { return controlPort;};

	double tempSens_T0;

	///Reference clock
	float_type mRefClk_MHz;

protected:
    LMS8001_RegistersMap *mRegistersMap;
    static const uint16_t readOnlyRegisters[];
    static const uint16_t readOnlyRegistersMasks[];

    uint16_t MemorySectionAddresses[MEMORY_SECTIONS_COUNT][2];
    ///@name Algorithms functions
    void BackupAllRegisters();
    void RestoreAllRegisters();

    liblms8_status RegistersTestInterval(uint16_t startAddr, uint16_t endAddr, uint16_t pattern, std::stringstream &ss);
    liblms8_status SPI_write_batch(const uint16_t* spiAddr, const uint16_t* spiData, uint16_t cnt);
    liblms8_status SPI_read_batch(const uint16_t* spiAddr, uint16_t* spiData, uint16_t cnt);
    liblms8_status Modify_SPI_Reg_mask(const uint16_t *addr, const uint16_t *masks, const uint16_t *values, uint8_t start, uint8_t stop);
    ///@}
/*
    ///Reference clock used for Receiver frequency calculations
    float_type mRefClkSXR_MHz;
    ///Reference clock used for Transmitter frequency calculations
    float_type mRefClkSXT_MHz;
*/

    enum LogType
    {
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_DATA
    };
    virtual void Log(const char* text, LogType type);

    ///port used for communicating with LMS8001
    LMScomms* controlPort;
};
#endif
