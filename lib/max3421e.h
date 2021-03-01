/*
 * max3421e.h
 *
 *  Created on: Oct 2, 2020
 *      Author: user
 */

#ifndef MAX3421E_H_
#define MAX3421E_H_

#include "drivers.h"

__PACKED_STRUCT std_request {
		uint8_t		bm_request_type;
		uint8_t		b_request;
		uint16_t	w_value;
		uint16_t	w_index;
		uint16_t	w_length;
	};

__PACKED_STRUCT device_descriptor {
	uint8_t		b_length;
	uint8_t		b_descriptor_type;
	uint16_t	bcd_usb;
	uint8_t		b_device_class;
	uint8_t		b_device_sub_class;
	uint8_t		b_device_protocol;
	uint8_t		b_max_packet_size;
	uint16_t	id_vendor;
	uint16_t	id_product;
	uint16_t	bcd_device;
	uint8_t		i_manufacturer;
	uint8_t		i_product;
	uint8_t		i_serial_number;
	uint8_t		b_num_configurations;
};

__PACKED_STRUCT configuration_descriptor {
	uint8_t		b_length;
	uint8_t		b_descriptor_type;
	uint16_t	w_total_length;
	uint8_t		b_num_interfaces;
	uint8_t		b_configuration_value;
	uint8_t		i_configuration;
	uint8_t		bm_attributes;
	uint8_t		b_max_power;
};

__PACKED_STRUCT interface_descriptor {
	uint8_t		b_length;
	uint8_t		b_descriptor_type;
	uint8_t		b_interface_number;
	uint8_t		b_alternate_setting;
	uint8_t		b_num_endpoints;
	uint8_t		b_interface_class;
	uint8_t		b_interface_subclass;
	uint8_t		b_interface_protocol;
	uint8_t		i_interface;
};

__PACKED_STRUCT endpoint_descriptor {
	uint8_t		b_length;
	uint8_t		b_descriptor_type;
	uint8_t		b_endpoint_address;
	uint8_t		bm_attributes;
	uint16_t	w_max_packet_size;
	uint8_t		b_interval;
};

#define USB_EP0					0x00
#define USB_EP1					0x01

#define SPI_USB_REGNUMOFF		0x03
#define SPI_USB_WROP			0x02
#define SPI_USB_RDOP			0x00

#define SPI_USB_RCVFIFOREG		0x01
#define SPI_USB_SNDFIFOREG		0x02
#define SPI_USB_SUDFIFOREG		0x04
#define SPI_USB_RCVBCREG		0x06
#define SPI_USB_SNDBCREG		0x07

#define SPI_USB_USBIRQREG		0x0D
#define SPI_USB_USBCTLREG		0x0F
#define SPI_USB_CPUCTLREG		0x10
#define SPI_USB_PINCTLREG		0x11
#define SPI_USB_REVREG			0x12
#define SPI_USB_IOPINS1REG		0x14
#define SPI_USB_IOPINS2REG		0x15
#define SPI_USB_HIRQREG			0x19
#define SPI_USB_MODEREG			0x1B
#define SPI_USB_PERADDRREG		0x1C
#define SPI_USB_HCTLREG			0x1D
#define SPI_USB_HXFRREG			0x1E
#define SPI_USB_HRSLREG			0x1F

//#define SPI_USB_HIENREG			0x1A

#define SPI_CMD_RDRCVFIFO	((SPI_USB_RCVFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)
#define SPI_CMD_WRRCVFIFO	((SPI_USB_RCVFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)

#define SPI_CMD_RDSNDFIFO	((SPI_USB_SNDFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)
#define SPI_CMD_WRSNDFIFO	((SPI_USB_SNDFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)

#define SPI_CMD_RDSUDFIFO	((SPI_USB_SUDFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)
#define SPI_CMD_WRSUDFIFO	((SPI_USB_SUDFIFOREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)

#define SPI_CMD_RDRCVBC		((SPI_USB_RCVBCREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)
#define SPI_CMD_WRRCVBC		((SPI_USB_RCVBCREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)

#define SPI_CMD_RDSNDBC		((SPI_USB_SNDBCREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)
#define SPI_CMD_WRSNDBC		((SPI_USB_SNDBCREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)

#define SPI_CMD_RDREV		((SPI_USB_REVREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRCPUCTL	((SPI_USB_CPUCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDCPUCTL	((SPI_USB_CPUCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRPINCTL	((SPI_USB_PINCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDPINCTL	((SPI_USB_PINCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRUSBIRQ	((SPI_USB_USBIRQREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDUSBIRQ	((SPI_USB_USBIRQREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRUSBCTL	((SPI_USB_USBCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDUSBCTL	((SPI_USB_USBCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRIOPINS1	((SPI_USB_IOPINS1REG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDIOPINS1	((SPI_USB_IOPINS1REG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRIOPINS2	((SPI_USB_IOPINS2REG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDIOPINS2	((SPI_USB_IOPINS2REG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRHIRQ	((SPI_USB_HIRQREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDHIRQ	((SPI_USB_HIRQREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRMODE	((SPI_USB_MODEREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDMODE	((SPI_USB_MODEREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRPERADDR	((SPI_USB_PERADDRREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDPERADDR	((SPI_USB_PERADDRREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRHCTL	((SPI_USB_HCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDHCTL	((SPI_USB_HCTLREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_WRHXFR	((SPI_USB_HXFRREG << SPI_USB_REGNUMOFF) | SPI_USB_WROP)
#define SPI_CMD_RDHXFR	((SPI_USB_HXFRREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define SPI_CMD_RDHRSL	((SPI_USB_HRSLREG << SPI_USB_REGNUMOFF) | SPI_USB_RDOP)

