/*
 * kbmsusb.c
 *
 *  Created on: Oct 29, 2020
 *      Author: user
 */
#include <string.h>
#include <stdint.h>

#include "drivers.h"
#include "debug.h"
#include "console.h"
#include "max3421e.h"
#include "kbmsusb.h"

#include "time.h"
#include "spi_flash.h"

#define MS_USB_ADDR	0x33
#define KB_USB_ADDR 0x34

#define USB_NAK		0x04
#define USB_TOGERR	0x06

#ifndef USE_MDR1986VE9x
void max3421e_rev_print(uint32_t chip_num)
{
	max3421e_chip_activate(chip_num);
	/* TODO: Implement device presence checking based on revision reading */
	printk(DEBUG, "REVISION 0x%02X\r\n", max3421e_rev_read());
	max3421e_chip_deactivate(chip_num);
}
#endif

void kb_ms_power_on(void)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(KEYBOARD_CHANNEL);
	uint8_t iopins1 = max3421e_iopins1_read();
	max3421e_chip_deactivate(KEYBOARD_CHANNEL);

	max3421e_chip_activate(KEYBOARD_CHANNEL);
	max3421e_iopins1_write(iopins1 | IOPINS1_GPOUT1);
	max3421e_chip_deactivate(KEYBOARD_CHANNEL);
}

#ifndef USE_MDR1986VE9x
void usb_std_req_print(const struct std_request *std_req)
{
	printk(DEBUG, "bm_request_type: 0x%02X\r\n", std_req->bm_request_type);
	printk(DEBUG, "b_request: 0x%02X\r\n", std_req->b_request);
	printk(DEBUG, "w_value: 0x%04X\r\n", std_req->w_value);
	printk(DEBUG, "w_index: 0x%04X\r\n", std_req->w_index);
	printk(DEBUG, "w_length: 0x%04X\r\n", std_req->w_length);
}

void usb_dev_descr_print(const struct device_descriptor *dev_descr)
{
	printk(DEBUG, "b_length: 0x%02X\r\n", dev_descr->b_length);
	printk(DEBUG, "b_descriptor_type: 0x%02X\r\n", dev_descr->b_descriptor_type);
	printk(DEBUG, "bcd_usb: 0x%04X\r\n", dev_descr->bcd_usb);
	printk(DEBUG, "b_device_class: 0x%02X\r\n", dev_descr->b_device_class);
	printk(DEBUG, "b_device_sub_class: 0x%02X\r\n", dev_descr->b_device_sub_class);
	printk(DEBUG, "b_device_protocol: 0x%02X\r\n", dev_descr->b_device_protocol);
	printk(DEBUG, "b_max_packet_size: 0x%02X\r\n", dev_descr->b_max_packet_size);
	printk(DEBUG, "id_vendor: 0x%04X\r\n", dev_descr->id_vendor);
	printk(DEBUG, "id_product: 0x%04X\r\n", dev_descr->id_product);
	printk(DEBUG, "bcd_device: 0x%04X\r\n", dev_descr->bcd_device);
	printk(DEBUG, "i_manufacturer: 0x%02X\r\n", dev_descr->i_manufacturer);
	printk(DEBUG, "i_product: 0x%02X\r\n", dev_descr->i_product);
	printk(DEBUG, "i_serial_number: 0x%02X\r\n", dev_descr->i_serial_number);
	printk(DEBUG, "b_num_configurations: 0x%02X\r\n", dev_descr->b_num_configurations);
}

void usb_conf_descr_print(const struct configuration_descriptor *conf_descr)
{
	printk(DEBUG, "b_length: 0x%02X\r\n", conf_descr->b_length);
	printk(DEBUG, "b_descriptor_type: 0x%02X\r\n", conf_descr->b_descriptor_type);
	printk(DEBUG, "w_total_length: 0x%04X\r\n", conf_descr->w_total_length);
	printk(DEBUG, "b_num_interfaces: 0x%02X\r\n", conf_descr->b_num_interfaces);
	printk(DEBUG, "b_configuration_value: 0x%02X\r\n", conf_descr->b_configuration_value);
	printk(DEBUG, "i_configuration: 0x%02X\r\n", conf_descr->i_configuration);
	printk(DEBUG, "bm_attributes: 0x%02X\r\n", conf_descr->bm_attributes);
	printk(DEBUG, "b_max_power: 0x%02X\r\n", conf_descr->b_max_power);
}

