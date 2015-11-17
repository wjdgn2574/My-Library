/*
 ============================================================================
 Name        : lib_Si114x.h
 Author      : wjdgn2574
 Version     : 0.7
 Copyright   :
 Description : Si114x Library Header File
 ============================================================================
*/

#ifndef __LIB_SI114X_H
#define __LIB_SI114X_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/*******************************************************************************
 * Exported defines
 ******************************************************************************/
// Si114x Slave Address
#define SI114X_SLAVE_ADDRESS				0x5A
#define SI114X_HW_KEY_VAL0					0x17		// Value to write into the HW Key register

// Si114x Register Address Map
#define SI114X_PART_ID						0x00
#define SI114X_REV_ID						0x01
#define SI114X_SEQ_ID						0x02
#define SI114X_INT_CFG						0x03
#define SI114X_IRQ_ENABLE					0x04
#define SI114X_IRQ_MODE1					0x05
#define SI114X_IRQ_MODE2					0x06
#define SI114X_HW_KEY						0x07
#define SI114X_MEAS_RATE					0x08
#define SI114X_ALS_RATE						0x09
#define SI114X_PS_RATE						0x0A
#define SI114X_ALS_LOW_TH0					0x0B
#define SI114X_ALS_LOW_TH1					0x0C
#define SI114X_ALS_HI_TH0					0x0D
#define SI114X_ALS_HI_TH1					0x0E
#define SI114X_PS_LED21						0x0F
#define SI114X_PS_LED3						0x10
#define SI114X_PS1_TH0						0x11
#define SI114X_PS1_TH1						0x12
#define SI114X_PS2_TH0						0x13
#define SI114X_PS2_TH1						0x14
#define SI114X_PS3_TH0						0x15
#define SI114X_PS3_TH1						0x16
#define SI114X_PARAM_WR						0x17
#define SI114X_COMMAND						0x18
#define SI114X_RESPONSE						0x20
#define SI114X_IRQ_STATUS					0x21
#define SI114X_ALS_VIS_DATA0				0x22
#define SI114X_ALS_VIS_DATA1				0x23
#define SI114X_ALS_IR_DATA0					0x24
#define SI114X_ALS_IR_DATA1					0x25
#define SI114X_PS1_DATA0					0x26
#define SI114X_PS1_DATA1 					0x27
#define SI114X_PS2_DATA0					0x28
#define SI114X_PS2_DATA1					0x29
#define SI114X_PS3_DATA0					0x2A
#define SI114X_PS3_DATA1 					0x2B
#define SI114X_AUX_DATA0					0x2C
#define SI114X_AUX_DATA1					0x2D
#define SI114X_PARAM_RD						0x2E
#define SI114X_CHIP_STAT					0x30
#define SI114X_ANA_IN_KEY0					0x3B
#define SI114X_ANA_IN_KEY1					0x3C
#define SI114X_ANA_IN_KEY2					0x3D
#define SI114X_ANA_IN_KEY3					0x3E

// Si114x RAM Address
#define SI114X_RAM_I2C_ADDR					0x00
#define SI114X_RAM_CHLIST					0x01
#define Si114X_RAM_PSLED12_SELECT			0x02
#define SI114X_RAM_PSLED3_SELECT			0x03
#define SI114X_RAM_FILTER_EN				0x04
#define SI114X_RAM_PS_ENCODING				0x05
#define SI114X_RAM_ALS_ENCODING				0x06
#define SI114X_RAM_PS1_ADCMUX				0x07
#define SI114X_RAM_PS2_ADCMUX				0x08
#define SI114X_RAM_PS3_ADCMUX				0x09
#define SI114X_RAM_PS_ADC_COUNTER			0x0A
#define SI114X_RAM_PS_ADC_GAIN				0x0B
#define SI114X_RAM_PS_ADC_MISC				0x0C
#define SI114X_RAM_ALS1_ADCMUX				0x0D
#define SI114X_RAM_ALS2_ADCMUX				0x0E
#define SI114X_RAM_ALS3_ADCMUX				0x0F
#define SI114X_RAM_ALS_VIS_ADC_COUNTER		0x10
#define SI114X_RAM_ALS_VIS_ADC_GAIN			0x11
#define SI114X_RAM_ALS_VIS_ADC_MISC			0x12
#define SI114X_RAM_ALS_HYST					0x16
#define SI114X_RAM_PS_HYST					0x17
#define SI114X_RAM_PS_HISTORY				0x18
#define SI114X_RAM_ALS_HISTORY				0x19
#define SI114X_RAM_ADC_OFFSET				0x1A
#define SI114X_RAM_SLEEP_CTRL				0x1B
#define SI114X_RAM_LED_REC					0x1C
#define SI114X_RAM_ALS_IR_ADC_COUNTER		0x1D
#define SI114X_RAM_ALS_IR_ADC_GAIN			0x1E
#define SI114X_RAM_ALS_IR_ADC_MISC			0x1F

