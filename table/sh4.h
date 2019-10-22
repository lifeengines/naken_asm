/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2019 by Michael Kohn
 *
 */

#ifndef NAKEN_ASM_TABLE_SH4_H
#define NAKEN_ASM_TABLE_SH4_H

#include "common/assembler.h"

enum
{
  OP_NONE,
  OP_REG_REG,
};

struct _table_sh4
{
  char *instr;
  uint16_t opcode;
  uint16_t mask;
  uint8_t type;
};

extern struct _table_sh4 table_sh4[];

#endif

