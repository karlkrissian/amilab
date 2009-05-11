//
// C++ Interface: 3DViewParameters
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _Viewer3D_ViewParam_h_
#define _Viewer3D_ViewParam_h_

class Viewer3D;

class  Viewer3D_ViewParam: public ParamPanel
{
private:

  Viewer3D* parent_class;

/** @name  Gestion des parametres de la vue 3D
*/
   int    _id_boutton_center;
   int    _id_boutton_normalize;
   int    _id_boutton_XY;
   int    _id_boutton_XZ;
   int    _id_boutton_YZ;
   int    _id_rotX_plus;
   int    _id_rotX_moins;
   int    _id_rotY_plus;
   int    _id_rotY_moins;
   int    _id_rotZ_plus;
   int    _id_rotZ_moins;
   int    _id_boutton_sauve;

   // to do in the future : decomposition of the 
   // transformation matrix
//    int       _id_scalex;
//    int       _id_scaley;
//    int       _id_scalez;
//    int       _id_rot_X;
//    int       _id_rot_Y;
//    int       _id_rot_Z;

public:

  Viewer3D_ViewParam(Viewer3D* parent);
  void CreateParameters();

  // Callbacks
  static void CB_Center           (void* cd);
  static void CB_Normalize        (void* cd);
  static void CB_CenterNormalize  (void* cd);
  static void CB_XY_proj          (void* cd);
  static void CB_XZ_proj          (void* cd);
  static void CB_YZ_proj          (void* cd);
  static void CB_rotX_plus        (void* cd);
  static void CB_rotY_plus        (void* cd);
  static void CB_rotZ_plus        (void* cd);
  static void CB_rotX_moins       (void* cd);
  static void CB_rotY_moins       (void* cd);
  static void CB_rotZ_moins       (void* cd);
  static void CB_SauveImage       (void* cd);

}; // class Viewer3D_ViewParam

#endif // _Viewer3D_ViewParam_h_
