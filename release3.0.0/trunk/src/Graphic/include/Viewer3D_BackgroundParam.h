//
// C++ Interface: 3DBackgroundParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_BackgroundParam_h_
#define _Viewer3D_BackgroundParam_h_

#include "DefineClass.hpp"

class Viewer3D;

class  Viewer3D_BackgroundParam: public ParamPanel
{
  DEFINE_CLASS(Viewer3D_BackgroundParam);

private:

  Viewer3D* parent_class;

  // Parameters
   int   _id_backgroundtype;
   int     _id_bg_onecolor;
   int     _id_bg_gradient;
   int   _id_backgroundcolor;
   int   _id_bg_tl; // top left color
   int   _id_bg_tr; // top right color
   int   _id_bg_bl; // bottom left color
   int   _id_bg_br; // bottom right color
   int   _id_bc_close;
   int    _etat_param_backgroundcolor;

public:

  Viewer3D_BackgroundParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 
  static void CB_BackgroundColorApply(void* cd);

}; // class Viewer3D_BackgroundParam

#endif // _Viewer3D_BackgroundParam_h_
