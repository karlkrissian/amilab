
#include "VectorImage2StructuredGrid.h"

#ifndef _WITHOUT_VTK_

#include "vtkFloatArray.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkStructuredGrid.h"
#include "vtkStructuredGridWriter.h"

#endif // WITHOUT_VTK_


void Func_VectorImage2StructuredGrid(InrImage* im, char* name)
{

#ifndef _WITHOUT_VTK_
  int i, j, k, offset;
  float x[3], v[3];

  if (im->GetVDim()!=3) return;  

  // Create the structured grid.
  vtkStructuredGrid *sgrid = vtkStructuredGrid::New();
  sgrid->SetDimensions(im->DimX(),im->DimY(),im->DimZ());

  // We also create the points and vectors. 
  vtkFloatArray *vectors = vtkFloatArray::New();
  vectors->SetNumberOfComponents(3);
  vectors->SetNumberOfTuples(im->Size());
  vtkPoints *points = vtkPoints::New();
  points->Allocate(im->Size());
  
  im->InitBuffer();
  offset=0;
  for ( k=0; k<im->DimZ(); k++) {
    for (j=0; j<im->DimY(); j++)  {
      for (i=0; i<im->DimX(); i++) 
        {
	  x[0] = i*im->VoxSizeX();
	  x[1] = j*im->VoxSizeY();
	  x[2] = k*im->VoxSizeZ();
	  v[0] = im->VectValeurBuffer(0);
	  v[1] = im->VectValeurBuffer(1);
	  v[2] = im->VectValeurBuffer(2);
	  points->InsertPoint(offset,x);
	  vectors->InsertTuple(offset,v);
	  im->IncBuffer();
	  offset++;
        }
      }
    }
  sgrid->SetPoints(points);
  points->Delete();
  sgrid->GetPointData()->SetVectors(vectors);
  vectors->Delete();

  // We save the result
  vtkStructuredGridWriter* w = vtkStructuredGridWriter::New();

  w->SetInputData(sgrid);
  w->SetFileName(name);
  w->Write();
#else
  fprintf(stderr,"Func_VectorImage2StructuredGrid()\t this function needs VTK and it is not available ...\n");
#endif // WITHOUT_VTK_
}