#define HIRQ_RCVDAVIRQ	0x04
#define HIRQ_CONDETIRQ	0x20
#define HIRQ_FRAMEIRQ	0x40
#define HIRQ_HXFRDNIRQ	0x80

#define HCTL_BUSRST		0x01
#define HCTL_SAMPLEBUS	0x04
#define HCTL_RCVTOG0	0x10
#define HCTL_RCVTOG1	0x20
#define HCTL_SNDTOG0	0x40
#define HCTL_SNDTOG1	0x80

#define MODE_HOST		0x01
#define MODE_LOWSPEED	0x02
#define MODE_SOFKAENAB	0x08
#define MODE_DMPULLDN	0x40
#define MODE_DPPULLDN	0x80

#define HRSL_KSTATUS	0x40
#define HRSL_JSTATUS	0x80

#define HXFR_BULKIN		0x00
#define HXFR_SETUP		0x10
#define HXFR_BULK_OUT	0x20
#define HXFR_HSIN		0x80
#define HXFR_HSOUT		0xA0

#define IOPINS1_GPOUT1 0x1

#define USBCTL_CHIPRES	0x20

#define USBIRQ_OSCOKIRQ	0x01

#define PINCTL_GPXA		0x01
#define PINCTL_GPXB		0x02
#define PINCTL_POSINT	0x04
#define PINCTL_INTLEVEL 0x08
#define PINCTL_FDUPSPI	0x10

void max3421e_chip_activate(uint32_t chip_num);

void max3421e_chip_deactivate(uint32_t chip_num);

uint8_t max3421e_usbirq_read(void);

void max3421e_usbirq_write(uint8_t usbirq);

uint8_t max3421e_usbctl_read(void);

void max3421e_usbctl_write(uint8_t usbctl);

uint8_t max3421e_pinctl_read(void);

void max3421e_pinctl_write(uint8_t pinctl);

uint8_t max3421e_iopins1_read(void);

void max3421e_iopins1_write(uint8_t iopins1);

uint8_t max3421e_iopins2_read(void);

void max3421e_iopins2_write(uint8_t iopins1);

uint8_t max3421e_rev_read(void);

uint8_t max3421e_hirq_read(void);

void max3421e_hirq_write(uint8_t hirq);

uint8_t max3421e_mode_read(void);

void max3421e_mode_write(uint8_t mode);

uint8_t max3421e_peraddr_read(void);

void max3421e_peraddr_write(uint8_t peraddr);

uint8_t max3421e_hctl_read(void);

void max3421e_hctl_write(uint8_t hctl);

uint8_t max3421e_hxfr_read(void);

void max3421e_hxfr_write(uint8_t hxfr);

uint8_t max3421e_hrsl_read(void);

uint8_t max3421e_rcvfifo_write(uint8_t *src_buf, size_t data_size);

uint8_t max3421e_rcvfifo_read(uint8_t *dst_buf, size_t data_size);

uint8_t max3421e_sndfifo_write(uint8_t *src_buf, size_t data_size);

uint8_t max3421e_sndfifo_read(uint8_t *dst_buf, size_t data_size);

uint8_t max3421e_sudfifo_write(uint8_t *src_buf, size_t data_size);

uint8_t max3421e_sudfifo_read(uint8_t *dst_buf, size_t data_size);

void max3421e_rcvbc_write(uint8_t size);

uint8_t max3421e_rcvbc_read(void);

void max3421e_sndbc_write(uint8_t size);

uint8_t max3421e_sndbc_read(void);

/****************************************************************************/

void max3421e_fullduplex_spi_set(uint32_t chip_num);

void max3421e_chip_reset(uint32_t chip_num);

void max3421e_master_mode_set(uint32_t chip_num);

void max3421e_usb_sof_start(uint32_t chip_num);

void max3421e_usb_sof_stop(uint32_t chip_num);

void max3421e_usb_bus_reset(uint32_t chip_num);

#if 0
void max3421e_usb_device_poll_detection_cycle(void);
void max3421e_usb_device_irq_detection_cycle(void);
#endif

uint32_t max3421e_usb_device_detect(uint32_t chip_num);

int32_t max3421e_usb_device_set_address(uint32_t chip_num, uint8_t dev_addr);

int16_t max3421e_usb_setup_send(uint32_t usb_channel, uint8_t dev_addr, struct std_request* request);

int16_t max3421e_usb_status_out_send(uint32_t usb_channel, uint8_t dev_addr);

int16_t max3421e_usb_setup_send(uint32_t usb_channel, uint8_t dev_addr, struct std_request* request);

int16_t max3421e_usb_status_in_send(uint32_t usb_channel, uint8_t dev_addr);

int16_t max3421e_usb_bulk_receive(uint32_t chip_num, uint8_t dev_addr, uint8_t ep_addr, void* dst_buf, size_t buf_size);

void max3421e_usb_recv_tog_set(uint32_t chip_num, uint32_t recv_tog);
void max3421e_usb_send_tog_set(uint32_t chip_num, uint32_t send_tog);

#endif /* MAX3421E_H_ */
