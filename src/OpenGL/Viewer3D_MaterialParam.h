//
// C++ Interface: 3DMaterialParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_MaterialParam_h_
#define _Viewer3D_MaterialParam_h_

class Viewer3D;

class  Viewer3D_MaterialParam: public ParamPanel
{
private:

    Viewer3D* parent_class;

    GLMaterialParam _GLMaterial_display;
    unsigned char   _current_object_visible;

    int   _object_number;

    int   _id_object_number;
    int   _id_display_object;
    int   _id_point_size;
    int   _id_line_width;
    int   _id_colormaterial;
    int   _id_colormaterial_mode;
    int    _id_colormaterial_emission;
    int    _id_colormaterial_ambient;
    int    _id_colormaterial_diffuse;
    int    _id_colormaterial_specular;
    int    _id_colormaterial_ambient_and_diffuse;
    int   _id_mat_ambient;
    int   _id_mat_diffuse;
    int   _id_mat_specular;
    int   _id_mat_emission;
    int   _id_mat_shininess;
    int   _id_mat_opacity;
    int   _id_mat_fermer;

public:

  Viewer3D_MaterialParam(Viewer3D* parent);
  void CreateParameters();

  // Update the Gui depending on the changes
  // in the graphical objects
  void UpdateGui();

  // Callbacks  static 
  static void CB_object_number       (void* cd);
  static void CB_material_update     (void* cd);
  static void CB_material_fermer     (void* cd);

}; // class Viewer3D_MaterialParam

#endif // _Viewer3D_MaterialParam_h_
