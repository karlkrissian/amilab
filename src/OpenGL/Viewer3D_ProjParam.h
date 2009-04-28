//
// C++ Interface: 3DProjParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_ProjParam_h_
#define _Viewer3D_ProjParam_h_

class Viewer3D;

class  Viewer3D_ProjParam: public ParamBox
{
private:

  Viewer3D* parent_class;

   int    _id_type_proj;
   int      _id_proj_ortho;
   int      _id_proj_persp;
   int    _id_left;
   int    _id_right;
   int    _id_bottom;
   int    _id_top;
   int    _id_near;
   int    _id_far;
   int    _id_persp_near;
   int    _id_persp_far;
   int    _id_basis_far;

public:

  Viewer3D_ProjParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks
  static void CB_proj_param       (void* cd);
  static void CB_proj_type        (void* cd);

}; // class Viewer3D_ProjParam

#endif // _Viewer3D_ProjParam_h_