void usb_iface_descr_print(const struct interface_descriptor *iface_descr)
{
	printk(DEBUG, "b_length: 0x%02X\r\n", iface_descr->b_length);
	printk(DEBUG, "b_descriptor_type: 0x%02X\r\n", iface_descr->b_descriptor_type);
	printk(DEBUG, "b_interface_number: 0x%02X\r\n", iface_descr->b_interface_number);
	printk(DEBUG, "b_alternate_setting: 0x%02X\r\n", iface_descr->b_alternate_setting);
	printk(DEBUG, "b_num_endpoints: 0x%02X\r\n", iface_descr->b_num_endpoints);
	printk(DEBUG, "b_interface_class: 0x%02X\r\n", iface_descr->b_interface_class);
	printk(DEBUG, "b_interface_subclass: 0x%02X\r\n", iface_descr->b_interface_subclass);
	printk(DEBUG, "b_interface_protocol: 0x%02X\r\n", iface_descr->b_interface_protocol);
	printk(DEBUG, "i_interface: 0x%02X\r\n", iface_descr->i_interface);
}

void usb_endp_descr_print(const struct endpoint_descriptor *endp_descr)
{
	printk(DEBUG, "b_length: 0x%02X\r\n", endp_descr->b_length);
	printk(DEBUG, "b_descriptor_type: 0x%02X\r\n", endp_descr->b_descriptor_type);
	printk(DEBUG, "b_endpoint_address: 0x%02X\r\n", endp_descr->b_endpoint_address);
	printk(DEBUG, "bm_attributes: 0x%02X\r\n", endp_descr->bm_attributes);
	printk(DEBUG, "w_max_packet_size: 0x%02X\r\n", endp_descr->w_max_packet_size);
	printk(DEBUG, "b_interval: 0x%02X\r\n", endp_descr->b_interval);
}
#endif

int32_t usb_device_get_dev_descr(uint32_t usb_channel, uint8_t dev_addr, struct device_descriptor *dev_descr)
{
	struct std_request get_dev_descr = {0x80, 0x06, 0x0100, 0x0000, sizeof(struct device_descriptor)};

	int16_t hrslt = max3421e_usb_setup_send(usb_channel, dev_addr, &get_dev_descr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -1;
	}

	/* It needs time to process request */
	mdelay(200);

	max3421e_usb_recv_tog_set(usb_channel, 1);

	hrslt = max3421e_usb_bulk_receive(usb_channel, dev_addr, 0, dev_descr, sizeof(struct device_descriptor));
	mdelay(50);
	max3421e_usb_status_out_send(usb_channel, dev_addr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): BULK-IN transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -2;
	}
	return 0;
}

int32_t usb_device_get_conf_descr(uint32_t usb_channel, uint8_t dev_addr, struct configuration_descriptor *conf_descr)
{
	struct std_request get_conf_descr = {0x80, 0x06, 0x0200, 0x0000, sizeof(struct configuration_descriptor)};

	int16_t hrslt = max3421e_usb_setup_send(usb_channel, dev_addr, &get_conf_descr);

	if (hrslt < 0) {
		printk(DEBUG, "%s() SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -1;
	}

	/* It needs time to process request */
	mdelay(200);

	max3421e_usb_recv_tog_set(usb_channel, 1);

	hrslt = max3421e_usb_bulk_receive(usb_channel, dev_addr, 0, conf_descr, sizeof(struct configuration_descriptor));
	mdelay(50);
	max3421e_usb_status_out_send(usb_channel, dev_addr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): BULK-IN transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -2;
	}

	return 0;
}

#ifndef USE_MDR1986VE9x
void usb_device_full_conf_print(uint8_t *full_conf, size_t full_conf_size)
{
	size_t remain_bytes = full_conf_size;
	size_t base = 0;
	struct configuration_descriptor *p_conf_descr;
	struct interface_descriptor *p_iface_descr;
	struct endpoint_descriptor *p_endp_descr;

	while (remain_bytes > 1) {

		switch (full_conf[base + 1]) {

		case 0x2: /* CONFIGURATION_DESCRIPTOR_TYPE */

			p_conf_descr = (struct configuration_descriptor *)(full_conf + base);
			base += sizeof(struct configuration_descriptor);
			remain_bytes -= sizeof(struct configuration_descriptor);

			printk(DEBUG, "Configuration descriptor\r\n");
			usb_conf_descr_print(p_conf_descr);
			mdelay(200);
			break;

		case 0x4: /* INTERFACE_DESCRIPTOR_TYPE */

			p_iface_descr = (struct interface_descriptor *)(full_conf + base);
			base += sizeof(struct interface_descriptor);
			remain_bytes -= sizeof(struct interface_descriptor);

			printk(DEBUG, "Interface descriptor\r\n");
			usb_iface_descr_print(p_iface_descr);
			mdelay(200);
			break;

		case 0x5: /* ENDPOINT_DESCRIPTOR_TYPE */

			p_endp_descr = (struct endpoint_descriptor *)(full_conf + base);
			base += sizeof(struct endpoint_descriptor);
			remain_bytes -= sizeof(struct endpoint_descriptor);

			printk(DEBUG, "Endpoint descriptor\r\n");
			usb_endp_descr_print(p_endp_descr);
			mdelay(200);
			break;

		default:
			base++;
			remain_bytes--;
		};
	}
}

