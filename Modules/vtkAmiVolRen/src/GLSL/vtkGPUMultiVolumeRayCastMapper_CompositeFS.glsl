/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkGPUVolumeRayCastMapper_CompositeFS.glsl

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

// Fragment program part with ray cast and composite method.

#version 110

uniform sampler3D dataSetTexture;
uniform sampler1D opacityTexture;

//carlos
uniform sampler3D dataSetTexture2;
uniform sampler1D opacityTexture2;
// uniform sampler1D mask2ColorTexture;

uniform vec3 lowBounds;
uniform vec3 highBounds;

// Entry position (global scope)
vec3 pos;
// Incremental vector in texture space (global scope)
vec3 rayDir;

float tMax;

// from cropping vs no cropping
vec4 initialColor();

// from 1 vs 4 component shader.
float scalarFromValue(vec4 value);
vec4 colorFromValue(vec4 value);
vec4 colorFromValue2(vec4 value);

// from noshade vs shade.
void initShade();
vec4 shade(vec4 value);
vec4 shade2(vec4 value);

void trace(void)
{
  vec4 destColor=initialColor();
  float remainOpacity=1.0-destColor.a;

  bool inside=true;
  
  vec4 color;
  vec4 opacity;

  vec4 color2;
  vec4 opacity2;

  initShade();
  
  float t=0.0;
  bool text1=false;
  bool text2=false;
  
  // We NEED two nested while loops. It is trick to work around hardware
  // limitation about the maximum number of loops.

  while(inside)
    {  
    while(inside)
      {
      //float intensity,af;
      text1=false;
      text2=false;
      //texture 1
      vec4 value=texture3D(dataSetTexture,pos);
      float scalar=scalarFromValue(value);
      //texture 2 (dataSetTexture2)
      vec4 value2=texture3D(dataSetTexture2,pos);
      float scalar2=scalarFromValue(value2);
      // opacity is the sampled texture value in the 1D opacity texture at
      // scalarValue


//       opacity=texture1D(opacityTexture,scalar)+texture1D(opacityTexture,scalar2);
//       if(opacity.a>0.0)
//         {
//         color=shade(value)+shade2(value2);
//         color=color*opacity.a;
//         destColor=destColor+color*remainOpacity;
//         remainOpacity=remainOpacity*(1.0-opacity.a);
//         }

      //Texture1
      opacity=texture1D(opacityTexture,scalar);
      if(opacity.a>0.0)
        {
        text1=true;
        color=shade(value);
//         vec3 col= mix(color.rgb,value.rgb,value.a);
//         color= vec4(col,color.a); 

        color=color*opacity.a;
        destColor=destColor+color*remainOpacity;
        remainOpacity=remainOpacity*(1.0-opacity.a);
        }
      //Texture2
      opacity2=texture1D(opacityTexture2,scalar2);
      if(opacity2.a>0.0)
        {
        text2=true;
        color2=shade2(value2);
        color2=color2*opacity2.a;
        destColor=destColor+color2*remainOpacity;
        remainOpacity=remainOpacity*(1.0-opacity2.a);
        }

//       if(text1 && text2)
//         {
//          destColor=destColor*0.5;
//          remainOpacity=remainOpacity*0.5;
//         }
      pos=pos+rayDir;
      t+=1.0;
      inside=t<tMax && all(greaterThanEqual(pos,lowBounds))
        && all(lessThanEqual(pos,highBounds))
        && (remainOpacity>=0.0039); // 1/255=0.0039
      }
    }
   gl_FragColor = destColor;
   //gl_FragColor = vec4 (destColor.rgb, destColor.a)
   gl_FragColor.a = 1.0-remainOpacity;
}
