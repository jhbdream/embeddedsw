/*
 * Copyright (C) 2017 - 2018 Xilinx, Inc.  All rights reserved.
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
 */
#include "xpfw_config.h"
#ifdef ENABLE_PM

#include "pm_hooks.h"
#include "pm_periph.h"
#include "pm_requirement.h"
#include "pm_qspi.h"

#ifdef ENABLE_POS
/**
 * These requirements are needed for the system in order to save DDR context
 * during Power Off Suspend. On ZCU102 board QSPI Flash memory device is used
 * for storing DDR context.
 */
PmPosRequirement pmPosDdrReqs_g[POS_DDR_REQS_SIZE] = {
	{
		.slave = &pmSlaveQSpi_g,
		.caps = PM_CAP_ACCESS,
	},
};

extern u8 __srdata_start;
extern u8 __srdata_end;

/**
 * PmHookPosSaveDdrContext() - User hook for saving context required for taking
 * 			       DDR out of self refresh after resume from Power
 * 			       Off Suspend
 *
 * @return	XST_SUCCESS if context is saved, failure code otherwise
 */
int PmHookPosSaveDdrContext(void)
{
	int status;
	u32 srDataStart = (u32)&__srdata_start;
	u32 srDataEnd = (u32)&__srdata_end;

	/* Initialize hardware required for QSPI operation */
	status = PmQspiHWInit();
	if (XST_SUCCESS != status) {
		goto done;
	}

	/* Initialize QSPI driver */
	status = PmQspiInit();
	if (XST_SUCCESS != status) {
		goto done;
	}

	/* Save data to QSPI */
	status = PmQspiWrite((u8*)srDataStart, srDataEnd - srDataStart);
	if (XST_SUCCESS != status) {
		goto done;
	}

done:
	return status;
}
#endif

#endif
