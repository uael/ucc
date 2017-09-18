/*
 * MIT License
 *
 * Copyright (c) 2016-2017 Abel Lucas <www.github.com/uael>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!@file ucc/arch.h
 * @author uael
 */
#ifndef __UCC_ARCH_H
# define __UCC_ARCH_H

#include "kw.h"

#if defined __alpha__ || defined __alpha || defined _M_ALPHA
# define ARCH_ALPHA
#elif defined __arm__ || defined __TARGET_ARCH_ARM || defined _ARM || \
      defined _M_ARM_ || defined __arm || defined __aarch64__
# if defined __aarch64__
#   define ARCH_ARM_64
# else
#   define ARCH_ARM_32
# endif
# if defined __ARM_ARCH && __ARM_ARCH > 1
#   define ARCH_ARM __ARM_ARCH
# elif defined __TARGET_ARCH_ARM && __TARGET_ARCH_ARM > 1
#   define ARCH_ARM __TARGET_ARCH_ARM
# elif defined _M_ARM && _M_ARM > 1
#   define ARCH_ARM _M_ARM
# elif defined __ARM64_ARCH_8__ || defined __aarch64__ || \
       defined __CORE_CORTEXAV8__
#   define ARCH_ARM 8
#   define ARCH_ARM_V8
# elif defined __ARM_ARCH_7__ || defined __ARM_ARCH_7A__ || \
       defined __ARM_ARCH_7R__ || defined __ARM_ARCH_7M__ || \
       defined __ARM_ARCH_7S__ || defined _ARM_ARCH_7 || \
       defined __CORE_CORTEXA__
#   define ARCH_ARM 7
#   define ARCH_ARM_V7
# elif defined __ARM_ARCH_6__ || defined __ARM_ARCH_6J__ || \
       defined __ARM_ARCH_6T2__ || defined __ARM_ARCH_6Z__ || \
       defined __ARM_ARCH_6K__ || defined __ARM_ARCH_6ZK__ || \
       defined __ARM_ARCH_6M__
#   define ARCH_ARM 6
#   define ARCH_ARM_V6
# elif defined __ARM_ARCH_5__ || defined __ARM_ARCH_5E__ || \
       defined __ARM_ARCH_5T__ || defined __ARM_ARCH_5TE__ || \
       defined __ARM_ARCH_5TEJ__
#   define ARCH_ARM 5
#   define ARCH_ARM_V5
# elif defined __ARM_ARCH_4__ || defined __ARM_ARCH_4T__
#   define ARCH_ARM 4
#   define ARCH_ARM_V4
# elif defined __ARM_ARCH_3__ || defined __ARM_ARCH_3M__
#   define ARCH_ARM 3
#   define ARCH_ARM_V3
# elif defined __ARM_ARCH_2__
#   define ARCH_ARM 2
#   define ARCH_ARM_V2
# endif
#elif defined __i386__ || defined __i386 || defined _M_IX86
# define ARCH_X86_32
# if defined _M_IX86
#   if (_M_IX86 <= 600)
#     define ARCH_X86 (_M_IX86 / 100)
#   else
#     define ARCH_X86 6
#   endif
# elif defined __i686__ || defined __athlon__ || defined __SSE__ || \
       defined __pentiumpro__
#   define ARCH_X86 6
# elif defined __i586__ || defined __k6__ || defined __pentium__
#   define ARCH_X86 5
# elif defined __i486__ || defined __80486__
#   define ARCH_X86 4
# else
#   define ARCH_X86 3
# endif
#elif defined __x86_64__ || defined __x86_64 || defined __amd64__ || \
      defined __amd64 || defined _M_X64 || defined _M_AMD64
# define ARCH_X86_64
# define ARCH_X86 6
#elif defined __ia64__ || defined __ia64 || defined _M_IA64
# define ARCH_IA64
#elif defined __mips__ || defined __mips || defined _M_MRX000
# define ARCH_MIPS
# if defined _M_MRX000
#   if (_M_MRX000 >= 10000)
#     define ARCH_MIPS_IV
#   else
#     define ARCH_MIPS_III
#   endif
# endif
# if defined _MIPS_ARCH_MIPS64 || (defined __mips && __mips - 0 >= 64) || \
     (defined _MIPS_ISA && defined _MIPS_ISA_MIPS64 && \
     __MIPS_ISA - 0 >= _MIPS_ISA_MIPS64)
