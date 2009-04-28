//
// C++ Interface: 3DLineParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_LineParam_h_
#define _Viewer3D_LineParam_h_

class Viewer3D;

class  Viewer3D_LineParam: public ParamBox
{
private:

   Viewer3D* parent_class;

   int   _id_line_action;
   int    _id_line_info;
   int    _id_line_select;
   int    _id_line_remove;
   int    _id_line_connect;
   int    _id_line_junction;
   int   _id_lines_remove_selection;
   int   _id_lines_remove_non_selected;
   int   _id_lines_connect_selection;
   int   _id_lines_new_selection;
   int   _id_lines_save_selection;
   int   _id_lines_undo;
   int   _id_lines_width;
   int   _id_lines_color;


public:

  Viewer3D_LineParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 

  static void CB_lines_remove(void*);
  static void CB_lines_remove_non_selected(void*);
  static void CB_lines_connect(void*);
  static void CB_lines_new(void*);
  static void CB_lines_save_selection(void*);
  static void CB_lines_undo(void*);

}; // class Viewer3D_LineParam

#endif // _Viewer3D_LineParam_h_
