/*  ==================================================
    Module : vtkLevelSets
    Authors: Karl Krissian (from initial code by Liana Lorigo and Renaud Keriven)
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

#include "AMILabConfig.h"

#include "vtkLevelSets.h"
#include "vtkObjectFactory.h"
#include "vtkStructuredPointsWriter.h"
#include "vtkFloatArray.h"

#include "vtkPointData.h"
#include "vtkImageData.h"
//#include "vtkImageIsoContourDist.h"
//#include "vtkImageFastSignedChamfer.h"
#include "vtkMultiThreader.h"

#ifdef HAVE_MALLOC_H
  #include <malloc.h>
#else
  #include <stdlib.h>
#endif


#ifdef _WIN32
#include <string.h>
#else
#include <strings.h>
#endif

#define NOT_VESSEL 2  // can be anything positive
#define VESSEL    -1   // anything negative

// Some method's defines
#define INBAND    (1<<0)
#define NEGMINE   (1<<1)
#define POSMINE   (1<<2)
#define TIMEMINE  (1<<3)
#define TUBEFRONT (1<<5)
#define INTUBE    (1<<6)

#define NOTSET 1000
// used in convergence check
// if changing, remember that these are uchars

#define ON_STORED 0
#define OFF_STORED 1
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

#define GB_debug 0

#define EPSILON 1E-5

/* ONLY ON SOLARIS MACHINES */
#ifdef _SOLARIS_
/* Must be a Sun machine */
#include <thread.h>
#endif

#define ADDMEMORY(text,size) \
  MemoryAllocated += (size)/1000000.0; \
  if (verbose) \
    fprintf(stderr,"%s : %4.2f Mb,  total %4.2f Mb \n", \
        text,(size)/1000000.0,MemoryAllocated);


vtkCxxSetObjectMacro( vtkLevelSets,
                      SkeletonImage,
                      vtkImageData);

vtkCxxSetObjectMacro( vtkLevelSets,
                      initImage,
                      vtkImageData);

//vtkCxxRevisionMacro(vtkLevelSets,"$Revision: 1.0$")

#ifndef vtkFloatingPointType
#define vtkFloatingPointType double
#endif


