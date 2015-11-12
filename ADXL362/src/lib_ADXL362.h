/*
 ============================================================================
 Name        : lib_ADXL362.h
 Author      : wjdgn2574
 Version     : 0.7
 Copyright   :
 Description : ADXL362 Library Header File
 ============================================================================
*/

#ifndef __LIB_ADXL362_H
#define __LIB_ADXL362_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/*******************************************************************************
 * Exported defines
 ******************************************************************************/
// ADXL Mode Byte
#define ADXL362_WRITE_MODE				0x0A
#define ADXL362_READ_MODE				0x0B

// ADXL Register Address Map
#define ADXL362_DEVID_AD				0x00
#define ADXL362_DEVID_MST				0x01
#define ADXL362_PARTID					0x02
#define ADXL362_REVID					0x03
#define ADXL362_XDATA					0x08
#define ADXL362_YDATA					0x09
#define ADXL362_ZDATA					0x0A
#define ADXL362_STATUS					0x0B
#define ADXL362_FIFO_ENTRIES_L			0x0C
#define ADXL362_FIFO_ENTRIES_H			0x0D
#define ADXL362_XDATA_L					0x0E
#define ADXL362_XDATA_H					0x0F
#define ADXL362_YDATA_L					0x10
#define ADXL362_YDATA_H					0x11
#define ADXL362_ZDATA_L					0x12
#define ADXL362_ZDATA_H					0x13
#define ADXL362_TEMP_L					0x14
#define ADXL362_TEMP_H					0x15
#define ADXL362_RESERVED1				0x16
#define ADXL362_RESERVED2				0x17
#define ADXL362_SOFT_RESET				0x1F
#define ADXL362_THRESH_ACT_L			0x20
#define ADXL362_THRESH_ACT_H			0x21
#define ADXL362_TIME_ACT				0x22
#define ADXL362_THRESH_INACT_L			0x23
#define ADXL362_THRESH_INACT_H			0x24
#define ADXL362_TIME_INACT_L			0x25
#define ADXL362_TIME_INACT_H			0x26
#define ADXL362_ACT_INACT_CTL			0x27
#define ADXL362_FIFO_CONTROL			0x28
#define ADXL362_FIFO_SAMPLES			0x29
#define ADXL362_INTMAP1					0x2A
#define ADXL362_INTMAP2					0x2B
#define ADXL362_FILTER_CTL				0x2C
#define ADXL362_POWER_CTL				0x2D
#define ADXL362_SELF_TEST				0x2E

// Values
#define ADXL362_DEFAULT_VALUE			0x00
#define ADXL362_DEVICE_ID_VALUE			0xAD	// ADXL362_DEVID_AD
#define ADXL362_MEMS_ID_VALUE			0x1D	// ADXL362_DEVID_MST
#define ADXL362_PART_ID_VALUE			0xF2	// ADXL362_PARTID
#define ADXL362_RESET_VALUE				0x52	// ADXL362_REVID
#define ADXL362_STATUS_DATA_READY		0x01	// ADXL362_STATUS
#define ADXL362_STATUS_FIFO_READY		0x02	// ADXL362_STATUS
#define ADXL362_STATUS_FIFO_WATERMARK	0x04	// ADXL362_STATUS
#define ADXL362_STATUS_FIFO_OVERRUN		0x08	// ADXL362_STATUS
#define ADXL362_STATUS_ACT				0x10	// ADXL362_STATUS
#define ADXL362_STATUS_INACT			0x20	// ADXL362_STATUS
#define ADXL362_STATUS_AWAKE			0x40	// ADXL362_STATUS
#define ADXL362_STATUS_ERR_USER_REGS	0x80	// ADXL362_STATUS
#define ADXL362_SOFT_RESET_VALUE		0x52	// ADXL362_SOFT_RESET
#define ADXL362_ACT_EN					0x01	// ADXL362_ACT_INACT_CTL
#define ADXL362_ACT_REF					0x02	// ADXL362_ACT_INACT_CTL
#define ADXL362_INACT_EN				0x04	// ADXL362_ACT_INACT_CTL
#define ADXL362_INACT_REF				0x08	// ADXL362_ACT_INACT_CTL
#define ADXL362_DEFAULT_MODE			0x00	// ADXL362_ACT_INACT_CTL
#define ADXL362_LINK_MODE				0x10	// ADXL362_ACT_INACT_CTL
#define ADXL362_LOOP_MODE				0x30	// ADXL362_ACT_INACT_CTL
#define ADXL362_FIFO_DISABLE			0x00	// ADXL362_FIFO_CONTROL
#define ADXL362_FIFO_OLDSAVE_MODE		0x01	// ADXL362_FIFO_CONTROL
#define ADXL362_FIFO_STREAM_MODE		0x02	// ADXL362_FIFO_CONTROL
#define ADXL362_FIFO_TRIGGER_MODE		0x03	// ADXL362_FIFO_CONTROL
#define ADXL362_FIFO_TEMP_EN			0x04	// ADXL362_FIFO_CONTROL
#define ADXL362_FIFO_AH					0x08	// ADXL362_FIFO_CONTROL
#define ADXL362_INT_DATA_READY			0x01	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_FIFO_READY			0x02	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_FIFO_WATERMARK		0x04	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_FIFO_OVERRUN		0x08	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_ACT					0x10	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_INACT				0x20	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_AWAKE				0x40	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_INT_INT_LOW				0x80	// ADXL362_INTMAP1 or ADXL362_INTMAP2
#define ADXL362_FILTER_ODR_12_5HZ		0x00	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_ODR_25HZ			0x01	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_ODR_50HZ			0x02	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_ODR_100HZ		0x03	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_ODR_200HZ		0x04	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_ODR_400HZ		0x05	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_EXT_SAMPLE		0x08	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_HALF_BW			0x10	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_2G				0x00	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_4G				0x40	// ADXL362_FILTER_CTL
#define ADXL362_FILTER_8G				0x80	// ADXL362_FILTER_CTL
#define ADXL362_POWER_STANDBY			0x00	// ADXL362_POWER_CTL
#define ADXL362_POWER_MEASURE			0x02	// ADXL362_POWER_CTL
#define ADXL362_POWER_AUTOSLEEP			0x04	// ADXL362_POWER_CTL
#define ADXL362_POWER_WAKEUP			0x08	// ADXL362_POWER_CTL
#define ADXL362_POWER_LOW_NOISE			0x10	// ADXL362_POWER_CTL
#define ADXL362_POWER_ULTRA_LN			0x20	// ADXL362_POWER_CTL
#define ADXL362_POWER_EXT_CLK			0x40	// ADXL362_POWER_CTL
#define ADXL362_SELF_TEST_EN			0x01	// ADXL362_SELF_TEST

