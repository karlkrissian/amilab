#ifndef _WITHOUT_ITK_

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"

#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapitkWrite.h"
#include "wrapConversion.tpp"


/** Read a 3D Flow from an ASCII file **/
template<class TPixel, unsigned int Dimension>
class itkWriteClass {
  typedef typename itk::Image< TPixel, Dimension>    ImageType;
  typedef typename itk::ImageFileWriter< ImageType >  WriterType;

  public: 
		void operator()(typename ImageType::Pointer image, const string& filename) 
    { 
    #ifndef _WITHOUT_ITK_

      typename WriterType::Pointer writer = WriterType::New();
    
			writer->SetFileName( filename.c_str());
			writer->SetInput(image);
    
      try
        {
        writer->Update();
        }
      catch( itk::ExceptionObject & err )
        {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
        //return NULL;
        }
   
    #else
      fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
      return NULL;
    #endif // _WITHOUT_ITK_

    }  
};


InrImage* itkWrite(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkWrite";
  char description[]=" \n\
        Use itk Writer factory to write an image file\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
					InrImage:\n\
          string: filename\n\
      ";
  
	InrImage* input = NULL;
  std::string*  fname = NULL;
  int n=0;
  
	if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_string_param( fname, p, n)) HelpAndReturnNULL;
	
  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;
  ImageType::RegionType region;
  ImageType::Pointer image;
 
  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  	
	image = InrToITK<PixelType,Dimension>(input,region);
  cout << "Writing itk file " << endl;
	itkWriteClass<PixelType,Dimension>()(image,*fname);
	return input;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // itkWrite()