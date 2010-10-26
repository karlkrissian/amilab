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

#ifndef __itkBackTrackingImageFilter_txx
#define __itkBackTrackingImageFilter_txx

#include "itkBackTrackingMeshFilter.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkImage.h"
#include "math.h"
#include "itkMesh.h"
#include "itkLineCell.h"

namespace itk
{

template< class TInputImage, class TOutputMesh, unsigned int TDimension>
void BackTrackingMeshFilter< TInputImage, TOutputMesh, TDimension >
::GenerateData()
{
  
  typename TInputImage::ConstPointer input  = this->GetInput(0);
  
  // Allocate mesh output
  typename TOutputMesh::Pointer output = this->GetOutput();

  typename TOutputMesh::Pointer mesh = TOutputMesh::New();
  typename TOutputMesh::PointType point;

  // Use to create the path adding points to a line
  typedef typename TOutputMesh::CellType CellType;
  typedef typename itk::LineCell<CellType> LineType;
  typedef typename CellType::CellAutoPointer CellAutoPointer;
  CellAutoPointer line;

  line.TakeOwnership( new LineType );

  double p[TDimension];
  double q[TDimension];
  double vox_p[TDimension];
  bool   end_reached = false;
  double distance = 0.0;
  double step;
  double vx,vy,vz,nv;
  double vpx = 0.0,vpy = 0.0,vpz = 0.0;
  double I=0,Ixp=0,Ixm=0,Iyp=0,Iym=0,Izp=0,Izm=0;
  double closest_point_intensity;
  
  p[0] = m_startX;
  p[1] = m_startY;
  if (input->GetImageDimension() == 3) p[2] = m_startZ;

  //typename OutputImageType::Pointer image = OutputImageType::New();
  typename OutputImageType::IndexType index;
  typename OutputImageType::IndexType pos;

  // SpaceToVoxel in X, Y and Z.
  vox_p[0] = (p[0]-input->GetOrigin()[0])/(double)input->GetSpacing()[0];
  vox_p[1] = (p[1]-input->GetOrigin()[1])/input->GetSpacing()[1];
  if (input->GetImageDimension() == 3) vox_p[2] = (p[2]-input->GetOrigin()[2])/input->GetSpacing()[2];

  index[0] = vox_p[0];
  index[1] = vox_p[1];
  if (input->GetImageDimension() == 3) index[2] = vox_p[2];

  // Linear interpolator to compute downwind gradient
  typedef double    TInterpolatorPrecisionType;
  typedef typename  itk::ContinuousIndex<TInterpolatorPrecisionType, TDimension> ContinuousIndexType;

  typedef typename  itk::LinearInterpolateImageFunction< InputImageType, TInterpolatorPrecisionType >  InterpolatorType;
  typename          InterpolatorType::Pointer interpolator = InterpolatorType::New();

  // Need to pass the coordinates to the interpolator filter
  ContinuousIndexType coord;

  // Is the initial point inside the image domain ?
  if (!input->GetLargestPossibleRegion().IsInside(index))
  {
    std::cout << "Initial point not within image domain" << std::endl;
  }
  for(int i=0;i<1;i++) q[i] = p[i];
  if (input->GetImageDimension() == 3) for(int i=0;i<2;i++) q[i] = p[i];

  int numpoints = 0;
  
  // Until not reach the end point continue iterating.
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
    
    // Compute downwind gradient to ensure evolution toward lower intensities
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
    
    
    // Go in the oposite direction of the gradient and towards lower values
    // Need to multiply the step value to the VoxSize
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

    // If the gradient is stong enough, normalize it
    if (nv>1E-4)
    {
      vx /= nv;
      vy /= nv;
      if (input->GetImageDimension() == 3) vz /= nv;
    }
    else
    {
      // Look fot the minimal over the neighbors
      int xpos = round(vpx);
      int ypos = round(vpy);
      int zpos;
      if (input->GetImageDimension() == 3) zpos = round(vpz);
      float valmin = I;
      bool minfound = false;
      int xmin=0,ymin=0,zmin=0;
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
        // Move toward the neighbor point with lower intensity
        vx = (xmin-vpx)*input->GetSpacing()[0];
        vy = (ymin-vpy)*input->GetSpacing()[1];
        if (input->GetImageDimension() == 3) vz = (zmin-vpz)*input->GetSpacing()[2];
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
    // Small fix for stopping vessel int CTA challenge
    end_reached = end_reached || (vox_p[0]<0) || (vox_p[1]<0) ;
    if (input->GetImageDimension() == 3) end_reached = end_reached || (vox_p[2]<0);
  }
}

// Using for debugging
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
