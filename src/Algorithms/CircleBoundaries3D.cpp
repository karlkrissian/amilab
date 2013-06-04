
#include "CircleBoundaries3D.h"

#include "amilab_messages.h"

void CircleBoundaries3D::Execute(InrImage* res)
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
