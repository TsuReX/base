/**
 * @file	include/config.h
 *
 * @brief	Объявление функций инициализации SoC и периферии.
 *
 * @author	Vasily Yurchenko <vasily.v.yurchenko@yandex.ru>
 */

#ifndef _INIT_H_
#define _INIT_H_

#include <stdint.h>

#if 0
/* TODO: Продумать, куда можно перенести функцию */
void get_system_ticks(uint64_t *sys_ticks);

/* TODO: Продумать, куда можно перенести функцию */
void get_system_tick_period(uint32_t *sys_period);
#endif

/**
 * @brief	Инициализирует устройства и подсистемы внутри SoC.
 */
void soc_init(void);

/**
 * @brief	Инициализирует устройства платформы.
 */
void board_init(void);


#endif /* _INIT_H_ */
