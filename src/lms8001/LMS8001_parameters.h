/**
@file	LMS8001_parameters.h
@author Lime Microsystems (www.limemicro.com)
@brief 	List of LMS8001 transceiver control parameters
*/

#ifndef LMS8001_PARAMETERS_H
#define LMS8001_PARAMETERS_H

#include "typedefs.h"
#include <vector>

struct LMS8Parameter;
extern std::vector<const LMS8Parameter*> LMS8parameterList;

struct LMS8Parameter
{
    LMS8Parameter() : address(0), msb(0), lsb(0), defaultValue(0), name(nullptr), tooltip(nullptr)
    {
    }

    LMS8Parameter(uint16_t address, uint8_t msb, uint8_t lsb, uint16_t defaultValue, const char *name, const char* tooltip)
        : address(address), msb(msb), lsb(lsb), defaultValue(defaultValue), name(name), tooltip(tooltip)
    {
        LMS8parameterList.push_back(this);
    }

    uint16_t address;
    uint8_t msb;
    uint8_t lsb;
    uint16_t defaultValue;
    const char* name;
    const char* tooltip;
    inline bool operator==(const LMS8Parameter& obj)
    {
        if (address == obj.address && msb == obj.msb && lsb == obj.lsb)
            return true;
        return false;
    };
};

extern const struct LMS8Parameter SPI_SDIO_DS;
extern const struct LMS8Parameter SPI_SDO_DS;
extern const struct LMS8Parameter SPI_SDIO_PE;
extern const struct LMS8Parameter SPI_SDO_PE;
extern const struct LMS8Parameter SPI_SCLK_PE;
extern const struct LMS8Parameter SPI_SEN_PE;
extern const struct LMS8Parameter SPIMODE;
extern const struct LMS8Parameter GPIO_OUT_SPI_0;
extern const struct LMS8Parameter GPIO_OUT_SPI_1;
extern const struct LMS8Parameter GPIO_OUT_SPI_2;
extern const struct LMS8Parameter GPIO_OUT_SPI_3;
extern const struct LMS8Parameter GPIO_OUT_SPI_4;
extern const struct LMS8Parameter GPIO_OUT_SPI_5;
extern const struct LMS8Parameter GPIO_OUT_SPI_6;
extern const struct LMS8Parameter GPIO_OUT_SPI_7;
extern const struct LMS8Parameter GPIO_OUT_SPI_8;
extern const struct LMS8Parameter GPIO0_SEL;
extern const struct LMS8Parameter GPIO1_SEL;
extern const struct LMS8Parameter GPIO2_SEL;
extern const struct LMS8Parameter GPIO3_SEL;
extern const struct LMS8Parameter GPIO4_SEL;
extern const struct LMS8Parameter GPIO5_SEL;
extern const struct LMS8Parameter GPIO6_SEL;
extern const struct LMS8Parameter GPIO7_SEL;
extern const struct LMS8Parameter GPIO8_SEL;
extern const struct LMS8Parameter GPIO_IN_0;
extern const struct LMS8Parameter GPIO_IN_1;
extern const struct LMS8Parameter GPIO_IN_2;
extern const struct LMS8Parameter GPIO_IN_3;
extern const struct LMS8Parameter GPIO_IN_4;
extern const struct LMS8Parameter GPIO_IN_5;
extern const struct LMS8Parameter GPIO_IN_6;
extern const struct LMS8Parameter GPIO_IN_7;
extern const struct LMS8Parameter GPIO_IN_8;
extern const struct LMS8Parameter GPIO_PE_0;
extern const struct LMS8Parameter GPIO_PE_1;
extern const struct LMS8Parameter GPIO_PE_2;
extern const struct LMS8Parameter GPIO_PE_3;
extern const struct LMS8Parameter GPIO_PE_4;
extern const struct LMS8Parameter GPIO_PE_5;
extern const struct LMS8Parameter GPIO_PE_6;
extern const struct LMS8Parameter GPIO_PE_7;
extern const struct LMS8Parameter GPIO_PE_8;
extern const struct LMS8Parameter GPIO_DS_0;
extern const struct LMS8Parameter GPIO_DS_1;
extern const struct LMS8Parameter GPIO_DS_2;
extern const struct LMS8Parameter GPIO_DS_3;
extern const struct LMS8Parameter GPIO_DS_4;
extern const struct LMS8Parameter GPIO_DS_5;
extern const struct LMS8Parameter GPIO_DS_6;
extern const struct LMS8Parameter GPIO_DS_7;
extern const struct LMS8Parameter GPIO_DS_8;
extern const struct LMS8Parameter GPIO_InO_0;
extern const struct LMS8Parameter GPIO_InO_1;
extern const struct LMS8Parameter GPIO_InO_2;
extern const struct LMS8Parameter GPIO_InO_3;
extern const struct LMS8Parameter GPIO_InO_4;
extern const struct LMS8Parameter GPIO_InO_5;
extern const struct LMS8Parameter GPIO_InO_6;
extern const struct LMS8Parameter GPIO_InO_7;
extern const struct LMS8Parameter GPIO_InO_8;
extern const struct LMS8Parameter TEMP_SENS_EN;
extern const struct LMS8Parameter TEMP_SENS_CLKEN;
extern const struct LMS8Parameter TEMP_START_CONV;
extern const struct LMS8Parameter TEMP_READ;
extern const struct LMS8Parameter VER;
extern const struct LMS8Parameter REV;
extern const struct LMS8Parameter MASK;
extern const struct LMS8Parameter PD_CALIB_COMP;
extern const struct LMS8Parameter RP_CALIB_COMP;
extern const struct LMS8Parameter RP_CALIB_BIAS;
extern const struct LMS8Parameter PD_FRP_BIAS;
extern const struct LMS8Parameter PD_F_BIAS;
extern const struct LMS8Parameter PD_PTRP_BIAS;
extern const struct LMS8Parameter PD_PT_BIAS;
extern const struct LMS8Parameter PD_BIAS;

