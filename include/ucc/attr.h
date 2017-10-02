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
# define EXPORT __declspec(dllexport)
#elif defined CC_CLANG || (defined CC_GCC && VERNO_GE(CC_GCC, 3, 3))
# define EXPORT __attribute__((visibility("default")))
#else
# define EXPORT
#endif

#if defined CC_CLANG || (defined CC_GCC && VERNO_GE(CC_GCC, 3, 0))
# define DEPRECATED __attribute__((deprecated))
#elif defined CC_MSVC && CC_MSVC >= 1300
# define DEPRECATED __declspec(deprecated)
#else
# define DEPRECATED
#endif

#if __has_feature(address_sanitizer) || defined __SANITIZE_ADDRESS__
# define NOSANITIZE __attribute__((no_sanitize_address))
#else
# define NOSANITIZE
#endif

#if defined U_DEBUG
# define FORCEINLINE
#elif __has_feature(c_inline)
# define FORCEINLINE __attribute__((__always_inline__)) __inline__
#elif defined CC_GCC
# if __has_attribute(gnu_inline)
#   define FORCEINLINE \
  __attribute__((__always_inline__,__gnu_inline__)) __inline__
# else
#   define FORCEINLINE __attribute__((__always_inline__)) __inline__
# endif
#elif __has_attribute(always_inline)
# define FORCEINLINE __attribute__((__always_inline__)) __inline__
#elif defined CC_MSVC || defined CC_INTEL
# define FORCEINLINE __forceinline
#else
# define FORCEINLINE __inline__
#endif

#if __has_feature(stdnoreturn_h) || __has_include("stdnoreturn.h")
# define NORETURN _Noreturn
#elif __has_attribute(noreturn) || (defined CC_GCC && CC_GCC >= 20700UL)
# define NORETURN __attribute__((__noreturn__))
#elif defined __STDC__ && __STDC_VERSION__ >= 201112L
# define NORETURN _Noreturn
#elif defined CC_MSVC
# define NORETURN __declspec(noreturn)
#else
# define NORETURN
#endif

#if __has_attribute(pure)
# define PURE __attribute__((__pure__))
#else
# define PURE
#endif

#if __has_extension(attribute_const) || __has_attribute(const)
# define CONST __attribute__((__const__))
#else
# define CONST
#endif

#if defined CC_GCC || __has_attribute(unused)
# define UNUSED __attribute__((unused))
#elif defined __LCLINT__
# define UNUSED /*@unused@*/
#else
# define UNUSED
#endif

#endif /* !__UCC_ATTR_H */
