
#pragma once
#ifndef _RecursiveGaussianConvolution1D_h_
#define _RecursiveGaussianConvolution1D_h_

#include "inrimage.hpp"
#include "amiImageExtent.h"
#include "amiImageToImageFilter.h"
#include <vector>
#include "DefineClass.hpp"
#include "../FastConvolution/convolve.h"
#include <iostream>
#include <xmmintrin.h>

namespace ami {

  
  #define AddSetGetVar( name, type) \
    type  name; \
    void Set##name( type _arg) \
    { \
      this->name = _arg; \
    };  \
    type Get##name() \
    { \
      return this->name; \
    };

  class RecursiveGaussianConvolution1D : public ImageToImageFilter 
  {
    DEFINE_CLASS(RecursiveGaussianConvolution1D);

    InrImage::ptr output;

  public:
	typedef float ScalarRealType;
    
    RecursiveGaussianConvolution1D() 
    {
      _dir                = DIR_X;
      _sigma              = 1;
      _order              = 0;
    }
    
    /** @name ConvOrientation
    */
    enum ConvOrientation
    {
      DIR_X= 0,
      DIR_Y,
      DIR_Z
    };
   
    /// Convolution orientation
    AddSetGetVar( _dir, ConvOrientation)

    /// Gaussian Standard Deviation
    AddSetGetVar( _sigma, double)
    
    /// Gaussian derivation order
    AddSetGetVar( _order, int)

    /// Mask Image
    AddSetGetVar( _mask, InrImage::ptr)
    
    
    ///
    template <class T>
    double ConvolveDirX(  T* input, 
                          const int& x, const int& tx, 
                          const T& minval, 
                          const T& maxval);
    ///
    template <class T>
    double ConvolveDirY(  T* input, 
                          const int& y, const int& ty, const int& incy,
                          const T& minval, 
                          const T& maxval);
    ///
    template <class T>
    double ConvolveDirZ(  T* input, 
                          const int& z, const int& tz, const int& incz,
                          const T& minval, 
                          const T& maxval);

    template <class T>
	void FilterDataArray(T *outs, const T *data,T *scratch, const unsigned int& ln);
	
	void FilterDataArray_Float_SSE2(float *outs, const float *data,float *scratch, const unsigned int& ln);

	// trying new recursive procedure
//	void FilterDataArray_Float_New(float *outs, const float *data,float *scratch, const unsigned int& ln);

	/**
    * Process part of the image
    * @param threadid 
    */
    template <class T>
    void TemplateProcess( int threadid = 0);

    /**
    * Process part of the image
    * @param threadid 
    */
    void Process( int threadid = 0);
	
    //--------------------------------------------------------------------------
    void Run();

    //--------------------------------------------------------------------------
    void SetOutputImage(InrImage::ptr o)
    {
      output = o;
    }

    //--------------------------------------------------------------------------
    InrImage::ptr& GetOutput()
    {
      return output;
    }
    

	protected:
		// coefficients, taken from itkRecursiveSeparableImageFilter.h
		
		/** Causal coefficients that multiply the input data. */
		ScalarRealType m_N0;
		ScalarRealType m_N1;
		ScalarRealType m_N2;
		ScalarRealType m_N3;

		/** Recursive coefficients that multiply previously computed values
		* at the output. These are the same for the causal and
		* anti-causal parts of the filter. */
		ScalarRealType m_D1;
		ScalarRealType m_D2;
		ScalarRealType m_D3;
		ScalarRealType m_D4;

		/** Anti-causal coefficients that multiply the input data. */
		ScalarRealType m_M1;
		ScalarRealType m_M2;
		ScalarRealType m_M3;
		ScalarRealType m_M4;

		/** Recursive coefficients to be used at the boundaries to simulate
		* edge extension boundary conditions. */
		ScalarRealType m_BN1;
		ScalarRealType m_BN2;
		ScalarRealType m_BN3;
		ScalarRealType m_BN4;

		ScalarRealType m_BM1;
		ScalarRealType m_BM2;
		ScalarRealType m_BM3;
		ScalarRealType m_BM4;
		
		/** Set up the coefficients of the filter to approximate a specific kernel.
		* Typically it can be used to approximate a Gaussian or one of its
		* derivatives. Parameter is the spacing along the dimension to
		* filter. */
		virtual void SetUp(ScalarRealType spacing);

	  
  private:
	  
	// taken from itkRecursiveGaussianImageFilter
    
	/** Compute the N coefficients in the recursive filter. */
	void ComputeNCoefficients(ScalarRealType sigmad,
								ScalarRealType A1, ScalarRealType B1, ScalarRealType W1, ScalarRealType L1,
								ScalarRealType A2, ScalarRealType B2, ScalarRealType W2, ScalarRealType L2,
								ScalarRealType & N0, ScalarRealType & N1,
								ScalarRealType & N2, ScalarRealType & N3,
								ScalarRealType & SN, ScalarRealType & DN, ScalarRealType & EN);

	/** Compute the D coefficients in the recursive filter. */
	void ComputeDCoefficients(ScalarRealType sigmad,
								ScalarRealType W1, ScalarRealType L1, ScalarRealType W2, ScalarRealType L2,
								ScalarRealType & SD, ScalarRealType & DD, ScalarRealType & ED);

	/** Compute the M coefficients and the boundary coefficients in the
	* recursive filter. */
	void ComputeRemainingCoefficients(bool symmetric);

  };
} // end namespace ami

#endif // _RecursiveGaussianConvolution1D_h_

