/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
               Sara Arencibia
    Email    : karl@bwh.harvard.edu
               darkmind@gmail.com

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "AMILabConfig.h"

#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#ifndef _WITHOUT_ITK_
#include <stddef.h>
#include "itkOrientedImage.h"
#include "itkImageSeriesReader.h"
#include "itkDICOMImageIO2.h"
#include "itkDICOMSeriesFileNames.h"
#include "itkImageIOBase.h"
#endif // _WITHOUT_ITK_

#include "paramlist.h"
#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkDICOMRead.h"


template<class PixelType, unsigned int Dimension>
class itkReadDICOMClass {
  typedef itk::OrientedImage< PixelType, Dimension > ImageType;
  typedef itk::ImageSeriesReader< ImageType > ReaderType;
  
  private:
    InrImage* CreateImage( int dimx, int dimy, int dimz, WORDTYPE type, const std::string& name) {
      return new InrImage(dimx,dimy,dimz,1,type,"Image_itk.ami.gz");
    }

  public: 
    InrImage* operator()(std::vector< std::string > fileNames, WORDTYPE type, int vdim=1) 
    { 
    #ifdef AMI_USE_ITK

      InrImage* res = NULL;
    
      typename ReaderType::Pointer reader = ReaderType::New();
    
      typename ImageType::ConstPointer inputImage;
      typedef typename itk::ImageLinearConstIteratorWithIndex< ImageType > ConstIteratorType;
    
      reader->SetFileNames( fileNames );

      try
        {
        reader->Update();
        inputImage = reader->GetOutput();
        }
      catch( itk::ExceptionObject & err )
        {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
        return NULL;
        }
    
      typename ImageType::RegionType region= inputImage->GetRequestedRegion();
      ConstIteratorType inputIt( inputImage, region);
      // size 
      int dim[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) 
        dim[i] = region.GetSize(i);
      res = new InrImage(dim[0],dim[1],dim[2],vdim,type,"Image_itk.ami.gz");

      float tr[3] = {0,0,0};
      float vs[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) {
        tr[i] = inputImage->GetOrigin()[i];
        vs[i] = inputImage->GetSpacing()[i];
        std::cout << "vs["<<i<<"] = " << vs[i] << std::endl;
      }
      res->SetTranslation( tr[0], tr[1], tr[2]);
      res->SetVoxelSize(   vs[0], vs[1], vs[2]);
    
      res->InitBuffer();
      inputIt.SetDirection(0);
      for ( inputIt.GoToBegin(); ! inputIt.IsAtEnd();  inputIt.NextLine())
        {
        inputIt.GoToBeginOfLine();
        while ( ! inputIt.IsAtEndOfLine() )
          {
          res->FixeValeur( inputIt.Get() );
          ++inputIt;
          res->IncBuffer();
          }
        }
    
      return res;
    
    #else
      fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
      return NULL;
    #endif // AMI_USE_ITK

    }
};