extern const struct LMS8Parameter EN_LDO_LOBUFA;
extern const struct LMS8Parameter EN_LDO_LOBUFB;
extern const struct LMS8Parameter EN_LDO_LOBUFC;
extern const struct LMS8Parameter EN_LDO_LOBUFD;

extern const struct LMS8Parameter EN_LDO_HFLNAA;
extern const struct LMS8Parameter EN_LDO_HFLNAB;
extern const struct LMS8Parameter EN_LDO_HFLNAC;
extern const struct LMS8Parameter EN_LDO_HFLNAD;

extern const struct LMS8Parameter EN_LDO_CLK_BUF;
extern const struct LMS8Parameter EN_LDO_PLL_DIV;
extern const struct LMS8Parameter EN_LDO_PLL_CP;
extern const struct LMS8Parameter PD_LDO_DIG_CORE;

extern const struct LMS8Parameter SPDUP_LDO_LOBUFA;
extern const struct LMS8Parameter SPDUP_LDO_LOBUFB;
extern const struct LMS8Parameter SPDUP_LDO_LOBUFC;
extern const struct LMS8Parameter SPDUP_LDO_LOBUFD;

extern const struct LMS8Parameter SPDUP_LDO_HFLNAA;
extern const struct LMS8Parameter SPDUP_LDO_HFLNAB;
extern const struct LMS8Parameter SPDUP_LDO_HFLNAC;
extern const struct LMS8Parameter SPDUP_LDO_HFLNAD;

extern const struct LMS8Parameter SPDUP_LDO_CLK_BUF;
extern const struct LMS8Parameter SPDUP_LDO_PLL_DIV;
extern const struct LMS8Parameter SPDUP_LDO_PLL_CP;
extern const struct LMS8Parameter SPDUP_LDO_DIG_CORE;

extern const struct LMS8Parameter EN_LOADIMP_LDO_LOBUFA;
extern const struct LMS8Parameter EN_LOADIMP_LDO_LOBUFB;
extern const struct LMS8Parameter EN_LOADIMP_LDO_LOBUFC;
extern const struct LMS8Parameter EN_LOADIMP_LDO_LOBUFD;

extern const struct LMS8Parameter EN_LOADIMP_LDO_HFLNAA;
extern const struct LMS8Parameter EN_LOADIMP_LDO_HFLNAB;
extern const struct LMS8Parameter EN_LOADIMP_LDO_HFLNAC;
extern const struct LMS8Parameter EN_LOADIMP_LDO_HFLNAD;