/*******************************************************************************
 * Exported macros
 ******************************************************************************/

/*******************************************************************************
 * Exported types
 ******************************************************************************/
typedef struct ADXL362_DATA
{
	uint8_t status_ERR_USER_REGS;	// Status Register Bit Value - ERR_USER_REGS
	uint8_t status_AWAKE;			// Status Register Bit Value - AWAKE
	uint8_t status_INACT;			// Status Register Bit Value - INACT
	uint8_t status_ACT;				// Status Register Bit Value - ACT
	uint8_t status_FIFO_OVERRUN;	// Status Register Bit Value - FIFO_OVERRUN
	uint8_t status_FIFO_WATERMARK;	// Status Register Bit Value - FIFO_WATERMARK
	uint8_t status_FIFO_READY;		// Status Register Bit Value - FIFO_READY
	uint8_t status_DATA_READY;		// Status Register Bit Value - DATA_READY

	uint8_t x_accel_8bit;			// x-axis 8 Bit Value
	uint8_t y_accel_8bit;			// y-axis 8 Bit Value
	uint8_t z_accel_8bit;			// z-axis 8 Bit Value

	int16_t x_accel;					// x-axis 16 Bit Value
	int16_t y_accel;					// y-axis 16 Bit Value
	int16_t z_accel;					// z-axis 16 Bit Value
	int16_t temp_accel;				// Temperature Value
} ADXL362;

/*******************************************************************************
 * Exported constants
 ******************************************************************************/

/*******************************************************************************
 * Exported functions
 ******************************************************************************/
// Wrapper SPI Functions
// To use Function, Implement to use target MCU SPI functions
void write_ADXL362(uint8_t address, uint8_t *tx, uint8_t length);
void read_ADXL362(uint8_t address, uint8_t *rx, uint8_t length);

// Getter Functions
uint8_t get_Device_ID_ADXL362(void);			// Get Device Company ID Value
uint8_t get_MEMS_ID_ADXL362(void);				// Get Device Company MST ID Value
uint8_t get_Part_ID_ADXL362(void);				// Get Device Part ID Value
uint8_t get_Rev_ID_ADXL362(void);				// Get Device Revision ID Value
bool get_raw_8bit_ADXL362(ADXL362 *p_data);		// Get 8Bit Raw Value - x, y, z
bool get_raw_16bit_ADXL362(ADXL362 *p_data);	// Get 16Bit Raw Value - x, y, z, Temperature
void get_status_ADXL362(ADXL362 *p_data);		// Get ADXL362 Status Values

// Setter Functions
// If you set default, Use 'ADXL362_DEFAULT_VALUE' defining value
// Ex) set_Self_Test_ADXL362(ADXL362_DEFAULT_VALUE);
void set_soft_reset_ADXL362(void);
void set_control_Act_Inact_ADXL362(uint8_t act_en, uint8_t act_ref, uint8_t inact_en, uint8_t inact_ref, uint8_t mode);
void set_control_FIFO_ADXL362(uint8_t mode, uint8_t temp_en, uint8_t ah);
void set_control_FILTER_ADXL362(uint8_t odr, uint8_t ext_sample, uint8_t half_bw, uint8_t range);
void set_control_POWER_ADXL362(uint8_t measure, uint8_t auto_sleep, uint8_t wakeup, uint8_t low_noise, uint8_t ext_clk);
void set_mapping_INT1_ADXL362(uint8_t mode_pin);
void set_mapping_INT2_ADXL362(uint8_t mode_pin);
void set_threshold_Act_ADXL362(int16_t threshold);
void set_threshold_Inact_ADXL362(int16_t threshold);
void set_time_Act_ADXL362(uint8_t time);
void set_time_Inact_ADXL362(int16_t time);
void set_Self_Test_ADXL362(uint8_t enable);

#endif /* __LIB_ADXL362_H */