//-------------------------------------------------------------------------------------
InrImage* itkDICOMRead(const std::string DicomFolder)
{

//#ifdef AMI_USE_ITK

  InrImage* res = NULL;

  itk::ImageIOBase* image_io=NULL;
  typedef  itk::Image< unsigned char, 3>    ImageType;
  typedef  itk::ImageSeriesReader< ImageType >  ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  typedef   itk::ImageIOBase::IOComponentType comptype;
  comptype image_component_type = itk::ImageIOBase::UNKNOWNCOMPONENTTYPE;
  typedef   itk::ImageIOBase::IOPixelType ptype;
  ptype image_pixel_type = itk::ImageIOBase::UNKNOWNPIXELTYPE;
  typedef itk::DICOMImageIO2 ImageIOType;
  ImageIOType::Pointer dicomIO = ImageIOType::New();

  typedef itk::DICOMSeriesFileNames NamesGeneratorType;
  NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();
  typedef std::vector< std::string > SeriesIdContainer;
  typedef std::vector< std::string > FileNamesContainer;
  FileNamesContainer fileNames;
  
  try {
    nameGenerator->SetDirectory( DicomFolder );
    const SeriesIdContainer & seriesUID = nameGenerator->GetSeriesUIDs();
    
    if (seriesUID.size()>0) {
      SeriesIdContainer::const_iterator seriesItr = seriesUID.begin();
      SeriesIdContainer::const_iterator seriesEnd = seriesUID.end();
      while( seriesItr != seriesEnd )
      {
        std::cout << seriesItr->c_str() << std::endl;
        seriesItr++;
      }
      std::string seriesIdentifier;
      seriesIdentifier = seriesUID.begin()->c_str();
                    
      fileNames = nameGenerator->GetFileNames( seriesIdentifier );
  
      reader->SetImageIO( dicomIO );
      reader->SetFileNames( fileNames );
      reader->Update();
      reader->GenerateOutputInformation();
      image_io= reader->GetImageIO();
      image_component_type = image_io->GetComponentType();
      image_pixel_type = image_io->GetPixelType();
      std::cout << "  Component Type = " << image_io->GetComponentTypeAsString(image_component_type) << std::endl;
      std::cout << "  Pixel Type = "     << image_io->GetPixelTypeAsString(image_pixel_type) << std::endl;
      std::cout << "  Number of Dimensions = "<< image_io->GetNumberOfDimensions() << std::endl;
      int vdim = image_io->GetNumberOfComponents();
      std::cout << "  Number of Components = "<< vdim << std::endl;
    } else
    {
      FILE_ERROR("Dicom series not found ...");
      return NULL;
    }

  } catch( itk::ExceptionObject & err ) {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
  }

//  int vdim = image_io->GetNumberOfComponents();
  const unsigned int image_dim = image_io->GetNumberOfDimensions();

#define READ_IMAGE(imdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR:  res = itkReadDICOMClass<unsigned char,  imdim>()(fileNames,WT_UNSIGNED_CHAR);   break; \
    case itk::ImageIOBase::USHORT: res = itkReadDICOMClass<unsigned short, imdim>()(fileNames,WT_UNSIGNED_SHORT);  break; \
    case itk::ImageIOBase::SHORT:  res = itkReadDICOMClass<signed short,   imdim>()(fileNames,WT_SIGNED_SHORT);    break; \
    case itk::ImageIOBase::CHAR:    \
    case itk::ImageIOBase::UNKNOWNPIXELTYPE:  \
    default:  \
      std::cerr << "Format not supported in InrImage class "<< std::endl;  \
  }

  switch (image_pixel_type) {
    case itk::ImageIOBase::SCALAR:
      switch (image_dim) {
        case 1: READ_IMAGE(1); break;
        case 2: READ_IMAGE(2); break;
        case 3: READ_IMAGE(3); break;
        default:
          std::cerr << " InrImage format does not support images of dimension " << image_dim << std::endl;
      }
    break;

    default:
        std::cerr << boost::format(" itkRead() \t pixel type %s% not supported in this release") % image_io->GetPixelTypeAsString(image_pixel_type)
              << std::endl;
    return NULL;
  }

 std::cout << image_component_type << std::endl;
 std::cout << itk::ImageIOBase::USHORT << std::endl;

  return res;

//#else
//  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
//  return NULL;
//#endif // AMI_USE_ITK

} // itkDICOMRead()


//-------------------------------------------------------------------------------
InrImage* wrap_itkDICOMRead(ParamList* p)
{

//#ifdef AMI_USE_ITK

  char functionname[] = "itkDICOMRead";
  char description[]=" \n\
        Use itk to read a DICOM image folfer\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
          string: DicomFolder\n\
      ";
    
  std::string*  DicomFolder = NULL;
  int n=0;
  
  if (!get_val_ptr_param<std::string>( DicomFolder, p, n)) HelpAndReturnNULL;

  return itkDICOMRead(*DicomFolder);

//#else
//  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
//  return NULL;
//#endif // AMI_USE_ITK

} // wrap_itkDICOMRead()
