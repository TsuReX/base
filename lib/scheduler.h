/**
 * @file	include/scheduler.h
 *
 * @brief	Объявления функций для работы с диспетчером на основе таймера TIM6.
 *
 * @author	Vasily Yurchenko <vasily.v.yurchenko@yandex.ru>
 */

#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

/*
 *	@brief	Инициализирует подсистему диспетчирования на основе таймера TIM6.
 */
void scheduler_init(void);

/*
 *	@brief	Отключает таймер TIM6.
 */
void scheduler_close(void);

/*
 *	@brief	Выполняет необходимые операции через определенные нтервалы времени.
 *			Функция-заглушка. Определена в файле scheduler.c как слабая.
 *			Для выполнения необходимых
 *			операций по таймеру необходимо переобпределить функцию
 *			и размесить в ней вызовы соответствуюших команд.
 */
void scheduler_process(void);

#endif /* __SCHEDULER_H_ */