extern const struct LMS8Parameter EN_LOADIMP_LDO_CLK_BUF;
extern const struct LMS8Parameter EN_LOADIMP_LDO_PLL_DIV;
extern const struct LMS8Parameter EN_LOADIMP_LDO_PLL_CP;
extern const struct LMS8Parameter EN_LOADIMP_LDO_DIG_CORE;

extern const struct LMS8Parameter RDIV_LOBUFA;
extern const struct LMS8Parameter RDIV_LOBUFB;
extern const struct LMS8Parameter RDIV_LOBUFC;
extern const struct LMS8Parameter RDIV_LOBUFD;

extern const struct LMS8Parameter RDIV_HFLNAA;
extern const struct LMS8Parameter RDIV_HFLNAB;
extern const struct LMS8Parameter RDIV_HFLNAC;
extern const struct LMS8Parameter RDIV_HFLNAD;

extern const struct LMS8Parameter RDIV_CLK_BUF;
extern const struct LMS8Parameter RDIV_PLL_DIV;
extern const struct LMS8Parameter RDIV_PLL_CP;
extern const struct LMS8Parameter RDIV_DIG_CORE;

extern const struct LMS8Parameter CHx_MIXA_ICT;
extern const struct LMS8Parameter CHx_MIXB_ICT;

extern const struct LMS8Parameter CHx_PA_ILIN2X;
extern const struct LMS8Parameter CHx_PA_ICT_LIN;
extern const struct LMS8Parameter CHx_PA_ICT_MAIN;

extern const struct LMS8Parameter CHx_PA_R50_EN0;
extern const struct LMS8Parameter CHx_PA_BYPASS0;
extern const struct LMS8Parameter CHx_PA_PD0;
extern const struct LMS8Parameter CHx_MIXB_LOBUFF_PD0;
extern const struct LMS8Parameter CHx_MIXB_BIAS_PD0;
extern const struct LMS8Parameter CHx_MIXA_LOBUFF_PD0;
extern const struct LMS8Parameter CHx_MIXA_BIAS_PD0;
extern const struct LMS8Parameter CHx_LNA_PD0;

extern const struct LMS8Parameter CHx_LNA_ICT_LIN0;
extern const struct LMS8Parameter CHx_LNA_ICT_MAIN0;
extern const struct LMS8Parameter CHx_LNA_CGSCTRL0;
extern const struct LMS8Parameter CHx_LNA_GCTRL0;

extern const struct LMS8Parameter CHx_PA_LIN_LOSS0;
extern const struct LMS8Parameter CHx_PA_MAIN_LOSS0;

extern const struct LMS8Parameter CHx_PA_R50_EN1;
extern const struct LMS8Parameter CHx_PA_BYPASS1;
extern const struct LMS8Parameter CHx_PA_PD1;
extern const struct LMS8Parameter CHx_MIXB_LOBUFF_PD1;
extern const struct LMS8Parameter CHx_MIXB_BIAS_PD1;
extern const struct LMS8Parameter CHx_MIXA_LOBUFF_PD1;
extern const struct LMS8Parameter CHx_MIXA_BIAS_PD1;
extern const struct LMS8Parameter CHx_LNA_PD1;

extern const struct LMS8Parameter CHx_LNA_ICT_LIN1;
extern const struct LMS8Parameter CHx_LNA_ICT_MAIN1;
extern const struct LMS8Parameter CHx_LNA_CGSCTRL1;
extern const struct LMS8Parameter CHx_LNA_GCTRL1;

extern const struct LMS8Parameter CHx_PA_LIN_LOSS1;
extern const struct LMS8Parameter CHx_PA_MAIN_LOSS1;

extern const struct LMS8Parameter CHx_PA_R50_EN2;
extern const struct LMS8Parameter CHx_PA_BYPASS2;
extern const struct LMS8Parameter CHx_PA_PD2;
extern const struct LMS8Parameter CHx_MIXB_LOBUFF_PD2;
extern const struct LMS8Parameter CHx_MIXB_BIAS_PD2;
extern const struct LMS8Parameter CHx_MIXA_LOBUFF_PD2;
extern const struct LMS8Parameter CHx_MIXA_BIAS_PD2;
extern const struct LMS8Parameter CHx_LNA_PD2;

