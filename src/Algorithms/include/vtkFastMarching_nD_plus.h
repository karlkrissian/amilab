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

// .NAME vtkFastMarching_nD_plus - short description

// .SECTION Description
// vtkFastMarching_nD_plus 
//
//

#ifndef __vtkFastMarching_nD_plus_h
#define __vtkFastMarching_nD_plus_h

#include <vtkLevelSetsConfigure.h>
#include "vtkPointData.h"
#include "vtkImageData.h"
#include "vtkImageToImageFilter.h"


//BTX
#include "vtkMinHeap.h"
//ETX

#include <list>
//using -- namespace std;

#define VTK_VAL_ACCEPTED 0
#define VTK_VAL_TRIAL    1
#define VTK_VAL_FAR      2

#define VTK_MODE_2D 2
#define VTK_MODE_3D 3


//BTX
class FM_TrialPoint_nD_plus;

class target_point_nD_plus {
public:
  int x;
  int y;
  int z;
  int t;
  
  target_point_nD_plus(int _x,int _y, int _z, int _t) 
  {
    x = _x;
    y = _y;
    z = _z;
    t = _t;
  }
};

void UpdateMinHeapPos(unsigned int image_pos, int pos, void* data);

//----------------------------------------------------------------------
//
class VTK_LEVELSETS_EXPORT FM_TrialPoint_nD_plus {

public:
  short   x,y,z,t;
  long    impos;
  int     track;
  // minimal value for the neighbor in each direction:
  // 0,1,2 for X,Y,Z
  float   valmin[4];
  float   value;

  FM_TrialPoint_nD_plus()
  {
    x = y = z = t = impos = 0;
    value = 
    valmin[0] = 
    valmin[1] =
    valmin[2] =
    valmin[3] = 1E5;
    track = -1;
  }

  FM_TrialPoint_nD_plus(int px, int py, int pz, int pt, int im_pos, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    t     = pt;
    impos = im_pos;
    value = val;
    valmin[0] = 
    valmin[1] =
    valmin[2] =
    valmin[3] = 1E5;
    track = -1;
  }


  FM_TrialPoint_nD_plus& operator=(const FM_TrialPoint_nD_plus& p)
  {
    x     = p.x;
    y     = p.y;
    z     = p.z;
    t     = p.t;
    impos = p.impos;
    value = p.value;
    valmin[0] = p.valmin[0];
    valmin[1] = p.valmin[1];
    valmin[2] = p.valmin[2];
    valmin[3] = p.valmin[3];
    track = p.track;
    return *this;
  }


  void Init(int px, int py, int pz, int pt,  int im_pos, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    t     = pt;
    impos = im_pos;
    value = val;
    valmin[0] = 
    valmin[1] =
    valmin[2] =
    valmin[3] = 1E5;
  }


  void SetValue(float val) { value=val; }
  void SetTrack(int t)     { track = t; }


  friend inline int operator < ( const FM_TrialPoint_nD_plus& p1, const FM_TrialPoint_nD_plus& p2)
  {
    return (p1.value < p2.value);
  }

  friend inline int operator > ( const FM_TrialPoint_nD_plus& p1, const FM_TrialPoint_nD_plus& p2)
  {
    return (p1.value > p2.value);
  }

  friend std::ostream& operator << (std::ostream&, const FM_TrialPoint_nD_plus& p);

}; // FM_TrialPoint_nD_plus


//ETX

//----------------------------------------------------------------------
class VTK_EXPORT vtkFastMarching_nD_plus : public vtkImageToImageFilter
{
public:
  vtkTypeRevisionMacro(vtkFastMarching_nD_plus,vtkImageToImageFilter);
  void PrintSelf(std::ostream& os, vtkIndent indent);

  // Description:
  // Construct object to extract all of the input data.
  static vtkFastMarching_nD_plus *New();

  //
  vtkGetMacro(voxelsize_time, vtkFloatingPointType);
  vtkSetMacro(voxelsize_time, vtkFloatingPointType);

  //
  vtkSetMacro(dim,int);
  vtkGetMacro(dim,int);

  //
  vtkGetMacro(tx,int);

  //
  vtkGetMacro(ty,int);

  //
  vtkGetMacro(tz,int);

  //
  vtkGetMacro(tt,int);

  //
  vtkSetMacro(cx,int);
  vtkGetMacro(cx,int);

  //
  vtkSetMacro(cy,int);
  vtkGetMacro(cy,int);

  //
  vtkSetMacro(cz,int);
  vtkGetMacro(cz,int);

  //
  vtkSetMacro(ct,int);
  vtkGetMacro(ct,int);

  //
  vtkSetMacro(radius,float);
  vtkGetMacro(radius,float);

  //
  vtkSetMacro(maxTime,float);
  vtkGetMacro(maxTime,float);

