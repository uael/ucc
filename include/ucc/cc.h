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

/*!@file ucc/cc.h
 * @author uael
 */
#ifndef __UCC_CC_H
# define __UCC_CC_H

/*!@def VERNO(major, minor, patch)
 * Compute a valid semantic version into a unsigned long value.
 * @param[in] major The major version.
 * @param[in] minor The minor version.
 * @param[in] patch The patch version.
 * @return An unsigned long.
 */
#ifndef VERNO
# define VERNO(major, minor, patch) (((major)*10000UL)+(minor)*100UL+(patch))
#endif

/*!@def STRINGIFY(x)
 * A macro which stringifies its argument.
 * @param[in] x All the tokens which have to be stringified.
 * @return An expression of type pointer to char.
 */
#ifndef STRINGIFY
# define STRINGIFY_EX(x) #x
# define STRINGIFY(x) STRINGIFY_EX(x)
#endif

#if defined __INTEL_COMPILER
# define CC_ICC VERNO(__INTEL_COMPILER,0,0)
# define CC_VERNO CC_ICC
# define CC_DESC "intel c/c++"
# if (__INTEL_COMPILER == 600)
# define CC_VERSTR "intel c/c++ 6.0"
# elif (__INTEL_COMPILER == 700)
# define CC_VERSTR "intel c/c++ 7.0"
# elif (__INTEL_COMPILER == 800)
# define CC_VERSTR "intel c/c++ 8.0"
# elif (__INTEL_COMPILER == 900)
# define CC_VERSTR "intel c/c++ 9.0"
# elif (__INTEL_COMPILER == 1000)
# define CC_VERSTR "intel c/c++ 10.0"
# elif (__INTEL_COMPILER == 1100)
#   define CC_VERSTR "intel c/c++ 11.0"
# elif (__INTEL_COMPILER == 1110)
#   define CC_VERSTR "intel c/c++ 11.1"
# elif (__INTEL_COMPILER == 1200)
#   define CC_VERSTR "intel c/c++ 12.0"
# elif (__INTEL_COMPILER == 1210)
#   define CC_VERSTR "intel c/c++ 12.1"
# elif (__INTEL_COMPILER == 1300)
#   define CC_VERSTR "intel c/c++ 13.0"
# elif (__INTEL_COMPILER == 1310)
#   define CC_VERSTR "intel c/c++ 13.1"
# elif (__INTEL_COMPILER == 1400)
#   define CC_VERSTR "intel c/c++ 14.0"
# elif (__INTEL_COMPILER == 1410)
#   define CC_VERSTR "intel c/c++ 14.1"
# elif (__INTEL_COMPILER == 9999)
#   define CC_VERSTR "intel c/c++ mainline"
# else
#   define CC_VERSTR "intel c/c++ unknown"
# endif
#elif defined __BORLANDC__
# define CC_BORLAND VERNO(__BORLANDC__,0,0)
# define CC_VERNO CC_BORLAND
# define CC_DESC "borland c/c++"
# if 0
#   define CC_VERSTR "borland c++ 4.52"
# elif 0
#   define CC_VERSTR "borland c++ 5.5"
# elif (__BORLANDC__ == 0x0551)
#   define CC_VERSTR "borland c++ 5.51"
# elif (__BORLANDC__ == 0x0560)
#   define CC_VERSTR "borland c++ 5.6"
# elif (__BORLANDC__ == 0x0564)
#   define CC_VERSTR "borland c++ 5.6.4 (c++ builderx)"
# elif (__BORLANDC__ == 0x0582)
#   define CC_VERSTR "borland c++ 5.82 (turbo c++)"
# else
#   define CC_VERSTR "borland c/c++ unknown"
# endif
#elif defined __GNUC__
# define CC_GCC VERNO(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
# define CC_VERNO CC_GCC
# if defined __clang__
#   define CC_CLANG VERNO(__clang_major__,__clang_minor__,__clang_patchlevel__)
#   define CC_DESC "clang c/c++"
#   if defined __VERSION__
#     define CC_VERSTR __VERSION__
#   elif defined __clang_version__
#     define CC_VERSTR __clang_version__
#   else
#     define CC_VERSTR CC_DESC
#   endif
#   ifdef __cplusplus
#     pragma clang diagnostic ignored "-Wextern-c-compat"
#   endif
#   pragma clang diagnostic ignored "-Wunknown-pragmas"
#   pragma clang diagnostic ignored "-Wnullability-completeness"
# else
#   define CC_DESC "gnu c/c++"
#   if  __GNUC__ == 2
#     if __GNUC_MINOR__ < 95
#       define CC_VERSTR "gnu c/c++ <2.95"
#     elif __GNUC_MINOR__ == 95
#       define CC_VERSTR "gnu c/c++ 2.95"
#     elif __GNUC_MINOR__ == 96
#       define CC_VERSTR "gnu c/c++ 2.96"
#     else
#       define CC_VERSTR "gnu c/c++ > 2.96 && < 3.0"
#     endif
#   elif __GNUC__ == 3
#     if __GNUC_MINOR__ == 2
#       define CC_VERSTR "gnu c/c++ 3.2"
#     elif __GNUC_MINOR__ == 3
#       define CC_VERSTR "gnu c/c++ 3.3"
#     elif __GNUC_MINOR__ == 4
#       define CC_VERSTR "gnu c/c++ 3.4"
#     else
#       define CC_VERSTR "gnu c/c++ > 3.4 && < 4.0"
#     endif
#   elif __GNUC__ >= 4 && defined __GNUC_MINOR__
#     define CC_VERSTR \
  "gnu c/c++ "STRINGIFY(__GNUC__)"."STRINGIFY(__GNUC_MINOR__)
