///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __LMS8001_WXGUI_H__
#define __LMS8001_WXGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class lms8001_pnlChannel_view;
class lms8001_pnlConfig_view;
class lms8001_pnlHLMIX_view;
class lms8001_pnlLDO_view;
class lms8001_pnlPLLConfig_view;
class lms8001_pnlPLLProfiles_view;

#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class mainPanel
///////////////////////////////////////////////////////////////////////////////
class mainPanel : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_BTN_RESET_CHIP = 2048,
			ID_BTN_CHIP_TO_GUI,
			ID_BTN_UPLOAD_PANEL,
			ID_TABS_NOTEBOOK,
			ID_TAB_CHIP_CONFIG,
			ID_TAB_LDO,
			ID_TAB_CHANNEL,
			ID_TAB_HLMIX,
			ID_TAB_PLLCONFIG,
			ID_TAB_PLLPROFILES
		};
		
		wxButton* btnNew;
		wxButton* btnOpen;
		wxButton* btnSave;
		wxRadioBox* rgrChannel;
		wxButton* btnResetChip;
		wxButton* btnDownloadAll;
		wxButton* btnUploadAll;
		wxButton* btnUploadPanel;
		wxNotebook* tabsNotebook;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnNewProject( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenProject( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveProject( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSwitchChannel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetChip( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDownloadAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUploadAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUploadPanel( wxCommandEvent& event ) { event.Skip(); }
		virtual void Onnotebook_modulesPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		
	
	public:
		lms8001_pnlConfig_view* mTabChipConfig;
		lms8001_pnlLDO_view* mTabLDO;
		lms8001_pnlChannel_view* mTabChannel;
		lms8001_pnlHLMIX_view* mTabHLMIX;
		lms8001_pnlPLLConfig_view* mTabPLLConfig;
		lms8001_pnlPLLProfiles_view* mTabPLLProfiles;
		
		mainPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~mainPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlConfig_view
///////////////////////////////////////////////////////////////////////////////
class pnlConfig_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_GPIO_OUT_SPI_0 = 2048,
			ID_GPIO_OUT_SPI_1,
			IID_GPIO_OUT_SPI_2,
			ID_GPIO_OUT_SPI_3,
			IID_GPIO_OUT_SPI_4,
			ID_GPIO_OUT_SPI_5,
			ID_GPIO_OUT_SPI_6,
			IID_GPIO_OUT_SPI_7,
			IID_GPIO_OUT_SPI_8,
			ID_GPIO0_SEL,
			ID_GPIO_IN_0,
			ID_GPIO_IN_1,
			IID_GPIO_IN_2,
			ID_GPIO_IN_3,
			IID_GPIO_IN_4,
			ID_GPIO_IN_5,
			ID_GPIO_IN_6,
			IID_GPIO_IN_7,
			IID_GPIO_IN_8,
			ID_GPIO_PE_0,
			ID_GPIO_PE_1,
			ID_GPIO_PE_2,
			ID_GPIO_PE_3,
			ID_GPIO_PE_4,
			ID_GPIO_PE_5,
			ID_GPIO_PE_6,
			ID_GPIO_PE_7,
			ID_GPIO_PE_8,
			ID_GPIO_DS_0,
			ID_GPIO_DS_1,
			ID_GPIO_DS_2,
			ID_GPIO_DS_3,
			ID_GPIO_DS_4,
			ID_GPIO_DS_5,
			ID_GPIO_DS_6,
			ID_GPIO_DS_7,
			ID_GPIO_DS_8,
			ID_GPIO_InO_0,
			ID_GPIO_InO_1,
			ID_GPIO_InO_2,
			ID_GPIO_InO_3,
			ID_GPIO_InO_4,
			ID_GPIO_InO_5,
			ID_GPIO_InO_6,
			ID_GPIO_InO_7,
			ID_GPIO_InO_8,
			ID_SPI_SDIO_DS,
			ID_SPI_SDO_DS,
			ID_SPI_SDIO_PE,
			ID_SPI_SDO_PE,
			ID_SPI_SEN_PE,
			ID_TEMP_SENS_EN,
			ID_TEMP_SENS_CLKEN,
			ID_TEMP_START_CONV
		};
		
		wxNotebook* ID_NOTEBOOK_CONFIG;
		wxPanel* ID_PANEL_CONFIG;
		wxCheckBox* chkGPIO_OUT_SPI_0;
		wxCheckBox* chkGPIO_OUT_SPI_1;
		wxCheckBox* chkGPIO_OUT_SPI_2;
		wxCheckBox* chkGPIO_OUT_SPI_3;
		wxCheckBox* chkGPIO_OUT_SPI_4;
		wxCheckBox* chkGPIO_OUT_SPI_5;
		wxCheckBox* chkGPIO_OUT_SPI_6;
		wxCheckBox* chkGPIO_OUT_SPI_7;
		wxCheckBox* chkGPIO_OUT_SPI_8;
		wxStaticText* m_staticText1;
		wxComboBox* cmbGPIO0_SEL;
		wxStaticText* m_staticText11;
		wxComboBox* cmbGPIO1_SEL;
		wxStaticText* m_staticText111;
		wxComboBox* cmbGPIO2_SEL;
		wxStaticText* m_staticText1111;
		wxComboBox* cmbGPIO3_SEL;
		wxStaticText* m_staticText11111;
		wxComboBox* cmbGPIO4_SEL;
		wxStaticText* m_staticText111111;
		wxComboBox* cmbGPIO5_SEL;
		wxStaticText* m_staticText1111111;
		wxComboBox* cmbGPIO6_SEL;
		wxStaticText* m_staticText11111111;
		wxComboBox* cmbGPIO7_SEL;
		wxStaticText* m_staticText111111111;
		wxComboBox* cmbGPIO8_SEL;
		wxCheckBox* chkGPIO_IN_0;
		wxCheckBox* chkGPIO_IN_1;
		wxCheckBox* chkGPIO_IN_2;
		wxCheckBox* chkGPIO_IN_3;
		wxCheckBox* chkGPIO_IN_4;
		wxCheckBox* chkGPIO_IN_5;
		wxCheckBox* chkGPIO_IN_6;
		wxCheckBox* chkGPIO_IN_7;
		wxCheckBox* chkGPIO_IN_8;
		wxCheckBox* chkGPIO_PE_0;
		wxCheckBox* chkGPIO_PE_1;
		wxCheckBox* chkGPIO_PE_2;
		wxCheckBox* chkGPIO_PE_3;
		wxCheckBox* chkGPIO_PE_4;
		wxCheckBox* chkGPIO_PE_5;
		wxCheckBox* chkGPIO_PE_6;
		wxCheckBox* chkGPIO_PE_7;
		wxCheckBox* chkGPIO_PE_8;
		wxCheckBox* chkGPIO_DS_0;
		wxCheckBox* chkGPIO_DS_1;
		wxCheckBox* chkGPIO_DS_2;
		wxCheckBox* chkGPIO_DS_3;
		wxCheckBox* chkGPIO_DS_4;
		wxCheckBox* chkGPIO_DS_5;
		wxCheckBox* chkGPIO_DS_6;
		wxCheckBox* chkGPIO_DS_7;
		wxCheckBox* chkGPIO_DS_8;
		wxStaticText* m_staticText37;
		wxStaticText* m_staticText372;
		wxCheckBox* chkGPIO_InO_0;
		wxCheckBox* chkGPIO_InO_1;
		wxCheckBox* chkGPIO_InO_2;
		wxCheckBox* chkGPIO_InO_3;
		wxCheckBox* chkGPIO_InO_4;
		wxCheckBox* chkGPIO_InO_5;
		wxCheckBox* chkGPIO_InO_6;
		wxCheckBox* chkGPIO_InO_7;
		wxCheckBox* chkGPIO_InO_8;
		wxStaticText* m_staticText371;
		wxStaticText* m_staticText3711;
		wxRadioBox* rgrSPI_SDIO_DS;
		wxRadioBox* rgrSPI_SDO_DS;
		wxCheckBox* chkSPI_SDIO_PE;
		wxCheckBox* chkSPI_SDO_PE;
		wxCheckBox* chkSPI_SCLK_PE;
		wxCheckBox* chkSPI_SEN_PE;
		wxRadioBox* rgrSPIMODE;
		wxCheckBox* chkTEMP_SENS_EN;
		wxCheckBox* chkTEMP_SENS_CLKEN;
		wxCheckBox* chkTEMP_START_CONV;
		wxStaticText* m_staticText280;
		wxStaticText* sttxtTEMP_READ;
		wxStaticText* m_staticText2801;
		wxStaticText* sttxtTemp;
		wxButton* btnTempRead;
		wxButton* btnTempCalibrate;
		wxStaticText* m_staticText40;
		wxStaticText* sttxtVER;
		wxStaticText* m_staticText41;
		wxStaticText* sttxtREV;
		wxStaticText* m_staticText42;
		wxStaticText* sttxtMASK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI_sttxtTemp( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnClick_btnTempRead( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_btnTempCalibrate( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlConfig_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlConfig_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlLDO_view
///////////////////////////////////////////////////////////////////////////////
class pnlLDO_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_PD_FRP_BIAS = 2048,
			ID_PD_F_BIAS,
			ID_PD_PTRP_BIAS,
			ID_PD_PT_BIAS,
			ID_PD_BIAS,
			ID_EN_LDO_LOBUFA,
			ID_EN_LDO_LOBUFB,
			ID_EN_LDO_LOBUFC,
			ID_EN_LDO_HFLNAA,
			ID_EN_LDO_HFLNAB,
			ID_EN_LDO_HFLNAC,
			ID_EN_LDO_HFLNAD,
			ID_EN_LDO_CLK_BUF,
			ID_EN_LDO_PLL_DIV,
			ID_EN_LDO_PLL_CP,
			ID_PD_LDO_DIG_CORE,
			ID_SPDUP_LDO_LOBUFA,
			ID_SPDUP_LDO_LOBUFB,
			ID_SPDUP_LDO_LOBUFC,
			ID_SPDUP_LDO_LOBUFD,
			ID_SPDUP_LDO_HFLNAA,
			ID_SPDUP_LDO_HFLNAB,
			ID_SPDUP_LDO_HFLNAC,
			ID_SPDUP_LDO_HFLNAD,
			ID_SPDUP_LDO_CLK_BUF,
			ID_SPDUP_LDO_PLL_DIV,
			ID_SPDUP_LDO_PLL_CP,
			ID_SPDUP_LDO_DIG_CORE,
			ID_EN_LOADIMP_LDO_LOBUFA,
			ID_EN_LOADIMP_LDO_LOBUFB,
			ID_EN_LOADIMP_LDO_LOBUFC,
			ID_EN_LOADIMP_LDO_LOBUFD,
			ID_EN_LOADIMP_LDO_HFLNAA,
			ID_EN_LOADIMP_LDO_HFLNAB,
			ID_EN_LOADIMP_LDO_HFLNAD,
			ID_EN_LOADIMP_LDO_CLK_BUF,
			ID_EN_LOADIMP_LDO_PLL_DIV,
			ID_EN_LOADIMP_LDO_PLL_CP,
			ID_EN_LOADIMP_LDO_DIG_CORE,
			ID_RDIV_LOBUFA,
			ID_RDIV_LOBUFB,
			ID_RDIV_LOBUFC,
			ID_RDIV_LOBUFD,
			ID_RDIV_HFLNAA,
			ID_RDIV_HFLNAB,
			ID_RDIV_HFLNAC,
			ID_RDIV_HFLNAD,
			ID_RDIV_CLK_BUF,
			ID_RDIV_PLL_DIV,
			ID_RDIV_PLL_CP,
			ID_RDIV_DIG_CORE,
			ID_PD_CALIB_COMP,
			ID_RP_CALIB_BIAS
		};
		
		wxNotebook* ID_NOTEBOOK_LDO;
		wxPanel* ID_PANEL_LDO;
		wxCheckBox* chkPD_FRP_BIAS;
		wxCheckBox* chkPD_F_BIAS;
		wxCheckBox* chkPD_PTRP_BIAS;
		wxCheckBox* chkPD_PT_BIAS;
		wxCheckBox* chkPD_BIAS;
		wxCheckBox* chkEN_LDO_LOBUFA;
		wxCheckBox* chkEN_LDO_LOBUFB;
		wxCheckBox* chkEN_LDO_LOBUFC;
		wxCheckBox* chkEN_LDO_LOBUFD;
		wxCheckBox* chkEN_LDO_HFLNAA;
		wxCheckBox* chkEN_LDO_HFLNAB;
		wxCheckBox* chkEN_LDO_HFLNAC;
		wxCheckBox* chkEN_LDO_HFLNAD;
		wxCheckBox* chkEN_LDO_CLK_BUF;
		wxCheckBox* chkEN_LDO_PLL_DIV;
		wxCheckBox* chkEN_LDO_PLL_CP;
		wxCheckBox* chkPD_LDO_DIG_CORE;
		wxCheckBox* chkSPDUP_LDO_LOBUFA;
		wxCheckBox* chkSPDUP_LDO_LOBUFB;
		wxCheckBox* chkSPDUP_LDO_LOBUFC;
		wxCheckBox* chkSPDUP_LDO_LOBUFD;
		wxCheckBox* chkSPDUP_LDO_HFLNAA;
		wxCheckBox* chkSPDUP_LDO_HFLNAB;
		wxCheckBox* chkSPDUP_LDO_HFLNAC;
		wxCheckBox* chkSPDUP_LDO_HFLNAD;
		wxCheckBox* chkSPDUP_LDO_CLK_BUF;
		wxCheckBox* chkSPDUP_LDO_PLL_DIV;
		wxCheckBox* chkSPDUP_LDO_PLL_CP;
		wxCheckBox* chkSPDUP_LDO_DIG_CORE;
		wxCheckBox* chkEN_LOADIMP_LDO_LOBUFA;
		wxCheckBox* chkEN_LOADIMP_LDO_LOBUFB;
		wxCheckBox* chkEN_LOADIMP_LDO_LOBUFC;
		wxCheckBox* chkEN_LOADIMP_LDO_LOBUFD;
		wxCheckBox* chkEN_LOADIMP_LDO_HFLNAA;
		wxCheckBox* chkEN_LOADIMP_LDO_HFLNAB;
		wxCheckBox* chkEN_LOADIMP_LDO_HFLNAC;
		wxCheckBox* chkEN_LOADIMP_LDO_HFLNAD;
		wxCheckBox* chkEN_LOADIMP_LDO_CLK_BUF;
		wxCheckBox* chkEN_LOADIMP_LDO_PLL_DIV;
		wxCheckBox* chkEN_LOADIMP_LDO_PLL_CP;
		wxCheckBox* chkEN_LOADIMP_LDO_DIG_CORE;
		wxStaticText* m_staticText44;
		wxComboBox* cmbRDIV_LOBUFA;
		wxStaticText* m_staticText441;
		wxComboBox* cmbRDIV_LOBUFB;
		wxStaticText* m_staticText4411;
		wxComboBox* cmbRDIV_LOBUFC;
		wxStaticText* m_staticText44111;
		wxComboBox* cmbRDIV_LOBUFD;
		wxStaticText* m_staticText442;
		wxComboBox* cmbRDIV_HFLNAA;
		wxStaticText* m_staticText4421;
		wxComboBox* cmbRDIV_HFLNAB;
		wxStaticText* m_staticText44211;
		wxComboBox* cmbRDIV_HFLNAC;
		wxStaticText* m_staticText442111;
		wxComboBox* cmbRDIV_HFLNAD;
		wxStaticText* m_staticText4421111;
		wxComboBox* cmbRDIV_CLK_BUF;
		wxStaticText* m_staticText44211111;
		wxComboBox* cmbRDIV_PLL_DIV;
		wxStaticText* m_staticText442111111;
		wxComboBox* cmbRDIV_PLL_CP;
		wxStaticText* m_staticText4421111111;
		wxComboBox* cmbRDIV_DIG_CORE;
		wxCheckBox* chkPD_CALIB_COMP;
		wxCheckBox* chkRP_CALIB_COMP;
		wxStaticText* m_staticText43;
		wxSpinCtrl* cmbRP_CALIB_BIAS;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxSpinEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlLDO_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlLDO_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlChannel_view
///////////////////////////////////////////////////////////////////////////////
class pnlChannel_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_CHx_PA_ILIN2X = 2048,
			ID_RP_CALIB_BIAS
		};
		
		wxNotebook* ID_NOTEBOOK_CHANNEL;
		wxPanel* ID_PANEL_CHANNEL;
		wxCheckBox* chkCHx_PA_ILIN2X;
		wxStaticText* m_staticText4311;
		wxSpinCtrl* cmbCHx_PA_ICT_LIN;
		wxStaticText* m_staticText43111;
		wxSpinCtrl* cmbCHx_PA_ICT_MAIN;
		wxNotebook* ID_NOTEBOOK_CH_PROGRAM;
		wxPanel* ID_PANEL_CH_P0;
		wxPanel* pnlChannel;
		wxCheckBox* chkCHx_LNA_PD0;
		wxCheckBox* chkCHx_MIXB_LOBUFF_PD0;
		wxCheckBox* chkCHx_MIXA_LOBUFF_PD0;
		wxCheckBox* chkCHx_PA_R50_EN0;
		wxCheckBox* chkCHx_PA_BYPASS0;
		wxCheckBox* chkCHx_PA_PD0;
		wxStaticText* m_staticText431111;
		wxSpinCtrl* cmbCHx_LNA_ICT_LIN0;
		wxStaticText* m_staticText4311111;
		wxSpinCtrl* cmbCHx_LNA_ICT_MAIN0;
		wxStaticText* m_staticText43111111;
		wxSpinCtrl* cmbCHx_LNA_CGSCTRL0;
		wxStaticText* m_staticText431111111;
		wxSpinCtrl* cmbCHx_LNA_GCTRL0;
		wxStaticText* m_staticText4311111111;
		wxSpinCtrl* cmbCHx_PA_LIN_LOSS0;
		wxStaticText* m_staticText43111111111;
		wxSpinCtrl* cmbCHx_PA_MAIN_LOSS0;
		wxPanel* ID_PANEL_CH_P1;
		wxPanel* pnlChannel1;
		wxCheckBox* chkCHx_LNA_PD1;
		wxCheckBox* chkCHx_MIXB_LOBUFF_PD1;
		wxCheckBox* chkCHx_MIXA_LOBUFF_PD1;
		wxCheckBox* chkCHx_PA_R50_EN1;
		wxCheckBox* chkCHx_PA_BYPASS1;
		wxCheckBox* chkCHx_PA_PD1;
		wxStaticText* m_staticText4311112;
		wxSpinCtrl* cmbCHx_LNA_ICT_LIN1;
		wxStaticText* m_staticText43111112;
		wxSpinCtrl* cmbCHx_LNA_ICT_MAIN1;
		wxStaticText* m_staticText431111112;
		wxSpinCtrl* cmbCHx_LNA_CGSCTRL1;
		wxStaticText* m_staticText4311111112;
		wxSpinCtrl* cmbCHx_LNA_GCTRL1;
		wxStaticText* m_staticText43111111112;
		wxSpinCtrl* cmbCHx_PA_LIN_LOSS1;
		wxStaticText* m_staticText431111111111;
		wxSpinCtrl* cmbCHx_PA_MAIN_LOSS1;
		wxPanel* ID_PANEL_CH_P2;
		wxPanel* pnlChannel11;
		wxCheckBox* chkCHx_LNA_PD2;
		wxCheckBox* chkCHx_MIXB_LOBUFF_PD2;
		wxCheckBox* chkCHx_MIXA_LOBUFF_PD2;
		wxCheckBox* chkCHx_PA_R50_EN2;
		wxCheckBox* chkCHx_PA_BYPASS2;
		wxCheckBox* chkCHx_PA_PD2;
		wxStaticText* m_staticText43111121;
		wxSpinCtrl* cmbCHx_LNA_ICT_LIN2;
		wxStaticText* m_staticText431111121;
		wxSpinCtrl* cmbCHx_LNA_ICT_MAIN2;
		wxStaticText* m_staticText4311111121;
		wxSpinCtrl* cmbCHx_LNA_CGSCTRL2;
		wxStaticText* m_staticText43111111121;
		wxSpinCtrl* cmbCHx_LNA_GCTRL2;
		wxStaticText* m_staticText431111111121;
		wxSpinCtrl* cmbCHx_PA_LIN_LOSS2;
		wxStaticText* m_staticText4311111111111;
		wxSpinCtrl* cmbCHx_PA_MAIN_LOSS2;
		wxPanel* ID_PANEL_CH_P3;
		wxPanel* pnlChannel111;
		wxCheckBox* chkCHx_LNA_PD3;
		wxCheckBox* chkCHx_MIXB_LOBUFF_PD3;
		wxCheckBox* chkCHx_MIXA_LOBUFF_PD3;
		wxCheckBox* chkCHx_PA_R50_EN3;
		wxCheckBox* chkCHx_PA_BYPASS3;
		wxCheckBox* chkCHx_PA_PD3;
		wxStaticText* m_staticText431111211;
		wxSpinCtrl* cmbCHx_LNA_ICT_LIN3;
		wxStaticText* m_staticText4311111211;
		wxSpinCtrl* cmbCHx_LNA_ICT_MAIN3;
		wxStaticText* m_staticText43111111211;
		wxSpinCtrl* cmbCHx_LNA_CGSCTRL3;
		wxStaticText* m_staticText431111111211;
		wxSpinCtrl* cmbCHx_LNA_GCTRL3;
		wxStaticText* m_staticText4311111111211;
		wxSpinCtrl* cmbCHx_PA_LIN_LOSS3;
		wxStaticText* m_staticText43111111111111;
		wxSpinCtrl* cmbCHx_PA_MAIN_LOSS3;
		wxPanel* ID_PANEL_CH_RB;
		wxPanel* pnlChannel1111;
		wxCheckBox* chkCHx_LNA_PD_RB;
		wxCheckBox* chkCHx_MIXB_LOBUFF_PD_RB;
		wxCheckBox* chkCHx_MIXA_LOBUFF_PD_RB;
		wxCheckBox* chkCHx_PA_R50_EN_RB;
		wxCheckBox* chkCHx_PA_BYPASS_RB;
		wxCheckBox* chkCHx_PA_PD_RB;
		wxStaticText* m_staticText4311112111;
		wxSpinCtrl* cmbCHx_LNA_ICT_LIN_RB;
		wxStaticText* m_staticText43111112111;
		wxSpinCtrl* cmbCHx_LNA_ICT_MAIN_RB;
		wxStaticText* m_staticText431111112111;
		wxSpinCtrl* cmbCHx_LNA_CGSCTRL_RB;
		wxStaticText* m_staticText4311111112111;
		wxSpinCtrl* cmbCHx_LNA_GCTRL_RB;
		wxStaticText* m_staticText43111111112111;
		wxSpinCtrl* cmbCHx_PA_LIN_LOSS_RB;
		wxStaticText* m_staticText431111111111111;
		wxSpinCtrl* cmbCHx_PA_MAIN_LOSS_RB;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_PD;
		wxPanel* ID_PANEL_MUX_PD_SEL0;
		wxCheckBox* chkCHx_PD_SEL0_INTERNAL;
		wxCheckBox* chkCHx_PD_SEL0_INVERT;
		wxStaticText* m_staticText265;
		wxStaticText* m_staticText2651;
		wxStaticText* m_staticText2652;
		wxStaticText* m_staticText2653;
		wxStaticText* m_staticText2654;
		wxStaticText* m_staticText2655;
		wxStaticText* m_staticText2656;
		wxStaticText* m_staticText2657;
		wxStaticText* m_staticText2658;
		wxCheckBox* chkCHx_PD_SEL0_MASK0;
		wxCheckBox* chkCHx_PD_SEL0_MASK1;
		wxCheckBox* chkCHx_PD_SEL0_MASK2;
		wxCheckBox* chkCHx_PD_SEL0_MASK3;
		wxCheckBox* chkCHx_PD_SEL0_MASK4;
		wxCheckBox* chkCHx_PD_SEL0_MASK5;
		wxCheckBox* chkCHx_PD_SEL0_MASK6;
		wxCheckBox* chkCHx_PD_SEL0_MASK7;
		wxCheckBox* chkCHx_PD_SEL0_MASK8;
		wxPanel* ID_PANEL_MUX_PD_SEL01;
		wxCheckBox* chkCHx_PD_SEL1_INTERNAL;
		wxCheckBox* chkCHx_PD_SEL1_INVERT;
		wxStaticText* m_staticText2659;
		wxStaticText* m_staticText26511;
		wxStaticText* m_staticText26521;
		wxStaticText* m_staticText26531;
		wxStaticText* m_staticText26541;
		wxStaticText* m_staticText26551;
		wxStaticText* m_staticText26561;
		wxStaticText* m_staticText26571;
		wxStaticText* m_staticText26581;
		wxCheckBox* chkCHx_PD_SEL1_MASK0;
		wxCheckBox* chkCHx_PD_SEL1_MASK1;
		wxCheckBox* chkCHx_PD_SEL1_MASK2;
		wxCheckBox* chkCHx_PD_SEL1_MASK3;
		wxCheckBox* chkCHx_PD_SEL1_MASK4;
		wxCheckBox* chkCHx_PD_SEL1_MASK5;
		wxCheckBox* chkCHx_PD_SEL1_MASK6;
		wxCheckBox* chkCHx_PD_SEL1_MASK7;
		wxCheckBox* chkCHx_PD_SEL1_MASK8;
		wxCheckBox* chkCHx_PD_INT_SEL0;
		wxCheckBox* chkCHx_PD_INT_SEL1;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_LNA;
		wxPanel* ID_PANEL_MUX_PD_SEL02;
		wxCheckBox* chkCHx_LNA_SEL0_INTERNAL;
		wxCheckBox* chkCHx_LNA_SEL0_INVERT;
		wxStaticText* m_staticText26510;
		wxStaticText* m_staticText26512;
		wxStaticText* m_staticText26522;
		wxStaticText* m_staticText26532;
		wxStaticText* m_staticText26542;
		wxStaticText* m_staticText26552;
		wxStaticText* m_staticText26562;
		wxStaticText* m_staticText26572;
		wxStaticText* m_staticText26582;
		wxCheckBox* chkCHx_LNA_SEL0_MASK0;
		wxCheckBox* chkCHx_LNA_SEL0_MASK1;
		wxCheckBox* chkCHx_LNA_SEL0_MASK2;
		wxCheckBox* chkCHx_LNA_SEL0_MASK3;
		wxCheckBox* chkCHx_LNA_SEL0_MASK4;
		wxCheckBox* chkCHx_LNA_SEL0_MASK5;
		wxCheckBox* chkCHx_LNA_SEL0_MASK6;
		wxCheckBox* chkCHx_LNA_SEL0_MASK7;
		wxCheckBox* chkCHx_LNA_SEL0_MASK8;
		wxPanel* ID_PANEL_MUX_PD_SEL011;
		wxCheckBox* chkCHx_LNA_SEL1_INTERNAL;
		wxCheckBox* chkCHx_LNA_SEL1_INVERT;
		wxStaticText* m_staticText26591;
		wxStaticText* m_staticText265111;
		wxStaticText* m_staticText265211;
		wxStaticText* m_staticText265311;
		wxStaticText* m_staticText265411;
		wxStaticText* m_staticText265511;
		wxStaticText* m_staticText265611;
		wxStaticText* m_staticText265711;
		wxStaticText* m_staticText265811;
		wxCheckBox* chkCHx_LNA_SEL1_MASK0;
		wxCheckBox* chkCHx_LNA_SEL1_MASK1;
		wxCheckBox* chkCHx_LNA_SEL1_MASK2;
		wxCheckBox* chkCHx_LNA_SEL1_MASK3;
		wxCheckBox* chkCHx_LNA_SEL1_MASK4;
		wxCheckBox* chkCHx_LNA_SEL1_MASK5;
		wxCheckBox* chkCHx_LNA_SEL1_MASK6;
		wxCheckBox* chkCHx_LNA_SEL1_MASK7;
		wxCheckBox* chkCHx_LNA_SEL1_MASK8;
		wxCheckBox* chkCHx_LNA_INT_SEL0;
		wxCheckBox* chkCHx_LNA_INT_SEL1;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_PA;
		wxPanel* ID_PANEL_MUX_PD_SEL03;
		wxCheckBox* chkCHx_PA_SEL0_INTERNAL;
		wxCheckBox* chkCHx_PA_SEL0_INVERT;
		wxStaticText* m_staticText26513;
		wxStaticText* m_staticText26514;
		wxStaticText* m_staticText26523;
		wxStaticText* m_staticText26533;
		wxStaticText* m_staticText26543;
		wxStaticText* m_staticText26553;
		wxStaticText* m_staticText26563;
		wxStaticText* m_staticText26573;
		wxStaticText* m_staticText26583;
		wxCheckBox* chkCHx_PA_SEL0_MASK0;
		wxCheckBox* chkCHx_PA_SEL0_MASK1;
		wxCheckBox* chkCHx_PA_SEL0_MASK2;
		wxCheckBox* chkCHx_PA_SEL0_MASK3;
		wxCheckBox* chkCHx_PA_SEL0_MASK4;
		wxCheckBox* chkCHx_PA_SEL0_MASK5;
		wxCheckBox* chkCHx_PA_SEL0_MASK6;
		wxCheckBox* chkCHx_PA_SEL0_MASK7;
		wxCheckBox* chkCHx_PA_SEL0_MASK8;
		wxPanel* ID_PANEL_MUX_PD_SEL012;
		wxCheckBox* chkCHx_PA_SEL1_INTERNAL;
		wxCheckBox* chkCHx_PA_SEL1_INVERT;
		wxStaticText* m_staticText26592;
		wxStaticText* m_staticText265112;
		wxStaticText* m_staticText265212;
		wxStaticText* m_staticText265312;
		wxStaticText* m_staticText265412;
		wxStaticText* m_staticText265512;
		wxStaticText* m_staticText265612;
		wxStaticText* m_staticText265712;
		wxStaticText* m_staticText265812;
		wxCheckBox* chkCHx_PA_SEL1_MASK0;
		wxCheckBox* chkCHx_PA_SEL1_MASK1;
		wxCheckBox* chkCHx_PA_SEL1_MASK2;
		wxCheckBox* chkCHx_PA_SEL1_MASK3;
		wxCheckBox* chkCHx_PA_SEL1_MASK4;
		wxCheckBox* chkCHx_PA_SEL1_MASK5;
		wxCheckBox* chkCHx_PA_SEL1_MASK6;
		wxCheckBox* chkCHx_PA_SEL1_MASK7;
		wxCheckBox* chkCHx_PA_SEL1_MASK8;
		wxCheckBox* chkCHx_PA_INT_SEL0;
		wxCheckBox* chkCHx_PA_INT_SEL1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnEraseBackground_pnlChannel( wxEraseEvent& event ) { event.Skip(); }
		virtual void OnClick_chkCHx_PA_BYPASS0( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClick_chkCHx_PA_PD0( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlChannel_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlChannel_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlHLMIX_view
///////////////////////////////////////////////////////////////////////////////
class pnlHLMIX_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_HLMIXx_VGCAS0 = 2048,
			ID_RP_CALIB_BIAS,
			ID_CHx_PA_ILIN2X,
			ID_HLMIXx_VGCAS1,
			ID_HLMIXx_VGCAS2,
			ID_HLMIXx_VGCAS3
		};
		
		wxNotebook* ID_NOTEBOOK_HLMIX;
		wxPanel* ID_PANEL_HLMIX;
		wxNotebook* ID_NOTEBOOK_HLMIX_PROGRAM;
		wxPanel* ID_PANEL_HLMIX_P0;
		wxStaticText* m_staticText6493;
		wxSpinCtrl* cmbHLMIXx_VGCAS0;
		wxStaticText* m_staticText649;
		wxSpinCtrl* cmbHLMIXx_ICT_BIAS0;
		wxCheckBox* chkHLMIXx_BIAS_PD0;
		wxCheckBox* chkHLMIXx_LOBUF_PD0;
		wxStaticText* m_staticText6491;
		wxSpinCtrl* cmbHLMIXx_MIXLOSS0;
		wxPanel* ID_PANEL_HLMIX_P1;
		wxStaticText* m_staticText64922;
		wxSpinCtrl* cmbHLMIXx_VGCAS1;
		wxStaticText* m_staticText6492;
		wxSpinCtrl* cmbHLMIXx_ICT_BIAS1;
		wxCheckBox* chkHLMIXx_BIAS_PD1;
		wxCheckBox* chkHLMIXx_LOBUF_PD1;
		wxStaticText* m_staticText64912;
		wxSpinCtrl* cmbHLMIXx_MIXLOSS1;
		wxPanel* ID_PANEL_HLMIX_P2;
		wxStaticText* m_staticText649212;
		wxSpinCtrl* cmbHLMIXx_VGCAS2;
		wxStaticText* m_staticText64921;
		wxSpinCtrl* cmbHLMIXx_ICT_BIAS2;
		wxCheckBox* chkHLMIXx_BIAS_PD2;
		wxCheckBox* chkHLMIXx_LOBUF_PD2;
		wxStaticText* m_staticText649121;
		wxSpinCtrl* cmbHLMIXx_MIXLOSS2;
		wxPanel* ID_PANEL_HLMIX_P3;
		wxStaticText* m_staticText6492121;
		wxSpinCtrl* cmbHLMIXx_VGCAS3;
		wxStaticText* m_staticText649211;
		wxSpinCtrl* cmbHLMIXx_ICT_BIAS3;
		wxCheckBox* chkHLMIXx_BIAS_PD3;
		wxCheckBox* chkHLMIXx_LOBUF_PD3;
		wxStaticText* m_staticText6491211;
		wxSpinCtrl* cmbHLMIXx_MIXLOSS3;
		wxPanel* ID_PANEL_HLMIX_RB;
		wxStaticText* m_staticText64921211;
		wxSpinCtrl* cmbHLMIXx_VGCAS_RB;
		wxStaticText* m_staticText6492111;
		wxSpinCtrl* cmbHLMIXx_ICT_BIAS_RB;
		wxCheckBox* chkHLMIXx_BIAS_PD_RB;
		wxCheckBox* chkHLMIXx_LOBUF_PD_RB;
		wxStaticText* m_staticText64912111;
		wxSpinCtrl* cmbHLMIXx_MIXLOSS_RB;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_HLMIX_CONFIG;
		wxPanel* ID_PANEL_MUX_HLMIX_CONFIG_SEL0;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_INTERNAL;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_INVERT;
		wxStaticText* m_staticText26510;
		wxStaticText* m_staticText26512;
		wxStaticText* m_staticText26522;
		wxStaticText* m_staticText26532;
		wxStaticText* m_staticText26542;
		wxStaticText* m_staticText26552;
		wxStaticText* m_staticText26562;
		wxStaticText* m_staticText26572;
		wxStaticText* m_staticText26582;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK0;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK1;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK2;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK3;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK4;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK5;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK6;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK7;
		wxCheckBox* chkHLMIXx_CONFIG_SEL0_MASK8;
		wxPanel* ID_PANEL_MUX_HLMIX_CONFIG_SEL1;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_INTERNAL;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_INVERT;
		wxStaticText* m_staticText26591;
		wxStaticText* m_staticText265111;
		wxStaticText* m_staticText265211;
		wxStaticText* m_staticText265311;
		wxStaticText* m_staticText265411;
		wxStaticText* m_staticText265511;
		wxStaticText* m_staticText265611;
		wxStaticText* m_staticText265711;
		wxStaticText* m_staticText265811;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK0;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK1;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK2;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK3;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK4;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK5;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK6;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK7;
		wxCheckBox* chkHLMIXx_CONFIG_SEL1_MASK8;
		wxCheckBox* chkHLMIXx_CONFIG_INT_SEL0;
		wxCheckBox* chkHLMIXx_CONFIG_INT_SEL1;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_HLMIX;
		wxPanel* ID_PANEL_MUX_HLMIX_SEL0;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_INTERNAL;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_INVERT;
		wxStaticText* m_staticText265;
		wxStaticText* m_staticText2651;
		wxStaticText* m_staticText2652;
		wxStaticText* m_staticText2653;
		wxStaticText* m_staticText2654;
		wxStaticText* m_staticText2655;
		wxStaticText* m_staticText2656;
		wxStaticText* m_staticText2657;
		wxStaticText* m_staticText2658;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK0;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK1;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK2;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK3;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK4;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK5;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK6;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK7;
		wxCheckBox* chkHLMIXx_LOSS_SEL0_MASK8;
		wxPanel* ID_PANEL_MUX_HLMIX_SEL1;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_INTERNAL;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_INVERT;
		wxStaticText* m_staticText2659;
		wxStaticText* m_staticText26511;
		wxStaticText* m_staticText26521;
		wxStaticText* m_staticText26531;
		wxStaticText* m_staticText26541;
		wxStaticText* m_staticText26551;
		wxStaticText* m_staticText26561;
		wxStaticText* m_staticText26571;
		wxStaticText* m_staticText26581;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK0;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK1;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK2;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK3;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK4;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK5;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK6;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK7;
		wxCheckBox* chkHLMIXx_LOSS_SEL1_MASK8;
		wxCheckBox* chkHLMIXx_LOSS_INT_SEL0;
		wxCheckBox* chkHLMIXx_LOSS_INT_SEL1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ParameterChangeHandler( wxSpinEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlHLMIX_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlHLMIX_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlPLLConfig_view
///////////////////////////////////////////////////////////////////////////////
class pnlPLLConfig_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_CHx_PA_ILIN2X = 2048,
			ID_RDIV_LOBUFA,
			ID_VCO_SEL_FINAL,
			ID_VTUNE_HIGH,
			ID_VTUNE_LOW,
			ID_PLL_LOCK,
			ID_PLL_CFG_SEL0_MASK0,
			ID_PLL_CFG_SEL0_MASK1,
			ID_PLL_CFG_SEL0_MASK2,
			ID_PLL_CFG_SEL0_MASK3,
			ID_PLL_CFG_SEL0_MASK4,
			ID_PLL_CFG_SEL0_MASK5,
			ID_PLL_CFG_SEL0_MASK6,
			ID_PLL_CFG_SEL0_MASK7,
			ID_PLL_CFG_SEL0_MASK8,
			ID_PLL_CFG_SEL1_MASK0,
			ID_PLL_CFG_SEL1_MASK1,
			ID_PLL_CFG_SEL1_MASK2,
			ID_PLL_CFG_SEL1_MASK3,
			ID_PLL_CFG_SEL1_MASK4,
			ID_PLL_CFG_SEL1_MASK5,
			ID_PLL_CFG_SEL1_MASK6,
			ID_PLL_CFG_SEL1_MASK7,
			ID_PLL_CFG_SEL1_MASK8,
			ID_PLL_CFG_SEL2_INTERNAL,
			ID_PLL_CFG_SEL2_INVERT,
			ID_PLL_CFG_SEL2_MASK0,
			ID_PLL_CFG_SEL2_MASK1,
			ID_PLL_CFG_SEL2_MASK2,
			ID_PLL_CFG_SEL2_MASK3,
			ID_PLL_CFG_SEL2_MASK4,
			ID_PLL_CFG_SEL2_MASK5,
			ID_PLL_CFG_SEL2_MASK6,
			ID_PLL_CFG_SEL2_MASK7,
			ID_PLL_CFG_SEL2_MASK8,
			ID_PLL_CFG_INT_SEL0,
			ID_PLL_CFG_INT_SEL1,
			ID_PLL_CFG_INT_SEL2,
			ID_PLL_LODIST_ICT_CORE,
			ID_PLL_LODIST_ICT_BUF,
			ID_BSTATE,
			ID_EN_SDM_TSTO
		};
		
		wxNotebook* ID_NOTEBOOK_PLLCONFIG;
		wxPanel* ID_PANEL_PLLCONFIG;
		wxCheckBox* chkEN_VCOBIAS;
		wxCheckBox* chkBYP_VCOREG;
		wxCheckBox* chkCURLIM_VCOREG;
		wxCheckBox* chkSPDUP_VCOREG;
		wxStaticText* m_staticText991;
		wxComboBox* cmbVDIV_VCOREG;
		wxCheckBox* chkPLL_XBUF_SLFBEN;
		wxCheckBox* chkPLL_XBUF_BYPEN;
		wxCheckBox* chkPLL_XBUF_EN;
		wxStaticText* m_staticText99211;
		wxSpinCtrl* cmbVCO_FREQ_MAN;
		wxStaticText* m_staticText9923;
		wxSpinCtrl* cmbVCO_SEL_MAN;
		wxStaticText* m_staticText99231;
		wxStaticText* m_staticText99232;
		wxStaticText* m_staticText99233;
		wxCheckBox* chkFREQ_LOW;
		wxCheckBox* chkFREQ_EQUAL;
		wxCheckBox* chkFREQ_HIGH;
		wxCheckBox* chkCTUNE_STEP_DONE;
		wxCheckBox* chkCTUNE_START;
		wxCheckBox* chkCTUNE_EN;
		wxStaticText* m_staticText1184;
		wxCheckBox* chkVTUNE_HIGH;
		wxCheckBox* chkVTUNE_LOW;
		wxCheckBox* chkPLL_LOCK;
		wxCheckBox* chkFCAL_START;
		wxCheckBox* chkVCO_SEL_FINAL_VAL;
		wxStaticText* m_staticText992;
		wxSpinCtrl* cmbVCO_SEL_FINAL;
		wxCheckBox* chkFREQ_FINAL_VAL;
		wxStaticText* m_staticText9921;
		wxSpinCtrl* cmbFREQ_FINAL;
		wxCheckBox* chkVCO_SEL_FORCE;
		wxStaticText* m_staticText9922;
		wxSpinCtrl* cmbVCO_SEL_INIT;
		wxStaticText* m_staticText99221;
		wxSpinCtrl* cmbFREQ_INIT_POS;
		wxStaticText* m_staticText992211;
		wxSpinCtrl* cmbFREQ_INIT;
		wxStaticText* m_staticText9922111;
		wxSpinCtrl* cmbFREQ_SETTLING_N;
		wxStaticText* m_staticText99221111;
		wxSpinCtrl* cmbVTUNE_WAIT_N;
		wxStaticText* m_staticText992211111;
		wxSpinCtrl* cmbVCO_SEL_FREQ_MAX;
		wxStaticText* m_staticText9922111111;
		wxSpinCtrl* cmbVCO_SEL_FREQ_MIN;
		wxCheckBox* chkSelectProfile;
		wxComboBox* chkPLL_CFG_INT_SEL;
		wxNotebook* ID_NOTEBOOK_MUX_CONTROL_PLL;
		wxPanel* ID_NOTEBOOK_MUX_CONTROL_PLL_SEL0;
		wxCheckBox* chkPLL_CFG_SEL0_INTERNAL;
		wxCheckBox* chkPLL_CFG_SEL0_INVERT;
		wxStaticText* m_staticText26510;
		wxStaticText* m_staticText26512;
		wxStaticText* m_staticText26522;
		wxStaticText* m_staticText26532;
		wxStaticText* m_staticText26542;
		wxStaticText* m_staticText26552;
		wxStaticText* m_staticText26562;
		wxStaticText* m_staticText26572;
		wxStaticText* m_staticText26582;
		wxCheckBox* chkPLL_CFG_SEL0_MASK0;
		wxCheckBox* chkPLL_CFG_SEL0_MASK1;
		wxCheckBox* chkPLL_CFG_SEL0_MASK2;
		wxCheckBox* chkPLL_CFG_SEL0_MASK3;
		wxCheckBox* chkPLL_CFG_SEL0_MASK4;
		wxCheckBox* chkPLL_CFG_SEL0_MASK5;
		wxCheckBox* chkPLL_CFG_SEL0_MASK6;
		wxCheckBox* chkPLL_CFG_SEL0_MASK7;
		wxCheckBox* chkPLL_CFG_SEL0_MASK8;
		wxPanel* ID_NOTEBOOK_MUX_CONTROL_PLL_SEL1;
		wxCheckBox* chkPLL_CFG_SEL1_INTERNAL;
		wxCheckBox* chkPLL_CFG_SEL1_INVERT;
		wxStaticText* m_staticText265101;
		wxStaticText* m_staticText265121;
		wxStaticText* m_staticText265221;
		wxStaticText* m_staticText265321;
		wxStaticText* m_staticText265421;
		wxStaticText* m_staticText265521;
		wxStaticText* m_staticText265621;
		wxStaticText* m_staticText265721;
		wxStaticText* m_staticText265821;
		wxCheckBox* chkPLL_CFG_SEL1_MASK0;
		wxCheckBox* chkPLL_CFG_SEL1_MASK1;
		wxCheckBox* chkPLL_CFG_SEL1_MASK2;
		wxCheckBox* chkPLL_CFG_SEL1_MASK3;
		wxCheckBox* chkPLL_CFG_SEL1_MASK4;
		wxCheckBox* chkPLL_CFG_SEL1_MASK5;
		wxCheckBox* chkPLL_CFG_SEL1_MASK6;
		wxCheckBox* chkPLL_CFG_SEL1_MASK7;
		wxCheckBox* chkPLL_CFG_SEL1_MASK8;
		wxPanel* ID_NOTEBOOK_MUX_CONTROL_PLL_SEL2;
		wxCheckBox* chkPLL_CFG_SEL2_INTERNAL;
		wxCheckBox* chkPLL_CFG_SEL2_INVERT;
		wxStaticText* m_staticText2651011;
		wxStaticText* m_staticText2651211;
		wxStaticText* m_staticText2652211;
		wxStaticText* m_staticText2653211;
		wxStaticText* m_staticText2654211;
		wxStaticText* m_staticText2655211;
		wxStaticText* m_staticText2656211;
		wxStaticText* m_staticText2657211;
		wxStaticText* m_staticText2658211;
		wxCheckBox* chkPLL_CFG_SEL2_MASK0;
		wxCheckBox* chkPLL_CFG_SEL2_MASK1;
		wxCheckBox* chkPLL_CFG_SEL2_MASK2;
		wxCheckBox* chkPLL_CFG_SEL2_MASK3;
		wxCheckBox* chkPLL_CFG_SEL2_MASK4;
		wxCheckBox* chkPLL_CFG_SEL2_MASK5;
		wxCheckBox* chkPLL_CFG_SEL2_MASK6;
		wxCheckBox* chkPLL_CFG_SEL2_MASK7;
		wxCheckBox* chkPLL_CFG_SEL2_MASK8;
		wxCheckBox* chkPLL_CFG_INT_SEL0;
		wxCheckBox* chkPLL_CFG_INT_SEL1;
		wxCheckBox* chkPLL_CFG_INT_SEL2;
		wxRadioBox* rgrPLL_RSTN;
		wxStaticText* m_staticText992111;
		wxComboBox* cmbCTUNE_RES;
		wxCheckBox* chkPLL_CALIBRATION_MODE;
		wxCheckBox* chkPLL_CALIBRATION_EN;
		wxCheckBox* chkPLL_FLOCK_INTERNAL;
		wxCheckBox* chkPLL_FLOCK_INTVAL;
		wxCheckBox* chkSEL_BIAS_CORE;
		wxStaticText* m_staticText1191;
		wxSpinCtrl* cmbPLL_LODIST_ICT_CORE;
		wxStaticText* m_staticText11911;
		wxSpinCtrl* cmbPLL_LODIST_ICT_BUF;
		wxChoice* choPLL_ICT_OUT0;
		wxStaticText* m_staticText1195;
		wxChoice* choPLL_ICT_OUT1;
		wxStaticText* m_staticText11951;
		wxChoice* choPLL_ICT_OUT2;
		wxStaticText* m_staticText119511;
		wxChoice* choPLL_ICT_OUT3;
		wxStaticText* m_staticText1195111;
		wxStaticText* m_staticText1205;
		wxSpinCtrl* cmbBSIGL;
		wxCheckBox* chkBSTATE;
		wxCheckBox* chkEN_SDM_TSTO;
		wxCheckBox* chkBEN;
		wxCheckBox* chkBSTART;
		wxStaticText* m_staticText1206;
		wxSpinCtrl* cmbBSIGH;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnSelectProfileClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlPLLConfig_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlPLLConfig_view();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class pnlPLLProfiles_view
///////////////////////////////////////////////////////////////////////////////
class pnlPLLProfiles_view : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_VTUNE_HIGH = 2048,
			ID_VTUNE_LOW,
			ID_PLL_LOCK,
			ID_TEST,
			ID_CHx_PA_ILIN2X,
			ID_VCO_SEL_FINAL,
			ID_RDIV_LOBUFA,
			ID_FLOCK_VCO_SPDUP_n,
			ID_chkPLL_LODIST_FSP_OUT02_n
		};
		
		wxRadioBox* rgrPLLProfile;
		wxStaticText* m_staticText272;
		wxCheckBox* chkVTUNE_HIGH;
		wxCheckBox* chkVTUNE_LOW;
		wxCheckBox* chkPLL_LOCK;
		wxStaticText* sttxtPLLFreq;
		wxStaticText* sttxtPLLFreq1;
		wxCheckBox* chkPLL_LODIST_EN_BIAS_n;
		wxCheckBox* chkPLL_LODIST_EN_DIV2IQ_n;
		wxCheckBox* chkPLL_EN_VTUNE_COMP_n;
		wxCheckBox* chkPLL_EN_LD_n;
		wxCheckBox* chkPLL_EN_PFD_n;
		wxCheckBox* chkPLL_EN_CP_n;
		wxCheckBox* chkPLL_EN_CPOFS_n;
		wxCheckBox* chkPLL_EN_VCO_n;
		wxCheckBox* chkPLL_EN_FFDIV_n;
		wxCheckBox* chkPLL_EN_FB_PDIV2_n;
		wxCheckBox* chkPLL_EN_FFCORE_n;
		wxCheckBox* chkPLL_EN_FBDIV_n;
		wxCheckBox* chkPLL_SDM_CLK_EN_n;
		wxCheckBox* chkFLIP_n;
		wxStaticText* m_staticText1328;
		wxSpinCtrl* cmbDEL_n;
		wxStaticText* m_staticText13281;
		wxComboBox* cmbPULSE_n;
		wxStaticText* m_staticText132811;
		wxComboBox* cmbOFS_n;
		wxStaticText* m_staticText1328111;
		wxComboBox* cmbLD_VCT_n;
		wxStaticText* m_staticText13281111;
		wxSpinCtrl* cmbICT_CP_n;
		wxStaticText* m_staticText1341;
		wxSpinCtrl* cmbVCO_FREQ_n;
		wxCheckBox* chkSPDUP_VCO_n;
		wxCheckBox* chkVCO_AAC_EN_n;
		wxStaticText* m_staticText1342;
		wxComboBox* cmbVDIV_SWVDD_n;
		wxStaticText* m_staticText1343;
		wxComboBox* cmbVCO_SEL_n;
		wxStaticText* m_staticText1344;
		wxSpinCtrl* cmbVCO_AMP_n;
		wxStaticText* m_staticText13113;
		wxComboBox* cmbFLOCK_R3_n;
		wxStaticText* m_staticText131111;
		wxComboBox* cmbFLOCK_R2_n;
		wxStaticText* m_staticText1311221;
		wxComboBox* cmbFLOCK_C3_n;
		wxStaticText* m_staticText131123;
		wxComboBox* cmbFLOCK_C2_n;
		wxStaticText* m_staticText1311211;
		wxComboBox* cmbFLOCK_C1_n;
		wxStaticText* m_staticText132812;
		wxComboBox* cmbFLOCK_PULSE_n;
		wxStaticText* m_staticText1328112;
		wxComboBox* cmbFLOCK_OFS_n;
		wxCheckBox* chkFLOCK_VCO_SPDUP_n;
		wxStaticText* m_staticText134211221;
		wxSpinCtrl* cmbFLOCK_N_n;
		wxStaticText* sttxtFLockN;
		wxStaticText* m_staticText1328122;
		wxCheckBox* chkFLOCK_LODIST_EN_OUT0_n;
		wxCheckBox* chkFLOCK_LODIST_EN_OUT1_n;
		wxCheckBox* chkFLOCK_LODIST_EN_OUT2_n;
		wxCheckBox* chkFLOCK_LODIST_EN_OUT3_n;
		wxStaticText* m_staticText1311;
		wxComboBox* cmbR3_n;
		wxStaticText* m_staticText13111;
		wxComboBox* cmbR2_n;
		wxStaticText* m_staticText131122;
		wxComboBox* cmbC3_n;
		wxStaticText* m_staticText13112;
		wxComboBox* cmbC2_n;
		wxStaticText* m_staticText131121;
		wxComboBox* cmbC1_n;
		wxStaticText* m_staticText1324;
		wxComboBox* cmbVTUNE_VCT_n;
		wxCheckBox* chkLPFSW_n;
		wxStaticText* m_staticText134211;
		wxComboBox* cmbFF_MOD_n;
		wxStaticText* m_staticText1342112;
		wxCheckBox* chkEnableFFDIVDebug;
		wxCheckBox* chkFFDIV_SEL_n;
		wxStaticText* m_staticText13421;
		wxComboBox* cmbFFCORE_MOD_n;
		wxCheckBox* chkINTMOD_EN_n;
		wxCheckBox* chkDITHER_EN_n;
		wxCheckBox* chkSEL_SDMCLK_n;
		wxCheckBox* chkREV_SDMCLK_n;
		wxStaticText* m_staticText1342111;
		wxSpinCtrl* cmbINTMOD_n;
		wxStaticText* m_staticText13421111;
		wxSpinCtrl* cmbFRACMODL_n;
		wxStaticText* m_staticText134211111;
		wxSpinCtrl* cmbFRACMODH_n;
		wxStaticText* m_staticText13421123;
		wxStaticText* m_staticText134211231;
		wxStaticText* m_staticText1342112311;
		wxStaticText* m_staticText1342112312;
		wxStaticText* m_staticText262;
		wxStaticText* m_staticText13421123111;
		wxCheckBox* chkPLL_LODIST_EN_OUT0_n;
		wxCheckBox* chkPLL_LODIST_FSP_OUT02_n;
		wxComboBox* cmbPLL_LODIST_FSP_OUT010_n;
		wxStaticText* sttxtLODistrChAFreq;
		wxStaticText* m_staticText134211231111;
		wxCheckBox* chkPLL_LODIST_EN_OUT1_n;
		wxCheckBox* chkPLL_LODIST_FSP_OUT12_n;
		wxComboBox* cmbPLL_LODIST_FSP_OUT110_n;
		wxStaticText* sttxtLODistrChBFreq;
		wxStaticText* m_staticText1342112311111;
		wxCheckBox* chkPLL_LODIST_EN_OUT2_n;
		wxCheckBox* chkPLL_LODIST_FSP_OUT22_n;
		wxComboBox* cmbPLL_LODIST_FSP_OUT210_n;
		wxStaticText* sttxtLODistrChCFreq;
		wxStaticText* m_staticText13421123111111;
		wxCheckBox* chkPLL_LODIST_EN_OUT3_n;
		wxCheckBox* chkPLL_LODIST_FSP_OUT32_n;
		wxComboBox* cmbPLL_LODIST_FSP_OUT310_n;
		wxStaticText* sttxtLODistrChDFreq;
		wxTextCtrl* txtRefClock;
		wxStaticText* m_staticText273;
		wxTextCtrl* txtVCOFrequency;
		wxButton* btnTune;
		wxStaticText* m_staticText2731;
		wxTextCtrl* txtSmartTunePLLFrequency;
		wxCheckBox* chkSmartTuneGenIQ;
		wxStaticText* m_staticText27311;
		wxTextCtrl* txtSmartTuneLoopBW;
		wxStaticText* m_staticText273111;
		wxTextCtrl* txtSmartTunePhaseMargin;
		wxStaticText* m_staticText2731111;
		wxTextCtrl* txtSmartTuneBWEF;
		wxButton* btnSmartTune;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSwitchPLLProfile( wxCommandEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnupdateUI_sttxtPLLFreq( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void ParameterChangeHandler( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI_cmbFLOCK_PULSE_n( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI_sttxtFLockN( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void On_FF_MOD_Change( wxCommandEvent& event ) { event.Skip(); }
		virtual void chkPLL_LODIST_FSP_OUTCH2_n_Change( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI_cmbPLL_LODIST_FSP_OUTCH10_n( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnTextRefClock( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTuneClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSmartTuneClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		pnlPLLProfiles_view( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL ); 
		~pnlPLLProfiles_view();
	
};

#endif //__LMS8001_WXGUI_H__