//
//------------------------------------------------------------------------------
vtkLevelSets* vtkLevelSets::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkLevelSets");
  if(ret)
    {
    return (vtkLevelSets*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkLevelSets;
}


//----------------------------------------------------------------------------
// Constructor sets default values
vtkLevelSets::vtkLevelSets()
{
  verbose = 0;

  imsize         = 0;
  AdvectionCoeff = 1;
  NumIters       = 10;
  ReinitFreq     = 3;
  CheckFreq      = 20;
  init_dt        = .2;
  StepDt         = .1;
  ShapeMinDist   = -20;
  Band           = 4;
  Tube           = 2;
  
  SquaredGradientEpsilon = 1E-8;

  // rescaling to [0,255] parameters
  RescaleImage   = 1;
  minu           = 0;
  maxu           = 100;

  UseLowThreshold  = 0;
  UseHighThreshold = 0;
  LowThreshold     = 0;
  HighThreshold    = 0;

  ProbabilityHighThreshold = 0;

  /*
  xspacinginv = 1/.9375;
  yspacinginv = 1/.9375;
  zspacinginv = 1/1.5
  */

  ConvergedThresh = .02;
  DoMean          = 1;
  AffineCurvature = 0;

  inputImage           = NULL;
  inputImage_allocated = 0;
  stored_seg           = NULL;
  stored_seg_allocated = 0;

  distmap_count    = 0;
  band_count       = 0;
  DMmethod         = 1;
  savedistmap      = 0;
  savesecdergrad   = 0;
  advection_scheme = ADVECTION_UPWIND_VECTORS;

  balloon_scheme = BALLOON_BROCKETT_MARAGOS;
  //  balloon_scheme = BALLOON_VESSELS;

  fm      = vtk_new<vtkLevelSetFastMarching>   ()();
  isodist = vtk_new<vtkImageIsoContourDist>    ()();
  chamfer = vtk_new<vtkImageFastSignedChamfer> ()();
  shape   = vtk_new<vtkImagePropagateDist2>    ()();

  velocity             = NULL;
  coeff_velocity       = 1E-2;
  velocity_type        = 1; // multiplicative

  // Initialization of the balloon force
  balloon_coeff        = 0;
  balloon_image        = NULL;
  NumGaussians         = 0;
  Gaussians            = NULL;
  Probability          = NULL;
  ProbabilityThreshold = 0.3;

  // Skeleton for shape-based levelset
  SkeletonImage           = NULL;
  SkeletonImage_allocated = 0;

  // Initialization of the level set
  initImage       = NULL;
  InitThreshold   = 30.0;
  InitIntensity   = Bright;

  NumInitPoints   = 0;
  InitPoints      = NULL;

  coeff_curvature    = 1;
  HistoGradThreshold = 0.8;

  curvature_data = NULL;
  advection_data = NULL;
  velocity_data  = NULL;
  balloon_data   = NULL;
  distance_data  = NULL;

  curvature_weight = NULL;

  data_attach_x.clear();
  data_attach_y.clear();
  data_attach_z.clear();

  secdergrad = NULL;
  normgrad   = NULL;

  UseCosTerm    = 0;
  IsoContourBin = 0;

  Dimension = 3;
  SliceNum  = 0;

  isotropic_voxels = 0;

  EvolveThreads = 0;

  MemoryAllocated = 0;

} // vtkLevelSets()


//---------------------------------------------------------------------------
// Destructor
vtkLevelSets::~vtkLevelSets()
//              ---------------
{
  // unreference objects
  Setvelocity       (NULL);
  Setballoon_image  (NULL);
  SetinitImage      (NULL);

  int i;

  if (inputImage_allocated) {
    inputImage->Delete();
    inputImage=NULL;
  }

  if (SkeletonImage_allocated) {
    SkeletonImage->Delete();
  }
  SetSkeletonImage  (NULL);

  if (stored_seg_allocated) {
    delete [] stored_seg;
    stored_seg_allocated = 0;
  }

  if (NumGaussians>0) {
    for(i=0;i<NumGaussians;i++) {
      delete [] Gaussians[i];
    }
    delete [] Gaussians;
    NumGaussians = 0;
  }

} // ~vtkLevelSets()


//---------------------------------------------------------------------------
void vtkLevelSets::SetNumInitPoints( int n)
//
{
  int i;

  if ((n>0)&&(n<100)) {
    NumInitPoints=n;

    InitPoints = new int*[NumInitPoints];
    for(i=0;i<NumInitPoints;i++) {
      InitPoints[i] = new int[4];
      InitPoints[i][0] =
      InitPoints[i][1] =
      InitPoints[i][2] =
      InitPoints[i][3] = 0;
    }
  }
  else {
    fprintf(stderr,"number of initialization points must be in [1,99]\n");
    NumInitPoints=0;
  }

} // SetNumInitPoints()


//---------------------------------------------------------------------------
void vtkLevelSets::SetInitPoint( int num, int x, int y, int z, int radius)
//
{
  if ((num>=0)&&(num<NumInitPoints)) {
    InitPoints[num][0] = x;
    InitPoints[num][1] = y;
    InitPoints[num][2] = z;
    InitPoints[num][3] = radius;
  }
}


//---------------------------------------------------------------------------
void vtkLevelSets::SetNumGaussians( int n)
//
{
  int i;

  if ((n>0)&&(n<10)) {
    NumGaussians=n;

    Gaussians = new float*[NumGaussians];
    for(i=0;i<NumGaussians;i++) {
      Gaussians[i] = new float[2];
      Gaussians[i][0] =
      Gaussians[i][1] = 0;
    }
  }
  else {
    fprintf(stderr,"number of initialization points must be in [1,99]\n");
    NumGaussians=0;
  }

} // SetNumGaussians()


//---------------------------------------------------------------------------
void vtkLevelSets::SetGaussian( int num, float mean, float sd)
//
{

  if ((num>=0)&&(num<NumGaussians)) {
    Gaussians[num][0] = mean;
    Gaussians[num][1] = sd;
  }

} // SetGaussian()


//---------------------------------------------------------------------------
void vtkLevelSets::DistanceMap()
//                   -----------
{
  VTK_CLASS_MESSAGE("Begin");

  // Save the input
  if (savedistmap)
  {
    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
    vtkImageData* copyImage = vtkImageData::New();
    float* ptr;
    char name[255];
    vector_size  i;

    vtkImageData::SetScalarType( VTK_FLOAT, copyImage->GetInformation());
    vtkImageData::SetNumberOfScalarComponents(1, copyImage->GetInformation());
    copyImage->SetDimensions( outputImage->GetDimensions());
    copyImage->SetOrigin(     outputImage->GetOrigin());
    copyImage->SetSpacing(    outputImage->GetSpacing());

    copyImage->AllocateScalars(copyImage->GetInformation());
    //     copyImage->CopyAndCastFrom(outputImage,
    //                outputImage->GetExtent());

    ptr = (float*) copyImage->GetScalarPointer();
    for(i=0;i<imsize;i++) {
      *ptr = u[this->current][i];
      ptr++;
    }

    writer->SetInputData(copyImage);
    distmap_count++;
    sprintf(name,"distmap_input%d.vtk",distmap_count);
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
    writer->Write();
    copyImage->Delete();
  }


   std::cout << "DistanceMap() 1.1" << std::endl;

  switch (DMmethod) {
    case DISTMAP_CURVES      : DistanceMapCurves();    break;
    case DISTMAP_FASTMARCHING: DistanceMapFM();    break;
    case DISTMAP_CHAMFER     : DistanceMapChamfer();    break;
    case DISTMAP_SHAPE       : DistanceMapShape();    break;
  }

   std::cout << "DistanceMap() 1.2" << std::endl;

  // swap the images
  this->current=1-this->current;


  if (distance_data!=NULL) {
    vector_size  i;
    for(i=0;i<imsize;i++) {
      distance_data[i] = u[this->current][i];
    }
  }

  // Save the result
  if (savedistmap)
  {
    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
    vtkImageData*   copyImage = vtkImageData::New();
    float*    ptr;
    char            name[255];
    vector_size  i;

    vtkImageData::SetScalarType( VTK_FLOAT, copyImage->GetInformation());
    vtkImageData::SetNumberOfScalarComponents(1, copyImage->GetInformation());
    copyImage->SetDimensions( outputImage->GetDimensions());
    copyImage->SetOrigin(     outputImage->GetOrigin());
    copyImage->SetSpacing(    outputImage->GetSpacing());

    copyImage->AllocateScalars(copyImage->GetInformation());
    //     copyImage->CopyAndCastFrom(outputImage,
    //                outputImage->GetExtent());

    ptr = (float*) copyImage->GetScalarPointer();
    for(i=0;i<imsize;i++) {
      *ptr = u[this->current][i];
      ptr++;
    }

    writer->SetInputData(copyImage);
    distmap_count++;
    sprintf(name,"distmap%d.vtk",distmap_count);
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
     writer->Write();
    copyImage->Delete();
  }

  VTK_CLASS_MESSAGE("End");

} // DistanceMap()


//----------------------------------------------------------------------------
// Method to estimate the distance's map
//
// Input Parameters:
//
//   current
//   u[current]   : input image
//   inputImage   : for getting the voxel size
//   Band         : size of the band
//   flag         : INTUBE
//
// Outputs:
//
//   u[1-current]
//
//
void vtkLevelSets::DistanceMapCurves()
//                   ------------
{
    float_vec_it U    = u[this->current  ].begin();
    float_vec_it newU = u[1-this->current].begin();

    float           u0,upx,upy,upz,umx,umy,umz;
    float           Dpx,Dmx, Dpy,Dmy, Dpz=0,Dmz=0, deltap=0,deltam=0;
    vector_size  loop;
    vector_size  bpc,bpc0;
    vector_size  n,b;
    int             seen;
    int             p = 0;
    int             i1,j1,k1,ts;
    short           i,j,k;
    int             p1,maxt;
    int             s, sgn_pc;
    float           *times[2],*t,*newt=NULL;
    vtkFloatingPointType voxel[3];
    int             mx,px,my,py,mz,pz;
    int             tcurrent;

   if (GB_debug) fprintf(stderr, "DistanceMapCurves() begin \n");

   this->inputImage->GetSpacing(voxel);
   float xspacing = 1.0 / voxel[0];
   float yspacing = 1.0 / voxel[1];
   float zspacing = 1.0 / voxel[2];
   //
   //

   unsigned char *myflag= new unsigned char [imsize];
   int           *myBand= new int[imsize];

   times[0]= new float [imsize];
   times[1]= new float [imsize];

   for(loop=0;loop < imsize; loop++) {
     if (U[loop]>0) {
       newU[loop]=this->Band+1;
     }
     else if (U[loop]<0) {
       newU[loop]=-(this->Band)-1;
     } else {
       newU[loop]=0;
     }
   }
   //

   // Evolution on both sides of the surface: s=1 and s=-1
   for (s=1;s>=-1;s-=2) {

     bpc = 0;
     memset(myflag,0,sizeof(unsigned char)*imsize);

     for(loop=0;loop<this->bnd.size();loop++) {

       p = this->bnd[loop];

       if (this->flag[p]&INTUBE) {
         myBand[bpc] = bnd[loop];
         myflag[p]   = INBAND;
         bpc++;
       }

     }

     // bpc = number of point in the Tube
     bpc0   = bpc;
     sgn_pc = 0;

     // Add the points to myBand and a 4x4x4 neighborhood around TUBEFRONT
     for (loop=0;loop < bpc0;loop++) {

       if ((GB_debug)&&(bpc0>100)&&(loop%(bpc0/10)==0))
        fprintf(stderr," loop %2.2f %% \n",(100.0*loop)/bpc0);

       p  = myBand[loop];
       u0 = U[p];

       // si l'evolution en cours passera par le  point considere de myBand
       if ((s<0 && u0<0) || (s>0 && u0>0)) {

         myflag[p]|=TIMEMINE; //on leve le drapeau TIMEMINE
         sgn_pc++;

         // si ce point est de plus au bord du tube
         if (this->flag[p]&TUBEFRONT) {

           ExtractCoords(p,i,j,k);

       // 4x4x4 neighborhood
           for (i1=i-4;i1<i+4;i1++)
             if (i1>=0 && i1<this->tx)
             for (j1=j-4;j1<j+4;j1++)
           if (j1>=0 && j1<this->ty)
         {
           switch (Dimension) {
           case 2:
             p1 = i1+j1*tx;
             // on teste ces voisins et on les adjoint a myBand
             // lorsqu'il ne sont pas encore dans la Bande
             if (!(myflag[p1]&INBAND)) {
               myflag[p1]=INBAND;
               if ((s<0 && U[p1]<0) || (s>0 && U[p1]>0)) {
             myflag[p1]|=TIMEMINE; // idem
             sgn_pc++;
               }
               myBand[bpc]=p1;
               bpc++;
             }
             break;
           case 3:
             k1 = k-4;
             p1 = i1+j1*tx+k1*txy;
             for (k1=k-4;k1<k+4;k1++,p1+=txy)
               if (k1>=0 && k1<this->tz)
             // on teste ces voisins et on les adjoint a myBand
             // lorsqu'il ne sont pas encore dans la Bande
             if (!(myflag[p1]&INBAND)) {
               myflag[p1]=INBAND;
               if ((s<0 && U[p1]<0) || (s>0 && U[p1]>0)) {
                 myflag[p1]|=TIMEMINE; // idem
                 sgn_pc++;
               }
               myBand[bpc]=p1;
               bpc++;
             }
             break;
           } // end switch
         } // end if
     }
       } // end if

     } // end for loop

     // Copy the time
     for(n=0;n<imsize;n++) {
       times[0][n] = u[0][n];
       times[1][n] = u[1][n];
     }

     // number of iterations :  Band/dt
     maxt=(int)(((float)Band)/init_dt+1);

     for (tcurrent=ts=seen=0;ts<=maxt && seen<sgn_pc;ts++) {

       if (GB_debug)
     fprintf(stderr," Distance map: ts = %3d / %3d \n",ts,maxt);

       //      if (ts && !(ts%10)) {
       //      if (!ts) {
       //        fprintf(stderr,"old dist %f, bnd.size()
       // %d\n",ts*par->init_dt*s,this->bnd.size());
       //      }

       t   = times[tcurrent];
       newt= times[1-tcurrent];
       for (b=0;b<bpc;b++) {
         p = myBand[b];
         ExtractCoords(p,i,j,k);
         u0=t[p];

         if (i==0)    mx =  1;   else mx = -1;
         if (i==tx-1) px = -1;   else px =  1;
         if (j==0)    my =  tx;  else my = -tx;
         if (j==ty-1) py = -tx;  else py =  tx;

         umx=t[p+mx];   upx=t[p+px];
         umy=t[p+my];   upy=t[p+py];
         //
         Dpx=(upx-u0)*xspacing;
         Dmx=(u0-umx)*xspacing;
         Dpy=(upy-u0)*yspacing;
         Dmy=(u0-umy)*yspacing;

     if (Dimension==3) {
       if (k==0)    mz =  txy; else mz = -txy;
       if (k==tz-1) pz = -txy; else pz =  txy;
       umz=t[p+mz];   upz=t[p+pz];
       Dpz=(upz-u0)*zspacing;
       Dmz=(u0-umz)*zspacing;
     }

         if (s>0) {
           deltap=0;
           if (Dpx<=0)       deltap+=Dpx*Dpx;
           if (Dmx>0)        deltap+=Dmx*Dmx;
           if (Dpy<=0)       deltap+=Dpy*Dpy;
           if (Dmy>0)        deltap+=Dmy*Dmy;
       if (Dimension==3) {
         if (Dpz<=0)       deltap+=Dpz*Dpz;
         if (Dmz>0)        deltap+=Dmz*Dmz;
       }
           deltap=sqrt(deltap);
         } else {
           deltam=0;
           if (Dpx>0)        deltam+=Dpx*Dpx;
           if (Dmx<=0)       deltam+=Dmx*Dmx;
           if (Dpy>0)        deltam+=Dpy*Dpy;
           if (Dmy<=0)       deltam+=Dmy*Dmy;
       if (Dimension==3) {
         if (Dpz>0)        deltam+=Dpz*Dpz;
         if (Dmz<=0)       deltam+=Dmz*Dmz;
       }
           deltam=sqrt(deltam);
         }
         if (s>0) {
           //
           newt[p]=u0-this->init_dt*deltap;
           // si le point est TIMEMINE, il faut mettre a jour sa valeur
           // pour cela on utilise une interpolation

           // TIMEMINE just means on the outside of the surface if s>0
           // or on the inside if s<0.  ie, it is a point we care about
           // during the current iteration.

           // so, the following condition is:  if it is a point we care
           // about now, and if it swapped inside/outside of the
           // surface...

           if ((myflag[p]&TIMEMINE) && newt[p]<0) {
             //
             newU[p]=this->init_dt*(ts+u0/(u0-newt[p]));
             myflag[p]&=~TIMEMINE; // on baisse TIMEMINE
             seen++;
           }
         } else {/*idem*/
           //
           newt[p]=u0+this->init_dt*deltam;
           if ((myflag[p]&TIMEMINE) && newt[p]>0) {
             newU[p]=-this->init_dt*(ts+u0/(u0-newt[p]));
             myflag[p]&=~TIMEMINE;
             seen++;
           }
         }
       }
       tcurrent=1-tcurrent;
     } // end for ts
   } // end for s

   delete [] myBand;
   delete [] myflag;

   delete [] times[0];
   delete [] times[1];

   //
   //   MakeBand();

   if (GB_debug) fprintf(stderr, "DistanceMapCurves() end \n");

} // DistanceMapCurves()


//----------------------------------------------------------------------------
//
// Method to estimate the distance's map
// use vtkLevelSetFastMarching class
//
// Input Parameters:
//
//   current
//   u[current]   : input image
//   inputImage   : for getting the voxel size
//   Band         : size of the band
//
// Outputs:
//
//   u[1-current]
//
//
void vtkLevelSets::DistanceMapFMOld()
//                   ------------
{
   int U_pos    = this->current;
   int newU_pos = 1-this->current;
   float_vec_it        U    = u[U_pos].begin();
   float_vec_it        newU = u[newU_pos].begin();
   vtkImageData* current_image = vtkImageData::New();


   if (GB_debug) fprintf(stderr, "DistanceMapFM() begin \n");


   // Use U[] as input
   vtkImageData::SetScalarType(VTK_FLOAT,        current_image->GetInformation());
   vtkImageData::SetNumberOfScalarComponents(1,  current_image->GetInformation());
   current_image->SetDimensions( outputImage->GetDimensions());
   current_image->SetOrigin(     outputImage->GetOrigin());
   current_image->SetSpacing(    outputImage->GetSpacing());
   vtkFloatArray* da = vtkFloatArray::New();

   da->SetArray(&(u[U_pos].front()),imsize,1);
   current_image->GetPointData()->SetScalars(da);

   // use newU as output
   // improve this ???
   fm->UseOutputArray( &*(newU) );

   // Set the parameters
   // Trick:
   // Set the init image equal to the input image
   // which set a uniform force of 1 for the evolution
   fm->SetInputData( current_image);
   fm->Setinitimage( current_image);

   fm->Setinitiso(0);
   fm->SetmaxTime(Band+1);

   // Run the distance transform
   //   fm->Register(current_image);

   fm->Update();

   // Probably not necessary
   fm->GetOutput();

   if (GB_debug) fprintf(stderr, "DistanceMapFM()  current_image ->Delete(); \n");

   current_image ->Delete();
   da->Delete();

   if (GB_debug) fprintf(stderr, "DistanceMapFM() end \n");

} // DistanceMapFMOld()

//----------------------------------------------------------------------------
//
// Method to estimate the distance's map
// use vtkLevelSetFastMarching class
//
// Input Parameters:
//
//   current
//   u[current]   : input image
//   inputImage   : for getting the voxel size
//   Band         : size of the band
//
// Outputs:
//
//   u[1-current]
//
//
void vtkLevelSets::DistanceMapFM()
//                   ------------
{
   int U_pos    = this->current;
   int newU_pos = 1-this->current;
   float_vec_it        U    = u[U_pos].begin();
   float_vec_it        newU = u[newU_pos].begin();
   float*              ptr;
   vector_size      i;
   vtkImageData_ptr      res1;
   vtkImageData_ptr      current_image;


   if (GB_debug) fprintf(stderr, "DistanceMapFM() begin \n");

   current_image = vtk_new<vtkImageData> ()();
   if (!isodist.use_count())
    isodist = vtk_new<vtkImageIsoContourDist>()();

   // Use U[] as input
   vtkImageData::SetScalarType(VTK_FLOAT,        current_image->GetInformation());
   vtkImageData::SetNumberOfScalarComponents(1,  current_image->GetInformation());
   current_image->SetDimensions( outputImage->GetDimensions());
   current_image->SetOrigin(     outputImage->GetOrigin());
   current_image->SetSpacing(    outputImage->GetSpacing());

   boost::shared_ptr<vtkFloatArray> da = vtk_new<vtkFloatArray>()();
   da->SetArray(&(u[U_pos].front()),imsize,1);
   current_image->GetPointData()->SetScalars(da.get());

   // Compute the distance for the neighbors of the isocontour
   isodist->SetInputData(current_image.get());
   isodist->Setthreshold(0);
   isodist->Setfarvalue(Band+1);
   isodist->SetNarrowBand(&(this->bnd.front()),
                          this->bnd.size());
   isodist->Update();
   res1 = vtk_new<vtkImageData>()(isodist->GetOutput());

   if (IsoContourBin) {
     ptr = ((float*) res1->GetScalarPointer());
     for(i=0;i<imsize;i++) {
       if ((ptr[i]>0)&&(ptr[i]< 1)) ptr[i] =  0.5;
       if ((ptr[i]<0)&&(ptr[i]>-1)) ptr[i] = -0.5;
     }
   }

  if (savedistmap)
  {
    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
    char name[255];

    writer->SetInputData(res1.get());
    sprintf(name,"res1.vtk");
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
    writer->Write();
    writer->Delete();
  }
   // Put Values Positive
   ptr = (float*) res1->GetScalarPointer();
   for(i=0;i<imsize;i++) ptr[i] = fabs(ptr[i]);

   // use newU as output
   fm->UseOutputArray( &(u[newU_pos].front()) );

   // Set the parameters
   // Trick:
   // Set the init image equal to the input image
   // which set a uniform force of 1 for the evolution
   fm->SetInputData( res1.get());
   fm->Setinitimage( res1.get());
   // The to Band because of possible anisotropic voxels
   fm->Setinitmaxdist(1+1E-3);

   fm->SetNarrowBand(&(this->bnd.front()),
                      this->bnd.size());

   //   fm->Setinitiso(0);
   fm->SetmaxTime(Band+1E-3);

   // Run the distance transform
   //   fm->Register(current_image);

   fm->Update();

   // Probably not necessary
   //fm->GetOutput();
/* TODO: VTK6 port
   //fm->UnRegisterAllOutputs();
*/
   if (verbose) {
     fprintf(stderr, ".");fflush(stderr);
   }

   // Put the sign back to the image
   ptr = (float*) current_image->GetScalarPointer();
   for(i=0;i<imsize;i++) if (ptr[i]<0) newU[i] = -newU[i];

   if (verbose) {
     fprintf(stderr, ".");fflush(stderr);
   }

   isodist.reset();

   if (GB_debug) fprintf(stderr, "DistanceMapFM() end \n");

} // DistanceMapFM()


//----------------------------------------------------------------------------
//
// Method to estimate the distance's map
// use vtkImageIsoContourDist and vtkImageFastSignedChamfer
//
// vtkImageIsoContourDist use the voxel size
// but vtkImageFastSignedChamfer consider the voxels as isotropic
//
// Input Parameters:
//
//   current
//   u[current]   : input image
//   inputImage   : for getting the voxel size
//   Band         : size of the band
//
// Outputs:
//
//   u[1-current]
//
//
//
void vtkLevelSets::DistanceMapChamfer()
//                   ------------
{

  VTK_CLASS_MESSAGE("Begin");

   int U_pos    = this->current;
   int newU_pos = 1-this->current;
   float_vec_it        U    = u[U_pos].begin();
   float_vec_it        newU = u[newU_pos].begin();
   float*        ptr;
   vector_size      i;

   vtkImageData*              res1;

   if (GB_debug) {
     fprintf(stderr, "DistanceMapChamfer() .");fflush(stderr);
   }

   vtkImageData_ptr current_image = vtk_new< vtkImageData> ()();

   if (!isodist.use_count())
      isodist = vtk_new<vtkImageIsoContourDist> ()();
   if (!chamfer.use_count())
      chamfer = vtk_new<vtkImageFastSignedChamfer> ()();

   // Use U[] as input
   vtkImageData::SetScalarType(VTK_FLOAT,        current_image->GetInformation());
   vtkImageData::SetNumberOfScalarComponents(1,  current_image->GetInformation());
   current_image->SetDimensions( outputImage->GetDimensions());
   current_image->SetOrigin(     outputImage->GetOrigin());
   current_image->SetSpacing(    outputImage->GetSpacing());

   boost::shared_ptr<vtkFloatArray> da = vtk_new<vtkFloatArray>()();

   da->SetArray(&(u[U_pos].front()),imsize,1);
   current_image->GetPointData()->SetScalars(da.get());

   // Compute the distance for the neighbors of the isocontour
   isodist->SetInputData(current_image.get());
   isodist->Setthreshold(0);
   isodist->Setfarvalue(Band+1);

   // directly updates newU ...
   isodist->UseOutputArray( &(u[newU_pos].front()) );

   if (!this->bnd.empty())
     isodist->SetNarrowBand(&(this->bnd.front()),
                            this->bnd.size());

   //     fprintf(stderr, "DistanceMapChamfer() Register \n");
     //   isodist->Register(current_image);
   //     fprintf(stderr, "DistanceMapChamfer() Update \n");
   isodist->Update();

   //     fprintf(stderr, "DistanceMapChamfer() GetOutput \n");
   res1 = isodist->GetOutput();

  // Save the result

  if (savedistmap)
  {
    boost::shared_ptr<vtkStructuredPointsWriter> writer = vtk_new<vtkStructuredPointsWriter> ()();
    char name[255];

    writer->SetInputData(res1);
    sprintf(name,"res1.vtk");
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
    writer->Write();
  }


   // Put Values Positive
   if (IsoContourBin) {
     ptr = (float*) res1->GetScalarPointer();
     for(i=0;i<imsize;i++) {
       if ((ptr[i]>0)&&(ptr[i]< 1)) ptr[i] =  0.5;
       if ((ptr[i]<0)&&(ptr[i]>-1)) ptr[i] = -0.5;
     }
   }

   //   memcpy(newU,res1->GetScalarPointer(),imsize*sizeof(float));

   //    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
   //    writer->SetInputData(res1);
   //    writer->SetFileName("isodist.vtk");
   //    writer->SetFileTypeToBinary();
   //    writer->Write();
   //    writer->Delete();

   //   if (GB_debug)
   //     fprintf(stderr, "DistanceMapChamfer() chamfer \n");

   // uses newU both as input and output
   chamfer->UseInputOutputArray( &(u[newU_pos].front()) );

   // input not used ...
   chamfer->SetInputData(       res1);
   chamfer->Setmaxdist(     Band+1);
   // Don't propagate all the border points
   chamfer->Setnoborder(1);
   //     fprintf(stderr, "DistanceMapChamfer() update \n");
   chamfer->Update();
   chamfer->GetOutput();
/* TODO: VTK6 port
   //chamfer->UnRegisterAllOutputs();
*/

   if (GB_debug)
     fprintf(stderr, ";\n");

    VTK_CLASS_MESSAGE("End");

} // DistanceMapChamfer()


//----------------------------------------------------------------------------
//
// Method to estimate the distance's map
//
// use vtkImagePropagateDist2.h
//
// Compute the Danielsson distance to an isocontour,
// estimate a skeleton of the initial surface,
// and computed the distance and the projection to the skeleton
//
// Input Parameters:
//
//   current
//   u[current]   : input image
//   inputImage   : for getting the voxel size
//   Band         : size of the band
//   mindist      : <0,
//                  the maximal distance that we propagate inside the structure
//
// Outputs:
//
//   u[1-current]
//   distance to skeleton
//   projection to skeleton
//
//
void vtkLevelSets::DistanceMapShape()
//                 ----------------
{
   int U_pos    = this->current;
   int newU_pos = 1-this->current;
   float_vec_it        U    = u[U_pos].begin();
   float_vec_it        newU = u[newU_pos].begin();

   vtkImageData*              current_image;

   //   if (GB_debug)
   fprintf(stderr, "DistanceMapShape() .");fflush(stderr);

   current_image = vtkImageData::New();
   if (!shape.use_count())
      shape = vtk_new<vtkImagePropagateDist2>()();

   // Creation vtkImage from U[.]
   vtkImageData::SetScalarType(VTK_FLOAT,        current_image->GetInformation());
   vtkImageData::SetNumberOfScalarComponents(1,  current_image->GetInformation());
   current_image->SetDimensions( outputImage->GetDimensions());
   current_image->SetOrigin(     outputImage->GetOrigin());
   current_image->SetSpacing(    outputImage->GetSpacing());
   vtkFloatArray* da = vtkFloatArray::New();
   da->SetArray(&(u[U_pos].front()),imsize,1);
   current_image->GetPointData()->SetScalars(da);

   // Compute the distance for the neighbors of the isocontour
   shape->SetInputData(current_image);
   shape->Setthreshold(0);
   shape->Setmindist(ShapeMinDist);
   shape->Setmaxdist(Band+1);

   // directly updates newU ...
   shape->UseOutputArray( &(u[newU_pos].front()) );

   shape->SetNarrowBand(&(this->bnd.front()),
                        this->bnd.size());

   shape->Update();
   shape->GetOutput();

   //
   if (SkeletonImage==NULL) {
     // Allocate the Skeleton Image
     SkeletonImage = vtkImageData::New();
     vtkImageData::SetScalarType(VTK_FLOAT,        SkeletonImage->GetInformation());
     vtkImageData::SetNumberOfScalarComponents(1,  SkeletonImage->GetInformation());
     SkeletonImage->SetDimensions(inputImage->GetDimensions() );
     SkeletonImage->SetOrigin(    inputImage ->GetOrigin());
     SkeletonImage->SetSpacing(   inputImage->GetSpacing() );
     SkeletonImage->CopyAndCastFrom(inputImage,
                                  inputImage->GetExtent());
      //     SkeletonImage->AllocateScalars();
     SkeletonImage_allocated = 1;
   }
   shape->GetSkeleton( SkeletonImage);

   da->Delete();
   current_image ->Delete();


} // DistanceMapShape()


//--------------------------------------------------------------------------
// Check the convergence.
unsigned char vtkLevelSets::CheckConvergence( )
{
     vector_size p;;
     int            cnt1,cnt2,total;
     float          converged_check1;
     float          converged_check2;
     float          converged_check;

  VTK_CLASS_MESSAGE("Begin");

   return 0;

   total = cnt1 = cnt2 = 0;

   // counting
   // total: number of negative points
   // cnt1 number of point which passed from negative to positive value
   // cnt2 number of point which passed from positive to negative value

   // loop over the band instead ...
   for (p = 0; p < imsize; p++) {

     if (this->u[current][p] <= 0) total++;

     // 0.5, 0  is a hack.  maybe want zero, or at least try various
     // values between 0 and 1 to see what convergence estimates agreed
     // with observed convergence.
     if ((this->stored_seg[p] == ON_STORED)    && (this->u[current][p] > 0))
       cnt1++;
     else
       if ((this->stored_seg[p] == OFF_STORED) && (this->u[current][p] <= 0))
         cnt2++;

     // now rewrite stored_seg for the next time:
     if (this->u[this->current][p] <= 0)
       this->stored_seg[p] = ON_STORED;
     else
       this->stored_seg[p] = OFF_STORED;
   }

   converged_check1 = ((float)cnt2)/((float)total);
   converged_check2 = ((float)cnt1)/((float)total);

   vtkDebugMacro( << cnt1 << "," << cnt2 << "," <<
         total << "," << converged_check1 << "," << converged_check2);

   // in simulation experiments, care about shrinking also, so use
   //   a different convergence check
   //      if (check_shrink)
   //        converged_check = converged_check1+converged_check2;
   //      else

   converged_check = converged_check1;

   if (GB_debug) fprintf(stderr, "vtkLevelSets::CheckConvergence( ) end \n");

   return (converged_check < ConvergedThresh);

} // CheckConvergence()


//--------------------------------------------------------------------------
// Check the convergence.
void vtkLevelSets::CheckConvergenceNew( )
{
  VTK_CLASS_MESSAGE("Begin");

  if (bnd.size()==0) {
    VTK_CLASS_MESSAGE("Narrow Band not initialized");
    return;
  }

  register float_vec_it U =this->u[  this->current].begin();
  vector_size b;
  int i;
  // histogram of the log of the changes
  int* loghisto = new int[5];
  int logdiff;

  //cout << "bnd size = " << bnd.size() << std::endl;
  //cout << "bnd initialvalues = " << bnd_initialvalues.size() << std::endl;
  VTK_CLASS_MESSAGE("1.1");
  for(i=0;i<5;i++) {
//   std::cout << "i= " << i << std::endl;
    loghisto[i]=0;
  }

  VTK_CLASS_MESSAGE("1.2");
  // Loop over the Narrow Band and check the intensity change
  for(b=0;b<this->bnd.size();b++) {
    double tmp = fabs(bnd_initialvalues[b]-U[this->bnd[b]]);
//   std::cout << "b = " << b << "; tmp = " << tmp << std::endl;
    if (tmp>1E-5) {
      logdiff = (int) log(tmp);
      if (-logdiff<=0) loghisto[0]++;
      else
        if (-logdiff>=4) loghisto[4]++;
        else
      loghisto[-logdiff]++;
    } else loghisto[4]++;
  }

  VTK_CLASS_MESSAGE("1.3");

  // print the convergence results
  printf("\nConv test :");
  for(i=0;i<5;i++)
    printf(" %d, %02.2f  ",i,(loghisto[i]*100.0)/this->bnd.size());

  VTK_CLASS_MESSAGE("End");

  delete [] loghisto;
} // CheckConvergenceNew()


//---------------------------------------------------------------------------
//
inline void vtkLevelSets::ExtractCoords(int p, short& x, short& y, short& z)
{
  x = p%tx;
  p = (p-x)/tx;
  y = p%ty;
  z = (p-y)/ty;
} // ExtractCoords()


//---------------------------------------------------------------------------
//
void vtkLevelSets::MakeBand( )
{
  VTK_CLASS_MESSAGE("Begin" );

  // before creating the new band, check the convergence
  this->CheckConvergenceNew();
  this->MakeBand0();

  /*
   // Save the result
   {
     vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
     vtkImageData* copyImage = vtkImageData::New();
     unsigned char* ptr;
     char name[255];

     copyImage->SetScalarType( VTK_UNSIGNED_CHAR);
     copyImage->SetNumberOfScalarComponents(1);
     copyImage->SetDimensions( outputImage->GetDimensions());
     copyImage->SetOrigin(     outputImage->GetOrigin());
     copyImage->SetSpacing(    outputImage->GetSpacing());
     copyImage->CopyAndCastFrom(outputImage,
                outputImage->GetExtent());

     ptr = (unsigned char*) copyImage->GetScalarPointer(0,0,0);
     for(i=0;i<imsize;i++) {
       *ptr = this->flag[i];
       ptr++;
     }

     writer->SetInput(copyImage);
     band_count++;
     sprintf(name,"band%d.vtk",band_count);
     writer->SetFileName(name);
     writer->SetFileTypeToBinary();
     writer->Write();
   }
  */

    VTK_CLASS_MESSAGE("End" );
}


//---------------------------------------------------------------------------
//
//  Update the bounding band
//
//  Inputs
//    current
//    u[current]
//    u[1-current]
//    bnd
//    flag
//    tube           : size of the tube
//
//  Outputs
//
//
//    u[current]
//    u[1-current]
//    flag[.]        :
//                     0         : not in [-band,band]
//                     INBAND    : in  [-band,band]
//                     INTUBE    : in  [-Tube,Tube]
//                     TUBEFRONT : in  [-(Tube-1.8),Tube-1.8]
//                     NEGMINE   : in  [-band,-tube]
//                     POSMINE   : int [tube,band]
//
//    bnd[.]         : position in the image of each point of the bounding band
//    bnd.size()         : number of points in the bounding band
//
//
//
//
//
void vtkLevelSets::MakeBand0( )
{

  VTK_CLASS_MESSAGE("Begin" );

  register vector_size   p;
  register int   x, y, z;
  register float_vec_it U = u[  current].begin();
  register float_vec_it nU = u[1-current].begin();
  register float u0 = 0, u1;
  register float val;
  register uchar_vec_it    flag_ptr;

  register const unsigned char inband  = INBAND;
  register const unsigned char bandneg = INBAND | NEGMINE;
  register const unsigned char bandpos = INBAND | POSMINE;

  register int xmin, xmax, ymin, ymax, zmin, zmax;


  if ( verbose ) {
    fprintf ( stderr, "MB0() ." );
    fflush ( stderr );
  }

  // Allocating the band of the size of the image,
  // which is in general not necessary ...
  // allocate at 15% of the image size
  vector_size bnd_sizeinc   = ( vector_size ) ( imsize * 0.15 );
  if ( bnd.capacity() < bnd_sizeinc ) {
    fprintf ( stderr, "Band Allocation %d \n", ( int ) bnd_sizeinc );
    this->bnd               .reserve ( bnd_sizeinc );
    this->bnd_initialvalues .reserve ( bnd_sizeinc );
    this->flag              .reserve ( imsize );
    ADDMEMORY ( "vtkLevelSets::MakeBand0() allocated band capacity: bnd + flag ", bnd.capacity() *sizeof ( int ) + imsize )
  }

  // be sure the band is empty();
  this->bnd               .clear();
  this->bnd_initialvalues .clear();

  // Set by default to OUTBAND (0)
  this->flag.clear();
  this->flag.resize ( imsize, 0 );

  switch ( DMmethod ) {

    case DISTMAP_CURVES:
      //   --------------
      // update INTUBE and TUBEFRONT
      for ( p = 0;p < imsize;p++ ) {
        if ( fabs ( U[p] ) <= Band ) {
          u0    = U[p];
          nU[p] = u0;
          u1 = fabs ( u0 );
          this->flag[p] = INBAND;

          // Check in Tube
          if ( u1 <= this->Tube ) {
            this->flag[p] |= INTUBE;
            // Check Tube front
            if ( u1 >= this->Tube - 1.8 ) this->flag[p] |= TUBEFRONT;
          } else
            if ( u0 < -this->Tube )
              this->flag[p] |= NEGMINE;
            else
              this->flag[p] |= POSMINE;

          this->bnd               .push_back ( p );
          this->bnd_initialvalues .push_back ( u0 );
          if ( bnd.size() >= bnd.capacity() ) ResizeBand();
        }
      }
      break;

    case DISTMAP_FASTMARCHING:
      //   --------------------

      // don't need INTUBE and TUBEFRONT
      U = this->u[this->current].begin();

      // loop on x,y and z to avoid adding border points in the narrow
      // band and thus to avoid checking its limits and speed up
      // the other functions
      zmin = 1;
      zmax = tz - 2;

      if ( Dimension == 2 ) {
        zmin = zmax = 0;
      }


      p = zmin * txy;
      for ( z = zmin;z <= zmax;z++ ) {
        p += tx;
        for ( y = 1;y < ty - 1;y++ ) {
          p++;
          for ( x = 1;x < tx - 1;x++ ) {
            //      if (p>=imsize) fprintf(stderr,"Pb ...\n");
            val = U[p];
            if ( fabs ( val ) <= Band ) {

              // Check in Tube
              if ( val < -this->Tube )
                flag[p] = bandneg;
              else
                if ( val > this->Tube )
                  flag[p] = bandpos;
                else
                  flag[p] = inband;
              nU[p] = val;
              bnd               .push_back ( p );
              bnd_initialvalues .push_back ( val );
              if ( bnd.size() >= bnd.capacity() ) ResizeBand();
            }
            p++;
          } // end for x
          p++;
        } // end for y
        p += tx;
      } // end for z
      break;


    case DISTMAP_CHAMFER:
      //   ---------------

      VTK_CLASS_MESSAGE("Chamfer distance init" );

      // don't need INTUBE and TUBEFRONT
      U = this->u[this->current].begin();

      xmin = max ( 1,   chamfer->GetExtent() [0] );
      xmax = min ( tx - 2, chamfer->GetExtent() [1] );
      ymin = max ( 1,   chamfer->GetExtent() [2] );
      ymax = min ( ty - 2, chamfer->GetExtent() [3] );
      zmin = max ( 1,   chamfer->GetExtent() [4] );
      zmax = min ( tz - 2, chamfer->GetExtent() [5] );

      if ( Dimension == 2 ) {
        zmin = zmax = 0;
      }

      // loop on x,y and z to avoid adding border points in the narrow
      // band and thus to avoid checking its limits and speed up
      // the other functions
      p = zmin * txy;
      for ( z = zmin;z <= zmax;z++ ) {
        p += ymin * tx;
        for ( y = ymin;y <= ymax;y++ ) {
          p += xmin;
          for ( x = xmin;x <= xmax;x++ ) {
            //      if (p>=imsize) fprintf(stderr,"Pb ...\n");
            val = U[p];
            if ( fabs ( val ) <= Band ) {

              // Check in Tube
              if ( val < -this->Tube )
                flag[p] = bandneg;
              else
                if ( val > this->Tube )
                  flag[p] = bandpos;
                else
                  flag[p] = inband;
              nU[p] = val;
              bnd               .push_back ( p );
              bnd_initialvalues .push_back ( val );
              if ( bnd.size() >= bnd.capacity() ) ResizeBand();
            }
            p++;
          } // end for x
          p += tx - 1 - xmax;
        } // end for y
        p += tx * ( ty - 1 - ymax );
      } // end for z
      VTK_CLASS_MESSAGE("Chamfer distance init end" );

      break;

      // Slow: initial during the processing of the distance ...
    case DISTMAP_SHAPE:
      //   ---------------
      // don't need INTUBE and TUBEFRONT
      U = this->u[this->current].begin();

      xmin = 1;
      xmax = tx - 2;
      ymin = 1;
      ymax = ty - 2;
      zmin = 1;
      zmax = tz - 2;

      if ( Dimension == 2 ) {
        zmin = zmax = 0;
      }

      // loop on x,y and z to avoid adding border points in the narrow
      // band and thus to avoid checking its limits and speed up
      // the other functions
      p = zmin * txy;
      for ( z = zmin;z <= zmax;z++ ) {
        p += ymin * tx;
        for ( y = ymin;y <= ymax;y++ ) {
          p += xmin;
          for ( x = xmin;x <= xmax;x++ ) {
            //      if (p>=imsize) fprintf(stderr,"Pb ...\n");
            val = U[p];
            if ( fabs ( val ) <= Band ) {

              // Check in Tube
              if ( val < -this->Tube )
                flag[p] = bandneg;
              else
                if ( val > this->Tube )
                  flag[p] = bandpos;
                else
                  flag[p] = inband;
              nU[p] = val;
              bnd              .push_back ( p );
              bnd_initialvalues.push_back ( val );
              if ( bnd.size() >= bnd.capacity() ) ResizeBand();
            }
            p++;
          } // end for x
          p += tx - 1 - xmax;
        } // end for y
        p += tx * ( ty - 1 - ymax );
      } // end for z
      break;
  } // switch (DMmethod)

  VTK_CLASS_MESSAGE("End" );

} // MakeBand0()



//----------------------------------------------------------------
// Init params and copy data to float
void vtkLevelSets::InitParam( vtkImageData* input,
//                 ---------
                              vtkImageData* output)
{
  int type;

  if (verbose) {
    fprintf(stderr,"vtkLevelSets::InitParam() \n");
    //    this->PrintParameters();
  }

  inputImage = input;

  if (inputImage == NULL) {
    vtkErrorMacro("Missing input");
    return;
  }
  else {

    // check the image is in float format, or convert
    type = input->GetScalarType();
    //    if (type != VTK_FLOAT) {
      vtkDebugMacro(<<"making a copy of the input into float format");
      // Create a copy of the data
      inputImage = vtkImageData::New();

      vtkImageData::SetScalarType(VTK_FLOAT,        inputImage->GetInformation());
      vtkImageData::SetNumberOfScalarComponents(1,  inputImage->GetInformation());
      inputImage->SetDimensions( input->GetDimensions());
      inputImage->SetOrigin(     input->GetOrigin());
      inputImage->SetSpacing(    input->GetSpacing());

      inputImage->AllocateScalars(inputImage->GetInformation());
      inputImage->CopyAndCastFrom(input,
                                  input->GetExtent());
      inputImage_allocated = 1;
      //    }
      //    else
      //      inputImage = input;

    tx = this->inputImage->GetDimensions()[0];
    ty = this->inputImage->GetDimensions()[1];
    tz = this->inputImage->GetDimensions()[2];
    txy = tx*ty;
    imsize = txy*tz;


    if (tz==1) {
      Dimension = 2;
      SliceNum  = 0;
      fprintf(stderr," Set 2D LevelSets for 2D image \n");
    }


    //--- outputImage
    outputImage      = (vtkImageData*) output;

    outputImage->SetDimensions(inputImage->GetDimensions() );
    outputImage->SetSpacing(   inputImage->GetSpacing() );
    vtkImageData::SetScalarType(VTK_FLOAT, outputImage->GetInformation());
    vtkImageData::SetNumberOfScalarComponents(1, outputImage->GetInformation());
    outputImage->AllocateScalars(outputImage->GetInformation());
    outputImage->CopyAndCastFrom(this->inputImage,
                                 this->inputImage->GetExtent());

    ADDMEMORY("vtkLevelSets::InitParam() Input & Output Images",(2*sizeof(float)*imsize));

  }

  // initialize the volume used to check for convergence
  stored_seg = new unsigned char [imsize];
  stored_seg_allocated = 1;

  ADDMEMORY("vtkLevelSets::InitParam() stored_seg (UNSIGNED CHAR)",imsize);

  for(vector_size i=0;
      i<imsize;
      i++)
    stored_seg[i] = 0;


} //  InitParam()


//---------------------------------------------------------------------------
void vtkLevelSets::ResizeBand()
//                   ----------
{
/*
  int*           new_band;
  float*         new_bandval;
*/
  vector_size   bnd_maxsize = bnd.capacity();
  vector_size   new_maxsize;

  // add 15% of the image size
  new_maxsize = bnd_maxsize+(vector_size) (imsize*0.15);
  if (new_maxsize>imsize) new_maxsize = imsize;

  bnd               .reserve(new_maxsize);
  bnd_initialvalues .reserve(new_maxsize);


  ADDMEMORY("vtkLevelSets::ResizeBand() size increase (INT)",(new_maxsize-bnd_maxsize)*sizeof(int));

} // ResizeBand()


//---------------------------------------------------------------------------
void vtkLevelSets::Evolve()
//                   ------
{
  switch (Dimension) {
  case 2: Evolve2D(); break;
  case 3: Evolve3D(); break;
  }

}

//---------------------------------------------------------------------------
// One evolution of the PDE
//
//
//  Inputs
//    bnd[]
//    u[current]
//    inputImage
//    flag
//
//  Outputs
//    u[1-current]
//    current        : swapped
//
//  Calls
//
//    DistanceMap()  : if the surface touches the bb limit
//    MakeBand()     : if the surface touches the bb limit
//
//
void vtkLevelSets::Evolve2D()
//                   --------
{
    short i,j,k;
    int   p;
    float_vec_it U    = this->u[current].begin();
    float_vec_it newU = this->u[1-current].begin();
    float* im = ((float*) this->inputImage->GetScalarPointer());

    register float u0,upx,upy,umx,umy;
    register float D0x,D0y;
    register float i0x,i0y;

    float          delta0,sqrtdelta0;

    register float imx,imy;

    register float D0xy;
    float          normcompsq;

    register float D_x,Dx,D_y,Dy;

    float Dpmx=0;
    float Dpmy=0;
    float dxy2;
    float meancurv=0;
    float dxsq=0,dysq=0;
    float imcomp=0,costerm,ut;
    float curvterm;
    float balloonterm;

    register int mx,my,px,py;

    float adv;

    float Vx,Vy;

    float vel;
    float Gx,Gy,Gnorm,sp,norm_vel;


  this->mean_curv      = 0;
  this->mean_balloon   = 0;
  this->mean_advection = 0;
  this->mean_vel       = 0;

  this->touched=0;

  for ( vector_size b=0;
        b<this->bnd.size();
        b++) {

    p = this->bnd[b];
    ExtractCoords(p,i,j,k);

    if (i==0)    mx =  1;   else mx = -1;
    if (i==tx-1) px = -1;   else px =  1;
    if (j==0)    my =  tx;  else my = -tx;
    if (j==ty-1) py = -tx;  else py =  tx;

    // First order derivatives
    u0=U[p];
    umx=U[p+mx];
    upx=U[p+px];
    umy=U[p+my];
    upy=U[p+py];

    Dx = (upx-u0)/vx;
    Dy = (upy-u0)/vy;

    D_x = (u0-umx)/vx;
    D_y = (u0-umy)/vy;

    D0x=(upx-umx)*(doubxspacing);
    D0y=(upy-umy)*(doubyspacing);

    // Second order derivatives
    Dpmx=(upx-2*u0+umx)*sqxspacing;
    Dpmy=(upy-2*u0+umy)*sqyspacing;

    // Crossed derivatives
    D0xy=(U[p+px+py]+U[p+mx+my]-U[p+px+my]-U[p+mx+py])*xyspacing;

    //
    dxsq = D0x*D0x;
    dysq = D0y*D0y;
    dxy2 = 2*D0x*D0y;
    delta0=dxsq+dysq;
    sqrtdelta0 = sqrt(delta0);

    //--------------------------------------------------
    // Curvature Term
    //--------------------------------------------------

    //    if (delta0!=0)
    if (delta0>SquaredGradientEpsilon) {
      meancurv = (Dpmy*dxsq +Dpmx*dysq-dxy2*D0xy)/delta0/sqrtdelta0;

      //--------------------------------------------------
      // Data Attachment Term
      //--------------------------------------------------

      i0x=(im[p+px]-im[p+mx])*(doubxspacing);
      i0y=(im[p+py]-im[p+my])*(doubyspacing);

      normcompsq = i0x*i0x+i0y*i0y;

      if (normcompsq==0)
      {
        imcomp = 0;
        vel    = 0;
      }
      else
      {
        // BELOW IS WHAT WAS USED FOR IPMI PAPER
        if (UseCosTerm)
          costerm = -(D0x*i0x+D0y*i0y)/(sqrtdelta0*sqrt(normcompsq));
        else
          costerm = 1;

        // recall that image is rescaled to 0-255 when loaded.
        //
        // Where does the 'costerm' comes from ?
        // it should be: - H.DI.Du / |Du| / |DI|
        //

        if (fabs(AdvectionCoeff)>1E-10) {
          switch (advection_scheme) {
          case ADVECTION_UPWIND_VECTORS:
            // Use upwind differences for advection term :
            imx = data_attach_x[p];
            imy = data_attach_y[p];
            adv = 0;

            printf("imx imy = %f %f \n",imx,imy);

            if (costerm>0) {
              if (imx>0) adv += imx*D_x;  else   adv += imx*Dx;
              if (imy>0) adv += imy*D_y;  else   adv += imy*Dy;
            } else {
              if (imx>0) adv += imx*Dx;  else   adv += imx*D_x;
              if (imy>0) adv += imy*Dy;  else   adv += imy*D_y;
            }
            imcomp = adv*AdvectionCoeff*costerm;
          break;
          case ADVECTION_CENTRAL_VECTORS:
            imx = data_attach_x[p];
            imy = data_attach_y[p];
            adv =  D0x*imx+D0y*imy;
            imcomp = adv*AdvectionCoeff*costerm;
          break;
          case ADVECTION_MORPHO:
            if (secdergrad[p]*AdvectionCoeff<0) {
                  Gx = Gy = 0;
              if (D_x>=0) Gx = D_x;
              if ((Dx<0)&&(-Dx>Gx)) Gx = Dx;
                if (D_y>=0) Gy = D_y;
              if ((Dy<0)&&(-Dy>Gy)) Gy = Dy;
                }
                else {
              Gx = Gy = 0;
              if (D_x<=0) Gx = D_x;
              if ((Dx>0)&&(Dx>-Gx)) Gx = Dx;
              if (D_y<=0) Gy = D_y;
              if ((Dy>0)&&(Dy>-Gy)) Gy = Dy;
            }
            Gnorm = sqrt(Gx*Gx+Gy*Gy);
            imcomp = -Gnorm*secdergrad[p];
            imcomp *= AdvectionCoeff;
          break;
          } // end switch
        } // end if
      }

      //      g = exp(-sqrt(normcompq)/0.3);

      //--------------------------------------------------
      // Balloon expansion Term
      //--------------------------------------------------

      balloonterm = 0.0;
      if (fabs(balloon_coeff)>1E-10) {
        if (balloon_image != NULL)
          balloonterm = balloon_coeff*((float*)balloon_image->GetScalarPointer())[p];
        else
          balloonterm = balloon_coeff* this->ExpansionMap(im[p]);
      }

      if (balloonterm>0) {
        Gx = Gy = 0;
        if (D_x>=0) Gx = D_x;
        if ((Dx<0)&&(-Dx>Gx)) Gx = Dx;
        if (D_y>=0) Gy = D_y;
        if ((Dy<0)&&(-Dy>Gy)) Gy = Dy;
      }
      else {
        Gx = Gy = 0;
        if (D_x<=0) Gx = D_x;
        if ((Dx>0)&&(Dx>-Gx)) Gx = Dx;
        if (D_y<=0) Gy = D_y;
        if ((Dy>0)&&(Dy>-Gy)) Gy = Dy;
      }
      Gnorm = sqrt(Gx*Gx+Gy*Gy);
      balloonterm *= Gnorm;

      //--------------------------------------------------
      // Velocity Term
      //--------------------------------------------------

      vel = 0;
      // Compute the velocity term
      if ((velocity != NULL)&&(coeff_velocity>1E-2)) {
    //    printf("* ");fflush(stdout);
      if ((velocity->GetNumberOfScalarComponents()==2)) {


    //    printf("+ ");fflush(stdout);
    // Scheme of Brokett-Maragos

        Vx = velocity->GetScalarComponentAsDouble(i,j,k,0);
        Vy = velocity->GetScalarComponentAsDouble(i,j,k,1);

    // Scalar product
    norm_vel = sqrt(Vx*Vx+Vy*Vy);
    if (norm_vel>1E-2) {

      // Always expansion (erosion in our case) ...
      Gx = 0;
      if (D_x>=0) Gx = D_x;
      if ((Dx<0)&&(-Dx>Gx)) Gx = Dx;

          Gy = 0;
      if (D_y>=0) Gy = D_y;
      if ((Dy<0)&&(-Dy>Gy)) Gy = Dy;

          Gnorm = sqrt(Gx*Gx+Gy*Gy);

      if (Gnorm>1E-2)
        sp = (Vx*Gx+Vy*Gy)/Gnorm/norm_vel;
      else
        sp = 0;


      sp = fabs(sp);
      vel = Gnorm*sp*(1-exp(-1*(norm_vel*norm_vel)/100/100));

      if (!((vel>-100)&&(vel<100))) {
        fprintf(stderr,"(%d,%d); vel=%f; sp=%f; G=(%f,%f) \n",
            i,j,vel,sp,Gx,Gy);
      }
      vel *= coeff_velocity;
    }
    else
      vel = 0;
      } // if velocity with 2 scalar components
      } // if velocity!=NULL

      /*
      if (DoMean) ut = sqrtdelta0*meancurv    - imcomp;
      else        ut = sqrtdelta0*smallercurv - imcomp;
      */

    //--------------------------------------------------
    // new intensity
    //--------------------------------------------------

      curvterm = sqrtdelta0*meancurv   ;
      curvterm *= coeff_curvature;
      if (curvature_weight != NULL) curvterm *= curvature_weight[p];

      if (curvature_data!=NULL) curvature_data[p] = curvterm;
      if (advection_data!=NULL) advection_data[p] = -imcomp;
      if (velocity_data!=NULL)  velocity_data [p] = -vel;
      if (balloon_data !=NULL)  balloon_data  [p] = -balloonterm;


      ut = curvterm -imcomp - balloonterm;
      if (vel>1E-2) {
        switch (velocity_type) {
          case 0: ut -= vel;      break;
          case 1: ut *= fabsf(vel); break;
          default: std::cerr << "velocity type not available " << std::endl;
        }
      }

      this->mean_curv      += curvterm;
      this->mean_balloon   += balloonterm;
      this->mean_advection += imcomp;
      this->mean_vel       += vel;

      ut = min(max(StepDt*ut,-Band),Band);
      newU[p]=u0+ut;
    } // delta0 <= 0.1
    else {
      if (curvature_data!=NULL) curvature_data[p] = 0;
      if (advection_data!=NULL) advection_data[p] = 0;
      if (velocity_data!=NULL)  velocity_data [p] = 0;
      if (balloon_data !=NULL)  balloon_data  [p] = 0;
      newU[p]=u0;
    }

    if (!this->touched &&
        (((this->flag[p]&NEGMINE) && newU[p]>0) ||
         ((this->flag[p]&POSMINE) && newU[p]<0)
        )
       )
      this->touched=1;
  }
  this->current=1-this->current;

  if (this->touched) {
    fprintf(stderr,"touched \n ");
    //    fflush(stderr);
    this->DistanceMap();
    this->MakeBand();
    reinitcntr = 0;
  }
  else
    reinitcntr++;

  this->mean_curv      /= bnd.size();
  this->mean_balloon   /= bnd.size();
  this->mean_advection /= bnd.size();
  this->mean_vel       /= bnd.size();

  if (verbose) {
    fprintf(stderr,"Evolve2D()\n");
    fprintf(stderr," MEAN curv      = %2.2f\n",this->mean_curv);
    fprintf(stderr," MEAN advection = %2.2f\n",this->mean_advection);
    fprintf(stderr," MEAN balloon   = %2.2f\n",this->mean_balloon);
    fprintf(stderr," MEAN velocity  = %2.2f\n",this->mean_vel);

  }
  if (GB_debug) fprintf(stderr, ";\n");

} // Evolve2D()

//---------------------------------------------------------------------------
VTK_THREAD_RETURN_TYPE vtkLevelSetsThreadedEvolve3D( void *arg )
{
    vtkLevelSets* This;
    int             first,last, total;
    int             threadId;
    int             threadCount;

  threadId    = ((ThreadInfoStruct *)(arg))->ThreadID;
  threadCount = ((ThreadInfoStruct *)(arg))->NumberOfThreads;

  This = (vtkLevelSets *)(((ThreadInfoStruct *)(arg))->UserData);

  total = This->SplitBand(first, last, threadId, threadCount);

  if (threadId < total) This->Evolve3D(first,last);

  return VTK_THREAD_RETURN_VALUE;

} // vtkLevelSetsThreadedEvolve3D()


//---------------------------------------------------------------------------
void vtkLevelSets::Evolve3D( )
//
{

  this->touched=0;

  if (GB_debug) fprintf(stderr,"Evolve3D() threads %d \n",this->EvolveThreads);

  this->mean_curv      = 0;
  this->mean_balloon   = 0;
  this->mean_advection = 0;
  this->mean_vel       = 0;

  if (this->EvolveThreads<=0)
    Evolve3D(0,bnd.size()-1);
  else {
    //      vtkMultiThreader threader;

#ifdef _SOLARIS_
    if (GB_debug)  fprintf(stderr,"thr_setconurrency(%d) \n",this->EvolveThreads);
    //    code = thr_setconcurrency(this->EvolveThreads);
#endif

    vtkMultiThreader* threader = vtkMultiThreader::New();
    //    if (this->NumberOfThreads==0)
    //      this->NumberOfThreads = threader->GetNumberOfThreads();

    // Threaded execution
    threader->SetNumberOfThreads(this->EvolveThreads);


    // setup threading and the invoke threadedExecute
    threader->SetSingleMethod(vtkLevelSetsThreadedEvolve3D, this);
    threader->SingleMethodExecute();

    threader->Delete();
  }

  this->mean_curv      /= bnd.size();
  this->mean_balloon   /= bnd.size();
  this->mean_advection /= bnd.size();
  this->mean_vel       /= bnd.size();

  /*
  fprintf(stderr,"Evolve3D()\n");
  fprintf(stderr," MEAN curv      = %2.2f\n",this->mean_curv);
  fprintf(stderr," MEAN advection = %2.2f\n",this->mean_advection);
  fprintf(stderr," MEAN balloon   = %2.2f\n",this->mean_balloon);
  fprintf(stderr," MEAN velocity  = %2.2f\n",this->mean_vel);
  */

  this->current=1-this->current;

  if (this->touched) {
    if (verbose)
      fprintf(stderr,"touched \n ");
    //    fflush(stderr);
    this->DistanceMap();
    this->MakeBand();
    reinitcntr = 0;
  }
  else
    reinitcntr++;

} // Evolve3D()


//----------------------------------------------------------------------------
// For threads.
// Splits Narrow Band output into num pieces.
// This method returns the number of pieces resulting from a successful split.
//
// total is the total number of threads
//
int vtkLevelSets::SplitBand(int& first, int& last, int num, int total)
{
  // determine the actual number of pieces that will be generated
  int valuesPerThread = (int)ceil(this->bnd.size()/(double)total);
  int maxThreadIdUsed = (int)ceil(this->bnd.size()/(double)valuesPerThread) - 1;

  first =  num*valuesPerThread;
  if (num < maxThreadIdUsed)
    last = first + valuesPerThread - 1;
  else
    last = this->bnd.size()-1;

  return maxThreadIdUsed + 1;
}




//---------------------------------------------------------------------------
// One evolution of the PDE
//
//
//  Inputs
//    bnd[]
//    u[current]
//    inputImage
//    flag
//
//  Outputs
//    u[1-current]
//    current        : swapped
//
//  Calls
//
//    DistanceMap()  : if the surface touches the bb limit
//    MakeBand()     : if the surface touches the bb limit
//
//
void vtkLevelSets::Evolve3D( int first_band, int last_band)
//                   --------
{
    int   b;
    int   p;

    // here used iterator
    register float_vec_it U    = this->u[current].begin();
    register float_vec_it Up;
    register float_vec_it newU = this->u[1-current].begin();

    float* im = ((float*) this->inputImage->GetScalarPointer());

    register short i,j,k;
    register double u0,upx,upy,upz,umx,umy,umz;
    register double D0x,D0y,D0z;
    register double i0x,i0y,i0z;
    register double delta0,sqrtdelta0;
    register double imx,imy,imz;
    register double D0xy=0,D0yz=0,D0zx=0;
    register double normcompsq;
    register double D_x,Dx,D_y,Dy,D_z,Dz;
    register double Dpmx=0;
    register double Dpmy=0;
    register double Dpmz=0;
    //    register double dxy2, dyz2, dxz2;
    register double dxy, dyz, dxz;
    register double meancurv_grad;
    register double gausscurv_grad2;
    register double smallercurv_grad;
    register double biggercurv_grad;
    double discriminant=0, dxsq=0,dysq=0,dzsq=0;
    double imcomp=0,costerm,ut;
    double curvterm;
    double balloonterm;
    double val1,val2,val3,val;

    register int mx,my,mz,px,py,pz;

    double adv;

    double Vx,Vy,Vz;

    double vel;
    double Gx,Gy,Gz,Gnorm,norm_vel;


    //  if (GB_debug) {
    //    fprintf(stderr, ".");
    //    fflush(stderr);
    //  }


  mx = -1;   px = 1;
  my = -tx;  py = tx;
  mz = -txy; pz = txy;

  for (b=first_band;b<=last_band;b++){

    p = this->bnd[b];

    // Try to avoid this part by not putting in the narrow band the
    // voxels of the border ...

    //ExtractCoords(p,i,j,k);
    //// need (i,j,k) only for checking limits ...
    //if (i==0)    mx =  1;   else mx = -1;
    //if (i==tx-1) px = -1;   else px =  1;
    //if (j==0)    my =  tx;  else my = -tx;
    //if (j==ty-1) py = -tx;  else py =  tx;
    //if (k==0)    mz =  txy; else mz = -txy;
    //if (k==tz-1) pz = -txy; else pz =  txy;

    // First order derivatives
    Up = U+p;
    u0=*Up;
    umx=Up[mx];
    upx=Up[px];
    umy=Up[my];
    upy=Up[py];
    umz=Up[mz];
    upz=Up[pz];


    if (!isotropic_voxels) {
      Dx = (upx-u0)/vx;
      Dy = (upy-u0)/vy;
      Dz = (upz-u0)/vz;

      D_x = (u0-umx)/vx;
      D_y = (u0-umy)/vy;
      D_z = (u0-umz)/vz;

      D0x=(upx-umx)*(doubxspacing);
      D0y=(upy-umy)*(doubyspacing);
      D0z=(upz-umz)*(doubzspacing);

      if (coeff_curvature>0) {
        // Second order derivatives
        Dpmx=(upx-u0-u0+umx)*sqxspacing;
        Dpmy=(upy-u0-u0+umy)*sqyspacing;
        Dpmz=(upz-u0-u0+umz)*sqzspacing;

        // Crossed derivatives
        D0xy=(Up[px+py]+Up[mx+my]-Up[px+my]-Up[mx+py])*xyspacing;
        D0yz=(Up[py+pz]+Up[my+mz]-Up[py+mz]-Up[my+pz])*yzspacing;
        D0zx=(Up[pz+px]+Up[mz+mx]-Up[pz+mx]-Up[mz+px])*xzspacing;
      }

      //
      dxsq = D0x*D0x;
      dysq = D0y*D0y;
      dzsq = D0z*D0z;

      //dxy2 = 2*D0x*D0y;
      //dxz2 = 2*D0x*D0z;
      //dyz2 = 2*D0z*D0y;
      dxy = D0x*D0y;
      dxz = D0x*D0z;
      dyz = D0z*D0y;

      delta0=dxsq+dysq+dzsq;
    }
    else {
      // isotropic voxels
      Dx = upx-u0;
      Dy = upy-u0;
      Dz = upz-u0;

      D_x = u0-umx;
      D_y = u0-umy;
      D_z = u0-umz;

      // divide by 2 later
      D0x= (upx-umx)/2;  // /2
      D0y= (upy-umy)/2;  // /2
      D0z= (upz-umz)/2;  // /2

      if (coeff_curvature>0) {
        // Second order derivatives
        Dpmx=upx-u0-u0+umx;
        Dpmy=upy-u0-u0+umy;
        Dpmz=upz-u0-u0+umz;

        // Crossed derivatives
        // divide by 4 later
        D0xy=(Up[px+py]+Up[mx+my]-Up[px+my]-Up[mx+py])/4;  // /4
        D0yz=(Up[py+pz]+Up[my+mz]-Up[py+mz]-Up[my+pz])/4;  // /4
        D0zx=(Up[pz+px]+Up[mz+mx]-Up[pz+mx]-Up[mz+px])/4;  // /4
      }

      //
      dxsq = D0x*D0x;  // /4
      dysq = D0y*D0y;  // /4
      dzsq = D0z*D0z;  // /4

      // multiply by 2 later
      //dxy2 = 2*D0x*D0y; // /2
      //dxz2 = 2*D0x*D0z; // /2
      //dyz2 = 2*D0z*D0y; // /2
      dxy = D0x*D0y; // /2
      dxz = D0x*D0z; // /2
      dyz = D0z*D0y; // /2

      delta0=dxsq+dysq+dzsq;   // (/4)
    }

    //--------------------------------------------------
    // Curvature Term
    //--------------------------------------------------

    curvterm = 0;
    if (coeff_curvature>0) {

      //    if (delta0!=0)
      if (delta0>SquaredGradientEpsilon) {
        meancurv_grad =  ( 0.5*(  (Dpmy+Dpmz)*dxsq
                                  +(Dpmx+Dpmz)*dysq
                                  +(Dpmx+Dpmy)*dzsq
                                  )
                              -( dxy*D0xy
                                  +dxz*D0zx
                                  +dyz*D0yz)
                              ) /delta0;

        if (!DoMean) {
          gausscurv_grad2 = (2*(dxy*(D0zx*D0yz-D0xy*Dpmz) +
                  dyz*(D0zx*D0xy-D0yz*Dpmx) +
                  dxz*(D0yz*D0xy-D0zx*Dpmy)
                  ) +
                   dxsq*(Dpmy*Dpmz-D0yz*D0yz) +
                   dysq*(Dpmx*Dpmz-D0zx*D0zx) +
                   dzsq*(Dpmy*Dpmx-D0xy*D0xy))/delta0;

          discriminant = meancurv_grad*meancurv_grad-gausscurv_grad2;
          if (discriminant<0) discriminant=0;
          discriminant = sqrt(discriminant);
          smallercurv_grad  = meancurv_grad-discriminant;
          biggercurv_grad   = meancurv_grad+discriminant;
        }

        if (DoMean) curvterm = meancurv_grad   ;
        // should it be the minimal in absolute value ???
        else        curvterm = smallercurv_grad;

      // limit the curvature in high values
#define MAX_CURV_ABS 3
        if (curvterm> MAX_CURV_ABS) curvterm= MAX_CURV_ABS;
        if (curvterm<-MAX_CURV_ABS) curvterm=-MAX_CURV_ABS;
        curvterm *= coeff_curvature;

        this->mean_curv      += curvterm;
      } else {
        if (GetDebug()) {
          ExtractCoords(p,i,j,k);
          std::cerr << "*** Squared gradient too low: " 
                    << delta0
                    << ", at position "
                    << "( " << i << ", " << j << ", " << k << " ) "
                    << std::endl;
        }
      }
    } // coeff_curvature >0
    if (curvature_weight != NULL) curvterm *= curvature_weight[p];
    ut = curvterm;

    //--------------------------------------------------
    // Data Attachment Term
    //--------------------------------------------------

    imcomp = 0;
    if (fabs(AdvectionCoeff)>1E-10) {

      // BELOW IS WHAT WAS USED FOR IPMI PAPER
      if (UseCosTerm) {
        if (!isotropic_voxels) {
          i0x=(im[p+px]-im[p+mx])*(doubxspacing);
          i0y=(im[p+py]-im[p+my])*(doubyspacing);
          i0z=(im[p+pz]-im[p+mz])*(doubzspacing);
          normcompsq = (i0x*i0x+i0y*i0y+i0z*i0z);
        }
        else {
          i0x=(im[p+px]-im[p+mx])/2;  // /2
          i0y=(im[p+py]-im[p+my])/2;  // /2
          i0z=(im[p+pz]-im[p+mz])/2;  // /2
          normcompsq = i0x*i0x+i0y*i0y+i0z*i0z;  // /4
        }
        sqrtdelta0 = sqrt(delta0); // (/2)
        costerm = -(D0x*i0x+D0y*i0y+D0z*i0z)/(sqrtdelta0*sqrt(normcompsq));
      }
      else
       costerm = 1;

      // recall that image is rescaled to 0-255 when loaded.
      //
      // Where does the 'costerm' comes from ?
      // it should be: - H.DI.Du / |Du| / |DI|
      //

      switch (advection_scheme) {
      case ADVECTION_UPWIND_VECTORS:
        // Use upwind differences for advection term :
        imx = data_attach_x[p];
        imy = data_attach_y[p];
        imz = data_attach_z[p];
        adv = 0;
        if (costerm>0) {
          if (imx>0) adv += imx*D_x;  else   adv += imx*Dx;
          if (imy>0) adv += imy*D_y;  else   adv += imy*Dy;
          if (imz>0) adv += imz*D_z;  else   adv += imz*Dz;
        } else {
          if (imx>0) adv += imx*Dx;  else   adv += imx*D_x;
          if (imy>0) adv += imy*Dy;  else   adv += imy*D_y;
          if (imz>0) adv += imz*Dz;  else   adv += imz*D_z;
        }
        imcomp = adv*AdvectionCoeff*costerm;
        break;
      case ADVECTION_CENTRAL_VECTORS:
        imx = data_attach_x[p];
        imy = data_attach_y[p];
        imz = data_attach_z[p];
        adv =  D0x*imx+D0y*imy+D0z*imz;
        //    if (isotropic_voxels) adv/=2;
        imcomp = adv*AdvectionCoeff*costerm;
        break;
      case ADVECTION_MORPHO:
        if (secdergrad[p]*AdvectionCoeff<0) {
          Gx = Gy = Gz = 0;
          if (D_x>=0) Gx = D_x;
          if ((Dx<0)&&(-Dx>Gx)) Gx = Dx;
          if (D_y>=0) Gy = D_y;
          if ((Dy<0)&&(-Dy>Gy)) Gy = Dy;
          if (D_z>=0) Gz = D_z;
          if ((Dz<0)&&(-Dz>Gz)) Gz = Dz;
        }
        else {
          Gx = Gy = Gz = 0;
          if (D_x<=0) Gx = D_x;
          if ((Dx>0)&&(Dx>-Gx)) Gx = Dx;
          if (D_y<=0) Gy = D_y;
          if ((Dy>0)&&(Dy>-Gy)) Gy = Dy;
          if (D_z<=0) Gz = D_z;
          if ((Dz>0)&&(Dz>-Gz)) Gz = Dz;
        }
        Gnorm = sqrt(Gx*Gx+Gy*Gy+Gz*Gz);
        imcomp = -Gnorm*secdergrad[p];
        imcomp *= AdvectionCoeff;
        break;
      } // end switch

      this->mean_advection += imcomp;
    } //  fabsf(AdvectionCoeff)>1E-10
    ut -= imcomp;
      //      g = exp(-sqrt(normcompsq)/0.3);

    //--------------------------------------------------
    // Balloon expansion Term
    //--------------------------------------------------

    balloonterm = 0.0;
    if (fabs(balloon_coeff)>1E-10) {

      if (balloon_image != NULL)
    balloonterm = balloon_coeff*((float*)balloon_image->GetScalarPointer())[p];
      else
    balloonterm = balloon_coeff* this->ExpansionMap(im[p]);
    }

    // bug fixed, replaced balloon_coeff by balloonterm:
    //  in case of an balloon_image, the balloon_coeff is 0 ...

    // try another scheme ...
    switch (this->balloon_scheme) {
    case BALLOON_BROCKETT_MARAGOS:
      if (fabs(balloonterm)>1E-10) {
    if (balloonterm>0) {
      Gx = Gy = Gz = 0;
      if (D_x>=0) Gx = D_x;
      if ((Dx<0)&&(-Dx>Gx)) Gx = Dx;
          if (D_y>=0) Gy = D_y;
      if ((Dy<0)&&(-Dy>Gy)) Gy = Dy;
          if (D_z>=0) Gz = D_z;
      if ((Dz<0)&&(-Dz>Gz)) Gz = Dz;
        }
        else {
          Gx = Gy = Gz = 0;
      if (D_x<=0) Gx = D_x;
      if ((Dx>0)&&(Dx>-Gx)) Gx = Dx;
      if (D_y<=0) Gy = D_y;
      if ((Dy>0)&&(Dy>-Gy)) Gy = Dy;
      if (D_z<=0) Gz = D_z;
      if ((Dz>0)&&(Dz>-Gz)) Gz = Dz;
    }
        balloonterm *= sqrt(Gx*Gx+Gy*Gy+Gz*Gz);
        this->mean_balloon   += balloonterm;
      }
      break;
    case BALLOON_VESSELS:
      if (fabs(balloonterm)>1E-10) {
        if (balloonterm>0) {
          // get the minimum of the neighborhood
          val = u0;
          if (Up[px]<val) val=Up[px];
          if (Up[mx]<val) val=Up[mx];
          if (Up[py]<val) val=Up[py];
          if (Up[my]<val) val=Up[my];
          if (Up[pz]<val) val=Up[pz];
          if (Up[mz]<val) val=Up[mz];
          val1 = u0-val;

          // 2D diagonals
          val = u0;
          if (Up[px+py]<val) val=Up[px+py];
          if (Up[px+my]<val) val=Up[px+my];
          if (Up[mx+py]<val) val=Up[mx+py];
          if (Up[mx+my]<val) val=Up[mx+my];

          if (Up[px+pz]<val) val=Up[px+pz];
          if (Up[px+mz]<val) val=Up[px+mz];
          if (Up[mx+pz]<val) val=Up[mx+pz];
          if (Up[mx+mz]<val) val=Up[mx+pz];

          if (Up[py+pz]<val) val=Up[py+pz];
          if (Up[py+mz]<val) val=Up[py+mz];
          if (Up[my+pz]<val) val=Up[my+pz];
          if (Up[my+mz]<val) val=Up[my+pz];
          val2 = (u0-val)/sqrt(2.0);

          // 3D diagonals
          val = u0;
          if (Up[px+py+pz]<val) val=Up[px+py+pz];
          if (Up[px+py+mz]<val) val=Up[px+py+mz];
          if (Up[px+my+pz]<val) val=Up[px+my+pz];
          if (Up[px+my+mz]<val) val=Up[px+my+mz];

          if (Up[mx+py+pz]<val) val=Up[mx+py+pz];
          if (Up[mx+py+mz]<val) val=Up[mx+py+mz];
          if (Up[mx+my+pz]<val) val=Up[mx+my+pz];
          if (Up[mx+my+mz]<val) val=Up[mx+my+mz];
          val3 = (u0-val)/sqrt(3.0);

          val=val1;
          if (val2>val) val=val2;
          if (val3>val) val=val3;
          balloonterm *= val;
        }
        else {
          // get the maximum of the neighborhood
          val = u0;
          if (Up[px]>val) val=Up[px];
          if (Up[mx]>val) val=Up[mx];
          if (Up[py]>val) val=Up[py];
          if (Up[my]>val) val=Up[my];
          if (Up[pz]>val) val=Up[pz];
          if (Up[mz]>val) val=Up[mz];
          val1 = val-u0;

          // 2D diagonals
          val = u0;
          if (Up[px+py]>val) val=Up[px+py];
          if (Up[px+my]>val) val=Up[px+my];
          if (Up[mx+py]>val) val=Up[mx+py];
          if (Up[mx+my]>val) val=Up[mx+my];

          if (Up[px+pz]>val) val=Up[px+pz];
          if (Up[px+mz]>val) val=Up[px+mz];
          if (Up[mx+pz]>val) val=Up[mx+pz];
          if (Up[mx+mz]>val) val=Up[mx+pz];

          if (Up[py+pz]>val) val=Up[py+pz];
          if (Up[py+mz]>val) val=Up[py+mz];
          if (Up[my+pz]>val) val=Up[my+pz];
          if (Up[my+mz]>val) val=Up[my+pz];
          val2 = (val-u0)/sqrt(2.0);

          // 3D diagonals
          val = u0;
          if (Up[px+py+pz]>val) val=Up[px+py+pz];
          if (Up[px+py+mz]>val) val=Up[px+py+mz];
          if (Up[px+my+pz]>val) val=Up[px+my+pz];
          if (Up[px+my+mz]>val) val=Up[px+my+mz];

          if (Up[mx+py+pz]>val) val=Up[mx+py+pz];
          if (Up[mx+py+mz]>val) val=Up[mx+py+mz];
          if (Up[mx+my+pz]>val) val=Up[mx+my+pz];
          if (Up[mx+my+mz]>val) val=Up[mx+my+mz];
          val3 = (val-u0)/sqrt(3.0);

          val=val1;
          if (val2>val) val=val2;
          if (val3>val) val=val3;
          balloonterm *= val;
        }
        this->mean_balloon   += balloonterm;
        break;
      }
    }
    ut -= balloonterm;


    //--------------------------------------------------
    // Velocity Term
    //--------------------------------------------------

    vel = 0;
    // Compute the velocity term
    if ((velocity != NULL)&&(coeff_velocity>1E-2)) {

      if ((velocity->GetNumberOfScalarComponents()==3)) {

        //    printf("+ ");fflush(stdout);
        // Scheme of Brokett-Maragos
        ExtractCoords(p,i,j,k);
        Vx = velocity->GetScalarComponentAsDouble(i,j,k,0);
        Vy = velocity->GetScalarComponentAsDouble(i,j,k,1);
        Vz = velocity->GetScalarComponentAsDouble(i,j,k,2);

        // Scalar product
        norm_vel = sqrt(Vx*Vx+Vy*Vy+Vz*Vz);
        if (norm_vel>1E-2) {
          //double vel1,vel2;

          // estimate in one direction
          // Always expansion (erosion in our case) ...
          if (Vx>0) Gx = D_x;  else   Gx = Dx;
          if (Vy>0) Gy = D_y;  else   Gy = Dy;
          if (Vz>0) Gz = D_z;  else   Gz = Dz;
          // get absolute value of scalar product ...
          // vector direction does not matter ...
          vel = Vx*Gx+Vy*Gy+Vz*Gz;

          // estimate in the other direction
          Vx = -Vx; Vy=-Vy; Vz=-Vz;

          if (Vx>0) Gx = D_x;  else   Gx = Dx;
          if (Vy>0) Gy = D_y;  else   Gy = Dy;
          if (Vz>0) Gz = D_z;  else   Gz = Dz;
          // get absolute value of scalar product ...
          // vector direction does not matter ...
          vel = max(0,max(vel,Vx*Gx+Vy*Gy+Vz*Gz));

          vel *= coeff_velocity;
        }
        else
          vel = 0;
      }

      this->mean_vel       += vel;

      // Here should it be an additional term or a multiplication???
      switch (velocity_type) {
        case 0: ut -= vel;      break;
        case 1: ut *= fabsf(vel); break;
        default: std::cerr << "velocity type not available " << std::endl;
      }

    }

    //ut -= vel;

    //--------------------------------------------------
    // new intensity
    //--------------------------------------------------

    //      if (isotropic_voxels) sqrtdelta0 /= 2;


    if (curvature_data!=NULL) curvature_data[p] = curvterm*StepDt;
    if (advection_data!=NULL) advection_data[p] = -imcomp*StepDt;
    if (velocity_data !=NULL) velocity_data [p] = -vel*StepDt;
    if (balloon_data  !=NULL) balloon_data  [p] = -balloonterm*StepDt;


    //ut = min(max(StepDt*ut,-Band),Band);
    newU[p]=u0+StepDt*ut;
    if ((fabs(newU[p])>Band+1)&&(verbose)) {
      fprintf(stderr,"pb: absf(newU[p])>Band+1, p=%d, newU[p] = %f \n",p,newU[p]);
      fprintf(stderr,"pb: curvterm = %f, imcomp = %f, balloonterm = %f, vel = %f, \n",curvterm, imcomp,balloonterm, vel);
    }
    newU[p] = min(max(newU[p],-Band-1),Band+1);

      /*
    }
    else {
      if (curvature_data!=NULL) curvature_data[p] = 0;
      if (advection_data!=NULL) advection_data[p] = 0;
      if (velocity_data!=NULL)  velocity_data [p] = 0;
      if (balloon_data !=NULL)  balloon_data  [p] = 0;
      newU[p]=u0;
    }
      */

    if (!this->touched &&
        (((this->flag[p]&NEGMINE) && newU[p]>0) ||
         ((this->flag[p]&POSMINE) && newU[p]<0)
        )
       )
      this->touched=1;
  }

  /*
  mean_curv      /= (last_band-first_band+1);
  mean_balloon   /= (last_band-first_band+1);
  mean_advection /= (last_band-first_band+1);
  mean_vel       /= (last_band-first_band+1);

  fprintf(stderr,"Evolve3D()\n");
  fprintf(stderr," MEAN curv      = %2.2f\n",mean_curv);
  fprintf(stderr," MEAN advection = %2.2f\n",mean_advection);
  fprintf(stderr," MEAN balloon   = %2.2f\n",mean_balloon);
  fprintf(stderr," MEAN velocity  = %2.2f\n",mean_vel);
  */


  //   if (GB_debug) fprintf(stderr, ";\n");

} // Evolve3D()


//------------------------------------------------------------------
void vtkLevelSets::InitEvolution()
{

  float *inPtr;
  float *outPtr;
  // Rescale parameters
  vtkFloatingPointType vs[3];
  float th;
  //     float mean,sd;

  if ( verbose ) {
    fprintf ( stderr, "vtkLevelSets::InitEvolution() \n" );
    this->PrintParameters();
  }

  this->inputImage->GetSpacing ( vs );
  vx = vs[0];
  vy = vs[1];
  vz = vs[2];

  if ( !isotropic_voxels ) isotropic_voxels = ( ( vx == vy ) && ( vx == vz ) );

  if ( ( isotropic_voxels ) && ( verbose ) )
    fprintf ( stderr, "ISOTROPIC VOXELS \n" );

  // First estimation of output is a threshold segmentation

  if ( ( this->UseLowThreshold ) || ( this->UseHighThreshold ) ) {
    inPtr  = ( float* ) inputImage ->GetScalarPointer();
    for ( vector_size i = 0; i < imsize; i++ ) {
      if ( ( UseLowThreshold ) && ( inPtr[i] < LowThreshold ) ) inPtr[i] = LowThreshold;

      if ( ( UseHighThreshold ) && ( inPtr[i] > HighThreshold ) )
        inPtr[i] = HighThreshold + log ( 1 + inPtr[i] - HighThreshold );
    }
  }

  // Rescaling the image to 0 - 255
  inPtr  = ( float* ) inputImage ->GetScalarPointer();
  outPtr = ( float* ) outputImage->GetScalarPointer();
  if ( this->RescaleImage ) {
    if ( GB_debug ) fprintf ( stderr, "Threshold %f \n", this->InitThreshold );
    maxu = minu = *inPtr;
    inPtr++;
    for ( vector_size i = 1; i < imsize; i++ ) {
      if ( *inPtr > maxu ) maxu = *inPtr;
      if ( *inPtr < minu ) minu = *inPtr;
      inPtr++;
    }
    vtkDebugMacro ( << "Data range after reescaling: " << minu << "," << maxu );
    // we scale to 0-255
    inPtr  = ( float* ) inputImage ->GetScalarPointer();
    for ( vector_size i = 0; i < imsize; i++ ) {
      ( *inPtr ) = ( *inPtr - minu ) * 255.0 / ( maxu - minu );
      inPtr++;
    }
  }

  //
  // Computation of the initial image (initial level set)
  //
  inPtr  = ( float* ) inputImage ->GetScalarPointer();
  outPtr = ( float* ) outputImage->GetScalarPointer();

  fprintf ( stderr, "Threshold %f \n", this->InitThreshold );

  if ( ( this->RescaleImage ) && ( initImage == NULL ) )
    th = ( InitThreshold - minu ) / ( maxu - minu ) * 255.0;
  else
    th = InitThreshold;


  if ( initImage == NULL ) {
    // Check if we have initialization points
    if ( NumInitPoints > 0 ) {
      int   x, y, z, n, r, x0, y0, z0;
      int   xmin, xmax, ymin, ymax, zmin, zmax;
      float d2x, d2y, d2z, dist;
      vector_size p;

      // Initialize the image to Band
      for ( p = 0;p < imsize;p++ ) outPtr[p] = Band + 1;

      // Compute the spheres or disks around the initialization points
      for ( n = 0;n < NumInitPoints;n++ ) {
        x0 = InitPoints[n][0];
        y0 = InitPoints[n][1];
        z0 = InitPoints[n][2];
        r  = InitPoints[n][3];
        xmin = max ( 0, ( int ) ( x0 - ( r + Band + 1 ) / vx - 0.5 ) );
        xmax = min ( tx - 1, ( int ) ( x0 + ( r + Band + 1 ) / vx + 0.5 ) );
        ymin = max ( 0, ( int ) ( y0 - ( r + Band + 1 ) / vy - 0.5 ) );
        ymax = min ( ty - 1, ( int ) ( y0 + ( r + Band + 1 ) / vy + 0.5 ) );
        if ( Dimension > 2 ) {
          zmin = max ( 0, ( int ) ( z0 - ( r + Band + 1 ) / vz - 0.5 ) );
          zmax = min ( tz - 1, ( int ) ( z0 + ( r + Band + 1 ) / vz + 0.5 ) );
        } else zmin = zmax = z0 = 0;

        printf ( "n=%d, [%d,%d] [%d,%d] [%d,%d] \n",
                 n, xmin, xmax, ymin, ymax, zmin, zmax );

        p = zmin * txy;
        for ( z = zmin;z <= zmax;z++ ) {
          d2z = ( z - z0 ) * vz;
          d2z = d2z * d2z;
          p += ymin * tx;
          for ( y = ymin;y <= ymax;y++ ) {
            d2y = ( y - y0 ) * vy;
            d2y = d2y * d2y;
            p += xmin;
            for ( x = xmin;x <= xmax;x++ ) {
              d2x = ( x - x0 ) * vx;
              d2x = d2x * d2x;
              // computes distance to each initial sphere (or disk)
              dist = sqrt ( d2x + d2y + d2z ) - r;
              if ( dist < outPtr[p] )      outPtr[p] = dist;
              if ( outPtr[p] < - ( Band + 1 ) ) outPtr[p] = - ( Band + 1 );
              if ( outPtr[p] > ( Band + 1 ) ) outPtr[p] = Band + 1;
              p++;
            } // end for x
            p += tx - 1 - xmax;
          } // end for y
          p += tx * ( ty - 1 - ymax );
        } // end for z
      } // NumInitPoints
    } else
      // Otherwise use the threshold on the initial image
      switch ( DMmethod ) {
        case DISTMAP_CURVES:
          for ( vector_size i = 0; i < imsize; i++ ) {
            switch ( InitIntensity ) {
              case Bright:
                if ( *inPtr >= th )      *outPtr = VESSEL;
                else                   *outPtr = NOT_VESSEL;
                break;
              case Dark:
                if ( *inPtr <= th )      *outPtr = VESSEL;
                else                   *outPtr = NOT_VESSEL;
                break;
            }
            inPtr++;
            outPtr++;
          }
          break;

        case DISTMAP_FASTMARCHING: // FastMarching initialization
        case DISTMAP_CHAMFER:      // Chamfer initialization
        case DISTMAP_SHAPE:        // Shape levelset initialization
          fprintf ( stderr, "Fast Marching or Chamferevolution \n" );
          for ( vector_size i = 0; i < imsize; i++ ) {
            switch ( InitIntensity ) {
              case Bright: *outPtr = th - *inPtr; break;
              case Dark:   *outPtr = *inPtr - th; break;
            }
            inPtr++;
            outPtr++;
          }
          break;
      }
  } else {
    fprintf ( stderr, " Copy the initial; image !! \n" );
    outputImage->CopyAndCastFrom( initImage,
                                  initImage->GetExtent() );

    //float* inPtr = (float*) initImage->GetScalarPointer();
    outPtr = ( float* ) outputImage->GetScalarPointer();
    for ( vector_size i = 0; i < imsize; i++ ) {
      switch ( InitIntensity ) {
        case Bright: *outPtr = -*outPtr + th; break;
        case Dark:   *outPtr = *outPtr  - th; break;
      }
      outPtr++;
      //inPtr++;
    }
  }

  this->current = 0;
  // don't share memory here: too dangerous,
  // reallocated ...
  float* output_pointer = ( float* ) outputImage->GetScalarPointer();

  // creates vectors of size imsize
  // and copy values from the output image
  this->u[0] = float_vec( output_pointer, output_pointer + imsize );
  this->u[1] = this->u[0];
  /*
    this->u[0]    = (float*) outputImage->GetScalarPointer();
    this->u[1]    = new float [imsize];

    ADDMEMORY("vtkLevelSets::InitEvolution() u[1]",imsize*sizeof(float));

    // copy the initial image to the new image
    // but after the first distance computation
    //memcpy(u[1-current],u[current],imsize*sizeof(float));
  */

  //
  // Set the Balloon Force Parameters
  //
  ComputeProbabilityLUT();

  //
  // Set the Advection Parameters
  //
  if (  ( fabs ( AdvectionCoeff ) > 1E-10 ) &&
        ( data_attach_x.empty()) ) {
    switch ( advection_scheme ) {
      case ADVECTION_UPWIND_VECTORS:
      case ADVECTION_CENTRAL_VECTORS:
        this->data_attach_x.resize(imsize,0);
        this->data_attach_y.resize(imsize,0);
        ADDMEMORY ( "vtkLevelSets::InitEvolution() data_attach_{x,y}", 2*sizeof ( float ) *imsize );
        if ( Dimension == 3 ) {
          this->data_attach_z.resize(imsize,0);
          ADDMEMORY ( "vtkLevelSets::InitEvolution() data_attach_z", sizeof ( float ) *imsize );
        }
        break;
      case ADVECTION_MORPHO:
        this->secdergrad    = new float[imsize];
        this->normgrad      = new float[imsize];
        ADDMEMORY ( "vtkLevelSets::InitEvolution() ADVECTION_MORPHO secdergrad", 2*sizeof ( float ) *imsize );
        break;
    }
  }

  sqxspacing   = 1.0 / vx / vx;
  sqyspacing   = 1.0 / vy / vy;
  doubxspacing = 0.5 / vx;
  doubyspacing = 0.5 / vy;
  xyspacing    = .25 / vx / vy;

  if ( Dimension == 3 ) {
    sqzspacing   = 1.0 / vz / vz;
    doubzspacing = 0.5 / vz;
    yzspacing    = .25 / vy / vz;
    xzspacing    = .25 / vx / vz;
  }


  if (  (fabs (AdvectionCoeff ) > 1E-10 ) &&
        (data_attach_x.empty()) )
    PreComputeDataAttachment();

   std::cout << "InitEvolution DMethod = " << DMmethod << std::endl;

  if ( DMmethod == 0 ) {

    this->MakeBand();
    //
    this->DistanceMap();
    this->MakeBand();

    this->DistanceMap();
    this->MakeBand();

  } else {

   std::cout << "InitEvolution 2.0" << std::endl;
    this->DistanceMap();

    VTK_CLASS_MESSAGE( "copy");
    // copy the initial image to the new image
    // after the first distance computation
    // to have correct minimal and maximal values:
    // after we will only work in the narrow band
    copy (
      u[current].begin(),
      u[current].end(),
      u[1-current].begin()
    );

    VTK_CLASS_MESSAGE( "make band");
    this->MakeBand();
    VTK_CLASS_MESSAGE(" 2.2" );
  }

  step       = 0;
  reinitcntr = 0;

  VTK_CLASS_MESSAGE("End" );

} // InitEvolution()



//----------------------------------------------------------------------------
int vtkLevelSets::Iterate()
{

  //  if (step>=NumIters) return 0;

  if (GB_debug) {
    fprintf(stderr,"\n ==== \n\t Execute Step %d \n",step);
     }
  else {
    if (verbose) {
      printf("\b\b\b\b");
      printf("%4d",step);
      fflush(stdout);
    }
  }

  if ((step >0) &&(step % CheckFreq == 0)) {
    // convergence check more stable if just do a new DistanceMap
    if (reinitcntr > 0) {
      this->DistanceMap();
      this->MakeBand();
      reinitcntr=0;
    }

    // at the original code this comparison is with conv_rep, that
    // by default is 1.
    if (CheckConvergence()) {
      vtkGenericWarningMacro("Method has converged after " << step << " steps, stopping\n");
      step = NumIters; // finish the evolution
    }
  } // end if

  if (reinitcntr==ReinitFreq) {
    this->DistanceMap();
    this->MakeBand();
    reinitcntr=0;
  }

 // Evolve one iteration
  this->Evolve( );

  step++;
  return 1; //(step<NumIters);

} // Iterate()


//----------------------------------------------------------------------------
void vtkLevelSets::EndEvolution()
{

  float  th;
  float* outPtr;

  fprintf(stderr,"Threshold %f \n", this->InitThreshold);

  th = InitThreshold;

  // Compute the distance map to the isosurface 0
  DistanceMap();

  // Multiply the image by -1
  outPtr = (float*) outputImage->GetScalarPointer();
  for (vector_size i=0; i<imsize; i++) {
    *outPtr *= -100;
    outPtr++;
  }

  //
  if (Probability!= NULL) {
    delete [] Probability;
    Probability = NULL;
  }

  data_attach_x.clear();
  data_attach_y.clear();
  data_attach_z.clear();

  if (secdergrad != NULL) {
    delete [] this->secdergrad;
    secdergrad = NULL;
  }

  if (normgrad != NULL) {
    delete [] this->normgrad;
    normgrad = NULL;
  }

} // EndEvolution()



//----------------------------------------------------------------------------
void vtkLevelSets::PreComputeDataAttachment()
{

    int x,y,z,p;
    int mx,my,mz,px,py,pz;
    float ipmx;
    float ipmy;
    float ipmz;
    float i0xy,i0yz,i0zx,i0;
    float i0x,i0y,i0z=0;
    register float upx,upy,upz,umx,umy,umz;
    float gradnorm=0;
    float DAx=0,DAy=0,DAz=0;
    float* im   = (float*) this->inputImage->GetScalarPointer();;
    //    int imsize;

    float norm=0, maxnorm;

  if (GB_debug) fprintf(stderr,"PreComputeDataAttachment() \n");

  this->SetProgressText("Precompute Data Attachement");

  p       = 0;
  maxnorm = 0;

  for(z=0;z<tz;z++) {
  this->UpdateProgress(p*1.0/this->imsize);
  for(y=0;y<ty;y++) {
  for(x=0;x<tx;x++) {


    if (x==0)    mx =  1;   else mx = -1;
    if (x==tx-1) px = -1;   else px =  1;
    if (y==0)    my =  tx;  else my = -tx;
    if (y==ty-1) py = -tx;  else py =  tx;

    // derivative in XY plane, for 2D level sets
    i0=im[p];
    umx=im[p+mx];
    upx=im[p+px];
    umy=im[p+my];
    upy=im[p+py];

    i0x=(upx-umx)*(doubxspacing);
    i0y=(upy-umy)*(doubyspacing);

    ipmx=(upx-2*i0+umx)*sqxspacing;
    ipmy=(upy-2*i0+umy)*sqyspacing;

    // 2D Crossed derivatives
    i0xy=(im[p+px+py]+im[p+mx+my]-im[p+px+my]-im[p+mx+py])*xyspacing;

    //   if (p%100000 ==0) printf("Dimension = %d\n",Dimension);

    switch (Dimension) {
    case 2:
      gradnorm = sqrt(i0x*i0x+i0y*i0y);
      if (gradnorm>EPSILON) {
    i0x /= gradnorm;
    i0y /= gradnorm;

    DAx = (ipmx*i0x+i0xy*i0y);
    DAy = (i0xy*i0x+ipmy*i0y);

    norm =  DAx*DAx+DAy*DAy;
    if (norm>maxnorm) maxnorm = norm;
      }
      else {
    i0x=i0y=DAx=DAy=norm=0;
      }

      break;
    case 3:
      if (z==0)    mz =  txy; else mz = -txy;
      if (z==tz-1) pz = -txy; else pz =  txy;

      umz=im[p+mz];
      upz=im[p+pz];

      i0z=(upz-umz)*(doubzspacing);

      ipmz=(upz-2*i0+umz)*sqzspacing;

      // 3D Crossed derivatives
      i0yz=(im[p+py+pz]+im[p+my+mz]-im[p+py+mz]-im[p+my+pz])*yzspacing;
      i0zx=(im[p+pz+px]+im[p+mz+mx]-im[p+pz+mx]-im[p+mz+px])*xzspacing;

      gradnorm = sqrt(i0x*i0x+i0y*i0y+i0z*i0z);
      if (gradnorm>EPSILON) {
    i0x /= gradnorm;
    i0y /= gradnorm;
    i0z /= gradnorm;

    DAx = (ipmx*i0x+i0xy*i0y+i0zx*i0z);
    DAy = (i0xy*i0x+ipmy*i0y+i0yz*i0z);
    DAz = (i0zx*i0x+i0yz*i0y+ipmz*i0z);

    norm =  DAx*DAx+DAy*DAy+DAz*DAz;
    if (norm>maxnorm) maxnorm = norm;
      }
      else {
    i0x=i0y=i0z=0;
    DAx=DAy=DAz=norm=0;
      }


      break;
    }

    //    if (p%100000 ==0) printf("scheme = %d\n",advection_scheme);
    //    if (p%100000 ==0) printf("norm = %f\n",norm);
    switch (advection_scheme) {
    case ADVECTION_UPWIND_VECTORS:
    case ADVECTION_CENTRAL_VECTORS:
      if (gradnorm<=EPSILON)
    data_attach_x[p] = 0;
    data_attach_y[p] = 0;
        if (Dimension==3) data_attach_z[p] = 0;
      else
    {
      data_attach_x[p] = DAx;
      data_attach_y[p] = DAy;
      if (Dimension==3) data_attach_z[p] = DAz;
    }
      break;
    case ADVECTION_MORPHO:
      if (gradnorm<=EPSILON)
    secdergrad[p] = normgrad[p] = 0;
      else
    {
      secdergrad[p] = i0x*DAx+i0y*DAy;
      if (Dimension==3) secdergrad[p] += i0z*DAz;

      if (!((secdergrad[p]>-1E5)&&(secdergrad[p]<1E5))) {
        fprintf(stderr,"PreComputeDataAttachment() \t secdergrad(%d,%d,%d) = %f \n",x,y,z,secdergrad[p]);
      }
      normgrad[p]   = sqrt(norm);
    }
      break;
    } // end switch

    //    if (p%100000 ==0) printf("normgrad[%5d] = %f \n",p,normgrad[p]);

    p++;

  } // x
  } // y
  } // z

  printf(" Max norm of precomputed data attachment vector field : %f \n", sqrt(maxnorm));

  max_normgrad = sqrt(maxnorm);

 std::cout << "PreComputeDataAttachment 1" << std::endl;
  if (advection_scheme == ADVECTION_MORPHO) {
    NormalizeSecDerGrad();
    delete [] this->normgrad;
    this->normgrad=NULL;
    ADDMEMORY("vtkLevelSets::PreComputeDataAttachment()  delete normgrad",-1.0*sizeof(float)*this->imsize);
  }

 std::cout << "PreComputeDataAttachment 2" << std::endl;
  //
  // Save secdergrad
  //

  if (savesecdergrad)  {
   std::cout << "PreComputeDataAttachment savesecdergrad" << std::endl;

    vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
    vtkImageData* copyImage = vtkImageData::New();
    float* ptr;
    char name[255];

    vtkImageData::SetScalarType( VTK_FLOAT, copyImage->GetInformation());
    vtkImageData::SetNumberOfScalarComponents(1, copyImage->GetInformation());
    copyImage->SetDimensions( outputImage->GetDimensions());
    copyImage->SetOrigin(     outputImage->GetOrigin());
    copyImage->SetSpacing(    outputImage->GetSpacing());

    copyImage->AllocateScalars(copyImage->GetInformation());

    ptr = (float*) copyImage->GetScalarPointer();
    for(vector_size i=0;i<this->imsize;i++) {
      *ptr = secdergrad[i];
      ptr++;
    }

    writer->SetInputData(copyImage);
    sprintf(name,"SecDerGrad.vtk");
    writer->SetFileName(name);
    writer->SetFileTypeToBinary();
    writer->Write();
    copyImage->Delete();
    writer->Delete();
  }

 std::cout << "PreComputeDataAttachment 3" << std::endl;

} // PreComputeDataAttachment()


//----------------------------------------------------------------------------
void vtkLevelSets::NormalizeSecDerGrad()
{
  float*         tmp;
  float*         tmp_buf;
  float*         sdg_buf;
  float          val0_new,val1_new;
  int            displace[3];  // displacement for the 5 neighbors
  int            sign, neigh_sign;
  float          val0,val1,diff;
  unsigned char  grad_computed;
  float          norm=0;
  float          Grad[3];
  register int   x,y,z;
  int            n,p;
  float          val;
  vtkFloatingPointType          vs[3];
  unsigned long  cumul_histo;
  float          threshold;
  int*           histo;
  int            histosize;
  int            zmin=0,zmax=0,nmax=0;


  this->SetProgressText("Normalize 2nd Deriv Gradient");

  // tmp: for compute the distance to the second order derivatives
  tmp = new float[this->imsize];

  //  fprintf(stderr,"%4.2f \n",(1.0*sizeof(float)*this->imsize));
  ADDMEMORY("vtkLevelSets::NormalizeSecDerGrad() tmp",(1.0*sizeof(float)*this->imsize));

  // Put the result in the time image
  sdg_buf = secdergrad;

  for(vector_size pos=0;pos<this->imsize;pos++)
    if (secdergrad[pos]>0)
      tmp[pos] = 1;
    else
      tmp[pos] = -1;


  displace[0] = 1;
  displace[1] = tx;
  displace[2] = txy;
  this->inputImage->GetSpacing(vs);

  switch (Dimension) {
  case 2:
    zmin = zmax = SliceNum;
    nmax = 1;
    break;
  case 3:
    zmin = 0;
    zmax = tz-2;
    nmax = 2;
    break;
  }

  // Compute the distance approximation close to the surface
  // Should call vtkImageIsoContourDist ...
  p=0;
  for(z=zmin;z<=zmax;z++) {
    this->UpdateProgress(p*1.0/this->imsize);
  for(y=0;y<=ty-2;y++) {
    sdg_buf   = secdergrad+y*tx;
    tmp_buf   = tmp       +y*tx;
    if (Dimension==3) {
      sdg_buf += z*txy;
      tmp_buf += z*txy;
    }
    for(x=0;x<=tx-2;x++) {

      val0 =  *sdg_buf;
      sign = (val0>0);

      grad_computed = 0;

      for(n=0;n<=nmax;n++) {

    val1 = *(sdg_buf+displace[n]);
    neigh_sign =  (val1>0);

    if (sign != neigh_sign) {

      if (!grad_computed) {
        // gradient estimation
        Grad[0] = (*(sdg_buf+1)    - *sdg_buf)/vs[0];
        Grad[1] = (*(sdg_buf+tx)   - *sdg_buf)/vs[1];

        norm = Grad[0]*Grad[0]+Grad[1]*Grad[1];

        if (Dimension==3) {
          Grad[2] = (*(sdg_buf+txy)  - *sdg_buf)/vs[2];
          norm += Grad[2]*Grad[2];
        }

        // Normalization
        norm = sqrt(norm);
        grad_computed = 1;
      }

      if (sign)
        diff = val0-val1;
      else
        diff = val1-val0;

      if (diff<EPSILON) {
        //        fprintf(stderr,
        //            " %d %d %d %d  diff = %f : val0 %f val1 %f vs[n] %f diff<1-5 \n",
        //            x,y,z,n,diff,val0,val1,vs[n]);
        continue;
      }

      val = fabs(Grad[n])*vs[n]/diff/norm;

      if (norm>EPSILON) {
        val0_new = val0*val;
        val1_new = val1*val;


          if (fabs(val0_new)<fabs(*tmp_buf))
          *tmp_buf = val0_new;

        if (fabs(val1_new)<fabs(*(tmp_buf+displace[n])))
          *(tmp_buf+displace[n]) = val1_new;
      }
      else
        fprintf(stderr, " %d %d %d norm=%f \n",x,y,z,norm);

    } // if (sign != neigh_sign)
      } // n

      sdg_buf++;
      tmp_buf++;
      p++;

    } // x
  }
  } // y,z


  // Copy tmp to secdergrad
  for(vector_size p=0;p<this->imsize;p++) secdergrad[p]=tmp[p];

  histosize = 10000;
  histo = new int[histosize];
  for(n=0;n<histosize;n++) histo[n] = 0;

  // histogram
  for(vector_size p=0;p<this->imsize;p++)
    histo[(int) (normgrad[p]/(max_normgrad+1E-5)*histosize)]++;

  // compute "HistoGradThreshold*100%" of cumulative histogram
  cumul_histo = 0;
  n = 0;
  while (cumul_histo<HistoGradThreshold*this->imsize) {
    cumul_histo += histo[n];
    n++;
  }

  threshold = max_normgrad/histosize*(n-0.5);
  printf("NormalizeSecDerGrad() maxnorm %.2f threshold %.2f +/- %.2f \n",
     max_normgrad,threshold,max_normgrad/histosize);

 std::cout << "1" << std::endl;

  for(vector_size p=0;p<this->imsize;p++) {
    if (normgrad[p]>EPSILON)
      secdergrad[p] *= 1-exp(-normgrad[p]*normgrad[p]/threshold/threshold);
    else
      secdergrad[p]=0;
    if (!((secdergrad[p]>-1E5)&&(secdergrad[p]<1E5))) {
    fprintf(stderr,
            "NormalizeSecDerGrad() \t secdergrad[%d] = %f \n",
            (int)p,
            secdergrad[p]
            );
    }

  }

  delete [] histo;
  delete [] tmp;
  ADDMEMORY("vtkLevelSets::NormalizeSecDerGrad() tmp",-1.0*sizeof(float)*this->imsize);

 std::cout << "end NormalizeSecDerGrad()" << std::endl;

} // NormalizeSecDerGrad()


//----------------------------------------------------------------------------
// This method is passed  input and output data, and executes the filter
// algorithm to fill the output from the input.
// It just executes a switch statement to call the correct function for
// the data types.
void vtkLevelSets::ExecuteData( vtkDataObject *outData)
//                   -------
{


  if (GB_debug) fprintf(stderr,"Execute begin \n");

  InitParam( this->GetImageDataInput(0), (vtkImageData*) outData);
  InitEvolution();
  while (Iterate());
  EndEvolution();

} // Execute()


//----------------------------------------------------------------------
//
// Updates the resulting image so that it contains the current result
//
int vtkLevelSets::UpdateResult(){

  // now always copy
  copy( u[current].begin(),
        u[current].end(),
        (float*) outputImage->GetScalarPointer());

/*
  if ((float*) u[this->current].get() != (float*) outputImage->GetScalarPointer())
    {
      if (verbose)
       std::cout << "Updating result ... " << 1-current <<"\n" ;
        memcpy(
              u[1-current].get(),
              u[current].get(),
              this->imsize*sizeof(float));
      return 1;
    }
*/
  return 0;

} // UpdateResult()


/*
//----------------------------------------------------------------------
// Compute mean and standard deviation of the intensity
// within the initial spheres or disks
//
float *vtkLevelSets::GetInitPointsStatistics()
{

  float* res;

  res=new float[2];
  this->InitPointsStatistics(res);

  return res;
}
*/

//----------------------------------------------------------------------
// Compute mean and standard deviation of the intensity
// within the initial spheres or disks
//
void vtkLevelSets::InitPointsStatistics( float stats[2])
{

  int i;
  int x0,y0,z0,r;
  int x,y,z;
  int totalpoints;
  double mean,sd,d;

  if (this->inputImage==NULL)
    {
      stats[0]=stats[1]=0;
      return;
    }

  mean=0;
  totalpoints=0;

  // compute mean
  for(i=0;i<NumInitPoints;i++) {
    x0 = InitPoints[i][0];
    y0 = InitPoints[i][1];
    z0 = InitPoints[i][2];
    r  = InitPoints[i][3];
    for (x=x0-r; x<=x0+r; x++) {
      if ((x<0)||(x>tx-1)) continue;
      for (y=y0-r; y<=y0+r; y++) {
    if ((y<0)||(y>ty-1)) continue;
    for (z=z0-r; z<=z0+r; z++) {
      if ((z<0)||(z>tz-1)) continue;

#if (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION >= 3)
      mean += this->inputImage->GetScalarComponentAsDouble(x,y,z,0);
#else
      mean += this->inputImage->GetScalarComponentAsFloat(x,y,z,0);
#endif
      totalpoints++;
    }
      }
    }
  }

  mean /= totalpoints;
  sd = 0;

  // compute standard deviation
  for(i=0;i<NumInitPoints;i++) {
    x0 = InitPoints[i][0];
    y0 = InitPoints[i][1];
    z0 = InitPoints[i][2];
    r  = InitPoints[i][3];
    for (x=x0-r; x<=x0+r; x++) {
      if ((x<0)||(x>tx-1)) continue;
      for (y=y0-r; y<=y0+r; y++) {
    if ((y<0)||(y>ty-1)) continue;
    for (z=z0-r; z<=z0+r; z++) {
      if ((z<0)||(z>tz-1)) continue;
#if (VTK_MAJOR_VERSION == 4 && VTK_MINOR_VERSION >= 3)
      d = this->inputImage->GetScalarComponentAsDouble(x,y,z,0)-mean;
#else
      d = this->inputImage->GetScalarComponentAsFloat(x,y,z,0)-mean;
#endif
      sd += d*d;
    }
      }
    }
  }

  sd = sqrt(sd/totalpoints);

  stats[0]=mean;
  stats[1]=sd;


} // InitPointsStatistics()


//----------------------------------------------------------------------
// Precompute the probability Lookup Table is the image
// was rescaled to [0,255]
void vtkLevelSets::ComputeProbabilityLUT()
{
  int i;

  if (this->NumGaussians!=0) {
    // Computes a lookup table for the balloon force
    if (this->RescaleImage) {
      this->Probability = new float[2551];
      for(i=0;i<2551;i++) {
        // force the computation of the probability by setting the 2nd param to 1
        this->Probability[i] = this->ExpansionMap(i/2550.0*(this->maxu-this->minu)+this->minu,1);
      }
    }

  }

} // ComputeProbabilityLUT()


//----------------------------------------------------------------------
//
// Return the expansion coefficient based on the
// probability of having the given intensity
//
//
float vtkLevelSets::ExpansionMap( float I, unsigned char compute)
{
  int n;
  double tmp,res;

  if ((Probability!=NULL)&&(!compute))
    // Image has been rescale to [0,255]
    return Probability[(int) I*10];

  if (NumGaussians>0) {
    if (ProbabilityHighThreshold!=0)
      if (I>ProbabilityHighThreshold) return 1;
    res = 0;
    for(n=0;n<NumGaussians;n++) {
      tmp = I-Gaussians[n][0];
      res += exp(-tmp*tmp/2.0/Gaussians[n][1]/Gaussians[n][1]);
    }
    // Divide by NumGaussians here ??? or take the maximum instead of the sum??
    if (res>1) res=1;
    // Cut at a certain value
    return (res-ProbabilityThreshold);
  }
  else
    return 0;

} // ExpansionMap()

//----------------------------------------------------------------------
void vtkLevelSets::PrintParameters()
{
  int i;

 std::cout << "------------- Level Set Parameters ---------------\n";
 std::cout << "--- Input Parameters \n";
 std::cout << "RescaleImage: "         << this->RescaleImage     << "\n";
 std::cout << "UseLowThreshold: "      << this->UseLowThreshold  << "\n";
 std::cout << "LowThreshold: "         << this->LowThreshold     << "\n";
 std::cout << "UseHighThreshold: "     << this->UseHighThreshold << "\n";
 std::cout << "HighThreshold: "        << this->HighThreshold    << "\n";
 std::cout << "--- Initial Level Set Parameters \n";
 std::cout << "Initial threshold: "    << this->InitThreshold    << "\n";
 std::cout << "NumInitPoints: "        << this->NumInitPoints    << "\n";
  for(i=0;i<NumInitPoints;i++)
   std::cout << "Point " << i << " ( "
     << InitPoints[i][0] << " , "
     << InitPoints[i][1] << " , "
     << InitPoints[i][2] << " ) "
     << InitPoints[i][3] << "\n ";
 std::cout << "--- Narrow Band Parameters \n";
 std::cout << "Band: "                 << this->Band             << "\n";
 std::cout << "Tube: "                 << this->Tube             << "\n";
 std::cout << "--- Distance Map Parameters \n";
 std::cout << "DMmethod: "             << this->DMmethod          << "\n";
 std::cout << "IsoContourBin: "        << this->IsoContourBin    << "\n";
 std::cout << "--- PDE Parameters \n";
 std::cout << "Dimension:"             << this->Dimension        << "\n";
 std::cout << "NumIters: "             << this->NumIters         << "\n";
 std::cout << "check freq.: "          << this->CheckFreq        << "\n";
 std::cout << "Reinit Freq.: "         << this->ReinitFreq       << "\n";
 std::cout << "Converged Threshold: "  << this->ConvergedThresh  << "\n";
 std::cout << "Step in t (StepDt): "   << this->StepDt           << "\n";
 std::cout << "Init dt (step): "       << this->init_dt          << "\n";
 std::cout << "EvolveThreads: "        << this->EvolveThreads    << "\n";
 std::cout << "--- Curvature Parameters \n";
 std::cout << "DoMean: "               << this->DoMean           << "\n";
 std::cout << "coeff_curvature: "      << this->coeff_curvature  << "\n";
 std::cout << "--- Advection Parameters \n";
 std::cout << "Advection coeff: "          << this->AdvectionCoeff              << "\n";
 std::cout << "HistoGradThreshold:"    << this->HistoGradThreshold   << "\n";
 std::cout << "advection_scheme:"<<this->advection_scheme<<"\n";
  printf("advection_scheme = %d \n",this->advection_scheme);
 std::cout << "--- Expansion Parameters \n";
 std::cout << "balloon_coeff: "        << this->balloon_coeff        << "\n";
 std::cout << "ProbabilityThreshold: " << this->ProbabilityThreshold << "\n";
 std::cout << "ProbabilityHighThreshold: " << this->ProbabilityHighThreshold << "\n";
 std::cout << "NumGaussians: "         << this->NumGaussians         << "\n";
  for(i=0;i<NumGaussians;i++)
   std::cout << "Gaussian " << i << " mean="
     << Gaussians[i][0] << " SD="
     << Gaussians[i][1] << "\n ";
 std::cout << "--- Velocity Parameters \n";
 std::cout << "coeff_velocity: "       << this->coeff_velocity       << "\n";
 std::cout << "--------------------------------------------------\n";

} // PrintParameters()


//----------------------------------------------------------------------
void vtkLevelSets::PrintSelf(ostream& os, vtkIndent indent)
{
   vtkImageAlgorithm::PrintSelf(os,indent);
   os << indent << "RescaleImage: "         << this->RescaleImage     << "\n";
   os << indent << "Initial threshold: "    << this->InitThreshold    << "\n";
   os << indent << "Band around isoline: "  << this->Band             << "\n";
   os << indent << "Number of Iterations: " << this->NumIters         << "\n";
   os << indent << "Advection coeff: "          << this->AdvectionCoeff          << "\n";
   os << indent << "check freq.: "          << this->CheckFreq        << "\n";
   os << indent << "Reinit Freq.: "         << this->ReinitFreq       << "\n";
   os << indent << "Converged Threshold: "  << this->ConvergedThresh  << "\n";
   os << indent << "Classical method with mean curvature: "
                                            << this->DoMean           << "\n";
   os << indent << "Step in t (StepDt): "   << this->StepDt           << "\n";
   os << indent << "Init dt (step): "       << this->init_dt          << "\n";
} // PrintSelf()




