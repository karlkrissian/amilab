 /*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkConvexHull.cxx,v $
  Language:  C++
  Date:      $Date: 2004/02/02 20:47:10 $
  Version:   $Revision: 1.1.1.1 $

=========================================================================*/

#include "vtkConvexHull.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkConvexHull,"$Revision: 1.0$")

//----------------------------------------------------------------------
ProjectionLine::ProjectionLine(int min,int max)
{
  int i;
  
  minimum=min;
  maximum=max;
  size=maximum-minimum+1;
  line=new lineType[size];
  for (i=0;i<size;i++) {
    line[i].position=i;
    line[i].values=vtkFloatArray::New();
  }
}


//----------------------------------------------------------------------
ProjectionLine::~ProjectionLine()
{
  int i;
  
  for (i=0;i<size;i++) {
    line[i].values->Delete();
  }
  
  delete [] line;
}

//----------------------------------------------------------------------
void ProjectionLine::AddValue(float position, int index, float value)
{
  int pos;
  
  pos=(int)floor(position)-minimum;

  if (pos<0)      pos=0;
  if (pos>size-1) pos=size-1;

  line[pos].position=pos;
  line[pos].values->InsertNextTuple1(index);
  line[pos].values->InsertNextTuple1(value);

}


//----------------------------------------------------------------------
void ProjectionLine::GetValues(int position,vtkFloatArray** values)
{
  if ((position >= minimum) && (position <= maximum)) {
    *values=line[position-minimum].values;
  } else {
    fprintf(stderr,"GetValues: Requested position %d is out of range - dimension of the line is (%d,%d)\n",position,minimum,maximum);
  }
}


