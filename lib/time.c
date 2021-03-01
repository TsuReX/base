/*
 * utils.c
 *
 *  Created on: Oct 2, 2020
 *      Author: user
 */


#include "time.h"
//#include "drivers.h"

void period_start(struct period *per, uint32_t usec_period)
{
	uint32_t system_tick_period = 0;
	uint64_t system_ticks = 0;

	get_system_tick_period(&system_tick_period);
	uint32_t period_ticks = (usec_period + (system_tick_period / 2)) / system_tick_period;

	if (period_ticks == 0)
		period_ticks = 1;

	per->usec_period = usec_period;
	get_system_ticks(&system_ticks);
	per->next_system_ticks = system_ticks + period_ticks;
}

uint32_t is_period_expired(struct period *per, uint32_t restart)
{
	uint64_t system_ticks = 0;
	uint32_t expired = 0;

	get_system_ticks(&system_ticks);

	if (system_ticks > per->next_system_ticks) {
		expired = 1;

		if (restart == 1)
			period_start(per, per->usec_period);
	}

	return expired;
}

/**
 * @brief	Выполняет активную задержку
 *
 * @param[in]	useconds	количество микросекунд задержки,
 * 							по факту длительность задержки
 * 							может быть кратна только значению system_period
 */
void udelay(uint32_t useconds)
{
	uint32_t system_tick_period = 0;
	uint64_t system_ticks = 0;

	get_system_tick_period(&system_tick_period);

	uint32_t ticks = (useconds + (system_tick_period / 2)) / system_tick_period;
	if (ticks == 0)
		++ticks;
#if 1
	/* Disable interrupt */
	get_system_ticks(&system_ticks);
	uint64_t next_tick = system_ticks + ticks;
	/* Enable interrupt */
#else
	/* Исходить из соображения, что задержка должна уложится в 32 разряда. */
	uint32_t next_tick = system_ticks + ticks;
#endif
	while (next_tick > system_ticks)
		get_system_ticks(&system_ticks);
}

void mdelay(uint32_t mseconds)
{
	udelay(mseconds * 1000);
}

void u100delay(uint32_t u100seconds)
{
	udelay(u100seconds * 100);
}
