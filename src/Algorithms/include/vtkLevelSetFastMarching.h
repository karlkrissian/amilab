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

// .NAME vtkLevelSetFastMarching - short description

// .SECTION Description
// vtkLevelSetFastMarching 
//
//

#ifndef __vtkLevelSetFastMarching_h
#define __vtkLevelSetFastMarching_h

#include <vtkLevelSetsConfigure.h>
#include "vtkPointData.h"
#include "vtkImageData.h"
#include "vtkSimpleImageToImageFilter.h"


//BTX
#include "vtkMinHeap.h"
//ETX

#ifndef vtkFloatingPointType
#define vtkFloatingPointType double
#endif

#include <list>

#define VTK_VAL_ACCEPTED 0
#define VTK_VAL_TRIAL    1
#define VTK_VAL_FAR      2

#define VTK_MODE_2D 2
#define VTK_MODE_3D 3


//BTX
class FM_TrialPoint;

class target_point {
public:
  int x;
  int y;
  int z;
  
  target_point(int _x,int _y, int _z) 
  {
    x=_x;
    y=_y;
    z=_z;
  }
};

void UpdateMinHeapPos(unsigned int image_pos, int pos, void* data);

//----------------------------------------------------------------------
//
class VTK_LEVELSETS_EXPORT FM_TrialPoint {

public:
  short   x,y,z;
  int     impos;
  int     track;
  // minimal value for the neighbor in each direction:
  // 0,1,2 for X,Y,Z
  float   valmin[3];
  float   value;

  // Class at which the point belongs (optional)
  unsigned short _class; 

  FM_TrialPoint()
  {
    x = y = z = impos = 0;
    value = 
    valmin[0] = 
    valmin[1] =
    valmin[2] = 1E5;
    track = -1;
    _class = 0;
  }

  FM_TrialPoint(int px, int py, int pz, int im_pos, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    impos = im_pos;
    value = val;
    valmin[0] = 
    valmin[1] =
    valmin[2] = 1E5;
    track = -1;
    _class = 0;
  }


  FM_TrialPoint& operator=(const FM_TrialPoint& p)
  {
    x     = p.x;
    y     = p.y;
    z     = p.z;
    impos = p.impos;
    value = p.value;
    valmin[0] = p.valmin[0];
    valmin[1] = p.valmin[1];
    valmin[2] = p.valmin[2];
    track = p.track;
    _class = p._class;
    return *this;
  }


  void Init(int px, int py, int pz, int im_pos, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    impos = im_pos;
    value = val;
    valmin[0] = 
    valmin[1] =
    valmin[2] = 1E5;
  }


  void SetValue(float val) { value=val; }
  void SetClass(const unsigned short& c) { _class=c; }
  void SetTrack(int t)     { track = t; }


  friend inline int operator < ( const FM_TrialPoint& p1, const FM_TrialPoint& p2)
  {
    return (p1.value < p2.value);
  }

  friend inline int operator > ( const FM_TrialPoint& p1, const FM_TrialPoint& p2)
  {
    return (p1.value > p2.value);
  }

  friend std::ostream& operator << (std::ostream&, const FM_TrialPoint& p);

}; // FM_TrialPoint


//ETX

//----------------------------------------------------------------------
class VTK_EXPORT vtkLevelSetFastMarching : public vtkSimpleImageToImageFilter
{
public:
  vtkTypeMacro(vtkLevelSetFastMarching, vtkSimpleImageToImageFilter);
  void PrintSelf(std::ostream& os, vtkIndent indent);

  // Description:
  // Construct object to extract all of the input data.
  static vtkLevelSetFastMarching *New();

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
  vtkSetMacro(cx,int);
  vtkGetMacro(cx,int);

  //
  vtkSetMacro(cy,int);
  vtkGetMacro(cy,int);

  //
  vtkSetMacro(cz,int);
  vtkGetMacro(cz,int);

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
  vtkSetObjectMacro(trajectory_distance,vtkImageData);
  vtkGetObjectMacro(trajectory_distance,vtkImageData);

  //
  vtkSetObjectMacro(trajectory_cost,vtkImageData);
  vtkGetObjectMacro(trajectory_cost,vtkImageData);

  //
  vtkSetObjectMacro(class_image,vtkImageData);
  vtkGetObjectMacro(class_image,vtkImageData);

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
  void Init( int cx, int cy, int cz, int radius);

  void UseOutputArray(float* array) { output_array = array; }

  void SetNarrowBand( int* band, int size);

  //
  void SetGaussianForce( float mean, float sd)
    {
      UseGaussianForce=1;
      IntensityMean=mean;
      IntensityStandardDeviation=sd;
    }

  void AddTargetPoint( int x, int y, int z) 
  {
    target_points.push_back(target_point(x,y,z));
  } 

protected:
  vtkLevelSetFastMarching();
  ~vtkLevelSetFastMarching();

  vtkLevelSetFastMarching(const vtkLevelSetFastMarching&);
  void operator=(const vtkLevelSetFastMarching&);

  virtual void SimpleExecute(vtkImageData* input, vtkImageData* output);
  void InitParam(vtkImageData* input, vtkImageData* output);

//BTX
  // 2D or 3D processing
  int dim;

  // image size
  int tx,ty,tz,txy,imsize;

  // voxel size
  vtkFloatingPointType vs[3];

  // inverse of the squared voxel size
  vtkFloatingPointType ivs2[3];

  // center of the initial sphere
  int cx,cy,cz;

  // radius of the initial sphere
  float radius;

  // MinHeap binary tree object
  vtkMinHeap<FM_TrialPoint> mh;

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

  vtkImageData* trajectory_distance;
  vtkImageData* trajectory_cost;

  // Class image to partition the result based on the initial points
  vtkImageData* class_image;
  short* Class_buf;  

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

  // Narrow Band Information
  int*           narrowband;
  int            bandsize;  

  // Gaussian Intensity Based Force
  int         UseGaussianForce;
  float       IntensityMean;
  float       IntensityStandardDeviation;

  // Evolve until a set of points are reached
  std::list<target_point> target_points;

//ETX

  // Initialization of the time image
  //  void Init( int cx, int cy, int cz, int radius);
  void Init2D( int cx, int cy, int radius);
  void Init3D( int cx, int cy, int cz, int radius);

  //
  void InitWithImage();

  // 
  void InitIsoSurf();

  // 
  void AddAcceptedPoint( short x, short y, short z, int pos);

  // Only used when initializing with a distance map
  void AddTrialPointsOld( short x, short y, short z, int pos);
  void AddTrialPoints( short x, short y, short z, int pos);

  // Computation of the new value at (x,y,z)
  float ComputeValueDijkstra(FM_TrialPoint& trial);

  // Computation of the new value at (x,y,z)
  unsigned char ComputeValue(FM_TrialPoint& trial, float val, unsigned char dir);

  // Computation of the new value at (x,y,z)
  unsigned char ComputeValueSethian(FM_TrialPoint& trial, float val, unsigned char dir);

  // Take into account the voxel size 
  unsigned char ComputeValueSethian2(FM_TrialPoint& trial, float val, unsigned char dir);

};

#endif


