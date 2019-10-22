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

#include "cpu_list.h"

#include "asm/1802.h"
#include "asm/4004.h"
#include "asm/6502.h"
#include "asm/65816.h"
#include "asm/6800.h"
#include "asm/6809.h"
#include "asm/68hc08.h"
#include "asm/68000.h"
#include "asm/8051.h"
#include "asm/arc.h"
#include "asm/arm.h"
#include "asm/avr8.h"
#include "asm/cell.h"
#include "asm/cp1610.h"
#include "asm/common.h"
#include "asm/copper.h"
#include "asm/dotnet.h"
#include "asm/dspic.h"
#include "asm/epiphany.h"
#include "asm/java.h"
#include "asm/lc3.h"
#include "asm/mcs48.h"
#include "asm/mips.h"
#include "asm/msp430.h"
#include "asm/pdp8.h"
#include "asm/pic14.h"
#include "asm/powerpc.h"
#include "asm/propeller.h"
#include "asm/ps2_ee_vu.h"
#include "asm/riscv.h"
#include "asm/sh4.h"
#include "asm/stm8.h"
#include "asm/super_fx.h"
#include "asm/sweet16.h"
#include "asm/thumb.h"
#include "asm/tms1000.h"
#include "asm/tms9900.h"
#include "asm/webasm.h"
#include "asm/xtensa.h"
#include "asm/z80.h"
#include "disasm/1802.h"
#include "disasm/4004.h"
#include "disasm/6502.h"
#include "disasm/65816.h"
#include "disasm/6800.h"
#include "disasm/6809.h"
#include "disasm/68hc08.h"
#include "disasm/68000.h"
#include "disasm/8051.h"
#include "disasm/arc.h"
#include "disasm/arm.h"
#include "disasm/avr8.h"
#include "disasm/cell.h"
#include "disasm/copper.h"
#include "disasm/cp1610.h"
#include "disasm/dotnet.h"
#include "disasm/dspic.h"
#include "disasm/epiphany.h"
#include "disasm/java.h"
#include "disasm/lc3.h"
#include "disasm/mcs48.h"
#include "disasm/mips.h"
#include "disasm/msp430.h"
#include "disasm/pdp8.h"
#include "disasm/pic14.h"
#include "disasm/powerpc.h"
#include "disasm/propeller.h"
#include "disasm/ps2_ee_vu.h"
#include "disasm/riscv.h"
#include "disasm/sh4.h"
#include "disasm/stm8.h"
#include "disasm/super_fx.h"
#include "disasm/sweet16.h"
#include "disasm/thumb.h"
#include "disasm/tms1000.h"
#include "disasm/tms9900.h"
#include "disasm/webasm.h"
#include "disasm/xtensa.h"
#include "disasm/z80.h"
#include "simulate/1802.h"
#include "simulate/6502.h"
#include "simulate/65816.h"
#include "simulate/avr8.h"
#include "simulate/lc3.h"
#include "simulate/mips.h"
#include "simulate/msp430.h"
#include "simulate/stm8.h"
#include "simulate/tms9900.h"
#include "simulate/z80.h"

#define NO_FLAGS 0

int link_not_supported(
  struct _asm_context *asm_context,
  struct _imports *imports,
  const uint8_t *code,
  uint32_t function_offset,
  int size,
  uint8_t *obj_file,
  uint32_t obj_size)
{
  printf("Error: This platform doesn't support linking.\n");
  return -1;
}