int32_t usb_device_get_full_conf(uint32_t usb_channel, uint8_t dev_addr, uint8_t *full_conf, size_t full_conf_size)
{
	struct std_request get_full_conf = {0x80, 0x06, 0x0200, 0x0000, full_conf_size};

	int16_t ret_val = max3421e_usb_setup_send(usb_channel, dev_addr, &get_full_conf);

	if (ret_val < 0) {
		printk(DEBUG, "%s(): SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * ret_val);
		return -1;
	}

	/* It needs time to process request */
	mdelay(200);

	max3421e_usb_recv_tog_set(usb_channel, 1);

	ret_val = max3421e_usb_bulk_receive(usb_channel, dev_addr, 0, full_conf, full_conf_size);
	mdelay(50);
	max3421e_usb_status_out_send(usb_channel, dev_addr);

	if (ret_val < 0) {
		printk(DEBUG, "%s(): BULK-IN transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * ret_val);
		return -2;
	}
	return 0;
}
#endif

int16_t usb_device_get_conf(uint32_t usb_channel, uint8_t dev_addr)
{
	uint8_t configuration;
	struct std_request get_ep_status = {0x80, 0x08, 0x0000, 0x0000, 1};

	int16_t hrslt = max3421e_usb_setup_send(usb_channel, dev_addr, &get_ep_status);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -1;
	}

	/* It needs time to process request */
	mdelay(200);

	max3421e_usb_recv_tog_set(usb_channel, 1);

	hrslt = max3421e_usb_bulk_receive(usb_channel, dev_addr, 0, &configuration, get_ep_status.w_length);
	mdelay(50);
	max3421e_usb_status_out_send(usb_channel, dev_addr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): BULK-IN transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -2;
	}
	return configuration;
}

int32_t usb_device_set_conf(uint32_t usb_channel, uint8_t dev_addr, uint8_t conf)
{
	struct std_request set_conf_req = {0x00, 0x09, conf, 0x0000, 0x0000};

	int16_t hrslt = max3421e_usb_setup_send(usb_channel, dev_addr, &set_conf_req);
	mdelay(50);
	max3421e_usb_status_in_send(usb_channel, dev_addr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -1;
	}
	return 0;
}

int32_t usb_device_get_ep_status(uint32_t usb_channel, uint8_t dev_addr, uint8_t ep_addr, uint8_t *status)
{
	struct std_request get_ep_status = {0x82, 0x00, 0x0000, ep_addr, 2};

	int16_t hrslt = max3421e_usb_setup_send(usb_channel, dev_addr, &get_ep_status);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): SETUP transmission error. HRSLT: 0x%01X\r\n", __func__, -1 * hrslt);
		return -1;
	}

	/* It needs time to process request */
	mdelay(200);

	max3421e_usb_recv_tog_set(usb_channel, 1);

	hrslt = max3421e_usb_bulk_receive(usb_channel, dev_addr, 0, status, get_ep_status.w_length);

	max3421e_usb_status_out_send(usb_channel, dev_addr);

	if (hrslt < 0) {
		printk(DEBUG, "%s(): BULK-IN transmission error. HRSLT: 0x%01X\r\n", __func__,  -1 * hrslt);
		return -2;
	}

	return 0;
}

int32_t ms_usb_data_read(uint8_t dev_addr, uint8_t ep_addr, uint8_t *dst_buf, size_t dst_buf_size)
{
	int8_t ret_val = 0x0;

	ret_val = max3421e_usb_bulk_receive(MOUSE_CHANNEL, dev_addr, ep_addr, dst_buf, dst_buf_size);
	if ((-1 * ret_val) == USB_NAK)
		return -1;

	if ((-1 * ret_val) == USB_TOGERR){
		max3421e_usb_recv_tog_set(MOUSE_CHANNEL, 0);
		return -2;
	}

	if (ret_val < 0) {
		printk(DEBUG, "BULK-IN transmission error. HRSLT: 0x%01X\r\n",  -1 * ret_val);
		return -3;
	}
	return ret_val;
}