#   define ARCH_MIPS_64
# elif defined _MIPS_ARCH_MIPS32 || (defined __mips && __mips - 0 >= 32) || \
       (defined _MIPS_ISA && defined _MIPS_ISA_MIPS32 && \
       __MIPS_ISA - 0 >= _MIPS_ISA_MIPS32)
#   define ARCH_MIPS_32
# elif defined _MIPS_ARCH_MIPS4 || (defined __mips && __mips - 0 >= 4) || \
       (defined _MIPS_ISA && defined _MIPS_ISA_MIPS4 && \
       __MIPS_ISA - 0 >= _MIPS_ISA_MIPS4)
#   define ARCH_MIPS_IV
# elif defined _MIPS_ARCH_MIPS3 || (defined __mips && __mips - 0 >= 3) || \
       (defined _MIPS_ISA && defined _MIPS_ISA_MIPS3 && \
       __MIPS_ISA - 0 >= _MIPS_ISA_MIPS3)
#   define ARCH_MIPS_III
# elif defined _MIPS_ARCH_MIPS2 || (defined __mips && __mips - 0 >= 2) || \
       (defined _MIPS_ISA && defined _MIPS_ISA_MIPS2 && \
       __MIPS_ISA - 0 >= _MIPS_ISA_MIPS2)
#   define ARCH_MIPS_II
# elif defined _MIPS_ARCH_MIPS1 || (defined __mips && __mips - 0 >= 1) || \
     (defined _MIPS_ISA && defined _MIPS_ISA_MIPS1 && \
     __MIPS_ISA - 0 >= _MIPS_ISA_MIPS1)
#   define ARCH_MIPS_I
# endif
# if defined ARCH_MIPS_64
#   define ARCH_MIPS_IV
# endif
# if defined ARCH_MIPS_IV
#   define ARCH_MIPS_III
# endif
# if defined ARCH_MIPS_32 || defined ARCH_MIPS_III
#   define ARCH_MIPS_II
# endif
# if defined ARCH_MIPS_II
#   define ARCH_MIPS_I
# endif
#elif defined __powerpc__ || defined __powerpc || defined __ppc__ || \
      defined __ppc || defined _ARCH_PPC || defined _ARCH_PWR || \
      defined _ARCH_COM || defined _M_PPC || defined _M_MPPC
# define ARCH_POWER
# if defined __powerpc64__ || defined __powerpc64 || defined __ppc64__ || \
     defined __ppc64 || defined __64BIT__ || defined __LP64__ || \
     defined _LP64
#   define ARCH_POWER_64
# else
#   define ARCH_POWER_32
# endif
#elif defined __sparc__ || defined __sparc
# define ARCH_SPARC
# if defined __sparc_v9__ || defined __sparcv9
#   define ARCH_SPARC_V9
# elif defined __sparc_v8__ || defined __sparcv8
#   define ARCH_SPARC_V8
# endif
#elif defined __hppa__ || defined __hppa
# define ARCH_HPPA
# if defined _PA_RISC2_0 || defined __RISC2_0__ || defined __HPPA20__ || \
     defined __PA8000__
#   define ARCH_HPPA_64
# else
#   define ARCH_HPPA_32
# endif
#endif

#if defined ARCH_x86 || defined ARCH_X86_64
# if defined __SSE__
#   define ARCH_SSE
# endif
# if defined __SSE2__
#   define ARCH_SSE2
# endif
# if defined __SSE3__
#   define ARCH_SSE3
# endif
# if defined __SSE4_1__
#   define ARCH_SSE4
# endif
#endif

#if defined __ARM_NEON__
# define ARCH_NEON
#endif

#if defined __thumb__
# define ARCH_THUMB
#endif

#if defined __VFP_FP__
# define ARCH_VFP
#endif

#if defined __ELF__
# define ARCH_ELF
#endif

#if defined __MACH__
# define ARCH_MACH
#endif

#endif /* !__UCC_ARCH_H */