  //
  vtkSetObjectMacro(mask,vtkImageData);
  vtkGetObjectMacro(mask,vtkImageData);

  //
  vtkSetObjectMacro(track,vtkImageData);
  vtkGetObjectMacro(track,vtkImageData);

  //
  vtkSetObjectMacro(initimage,vtkImageData);
  vtkGetObjectMacro(initimage,vtkImageData);

  //
  vtkSetMacro(initiso,float);
  vtkGetMacro(initiso,float);

  //
  vtkSetMacro(initmaxdist,float);
  vtkGetMacro(initmaxdist,float);

  //
  vtkSetMacro(EvolutionScheme,int);
  vtkGetMacro(EvolutionScheme,int);

  // Initialization of the time image
//  void Init( int cx, int cy, int cz, int ct, int radius);

  void UseOutputArray(float* array) { output_array = array; }

//  void SetNarrowBand( int* band, int size);

  //
  void SetGaussianForce( float mean, float sd)
    {
      UseGaussianForce=1;
      IntensityMean=mean;
      IntensityStandardDeviation=sd;
    }

  void AddTargetPoint( int x, int y, int z, int t) 
  {
    target_points.push_back(target_point_nD_plus(x,y,z,t));
  } 

protected:
  vtkFastMarching_nD_plus();
  ~vtkFastMarching_nD_plus();

  vtkFastMarching_nD_plus(const vtkFastMarching_nD_plus&);
  void operator=(const vtkFastMarching_nD_plus&);

  void ExecuteData(vtkDataObject* output);
  void InitParam();

//BTX
  // 2D or 3D processing
  int dim;

  // image size
  int tx,ty,tz,tt,txy,imsize;
  int inc_t,inc_x,inc_y,inc_z;
  int inc[4];

  // voxel size
  vtkFloatingPointType vs[4];

  // Spacing in the time component
  vtkFloatingPointType voxelsize_time;

  // inverse of the squared voxel size
  vtkFloatingPointType ivs2[4];

  // center of the initial sphere
  int cx,cy,cz,ct;

  // radius of the initial sphere
  float radius;

  // MinHeap binary tree object
  vtkMinHeap<FM_TrialPoint_nD_plus> mh;

  // Maximal treated evolution time
  float maxTime;

  // Output: time at which the surface goes though each point
  vtkImageData* T;

  // Input: the force that drives the evolution
  vtkImageData* force;
  unsigned char force_allocated;

  // status of the voxels (or pixels)
  unsigned char* status;

  // Position of each point in the MinHeap array
  unsigned int* mhPos;

  // Mask where to evolve the surface
  vtkImageData* mask;
  unsigned char mask_allocated;

  // Mask where to evolve the surface
  vtkImageData* track;

  // Initialize with an isosurface : threshold
  float                initiso;

  // Initialize with an image
  vtkImageData* initimage;
  float                initmaxdist;

  // pointers to the first element of the images data
  float* T_buf;  
  float* force_buf;

  // 0: Sethian
  // 1: Dijkstra
  int  EvolutionScheme;

  unsigned char isotropic_voxels;

  float* output_array;

  // Gaussian Intensity Based Force
  int         UseGaussianForce;
  float       IntensityMean;
  float       IntensityStandardDeviation;

  // Evolve until a set of points are reached
  std::list<target_point_nD_plus> target_points;

//ETX

  // Initialization of the time image
  //  void Init( int cx, int cy, int cz, int radius);
  //  void Init2D( int cx, int cy, int radius);
  //  void Init3D( int cx, int cy, int cz, int radius);
  //  void Init4D( int cx, int cy, int cz, int ct, int radius);

  //
  void InitWithImage();

  // 
  void InitIsoSurf();

  long GetPosition( const short& x, const short& y, const short& z, const short&  t) const
  {
    return ((z*ty+y)*tx+x)*tt+t;
  }

  void CoordinatesFromPosition( short& x, short& y, short& z,short& t, long pos) const
  {
    long p = pos;
    t = p % tt;
    p = (p-t)/tt;
    x = p % tx;
    p = (p-x)/tx;
    y = p % ty;
    z = (p-y)/ty;
  }

  // 
  void AddAcceptedPoint( short x, short y, short z, short t, int pos);

  void AddTrialPoints( short x, short y, short z, short t, int pos);

  // Computation of the new value at (x,y,z)
  unsigned char ComputeValue(FM_TrialPoint_nD_plus& trial, float val, unsigned char dir);

  // Computation of the new value at (x,y,z)
  unsigned char ComputeValueSethian(FM_TrialPoint_nD_plus& trial, float val, unsigned char dir);

  // Take into account the voxel size 
  unsigned char ComputeValueSethian2(FM_TrialPoint_nD_plus& trial, float val, unsigned char dir);

};

#endif


