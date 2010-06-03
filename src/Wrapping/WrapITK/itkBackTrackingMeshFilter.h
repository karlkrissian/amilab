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

#ifndef __itkBackTrackingImageFilter_h
#define __itkBackTrackingImageFilter_h

#include "itkImageToMeshFilter.h"
#include "itkImage.h"
#include "itkMesh.h"

namespace itk
{

/** \class BackTrackingImageFilter
 *  This filter creates a path starting at a point and following the displacements
 *  given by the input vector field image if the input is scalar the corresponding 
 *  vector field is computed from its gradient by local linear interpolation 
 *  the tracking stops in one of the following cases: 
 *      - the maximal distance is reached 
 *      - the closest voxel to the current location has a negative intensity 
 *      - the current gradient is very low 
 *
 *  \par Inputs and Outputs
 *  This is an image-to-mesh filter.  The requirements for data types and
 *  dimensionality of the input and output are defined by subclasses.  In
 *  general, these filters expect images of real-valued types.  This means
 *  pixel types of floats, doubles, or a user-defined type with floating point
 *  accuracy and arithmetic operations.
 *
 *  \par Parameters
 *  Set/Get startX, startY and startZ specifies the coordinates for the point
 *  where the path starting to grow.
 *  \par
 *  Set/Get stepSize is used to set the time step for the evolution.
 *  \par
 *  Set/Get maxLength set the Maximal Euclidean distance of the path.
 *  \par
 *  Set/Get delta is the small incremente used to estimate the derivatives 
 *  based on linear interpolation.
 *
 *  \par How to use this filter
 *  This filter require an input based on a fast marching solution. 
 *  This input should be double type to compute better the differents 
 *  steps to arrive at the final solution.
 *  The output will be a mesh that represent the path.
 *  You need to initialize the dimension to use in this filter. 
 *  It is think to use in 3D images.
 *  \par Note: not supported multithreaded.
*/
template <class TInputImage, class TOutputMesh, unsigned int TDimension>
class ITK_EXPORT BackTrackingMeshFilter :
    public ImageToMeshFilter< TInputImage, TOutputMesh>
{
public:
  /** Standard class typedefs. */
  typedef BackTrackingMeshFilter                        Self;
  typedef ImageToMeshFilter< TInputImage, TOutputMesh > Superclass;
  typedef SmartPointer< Self >                          Pointer;
  typedef SmartPointer< const Self >                    ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(BackTrackingMeshFilter, ImageToMeshFilter);

  /** Image type information. */
  typedef TInputImage InputImageType;
  typedef TInputImage OutputImageType;
  typedef TOutputMesh OutputMeshType;
  
  /** Set/Get the X coordinate */
  itkSetMacro(startX, double); // start X
  itkGetMacro(startX, double);
  
  /** Set/Get the Y coordinate */
  itkSetMacro(startY, double); // start Y
  itkGetMacro(startY, double);
  
  /** Set/Get the Z coordinate (only for 3D images) */
  itkSetMacro(startZ, double); // start Z
  itkGetMacro(startZ, double);
  
  /** Set/Get the time step for the evolution */
  itkSetMacro(stepSize, double); // stepSize
  itkGetMacro(stepSize, double);
  
  /** Set/Get the Maximal Euclidean distance of the path. */
  itkSetMacro(maxLength, double); // maxLength
  itkGetMacro(maxLength, double);
  
  /** Set/Get the small increment for the derivatives */
  itkSetMacro(delta, double); // delta
  itkGetMacro(delta, double);
  
protected:
  BackTrackingMeshFilter()
  {
    m_startX = 0.0;
    m_startY = 0.0;
    m_startZ = 0.0;
    
    m_stepSize = 0.1;
    m_maxLength = 500;
    
    m_delta = 0.05;
  }
  virtual ~BackTrackingMeshFilter() {}
  void PrintSelf(std::ostream& os, Indent indent) const;

  void GenerateData();

private:
  BackTrackingMeshFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  double m_startX;
  double m_startY;
  double m_startZ;
  
  double m_stepSize;
  double m_maxLength;
  double m_delta;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBackTrackingMeshFilter.txx"
#endif

#endif
