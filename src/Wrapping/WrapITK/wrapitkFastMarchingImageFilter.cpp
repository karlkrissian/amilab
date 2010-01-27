#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkSigmoidImageFilter.h"
#include "itkImage.h"
#include "itkFastMarchingImageFilter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkFastMarchingImageFilter.h"

InrImage* wrap_itkFastMarchingImageFilter2D(ParamList* p)
{
	
#ifndef _WITHOUT_ITK_

	char functionname[] = "itkFastMarchingImageFilter2D";
  char description[]=" \n\
        Filter to compute a fast marching solution in 2D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          seedX \n\
          seedY \n\
					SigmoidAlpha \n\
					SigmoidBeta \n\
					StoppingValue \n\
      ";
    
	InrImage* input = NULL;
	float seedX = 0.0;
	float seedY = 0.0;
	float alpha = 0.0;
	float beta = 0.0;
	float timeThreshold = 0.0;
	float stoppingTime = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  seedX,    p, n)) HelpAndReturnNULL;
  if (!get_float_param(  seedY,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  alpha,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  beta,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  stoppingTime,      p, n)) HelpAndReturnNULL; 
 
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

  typedef  itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

  FastMarchingFilterType::Pointer  fastMarching = FastMarchingFilterType::New();

  fastMarching->SetInput( image );
 
  typedef FastMarchingFilterType::NodeContainer           NodeContainer;
  typedef FastMarchingFilterType::NodeType                NodeType;
  NodeContainer::Pointer seeds = NodeContainer::New();
 
  InternalImageType::IndexType  seedPosition;
 
  seedPosition[0] = seedX;
  seedPosition[1] = seedY;
  
  std::cout << "seedPosition " << seedPosition << std::endl;

  NodeType node;
  const double seedValue = -5.0;
 
  node.SetValue( seedValue );
  node.SetIndex( seedPosition );

  seeds->Initialize();
  seeds->InsertElement( 0, node );

  fastMarching->SetTrialPoints(  seeds  );

  fastMarching->SetOutputSize( image->GetBufferedRegion().GetSize() );
  
  fastMarching->SetStoppingValue(  stoppingTime  );
 
  fastMarching->Update();

	outimage = fastMarching->GetOutput();

	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkFastMarchingImageFilter2D


InrImage* wrap_itkFastMarchingImageFilter3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkFastMarchingImageFilter3D";
  char description[]=" \n\
        Filter to compute a fast marching solution in 3D.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          seedX \n\
          seedY \n\
					seedZ \n\
					SigmoidAlpha \n\
					SigmoidBeta \n\
					StoppingValue \n\
      ";
    
	InrImage* input = NULL;
	float seedX = 0.0;
	float seedY = 0.0;
	float seedZ = 0.0;
	float alpha = 0.0;
	float beta = 0.0;
	float timeThreshold = 0.0;
	float stoppingTime = 0.0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  seedX,    p, n)) HelpAndReturnNULL;
  if (!get_float_param(  seedY,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  seedZ,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  alpha,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  beta,      p, n)) HelpAndReturnNULL;
	if (!get_float_param(  stoppingTime,      p, n)) HelpAndReturnNULL; 
 
  typedef float               InternalPixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< InternalPixelType, Dimension > InternalImageType;
  InternalImageType::RegionType region;
  InternalImageType::Pointer image;

	typedef float OutputPixelType;
	typedef itk::Image< OutputPixelType,Dimension > OutputImageType;
	OutputImageType::Pointer outimage;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<InternalPixelType,Dimension>(input,region);
	
	cout << "Conversión hecha" << endl;

  typedef  itk::FastMarchingImageFilter< InternalImageType, InternalImageType > FastMarchingFilterType;

  FastMarchingFilterType::Pointer  fastMarching = FastMarchingFilterType::New();

  fastMarching->SetInput( image );
  
  typedef FastMarchingFilterType::NodeContainer           NodeContainer;
  typedef FastMarchingFilterType::NodeType                NodeType;
  NodeContainer::Pointer seeds = NodeContainer::New();
 
  InternalImageType::IndexType  seedPosition;
 
  seedPosition[0] = seedX;
  seedPosition[1] = seedY;
  seedPosition[2] = seedZ;

  std::cout << "seedPosition " << seedPosition << std::endl;

  NodeType node;
  const double seedValue = -5;
   
  node.SetValue( seedValue );
  node.SetIndex( seedPosition );

  seeds->Initialize();
  seeds->InsertElement( 0, node );

  fastMarching->SetTrialPoints(  seeds  );

  fastMarching->SetOutputSize( image->GetBufferedRegion().GetSize() );
  
  fastMarching->SetStoppingValue(  stoppingTime  );
  
	fastMarching->Update();
  
  outimage = fastMarching->GetOutput();
   
	// Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

	res = ITKToInr<OutputPixelType,Dimension>(outimage, region);
	
	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} // wrap_itkFastMarchingImageFilter3D