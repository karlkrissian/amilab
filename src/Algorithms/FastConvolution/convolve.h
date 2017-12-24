/* Copyright (C) 2012 Henry Gomersall <heng@cantab.net> 
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the organization nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY  THE AUTHOR ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef _CONVOLVE_H
#define _CONVOLVE_H

#include "AMILabConfig.h"

#ifndef __GCCXML__
  #ifdef AMI_USE_SSE 
    #define SSE3
  #endif

  #if defined SSE3 || defined AVX
  #include <immintrin.h>
  #endif
#endif


/* A macro that outputs a wrapper for each of the convolution routines.
 * The macro passed a name conv_func will output a function called
 * conv_func_multiple and it will have signature:
 * conv_func_multiple(float* in, float* out, int length,
 *                    float* kernel, int kernel_length, int N)
 * 
 * The additional N defines how many times to run the convolution function
 * conv_func(float* in, float* out, int length,
 *                    float* kernel, int kernel_length)
 * */
#ifndef MULTIPLE_CONVOLVE

#define MULTIPLE_CONVOLVE(FUNCTION_NAME) 

// int FUNCTION_NAME ## _multiple(float* in, float* out, int length, \
//         float* kernel, int kernel_length, int N) \
// { \
//   int i; \
//     for(i=0; i<N; i++){ \
//         FUNCTION_NAME(in, out, length, kernel, kernel_length); \
//     } \
//  \
//     return 0; \
// }
#endif

inline int convolve_naive(float* in, float* out, int length,
        float* kernel, int kernel_length);

#ifdef SSE3

inline __m128* sse_prepare_kernel_reverse( float* kernel, int kernel_length);

// force multiple of 4 kernel by padding with 0
inline __m128* sse_prepare_kernel_reverse_x4( float* kernel, 
                                              int kernel_length,
                                              int& new_kernel_length
                                            );

inline void    sse_free_kernel           (__m128* kernel);

inline int convolve_sse_simple_prepared(float* in, float* out, int length,
                                        __m128* kernel, int kernel_length);

inline int convolve_sse_simple(         float* in, float* out, int length,
                                        float* kernel, int kernel_length);

inline int convolve_sse_partial_unroll_prepared( 
                                        float* in, float* out, int length,
                                        __m128* kernel, int kernel_length);

inline int convolve_sse_partial_unroll( float* in, float* out, int length,
                                        float* kernel, int kernel_length);


// process 4 lines in a row
inline int convolve_sse_x4_prepared(  __m128* in, __m128* out, int length,
                                      __m128* kernel, int kernel_length);


// process 4 lines in a row with symmetric kernel
inline int convolve_sse_x4_prepared_sym(  __m128* in, __m128* out, int length,
                                          __m128* kernel_reverse, 
                                          int kernel_radius);

// process 4 lines in a row with asymmetric kernel
inline int convolve_sse_x4_prepared_asym(  __m128* in, __m128* out, int length,
                                           __m128* kernel_reverse, 
                                           int kernel_radius);

inline int convolve_sse_in_aligned(float* in, float* out, const int length,
        float* kernel, const int kernel_length);

inline int convolve_sse_in_aligned_fixed_kernel(float* in, float* out, int length,
        float* kernel, int kernel_length);

inline int convolve_sse_unrolled_avx_vector(float* in, float* out, int length,
        float* kernel, int kernel_length);

inline int convolve_sse_unrolled_vector(float* in, float* out, int length,
        float* kernel, int kernel_length);

#endif

#ifdef AVX
inline int convolve_avx_unrolled_vector(float* in, float* out, int length,
        float* kernel, int kernel_length);

inline int convolve_avx_unrolled_vector_partial_aligned(
        float* in, float* out, int length,
        float* kernel, int kernel_length);
#endif

#ifndef __GCCXML__
#include "convolve.cpp"
#endif // __GCCXML__

#endif /*Header guard*/
