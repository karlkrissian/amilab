/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

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
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#include "inrimage.hpp"
#include "LevelSetsCURVES.h"

#ifndef _WITHOUT_VTK_

#include "vtkLevelSets.h"
#include "vtkImageData.h"
#include "vtk_common.h"

// Only one execution of curv at a time
static boost::shared_ptr<vtkLevelSets> curv;
static vtkImageData_ptr image_input;
static vtkImageData_ptr velocity;
static vtkImageData_ptr expansion_image;
static vtkImageData_ptr image_output;
static vtkImageData_ptr initimage;

#endif // _WITHOUT_VTK_

#include "MainFrame.h"
#include <vtkCommand.h>

extern MainFrame*   GB_main_wxFrame;

class vtkUpdateProgressBar : public vtkCommand
{
  public:

  static vtkUpdateProgressBar *New()
  { 
    return new vtkUpdateProgressBar; 
  }

  virtual void Execute(vtkObject *caller, unsigned long, void* calldata)
  {
    double value = *(double*) calldata;
    if (GB_main_wxFrame)
      GB_main_wxFrame->SetProgress((int)(value*100+0.5));
  }
};

static vtkUpdateProgressBar update_progressbar;


void StartVTKProcedure()
{
#ifdef _WITHOUT_VTK_ 
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_ 
}


void Func_LevelSets_InitParam(			      
			      float gradthreshold,
			      int   iterations,
			      float attachcoeff,
			      float curvcoeff,
			      float dt,
			      int   ReinitFreq
			      )
{ 
  StartVTKProcedure();
#ifndef _WITHOUT_VTK_ 
  

  curv = vtk_new<vtkLevelSets> ()();
 std::cout  << "curv reference count (just after constructor)"
        << curv->GetReferenceCount()
        << std::endl;

  //  curv->SetConvergedThresh( conv_th);

  curv->SetNumIters(           iterations);
  curv->SetAdvectionCoeff(     attachcoeff);
  curv->SetStepDt(             dt);
  curv->SetReinitFreq(         ReinitFreq);
  curv->SetHistoGradThreshold( gradthreshold);
  curv->Setcoeff_curvature(    curvcoeff);
  curv->SetDMmethod(           DISTMAP_FASTMARCHING);
  curv->Setsavedistmap(        0);

  //  Si meancurv AlorsFait curv->DoMeanOn();
  curv->Setadvection_scheme(   ADVECTION_MORPHO);

  curv->AddObserver(vtkCommand::ProgressEvent,&update_progressbar);

  //  curv->Setadvection_scheme(ADVECTION_CENTRAL_VECTORS);
  //  curv->SetUseCosTerm(1);
#endif // _WITHOUT_VTK_ 
}

//--------------------------------------------------
void Func_LevelSets_SetMeanCurv( int meancurv)
{
  StartVTKProcedure();
#ifndef _WITHOUT_VTK_ 
   
   Si meancurv Alors
     curv->DoMeanOn();
   Sinon
     curv->DoMeanOff();
   FinSi
       
#endif // _WITHOUT_VTK_
} // Func_LevelSetsMeanCurv()


//--------------------------------------------------
void Func_LevelSets_SetAffineCurvature( int affcurv)
{
  StartVTKProcedure();
#ifndef _WITHOUT_VTK_ 
   Si affcurv Alors
     curv->AffineCurvatureOn();
   Sinon
     curv->AffineCurvatureOff();
   FinSi
#endif // _WITHOUT_VTK_
} // Func_LevelSets_SetAffineCurvature()

//--------------------------------------------------
void Func_LevelSets_SetBalloonScheme( int balloonscheme)
{
   StartVTKProcedure();
#ifndef _WITHOUT_VTK_ 
    curv->Setballoon_scheme(balloonscheme);
#endif // _WITHOUT_VTK_
} // Func_LevelSets_SetBalloonScheme()

