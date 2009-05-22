//
// C++ Interface: 3DFogParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_FogParam_h_
#define _Viewer3D_FogParam_h_

#include "DefineClass.hpp"

class Viewer3D;

class  Viewer3D_FogParam: public ParamPanel
{
  DEFINE_CLASS(Viewer3D_FogParam);
private:

  Viewer3D* parent_class;

   // Parameters
  int   _id_fog_enabled;
  int   _id_fog_mode;
  int     _id_mode_exp;
  int     _id_mode_exp2;
  int     _id_mode_linear;
  int   _id_fog_use_backgroundcolor;
  int   _id_fog_color;
  int   _id_fog_density;
  int   _id_fog_start;
  int   _id_fog_end;
  int   _id_fog_fermer;

public:

  Viewer3D_FogParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 
  static void CB_fog_use_bg_color (void* cd);
  static void CB_fog_fermer       (void* cd);

}; // class Viewer3D_FogParam

#endif // _Viewer3D_FogParam_h_
