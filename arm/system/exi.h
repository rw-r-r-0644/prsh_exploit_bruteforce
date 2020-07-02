/*
 * exi.h
 * EXI functions and definitions.
 * 
 * Copyright (C) 2020 rw-r-r-0644
 * This file is under GNU GPL
 */

#define EXICSR_DEV		0x380
	#define EXICSR_DEV1			0x100
#define EXICSR_CLK		0x070
	#define EXICSR_CLK_1MHZ		0x000
	#define EXICSR_CLK_8MHZ		0x030
#define EXICSR_INT		0x008
	#define EXICSR_INTSET		0x008
    
#define EXICR_TSTART	0x001
#define EXICR_TRSMODE	0x002
	#define EXICR_TRSMODE_IMM	0x000
#define EXICR_TRSTYPE	0x00C
	#define EXICR_TRSTYPE_R		0x000
	#define EXICR_TRSTYPE_W		0x004
#define EXICR_TLEN		0x030
	#define EXICR_TLEN32		0x030

void exi_initialize(void);