extern const struct LMS8Parameter CHx_LNA_ICT_LIN2;
extern const struct LMS8Parameter CHx_LNA_ICT_MAIN2;
extern const struct LMS8Parameter CHx_LNA_CGSCTRL2;
extern const struct LMS8Parameter CHx_LNA_GCTRL2;

extern const struct LMS8Parameter CHx_PA_LIN_LOSS2;
extern const struct LMS8Parameter CHx_PA_MAIN_LOSS2;

extern const struct LMS8Parameter CHx_PA_R50_EN3;
extern const struct LMS8Parameter CHx_PA_BYPASS3;
extern const struct LMS8Parameter CHx_PA_PD3;
extern const struct LMS8Parameter CHx_MIXB_LOBUFF_PD3;
extern const struct LMS8Parameter CHx_MIXB_BIAS_PD3;
extern const struct LMS8Parameter CHx_MIXA_LOBUFF_PD3;
extern const struct LMS8Parameter CHx_MIXA_BIAS_PD3;
extern const struct LMS8Parameter CHx_LNA_PD3;

extern const struct LMS8Parameter CHx_LNA_ICT_LIN3;
extern const struct LMS8Parameter CHx_LNA_ICT_MAIN3;
extern const struct LMS8Parameter CHx_LNA_CGSCTRL3;
extern const struct LMS8Parameter CHx_LNA_GCTRL3;

extern const struct LMS8Parameter CHx_PA_LIN_LOSS3;
extern const struct LMS8Parameter CHx_PA_MAIN_LOSS3;

extern const struct LMS8Parameter CHx_PA_R50_EN_RB;
extern const struct LMS8Parameter CHx_PA_BYPASS_RB;
extern const struct LMS8Parameter CHx_PA_PD_RB;
extern const struct LMS8Parameter CHx_MIXB_LOBUFF_PD_RB;
extern const struct LMS8Parameter CHx_MIXB_BIAS_PD_RB;
extern const struct LMS8Parameter CHx_MIXA_LOBUFF_PD_RB;
extern const struct LMS8Parameter CHx_MIXA_BIAS_PD_RB;
extern const struct LMS8Parameter CHx_LNA_PD_RB;

extern const struct LMS8Parameter CHx_LNA_ICT_LIN_RB;
extern const struct LMS8Parameter CHx_LNA_ICT_MAIN_RB;
extern const struct LMS8Parameter CHx_LNA_CGSCTRL_RB;
extern const struct LMS8Parameter CHx_LNA_GCTRL_RB;

extern const struct LMS8Parameter CHx_PA_LIN_LOSS_RB;
extern const struct LMS8Parameter CHx_PA_MAIN_LOSS_RB;

extern const struct LMS8Parameter CHx_PD_SEL0_INTERNAL;
extern const struct LMS8Parameter CHx_PD_SEL0_INVERT;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK0;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK1;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK2;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK3;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK4;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK5;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK6;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK7;
extern const struct LMS8Parameter CHx_PD_SEL0_MASK8;

extern const struct LMS8Parameter CHx_PD_SEL1_INTERNAL;
extern const struct LMS8Parameter CHx_PD_SEL1_INVERT;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK0;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK1;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK2;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK3;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK4;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK5;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK6;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK7;
extern const struct LMS8Parameter CHx_PD_SEL1_MASK8;

extern const struct LMS8Parameter CHx_LNA_SEL0_INTERNAL;
extern const struct LMS8Parameter CHx_LNA_SEL0_INVERT;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK0;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK1;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK2;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK3;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK4;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK5;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK6;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK7;
extern const struct LMS8Parameter CHx_LNA_SEL0_MASK8;

extern const struct LMS8Parameter CHx_LNA_SEL1_INTERNAL;
extern const struct LMS8Parameter CHx_LNA_SEL1_INVERT;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK0;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK1;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK2;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK3;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK4;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK5;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK6;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK7;
extern const struct LMS8Parameter CHx_LNA_SEL1_MASK8;

extern const struct LMS8Parameter CHx_PA_SEL0_INTERNAL;
extern const struct LMS8Parameter CHx_PA_SEL0_INVERT;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK0;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK1;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK2;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK3;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK4;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK5;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK6;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK7;
extern const struct LMS8Parameter CHx_PA_SEL0_MASK8;

