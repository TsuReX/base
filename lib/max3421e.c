/*
 * max3421e.c
 *
 *  Created on: Oct 2, 2020
 *      Author: user
 */

#include <stddef.h>

#include "drivers.h"
#include "max3421e.h"

#include "time.h"
#include "spi.h"
#include "console.h"
#include "debug.h"

#undef SPI_DMA

uint8_t max3421e_usbirq_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDUSBIRQ, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDUSBIRQ;
	uint8_t usbirq = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&usbirq, sizeof(usbirq));
	return usbirq;
#endif
}

void max3421e_usbirq_write(uint8_t usbirq)
{
	uint8_t	buffer[2] = {SPI_CMD_WRUSBIRQ, usbirq};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_usbctl_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDUSBCTL, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDUSBCTL;
	uint8_t usbctl = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&usbctl, sizeof(usbctl));
	return usbctl;
#endif
}

void max3421e_usbctl_write(uint8_t usbctl)
{
	uint8_t	buffer[2] = {SPI_CMD_WRUSBCTL, usbctl};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_cpuctl_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDCPUCTL, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDCPUCTL;
	uint8_t cpuctl = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&cpuctl, sizeof(cpuctl));
	return cpuctl;
#endif
}

void max3421e_cpuctl_write(uint8_t cpuctl)
{
	uint8_t	buffer[2] = {SPI_CMD_WRCPUCTL, cpuctl};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_pinctl_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDCPUCTL, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDCPUCTL;
	uint8_t pinctl = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&pinctl, sizeof(pinctl));
	return pinctl;
#endif
}

void max3421e_pinctl_write(uint8_t pinctl)
{
	uint8_t	buffer[2] = {SPI_CMD_WRPINCTL, pinctl};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_iopins1_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDIOPINS1, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDIOPINS1;
	uint8_t iopins1 = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&iopins1, sizeof(iopins1));
	return iopins1;
#endif
}

void max3421e_iopins1_write(uint8_t iopins1)
{
	uint8_t	buffer[2] = {SPI_CMD_WRIOPINS1, iopins1};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_iopins2_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDIOPINS2, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDIOPINS2;
	uint8_t iopins2 = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&iopins2, sizeof(iopins2));
	return iopins2;
#endif
}

void max3421e_iopins2_write(uint8_t iopins1)
{
	uint8_t	buffer[2] = {SPI_CMD_WRIOPINS2, iopins1};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_rev_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDREV, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t	cmd = SPI_CMD_RDREV;
	uint8_t revision = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&revision, sizeof(revision));
	return revision;
#endif
}

uint8_t max3421e_hirq_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDHIRQ, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDHIRQ;
	uint8_t hirq = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&hirq, sizeof(hirq));
	return hirq;
#endif
}

void max3421e_hirq_write(uint8_t hirq)
{
	uint8_t	buffer[2] = {SPI_CMD_WRHIRQ, hirq};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_mode_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDMODE, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDMODE;
	uint8_t mode = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&mode, sizeof(mode));
	return mode;
#endif
}

void max3421e_mode_write(uint8_t mode)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_WRMODE, mode};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	uint8_t	buffer[2] = {SPI_CMD_WRMODE, mode};
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_peraddr_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDPERADDR, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDPERADDR;
	uint8_t peraddr = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&peraddr, sizeof(peraddr));
	return peraddr;
#endif
}

void max3421e_peraddr_write(uint8_t peraddr)
{
	uint8_t	buffer[2] = {SPI_CMD_WRPERADDR, peraddr};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_hctl_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDHCTL, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDHCTL;
	uint8_t hctl = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&hctl, sizeof(hctl));
	return hctl;
#endif
}

void max3421e_hctl_write(uint8_t hctl)
{
	uint8_t	buffer[2] = {SPI_CMD_WRHCTL, hctl};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_hxfr_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDHXFR, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDHXFR;
	uint8_t hxfr = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&hxfr, sizeof(hxfr));
	return hxfr;
#endif
}

void max3421e_hxfr_write(uint8_t hxfr)
{
	uint8_t	buffer[2] = {SPI_CMD_WRHXFR, hxfr};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_hrsl_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDHRSL, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDHRSL;
	uint8_t hrsl = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&hrsl, sizeof(hrsl));
	return hrsl;
#endif
}

