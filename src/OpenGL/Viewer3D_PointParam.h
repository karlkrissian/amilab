//
// C++ Interface: 3DPointParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_PointParam_h_
#define _Viewer3D_PointParam_h_

#include "DefineClass.hpp"

class Viewer3D;

class  Viewer3D_PointParam: public ParamBox
{
  DEFINE_CLASS(Viewer3D_PointParam);
private:

   Viewer3D* parent_class;

   int   _id_point_action;
   int    _id_point_info;
   int    _id_point_select;
   int    _id_point_remove;
   int    _id_point_connect;
   int    _id_point_junction;
   int   _id_points_remove_selection;
   int   _id_points_remove_non_selected;
   int   _id_points_connect_selection;
   int   _id_points_new_selection;
   int   _id_points_save_selection;
   int   _id_points_width;
   int   _id_points_color;

public:

  Viewer3D_PointParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 
  static void CB_points_remove              (void* cd);
  static void CB_points_remove_non_selected (void* cd);
  static void CB_points_connect             (void* cd);
  static void CB_points_new                 (void* cd);
//  static void CB_points_save_selection      (void* cd);


}; // class Viewer3D_PointParam

#endif // _Viewer3D_PointParam_h_
