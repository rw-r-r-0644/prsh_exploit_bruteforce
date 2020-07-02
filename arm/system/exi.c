/*
 * exi.c
 * EXI functions and definitions.
 * 
 * Copyright (C) 2020 rw-r-r-0644
 * This file is under GNU GPL
 */

#include "exi.h"
#include "latte.h"
#include "common/utils.h"

void exi_initialize(void)
{
	set32(LT_EXICTRL, 1);
}
