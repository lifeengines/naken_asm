/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2013 by Michael Kohn
 *
 */

#ifndef _TABLE_TMS9900_H
#define _TABLE_TMS9900_H

#include "assembler.h"

enum
{
  OP_CRU_MULTIBIT,
  OP_CRU_SINGLEBIT,
  OP_DUAL,
  OP_DUAL_MULTIPLE,
  OP_EXTERNAL,
  OP_IMMEDIATE,
  OP_INT_REG_LD,
  OP_INT_REG_ST,
  OP_JUMP,
  OP_RTWP,
  OP_SHIFT,
  OP_SINGLE,
  OP_XOP,
};

struct _table_tms9900
{
  char *instr;
  unsigned short int opcode;
  unsigned char type;
  unsigned char cycles_min;
  unsigned char cycles_max;
};

extern struct _table_tms9900 table_tms9900[];

#endif


