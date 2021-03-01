/*
 * systimer.h
 *
 *  Created on: Feb 9, 2021
 *      Author: user
 */

#ifndef INCLUDE_SYSTIMER_H_
#define INCLUDE_SYSTIMER_H_

#include <stdint.h>

/* TODO: Продумать, куда можно перенести функцию */
void get_system_ticks(uint64_t *sys_ticks);

/* TODO: Продумать, куда можно перенести функцию */
void get_system_tick_period(uint32_t *sys_period);

void systimer_init(uint32_t core_freq, uint32_t period);

#endif /* INCLUDE_SYSTIMER_H_ */