struct _cpu_list cpu_list[] =
{
#ifdef ENABLE_MSP430
  {
    "msp430",
    CPU_TYPE_MSP430,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_msp430,
    NULL,
    link_function_msp430,
    list_output_msp430,
    disasm_range_msp430,
    simulate_init_msp430,
    NO_FLAGS,
  },
  {
    "msp430x",
    CPU_TYPE_MSP430X,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    0,
    0,
    SREC_24,
    parse_instruction_msp430,
    NULL,
    link_not_supported,
    list_output_msp430x,
    disasm_range_msp430x,
    simulate_init_msp430,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_1802
  {
    "1802",
    CPU_TYPE_1802,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_1802,
    NULL,
    link_not_supported,
    list_output_1802,
    disasm_range_1802,
    simulate_init_1802,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_4004
  {
    "4004",
    CPU_TYPE_4004,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_4004,
    NULL,
    link_not_supported,
    list_output_4004,
    disasm_range_4004,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6502
  {
    "6502",
    CPU_TYPE_6502,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_6502,
    NULL,
    link_not_supported,
    list_output_6502,
    disasm_range_6502,
    simulate_init_6502,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_65816
  {
    "65816",
    CPU_TYPE_65816,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_65816,
    NULL,
    link_not_supported,
    list_output_65816,
    disasm_range_65816,
    simulate_init_65816,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6800
  {
    "6800",
    CPU_TYPE_6800,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_6800,
    NULL,
    link_not_supported,
    list_output_6800,
    disasm_range_6800,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_6809
  {
    "6809",
    CPU_TYPE_6809,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_6809,
    NULL,
    link_not_supported,
    list_output_6809,
    disasm_range_6809,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_68HC08
  {
    "68hc08",
    CPU_TYPE_68HC08,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_68hc08,
    NULL,
    link_not_supported,
    list_output_68hc08,
    disasm_range_68hc08,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_68000
  {
    "68000",
    CPU_TYPE_68000,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    1,
    0,
    1,
    0,
    0,
    SREC_32,
    parse_instruction_68000,
    NULL,
    link_not_supported,
    list_output_68000,
    disasm_range_68000,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_8051
  {
    "8051",
    CPU_TYPE_8051,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_8051,
    NULL,
    link_not_supported,
    list_output_8051,
    disasm_range_8051,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_ARC
  {
    "arc",
    CPU_TYPE_ARC,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_arc,
    NULL,
    link_not_supported,
    list_output_arc,
    disasm_range_arc,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_ARM
  {
    "arm",
    CPU_TYPE_ARM,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_arm,
    NULL,
    link_not_supported,
    list_output_arm,
    disasm_range_arm,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_AVR8
  {
    "avr8",
    CPU_TYPE_AVR8,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_avr8,
    NULL,
    link_not_supported,
    list_output_avr8,
    disasm_range_avr8,
    simulate_init_avr8,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_CELL
  {
    "cell",
    CPU_TYPE_CELL,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_cell,
    NULL,
    link_not_supported,
    list_output_cell,
    disasm_range_cell,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_COPPER
  {
    "copper",
    CPU_TYPE_COPPER,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_copper,
    NULL,
    link_not_supported,
    list_output_copper,
    disasm_range_copper,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_CP1610
  {
    "cp1610",
    CPU_TYPE_CP1610,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_cp1610,
    NULL,
    link_not_supported,
    list_output_cp1610,
    disasm_range_cp1610,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DOTNET
  {
    "dotnet",
    CPU_TYPE_DOTNET,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    0,
    SREC_16,
    parse_instruction_dotnet,
    NULL,
    link_not_supported,
    list_output_dotnet,
    disasm_range_dotnet,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DSPIC
  {
    "dspic",
    CPU_TYPE_DSPIC,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_dspic,
    NULL,
    link_not_supported,
    list_output_dspic,
    disasm_range_dspic,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_EPIPHANY
  {
    "epiphany",
    CPU_TYPE_EPIPHANY,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    1,
    0,
    0,
    SREC_32,
    parse_instruction_epiphany,
    NULL,
    link_not_supported,
    list_output_epiphany,
    disasm_range_epiphany,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_JAVA
  {
    "java",
    CPU_TYPE_JAVA,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_java,
    NULL,
    link_not_supported,
    list_output_java,
    disasm_range_java,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_LC3
  {
    "lc3",
    CPU_TYPE_LC3,
    ENDIAN_BIG,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_lc3,
    NULL,
    link_not_supported,
    list_output_lc3,
    disasm_range_lc3,
    simulate_init_lc3,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_MCS48
  {
    "MCS48",
    CPU_TYPE_MCS48,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_mcs48,
    NULL,
    link_not_supported,
    list_output_mcs48,
    disasm_range_mcs48,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_MIPS
  {
    "mips",
    CPU_TYPE_MIPS32,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    simulate_init_mips,
    MIPS_I | MIPS_II | MIPS_III,
  },
  {
    "mips32",
    CPU_TYPE_MIPS32,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    simulate_init_mips,
    MIPS_I | MIPS_II | MIPS_III | MIPS_FPU | MIPS_MSA,
  },
  {
    "pic32",
    CPU_TYPE_MIPS32,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    simulate_init_mips,
    MIPS_I | MIPS_II | MIPS_III | MIPS_32,
  },
  {
    "ps2_ee",
    CPU_TYPE_EMOTION_ENGINE,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_mips,
    NULL,
    link_function_mips,
    list_output_mips,
    disasm_range_mips,
    simulate_init_mips,
    MIPS_I | MIPS_II | MIPS_III | MIPS_IV | MIPS_FPU | MIPS_EE_CORE | MIPS_EE_VU,
  },
#endif
#ifdef ENABLE_PDP8
  {
    "pdp8",
    CPU_TYPE_PDP8,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_pdp8,
    NULL,
    link_not_supported,
    list_output_pdp8,
    disasm_range_pdp8,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PIC14
  {
    "pic14",
    CPU_TYPE_PIC14,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_pic14,
    NULL,
    link_not_supported,
    list_output_pic14,
    disasm_range_pic14,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_DSPIC
  {
    "pic24",
    CPU_TYPE_PIC24,
    ENDIAN_LITTLE,
    2,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_24,
    parse_instruction_dspic,
    NULL,
    link_not_supported,
    list_output_dspic,
    disasm_range_dspic,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_POWERPC
  {
    "powerpc",
    CPU_TYPE_POWERPC,
    ENDIAN_BIG,
    1,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_powerpc,
    NULL,
    link_not_supported,
    list_output_powerpc,
    disasm_range_powerpc,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_PROPELLER
  {
    "propeller",
    CPU_TYPE_PROPELLER,
    ENDIAN_LITTLE,
    4,
    ALIGN_4,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_propeller,
    NULL,
    link_not_supported,
    list_output_propeller,
    disasm_range_propeller,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_EMOTION_ENGINE
  {
    "ps2_ee_vu0",
    CPU_TYPE_PS2_EE_VU,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_ps2_ee_vu,
    NULL,
    link_not_supported,
    list_output_ps2_ee_vu,
    disasm_range_ps2_ee_vu,
    NULL,
    PS2_EE_VU0,
  },
  {
    "ps2_ee_vu1",
    CPU_TYPE_PS2_EE_VU,
    ENDIAN_LITTLE,
    1,
    ALIGN_16,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_ps2_ee_vu,
    NULL,
    link_not_supported,
    list_output_ps2_ee_vu,
    disasm_range_ps2_ee_vu,
    NULL,
    PS2_EE_VU1,
  },
#endif
#ifdef ENABLE_RISCV
  {
    "riscv",
    CPU_TYPE_RISCV,
    ENDIAN_LITTLE,
    1,
    ALIGN_4,
    1,
    0,
    1,
    0,
    0,
    SREC_32,
    parse_instruction_riscv,
    NULL,
    link_not_supported,
    list_output_riscv,
    disasm_range_riscv,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SH4
  {
    "sh4",
    CPU_TYPE_SH4,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    1,
    1,
    1,
    SREC_16,
    parse_instruction_sh4,
    NULL,
    link_not_supported,
    list_output_sh4,
    disasm_range_sh4,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_STM8
  {
    "stm8",
    CPU_TYPE_STM8,
    ENDIAN_BIG,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_stm8,
    NULL,
    link_not_supported,
    list_output_stm8,
    disasm_range_stm8,
    simulate_init_stm8,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SUPER_FX
  {
    "super_fx",
    CPU_TYPE_SUPER_FX,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_super_fx,
    NULL,
    link_not_supported,
    list_output_super_fx,
    disasm_range_super_fx,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_SWEET16
  {
    "sweet16",
    CPU_TYPE_SWEET16,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    1,
    0,
    1,
    0,
    0,
    SREC_16,
    parse_instruction_sweet16,
    NULL,
    link_not_supported,
    list_output_sweet16,
    disasm_range_sweet16,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_THUMB
  {
    "thumb",
    CPU_TYPE_THUMB,
    ENDIAN_LITTLE,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_32,
    parse_instruction_thumb,
    NULL,
    link_not_supported,
    list_output_thumb,
    disasm_range_thumb,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_TMS1000
  {
    "tms1000",
    CPU_TYPE_TMS1000,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms1000,
    NULL,
    link_not_supported,
    list_output_tms1000,
    disasm_range_tms1000,
    NULL,
    NO_FLAGS,
  },
  {
    "tms1100",
    CPU_TYPE_TMS1100,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms1100,
    NULL,
    link_not_supported,
    list_output_tms1100,
    disasm_range_tms1100,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_TMS9900
  {
    "tms9900",
    CPU_TYPE_TMS9900,
    ENDIAN_BIG,
    1,
    ALIGN_2,
    0,
    0,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_tms9900,
    NULL,
    link_not_supported,
    list_output_tms9900,
    disasm_range_tms9900,
    simulate_init_tms9900,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_WEBASM
  {
    "webasm",
    CPU_TYPE_WEBASM,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    1,
    SREC_16,
    parse_instruction_webasm,
    NULL,
    link_not_supported,
    list_output_webasm,
    disasm_range_webasm,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_XTENSA
  {
    "xtensa",
    CPU_TYPE_XTENSA,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    0,
    0,
    1,
    0,
    SREC_16,
    parse_instruction_xtensa,
    NULL,
    link_not_supported,
    list_output_xtensa,
    disasm_range_xtensa,
    NULL,
    NO_FLAGS,
  },
#endif
#ifdef ENABLE_Z80
  {
    "z80",
    CPU_TYPE_Z80,
    ENDIAN_LITTLE,
    1,
    ALIGN_1,
    0,
    1,
    0,
    0,
    0,
    SREC_16,
    parse_instruction_z80,
    NULL,
    link_not_supported,
    list_output_z80,
    disasm_range_z80,
    simulate_init_z80,
    NO_FLAGS,
  },
#endif
  { NULL },
};

