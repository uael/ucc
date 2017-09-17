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

/*!@file ucc/kw.h
 * @author uael
 */
#ifndef __UCC_KW_H
# define __UCC_KW_H

#include "feature.h"

#ifndef __cplusplus
# define __register__ register
#else
# define __register__
#endif
#define __restrict__ __restrict
#define __volatile__ __volatile
#define __func__ __FUNCTION__
#define __file__ __FILE__
#define __line____LINE__

#if defined CC_MSVC || defined CC_ICC
# define __asm__ __asm
# define __inline__ __inline
# define __packed__(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
# define __aligned__(a) __declspec(align(a))
# define __alignof__(ty) __alignof(ty)
# define __cdecl__ __cdecl
# define __stdcall__ __stdcall
# define __fastcall__ __fastcall
# define __thiscall__ __thiscall
#elif defined CC_GCC
# define __asm__ __asm__
# define __inline__ __inline__
# define __packed__(...) __attribute__((packed, aligned(1))) __VA_ARGS__
# define __aligned__(a) __attribute__((aligned(a)))
# define __alignof__(ty) __alignof__(ty)
# if defined __x86_64 || defined __amd64__ || defined __amd64 \
  || defined _M_IA64 || defined _M_X64
#   define __cdecl__
#   define __stdcall__
#   define __fastcall__
#   define __thiscall__
# else
#   define __cdecl__ __attribute__((__cdecl__))
#   define __stdcall__ __attribute__((__stdcall__))
#   define __fastcall__ __attribute__((__fastcall__))
#   define __thiscall__ __attribute__((__thiscall__))
# endif
#else
# define __asm__
# define __inline__ inline
# define __packed__(...) __VA_ARGS__
# define __aligned__(a)
# define __alignof__(ty)
# define __cdecl__
# define __stdcall__
# define __fastcall__
# define __thiscall__
#endif

/*!@def __cpu_aligned__
 * the cpu byte alignment.
 */
#if (CPU_BYTE == 8)
# define __cpu_aligned__ __aligned__(8)
#elif (CPU_BYTE == 4)
# define __cpu_aligned__ __aligned__(4)
#elif (CPU_BYTE == 2)
# define __cpu_aligned__ __aligned__(2)
#else
# error unknown cpu bytes
#endif

#if defined CC_ICC || (defined CC_GCC && CC_BT(2, 0))
# define LIKELY(x) __builtin_expect(!!(x), 1)
# define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
# define LIKELY(x) (x)
# define UNLIKELY(x) (x)
#endif

#ifdef __cplusplus
# define __extern_c__ extern "C"
#else
# define __extern_c__
#endif

#if __has_feature(c_thread_local)
# define __thread_local__ _Thread_local
#elif defined CC_GCC
# define __thread_local__ __thread
#elif defined CC_MSVC || defined CC_BORLAND
# define __thread_local__ __declspec(thread)
#endif

#endif /* !__UCC_KW_H */
