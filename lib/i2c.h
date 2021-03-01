/**
 * @file	include/i2c.h
 *
 * @brief	Объявление функций работы с шиной I2C.
 *
 * @author	Vasily Yurchenko <vasily.v.yurchenko@yandex.ru>
 */

#ifndef _I2C_H_
#define _I2C_H_

#include "drivers.h"
#include <stddef.h>

/**
 * @brief  I2C1 Configuration
 */
void i2c_init(void);

int32_t i2c_read(uint8_t chip_addr, uint8_t reg_addr, uint8_t *buffer, size_t buffer_size);
int32_t i2c_stream(uint8_t *buffer, size_t buffer_size);
int32_t i2c_write(uint8_t chip_addr, uint8_t reg_addr, uint8_t *data, size_t data_size);

#endif /* _I2C_H_ */