extern const struct LMS8Parameter CHx_PA_SEL1_INTERNAL;
extern const struct LMS8Parameter CHx_PA_SEL1_INVERT;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK0;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK1;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK2;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK3;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK4;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK5;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK6;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK7;
extern const struct LMS8Parameter CHx_PA_SEL1_MASK8;

extern const struct LMS8Parameter CHx_PD_INT_SEL0;
extern const struct LMS8Parameter CHx_PD_INT_SEL1;
extern const struct LMS8Parameter CHx_LNA_INT_SEL0;
extern const struct LMS8Parameter CHx_LNA_INT_SEL1;
extern const struct LMS8Parameter CHx_PA_INT_SEL0;
extern const struct LMS8Parameter CHx_PA_INT_SEL1;

extern const struct LMS8Parameter HLMIXx_VGCAS0;
extern const struct LMS8Parameter HLMIXx_ICT_BIAS0;
extern const struct LMS8Parameter HLMIXx_BIAS_PD0;
extern const struct LMS8Parameter HLMIXx_LOBUF_PD0;
extern const struct LMS8Parameter HLMIXx_MIXLOSS0;

extern const struct LMS8Parameter HLMIXx_VGCAS1;
extern const struct LMS8Parameter HLMIXx_ICT_BIAS1;
extern const struct LMS8Parameter HLMIXx_BIAS_PD1;
extern const struct LMS8Parameter HLMIXx_LOBUF_PD1;
extern const struct LMS8Parameter HLMIXx_MIXLOSS1;

extern const struct LMS8Parameter HLMIXx_VGCAS2;
extern const struct LMS8Parameter HLMIXx_ICT_BIAS2;
extern const struct LMS8Parameter HLMIXx_BIAS_PD2;
extern const struct LMS8Parameter HLMIXx_LOBUF_PD2;
extern const struct LMS8Parameter HLMIXx_MIXLOSS2;

extern const struct LMS8Parameter HLMIXx_VGCAS3;
extern const struct LMS8Parameter HLMIXx_ICT_BIAS3;
extern const struct LMS8Parameter HLMIXx_BIAS_PD3;
extern const struct LMS8Parameter HLMIXx_LOBUF_PD3;
extern const struct LMS8Parameter HLMIXx_MIXLOSS3;

extern const struct LMS8Parameter HLMIXx_VGCAS_RB;
extern const struct LMS8Parameter HLMIXx_ICT_BIAS_RB;
extern const struct LMS8Parameter HLMIXx_BIAS_PD_RB;
extern const struct LMS8Parameter HLMIXx_LOBUF_PD_RB;
extern const struct LMS8Parameter HLMIXx_MIXLOSS_RB;

extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_INTERNAL;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_INVERT;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK0;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK1;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK2;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK3;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK4;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK5;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK6;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK7;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL0_MASK8;

extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_INTERNAL;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_INVERT;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK0;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK1;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK2;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK3;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK4;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK5;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK6;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK7;
extern const struct LMS8Parameter HLMIXx_CONFIG_SEL1_MASK8;

extern const struct LMS8Parameter HLMIXx_CONFIG_INT_SEL0;
extern const struct LMS8Parameter HLMIXx_CONFIG_INT_SEL1;

extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_INTERNAL;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_INVERT;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK0;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK1;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK2;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK3;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK4;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK5;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK6;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK7;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL0_MASK8;

extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_INTERNAL;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_INVERT;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK0;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK1;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK2;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK3;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK4;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK5;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK6;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK7;
extern const struct LMS8Parameter HLMIXx_LOSS_SEL1_MASK8;

extern const struct LMS8Parameter HLMIXx_LOSS_INT_SEL0;
extern const struct LMS8Parameter HLMIXx_LOSS_INT_SEL1;

extern const struct LMS8Parameter EN_VCOBIAS;
extern const struct LMS8Parameter BYP_VCOREG;
extern const struct LMS8Parameter CURLIM_VCOREG;
extern const struct LMS8Parameter SPDUP_VCOREG;
extern const struct LMS8Parameter VDIV_VCOREG;

extern const struct LMS8Parameter PLL_XBUF_SLFBEN;
extern const struct LMS8Parameter PLL_XBUF_BYPEN;
extern const struct LMS8Parameter PLL_XBUF_EN;

