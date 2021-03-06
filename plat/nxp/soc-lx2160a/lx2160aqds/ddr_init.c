/*
 * Copyright 2018-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <common/debug.h>
#include <ddr.h>
#include <lib/utils.h>
#include <load_img.h>

#include "plat_common.h"
#include <platform_def.h>

#ifdef CONFIG_STATIC_DDR

const struct ddr_cfg_regs static_3200 = {
	.cs[0].bnds = U(0x03FF),
	.cs[1].bnds = U(0x03FF),
	.cs[0].config = U(0x80050422),
	.cs[1].config = U(0x80000422),
	.cs[2].bnds = U(0x00),
	.cs[3].bnds = U(0x00),
	.cs[2].config = U(0x00),
	.cs[3].config = U(0x00),
	.timing_cfg[0] = U(0xFFAA0018),
	.timing_cfg[1] = U(0x646A8844),
	.timing_cfg[2] = U(0x00058022),
	.timing_cfg[3] = U(0x13622100),
	.timing_cfg[4] = U(0x02),
	.timing_cfg[5] = U(0x07401400),
	.timing_cfg[7] = U(0x3BB00000),
	.timing_cfg[8] = U(0x0944AC00),
	.sdram_cfg[0] = U(0x65044008),
	.sdram_cfg[1] = U(0x00401011),
	.sdram_cfg[2] = U(0x00),
	.sdram_mode[0] = U(0x06010C50),
	.sdram_mode[1] = U(0x00280400),
	.sdram_mode[2] = U(0x00),
	.sdram_mode[3] = U(0x00),
	.sdram_mode[4] = U(0x00),
	.sdram_mode[5] = U(0x00),
	.sdram_mode[6] = U(0x00),
	.sdram_mode[7] = U(0x00),
	.sdram_mode[8] = U(0x0500),
	.sdram_mode[9] = U(0x10240000),
	.sdram_mode[10] = U(0x00),
	.sdram_mode[11] = U(0x00),
	.sdram_mode[12] = U(0x00),
	.sdram_mode[13] = U(0x00),
	.sdram_mode[14] = U(0x00),
	.sdram_mode[15] = U(0x00),
	.md_cntl = U(0x00),
	.interval = U(0x30C00000),
	.data_init = U(0xDEADBEEF),
	.init_addr = U(0x00),
	.zq_cntl = U(0x8A090705),
	.sdram_rcw[0] = U(0x00),
	.sdram_rcw[1] = U(0x00),
	.sdram_rcw[2] = U(0x00),
	.sdram_rcw[3] = U(0x00),
	.sdram_rcw[4] = U(0x00),
	.sdram_rcw[5] = U(0x00),
	.err_disable = U(0x00),
	.err_int_en = U(0x00),
};

const struct ddr_cfg_regs static_2900 = {
	.cs[0].bnds = U(0x03FF),
	.cs[1].bnds = U(0x03FF),
	.cs[0].config = U(0x80050422),
	.cs[1].config = U(0x80000422),
	.cs[2].bnds = U(0x00),
	.cs[3].bnds = U(0x00),
	.cs[2].config = U(0x00),
	.cs[3].config = U(0x00),
	.timing_cfg[0] = U(0xFF990018),
	.timing_cfg[1] = U(0x4F4A4844),
	.timing_cfg[2] = U(0x0005601F),
	.timing_cfg[3] = U(0x125F2100),
	.timing_cfg[4] = U(0x02),
	.timing_cfg[5] = U(0x07401400),
	.timing_cfg[7] = U(0x3AA00000),
	.timing_cfg[8] = U(0x09449B00),
	.sdram_cfg[0] = U(0x65044008),
	.sdram_cfg[1] = U(0x00401011),
	.sdram_cfg[2] = U(0x00),
	.sdram_mode[0] = U(0x06010C50),
	.sdram_mode[1] = U(0x00280400),
	.sdram_mode[2] = U(0x00),
	.sdram_mode[3] = U(0x00),
	.sdram_mode[4] = U(0x00),
	.sdram_mode[5] = U(0x00),
	.sdram_mode[6] = U(0x00),
	.sdram_mode[7] = U(0x00),
	.sdram_mode[8] = U(0x0500),
	.sdram_mode[9] = U(0x10240000),
	.sdram_mode[10] = U(0x00),
	.sdram_mode[11] = U(0x00),
	.sdram_mode[12] = U(0x00),
	.sdram_mode[13] = U(0x00),
	.sdram_mode[14] = U(0x00),
	.sdram_mode[15] = U(0x00),
	.md_cntl = U(0x00),
	.interval = U(0x2C2E0000),
	.data_init = U(0xDEADBEEF),
	.init_addr = U(0x00),
	.zq_cntl = U(0x8A090705),
	.sdram_rcw[0] = U(0x00),
	.sdram_rcw[1] = U(0x00),
	.sdram_rcw[2] = U(0x00),
	.sdram_rcw[3] = U(0x00),
	.sdram_rcw[4] = U(0x00),
	.sdram_rcw[5] = U(0x00),
	.err_disable = U(0x00),
	.err_int_en = U(0x00),
};

const struct ddr_cfg_regs static_2600 = {
	.cs[0].bnds = U(0x03FF),
	.cs[1].bnds = U(0x03FF),
	.cs[0].config = U(0x80050422),
	.cs[1].config = U(0x80000422),
	.cs[2].bnds = U(0x00),
	.cs[3].bnds = U(0x00),
	.cs[2].config = U(0x00),
	.cs[3].config = U(0x00),
	.timing_cfg[0] = U(0xFF880018),
	.timing_cfg[1] = U(0x2A24F444),
	.timing_cfg[2] = U(0x007141DC),
	.timing_cfg[3] = U(0x125B2100),
	.timing_cfg[4] = U(0x02),
	.timing_cfg[5] = U(0x06401400),
	.timing_cfg[7] = U(0x28800000),
	.timing_cfg[8] = U(0x07338A00),
	.sdram_cfg[0] = U(0x65044008),
	.sdram_cfg[1] = U(0x00401011),
	.sdram_cfg[2] = U(0x00),
	.sdram_mode[0] = U(0x06010A70),
	.sdram_mode[1] = U(0x00200400),
	.sdram_mode[2] = U(0x00),
	.sdram_mode[3] = U(0x00),
	.sdram_mode[4] = U(0x00),
	.sdram_mode[5] = U(0x00),
	.sdram_mode[6] = U(0x00),
	.sdram_mode[7] = U(0x00),
	.sdram_mode[8] = U(0x0500),
	.sdram_mode[9] = U(0x0C240000),
	.sdram_mode[10] = U(0x00),
	.sdram_mode[11] = U(0x00),
	.sdram_mode[12] = U(0x00),
	.sdram_mode[13] = U(0x00),
	.sdram_mode[14] = U(0x00),
	.sdram_mode[15] = U(0x00),
	.md_cntl = U(0x00),
	.interval = U(0x279C0000),
	.data_init = U(0xDEADBEEF),
	.init_addr = U(0x00),
	.zq_cntl = U(0x8A090705),
	.sdram_rcw[0] = U(0x00),
	.sdram_rcw[1] = U(0x00),
	.sdram_rcw[2] = U(0x00),
	.sdram_rcw[3] = U(0x00),
	.sdram_rcw[4] = U(0x00),
	.sdram_rcw[5] = U(0x00),
	.err_disable = U(0x00),
	.err_int_en = U(0x00),
};

const struct dimm_params static_dimm = {
	.rdimm = U(0),
	.primary_sdram_width = U(64),
	.ec_sdram_width = U(8),
	.n_ranks = U(2),
	.device_width = U(8),
	.mirrored_dimm = U(1),
};

/* Sample code using two UDIMM MT18ASF1G72AZ-2G6B1, on each DDR controller */
long long board_static_ddr(struct ddr_info *priv)
{
	memcpy(&priv->ddr_reg, &static_2900, sizeof(static_2900));
	memcpy(&priv->dimm, &static_dimm, sizeof(static_dimm));
	priv->conf.cs_on_dimm[0] = 0x3;
	ddr_board_options(priv);
	compute_ddr_phy(priv);

	return ULL(0x400000000);
}

