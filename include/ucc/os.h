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
# define OS_POSIX OS_ANDROID
#elif defined __TIZEN__
# define OS_TIZEN __TIZEN__
# define OS_POSIX OS_TIZEN
#elif defined __APPLE__ && __APPLE__
# define OS_APPLE __APPLE__
# define OS_POSIX OS_APPLE
#elif defined __MACH__
# define OS_MACOS __MACH__
#elif defined __linux__
# define OS_LINUX __linux__
# define OS_POSIX OS_LINUX
#elif defined __linux
# define OS_LINUX __linux
# define OS_POSIX OS_LINUX
#elif defined __BSD__
# define OS_BSD __BSD__
# define OS_POSIX OS_BSD
#elif defined __FreeBSD__
# define OS_BSD __FreeBSD__
# define OS_POSIX OS_BSD
#elif defined _WIN64
# define OS_WIN _WIN64
# define OS_WIN64 OS_WIN
#elif defined _WIN32
# define OS_WIN _WIN32
# define OS_WIN32 OS_WIN
#elif defined __WIN32__
# define OS_WIN __WIN32__
# define OS_WIN32 OS_WIN
#else
# define OS_UNKNOWN
#endif

#endif /* !__UCC_OS_H */
