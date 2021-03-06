//$$CDS-header$$

#ifndef CDSLIB_COMPILER_GCC_DEFS_H
#define CDSLIB_COMPILER_GCC_DEFS_H

// Compiler version
#define CDS_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if CDS_COMPILER_VERSION < 40800
#   error "Compiler version error. GCC version 4.8.0 and above is supported"
#endif

// Compiler name
#ifdef __VERSION__
#   define  CDS_COMPILER__NAME    ("GNU C++ " __VERSION__)
#else
#   define  CDS_COMPILER__NAME    "GNU C++"
#endif
#define  CDS_COMPILER__NICK        "gcc"

#include <cds/compiler/gcc/compiler_macro.h>

#define alignof __alignof__

// ***************************************
// C++11 features

// C++11 inline namespace
#define CDS_CXX11_INLINE_NAMESPACE_SUPPORT

// constexpr
#define CDS_CONSTEXPR    constexpr

// noexcept
#define CDS_NOEXCEPT_SUPPORT        noexcept
#define CDS_NOEXCEPT_SUPPORT_(expr) noexcept(expr)

// C++11 thread_local keyword
#define CDS_CXX11_THREAD_LOCAL_SUPPORT

// Full SFINAE support
#define CDS_CXX11_SFINAE

// Inheriting constructors
#define CDS_CXX11_INHERITING_CTOR

// *************************************************
// Features
// If you run under Thread Sanitizer, pass -DCDS_THREAD_SANITIZER_ENABLED in compiler command line
//#define CDS_THREAD_SANITIZER_ENABLED

// *************************************************
// Alignment macro

#define CDS_TYPE_ALIGNMENT(n)   __attribute__ ((aligned (n)))
#define CDS_CLASS_ALIGNMENT(n)  __attribute__ ((aligned (n)))
#define CDS_DATA_ALIGNMENT(n)   __attribute__ ((aligned (n)))

// Attributes
#if CDS_COMPILER_VERSION >= 40900
#   if __cplusplus < 201103
#       define CDS_DEPRECATED( reason ) __attribute__((deprecated( reason )))
#   elif __cplusplus == 201103 // C++11
#       define CDS_DEPRECATED( reason ) [[gnu::deprecated(reason)]]
#   else  // C++14
#       define CDS_DEPRECATED( reason ) [[deprecated(reason)]]
#   endif
#else
#   define CDS_DEPRECATED( reason ) __attribute__((deprecated( reason )))
#endif

#include <cds/compiler/gcc/compiler_barriers.h>

#endif // #ifndef CDSLIB_COMPILER_GCC_DEFS_H