extern const struct LMS8Parameter FCAL_START;
extern const struct LMS8Parameter VCO_SEL_FINAL_VAL;
extern const struct LMS8Parameter VCO_SEL_FINAL;
extern const struct LMS8Parameter FREQ_FINAL_VAL;
extern const struct LMS8Parameter FREQ_FINAL;
extern const struct LMS8Parameter VCO_SEL_FORCE;
extern const struct LMS8Parameter VCO_SEL_INIT;
extern const struct LMS8Parameter FREQ_INIT_POS;
extern const struct LMS8Parameter FREQ_INIT;
extern const struct LMS8Parameter FREQ_SETTLING_N;
extern const struct LMS8Parameter VTUNE_WAIT_N;
extern const struct LMS8Parameter VCO_SEL_FREQ_MAX;
extern const struct LMS8Parameter VCO_SEL_FREQ_MIN;

extern const struct LMS8Parameter VCO_FREQ_MAN;
extern const struct LMS8Parameter VCO_SEL_MAN;
extern const struct LMS8Parameter FREQ_LOW;
extern const struct LMS8Parameter FREQ_EQUAL;
extern const struct LMS8Parameter FREQ_HIGH;
extern const struct LMS8Parameter CTUNE_STEP_DONE;
extern const struct LMS8Parameter CTUNE_START;
extern const struct LMS8Parameter CTUNE_EN;

extern const struct LMS8Parameter PLL_CFG_SEL0_INTERNAL;
extern const struct LMS8Parameter PLL_CFG_SEL0_INVERT;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK0;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK1;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK2;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK3;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK4;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK5;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK6;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK7;
extern const struct LMS8Parameter PLL_CFG_SEL0_MASK8;

extern const struct LMS8Parameter PLL_CFG_SEL0;

extern const struct LMS8Parameter PLL_CFG_SEL1_INTERNAL;
extern const struct LMS8Parameter PLL_CFG_SEL1_INVERT;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK0;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK1;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK2;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK3;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK4;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK5;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK6;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK7;
extern const struct LMS8Parameter PLL_CFG_SEL1_MASK8;

extern const struct LMS8Parameter PLL_CFG_SEL1;

extern const struct LMS8Parameter PLL_CFG_SEL2_INTERNAL;
extern const struct LMS8Parameter PLL_CFG_SEL2_INVERT;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK0;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK1;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK2;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK3;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK4;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK5;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK6;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK7;
extern const struct LMS8Parameter PLL_CFG_SEL2_MASK8;

extern const struct LMS8Parameter PLL_CFG_SEL2;

extern const struct LMS8Parameter PLL_CFG_INT_SEL0;
extern const struct LMS8Parameter PLL_CFG_INT_SEL1;
extern const struct LMS8Parameter PLL_CFG_INT_SEL2;

extern const struct LMS8Parameter PLL_CFG_INT_SEL;

extern const struct LMS8Parameter PLL_RSTN;
extern const struct LMS8Parameter CTUNE_RES;
extern const struct LMS8Parameter PLL_CALIBRATION_MODE;
extern const struct LMS8Parameter PLL_CALIBRATION_EN;
extern const struct LMS8Parameter PLL_FLOCK_INTERNAL;
extern const struct LMS8Parameter PLL_FLOCK_INTVAL;

extern const struct LMS8Parameter VTUNE_HIGH;
extern const struct LMS8Parameter VTUNE_LOW;
extern const struct LMS8Parameter PLL_LOCK;

extern const struct LMS8Parameter SEL_BIAS_CORE;
extern const struct LMS8Parameter PLL_LODIST_ICT_CORE;
extern const struct LMS8Parameter PLL_LODIST_ICT_BUF;
extern const struct LMS8Parameter PLL_ICT_OUT0;
extern const struct LMS8Parameter PLL_ICT_OUT1;
extern const struct LMS8Parameter PLL_ICT_OUT2;
extern const struct LMS8Parameter PLL_ICT_OUT3;

extern const struct LMS8Parameter BSIGL;
extern const struct LMS8Parameter BSTATE;
extern const struct LMS8Parameter EN_SDM_TSTO;
extern const struct LMS8Parameter BEN;
extern const struct LMS8Parameter BSTART;

extern const struct LMS8Parameter BSIGH;

