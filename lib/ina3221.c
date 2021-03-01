/*
 * ina3221.c
 *
 *  Created on: Feb 15, 2020
 *      Author: vasily
 */

#include "stddef.h"
#include "drivers.h"
#include "ina3221.h"
#include "console.h"
#include "i2c.h"

void ina3221_print_voltage_current(void)
{
	uint8_t	ina3221_addr = 0x80;

	uint16_t v0 = 0, v1 = 0,v2 = 0;
	uint16_t i0 = 0, i1 = 0,i2 = 0, I = 0;

	int32_t ret_val = 0;
	ret_val = i2c_read(ina3221_addr, 0x1, (uint8_t *)&i0, sizeof(i0));
	if (ret_val < 0) {
		print("i2c_read_1 finished with error %d\r\n", ret_val);
		return;
	}
	ret_val = i2c_read(ina3221_addr, 0x2, (uint8_t *)&v0, sizeof(v0));
	if (ret_val < 0) {
		print("i2c_read_2 finished with error %d\r\n", ret_val);
		return;
	}

	ret_val = i2c_read(ina3221_addr, 0x3, (uint8_t *)&i1, sizeof(i1));
	if (ret_val < 0) {
		print("i2c_read_3 finished with error %d\r\n", ret_val);
		return;
	}
	ret_val = i2c_read(ina3221_addr, 0x4, (uint8_t *)&v1, sizeof(v1));
	if (ret_val < 0) {
		print("i2c_read_4 finished with error %d\r\n", ret_val);
		return;
	}

	ret_val = i2c_read(ina3221_addr, 0x5, (uint8_t *)&i2, sizeof(i2));
	if (ret_val < 0) {
		print("i2c_read_5 finished with error %d\r\n", ret_val);
		return;
	}
	ret_val = i2c_read(ina3221_addr, 0x6, (uint8_t *)&v2, sizeof(v2));
	if (ret_val < 0) {
		print("i2c_read_6 finished with error %d\r\n", ret_val);
		return;
	}

	/*i2c_read(ina3221_addr, 0xD, (uint8_t *)&I, sizeof(I));*/

	print("Channel 0: voltage %dmV, current %dmA\r\n", swap_bytes_in_word(v0), (swap_bytes_in_word(i0) * 4) / 10);
	print("Channel 1: voltage %dmV, current %dmA\r\n", swap_bytes_in_word(v1), (swap_bytes_in_word(i1) * 4) / 10);
	print("Channel 2: voltage %dmV, current %dmA\r\n", swap_bytes_in_word(v2), (swap_bytes_in_word(i2) * 4) / 10);
	/*print("Total current %dmA\r\n", (swap_bytes_in_word(I) * 4) / 10);*/
}
