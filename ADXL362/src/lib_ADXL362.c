/*
 ============================================================================
 Name        : lib_ADXL362.c
 Author      : Park Jung Hoo
 Version     :
 Copyright   : Your copyright notice
 Description : ADXL362 Library Source File
 ============================================================================
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lib_ADXL362.h"

// Input target MCU SPI Function's Header File
// Here

/*******************************************************************************
 * Private define
 ******************************************************************************/

/*******************************************************************************
 * Private macro
 ******************************************************************************/

/*******************************************************************************
 * Private typedef
 ******************************************************************************/

/*******************************************************************************
 * Private variables
 ******************************************************************************/

/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Exported Functions
 ******************************************************************************/
// Wrapper SPI Functions
void write_ADXL362(uint8_t address, uint8_t *tx, uint8_t length)
{
	uint8_t addr_mode = ADXL362_WRITE_MODE;
	uint8_t addr_reg = address;

	// Here, Implement Wrapper SPI Write Functions
	// Step 1. Select Mode
	// To transmit addr_mode variable
	// here

	// Step 2. Send address
	// To transmit addr_reg variable
	// here

	// Step 3. Send Data
	// To transmit (*tx) variable
	// here
}

void read_ADXL362(uint8_t address, uint8_t *rx, uint8_t length)
{
	uint8_t addr_mode = ADXL362_READ_MODE;
	uint8_t addr_reg = address;
	uint8_t dummy = 0x00;

	// Here, Implement Wrapper SPI Read Functions
	// Step 1. Select Mode
	// To transmit addr_mode variable
	// here

	// Step 2. Send address
	// To transmit addr_reg variable
	// here

	// Step 3. Receive Data
	// To transmit (*rx) variable
	// here
}

// Getter Functions
uint8_t get_Device_ID_ADXL362(void)
{
	uint8_t address = ADXL362_DEVID_AD;
	uint8_t data = 0x00;

	read_ADXL362(address, &data, 1);

	return data;
}

uint8_t get_MEMS_ID_ADXL362(void)
{
	uint8_t address = ADXL362_DEVID_MST;
	uint8_t data = 0x00;

	read_ADXL362(address, &data, 1);

	return data;
}

uint8_t get_Part_ID_ADXL362(void)
{
	uint8_t address = ADXL362_PARTID;
	uint8_t data = 0x00;

	read_ADXL362(address, &data, 1);

	return data;
}

uint8_t get_Rev_ID_ADXL362(void)
{
	uint8_t address = ADXL362_REVID;
	uint8_t data = 0x00;

	read_ADXL362(address, &data, 1);

	return data;
}

void get_status_ADXL362(ADXL362 *p_data)
{
	uint8_t address = ADXL362_STATUS;
	uint8_t data = 0x00;

	read_ADXL362(address, &data, 1);

	if((data & ADXL362_STATUS_DATA_READY) == ADXL362_STATUS_DATA_READY)
	{
		p_data->status_DATA_READY = 1;
	}
	else
	{
		p_data->status_DATA_READY = 0;
	}

	if((data & ADXL362_STATUS_FIFO_READY) == ADXL362_STATUS_FIFO_READY)
	{
		p_data->status_FIFO_READY = 1;
	}
	else
	{
		p_data->status_FIFO_READY = 0;
	}

	if((data & ADXL362_STATUS_FIFO_WATERMARK) == ADXL362_STATUS_FIFO_WATERMARK)
	{
		p_data->status_FIFO_WATERMARK = 1;
	}
	else
	{
		p_data->status_FIFO_WATERMARK = 0;
	}

	if((data & ADXL362_STATUS_FIFO_OVERRUN) == ADXL362_STATUS_FIFO_OVERRUN)
	{
		p_data->status_FIFO_OVERRUN = 1;
	}
	else
	{
		p_data->status_FIFO_OVERRUN = 0;
	}

	if((data & ADXL362_STATUS_ACT) == ADXL362_STATUS_ACT)
	{
		p_data->status_ACT = 1;
	}
	else
	{
		p_data->status_ACT = 0;
	}

	if((data & ADXL362_STATUS_INACT) == ADXL362_STATUS_INACT)
	{
		p_data->status_INACT = 1;
	}
	else
	{
		p_data->status_INACT = 0;
	}

	if((data & ADXL362_STATUS_AWAKE) == ADXL362_STATUS_AWAKE)
	{
		p_data->status_AWAKE = 1;
	}
	else
	{
		p_data->status_AWAKE = 0;
	}

	if((data & ADXL362_STATUS_ERR_USER_REGS) == ADXL362_STATUS_ERR_USER_REGS)
	{
		p_data->status_ERR_USER_REGS = 1;
	}
	else
	{
		p_data->status_ERR_USER_REGS = 0;
	}
}

bool get_raw_8bit_ADXL362(ADXL362 *p_data)
{
	bool check = false;
	uint8_t address = 0x00;
	uint8_t data = 0x00;

	get_status_ADXL362(p_data);

	if(p_data->status_DATA_READY == 1)
	{
		address = ADXL362_XDATA;
		read_ADXL362(address, &data, 1);
		p_data->x_accel_8bit = data;

		address = ADXL362_YDATA;
		read_ADXL362(address, &data, 1);
		p_data->y_accel_8bit = data;

		address = ADXL362_ZDATA;
		read_ADXL362(address, &data, 1);
		p_data->z_accel_8bit = data;

		check = true;
	}

	return check;
}

