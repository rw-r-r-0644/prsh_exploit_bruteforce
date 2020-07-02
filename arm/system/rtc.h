/*
 * rtc.h
 * Functions for accessing the Wii U RTC.
 * 
 * Copyright (C) 2020 rw-r-r-0644
 * This file is under GNU GPL
 */

#pragma once

#include "common/types.h"


/* RTC registers. */
#define RTC_COUNTER		0x20000000
#define RTC_SRAM		0x20000100
#define RTC_SNAPSHOT	0x20400000
#define RTC_ONTMR		0x21000000
#define RTC_OFFTMR		0x21000100

#define RTC_CONTROL0	0x21000C00

#define RTC_CONTROL1	0x21000D00
	#define POFF_EXE		0x00010000
	#define DEVPWR_EN		0x00000400
	#define SLEEP_EN		0x00000100
	#define FPOFF_MODE		0x00000008
	#define CLKOUT_EN		0x00000004
	#define COUNT4_EN		0x00000001

/* Write to RTC register. */
void rtc_write(u32 reg, u32 data);

/* Read from RTC register. */
u32 rtc_read(u32 reg);

/* Write to RTC SRAM. */
void rtc_sram_write(u32 index, u32 value);

/* Read from RTC SRAM. */
u32 rtc_sram_read(u32 index);