uint8_t max3421e_rcvfifo_write(uint8_t *src_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_WRRCVFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(src_buf, NULL, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(src_buf, sizeof(data_size));
	return data_size;
#endif
}

uint8_t max3421e_rcvfifo_read(uint8_t *dst_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_RDRCVFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(NULL, dst_buf, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(dst_buf, sizeof(data_size));
	return data_size;
#endif
}

uint8_t max3421e_sndfifo_write(uint8_t *src_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_WRSNDFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(src_buf, NULL, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(src_buf, sizeof(data_size));
	return data_size;
#endif
}

uint8_t max3421e_sndfifo_read(uint8_t *dst_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_RDSNDFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(NULL, dst_buf, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(dst_buf, sizeof(data_size));
	return data_size;
#endif
}

uint8_t max3421e_sudfifo_write(uint8_t *src_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_WRSUDFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(src_buf, NULL, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(src_buf, sizeof(data_size));
	return data_size;
#endif
}

uint8_t max3421e_sudfifo_read(uint8_t *dst_buf, size_t data_size)
{
	uint8_t	cmd = SPI_CMD_RDSUDFIFO;
#if !defined(SPI_DMA)
	spi_data_xfer(&cmd, NULL, 1);
	size_t size = spi_data_xfer(NULL, dst_buf, data_size);
	return size;
#else
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(dst_buf, sizeof(data_size));
	return data_size;
#endif
}

void max3421e_rcvbc_write(uint8_t size)
{
	uint8_t	buffer[2] = {SPI_CMD_WRRCVBC, size};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_rcvbc_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDRCVBC, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDRCVBC;
	uint8_t rcvdc = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&rcvdc, sizeof(rcvdc));
	return rcvdc;
#endif
}

void max3421e_sndbc_write(uint8_t size)
{
	uint8_t	buffer[2] = {SPI_CMD_WRSNDBC, size};
#if !defined(SPI_DMA)
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
#else
	spi_dma_data_send(buffer, sizeof(buffer) / sizeof(buffer[0]));
#endif
}

uint8_t max3421e_sndbc_read(void)
{
#if !defined(SPI_DMA)
	uint8_t	buffer[2] = {SPI_CMD_RDSNDBC, 0x00};
	spi_data_xfer(buffer, buffer, sizeof(buffer) / sizeof(buffer[0]));
	return buffer[1];
#else
	uint8_t cmd = SPI_CMD_RDSNDBC;
	uint8_t sndbc = 0xFF;
	spi_dma_data_send(&cmd, sizeof(cmd));
	spi_dma_data_recv(&sndbc, sizeof(sndbc));
	return sndbc;
#endif
}

/*********************************************************************************/

uint32_t max3421e_hirq_hxfrdnirq_wait(uint32_t chip_num, size_t u100_timeout)
{
	max3421e_chip_activate(chip_num);
	while(((max3421e_hirq_read() & HIRQ_HXFRDNIRQ) != HIRQ_HXFRDNIRQ) && (u100_timeout > 0)) {
		max3421e_chip_deactivate(chip_num);
		u100delay(1);
		max3421e_chip_activate(chip_num);
		--u100_timeout;
	}
	max3421e_chip_deactivate(chip_num);
	if (u100_timeout == 0)
		return 1;
	return 0;
}

int16_t max3421e_usb_status_in_send(uint32_t chip_num, uint8_t dev_addr)
{
	max3421e_chip_activate(chip_num);
	max3421e_peraddr_write(dev_addr);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_hxfr_write(HXFR_HSIN);
	max3421e_chip_deactivate(chip_num);

//	max3421e_chip_activate(chip_num);
//	while((max3421e_hirq_read() & HIRQ_HXFRDNIRQ) != HIRQ_HXFRDNIRQ) {
//		max3421e_chip_deactivate(chip_num);
//		u100delay(1);
//		max3421e_chip_activate(chip_num);
//	}
//	max3421e_chip_deactivate(chip_num);

	uint32_t ret_val = max3421e_hirq_hxfrdnirq_wait(chip_num, 1000);
	if (ret_val != 0) {
#ifdef DEBUG
		printk(DEBUG, "%s(): Transfer can't be done\r\n", __func__);
#endif
		return -1 * 0xFF;
	}

	max3421e_chip_activate(chip_num);
	max3421e_hirq_write(HIRQ_HXFRDNIRQ);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	uint8_t hrslt = max3421e_hrsl_read() & 0x0F;
	max3421e_chip_deactivate(chip_num);

	return -1 * hrslt;
}

int16_t max3421e_usb_status_out_send(uint32_t chip_num, uint8_t dev_addr)
{
	max3421e_chip_activate(chip_num);
	max3421e_peraddr_write(dev_addr);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_hxfr_write(HXFR_HSOUT);
	max3421e_chip_deactivate(chip_num);

//	max3421e_chip_activate(chip_num);
//	while((max3421e_hirq_read() & HIRQ_HXFRDNIRQ) != HIRQ_HXFRDNIRQ) {
//		max3421e_chip_deactivate(chip_num);
//		u100delay(1);
//		max3421e_chip_activate(chip_num);
//	}
//	max3421e_chip_deactivate(chip_num);

	uint32_t ret_val = max3421e_hirq_hxfrdnirq_wait(chip_num, 1000);
	if (ret_val != 0) {
#ifdef DEBUG
		printk(DEBUG, "%s(): Transfer can't be done\r\n", __func__);
#endif
		return -1 * 0xFF;
	}

	max3421e_chip_activate(chip_num);
	max3421e_hirq_write(HIRQ_HXFRDNIRQ);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	uint8_t hrslt = max3421e_hrsl_read() & 0x0F;
	max3421e_chip_deactivate(chip_num);

	return -1 * hrslt;
}

int16_t max3421e_usb_setup_send(uint32_t chip_num, uint8_t dev_addr, struct std_request* request)
{
	/* Write data into SETUP FIFO */
	max3421e_chip_activate(chip_num);
	max3421e_sudfifo_write((uint8_t*)request, 8);
	max3421e_chip_deactivate(chip_num);

	/* Set device address */
	max3421e_chip_activate(chip_num);
	max3421e_peraddr_write(dev_addr);
	max3421e_chip_deactivate(chip_num);

	size_t tries = 10;
	uint32_t ret_val = 0;
	do {
		/* Initiate SETUP package transmission */
		max3421e_chip_activate(chip_num);
		max3421e_hxfr_write(HXFR_SETUP);
		max3421e_chip_deactivate(chip_num);
		/* Check ending of the package transmission */
		ret_val = max3421e_hirq_hxfrdnirq_wait(chip_num, 1000);
		if (ret_val != 0) {
			printk(DEBUG, "%s(): Transfer can't be done\r\n", __func__);
		} else {
			break;
		}
	} while (tries-- != 0);

	if (tries == 0 && ret_val != 0) {
#ifdef DEBUG
		printk(DEBUG, "%s(): Transfer can't be done\r\n", __func__);
#endif
		return -1 * 0xFF;
	}

	/* Clear flag of the transmission ending */
	max3421e_chip_activate(chip_num);
	max3421e_hirq_write(HIRQ_HXFRDNIRQ);
	max3421e_chip_deactivate(chip_num);

	/* Check result of the SETUP transmission */
	uint8_t hrsl = 0;
	max3421e_chip_activate(chip_num);
	hrsl = max3421e_hrsl_read() & 0x0F;
	max3421e_chip_deactivate(chip_num);

	return -1 * (hrsl & 0x0F);
}

void max3421e_usb_send_tog_set(uint32_t chip_num, uint32_t send_tog)
{
	/* Read HCTL register */
	max3421e_chip_activate(chip_num);
	uint8_t hctl = max3421e_hctl_read();
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	if (send_tog == 0){
		/* Notice master to send DATA0 */
		max3421e_hctl_write(hctl | HCTL_SNDTOG0);
	} else {
		/* Notice master to send DATA1 */
		max3421e_hctl_write(hctl | HCTL_SNDTOG1);
	}
	max3421e_chip_deactivate(chip_num);
}

void max3421e_usb_recv_tog_set(uint32_t chip_num, uint32_t recv_tog)
{
	/* Read HCTL register */
	max3421e_chip_activate(chip_num);
	uint8_t hctl = max3421e_hctl_read();
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	if (recv_tog == 0){
		/* Notice master to wait DATA0 */
		max3421e_hctl_write(hctl | HCTL_RCVTOG0);
	} else {
		/* Notice master to wait DATA1 */
		max3421e_hctl_write(hctl | HCTL_RCVTOG1);
	}
	max3421e_chip_deactivate(chip_num);
}

int16_t max3421e_usb_bulk_receive(uint32_t chip_num, uint8_t dev_addr, uint8_t ep_addr, void* dst_buf, size_t buf_size)
{
	/* Set device address */
	max3421e_chip_activate(chip_num);
	max3421e_peraddr_write(dev_addr);
	max3421e_chip_deactivate(chip_num);

	size_t size_to_recv = buf_size;

	do {
//		printk(DEBUG, "Size to receive %d\r\n", size_to_recv);
		/* Initiate BULK-IN transaction */
		max3421e_chip_activate(chip_num);
		max3421e_hxfr_write(HXFR_BULKIN | ep_addr);
		max3421e_chip_deactivate(chip_num);

		/* Check ending of the package transmission */
//		max3421e_chip_activate(chip_num);
//		while((max3421e_hirq_read() & HIRQ_HXFRDNIRQ) != HIRQ_HXFRDNIRQ) {
//			max3421e_chip_deactivate(chip_num);
//			u100delay(1);
//			max3421e_chip_activate(chip_num);
//		}
//		max3421e_chip_deactivate(chip_num);

		uint32_t ret_val = max3421e_hirq_hxfrdnirq_wait(chip_num, 1000);
		if (ret_val != 0) {
#ifdef DEBUG
			printk(DEBUG, "%s(): Transfer can't be done\r\n", __func__);
#endif
			return -1 * 0xFF;
		}

		/* Clear flag of the transmission ending */
		max3421e_chip_activate(chip_num);
		max3421e_hirq_write(HIRQ_HXFRDNIRQ);
		max3421e_chip_deactivate(chip_num);

		/* Check result of the BULK-IN transmission */
		max3421e_chip_activate(chip_num);
		uint8_t hrslt = max3421e_hrsl_read() & 0x0F;
		max3421e_chip_deactivate(chip_num);

		if (hrslt != 0){
			printk(DEBUG, "BULK-IN transmission error. HRSLT: 0x%01X\r\n", hrslt);
			return -1 * hrslt;
		}

		/* Check flag of successful data reception */
		max3421e_chip_activate(chip_num);
		while((max3421e_hirq_read() & HIRQ_RCVDAVIRQ) != HIRQ_RCVDAVIRQ) {
			max3421e_chip_deactivate(chip_num);
			u100delay(1);
			max3421e_chip_activate(chip_num);
		}
		max3421e_chip_deactivate(chip_num);

		uint8_t rcvbc = 0x00;

		/* Read data form reception byte counter */
		max3421e_chip_activate(chip_num);
		rcvbc = max3421e_rcvbc_read();
		max3421e_chip_deactivate(chip_num);

		printk(DEBUG, "rcvbc: 0x%02X\r\n", rcvbc);

		/* Read data from reception FIFO */
		max3421e_chip_activate(chip_num);
		if (size_to_recv >= rcvbc) {
			max3421e_rcvfifo_read((uint8_t*)(dst_buf + buf_size - size_to_recv), rcvbc);
			size_to_recv -= rcvbc;
		} else {
			max3421e_rcvfifo_read((uint8_t*)(dst_buf + buf_size - size_to_recv), size_to_recv);
			size_to_recv -= size_to_recv;
		}
		max3421e_chip_deactivate(chip_num);


		/* Clear flag of successful reception */
		max3421e_chip_activate(chip_num);
		max3421e_hirq_write(HIRQ_RCVDAVIRQ);
		max3421e_chip_deactivate(chip_num);

	} while(size_to_recv > 0);

	return buf_size;
}

void max3421e_fullduplex_spi_set(uint32_t chip_num)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(chip_num);
	max3421e_pinctl_write(PINCTL_FDUPSPI | PINCTL_POSINT | PINCTL_GPXB | PINCTL_GPXA);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_cpuctl_write(0x0);
	max3421e_chip_deactivate(chip_num);

}

void max3421e_chip_reset(uint32_t chip_num)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(chip_num);
	uint8_t usbctl = max3421e_usbctl_read();
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_usbctl_write(usbctl | USBCTL_CHIPRES);
	max3421e_chip_deactivate(chip_num);

	mdelay(10);

	max3421e_chip_activate(chip_num);
	max3421e_usbctl_write(usbctl);
	max3421e_chip_deactivate(chip_num);

	/* TODO: Implement waiting based on a timeout */
	max3421e_chip_activate(chip_num);
	while((max3421e_usbirq_read() & USBIRQ_OSCOKIRQ) != USBIRQ_OSCOKIRQ) {
		max3421e_chip_deactivate(chip_num);
		mdelay(1);
		max3421e_chip_activate(chip_num);
	}
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_usbirq_write(USBIRQ_OSCOKIRQ);
	max3421e_chip_deactivate(chip_num);
}

void max3421e_master_mode_set(uint32_t chip_num)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(chip_num);
	uint8_t mode = max3421e_mode_read();
	max3421e_chip_deactivate(chip_num);
	printk(DEBUG, "0 MODE: 0x%02X\r\n", mode);

	max3421e_chip_activate(chip_num);
	max3421e_mode_write(mode | MODE_DPPULLDN | MODE_DMPULLDN |MODE_HOST);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	mode = max3421e_mode_read();
	max3421e_chip_deactivate(chip_num);
	printk(DEBUG, "1 MODE: 0x%02X\r\n", mode);
}

void max3421e_usb_sof_stop(uint32_t chip_num)
{
	max3421e_chip_activate(chip_num);
	uint8_t mode = max3421e_mode_read();
	max3421e_chip_deactivate(chip_num);

	/* Start SOF */
	max3421e_chip_activate(chip_num);
	max3421e_mode_write(mode & ~MODE_SOFKAENAB);
	max3421e_chip_deactivate(chip_num);
}

void max3421e_usb_sof_start(uint32_t chip_num)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(chip_num);
	uint8_t mode = max3421e_mode_read();
	max3421e_chip_deactivate(chip_num);

	/* Start SOF */
	max3421e_chip_activate(chip_num);
	max3421e_mode_write(mode | MODE_SOFKAENAB);
	max3421e_chip_deactivate(chip_num);

	/* Wait first SOF */
	/* TODO: Implement waiting based on a timeout */
	max3421e_chip_activate(chip_num);
	while((max3421e_hirq_read() & HIRQ_FRAMEIRQ) != HIRQ_FRAMEIRQ) {
		max3421e_chip_deactivate(chip_num);
		mdelay(1);
		max3421e_chip_activate(chip_num);
	}
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	mode = max3421e_mode_read();
	max3421e_chip_deactivate(chip_num);
	printk(DEBUG, "MODE: 0x%02X\r\n", mode);
}

