/*  ==================================================
    Module : vtkLevelSets
    Authors: Karl Krissian
    Email  : karl@bwh.harvard.edu

    This module implements a Active Contour evolution
    for segmentation of 2D and 3D images.
    It implements a 'codimension 2' levelsets as an
    option for the smoothing term.
    It comes with a Tcl/Tk interface for the '3D Slicer'.
    ==================================================
    Copyright (C) 2003  LMI, Laboratory of Mathematics in Imaging, 
    Brigham and Women's Hospital, Boston MA USA

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    ================================================== 
   The full GNU Lesser General Public License file is in vtkLevelSets/LesserGPL_license.txt
*/

/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageIsoContourDist.h,v $
  Language:  C++
  Date:      $Date: 2003/04/28 18:13:23 $
  Version:   $Revision: 1.1 $
  Author:    Karl Krissian

=========================================================================*/
// .NAME vtkImageIsoContourDist - short description

// .SECTION Description
// vtkImageIsoContourDist
//
// Compute the distance to an isocontour
//

#ifndef _vtkImageIsoContourDist_h
#define _vtkImageIsoContourDist_h

#include <vtkLevelSetsConfigure.h>
#include "vtkImageAlgorithm.h"
#include "vtkFloatArray.h"

class VTK_LEVELSETS_EXPORT vtkImageIsoContourDist : public vtkImageAlgorithm
{
public:
  static vtkImageIsoContourDist *New();
  vtkTypeMacro(vtkImageIsoContourDist,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description

  // Intensity of the IsoContour
  vtkSetMacro(threshold,float);
  vtkGetMacro(threshold,float);

  // value for voxel not neighbors to the isocontour
  vtkSetMacro(farvalue,float);
  vtkGetMacro(farvalue,float);

  // Modify the input image without creating the output
  //  vtkSetMacro(     modify_input,int);
  //  vtkGetMacro(     modify_input,int);
  //  vtkBooleanMacro( modify_input,int);

  void InitParam();

  void UseOutputArray(float* array) { output_array = array; }

  void SetNarrowBand( int* band, int size);
  void SetMinMaxX( int** minx, int** maxx);

  // for multi-thread purpose
  int  SplitBand(int& first, int& last, int num, int total);
  void IsoSurfDist3D_band(int first_band,int last_band);

protected:
  vtkImageIsoContourDist();
  ~vtkImageIsoContourDist();

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  void IsoSurfDistInit();

  void IsoSurfDist2D();
  void IsoSurfDist3D();

  void IsoSurfDist3D_band();

//BTX
  float threshold;

  // value +/- farvalue for voxels which are not
  // neighbors to the isocontour.
  float farvalue;

  int tx,ty,tz,txy;
  unsigned long imsize;

  // Narrow Band Information
  int*           narrowband;
  int            bandsize;  

  // Limits for each line in X direction
  int** min_x;
  int** max_x;

  // We copy input data in float format
  vtkImageData *inputImage;
  int inputImage_allocated;

  //  int modify_input;

  vtkImageData *outputImage;

  // allows to use an array for the output image without allocation
  float* output_array;

  vtkFloatArray* float_array;
  unsigned char  float_array_allocated;

//ETX
};


#endif // _vtkImageIsoContourDist_h
