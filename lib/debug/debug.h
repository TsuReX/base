/*
 * debug.h
 *
 *  Created on: Nov 18, 2020
 *      Author: vasily
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "stdint.h"

#define DEBUG	0
#define INFO	1
#define ERR		1
#define CRIT	2
#define NONE	15

#if defined(DBG_OUT)

uint32_t log_level_get(void);
void log_level_set(uint32_t log_level);
void printk(uint32_t debug_level, const char *format, ...) __attribute__((format(printf, 2, 3)));

#else

static inline void log_level_set(uint32_t log_level) {}
static inline uint32_t log_level_get(void) {return NONE;}
static inline void printk(uint32_t debug_level, const char *format, ...) {}

#endif

#endif /* INCLUDE_DEBUG_H_ */
