/*
 * ds3231m.c
 *
 *  Created on: Feb 15, 2020
 *      Author: vasily
 */

#include "stddef.h"
#include "drivers.h"
#include "ds3231m.h"
#include "console.h"

void ds3231m_read_regs(void)
{
	print("%s()\r\n", __func__);

	/* DS3231M */
	//uint8_t chip_addr = 0xD0;
	//uint8_t reg_addr = 0x00;

}
