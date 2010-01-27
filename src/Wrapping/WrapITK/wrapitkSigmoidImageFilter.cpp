#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkSigmoidImageFilter.h"
#include "itkImage.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkSigmoidImageFilter.h"

InrImage* wrap_itkSigmoidImageFilter2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkSigmoidImageFilter2D";
  char description[]=" \n\
        Filter to compute a sigmoid solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          outputMin \n\
          outputMax \n\
					SigmoidAlpha \n\
					SigmoidBeta \n\
      ";
    
	InrImage* input = NULL;
	float outputMin = 0.0;
	float outputMax = 0.0;
	float alpha = 0.0;
	float beta = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  outputMin,    p, n)) HelpAndReturnNULL;
  if (!get_float_param(  outputMax,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  alpha,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  beta,      p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 2;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

	typedef float OutputPixelType;
	typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
	OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

  typedef itk::SigmoidImageFilter< InternalImageType, InternalImageType >  SigmoidFilterType;
  SigmoidFilterType::Pointer sigmoidFilter = SigmoidFilterType::New();

  sigmoidFilter->SetOutputMinimum(   outputMin  );
  sigmoidFilter->SetOutputMaximum(   outputMax  );

  sigmoidFilter->SetAlpha(  alpha  );
  sigmoidFilter->SetBeta(   beta   );

  sigmoidFilter->SetInput( image );
  sigmoidFilter->Update();

	outimage = sigmoidFilter->GetOutput();
  
	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkSigmoidImageFilter2D


InrImage* wrap_itkSigmoidImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkSigmoidImageFilter3D";
  char description[]=" \n\
        Filter to compute a sigmoid solution in 3D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          outputMin \n\
          outputMax \n\
					SigmoidAlpha \n\
					SigmoidBeta \n\
      ";
    
	InrImage* input = NULL;
	float outputMin = 0.0;
	float outputMax = 0.0;
	float alpha = 0.0;
	float beta = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  outputMin,    p, n)) HelpAndReturnNULL;
  if (!get_float_param(  outputMax,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  alpha,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  beta,      p, n)) HelpAndReturnNULL;
 
  typedef float       InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension >    InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

	typedef float OutputPixelType;
	typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
	OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

  typedef itk::SigmoidImageFilter< InternalImageType, OutputImageType >  SigmoidFilterType;
  SigmoidFilterType::Pointer sigmoidFilter = SigmoidFilterType::New();

  sigmoidFilter->SetOutputMinimum(   outputMin  );
  sigmoidFilter->SetOutputMaximum(   outputMax  );

  sigmoidFilter->SetInput( image );
  
  sigmoidFilter->SetAlpha(  alpha  );
  sigmoidFilter->SetBeta(   beta   );

  sigmoidFilter->Update();

	outimage = sigmoidFilter->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkSigmoidImageFilter3D