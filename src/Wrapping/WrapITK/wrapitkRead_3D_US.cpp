#include "AMILabConfig.h"

#ifdef AMI_USE_ITK

#include "itkImage.h"
#include "itkImageIOBase.h"
#include "itkImageFileReader.h"
#include "itkImageLinearConstIteratorWithIndex.h"

#endif // AMI_USE_ITK

#include "wrapfunctions.hpp" 


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
    #endif // AMI_USE_ITK

    }  
};


InrImage* itkRead_3D_US(ParamList* p)
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
    
  std::string*  filename_param = NULL;
  InrImage* res = NULL;
  int n=0;
  
  if (!get_val_ptr_param<string>( filename_param, p, n)) HelpAndReturnNULL;

  res = itkReadClass<unsigned short,3>()(*filename_param,WT_UNSIGNED_SHORT);

  return res;

#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // AMI_USE_ITK

} // itkRead()
