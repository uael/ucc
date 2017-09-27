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

/*!@file ucc/feature.h
 * @author uael
 */
#ifndef __UCC_FEATURE_H
# define __UCC_FEATURE_H

#include "plat.h"

#ifndef __has_feature
# define __has_feature(x) ucc_has_feature_##x
#endif

#ifndef __has_include
# define __has_include(x) 0
#endif

#ifndef __has_builtin
# define __has_builtin(x) ucc_has_builtin_##x
#endif

#ifndef __has_attribute
# define __has_attribute(x) ucc_has_attribute_##x
#endif

#ifndef __has_extension
# define __has_extension(x) __has_feature(x) || ucc_has_extension_##x
#endif

#if defined CC_CLANG
# if VERNO_GT(CC_CLANG, 3, 2)
#   define ucc_has_feature_stdnoreturn_h 1
# endif
#elif defined CC_GCC
# define ucc_has_attribute_weak 1
# define ucc_has_attribute_always_inline 1
# define ucc_has_attribute_noinline 1
# define ucc_has_attribute_pure 1
# define ucc_has_attribute_aligned 1
# define ucc_has_attribute_noreturn 1
# define ucc_has_attribute___noreturn__ 1
# define ucc_has_attribute_unused 1
# define ucc_has_extension_attribute_const 1
# define ucc_has_builtin___builtin_popcount 1
# if VERNO_GT(CC_GCC, 2, 0)
#   define ucc_has_builtin_expect 1
# endif
# if VERNO_GE(CC_GCC, 4, 6)
#  define ucc_has_attribute_externally_visible 1
# endif
# if VERNO_GE(CC_GCC, 4, 7)
#  define ucc_has_feature_stdnoreturn_h 1
#  define ucc_has_feature_stdalign_h 1
# endif
# if VERNO_GE(CC_GCC, 4, 9)
#   define ucc_has_feature_c_thread_local 1
# endif
# if defined __GNUC_GNU_INLINE__ || VERNO_LT(CC_GCC, 4, 3)
#  define ucc_has_attribute_gnu_inline 1
# endif
# if defined __GNUC_STDC_INLINE__ || VERNO_GE(CC_GCC, 4, 3)
#  define ucc_has_feature_c_inline 1
# endif
#elif defined CC_ICC
#   define ucc_has_builtin_expect 1
#endif

#endif /* !__UCC_FEATURE_H */