//--------------------------------------------------
InrImage* Func_LevelSets_Init(InrImage* in, 
			      float threshold
			      )
{
#ifndef _WITHOUT_VTK_ 

  InrImage* out;
  //float tr_x,tr_y,tr_z;

  // Initialize the evolution
  image_input  = (vtkImageData_ptr) (*in);
  image_output = vtk_new<vtkImageData>()();

  curv->InitParam( image_input.get(), image_output.get());

  curv->SetInitThreshold(   threshold);
  curv->InitEvolution();

  out = new InrImage(image_output.get());

/*
  out->SetImageData(in->_tx,in->_ty,in->_tz,WT_FLOAT,
		    output->GetScalarPointer());
  out->SetVoxelSize(in->_size_x,in->_size_y,in->_size_z);
  in ->GetTranslation(tr_x,tr_y,tr_z);
  out->SetTranslation(tr_x,tr_y,tr_z);
*/
  // return the output as an InrImage
  return out;

#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
  return(NULL);
#endif // _WITHOUT_VTK_
}

//--------------------------------------------------
InrImage* Func_LevelSets_Init(InrImage* in, 
			      InrImage* initImage
			      )
{
#ifndef _WITHOUT_VTK_ 

  InrImage* out;
  //float tr_x,tr_y,tr_z;

  // Initialize the evolution
  image_input  = (vtkImageData_ptr) (*in);

 std::cout  << "input reference count "
        << image_input->GetReferenceCount()
        << std::endl;

  image_output = vtk_new<vtkImageData>()();

  curv->InitParam( image_input.get(), image_output.get());

  if (!initimage.use_count()) {
   std::cout << " ************************** " << std::endl;
   std::cout << " ************************** " << std::endl;
   std::cout << " ************************** " << std::endl;
    initimage = (vtkImageData_ptr) (*initImage);
 std::cout  << "initimage reference count "
        << initimage->GetReferenceCount()
        << std::endl;
  }

  curv->SetinitImage(initimage.get());

 std::cout  << "initimage reference count "
        << initimage->GetReferenceCount()
        << std::endl;

  curv->SetInitThreshold(0);
  curv->InitEvolution();

  out = new InrImage(image_output.get());

/*
  out = new InrImage();
  out->SetImageData(in->_tx,in->_ty,in->_tz,WT_FLOAT,
		    image_output->GetScalarPointer());
  out->SetVoxelSize(in->_size_x,in->_size_y,in->_size_z);
  
  in ->GetTranslation(tr_x,tr_y,tr_z);
  out->SetTranslation(tr_x,tr_y,tr_z);

*/
  return out;

#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
  return(NULL);
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
InrImage* Func_LevelSets_GetCurrentOutput()
{
  InrImage* out;
  out = new InrImage(image_output.get());
  return out;
}


//--------------------------------------------------
int Func_LevelSets_UpdateResult()
{
#ifndef _WITHOUT_VTK_ 

  return curv->UpdateResult();
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
  return(0);
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
void      Func_LevelSets_SetDMmethod( int m)
{
#ifndef _WITHOUT_VTK_ 
  Si m>=0 Et m<=3 Alors
  curv->SetDMmethod( m);
  Sinon
    fprintf(stderr,"Func_LevelSets_SetDMmethod() \t bad value \n");   
  FinSi
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
void      Func_LevelSets_SetThreads( int n)
{
#ifndef _WITHOUT_VTK_ 
  Si n>=1  Alors
    curv->SetEvolveThreads( n);
  FinSi
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
void      Func_LevelSets_SetIsoContourBin( int b)
{
#ifndef _WITHOUT_VTK_ 
  curv->SetIsoContourBin( b);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
int      Func_LevelSets_Iterate()
{
#ifndef _WITHOUT_VTK_ 
  return curv->Iterate();
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
  return(0);
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
InrImage*    Func_LevelSets_GetAttachVectors( InrImage* in)
{
#ifndef _WITHOUT_VTK_ 
  InrImage* res;
  float_vec DAx;
  float_vec DAy;
  float_vec DAz;
  int i;

  switch  (curv->Getadvection_scheme()) {
    case ADVECTION_UPWIND_VECTORS:
    case ADVECTION_CENTRAL_VECTORS:
      res = new InrImage(WT_FLOAT,3,"AttachVectors.ami.gz",in);
      curv->GetDataAttach(DAx,DAy,DAz);
      res->InitBuffer();
      i = 0;
      Repeter
        res->VectFixeValeurs(DAx[i],DAy[i],DAz[i]);
        i++;
      JusquA Non(res->IncBuffer()) FinRepeter
      return res;
    case ADVECTION_MORPHO:
      res = new InrImage(WT_FLOAT,"AttachVectors.ami.gz",in);
      curv->GetDataAttach(DAx,DAy,DAz);
      res->InitBuffer();
      i = 0;
      Repeter
        res->FixeValeur(DAx[i]);
        i++;
      JusquA Non(res->IncBuffer()) FinRepeter
      return res;
  } // end switch      

  return NULL;
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
  return(NULL);
#endif // _WITHOUT_VTK_
}


//--------------------------------------------------
void      Func_LevelSets_SetIntensityLowThreshold( float th)
{
#ifndef _WITHOUT_VTK_ 

  curv->UseLowThresholdOn();
  curv->SetLowThreshold(th);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetIntensityLowThreshold()


//--------------------------------------------------
void      Func_LevelSets_SetIntensityHighThreshold( float th)
{
#ifndef _WITHOUT_VTK_ 

  curv->UseHighThresholdOn();
  curv->SetHighThreshold(th);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetIntensityHighThreshold()


//--------------------------------------------------
void      Func_LevelSets_SetProbabilityHighThreshold( float th)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetProbabilityHighThreshold(th);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetProbabilityHighThreshold()


//--------------------------------------------------
void      Func_LevelSets_SetProbThreshold( float th)
{
#ifndef _WITHOUT_VTK_ 

  if ((th>0)&&(th<1))
    curv->SetProbabilityThreshold(th);
  else
    fprintf(stderr,"Func_LevelSets_SetProbThreshold() threshold must be in ]0,1[ \n");
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetProbThreshold()


//--------------------------------------------------
void      Func_LevelSets_SetNumGaussians(int n)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetNumGaussians(n);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetNumGaussians()


//--------------------------------------------------
void      Func_LevelSets_SetGaussian(int n, float mean, float sd)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetGaussian(n,mean,sd);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetGaussian()


//--------------------------------------------------
void      Func_LevelSets_SetNumInitPoints(int n)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetNumInitPoints(n);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetNumInitPoints()


//--------------------------------------------------
void      Func_LevelSets_SetInitPoint(int n,  int x, int y, int z, int radius)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetInitPoint(n,x,y,z,radius);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSets_SetInitPoint()


//--------------------------------------------------
void      Func_LevelSetsGetCurvatureData( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  if (im!=NULL)
    curv->GetCurvatureTerm( (float*) im->Buffer());
  else
    curv->GetCurvatureTerm( NULL);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetCurvatureData()


//--------------------------------------------------
void      Func_LevelSetsGetDistanceMap( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  if (im!=NULL)
    curv->GetDistanceMap( (float*) im->Buffer());
  else
    curv->GetDistanceMap( NULL);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetDistanceMap()


//--------------------------------------------------
void      Func_LevelSetsGetAdvectionData( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  if (im!=NULL)
    curv->GetAdvectionTerm( (float*) im->Buffer());
  else
    curv->GetAdvectionTerm( NULL);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetAdvectionData()


//--------------------------------------------------
void      Func_LevelSetsGetVelocityData( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  if (im!=NULL)
    curv->GetVelocityTerm( (float*) im->Buffer());
  else
    curv->GetVelocityTerm( NULL);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetVelocityData()


//--------------------------------------------------
void      Func_LevelSetsGetExpansionData( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  if (im!=NULL)
    curv->GetBalloonTerm( (float*) im->Buffer());
  else
    curv->GetBalloonTerm( NULL);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetExpansionData()


//--------------------------------------------------
void      Func_LevelSetsGetSkeleton( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  vtkImageData* SkeletonImage;
  float* buf2;

  if (im!=NULL) {
    // The images must be in float format
    SkeletonImage = curv->GetSkeletonImage();

    buf2 = (float*) SkeletonImage->GetScalarPointer();
    im->InitBuffer();
    do {
      im->FixeValeur(*buf2);
      buf2++;
    }
    while (im->IncBuffer());
    
  }
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsGetSkeleton()


//--------------------------------------------------
void      Func_LevelSetsSetCurvWeights( InrImage* cw)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetCurvatureWeights((float*)(cw->GetData()));

#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsVelocity()


//--------------------------------------------------
void      Func_LevelSetsSetAdvectionField( InrImage* adx, InrImage* ady, InrImage* adz)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetAdvectionVectorField((float*)(adx->GetData()),
				(float*)(ady->GetData()),
				(float*)(adz->GetData()));

#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsVelocity()


//--------------------------------------------------
void      Func_LevelSetsVelocity( InrImage* vel, float coeff)
{
#ifndef _WITHOUT_VTK_ 
  if (curv.use_count()) {
    velocity  = vtk_new<vtkImageData>()((vtkImageData*) (*vel));
    curv->Setvelocity(velocity.get());
    curv->Setcoeff_velocity(coeff);
  } else {
    std::cerr << "Func_LevelSetsVelocity() level set class not allocated ! " << std::endl;
    return;
  }
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsVelocity()


//--------------------------------------------------
void      Func_LevelSetsExpansion( float coeff)
{
#ifndef _WITHOUT_VTK_ 

  curv->Setballoon_coeff(coeff);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsExpansion()


//--------------------------------------------------
void      Func_LevelSetsExpansionImage( InrImage* im)
{
#ifndef _WITHOUT_VTK_ 

  expansion_image  = vtk_new<vtkImageData>()((vtkImageData*) (*im));
  curv->Setballoon_image(expansion_image.get());
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsExpansionImage()


//--------------------------------------------------
void     Func_LevelSets_End()
{
#ifndef _WITHOUT_VTK_ 

  curv->EndEvolution();

 std::cout  << "curv reference count "
        << curv->GetReferenceCount()
        << std::endl;
  
  curv            .reset();
 std::cout  << "input reference count "
        << image_input->GetReferenceCount()
        << std::endl;
  image_input           .reset();
  velocity        .reset();
  expansion_image .reset();
  image_output          .reset();
 std::cout  << "initimage reference count "
        << initimage->GetReferenceCount()
        << std::endl;
  initimage       .reset();

  // should probably copy the resulting data
  // into new allocated data array and delete 'output' ....
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

}


//--------------------------------------------------
void      Func_LevelSetsBandAndTube( int band, int tube)
{
#ifndef _WITHOUT_VTK_ 

  curv->SetBand(band);
  curv->SetTube(tube);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsExpansionImage()


//--------------------------------------------------
void      Func_LevelSetsSaveDistMap( int sdm)
{
#ifndef _WITHOUT_VTK_ 

  curv->Setsavedistmap(sdm);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsSaveDistMap()

//--------------------------------------------------
void      Func_LevelSetsSaveSecDerGrad( int save)
{
#ifndef _WITHOUT_VTK_ 

  curv->Setsavesecdergrad(save);
#else
  fprintf(stderr,"LevelSetsCURVES.cpp \t AMILab compiled without VTK, function not available \n");
#endif // _WITHOUT_VTK_

} // Func_LevelSetsSaveDistMap()
