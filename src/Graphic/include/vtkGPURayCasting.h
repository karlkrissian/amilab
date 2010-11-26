/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: GPURenderDemo.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// VTK includes

#ifndef _vtkGPURayCasting_h_
#define _vtkGPURayCasting_h_


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wxVTKRenderWindowInteractor.h"

#include "vtk_common.h"

class vtkImageData;

class vtkGPURayCasting : public wxFrame
{

    /// 0: MIP 1:CompositeRamp 2:CompositeShadeRamp, 3: CT_Skin, 4: CT_Bone, 5:CT_Muscle, 6:RGB_Composite
    int blendType;

    double opacityWindow;
    double opacityLevel;

    /// clip 0|1
    int clip; 
    
    /// within [0,1]
    double reductionFactor;

    /// within [0.01,60]
    double frameRate;
    char *fileName;
    int fileType;
    
    ///
    bool independentComponents;
    
//    vtkImageData *input;

  public:
    
    vtkGPURayCasting(vtkImageData_ptr image, bool clip=true);
    ~vtkGPURayCasting();
    
    void SetClip(int val) { clip = val; }
    void SetBlendType(int val) { blendType = val; }
    void SetOpacityMap(double win, double level) 
    { 
      opacityWindow = win;
      opacityLevel = level; 
    }

    void SetInput( vtkImageData_ptr image);
  
    vtkRenderer* GetRenderer() { return renderer; }

    vtkRenderWindowInteractor* GetRenderWindowInteractor() 
    { 
      return m_pVTKWindow; 
    }


    bool Display();

protected:
    void ConstructVTK();
    void ConfigureVTK();
    void DestroyVTK();

private:

  wxVTKRenderWindowInteractor *m_pVTKWindow;
  // vtk classes
  vtkRenderer       *renderer;
  vtkImageData_ptr  input;

private:
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE();
};

#endif // _vtkGPURayCasting_h_