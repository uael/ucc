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

#if defined __i386 || defined __i686 || defined __i386__ \
  || defined __i686__ || defined _M_IX86
# define ARCH_x86
# if defined __i386 || defined __i386__
#   define ARCH_STR "i386"
# elif defined __i686 || defined __i686__
#   define ARCH_STR "i686"
# elif defined _M_IX86
#   if (_M_IX86 == 300)
#     define ARCH_STR "i386"
#   elif (_M_IX86 == 400)
#     define ARCH_STR "i486"
#   elif (_M_IX86 == 500 || _M_IX86 == 600)
#     define ARCH_STR "Pentium"
#   endif
# else
#   define ARCH_STR "x86"
# endif
#elif defined __x86_64 || defined __amd64__ || defined __amd64 \
    || defined _M_IA64 || defined _M_X64
# define ARCH_x64
# if defined __x86_64
#   define ARCH_STR "x86_64"
# elif defined __amd64__ || defined __amd64
#   define ARCH_STR "amd64"
# else
#   define ARCH_STR "x64"
# endif
#elif defined __arm__ || defined __arm64 || defined __arm64__ \
  || (defined __aarch64__ && __aarch64__)
# define ARCH_ARM
# if defined __ARM64_ARCH_8__
#   define ARCH_ARM64
#   define ARCH_ARM_VER (8)
#   define ARCH_ARM_v8
#   define ARCH_STR "arm64"
# elif defined __ARM_ARCH_7A__
#   define ARCH_ARM_VER (7)
#   define ARCH_ARM_v7A
#   define ARCH_STR "armv7a"
# elif defined __ARM_ARCH_7__
#   define ARCH_ARM_VER (7)
#   define ARCH_ARM_v7
#   define ARCH_STR "armv7"
# elif defined __ARM_ARCH_6__
#   define ARCH_ARM_VER (6)
#   define ARCH_ARM_v6
#   define ARCH_STR "armv6"
# elif defined __ARM_ARCH_5TE__
#   define ARCH_ARM_VER (5)
#   define ARCH_ARM_v5te
#   define ARCH_STR "armv5te"
# elif defined __ARM_ARCH_5__
#   define ARCH_ARM_VER (5)
#   define ARCH_ARM_v5
#   define ARCH_STR "armv5"
# elif defined __ARM_ARCH_4T__
#   define ARCH_ARM_VER (4)
#   define ARCH_ARM_v4t
#   define ARCH_STR "armv4t"
# elif defined __ARM_ARCH
#   define ARCH_ARM_VER __ARM_ARCH
#   if __ARM_ARCH >= 8
#     define ARCH_ARM_v8
#     if defined __arm64 || defined __arm64__
#       define ARCH_ARM64
#       define ARCH_STR "arm64"
#     else
#       define ARCH_STR "armv7s"
#     endif
#   elif __ARM_ARCH >= 7
#     define ARCH_ARM_v7
#     define ARCH_STR "armv7"
#   elif __ARM_ARCH >= 6
#     define ARCH_ARM_v6
#     define ARCH_STR "armv6"
#   else
#     define ARCH_ARM_v5
#     define ARCH_STR "armv5"
#   endif
# elif defined __aarch64__ && __aarch64__
#   define ARCH_ARM_v8
#   define ARCH_ARM64
#   define ARCH_STR "arm64-v8a"
# else
#   error unknown arm arch VER
# endif
# if !defined ARCH_ARM64 && (defined __arm64 || defined __arm64__)
#   define ARCH_ARM64
#   ifndef ARCH_STR
#     define ARCH_STR "arm64"
#   endif
# endif
# ifndef ARCH_STR
#   define ARCH_STR "arm"
# endif
# if defined __thumb__
#   define ARCH_ARM_THUMB
#   define ARCH_STR_2 "_thumb"
# endif
# if defined __ARM_NEON__
#   define ARCH_ARM_NEON
#   define ARCH_STR_3 "_neon"
# endif
#elif defined mips || defined _mips || defined __mips__
# define ARCH_MIPS
# define ARCH_STR "mips"
#else
# error unknown arch
# define ARCH_STR "unknown_arch"
#endif

#if defined ARCH_x86 || defined ARCH_x64
# if defined __SSE__
#   define ARCH_SSE
#   define ARCH_STR_2 "_sse"
# endif
# if defined __SSE2__
#   define ARCH_SSE2
#     undef ARCH_STR_2
#   define ARCH_STR_2 "_sse2"
# endif
# if defined __SSE3__
#   define ARCH_SSE3
#     undef ARCH_STR_2
#   define ARCH_STR_2 "_sse3"
# endif
#endif

#if defined __VFP_FP__
# define ARCH_VFP
# define ARCH_STR_4 "_vfp"
#endif

#if defined __ELF__
# define ARCH_ELF
# define ARCH_STR_5 "_elf"
#endif

#if defined __MACH__
# define ARCH_MACH
# define ARCH_STR_5 "_mach"
#endif

#ifndef ARCH_STR_1
# define ARCH_STR_1 ""
#endif

#ifndef ARCH_STR_2
# define ARCH_STR_2 ""
#endif

#ifndef ARCH_STR_3
# define ARCH_STR_3 ""
#endif

#ifndef ARCH_STR_4
# define ARCH_STR_4 ""
#endif

#ifndef ARCH_STR_5
# define ARCH_STR_5 ""
#endif

#ifndef ARCH_VER_STRING
# define ARCH_VER_STRING ARCH_STR ARCH_STR_1 ARCH_STR_2 ARCH_STR_3 ARCH_STR_4 \
  ARCH_STR_5
#endif

#endif /* !__UCC_ARCH_H */
