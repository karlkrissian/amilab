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
#include "wrapitkRead.h"


template<class TPixel, unsigned int Dimension>
class itkReadClass {
  typedef typename itk::Image< TPixel, Dimension>    ImageType;
  typedef typename itk::ImageFileReader< ImageType > ReaderType;

  
  private:
    InrImage* CreateImage( int dimx, int dimy, int dimz, WORDTYPE type, const string& name) {
      return new InrImage(dimx,dimy,dimz,1,type,"Image_itk.ami.gz");
    }

  public: 
    InrImage* operator()(const string& filename, WORDTYPE type, int vdim=1) 
    { 
    #ifdef AMI_USE_ITK

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
      int dim[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) 
        dim[i] = region.GetSize(i);
      res = new InrImage(dim[0],dim[1],dim[2],vdim,type,"Image_itk.ami.gz");

      float tr[3] = {0,0,0};
      float vs[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) {
        tr[i] = inputImage->GetOrigin()[i];
        vs[i] = inputImage->GetSpacing()[i];
        cout << "vs["<<i<<"] = " << vs[i] << endl;
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


    static InrImage* ConvertVector(const string& filename, WORDTYPE type, int vdim) 
    { 
    #ifdef AMI_USE_ITK

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
      int dim[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) 
        dim[i] = region.GetSize(i);
      res = new InrImage(dim[0],dim[1],dim[2],vdim,type,"Image_itk.ami.gz");

      int tr[3] = {0,0,0};
      int vs[3] = {1,1,1};
      for (unsigned int i=0; i<Dimension; i++) {
        tr[i] = inputImage->GetOrigin()[i];
        vs[i] = inputImage->GetSpacing()[i];
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
          // vectorial type
          for(int i=0;i<vdim;i++)
            res->VectFixeValeur(i,inputIt.Get()[i]);
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
InrImage* itkRead(const std::string& fname)
{

#ifdef AMI_USE_ITK

  InrImage* res = NULL;

  itk::ImageIOBase* image_io=NULL;
  typedef  itk::Image< unsigned char, 3>    ImageType;
  typedef  itk::ImageFileReader< ImageType >  ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  typedef   itk::ImageIOBase::IOComponentType comptype;
  comptype image_component_type = itk::ImageIOBase::UNKNOWNCOMPONENTTYPE;
  typedef   itk::ImageIOBase::IOPixelType ptype;
  ptype image_pixel_type = itk::ImageIOBase::UNKNOWNPIXELTYPE;

  try {
    reader->SetFileName( fname.c_str());
    reader->GenerateOutputInformation();
    image_io= reader->GetImageIO();
    image_component_type = image_io->GetComponentType();
    image_pixel_type = image_io->GetPixelType();
    cout << "  Component Type = " << image_io->GetComponentTypeAsString(image_component_type) << endl;
    cout << "  Pixel Type = "     << image_io->GetPixelTypeAsString(image_pixel_type) << endl;
    cout << "  Number of Dimensions = "<< image_io->GetNumberOfDimensions() << endl;
    int vdim = image_io->GetNumberOfComponents();
    cout << "  Number of Components = "<< vdim << endl;
//->PrintSelf(cout,itk::Indent(2));

  } catch( itk::ExceptionObject & err ) {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return NULL;
  }

  int vdim = image_io->GetNumberOfComponents();
  const unsigned int image_dim = image_io->GetNumberOfDimensions();

#define READ_IMAGE(imdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR:  res = itkReadClass<unsigned char,  imdim>()(fname,WT_UNSIGNED_CHAR);   break; \
    case itk::ImageIOBase::USHORT: res = itkReadClass<unsigned short, imdim>()(fname,WT_UNSIGNED_SHORT);  break; \
    case itk::ImageIOBase::SHORT:  res = itkReadClass<signed short,   imdim>()(fname,WT_SIGNED_SHORT);    break; \
    case itk::ImageIOBase::UINT:   res = itkReadClass<unsigned int,   imdim>()(fname,WT_UNSIGNED_INT);    break; \
    case itk::ImageIOBase::INT:    res = itkReadClass<signed int,     imdim>()(fname,WT_SIGNED_INT);      break; \
    case itk::ImageIOBase::ULONG:  res = itkReadClass<unsigned long,  imdim>()(fname,WT_UNSIGNED_LONG);   break; \
    case itk::ImageIOBase::FLOAT:  res = itkReadClass<float,          imdim>()(fname,WT_FLOAT);           break; \
    case itk::ImageIOBase::DOUBLE: res = itkReadClass<double,         imdim>()(fname,WT_DOUBLE);          break; \
    case itk::ImageIOBase::CHAR:    \
    case itk::ImageIOBase::UNKNOWNPIXELTYPE:  \
    default:  \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }

#define READ_VECTOR_IMAGE(imdim,vdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR: \
      res = itkReadClass<itk::Vector<unsigned char,vdim>,  imdim>::\
            ConvertVector(fname,WT_UNSIGNED_CHAR,vdim);   break; \
    case itk::ImageIOBase::USHORT: \
      res = itkReadClass<itk::Vector<unsigned short,vdim>, imdim>::\
            ConvertVector(fname,WT_UNSIGNED_SHORT,vdim);  break; \
    case itk::ImageIOBase::SHORT: \
      res = itkReadClass<itk::Vector<signed short,vdim>,   imdim>::  \
            ConvertVector(fname,WT_SIGNED_SHORT,vdim);    break; \
    case itk::ImageIOBase::UINT:  \
      res = itkReadClass<itk::Vector<unsigned int,vdim>,   imdim>::\
            ConvertVector(fname,WT_UNSIGNED_INT,vdim);    break; \
    case itk::ImageIOBase::INT:  \
      res = itkReadClass<itk::Vector<signed int,vdim>,     imdim>::\
            ConvertVector(fname,WT_SIGNED_INT,vdim);      break; \
    case itk::ImageIOBase::ULONG: \
      res = itkReadClass<itk::Vector<unsigned long,vdim>,  imdim>::  \
            ConvertVector(fname,WT_UNSIGNED_LONG,vdim);   break; \
    case itk::ImageIOBase::FLOAT: \
      res = itkReadClass<itk::Vector<float,vdim>,          imdim>::\
            ConvertVector(fname,WT_FLOAT,vdim);           break; \
    case itk::ImageIOBase::DOUBLE:  \
      res = itkReadClass<itk::Vector<double,vdim>,         imdim>::\
            ConvertVector(fname,WT_DOUBLE,vdim);          break; \
    case itk::ImageIOBase::UNKNOWNPIXELTYPE:\
    default:  \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }

/*
    case itk::ImageIOBase::CHAR:    \
    case itk::ImageIOBase::UNKNOWNPIXELTYPE:  \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }
*/

#define READ_RGB_IMAGE(imdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR:  res = itkReadClass<itk::RGBPixel<unsigned char>,  imdim>::ConvertVector(fname,WT_RGB,3);   break; \
    case itk::ImageIOBase::USHORT: res = itkReadClass<itk::RGBPixel<unsigned short>, imdim>::ConvertVector(fname,WT_UNSIGNED_SHORT,3);  break; \
    default: \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }

#define READ_RGBA_IMAGE(imdim) \
  switch(image_component_type) { \
    case itk::ImageIOBase::UCHAR:  res = itkReadClass<itk::RGBAPixel<unsigned char>,  imdim>::ConvertVector(fname,WT_RGBA,4);   break; \
    case itk::ImageIOBase::USHORT: res = itkReadClass<itk::RGBAPixel<unsigned short>, imdim>::ConvertVector(fname,WT_UNSIGNED_SHORT,4);  break; \
    default: \
      cerr << "Format not supported in InrImage class "<< endl;  \
  }

  switch (image_pixel_type) {
    case itk::ImageIOBase::SCALAR:
      switch (image_dim) {
        //case 1: READ_IMAGE(1); break;
        case 2: READ_IMAGE(2); break;
        case 3: READ_IMAGE(3); break;
        default:
          cerr << " InrImage format does not support images of dimension " << image_dim << endl;
      }
    break;

    case itk::ImageIOBase::VECTOR:
      switch (vdim) {
        case 2: {
            switch (image_dim) {
              //case 1: READ_VECTOR_IMAGE(1,2); break;
              case 2: READ_VECTOR_IMAGE(2,2); break;
              case 3: READ_VECTOR_IMAGE(3,2); break;
              default:
                cerr << " InrImage format does not support images of dimension " << image_dim << endl;
            }
          }
         break;
        case 3: {
          switch (image_dim) {
            //case 1: READ_VECTOR_IMAGE(1,3); break;
            case 2: READ_VECTOR_IMAGE(2,3); break;
            case 3: READ_VECTOR_IMAGE(3,3); break;
            default:
              cerr << " InrImage format does not support images of dimension " << image_dim << endl;
          }
          } break;
        default:
          FILE_ERROR("Only 2D and 3D vector fields are supported at the moment");
       }
    break;

    case itk::ImageIOBase::RGB:
      switch (image_dim) {
        //case 1: READ_RGB_IMAGE(1); break;
        case 2: READ_RGB_IMAGE(2); break;
        case 3: READ_RGB_IMAGE(3); break;
        default:
          cerr << " InrImage format does not support images of dimension " << image_dim << endl;
      }
    break;
    case itk::ImageIOBase::RGBA:
      switch (image_dim) {
        //case 1: READ_RGBA_IMAGE(1); break;
        case 2: READ_RGBA_IMAGE(2); break;
        case 3: READ_RGBA_IMAGE(3); break;
        default:
          cerr << " InrImage format does not support images of dimension " << image_dim << endl;
      }
    break;
    default:
        cerr << boost::format(" itkRead() \t pixel type %s% not supported in this release") % image_io->GetPixelTypeAsString(image_pixel_type)
              << endl;
    return NULL;
  }



cout << image_component_type << endl;
cout << itk::ImageIOBase::USHORT << endl;
// compilation pb with long: don't know why
// /home/karl/projects/Sourceforge/amilab/src/WrapITK/wrapITK.cpp:216: error: expected unqualified-id before 'long'
//    case itk::ImageIOBase::LONG:   res = itkReadClass<signed long,    imdim>()(*fname,WT_SIGNED_LONG);     break; 
//


  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK

} // itkRead()


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
