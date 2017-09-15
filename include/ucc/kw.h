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

#include "cc.h"
#include "cpu.h"
#include "os.h"

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
# define __inline_force__ __forceinline
# define __packed__(x) __pragma(pack(push, 1)) x __pragma(pack(pop))
# define __aligned__(a) __declspec(align(a))
# define __alignof__(ty) __alignof(ty)
# define __cdecl__ __cdecl
# define __stdcall__ __stdcall
# define __fastcall__ __fastcall
# define __thiscall__ __thiscall
#elif defined CC_GCC
# define __asm__ __asm__
# define __inline__ __inline__
# define __inline_force__ __inline__ __attribute__((always_inline))
# define __packed__(x) __attribute__((packed, aligned(1))) x
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
# define __inline_force__ static inline
# define __func__
# define __file__ ""
# define __line__ (0)
# define __packed__(x)
# define __aligned__(a)
# define __alignof__(ty)
# define __cdecl__
# define __stdcall__
# define __fastcall__
# define __thiscall__
#endif

/*! @def __cpu_aligned__
 *
 * the cpu byte alignment
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
# define __likely__(x) __builtin_expect(!!(x), 1)
# define __unlikely__(x) __builtin_expect(!!(x), 0)
#else
# define __likely__(x) (x)
# define __unlikely__(x) (x)
#endif

#ifdef OS_WIN
# define __newline__ "\r\n"
#else
# define __newline__ "\n"
#endif

#ifdef __cplusplus
# define __extern_c__ extern "C"
#else
# define __extern_c__
#endif

#if defined CC_MSVC
# define __export__ __declspec(dllexport)
#elif defined CC_CLANG || (defined CC_GCC && CC_BE(3, 3))
# define __export__ __attribute__((visibility("default")))
#else
# define __export__
#endif

#if defined CC_CLANG || (defined CC_GCC && CC_BE(3, 0))
# define __deprecated__ __attribute__((deprecated))
#elif defined CC_MSVC && CC_MSVC >= 1300
# define __deprecated__ __declspec(deprecated)
#else
# define __deprecated__
#endif

#ifdef __has_feature
# define __has_feature__(x) __has_feature(x)
#else
# define __has_feature__(x) 0
#endif

#ifdef __has_include
# define __has_include__(x) __has_include(x)
#else
# define __has_include__(x) 0
#endif

#ifdef __has_builtin
# define __has_builtin__(x) __has_builtin(x)
#else
# define __has_builtin__(x) 0
#endif

#if __has_feature__(address_sanitizer) || defined __SANITIZE_ADDRESS__
# define __no_sanitize_address__ __attribute__((no_sanitize_address))
#else
# define __no_sanitize_address__
#endif

#if __has_feature__(c_thread_local)
# define __thread_local__ _Thread_local
#elif defined CC_GCC
# if CC_BE(4, 9)
#   define __thread_local__ _Thread_local
# else
#   define __thread_local__ __thread
# endif
#elif defined CC_MSVC || defined CC_BORLAND
# define __thread_local__ __declspec(thread)
#endif

#endif /* !__UCC_KW_H */
