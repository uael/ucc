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

/*!@file ucc/attr.h
 * @author uael
 */
#ifndef __UCC_ATTR_H
# define __UCC_ATTR_H

#include "kw.h"

#if defined CC_MSVC
# define $export __declspec(dllexport)
#elif defined CC_CLANG || (defined CC_GCC && CC_BE(3, 3))
# define $export __attribute__((visibility("default")))
#else
# define $export
#endif

#if defined CC_CLANG || (defined CC_GCC && CC_BE(3, 0))
# define $deprecated __attribute__((deprecated))
#elif defined CC_MSVC && CC_MSVC >= 1300
# define $deprecated __declspec(deprecated)
#else
# define $deprecated
#endif

#if __has_feature(address_sanitizer) || defined __SANITIZE_ADDRESS__
# define $no_sanitize_address __attribute__((no_sanitize_address))
#else
# define $no_sanitize_address
#endif

#if __has_feature(c_inline)
# define $forceinline __attribute__((__always_inline__)) __inline__
#elif defined CC_GCC
# if __has_attribute(gnu_inline)
#   define $forceinline \
  __attribute__((__always_inline__,__gnu_inline__,__weak__)) __inline__
# else
#   define $forceinline __attribute__((__always_inline__,__weak__)) __inline__
# endif
#elif __has_attribute(always_inline)
# define $forceinline __attribute__((__always_inline__)) __inline__
#elif defined CC_MSVC || defined CC_INTEL
# define $forceinline ___forceinline __inline__
#else
# define $forceinline static __inline__
#endif

#if __has_feature(stdnoreturn_h) || __has_include("stdnoreturn.h")
# include <stdnoreturn.h>
# define $noreturn noreturn
#elif __has_attribute(noreturn) || (defined CC_GCC && CC_GCC >= 20700UL)
# define $noreturn __attribute__((__noreturn__))
#elif defined __STDC__ && __STDC_VERSION__ >= 201112L
# define $noreturn _Noreturn
#elif defined CC_MSVC
# define $noreturn __declspec(noreturn)
#else
# define $noreturn
#endif

#if __has_attribute(pure)
# define $pure __attribute__((__pure__))
#else
# define $pure
#endif

#if __has_extension(attribute_const) || __has_attribute(const)
# define $const __attribute__((__const__))
#else
# define $const
#endif

#if defined CC_GCC || __has_attribute(unused)
# define $unused __attribute__((unused))
#elif defined __LCLINT__
# define $unused /*@unused@*/
#else
# define $unused
#endif

#endif /* !__UCC_ATTR_H */
