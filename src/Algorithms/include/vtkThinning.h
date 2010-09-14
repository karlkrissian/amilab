/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkThinning.h,v $
  Language:  C++
  Date:      $Date: 2004/02/02 20:47:10 $
  Version:   $Revision: 1.1.1.1 $
  Author:    Karl Krissian

=========================================================================*/
// .NAME vtkThinning - short description

#ifndef __vtkThinning_h
#define __vtkThinning_h

// Author Karl Krissian
//
// .SECTION Description
// vtkThinning 
// 3D thinning using simple points
//  
//


#include "vtkImageToImageFilter.h"
#include "vtkImageData.h"

//BTX
#include "vtkImageTemplate.h"
#include "vtkMinHeap.h"

#define unsigned char unsigned char


//----------------------------------------------------------------------
//
class TrialPoint {
//    ----------
public:
  int   x,y,z;
  float value;

  TrialPoint()
  {
    x = y = z = 0;
    value = 1000;
  }

  TrialPoint(int px, int py, int pz, float val)
  {
    x     = px;
    y     = py;
    z     = pz;
    value = val;
  }

  TrialPoint& operator=(const TrialPoint& p)
  {
    x     = p.x;
    y     = p.y;
    z     = p.z;
    value = p.value;
  }


  friend int operator < ( const TrialPoint& p1, const TrialPoint& p2)
  {
    return (p1.value < p2.value);
  }

  friend int operator > ( const TrialPoint& p1, const TrialPoint& p2)
  {
    return (p1.value > p2.value);
  }

  friend ostream& operator << (ostream&, const TrialPoint& p);

}; // TrialPoint
//ETX


//----------------------------------------------------------------------
class VTK_EXPORT vtkThinning : public vtkImageToImageFilter
{
public:
  vtkTypeMacro(vtkThinning,vtkImageToImageFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object to extract all of the input data.
  static vtkThinning *New();

  // Minimum threshold
  vtkSetMacro(min_threshold,float);
  vtkGetMacro(min_threshold,float);

  // Maximum threshold
  vtkSetMacro(max_threshold,float);
  vtkGetMacro(max_threshold,float);

  //
  vtkSetObjectMacro(criterion,vtkImageData);
  vtkGetObjectMacro(criterion,vtkImageData);

  /*
  void ComputeInputUpdateExtent(int inExt[6], 
				int outExt[6]);
  */

  /*
  void ThreadedExecute(vtkImageData *inData, 
		       vtkImageData *outData,
		       int extent[6], int threadId);
  */

protected:

  vtkThinning();
  ~vtkThinning();

  unsigned char IsSimple( vtkImageDataBase* im,
		    int x, int y, int z, int& cc1, int& cc2);

  void Init();

  void Thin_init_pos( );
  
  void init_neighborhoods();

  unsigned char IsEndPoint( vtkImageDataBase* im, int x, int y, int z);

  void ParseCC( int* domain, 
  //   -------
		int neighborhood[27][27], 
		int* cc,
		int point, 
		int num_cc );

  //
  void ExecuteData(vtkDataObject* output);

//BTX
  //
 int N26_star[27][27]; // 26 adjacent neighbors for each point in 
                             // the N26* neighborhood:
                             // N26_star[i][0] = number of neighbors

 int N18[27][27]; // 6 adjacent neighbors for each point in 
                        // the N18 neighborhood:
                        // N18[i][0] = number of neighbors

 int pos[3][3][3];
 int neighbors_pos  [27];
 int neighbors_place[27][3];


 int tx,ty,tz,txy;


  vtkImageDataBase*   input_image; 
  vtkImageDataBase*   output_image; 
  vtkImageData*       criterion;

  float min_threshold;
  float max_threshold;

//ETX
}; // vtkThinning()

#endif // __vtkThinning_h
