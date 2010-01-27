#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_

#include "itkImage.h"
#include "itkBoxMeanImageFilter.h"
#include "itkResampleImageFilter.h"
#include "itkAffineTransform.h"
#include "itkSubtractImageFilter.h"
#include "itkAddImageFilter.h"
#include "itkSquareImageFilter.h"
#include "itkWeights.h"
#include "itkMultiplyImageFilter.h"
#include "itkDivideImageFilter.h"
#include "itkFastNLMeansImageFilter.h"

#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkFastNLMeansImageFilter.h"


InrImage* wrap_itkBasicNLMeans2D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkFastNLMeansImageFilter2D";
  char description[]=" \n\
        Reduces the noise of an image 2D through NLMeans filter.\n\
      ";
	  
  char parameters[] =" \n\
					Parameters:\n\
					input image \n\
					searching window (def:7) \n\
					threshold (def:10) \n\					
      ";
			
  InrImage* input = NULL;
  int     searching = 7;
  float   threshold = 10;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  searching,    p, n)) HelpAndReturnNULL;
  if (!get_float_param(	threshold, 	 p, n)) HelpAndReturnNULL;
  
  const     unsigned int   Dimension = 2;
  typedef   float  PixelType;
  typedef itk::Image< PixelType, Dimension > ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
  
  typedef itk::BoxMeanImageFilter<ImageType,ImageType> BoxMeanFilterType;
  BoxMeanFilterType::Pointer boxmean = BoxMeanFilterType::New();
  
  typedef itk::ResampleImageFilter<ImageType,ImageType> ResampleFilterType;
  ResampleFilterType::Pointer resample = ResampleFilterType::New();
  
  typedef itk::SubtractImageFilter<ImageType,ImageType,ImageType> SubtractFilterType;
  SubtractFilterType::Pointer subtract = SubtractFilterType::New();
  
  typedef itk::AddImageFilter<ImageType,ImageType,ImageType> AddFilterType;
  AddFilterType::Pointer add = AddFilterType::New();
  AddFilterType::Pointer add1 = AddFilterType::New();
  
  typedef itk::SquareImageFilter<ImageType,ImageType> SquareFilterType;
  SquareFilterType::Pointer square = SquareFilterType::New();

  typedef itk::Weights<ImageType,ImageType> WeightsFilterType;
  WeightsFilterType::Pointer weights = WeightsFilterType::New();

  typedef itk::MultiplyImageFilter<ImageType,ImageType, ImageType> MultiplyFilterType;
  MultiplyFilterType::Pointer multiply = MultiplyFilterType::New();
  
  typedef itk::DivideImageFilter<ImageType,ImageType, ImageType> DivideFilterType;
  DivideFilterType::Pointer divide = DivideFilterType::New();

  typedef itk::AffineTransform< double, Dimension >  TransformType;

  TransformType::Pointer transform = TransformType::New();
  
  typedef BoxMeanFilterType::RadiusType RadiusType;
  
  TransformType::OutputVectorType translation;

  clock_t tiempoInicial = clock();
  
    // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
 
	image = InrToITK<PixelType,Dimension>(input,region);

  resample->SetTransform( transform );

  resample->SetDefaultPixelValue( 0 );

  resample->SetReferenceImage(image);

  resample->SetUseReferenceImage(true);

  resample->SetInput( image );
  
  for (int i=-t;i<=t;i++)
  {
    for (int j=-t;j<=t;j++)
    {
      translation[0] = i;
      translation[1] = j;
      transform->Translate( translation );
      
      //media local
      subtract->SetInput1(reader->GetOutput());
      subtract->SetInput2(resample->GetOutput());
      subtract->Update();
  
      square->SetInput(subtract->GetOutput());
      square->Update();

      boxmean->SetInput(square->GetOutput());
      boxmean->SetRadius( t );
      boxmean->Update();

      //función de pesos
      weights->SetInput(boxmean->GetOutput());
      weights->SetThreshold(atof (argv[4]));
      weights->Update();

      //sumatoria resultado
      multiply->SetInput1(weights->GetOutput());
      multiply->SetInput2(resample->GetOutput());
      multiply->Update();

      add->SetInput1(multiply->GetOutput());
      add->SetInput2(add->GetOutput());
      add->Update();

      add1->SetInput1(weights->GetOutput());
      add1->SetInput2(add1->GetOutput());
      add1->Update();
    }
  }
  
  divide->SetInput1(add->GetOutput());
  divide->SetInput2(add1->GetOutput());
  divide->Update();

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(divide->GetOutput(), region);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_


} // wrap_itkFastNLMeansImageFilter2D


//--------------------------------------------------------------------------
//
InrImage* wrap_itkBasicNLMeans3D(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkBasicNLMeans3D";
  char description[]=" \n\
        Reduces the noise of an image 3D trhough NLMeans filter.\n\
      ";
	  
  char parameters[] =" \n\
					Parameters:\n\
					input image \n\
					searching window (def:7) \n\
					pattern window (def:3) \n\
					threshold (def:10) \n\
					noise (def:0) \n\
      ";
    
  InrImage* input = NULL;
  int     searching = 7;
  int     pattern = 3;
  float   threshold = 10;
  int     noise = 0;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_int_param(  searching,    p, n)) HelpAndReturnNULL;
  if (!get_int_param(  pattern,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(	threshold, 	 p, n)) HelpAndReturnNULL;
  if (!get_int_param(	noise,	 	 p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<PixelType,Dimension>(input,region);

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;

  try {
    typedef itk::BasicNLMeansFilter<ImageType,ImageType> NLMeansType;
    NLMeansType::Pointer nlmeans = NLMeansType::New();
	
		ImageType::SizeType i_f;
  
		i_f[0]=pattern;
		i_f[1]=pattern;
		i_f[2]=pattern;

    nlmeans->SetInput( image );
    nlmeans->SetSearching(searching);
    nlmeans->SetPattern(i_f);
    nlmeans->SetThreshold(threshold);
    nlmeans->SetNoise(noise);
    nlmeans->Update();
    image = nlmeans->GetOutput();
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

  res = ITKToInr<PixelType,Dimension>(image, region);

	return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // wrap_itkBasicNLMeansFilter3D