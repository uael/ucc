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

/*!@file ucc/libc.h
 * @author uael
 */
#ifndef __UCC_LIBC_H
# define __UCC_LIBC_H

#include "feature.h"

#ifdef __cplusplus
# include <cassert>
# include <cctype>
# include <cerrno>
# include <cfloat>
# include <climits>
# include <clocale>
# include <cmath>
# include <csetjmp>
# include <csignal>
# include <cstdarg>
# include <cstddef>
# include <cstdint>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <ctime>
#else
# include <assert.h>
# include <ctype.h>
# include <errno.h>
# include <float.h>
# include <limits.h>
# include <locale.h>
# include <math.h>
# include <setjmp.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <time.h>
#endif

#if defined STD_C99 || __has_feature(complex_h)
# include <complex.h>
#endif

#if defined OS_WIN || __has_feature(direct_h)
# include <direct.h>
#endif

#if defined STD_POSIX || __has_feature(dirent_h)
# include <dirent.h>
#endif

#if defined STD_POSIX || __has_feature(fcntl_h)
# include <fcntl.h>
#endif

#if defined STD_C99 || __has_feature(fenv_h)
# include <fenv.h>
#endif

#if defined STD_C99 || __has_feature(inttypes_h)
# include <inttypes.h>
#endif

#if defined OS_WIN || __has_feature(io_h)
# include <io.h>
#endif

#if defined STD_POSIX || __has_feature(iso646_h)
# include <iso646.h>
#endif

#if defined STD_C11 || __has_feature(stdalign_h)
# include <stdalign.h>
#endif

#if defined STD_C11 || __has_feature(stdatomic_h)
# include <stdatomic.h>
#endif

#if defined STD_C99 || __has_feature(stdbool_h)
# include <stdbool.h>
#endif

#if defined STD_C99 || __has_feature(stdint_h)
# include <stdint.h>
#endif

#if defined STD_C11 || __has_feature(stdnoreturn_h)
# include <stdnoreturn.h>
#endif

#if defined STD_C11 || __has_feature(threads_h)
# include <stdthreads.h>
#endif

#if defined STD_POSIX || __has_feature(sys_stat_h)
# include <sys/stat.h>
#endif

#if defined STD_POSIX || __has_feature(sys_types_h)
# include <sys/types.h>
#endif

#if defined STD_C99 || __has_feature(tgmath_h)
# include <tgmath.h>
#endif

#if defined STD_C11 || __has_feature(uchar_h)
# include <uchar.h>
#endif

#if defined STD_POSIX || __has_feature(unistd_h)
# include <unistd.h>
#endif

#if defined STD_C90 || __has_feature(wchar_h)
# include <wchar.h>
#endif

#if defined STD_C90 || __has_feature(wctype_h)
# include <wctype.h>
#endif

#endif /* !__UCC_LIBC_H */