// Si114x Command Register Value
#define SI114X_CMD_PARAM_QUERY				0x80
#define SI114X_CMD_PARAM_SET				0xA0
#define SI114X_CMD_PARAM_AND				0xC0
#define SI114X_CMD_PARAM_OR					0xE0
#define SI114X_CMD_NOP						0x00
#define SI114X_CMD_RESET					0x01
#define SI114X_CMD_BUSADDR					0x02
#define SI114X_CMD_PS_FORCE					0x05
#define SI114X_CMD_ALS_FORCE				0x06
#define SI114X_CMD_PSALS_FORCE				0x07
#define SI114X_CMD_PS_PAUSE					0x09
#define SI114X_CMD_ALS_PAUSE				0x0A
#define SI114X_CMD_PSALS_PAUSE				0x0B
#define SI114X_CMD_PS_AUTO					0x0D
#define SI114X_CMD_ALS_AUTO					0x0E
#define SI114X_CMD_PSALS_AUTO				0x0F

// Si114x Response Register Value
#define SI114X_RES_INVALID_SETTING			0x80
#define SI114X_RES_PS1_ADC_OVERFLOW			0x88
#define SI114X_RES_PS2_ADC_OVERFLOW			0x89
#define SI114X_RES_PS3_ADC_OVERFLOW			0x8A
#define SI114X_RES_ALS_VIS_ADC_OVERFLOW		0x8C
#define SI114X_RES_ALS_IR_ADC_OVERFLOW		0x8D
#define SI114X_RES_AUX_ADC_OVERFLOW			0x8E

// Si114x Interrupt Flag Bits
#define SI114X_IRQ_ALS_INT0					0x01
#define SI114X_IRQ_ALS_INT1					0x02
#define SI114X_IRQ_PS1_INT					0x04
#define SI114X_IRQ_PS2_INT					0x08
#define SI114X_IRQ_PS3_INT					0x10
#define SI114X_IRQ_CMD_INT					0x20
#define SI114X_IRQ_ALL_CHANNELS				(SI114X_IRQ_ALS_INT0 + SI114X_IRQ_PS1_INT + SI114X_IRQ_PS2_INT + SI114X_IRQ_PS3_INT)

// Si114x Measurement Channel List
#define SI114X_MCL_PS1_TASK					0x01
#define SI114X_MCL_PS2_TASK					0x02
#define SI114X_MCL_PS3_TASK					0x04
#define SI114X_MCL_ALS_VIS_TASK				0x10
#define SI114X_MCL_ALS_IR_TASK				0x20
#define SI114X_MCL_AUX_TASK					0x40

// Si114x Mask Bits
#define SI114X_INT_OE						0x01
#define SI114X_INT_MODE						0x02
#define SI114X_ALS_IE_X1					0x01
#define SI114X_ALS_IE_1X					0x02
#define SI114X_ALS_IE_11					0x03
#define SI114X_PS1_IE						0x04
#define SI114X_PS2_IE						0x08
#define SI114X_PS3_IE						0x10
#define SI114X_CMD_IE						0x20
#define SI114X_ALS_IM_000					0x00
#define SI114X_ALS_IM_001					0x01
#define SI114X_ALS_IM_010					0x02
#define SI114X_ALS_IM_011					0x03
#define SI114X_ALS_IM_100					0x04
#define SI114X_ALS_IM_101					0x05
#define SI114X_ALS_IM_110					0x06
#define SI114X_ALS_IM_111					0x07
#define SI114X_PS1_IM_CROSS					0x10
#define SI114X_PS1_IM_OVER					0x30
#define SI114X_PS2_IM_CROSS					0x40
#define SI114X_PS2_IM_OVER					0xC0
#define SI114X_PS3_IM_CROSS					0x01
#define SI114X_PS3_IM_OVER					0x03
#define SI114X_CMD_IM_WITH_ERR				0x04

// Values
#define SI114X_PART_ID_VALUE				0x41
#define SI114X_REV_ID_VALUE					0x00
#define SI114X_SEQ_ID_VALUE					0x09
// Measure Rate
#define SI114X_MEAS_RATE_10MS				0x84
#define SI114X_MEAS_RATE_20MS				0x94
#define SI114X_MEAS_RATE_100MS				0xB9
#define SI114X_MEAS_RATE_496MS				0xDF
#define SI114X_MEAS_RATE_1984MS				0xFF
// ALS Rate
#define SI114X_ALS_RATE_TIME				0x08
#define SI114X_ALS_RATE_10TIMES				0x32
#define SI114X_ALS_RATE_100TIMES			0x69
// PS Rate
#define SI114X_PS_RATE_TIME					0x08
#define SI114X_PS_RATE_10TIMES				0x32
#define SI114X_PS_RATE_100TIMES				0x69
// LED Drive Current  Values
#define LEDI_000_MA							0x00
#define LEDI_006_MA							0x01
#define LEDI_011_MA							0x02
#define LEDI_022_MA							0x03
#define LEDI_045_MA							0x04
#define LEDI_067_MA							0x05
#define LEDI_090_MA							0x06
#define LEDI_112_MA							0x07
#define LEDI_135_MA							0x08
#define LEDI_157_MA							0x09
#define LEDI_180_MA							0x0A
#define LEDI_202_MA							0x0B
#define LEDI_224_MA							0x0C
#define LEDI_269_MA							0x0D
#define LEDI_314_MA							0x0E
#define LEDI_359_MA							0x0F
#define MIN_LED_CURRENT						LEDI_006_MA
#define MAX_LED_CURRENT						LEDI_359_MA
#define DEFAULT_LED_CURRENT					LEDI_180_MA