int32_t kb_usb_data_read(uint8_t dev_addr, uint8_t ep_addr, uint8_t *dst_buf, size_t dst_buf_size)
{
	int8_t ret_val = 0x0;

	ret_val = max3421e_usb_bulk_receive(KEYBOARD_CHANNEL, dev_addr, ep_addr, dst_buf, dst_buf_size);
	if ((-1 * ret_val) == USB_NAK)
		return -1;

	if ((-1 * ret_val) == USB_TOGERR){
		max3421e_usb_recv_tog_set(KEYBOARD_CHANNEL, 0);
		return -2;
	}

	if (ret_val < 0) {
		printk(DEBUG, "BULK-IN transmission error. HRSLT: 0x%01X\r\n",  -1 * ret_val);
		return -3;
	}
	return ret_val;
}

int32_t device_detect_init(uint32_t usb_channel, uint8_t usb_dev_addr)
{
	max3421e_master_mode_set(usb_channel);

	/* TODO: Check return value */
	if (max3421e_usb_device_detect(usb_channel) == 0){
		return -1;
	}

	max3421e_usb_sof_start(usb_channel);

	max3421e_usb_bus_reset(usb_channel);

	if (max3421e_usb_device_set_address(usb_channel, usb_dev_addr) != 0)
		return -2;

	mdelay(150);

	struct configuration_descriptor conf_descr;
	if (usb_device_get_conf_descr(usb_channel, usb_dev_addr, &conf_descr) != 0)
		return -8;
#ifndef USE_MDR1986VE9x
	usb_conf_descr_print(&conf_descr);
#endif
	mdelay(50);

	struct device_descriptor dev_descr;
	if (usb_device_get_dev_descr(usb_channel, usb_dev_addr, &dev_descr) != 0)
		return -3;
#ifndef USE_MDR1986VE9x
	usb_dev_descr_print(&dev_descr);
#endif
	/* TODO: Check VID and PID dev_descr */

	mdelay(50);

#ifndef USE_MDR1986VE9x
	uint8_t full_conf[512];
	if (usb_device_get_full_conf(usb_channel, usb_dev_addr, full_conf, conf_descr.w_total_length) < 0)
		return -4;
	usb_device_full_conf_print(full_conf, conf_descr.w_total_length);
#endif

	mdelay(50);

	int16_t conf = usb_device_get_conf(usb_channel, usb_dev_addr);
	if (conf < 0)
		return -5;
	printk(DEBUG, "configuration: 0x%02X\r\n", conf);

	mdelay(50);

	if (usb_device_set_conf(usb_channel, usb_dev_addr, 0x1) != 0)
		return -6;

	mdelay(50);

	conf = usb_device_get_conf(usb_channel, usb_dev_addr);
	if (conf < 0)
		return -7;
	printk(DEBUG, "configuration: 0x%02X\r\n", conf);

	mdelay(50);

#ifndef USE_MDR1986VE9x
	uint8_t status[2];
	if (usb_device_get_ep_status(usb_channel, usb_dev_addr, 0x01, status) == 0) {
		printk(DEBUG, "status[0]: 0x%02X\r\n", status[0]);
		printk(DEBUG, "status[1]: 0x%02X\r\n", status[1]);
	}
#endif

	mdelay(50);
	return 0;
}

void data_to_hid_transmit(uint32_t hid_num, uint8_t *src_buffer, size_t buffer_size)
{
	printk(DEBUG, "%s(): hid_num %ld, buffer_size %d\r\n", __func__, hid_num, buffer_size);
#ifdef USE_MDR1986VE9x
	MDR_UART_TypeDef* UARTx = MDR_UART1;
//	if (hid_num == 1) {
//		UARTx = MDR_UART1;
//	} else if (hid_num == 2){
//		UARTx = MDR_UART2;
//	}

	uint32_t	ms_timeout = 200000;
	size_t i;
	for (i = 0; i < buffer_size; ++i) {
		UART_SendData (UARTx, src_buffer[i]);
		/** Ожидать окончания передачи ms_timeout миллисекунд.*/
		do {
			--ms_timeout;
			if (ms_timeout == 0)
				/* TODO: Рассмотреть возможные варианты действий в случае превышения таймаута. */
				break;
		} while (UART_GetFlagStatus (UARTx, UART_FLAG_TXFE) != 1);
	}
#else
	USART_TypeDef* UARTx = USART1;
	if (hid_num == 1) {
		UARTx = USART1;
	} else if (hid_num == 2){
		UARTx = USART2;
	}
	size_t i;
	for (i = 0; i < buffer_size; ++i) {
		LL_USART_TransmitData8(UARTx, src_buffer[i]);

#if defined(PERIOD_TIMEOUT)
		struct period timeout;
		period_start(&timeout, 100000);
#endif

		do {
			__DSB();
#if !defined(PERIOD_TIMEOUT)
			--usec_timeout;
			if (usec_timeout == 0)
				break;
#else
			if (is_period_expired(&timeout, NOT_RESTART_PERIOD))
				break;
#endif
		} while (LL_USART_IsActiveFlag_TXE(UARTx) != 1);
	}
#endif


}

