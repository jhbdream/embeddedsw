/******************************************************************************
*
* Copyright (C) 2015-2018 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*
*
******************************************************************************/

/*****************************************************************************/
/**
 * @file pm_clock.h
 *
 * PM Definitions of clocks - for xilpm internal purposes only
 *****************************************************************************/

#ifndef PM_CLOCKS_H_
#define PM_CLOCKS_H_

#include <xil_types.h>
#include <xstatus.h>
#include "pm_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

XStatus XPm_GetClockParentBySelect(const enum XPmClock clock,
				   const u32 select,
				   enum XPmClock* const parent);

XStatus XPm_GetSelectByClockParent(const enum XPmClock clock,
				   const enum XPmClock parent,
				   u32* const select);

u8 XPm_GetClockDivType(const enum XPmClock clock);

u8 XPm_MapDivider(const enum XPmClock clock,
		  const u32 div,
		  u32* const div0,
		  u32* const div1);

#ifdef __cplusplus
}
#endif

#endif /* PM_CLOCKS_H_ */