void max3421e_usb_bus_reset(uint32_t chip_num)
{
	printk(DEBUG, "%s()\r\n", __func__);

	max3421e_chip_activate(chip_num);
	uint8_t hctl = max3421e_hctl_read();
	max3421e_chip_deactivate(chip_num);

	/* Start bus reset */
	max3421e_chip_activate(chip_num);
	max3421e_hctl_write(hctl | HCTL_BUSRST);
	max3421e_chip_deactivate(chip_num);

	/* Wait end of bus reset */
	/* TODO: Implement waiting based on a timeout */
	max3421e_chip_activate(chip_num);
	while((max3421e_hctl_read() & HCTL_BUSRST) == HCTL_BUSRST) {
		max3421e_chip_deactivate(chip_num);
		mdelay(1);
		max3421e_chip_activate(chip_num);
	}
	max3421e_chip_deactivate(chip_num);

	mdelay(500);
}

#if 0
void max3421e_device_poll_detection_cycle(void)
{
	while(1) {
		max3421e_chip_activate();
		uint8_t hctl = max3421e_hctl_read();
		max3421e_chip_deactivate();

		/* Update bus state */
		max3421e_chip_activate();
		max3421e_hctl_write(hctl | HCTL_SAMPLEBUS);
		max3421e_chip_deactivate();

		max3421e_chip_activate();
		uint16_t hrsl = max3421e_hrsl_read();
		max3421e_chip_deactivate();

		switch(hrsl & (HRSL_JSTATUS | HRSL_KSTATUS)){
		case HRSL_KSTATUS:
				printk(DEBUG, "Low speed device connected\r\n");
				max3421e_chip_activate();
				uint8_t mode = max3421e_mode_read();
				max3421e_chip_deactivate();

				max3421e_chip_activate();
				max3421e_mode_write(mode | MODE_LOWSPEED);
				max3421e_chip_deactivate();
				break;
		case HRSL_JSTATUS:
				printk(DEBUG, "Full speed device connected\r\n");
				break;
		case (HRSL_JSTATUS | HRSL_KSTATUS):
				printk(DEBUG, "Bus illegal state\r\n");
				break;
		case 0x00:
				printk(DEBUG, "Device not connected\r\n");
				break;
		}

		mdelay(1000);
	}
}