#   else
#     define CC_VERSTR "gnu c/c++ nuknown"
#   endif
# endif
#elif defined __WATCOMC__
# define CC_WATCOM VERNO(0,__WATCOMC__,0)
# define CC_VERNO CC_WATCOM
# define CC_DESC "watcom c/c++"
# if (__WATCOMC__ == 1100)
#   define CC_VERSTR "watcom c/c++ 11.0"
# elif (__WATCOMC__ == 1200)
#   define CC_VERSTR "open watcom c/c++ 1.0 (watcom 12.0)"
# elif (__WATCOMC__ == 1210)
#   define CC_VERSTR "open watcom c/c++ 1.1 (watcom 12.1)"
# elif (__WATCOMC__ == 1220)
#   define CC_VERSTR "open watcom c/c++ 1.2 (watcom 12.2)"
# elif (__WATCOMC__ == 1230)
#   define CC_VERSTR "open watcom c/c++ 1.3 (watcom 12.3)"
# elif (__WATCOMC__ == 1240)
#   define CC_VERSTR "open watcom c/c++ 1.4 (watcom 12.4)"
# elif (__WATCOMC__ == 1250)
#   define CC_VERSTR "open watcom c/c++ 1.5"
# elif (__WATCOMC__ == 1260)
#   define CC_VERSTR "open watcom c/c++ 1.6"
# elif (__WATCOMC__ == 1270)
#   define CC_VERSTR "open watcom c/c++ 1.7"
# else
#   define CC_VERSTR "open watcom c/c++ unknwon"
# endif
#elif defined __DMC__
# define CC_DMC VERNO(0,__DMC__,0)
# define CC_VERNO CC_DMC
# define CC_DESC "digital mars c/c++"
# if (__DMC__ < 0x0826)
#   error Unsupported version of the digital mars c/c++ compilers
# else
#   if __DMC__ >= 0x0832
#     define CC_VERSTR __DMC_VERSION_STRING__
#   elif (__DMC__ == 0x0826)
#     define CC_VERSTR "digital mars c/c++ 8.26"
#   elif (__DMC__ == 0x0827)
#     define CC_VERSTR "digital mars c/c++ 8.27"
#   elif (__DMC__ == 0x0828)
#     define CC_VERSTR "digital mars c/c++ 8.28"
#   elif (__DMC__ == 0x0829)
#     define CC_VERSTR "digital mars c/c++ 8.29"
#   elif (__DMC__ == 0x0830)
#     define CC_VERSTR "digital mars c/c++ 8.30"
#   elif (__DMC__ == 0x0831)
#     define CC_VERSTR "digital mars c/c++ 8.31"
#   else
#     define CC_VERSTR "digital mars c/c++ unknwon"
#   endif
# endif
#elif defined __VECTORC
# define CC_VECTOR VERNO(__VECTORC,0,0)
# define CC_VERNO CC_VECTOR
# define CC_VERSTR "codeplay vector c/c++"
# if (__VECTORC == 1)
#   define CC_VERSTR "codeplay vector c/c++"
# else
#   define CC_VERSTR "codeplay vector unknwon"
# endif
#elif defined _MSC_VER
# define CC_MSVC VERNO(0,_MSC_VER,0)
# define CC_VERNO CC_MSVC
# define CC_DESC "visual c++"
# if (_MSC_VER == 1020)
#   define CC_VERSTR "visual c++ 4.2"
# elif (_MSC_VER == 1100)
#   define CC_VERSTR "visual c++ 5.0"
# elif (_MSC_VER == 1200)
#   define CC_VERSTR "visual c++ 6.0"
# elif (_MSC_VER == 1300)
#   define CC_VERSTR "visual c++ .net (7.0)"
# elif (_MSC_VER == 1310)
#   define CC_VERSTR "visual c++ .net 2003 (7.1)"
# elif (_MSC_VER == 1400)
#   define CC_VERSTR "visual c++ .net 2005 (8.0)"
# elif (_MSC_VER == 1500)
#   define CC_VERSTR "visual c++ .net 2008 (9.0)"
# elif (_MSC_VER == 1600)
#   define CC_VERSTR "visual c++ .net 2010 (10.0)"
# elif (_MSC_VER == 1700)
#   define CC_VERSTR "visual c++ .net 2012 (11.0)"
# elif (_MSC_VER == 1800)
#   define CC_VERSTR "visual c++ .net 2013 (12.0)"
# elif (_MSC_VER == 1900)
#   define CC_VERSTR "visual c++ .net 2015 (14.0)"
# elif (_MSC_VER == 1910 || _MSC_VER == 1911)
#   define CC_VERSTR "visual c++ .net 2017 (14.1)"
# else
#   define CC_VERSTR "visual c++ unknwon"
# endif
# pragma warning(disable:4018)
# pragma warning(disable:4197)
# pragma warning(disable:4141)
# pragma warning(disable:4996)
# pragma warning(disable:4359)
# pragma warning(disable:4838)
#else
# define CC_DESC "unknown compiler"
# define CC_VERNO 0
# define CC_VERSTR "unknown compiler version"
# define CC_UNKNOWN
#endif

#define CC_BT(major, minor) (CC_VERNO>VERNO(major,minor,0))
#define CC_BE(major, minor) (CC_VERNO>=VERNO(major,minor,0))
#define CC_EQ(major, minor) (CC_VERNO==VERNO(major,minor,0))
#define CC_LT(major, minor) (CC_VERNO<VERNO(major,minor,0))
#define CC_LE(major, minor) (CC_VERNO<=VERNO(major,minor,0))

#endif /* !__UCC_CC_H */
