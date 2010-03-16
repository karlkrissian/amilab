#include "AMILabConfig.h"

#ifndef _WITHOUT_ITK_
#include "itkOrientedImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include "itkImageFileWriter.h"
#endif // _WITHOUT_ITK_

#include "wrapfunctions.hpp" 
#include "wrapConversion.tpp"
#include "wrapitkDICOMReadWrite.h"

InrImage* wrap_itkDICOMRead(ParamList* p)
{
#ifndef _WITHOUT_ITK_

	char functionname[] = "itkDICOMRead";
  char description[]=" \n\
        Solution for read a DICOM series.\n\
      ";
	  
  char parameters[] =" \n\
          Parameters:\n\
          DicomFolder \n\
			";
			
	string* DicomFolder = NULL;
  InrImage* res = NULL;
  int n=0;
	
	if (!get_string_param(  DicomFolder,      p, n)) HelpAndReturnNULL;
  
  typedef signed short PixelType;
  const unsigned int Dimension = 3;

  typedef itk::OrientedImage< PixelType, Dimension > ImageType;
  ImageType::RegionType region;
	
	typedef itk::ImageSeriesReader< ImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  
  typedef itk::GDCMImageIO ImageIOType;
  ImageIOType::Pointer dicomIO = ImageIOType::New();
  
  reader->SetImageIO( dicomIO );

  typedef itk::GDCMSeriesFileNames NamesGeneratorType;
  NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();

  nameGenerator->SetDirectory( *DicomFolder );

  typedef std::vector< std::string > SeriesIdContainer;
    
  const SeriesIdContainer & seriesUID = nameGenerator->GetSeriesUIDs();
    
  SeriesIdContainer::const_iterator seriesItr = seriesUID.begin();
  SeriesIdContainer::const_iterator seriesEnd = seriesUID.end();
  while( seriesItr != seriesEnd )
  {
		std::cout << seriesItr->c_str() << std::endl;
    seriesItr++;
  }

  std::string seriesIdentifier;
  
  seriesIdentifier = seriesUID.begin()->c_str();
      
  typedef std::vector< std::string > FileNamesContainer;
  FileNamesContainer fileNames;
	
	fileNames = nameGenerator->GetFileNames( seriesIdentifier );

  reader->SetFileNames( fileNames );

	reader->Update();

  res = ITKToInr<PixelType,Dimension>(reader->GetOutput(), reader->GetOutput()->GetLargestPossibleRegion());
	
	return res;

  //typedef itk::ImageFileWriter< ImageType > WriterType;
  //WriterType::Pointer writer = WriterType::New();
    
  //writer->SetFileName( *fname );

  //writer->SetInput( reader->GetOutput() );

	//writer->Update();
			
#else
  fprintf(stderr," ITK not available, you need to compile with ITK ...\n");
  return NULL;
#endif // _WITHOUT_ITK_	
} //itkDICOMReadWrite