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


void itkWrite(ParamList* p)
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
  
	if (!get_image_param(  input,      p, n)) HelpAndReturn;
  if (!get_string_param( fname, p, n)) HelpAndReturn;

	const WORDTYPE image_component_type = input->GetFormat();
	std::cout << "Dimension: " << input->DimZ() << " " << std::endl;
	
  //typedef float               PixelType;
  //const   unsigned int        Dimension = 3;
  //typedef itk::Image< unsigned char, 3 >    ImageType;
	
	if (input->DimZ()<3)
	{
		std::cout << "Dimension 2" << std::endl;
		switch(image_component_type) { \
			case WT_UNSIGNED_CHAR:
			{
				itk::Image< unsigned char, 2 >::RegionType region;
				itk::Image< unsigned char, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned char,2>(input,region);
				itkWriteClass<unsigned char,2>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_SHORT: 
			{
				itk::Image< unsigned short, 2 >::RegionType region;
				itk::Image< unsigned short, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned short,2>(input,region);
				itkWriteClass<unsigned short,2>()(image,*fname);
				
				break; \
			}
			case WT_SIGNED_SHORT:
			{
				itk::Image< signed short, 2 >::RegionType region;
				itk::Image< signed short, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<signed short,2>(input,region);
				itkWriteClass<signed short,2>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_INT:
			{
				itk::Image< unsigned int, 2 >::RegionType region;
				itk::Image< unsigned int, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned int,2>(input,region);
				itkWriteClass<unsigned int,2>()(image,*fname);
				
				break; \
			}
			case WT_SIGNED_INT:
			{
				itk::Image< signed int, 2 >::RegionType region;
				itk::Image< signed int, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<signed int,2>(input,region);
				itkWriteClass<signed int,2>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_LONG:
			{
				itk::Image< unsigned long, 2 >::RegionType region;
				itk::Image< unsigned long, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned long,2>(input,region);
				itkWriteClass<unsigned long,2>()(image,*fname);
				
				break; \
			}
			case WT_FLOAT:
			{
				itk::Image< float, 2 >::RegionType region;
				itk::Image< float, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<float,2>(input,region);
				itkWriteClass<float,2>()(image,*fname);
				
				break; \
			}
			case WT_DOUBLE:
			{
				itk::Image< double, 2 >::RegionType region;
				itk::Image< double, 2 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<double,2>(input,region);
				itkWriteClass<double,2>()(image,*fname);
				
				break; \
			}
			default:  \
				cerr << "Format not supported in InrImage class "<< endl;  \
		}
	}
	else
	{
		std::cout << "Dimension 3" << std::endl;
		switch(image_component_type) { \
			case WT_UNSIGNED_CHAR:
			{
				itk::Image< unsigned char, 3 >::RegionType region;
				itk::Image< unsigned char, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned char,3>(input,region);
				itkWriteClass<unsigned char,3>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_SHORT: 
			{
				itk::Image< unsigned short, 3 >::RegionType region;
				itk::Image< unsigned short, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned short,3>(input,region);
				itkWriteClass<unsigned short,3>()(image,*fname);
				
				break; \
			}
			case WT_SIGNED_SHORT:
			{
				itk::Image< signed short, 3 >::RegionType region;
				itk::Image< signed short, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<signed short,3>(input,region);
				itkWriteClass<signed short,3>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_INT:
			{
				itk::Image< unsigned int, 3 >::RegionType region;
				itk::Image< unsigned int, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned int,3>(input,region);
				itkWriteClass<unsigned int,3>()(image,*fname);
				
				break; \
			}
			case WT_SIGNED_INT:
			{
				itk::Image< signed int, 3 >::RegionType region;
				itk::Image< signed int, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<signed int,3>(input,region);
				itkWriteClass<signed int,3>()(image,*fname);
				
				break; \
			}
			case WT_UNSIGNED_LONG:
			{
				itk::Image< unsigned long, 3 >::RegionType region;
				itk::Image< unsigned long, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<unsigned long,3>(input,region);
				itkWriteClass<unsigned long,3>()(image,*fname);
				
				break; \
			}
			case WT_FLOAT:
			{
				itk::Image< float, 3 >::RegionType region;
				itk::Image< float, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<float,3>(input,region);
				itkWriteClass<float,3>()(image,*fname);
				
				break; \
			}
			case WT_DOUBLE:
			{
				itk::Image< double, 3 >::RegionType region;
				itk::Image< double, 3 >::Pointer image;
				// Convert from InrImage to ITK
				cout << "Converting image to ITK format " << endl;
	  	
				image = InrToITK<double,3>(input,region);
				itkWriteClass<double,3>()(image,*fname);
				
				break; \
			}
			default:  \
				cerr << "Format not supported in InrImage class "<< endl;  \
		}
	}

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // itkWrite()