bool get_raw_16bit_ADXL362(ADXL362 *p_data)
{
	bool check = false;
	uint8_t mask = 0x0F;
	uint8_t address = 0x00;
	uint8_t data[2] = {0x00, 0x00};

	get_status_ADXL362(p_data);

	if(p_data->status_DATA_READY == 1)
	{
		address = ADXL362_XDATA_L;
		read_ADXL362(address, data, 2);
		p_data->x_accel = ((int16_t)(mask & data[1]) << 8) | data[0];

		address = ADXL362_YDATA_L;
		read_ADXL362(address, data, 2);
		p_data->y_accel = ((int16_t)(mask & data[1]) << 8) | data[0];

		address = ADXL362_ZDATA_L;
		read_ADXL362(address, data, 2);
		p_data->z_accel = ((int16_t)(mask & data[1]) << 8) | data[0];

		address = ADXL362_TEMP_L;
		read_ADXL362(address, data, 2);
		p_data->temp_accel = ((int16_t)(mask & data[1]) << 8) | data[0];

		check = true;
	}

	return check;
}

// Setter Functions
void set_soft_reset_ADXL362(void)
{
	uint8_t address = ADXL362_SOFT_RESET;
	uint8_t data = ADXL362_RESET_VALUE;

	write_ADXL362(address, &data, 1);
}

void set_control_Act_Inact_ADXL362(uint8_t act_en, uint8_t act_ref, uint8_t inact_en, uint8_t inact_ref, uint8_t mode)
{
	uint8_t address = ADXL362_ACT_INACT_CTL;
	uint8_t data = 0x00;

	data = data | act_en;
	data = data | act_ref;
	data = data | inact_en;
	data = data | inact_ref;
	data = data | mode;

	write_ADXL362(address, &data, 1);
}

void set_control_FIFO_ADXL362(uint8_t mode, uint8_t temp_en, uint8_t ah)
{
	uint8_t address = ADXL362_FIFO_CONTROL;
	uint8_t data = 0x00;

	data = data | mode;
	data = data | temp_en;
	data = data | ah;

	write_ADXL362(address, &data, 1);
}

void set_control_FILTER_ADXL362(uint8_t odr, uint8_t ext_sample, uint8_t half_bw, uint8_t range)
{
	uint8_t address = ADXL362_FILTER_CTL;
	uint8_t data = 0x00;

	data = data | odr;
	data = data | ext_sample;
	data = data | half_bw;
	data = data | range;

	write_ADXL362(address, &data, 1);
}

void set_control_POWER_ADXL362(uint8_t measure, uint8_t auto_sleep, uint8_t wakeup, uint8_t low_noise, uint8_t ext_clk)
{
	uint8_t address = ADXL362_POWER_CTL;
	uint8_t data = 0x00;

	data = data | measure;
	data = data | auto_sleep;
	data = data | wakeup;
	data = data | low_noise;
	data = data | ext_clk;

	write_ADXL362(address, &data, 1);
}

void set_mapping_INT1_ADXL362(uint8_t mode_pin)
{
	uint8_t address = ADXL362_INTMAP1;
	uint8_t data = mode_pin;

	write_ADXL362(address, &data, 1);
}

void set_mapping_INT2_ADXL362(uint8_t mode_pin)
{
	uint8_t address = ADXL362_INTMAP2;
	uint8_t data = mode_pin;

	write_ADXL362(address, &data, 1);
}

void set_threshold_Act_ADXL362(short threshold)
{
	uint8_t mask_H = 0x07;
	uint8_t mask_L = 0xFF;
	uint8_t address = ADXL362_THRESH_ACT_L;
	uint8_t data[2] = {0x00, 0x00};

	data[0] = (uint8_t)((short)mask_L & threshold);
	data[1] = (uint8_t)((((short)mask_H << 8) & threshold) >> 8);

	write_ADXL362(address, data, 2);
}

void set_threshold_Inact_ADXL362(short threshold)
{
	uint8_t mask_H = 0x07;
	uint8_t mask_L = 0xFF;
	uint8_t address = ADXL362_THRESH_INACT_L;
	uint8_t data[2] = {0x00, 0x00};

	data[0] = (uint8_t)((short)mask_L & threshold);
	data[1] = (uint8_t)((((short)mask_H << 8) & threshold) >> 8);

	write_ADXL362(address, data, 2);
}

void set_time_Act_ADXL362(uint8_t time)
{
	uint8_t address = ADXL362_TIME_ACT;
	uint8_t data = time;

	write_ADXL362(address, &data, 1);
}

void set_time_Inact_ADXL362(short time)
{
	uint8_t mask_H = 0xFF;
	uint8_t mask_L = 0xFF;
	uint8_t address = ADXL362_TIME_INACT_L;
	uint8_t data[2] = {0x00, 0x00};

	data[0] = (uint8_t)((short)mask_L & time);
	data[1] = (uint8_t)((((short)mask_H << 8) & time) >> 8);

	write_ADXL362(address, data, 2);
}

void set_Self_Test_ADXL362(uint8_t enable)
{
	uint8_t address = ADXL362_SELF_TEST;
	uint8_t data = enable;

	write_ADXL362(address, &data, 1);
}
