#ifndef __itkBackTrackingImageFilter_txx
#define __itkBackTrackingImageFilter_txx

#include "itkBackTrackingMeshFilter.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkLineSpatialObject.h"
#include "itkImage.h"
#include "itkPoint.h"
#include "math.h"
#include "itkImageRegionIterator.h"
#include "itkContinuousIndex.h"
#include "itkSpatialObjectWriter.h"
#include "itkMesh.h"
#include "itkLineCell.h"


namespace itk
{

template< class TInputImage, class TOutputMesh, unsigned int TDimension>
void BackTrackingMeshFilter< TInputImage, TOutputMesh, TDimension >
::GenerateData()
{
  // Allocate output
  typename TInputImage::ConstPointer input  = this->GetInput(0);
  
  TOutputMesh::Pointer output = this->GetOutput();

  TOutputMesh::Pointer mesh = TOutputMesh::New();
  TOutputMesh::PointType point;

  typedef typename TOutputMesh::CellType CellType;
  typedef typename itk::LineCell<CellType> LineType;
  typedef typename CellType::CellAutoPointer CellAutoPointer;
  CellAutoPointer line;

  line.TakeOwnership( new LineType );

  double p[TDimension];
  p[0] = m_startX;
  p[1] = m_startY;
  if (input->GetImageDimension() == 3) p[2] = m_startZ;
  double q[TDimension];
  double vox_p[TDimension];
  bool end_reached = false;
  double distance = 0.0;
  double step;
  double vx,vy,vz,nv;
  double vpx,vpy,vpz;
  double I,Ixp,Ixm,Iyp,Iym,Izp,Izm;
  double closest_point_intensity;

  OutputImageType::Pointer image = OutputImageType::New();
  OutputImageType::IndexType index;
  OutputImageType::IndexType pos;
      
  vox_p[0] = (p[0]-input->GetOrigin()[0])/(double)input->GetSpacing()[0];
  vox_p[1] = (p[1]-input->GetOrigin()[1])/input->GetSpacing()[1];
  if (input->GetImageDimension() == 3) vox_p[2] = (p[2]-input->GetOrigin()[2])/input->GetSpacing()[2];

  index[0] = vox_p[0];
  index[1] = vox_p[1];
  if (input->GetImageDimension() == 3) index[2] = vox_p[2];

  typedef typename double TInterpolatorPrecisionType;
  typedef typename itk::ContinuousIndex<TInterpolatorPrecisionType, TDimension> ContinuousIndexType;

  typedef typename itk::LinearInterpolateImageFunction< InputImageType, TInterpolatorPrecisionType >  InterpolatorType;
  InterpolatorType::Pointer interpolator = InterpolatorType::New();

  ContinuousIndexType coord;

  if (!input->GetLargestPossibleRegion().IsInside(index))
  {
    std::cout << "Initial point not within image domain" << std::endl;
  }
  for(int i=0;i<1;i++) q[i] = p[i];
  if (input->GetImageDimension() == 3) for(int i=0;i<2;i++) q[i] = p[i];

  int numpoints = 0;
    
  while (!end_reached)
  {
    point[0] = p[0];
    point[1] = p[1];
    point[2] = p[2];
    output->SetPoint(numpoints,point);
    if (numpoints != 0)
    {
      line->SetPointId(0,numpoints-1);
      line->SetPointId(1,numpoints);
    }
    output->SetCell(numpoints,line);
    line.TakeOwnership( new LineType );
    numpoints += 1;
    
    step = m_delta;
    vpx = vox_p[0];
    vpy = vox_p[1];
    if (input->GetImageDimension() == 3) vpz = vox_p[2];
    
    coord[0] = vpx;
    coord[1] = vpy;
    if (input->GetImageDimension() == 3) coord[2] = vpz;
    interpolator->SetInputImage(input);
    if (interpolator->IsInsideBuffer(coord)) 
      I = interpolator->EvaluateAtContinuousIndex(coord); 
    else
      std::cout << "point not within image domain" << std::endl;
    
    coord[0] = vpx+step;
    coord[1] = vpy;
    if (input->GetImageDimension() == 3) coord[2] = vpz;
    interpolator->SetInputImage(input);
    if (interpolator->IsInsideBuffer(coord)) 
      Ixp = interpolator->EvaluateAtContinuousIndex(coord); 
    else
      std::cout << "point not within image domain" << std::endl;

    coord[0] = vpx-step;
    coord[1] = vpy;
    if (input->GetImageDimension() == 3) coord[2] = vpz;
    interpolator->SetInputImage(input);
    if (interpolator->IsInsideBuffer(coord)) 
      Ixm = interpolator->EvaluateAtContinuousIndex(coord); 
    else
      std::cout << "point not within image domain" << std::endl;

    coord[0] = vpx;
    coord[1] = vpy+step;
    if (input->GetImageDimension() == 3) coord[2] = vpz;
    interpolator->SetInputImage(input);
    if (interpolator->IsInsideBuffer(coord)) 
      Iyp = interpolator->EvaluateAtContinuousIndex(coord); 
    else
      std::cout << "point not within image domain" << std::endl;

    coord[0] = vpx;
    coord[1] = vpy-step;
    if (input->GetImageDimension() == 3) coord[2] = vpz;
    interpolator->SetInputImage(input);
    if (interpolator->IsInsideBuffer(coord)) 
      Iym = interpolator->EvaluateAtContinuousIndex(coord); 
    else
      std::cout << "point not within image domain" << std::endl;
    
    if (input->GetImageDimension() == 3)
    {
      coord[0] = vpx;
      coord[1] = vpy;
      if (input->GetImageDimension() == 3) coord[2] = vpz+step;
      interpolator->SetInputImage(input);
      if (interpolator->IsInsideBuffer(coord)) 
        Izp = interpolator->EvaluateAtContinuousIndex(coord); 
      else
        std::cout << "point not within image domain" << std::endl;

      coord[0] = vpx;
      coord[1] = vpy;
      if (input->GetImageDimension() == 3) coord[2] = vpz-step;
      interpolator->SetInputImage(input);
      if (interpolator->IsInsideBuffer(coord)) 
        Izm = interpolator->EvaluateAtContinuousIndex(coord); 
      else
        std::cout << "point not within image domain" << std::endl;
    }
    
    if ((Ixp<=Ixm)&&(Ixp<I))
      vx = (I-Ixp)/(step*input->GetSpacing()[0]);
    else
      if ((Ixm<Ixp)&&(Ixm<I))
      vx = (Ixm-I)/(step*input->GetSpacing()[0]);
    else
      vx = 0;
      
    if ((Iyp<=Iym)&&(Iyp<I))
      vy = (I-Iyp)/(step*input->GetSpacing()[1]);
    else
    if ((Iym<Iyp)&&(Iym<I))
      vy = (Iym-I)/(step*input->GetSpacing()[1]);
    else
      vy = 0;
      
    if (input->GetImageDimension() ==3)
    {
      if ((Izp<=Izm)&&(Izp<I))
        vz = (I-Izp)/(step*input->GetSpacing()[2]);
      else
      if ((Izm<Izp)&&(Izm<I))
        vz = (Izm-I)/(step*input->GetSpacing()[2]);
      else
        vz = 0;
    }
    
    nv = sqrt(vx*vx+vy*vy);
    if (input->GetImageDimension() == 3) nv = sqrt(vx*vx+vy*vy+vz*vz);
        
    if (nv>1E-4)
    {
      vx /= nv;
      vy /= nv;
      if (input->GetImageDimension() == 3) vz /= nv;
    }
    else
    {
      int xpos = round(vpx);
      int ypos = round(vpy);
      int zpos;
      if (input->GetImageDimension() == 3) zpos = round(vpz);
      float valmin = I;
      bool minfound = false;
      int xmin,ymin,zmin;
      for (int i=-1;i<=1;i++)
      {
        for (int j=-1;j<=1;j++)
        {
          if (input->GetImageDimension() == 3) for (int k=-1;k<=1;k++)
          {
            pos[0] = xpos + i;
            pos[1] = ypos + j;
            if (input->GetImageDimension() == 3) pos[2] = zpos + k;
            if (input->GetLargestPossibleRegion().IsInside(pos))
            {
              if (input->GetPixel(pos) < valmin)
              {
                valmin = input->GetPixel(pos);
                xmin = xpos+i;
                ymin = ypos+j;
                if (input->GetImageDimension() ==3) zmin = zpos+k;
                minfound = true;
              }
            }
          }
        }
      }
      if (minfound)
      {
        vx = (xmin-vpx)*input->GetSpacing()[0];
        vy = (ymin-vpy)*input->GetSpacing()[1];
        vz = (zmin-vpz)*input->GetSpacing()[2];
        nv = sqrt(vx*vx+vy*vy);
        if (input->GetImageDimension() == 3) nv = sqrt(vx*vx+vy*vy+vz*vz);
      }
      else
      {
        std::cout << "no minimum found among neighbors" << std::endl;
      }
      if (nv>1E-4)
      {
        vx /= m_stepSize;
        vy /= m_stepSize;
        if (input->GetImageDimension() == 3) vz /=m_stepSize;
      }
    }
    
    pos[0] = round(vox_p[0]);
    pos[1] = round(vox_p[1]);
    if (input->GetImageDimension() == 3) pos[2] = round(vox_p[2]);
    closest_point_intensity = input->GetPixel(pos);
       
    distance += m_stepSize;

    p[0] += vx*m_stepSize;
    p[1] += vy*m_stepSize;
    if (input->GetImageDimension() == 3) p[2] += vz*m_stepSize;
    
    vox_p[0] = (p[0]-input->GetOrigin()[0])/input->GetSpacing()[0];
    vox_p[1] = (p[1]-input->GetOrigin()[1])/input->GetSpacing()[1];
    if (input->GetImageDimension() == 3) vox_p[2] = (p[2]-input->GetOrigin()[2])/input->GetSpacing()[2];

    pos[0] = vox_p[0];
    pos[1] = vox_p[1];
    if (input->GetImageDimension() == 3) pos[2] = vox_p[2];
    
    end_reached = !input->GetLargestPossibleRegion().IsInside(pos) || (nv<1E-5) || (distance>m_maxLength) || (closest_point_intensity<0);
    end_reached = end_reached || (vox_p[0]<0) || (vox_p[1]<0) || (vox_p[2]<0);
  }
}

template< class TInputImage, class TOutputMesh, unsigned int TDimension >
void
BackTrackingMeshFilter<TInputImage, TOutputMesh, TDimension>
::PrintSelf(std::ostream& os, Indent indent) const
{
	Superclass::PrintSelf(os,indent);

  os << indent << "startX: " << m_startX << std::endl;
  os << indent << "startY: " << m_startY << std::endl;
  os << indent << "startZ: " << m_startZ << std::endl;
  os << indent << "stepSize: " << m_stepSize << std::endl;
  os << indent << "maxLength: " << m_maxLength << std::endl;
  os << indent << "delta: " << m_delta << std::endl;
}

} // end namespace itk

#endif
