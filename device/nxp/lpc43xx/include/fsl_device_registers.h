/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))

#define LPC54608_SERIES

/* CMSIS-style register definitions */
#include "LPC54608.h"
/* CPU specific feature definitions */
#include "LPC54608_features.h"

#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))

#define LPC54618_SERIES

/* CMSIS-style register definitions */
#include "LPC54618.h"
/* CPU specific feature definitions */
#include "LPC54618_features.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
