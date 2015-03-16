//
// C++ Implementation: RecursiveGaussianConvolution1D
//
// Description:
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "amiRecursiveGaussianConvolution1D.h"
#include "amiImageExtent.h"
#include "amilab_messages.h"
#include <iostream>
#include "Timing.hpp"
#include <typeinfo>
#include "convolve.h"
#include <complex>

// SSE2 header
#include <xmmintrin.h>

// SSE3 header
#include <pmmintrin.h>

#include <iostream>

#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

#ifndef macro_max
#define macro_max(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef macro_min
#define macro_min(a,b) (((a)<(b))?(a):(b))
#endif


#ifdef _MSC_VER
  #define bzero(s,n) memset ((s), 0, (n))
  #define ALIGN16( __Declaration__ ) \
    __declspec( align( 16 ) )  __Declaration__ 

    //__pragma( pack(push, 1) ) 
    //__pragma( pack(pop) )
#else
    #define ALIGN16( __Declaration__ ) \
      __Declaration__ __attribute__ ((aligned (16)))
#endif

namespace ami {

//------------------------------------------------------------------------------
/**
 * Compute the N coefficients.
 */
void RecursiveGaussianConvolution1D
::ComputeNCoefficients ( ScalarRealType sigmad,
                         ScalarRealType A1, ScalarRealType B1, ScalarRealType W1, ScalarRealType L1,
                         ScalarRealType A2, ScalarRealType B2, ScalarRealType W2, ScalarRealType L2,
                         ScalarRealType& N0, ScalarRealType& N1, ScalarRealType& N2, ScalarRealType& N3,
                         ScalarRealType& SN, ScalarRealType& DN, ScalarRealType& EN )
{
	ScalarRealType Sin1 = sin ( W1 / sigmad );
	ScalarRealType Sin2 = sin ( W2 / sigmad );
	ScalarRealType Cos1 = cos ( W1 / sigmad );
	ScalarRealType Cos2 = cos ( W2 / sigmad );
	ScalarRealType Exp1 = exp ( L1 / sigmad );
	ScalarRealType Exp2 = exp ( L2 / sigmad );

	N0  = A1 + A2;
	N1  = Exp2 * ( B2 * Sin2 - ( A2 + 2 * A1 ) * Cos2 );
	N1 += Exp1 * ( B1 * Sin1 - ( A1 + 2 * A2 ) * Cos1 );
	N2  = ( A1 + A2 ) * Cos2 * Cos1;
	N2 -= B1 * Cos2 * Sin1 + B2 * Cos1 * Sin2;
	N2 *= 2 * Exp1 * Exp2;
	N2 += A2 * Exp1 * Exp1 + A1 * Exp2 * Exp2;
	N3  = Exp2 * Exp1 * Exp1 * ( B2 * Sin2 - A2 * Cos2 );
	N3 += Exp1 * Exp2 * Exp2 * ( B1 * Sin1 - A1 * Cos1 );

	SN = N0 + N1 + N2 + N3;
	DN = N1 + 2 * N2 + 3 * N3;
	EN = N1 + 4 * N2 + 9 * N3;
}


//------------------------------------------------------------------------------
/**
 * Compute the D coefficients.
 */
void RecursiveGaussianConvolution1D
::ComputeDCoefficients ( ScalarRealType sigmad,
                         ScalarRealType W1, ScalarRealType L1, ScalarRealType W2, ScalarRealType L2,
                         ScalarRealType& SD, ScalarRealType& DD, ScalarRealType& ED )
{
	//  const ScalarRealType Sin1 = vcl_sin(W1 / sigmad);
	//  const ScalarRealType Sin2 = vcl_sin(W2 / sigmad);
	const ScalarRealType Cos1 = cos ( W1 / sigmad );
	const ScalarRealType Cos2 = cos ( W2 / sigmad );
	const ScalarRealType Exp1 = exp ( L1 / sigmad );
	const ScalarRealType Exp2 = exp ( L2 / sigmad );

	this->m_D4 = Exp1 * Exp1 * Exp2 * Exp2;
	this->m_D3 = -2 * Cos1 * Exp1 * Exp2 * Exp2;
	this->m_D3 += -2 * Cos2 * Exp2 * Exp1 * Exp1;
	this->m_D2 = 4 * Cos2 * Cos1 * Exp1 * Exp2;
	this->m_D2 += Exp1 * Exp1 + Exp2 * Exp2;
	this->m_D1 = -2 * ( Exp2 * Cos2 + Exp1 * Cos1 );

	SD = 1.0 + this->m_D1 + this->m_D2 + this->m_D3 + this->m_D4;
	DD = this->m_D1 + 2 * this->m_D2 + 3 * this->m_D3 + 4 * this->m_D4;
	ED = this->m_D1 + 4 * this->m_D2 + 9 * this->m_D3 + 16 * this->m_D4;
}


//------------------------------------------------------------------------------
/**
 * Compute the M coefficients and the boundary coefficients.
 */
void RecursiveGaussianConvolution1D
::ComputeRemainingCoefficients ( bool symmetric )
{
	if ( symmetric ) {
		this->m_M1 = this->m_N1 - this->m_D1 * this->m_N0;
		this->m_M2 = this->m_N2 - this->m_D2 * this->m_N0;
		this->m_M3 = this->m_N3 - this->m_D3 * this->m_N0;
		this->m_M4 =            -this->m_D4 * this->m_N0;
	}
	else {
		this->m_M1 = - ( this->m_N1 - this->m_D1 * this->m_N0 );
		this->m_M2 = - ( this->m_N2 - this->m_D2 * this->m_N0 );
		this->m_M3 = - ( this->m_N3 - this->m_D3 * this->m_N0 );
		this->m_M4 =                 this->m_D4 * this->m_N0;
	}

	// Compute coefficients to be used at the boundaries
	// in order to simulate edge extension boundary conditions.
	const ScalarRealType SN = this->m_N0 + this->m_N1 + this->m_N2 + this->m_N3;
	const ScalarRealType SM = this->m_M1 + this->m_M2 + this->m_M3 + this->m_M4;
	const ScalarRealType SD = 1.0 + this->m_D1 + this->m_D2 + this->m_D3 + this->m_D4;

	this->m_BN1 = this->m_D1 * SN / SD;
	this->m_BN2 = this->m_D2 * SN / SD;
	this->m_BN3 = this->m_D3 * SN / SD;
	this->m_BN4 = this->m_D4 * SN / SD;

	this->m_BM1 = this->m_D1 * SM / SD;
	this->m_BM2 = this->m_D2 * SM / SD;
	this->m_BM3 = this->m_D3 * SM / SD;
	this->m_BM4 = this->m_D4 * SM / SD;
}


//------------------------------------------------------------------------------
void RecursiveGaussianConvolution1D::SetUp ( ScalarRealType spacing )
{
	const ScalarRealType spacingTolerance = 1e-8;

	/**  Parameters of exponential series. */
	ScalarRealType A1[3];
	ScalarRealType B1[3];
	ScalarRealType W1;
	ScalarRealType L1;
	ScalarRealType A2[3];
	ScalarRealType B2[3];
	ScalarRealType W2;
	ScalarRealType L2;

	ScalarRealType direction = 1.0;

	if ( spacing < 0.0 ) {
		direction = -1.0;
		spacing = -spacing;
	}

	if ( spacing < spacingTolerance ) {
		std::cerr 	<< "The spacing " << spacing
		            << "is suspiciosly small in this image" << std::endl;
	}

	const ScalarRealType sigmad = _sigma / spacing;
	ScalarRealType       across_scale_normalization = 1.0;


	A1[0] = static_cast< ScalarRealType > ( 1.3530 );
	B1[0] = static_cast< ScalarRealType > ( 1.8151 );
	W1    = static_cast< ScalarRealType > ( 0.6681 );
	L1    = static_cast< ScalarRealType > ( -1.3932 );
	A2[0] = static_cast< ScalarRealType > ( -0.3531 );
	B2[0] = static_cast< ScalarRealType > ( 0.0902 );
	W2    = static_cast< ScalarRealType > ( 2.0787 );
	L2    = static_cast< ScalarRealType > ( -1.3732 );

	A1[1] = static_cast< ScalarRealType > ( -0.6724 );
	B1[1] = static_cast< ScalarRealType > ( -3.4327 );
	A2[1] = static_cast< ScalarRealType > ( 0.6724 );
	B2[1] = static_cast< ScalarRealType > ( 0.6100 );

	A1[2] = static_cast< ScalarRealType > ( -1.3563 );
	B1[2] = static_cast< ScalarRealType > ( 5.2318 );
	A2[2] = static_cast< ScalarRealType > ( 0.3446 );
	B2[2] = static_cast< ScalarRealType > ( -2.2355 );

	ScalarRealType SD, DD, ED;
	this->ComputeDCoefficients ( sigmad, W1, L1, W2, L2, SD, DD, ED );
	ScalarRealType SN, DN, EN;

	switch ( _order ) {
		case 0: {
			// Approximation of convolution with a gaussian.
			ComputeNCoefficients ( sigmad,
			                       A1[0], B1[0], W1, L1,
			                       A2[0], B2[0], W2, L2,
			                       this->m_N0,
			                       this->m_N1,
			                       this->m_N2,
			                       this->m_N3,
			                       SN, DN, EN );

			ScalarRealType alpha0 = 2 * SN / SD - this->m_N0;
			this->m_N0 *= across_scale_normalization / alpha0;
			this->m_N1 *= across_scale_normalization / alpha0;
			this->m_N2 *= across_scale_normalization / alpha0;
			this->m_N3 *= across_scale_normalization / alpha0;
			const bool symmetric = true;
			this->ComputeRemainingCoefficients ( symmetric );
			break;
		}

		case 1: {
			across_scale_normalization =  _sigma;
			// Approximation of convolution with the first derivative of a  Gaussian
			ComputeNCoefficients ( sigmad,
			                       A1[1], B1[1], W1, L1,
			                       A2[1], B2[1], W2, L2,
			                       this->m_N0, this->m_N1, this->m_N2, this->m_N3,
			                       SN, DN, EN );

			ScalarRealType alpha1 = 2 * ( SN * DD - DN * SD ) / ( SD * SD );
			// If negative spacing, negate the first derivative response.
			alpha1 *= direction;

			this->m_N0 *= across_scale_normalization / alpha1;
			this->m_N1 *= across_scale_normalization / alpha1;
			this->m_N2 *= across_scale_normalization / alpha1;
			this->m_N3 *= across_scale_normalization / alpha1;

			const bool symmetric = false;
			this->ComputeRemainingCoefficients ( symmetric );
			break;
		}

		case 2: {
			across_scale_normalization = _sigma * _sigma;
			// Approximation of convolution with the second derivative of a
			// Gaussian.
			ScalarRealType N0_0, N1_0, N2_0, N3_0;
			ScalarRealType N0_2, N1_2, N2_2, N3_2;
			ScalarRealType SN0, DN0, EN0;
			ScalarRealType SN2, DN2, EN2;
			ComputeNCoefficients ( sigmad,
			                       A1[0], B1[0], W1, L1,
			                       A2[0], B2[0], W2, L2,
			                       N0_0, N1_0, N2_0, N3_0,
			                       SN0, DN0, EN0 );
			ComputeNCoefficients ( sigmad,
			                       A1[2], B1[2], W1, L1,
			                       A2[2], B2[2], W2, L2,
			                       N0_2, N1_2, N2_2, N3_2,
			                       SN2, DN2, EN2 );

			ScalarRealType beta = - ( 2 * SN2 - SD * N0_2 ) / ( 2 * SN0 - SD * N0_0 );
			this->m_N0 = N0_2 + beta * N0_0;
			this->m_N1 = N1_2 + beta * N1_0;
			this->m_N2 = N2_2 + beta * N2_0;
			this->m_N3 = N3_2 + beta * N3_0;
			SN = SN2 + beta * SN0;
			DN = DN2 + beta * DN0;
			EN = EN2 + beta * EN0;

			ScalarRealType alpha2;
			alpha2  = EN * SD * SD - ED * SN * SD - 2 * DN * DD * SD + 2 * DD * DD * SN;
			alpha2 /= SD * SD * SD;

			this->m_N0 *= across_scale_normalization / alpha2;
			this->m_N1 *= across_scale_normalization / alpha2;
			this->m_N2 *= across_scale_normalization / alpha2;
			this->m_N3 *= across_scale_normalization / alpha2;

			const bool symmetric = true;
			this->ComputeRemainingCoefficients ( symmetric );
			break;
		}

		default: {
			std::cerr << "Unknown Order" << std::endl;
			return;
		}
	}
}

//------------------------------------------------------------------------------
/**
 * Apply Recursive Filter
 */
template <class T>
__attribute__((optimize("unroll-loops")))
void RecursiveGaussianConvolution1D
::FilterDataArray (	T* outs, const T* data,
                    T* scratch, const unsigned int& ln )
{
	/**
	 * Causal direction pass
	 */

	// this value is assumed to exist from the border to infinity.
	const T outV1 = data[0];

	/**
	 * Initialize borders
	 */
	scratch[0] = T ( outV1   * m_N0 +   outV1 * m_N1 + outV1   * m_N2 + outV1 * m_N3 );
	scratch[1] = T ( data[1] * m_N0 +   outV1 * m_N1 + outV1   * m_N2 + outV1 * m_N3 );
	scratch[2] = T ( data[2] * m_N0 + data[1] * m_N1 + outV1   * m_N2 + outV1 * m_N3 );
	scratch[3] = T ( data[3] * m_N0 + data[2] * m_N1 + data[1] * m_N2 + outV1 * m_N3 );

	// note that the outV1 value is multiplied by the Boundary coefficients m_BNi
	scratch[0] -= T ( outV1      * m_BN1 + outV1      * m_BN2 + outV1      * m_BN3 + outV1 * m_BN4 );
	scratch[1] -= T ( scratch[0] * m_D1  + outV1      * m_BN2 + outV1      * m_BN3  + outV1 * m_BN4 );
	scratch[2] -= T ( scratch[1] * m_D1  + scratch[0] * m_D2  + outV1      * m_BN3  + outV1 * m_BN4 );
	scratch[3] -= T ( scratch[2] * m_D1  + scratch[1] * m_D2  + scratch[0] * m_D3   + outV1 * m_BN4 );

	/**
	 * Recursively filter the rest
	 */
	for ( unsigned int i = 4; i < ln; i++ ) {
		scratch[i]  = data[i]     * m_N0 + data[i - 1]   * m_N1 + data[i - 2]   * m_N2 + data[i - 3]   * m_N3;
		scratch[i] -= scratch[i - 1] * m_D1 + scratch[i - 2] * m_D2 + scratch[i - 3] * m_D3 + scratch[i - 4] * m_D4;
	}

	/**
	 * Store the causal result
	 */
	memcpy(outs,scratch,ln*sizeof(float));
// 	for ( unsigned int i = 0; i < ln; i++ ) {
// 		outs[i] = scratch[i];
// 	}

	/**
	 * AntiCausal direction pass
	 */

	// this value is assumed to exist from the border to infinity.
	const T outV2 = data[ln - 1];

	/**
	 * Initialize borders
	 */
	scratch[ln - 1] = T ( outV2      * m_M1 + outV2      * m_M2 + outV2      * m_M3 + outV2 * m_M4 );
	scratch[ln - 2] = T ( data[ln - 1] * m_M1 + outV2      * m_M2 + outV2      * m_M3 + outV2 * m_M4 );
	scratch[ln - 3] = T ( data[ln - 2] * m_M1 + data[ln - 1] * m_M2 + outV2      * m_M3 + outV2 * m_M4 );
	scratch[ln - 4] = T ( data[ln - 3] * m_M1 + data[ln - 2] * m_M2 + data[ln - 1] * m_M3 + outV2 * m_M4 );

	// note that the outV2value is multiplied by the Boundary coefficients m_BMi
	scratch[ln - 1] -= T ( outV2         * m_BM1 + outV2         * m_BM2 + outV2         * m_BM3 + outV2 * m_BM4 );
	scratch[ln - 2] -= T ( scratch[ln - 1] * m_D1  + outV2         * m_BM2 + outV2         * m_BM3 + outV2 * m_BM4 );
	scratch[ln - 3] -= T ( scratch[ln - 2] * m_D1  + scratch[ln - 1] * m_D2  + outV2         * m_BM3 + outV2 * m_BM4 );
	scratch[ln - 4] -= T (
	                       scratch[ln - 3] * m_D1  + scratch[ln - 2] * m_D2  + scratch[ln - 1] * m_D3  + outV2 * m_BM4 );

	outs[ln-1] += scratch[ln-1];
	outs[ln-2] += scratch[ln-2];
	outs[ln-3] += scratch[ln-3];
	outs[ln-4] += scratch[ln-4];

	/**
	 * Recursively filter the rest
	 */
	for ( unsigned int i = ln - 4; i > 0; i-- ) {
		scratch[i - 1]  = data[i]   * m_M1 + data[i + 1]   * m_M2 + data[i + 2]   * m_M3 + data[i + 3]   * m_M4;
		scratch[i - 1] -= scratch[i] * m_D1 + scratch[i + 1] * m_D2 + scratch[i + 2] * m_D3 + scratch[i + 3] * m_D4;
		outs[i-1] += scratch[i-1];
	}

	/**
	 * Roll the antiCausal part into the output
	 */
// 	for ( unsigned int i = 0; i < ln; i++ ) {
// 	}
}

//------------------------------------------------------------------------------
/**
 * Apply Recursive Filter
 */
__attribute__((optimize("unroll-loops")))
void FilterDataArray_Float_New(float *outs, 
							   const float *data,
							   float *scratch, 
							   const unsigned int& ln)
{
	// Compute \lambda \sum_{n=1}^{\infty} e^{-\alpha \frac{n}{\sigma} } . u_n
	// where u_n = I(x-n) or I(x+n) at the pixel position x

	// we denote \beta = \frac{\alpha}{\sigma}

	//const 
	float sigma;

	// complex alpha
	//const 
	std::complex<float> alpha;
	
	// complex beta
	//const 
	std::complex<float> beta = alpha/sigma;
	
	// complex lambda
	//const 
	std::complex<float> lambda;
	
	// we multiply by lambda at the end
	// so we need to compute \sum_{n=1}^{\infty} e^{-\beta n } . u_n
	// for a constant value, we have S = \sum_{n=1}^{\infty} e^{-\beta n } = e^-\beta / (1-e^-\beta)
	// so the first value will be S.u[0]
	
	std::complex<float> S = exp(-beta)/(-exp(-beta)+std::complex<float>(1,0));
}

//------------------------------------------------------------------------------
inline float SSE_DOTPRODUCT(const __m128& a, const __m128& b)
{
	float res;
	ALIGN16(__m128 v);
	v = _mm_mul_ps(a, b); 
	v = _mm_hadd_ps(v, v); 
	v = _mm_hadd_ps(v, v); 
	_mm_store_ss(&res, v);
	return res;
}

//------------------------------------------------------------------------------
void RecursiveGaussianConvolution1D::FilterDataArray_Float_SSE2 (
    float* outs,
    const float* data,
    float* scratch,
    const unsigned int& ln )
{
	/**
	 * Causal direction pass
	 */

	// this value is assumed to exist from the border to infinity.
	const float outV1 = data[0];

	/**
	 * Initialize borders
	 */

	ALIGN16(__m128 mm_Ncoeffs);
	ALIGN16(__m128 mm_Dcoeffs);
	ALIGN16(__m128 mm_Mcoeffs);

	ALIGN16(__m128 data_val);
	ALIGN16(__m128 scratch_val);
	ALIGN16(__m128 data_block);
	ALIGN16(__m128 outs_block);
	ALIGN16(__m128 data_block1);
	ALIGN16(__m128 data_block2);


	// run initialization with SSE
// 		outs[0] = outV1   * m_N0 +   outV1 * m_N1 + outV1   * m_N2 + outV1 * m_N3;
// 		outs[1] = data[1] * m_N0 +   outV1 * m_N1 + outV1   * m_N2 + outV1 * m_N3;
// 		outs[2] = data[2] * m_N0 + data[1] * m_N1 + outV1   * m_N2 + outV1 * m_N3;
// 		outs[3] = data[3] * m_N0 + data[2] * m_N1 + data[1] * m_N2 + outV1 * m_N3;

	outs_block = _mm_mul_ps( _mm_setr_ps(outV1,data[1],data[2],data[3]),
							 _mm_set1_ps(m_N0));
	outs_block = _mm_add_ps(outs_block,
							_mm_mul_ps(_mm_setr_ps(outV1,outV1,data[1],data[2]),
									   _mm_set1_ps(m_N1)));
	outs_block = _mm_add_ps(outs_block,
							_mm_mul_ps(_mm_setr_ps(outV1,outV1,outV1,data[1]),
									   _mm_set1_ps(m_N2)));
	outs_block = _mm_add_ps(outs_block,
							_mm_mul_ps(_mm_set1_ps(outV1),
									   _mm_set1_ps(m_N3)));

 	_mm_storeu_ps(outs,outs_block);


	// note that the outV1 value is multiplied by the Boundary coefficients m_BNi
// 	outs[0] -= outV1   * m_BN1 + outV1   * m_BN2 + outV1   * m_BN3  + outV1 * m_BN4;
// 	outs[1] -= outs[0] * m_D1  + outV1   * m_BN2 + outV1   * m_BN3  + outV1 * m_BN4;
// 	outs[2] -= outs[1] * m_D1  + outs[0] * m_D2  + outV1   * m_BN3  + outV1 * m_BN4;
// 	outs[3] -= outs[2] * m_D1  + outs[1] * m_D2  + outs[0] * m_D3   + outV1 * m_BN4;

	outs[0] -= SSE_DOTPRODUCT(_mm_set1_ps(outV1),_mm_setr_ps(m_BN1,m_BN2,m_BN3,m_BN4));
	outs[1] -= SSE_DOTPRODUCT(_mm_setr_ps(outs[0],outV1,outV1,outV1),    _mm_setr_ps(m_D1,m_BN2,m_BN3,m_BN4));
	outs[2] -= SSE_DOTPRODUCT(_mm_setr_ps(outs[1],outs[0],outV1,outV1),  _mm_setr_ps(m_D1,m_D2,m_BN3,m_BN4));
	outs[3] -= SSE_DOTPRODUCT(_mm_setr_ps(outs[2],outs[1],outs[0],outV1),_mm_setr_ps(m_D1,m_D2,m_D3,m_BN4));
	

	/**
	 * Recursively filter the rest
	 */
	ALIGN16(__m128 r1);
	ALIGN16(__m128 r2);
	ALIGN16(__m128 diff);
	float val1,val2;

	// 1: load (m_N3,m_N2,m_N1,m_N0) vector
	mm_Ncoeffs = _mm_setr_ps ( m_N3, m_N2,m_N1,m_N0);
	// 2: load (m_D4,m_D3,m_D2,m_D1) vector
	mm_Dcoeffs  = _mm_setr_ps ( m_D4,m_D3, m_D2, m_D1);

	register float val1_2,val2_2;

	register const float* data_ptr1;
	register float* outs_ptr1;

	data_ptr1 = data 	- 3;
	outs_ptr1 = outs	- 4;
	for (  int i = 4; i < ln; i++ ) {
		// 		scratch[i]  = data[i]     * m_N0 + data[i - 1]   * m_N1 + data[i - 2]   * m_N2 + data[i - 3]   * m_N3;
		data_block1 = _mm_loadu_ps(&data_ptr1[i]);
		r1 = _mm_mul_ps(data_block1, mm_Ncoeffs);
		
		data_block2 = _mm_loadu_ps(&outs_ptr1[i]);
		r2 = _mm_mul_ps(data_block2, mm_Dcoeffs);
		
		diff = _mm_sub_ps(r1,r2);
 		diff = _mm_hadd_ps(diff, diff);
 		diff = _mm_hadd_ps(diff, diff);
		_mm_store_ss(&outs[i], diff);
		
// 		val1 = outs[i];
// 		val2  = data[i]     * m_N0 + data[i - 1]   * m_N1 + data[i - 2]   * m_N2 + data[i - 3]   * m_N3;
// 		val2 -= outs[i - 1] * m_D1 + outs[i - 2] * m_D2 + outs[i - 3] * m_D3 + outs[i - 4] * m_D4;
// 		
// 		if (fabsf(val1-val2)>1E-3) {
// 			std::cout << "pb" << std::endl;
// 		}
	}

	/**
	 * Store the causal result
	 */
//	memcpy(outs,scratch,ln*sizeof(float));
// 	for ( unsigned int i = 0; i < ln; i++ ) {
// 		outs[i] = scratch[i];
// 	}

	/**
	 * AntiCausal direction pass
	 */

	// this value is assumed to exist from the border to infinity.
	const float outV2 = data[ln - 1];

	/**
	 * Initialize borders
	 */
	scratch[ln - 1] = outV2        * m_M1 + outV2        * m_M2 + outV2        * m_M3 + outV2 * m_M4;
	scratch[ln - 2] = data[ln - 1] * m_M1 + outV2        * m_M2 + outV2        * m_M3 + outV2 * m_M4;
	scratch[ln - 3] = data[ln - 2] * m_M1 + data[ln - 1] * m_M2 + outV2        * m_M3 + outV2 * m_M4;
	scratch[ln - 4] = data[ln - 3] * m_M1 + data[ln - 2] * m_M2 + data[ln - 1] * m_M3 + outV2 * m_M4;

	// note that the outV2value is multiplied by the Boundary coefficients m_BMi
	scratch[ln - 1] -= outV2        * m_BM1 + outV2        * m_BM2 + outV2        * m_BM3 + outV2 * m_BM4;
	scratch[ln - 2] -= scratch[ln - 1] * m_D1  + outV2        * m_BM2 + outV2        * m_BM3 + outV2 * m_BM4;
	scratch[ln - 3] -= scratch[ln - 2] * m_D1  + scratch[ln - 1] * m_D2  + outV2        * m_BM3 + outV2 * m_BM4;
	scratch[ln - 4] -= scratch[ln - 3] * m_D1  + scratch[ln - 2] * m_D2  + scratch[ln - 1] * m_D3  + outV2 * m_BM4;
	
	outs[ln-1] += scratch[ln-1];
	outs[ln-2] += scratch[ln-2];
	outs[ln-3] += scratch[ln-3];
	outs[ln-4] += scratch[ln-4];

	/**
	 * Recursively filter the rest
	 */
	// 1: load (m_M1,m_M2,m_M3,m_M4) vector
	mm_Mcoeffs = _mm_setr_ps ( m_M1, m_M2, m_M3, m_M4 );

	// 2: load (m_D4,m_D3,m_D2,m_D1) vector
	mm_Dcoeffs  = _mm_setr_ps ( m_D1, m_D2, m_D3, m_D4 );
	

	register float* scratch_ptr;
	scratch_ptr  = scratch - 1;
	outs_ptr1 = outs-1;
	register float val;
	for ( int i = ln - 4; i > 0; i-- ) {

		//scratch[i - 1]  = data[i]   * m_M1 + data[i + 1]   * m_M2 + data[i + 2]   * m_M3 + data[i + 3]   * m_M4;
		data_block = _mm_loadu_ps(&data[i]);
		r1 = _mm_mul_ps(data_block, mm_Mcoeffs);

		//scratch[i - 1] -= scratch[i] * m_D1 + scratch[i + 1] * m_D2 + scratch[i + 2] * m_D3 + scratch[i + 3] * m_D4;
		data_block = _mm_loadu_ps(&scratch[i]);
		r2 = _mm_mul_ps(data_block, mm_Dcoeffs);
		
		diff = _mm_sub_ps(r1,r2);
 		diff = _mm_hadd_ps(diff, diff);
 		diff = _mm_hadd_ps(diff, diff);
		_mm_store_ss(&scratch_ptr[i], diff);
		outs_ptr1[i] += scratch_ptr[i];
	}

// 	/**
// 	 * Roll the antiCausal part into the output
// 	 */
// 	for ( unsigned int i = 0; i < ln; i++ ) {
// 		outs[i] += scratch[i];
// 	}
}

//------------------------------------------------------------------------------
/**
* Process part of the image
* @param threadid
*/
template <class T>
void RecursiveGaussianConvolution1D::TemplateProcess ( int threadid )
{
	extenttype extent = extents[threadid];
	int x, y, z;
	InrImage::ptr in = params.GetInput();

	int tx = in->DimX();
	int ty = in->DimY();
	int tz = in->DimZ();
	int incx, incy, incz;
	in->GetBufferIncrements ( incx, incy, incz );

	if ( incx != 1 ) {
		CLASS_ERROR ( "incx should be equal to one !!!" );
	}

	T* in_data  = ( T* ) in     ->GetData();
	T* out_data = ( T* ) output ->GetData();
	T* tmp;
	T minval;
	T maxval;

	bool has_mask = _mask.get();

	// use SSE only with float for the moment
	bool use_sse = ( typeid ( T ) == typeid ( float ) );

	if ( params.GetProfile() ) {
		std::cout << "ImageConvolution1D::TemplateProcess()" << std::endl;
		std::cout << "tx=" << tx << ", ty=" << ty << ",tz=" << tz << std::endl;
		std::cout << "extent = "
		          << extent.GetMin ( 0 ) << "-" << extent.GetMax ( 0 ) << "; "
		          << extent.GetMin ( 1 ) << "-" << extent.GetMax ( 1 ) << "; "
		          << extent.GetMin ( 2 ) << "-" << extent.GetMax ( 2 ) << std::endl;
		std::cout << "dir :" <<  _dir << std::endl;
		std::cout << "use_sse :  "          << use_sse << std::endl;
		std::cout << "has SSE3 :";
#ifdef SSE3
		std::cout << "yes" << std::endl;
#else
		std::cout << "no" << std::endl;
#endif
	}


	int xmin  = extent.GetMin ( 0 );
	int xmax  = extent.GetMax ( 0 );
	int xsize = extent.GetSize ( 0 );
	int ymin  = extent.GetMin ( 1 );
	int ymax  = extent.GetMax ( 1 );
	int ysize = extent.GetSize ( 1 );
	int zmin  = extent.GetMin ( 2 );
	int zmax  = extent.GetMax ( 2 );
	int zsize = extent.GetSize ( 2 );

	if ( _dir == DIR_X ) {

		T* scratch_data = new T[xsize];

		for ( z = zmin; z <= zmax; z++ )
			for ( y = ymin; y <= ymax; y++ ) {
				T* in_data1  = in_data  + z * incz + y * incy + xmin * incx;
				T* out_data1 = out_data + z * incz + y * incy + xmin * incx;
// 				if (use_sse)
// 					FilterDataArray_Float_SSE2 ( (float*)out_data1, 
// 												 (float*)in_data1, 
// 												 (float*)scratch_data, 
// 												 xsize );
// 				else
					FilterDataArray ( out_data1, in_data1, scratch_data, xsize );
			}

		delete[] scratch_data;
	}

	if ( _dir == DIR_Y ) {
		/*
			T* in1 = new T[ty];
			T* in1_ptr;
			T* out1 = new T[ty];
			T* out1_ptr;
			T* scratch_data = new T[xsize];
			for(z=zmin;z<=zmax; z++)
			for(x=xmin;x<=xmax; x++)
			{
		            int pos = z*incz + ymin*incy + x*incx;
		            T* in_data1  = in_data  + pos;
		            T* out_data1 = out_data + pos;
		            // 1. copy in1
		            tmp = in_data+z*incz+x*incx;
		            for(y=0;y<ty;y++) { in1[y] = *tmp; tmp+=incy; }
		            minval = in1[0];
		            maxval = in1[ty-1];
		            in1_ptr  = in1+ymin;
		            out1_ptr = out1+ymin;
		            if (use_sse) {
		              // prepare sse_input:  1 memcpy
		              int minpos = macro_max(0,    ymin-_kernel_radius);
		              int maxpos = macro_min(ty-1, ymax+_kernel_radius);
		              int pos=0;
		              for(y=ymin-_kernel_radius;y<minpos;y++) {
		                sse_input[pos] = minval;
		                pos++;
		              }
		              memcpy(&sse_input[pos],
		                      in1_ptr-_kernel_radius+pos,
		                      sizeof(float)*(maxpos-minpos+1) );
		              pos += maxpos-minpos+1;
		              for(y=maxpos+1;y<=ymax+_kernel_radius;y++) {
		                sse_input[pos] = maxval;
		                pos++;
		              }

		              switch(_fast_convolve_mode) {
		                case NAIVE:
		                case SSE_IN_ALIGNED:
		                    fast_convolve(sse_input,
		                                  out1_ptr,   ysize+2*_kernel_radius,
		                                  sse_kernel,  kernel_size);
		                    break;

		                case SSE_SIMPLE:
		                case SSE_PARTIAL_UNROLL:
		                    fast_convolve_prepared(sse_input,
		                                  out1_ptr,   ysize+2*_kernel_radius,
		                                  sse_kernel_prepared, kernel_size);
		                    break;
		              }

		            } else {
		              for(y=ymin;y<=ymax; y++) {
		                out1[y] = ConvolveDirX<T>(in1_ptr,y,ty,minval,maxval);
		                in1_ptr++;
		              }
		            }

		            for(y=ymin;y<=ymax; y++) {
		              *out_data1 = out1[y];
		              out_data1 += incy;
		            }
		          }
		          delete [] in1;
		          delete [] out1;
		        }
		        */
	} // end if

	if ( _dir == DIR_Z ) {
		/*
		switch(_dirz_version)
		{
		case 0: // call ConvolveDirZ, loop z,y,x
		  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
		  for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
		  {
		    T* in_data1  = in_data + z*incz + y*incy +
		                        extent.GetMin(0)*incx;
		    T* out_data1 = out_data + z*incz + y*incy +
		                        extent.GetMin(0)*incx;
		    if (has_mask) {
		      for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
		      {
		        if ((*_mask)(x,y,z)>0.5) {
		          tmp = in_data+y*incy+x*incx;
		          minval = *(tmp);
		          maxval = *(tmp+(tz-1)*incz);
		          *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
		        }
		        in_data1++;
		        out_data1++;
		      }
		    } else {
		      for(x=extent.GetMin(0);x<=extent.GetMax(0); x++)
		      {
		        tmp = in_data+y*incy+x*incx;
		        minval = *(tmp);
		        maxval = *(tmp+(tz-1)*incz);
		        *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
		        in_data1++;
		        out_data1++;
		      }
		    }
		  }
		  break;
		case 1:  // call ConvolveDirZ, loop y,x,z
		    for(y=ymin;y<=ymax; y++)
		    for(x=xmin;x<=xmax; x++)
		    {
		      T* in_data1  = in_data  + zmin*incz + y*incy + x*incx;
		      T* out_data1 = out_data + zmin*incz + y*incy + x*incx;
		      tmp = in_data+y*incy+x*incx;
		      minval = *(tmp);
		      maxval = *(tmp+(tz-1)*incz);
		      if (has_mask) {
		        for(z=zmin;z<=zmax; z++)
		        {
		          if ((*_mask)(x,y,z)>0.5) {
		            *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
		          }
		          in_data1  += incz;
		          out_data1 += incz;
		        }
		      } else {
		        for(z=zmin;z<=zmax; z++)
		        {
		          *out_data1 = ConvolveDirZ<T>(in_data1,z,tz,incz,minval,maxval);
		          in_data1  += incz;
		          out_data1 += incz;
		        }
		      }
		    }
		  break;
		case 2: // call ConvolveDirX, loop y,x,z
		  {
		    T* in1 = new T[tz];
		    T* in1_ptr;
		    T* out1 = new T[tz];
		    T* out1_ptr;
		    for(y=ymin;y<=ymax; y++)
		    for(x=xmin;x<=xmax; x++)
		    {
		      int pos = zmin*incz + y*incy + x*incx;
		      T* in_data1  = in_data  + pos;
		      T* out_data1 = out_data + pos;
		      // 1. copy in1
		      tmp = in_data+y*incy+x*incx;
		      for(z=0;z<tz;z++) { in1[z] = *tmp; tmp+=incz; }
		      minval = in1[0];
		      maxval = in1[tz-1];
		      in1_ptr  = in1+zmin;
		      out1_ptr = out1+zmin;
		      if (use_sse) {
		        // prepare sse_input:  1 memcpy
		        int minpos = macro_max(0,    zmin-_kernel_radius);
		        int maxpos = macro_min(tz-1, zmax+_kernel_radius);
		        int pos=0;
		        for(z=zmin-_kernel_radius;z<minpos;z++) {
		          sse_input[pos] = minval;
		          pos++;
		        }
		        memcpy(&sse_input[pos],
		                in1_ptr-_kernel_radius+pos,
		                sizeof(float)*(maxpos-minpos+1) );
		        pos += maxpos-minpos+1;
		        for(z=maxpos+1;z<=zmax+_kernel_radius;z++) {
		          sse_input[pos] = maxval;
		          pos++;
		        }

		        switch(_fast_convolve_mode) {
		          case NAIVE:
		          case SSE_IN_ALIGNED:
		              fast_convolve(sse_input,
		                            out1_ptr,   zsize+2*_kernel_radius,
		                            sse_kernel,  kernel_size);
		              break;

		          case SSE_SIMPLE:
		          case SSE_PARTIAL_UNROLL:
		              fast_convolve_prepared(sse_input,
		                            out1_ptr,   zsize+2*_kernel_radius,
		                            sse_kernel_prepared, kernel_size);
		              break;
		        }

		      } else {
		        for(z=zmin;z<=zmax; z++) {
		          out1[z] = ConvolveDirX<T>(in1_ptr,z,tz,minval,maxval);
		          in1_ptr++;
		        }
		      }

		      for(z=zmin;z<=zmax; z++) {
		        *out_data1 = out1[z];
		        out_data1 += incz;
		      }
		    }
		    delete [] in1;
		    delete [] out1;
		  }
		  break;

		case 3: // process 4 lines in parallel
		case 4: // process 4 lines in parallel with symmetry
		  {
		    if (use_sse) {
		      int size = extent.GetSize((int)_dir)+2*_kernel_radius;
		      __m128* in_x4  = (__m128*) _mm_malloc(sizeof(__m128)*size,16);
		      __m128* out_x4 = (__m128*) _mm_malloc(
		                          sizeof(__m128)*extent.GetSize((int)_dir),16);
		      __m128 minvalues;
		      __m128 maxvalues;
		      float values[4] __attribute__ ((aligned (16)));;

		      for(y=ymin;y<=ymax; y++)
		      {
		        // step 4 by 4 in x
		        for(x=xmin;x<=xmax; x+=4)
		        {
		          int pos0 = y*incy + x*incx;
		          //int pos = zmin*incz + pos0;

		          float* in_data1  = (float*)in_data  + pos0;
		          if (x>xmax-3) {
		            bzero(values,4*sizeof(float));
		            memcpy(values,
		                   in_data1,
		                   (xmax-x+1)*sizeof(float));
		            minvalues =  _mm_load_ps(values);
		            memcpy(values,
		                   (in_data1+(tz-1)*incz),
		                   (xmax-x+1)*sizeof(float));
		            maxvalues =  _mm_load_ps(values);
		          } else {
		            minvalues = _mm_loadu_ps(in_data1);
		            maxvalues = _mm_loadu_ps(in_data1+(tz-1)*incz);
		          }

		          // prepare in_x4
		          int minpos = macro_max(0,    zmin-_kernel_radius);
		          int maxpos = macro_min(tz-1, zmax+_kernel_radius);
		          int pos=0;
		          for(z=zmin-_kernel_radius;z<minpos;z++) {
		            in_x4[pos] = minvalues;
		            pos++;
		          }
		          in_data1  = (float*)in_data  + pos0 + minpos*incz;
		          // special case is not multiple of 4
		          if (x>xmax-3) {
		            for(z=minpos;z<=maxpos;z++) {
		              bzero(values,4*sizeof(float));
		              memcpy(values,in_data1,(xmax-x+1)*sizeof(float));
		              // data not necessary aligned in the original image
		              in_x4[pos] =  _mm_load_ps(values);
		              in_data1+=incz;
		              pos++;
		            }
		          } else {
		            for(z=minpos;z<=maxpos;z++) {
		              // data not necessary aligned in the original image
		              in_x4[pos] =  _mm_loadu_ps(in_data1);
		              in_data1+=incz;
		              pos++;
		            }
		          }
		          for(z=maxpos+1;z<=zmax+_kernel_radius;z++) {
		            in_x4[pos] = maxvalues;
		            pos++;
		          }

		          if (_dirz_version==4) {
		            if (_symmetry==EVEN)
		              convolve_sse_x4_prepared_sym( in_x4,
		                                            out_x4,
		                                            zsize+2*_kernel_radius,
		                                            sse_kernel_prepared,
		                                            _kernel_radius);
		            else
		              convolve_sse_x4_prepared_asym( in_x4,
		                                             out_x4,
		                                             zsize+2*_kernel_radius,
		                                             sse_kernel_prepared,
		                                             _kernel_radius);
		          }
		          else
		            convolve_sse_x4_prepared( in_x4,
		                                      out_x4,   zsize+2*_kernel_radius,
		                                      sse_kernel_prepared,  kernel_size);

		          // copy back the results
		          float* out_data1 = (float*)out_data + zmin*incz + pos0;

		          if (x>xmax-3) {
		            for(z=0;z<extent.GetSize(2); z++) {
		              _mm_store_ps(values,out_x4[z]);
		              memcpy(out_data1,values,(xmax-x+1)*sizeof(float));
		              out_data1 += incz;
		            }
		          } else
		            for(z=0;z<extent.GetSize(2); z++) {
		              _mm_storeu_ps(out_data1, out_x4[z]);
		              out_data1 += incz;
		            }
		        } // for x
		        // should compute the remaining lines ...

		      } // for y
		      _mm_free( in_x4);
		      _mm_free( out_x4);
		    }
		  }
		  break;
		}
		*/
	}
}


//------------------------------------------------------------------------------
/**
* Process part of the image
* @param threadid
*/
void RecursiveGaussianConvolution1D::Process ( int threadid )
{
	// process using precomputed extent number threadid
	InrImage::ptr in = params.GetInput();

	switch ( in->GetFormat() ) {
		case WT_UNSIGNED_CHAR:
			TemplateProcess<unsigned char> ( threadid );
			break;

		case WT_UNSIGNED_SHORT:
			TemplateProcess<unsigned short> ( threadid );
			break;

		case WT_SIGNED_SHORT:
			TemplateProcess<short> ( threadid );
			break;

		case WT_UNSIGNED_INT:
			TemplateProcess<unsigned int> ( threadid );
			break;

		case WT_SIGNED_INT:
			TemplateProcess<int> ( threadid );
			break;

		case WT_FLOAT:
			TemplateProcess<float> ( threadid );
			break;

		case WT_DOUBLE:
			TemplateProcess<double> ( threadid );
			break;

		default:
			CLASS_ERROR ( ( boost::format ( " format %1% not available" ) %
			                in->GetFormat() ).str().c_str() );
	}
}


//------------------------------------------------------------------------------
void RecursiveGaussianConvolution1D::Run()
{
	//std::cout << "ImageConvolution1D::Run() Begin" << std::endl;

	Timing t ( ( boost::format ( "ImageConvolution1D::Run() %1%" ) % _dir ).str() );

	t.Debut();
	InrImage::ptr in = params.GetInput();
	bool output_ok = false;

	if ( output.get() ) {
		if ( ( output->DimX() == in->DimX() ) && ( output->DimY() == in->DimY() )
		        && ( output->DimZ() == in->DimZ() )
		        && ( in->GetFormat() == output->GetFormat() ) ) {
			output_ok = true;
		}
	}

	if ( !output_ok ) {
		output = InrImage::ptr ( new InrImage ( in->GetFormat(),
		                                        "convolution_res.ami.gz",
		                                        in.get() ) );
	}

//   InitGaussianKernel();
	this->SetUp ( in->VoxSize ( _dir ) );
	ImageToImageFilter::Run();
	t.Fin();
	std::cout << t
//             << ", kernel radius " << _kernel_radius
//             << ", time per billion voxels /kernelsize "
//             << t.GetDurationMilliSec()/(2*_kernel_radius+1)/in->Size()*100000000
//             << " millisec"
	          << std::endl;
	//std::cout << "ImageConvolution1D::Run() End" << std::endl;
}


}
