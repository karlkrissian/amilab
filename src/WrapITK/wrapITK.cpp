//
// C++ Implementation: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//



#ifndef _WITHOUT_ITK_

#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"
#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkIsoContourDistanceImageFilter.h"

//using namespace itk;

#include "itkImageFileReader.h"

#endif // _WITHOUT_ITK_

#include "VarContexts.hpp"
#include "wrapfunctions.hpp" 
#include "wrapITK.h"

extern VarContexts  Vars;

//---------------------------------------------------------
void AddWrapITK(){
 Vars.AddVar(type_c_image_function,"itkRead_3D_US",     (void*) itkRead_3D_US);
 Vars.AddVar(type_c_image_function,"itkRead",     (void*) itkRead);
 Vars.AddVar(type_c_image_function,"itkIsoContourDist", (void*) itkIsoContourDist);
}


/** Read a 3D Flow from an ASCII file **/
template<class TPixel, unsigned int Dimension>
class itkReadClass {
  typedef typename itk::Image< TPixel, Dimension>    ImageType;
  typedef typename itk::ImageFileReader< ImageType >  ReaderType;
  
  private:
    InrImage* CreateImage( int dimx, int dimy, int dimz, WORDTYPE type, const string& name) {
      return new InrImage(dimx,dimy,dimz,1,type,"Image_itk.ami.gz");
    }

  public: 
    InrImage* operator()(const string& filename, WORDTYPE type) 
    { 
    #ifndef _WITHOUT_ITK_

      InrImage* res = NULL;
    
      typename ReaderType::Pointer reader2 = ReaderType::New();
    
      typename ImageType::ConstPointer inputImage;
      typedef typename itk::ImageLinearConstIteratorWithIndex< ImageType >       ConstIteratorType;
    
      reader2->SetFileName( filename.c_str());
    
      try
        {
        reader2->Update();
        inputImage = reader2->GetOutput();
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
      int dimx = region.GetSize(0);
      int dimy = region.GetSize(1);
      int dimz = 1;
      if (Dimension>=3) {
        dimz = region.GetSize(2);
      }
      res = new InrImage(dimx,dimy,dimz,1,type,"Image_itk.ami.gz");
    
      if (Dimension>=3) {
        res->SetTranslation(  inputImage->GetOrigin()[0],
                              inputImage->GetOrigin()[1],
                              inputImage->GetOrigin()[2]);
        res->SetVoxelSize(  inputImage->GetSpacing()[0],
                            inputImage->GetSpacing()[1],
                            inputImage->GetSpacing()[2]);
      } else {
        res->SetTranslation(  inputImage->GetOrigin()[0],
                              inputImage->GetOrigin()[1],
                              0);
        res->SetVoxelSize(  inputImage->GetSpacing()[0],
                            inputImage->GetSpacing()[1],
                            1);
      }
    
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
    #endif // _WITHOUT_ITK_

    }  
};




//
InrImage* itkRead_3D_US(ParamList* p)
{

#ifndef _WITHOUT_ITK_

	char functionname[] = "itkRead";
	char description[]=" \n\
        Use itk Reader factory to read a 3D image file of type unsigned short\n\
			";
	char parameters[] =" \n\
          Parameters:\n\
          string: filename\n\
			";
    
  std::string*  filename_param = NULL;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_string_param( filename_param, p, n)) HelpAndReturnNULL;

  res = itkReadClass<unsigned short,3>()(*filename_param,WT_UNSIGNED_SHORT);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // itkRead()


//
InrImage* itkRead(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkRead";
  char description[]=" \n\
        Use itk Reader factory to read a 3D image file of type unsigned short\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
          string: filename\n\
      ";
    
  std::string*  fname = NULL;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_string_param( fname, p, n)) HelpAndReturnNULL;

  itk::ImageIOBase* image_io=NULL;
  typedef  itk::Image< unsigned char, 3>    ImageType;
  typedef  itk::ImageFileReader< ImageType >  ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  typedef   itk::ImageIOBase::IOComponentType comptype;
  comptype image_component_type = itk::ImageIOBase::UNKNOWNCOMPONENTTYPE;
  typedef   itk::ImageIOBase::IOPixelType ptype;
  ptype image_pixel_type = itk::ImageIOBase::UNKNOWNPIXELTYPE;

  try {
    reader->SetFileName( fname->c_str());
    reader->GenerateOutputInformation();
    image_io= reader->GetImageIO();
    image_component_type = image_io->GetComponentType();
    image_pixel_type = image_io->GetPixelType();
    cout << "  Component Type = " << image_io->GetComponentTypeAsString(image_component_type) << endl;
    cout << "  Pixel Type = "     << image_io->GetPixelTypeAsString(image_pixel_type) << endl;
    cout << "  Number of Dimensions = "<< image_io->GetNumberOfDimensions() << endl;
    cout << "  Number of Components = "<< image_io->GetNumberOfComponents() << endl;
//->PrintSelf(cout,itk::Indent(2));

  } catch( itk::ExceptionObject & err ) {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
  }

