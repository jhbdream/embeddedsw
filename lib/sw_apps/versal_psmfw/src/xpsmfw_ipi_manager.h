/******************************************************************************
* Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
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
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xpsmfw_ipi_manager.h
*
* This file contains definitions for IPI manager
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver	Who		Date		Changes
* ---- ---- -------- ------------------------------
* 1.00  ma   04/09/2018 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef XPSMFW_IPI_MANAGER_H_
#define XPSMFW_IPI_MANAGER_H_

#include "xparameters.h"

#ifdef XPAR_PSU_IPI_PSM_DEVICE_ID
#include "xpsmfw_default.h"
#include "xipipsu.h"

/* Instance of IPI Driver */
//extern XIpiPsu *IpiInstPtr;

#define XPSMFW_IPI_MASK_COUNT 	XIPIPSU_MAX_TARGETS
extern u32 IpiMaskList[XPSMFW_IPI_MASK_COUNT];

#define XPSMFW_IPI_MAX_MSG_LEN XIPIPSU_MAX_MSG_LEN

#ifdef XPAR_XIPIPS_TARGET_PSU_PMC_0_CH0_MASK
#define IPI_PSM_IER_PMC_MASK	  XPAR_XIPIPS_TARGET_PSU_PMC_0_CH0_MASK
#else
#define IPI_PSM_IER_PMC_MASK 0U
#endif

/**
 * Initialize the IPI driver instance
 * This should be called in the core init
 */
s32 XPsmfw_IpiManagerInit(void);

int XPsmFw_DispatchIpiHandler(u32 SrcMask);
#endif

#endif /* XPSMFW_IPI_MANAGER_H_ */