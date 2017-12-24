/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkConvexHull.h,v $
  Language:  C++
  Date:      $Date: 2004/02/02 20:47:10 $
  Version:   $Revision: 1.1.1.1 $
  Author:    Arne Hans

=========================================================================*/
// .NAME vtkConvexHull - computes the convex hull

#ifndef __vtkConvexHull_h
#define __vtkConvexHull_h

// Author: Arne Hans
//
// .SECTION Description
// vtkConvexHull 
// 
//  
//

//#include "vtkmyUnsortedWin32Header.h"

#include <vtkConvexHullConfigure.h>
#include <vtkLevelSetsConfigure.h>

#include "vtkImageAlgorithm.h"
#include "vtkImageData.h"
#include "vtkFloatArray.h"

#define Boolean unsigned char

#define __max(a,b) (((a) > (b)) ? (a) : (b))
#define __min(a,b) (((a) < (b)) ? (a) : (b))

//BTX
class ProjectionLine
{
public:
	ProjectionLine(int min,int max);
	~ProjectionLine();
	void AddValue(float position,int index,float value);
	void GetValues(int position,vtkFloatArray** values);

protected:
	typedef struct {
		int position;
		vtkFloatArray* values;
	} lineType;

	lineType* line;
	int minimum,maximum;
	int size;
};

//ETX


//----------------------------------------------------------------------
class VTK_LEVELSETS_EXPORT vtkConvexHull : public vtkImageAlgorithm
{
public:
  vtkTypeMacro(vtkConvexHull,vtkImageAlgorithm);
  //vtkTypeMacro(vtkConvexHull,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct object to extract all of the input data.
  static vtkConvexHull *New();
  
  // Order of the convex hull
  vtkSetMacro(Order,int);
  vtkGetMacro(Order,int);
  
  // Number of angles
  vtkSetMacro(Angles,int);
  vtkGetMacro(Angles,int);

  // Resolution
  vtkSetMacro(Resolution,float);
  vtkGetMacro(Resolution,float);

  // Output image
  //vtkSetObjectMacro(OutputImage,vtkImageData);
  //vtkGetObjectMacro(OutputImage,vtkImageData);

  void Update() {ExecuteData(this->GetOutput());};

protected:

  vtkConvexHull();
  ~vtkConvexHull();

  void  InitializeDirections(int dim);
  float ProjectSlope( int px,int py,int pz,float slope[3]);
  void  GetLineExtent(float& minline, float& maxline, float slope[3], 
		      int dims[3], float Resolution);

  void ExecuteData(vtkDataObject *);
  void Execute() { this->vtkImageAlgorithm::Execute(); };


//BTX
  //

  vtkImageData* InputImage; 
  vtkImageData* ProjectionImage;
  vtkImageData* OutputImage;
  
  vtkFloatArray* Slopes;

  int   Order;
  int   Angles;
  float Resolution;

//ETX
}; // vtkConvexHull()

#endif // __vtkConvexHull_h
