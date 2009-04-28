//
// C++ Interface: 3DVectorsParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_VectorsParam_h_
#define _Viewer3D_VectorsParam_h_

class Viewer3D;

class  Viewer3D_VectorsParam: public ParamBox
{
private:

  Viewer3D* parent_class;

   // Parameters
   int   _id_vecttype;
   int    _id_vecttype_orient;
   int    _id_vecttype_dir;
   int   _id_vect1image;
   int   _id_display_vect1;
   int   _id_vect1color;
   int   _id_vect1size;
   int   _id_vect1width;
   int   _id_vect2image;
   int   _id_display_vect2;
   int   _id_vect2color;
   int   _id_vect2size;
   int   _id_vect2width;

public:

  Viewer3D_VectorsParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks  static 
  static void CB_vect1_image(       void* cd);
  static void CB_vect2_image(       void* cd);
  static void CB_recompute_allvect( void* cd );
  static void CB_recompute_vect1(   void* cd );
  static void CB_recompute_vect2(   void* cd );

}; // class Viewer3D_VectorsParam

#endif // _Viewer3D_VectorsParam_h_