void max3421e_device_irq_detection_cycle(void)
{
	while(1) {
		max3421e_chip_activate();
		uint16_t hirq = max3421e_hirq_read();
		while((hirq & HIRQ_CONDETIRQ) == 0x0) {
			max3421e_chip_deactivate();

			mdelay(1000);

			max3421e_chip_activate();
			hirq = max3421e_hirq_read();
		}
		max3421e_chip_deactivate();

		/* Deassert CONDETIRQ */
		max3421e_chip_activate();
		max3421e_hirq_write(HIRQ_CONDETIRQ);
		max3421e_chip_deactivate();

		max3421e_chip_activate();
		uint16_t hrsl = max3421e_hrsl_read();
		max3421e_chip_deactivate();

		switch(hrsl & (HRSL_JSTATUS | HRSL_KSTATUS)){
		case HRSL_KSTATUS:
				printk(DEBUG, "Low speed device connected\r\n");
				max3421e_chip_activate();
				uint8_t mode = max3421e_mode_read();
				max3421e_chip_deactivate();

				max3421e_chip_activate();
				max3421e_mode_write(mode | MODE_LOWSPEED);
				max3421e_chip_deactivate();
				break;
		case HRSL_JSTATUS:
				printk(DEBUG, "Full speed device connected\r\n");
				break;
		case (HRSL_JSTATUS | HRSL_KSTATUS):
				printk(DEBUG, "Bus illegal state\r\n");
				break;
		case 0x00:
				printk(DEBUG, "Device not connected\r\n");
				break;
		}

		mdelay(1000);
	}
}
#endif

