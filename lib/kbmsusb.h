/*
 * kbmsusb.h
 *
 *  Created on: Oct 29, 2020
 *      Author: user
 */

#ifndef KBMSUSB_H_
#define KBMSUSB_H_

#define KEYBOARD_CHANNEL	0x1
#define MOUSE_CHANNEL		0x2

struct kbms_data {
	uint8_t kb_data[8];
	uint8_t ms_data[4];
	uint8_t	hid_num;
};

void max3421e_rev_print(uint32_t chip_num);
void max3421e_chip_deactivate(uint32_t chip_num);
void spi_usb_transmission_start(void);

#endif /* KBMSUSB_H_ */
