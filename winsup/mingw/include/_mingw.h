/*
 * _mingw.h
 *
 * Mingw specific macros included by ALL include files. 
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Mumit Khan  <khan@xraylith.wisc.edu>
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __MINGW_H
#define __MINGW_H

/* These are defined by the user (or the compiler)
   to specify how identifiers are imported from a DLL.

   __DECLSPEC_SUPPORTED    Defined if dllimport attribute is supported.
   __MINGW_IMPORT          The attribute definition to specify imported
                           variables/functions. 
   __MINGW32_VERSION       Runtime version.
   __MINGW32_MAJOR_VERSION Runtime major version.
   __MINGW32_MINOR_VERSION Runtime minor version.
   __MINGW32_BUILD_DATE    Runtime build date.
   
   Other macros:

   __int64                 define to be long long. Using a typedef can
                           tweak bugs in the C++ parser.
  
   All headers should include this first, and then use __DECLSPEC_SUPPORTED
   to choose between the old ``__imp__name'' style or __MINGW_IMPORT
   style declarations.  */

#ifndef __GNUC__
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT  __declspec(dllimport)
# endif
# define __DECLSPEC_SUPPORTED
#else /* __GNUC__ */
# ifdef __declspec
#  ifndef __MINGW_IMPORT

   /* Note the extern. This is needed to work around GCC's
      limitations in handling dllimport attribute.  */
#   define __MINGW_IMPORT  extern __attribute__((dllimport))
#   endif
#  define __DECLSPEC_SUPPORTED
# else /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
# endif 
# undef __int64
# define __int64 long long
#endif /* __GNUC__ */

#define __MINGW32_VERSION 2.4
#define __MINGW32_MAJOR_VERSION 2
#define __MINGW32_MINOR_VERSION 4

/*  ISO C++.  */
#ifndef __HAVE_STD_CXX
#if  __GNUC__ >= 3 && __GNUC_MINOR__ >= 3
#define __HAVE_STD_CXX 1
#else
#define __HAVE_STD_CXX 0
#endif
#endif

#ifdef __cplusplus
# if !(defined(__BEGIN_CSTD_NAMESPACE) \
       && defined(__END_CSTD_NAMESPACE))
#  if  __HAVE_STD_CXX
#   define __BEGIN_CSTD_NAMESPACE namespace std { extern "C" {
#   define __END_CSTD_NAMESPACE  } }
#   define __CSTD std::
#  else
#   define __BEGIN_CSTD_NAMESPACE extern "C" {
#   define __END_CSTD_NAMESPACE  }
#   define __CSTD
#  endif
# endif /* !defined(__BEGIN_CSTD_NAMESPACE) */ 
# if !(defined(__BEGIN_CGLOBAL_NAMESPACE) \
       && defined(__END_GLOBAL_NAMESPACE))
#  define __BEGIN_CGLOBAL_NAMESPACE extern "C" {
#  define __END_CGLOBAL_NAMESPACE  }
#  define __CGLOBAL ::
# endif /* !defined(__BEGIN_CGLOBAL_NAMESPACE) */ 
#else /* !__cplusplus */
# define __BEGIN_CSTD_NAMESPACE
# define __END_CSTD_NAMESPACE
# define __CSTD 
# define __BEGIN_CGLOBAL_NAMESPACE
# define __END_CGLOBAL_NAMESPACE
# define __CGLOBAL
#endif


#endif /* __MINGW_H */