extern const struct LMS8Parameter PLL_LODIST_EN_BIAS_n;
extern const struct LMS8Parameter PLL_LODIST_EN_DIV2IQ_n;
extern const struct LMS8Parameter PLL_EN_VTUNE_COMP_n;
extern const struct LMS8Parameter PLL_EN_LD_n;
extern const struct LMS8Parameter PLL_EN_PFD_n;
extern const struct LMS8Parameter PLL_EN_CP_n;
extern const struct LMS8Parameter PLL_EN_CPOFS_n;
extern const struct LMS8Parameter PLL_EN_VCO_n;
extern const struct LMS8Parameter PLL_EN_FFDIV_n;
extern const struct LMS8Parameter PLL_EN_FB_PDIV2_n;
extern const struct LMS8Parameter PLL_EN_FFCORE_n;
extern const struct LMS8Parameter PLL_EN_FBDIV_n;
extern const struct LMS8Parameter PLL_SDM_CLK_EN_n;

extern const struct LMS8Parameter R3_n;
extern const struct LMS8Parameter R2_n;
extern const struct LMS8Parameter C2_n;
extern const struct LMS8Parameter C1_n;
extern const struct LMS8Parameter VTUNE_VCT_n;
extern const struct LMS8Parameter LPFSW_n;
extern const struct LMS8Parameter C3_n;

extern const struct LMS8Parameter FLIP_n;
extern const struct LMS8Parameter DEL_n;
extern const struct LMS8Parameter PULSE_n;
extern const struct LMS8Parameter OFS_n;
extern const struct LMS8Parameter LD_VCT_n;
extern const struct LMS8Parameter ICT_CP_n;

extern const struct LMS8Parameter VCO_FREQ_n;
extern const struct LMS8Parameter SPDUP_VCO_n;
extern const struct LMS8Parameter VCO_AAC_EN_n;
extern const struct LMS8Parameter VDIV_SWVDD_n;
extern const struct LMS8Parameter VCO_SEL_n;
extern const struct LMS8Parameter VCO_AMP_n;

extern const struct LMS8Parameter FFDIV_SEL_n;
extern const struct LMS8Parameter FFCORE_MOD_n;
extern const struct LMS8Parameter FF_MOD_n;
extern const struct LMS8Parameter INTMOD_EN_n;
extern const struct LMS8Parameter DITHER_EN_n;
extern const struct LMS8Parameter SEL_SDMCLK_n;
extern const struct LMS8Parameter REV_SDMCLK_n;
extern const struct LMS8Parameter INTMOD_n;
extern const struct LMS8Parameter FRACMODL_n;
extern const struct LMS8Parameter FRACMODH_n;

extern const struct LMS8Parameter PLL_LODIST_EN_OUT_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT3_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT2_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT1_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT0_n;
extern const struct LMS8Parameter FLOCK_R3_n;
extern const struct LMS8Parameter FLOCK_R2_n;
extern const struct LMS8Parameter FLOCK_C3_n;
extern const struct LMS8Parameter FLOCK_C2_n;
extern const struct LMS8Parameter FLOCK_C1_n;
extern const struct LMS8Parameter FLOCK_PULSE_n;
extern const struct LMS8Parameter FLOCK_OFS_n;
extern const struct LMS8Parameter FLOCK_LODIST_EN_OUT_n;
extern const struct LMS8Parameter FLOCK_VCO_SPDUP_n;
extern const struct LMS8Parameter FLOCK_N_n;

extern const struct LMS8Parameter FLOCK_LODIST_EN_OUT0_n;
extern const struct LMS8Parameter FLOCK_LODIST_EN_OUT1_n;
extern const struct LMS8Parameter FLOCK_LODIST_EN_OUT2_n;
extern const struct LMS8Parameter FLOCK_LODIST_EN_OUT3_n;

extern const struct LMS8Parameter PLL_LODIST_EN_OUT0_n;
extern const struct LMS8Parameter PLL_LODIST_EN_OUT1_n;
extern const struct LMS8Parameter PLL_LODIST_EN_OUT2_n;
extern const struct LMS8Parameter PLL_LODIST_EN_OUT3_n;

extern const struct LMS8Parameter PLL_LODIST_FSP_OUT02_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT12_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT22_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT32_n;

extern const struct LMS8Parameter PLL_LODIST_FSP_OUT010_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT110_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT210_n;
extern const struct LMS8Parameter PLL_LODIST_FSP_OUT310_n;

//extern const struct LMS8Parameter MAC;

#endif