uint32_t current_hid_num = 1;

void kbms_data_send(uint8_t *kb_buffer, size_t kb_buffer_size, uint8_t *ms_buffer, size_t ms_buffer_size) {

	if (kb_buffer[0] == 0x10 && kb_buffer[2] == 0x50) {
		printk(DEBUG, "R_CTRL + <-\r\n");
		current_hid_num = 1;
		return;
	}
	if (kb_buffer[0] == 0x10 && kb_buffer[2] == 0x4F) {
		printk(DEBUG, "R_CTRL + ->\r\n");
		current_hid_num = 2;
		return;
	}
	struct kbms_data kbms;

	memcpy(&kbms.kb_data, kb_buffer, sizeof(kbms.kb_data));
	memcpy(&kbms.ms_data, ms_buffer, sizeof(kbms.ms_data));
	kbms.hid_num = current_hid_num;

	data_to_hid_transmit(current_hid_num, (uint8_t*)&kbms, sizeof(kbms));
}

void spi_usb_transmission_start(void)
{
	int32_t ret_val = -1;
	uint32_t kb_present = 0;
	uint32_t ms_present = 0;
	mdelay(1000);
	printk(DEBUG, "\r\nPrepare keyboard channel\r\n");
	max3421e_fullduplex_spi_set(KEYBOARD_CHANNEL);
#ifndef USE_MDR1986VE9x
	max3421e_rev_print(KEYBOARD_CHANNEL);
#endif
	max3421e_chip_reset(KEYBOARD_CHANNEL);
	mdelay(1000);
	kb_ms_power_on();
	mdelay(5000);
	ret_val = device_detect_init(KEYBOARD_CHANNEL, KB_USB_ADDR);
	if (ret_val != 0) {
		printk(DEBUG, "kb_detect_init(): %ld\r\n", ret_val);
		return;
	} else {
		kb_present = 1;
	}

	printk(DEBUG, "\r\nPrepare mouse channel\r\n");
	max3421e_fullduplex_spi_set(MOUSE_CHANNEL);
#ifndef USE_MDR1986VE9x
	max3421e_rev_print(MOUSE_CHANNEL);
#endif
	max3421e_chip_reset(MOUSE_CHANNEL);
	mdelay(1000);
	ret_val = device_detect_init(MOUSE_CHANNEL, MS_USB_ADDR);
	if (ret_val != 0) {
		printk(DEBUG, "ms_detect_init(): %ld\r\n", ret_val);
		return;
	} else {
		ms_present = 1;
	}

	if (kb_present == 0 && ms_present == 0) {
		printk(DEBUG, "There aren't devices. Exit\r\n");
		return;
	}
	printk(DEBUG, "Start transmission\r\n");

	uint8_t kb_data[8];
	uint8_t ms_data[4];
	while (1) {
		memset(kb_data, 0, sizeof(kb_data));
		if (kb_present == 1) {
			kb_usb_data_read(KB_USB_ADDR, 0x1, kb_data, sizeof(kb_data));

#if !defined(USE_MDR1986VE9x)
			printk(INFO, "kb_data: ");
			size_t idx = 0;
			for (idx = 0; idx < sizeof(kb_data); ++idx)
				printk(INFO, "0x%02X ", kb_data[idx]);
			printk(INFO, "\r\n");
#endif
		}

		memset(ms_data, 0, sizeof(ms_data));
		if (ms_present == 1) {
			ms_usb_data_read(MS_USB_ADDR, 0x1, ms_data, sizeof(ms_data));
#if !defined(USE_MDR1986VE9x)
			printk(INFO, "ms_data: ");
			size_t idx = 0;
			for (idx = 0; idx < sizeof(ms_data); ++idx)
				printk(INFO, "0x%02X ", ms_data[idx]);
			printk(INFO, "\r\n");
#endif
		}
		kbms_data_send(kb_data, sizeof(kb_data), ms_data, sizeof(ms_data));
		mdelay(50);
	}
}
