/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : krissian@dis.ulpgc.es

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2012  Karl Krissian

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


#include "amivtkFastMarchingFunctions.h"
#include "style.hpp"
#include "inrimage.hpp"
#include "Coordonnees.hpp"
#include "vtkLevelSetFastMarching.h"
#include "vtk_common.h"

namespace ami {

  //---------------------------------------------------------------------------
  // inittype 0: InitIsoSurf
  // inittype 1: InitWithImage

  InrImage::ptr vtkFastMarchingFunctions::FastMarching( InrImage* input, InrImage* init,
                                    float maxtime, InitializationType inittype)
  {
    InrImage::ptr res;
    #ifdef AMI_USE_VTK
      
      vtkImageData_ptr           vtk_input;
      vtkImageData_ptr           vtk_init;
      vtkLevelSetFastMarching*   vtk_FM;

      // Convert InrImage to vtkImageData
      vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
      vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));

      vtk_FM = vtkLevelSetFastMarching::New();

      vtk_FM->SetInput(     vtk_input.get());

      vtk_FM->Setinitimage( vtk_init.get());
      // if we set initiso to a different value than -1E10 (default value)
      // the it will call InitIsoSurf which recomputes the distance close to the surface
      // otherwise, it call InitWithImage which is much faster, and
      // all values lower than initmaxdist will be accepted to start with.

      switch (inittype)
      {
      case 0:
        vtk_FM->Setinitiso(   0);
        break;
      }
      vtk_FM->Setinitmaxdist(1+1E-3);
      vtk_FM->SetmaxTime( maxtime);

      vtk_FM->Update();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching() \t conversion InrImage \n");

      res = InrImage::ptr(new InrImage( vtk_FM->GetOutput()));

      vtk_FM->Delete();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching() \t end \n");

    #else
      fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    #endif // AMI_USE_VTK
    return res;

  } // vtkFastMarchingFunctions::FastMarching()


  //---------------------------------------------------------------------------
  // inittype 0: InitIsoSurf
  // inittype 1: InitWithImage
  InrImage::ptr vtkFastMarchingFunctions::FastMarchingTarget(  InrImage* input, InrImage* init,
                                      float maxtime, 
                                      int x, int y, int z)
  {
    InrImage::ptr                  res;
    #ifdef AMI_USE_VTK
      
      vtkImageData_ptr           vtk_input;
      vtkImageData_ptr           vtk_init;

      // Convert InrImage to vtkImageData
      vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
      vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
    
      vtkLevelSetFastMarching*   vtk_FM;


      vtk_FM = vtkLevelSetFastMarching::New();

      for (int i=-1; i<=1; i++)
      for (int j=-1; j<=1; j++)
      for (int k=-1; k<=1; k++) {
      if (input->CoordOK(x+i,y+j,z+k)) 
        vtk_FM->AddTargetPoint( x+i,y+j,z+k);
      }

      vtk_FM->SetInput(     vtk_input.get());

      vtk_FM->Setinitimage( vtk_init.get());
      // if we set initiso to a different value than -1E10 (default value)
      // the it will call InitIsoSurf which recomputes the distance close to the surface
      // otherwise, it call InitWithImage which is much faster, and
      // all values lower than initmaxdist will be accepted to start with.

      vtk_FM->Setinitiso(   0);

      vtk_FM->Setinitmaxdist(1+1E-3);
      vtk_FM->SetmaxTime( maxtime);

      vtk_FM->Update();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarchingTarget() \t conversion InrImage \n");

      res = InrImage::ptr(new InrImage( vtk_FM->GetOutput()));

      vtk_FM->Delete();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarchingTarget() \t end \n");

    #else
      fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    #endif // AMI_USE_VTK

    return res;

  } // vtkFastMarchingFunctions::FastMarchingTarget()


  //---------------------------------------------------------------------------
  InrImage::ptr vtkFastMarchingFunctions::FastMarching(  
                                                  InrImage* input 
                                                  ,InrImage* init
                                                  ,float mean
                                                  , float sd
                                                  , float maxtime
                                                  ,InitializationType inittype
                                                  ,int evol_scheme)
  {
    InrImage::ptr                  res;
    #ifdef AMI_USE_VTK
      
      vtkImageData_ptr           vtk_input;
      vtkImageData_ptr           vtk_init;

      // Convert InrImage to vtkImageData
      vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
      vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));

      vtkLevelSetFastMarching*   vtk_FM;

      vtk_FM = vtkLevelSetFastMarching::New();

      vtk_FM->SetInput(     vtk_input.get());
      vtk_FM->SetEvolutionScheme( evol_scheme);

      vtk_FM->Setinitimage( vtk_init.get());
      switch (inittype)
      {
      case 0:
        vtk_FM->Setinitiso(   0);
        break;
      }
      vtk_FM->Setinitmaxdist(1+1E-3);
      vtk_FM->SetmaxTime( maxtime);
      vtk_FM->SetGaussianForce(mean,sd);

      vtk_FM->Update();

      if (GB_debug) 
        fprintf(stderr,
                "vtkFastMarchingFunctions::FastMarching() \t conversion InrImage \n");

      res = InrImage::ptr(new InrImage( vtk_FM->GetOutput()));

      vtk_FM->Delete();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching \t end \n");

    #else
      fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    #endif // AMI_USE_VTK
    return res;

  } // vtkFastMarchingFunctions::FastMarching()



  //---------------------------------------------------------------------------
  InrImage::ptr vtkFastMarchingFunctions::FastMarchingTrack(  
                InrImage* input, InrImage* init,
                InrImage* track,
                float mean, float sd, float maxtime, 
                InitializationType inittype)
  {
    InrImage::ptr                  res;
    #ifdef AMI_USE_VTK
      vtkImageData_ptr           vtk_input;
      vtkImageData_ptr           vtk_init;
      vtkImageData_ptr           vtk_track;
      vtkLevelSetFastMarching*   vtk_FM;

      // Convert InrImage to vtkImageData
      vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
      vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
      vtk_track = vtk_new<vtkImageData>()((vtkImageData*) (*track));

      vtk_FM = vtkLevelSetFastMarching::New();

      vtk_FM->SetInput          (vtk_input.get());
      vtk_FM->SetEvolutionScheme(1); // Dijkstra
      vtk_FM->Settrack          (vtk_track.get());

      vtk_FM->Setinitimage( vtk_init.get());
      switch (inittype)
      {
      case 0:
        vtk_FM->Setinitiso(   0);
        break;
      }
      vtk_FM->Setinitmaxdist(1+1E-3);
      vtk_FM->SetmaxTime( maxtime);
      vtk_FM->SetGaussianForce(mean,sd);

      vtk_FM->Update();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching() \t conversion InrImage \n");

      res = InrImage::ptr(new InrImage( vtk_FM->GetOutput()));

      InrImage* tmp_track = new InrImage(vtk_track.get());
      (*track) = (*tmp_track);
      delete tmp_track;
    
      vtk_FM->Delete();
      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching() \t end \n");

    #else
      fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    #endif // AMI_USE_VTK
    return res;

  } // vtkFastMarchingFunctions::FastMarchingTrack()


  //---------------------------------------------------------------------------
  InrImage::ptr vtkFastMarchingFunctions::FastMarchingTrack(  
                InrImage* input, InrImage* init,
                InrImage* track,
                float maxtime,
                InitializationType inittype)
  {
    InrImage::ptr                  res;
    #ifdef AMI_USE_VTK
      vtkImageData_ptr           vtk_input;
      vtkImageData_ptr           vtk_init;
      vtkImageData_ptr           vtk_track;
      vtkLevelSetFastMarching*   vtk_FM;

      // Convert InrImage to vtkImageData
      vtk_input = vtk_new<vtkImageData>()((vtkImageData*) (*input));
      vtk_init  = vtk_new<vtkImageData>()((vtkImageData*) (*init));
      vtk_track = vtk_new<vtkImageData>()((vtkImageData*) (*track));

      vtk_FM = vtkLevelSetFastMarching::New();

      vtk_FM->SetInput          (vtk_input.get());
      vtk_FM->SetEvolutionScheme(1); // Dijkstra
      vtk_FM->Settrack          (vtk_track.get());

      vtk_FM->Setinitimage( vtk_init.get());
      switch (inittype)
      {
      case 0:
        vtk_FM->Setinitiso(   0);
        break;
      }
      vtk_FM->Setinitmaxdist(1+1E-3);
      vtk_FM->SetmaxTime( maxtime);

      vtk_FM->Update();

      if (GB_debug) 
        fprintf(stderr,
          "vtkFastMarchingFunctions::FastMarching() \t conversion InrImage \n");

      res = InrImage::ptr(new InrImage( vtk_FM->GetOutput()));

      InrImage* tmp_track = new InrImage(vtk_track.get());
      (*track) = (*tmp_track);
      delete tmp_track;
    
      vtk_FM->Delete();

      if (GB_debug) 
        fprintf(stderr,"vtkFastMarchingFunctions::FastMarching() \t end \n");

    #else
      fprintf(stderr," VTK not available, you need to compile with VTK ...\n");
    #endif // AMI_USE_VTK
    return res;

  } // vtkFastMarchingFunctions::FastMarchingTrack()



} // end namespace ami