  const unsigned int image_dim = image_io->GetNumberOfDimensions();
  if (image_pixel_type != itk::ImageIOBase::SCALAR) {
    cerr << " itkRead() \t only supports scalar type for the moment " << endl;
    return NULL;
  }

#define READ_IMAGE(imdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR:  res = itkReadClass<unsigned char,  imdim>()(*fname,WT_UNSIGNED_CHAR);   break; \
    case itk::ImageIOBase::USHORT: res = itkReadClass<unsigned short, imdim>()(*fname,WT_UNSIGNED_SHORT);  break; \
    case itk::ImageIOBase::SHORT:  res = itkReadClass<signed short,   imdim>()(*fname,WT_SIGNED_SHORT);    break; \
    case itk::ImageIOBase::UINT:   res = itkReadClass<unsigned int,   imdim>()(*fname,WT_UNSIGNED_INT);    break; \
    case itk::ImageIOBase::INT:    res = itkReadClass<signed int,     imdim>()(*fname,WT_SIGNED_INT);      break; \
    case itk::ImageIOBase::ULONG:  res = itkReadClass<unsigned long,  imdim>()(*fname,WT_UNSIGNED_LONG);   break; \
    case itk::ImageIOBase::FLOAT:  res = itkReadClass<float,          imdim>()(*fname,WT_FLOAT);           break; \
    case itk::ImageIOBase::DOUBLE: res = itkReadClass<double,         imdim>()(*fname,WT_DOUBLE);          break; \
    case itk::ImageIOBase::CHAR:    \
    case itk::ImageIOBase::UNKNOWNPIXELTYPE:  \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }

cout << image_component_type << endl;
cout << itk::ImageIOBase::USHORT << endl;
// compilation pb with long: don't know why
// /home/karl/projects/Sourceforge/amilab/src/WrapITK/wrapITK.cpp:216: error: expected unqualified-id before 'long'
//    case itk::ImageIOBase::LONG:   res = itkReadClass<signed long,    imdim>()(*fname,WT_SIGNED_LONG);     break; \

  switch (image_dim) {
//    case 1: READ_IMAGE(1); break;
    case 2: READ_IMAGE(2); break;
    case 3: READ_IMAGE(3); break;
    default:
      cerr << " InrImage format does not support images of dimension " << image_dim << endl;
  }

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // itkRead()


//-------------------------------------------------------------------------------
//
InrImage* itkIsoContourDist(ParamList* p)
{

#ifndef _WITHOUT_ITK_

  char functionname[] = "itkIsoContourDist";
  char description[]=" \n\
        Computes an approximation of the distance to the isocontour\n\
      ";
  char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          isocontour threshold (def:0)\n\
          far value (def:10)\n\
      ";
    
  std::string*  filename_param = NULL;
  InrImage* input = NULL;
  float     threshold = 0;
  float     farvalue = 10;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_image_param(  input,      p, n)) HelpAndReturnNULL;
  if (!get_float_param(  threshold,  p, n)) HelpAndReturnNULL;
  if (!get_float_param(  farvalue,   p, n)) HelpAndReturnNULL;

  typedef float               PixelType;
  const   unsigned int        Dimension = 3;
  typedef itk::Image< PixelType, Dimension >    ImageType;

  // Convert from InrImage to ITK
  cout << "Converting image to ITK format " << endl;
  ImageType::ConstPointer inputImage;
  typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
  typedef itk::ImageLinearIteratorWithIndex< ImageType >       IteratorType;

  ImageType::Pointer image = ImageType::New();
  ImageType::SizeType size;
  size[0] = input->DimX();
  size[1] = input->DimY();
  size[2] = input->DimZ();
  ImageType::RegionType region( size );
  image->SetRegions( region );
  image->Allocate();

  float origin[3]  = {input->TrX(),input->TrY(),input->TrZ()};
  image->SetOrigin(origin);
  float voxsize[3] = {input->VoxSizeX(),input->VoxSizeY(),input->VoxSizeZ()};
  image->SetSpacing(voxsize);

  IteratorType iter( image, region );
  iter.GoToBegin();
  input->InitBuffer();
  iter.SetDirection(0);
  for ( iter.GoToBegin(); ! iter.IsAtEnd();  iter.NextLine())
    {
    iter.GoToBeginOfLine();
    while ( ! iter.IsAtEndOfLine() )
      {
      iter.Set(input->ValeurBuffer());
      ++iter;
      input->IncBuffer();
      }
    }

  // Apply the filter
  // Set up  image filter
  cout << "Applying filter " << endl;

  try {
    typedef itk::IsoContourDistanceImageFilter<ImageType,ImageType> IsoContourType;
    IsoContourType::Pointer isocontour = IsoContourType::New();
    isocontour->SetInput( image );
    isocontour->SetFarValue(farvalue);
    isocontour->SetLevelSetValue(threshold );
    isocontour->NarrowBandingOff();
    isocontour->SetNumberOfThreads(1);
    isocontour->Update();
    image = isocontour->GetOutput();
  } catch (itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
    }

  // Convert from ITK to InrImage
  cout << "Converting back to InrImage " << endl;

//  ImageType::RegionType region= inputImage->GetRequestedRegion();
  ConstIteratorType inputIt( image, region);
  cout << "1 " << endl;
  // size 
  int dimx = region.GetSize(0);
  int dimy = region.GetSize(1);
  int dimz = region.GetSize(2);
  res = new InrImage(dimx,dimy,dimz,1,WT_FLOAT,"Image_itk.ami.gz");

  cout << "2 " << endl;
  res->SetTranslation(  image->GetOrigin()[0],
                        image->GetOrigin()[1],
                        image->GetOrigin()[2]);
  res->SetVoxelSize(  image->GetSpacing()[0],
                      image->GetSpacing()[1],
                      image->GetSpacing()[2]);


  cout << "3 " << endl;
  int i=0;
  res->InitBuffer();
  inputIt.SetDirection(0);
  for ( inputIt.GoToBegin(); ! inputIt.IsAtEnd();  inputIt.NextLine())
    {
    inputIt.GoToBeginOfLine();
    //cout << "line number "<< i << endl;
    while ( ! inputIt.IsAtEndOfLine() )
      {
      res->FixeValeur( inputIt.Get() );
      ++inputIt;
      if (!res->IncBuffer()) 
        cout << "! res->IncBuffer()" << endl;
      }
      i++;
    }

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_

} // itkIsoContourDist
