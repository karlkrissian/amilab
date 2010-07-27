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

#ifndef _WITHOUT_ITK_
#include "itkImage.h"
#include "itkMesh.h"
#include "itkBackTrackingMeshFilter.h"
#include "itkPointSet.h"
#endif // _WITHOUT_ITK_

#include <vtkPointData.h>

//#include "vtk_common.h"
#include "surface.hpp"
using namespace amilab;

#include "wrap_SurfacePoly.h"

#include "wrapfunctions.hpp"
#include "wrapConversion.tpp"
#include "wrapitkBackTrackingMeshFilter.h"

BasicVariable::ptr wrap_itkBackTrackingMeshFilter2D(ParamList* p)
{

    char functionname[] = "itkBackTrackingMeshFilter2D";
    char description[]=" \n\
        Filter to compute a backtracking solution in 2D.\n\
      ";

    char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          startX \n\
          startY \n\
          stepSize \n\
          maxLength \n\
          delta \n\
      ";

    InrImage* input = NULL;
    float     startX = 0.0;
    float     startY = 0.0;
    float     stepSize = 0.0;
    float     maxLength = 0.0;
    float     delta = 0.0;

    int n=0;

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  startX,     p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  startY,     p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  stepSize,   p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  maxLength,  p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  delta,      p, n)) HelpAndReturnVarPtr;

    typedef double        InternalPixelType;
    const unsigned int    Dimension = 2;

    typedef itk::Image< InternalPixelType, Dimension > InternalImageType;
    InternalImageType::RegionType region;
    InternalImageType::Pointer image;

    typedef itk::Mesh<InternalPixelType,Dimension> MeshType;

    MeshType::Pointer output = MeshType::New();

    // Convert from InrImage to ITK
    cout << "Converting image to ITK format " << endl;

    image = InrToITK<InternalPixelType,Dimension>(input,region);

    cout << "Conversion done" << endl;

    typedef itk::BackTrackingMeshFilter<InternalImageType,MeshType,Dimension> BackTrackingFilterType;
    BackTrackingFilterType::Pointer BackTracking = BackTrackingFilterType::New();

    BackTracking->SetInput(0, image );
    BackTracking->SetstartX( startX );
    BackTracking->SetstartY( startY );
    BackTracking->SetstepSize( stepSize );
    BackTracking->SetmaxLength( maxLength );
    BackTracking->Setdelta( delta );
    BackTracking->Update();

    typedef itk::PointSet<InternalPixelType,Dimension> PointSetType;
    PointSetType::PointIdentifier pointID;
    typedef PointSetType::PointType PointType;
    PointType pp;

    SurfacePoly* surf;
    surf = new SurfacePoly;
    surf->NewLine();
    int num_points=0;

    // Conversion to amilab type to show it
    for (int i=0;i<BackTracking->GetOutput()->GetNumberOfPoints();i++)
    {
        pointID = i;
        bool pointExists = BackTracking->GetOutput()->GetPoint(pointID,&pp);
        surf->AddPoint(pp[0],pp[1],0);
        surf->LineAddPointNumber(num_points);
        num_points++;
    }
    surf->EndLine();

    return CreateVar_SurfacePoly(surf);

} // wrap_itkBackTrackingMeshFilter2D


//Variable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList* p)
BasicVariable::ptr wrap_itkBackTrackingMeshFilter3D(ParamList* p)
{

    char functionname[] = "itkBackTrackingMeshFilter3D";
    char description[]=" \n\
        Filter to compute a backtracking solution in 3D.\n\
      ";

    char parameters[] =" \n\
          Parameters:\n\
          input image \n\
          startX \n\
          startY \n\
          startZ \n\
          stepSize \n\
          maxLength \n\
          delta \n\
      ";

    InrImage* input = NULL;
    float     startX = 0.0;
    float     startY = 0.0;
    float     startZ = 0.0;
    float     stepSize = 0.0;
    float     maxLength = 0.0;
    float     delta = 0.0;

    int n=0;

    if (!get_val_ptr_param<InrImage>(  input,      p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  startX,     p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  startY,     p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  startZ,     p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  stepSize,   p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  maxLength,  p, n)) HelpAndReturnVarPtr;
    if (!get_val_param<float>       (  delta,      p, n)) HelpAndReturnVarPtr;

    typedef double       InternalPixelType;
    const unsigned int   Dimension = 3;

    typedef itk::Image< InternalPixelType, Dimension > InternalImageType;
    InternalImageType::RegionType region;
    InternalImageType::Pointer image;

    typedef itk::Mesh<InternalPixelType,Dimension> MeshType;

    MeshType::Pointer output = MeshType::New();

    // Convert from InrImage to ITK
    cout << "Converting image to ITK format " << endl;

    image = InrToITK<InternalPixelType,Dimension>(input,region);

    cout << "Conversion done" << endl;

    typedef itk::BackTrackingMeshFilter<InternalImageType,MeshType,Dimension> BackTrackingFilterType;
    BackTrackingFilterType::Pointer BackTracking = BackTrackingFilterType::New();

    BackTracking->SetInput(0, image );
    BackTracking->SetstartX( startX );
    BackTracking->SetstartY( startY );
    BackTracking->SetstartZ( startZ );
    BackTracking->SetstepSize( stepSize );
    BackTracking->SetmaxLength( maxLength );
    BackTracking->Setdelta( delta );
    BackTracking->Update();

    //vtkFloatingPointType triangle[3];
    typedef itk::PointSet<InternalPixelType,Dimension> PointSetType;
    PointSetType::PointIdentifier pointID;
    typedef PointSetType::PointType PointType;
    PointType pp;

    SurfacePoly* surf;
    surf = new SurfacePoly;
    surf->NewLine();
    int num_points=0;

    for (int i=0;i<BackTracking->GetOutput()->GetNumberOfPoints();i++)
    {
        pointID = i;
        bool pointExists = BackTracking->GetOutput()->GetPoint(pointID,&pp);
        surf->AddPoint(pp[0],pp[1],pp[2]);
        surf->LineAddPointNumber(num_points);
        num_points++;
    }
    surf->EndLine();

    return CreateVar_SurfacePoly(surf);

} // wrap_itkBackTrackingMeshFilter3D
