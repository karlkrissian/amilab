#ifndef _WITHOUT_ITK_

#include "itkImageLinearConstIteratorWithIndex.h"
#include "itkImageLinearIteratorWithIndex.h"

//using namespace itk;

#include "itkImageFileReader.h"
#include "itkImage.h"

#endif // _WITHOUT_ITK_

// #include "VarContexts.hpp"
#include "wrapfunctions.hpp" 


template <class TPixel, unsigned int Dimension> 
InrImage* ITKToInr(typename itk::Image<TPixel,Dimension>::Pointer image,
									typename itk::Image<TPixel,Dimension>::RegionType region)
{
	typedef TPixel               PixelType;
	typedef itk::Image< PixelType, Dimension >    ImageType;
	typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
	InrImage* res = NULL;

	ConstIteratorType inputIt( image, region);
	cout << "1 " << endl;
	// size 
	int dimx = region.GetSize(0);
	int dimy = region.GetSize(1);
	int dimz = 1;
	if (Dimension==3) dimz = region.GetSize(2);
	res = new InrImage(dimx,dimy,dimz,1,WT_FLOAT,"Image_itk.ami.gz");

	cout << "2 " << endl;
	res->SetTranslation(image->GetOrigin()[0],
						image->GetOrigin()[1],
						image->GetOrigin()[2]);
	res->SetVoxelSize(image->GetSpacing()[0],
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
}


template <class TPixel, unsigned int Dimension> 
typename itk::Image<TPixel,Dimension>::Pointer InrToITK(InrImage* input, 
								typename itk::Image<TPixel,Dimension>::RegionType &region)
{
	typedef  TPixel              PixelType;
	typedef typename itk::Image< TPixel,Dimension>    ImageType;
	
	typename ImageType::ConstPointer inputImage;
	typedef itk::ImageLinearConstIteratorWithIndex< ImageType >  ConstIteratorType;
	typedef itk::ImageLinearIteratorWithIndex< ImageType >       IteratorType;
	
	typename ImageType::Pointer image = ImageType::New();
	typename ImageType::SizeType size;

	size[0] = input->DimX();
	size[1] = input->DimY();
	if (Dimension==3) size[2] = input->DimZ();
	region.SetSize(size);
	image->SetRegions(region);
	image->Allocate();

	float origin[Dimension];
  origin[0] = input->TrX();
	origin[1] = input->TrY();
	if (Dimension==3) origin[2] = input->TrZ();
	image->SetOrigin(origin);
	float voxsize[Dimension];
  voxsize[0] = input->VoxSizeX();
	voxsize[1] = input->VoxSizeY();
	if (Dimension==3) voxsize[2] = input->VoxSizeZ();
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
	return image;
}