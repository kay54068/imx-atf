/*
 * Copyright 2018-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include <common/debug.h>
#include <dcfg.h>
#include <drivers/arm/pl011.h>
#include <drivers/console.h>
#include <lib/utils.h>

/*
 * Perform arm specific early platform setup. At this moment we only initialize
 * the console and the memory layout.
 */
void plat_console_init(uintptr_t nxp_console_addr, uint32_t uart_clk_div,
			uint32_t baud)
{
	struct sysinfo sys;
	static console_t nxp_console;

	zeromem(&sys, sizeof(sys));
	if (get_clocks(&sys)) {
		ERROR("System clocks are not set\n");
		assert(0);
	}

	console_pl011_register(nxp_console_addr,
			      (sys.freq_platform/uart_clk_div),
			       baud, &nxp_console);
}
