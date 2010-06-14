
#include "AMILabConfig.h"
#include "amilab_messages.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileReader.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include <itkRGBAPixel.h>

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 

#include "ami_itkRead.h"

//-------------------------------------------------------------------------------
InrImage* wrap_itkRead(ParamList* p)
{

#ifdef AMI_USE_ITK

  char functionname[] = "itkRead";
  char description[]=" \n\
        Use itk Reader factory to read a 3D image file of type unsigned short\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
          string: filename\n\
      ";
    
  std::string*  fname = NULL;
  //InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<string>( fname, p, n)) HelpAndReturnNULL;

  return itkRead(*fname);

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK

} // wrap_itkRead()