uint32_t max3421e_usb_device_detect(uint32_t chip_num)
{
	printk(DEBUG, "%s(): chip_num %ld\r\n", __func__, chip_num);
	max3421e_chip_activate(chip_num);
	uint8_t hctl = max3421e_hctl_read();
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	max3421e_hctl_write(hctl | HCTL_SAMPLEBUS);
	max3421e_chip_deactivate(chip_num);

	max3421e_chip_activate(chip_num);
	uint8_t hrsl = max3421e_hrsl_read();
	max3421e_chip_deactivate(chip_num);
	/*
		(J,K)
		(0,0) - Single Ended Zero
		(0,1) - Low Speed
		(1,0) - Full Speed
		(1,1) - Single Ended One (Illegal state)
	*/

	switch (hrsl & (HRSL_JSTATUS | HRSL_KSTATUS)) {
		case HRSL_KSTATUS:
			max3421e_chip_activate(chip_num);
			uint8_t mode = max3421e_mode_read();
			max3421e_chip_deactivate(chip_num);

			max3421e_chip_activate(chip_num);
			max3421e_mode_write(mode | MODE_LOWSPEED);
			max3421e_chip_deactivate(chip_num);
#ifdef DEBUG
			printk(DEBUG, "Low speed device connected\r\n");
#endif
			return 1;

		case HRSL_JSTATUS:
#ifdef DEBUG
			printk(DEBUG, "Full speed device connected\r\n");
#endif
			return 2;

		case (HRSL_JSTATUS | HRSL_KSTATUS):
#ifdef DEBUG
			printk(DEBUG, "Bus illegal state\r\n");
#endif
			return 0;

		case 0x00:
#ifdef DEBUG
			printk(DEBUG, "Device not connected\r\n");
#endif
			return 0;
	}
	return 0;
}

int32_t max3421e_usb_device_set_address(uint32_t chip_num, uint8_t dev_addr)
{
	struct std_request set_addr = {0x0, 0x5, dev_addr, 0x0, 0x0};

	if (max3421e_usb_setup_send(chip_num, 0x00, &set_addr) != 0)
		return -1;
	mdelay(50);
	max3421e_usb_status_in_send(chip_num, 0x00);
	printk(DEBUG, "Device address is set\r\n");
	return 0;
}
