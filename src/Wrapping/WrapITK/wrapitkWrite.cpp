
#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 
#include "wrapitkWrite.h"
#include "wrapConversion.tpp"


/** Read a 3D Flow from an ASCII file **/
template<class TPixel, unsigned int Dimension>
class itkWriteClass {
  typedef typename itk::Image< TPixel, Dimension>    ImageType;
  typedef typename itk::ImageFileWriter< ImageType >  WriterType;

  public: 
    bool operator()(typename ImageType::Pointer image, const string& filename) 
    { 
    #ifdef AMI_USE_ITK

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
        return false;
        }
      return true;
   
    #else
      fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
      return false;
    #endif // AMI_USE_ITK

    }  
};

#define INRWRITEITK(type,dim)  { \
        itk::Image< type, dim >::RegionType region; \
        itk::Image< type, dim >::Pointer image;     \
        image = InrToITK<type,dim>(input,region); \
        return itkWriteClass<type,dim>()(image,fname);   }

//----------------------------------------------------------------
bool itkWrite(InrImage* input, const std::string& fname) 
{

  const WORDTYPE image_component_type = input->GetFormat();
  std::cout << "Dimension: " << input->DimZ() << " " << std::endl;
  
  

  if (input->DimZ()==1)  
  {
    switch(image_component_type) { 
      case WT_UNSIGNED_CHAR :  INRWRITEITK(unsigned char,  2); break;
      case WT_UNSIGNED_SHORT:  INRWRITEITK(unsigned short, 2); break;
      case WT_SIGNED_SHORT  :  INRWRITEITK(  signed short, 2); break;
      case WT_UNSIGNED_INT  :  INRWRITEITK(unsigned int,   2); break;
      case WT_SIGNED_INT    :  INRWRITEITK(  signed int,   2); break;
      case WT_UNSIGNED_LONG :  INRWRITEITK(unsigned long,  2); break;
      case WT_FLOAT         :  INRWRITEITK(float,          2); break;
      case WT_DOUBLE        :  INRWRITEITK(double,         2); break;
      default:  
        cerr << "Format not supported in InrImage class "<< endl;  
    }
  }  else
    switch(image_component_type) { 
      case WT_UNSIGNED_CHAR :  INRWRITEITK(unsigned char,  3); break;
      case WT_UNSIGNED_SHORT:  INRWRITEITK(unsigned short, 3); break;
      case WT_SIGNED_SHORT  :  INRWRITEITK(  signed short, 3); break;
      case WT_UNSIGNED_INT  :  INRWRITEITK(unsigned int,   3); break;
      case WT_SIGNED_INT    :  INRWRITEITK(  signed int,   3); break;
      case WT_UNSIGNED_LONG :  INRWRITEITK(unsigned long,  3); break;
      case WT_FLOAT         :  INRWRITEITK(float,          3); break;
      case WT_DOUBLE        :  INRWRITEITK(double,         3); break;
      default:  
        cerr << "Format not supported in InrImage class "<< endl;  
    }

}


//-----------------------------------------------------------------------
void wrap_itkWrite(ParamList* p)
{

#ifdef AMI_USE_ITK

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

  itkWrite(input,*fname);

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
#endif // else ifdef AMI_USE_ITK

} // itkWrite()