// Mode
#define SI114X_THRESHOLD_ALS_LOW			SI114X_ALS_LOW_TH0
#define SI114X_THRESHOLD_ALS_HIGH			SI114X_ALS_HI_TH0
#define SI114X_THRESHOLD_PS1				SI114X_PS1_TH0
#define SI114X_THRESHOLD_PS2				SI114X_PS2_TH0
#define SI114X_THRESHOLD_PS3				SI114X_PS3_TH0

#define SI114X_DATA_ALS_VIS					SI114X_ALS_VIS_DATA0
#define SI114X_DATA_ALS_IR					SI114X_ALS_IR_DATA0
#define SI114X_DATA_PS1						SI114X_PS1_DATA0
#define SI114X_DATA_PS2						SI114X_PS2_DATA0
#define SI114X_DATA_PS3						SI114X_PS3_DATA0
#define SI114X_DATA_AUX						SI114X_AUX_DATA0

/*******************************************************************************
 * Exported macros
 ******************************************************************************/

/*******************************************************************************
 * Exported types
 ******************************************************************************/
typedef struct SI114X_DATA
{
	// Data
	int16_t data_VIS_ALS;
	int16_t data_IR_ALS;
	int16_t data_PS1;
	int16_t data_PS2;
	int16_t data_PS3;
	int16_t data_AUX;

	// Threshold
	int16_t threshold_PS1;
	int16_t threshold_PS2;
	int16_t threshold_PS3;
	int16_t threshold_ALS_low;
	int16_t threshold_ALS_high;

	// LED Power
	uint8_t i_LED1;
	uint8_t i_LED2;
	uint8_t i_LED3;

	// INT Config
	uint8_t int_Mode;
	uint8_t int_OE;

	// IRQ Enable
	uint8_t ie_ALS;
	uint8_t ie_PS1;
	uint8_t ie_PS2;
	uint8_t ie_PS3;
	uint8_t ie_CMD;

	// IRQ Mode
	uint8_t im_ALS;
	uint8_t im_PS1;
	uint8_t im_PS2;
	uint8_t im_PS3;
	uint8_t im_CMD;

	// IRQ Status
	uint8_t int_ALS;
	uint8_t int_PS1;
	uint8_t int_PS2;
	uint8_t int_PS3;
	uint8_t int_CMD;

	// Chip Status
	uint8_t state_Sleep;
	uint8_t state_Suspend;
	uint8_t state_Running;
} Si114x;

/*******************************************************************************
 * Exported constants
 ******************************************************************************/

/*******************************************************************************
 * Exported functions
 ******************************************************************************/
// Getter
uint8_t get_Register_SI114X(uint8_t addr);
void get_Int_Cfg_SI114X(Si114x *p_data);
void get_Irq_Enable_SI114X(Si114x *p_data);
void get_Irq_Mode_SI114X(Si114x *p_data);
void get_Irq_Status_SI114X(Si114x *p_data);
void get_LED_SI114X(Si114x *p_data);
void get_Chip_Status_SI114X(Si114x *p_data);
void get_Threshold_Value_SI114X(uint8_t mode, Si114x *p_data);
void get_Data_SI114X(uint8_t mode, Si114x *p_data);

// Setter
void set_Register_SI114X(uint8_t addr, uint8_t value);
void set_Int_Cfg_SI114X(uint8_t mode, uint8_t oe);
void set_Irq_Enable_SI114X(uint8_t als, uint8_t ps1, uint8_t ps2, uint8_t ps3, uint8_t cmd);
void set_Irq_Mode_SI114X(uint8_t als_im, uint8_t ps1_im, uint8_t ps2_im, uint8_t ps3_im, uint8_t cmd_im);
void set_Irq_Status_SI114X(uint8_t als_int, uint8_t ps1_int, uint8_t ps2_int, uint8_t ps3_int, uint8_t cmd_int);
void set_LED_SI114X(uint8_t led1, uint8_t led2, uint8_t led3);
void set_Threshold_Value_SI114X(uint8_t mode, int16_t threshold);

// Command Functions
void command_SI114X(uint8_t command);

#endif /* __LIB_SI114X_H */
