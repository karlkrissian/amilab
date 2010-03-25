#ifndef __itkBasicNLMeansFilter_txx
#define __itkBasicNLMeansFilter_txx

#include "itkBasicNLMeansFilter.h"
#include "itkConstNeighborhoodIterator.h"
#include "itkNeighborhoodIterator.h"
#include "itkImageRegionIterator.h"
//#include "itkImageRegionConstIterator.h"
#include "itkImageRegionConstIteratorWithIndex.h"
#include "itkNeighborhoodAlgorithm.h"
//#include "itkZeroFluxNeumannBoundaryCondition.h"


namespace itk
{

// template <class TInputImage, class TOutputImage>
// void 
// BasicNLMeansFilter<TInputImage,TOutputImage>
// ::GenerateInputRequestedRegion() throw(InvalidRequestedRegionError)
// {
  // // call the superclass' implementation of this method
  // Superclass::GenerateInputRequestedRegion();
  
  // // get pointers to the input and output
  // typename Superclass::InputImagePointer inputPtr = 
    // const_cast< TInputImage * >( this->GetInput() );
  // typename Superclass::OutputImagePointer outputPtr = this->GetOutput();
  
  // if ( !inputPtr || !outputPtr )
    // {
    // return;
    // }

  // // get a copy of the input requested region (should equal the output
  // // requested region)
  // typename TInputImage::RegionType inputRequestedRegion;
  // inputRequestedRegion = inputPtr->GetRequestedRegion();

  // // pad the input requested region by the operator radius
  // inputRequestedRegion.PadByRadius( m_Searching );

  // // crop the input requested region at the input's largest possible region
  // if ( inputRequestedRegion.Crop(inputPtr->GetLargestPossibleRegion()) )
    // {
    // inputPtr->SetRequestedRegion( inputRequestedRegion );
    // return;
    // }
  // else
    // {
    // // Couldn't crop the region (requested region is outside the largest
    // // possible region).  Throw an exception.

    // // store what we tried to request (prior to trying to crop)
    // inputPtr->SetRequestedRegion( inputRequestedRegion );
    
