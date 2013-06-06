
#include "CircleBoundaries3D.h"

#include "amilab_messages.h"

//------------------------------------------------------------------------------
void CircleBoundaries3D::Process( int threadid )
{
  extenttype extent = extents[threadid];
  int x,y,z;
  // make local copy to avoid multithread safety problems
  CalculRepCercle crep = *rep;
  crep.InitCoeff();
  // allow the allocation of a new linearinterpolator: needed for multithreading
  crep.SetGradient(rep->GetGradient());

  InrImage*        out = this->output;
  
  float*           out_ptr;
  Vect3D<double>   v0;
  Vect3D<double>   v1;

  int incx,incy,incz;
  out->GetBufferIncrements(incx,incy,incz);

  float* out_data = (float*) output->GetData();
  
  bool mask_OK;

  for(z=extent.GetMin(2);z<=extent.GetMax(2); z++)
  for(y=extent.GetMin(1);y<=extent.GetMax(1); y++)
  {
    float* out_data1 = out_data + z*incz + y*incy + extent.GetMin(0)*incx;
    for(x=extent.GetMin(0);x<=extent.GetMax(0); x++,out_data1++)
    {
      // check for mask
      mask_OK = (mask!=NULL);
      if (mask_OK) mask_OK = (*mask)(x,y,z)>0.5;
      if (mask_OK) 
      {

        v0.Init(  (*vep0)(x,y,z,0), (*vep0)(x,y,z,1), (*vep0)(x,y,z,2));
        v1.Init(  (*vep1)(x,y,z,0), (*vep1)(x,y,z,1), (*vep1)(x,y,z,2));

        crep.CalculReponses(x,y,z,v0,v1, 1); // last parameter is the elliptic ratio, 1 for circle here
        *out_data1 = crep.Reponse();

      }

    }
  }
  
  
}



//------------------------------------------------------------------------------
void CircleBoundaries3D::Execute(InrImage* res)
{

  if ((vep0==NULL)||(vep1==NULL)||(rep==NULL)) {
    FILE_ERROR("Wrong parameters, returning");
    return;
  }

  
  this->output = res;
  
  if ((output->DimX()!=vep0->DimX())||
      (output->DimY()!=vep0->DimY())||
      (output->DimZ()!=vep0->DimZ())) {
    FILE_ERROR("Wrong image dimensions, returning");
    return;
  }
  
  if (output->GetFormat()!=WT_FLOAT) {
    FILE_ERROR("Wrong output image format, should be WT_FLOAT, returning");
    return;
  }

  output->InitImage(0);

  // need to set an output extent since no input image is given 
  params.SetOutputExtent( ami::ImageExtent<int>(output));

  ImageToImageFilter::Run();

  //return rep->GetGradient();
  
  

  //return out;
}


void CircleBoundaries3D::Execute_old(InrImage* res)
{

  if ((vep0==NULL)||(vep1==NULL)||(rep==NULL)) {
    FILE_ERROR("Wrong parameters, returning");
    return;
  }

  //return rep->GetGradient();
  
  int              x,y,z;
  InrImage*        out;
  Vect3D<double>   v0;
  Vect3D<double>   v1;

  //out = new InrImage(WT_FLOAT,1,"circle_integral.ami.gz",vep0);
  if ((res->DimX()!=vep0->DimX())||(res->DimY()!=vep0->DimY())||(res->DimZ()!=vep0->DimZ())) {
    FILE_ERROR("Wrong image dimensions, returning");
    return;
  }
  
  out = res;
  out->InitImage(0);

  out ->InitBuffer();
  vep0->InitBuffer();
  vep1->InitBuffer();
  mask->InitBuffer();

  // make it parallel?

  Pour( z, 0, out->DimZ() - 1)
  Pour( y, 0, out->DimY() - 1)
  Pour( x, 0, out->DimX() - 1)

    Si mask==NULL Ou mask->ValeurBuffer()>0.5 Alors

      v0.Init( vep0->VectValeurBuffer(0),
          vep0->VectValeurBuffer(1),
          vep0->VectValeurBuffer(2));

      v1.Init( vep1->VectValeurBuffer(0),
          vep1->VectValeurBuffer(1),
          vep1->VectValeurBuffer(2));

      rep->CalculReponses(x,y,z,v0,v1, 1); // last parameter is the elliptic ratio, 1 for circle here
      out->FixeValeur(rep->Reponse());

    FinSi

    out ->IncBuffer();
    vep0->IncBuffer();
    vep1->IncBuffer();
    mask->IncBuffer();

  FinPour
  FinPour
  FinPour
  

  //return out;
}
