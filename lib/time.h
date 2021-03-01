/*
 * utils.h
 *
 *  Created on: Oct 2, 2020
 *      Author: user
 */

#ifndef DELAY_H_
#define DELAY_H_

#include <stdint.h>

#include "systimer.h"

#define NOT_RESTART_PERIOD	0
#define RESTART_PERIOD		1

struct period {
	uint64_t	next_system_ticks;
	uint32_t	usec_period;
};

void period_start(struct period *per, uint32_t usec_period);
uint32_t is_period_expired(struct period *per, uint32_t restart);

/**
 * @brief	Выполняет активную задержку
 *
 * @param[in]	useconds	количество микросекунд задержки,
 * 							по факту длительность задержки
 * 							может быть кратна только значению system_period
 */
void udelay(uint32_t useconds);
void mdelay(uint32_t mseconds);
void u100delay(uint32_t u100seconds);

#endif /* DELAY_H_ */
