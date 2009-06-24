#ifndef _WRAPCONVERSION_H_
#define _WRAPCONVERSION_H_

#include "itkImage.h"
#include "itkImageIOBase.h"

template <class TPixel, unsigned int Dimension> 
typename itk::Image<TPixel,Dimension>::Pointer InrToITK(InrImage* input, 
								typename itk::Image<TPixel,Dimension>::RegionType &region);

template <class TPixel, unsigned int Dimension> 
InrImage* ITKToInr(typename itk::Image<TPixel,Dimension>::Pointer image,
								typename itk::Image<TPixel,Dimension>::RegionType region);

#include "wrapConversion.tpp"

#endif // _WRAPCONVERSION_H_