//-----------------------------------------------------------------------
//
//
vtkConvexHull* vtkConvexHull::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkConvexHull");
  if(ret)
    {
		return (vtkConvexHull*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkConvexHull;

} // vtkConvexHull::New()


//----------------------------------------------------------------------
// Construct object
//
vtkConvexHull::vtkConvexHull()
{

  Order = 0;
  Angles = 0;
  Resolution = 0.01;
  Slopes = vtkFloatArray::New();
  Slopes->SetNumberOfComponents(3);
} // vtkConvexHull::vtkConvexHull()


//----------------------------------------------------------------------
// Destruct object
//
vtkConvexHull::~vtkConvexHull()
{
	Slopes->Delete();
} // vtkConvexHull::~vtkConvexHull()


//----------------------------------------------------------------------
// Calculate the greatest common divisor of a and b
//
int GCD(int a,int b)
{
  int remainder;
  
  do {
    remainder=a%b;
    a=b;
    b=remainder;
  } while (remainder!=0);
  return(a);
} // GCD


//----------------------------------------------------------------------
// Calculates the slopes of the projection lines
//
void vtkConvexHull::InitializeDirections(int dim)
{
  int   i,j;
  float x,y;
  float alpha,beta;
  float norm;
  

  printf("Init dir \n");

  //don't do anything if we are working with angles
  if (Angles==0) {
 
    if (dim!=2)
      fprintf(stderr,"directions using order are only available in 2D!\n"); 

    // reinitialize the array to delete old values
    Slopes->Delete();
    Slopes=vtkFloatArray::New();
    Slopes->SetNumberOfComponents(3);
    
    // insert slopes for CH0
    Slopes->InsertNextTuple3(0,1,0);
    Slopes->InsertNextTuple3(0,-1,0);
    Slopes->InsertNextTuple3(1,0,0);
    Slopes->InsertNextTuple3(-1,0,0);
    
    // insert slopes for CHn (n>0)
    if (Order > 0) {
      for (i=1;i<=Order;i++) {
	for (j=i;j<=Order;j++) {
	  if (GCD(i,j)==1) {
	    norm=sqrt((float) (i*i+j*j));
	    x=i/norm;
	    y=j/norm;
	    Slopes->InsertNextTuple3(y,x,0);
	    Slopes->InsertNextTuple3(y,-x,0);
	    Slopes->InsertNextTuple3(-y,x,0);
	    Slopes->InsertNextTuple3(-y,-x,0);
	    if (j>i) {
	      Slopes->InsertNextTuple3(x,y,0);
	      Slopes->InsertNextTuple3(x,-y,0);
	      Slopes->InsertNextTuple3(-x,y,0);
	      Slopes->InsertNextTuple3(-x,-y,0);
	    }
	  }
	}
      }
    }

  } else {

    switch (dim) {
    case 2:
      // compute hull with angles
      for (i=0;i<Angles;i++) {
	alpha=1.0*i/Angles*(2*3.141592654);
	Slopes->InsertNextTuple3(cos(alpha),sin(alpha),0);
      }
      break;
    case 3:
      float ca,sa,cb,sb;

      // compute hull with angles
      for (i=0;i<Angles;i++) {
	alpha=1.0*i/Angles*(2*3.141592654);
	ca = cos(alpha);
	sa = sin(alpha);
	for (j=0;j<Angles;j++) {
	  beta =1.0*j/Angles*(2*3.141592654);
	  cb=cos(beta);
	  sb=sin(beta);
	  Slopes->InsertNextTuple3(ca*cb,sa*cb,sb);
	}
      }
      break;
    default:
      fprintf(stderr,"Angle directions not available for dimension %d \n",dim);
    }

  }

  printf("Init end \n");

} // vtkConvexHull::InitializeDirections()


//----------------------------------------------------------------------
// Project the vector (px,py,pz) onto the normalized vector (dx,dy)
//
float vtkConvexHull::ProjectSlope(int px, int py, int pz, float slope[3])
{

  float projection;
  projection=px*slope[0]+py*slope[1]+pz*slope[2];
  return(projection);

} // vtkConvexHull::ProjectSlope()


//----------------------------------------------------------------------
//
//
void vtkConvexHull::GetLineExtent(float& minLine, float& maxLine, float slope[3], 
				  int dims[3], float Resolution)
//
{

  int x,y,z;
  float proj;
  int xmin,xmax,xstep;
  int ymin,ymax,ystep;
  int zmin,zmax,zstep;

  proj=ProjectSlope(0,0,0,slope);
  maxLine=minLine=proj;

  xmin=ymin=zmin=0;
  xmax=dims[0]-1;
  ymax=dims[1]-1;
  zmax=dims[2]-1;

  xstep=__max(1,xmax);
  ystep=__max(1,ymax);
  // if dims[2]==1, avoid getting stuck ...
  zstep=__max(1,zmax);

  for(x=xmin; x<=xmax; x+=xstep)
  for(y=ymin; y<=ymax; y+=ystep)
  for(z=zmin; z<=zmax; z+=zstep)
    {
      // compute the extent of the line by projecting the corners of the image
      proj=ProjectSlope(x,y,z,slope);
      maxLine=__max(maxLine,proj);
      minLine=__min(minLine,proj);
    }

  maxLine /= Resolution;
  minLine /= Resolution;
}


//----------------------------------------------------------------------
//
//
void vtkConvexHull::ExecuteData(vtkDataObject *output)
{
  ProjectionLine* line;
  int             dims[3];
  float           maxLine,minLine;
  int             i,j,k;
//  int             x,y,z;
  float           pos;
  int             index;
  float           maxValue;
//  int             prevValue;
  vtkFloatArray*  lineValues=NULL;
  float           value;
  float*          inputPtr;
  float*          outputPtr;
  float           Slope[3];
  float           projectionI;
  int             counter;
  
  if (this->GetInput()==NULL)
    vtkErrorMacro("No input!");
  
  fprintf(stderr,"vtkConvexHull execution...\n");
  
  // Create float input image
  InputImage=vtkImageData::New();
  InputImage->SetScalarType( VTK_FLOAT);
  InputImage->SetNumberOfScalarComponents(1);
  InputImage->SetDimensions( this->GetInput()->GetDimensions());
  InputImage->SetOrigin(     this->GetInput()->GetOrigin());
  InputImage->SetSpacing(    this->GetInput()->GetSpacing());
  InputImage->CopyAndCastFrom(this->GetInput(),
			      this->GetInput()->GetExtent());

  
  OutputImage=this->GetOutput();
  OutputImage->SetScalarType(VTK_FLOAT);
  OutputImage->SetNumberOfScalarComponents(1);
  OutputImage->SetDimensions(InputImage->GetDimensions());
  OutputImage->SetOrigin(InputImage->GetOrigin());
  OutputImage->SetSpacing(InputImage->GetSpacing());
  OutputImage->AllocateScalars();
  
  
  
  InputImage->GetDimensions(dims);
  
  if (dims[2]>1)
    InitializeDirections(3);
  else
    InitializeDirections(2);

  for (counter=0;counter<Slopes->GetNumberOfTuples();counter++) {
    
    Slope[0]=Slopes->GetTuple(counter)[0];
    Slope[1]=Slopes->GetTuple(counter)[1];
    Slope[2]=Slopes->GetTuple(counter)[2];
    
    fprintf(stderr,"Computing slope {%0.2f, %0.2f, %0.2f}\n",Slope[0],Slope[1],Slope[2]);
    
    // compute the extent of the line by projecting the corners of the image
    GetLineExtent(minLine,maxLine, Slope, dims, Resolution);

    printf("minline maxline = %f %f\n", minLine, maxLine);
    
    // create the line
    line=new ProjectionLine((int)floor(minLine),(int)ceil(maxLine));
    
    // projection of the vector (1,0,0)
    projectionI=Slope[0]/Resolution;
    // project all pixels of the image to the line
    inputPtr=(float*)InputImage->GetScalarPointer(0,0,0);
    
    index=0;
    for (k=0;k<dims[2];k++) {
      for (j=0;j<dims[1];j++) {
	// projection of (0,j,k) 
	pos=(j*Slope[1]+k*Slope[2])/Resolution;
	for (i=0;i<dims[0];i++) {
	  pos += projectionI;
	  line->AddValue(pos,index,*inputPtr);
	  inputPtr++;
	  index++;
	}
      }
    }
    
    printf("projected \n");

    // re-read the line (sorted by projection values)
    // and generate the output image
    maxValue=0;
    for (i=(int)floor(minLine);i<ceil(maxLine);i++) {

      line->GetValues(i,&lineValues);
      if (lineValues==NULL) {
	fprintf(stderr,"Pointer value is NULL!\n");
	continue;
      }

      outputPtr=(float*)OutputImage->GetScalarPointer(0,0,0);

      j=0;
      while (j<lineValues->GetNumberOfTuples()) {
	index=(int)lineValues->GetValue(j++);
	value=lineValues->GetValue(j++);
	if (value > maxValue)  maxValue=value;

	//are we in the first iteration?
	if (counter==0) 
	  outputPtr[index]=maxValue;
        else 
	  if (maxValue <= outputPtr[index]) outputPtr[index]=maxValue;
      }
    }
    delete line;
  }
	
} // vtkConvexHull::ExecuteData()


//----------------------------------------------------------------------
//
//
void vtkConvexHull::PrintSelf(ostream& os, vtkIndent indent)
{
  // Nothing here yet
} // vtkConvexHull::PrintSelf()