#elif defined(CONFIG_DDR_NODIMM)
/*
 * Sample code to bypass reading SPD. This is a sample, not recommended
 * for boards with slots. DDR model number: UDIMM MT18ASF1G72AZ-2G6B1.
 */

const struct dimm_params ddr_raw_timing = {
	.n_ranks = U(2),
	.rank_density = U(4294967296u),
	.capacity = U(8589934592u),
	.primary_sdram_width = U(64),
	.ec_sdram_width = U(8),
	.device_width = U(8),
	.die_density = U(0x4),
	.rdimm = U(0),
	.mirrored_dimm = U(1),
	.n_row_addr = U(15),
	.n_col_addr = U(10),
	.bank_addr_bits = U(0),
	.bank_group_bits = U(2),
	.edc_config = U(2),
	.burst_lengths_bitmask = U(0x0c),
	.tckmin_x_ps = 750,
	.tckmax_ps = 1600,
	.caslat_x = U(0x00FFFC00),
	.taa_ps = 13750,
	.trcd_ps = 13750,
	.trp_ps = 13750,
	.tras_ps = 32000,
	.trc_ps = 457500,
	.twr_ps = 15000,
	.trfc1_ps = 260000,
	.trfc2_ps = 160000,
	.trfc4_ps = 110000,
	.tfaw_ps = 21000,
	.trrds_ps = 3000,
	.trrdl_ps = 4900,
	.tccdl_ps = 5000,
	.refresh_rate_ps = U(7800000),
};

