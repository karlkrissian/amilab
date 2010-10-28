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


  class vtkImageData;

  class vtkGPURayCasting
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
      
      vtkImageData *input;

    public:
      
      vtkGPURayCasting();
      
      void SetInput( vtkImageData* image);
    
      bool Display();
  };

#endif // _vtkGPURayCasting_h_