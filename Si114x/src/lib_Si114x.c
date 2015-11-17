/*
 ============================================================================
 Name        : lib_Si114x.c
 Author      : wjdgn2574
 Version     : 0.7
 Copyright   :
 Description : Si114x Library Source File
 ============================================================================
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lib_Si114x.h"

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
uint8_t get_Register_SI114X(uint8_t addr)
{
	uint8_t data = 0x00;

	read_SI114X(addr, &data, 1);

	return data;
}

void get_Int_Cfg_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_INT_CFG;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->int_OE = data & 0x03;			// INT_OE mask = 0x03
	p_data->int_Mode = data & 0x04;	// INT_MODE mask = 0x04
}

void get_Irq_Enable_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_IRQ_ENABLE;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->ie_ALS = data & 0x03;			// ALS_IE mask = 0x03
	p_data->ie_PS1 = data & 0x04;			// PS1_IE mask = 0x04
	p_data->ie_PS2 = data & 0x08;			// PS2_IE mask = 0x08
	p_data->ie_PS3 = data & 0x10;			// PS3_IE mask = 0x10
	p_data->ie_CMD = data & 0x20;		// CMD_IE mask = 0x20
}

void get_Irq_Mode_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_IRQ_MODE1;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->im_ALS = data & 0x07;			// ALS_IM mask = 0x07
	p_data->im_PS1 = data & 0x30;			// PS1_IM mask = 0x30
	p_data->im_PS2 = data & 0xC0;			// PS2_IM mask = 0xC0

	address = SI114X_IRQ_MODE2;
	data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->im_PS3 = data & 0x03;			// PS3_IM mask = 0x03
	p_data->im_CMD = data & 0x0C;		// CMD_IM mask = 0x0C
}

void get_Irq_Status_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_IRQ_STATUS;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->int_ALS = data & 0x03;			// ALS_INT mask = 0x03
	p_data->int_PS1 = data & 0x04;			// PS1_INT mask = 0x04
	p_data->int_PS2 = data & 0x08;			// PS2_INT mask = 0x08
	p_data->int_PS3 = data & 0x10;			// PS3_INT mask = 0x10
	p_data->int_CMD = data & 0x20;			// CMD_INT mask = 0x20
}

void get_LED_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_PS_LED21;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->i_LED1 = data & 0x0F;			// LED1_I mask = 0x0F
	p_data->i_LED2 = data & 0xF0;			// LED2_I mask = 0xF0

	address = SI114X_PS_LED3;
	data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->i_LED3 = data & 0x0F;			// LED3_I mask = 0x0F
}

void get_Chip_Status_SI114X(Si114x *p_data)
{
	uint8_t address = SI114X_CHIP_STAT;
	uint8_t data = 0x00;

	read_SI114X(address, &data, 1);

	p_data->state_Sleep = data & 0x01;				// SLEEP mask = 0x01
	p_data->state_Suspend = data & 0x02;	// SUSPEND mask = 0x02
	p_data->state_Running = data & 0x04;		// RUNNING mask = 0x04
}

void get_Threshold_Value_SI114X(uint8_t mode, Si114x *p_data)
{
	uint8_t address = mode;
	uint8_t data[2] = {0x00, 0x00};
	int16_t temp = 0;

	read_SI114X(address, data, 2);
	temp = (int16_t)((int16_t)data[1] << 8) | data[0];

	switch(mode)
	{
		case SI114X_THRESHOLD_ALS_LOW:
			p_data->threshold_ALS_low = temp;
			break;
		case SI114X_THRESHOLD_ALS_HIGH:
			p_data->threshold_ALS_high = temp;
			break;
		case SI114X_THRESHOLD_PS1:
			p_data->threshold_PS1 = temp;
			break;
		case SI114X_THRESHOLD_PS2:
			p_data->threshold_PS2 = temp;
			break;
		case SI114X_THRESHOLD_PS3:
			p_data->threshold_PS3 = temp;
			break;
	}
}

void get_Data_SI114X(uint8_t mode, Si114x *p_data)
{
	uint8_t address = mode;
	uint8_t data[2] = {0x00, 0x00};
	int16_t temp = 0;

	read_SI114X(address, data, 2);
	temp = (256 * (int16_t)data[1]) + (int16_t)data[0];

	switch(mode)
	{
		case SI114X_DATA_ALS_VIS:
			p_data->data_VIS_ALS = temp;
			break;
		case SI114X_DATA_ALS_IR:
			p_data->data_IR_ALS = temp;
			break;
		case SI114X_DATA_PS1:
			p_data->data_PS1 = temp;
			break;
		case SI114X_DATA_PS2:
			p_data->data_PS2 = temp;
			break;
		case SI114X_DATA_PS3:
			p_data->data_PS3 = temp;
			break;
		case SI114X_DATA_AUX:
			p_data->data_AUX = temp;
			break;
	}
}

void set_Register_SI114X(uint8_t addr, uint8_t value)
{
	write_SI114X(addr, value);
}

void set_Int_Cfg_SI114X(uint8_t mode, uint8_t oe)
{
	uint8_t address = SI114X_INT_CFG;
	uint8_t data = 0x00;

	data = data | mode;
	data = data | oe;

	write_SI114X(address, data);
}

void set_Irq_Enable_SI114X(uint8_t als, uint8_t ps1, uint8_t ps2, uint8_t ps3, uint8_t cmd)
{
	uint8_t address = SI114X_IRQ_ENABLE;
	uint8_t data = 0x00;

	data = data | als;
	data = data | ps1;
	data = data | ps2;
	data = data | ps3;
	data = data | cmd;

	write_SI114X(address, data);
}

void set_Irq_Mode_SI114X(uint8_t als_im, uint8_t ps1_im, uint8_t ps2_im, uint8_t ps3_im, uint8_t cmd_im)
{
	uint8_t address = SI114X_IRQ_MODE1;
	uint8_t data = 0x00;

	data = data | als_im;
	data = data | ps1_im;
	data = data | ps2_im;

	write_SI114X(address, data);

	address = SI114X_IRQ_MODE2;
	data = 0x00;

	data = data | ps3_im;
	data = data | cmd_im;

	write_SI114X(address, data);
}

void set_Irq_Status_SI114X(uint8_t als_int, uint8_t ps1_int, uint8_t ps2_int, uint8_t ps3_int, uint8_t cmd_int)
{
	uint8_t address = SI114X_IRQ_STATUS;
	uint8_t data = 0x00;

	data = data | als_int;
	data = data | ps1_int;
	data = data | ps2_int;
	data = data | ps3_int;
	data = data | cmd_int;

	write_SI114X(address, data);
}

void set_LED_SI114X(uint8_t led1, uint8_t led2, uint8_t led3)
{
	uint8_t address = SI114X_PS_LED21;
	uint8_t data = 0x00;

	data = data | led1;
	data = data | led2;

	write_SI114X(address, data);

	address = SI114X_PS_LED3;
	data = led3;

	write_SI114X(address, data);
}

void set_Threshold_Value_SI114X(uint8_t mode, int16_t threshold)
{
	uint8_t address = mode;
	uint8_t data = 0x00;

	data = (uint8_t)threshold | 0xFF;
	write_SI114X(address, data);

	switch(mode)
	{
		case SI114X_THRESHOLD_ALS_LOW:
			address = SI114X_ALS_LOW_TH1;
			break;
		case SI114X_THRESHOLD_ALS_HIGH:
			address = SI114X_ALS_HI_TH1;
			break;
		case SI114X_THRESHOLD_PS1:
			address = SI114X_PS1_TH1;
			break;
		case SI114X_THRESHOLD_PS2:
			address = SI114X_PS2_TH1;
			break;
		case SI114X_THRESHOLD_PS3:
			address = SI114X_PS3_TH1;
			break;
	}

	data = (uint8_t)(threshold >> 8) | 0xFF;
	write_SI114X(address, data);
}

void command_SI114X(uint8_t command)
{
	uint8_t data = get_Register_SI114X(SI114X_RESPONSE);

	while(data != 0x00)
	{
		set_Register_SI114X(SI114X_COMMAND, SI114X_CMD_NOP);
		data = get_Register_SI114X(SI114X_RESPONSE);
	}

	do
	{
		set_Register_SI114X(SI114X_COMMAND, command);

		if(command == SI114X_CMD_RESET)
		{
			break;
		}

		data = get_Register_SI114X(SI114X_RESPONSE);

	} while(data == 0x00);
}
