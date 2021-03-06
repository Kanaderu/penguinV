#pragma once

// This file is very important to setup penguinV library to have the best performance
// Please be very carefull in setting these parameters!!!

#ifdef _WIN32 // Windows

#include "cpu_id_windows.h"

    #ifdef _M_ARM
        #define PENGUINV_NEON_SET
    #else
        #define PENGUINV_SSE_SET

        #ifdef _MSC_VER
            #if _MSC_VER >= 1700
                #define PENGUINV_AVX_SET
            #endif
        #endif
    #endif
#elif __APPLE__ // MacOS

#include "cpu_id_macos.h"

    #ifdef __arm__
        #define PENGUINV_NEON_SET
    #elif __SSE2__
        #define PENGUINV_SSE_SET

        #ifdef __AVX2__
            #define PENGUINV_AVX_SET
        #endif
    #endif

#elif __linux__ // Linux

#include "cpu_id_linux.h"

    #ifdef __arm__
        #define PENGUINV_NEON_SET
    #elif __SSE2__
        #define PENGUINV_SSE_SET
    
        #ifdef __AVX2__
            #define PENGUINV_AVX_SET
        #endif
    #endif

#else
    #error "Unknown platform. Is your OS Windows or OSX or Linux?"
#endif

// We verify SIMD instruction set definition
#ifdef PENGUINV_NEON_SET

    #ifdef PENGUINV_SSE_SET
        #error "NEON and SSE cannot be supported on a single CPU. Please check SIMD instruction set verification code"
    #endif
    
    #ifdef PENGUINV_AVX_SET
        #error "NEON and AVX cannot be supported on a single CPU. Please check SIMD instruction set verification code"
    #endif

#endif

#ifdef PENGUINV_AVX_SET
    #ifndef PENGUINV_SSE_SET
        #error "Non of available processor cannot support only AVX without SSE support. Please check SIMD instruction set verification code"
    #endif
#endif

// Identify available technologies during runtime
#ifdef PENGUINV_SSE_SET
static const bool isSseAvailable  = CpuInformation::isSseSupported();
#else
static const bool isSseAvailable  = false;
#endif

#ifdef PENGUINV_AVX_SET
static const bool isAvxAvailable  = CpuInformation::isAvxSupported();
#else
static const bool isAvxAvailable  = false;
#endif

#ifdef PENGUINV_NEON_SET
static const bool isNeonAvailable = CpuInformation::isNeonSupported();
#else
static const bool isNeonAvailable = false;
#endif
