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

/*!@file ucc/os.h
 * @author uael
 */
#ifndef __UCC_OS_H
# define __UCC_OS_H

#if defined __pnacl__
# define OS_PNACL __pnacl__
#elif defined __ANDROID__
# define OS_ANDROID __ANDROID__
#elif defined __TIZEN__
# define OS_TIZEN __TIZEN__
#elif defined __APPLE__ && \
      (defined __GNUC__ || defined __xlC__ || defined __xlc__)
# define OS_DARWIN
# define OS_BSD4
# ifdef __LP64__
#   define OS_DARWIN64
# else
#   define OS_DARWIN32
# endif
# elif defined Macintosh || defined macintosh
# define OS_MAC9
#elif defined __MSYS__
# define OS_MSYS
#elif defined __CYGWIN__
# define OS_CYGWIN
#elif defined _WIN64 || defined _M_X64 || defined _M_AMD64
# define OS_WIN64
#elif defined __WIN32__ || defined _WIN32 || defined WIN32
# define OS_WIN
#elif defined __linux || defined __linux__
# define OS_LINUX
#elif defined __FreeBSD__
# define OS_FREEBSD
# define OS_BSD4
#elif defined __DragonFly__
# define OS_DRAGONFLY
# define OS_BSD4
#elif defined __NetBSD__
# define OS_NETBSD
# define OS_BSD4
#elif defined __OpenBSD__
# define OS_OPENBSD
# define OS_BSD4
#elif defined _AIX
# define OS_AIX
#elif defined hpux || defined __hpux
# define OS_HPUX
#elif defined __osf__ || defined __osf
# define OS_TRU64
#elif defined __sun || defined sun
# define OS_SOLARIS
#elif defined __QNXNTO__
# ifdef __BLACKBERRY10__
#   define OS_BB10
# else
#   define OS_QNX6
# endif
#elif defined __QNX__
# define OS_QNX
#elif defined _SCO_DS
# define OS_SCO
#elif defined __USLC__ || defined __UNIXWARE__
# define OS_UNIXWARE
#elif defined __svr4__ && defined i386
# define OS_UNIXWARE
#elif defined __sgi || defined sgi
# define OS_IRIX
#elif defined __HAIKU__
# define OS_HAIKU
#elif defined __SYLLABLE__
# define OS_SYLLABLE
#elif defined __BEOS__
# define OS_BEOS
#elif defined __OS2__
# define OS_OS2
#elif defined VMS || defined __VMS
# define OS_VMS
#endif

#ifdef OS_WIN64
# define OS_WIN
#endif

#if defined OS_DARWIN
# define OS_MAC
# if defined OS_DARWIN64
#   define OS_MAC64
# elif defined OS_DARWIN32
#   define OS_MAC32
# endif
#endif

#if defined OS_WIN || defined OS_MAC9 || defined OS_HAIKU || \
  defined OS_BEOS || defined OS_OS2 || defined OS_VMS || defined OS_PNACL
# undef OS_UNIX
#elif !defined OS_UNIX
# define OS_UNIX
#endif

#ifdef OS_WIN
# define EOL "\r\n"
# define DS "\\"
#else
# define EOL "\n"
# define DS "/"
#endif

#endif /* !__UCC_OS_H */
