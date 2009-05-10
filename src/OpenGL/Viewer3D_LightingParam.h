//
// C++ Interface: 3DLightingParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_LightingParam_h_
#define _Viewer3D_LightingParam_h_

class Viewer3D;

class  Viewer3D_LightingParam: public ParamPanel
{
private:

  Viewer3D* parent_class;

   // Parameters
   int   _id_light_number;
   int   _id_light_enabled;
   int   _id_light_ambient;
   int   _id_light_diffuse;
   int   _id_light_specular;
   int   _id_light_position_x;
   int   _id_light_position_y;
   int   _id_light_position_z;
   int   _id_light_directional;
   int   _id_light_valider;
   int   _id_light_fermer;

public:

  Viewer3D_LightingParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 
  static void CB_light_number   (void* cd);
  static void CB_light_update   (void* cd);
  static void CB_light_fermer   (void* cd);

}; // class Viewer3D_LightingParam

#endif // _Viewer3D_LightingParam_h_
