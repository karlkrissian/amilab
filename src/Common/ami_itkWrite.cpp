//
// C++ Implementation: ami_itkWrite.cpp
//
// Description: writes InrImage in itk format
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

//#include "paramlist.h"


#include "ami_itkWrite.h"

#include "AMILabConfig.h"
#include "amilab_messages.h"

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileWriter.h"
#include "itkImageLinearConstIteratorWithIndex.h"
#include <itkRGBPixel.h>
#include <itkRGBAPixel.h>

#include "wrapConversion.h"

/** Read a 3D Flow from an ASCII file **/
template<class TPixel, unsigned int Dimension>
class itkWriteClass {
  typedef typename itk::Image< TPixel, Dimension>    ImageType;
  typedef typename itk::ImageFileWriter< ImageType >  WriterType;

  public: 
    bool operator()(typename ImageType::Pointer image, const std::string& filename) 
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

#define INRWRITEITK_VECT(type,dim,vdim)  { \
        itk::Image< itk::Vector<type,vdim>, dim >::RegionType region; \
        itk::Image< itk::Vector<type,vdim>, dim >::Pointer image;     \
        image = InrToITK_Vect<itk::Vector<type,vdim>,dim>(input,region); \
        return itkWriteClass<itk::Vector<type,vdim>,dim>()(image,fname);   }

#define INRWRITEITK_RGB(type,dim)  { \
        itk::Image< itk::RGBPixel<type>, dim >::RegionType region; \
        itk::Image< itk::RGBPixel<type>, dim >::Pointer image;     \
        image = InrToITK_Vect<itk::RGBPixel<type>,dim>(input,region); \
        return itkWriteClass<itk::RGBPixel<type>,dim>()(image,fname);   }

#define INRWRITEITK_RGBA(type,dim)  { \
        itk::Image< itk::RGBAPixel<type>, dim >::RegionType region; \
        itk::Image< itk::RGBAPixel<type>, dim >::Pointer image;     \
        image = InrToITK_Vect<itk::RGBAPixel<type>,dim>(input,region); \
        return itkWriteClass<itk::RGBAPixel<type>,dim>()(image,fname);   }

//----------------------------------------------------------------
bool itkWrite(InrImage* input, const std::string& fname) 
{

  const WORDTYPE image_component_type = input->GetFormat();
  FILE_MESSAGE((boost::format("Writing %1% z dim: %2%") % fname % input->DimZ()).str().c_str());
  
  // for scalar images
  if ((input->GetVDim())==1) {
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
          FILE_ERROR("Format not supported ");  
          return false;
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
          FILE_ERROR("Format not supported ");  
          return false;
      }
  } else
  // for floating point vectorial images (2D vectors)
  if ((input->GetVDim())==2) {
    if (input->DimZ()==1)  
    {
      switch(image_component_type) { 
        case WT_FLOAT         :  INRWRITEITK_VECT(float,  2,2); break;
        case WT_DOUBLE        :  INRWRITEITK_VECT(double, 2,2); break;
        default:  
          FILE_ERROR("Format not supported ");  
          return false;
      }
    }  else
      switch(image_component_type) { 
        case WT_FLOAT         :  INRWRITEITK_VECT(float,  3,2); break;
        case WT_DOUBLE        :  INRWRITEITK_VECT(double, 3,2); break;
        default:  
          FILE_ERROR("Format not supported ");  
          return false;
      }
  } else 
  // for floating point vectorial images (3D vectors)
  if ((input->GetVDim())==3) {
    if (input->DimZ()==1)  
    {
      switch(image_component_type) { 
        case WT_RGB           :  INRWRITEITK_RGB(unsigned char, 2); break;
        case WT_RGBA          :  INRWRITEITK_RGBA(unsigned char,2); break;
        case WT_FLOAT         :  INRWRITEITK_VECT(float,  2,3); break;
        case WT_DOUBLE        :  INRWRITEITK_VECT(double, 2,3); break;
        default:  
          FILE_ERROR("Format not supported ");  
          return false;
      }
    }  else
      switch(image_component_type) { 
        case WT_RGB           :  INRWRITEITK_RGB(unsigned char,3); break;
        case WT_RGBA          :  INRWRITEITK_RGBA(unsigned char,3); break;
        case WT_FLOAT         :  INRWRITEITK_VECT(float,  3,3); break;
        case WT_DOUBLE        :  INRWRITEITK_VECT(double, 3,3); break;
        default:  
          FILE_ERROR("Format not supported ");  
          return false;
      }
  } else {
    FILE_ERROR("Format not supported");
    return false;
  }
  return true;
}

/*
std::vector<std::string> itkWriteGetExtensions( InrImage* input)
{

}
*/