    // // build an exception
    // InvalidRequestedRegionError e(__FILE__, __LINE__);
    // e.SetLocation(ITK_LOCATION);
    // e.SetDescription("Requested region is (at least partially) outside the largest possible region.");
    // e.SetDataObject(inputPtr);
    // throw e;
    // }
// }

template < class TInputImage, class TOutputImage >
void BasicNLMeansFilter< TInputImage, TOutputImage >
::BeforeThreadedGenerateData()
{
	int i, j, p, k, f;
	double sum = 0;
	f = m_Pattern[0];
	double sigma = f/2.0;
	p = 0;
	static unsigned int dimen;
	
	typename TInputImage::ConstPointer input = this->GetInput();
	dimen = input->GetImageDimension();
	
	if (dimen == 2)
	{
		dist_weights = new double[(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)];
		for (j=-f;j<=f;j++)
		{
			for (i=-f;i<=f;i++)
			{
				dist_weights[p] = exp(-(i*i+j*j)/sigma/sigma);
				sum += dist_weights[p];
				p++;
			}
		}
		p = 0;
		for (j=-f;j<=f;j++)
		{
			for (i=-f;i<=f;i++)
			{
				dist_weights[p] /= sum;
				p++;
			}
		}
	}
	else
	{
		if (dimen == 3)
		{
			dist_weights = new double [(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)*(2*m_Pattern[0]+1)];
			for (k=-f;k<=f;k++)
			{
				for (j=-f;j<=f;j++)
				{
					for (i=-f;i<=f;i++)
					{
						dist_weights[p] = exp(-(i*i+j*j+k*k)/sigma/sigma);
						sum += dist_weights[p];
						p++;
					}
				}
			}
			p = 0;
			for (k=-f;k<=f;k++)
			{
				for (j=-f;j<=f;j++)
				{
					for (i=-f;i<=f;i++)
					{
						dist_weights[p] /= sum;
						p++;
					}
				}
			}					
		}
	}
}

template< class TInputImage, class TOutputImage >
void BasicNLMeansFilter< TInputImage, TOutputImage >
::ThreadedGenerateData(const OutputImageRegionType& outputRegionForThread,int threadId)
{

  static unsigned int dimen;
  double w;
  //int prc = 0;
  
  RealType diff;
  double dist = 0;
  double wmax = 0;
  double average = 0;
  double total_weight = 0;
  
  //ZeroFluxNeumannBoundaryCondition<TInputImage> nbc;

  ImageRegionConstIteratorWithIndex<TInputImage> bit;
  ImageRegionIterator<TOutputImage> it;
  ConstNeighborhoodIterator<TInputImage> f_it;
  ConstNeighborhoodIterator<TInputImage> faux_it;
  
  // Allocate output
  typename TOutputImage::Pointer output = this->GetOutput();
  typename TInputImage::ConstPointer input  = this->GetInput();
  dimen = input->GetImageDimension(); // 1er cambio y funciona
  
  // Find the data-set boundary "faces"
  typename NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage>::FaceListType faceList;
  NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage> bC;
  
  typename NeighborhoodAlgorithm::ImageBoundaryFacesCalculator<TInputImage>::FaceListType::iterator fit;

  // support progress methods/callbacks
  //ProgressReporter progress(this, threadId, outputRegionForThread.GetNumberOfPixels());
  
  //InputRealType sum;
  
  typename TInputImage::RegionType::IndexType inputStart;
  typename TInputImage::RegionType::IndexType test;
  typename TInputImage::RegionType::SizeType  size;
  typename TInputImage::RegionType region;

  // Process each of the boundary faces.  These are N-d regions which border
  // the edge of the buffer.
  
	bit = ImageRegionConstIteratorWithIndex<TInputImage>(input, outputRegionForThread);
	faux_it = ConstNeighborhoodIterator<TInputImage>(m_Pattern, input, outputRegionForThread);
	it = ImageRegionIterator<TOutputImage>(output, outputRegionForThread);
	
    for (bit.GoToBegin(), faux_it.GoToBegin(), it.GoToBegin(); !bit.IsAtEnd(); ++bit, ++faux_it, ++it)//while ( ! bit.IsAtEnd() )
    {
		wmax = 0;
		average = 0;
		total_weight = 0;
		
		test = bit.GetIndex();
		
		int j_min, j_max, i_min, i_max, k_min, k_max;
		#define macro_min(a,b) ((a)<(b)?(a):(b))
		#define macro_max(a,b) ((a)>(b)?(a):(b))
		i_min = (int)test[0]-(int)m_Searching;
		i_min = macro_max(i_min,0);
		
		i_max = (int)test[0]+(int)m_Searching;
		i_max = macro_min(i_max,(int)input->GetBufferedRegion().GetSize()[0]-1);
		
		j_min = (int)test[1]-(int)m_Searching;
		j_min = macro_max(j_min,0);
		
		j_max = (int)test[1]+(int)m_Searching;
		j_max = macro_min(j_max,(int)input->GetBufferedRegion().GetSize()[1]-1);
		
		if (dimen == 3) // 2ºcambio y funciona
		{
			k_min = (int)test[2]-(int)m_Searching;
			k_min = macro_max(k_min,0);
			
			k_max = (int)test[2]+(int)m_Searching;
			k_max = macro_min(k_max,(int)input->GetBufferedRegion().GetSize()[2]-1);
		}
		
		inputStart[0] = i_min;
		inputStart[1] = j_min;
		
		size[0] = i_max - i_min + 1;
		size[1] = j_max - j_min + 1;
		
		if (dimen == 3) // 3er cambio y funciona
		{
			inputStart[2] = k_min;
			size[2] = k_max - k_min + 1;
		}
		
		region.SetIndex(inputStart);
		region.SetSize(size);
		
		faceList = bC(input, region, m_Pattern);
		
		for (fit=faceList.begin(); fit != faceList.end(); ++fit)
		{
			f_it = ConstNeighborhoodIterator<TInputImage>(m_Pattern, input, *fit);
			//f_it.OverrideBoundaryCondition(&nbc);
			f_it.GoToBegin();
			while(!f_it.IsAtEnd())
			{
				unsigned int neighborhoodSize = f_it.Size();
				dist = 0;
				for (int i=0;i < (int)neighborhoodSize; i++)
				{
					diff = static_cast<RealType>(faux_it.GetPixel(i)) - static_cast<RealType>(f_it.GetPixel(i));
					dist += diff*diff*dist_weights[i];
				}

				w = exp(-dist/(m_Threshold*m_Threshold));
				
				if (w>wmax) wmax=w;
				
				switch (m_Noise)
				{
					case 0: average += w*static_cast<RealType>(f_it.GetCenterPixel());
							break;
					case 1: average += w*static_cast<RealType>(f_it.GetCenterPixel())*static_cast<RealType>(f_it.GetCenterPixel());
							break;
				}
				total_weight += w;
				
				++f_it;
			}
		}
		
		switch (m_Noise)
		{
			case 0: average += wmax*static_cast<RealType>(bit.Get());
					total_weight += wmax;
					it.Set(static_cast<OutputPixelType>(average/total_weight));
					break;
			case 1: average += wmax*static_cast<RealType>(bit.Get())*static_cast<RealType>(bit.Get());
					total_weight += wmax;
					it.Set(static_cast<OutputPixelType>(sqrt(average/total_weight)));
					break;
		}
    }   
}

template< class TInputImage, class TOutputImage >
void
BasicNLMeansFilter<TInputImage, TOutputImage>
::PrintSelf(std::ostream& os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);

  os << indent << "Searching window: " << m_Searching << std::endl;
  os << indent << "Pattern Window: " << m_Pattern << std::endl;
  os << indent << "Threshold: " << m_Threshold << std::endl;
  os << indent << "Noise: " << m_Noise << std::endl;
}

} // end namespace itk

#endif