int ddr_get_ddr_params(struct dimm_params *pdimm,
			    struct ddr_conf *conf)
{
	static const char dimm_model[] = "Fixed DDR on board";

	conf->dimm_in_use[0] = 1;	/* Modify accordingly */
	memcpy(pdimm, &ddr_raw_timing, sizeof(struct dimm_params));
	memcpy(pdimm->mpart, dimm_model, sizeof(dimm_model) - 1);

	/* valid DIMM mask, change accordingly, together with dimm_on_ctlr. */
	return 0x5;
}
#endif	/* CONFIG_DDR_NODIMM */

int ddr_board_options(struct ddr_info *priv)
{
	struct memctl_opt *popts = &priv->opt;
	const struct ddr_conf *conf = &priv->conf;

	/* vref_dimm: value of this this field is reflected in sdram_mode[9]
	 * in upper 16 bits. This value is also the part of phy register MR6
	 * This is used for range selection and its corresponding value.
	 */
	popts->vref_dimm = U(0x24);		/* range 1, 83.4% */

	/* rtt_override: allows to override the cs.odt_rtt_norm, cs.odt_rtt_wr
	 *
	 * cs.odt_rtt_norm is reflected in sdram_mode 0[24..26] and the same
	 * value is reflected as phy MR1 value also. This is 3 bit value.
	 * Overriden value must be given as popts->rtt_override_value.
	 * Valid set of values:
	 * 	DDR4_RTT_OFF            0
	 * 	DDR4_RTT_60_OHM         1
	 *	DDR4_RTT_120_OHM        2
	 *	DDR4_RTT_40_OHM         3
	 *	DDR4_RTT_240_OHM        4
	 *	DDR4_RTT_48_OHM         5
	 *	DDR4_RTT_80_OHM         6
	 *	DDR4_RTT_34_OHM         7
	 */
	popts->rtt_override = 0;

	/* Dram driver strength: Is defined in the MR1 phy register bit[1..2]
	 * and sdram_mode 0[17..18]. This is a 2 bit value meaning as below:
	 *
	 * 00 (full 34 ohm)
	 * 01 (half 48 ohm)
	 *
	 * Default value is set to 0. To change it to 1 use below two options
	 * (whichever is true.)
	 * Set quad_rank_present or output_driver_impedance to 1
	 * popts->quad_rank_present = 1 or popts->output_driver_impedance = 1
	 */
	popts->output_driver_impedance = 0;

	/* rtt_park: the value of rtt_park is set in sdram_mode 8[6..8]. And the
	 * same value is used in MR5[A8:A6]. Below are valid values (in ohm):
	 * 0x0 -disable
	 * 0x1 -60
	 * 0x2 -120
	 * 0x3 -40
	 * 0x4 -240
	 * 0x5 -48
	 * 0x6 -80
	 * 0x7 -34
	 * Note: If the value is not defined then the default 0x4 is considered
	 * by SW.
	 */
	popts->rtt_park = U(240);

	popts->otf_burst_chop_en = 0;
	popts->burst_length = U(DDR_BL8);
	popts->bstopre = U(0);			/* auto precharge */
	popts->addr_hash = 1;

	/* trwt_override is used to override the turnaround timing values.
	 * It overrides following timing parameters
	 * trwt - read - write turnaround timing
	 * twrt - write - read turnaround timing
	 * trrt - read - read turnaround timing
	 * twwt - write - write turnaround timing
	 *
	 * Values are progrmamed using respective parameters:
	 * popts->trwt, popts->twrt, popts->trrt, popts->twwt
	 * These values are programmed in below switch case.
	 */
	popts->trwt_override = U(1);

	/*
	 * Various other phy parameters are also defined in this file
	 * such as:
	 * PHY Data bus driver impedance: value is defined in popts->tx_impedance
	 * 	If not defined default is 28 ohm
	 * 	Valid values (in ohm): 000001 - 480.0, 240.0, 160.0, 120.0,
	 * 	96.0, 80.0, 68.6, 60.0, 53.3, 48.0, 43.6, 40.0, 36.9, 34.3,
	 * 	32.0, 30.0, 28.2
	 * PHY C/A bus driver impedance: value is defined in popts->atx_impedance
	 * 	If not defined default is 30 ohm
	 * 	Valid values (in ohm): 120.0, 60.0, 40.0, 30.0, 24.0, 20.0 Ohm
	 * PHY ODT: value is defined in popts->odt
	 * 	If not defined default is 60 ohm
	 * 	Valid values (in ohm): 000001 - 480.0, 240.0, 160.0, 120.0,
	 * 	96.0, 80.0, 68.6, 60.0, 53.3, 48.0, 43.6, 40.0, 36.9, 34.3,
	 * 	32.0, 30.0, 28.2
	 * PHY Vref: value is defined in popts->vref_phy
	 *	if not defined default value is 0x61
	 *	Value programmed in register is calculated as:
	 *	(input_value * 1000 - 345 * 128 + 320) / (5 * 128);
	 *
	 * Above mentioned settings are set in the below code, user can change
	 * according to their board/DRAM configuration needs.
	 */

	/* Set ODT impedance on PHY side */
	switch (conf->cs_on_dimm[1]) {
	case 0xc:	/* Two slots dual rank */
	case 0x4:	/* Two slots single rank, not valid for interleaving */
		popts->trwt = U(0xf);
		popts->twrt = U(0x7);
		popts->trrt = U(0x7);
		popts->twwt = U(0x7);
		popts->vref_phy = U(0x6B);	/* 83.6% */
		popts->odt = U(60);
		popts->phy_tx_impedance = U(28);
		break;
	case 0:		/* Ont slot used */
	default:
		popts->trwt = U(0x3);
		popts->twrt = U(0x3);
		popts->trrt = U(0x3);
		popts->twwt = U(0x3);
		popts->vref_phy = U(0x60);	/* 75% */
		popts->odt = U(48);
		popts->phy_tx_impedance = U(28);
		break;
	}

	return 0;
}

