/*
 * rtc.c
 * Functions for accessing the Wii U RTC.
 * 
 * Copyright (C) 2020 rw-r-r-0644
 * This file is under GNU GPL
 */

#include "common/utils.h"
#include "common/types.h"
#include "rtc.h"
#include "latte.h"
#include "exi.h"

/* EXI registers config to access the RTC. */
#define RTC_EXICSR		(EXICSR_DEV1 | EXICSR_CLK_1MHZ | EXICSR_INTSET)
#define RTC_EXICR_W		(EXICR_TSTART | EXICR_TRSMODE_IMM | EXICR_TRSTYPE_W | EXICR_TLEN32)
#define RTC_EXICR_R		(EXICR_TSTART | EXICR_TRSMODE_IMM | EXICR_TRSTYPE_R | EXICR_TLEN32)

void SRAM_TEXT rtc_write(u32 reg, u32 data)
{
	/* Write register offset */
	write32(EXI0_CSR, RTC_EXICSR);
	write32(EXI0_DATA, reg | 0x80000000);
	write32(EXI0_CR, RTC_EXICR_W);
	while(!(read32(EXI0_CSR) & EXICSR_INTSET));

	/* Write data */
	write32(EXI0_CSR, RTC_EXICSR);
	write32(EXI0_DATA, data);
	write32(EXI0_CR, RTC_EXICR_W);
	while(!(read32(EXI0_CSR) & EXICSR_INTSET));

	/* Clear channel parameters */
	write32(EXI0_CSR, 0);
}

u32 SRAM_TEXT rtc_read(u32 reg)
{
	u32 data;

	/* Write register offset */
	write32(EXI0_CSR, RTC_EXICSR);
	write32(EXI0_DATA, reg);
	write32(EXI0_CR, RTC_EXICR_W);
	while(!(read32(EXI0_CSR) & EXICSR_INTSET));

	/* Read data */
	write32(EXI0_CSR, RTC_EXICSR);
	write32(EXI0_CR, RTC_EXICR_R);
	while(!(read32(EXI0_CSR) & EXICSR_INTSET));
	data = read32(EXI0_DATA);

	/* Clear channel parameters */
	write32(EXI0_CSR, 0);

	return data;
}

void rtc_sram_write(u32 index, u32 value)
{
	rtc_write(RTC_SRAM + 0x100 * index, value);
}

u32 rtc_sram_read(u32 index)
{
	return rtc_read(RTC_SRAM + 0x100 * index);
}
