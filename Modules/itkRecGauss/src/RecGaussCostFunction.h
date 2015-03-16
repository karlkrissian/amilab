
#pragma once

#ifndef _RecGaussCostFunction_h_
#define _RecGaussCostFunction_h_

#include "itkLevenbergMarquardtOptimizer.h"
#include "vnl/vnl_math.h"

typedef vnl_matrix<double> MatrixType;
typedef vnl_vector<double> VectorType;



/**
 *
 * Fitting Gaussian for recursive convolution
 * 
 * Gaussian (without normalization) exp(-(x/sigma)*(x/sigma)/2)
 * 
 * 2nd order: unknowns are a0,a1,w0,b0
 * 		(a0 cos(w0*n/sigma) + a1 sin(w0*n/sigma))*exp(-b0*n/sigma)
 * 
 * 4th order: unknowns are a0,a1,w0,b0, c0,c1,w1,b1
 * 		(a0 cos(w0*n/sigma) + a1 sin(w0*n/sigma))*exp(-b0*n/sigma) +
 * 		(c0 cos(w1*n/sigma) + c1 sin(w1*n/sigma))*exp(-b1*n/sigma) 
 * 
 * \class RecGaussCostFunction
 *
 */
class RecGaussCostFunction : public itk::MultipleValuedCostFunction
{
public:
  typedef RecGaussCostFunction                    Self;
  typedef itk::MultipleValuedCostFunction   Superclass;
  typedef itk::SmartPointer<Self>           Pointer;
  typedef itk::SmartPointer<const Self>     ConstPointer;
  itkNewMacro( Self );

  enum { SpaceDimension =  4 };
//   enum { XRange = 10* };   // size of the region to sample the cost function
//   enum { RangeDimension =  XRange+1 };

  typedef Superclass::ParametersType              ParametersType;
  typedef Superclass::DerivativeType              DerivativeType;
  typedef Superclass::MeasureType                 MeasureType;

  // skip derivative ...
  RecGaussCostFunction():
            m_TheoreticalData(SpaceDimension)
  {
	SetSigma(100);
	SetMinRange(0);
  }


  MeasureType GetValue( const ParametersType & parameters ) const
  {

    std::cout << "GetValue( ";
    double a0 = parameters[0];
    double a1 = parameters[1];
    double w0 = parameters[2];
    double b0 = parameters[3];

    std::cout 	<< a0 << " , ";
    std::cout 	<< a1 << " , ";
    std::cout 	<< w0 << " , "  << b0 
				<< ")  " << std::endl;

    // Compute points of the function over a square region
    unsigned valueindex = 0;
	for( int x = m_minrange; x<=m_range; x++ )
	{
		const double xd = ((double)x)/m_sigma;
		double value = (a0 * cos(w0*xd) + a1 * sin(w0*xd))*exp(-b0*xd);
		value -= m_TheoreticalData[valueindex];
		m_Measure[valueindex] = value;
		valueindex++;
	}

    return m_Measure;
 }

  void GetDerivative( const ParametersType & parameters,
                            DerivativeType  & derivative ) const
  {
  }

  unsigned int GetNumberOfParameters(void) const
  {
    return SpaceDimension;
  }

  unsigned int GetNumberOfValues(void) const
  {
    return m_range+1;
  }

  double GetNormalizeFactor()
  {
	  return m_normalize_factor;
  }
  
  void   SetSigma(const double& s ) 
  { 
	m_sigma = s;
	m_range = (int) (m_sigma*10);
	m_Measure.SetSize(m_range+1);
    m_TheoreticalData.SetSize(m_range+1);

    // Compute points of the function over a square region
    unsigned valueindex = 0;
	double normalize_factor = 0;
	for( int x = m_minrange; x<=m_range; x++ )
	{
		const double xd = ((double)x)/m_sigma;
		m_TheoreticalData[valueindex] = exp(-0.5*xd*xd);
		normalize_factor += m_TheoreticalData[valueindex]* m_TheoreticalData[valueindex];
		valueindex++;
	}
	m_normalize_factor = normalize_factor;
	  
  }

  double GetSigma() { return m_sigma; }

  void SetMinRange( const int& m) { m_minrange=m; }
  int  GetMinRange() { return m_minrange; }
  
private:

  mutable MeasureType       m_Measure;
  mutable DerivativeType    m_Derivative;
          MeasureType       m_TheoreticalData;
  double  					m_normalize_factor;
  double                    m_sigma;
  int                       m_minrange;
  int 						m_range;

};

#endif // _RecGaussCostFunction_h_