#ifdef NXP_WARM_BOOT
long long init_ddr(uint32_t wrm_bt_flg)
#else
long long init_ddr(void)
#endif
{
	int spd_addr[] = { 0x51, 0x52, 0x53, 0x54 };
	struct ddr_info info;
	struct sysinfo sys;
	long long dram_size;

	zeromem(&sys, sizeof(sys));
	if (get_clocks(&sys) == 1) {
		ERROR("System clocks are not set\n");
		assert(0);
	}
	debug("platform clock %lu\n", sys.freq_platform);
	debug("DDR PLL1 %lu\n", sys.freq_ddr_pll0);
	debug("DDR PLL2 %lu\n", sys.freq_ddr_pll1);

	zeromem(&info, sizeof(info));

	/* Set two DDRC. Unused DDRC will be removed automatically. */
	info.num_ctlrs = NUM_OF_DDRC;
	info.spd_addr = spd_addr;
	info.ddr[0] = (void *)NXP_DDR_ADDR;
	info.ddr[1] = (void *)NXP_DDR2_ADDR;
	info.phy[0] = (void *)NXP_DDR_PHY1_ADDR;
	info.phy[1] = (void *)NXP_DDR_PHY2_ADDR;
	info.clk = get_ddr_freq(&sys, 0);
	info.img_loadr = load_img;
	info.phy_gen2_fw_img_buf = PHY_GEN2_FW_IMAGE_BUFFER;
	if (info.clk == 0) {
		info.clk = get_ddr_freq(&sys, 1);
	}
	info.dimm_on_ctlr = DDRC_NUM_DIMM;

	info.warm_boot_flag = DDR_WRM_BOOT_NT_SUPPORTED;
#ifdef NXP_WARM_BOOT
	if (wrm_bt_flg) {
		info.warm_boot_flag = DDR_WARM_BOOT;
	} else if (wrm_bt_flg == 0x0) {
		info.warm_boot_flag = DDR_COLD_BOOT;
	}
#endif

	dram_size = dram_init(&info
#if defined(NXP_HAS_CCN504) || defined(NXP_HAS_CCN508)
		    , NXP_CCN_HN_F_0_ADDR
#endif
		    );


	if (dram_size < 0)
		ERROR("DDR init failed.\n");

	return dram_size;
}
