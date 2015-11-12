/*
 ============================================================================
 Name			: main.c
 Author			: wjdgn2574
 Version		: 0.7
 Copyright		:
 Description	: Do Test lib_ADXL362 library
 ============================================================================
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
// C Standard Library
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// Library
#include "lib_ADXL362.h"

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
void init_ADXL362(ADXL362 *p_adxl362);

/*******************************************************************************
 * Main Loop
 ******************************************************************************/
int main(void)
{
	ADXL362 adxl362;

	init_ADXL362(&adxl362);

	printf("Start ADXL362 TEST Application \r\n");

    while (true)
    {
		get_status_ADXL362(&adxl362);
		printf("DATA_READY(%d), FIFO_READY(%d), FIFO_WATERMARK(%d), FIFO_OVERRUN(%d), ACT(%d), INACT(%d), AWAKE(%d), ERR_USER_REGS(%d) \r\n", adxl362.status_DATA_READY, adxl362.status_FIFO_READY, adxl362.status_FIFO_WATERMARK, adxl362.status_FIFO_OVERRUN, adxl362.status_ACT, adxl362.status_INACT, adxl362.status_AWAKE, adxl362.status_ERR_USER_REGS);

		if(get_raw_8bit_ADXL362(&adxl362) == true)
		{
			printf("x = %d, y = %d, z = %d \r\n", adxl362.x_accel_8bit, adxl362.y_accel_8bit, adxl362.z_accel_8bit);
		}

		if(get_raw_16bit_ADXL362(&adxl362) == true)
		{
			printf("X = %d, Y = %d, Z = %d \r\n", adxl362.x_accel, adxl362.y_accel, adxl362.z_accel);
		}
    }
}

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
void init_ADXL362(ADXL362 *p_adxl362)
{
	if(get_Part_ID_ADXL362() == ADXL362_PART_ID_VALUE)
	{
		// Soft Reset
		set_soft_reset_ADXL362();
		sleep(100); // To use delay or wait function about micro second(ms)

		// Activity Threshold and Time Values
		set_threshold_Act_ADXL362(0);
		set_time_Act_ADXL362(0);
		sleep(10);

		// Inactivity Threshold and Time Values
		set_threshold_Inact_ADXL362(0);
		set_time_Inact_ADXL362(0);
		sleep(10);

		// Interrupt Pins Mapping
		set_mapping_INT1_ADXL362(ADXL362_DEFAULT_VALUE);
		set_mapping_INT2_ADXL362(ADXL362_DEFAULT_VALUE);
		sleep(10);

		// ACT and INACT Setting
		// ACT_EN = DISABLE
		// ACT_REF = DISABLE
		// INACT_EN = DISABLE
		// INACT_REF = DISABLE
		// MODE = ADXL362_DEFAULT_MODE
		set_control_Act_Inact_ADXL362(ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_MODE);
		sleep(10); // To use delay or wait function about micro second(ms)

		// FIFO Setting
		// MODE = ADXL362_FIFO_DISABLE
		// FIFO_TEMP = DISABLE
		// AH(Above Half) = DISABLE
		set_control_FIFO_ADXL362(ADXL362_FIFO_DISABLE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE);
		sleep(10);

		// Filter Setting
		// ODR = 400Hz
		// EXT_SAMPLE = DISABLE
		// HALF_BW = ENABLE
		// RANGE = 8g
		set_control_FILTER_ADXL362(ADXL362_FILTER_ODR_100HZ, ADXL362_DEFAULT_VALUE, ADXL362_FILTER_HALF_BW, ADXL362_FILTER_8G);
		sleep(10);

		// Power Setting
		// MODE = Measure Mode
		// Auto Sleep = DISABLE
		// Wake Up = DISABLE
		// Filter Mode = Normal Mode
		// EXT_CLK = DISABLE
		set_control_POWER_ADXL362(ADXL362_POWER_MEASURE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE, ADXL362_DEFAULT_VALUE);
		sleep(10);
	}
}
