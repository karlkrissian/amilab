
#include "amilab_messages.h"
#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include <itkRGBPixel.h>
#include <itkRGBAPixel.h>

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 
#include "wrapitkWrite.h"
#include "wrapConversion.tpp"

#include "ami_itkWrite.h"


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
  
  if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturn;
  if (!get_val_ptr_param<string>( fname, p, n)) HelpAndReturn;

  itkWrite(input,*fname);

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
#endif // else ifdef AMI_USE_ITK

} // itkWrite()
