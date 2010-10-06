/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : krissian@dis.ulpgc.es

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ==================================================
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ==================================================
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.21 $
 * $Log: DessinImage.cpp,v $
 * Revision 1.21  2006/03/09 16:49:07  karl
 * evolving for Fluid tutorial + fixed OpenGL pb with GLw
 *
 * Revision 1.20  2006/02/21 18:26:18  karl
 * many changes
 *
 * Revision 1.19  2006/01/13 14:00:21  karl
 * proportional vectors in slices
 *
 * Revision 1.18  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.17  2004/08/26 22:05:35  karl
 * adding control of imagedraw into amilab
 *
 * Revision 1.16  2004/08/25 22:37:38  karl
 * displaying vector field from amilab + read vtk vector field
 *
 * Revision 1.15  2004/08/24 22:26:41  karl
 * imagedraw getinrimage
 *
 * Revision 1.14  2004/08/24 22:14:43  karl
 * Saving IMAGEDRAW content
 *
 * Revision 1.13  2004/08/18 21:33:12  karl
 * warning and memory pbs
 *
 * Revision 1.12  2004/08/13 15:17:27  karl
 * fixed pb with CC and removed points in surface.cpp
 *
 * Revision 1.11  2004/08/06 01:02:11  karl
 * Position of the 3D cursor and 3D slices: including image translation
 *
 * Revision 1.10  2004/07/01 15:03:30  karl
 * Added features to Connected Components, Resize with translation, volume rendering
 *
 * Revision 1.9  2004/06/24 23:01:56  karl
 * small modif + RGB textures
 *
 * Revision 1.8  2004/06/24 05:18:53  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.7  2004/06/24 04:46:19  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.6  2004/06/21 19:50:34  karl
 * improved Volume Rendering
 *
 * Revision 1.5  2004/06/16 21:47:01  karl
 * Volume Rendering starting to work
 *
 * Revision 1.4  2004/06/16 02:00:02  karl
 * Starting Volume Rendering
 *
 * Revision 1.3  2004/06/02 22:57:34  karl
 * Connected Components + some bugs fixed
 *
 * Revision 1.2  2004/04/30 20:10:15  karl
 * several improcements
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:05  karl
 * Source code
 *
 * Revision 1.8  2001/03/02 11:49:32  karl
 * *** empty log message ***
 *
 * Revision 1.7  2000/11/08 16:42:10  karl
 * *** empty log message ***
 *
 * Revision 1.6  2000/11/08 16:23:21  karl
 * *** empty log message ***
 *
 * Revision 1.5  2000/10/30 13:13:31  karl
 * *** empty log message ***
 *
 * Revision 1.4  2000/10/30 12:57:03  karl
 *
 *
 * Dessin de la vue surfacique d'une coupe 2D
 *
 * Revision 1.2  2000/10/06 22:52:06  karl
 * *** empty log message ***
 *
 * Revision 1.3  2000/10/02 16:57:18  karl
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/19 12:19:07  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:28  karl
 * Sources code
 *
 *
 ***************************************************************************/
// Programme de courbes dans l'espace
// fichier DessinImage.cpp
//
// Karl KRISSIAN
//
// Sophia Antipolis le 08-12-96
//
#include "wx/wxprec.h"
#include <wx/version.h>
#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "MainFrame.h"
#include "DessinImage.hpp"
#include "CompareImage.hpp"
#include "ficparam.hpp"
#include "VolumeRender.hpp"
//#include "math1.hpp"
#include "Viewer3D.hpp"

#ifndef macro_min
  #define macro_min(a,b) ( (a)<(b) ? (a) : (b))
#endif

#ifndef macro_max
  #define macro_max(a,b) ( (a)>(b) ? (a) : (b))
#endif


typedef  unsigned long Dimension;

extern MainFrame*   GB_main_wxFrame;

//extern XtAppContext GB_contexte;
extern unsigned char      GB_debug;

#define aff_err(mess) if (GB_debug) fprintf(stderr,mess);

#include "amilab_messages.h"

#include <wx/aui/aui.h>

//Pixmaps
#include "../../Pixmaps/free_design_icons/Info_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Units_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Refresh_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Target_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Contrast_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Arrow_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Curve_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Circle_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Registry_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Color_palete_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Sections3D_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Layers_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Sharpness_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Transparent_background_xpm.xpm"
#include "../../Pixmaps/free_design_icons/New_imagelist_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Clear_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Selection_xpm.xpm"
#include "../../Pixmaps/free_design_icons/Zoom_out_xpm.xpm"

enum myIDs {
  wxID_POSITION = 0,
  wxID_INTENSITY = 1,
  wxID_VECTORS = 2,
  wxID_ISO_CONTOURS = 3,
  wxID_IMAGE_SURFACE = 4,
  wxID_IMAGE_INFORMATION = 5,
  wxID_VOXEL_SIZE = 6,
  wxID_COLORS = 7,
  wxID_SECTIONS3D = 8,
  wxID_VOLREN = 9,
  wxID_GLMIP = 10,
  wxID_VOXELS3D = 11,
  wxID_CIRCLES = 12,
  wxID_ZOOM_FACTOR = 13,
  wxID_MIP = 14,
  wxID_ANIMATION = 15,
  wxID_VIEW_TYPE = 16,
  wxID_SIZE_TYPE = 17,
  wxID_ORIGINAL_SIZE = 18,
  wxID_RELOAD = 19,
  wxID_CHECK_ZOOM = 20,
  wxID_UNZOOM = 21,
  wxID_XY = 22,
  wxID_XZ = 23,
  wxID_ZY = 24,
  wxID_MANYXY = 25
};

//----------------------------------------------------------------
void DessinImage::InitMinMax( InrImage::ptr& image)
//                ----------
{
  Si Non(_param->int_min_fixee) Ou Non(_param->int_max_fixee) Alors
    image->MinMax(&_val_min, &_val_max);
  FinSi

  Si _param->int_min_fixee AlorsFait _val_min = _param->intensite_min;
  Si _param->int_max_fixee AlorsFait _val_max = _param->intensite_max;

  Si fabs( _val_max - _val_min) < 1E-6 Alors
    Si image->_format == WT_UNSIGNED_CHAR Alors
      _val_min = 0;
      _val_max = 255;
    Autrement
    Si image->_format == WT_UNSIGNED_SHORT Alors
      _val_min = 0;
      _val_max = 65535;
    Sinon
      _val_min = 0;
      _val_max = 255;
    FinSi

    wxString message;
    message.Printf(GetwxStr("Intensity min = max, we will use [%.2f, %.2f]"),
                   _val_min,_val_max);
    wxMessageBox( message,
                  wxString::FromAscii("Warning: constant image"),
                  wxICON_INFORMATION|wxOK);

  FinSi

  _intensite_float_min = _val_min;
  _intensite_float_max = _val_max;

  _intensite_entier_min = (int) _val_min;
  _intensite_entier_max = (int) _val_max;

} // InitMinMax()


//----------------------------------------------------------------
void DessinImage::SetIntensityRange( float imin, float imax)
//                ----------
{
  int     int_max,int_min;
  float   float_max,float_min;

  int_min =   *(Get_intensite_entier_min());
  float_min = *(Get_intensite_float_min());
  int_max =   *(Get_intensite_entier_max());
  float_max = *(Get_intensite_float_max());

  Set_intensite_entier_min(imin);
  Set_intensite_entier_max(imax);
  Set_intensite_float_min( imin);
  Set_intensite_float_max( imax);

  if (!(VerifyMinMax()))
  {
    Set_intensite_entier_min(int_min);
    Set_intensite_float_min(float_min);
    Set_intensite_entier_max(int_max);
    Set_intensite_float_max(float_max);
  }

  MinMaxChecker();
  Param._MAJ._intensite = true;
  Param._MAJ.MAJCoupes();
  Paint();
  _param_intensity->MAJ();
}


//----------------------------------------------------------------
void DessinImage::UpDateMinMax( )
//                ------------
{

  InitMinMax( _image);
  SetMinMax( _val_min, _val_max);

} // UpDateMinMax()


//----------------------------------------------------------------
void DessinImage::SetMinMax( float min, float max)
//                ---------
{

  ImageDraw_IntensityParam::ptr intensity(_param_intensity);
  ImageDraw_GLMIPParam::ptr glmip(_param_glmip);
  ImageDraw_Voxels3DParam::ptr voxels3D(_param_voxels3D);

    int i;

  Si max<=min AlorsFait return;

  _val_min = min;
  _val_max = max;

  _intensite_float_min = _val_min;
  _intensite_float_max = _val_max;

  _intensite_entier_min = (int) _val_min;
  _intensite_entier_max = (int) _val_max;

  Si (_image->_format == WT_FLOAT ) Ou
     (_image->_format == WT_DOUBLE) Alors


//    _param_dialog->FloatConstraints(_id_min,_val_min,_val_max,_val_min);
//    _param_dialog->FloatConstraints(_id_max,_val_min,_val_max,_val_max);
  
    intensity->FloatConstraints(intensity->_id_min,_val_min,_val_max,_val_min);
    intensity->FloatConstraints(intensity->_id_max,_val_min,_val_max,_val_max);

  Sinon

//    _param_dialog->IntegerConstraints(_id_min,(int)_val_min,(int)_val_max,(int)_val_min);
//    _param_dialog->IntegerConstraints(_id_max,(int)_val_min,(int)_val_max,(int)_val_max);
  
    intensity->IntegerConstraints(intensity->_id_min,(int)_val_min,(int)_val_max,(int)_val_min);
    intensity->IntegerConstraints(intensity->_id_max,(int)_val_min,(int)_val_max,(int)_val_max);


  FinSi

//  ParametreReel* pcont;
  // TODO: get rid of MAX_ISOCONTOURS
  #define MAX_ISOCONTOURS 3
  ImageDraw_IsoContourParam::ptr c(_param_isocontour);
  Pour(i,0,MAX_ISOCONTOURS-1)
/*
      pcont = (ParametreReel*) (*_param_IsoContour)[_id_seuil_contour[i]];
      pcont->FixeContraintes(_val_min,_val_max,_val_max);
      pcont->MAJ_Contraintes();
 */
//      _param_dialog->FloatConstraints(_id_seuil_contour[i],_val_min,_val_max,_val_max);
      c->FloatConstraints(c->_id_seuil_contour[i],_val_min,_val_max,_val_max);
  FinPour


/*
  pcont = (ParametreReel*) (*_param_IsoContour)[_id_step_contours];
  _step_contours = pow(10, (int) (log(_val_max - _val_min)/log(10)));
  pcont->FixeContraintes(0, _val_max-_val_min, _step_contours);
  pcont->MAJ_Contraintes();
  */
  _step_contours = pow(10.0, (int) (log(_val_max - _val_min)/log(10.0)));
//  _param_dialog->FloatConstraints(_id_step_contours,0, _val_max-_val_min, _step_contours);
  c->FloatConstraints(c->_id_step_contours,0, _val_max-_val_min, _step_contours);


//  ParametreReel* pvox;

//  pvox = (ParametreReel*) (*_param_Voxels3D)[_id_voxels_seuilbas];
//  pvox->FixeContraintes(_val_min,_val_max,_val_max);
//  pvox->MAJ_Contraintes();
//  _param_Voxels3D->FloatConstraints(_id_voxels_seuilbas,_val_min,_val_max,_val_max);
  voxels3D->FloatConstraints(voxels3D->_id_voxels_seuilbas,_val_min,_val_max,_val_max);


//  pvox = (ParametreReel*) (*_param_Voxels3D)[_id_voxels_seuilhaut];
//  pvox->FixeContraintes(_val_min,_val_max,_val_max);
//  pvox->MAJ_Contraintes();
//  _param_Voxels3D->FloatConstraints(_id_voxels_seuilhaut,_val_min,_val_max,_val_max);
  voxels3D->FloatConstraints(voxels3D->_id_voxels_seuilhaut,_val_min,_val_max,_val_max);



//  pvox = (ParametreReel*) (*_param_GLMIP)[_id_glmip_seuilbas];
//  pvox->FixeContraintes(_val_min,_val_max,_val_max);
//  pvox->MAJ_Contraintes();
//  _param_GLMIP->FloatConstraints(_id_glmip_seuilbas,_val_min,_val_max,_val_max);
  glmip->FloatConstraints(glmip->_id_glmip_seuilbas,_val_min,_val_max,_val_max);


//  pvox = (ParametreReel*) (*_param_GLMIP)[_id_glmip_seuilhaut];
//  pvox->FixeContraintes(_val_min,_val_max,_val_max);
//  pvox->MAJ_Contraintes();
//  _param_GLMIP->FloatConstraints(_id_glmip_seuilhaut,_val_min,_val_max,_val_max);
  glmip->FloatConstraints(glmip->_id_glmip_seuilhaut,_val_min,_val_max,_val_max);


  EffaceTousLesEcrans(false);

} // SetMinMax()


//-----------------------------------------------------------------------
// Check if the limit values of the 2 intensity scales are different
// from the current intensity limits.
// if true, update the limits.
//
void DessinImage::CheckMinMax()
//
{
  ImageDraw_IntensityParam::ptr p(_param_intensity);

  Si (_image->_format == WT_FLOAT ) Ou
     (_image->_format == WT_DOUBLE) Alors

    float min,max;

    //_param_dialog->ParamFloatGetLimits(_id_min,min,max);
    p->ParamFloatGetLimits(p->_id_min,min,max);
    Si (fabsf(min-_val_min)>1E-5) Ou (fabsf(max-_val_max)>1E-5)
    Alors
      SetMinMax(min,max);
    Sinon
      //_param_dialog->ParamFloatGetLimits(_id_max,min,max);
      p->ParamFloatGetLimits(p->_id_max,min,max);
      Si (fabsf(min-_val_min)>1E-5) Ou (fabsf(max-_val_max)>1E-5)
      AlorsFait
        SetMinMax(min,max);
    FinSi

  Sinon

    int min,max;

    //_param_dialog->ParamIntGetLimits(_id_min,min,max);
    p->ParamIntGetLimits(p->_id_min,min,max);
    Si (fabsf(min-_val_min)>1E-5) Ou (fabsf(max-_val_max)>1E-5)
    Alors
      SetMinMax(min,max);
    Sinon
      //_param_dialog->ParamIntGetLimits(_id_max,min,max);
      p->ParamIntGetLimits(p->_id_max,min,max);
      Si (fabsf(min-_val_min)>1E-5) Ou (fabsf(max-_val_max)>1E-5)
      AlorsFait
        SetMinMax(min,max);
    FinSi

  FinSi

} // CheckMinMax()


//-----------------------------------------------------------------------
// Compute Colorbar and Axes sizes
//
void DessinImage::ComputeBasicSizes()
//
{
    char         valstr_max[30];
    char         valstr_min[30];
    char         valstr[30];
    float         valmin,valmax;


  Si (_image->_format != WT_RGB)Et(Param._show_colorbar) Alors


    valmin = _val_min;
    valmax = _val_max;

    Si valmax - valmin >= 100 Alors
      sprintf(valstr_max,"%3.0f",valmax);
      sprintf(valstr_min,"%3.0f",valmin);
    Autrement
    Si valmax - valmin >= 10 Alors
      sprintf(valstr_max,"%2.1f",valmax);
      sprintf(valstr_min,"%2.1f",valmin);
    Sinon
      sprintf(valstr_max,"%1.2f",valmax);
      sprintf(valstr_min,"%1.2f",valmin);
    FinSi

  int maxwidth;
  wxCoord maxCharWidth, maxCharHeight;
  wxCoord minCharWidth, minCharHeight;

  _memory_dc->GetTextExtent(wxString::FromAscii(valstr_max),
                    &maxCharWidth,
                    &maxCharHeight);
  maxwidth = (int) maxCharWidth;
  _memory_dc->GetTextExtent(wxString::FromAscii(valstr_min),
                    &minCharWidth,
                    &minCharHeight);

    _colorbar_width = 10 +
              macro_max(maxCharWidth,minCharWidth) +
              24;

  Sinon
    _colorbar_width = 0;
  FinSi

  switch ( Param._axes_info ){
    case AXES_VOXEL_POS:
      sprintf(valstr,"%d",macro_max(_image->_tx-1,_image->_tz-1));
    break;
    case AXES_SPACE_POS:
      sprintf(valstr,"%2.1f",macro_max(_image->SpacePosX(_image->_tx-1),
                       _image->SpacePosY(_image->_tz-1)));
    break;
  } // end switch

  wxCoord maxCharWidth, maxCharHeight;

  _memory_dc->GetTextExtent(wxString::FromAscii(valstr),
                            &maxCharWidth,
                            &maxCharHeight);

  _right_axe_width   = 5+2+(int) maxCharWidth+2;

  _bottom_axe_height = 5+2+(int) maxCharHeight;


//  _right_axe_width   = 0;
//  _bottom_axe_height = 0;

} // ComputeBasicSizes()

//-----------------------------------------------------------------------
void DessinImage::InitVoxelSize()
//                -------------
{
    float   val1, val2;
    float   dim_x, dim_y, dim_z;

    int avail_height; // width and height available for drawing slices
    int avail_width;
    int i;
    int h_margin[3]; // horizontal margin for each slice view
    int v_margin[3]; // vertical margin for each slice view

    int largeur,hauteur;

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::InitVoxelSize() \n");

  Si Param._option_traitement == OPTION_MIP Alors
    // On garde les proportions dans l'image MIP,
    // le changement d'�helle est inclus dans le calcul de l'image projett�
    dim_x = Param._Zoom._zoom_size_x;
    dim_y = Param._Zoom._zoom_size_y;
    dim_z = Param._Zoom._zoom_size_z;
  Sinon
    dim_x = Param._Zoom._zoom_size_x * Param._dim._voxel_size_x;
    dim_y = Param._Zoom._zoom_size_y * Param._dim._voxel_size_y;
    dim_z = Param._Zoom._zoom_size_z * Param._dim._voxel_size_z;
  FinSi

  largeur = _largeur - _colorbar_width;
  hauteur = _hauteur;

  Pour(i,0,2)
    _right_margin[i]  = _bottom_margin[i] = 2;
    _left_margin[i]   = _top_margin[i]    = 5;
  FinPour

  Si Param._show_axes Alors
    _bottom_margin[IMAGE_XZ] = 8;
    _right_margin[ IMAGE_ZY] = 8;

    _right_margin[IMAGE_XY]  =
    _right_margin[IMAGE_XZ]  = _right_axe_width;

    _bottom_margin[IMAGE_XY] =
    _bottom_margin[IMAGE_ZY] = _bottom_axe_height;
  FinSi

  Pour(i,0,2)
    h_margin[i] = _right_margin[i]  + _left_margin[i];
    v_margin[i] = _top_margin[i]    + _bottom_margin[i];
  FinPour

  Si (largeur > 20) Et (hauteur > 20) Alors
  //    _distance_coupes = 5;
    _distance_coupes = 0;
  Sinon
    _distance_coupes = 0;
  FinSi

  // Calcul dans _size_x, _size_y, et _size_z la taille
  // en pixels d'une unit�de longueur

  switch ( Param._type_taille ){

    case TAILLE_FENETRE:

      switch ( Param._type_coupe ){

        case TYPE_COUPE_XY:
          avail_width  = largeur - h_margin[IMAGE_XY];
          avail_height = hauteur - v_margin[IMAGE_XY];
          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;

          _size_x = (float) avail_width  / (1.0*dim_x);
          _size_y = (float) avail_height / (1.0*dim_y);
          _size_z = _size_x;
        break;

        case TYPE_COUPE_XZ:
          avail_width  = largeur - h_margin[IMAGE_XZ];
          avail_height = hauteur - v_margin[IMAGE_XZ];
          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;

          _size_x = (float) avail_width / dim_x;
          _size_z = (float) avail_height / dim_z;
          _size_y = _size_x;
        break;

        case TYPE_COUPE_ZY:
          avail_width  = largeur - h_margin[IMAGE_ZY];
          avail_height = hauteur - v_margin[IMAGE_ZY];
          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;

          _size_z = (float) avail_width / dim_z;
          _size_y = (float) avail_height / dim_y;
          _size_x = _size_y;
        break;

        case TYPE_COUPE_XY_XZ:

          avail_width  = largeur - h_margin[IMAGE_XY];
          avail_height = hauteur - v_margin[IMAGE_XY]
                                  - v_margin[IMAGE_XZ]
                                  - _distance_coupes;
          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;

          _size_x = (float) avail_width  / dim_x;
          _size_y =
          _size_z = (float) avail_height / ( dim_y + dim_z);

        break;

        case TYPE_COUPE_XY_ZY:

          avail_width  = largeur - h_margin[IMAGE_XY]
                                  - h_margin[IMAGE_ZY]
                                  - _distance_coupes;
          avail_height = hauteur - v_margin[IMAGE_XY];

          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;


          _size_x =
          _size_z = (float) avail_width  / ( dim_x + dim_z);
          _size_y = (float) avail_height / dim_y;

        break;

        case TYPE_COUPE_XZ_ZY:
        case TYPE_COUPE_XY_XZ_ZY:

          avail_width  = largeur - h_margin[IMAGE_XY]
                                  - h_margin[IMAGE_ZY]
                                  - _distance_coupes;
          avail_height = hauteur - v_margin[IMAGE_XY]
                                  - v_margin[IMAGE_XZ]
                                  - _distance_coupes;
          Si avail_width <1 AlorsFait avail_width  = 10;
          Si avail_height<1 AlorsFait avail_height = 10;

          val1 = (float) avail_width  / (dim_x + dim_z);
          val2 = (float) avail_height / (dim_y + dim_z);

          Si val1 < val2 Alors
            _size_x = _size_y = _size_z = val1;
          Sinon
            _size_x = _size_y = _size_z = val2;
          FinSi
          #ifdef AMI_BUILD_Debug
            CLASS_MESSAGE( boost::format(" avail_width, avail_height = %1% %2% size: %3% %4% %5% ")
                            % avail_width % avail_height 
                            % _size_x % _size_y % _size_z )
          #endif

        break;

      } // end switch // Param._type_coupe
    break;

    case TAILLE_FACTEUR:
      Si _type_facteur == FACTEUR_ENTIER Alors
        _size_x = _size_y = _size_z = _facteur_entier;
      Sinon
        _size_x = _size_y = _size_z = _facteur_reel;
      FinSi
    break;

  } // end switch // Param._type_taille

  Si _type_facteur == FACTEUR_ENTIER Alors
    _size_x = (int) _size_x;
    _size_y = (int) _size_y;
    _size_z = (int) _size_z;
  FinSi

  Si _size_x <= 0 Alors
    CLASS_ERROR(" _size_x < 0, set to 1 ");
    _size_x = 1;
  FinSi

  Si _size_y <= 0 Alors
    CLASS_ERROR(" _size_y < 0, set to 1 ");
    _size_y = 1;
  FinSi

  Si _size_z <= 0  Alors
    CLASS_ERROR(" _size_z < 0, set to 1 ");
    _size_z = 1;
  FinSi


  // Conservation de l'isotropie de l'image
  val1 = min( _size_x, _size_y);
  val1 = min( val1, _size_z);

  // Calcul dans _size_x, _size_y et _size_z la taille
  // en pixels d'un voxel selon chaque dimension.
  Si Param._option_traitement == OPTION_MIP Alors
    _size_x = _size_y = _size_z = val1;
  Sinon
    _size_x = val1 * Param._dim._voxel_size_x;
    _size_y = val1 * Param._dim._voxel_size_y;
    _size_z = val1 * Param._dim._voxel_size_z;
  FinSi

  CLASS_MESSAGE( boost::format("_size_x,y,z = %1% %2% %3% ") 
                % _size_x % _size_y % _size_z );

  CLASS_MESSAGE("End");

} // InitVoxelSize()


//----------------------------------------------------------------
void DessinImage::IncreaseZoomArea( )
//
{
    int tx,ty,tz;
    float   Xneed, Yneed;
    int i;
    int h_margin[3]; // horizontal margin for each slice view
    int v_margin[3]; // vertical margin for each slice view
    int largeur,hauteur;
    int inc_x, inc_y; // possible increases in each dimension

  largeur = _largeur - _colorbar_width;
  hauteur = _hauteur;

  Pour(i,0,2)
    h_margin[i] = _right_margin[i]  + _left_margin[i];
    v_margin[i] = _top_margin[i]    + _bottom_margin[i];
  FinPour

  tx = Param._Zoom._zoom_size_x;
  ty = Param._Zoom._zoom_size_y;
  tz = Param._Zoom._zoom_size_z;

  switch ( Param._type_coupe ){

    case TYPE_COUPE_XY:
      Xneed = tx*_size_x + h_margin[IMAGE_XY];
      Yneed = ty*_size_y + v_margin[IMAGE_XY];

      // possible increase in X is (largeur-Xneed)/_size_x
      inc_x = (int) ((largeur-Xneed)/_size_x);
      if (inc_x>0) Param._Zoom.IncreaseX(inc_x,_image);
      // possible increase in Y is (largeur-Yneed)/_size_y
      inc_y = (int) ((hauteur-Yneed)/_size_y);
      if (inc_y>0) Param._Zoom.IncreaseY(inc_y,_image);
      Param._Zoom.Check(_image);
    break;

    case TYPE_COUPE_XZ_ZY:
    case TYPE_COUPE_XY_XZ_ZY:
/*
      Xneed = tx*_size_x + tz*_size_z +
              h_margin[IMAGE_XY] +
              h_margin[IMAGE_ZY] +
              _distance_coupes;
      Yneed = ty*_size_y + tz*_size_z +
              v_margin[IMAGE_XY] +
              v_margin[IMAGE_XZ] +
              _distance_coupes;

      // possible increase in X is (largeur-Xneed)/_size_x
      inc_x = (int) ((largeur-Xneed)/_size_x);
      if (inc_x>0) Param._Zoom.IncreaseX(inc_x,_image);
      // possible increase in Y is (largeur-Yneed)/_size_y
      inc_y = (int) ((hauteur-Yneed)/_size_y);
      if (inc_y>0) Param._Zoom.IncreaseY(inc_y,_image);
      Param._Zoom.Check(_image);
*/
    break;

    case TYPE_COUPE_XZ:
    case TYPE_COUPE_ZY:
    case TYPE_COUPE_XY_XZ:
    case TYPE_COUPE_XY_ZY:
    case TYPE_COUPES:
    break;

  } // end switch // Param._type_coupe

}


//----------------------------------------------------------------
void DessinImage::InitPositionImages( )
//                  ------------------
{
    int tx,ty,tz;
    float   Xneed, Yneed;
    int i;
    int h_margin[3]; // horizontal margin for each slice view
    int v_margin[3]; // vertical margin for each slice view
    int largeur,hauteur;

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::InitPositionImages()  begin\n");

  largeur = _largeur - _colorbar_width;
  hauteur = _hauteur;

  if (GB_debug) std::cerr << format(" (%d %d) --> (%d %d ) ") %_largeur %_hauteur % largeur%hauteur << std::endl;

  Pour(i,0,2)
    h_margin[i] = _right_margin[i]  + _left_margin[i];
    v_margin[i] = _top_margin[i]    + _bottom_margin[i];

  if (GB_debug) std::cerr << format("i= %d  hmargin %d vmargin %d ")
      % i % h_margin[i]% v_margin[i] << std::endl;

  FinPour

  tx = Param._Zoom._zoom_size_x;
  ty = Param._Zoom._zoom_size_y;
  tz = Param._Zoom._zoom_size_z;

  switch ( Param._type_coupe ){

    case TYPE_COUPE_XY:

      Xneed = tx*_size_x + h_margin[IMAGE_XY];
      Yneed = ty*_size_y + v_margin[IMAGE_XY];

      _tab_ximage_pos_x[IMAGE_XY] = (int) (largeur-Xneed)/2 +
                                           _left_margin[IMAGE_XY];
      _tab_ximage_pos_y[IMAGE_XY] = (int) (hauteur-Yneed)/2 +
                                           _top_margin[IMAGE_XY];

    break;

    case TYPE_COUPE_XZ:

      Xneed = tx*_size_x + h_margin[IMAGE_XZ];
      Yneed = tz*_size_z + v_margin[IMAGE_XZ];

      _tab_ximage_pos_x[IMAGE_XZ] = (int) (largeur-Xneed)/2 +
                                           _left_margin[IMAGE_XZ];
      _tab_ximage_pos_y[IMAGE_XZ] = (int) (hauteur-Yneed)/2+
                                           _top_margin[IMAGE_XZ];

    break;

    case TYPE_COUPE_ZY:

      Xneed = tz*_size_z + h_margin[IMAGE_ZY];
      Yneed = ty*_size_y + v_margin[IMAGE_ZY];

      _tab_ximage_pos_x[IMAGE_ZY] = (int) (largeur-Xneed)/2 +
                                           _left_margin[IMAGE_ZY];
      _tab_ximage_pos_y[IMAGE_ZY] = (int) (hauteur-Yneed)/2 +
                                           _top_margin[IMAGE_ZY];
    break;

    case TYPE_COUPE_XY_XZ:

      Xneed = tx*_size_x + h_margin[IMAGE_XY];
      Yneed = ty*_size_y + tz*_size_z +
              v_margin[IMAGE_XY] +
              v_margin[IMAGE_XZ] +
              _distance_coupes;

      _tab_ximage_pos_x[IMAGE_XZ] = (int) (largeur-Xneed)/2 +
                                           _left_margin[IMAGE_XZ];
      _tab_ximage_pos_y[IMAGE_XZ] = (int) (hauteur-Yneed)/2 +
                                           _top_margin[IMAGE_XZ];


      _tab_ximage_pos_x[IMAGE_XY] = _tab_ximage_pos_x[IMAGE_XZ];
      _tab_ximage_pos_y[IMAGE_XY] = (int) (_tab_ximage_pos_y[IMAGE_XZ]   +
                                    tz*_size_z +
                                    _bottom_margin[IMAGE_XZ] +
                                    _distance_coupes +
                                    _top_margin[IMAGE_XY]);

    break;

    case TYPE_COUPE_XY_ZY:

      Xneed = tx*_size_x + tz*_size_z +
              h_margin[IMAGE_XY] +
              h_margin[IMAGE_ZY] +
              _distance_coupes;
      Yneed = ty*_size_y + v_margin[IMAGE_XY];

      _tab_ximage_pos_x[IMAGE_ZY] = (int) (largeur-Xneed)/2 +
                                    _left_margin[IMAGE_ZY];
      _tab_ximage_pos_y[IMAGE_ZY] = (int) (hauteur-Yneed)/2 +
                                    _top_margin[IMAGE_ZY];


      _tab_ximage_pos_x[IMAGE_XY] = (int) (_tab_ximage_pos_x[IMAGE_ZY] +
                                    tz*_size_z +
                                    _right_margin[IMAGE_ZY] +
                                    _distance_coupes +
                                    _left_margin[IMAGE_XY]);
      _tab_ximage_pos_y[IMAGE_XY] = _tab_ximage_pos_y[IMAGE_ZY];

    break;

    case TYPE_COUPE_XZ_ZY:
    case TYPE_COUPE_XY_XZ_ZY:

      Xneed = tx*_size_x + tz*_size_z +
              h_margin[IMAGE_XY] +
              h_margin[IMAGE_ZY] +
              _distance_coupes;
      Yneed = ty*_size_y + tz*_size_z +
              v_margin[IMAGE_XY] +
              v_margin[IMAGE_XZ] +
              _distance_coupes;

      _tab_ximage_pos_x[IMAGE_XY] = (int) ( largeur - tx*_size_x
                           -_right_margin[IMAGE_XY]);
      _tab_ximage_pos_y[IMAGE_XY] = (int) ( hauteur - ty*_size_y
                           -_bottom_margin[IMAGE_XY]);

      _tab_ximage_pos_x[IMAGE_ZY] = (int) (
                    _tab_ximage_pos_x[IMAGE_XY] -
                                    _left_margin[IMAGE_XY]  -
                                    _distance_coupes -
                                    _right_margin[IMAGE_ZY] -
                    tz*_size_z );
      _tab_ximage_pos_y[IMAGE_ZY] = _tab_ximage_pos_y[IMAGE_XY];

      _tab_ximage_pos_x[IMAGE_XZ] =_tab_ximage_pos_x[IMAGE_XY];
      _tab_ximage_pos_y[IMAGE_XZ] = (int) (
                                    _tab_ximage_pos_y[IMAGE_XY] -
                    _top_margin[IMAGE_XY] -
                                    _distance_coupes -
                    _bottom_margin[IMAGE_XZ] -
                                    tz*_size_z);

    break;

    case TYPE_COUPES:

      _tab_ximage_pos_x[IMAGE_COUPES] = (int) ( 0 );
      _tab_ximage_pos_y[IMAGE_COUPES] = (int) ( 0 );

    break;

  } // end switch // Param._type_coupe

  Si _dessine_masque Alors
    _tab_ximage_pos_x[IMAGE_MASQUE_XY] = _tab_ximage_pos_x[IMAGE_XY];
    _tab_ximage_pos_y[IMAGE_MASQUE_XY] = _tab_ximage_pos_y[IMAGE_XY];
  FinSi

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::InitPositionImages()  end\n");

} // InitPositionImages()

//-----------------------------------------------------------------------
BEGIN_EVENT_TABLE(DessinImage, DessinImageBase)
//    EVT_MENU(ID_MenuImage_Display,   DessinImage::OnQuit)
//    EVT_MENU(ID_MenuImage_Reload,    DessinImage::CB_relire)
    EVT_MENU(ID_MenuImage_Compare,   DessinImage::CB_comparer)
//    EVT_MENU(ID_MenuImage_VoxelSize, DessinImage::CB_voxel)
//    EVT_MENU(ID_MenuImage_info,      DessinImage::CB_image_info)
//    EVT_MENU(ID_MenuImage_Save_param,DessinImage::CB_sauver_param)
//    EVT_MENU(ID_MenuImage_Save_image,DessinImage::CB_sauver_image)
    EVT_MENU(ID_MenuImage_close,     DessinImage::CB_Close)

//    EVT_MENU(ID_MenuOptions_option_slice,   DessinImage::CB_option_traitement)
//    EVT_MENU(ID_MenuOptions_option_mip,     DessinImage::CB_option_traitement)
//    EVT_MENU(ID_MenuOptions_option_anim,    DessinImage::CB_option_traitement)

//    EVT_MENU(ID_MenuOptions_sliceXY,        DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceXZ,        DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceXY_XZ,     DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceZY,        DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceXY_ZY,     DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceXZ_ZY,     DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_sliceXY_XZ_ZY,  DessinImage::CB_redraw)
//    EVT_MENU(ID_MenuOptions_XYslices,       DessinImage::CB_redraw)

//    EVT_MENU(ID_MenuOptions_window_size,    DessinImage::CB_type_taille)
//    EVT_MENU(ID_MenuOptions_fixed_size,     DessinImage::CB_type_taille)

    EVT_MENU(ID_MenuImage_original_size,    DessinImage::CB_image_size)

//    EVT_MENU(ID_MenuImage_zoom_activated,    DessinImage::CB_fonction_zoom)
//    EVT_MENU(ID_MenuImage_zoom_desactivated, DessinImage::CB_fonction_zoom)
//    EVT_MENU(ID_MenuImage_unzoom,            DessinImage::CB_fonction_zoom)

    EVT_MENU(ID_MenuOptions_Interp_Active,   DessinImage::CB_interpole)

    EVT_MENU(ID_MenuOptions_interp_sub2,     DessinImage::CB_interpole)
    EVT_MENU(ID_MenuOptions_interp_sub3,     DessinImage::CB_interpole)
    EVT_MENU(ID_MenuOptions_interp_sub4,     DessinImage::CB_interpole)
    EVT_MENU(ID_MenuOptions_interp_sub8,     DessinImage::CB_interpole)
    EVT_MENU(ID_MenuOptions_interp_submax,   DessinImage::CB_interpole)

//    EVT_MENU(ID_MenuOptions_circlefield,     DessinImage::CB_circles)
//    EVT_MENU(ID_MenuOptions_voxels3D,        DessinImage::CB_voxels3D)
//    EVT_MENU(ID_MenuOptions_OpenGLMIP,       DessinImage::CB_GLMIP)
//    EVT_MENU(ID_MenuOptions_VolRen,          DessinImage::CB_VOLREN)
//    EVT_MENU(ID_MenuOptions_Sections3D,      DessinImage::CB_sections3D)
//    EVT_MENU(ID_MenuOptions_Colors,          DessinImage::CB_couleurs)

    EVT_MENU(ID_MenuOptions_linewidth1,      DessinImage::CB_largeur_lignes)
    EVT_MENU(ID_MenuOptions_linewidth2,      DessinImage::CB_largeur_lignes)
    EVT_MENU(ID_MenuOptions_linewidth3,      DessinImage::CB_largeur_lignes)
    EVT_MENU(ID_MenuOptions_linewidth4,      DessinImage::CB_largeur_lignes)

    EVT_MENU(ID_MenuOptions_display_mask,    DessinImage::CB_MasqueVisible)
    EVT_MENU(ID_MenuOptions_display_cursor,  DessinImage::CB_curseur_visible)
//    EVT_MENU(ID_MenuOptions_paramwin,        DessinImage::CB_parametres_visibles)

    EVT_MENU(ID_MenuMIP_param,               DessinImage::CB_parametresMIP_visibles)
    EVT_MENU(ID_MenuMIP_minmax,              DessinImage::CB_MIP_min_max)
    EVT_MENU(ID_MenuMIP_boundingbox,         DessinImage::CB_MIP_bounding_box)

    EVT_MENU(ID_MenuMIP_zoombb,              DessinImage::CB_MIP_zoom_bounding_box)

    EVT_MENU(ID_MenuMIP_Proj_morepoints,     DessinImage::CB_MIP_precise)
    EVT_MENU(ID_MenuMIP_Proj_interp,         DessinImage::CB_MIP_lin_interp)
    EVT_MENU(ID_MenuMIP_Proj_fast,           DessinImage::CB_MIP_rapide)

    EVT_MENU(ID_MenuMIP_ReadCrest,           DessinImage::CB_fichier_crest)
    EVT_MENU(ID_MIPstereo_active,            DessinImage::CB_MIP_stereo)
    EVT_MENU(ID_MIPstereo_anim,              DessinImage::CB_MIP_anim_stereo)
    EVT_MENU(ID_MIPstereo_colors,            DessinImage::CB_MIP_stereo_lunettes)

    EVT_MENU(ID_MenuCompare_DependIntensity,    DessinImage::CB_UpdateComparison)
    EVT_MENU(ID_MenuCompare_NormalizeIntensity, DessinImage::CB_UpdateComparison)
    EVT_MENU(ID_MenuCompare_DependPosition,     DessinImage::CB_UpdateComparison)
    EVT_MENU(ID_MenuCompare_UpdateMinMax,       DessinImage::CB_UpdateMinMax)

    EVT_TIMER(wxID_ANY, DessinImage::OnTimer)

    //Aui toolbars events
    EVT_TOOL(wxID_POSITION,           DessinImage::CB_OnPositionClick)
    EVT_TOOL(wxID_INTENSITY,          DessinImage::CB_OnIntensityClick)
    EVT_TOOL(wxID_VECTORS,            DessinImage::CB_OnVectorsClick)
    EVT_TOOL(wxID_ISO_CONTOURS,       DessinImage::CB_OnIsoContoursClick)
    EVT_TOOL(wxID_IMAGE_SURFACE,      DessinImage::CB_OnImageSurfaceClick)
    EVT_TOOL(wxID_IMAGE_INFORMATION,  DessinImage::CB_image_info)
    EVT_TOOL(wxID_VOXEL_SIZE,         DessinImage::CB_voxel)
    EVT_COMBOBOX(wxID_VIEW_TYPE,      DessinImage::CB_OnViewTypeClick)
    EVT_COMBOBOX(wxID_SIZE_TYPE,      DessinImage::CB_OnSizeTypeClick)
    EVT_TOOL(wxID_RELOAD,             DessinImage::CB_relire)
    EVT_TOOL(wxID_CHECK_ZOOM,         DessinImage::CB_OnZoomClick)
    EVT_TOOL(wxID_UNZOOM,             DessinImage::CB_OnUnzoomClick)
    EVT_TOOL(wxID_CIRCLES,            DessinImage::CB_circles)
    EVT_TOOL(wxID_VOXELS3D,           DessinImage::CB_voxels3D)
    EVT_TOOL(wxID_GLMIP,              DessinImage::CB_GLMIP)
    EVT_TOOL(wxID_VOLREN,             DessinImage::CB_VOLREN)
    EVT_TOOL(wxID_SECTIONS3D,         DessinImage::CB_sections3D)
    EVT_TOOL(wxID_COLORS,             DessinImage::CB_couleurs)
    EVT_TOOL(wxID_MANYXY,             DessinImage::CB_OnManyXYClick)
    EVT_CHECKBOX(wxID_XY,             DessinImage::CB_OnCheckXYClick)
    EVT_CHECKBOX(wxID_XZ,             DessinImage::CB_OnCheckXZClick)
    EVT_CHECKBOX(wxID_ZY,             DessinImage::CB_OnCheckZYClick)

END_EVENT_TABLE()



//-----------------------------------------------------------------------
//void DessinImage::CreeFenetreParametres(ParamBox* pb)
void DessinImage::CreeFenetreParametres()
//                ---------------------
{
   const char*  method = "CreeFenetreParametres";

  Si GB_debug AlorsFait printf("DessinImage::%s\n",method);
  
  _param_position = new_wxWindow_ptr(ImageDraw_PositionParam,this);
  _param_position->Hide();

  aff_err("DessinImage::CreeFenetreParametres() 5 \n");

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::%s min et max \n",method);

  _param_intensity = new_wxWindow_ptr(ImageDraw_IntensityParam,this);
  _param_intensity->Hide();

  aff_err("DessinImage::CreeFenetreParametres() fin \n");

} // CreeFenetreParametres()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresVoxel()
//                           -------------------
{
  
  _param_voxel = new_wxWindow_ptr(ImageDraw_VoxelSizeParam,this);
  _param_voxel->Hide();

} // CreeParametresVoxel()


//-----------------------------------------------------------------------
//void DessinImage::CreeParametresVecteurs(ParamBox* pb)
void DessinImage::CreeParametresVecteurs()
//                ----------------------
{
  
  _param_vectors = new_wxWindow_ptr(ImageDraw_VectorsParam,this);
  _param_vectors->Hide();

} // CreeParametresVecteurs()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresCircles()
//                           -------------------
{

  _param_circles = new_wxWindow_ptr(ImageDraw_CirclesParam,this);
  _param_circles->Hide();

} // CreeParametresCircles()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresMIP()
//                           -----------------
{

  _param_mip = new_wxWindow_ptr(ImageDraw_MIPParam,this);
  _param_mip->Hide();
  
} // CreeParametresMIP()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresMIP_stereo()
//                           ------------------------
{

  //=============
  _param_MIP_stereo = new ParamBox( this,  FrAn("Param�res MIP St��",
                                                        "Stereo MIP parameters"));

//  printf("_distance_yeux %f\n",_distance_yeux);
  //-------------- Distance entre les 2 yeux
  _param_MIP_stereo->AddFloat( &_id_distance_yeux, &_distance_yeux,
                                  FrAn("Dist. yeux","Eyes dist."));
  _param_MIP_stereo->FloatConstraints( _id_distance_yeux, 5.0, 8.0, _distance_yeux);
  _param_MIP_stereo->ChangedValueCallback( _id_distance_yeux,
                                   (void*) DessinImage::CB_MIP_stereo_param,
                                   (void*) this);

//  printf("_distance_oeil_ecran %f\n",_distance_oeil_ecran);
  //-------------- Distance oeil �ran
  _param_MIP_stereo->AddFloat( &_id_distance_oeil_ecran, &_distance_oeil_ecran,
                                  FrAn("Dist oeil-ecran","Dist eye-screen"));
  _param_MIP_stereo->FloatConstraints( _id_distance_oeil_ecran, 10.0, 60.0, _distance_oeil_ecran);
  _param_MIP_stereo->ChangedValueCallback( _id_distance_oeil_ecran,
                                   (void*) DessinImage::CB_MIP_stereo_param,
                                   (void*) this);

//  printf("_distance_ecran_objet %f\n",_distance_ecran_objet);
  //-------------- Distance �ran objet
  _param_MIP_stereo->AddFloat( &_id_distance_ecran_objet, &_distance_ecran_objet,
                                  FrAn("Dist ecran-objet","Dist screen-objet"));
  _param_MIP_stereo->FloatConstraints( _id_distance_ecran_objet, 3.0, 60.0, _distance_ecran_objet);
  _param_MIP_stereo->ChangedValueCallback( _id_distance_ecran_objet,
                                   (void*) DessinImage::CB_MIP_stereo_param,
                                   (void*) this);

//  printf("_pixel_cm %f\n",_pixel_cm);
  //-------------- Nombre de pixels par cm
  _param_MIP_stereo->AddFloat( &_id_pixel_cm, &_pixel_cm,
                                  FrAn("Pixels par cm","Pixels per cm"));
  _param_MIP_stereo->FloatConstraints( _id_pixel_cm, 20.0, 50.0, _pixel_cm);
  _param_MIP_stereo->ChangedValueCallback( _id_pixel_cm,
                                   (void*) DessinImage::CB_MIP_stereo_param,
                                   (void*) this);


  //---------- Creation de la boite de parametres
  _param_MIP_stereo->CreeDialogue( );

} // CreeParametresMIP_stereo()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresCoupesXY()
//                           ----------------------
{

  _param_coupesxy = new_wxWindow_ptr(ImageDraw_CoupesXYParam,this);
  _param_coupesxy->Hide();

} // CreeParametresCoupesXY()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresAnimation()
//                           -----------------------
{
  
  _param_animation = new_wxWindow_ptr(ImageDraw_AnimationParam,this);
  _param_animation->Hide();

} // CreeParametresAnimation()


//-----------------------------------------------------------------------
//void DessinImage::CreeParametresIsoContour(ParamBox* pb)
void DessinImage::CreeParametresIsoContour()
//                ------------------------
{
    
  _param_isocontour = new_wxWindow_ptr(ImageDraw_IsoContourParam,this);
  _param_isocontour->Hide();


} // CreeParametresIsoContour()

//-----------------------------------------------------------------------
//void DessinImage::CreeParametresImageSurface(ParamBox* pb)
void DessinImage::CreeParametresImageSurface()
//                --------------------------
{

  _param_imagesurface = new_wxWindow_ptr(ImageDraw_ImageSurfaceParam,this);
  _param_imagesurface->Hide();


} // CreeParametresImageSurface()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresVoxels3D()
//                           ----------------------
{

  _param_voxels3D = new_wxWindow_ptr(ImageDraw_Voxels3DParam,this);
  _param_voxels3D->Hide();
  
} // CreeParametresVoxels3D()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresGLMIP()
//                           ----------------------
{

  _param_glmip = new_wxWindow_ptr(ImageDraw_GLMIPParam,this);
  _param_glmip->Hide();

} // CreeParametresGLMIP()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresVOLREN()
//                           --------------------
{

  _param_volren = new_wxWindow_ptr(ImageDraw_VolRenParam,this);
  _param_volren->Hide();

} // CreeParametresVOLREN()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresSections3D()
//                           ------------------------
{

  _param_sections3D = new_wxWindow_ptr(ImageDraw_Sections3DParam,this);
  _param_sections3D->Hide();


} // CreeParametresSections3D()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresZoomFacteur()
//                           -------------------------
{

  _param_zoomfactor = new_wxWindow_ptr(ImageDraw_ZoomFactorParam,this);
  _param_zoomfactor->Hide();

} // CreeParametresZoomFacteur


//-----------------------------------------------------------------------
void DessinImage::CreeParametresCouleurs()
//                           ----------------------
{
  _param_colors = new_wxWindow_ptr(ImageDraw_ColorsParam,this);
  _param_colors->Hide();

} // CreeParametresCouleurs()


//-----------------------------------------------------------------------
void DessinImage::CreeSauveParametres()
//                           -------------------
{

/* Deprecated
  //-----
  _param_sauve_image = new ParamBox( this, FrAn(" Nom de l'image"," Image name"));

  //----- Nom du fichier
  _param_sauve_image->AddFilename( &_id_sauve_image,  &_nom_sauve_image,
                    FrAn(" Nom:"," Name:"));
  _param_sauve_image->ContraintesNomFichier( _id_sauve_image, "", ".", "*.inr*");

  //----- Type de sauvegarde

  _param_sauve_image->AddEnumeration( &_id_type_sauvegarde, 3, &_type_sauvegarde,
                     FrAn("TYPE SAUVEGARDE",
                          "SAVE TYPE"       ));
  _param_sauve_image->AddEnumChoice( _id_type_sauvegarde, &_id_inrimage,
                       "INRIMAGE");
  _param_sauve_image->AddEnumChoice( _id_type_sauvegarde, &_id_postscript_gris,
                       FrAn("POSTSCRIPT Niveaux Gris","Greyscale POSTSCRIPT"));
  _param_sauve_image->AddEnumChoice( _id_type_sauvegarde, &_id_postscript_couleur,
                       FrAn("POSTSCRIPT Couleur","Color POSTSCRIPT"));

  _param_sauve_image->EnumerationDefaut( _id_type_sauvegarde, _id_inrimage);

  //----- Format inrimage
  _param_sauve_image->AddEnumeration( &_id_image_format, 9, &_format_image ,
                     "FORMAT");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_uchar,
                       " WT_UNSIGNED_CHAR ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_ushort,
                       " WT_UNSIGNED_SHORT ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_sshort,
                       " WT_SIGNED_SHORT ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_uint,
                       " WT_UNSIGNED_INT ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_sint,
                       " WT_SIGNED_INT ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_ulong,
                       " WT_UNSIGNED_LONG ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_slong,
                       " WT_SIGNED_LONG ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_float,
                       " WT_FLOAT ");

  _param_sauve_image->AddEnumChoice( _id_image_format, &_id_format_double,
                       " WT_DOUBLE ");

  _param_sauve_image->EnumerationDefaut( _id_image_format, _id_format_uchar);

  _param_sauve_image->CreeDialogue();
*/
} //  CreeSauveParametres()


//-----------------------------------------------------------------------
void DessinImage::CreeParametresInfo()
//                           ------------------
{

  _param_image_info = new_wxWindow_ptr(ImageDraw_InfoParam,this);
  _param_image_info->Hide();

} // CreeParametresInfo()


//-----------------------------------------------------------------------
void DessinImage::CreeBoitesParametres()
//                --------------------
{

/*
    int dimx, dimy;
    int posx, posy;
*/

  Si GB_debug AlorsFait printf("CreeBoitesParametres\n");

//  _param_dialog = new ParamBox( this, "Parameters");
//  _param_dialog->BeginBook();

  /*CreeFenetreParametres(     _param_dialog);
  CreeParametresVecteurs(    _param_dialog);
  CreeParametresIsoContour(  _param_dialog);
  CreeParametresImageSurface(_param_dialog);*/
  CreeFenetreParametres();
  CreeParametresVecteurs();
  CreeParametresIsoContour();
  CreeParametresImageSurface();
//  _param_dialog->EndBook();
//  _param_dialog->EnleveBouttons();
//  _param_dialog->CreeDialogue( );

/*
  Recupere_fenetre_position( &posx, &posy);
  _param_dialog->RecupereDimensions( &dimx, &dimy);

  posx = macro_max( 0, posx-dimx-15);
  posy = macro_max( 0, posy);
// std::cout << "pos x " << posx << "  pos y " << posy << std::endl;
  _param_dialog->FixePosition( posx, posy);
*/

  CreeParametresVoxel();
  CreeParametresCircles();
  CreeParametresMIP();
  CreeParametresMIP_stereo();

  Si _image->_tz > 1 AlorsFait CreeParametresCoupesXY();
  CreeParametresAnimation();
  CreeParametresZoomFacteur();
  CreeParametresGLMIP();
  CreeParametresVOLREN();
  CreeParametresVoxels3D();
  CreeParametresSections3D();
  CreeSauveParametres();
  CreeParametresInfo();

  //-----
/* Deprecated
  _param_nom_image = new ParamBox( this, FrAn(" Nom de l'image"," Image name"));

  _param_nom_image->AddFilename( &_id_nom_image,  &_nom_nouvelle_image, FrAn(" Nom:"," Name:"));
  _param_nom_image->ContraintesNomFichier( _id_nom_image, "", ".", "*.inr*");

  _param_nom_image->CreeDialogue();
*/
 /*
  //-----
  _param_nom_fichier = new ParamBox( this, FrAn(" Nom du fichier","File name"));

  _param_nom_fichier->AddFilename( &_id_nom_fichier,  &_nom_fichier, FrAn(" Nom:"," Name:"));
  _param_nom_fichier->ContraintesNomFichier( _id_nom_fichier, "", ".", "*.fic");

  _param_nom_fichier->CreeDialogue();
*/

/*
  //-----
  _param_nom_tc = new ParamBox( this, " Nom de la table de couleurs");

  _param_nom_tc->AddFilename( &_id_nom_tc,  &_nom_tc, " Nom :");
  _param_nom_tc->ContraintesNomFichier( _id_nom_tc, "", ".", "*.tc");

  _param_nom_tc->CreeDialogue();
*/

//  _param_dialog->FermeDialogue( );
//  Param._parametres_visible = false;
//  _Moptions_parametres_visible->MAJ();

} // CreeBoitesParametres()


//-----------------------------------------------------------------------
void DessinImage::CreeBoitesParametres2()
//                           --------------------
{

  CreeParametresCouleurs();

  /* TODO move to wxwidgets
  Si  Param._parametres_visible Et
      Non(_interpole_ligne->WidgetCreated())
  Alors
    _interpole_ligne->CreeWidget(_palette);
    _interpole_ligne->Fixe_drawing_bg( wxCplour(255,255,255));
    _interpole_ligne->Paint();
  FinSi
  */


} // CreeBoitesParametres2()


//----------------------------------------------------------------
void DessinImage::DessineCurseurs(  int x, int y, int z)
//                           ---------------
//  Dessine la position du curseur sur toutes les coupes
{

  DessineCurseur(x,y,z,Param._curseur._type);
  Comparaisons_DessineCurseur( x, y, z);

} // DessineCurseurs()


//----------------------------------------------------------------
void DessinImage::DessineScrollBar( int image)
//                ---------------
//  Dessine la position du curseur sur toutes les coupes
{
    // position de l'image
    int xmin,ymin,largeur,hauteur;
    // position et dimensions de l'image
    int val_xmin=0,val_xmax=0,val_ymin=0,val_ymax=0;
    // position min et max visibles apres le zoom de l'image
    int zoom_xmin=1,zoom_xmax=1,zoom_ymin=1,zoom_ymax=1;
    ClasseCouleur blanc,noir;

  xmin = _tab_ximage_pos_x[image];
  ymin = _tab_ximage_pos_y[image];

#if defined(__WXMOTIF__)
  largeur = _tab_ximage[image]->width;
  hauteur = _tab_ximage[image]->height;
#else
  largeur = _tab_slices[image].image->GetWidth();
  hauteur = _tab_slices[image].image->GetHeight();
#endif

  switch ( image ){
    case IMAGE_XY:
      val_xmin  = val_ymin = 0;
      val_xmax  = _image->_tx-1;
      val_ymax  = _image->_ty-1;
      zoom_xmin = Param._Zoom._xmin;
      zoom_xmax = Param._Zoom._xmax;
      zoom_ymin = Param._Zoom._ymin;
      zoom_ymax = Param._Zoom._ymax;
    break;

    case IMAGE_XZ:
      val_xmin  = val_ymin = 0;
      val_xmax  = _image->_tx-1;
      val_ymax  = _image->_tz-1;
      zoom_xmin = Param._Zoom._xmin;
      zoom_xmax = Param._Zoom._xmax;
      zoom_ymin = Param._Zoom._zmin;
      zoom_ymax = Param._Zoom._zmax;
    break;

    case IMAGE_ZY:
      val_xmin  = val_ymin = 0;
      val_xmax  = _image->_tz-1;
      val_ymax  = _image->_ty-1;
      zoom_xmin = Param._Zoom._zmin;
      zoom_xmax = Param._Zoom._zmax;
      zoom_ymin = Param._Zoom._ymin;
      zoom_ymax = Param._Zoom._ymax;
    break;

  } // end switch

  blanc = _tab_intensite_couleur[255];
  noir  = _tab_intensite_couleur[0];

  // ScrollBar Horizontal
  SetPenColor(       noir);
  FixeCouleurRemplissage( blanc);
  Rectangle( xmin, ymin-4, xmin + largeur , ymin-1);
  FixeCouleurRemplissage( noir);
  Rectangle( xmin  + (int) (1.0*largeur*(zoom_xmin-val_xmin)/(val_xmax-val_xmin+1)),
             ymin-4,
             xmin  + (int) (1.0*largeur*(zoom_xmax+1-val_xmin)/(val_xmax-val_xmin+1)),
             ymin-1);

  // ScrollBar Vertical
  SetPenColor(       noir);
  FixeCouleurRemplissage( blanc);
  Rectangle( xmin-4, ymin, xmin - 1, ymin + hauteur);
  FixeCouleurRemplissage( noir);
  Rectangle( xmin - 4,
             ymin + (int) (1.0*hauteur*(zoom_ymin-val_ymin)/(val_ymax-val_ymin+1)),
             xmin - 1,
             ymin + (int) (1.0*hauteur*(zoom_ymax+1-val_ymin)/(val_ymax-val_ymin+1)) );
} // DessineScrollBar()


//----------------------------------------------------------------
void DessinImage::ProjetteVecteur(  int x, int y, float vx, float vy)
//                           --------------
{

  int x1, y1, x2, y2;
  float   norme_vect,coeff;

  switch ( _vecteur_type ){

    case VECTEUR_FLECHE:
      x1 = (int) (x+_taille_vecteur*vx);
      y1 = (int) (y+_taille_vecteur*vy);
      norme_vect = sqrt(vx*vx+vy*vy);
      Ligne( x, y, x1, y1);
      Si norme_vect > 1E-5 Alors
        Ligne( x1, y1, (int) (x1-6*(vx+vy)/norme_vect), (int) (y1-6*(vy-vx)/norme_vect) );
        Ligne( x1, y1, (int) (x1-6*(vx-vy)/norme_vect), (int) (y1-6*(vy+vx)/norme_vect) );
      FinSi
    break;

    case VECTEUR_DIRECTION:
      x1 = (int) (x-_taille_vecteur*vx);
      y1 = (int) (y-_taille_vecteur*vy);
      x2 = (int) (x+_taille_vecteur*vx);
      y2 = (int) (y+_taille_vecteur*vy);
      Ligne( x1, y1, x2, y2);
    break;

    case VECTEUR_FLECHE_PROP:
      x1 = (int) (x+_taille_vecteur*vx);
      y1 = (int) (y+_taille_vecteur*vy);
      norme_vect = sqrt(vx*vx+vy*vy);
      Ligne( x, y, x1, y1);
      Si norme_vect > 1E-5 Alors
        coeff = _taille_vecteur*0.15;
        Ligne( x1, y1, (int) (x1-coeff*(vx+vy)+0.5), (int) (y1-coeff*(vy-vx)+0.5) );
        Ligne( x1, y1, (int) (x1-coeff*(vx-vy)+0.5), (int) (y1-coeff*(vy+vx)+0.5) );
      FinSi
    break;

  } // end switch

} // ProjetteVecteur()


//----------------------------------------------------------------
void DessinImage::DrawVector( int vect_id, int x, int y, int z,
//                ----------
                          int type_coupe )
//  Dessine la valeur du vecteur pour le champ de vecteurs donn�// au point (x,y,z)  sur toutes les coupes
{
  if ((vect_id<0)||(vect_id>=(int)_vector_fields.size())) return;
  vectorfield_info vf = _vector_fields[vect_id];
  if (vf.vector.expired())  return;
  if (!vf.visible)          return;

  int pos_x, pos_y;
  Vect3D<float> v;
  int x0,y0,z0;    // Position dans l'image initiale

  Si Param._option_traitement == OPTION_MIP Alors
    _MIP->PosPoint( x, y, x0, y0, z0);
  Sinon
    x0 = x; y0 = y; z0 =z;
  FinSi

  InrImage::ptr vect(vf.vector);

  if (!vf.interpolate) {
      v.x = (float) vect->GetValue(x0,y0,z0,0);
      v.y = (float) vect->GetValue(x0,y0,z0,1);
      v.z = (float) vect->GetValue(x0,y0,z0,2);
  } else {
      // convert coordinates
      float x1,y1,z1; // spatial coordinates
      x1 = _image->SpacePosX(x0);
      y1 = _image->SpacePosY(y0);
      z1 = _image->SpacePosZ(z0);
      // vectorial image coordinates
      x1 = vect->SpaceToVoxelX(x1);
      y1 = vect->SpaceToVoxelY(y1);
      z1 = vect->SpaceToVoxelZ(z1);
      // NOT THREAD SAFE: fixe vector coordinates is not thread safe ...
      v.x = (float) vect->InterpLinIntensite(x1,y1,z1,0);
      v.y = (float) vect->InterpLinIntensite(x1,y1,z1,1);
      v.z = (float) vect->InterpLinIntensite(x1,y1,z1,2);
  }

  // Return if vector too small
  if ((fabsf(v.x)<1E-10)&&(fabsf(v.y)<1E-10)&&(fabsf(v.z)<1E-10)) return;

  Si Param._option_traitement == OPTION_MIP Alors
    v = _MIP->ProjetteVecteur(v);
  FinSi

  Si type_coupe==-1 AlorsFait type_coupe = Param._type_coupe;

  if (_vector_distance_unit==VECTOR_IMAGE_PIXELS) {
      v.x *= _size_x;
      v.y *= _size_y;
      v.z *= _size_z;
  }

  SetPenColor( vf.color );
  // Tests selon le type de Coupe
  Si (type_coupe+1) & (TYPE_COUPE_XY+1) Alors
    pos_x = (int) (_tab_ximage_pos_x[IMAGE_XY] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) (_tab_ximage_pos_y[IMAGE_XY] + (y - Param._Zoom._ymin + 0.5)*_size_y);
    ProjetteVecteur( pos_x, pos_y, v.x , v.y);
  FinSi

  Si (type_coupe+1) & (TYPE_COUPE_XZ+1) Alors
    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_XZ] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_XZ] + (z - Param._Zoom._zmin + 0.5)*_size_z);
    ProjetteVecteur( pos_x, pos_y, v.x , v.z);
  FinSi

  Si (type_coupe+1) & (TYPE_COUPE_ZY+1) Alors
    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_ZY] + (z - Param._Zoom._zmin + 0.5)*_size_z);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_ZY] + (y - Param._Zoom._ymin + 0.5)*_size_y);
    ProjetteVecteur( pos_x, pos_y, v.z , v.y);
  FinSi

//  Comparaisons_DessineCurseur( x, y, z);

} // DrawVector()


//----------------------------------------------------------------
void DessinImage::DrawVectors(  int x, int y, int z,
//                           --------------
                          int type_coupe )
//  Dessine la valeur du vecteur pour le champ de vecteurs donn�// au point (x,y,z)  sur toutes les coupes
{
  int i;
  SetLineParameters( _largeur_lignes+1, PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);

  i=0;
  std::vector<vectorfield_info>::iterator Iter;
  for (Iter  = _vector_fields.begin();
       Iter != _vector_fields.end()  ; Iter++,i++ )
    if (!(*Iter).vector.expired())
      this->DrawVector(i,x,y,z,type_coupe);

  _vecteur_ON = Non(_vecteur_ON);
//  Comparaisons_DessineCurseur( x, y, z);

} // DrawVectors()


//----------------------------------------------------------------
void DessinImage::DessineChampVecteurs( )
//                  --------------------
{
    int     x,y,z;
    int     pas_x, pas_y,pas_z;

  if (_vector_distance_unit==VECTOR_IMAGE_PIXELS) {
    pas_x = (int) (_espacement_vecteur/Param._dim._voxel_size_x);
    pas_y = (int) (_espacement_vecteur/Param._dim._voxel_size_y);
    pas_z = (int) (_espacement_vecteur/Param._dim._voxel_size_z);
  } else {
    pas_x = (int)_espacement_vecteur;
    pas_y = (int)_espacement_vecteur;
    pas_z = (int)_espacement_vecteur;
  }

  Si pas_x == 0 AlorsFait pas_x = 1;
  Si pas_y == 0 AlorsFait pas_y = 1;
  Si pas_z == 0 AlorsFait pas_z = 1;

  SetLineParameters( _largeur_lignes+1, PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);

  // Tests selon le type de Coupe
  int i=0;
  std::vector<vectorfield_info>::iterator Iter;
  for (Iter  = _vector_fields.begin();
       Iter != _vector_fields.end()  ; Iter++,i++ )
    if ((!(*Iter).vector.expired())&&(i<3)) {
      if (GB_debug)
        fprintf(stderr,"DessineChampVecteurs() \t vector %d count %d \n",i,(int)(*Iter).vector.use_count());

      if ((Param._type_coupe+1) & (TYPE_COUPE_XY+1))
        for(x=Param._Zoom._xmin; x<=Param._Zoom._xmax;
            x+=pas_x)
        for(y=Param._Zoom._ymin; y<=Param._Zoom._ymax;
            y+=pas_y)
          DrawVector( i, x, y, Param._pos._z, TYPE_COUPE_XY);

      if ((Param._type_coupe+1) & (TYPE_COUPE_XZ+1))
        for(x=Param._Zoom._xmin; x<=Param._Zoom._xmax;
            x+=pas_x)
        for(z=Param._Zoom._zmin; z<=Param._Zoom._zmax;
            z+=pas_z)
          DrawVector( i, x, Param._pos._y, z, TYPE_COUPE_XZ);

      if ((Param._type_coupe+1) & (TYPE_COUPE_ZY+1))
        for(z=Param._Zoom._zmin; z<=Param._Zoom._zmax; z+=pas_z)
        for(y=Param._Zoom._ymin; y<=Param._Zoom._ymax; y+=pas_y)
          DrawVector( i, Param._pos._x, y, z, TYPE_COUPE_ZY);

    } // end if , for



} // DessineChampVecteurs



//----------------------------------------------------------------
void DessinImage::DessineCercle(  int x, int y, int z, ClasseCouleur& c)
//
{
    int pos_x, pos_y;
    int x0,y0,z0;    // Position dans l'image initiale
    int type_coupe;
    float val;
    ClasseCouleur coul;


  SetLineParameters( _largeur_lignes+1, PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);

  Si Param._option_traitement == OPTION_MIP Alors
    _MIP->PosPoint( x, y, x0, y0, z0);
  Sinon
    x0 = x; y0 = y; z0 =z;
  FinSi

  val = (*_image_initiale)(x0,y0,z0);

  Si val<_circles_min_radius Ou val>_circles_max_radius AlorsFait
    return;

  Si val<0 Alors
  //    printf("negative colors \n");
    coul = _circles_negative_color;
    val = -val;
  Sinon
    coul = _circles_positive_color;
  FinSi

  Si _circles_fill AlorsFait
    FixeCouleurRemplissage(coul);

  type_coupe = Param._type_coupe;

  // Tests selon le type de Coupe
  Si (type_coupe+1) & (TYPE_COUPE_XY+1) Alors

    pos_x = (int) (_tab_ximage_pos_x[IMAGE_XY] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) (_tab_ximage_pos_y[IMAGE_XY] + (y - Param._Zoom._ymin + 0.5)*_size_y);

    SetPenColor( coul );
    Si _circles_fill Alors
      RemplitEllipse(pos_x,pos_y,(int) (val*_size_x), (int) (val*_size_y));
    Autrement
      Ellipse(pos_x,pos_y,(int) (val*_size_x), (int) (val*_size_y));

  FinSi

  Si (type_coupe+1) & (TYPE_COUPE_XZ+1) Alors

    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_XZ] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_XZ] + (z - Param._Zoom._zmin + 0.5)*_size_z);

    SetPenColor( coul );
    Si _circles_fill Alors
      RemplitEllipse(pos_x,pos_y, (int) (val*_size_x), (int) (val*_size_z));
    Autrement
      Ellipse(pos_x,pos_y, (int) (val*_size_x), (int) (val*_size_z));

  FinSi


  Si (type_coupe+1) & (TYPE_COUPE_ZY+1) Alors

    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_ZY] + (z - Param._Zoom._zmin + 0.5)*_size_z);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_ZY] + (y - Param._Zoom._ymin + 0.5)*_size_y);

    SetPenColor( coul );
    Si _circles_fill Alors
      RemplitEllipse(pos_x,pos_y,(int) (val*_size_y),(int) (val*_size_z));
    Autrement
      Ellipse(pos_x,pos_y,(int) (val*_size_y),(int) (val*_size_z));

  FinSi

  _vecteur_ON = Non(_vecteur_ON);



} // DessineCercle()


//----------------------------------------------------------------
void DessinImage::DessineChampCercles( )
//                           -------------------
{


    int     x,y,z;
    int     pas_x, pas_y,pas_z;

  pas_x = 1;
  pas_y = 1;
  pas_z = 1;

  // Tests selon le type de Coupe

  Si (Param._type_coupe+1) & (TYPE_COUPE_XY+1) Alors

  for(  x = Param._Zoom._xmin  ;  x <= Param._Zoom._xmax  ;  x += pas_x  Faire
  for(  y = Param._Zoom._ymin  ;  y <= Param._Zoom._ymax  ;  y += pas_y  Faire

    DessineCercle( x, y, Param._pos._z, _vector_fields[0].color);

  } // end for // y
  } // end for // x

  FinSi

  Si (Param._type_coupe+1) & (TYPE_COUPE_XZ+1) Alors

  for(  x = Param._Zoom._xmin  ;  x <= Param._Zoom._xmax  ;  x += pas_x  Faire
  for(  z = Param._Zoom._zmin  ;  z <= Param._Zoom._zmax  ;  z += pas_z  Faire

    DessineCercle( x, Param._pos._y, z, _vector_fields[0].color);

  } // end for // z
  } // end for // x

  FinSi

  Si (Param._type_coupe+1) & (TYPE_COUPE_ZY+1) Alors

  for(  z = Param._Zoom._zmin  ;  z <= Param._Zoom._zmax  ;  z += pas_z  Faire
  for(  y = Param._Zoom._ymin  ;  y <= Param._Zoom._ymax  ;  y += pas_y  Faire

    DessineCercle( Param._pos._x, y, z, _vector_fields[0].color);

  } // end for // y
  } // end for // z

  FinSi

} // DessineChampCercles()


//----------------------------------------------------------------
void DessinImage::DessineLigneDansMIP(
//                           -------------------
                         const Point_3D<int>& p1,
                         const Point_3D<int>& p2,
                         unsigned char pointilles)
//  Dessine une Ligne dans la  MIP
{


    float    x,y,z;
    int  pos_x, pos_y, pos_x0, pos_y0;
//    Point3D point;

  _MIP->Projection2( p1.x, p1.y, p1.z, &x, &y, &z);
  pos_x0 = (int) (_tab_ximage_pos_x[IMAGE_XY] +
             (x - Param._Zoom._xmin + 0.5)*_size_x);
  pos_y0 = (int) (_tab_ximage_pos_y[IMAGE_XY] +
             (y - Param._Zoom._ymin + 0.5)*_size_y);

  _MIP->Projection2( p2.x, p2.y, p2.z, &x, &y, &z);
  pos_x = (int) (_tab_ximage_pos_x[IMAGE_XY] +
            (x - Param._Zoom._xmin + 0.5)*_size_x);
  pos_y = (int) (_tab_ximage_pos_y[IMAGE_XY] +
            (y - Param._Zoom._ymin + 0.5)*_size_y);

  Si pointilles AlorsFait
    SetLineParameters( 1, wxDOT, wxCAP_ROUND, wxJOIN_MITER);

  Ligne( pos_x0, pos_y0, pos_x, pos_y);

  Si pointilles AlorsFait
    SetLineParameters( 1,  PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);

} // DessineLigneDansMIP()


//----------------------------------------------------------------
void DessinImage::DessineBoundingBox( )
//                           ------------------
//  Dessine une bounding box dans la projection MIP
{


//    float    facteur_dc; // facteur de depthcueing
    int  xmin,ymin,zmin,xmax,ymax,zmax;
    Point_3D<int> p[8];
    float    x,y,z, maxz=0;
    int  i,imax=0;

  xmin = ymin = zmin = 0;
  xmax = _image_initiale->_tx -1;
  ymax = _image_initiale->_ty -1;
  zmax = _image_initiale->_tz -1;

  SetLineParameters( 1,  PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);
  SetPenColor( _couleur_curseur);

  // Initialisation des 8 sommets du cube
  p[0].Init(xmin, ymin, zmin);
  p[1].Init(xmax, ymin, zmin);
  p[2].Init(xmin, ymax, zmin);
  p[3].Init(xmax, ymax, zmin);
  p[4].Init(xmin, ymin, zmax);
  p[5].Init(xmax, ymin, zmax);
  p[6].Init(xmin, ymax, zmax);
  p[7].Init(xmax, ymax, zmax);

  // Recherche du point le plus eloigne
  Pour( i, 0, 7)
    _MIP->Projection2( p[i].x, p[i].y, p[i].z, &x, &y, &z);
    Si i==0 Alors
      maxz = z;
      imax = 0;
    Sinon
      Si z>maxz Alors
        maxz = z;
        imax = i;
      FinSi
    FinSi
  FinPour

  //--- Plan XY avec Z = zmin
  DessineLigneDansMIP( p[0], p[1], ((imax==0)||(imax==1)));
  DessineLigneDansMIP( p[0], p[2], ((imax==0)||(imax==2)));
  DessineLigneDansMIP( p[3], p[1], ((imax==3)||(imax==1)));
  DessineLigneDansMIP( p[3], p[2], ((imax==3)||(imax==2)));

  //--- Plan XY avec Z = zmax
  DessineLigneDansMIP( p[4], p[5], ((imax==4)||(imax==5)));
  DessineLigneDansMIP( p[4], p[6], ((imax==4)||(imax==6)));
  DessineLigneDansMIP( p[7], p[5], ((imax==7)||(imax==5)));
  DessineLigneDansMIP( p[7], p[6], ((imax==7)||(imax==6)));

  //--- Liens entre les 2 plans
  DessineLigneDansMIP( p[0], p[4], ((imax==0)||(imax==4)));
  DessineLigneDansMIP( p[1], p[5], ((imax==1)||(imax==5)));
  DessineLigneDansMIP( p[2], p[6], ((imax==2)||(imax==6)));
  DessineLigneDansMIP( p[3], p[7], ((imax==3)||(imax==7)));

} // DessineBoundingBox()


//----------------------------------------------------------------
void DessinImage::DessineStereo( )
//                           -------------
//  Dessine une MIP en stereo
{
  std::cerr << "DessinImage::DessineStereo( ) feature disabled " << std::endl;

/* TODO: decide if I keep this feature ...

    CompareImage*   im_stereo;
    int          posx,posy;
    XImage*         image[2];
    XImage*         image_stereo;

  im_stereo = (CompareImage*) _tab_compare_image[ _MIP_num_stereo];

  image[0] =_tab_ximage[ IMAGE_XY];
  image[1] = im_stereo ->GetImage(    IMAGE_XY);

  posx = _tab_ximage_pos_x[IMAGE_XY];
  posy = _tab_ximage_pos_y[IMAGE_XY];

//  _MIP_OBJ_stereo->Parametres( _distance_yeux, _distance_oeil_ecran,
//                               _distance_ecran_objet,_pixel_cm/_size_y);

  _MIP_OBJ_stereo->Parametres( 0, _distance_oeil_ecran,
                               _distance_ecran_objet,_pixel_cm/_size_y);

  _MIP_OBJ_stereo->CreeStereo( _palette, image[0],image[1],&image_stereo);
  PlaceImage( posx, posy, image_stereo);
*/
} // DessineStereo()


//----------------------------------------------------------------
void DessinImage::MAJ_Image()
//                           ---------
// Met �jour tous les param�res de l'image "_image"
// et affiche l'image
{
  ImageDraw_PositionParam::ptr p ( _param_position);
  
  Param._MAJ.MAJCoupes();
  Param._MAJ._intensite = true;
  Param._MAJ._positions = true;

  Si Param._pos._z < 0            AlorsFait Param._pos._z = 0;
  Si Param._pos._z >= _image->_tz AlorsFait Param._pos._z = _image->_tz - 1;

  Si Param._pos._y < 0            AlorsFait Param._pos._y = 0;
  Si Param._pos._y >= _image->_ty AlorsFait Param._pos._y = _image->_ty - 1;

  Si Param._pos._x < 0            AlorsFait Param._pos._x = 0;
  Si Param._pos._x >= _image->_tx AlorsFait Param._pos._x = _image->_tx - 1;

  InitMinMax(_image);

//  Si _image->_tx > 1 AlorsFait _param_dialog->UpdateParameter( _id_planX);
//  Si _image->_ty > 1 AlorsFait _param_dialog->UpdateParameter( _id_planY);
//  Si _image->_tz > 1 AlorsFait _param_dialog->UpdateParameter( _id_planZ);
  
  Si _image->_tx > 1 AlorsFait p->UpdateParameter(p->_id_planX);
  Si _image->_ty > 1 AlorsFait p->UpdateParameter(p->_id_planY);
  Si _image->_tz > 1 AlorsFait p->UpdateParameter(p->_id_planZ);


} // MAJ_Image()


//----------------------------------------------------------------
void DessinImage::InitComparaisons()
//                           ----------------
{

/*
   int i;

  _compare_max = 10;
  _tab_compare_image = new CompareImage*[_compare_max+1];

  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    _tab_compare_image[i] = NULL;
  } // end for // i

*/
//  _compare_max = 0;
//  _nombre_comparaisons = 0;

} // InitComparaisons()


//----------------------------------------------------------------
void DessinImage::Comparaisons_UpdateStatusInfo( const Point_3D<int>& imagepos, int trouve)
//                  -----------------------------
{

  if (GB_debug)
    fprintf(stderr,"start testing _tab_compare_image\n");

  _comparison_lock = true;
/* Deprecated ...

  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->MAJ_label(im_x, im_y, im_z, trouve);
    FinSi
  } // end for // i
*/
  if (GB_debug)
    fprintf(stderr,"start testing _tab_compare_image2\n");

  std::list<compare_info>::iterator Iter;
  Iter  = _tab_compare2_image.begin();
  while (Iter != _tab_compare2_image.end() )
 {
  CLASS_MESSAGE(boost::format("(*Iter).di.use_count() = %d")
                %(int)(*Iter).di.use_count());
    if (!(*Iter).di.expired()) {
      // need to convert spatial coordinates
      InrImage::ptr input = this->GetImage();
      float px,py,pz;
      px = input->SpacePos(0,(float) imagepos.X());
      py = input->SpacePos(1,(float) imagepos.Y());
      pz = input->SpacePos(2,(float) imagepos.Z());
      InrImage::ptr input2 = ((*Iter).di.lock())->GetImage();
      Point_3D<int> newpos( (int) round(input2->SpaceToVoxelX(px)),
                            (int) round(input2->SpaceToVoxelY(py)),
                            (int) round(input2->SpaceToVoxelZ(pz)));
      ((*Iter).di.lock())->UpdateStatusInfo(newpos, trouve);
    } else {
        CLASS_MESSAGE("Removing deleted image from list");
        // Safely removing an element
        // by assigning the result to the current
        // iterator ...
        Iter = _tab_compare2_image.erase(Iter);
        continue;
    }
   Iter++;

 }

  _comparison_lock = false;

  if (GB_debug)  fprintf(stderr,"end\n");

} // Comparaisons_UpdateStatusInfo()


//----------------------------------------------------------------
void DessinImage::UpdateStatusInfo( const Point_3D<int>& imagepos,  int trouve)
//                --------------
{

  CLASS_MESSAGE("Begin");

  if (_comparison_lock) return;

  Si (trouve != -1) Alors
    UpdateStatusIntensity( imagepos.x, imagepos.y, imagepos.z);
    UpdateStatusPosition(  imagepos.x, imagepos.y, imagepos.z);

    Comparaisons_UpdateStatusInfo( imagepos, trouve);

  Sinon
    _status_text = "Out of limits";
    SetStatusText(wxString::FromAscii(_status_text.c_str()),_intensity_statusid);
    SetStatusText(wxString::FromAscii("---"),               _voxelpos_statusid);
    SetStatusText(wxString::FromAscii("---"),               _spatialpos_statusid);
  FinSi


  CLASS_MESSAGE("End");

} // UpdateStatusInfo()


//----------------------------------------------------------------
void DessinImage::Comparaisons_Paint( )
//                           ------------------
{
//    int i;
    DessinImage::ptr di;

  _comparison_lock=true;

/*
  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
    printf("comparing image %d \n",i);
      ((CompareImage*) _tab_compare_image[i])->RecupereParametres();
      ((CompareImage*) _tab_compare_image[i])->Paint( true);
    FinSi
  } // end for // i
*/

  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
  {
    if ((*Iter).di.use_count()) {
      di = (*Iter).di.lock();
      if (di->_comparison_lock) continue;

      if (di->_compare_depend_position) {
        RecupereTypeCoupe( &di->Param._type_coupe);
        //        RecuperePosition ( di->Param);
        float px = _image->SpacePosX(Param._pos._x);
        float py = _image->SpacePosY(Param._pos._y);
        float pz = _image->SpacePosZ(Param._pos._z);
        di->Param._pos._x = (int) di->_image->SpaceToVoxelX(px);
        di->Param._pos._y = (int) di->_image->SpaceToVoxelY(py);
        di->Param._pos._z = (int) di->_image->SpaceToVoxelZ(pz);

        // convert the limits too ...
        // TODO: improve code here using vectors or intervals ...
        di->Param._Zoom._xmin = (int) di->_image->SpaceToVoxelX(_image->SpacePosX(Param._Zoom._xmin));
        di->Param._Zoom._xmax = (int) di->_image->SpaceToVoxelX(_image->SpacePosX(Param._Zoom._xmax));
        di->Param._Zoom._ymin = (int) di->_image->SpaceToVoxelY(_image->SpacePosY(Param._Zoom._ymin));
        di->Param._Zoom._ymax = (int) di->_image->SpaceToVoxelY(_image->SpacePosY(Param._Zoom._ymax));
        di->Param._Zoom._zmin = (int) di->_image->SpaceToVoxelZ(_image->SpacePosZ(Param._Zoom._zmin));
        di->Param._Zoom._zmax = (int) di->_image->SpaceToVoxelZ(_image->SpacePosZ(Param._Zoom._zmax));

        // check zoom and cursor position
        di->Param.CheckPosition( di->_image );
      }
      RecupereOptionTraitement( &di->Param._option_traitement);
      if (di->_compare_depend_intensity) {
        if (di->_compare_normalize_intensity) {
          float pos_min=0, pos_max=0;
          RecupereIntervalleIntensiteNormalise( &pos_min,  &pos_max);
          di->_intensite_float_min = di->_val_min + pos_min*(di->_val_max - di->_val_min);
          di->_intensite_float_max = di->_val_min + pos_max*(di->_val_max - di->_val_min);
          di->_intensite_entier_min = (int) (di->_intensite_float_min);
          di->_intensite_entier_max = (int) (di->_intensite_float_max);
        }
        else
          RecupereIntervalleIntensite(
                   &di->_intensite_float_min,  &di->_intensite_float_max,
                   &di->_intensite_entier_min, &di->_intensite_entier_max);

        RecupereTypeCourbe(  &di->Param._I._type_courbe);
        RecupereTypeCurseur( &di->Param._curseur._type);
      }
      RecupereMAJ( di->Param );
      di->Paint( true);
    } // if use_count()
  } // iterator tab_compare2_image

  _comparison_lock=false;

} // Comparaisons_Paint()


//----------------------------------------------------------------
void DessinImage::Comparaisons_DessineCurseur( int x, int y, int z)
//                           ---------------------------
{
//    int i;

/*
  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->DessineCurseur( x, y, z, Param._curseur._type);
    FinSi
  } // end for // i
*/

  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
  {
    float cx,cy,cz; // cursor position
    cx = _image->SpacePosX(x);
    cy = _image->SpacePosY(y);
    cz = _image->SpacePosZ(z);

    if (!(*Iter).di.expired()) {
      if (!(*Iter).displ.expired()) {
        InrImage::ptr displ = (*Iter).displ.lock();
        // apply displacement to the cursor
        // is displacement is voxels or space coordinates?
        cx += (*displ)(x,y,z,0);
        cy += (*displ)(x,y,z,1);
        cz += (*displ)(x,y,z,2);
      }

     // Should we draw all images at the same position?
      ((*Iter).di.lock())->DessineSpatialCurseur(
                    cx, cy, cz,
                    Param._curseur._type);
    FinSi
  } // end for // i


} // Comparaisons_DessineCurseur()


//----------------------------------------------------------------
void DessinImage::Comparaisons_EffaceEcran( unsigned char expose)
//                           -------------------------
{


//    int i;

/*
  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->EffaceEcran( expose);
    FinSi
  } // end for // i
*/

  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
  {
    if (!(*Iter).di.expired())
      ((*Iter).di.lock())->EffaceEcran( expose);
  } // _tab_compare2_image iterator

} // Comparaisons_EffaceEcran()


//----------------------------------------------------------------
void DessinImage::Comparaisons_MAJ_taille( )
//                           -----------------------
{
//    int i;
    int h,l;

  Recupere_fenetre_dimensions(&l, &h);

/*
  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->Fixe_fenetre_dimensions( l, h);
    FinSi
  } // end for // i
*/

  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
    if (!(*Iter).di.expired())
      ((*Iter).di.lock())->Fixe_fenetre_dimensions( l, h);

} // Comparaisons_MAJ_taille()


//----------------------------------------------------------------
void DessinImage::Comparaisons_MemoriseCoupesXY( unsigned char activation )
//                           -----------------------------
{


//    int i;

/*
  for(  i = 0 ;  i < _compare_max ;  i++ Faire
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->MemoriseCoupesXY( activation);
    FinSi
  } // end for // i
*/
  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
    if (!(*Iter).di.expired())
      ((*Iter).di.lock())->MemoriseCoupesXY( activation);

} // Comparaisons_MAJ_taille()

//----------------------------------------------------------------
void DessinImage::LoadNewFont(  )
//                           -----------
{

#if defined(__WXMOTIF__)
  int num_fonts,i;
  char** fonts;
  fonts = XListFonts(display, "-misc-*-*-r-*-*-15-*-75-75-*-*-*-*",
                    10, &num_fonts);
  Si GB_debug Alors
    fprintf(stderr,"num fonts %d \n",num_fonts);
    Pour(i,0,num_fonts-1)
    printf("%s \n",fonts[i]);
    FinPour
  FinSi

  Si num_fonts>0 Alors
    _new_font = XLoadQueryFont(display,fonts[0]);
  Sinon
    XFreeFontNames(fonts);
    fonts = XListFonts(display, "-*-*-*-r-*-*-0-0-0-0-*-0-*-*",
                      10, &num_fonts);
    Si GB_debug Alors
      fprintf(stderr,"num fonts %d \n",num_fonts);
      Pour(i,0,num_fonts-1)
       printf("%s \n",fonts[i]);
      FinPour
    FinSi
    Si num_fonts>0 Alors
      _new_font = XLoadQueryFont(display,fonts[0]);
    Sinon
      _new_font = NULL;
    FinSi
  FinSi
  XFreeFontNames(fonts);
#endif

} // LoadNewFont()



//----------------------------------------------------------------
unsigned char DessinImage::CheckGLWindow()
//                              -------------
{
  return (!_GLWindow.expired());
} // CheckGLWindow()

//----------------------------------------------------------------
void DessinImage::ToggleParamPanel(ParamPanel* p)
{
  if (!(ParamIsDisplayed(p))) {
    AddParamPage(p,p->GetName(),true);
    p->MAJ();
    p->Refresh();
    p->Update();
    p->AfficheDialogue();
    p->Layout();
  } else {
    p->Hide();
    RemoveParamPage(p);
  }
}
  
//----------------------------------------------------------------
void DessinImage::CreateParamBook(wxWindow* parent)
{
   // create the notebook off-window to avoid flicker
   wxSize client_size = GetClientSize();

   _param_book = new wxAuiNotebook(this, wxID_ANY,
                                    wxPoint(client_size.x, client_size.y),
                                    wxDefaultSize,
                                    wxAUI_NB_TOP          |
                                    wxAUI_NB_TAB_SPLIT    |
                                    wxAUI_NB_TAB_MOVE
                                    |wxAUI_NB_WINDOWLIST_BUTTON
                                    |wxAUI_NB_SCROLL_BUTTONS
                                  );

  _param_book->Fit();

}  

//----------------------------------------------------------------
bool DessinImage::AddParamPage(wxWindow* page, const wxString& caption,
                            bool select, const wxBitmap& bitmap)
{
 std::cout << "DessinImage::AddParamPage()" << std::endl;
  bool result = _param_book->AddPage( page,caption,select,bitmap );
  manager.GetPane(_param_book).Show();
  manager.Update();
  _param_book->Layout();
  page->Show();
  page->Layout();
  return result;
} // AddParamPage()

//----------------------------------------------------------------
bool DessinImage::RemoveParamPage(wxWindow* page)
{
  bool result = _param_book->RemovePage( _param_book->GetPageIndex(page) );
  _param_book->Fit();
  if (_param_book->GetPageCount()==0)
     manager.GetPane(_param_book).Hide();
  manager.Update();
  return result;
} // RemoveParamPage()

//----------------------------------------------------------------
bool DessinImage::ParamIsDisplayed(wxWindow* page)
{
  return (_param_book->GetPageIndex(page)!=wxNOT_FOUND);
}
  
//======================================================================
// MEMBRES PUBLICS
//======================================================================


//----------------------------------------------------------------
// default int type=CREATE_WINDOW
//
DessinImage:: DessinImage(
//                       ------------
    wxWindow* parent,
    const std::string& ATitle, InrImage::ptr image, DessinParam::ptr param,
    int l, int h,   int type)
                               : DessinImageBase( parent, ATitle, l, h, type ) 
                                , m_timer(this)
                                ,_vector_fields(3)
{


    const char*  method = "DessinImage 3";

  if (GB_debug) printf("DessinImage::DessinImage title = %s \n",ATitle.c_str());

  Si GB_debug AlorsFait printf("DessinImage::DessinImage **\n");
  _param = DessinParam::ptr(param);

  Si GB_debug AlorsFait printf("DessinImage::DessinImage CreateWxMenu\n");
  CreateWxMenu();

  _image_initiale = _image = image;

  CreateStatusBar(3);
  int fieldwidths[3] = {-1,-2,-3};
  SetStatusWidths(3,fieldwidths);
  _intensity_statusid  = 0;
  _voxelpos_statusid   = 1;
  _spatialpos_statusid = 2;
  
  CreateParamBook(this);
  
  //Create image viewer toolbar
  Create_Toolbar();
  
  manager.SetManagedWindow(this);
  
  manager.SetFlags( 
                  wxAUI_MGR_ALLOW_FLOATING |
                  // Avoid problem with KDE desktop composing effect
                  #ifdef __WXGTK__ 
                    wxAUI_MGR_RECTANGLE_HINT |
                  #else
                   wxAUI_MGR_TRANSPARENT_HINT |
                  #endif
                  wxAUI_MGR_HINT_FADE |
                  wxAUI_MGR_NO_VENETIAN_BLINDS_FADE |
                  wxAUI_MGR_ALLOW_ACTIVE_PANE
                ); 
  
  //Add image to manager
  manager.AddPane(this->_drawing_window, 
                wxAuiPaneInfo()
                .Name(wxT("2D viewer"))
                .Caption(wxT("Image viewer"))
                //.MinSize(wxSize(200,200))
                .Center()
                .MaximizeButton(true)
                .CloseButton(false));
  
  //Add param_book to manager
  manager.AddPane(_param_book,
                  wxAuiPaneInfo()
                  .Name(wxT("Param Book"))
                  .Caption(wxT("Image Parameters"))
                  .MinSize(wxSize(200,100))
                  .BestSize(wxSize(300,200))
                  .Right().Layer(1)
                  .MaximizeButton(true)
                  .Hide()
                  );
  
  //Add toolbars to manager
  manager.AddPane(ViewStyle, wxAuiPaneInfo().
                  Name(wxT("ViewerToolbar1")).Caption(wxT("Viewer style toolbar")).
                  ToolbarPane().Top().Row(2).
                  LeftDockable(false).RightDockable(false));
  
  manager.AddPane(ViewParameters, wxAuiPaneInfo().
                  Name(wxT("ViewerToolbar2")).Caption(wxT("Viewer parameters toolbar")).
                  ToolbarPane().Top().Row(1).
                  LeftDockable(false).RightDockable(false));
    
  manager.Update();

  Si GB_debug AlorsFait printf("DessinImage::DessinImage ManageWidgets\n");

  Si GB_debug AlorsFait printf("DessinImage::DessinImage InitParameters\n");

  InitParametres();

  Si GB_debug AlorsFait printf("DessinImage::DessinImage AfficheFenetre\n");

  AfficheFenetre();
  InitPalette();
  LoadNewFont();
//      _new_font = NULL;


  Si GB_debug AlorsFait printf("DessinImage::DessinImage InitComparisons\n");

  //----- Initialisation des objets de comparaison
  InitComparaisons();

//  Fixe_drawing_attachment( _form, _form);
//  Fixe_fenetre_dimensions(l,h,true);

  Si GB_debug AlorsFait printf("DessinImage::DessinImage CreeBoitesParametres\n");

  // Creation des differentes boites de parametres
  CreeBoitesParametres();

  Si GB_debug AlorsFait printf("DessinImage::DessinImage CreeBoitesParametres2\n");

  CreeBoitesParametres2();

  Si GB_debug Alors
    printf("Fin DessinImage::%s\n",method);

    printf(" image  (%d %d %d) image initiale (%d %d %d) \n",
       image->_tx, image->_ty, image->_tz,
       _image_initiale->_tx,
       _image_initiale->_ty,
       _image_initiale->_tz );
  FinSi

  Show(true);
  int size = (ViewStyle->GetSize().GetWidth() > ViewParameters->GetSize().GetWidth())?
              ViewStyle->GetSize().GetWidth() : ViewParameters->GetSize().GetWidth();
  this->SetSize(size, size);
  this->Raise();

} // Constructor


//----------------------------------------------------------------
DessinImage::~DessinImage()
//                       -----------
{
//    int i;
  
  Si GB_debug AlorsFait printf("~DessinImage()  %s \n",
                   (char*)_name);


//  delete _MIP_OBJ_stereo;

  // TODO move _interpole_ligne to wxwidgets
  // delete _interpole_ligne;

/*
  Pour( i, 0,  _compare_max-1)
    Si _tab_compare_image[i] != NULL Alors
      LibereCompareImage(i,1);
    FinSi
  FinPour // i
*/
  // stop the time if it is running
  if ( m_timer.IsRunning() )
  {
      m_timer.Stop();
  }

  Si GB_debug AlorsFait printf("~DessinImage() %s Fin \n",
                   (char*)_name);

  manager.UnInit();
  
} // Destructor



//------------------------------------------------------------
void DessinImage::InitPalette()
//                -----------
{
  //  XWindowAttributes w_attrib;
    size_t n;
    int i;

  aff_err("DessinImage::InitPalette()\n");

//  XGetWindowAttributes(display, fenetre, & w_attrib);
//  _visual = w_attrib.visual;

  _couleur_curseur.FixeValeur(255,0,0);
  _vector_fields[0].color.FixeValeur( 0, 200, 0);
  _vector_fields[1].color.FixeValeur( 0, 0, 200);
  for(n=2;n<_vector_fields.size();n++) {
    _vector_fields[n].color.FixeValeur( 0, 200, 200);
  }

  // Circle Field positive and negative colors
  _circles_positive_color.FixeValeur( 0, 200, 0);
  _circles_negative_color.FixeValeur( 0, 200, 0);

  // Mask Color
  _couleur_masque = _couleur_curseur;

  Pour(i,0,MAX_ISOCONTOURS-1)

    switch ( i ){
      case 0:
        _isocontours[i].color.FixeValeur(250,0,0);
      break;
      case 1:
        _isocontours[i].color.FixeValeur(0,250,0);
        break;
      default:
        _isocontours[i].color.FixeValeur(0,0,250);
    } // end switch
  FinPour

  _couleur_fond  .FixeValeur(0,0,0);
  _couleur_objet .FixeValeur(255,255,255);
  _couleur_lignes.FixeValeur(255,0,0);


  aff_err("DessinImage::InitPalette() Fin\n");

} // InitPalette()


//------------------------------------------------------------
void DessinImage::InitParametres()
//                --------------
{
  // not executing Paint()
  _in_paint          = 0;
  _imsurf_zscale     = 1.0;
  _sectionXY_visible =
  _sectionXZ_visible =
  _sectionYZ_visible = false;
  _volren_mode       = VOLREN_IA;
  _volren_planes     = 8;
  _volren_texture    = true;
  _volren_power2dim  = true;

  if (_param.use_count()==0)
    _param = DessinParam::ptr(new DessinParam);
  // initialisation des parametres de l'image
  Param.InitParam( _image.get(), _param);

  // initialisation de l'image MIP
  _MIP = new ImageMIP( _image_initiale.get());
  _MIP->FixeVoxelSize( Param._dim._voxel_size_x,
               Param._dim._voxel_size_y,
               Param._dim._voxel_size_z);
  _MIP_stereo_lunettes = false;
  _distance_yeux        = 6.0;
  _distance_oeil_ecran  = 40.0;
  _distance_ecran_objet = 5.0;
  _pixel_cm             = 30.0;

/*
  _MIP_OBJ_stereo = new Stereo( _distance_yeux, _distance_oeil_ecran,
                _distance_ecran_objet,
                _pixel_cm);
*/

  _curseur_x = Param._pos._x;
  _curseur_y = Param._pos._y;
  _curseur_z = Param._pos._z;

  Si GB_debug AlorsFait printf("InitMinMax\n");

  InitMinMax(_image);

  // initialisation du tableau des coupes XY
  InitTabImagesXY();

  // Autres Parametres
  _type_facteur   = FACTEUR_REEL;
  _facteur_entier = 1;
  _facteur_reel   = 1.0;

  // Vector Field parameters
  // add 3 vectors
//printf("DessinImage::InitParametres() _vector_fields %d \n",(int)_vector_fields.size());
/*
  _vector_fields.push_back(InrImage::wptr());
  _vector_fields.push_back(InrImage::wptr());
  _vector_fields.push_back(InrImage::wptr());
*/
//printf("DessinImage::InitParametres() _vector_fields %d \n",(int)_vector_fields.size());

  _vecteur_ON        = false;
  _vecteur_type      = VECTEUR_FLECHE_PROP;
  _taille_vecteur = 1.0;
  _vector_distance_unit = VECTOR_IMAGE_PIXELS;
  _display_vectors = false;
  _espacement_vecteur = (int) (2*_taille_vecteur);


  // Circle Field parameters
  _circles_ON   = false;
  _circles_fill = false;
  _circles_min_radius = -0.99f;
  _circles_max_radius = 0.99f;


  // IsoContours parameters
  _all_contours     = false;
  _step_contours    = pow(10.0, (int) (log(_val_max - _val_min)/log(10.0)));
  _contours_winsize = _val_max-_val_min;

  _voxels3D_seuilbas  = _val_min;
  _voxels3D_seuilhaut = _val_max;

  _GLMIP_seuilbas  = _val_min;
  _GLMIP_seuilhaut = _val_max;

  // number of quads allowed = _GLMIP_maxquads*100,000
  _GLMIP_maxquads  = 3;

  _shift_deplace = _shift_zoom = false;

  Si GB_debug AlorsFait
    printf("InitParametres() %f %f \n",
       _voxels3D_seuilbas,
       _voxels3D_seuilhaut);

  _comparison_lock = false;

  _type_animation = TYPE_ANIM_FORWARD;
  _ANIM_vitesse   = 25;
  _ANIM_etat      = ANIM_PLAY;


} // InitParametres()


/*
//-------------------------------------------------------------------------
int  DessinImage::CreeCompareImage( char* titre, char* nom_image)
//                               ----------------
// Cette methode permet de creer un "clone"
// de l'image de dessin avec une autre image de memes dimensions
// et donc de comparer deux images
{
  InrImage::ptr     image;

  try{
    image = InrImage::ptr(new InrImage( nom_image));
  }
  catch (InrImage::ErreurLecture){
    wxMessageBox( wxString::FromAscii("Read error"),
                  wxString::FromAscii("Image"),
                  wxICON_ERROR);

    return -1;
  }

  return CreeCompareImage(titre,image,true);

} // CreeCompareImage()
*/


/*
//-------------------------------------------------------------------------
int  DessinImage::CreeCompareImage( char* titre,
//                               ----------------
                           InrImage::ptr image,
                           bool allocated_image)
// Cette methode permet de creer un "clone"
// de l'image de dessin avec une autre image de memes dimensions
// et donc de comparer deux images
{


    int    n,l,h;
    CompareImage* ci;

  Si GB_debug AlorsFait printf("CreeCompareImage \n");


  Si _nombre_comparaisons >= _compare_max Alors
    fprintf(stderr,"Erreur DessinImage::CreeCompareImage() \t trop d'images ...\n");
    return -1;
  FinSi

  // Recherche du premier ��ent non NULL du tableau
  n = 0;
  TantQue (n < _compare_max) Et (_tab_compare_image[n] != NULL) Faire
   n++;
  FinTantQue

  // Cr�tion de la nouvelle fen�re
  Recupere_fenetre_dimensions(&l, &h);

  ci = (CompareImage*) new CompareImage( this->GetParent(), titre,
                     image, this, l, h);

//  ci->SetAllocatedImage(allocated_image);

  _tab_compare_image[n] = ci;
  ci->NumeroFenetre(n);

  Si _palette->_type_palette == PALETTE_TC Alors
    ci->FixeTableCouleurs( (unsigned char*) _palette->_TC_RGB);
  FinSi

  ci->Fixe_fenetre_dimensions( l, h);

  _nombre_comparaisons++;

  return n;

} // CreeCompareImage()
*/

//-------------------------------------------------------------------------
int  DessinImage::CreeCompare2Image( DessinImage::ptr di)
//                               -----------------
// Cette methode permet de comparer avec
// un autre object du meme tytpe
//
{
  int    l,h;

  InrImage::ptr newimptr;
  DessinImage::wptr w_di(di);

  _tab_compare2_image.push_back(
      compare_info(w_di,InrImage::wptr(newimptr)));

  // Creation de la nouvelle fenetre
  Recupere_fenetre_dimensions(&l, &h);
  di->Fixe_fenetre_dimensions( l, h);

//  _nombre_comparaisons2++;
  return 1;

} // CreeCompare2Image()

//-----------------------------------------------------------
void DessinImage::SetCompareDisplacement( DessinImage::ptr compare_win, InrImage::ptr displ) {

  if (!displ->VectorialFormat()) {
    std::cerr << "DessinImage::SetCompareDisplacement() Image not in vectorial format \n";
    return;
  }

  // looking for the comparison window
  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
  {
    if ((*Iter).di.lock() == compare_win) {
      (*Iter).displ = displ;
      return;
    }
  }

  std::cerr << "DessinImage::SetCompareDisplacement() comparing window not found \n";

}

/*
//--------------------------------------------------
void DessinImage::LibereCompareImage( int num, unsigned char delete_window)
//                            ------------------
{

  printf("DessinImage::LibereCompareImage(%d) \n",num);
  if (_tab_compare_image[num]!=NULL) {
    if (delete_window) delete _tab_compare_image[num];
    _tab_compare_image[num] = NULL;
    _nombre_comparaisons--;
  }

}  // LibereCompareImage()
*/

//-------------------------------------------------------------------------
void DessinImage::ChangeImage( InrImage::ptr image, unsigned char Efface)
//                            -----------
// change l'image traitee, ce qui oblige a mettre a jour un
// certain nombre de parametres
// Cette procedure est utilisee pour permettre l'affichage des
// images MIP,
{

//  Si image == _image AlorsRetourne;

  ImageDraw_PositionParam::ptr p ( _param_position);
  
  _image = image;

  Param.InitParam( _image.get(), _param);
  Param._Zoom.InitLimites( _image.get());

//  _param_dialog->IntegerConstraints( _id_planX, 0, _image->_tx - 1, Param._pos._x);
//  _param_dialog->IntegerConstraints( _id_planY, 0, _image->_ty - 1, Param._pos._y);
//  _param_dialog->IntegerConstraints( _id_planZ, 0, _image->_tz - 1, Param._pos._z);
  
  p->IntegerConstraints( p->_id_planX, 0, _image->_tx - 1, Param._pos._x);
  p->IntegerConstraints( p->_id_planY, 0, _image->_ty - 1, Param._pos._y);
  p->IntegerConstraints( p->_id_planZ, 0, _image->_tz - 1, Param._pos._z);

//  (*_param_dialog)[_id_planX]->MAJ_Contraintes();
//  (*_param_dialog)[_id_planY]->MAJ_Contraintes();
//  (*_param_dialog)[_id_planZ]->MAJ_Contraintes();

//  _param_dialog->FixeVisible( _id_planX, (_image->_tx>1));
//  _param_dialog->FixeVisible( _id_planY, (_image->_ty>1));
//  _param_dialog->FixeVisible( _id_planZ, (_image->_tz>1));
  
  p->FixeVisible( p->_id_planX, (_image->_tx>1));
  p->FixeVisible( p->_id_planY, (_image->_ty>1));
  p->FixeVisible( p->_id_planZ, (_image->_tz>1));

  p->ReAfficheParametres();

  Param._MAJ.MAJCoupes();
  Param._MAJ._intensite = true;
  Param._MAJ._positions = true;


  Si Efface AlorsFait EffaceTousLesEcrans( false);
  Paint();

}  // ChangeImage()


//-------------------------------------------------------------------------
unsigned char DessinImage::LitFichierParametres(  char* nom_fichier)
//                               --------------------
{

    ImageDraw_MIPParam::ptr mip(_param_mip);

    char       NomImage[100];
    int     Pos_x, Pos_y;
    int     Hauteur, Largeur;
    int     PlanX, PlanY, PlanZ;
    int     Option;
    int     TypeCoupe;
    float       IntMin, IntMax;
    int     Xmin, Xmax, Ymin, Ymax, Zmin, Zmax;
    Parametres Par;
    int     NbreComparaisons;
    char       CompareNomImage[100];
    int     ComparePos_x;
    int     ComparePos_y;
    int     MIP_rotX, MIP_rotY, MIP_rotZ;

  Par.NomFichier( nom_fichier);

  Par.Parcours("Nom de l'image: ");
  Par.LitChaine( NomImage);
  Par.Parcours("\n");

  Par.Parcours("Position: ");
  Par.LitEntier( &Pos_x);
  Par.Parcours(", ");
  Par.LitEntier( &Pos_y);
  Par.Parcours("\n");

  Par.Parcours("Dimension: ");
  Par.LitEntier( &Largeur);
  Par.Parcours(", ");
  Par.LitEntier( &Hauteur);
  Par.Parcours("\n");

  Par.Parcours("Option: ");
  Par.LitEntier( &Option);
  Par.Parcours("\n");

  Par.Parcours("Type coupe: ");
  Par.LitEntier( &TypeCoupe);
  Par.Parcours("\n");

  Par.Parcours("Position dans l'image: ");
  Par.LitEntier( &PlanX);
  Par.Parcours(", ");
  Par.LitEntier( &PlanY);
  Par.Parcours(", ");
  Par.LitEntier( &PlanZ);
  Par.Parcours("\n");

  Si Option == OPTION_MIP Alors
    Par.Parcours("Rotation de l'image MIP: ");
    Par.LitEntier( &MIP_rotX);
    Par.Parcours(", ");
    Par.LitEntier( &MIP_rotY);
    Par.Parcours(", ");
    Par.LitEntier( &MIP_rotZ);
    Par.Parcours("\n");
  FinSi

  Par.Parcours("Intensite min: ");
  Par.LitReel( &IntMin);
  Par.Parcours("\n");

  Par.Parcours("Intensite max: ");
  Par.LitReel( &IntMax);
  Par.Parcours("\n");

  Par.Parcours("Limites de l'image: \n");
  Par.Parcours("X dans [");
  Par.LitEntier( &Xmin);
  Par.Parcours(", ");
  Par.LitEntier( &Xmax);
  Par.Parcours("]\n");
  Par.Parcours("Y dans [");
  Par.LitEntier( &Ymin);
  Par.Parcours(", ");
  Par.LitEntier( &Ymax);
  Par.Parcours("]\n");
  Par.Parcours("Z dans [");
  Par.LitEntier( &Zmin);
  Par.Parcours(", ");
  Par.LitEntier( &Zmax);
  Par.Parcours("]\n");

  //--- Lecture des couleurs
  unsigned char r,g,b;
  Par.Parcours( "Couleur du fond: ");
  Par.LitUCHAR( &r);
  Par.Parcours( ", ");
  Par.LitUCHAR( &g);
  Par.Parcours( ", ");
  Par.LitUCHAR( &b);
  Par.Parcours( "\n");
  _couleur_fond.Set(r,g,b);
/*
  _boutton_couleur_fond->FixeCouleurFond(
     _couleur_fond );
  _boutton_couleur_fond->FixeCouleurCaracteres(
     _couleur_fond.RetourneCouleurDistincte() );
     */

  Par.Parcours( "Couleur de l'image: ");
  Par.LitUCHAR( &r); Par.Parcours( ", ");
  Par.LitUCHAR( &g); Par.Parcours( ", ");
  Par.LitUCHAR( &b); Par.Parcours( "\n");
  _couleur_objet.Set(r,g,b);


/*
  _boutton_couleur_objet->FixeCouleurFond(
     _couleur_objet.RetourneCouleur( ) );
  _boutton_couleur_objet->FixeCouleurCaracteres(
     _couleur_objet.RetourneCouleurDistincte( ) );
     */

  Par.Parcours( "Couleur des lignes: ");
  Par.LitUCHAR( &r); Par.Parcours( ", ");
  Par.LitUCHAR( &g); Par.Parcours( ", ");
  Par.LitUCHAR( &b); Par.Parcours( "\n");
  _couleur_lignes.Set(r,g,b);

/*
  _boutton_couleur_lignes->FixeCouleurFond(
     _couleur_lignes.RetourneCouleur() );
  _boutton_couleur_lignes->FixeCouleurCaracteres(
     _couleur_lignes.RetourneCouleurDistincte( ) );
     */

  ImageDraw_PositionParam::ptr p ( _param_position);
  
  Param._pos._x = PlanX;
  Param._pos._y = PlanY;
  Param._pos._z = PlanZ;

  Si _image->_tx > 1 AlorsFait
    p->UpdateParameter(p->_id_planX);
     //_param_dialog->UpdateParameter( _id_planX);

  Si _image->_ty > 1 AlorsFait
    p->UpdateParameter(p->_id_planY);
     //_param_dialog->UpdateParameter( _id_planY);

  Si _image->_tz > 1 AlorsFait
    p->UpdateParameter(p->_id_planZ);
     //_param_dialog->UpdateParameter( _id_planZ);

  Param._option_traitement = Option;

//  _Moptions_mode->MAJ();

  Param._type_coupe = TypeCoupe;
//  _Moptions_type_coupe->MAJ();

  _intensite_float_min = IntMin;
  _intensite_float_max = IntMax;

  _intensite_entier_min = (int) IntMin;
  _intensite_entier_max = (int) IntMax;

  ImageDraw_IntensityParam::ptr intensity ( _param_intensity);
  
//   _param_dialog->UpdateParameter( _id_min);
//   _param_dialog->UpdateParameter( _id_max);
  
  intensity->UpdateParameter(intensity->_id_min);
  intensity->UpdateParameter(intensity->_id_max);


  Param._Zoom._xmin = Xmin;
  Param._Zoom._xmax = Xmax;
  Param._Zoom._ymin = Ymin;
  Param._Zoom._ymax = Ymax;
  Param._Zoom._zmin = Zmin;
  Param._Zoom._zmax = Zmax;

  Param._Zoom.ComputeSize();

  Param._MAJ._intensite = true;
  Param._MAJ.MAJCoupes();
  EffaceTousLesEcrans( false);

  Fixe_fenetre_position(   Pos_x,   Pos_y  );
  Fixe_fenetre_dimensions( Largeur, Hauteur, true);

  Par.Parcours("Nombre de comparaisons = ");
  Par.LitEntier( &NbreComparaisons);
  Par.Parcours("\n");
 
  int i=0;
  Pour( i, 0, NbreComparaisons - 1 )

    Par.Parcours("Nom Image:");
    Par.LitChaine( CompareNomImage  );
    Par.Parcours("\n");

    Par.Parcours("Position: ");
    Par.LitEntier( &ComparePos_x );
    Par.Parcours(", ");
    Par.LitEntier( &ComparePos_y );
    Par.Parcours("\n");

//    n = CreeCompareImage( CompareNomImage, CompareNomImage);

/* deprecated
    Si n != -1 AlorsFait
      ((CompareImage*) _tab_compare_image[n])->Fixe_fenetre_position( ComparePos_x, ComparePos_y);
*/
  FinPour // i

 //--- Mise �jour des principaux parametres

  aff_err("LitFichierParametres:Paint()\n");

  // Indispensable de lancer un premier appel a Paint()
  // pour initialiser les valeurs des images �comparer
  // Par exemple, les animations n'utilisent que DessinePlanZ()...

  // Dans le cas des MIP, on appelle Paint() apres initialisation de la
  // MIP,
  // Dans le cas des animations, on appelle Paint() avant Animation()
  //  Pour initialiser les images a Comparer

  switch ( Param._option_traitement ){

    case OPTION_MIP:
      Param._MIP._rot_X = MIP_rotX;
      Param._MIP._rot_Y = MIP_rotY;
      Param._MIP._rot_Z = MIP_rotZ;
//       _param_MIP->UpdateParameter( _id_rot_X);
//       _param_MIP->UpdateParameter( _id_rot_Y);
//       _param_MIP->UpdateParameter( _id_rot_Z);
        mip->UpdateParameter( mip->_id_rot_X);
        mip->UpdateParameter( mip->_id_rot_Y);
        mip->UpdateParameter( mip->_id_rot_Z);

      _image_MIP = InrImage::ptr(_MIP->CreeMIP( Param._MIP._rot_X,
                  Param._MIP._rot_Y,
                  Param._MIP._rot_Z));
      Param._MIP._MAJ   = true;
      _image     = _image_MIP;

//      _param_MIP->AfficheDialogue();
      mip->AfficheDialogue();

      Paint();
    break;

    case OPTION_ANIM:
      Paint();
      MemoriseCoupesXY(true);
      Comparaisons_MemoriseCoupesXY(true);
      LanceAnimation();
    break;

    case OPTION_COUPE:
      Paint();
    break;

  } // end switch


  return true;

}  // LitFichierParametres()


//-------------------------------------------------------------------------
void DessinImage::SauveFichierParametres(  char* nom_fichier)
//                            ----------------------
{


    FILE*      pfic;
        int     Pos_x, Pos_y;
        int     Hauteur, Largeur;
//        int     i;

  Recupere_fenetre_position(   &Pos_x,   &Pos_y  );
  Recupere_fenetre_dimensions( &Largeur, &Hauteur);

  pfic = fopen( nom_fichier, "w");

  fprintf( pfic, "Nom de l'image: ");
  fprintf( pfic, "%s", _image_initiale->GetName() );
  fprintf( pfic, "\n");

  fprintf( pfic, "Position: ");
  fprintf( pfic, "%lu", (Dimension) Pos_x);
  fprintf( pfic, ", ");
  fprintf( pfic, "%lu", (Dimension) Pos_y);
  fprintf( pfic, "\n");

  fprintf( pfic, "Dimension: ");
  fprintf( pfic, "%lu", (Dimension) Largeur);
  fprintf( pfic, ", ");
  fprintf( pfic, "%lu", (Dimension) Hauteur);
  fprintf( pfic, "\n");

  fprintf( pfic, "Option: ");
  fprintf( pfic, "%d", Param._option_traitement);
  fprintf( pfic, "\n");

  fprintf( pfic, "Type coupe: ");
  fprintf( pfic, "%d", Param._type_coupe);
  fprintf( pfic, "\n");

  fprintf( pfic, "Position dans l'image: ");
  fprintf( pfic, "%d", Param._pos._x);
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", Param._pos._y);
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", Param._pos._z);
  fprintf( pfic, "\n");

  Si Param._option_traitement == OPTION_MIP Alors
    fprintf( pfic, "Rotation de l'image MIP: ");
    fprintf( pfic, "%d", Param._MIP._rot_X);
    fprintf( pfic, ", ");
    fprintf( pfic, "%d", Param._MIP._rot_Y);
    fprintf( pfic, ", ");
    fprintf( pfic, "%d", Param._MIP._rot_Z);
    fprintf( pfic, "\n");
  FinSi

  Si (_image->_format == WT_FLOAT ) Ou
     (_image->_format == WT_DOUBLE) Alors
    fprintf( pfic, "Intensite min: ");
    fprintf( pfic, "%f", _intensite_float_min);
    fprintf( pfic, "\n");

    fprintf( pfic, "Intensite max: ");
    fprintf( pfic, "%f", _intensite_float_max);
    fprintf( pfic, "\n");
  Sinon
    fprintf( pfic, "Intensite min: ");
    fprintf( pfic, "%d", _intensite_entier_min);
    fprintf( pfic, "\n");

    fprintf( pfic, "Intensite max: ");
    fprintf( pfic, "%d", _intensite_entier_max);
    fprintf( pfic, "\n");
  FinSi

  fprintf( pfic, "Limites de l'image: \n");
  fprintf( pfic, "X dans [");
  fprintf( pfic, "%d", Param._Zoom._xmin);
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", Param._Zoom._xmax);
  fprintf( pfic, "]\n");
  fprintf( pfic, "Y dans [");
  fprintf( pfic, "%d", Param._Zoom._ymin);
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", Param._Zoom._ymax);
  fprintf( pfic, "]\n");
  fprintf( pfic, "Z dans [");
  fprintf( pfic, "%d", Param._Zoom._zmin);
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", Param._Zoom._zmax);
  fprintf( pfic, "]\n");

  //--- Sauvegarde des couleurs
  fprintf( pfic, "Couleur du fond: ");
  fprintf( pfic, "%d", _couleur_fond.Red());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_fond.Green());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_fond.Blue());
  fprintf( pfic, "\n");

  fprintf( pfic, "Couleur de l'image: ");
  fprintf( pfic, "%d", _couleur_objet.Red());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_objet.Green());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_objet.Blue());
  fprintf( pfic, "\n");

  fprintf( pfic, "Couleur des lignes: ");
  fprintf( pfic, "%d", _couleur_lignes.Red());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_lignes.Green());
  fprintf( pfic, ", ");
  fprintf( pfic, "%d", _couleur_lignes.Blue());
  fprintf( pfic, "\n");



  //--- Sauvegarde des images comparees
/*
  fprintf( pfic, "Nombre de comparaisons = ");
  fprintf( pfic, "%d", _nombre_comparaisons);
*/
  fprintf( pfic, "\n");

/* deprecated
  Pour( i, 0, _compare_max - 1)

    Si _tab_compare_image[i] != NULL Alors
      fprintf( pfic, "Nom Image:");
      fprintf( pfic, "%s", ((CompareImage*) _tab_compare_image[i])->NomImage()  );
      fprintf( pfic, "\n");

      ((CompareImage*) _tab_compare_image[i])->Recupere_fenetre_position( &Pos_x, &Pos_y);

      fprintf( pfic, "Position: ");
      fprintf( pfic, "%lu", (Dimension) Pos_x );
      fprintf( pfic, ", ");
      fprintf( pfic, "%lu", (Dimension) Pos_y );
      fprintf( pfic, "\n");
    FinSi

  FinPour // i
*/
  fclose( pfic);

}  // SauveFichierParametres()


//-------------------------------------------------------------------------
void DessinImage::SauveImage( char* nom_image)
//                            ----------
{

/* Deprecated
    InrImage*     nouvelle_image;
    int        x, y, z;
    WORDTYPE      format;

  // Choix du format de l'image

//  Si _type_courbe == TYPE_COURBE_PLATEAU Alors
//    format = TYPEIM_256;
//  FinSi

  format = (WORDTYPE) _format_image;
  printf("format %d\n", format);
  nouvelle_image = new InrImage( Param._Zoom._zoom_size_x,
                 Param._Zoom._zoom_size_y,
                 Param._Zoom._zoom_size_z, format, nom_image);
  nouvelle_image->SetVoxelSize(Param._dim._voxel_size_x,
                     Param._dim._voxel_size_y,
                     Param._dim._voxel_size_z);

  switch ( format ){

    case WT_UNSIGNED_CHAR:

      nouvelle_image->InitBuffer();
      _image->InitBuffer();

      Pour( z, 0, _image->_tz -1)
      Pour( y, 0, _image->_ty -1)
      Pour( x, 0, _image->_tx -1)

        Si (x >= Param._Zoom._xmin) Et (x <= Param._Zoom._xmax) Et
           (y >= Param._Zoom._ymin) Et (y <= Param._Zoom._ymax) Et
           (z >= Param._Zoom._zmin) Et (z <= Param._Zoom._zmax)
        Alors
          nouvelle_image->FixeValeur( IntensiteBuffer());
          nouvelle_image->IncBuffer();
        FinSi

        _image->IncBuffer();

      FinPour // x
      FinPour // y
      FinPour // z

    break;

    case WT_UNSIGNED_SHORT:
    case WT_SIGNED_SHORT:
    case WT_UNSIGNED_INT:
    case WT_SIGNED_INT:
    case WT_UNSIGNED_LONG:
    case WT_SIGNED_LONG:
    case WT_FLOAT:
    case WT_DOUBLE:

      nouvelle_image->InitBuffer();
      _image->InitBuffer();

      Pour( z, 0, _image->_tz -1)
      Pour( y, 0, _image->_ty -1)
      Pour( x, 0, _image->_tx -1)
        Si (x >= Param._Zoom._xmin) Et (x <= Param._Zoom._xmax) Et
           (y >= Param._Zoom._ymin) Et (y <= Param._Zoom._ymax) Et
           (z >= Param._Zoom._zmin) Et (z <= Param._Zoom._zmax)
        Alors
          nouvelle_image->FixeValeur( _image->ValeurBuffer());
          nouvelle_image->IncBuffer();
        FinSi
        _image->IncBuffer();

      FinPour // x
      FinPour // y
      FinPour // z
    break;

      default:
      fprintf(stderr,"DessinImage::SauveImage() format not available \n");

  } // end switch

  nouvelle_image->Sauve();

  delete nouvelle_image;
*/
} // SauveImage()


//-------------------------------------------------------------------------
void DessinImage::SauveImagePS( const char* nom_image)
//                ------------
{

  std::cerr << "DessinImage::SauveImagePS()\t not available anymore " << std::endl;

} // SauveImagePS()

/* TODO: need to create a shared_ptr of the new image

//-------------------------------------------------------------------------
unsigned char DessinImage::ChargeImageVecteur( int index, char* nom)
//                           -------------------
{


  Si strlen(nom) > B_FNAME_LENGTH Alors
    _message_erreur->FixeValeurs(" Erreur",
       "ChargeImageVecteur( ) \t nom de fichier trop grand pour la lecture inrimage");
    _message_erreur->AfficheDialogue();

    return false;
  FinSi

  try{
// Check how to do this ...
    _vector_fields[index].vector = new InrImage( nom);
    _vect_alloue[index]   = true;
  }
  catch (InrImage::ErreurLecture)
  {
    _image_vecteur[index] = NULL;
    _message_erreur->FixeValeurs(" Erreur",
       "ChargeImageVecteur() \t lecture de l'image");
    _message_erreur->AfficheDialogue();

      //    E_RESETERR()
    return false;
  }

  Si (_image_vecteur[index]->_tx != _image->_tx) Ou
     (_image_vecteur[index]->_ty != _image->_ty)   Ou
     (_image_vecteur[index]->_tz != _image->_tz) Ou
     ( ! _image_vecteur[index]->VectorialFormat()) Alors

    printf("Erreur, DessinImage::ChargeImageVecteur() \t");
    printf(" Mauvais Format ... \n");

    delete _image_vecteur[index];
    _image_vecteur[index] = NULL;
    _vect_alloue[index]   = false;
    return false;
  FinSi

  return true;

}  // ChargeImageVecteur()
*/


//----------------------------------------------------------------------
unsigned char DessinImage::LoadVectImage( int num, InrImage::ptr im)
//                           -------------
// chargement d'un champ de vecteurs
// num est le numero du champ de vecteurs dans (0..2)
{

  if ((num<0)||(num>=(int)_vector_fields.size())) {
    fprintf(stderr,"DessinImage::LoadVectImage() \t bad vect number \n");
    return false;
  }

  Si  (!im->VectorialFormat()) Alors
    fprintf(stderr,"Erreur, DessinImage::LoadVectImage() \t");
    fprintf(stderr," Bad Image Format (not vectorial) ... \n");
    return false;
  FinSi

  Si (im->_tx != _image->_tx) Ou
     (im->_ty != _image->_ty) Ou
     (im->_tz != _image->_tz)
  Alors
    // interpolate vector
    if ((im->SpacePosX(0)           <=_image->SpacePosX(_image->DimX()-1))&&
        (im->SpacePosX(im->DimX()-1)>=_image->SpacePosX(0)               )&&
        (im->SpacePosY(0)           <=_image->SpacePosY(_image->DimY()-1))&&
        (im->SpacePosY(im->DimY()-1)>=_image->SpacePosY(0)               )&&
        (im->SpacePosZ(0)           <=_image->SpacePosZ(_image->DimZ()-1))&&
        (im->SpacePosZ(im->DimZ()-1)>=_image->SpacePosZ(0)               )) {
      _vector_fields[num].vector      = im;
      _vector_fields[num].interpolate = true;
    }
    else {
      printf("Erreur, DessinImage::LoadVectImage() \t");
      printf(" Image domains don't overlap ... \n");
      return false;
    }
  Sinon
    _vector_fields[num].vector        = im;
    _vector_fields[num].interpolate = false;
  FinSi

  return true;

} // LoadVectImage()


// --------------------------------------------------------
void DessinImage::UpdateZoom()
{
  // Update current position based on the available new zoom
  Param._pos._x = macro_max( Param._pos._x, Param._Zoom._xmin);
  Param._pos._x = macro_min( Param._pos._x, Param._Zoom._xmax);
  Param._pos._y = macro_max( Param._pos._y, Param._Zoom._ymin);
  Param._pos._y = macro_min( Param._pos._y, Param._Zoom._ymax);
  Param._pos._z = macro_max( Param._pos._z, Param._Zoom._zmin);
  Param._pos._z = macro_min( Param._pos._z, Param._Zoom._zmax);

  Param._Zoom.ComputeSize();
  Param._MAJ.MAJCoupes();
  Paint();
}

// --------------------------------------------------------
void DessinImage::ApplyZoom( const ParamZoom& initial_zoom, 
          const int x, const int y, const int z, 
          const float zoom_factor)
{

  Si (z < initial_zoom._zmin) Ou (z > initial_zoom._zmax) Alors
    CLASS_ERROR(boost::format("Wrong Z position for zoom."));
    return;
  FinSi

  // Ajouter 0.5 permet de ne pas stagner si une difference est nulle
  Param._Zoom._xmin = macro_max( 0,
              (int) (x - 1.0*( x - initial_zoom._xmin + 0.5)/zoom_factor));
  Param._Zoom._xmax = macro_min( _image->DimX() - 1,
              (int) (x + 1.0*( initial_zoom._xmax - x    + 0.5)/zoom_factor));

  Param._Zoom._ymin = macro_max( 0,
              (int) (y - 1.0*
                    ( y    - initial_zoom._ymin + 0.5)/zoom_factor));
  Param._Zoom._ymax = min( _image->DimY() - 1,
              (int) (y + 1.0*
                    ( initial_zoom._ymax - y    + 0.5)/zoom_factor));

  Param._Zoom._zmin = max( 0,
              (int) (z - 1.0*
                    ( z    - initial_zoom._zmin + 0.5)/zoom_factor));
  Param._Zoom._zmax = min( _image->DimZ() - 1,
              (int) (z + 1.0*
                    ( initial_zoom._zmax - z    + 0.5)/zoom_factor));

}


// --------------------------------------------------------
void DessinImage::OnWheel(wxMouseEvent& event) 
{
  // ici faire zoom??
  CLASS_MESSAGE(" Should apply zoom here s")

  int wr = event.GetWheelRotation();
  if (wr != 0) {

    int x1,y1,z1;
    CursorToImage(_souris_x, _souris_y, x1, y1, z1, _zoom_coupe);
    // Il faut etre dans une des images ...
    if (_zoom_coupe == -1) {
      CLASS_ERROR("Trying to zoom from outside the image.")
      return;
    }
    _initial_zoom = Param._Zoom;

    float step  = ((float)wr)/(5*(float)event.GetWheelDelta());
    //cout << " wr = " << wr << " wheeldata = "<< event.GetWheelDelta() << " step = " << step << std::endl;

    Si step > 7  AlorsFait step = 7;
    Si step < -7 AlorsFait step = -7;
    float zoom_factor  = exp( step*log2f(2));

    ApplyZoom(_initial_zoom,x1,y1,z1,zoom_factor);
    UpdateZoom();
  }
}

// -------------------------------------------------------------------------
//
void DessinImage::Boutton_Presse()
//                --------------
{
  this->SetFocus();
    if (GB_debug)
      printf("DessinImage::Boutton_Presse() \n");
        Point_3D<int> im;  // position dans l'image visualisee
        int    trouve;

  _shift_deplace = false;

  Si Param._curseur._type != TYPE_CURSEUR_equiv Alors
    Param._curseur._type = TYPE_CURSEUR_equiv;
    Si Param._curseur._ON AlorsFait Paint();
  FinSi

  CursorToImage(_souris_x, _souris_y, im.x, im.y, im.z, trouve);
  UpdateStatusInfo( im, trouve);

  Si Param._fonction_zoom == FUNC_ZOOM_ACTIVE Alors
    _zoom_coupe = -1;
  FinSi

  Si _buttonpressed_callback != NULL Alors
/* TODO ...
    ((XtCallbackProc) _buttonpressed_callback)(_drawing_area,
                           _buttonpressed_data,
                           _button_event);
*/
  FinSi

  Si (trouve != -1) Alors

    Si (Param._fonction_zoom == FUNC_ZOOM_ACTIVE) Alors
      _zoom_coupe = trouve;
      _zoom_x2 = _zoom_x1    = _souris_x;
      _zoom_y2 = _zoom_y1    = _souris_y;
      wxClientDC dc(_drawing_window);
      if (dc.IsOk()) {
        _current_pen->SetColour(*wxBLACK);
        _current_pen->SetWidth(1);
        dc.SetPen(*_current_pen);
        dc.SetLogicalFunction(wxINVERT);
        dc.DrawRectangle( _zoom_x1, _zoom_y1,
                          _zoom_x2-_zoom_x1, _zoom_y2-_zoom_y1);
        dc.SetLogicalFunction(wxCOPY);
      } else
        std::cerr << "DC not OK " << std::endl;
    Sinon
      Si Param._curseur._ON AlorsFait DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);
      _curseur_x = im.x;
      _curseur_y = im.y;
      _curseur_z = im.z;
      DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);
    FinSi

  FinSi

} // Boutton_Presse()


// -------------------------------------------------------------------------
//
void DessinImage::Boutton_Relache()
//                              ---------------
{


    if (GB_debug)
      printf("DessinImage::Boutton_Relache() \n");

    int    x1,x2,y1,y2,z1,z2, etat;


  Si _shift_deplace Alors
      _shift_deplace = false;
      return;
  FinSi

  Si (Param._fonction_zoom == FUNC_ZOOM_ACTIVE) Et (_zoom_coupe >= 0) Alors

      Si (_zoom_x1 != _zoom_x2) Et (_zoom_y1 != _zoom_y2) Alors

      wxClientDC dc(_drawing_window);
      if (dc.IsOk()) {
        _current_pen->SetColour(*wxBLACK);
        _current_pen->SetWidth(1);
        dc.SetPen(*_current_pen);
        dc.SetLogicalFunction(wxINVERT);
        dc.DrawRectangle( _zoom_x1, _zoom_y1,
                          _zoom_x2-_zoom_x1, _zoom_y2-_zoom_y1);
        dc.SetLogicalFunction(wxCOPY);
      } else
        std::cerr << "DC not OK" << std::endl;

        _souris_x = _zoom_x1;
        _souris_y = _zoom_y1;
        CursorToImage(_souris_x,_souris_y,x1, y1, z1, etat);
        _souris_x = _zoom_x2;
        _souris_y = _zoom_y2;

        CursorToImage(_souris_x, _souris_y,  x2, y2, z2, etat);
        switch ( etat ){
          case IMAGE_XY:
            Param._Zoom._xmin = macro_min(x1,x2);   Param._Zoom._xmax = macro_max(x1,x2);
            Param._Zoom._ymin = macro_min(y1,y2);   Param._Zoom._ymax = macro_max(y1,y2);
          break;
          case IMAGE_XZ:
            Param._Zoom._xmin = macro_min(x1,x2);   Param._Zoom._xmax = macro_max(x1,x2);
            Param._Zoom._zmin = macro_min(z1,z2);   Param._Zoom._zmax = macro_max(z1,z2);
          break;
          case IMAGE_ZY:
            Param._Zoom._zmin = macro_min(z1,z2);   Param._Zoom._zmax = macro_max(z1,z2);
            Param._Zoom._ymin = macro_min(y1,y2);   Param._Zoom._ymax = macro_max(y1,y2);
          break;
        } // end switch
     FinSi

    
     Param._pos._x = macro_max( Param._pos._x, Param._Zoom._xmin);
     Param._pos._x = macro_min( Param._pos._x, Param._Zoom._xmax);
     Param._pos._y = macro_max( Param._pos._y, Param._Zoom._ymin);
     Param._pos._y = macro_min( Param._pos._y, Param._Zoom._ymax);
     Param._pos._z = macro_max( Param._pos._z, Param._Zoom._zmin);
     Param._pos._z = macro_min( Param._pos._z, Param._Zoom._zmax);

     Param._Zoom.ComputeSize();

     Param._MAJ.MAJCoupes();
     EffaceTousLesEcrans( false);
     Paint();

  Sinon

    Si Non(Param._curseur._visible) Et Param._curseur._ON
        AlorsFait DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);

  FinSi

} // Boutton_Relache()


// -------------------------------------------------------------------------
//
void DessinImage::DeplaceSourisBout1()
//                ------------------
{
        Point_3D<int> im;  // position dans l'image visualisee
        int     trouve;

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() \n");

  _shift_deplace = false;

  CursorToImage(_souris_x, _souris_y, im.x, im.y, im.z, trouve);
  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() 1 \n");

  UpdateStatusInfo( im,  trouve);

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() 2 \n");



  Si (trouve != -1) Alors
    Si (Param._fonction_zoom == FUNC_ZOOM_ACTIVE) Et (trouve == _zoom_coupe) Alors

      wxClientDC dc(_drawing_window);
      if (dc.IsOk()) {
        _current_pen->SetColour(*wxBLACK);
        _current_pen->SetWidth(1);
        dc.SetPen(*_current_pen);
        dc.SetLogicalFunction(wxINVERT);
        dc.DrawRectangle( _zoom_x1, _zoom_y1,
                          _zoom_x2-_zoom_x1, _zoom_y2-_zoom_y1);
        _zoom_x2    = _souris_x;
        _zoom_y2    = _souris_y;
        dc.DrawRectangle( _zoom_x1, _zoom_y1,
                          _zoom_x2-_zoom_x1, _zoom_y2-_zoom_y1);
        dc.SetLogicalFunction(wxCOPY);
      } else
        std::cerr << "DC not OK" << std::endl;


    FinSi

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() 2 \n");
    Si (Param._fonction_zoom != FUNC_ZOOM_ACTIVE) Et (trouve != -1) Alors
      Si Param._curseur._ON AlorsFait DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);
      _curseur_x = im.x;
      _curseur_y = im.y;
      _curseur_z = im.z;

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() 3 \n");

      DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);
    FinSi
  FinSi

  Si GB_debug AlorsFait fprintf(stderr,"DessinImage::DeplaceSourisBout1() Fin \n");

} // DeplaceSourisBout1()


// -------------------------------------------------------------------------
//
void DessinImage::DeplaceSourisShiftBout1()
//                              -----------------------
{

        int       dx,dy,dz;
        int       dposx,dposy;
        static int     deplace_coupe;
        static int     x1,y1,z1;


    Si Non(_shift_deplace) Alors

      CursorToImage(_souris_x, _souris_y, x1, y1, z1, deplace_coupe);

      // Il faut etre dans une des images ...
      Si deplace_coupe == -1 AlorsRetourne;

      _souris_position_initiale_x = _souris_x;
      _souris_position_initiale_y = _souris_y;

      _initial_zoom = Param._Zoom;

    FinSi

    _shift_deplace = true;

    dposx = _souris_x - _souris_position_initiale_x;
    dposy = _souris_y - _souris_position_initiale_y;

    dx = dy = dz = 0;

    switch ( deplace_coupe ){

      case IMAGE_XY:
        dx = (int) (-dposx/_size_x);
        dy = (int) (-dposy/_size_y);
      break;

      case IMAGE_XZ:
        dx = (int) (-dposx/_size_x);
        dz = (int) (-dposy/_size_z);
      break;

      case IMAGE_ZY:
        dy = (int) (-dposy/_size_y);
        dz = (int) (-dposx/_size_z);
      break;

    } // end switch


    // Deplacement
    // dx >= -_initial_zoom._xmin et dx <= _image->_tx - 1 - _initial_zoom._xmax
    dx = max( dx, -_initial_zoom._xmin);
    dx = min( dx, _image->_tx - 1 - _initial_zoom._xmax);
    Param._Zoom._xmin = (int) ( _initial_zoom._xmin + dx);
    Param._Zoom._xmax = (int) ( _initial_zoom._xmax + dx);

    dy = max( dy, - _initial_zoom._ymin);
    dy = min( dy, _image->_ty - 1 - _initial_zoom._ymax);
    Param._Zoom._ymin = (int) ( _initial_zoom._ymin + dy);
    Param._Zoom._ymax = (int) ( _initial_zoom._ymax + dy);

    dz = max( dz, -_initial_zoom._zmin);
    dz = min( dz, _image->_tz - 1 - _initial_zoom._zmax);
    Param._Zoom._zmin = (int) ( _initial_zoom._zmin + dz);
    Param._Zoom._zmax = (int) ( _initial_zoom._zmax + dz);

    UpdateZoom();

} // DeplaceSourisShiftBout1()


// -------------------------------------------------------------------------
//
void DessinImage::Boutton2_Presse()
//                              --------------
{
  ImageDraw_PositionParam::ptr p ( _param_position);
 
  this->SetFocus();
    if (GB_debug)
      printf("DessinImage::Boutton2_Presse() \n");

        Point_3D<int> im;  // position dans l'image visualisee
        int     trouve;


  _shift_zoom = false;

  Si Param._option_traitement == OPTION_MIP Alors
    _souris_position_initiale_x = _souris_x;
    _souris_position_initiale_y = _souris_y;
    _MIP_rot_X_initiale = Param._MIP._rot_X;
    _MIP_rot_Y_initiale = Param._MIP._rot_Y;
    _MIP_rot_Z_initiale = Param._MIP._rot_Z;
    return;
  FinSi

  Param._curseur._type = TYPE_CURSEUR_copy;
  CursorToImage(_souris_x, _souris_y, im.x, im.y, im.z, trouve);
  UpdateStatusInfo( im, trouve);

  Si (trouve != -1) Alors

    Si Param._pos._x != im.x Alors
      Param._pos._x = im.x;
      Param._MAJ._planZY = true;
  //_param_dialog->UpdateParameter( _id_planX);
      p->UpdateParameter(p->_id_planX);
    FinSi

    Si Param._pos._y != im.y Alors
      Param._pos._y = im.y;
      Param._MAJ._planXZ = true;
  //  _param_dialog->UpdateParameter( _id_planY);
      p->UpdateParameter(p->_id_planY);
    FinSi

    Si Param._pos._z != im.z Alors
      Param._pos._z = im.z;
      Param._MAJ._planXY = true;
  //  _param_dialog->UpdateParameter( _id_planZ);
      p->UpdateParameter(p->_id_planZ);
    FinSi

    _curseur_x = im.x;
    _curseur_y = im.y;
    _curseur_z = im.z;
    Paint();
    Si Non(Param._curseur._ON) AlorsFait
      DessineCurseurs( _curseur_x, _curseur_y, _curseur_z);

  Sinon
    Si _buttonpressed_callback != NULL Alors
/* TODO ...
      ((XtCallbackProc) _buttonpressed_callback)(_drawing_area,
                         _buttonpressed_data,
                         _button_event);
*/
    FinSi

  FinSi

} // Boutton2_Presse()


// -------------------------------------------------------------------------
//
void DessinImage::Boutton2_Relache()
//                              ----------------
{

  ImageDraw_MIPParam::ptr mip(_param_mip);
  
    if (GB_debug)
      printf("DessinImage::Boutton2_Relache() \n");

    int var;

  Si _shift_zoom Alors
    _shift_zoom = false;
    return;
  FinSi

  Si Param._option_traitement == OPTION_MIP Alors

    _MIP->FixeRotation( _MIP_rot_X_initiale, _MIP_rot_Y_initiale, _MIP_rot_Z_initiale);

    var = _souris_y - _souris_position_initiale_y;
    _MIP->RotationX(  (double) ( var * -90.0 / _hauteur ) );

    var = _souris_x - _souris_position_initiale_x;
    _MIP->RotationY(  (double) ( var * 90.0 / _largeur ) );

    _MIP->DetecteRotations( &Param._MIP._rot_X, &Param._MIP._rot_Y, &Param._MIP._rot_Z );

//     _param_MIP->UpdateParameter( _id_rot_X);
//     _param_MIP->UpdateParameter( _id_rot_Y);
//     _param_MIP->UpdateParameter( _id_rot_Z);
     mip->UpdateParameter( mip->_id_rot_X);
     mip->UpdateParameter( mip->_id_rot_Y);
     mip->UpdateParameter( mip->_id_rot_Z);

    _image_MIP = InrImage::ptr(_MIP->CreeMIP( ));
    Param._MIP._MAJ = true;
    Param._MAJ.MAJCoupes();

    Paint();

    return;
  FinSi

  Si Param._curseur._ON AlorsFait Paint();
/* Already updating during mouse motion
  Si _image->_tx > 1 AlorsFait
     _param_dialog->UpdateParameter( _id_planX);

  Si _image->_ty > 1 AlorsFait
     _param_dialog->UpdateParameter( _id_planY);

  Si _image->_tz > 1 AlorsFait
     _param_dialog->UpdateParameter( _id_planZ);
*/
} // Boutton2_Relache()


// -------------------------------------------------------------------------
//
void DessinImage::DeplaceSourisBout2()
//                ------------------
{
  ImageDraw_MIPParam::ptr mip(_param_mip);
  
  int var;

  _shift_zoom = false;

  Si (Param._option_traitement == OPTION_MIP)  Alors

    Si Param._MIP._bounding_box Alors

      _MIP->FixeRotation( _MIP_rot_X_initiale, _MIP_rot_Y_initiale, _MIP_rot_Z_initiale);

      var = _souris_y - _souris_position_initiale_y;
      _MIP->RotationX(  (double) ( var * -90.0 / _largeur ) );

      var = _souris_x - _souris_position_initiale_x;
      _MIP->RotationY(  (double) ( var * 90.0 / _hauteur ) );

      _MIP->DetecteRotations( &Param._MIP._rot_X, &Param._MIP._rot_Y, &Param._MIP._rot_Z );

//       _param_MIP->UpdateParameter( _id_rot_X);
//       _param_MIP->UpdateParameter( _id_rot_Y);
//       _param_MIP->UpdateParameter( _id_rot_Z);
       mip->UpdateParameter( mip->_id_rot_X);
       mip->UpdateParameter( mip->_id_rot_Y);
       mip->UpdateParameter( mip->_id_rot_Z);

      Paint();
    FinSi

    return;
  FinSi

  Boutton2_Presse();

} // DeplaceSourisBout2()


// -------------------------------------------------------------------------
//
void DessinImage::DeplaceSourisShiftBout2()
//                -----------------------
{
    float       dy,alpha;

    // Les images changent, mais on se base sur l'image initiale
    // les variables statiques permettent de memoriser les parametres
    // de l'image initiale

    // Position initiale dans l'image au moment du zoom
    static int     x1,y1,z1;
    static int     hauteur_initiale;


    Si Non(_shift_zoom) Alors

      CursorToImage(_souris_x, _souris_y, x1, y1, z1, _zoom_coupe);
      // Il faut etre dans une des images ...
      Si _zoom_coupe == -1 AlorsRetourne;
      _souris_position_initiale_x = _souris_x;
      _souris_position_initiale_y = _souris_y;
      _initial_zoom = Param._Zoom;

     // Initialisation des variables statiques
     hauteur_initiale = GetImageHeight(_zoom_coupe);

    FinSi

    Si (z1 < _initial_zoom._zmin) Ou (z1 > _initial_zoom._zmax) Alors
      printf("z1 %d _initial_zoom._zmin %d _initial_zoom._zmax %d \n",
         z1,_initial_zoom._zmin,_initial_zoom._zmax);
    FinSi

    _shift_zoom = true;

    dy = 2.0*(_souris_position_initiale_y - _souris_y)/hauteur_initiale;

    // 2^dy permet en fonction du signe de diviser ou multiplier les distances
    // Limites pour alpha: facteur 2^7 = 128, afin d'eviter le depassement de la capacite des entiers ...
    Si dy > 7  AlorsFait dy = 7;
    Si dy < -7 AlorsFait dy = -7;
    alpha = exp( dy*log2f(2));
    //    alpha = exp( dy*log(2));

    ApplyZoom(_initial_zoom,x1,y1,z1,alpha);
    UpdateZoom();

} // DeplaceSourisShiftBout2()


// -------------------------------------------------------------------------
//
void DessinImage::Boutton3_Presse()
//                              --------------
{
        Point_3D<int> im;  // position dans l'image visualisee
        int     trouve;

  this->SetFocus();

  CursorToImage(_souris_x, _souris_y, im.x,im.y, im.z, trouve);
  UpdateStatusInfo( im,  trouve);

  Si (trouve != -1) Alors
    Si Param._pos._x != im.x Alors
      Param._pos._x = im.x;
      Param._MAJ._planZY = true;
    FinSi

    Si Param._pos._y != im.y Alors
      Param._pos._y = im.y;
      Param._MAJ._planXZ = true;
    FinSi

    Si Param._pos._z != im.z Alors
      Param._pos._z = im.z;
      Param._MAJ._planXY = true;
    FinSi

    Paint();
    _curseur_x = im.x;
    _curseur_y = im.y;
    _curseur_z = im.z;
    DrawVectors( _curseur_x, _curseur_y, _curseur_z);

  Sinon

      Si _buttonpressed_callback != NULL Alors
/* TODO
        ((XtCallbackProc) _buttonpressed_callback)(_drawing_area,
                           _buttonpressed_data,
                           _button_event);
*/
      FinSi

  FinSi

} // Boutton3_Presse()


// -------------------------------------------------------------------------
//
void DessinImage::Boutton3_Relache()
//                              ----------------
{

  ImageDraw_PositionParam::ptr p (_param_position);
  
  CLASS_MESSAGE("begin");

  Si _vecteur_ON AlorsFait Paint(); // DrawVectors( _curseur_x, _curseur_y, _curseur_z);

  Si _image->_tx > 1 AlorsFait
    p->UpdateParameter(p->_id_planX);
     //_param_dialog->UpdateParameter( _id_planX);

  Si _image->_ty > 1 AlorsFait
    p->UpdateParameter(p->_id_planY);
     //_param_dialog->UpdateParameter( _id_planY);

  Si _image->_tz > 1 AlorsFait
    p->UpdateParameter(p->_id_planZ);
     //_param_dialog->UpdateParameter( _id_planZ);

#if defined(__WXMOTIF__)
  XUndefineCursor( display, fenetre);
  XFreeCursor( display, _vecteur_curseur);
#endif

  CLASS_MESSAGE("end");

} // Boutton3_Relache()


// -------------------------------------------------------------------------
//
void DessinImage::DeplaceSourisBout3()
//                              ------------------
{
        Point_3D<int> im;  // position dans l'image visualisee
        int     trouve;

#if defined(__WXMOTIF__)
  _vecteur_curseur = XCreateFontCursor( display, XC_ul_angle);
  XDefineCursor( display, fenetre, _vecteur_curseur);
#endif

  CursorToImage(_souris_x, _souris_y, im.x, im.y, im.z, trouve);
  UpdateStatusInfo( im, trouve);

  Si (trouve != -1) Alors
    Si Param._pos._x != im.x Alors
      Param._pos._x = im.x;
      Param._MAJ._planZY = true;
    FinSi

    Si Param._pos._y != im.y Alors
      Param._pos._y = im.y;
      Param._MAJ._planXZ = true;
    FinSi

    Si Param._pos._z != im.z Alors
      Param._pos._z = im.z;
      Param._MAJ._planXY = true;
    FinSi

    Paint();
    _curseur_x = im.x;
    _curseur_y = im.y;
    _curseur_z = im.z;
    DrawVectors( _curseur_x, _curseur_y, _curseur_z);

  FinSi

} // DeplaceSourisBout3()


// ---------------------------------------------------------
//
void  DessinImage::SetUserColormap(const InrImage::ptr& image, float center, float extent)
//    ---------------
{
  if ((image->_format==WT_RGB)&&
  (image->DimX()==256)&&(image->DimY()==1)&&(image->DimZ()==1)) {
    _user_colormap = image;
    _colormap_center = center;
    _colormap_extent = extent;
    Param._I._colorspace = COLORSPACE_USER;
  }
}


//-------------------------------------------------
void DessinImage::UpdateColormap()
{
  DessinImageParametres* Param = GetParam();
  InrImage::ptr _image = Get_image();

  switch ( Param->_I._colorspace ){

    case COLORSPACE_GREY:
      SetPaletteGrey(PALETTE_RGB);
    break;


    case COLORSPACE_RAINBOW:
      unsigned char rainbow[256*3];
      unsigned char pattern[192];

      for (int i = 0; i <= 63; i++)
      {
        pattern[i]= (unsigned char) (i/63.0*255.0);
      }

      for (int i = 64; i <= 127; i++)
      {
        pattern[i]= (unsigned char) 255;
      }

      for (int i = 128; i <= 191; i++)
      {
        pattern[i]= (unsigned char) (255.0-(i-128.0)/64.0*255.0);
      }

      for (int i = 0; i <= 256*3-1; i++)
      {
        rainbow[i]     = 0;
      }

      for (int i = 0; i <= 255; i++)
      {
        if (i<192-32)
          rainbow[i+512] = pattern[32+i];

        if (i<192)
          rainbow[i+256+32] = pattern[i];

        if ((i<192)&&((i+96)<256))
          rainbow[i+96] = pattern[i];
      }

      SetPaletteRU(rainbow);
    break;

    case COLORSPACE_USER:
      InrImage::ptr _user_colormap = Get_user_colormap();
      if (_user_colormap.get()) {
        unsigned char colmap[256*3];
        for(int i=0;i<256;i++) {
          colmap[i]    =(unsigned char)(*_user_colormap)(i,0,0,0);
          colmap[i+256]=(unsigned char)(*_user_colormap)(i,0,0,1);
          colmap[i+512]=(unsigned char)(*_user_colormap)(i,0,0,2);
        }
        SetPaletteRU(colmap);
      }
      else
        fprintf(stderr,"DessinImage::CB_colorspace() \t no user defined colormap ! \n");
    break;

  } // end switch

  Param->_MAJ._intensite = true;
  Param->_MAJ.MAJCoupes();
}

// ---------------------------------------------------------
//
void DessinImage::DrawContour( int i, int size, int style)
//                -----------
{

    InrImage::ptr            image;
    float                   seuil;

  if ((i<0) || (i>=(int)_isocontours.size())) {
    printf("DessinImageBase::DrawContour \t bad contour number %d \n",i);
    return;
  }

  //  if (_isocontours[i].image.expired()) return;

  //_isocontours[i].visible = true;
  seuil = _isocontours[i].threshold;

  // Set the parameters
  if (size==-1) size = _isocontours[i].thickness;
  if (size==0)  size = _largeur_lignes;
  if (style==-1) style = _isocontours[i].style;

  // Previous motif version
  //SetLineParameters( size, style, LineSolid, _cap_style, _join_style);
  SetLineParameters( size, style, PENSTYLE_SOLID);

  SetPenColor( _isocontours[i].color);

  if ((_isocontours[i].image.expired()) ||
      (Param._option_traitement == OPTION_MIP))
    image = _image;
  else
    image = InrImage::ptr(_isocontours[i].image);


  Si ((Param._type_coupe+1) & (TYPE_COUPE_ZY+1))
      AlorsFait  DessinePlanXIsoContour(image,seuil);
  Si ((Param._type_coupe+1) & (TYPE_COUPE_XZ+1))
      AlorsFait  DessinePlanYIsoContour(image,seuil);
  Si ((Param._type_coupe+1) & (TYPE_COUPE_XY+1))
      AlorsFait  DessinePlanZIsoContour(image,seuil);

} // DrawContour()


// ---------------------------------------------------------------
//
void DessinImage::DrawAllContours()
//                ---------------
{
    float threshold_backup;
    int  line_size;
    int  line_style;
    std::string method = "DessinImage::DrawAllContours()";

  aff_err("DrawAllContours() \t begin \n");

  if (_isocontours.size()==0) {
    std::cerr << "DessinImage::DrawAllContours()"
          << "\t no isocontour 0 ..." << std::endl;
    return;
  }

  Si _step_contours < 1E-3 Alors
    fprintf(stderr,"%s\t _step_contours < 1E-3 \n",method.c_str());
    return;
  FinSi

  Si (_val_max-_val_min)/_step_contours < 100 Alors

    Si GB_debug AlorsFait
      fprintf(stderr,"threshold of isocontour 0 = %f \n",_isocontours[0].threshold );

    line_size  = _isocontours[0].thickness; //_largeur_lignes;
    line_style = PENSTYLE_SOLID;
    threshold_backup = _isocontours[0].threshold;

    float& threshold = _isocontours[0].threshold;

    DrawContour(0,line_size,line_style);

    threshold += _step_contours;
    TantQue (threshold <= _val_max)Et
            (threshold-threshold_backup < _contours_winsize) Faire
      line_style = ((line_style==PENSTYLE_SOLID)?wxDOT:PENSTYLE_SOLID);
      DrawContour(0,line_size,line_style);
      threshold += _step_contours;
    FinTantQue
    threshold = threshold_backup;

    Si GB_debug AlorsFait
      fprintf(stderr,"threshold of isocontour 0 = %f \n",_isocontours[0].threshold );

    line_style = PENSTYLE_SOLID;
    threshold -= _step_contours;
    TantQue (threshold >= _val_min) Et
            (threshold_backup-threshold < _contours_winsize) Faire
      line_style = ((line_style==PENSTYLE_SOLID)?wxDOT:PENSTYLE_SOLID);
      DrawContour(0,line_size,line_style);
      threshold -= _step_contours;
    FinTantQue
    threshold = threshold_backup;

    Si GB_debug AlorsFait
      fprintf(stderr,"threshold of isocontour 0 = %f \n",threshold );

  Sinon
    fprintf(stderr,"DessinImage::DrawAllContours() \t Limited to 100 contours \n");

  FinSi

  aff_err("DrawAllContours() \t end \n");

} // DrawAllContours()


//-----------------------------------------------------
void DessinImage::CreateGLWindow()
//                  -----------
{
  Viewer3D* viewer = new Viewer3D(GB_main_wxFrame, GetwxStr("3D Viewer"));
  // Don´t delete the viewer since its parent will take care of it
  _GLWindow0 = Viewer3D::ptr( viewer,
                              wxwindow_nodeleter<Viewer3D>());
  _GLWindow0->SetCloseFunction( (void*) CB_CloseGL, (void*) this);
  _GLWindow0->Show(true);
  _GLWindow = _GLWindow0;
} // CreateGLWindow()


//----------------------------------------------------------------
void DessinImage::SetGLWindow( Viewer3D_ptr& glwin)
//                  -----------
{
  // life easier with smart pointers !!!

  // copy the pointer
  _GLWindow = glwin;

} // SetGLWindow()


//----------------------------------------------------------------
void DessinImage::Paint( unsigned char affiche)
//                            -----
{
  //wxPaintDC pdc(_drawing_area);
  if (!this->IsShown()) {
   std::cout << "DessinImage::Paint( ) \t window not shown " << std::endl;
    return;
  }
  if (this->IsIconized()) {
   std::cout << "DessinImage::Paint( ) \t window is iconized " << std::endl;
    return;
  }

  // Call the Paint from FenetreDessin
  // to be sure to be initialized
  FenetreDessin::Paint();

//    Cursor curseur = 0;
    int i;

  if (this->_in_paint) {
    CLASS_MESSAGE("_in_paint is true, return")
    return;
  }
  _in_paint=1;

  Si GB_debug AlorsFait
    std::cerr << format("\n **********\n \t DessinImage::Paint(%s)\t begin %d %d \n")
             % (char*)_name
             % _hauteur
             % _largeur
          << std::endl;

  Si Non(_vecteur_ON) Alors
  //    curseur = XCreateFontCursor( display, XC_watch);
  //    XDefineCursor( display, fenetre, curseur);
  FinSi

  Si VerifieMinMax() Alors

    ComputeBasicSizes();
    InitVoxelSize();

    Si Param._MAJ._intensite Alors
      InitCouleurs();
      Param._MAJ.MAJCoupes();
    FinSi

    // experimental: use the full available area
    IncreaseZoomArea();

    InitPositionImages();

    //--- Dans le cas de la memorisation des coupes XY,
    // Si a la fois _MAJ_planXY,  _MAJ_planZY et _MAJ_planXZ sont vrais
    // alors il faut recalculer les coupes XY memorisees
    Si _memorise_coupes_XY Et Param._MAJ._planXZ Et
       Param._MAJ._planZY Et Param._MAJ._planXZ
    Alors
      MAJ_ImagesXY();
/* deprecated TODO: adapt to new comparions
      Pour( i, 0,  _compare_max-1)
        Si _tab_compare_image[i] != NULL Alors
          ((CompareImage*) _tab_compare_image[i])->MAJ_ImagesXY();
        FinSi
      FinPour // i
*/
    FinSi

    DrawingAreaClear();

    Si Param._option_traitement == OPTION_MIP Alors

      Si Param._MAJ._planXY AlorsFait DessinePlanZ();
      Si Non(_MIP_stereo_lunettes) Alors
        AfficheImage( IMAGE_XY);
      FinSi

    Sinon
      Si (Param._type_coupe+1) & (TYPE_COUPE_XY+1) Alors
          if (Param._MAJ._planXY) DrawSlice(IMAGE_XY);
          Si Param._MAJ._planXY Ou affiche Alors
            AfficheImage( IMAGE_XY);
            DessineAxesXY();
          FinSi
      FinSi

      Si (Param._type_coupe+1) & (TYPE_COUPE_XZ+1) Alors
          if (Param._MAJ._planXZ) DrawSlice(IMAGE_XZ);
          Si Param._MAJ._planXZ Ou affiche Alors
            AfficheImage( IMAGE_XZ);
            DessineAxesXZ();
          FinSi
      FinSi

      Si (Param._type_coupe+1) & (TYPE_COUPE_ZY+1) Alors
          if (Param._MAJ._planZY) DrawSlice(IMAGE_ZY);
          Si Param._MAJ._planZY Ou affiche Alors
            AfficheImage( IMAGE_ZY);
            DessineAxesZY();
          FinSi
      FinSi


      Si (Param._type_coupe == TYPE_COUPES) Alors
          Si Param._MAJ._coupes AlorsFait DessineCoupes();
          AfficheImage( IMAGE_COUPES);
      FinSi

    FinSi

  Sinon

    printf("Warning, DessinImage::Paint() \t  intensit�min = intensit�max\n");

  FinSi

  DrawColorBar();

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::Paint()\t 1 \n");

  Comparaisons_Paint();

  Si _circles_ON AlorsFait DessineChampCercles();

  Si _all_contours Alors
    DrawAllContours();
  Sinon
    Pour(i,0,MAX_ISOCONTOURS-1)
      if (_isocontours[i].visible)
        DrawContour(i);
    FinPour
  FinSi

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::Paint()\t 2 \n");

  Si Param._option_traitement == OPTION_MIP Alors
    Si _MIP_stereo_lunettes Alors
      DessineStereo();
    Sinon
      LancePetiteAnimationStereo(3);
      Si Param._MIP._bounding_box AlorsFait DessineBoundingBox();
    FinSi
  FinSi

  Si Non(_vecteur_ON) Alors
    //    XUndefineCursor( display, fenetre);
    //    XFreeCursor( display, curseur);
  FinSi

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::Paint()\t 3 \n");

  Si _shift_deplace Ou _shift_zoom Alors
    Si (Param._type_coupe+1) & (TYPE_COUPE_XY+1) AlorsFait DessineScrollBar( IMAGE_XY);
    Si (Param._type_coupe+1) & (TYPE_COUPE_XZ+1) AlorsFait DessineScrollBar( IMAGE_XZ);
    Si (Param._type_coupe+1) & (TYPE_COUPE_ZY+1) AlorsFait DessineScrollBar( IMAGE_ZY);
  FinSi

  // Check if a Paint callback was set,
  // if so, call the function with its parameters
  if (_paint_callback.get()) {
    bool ok = (*_paint_callback)();
    if (!ok) _paint_callback.reset();
  }

  Si _display_vectors Alors
    DessineChampVecteurs();
  FinSi

  Si Param._curseur._visible Alors
    DessineCurseurs( Param._pos._x, Param._pos._y, Param._pos._z);
    Param._curseur._ON    = true;

#ifndef _NO_GL_
    Si CheckGLWindow() Alors
      Viewer3D_ptr glwin = _GLWindow.lock();
      glwin->GetCanvas()->SetCursor(
            _image->SpacePosX(Param._pos._x),
            _image->SpacePosY(Param._pos._y),
            _image->SpacePosZ(Param._pos._z));
      glwin->Paint();
    FinSi
#endif

  Sinon
    Param._curseur._ON    = false;
  FinSi

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::Paint()\t 4 \n");

  DrawingAreaDisplay();

  Si CheckGLWindow() Alors
    CB_DessineSections3D(this);
  FinSi

  Param._MIP._MAJ       = false;
  Param._MAJ.MAJCoupes( false);
  Param._MAJ._intensite = false;
  _vecteur_ON    = false;

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImage::Paint()\t end\n");

  this->_in_paint=0;

} // Paint()


//----------------------------------------------------------------
void DessinImage::PlayAnimation( )
//                --------------
{

  if ((_ANIM_etat == ANIM_PLAY) &&
      (Param._option_traitement == OPTION_ANIM))
  {
    switch (_type_animation)
    {

      case TYPE_ANIM_FORWARD:
      //     -----------------
        Param._pos._z++;
        Si Param._pos._z > Param._Zoom._zmax AlorsFait Param._pos._z = Param._Zoom._zmin;
      break;

      case TYPE_ANIM_BACKWARD:
      //     ------------------
        Param._pos._z--;
        Si Param._pos._z < Param._Zoom._zmin AlorsFait Param._pos._z = Param._Zoom._zmax;
      break;

      case TYPE_ANIM_AUTOREVERSE:
      //     ---------------------

        Si _ANIM_forward Alors
          Param._pos._z++;
          Si Param._pos._z > Param._Zoom._zmax Alors
            Param._pos._z = Param._Zoom._zmax;
            _ANIM_forward = false;
          FinSi
        Sinon
          Param._pos._z--;
          Si Param._pos._z < Param._Zoom._zmin Alors
            Param._pos._z = Param._Zoom._zmin;
            _ANIM_forward = true;
          FinSi
        FinSi

      break;

    } // end switch

    UpdateAnimation();

    std::list<compare_info>::iterator Iter;
    DessinImage::ptr di;
    for (Iter  = _tab_compare2_image.begin();
        Iter != _tab_compare2_image.end()  ; Iter++ )
    {
      if (!(*Iter).di.expired()) {
        di = (*Iter).di.lock();
        if (di->_compare_depend_position) {
          RecupereTypeCoupe( &di->Param._type_coupe);
          //        RecuperePosition ( di->Param);
          float px = _image->SpacePosX(Param._pos._x);
          float py = _image->SpacePosY(Param._pos._y);
          float pz = _image->SpacePosZ(Param._pos._z);
          di->Param._pos._x = (int) di->_image->SpaceToVoxelX(px);
          di->Param._pos._y = (int) di->_image->SpaceToVoxelY(py);
          di->Param._pos._z = (int) di->_image->SpaceToVoxelZ(pz);

          // check zoom and cursor position
          di->Param.CheckPosition( di->_image );
          di->UpdateAnimation();
        }
      }
    } // end for

    if (m_timer.GetInterval() != (int) (1000.0 / _ANIM_vitesse)) {
      // restart timer with new interval
      m_timer.Stop();
      m_timer.Start((unsigned long) (1000.0 / _ANIM_vitesse),
                    wxTIMER_CONTINUOUS);
    }

  } else {
    m_timer.Stop();
  }

} // PlayAnimation()

//----------------------------------------------------------------
void DessinImage::UpdateAnimation()
//                --------------
{
  ImageDraw_PositionParam::ptr p(_param_position);
  
     //_param_dialog->UpdateParameter( _id_planZ);
    p->UpdateParameter(p->_id_planZ);
  
    DessinePlanZ();
    AfficheImage( IMAGE_XY);
    DrawingAreaDisplay();

    Param._MAJ._planXY = true;
}

//----------------------------------------------------------------
void DessinImage::LanceAnimation( )
//                --------------
{

  Si _image->_tz <= 1 AlorsRetourne;

  _ANIM_forward = true; // for autoreverse
//  _param_Animation->AfficheDialogue();
  //if (!_param_animation->IsShown())
//    ToggleParamPanel(_param_animation.get());
  m_timer.Start((unsigned long) (1000.0 / _ANIM_vitesse),
                wxTIMER_CONTINUOUS);


} // LanceAnimation()


//----------------------------------------------------------------
void DessinImage::LancePetiteAnimationStereo( int n )
//                            --------------------------
{

/* TODO??
    CompareImage*   im_stereo;
    int          i,k,posx,posy;
    XImage*         image[2];
    int          images_par_sec;
    int          image_affichee;

  images_par_sec = 15;

  Si ( Param._option_traitement != OPTION_MIP) AlorsRetourne;
  Si Non(Param._MIP._stereo)                   AlorsRetourne;

  im_stereo = (CompareImage*) _tab_compare_image[_MIP_num_stereo];

  image[0] = _tab_ximage[ IMAGE_XY];
  image[1] = im_stereo ->GetImage(    IMAGE_XY);

  posx = _tab_ximage_pos_x[IMAGE_XY];
  posy = _tab_ximage_pos_y[IMAGE_XY];

  image_affichee = 0;

  _ANIM_timeout = true;
  // 30 images toutes les 4 secondes
  XtAppAddTimeOut( GB_contexte, (unsigned long) (1000.0 / images_par_sec),
             DessinImage::CB_TimeOutAnimation  , this);

  Pour( k,1,2*n)

    // on swappe d'image
    image_affichee = 1 - image_affichee;

    PlaceImage(posx,posy, image[image_affichee]);

    i = 0;
    TantQue (_ANIM_timeout Ou (i<100)) Faire
      Si XtAppPending( GB_contexte) Alors
        XtAppProcessEvent( GB_contexte, XtIMAll);
      FinSi
      i++;
    FinTantQue

   _ANIM_timeout = true;
   XtAppAddTimeOut( GB_contexte, (unsigned long) (1000.0 / images_par_sec),
            DessinImage::CB_TimeOutAnimation  , this);

  FinPour
*/
} // LancePetiteAnimationStereo()


//----------------------------------------------------------------
void DessinImage::EffaceTousLesEcrans( unsigned char expose)
//                            -------------------
{

  EffaceEcran(expose);
  Comparaisons_EffaceEcran( expose);

} // EffaceTousLesEcrans()


//----------------------------------------------------------------
void DessinImage::InitDrawingAreaAll(  )
//                -------------------
{

  DrawingAreaInit();
  _comparison_lock=true;

/* deprecated
  Pour( i, 0, _compare_max-1)
    Si _tab_compare_image[i] != NULL Alors
      ((CompareImage*) _tab_compare_image[i])->DrawingAreaInit();
    FinSi
  FinPour // i
*/

  std::list<compare_info>::iterator Iter;
  for (Iter  = _tab_compare2_image.begin();
       Iter != _tab_compare2_image.end()  ; Iter++ )
    if (!(*Iter).di.expired())
      ((*Iter).di.lock())->DrawingAreaInit();
  _comparison_lock=false;

} // InitDrawingAreaAll()


//----------------------------------------------------------------
void DessinImage::SetImageSize( )
//                -------------
{

  ImageDraw_ZoomFactorParam::ptr zoomFactor(_param_zoomfactor);
  
  ComputeBasicSizes();

  Fixe_drawing_dimensions(  _image->_tx+
                            _colorbar_width+
                            _right_axe_width+10,
                            _image->_ty+
                            _bottom_axe_height+10);
  _type_facteur = FACTEUR_ENTIER;
//  _param_ZoomFacteur->UpdateParameter(_id_type_facteur);
  zoomFactor->UpdateParameter(zoomFactor->_id_type_facteur);

  _facteur_entier = 1;
//  _param_ZoomFacteur->UpdateParameter(_id_facteur_valentier);
  zoomFactor->UpdateParameter(zoomFactor->_id_facteur_valentier);

  Param._MAJ.MAJCoupes();
  Comparaisons_MAJ_taille( );
  EffaceTousLesEcrans(false);
  Paint();

} // SetImageSize()


//----------------------------------------------------------------
void DessinImage::ReDimensionne( )
//                  -------------
{

  if (this->IsShown()) {
    InitDrawingAreaAll( );
    Param._MAJ.MAJCoupes();
    Comparaisons_MAJ_taille( );
  }
//  EffaceTousLesEcrans(false);
//  Paint();

} // ReDimensionne()



//----------------------------------------------------------------
void DessinImage::CB_Close(wxCommandEvent&)
//                            ---------
{

// TODO: check memory problems:
// don't do anything here since
// the parent FenetreDessin takes care of
// a closing callback ...

   this->Close();
//  CloseWindow();

    // cannot delete the pointer like this ... this->~DessinImage();

} // CB_Close()


//----------------------------------------------------------------
void DessinImage::CB_parametres_visibles( wxCommandEvent& event)
//                            ----------------------
{
  ToggleParamPanel(_param_position.get());
  ToggleParamPanel(_param_intensity.get());
  ToggleParamPanel(_param_vectors.get());
  ToggleParamPanel(_param_isocontour.get());
  ToggleParamPanel(_param_imagesurface.get());
  
  if (this->GetSize().GetHeight() >= this->_param_book->GetSize().GetHeight()) {
    this->SetSize(this->GetSize().GetWidth()+this->_param_book->GetSize().GetWidth(),
                  this->GetSize().GetHeight());
  }
  else {
    this->SetSize(this->GetSize().GetWidth()+this->_param_book->GetSize().GetWidth(),
                  this->_param_book->GetSize().GetHeight());
  }

 
  this->Refresh();
  this->Update();
  this->manager.Update();
    
  DessinImage*    di = (DessinImage*) this;
  
//printf("1 %d \n",(int)Param._parametres_visible);

  Param._parametres_visible =  menuOptions->IsChecked(ID_MenuOptions_paramwin);
//printf("2 %d \n",(int)Param._parametres_visible);

  Si di->Param._parametres_visible Alors
    //di->_param_dialog->AfficheDialogue();

    /* TODO
    Si  di->Param._parametres_visible Et
        Non(di->_interpole_ligne->WidgetCreated())
    Alors
//printf("3\n");
      di->_interpole_ligne->CreeWidget(di->_palette);
      di->_interpole_ligne->Fixe_drawing_bg( wxColour(255,255,255));
      di->_interpole_ligne->DrawingAreaInit( );
      di->_interpole_ligne->Paint();
    FinSi
    */
  Sinon
//printf("4\n");
    //di->_param_dialog->FermeDialogue( );
  FinSi
// printf("5\n");
  
} // CB_parametres_visibles()


//----------------------------------------------------------------
void DessinImage::CB_voxel(  wxCommandEvent& event)
//                            --------
{

//  _param_voxel->AfficheDialogue(/*&(this->_etat_voxel)*/);
  ToggleParamPanel(_param_voxel.get());

} // CB_voxel()


//----------------------------------------------------------------
void DessinImage::CB_relire(  wxCommandEvent& event)
//                ---------
{
    DessinImage*    di = this;
    InrImage::ptr  image;

  Si di->Param._option_traitement != OPTION_COUPE Alors
    wxMessageBox( wxString::FromAscii("You must be in 'SLICE' option for ReRead"),
                  wxString::FromAscii("File ReLoad"),
                  wxICON_ERROR);
    return;
  FinSi

  try{
  image = InrImage::ptr(new InrImage(di->_image_initiale->GetName()));
  }
  catch(InrImage::ErreurLecture){
    wxMessageBox( wxString::FromAscii("Read Error"),
                  wxString::FromAscii("File ReLoad"),
                  wxICON_ERROR);
    return;
  }

  Si (image->_tx != di->_image_initiale->_tx) Ou
     (image->_ty != di->_image_initiale->_ty) Ou
     (image->_tz != di->_image_initiale->_tz)
  Alors
    wxMessageBox( wxString::FromAscii("Image dimensions have changed."),
                  wxString::FromAscii("File ReLoad"),
                  wxICON_ERROR);
    return;
  FinSi

// not needed, smart pointer
//  delete di->_image_initiale;

  di->_image = di->_image_initiale = image;
  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_relire()


//----------------------------------------------------------------
void DessinImage::CB_comparer( wxCommandEvent& event)
//                            -----------
{
//    DessinImage*    di = this;
/* Deprecated
  di->_param_nom_image->AfficheDialogue();
*/
  // TODO: fix problems of etat variable here !!
/*
  Si etat == SORTIE_OK Alors
    di->CreeCompareImage( (char*)di->_nom_nouvelle_image.c_str(), (char*)di->_nom_nouvelle_image.c_str());
  FinSi
*/
} // CB_Comparer()


/*
//----------------------------------------------------------------
void DessinImage::(  wxCommandEvent&)
//                ---------------
{
    DessinImage*    di = (DessinImage*) this;

  di->_param_nom_fichier->ContraintesNomFichier( di->_id_nom_fichier, "", ".", "*.fic");
  di->_param_nom_fichier->AfficheDialogue();
  // TODO: fix problems of etat variable here !!

  Si etat == SORTIE_OK Alors
    di->SauveFichierParametres( (char*)di->_nom_fichier.c_str());
  FinSi
} // CB_Sauver_param()
*/


//----------------------------------------------------------------
void DessinImage::CB_sauver_image( wxCommandEvent&)
//                ---------------
{
//    DessinImage*    di = (DessinImage*) this;

  //di->_param_sauve_image->AfficheDialogue();

/*
  // TODO: fix problems of etat variable here !!

  Si etat == SORTIE_OK Alors
    switch ( di->_type_sauvegarde ){
      case SAUVE_INRIMAGE:   di->SauveImage( (char*)di->_nom_sauve_image.c_str()); break;
      case SAUVE_PS_GRIS:
      case SAUVE_PS_COULEUR:
        di->SauveImagePS( di->_nom_sauve_image.c_str());
      break;
    } // end switch
  FinSi
*/

} // CB_Sauver_image()


//----------------------------------------------------------------
void DessinImage::CB_image_info(  wxCommandEvent& )
//                            -------------
{
//  this->_param_image_info->AfficheDialogue();
  ToggleParamPanel(_param_image_info.get());
} // CB_image_info()


//----------------------------------------------------------------
void DessinImage::CB_circles(  wxCommandEvent& )
//                            ----------
{
//  _param_circles->AfficheDialogue();
  ToggleParamPanel(_param_circles.get());
} // CB_Circles()


//----------------------------------------------------------------
void DessinImage::CB_AfficheChampVect(  void* cd, void*)
//                -------------------
{


    DessinImage*    di = (DessinImage*) cd;

  di->Param._MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();

  di->DessineChampVecteurs();

} // CB_AfficheChampVect()


//----------------------------------------------------------------
void DessinImage::CB_voxels3D(  wxCommandEvent&)
//                -----------
{
  DessinImage*    di = (DessinImage*) this;
  bool  init;
  float min, max;

  if (GB_debug)
    printf("CB_voxels3D\n");
  if ((di->_image->_format == WT_FLOAT ) ||
     (di->_image->_format == WT_DOUBLE)) 
  {
    min = di->_intensite_float_min;
    max = di->_intensite_float_max;
    if (GB_debug)
      printf("min max %f %f \n", min, max);
  }
  else
  {
    min = di->_intensite_entier_min;
    max = di->_intensite_entier_max;
  }

  if (GB_debug)
    printf("min max %f %f \n", min, max);

//  di->_param_Voxels3D->AfficheDialogue();
  ToggleParamPanel(_param_voxels3D.get());
  
  //If _param_voxels3D isn't shown, dont show a GL window
  if (! _param_voxels3D->IsShown()) {
    return;
  }

  if (!(di->CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else
  {
    init = false;
  }

  if (GB_debug)
    printf("CB_voxels3D() 3.0 \n");


  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  glwin->GetCanvas()->CreeVoxels3D( di->_image.get(),
                   di->_voxels3D_seuilbas,
                   di->_voxels3D_seuilhaut,
                   min,
                   max,
                   di->_image->_size_x,
                   di->_image->_size_y,
                   di->_image->_size_z);


  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }
//  else
//  {
//    glwin->Close();
//  }

  glwin->Paint();

  if (GB_debug)
    printf("CB_voxels3D() End \n");


} // CB_voxels3D()


//----------------------------------------------------------------
void DessinImage::CB_GLMIP(  wxCommandEvent&)
//                --------
{
  DessinImage*    di = (DessinImage*) this;
  bool  init;
  float min, max;

  if (GB_debug) printf("CB_GLMIP\n");
  if ((di->_image->_format == WT_FLOAT ) ||
     (di->_image->_format == WT_DOUBLE)) 
  {
    min = di->_intensite_float_min;
    max = di->_intensite_float_max;
    if (GB_debug) printf("min max %f %f \n", min, max);
  }
  else
  {
    min = di->_intensite_entier_min;
    max = di->_intensite_entier_max;
  }

  if (GB_debug) printf("min max %f %f \n", min, max);

//  di->_param_GLMIP->AfficheDialogue();
  ToggleParamPanel(_param_glmip.get());

  if (!_param_glmip->IsShown()) {
    return;
  }
  
  if (!(di->CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else
  {
    init = false;
  }

  if (GB_debug) printf("CB_GLMIP() 3.0 \n");


  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  glwin->GetCanvas()->CreeGLMIP( di->_image,
                di->_GLMIP_seuilbas,
                di->_GLMIP_seuilhaut,
                min,
                max,
                di->_GLMIP_maxquads);


  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }
//  else
//  {
//    glwin->Close();
//  }
 
  glwin->Paint();

  if (GB_debug) printf("CB_GLMIP() End \n");

} // CB_GLMIP()


//----------------------------------------------------------------
void DessinImage::CB_VOLREN( wxCommandEvent&)
//                            -----------
{
  DessinImage*    di = (DessinImage*) this;
  bool  init;
  float min, max;

  if (GB_debug) printf("CB_GLMIP\n");
  if ((di->_image->_format == WT_FLOAT ) ||
     (di->_image->_format == WT_DOUBLE))
  {
    min = di->_intensite_float_min;
    max = di->_intensite_float_max;
    if (GB_debug) printf("min max %f %f \n", min, max);
  }
  else
  {
    min = di->_intensite_entier_min;
    max = di->_intensite_entier_max;
  }
  if (GB_debug) printf("min max %f %f \n", min, max);

//  di->_param_VOLREN->AfficheDialogue();
  ToggleParamPanel(_param_volren.get());
  
  if (! _param_volren->IsShown()) {
    return;
  }
  
  if (!(di->CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else
  {
    init = false;
  }

  if (GB_debug) printf("CB_VOLREN() 3.0 \n");

  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  glwin->GetCanvas()->InitVolRen( di->_image.get(),
                 min,
                 max,
                 di,
                 this->Get_volren_opacity());

  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }
//  else
//  {
//    glwin->Close();
//  }
  
  glwin->Paint();

  if (GB_debug) printf("CB_VOLREN() End \n");


} // CB_VOLREN()


//----------------------------------------------------------------
void DessinImage::CB_sections3D(  wxCommandEvent&)
//                            -------------
{
    DessinImage*    di = (DessinImage*) this;
    bool  init;
    float min, max;

//printf("CB_voxels3D\n");
  if ((di->_image->_format == WT_FLOAT ) ||
     (di->_image->_format == WT_DOUBLE)) 
  {
    min = di->_intensite_float_min;
    max = di->_intensite_float_max;
  }
//printf("min max %f %f \n", min, max);
  else 
  {
    min = di->_intensite_entier_min;
    max = di->_intensite_entier_max;
  }
  //printf("min max %f %f \n", min, max);

//  di->_param_Sections3D->AfficheDialogue();
  ToggleParamPanel(_param_sections3D.get());

  if (! _param_sections3D->IsShown()) {
    return;
  }
  
  if (!(di->CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else
  {
    init = false;
  }

  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }
//  else 
//  {
//    glwin->Close();
//  }

  
  glwin->Paint();

} // CB_sections3D()


//----------------------------------------------------------------
void DessinImage::CB_CloseGL( void* cd)
//                            ----------
{
  DessinImage*    di = (DessinImage*) cd;

  CLASS_MESSAGE_STATIC(di," call");
  CLASS_MESSAGE_STATIC(di,format(" use_count() %1%") % di->_GLWindow0.use_count());

  di->_GLWindow0->Close(true);
  di->_GLWindow0->Destroy();

  // no deleter for the shared pointer, will be deleted by its parent ...
  di->_GLWindow0 = Viewer3D_ptr();
} // CB_CloseGL()


//----------------------------------------------------------------
void DessinImage::CB_couleurs(  wxCommandEvent&)
//                            -----------
{
  ToggleParamPanel(_param_colors.get());

//    DessinImage*    di = (DessinImage*) this;
//
//  di->_param_couleurs->AfficheDialogue();

} // CB_couleurs()


//----------------------------------------------------------------
void DessinImage::CB_MIP_min_max(  wxCommandEvent& event)
//                            --------------
{

    DessinImage*    di = (DessinImage*) this;

//  Param._MIP._min_max = menuMIP->IsChecked(ID_MenuMIP_minmax);

  Si Non(di->Param._MIP._min_max) Alors
    di->_MIP->FixeLimites();
  Sinon
    Si ( di->_image->_format == WT_FLOAT ) Ou
       ( di->_image->_format == WT_DOUBLE)
    Alors
      di->_MIP->FixeLimites( di->_intensite_float_min,
                 di->_intensite_float_max);
    Sinon
      di->_MIP->FixeLimites( di->_intensite_entier_min,
                 di->_intensite_entier_max);
     FinSi
     //    di->_boutton_min_max->ChangeTitre("Ne pas utiliser min-max");
  FinSi

  di->_image_MIP = InrImage::ptr(di->_MIP->CreeMIP(
      di->Param._MIP._rot_X,
      di->Param._MIP._rot_Y,
      di->Param._MIP._rot_Z ));
  di->Param._MIP._MAJ   = true;
  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_MIP_min_max()


//----------------------------------------------------------------
void DessinImage::CB_MIP_rapide( wxCommandEvent&)
//                            -------------
{


    DessinImage*    di = (DessinImage*) this;

//  _MIP_rapide = menuMIP->IsChecked(ID_MenuMIP_Proj_fast);

  di->Param._MAJ.MAJCoupes();
  di->Paint();

  di->_MIP->MIPRapide( di->_MIP_rapide);

} // CB_MIP_rapide()


//----------------------------------------------------------------
void DessinImage::CB_MIP_bounding_box( wxCommandEvent& event)
//                            -------------------
{


    DessinImage*    di = (DessinImage*) this;

//  Param._MIP._bounding_box = menuMIP->IsChecked(ID_MenuMIP_boundingbox);

  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_MIP_bounding_box()


//----------------------------------------------------------------
void DessinImage::CB_MIP_zoom_bounding_box( wxCommandEvent&)
//                            ------------------------
{


    DessinImage*    di = (DessinImage*) this;
    float            x,y,z,xmin,xmax,ymin,ymax;
    int          tx,ty,tz;

  tx = di->_image_initiale->_tx-1;
  ty = di->_image_initiale->_ty-1;
  tz = di->_image_initiale->_tz-1;

  di->_MIP->Projection2( 0, 0, 0, &x, &y, &z);
  xmin=xmax=x;
  ymin=ymax=y;

  di->_MIP->Projection2( tx, 0, 0, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( tx, ty, 0, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( 0, 0, tz, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( 0, 0, tz, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( tx, 0, tz, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( 0, ty, tz, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->_MIP->Projection2( tx, ty, tz, &x, &y, &z);
  xmin = macro_min(xmin,x);  xmax = macro_max(xmax,x);
  ymin = macro_min(ymin,y);  ymax = macro_max(xmax,y);

  di->Param._Zoom._xmin = (int) (xmin-0.01);  di->Param._Zoom._ymin = (int) (ymin-0.01);
  di->Param._Zoom._xmax = (int) (xmax+0.99);  di->Param._Zoom._ymax = (int) (ymax+0.99);
  di->Param._Zoom.ComputeSize();
  di->Param._MAJ._planXY = true;
  di->EffaceTousLesEcrans( false);
  di->Paint();

} // CB_MIP_zoom_bounding_box()


//----------------------------------------------------------------
void DessinImage::CB_MIP_precise(  wxCommandEvent&)
//                            --------------
{

    DessinImage*    di = (DessinImage*) this;

  di->_image_MIP = InrImage::ptr(di->_MIP->CreeMIP_precise());
  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_MIP_precise()


//----------------------------------------------------------------
void DessinImage::CB_MIP_lin_interp( wxCommandEvent&)
//                            -----------------
{
    DessinImage*    di = (DessinImage*) this;

  aff_err("interpolation lin�ire \n");

#if defined(__WXMOTIF__)
    Cursor curseur = 0;
  curseur = XCreateFontCursor( di->display, XC_watch);
  XDefineCursor( di->display, di->fenetre, curseur);
#endif

  di->_image_MIP = InrImage::ptr(di->_MIP->CreeMIP_interpol_lineaire());
  di->Param._MAJ.MAJCoupes();

#if defined(__WXMOTIF__)
  XUndefineCursor( di->display, di->fenetre);
  XFreeCursor( di->display, curseur);
#endif

  aff_err("FIN interpolation lin�ire \n");

  di->Paint();

} // CB_MIP_lin_interp()


//----------------------------------------------------------------
void DessinImage::CB_fichier_crest(  wxCommandEvent& event)
//                            ----------------
{
/* removing this feature: needs to be redone
  using openGL ...
  this->_crest_view = new ListCrestView( this);
*/
} // CB_fichier_crest()


//----------------------------------------------------------------
void DessinImage::CB_MIP_stereo(  wxCommandEvent& )
//                            -------------
{
/* deprecated

    DessinImage*    di = (DessinImage*) this;
    Chaine          titre;
    int          numero_image;
    CompareImage*   im_stereo;
    int          Pos_x, Pos_y;
    int          Hauteur, Largeur;

  Si Non(di->Param._MIP._stereo) Alors
    di->LibereCompareImage( di->_MIP_num_stereo);
  Sinon
    titre = "stereo:";
    titre += di->_image_initiale->GetName();

//    numero_image = di->CreeCompareImage( (char*) titre, di->_image_initiale, false);

    Si numero_image != -1 Alors
      di->_MIP_num_stereo = numero_image;

      im_stereo = (CompareImage*) di->_tab_compare_image[numero_image];
      im_stereo->FixeDecalStereo( di->Param._MIP._decal_stereo);

      // Position de l'image
      di->Recupere_fenetre_position(   &Pos_x,   &Pos_y  );
      di->Recupere_fenetre_dimensions( &Largeur, &Hauteur);
      im_stereo->Fixe_fenetre_position( Pos_x+Largeur+10, Pos_y);
      im_stereo->Paint( );
    FinSi
  FinSi
*/
} // CB_MIP_stereo()


//----------------------------------------------------------------
void DessinImage::CB_MIP_anim_stereo(  wxCommandEvent&)
//                            ------------------
{


    DessinImage*    di = (DessinImage*) this;

  Si Non(di->Param._MIP._stereo) AlorsRetourne;
  Si di->_MIP_stereo_lunettes AlorsRetourne;

  di->LancePetiteAnimationStereo( 15);

} // CB_MIP_anim_stereo()


//----------------------------------------------------------------
void DessinImage::CB_MIP_stereo_lunettes(  wxCommandEvent&)
//                            ----------------------
{

/* deprecated
    DessinImage*    di = (DessinImage*) this;
    CompareImage*   im_stereo;
    float            voxel_cm;

  Si Non(di->Param._MIP._stereo) AlorsFait return;

  im_stereo = (CompareImage*) di->_tab_compare_image[ di->_MIP_num_stereo];

  di->_MIP_stereo_lunettes = true;

  Si Non(di->_MIP_stereo_lunettes) Alors

    di->_param_MIP_stereo->AfficheDialogue();
    di->_MIP->DesActiveStereo();

    im_stereo->FixeDecalStereo( di->Param._MIP._decal_stereo);

    di->Param._MIP._MAJ   = true;
    di->Param._MAJ.MAJCoupes();
    di->Paint();

  Sinon

      di->_param_MIP_stereo->AfficheDialogue();

      // Pas de rotation
      im_stereo->FixeDecalStereo( 0);

      voxel_cm = di->_pixel_cm / di->_size_x;
      im_stereo->_MIP->ActiveStereo( di->_distance_yeux       * voxel_cm,
                                     di->_distance_oeil_ecran * voxel_cm,
                                     di->_distance_ecran_objet* voxel_cm);
      im_stereo->_MIP->StereoOeilDroit();

      di       ->_MIP->ActiveStereo( di->_distance_yeux       * voxel_cm,
                                     di->_distance_oeil_ecran * voxel_cm,
                                     di->_distance_ecran_objet* voxel_cm);
      di       ->_MIP->StereoOeilGauche();

      di->Param._MIP._MAJ   = true;
      di->Param._MAJ.MAJCoupes();
      di->Paint();
  FinSi
*/

} // CB_MIP_stereo_lunettes()


//----------------------------------------------------------------
void DessinImage::CB_MIP_stereo_param( void* cd)
//                            -------------------
{

/* deprecated
    DessinImage*    di = (DessinImage*) cd;
    CompareImage*   im_stereo;
    float            voxel_cm;


  Si Non(di->_MIP_stereo_lunettes) AlorsRetourne;

  im_stereo = (CompareImage*) di->_tab_compare_image[ di->_MIP_num_stereo];

  voxel_cm = di->_pixel_cm / di->_size_x;
  im_stereo->_MIP->ActiveStereo( di->_distance_yeux       * voxel_cm,
                                 di->_distance_oeil_ecran * voxel_cm,
                                 di->_distance_ecran_objet* voxel_cm);
  im_stereo->_MIP->StereoOeilDroit();

  di       ->_MIP->ActiveStereo( di->_distance_yeux       * voxel_cm,
                                 di->_distance_oeil_ecran * voxel_cm,
                                 di->_distance_ecran_objet* voxel_cm);
  di       ->_MIP->StereoOeilGauche();

  di->_image_MIP = InrImage::ptr(di->_MIP->CreeMIP(
      di->Param._MIP._rot_X,
      di->Param._MIP._rot_Y,
      di->Param._MIP._rot_Z ));
  di->Param._MIP._MAJ = true;
  di->Param._MAJ.MAJCoupes();
  di->Paint( );
*/
} // CB_MIP_stereo_param()


//----------------------------------------------------------------
void DessinImage::CB_parametresMIP_visibles( wxCommandEvent& event)
//                            -------------------------
{

//  _MIP_parametres_visibles = menuMIP->IsChecked(ID_MenuMIP_param);

  Si _MIP_parametres_visibles Alors
//    _param_MIP->AfficheDialogue();
    _param_mip->AfficheDialogue();
  Sinon
//    _param_MIP->FermeDialogue( );
    ToggleParamPanel(_param_mip.get());
  FinSi

} // CB_parametresMIP_visibles()


//----------------------------------------------------------------
void DessinImage::CB_DessineSections3D(  void* cd )
//                            ------------------
{


    DessinImage*    di = (DessinImage*) cd;

  Si Non(di->CheckGLWindow()) AlorsFait return;

//printf( "CB_DessineSections3D XY \n");

//  Si di->_image->_format != WT_FLOAT Et
//     (di->_sectionXY_visible Ou
//      di->_sectionXZ_visible Ou
//      di->_sectionYZ_visible)
//  Alors
//    fprintf(stderr,"Limited to FLOAT images for the moment \n");
//    return;
//  FinSi


  if ((!di->_sectionXY_visible)&&
      (!di->_sectionXZ_visible)&&
      (!di->_sectionYZ_visible))
      return;

  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  glwin->GetCanvas()->SetLimits(
    di->_image->SpacePosX(di->Param._Zoom._xmin),
    di->_image->SpacePosX(di->Param._Zoom._xmax),
    di->_image->SpacePosY(di->Param._Zoom._ymin),
    di->_image->SpacePosY(di->Param._Zoom._ymax),
    di->_image->SpacePosZ(di->Param._Zoom._zmin),
    di->_image->SpacePosZ(di->Param._Zoom._zmax)
  );

  glwin->GetCanvas()->InitSection( di->_image.get(),
                  0,
                  di->Param._pos._z,
                  di->_sectionXY_visible,
                  di->GetMinIntensity(),
                  di->GetMaxIntensity(),
                  di->Param._Zoom);

//printf( "CB_DessineSections3D XZ \n");

  glwin->GetCanvas()->InitSection( di->_image.get(),
                  1,
                  di->Param._pos._y,
                  di->_sectionXZ_visible,
                  di->GetMinIntensity(),
                  di->GetMaxIntensity(),
                  di->Param._Zoom);

//printf( "CB_DessineSections3D YZ \n");

  glwin->GetCanvas()->InitSection( di->_image.get(),
                  2,
                  di->Param._pos._x,
                  di->_sectionYZ_visible,
                  di->GetMinIntensity(),
                  di->GetMaxIntensity(),
                  di->Param._Zoom);


  glwin->Paint();

} // CB_DessineSections3D()


//----------------------------------------------------------------
void DessinImage::CB_MasqueVisible( wxCommandEvent& event)
//                            ----------------
{


    DessinImage*    di = (DessinImage*) this;

printf("1\n");
//  _dessine_masque = menuOptions->IsChecked(ID_MenuOptions_display_mask);

printf("1.1 %d \n",(int)_dessine_masque);
  Si di->_image_masque == NULL Alors
    di->_dessine_masque = false;
    menuOptions->Check(ID_MenuOptions_display_mask,_image_masque);
//(di->_Moptions_masque_visible)->MAJ();
  FinSi

printf("1.2\n");
  di->Param._MAJ.MAJCoupes();
  di->Paint();

printf("2\n");
} // CB_MasqueVisible()


//----------------------------------------------------------------
void DessinImage::CB_redessine( void* cd)
//                            ------------
{


     DessinImage*    di = (DessinImage*) cd;

  Si (di->Param._type_coupe == TYPE_COUPES) Et (di->_image->_tz > 1) Alors
//    di->_param_CoupesXY->AfficheDialogue();
    di->ToggleParamPanel(di->_param_coupesxy.get());
  FinSi

  di->Param._MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();

} // CB_redessine()

  
//----------------------------------------------------------------
void DessinImage::CB_redraw( wxCommandEvent& event)
{

     DessinImage*    di = (DessinImage*) this;
//     unsigned char         nouvelle_valeur;
  
//  nouvelle_valeur =  di->_wxm_type_coupe->ValueChanged(event);

//  if ((di->Param._type_coupe == TYPE_COUPES) && (di->_image->_tz > 1)) {
//    //    di->_param_CoupesXY->AfficheDialogue();
//    if (!_param_coupesxy->IsShown())  
//      ToggleParamPanel(_param_coupesxy.get());
//  } else{
//    if (_param_coupesxy->IsShown())  
//      ToggleParamPanel(_param_coupesxy.get());
//  }
  
  di->Param._MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();
  
}


//----------------------------------------------------------------
void DessinImage::CB_option_traitement( wxCommandEvent& event)
//                            --------------------
{


     DessinImage*    di = (DessinImage*) this;
//     unsigned char         nouvelle_valeur;


//  nouvelle_valeur =  di->_wxm_mode->ValueChanged(event);

//  nouvelle_valeur =  di->_Moptions_mode->ValueChanged();
//return;
//  Si Non(nouvelle_valeur) AlorsRetourne;

  switch ( di->Param._option_traitement ){
    case OPTION_MIP:
      lastView = di->Param._type_coupe;
      di->MemoriseCoupesXY( false);
      di->Comparaisons_MemoriseCoupesXY( false);
      // on force l'affichage d'une image 2D
      //    di->Param._type_coupe == TYPE_COUPE_XY;
      //     di->_param_dialog->UpdateParameter( di->_id_type_coupe);

      // Il faut remplacer l'image courante
      // par l'image de projection MIP
      di->_MIP->FixeVoxelSize( di->Param._dim._voxel_size_x,
                   di->Param._dim._voxel_size_y,
                   di->Param._dim._voxel_size_z );
      di->_MIP->FixeLimites( di->Param._Zoom._xmin, di->Param._Zoom._xmax,
                 di->Param._Zoom._ymin, di->Param._Zoom._ymax,
                 di->Param._Zoom._zmin, di->Param._Zoom._zmax);
      di->_image_MIP = InrImage::ptr(di->_MIP->CreeMIP(
        di->Param._MIP._rot_X,
        di->Param._MIP._rot_Y,
        di->Param._MIP._rot_Z));
      di->Param._MIP._MAJ   = true;
      di->Param.ChangeTypeCoupeMIP();
      di->ChangeImage( di->_image_MIP);
      
//      di->_param_MIP->AfficheDialogue();
      
      if (_param_animation->IsShown())
        ToggleParamPanel(_param_animation.get());
      
      ToggleParamPanel(_param_mip.get());

    break;

    case OPTION_ANIM:
      di->ChangeImage( di->_image_initiale);
      di->MemoriseCoupesXY( true);
      di->Comparaisons_MemoriseCoupesXY( true);
      
      if (_param_mip->IsShown())
      {
        ToggleParamPanel(_param_mip.get());
        RestoreView(event);
      }
      
      if (!(di->_image->_tz > 1)) {
        wxMessageDialog* message = new wxMessageDialog(this, wxT("You are showing a two-dimensional image."),
                                                       wxT("Viewer Error"), wxOK | wxICON_EXCLAMATION);
        message->ShowModal();
        return;
      }
      ToggleParamPanel(_param_animation.get());
      di->LanceAnimation();
    break;

    case OPTION_COUPE:
      if (_param_mip->IsShown()) {
        ToggleParamPanel(_param_mip.get());
        RestoreView(event);
      }

      if (_param_animation->IsShown()) {
        Set_ANIM_STOP();
        ToggleParamPanel(_param_animation.get());
        RestoreView(event);
      }
      di->MemoriseCoupesXY( false);
      di->Comparaisons_MemoriseCoupesXY( false);
      di->ChangeImage( di->_image_initiale);
    break;

  } // end switch

/* MIP sub-menu
  Si di->Param._option_traitement == OPTION_MIP Alors
    XtManageChild((Widget)(*di->_Mmip));
  Sinon
    if (XtIsManaged((Widget)(*di->_Mmip)))
      XtUnmanageChild((Widget)(*di->_Mmip));
  FinSi
*/

} // CB_option_traitement()


//----------------------------------------------------------------
void DessinImage::CB_UpdateComparison( wxCommandEvent& event)
//                            --------------------
{
//printf("CB_UpdateComparison\n");

  _compare_normalize_intensity = menuCompare->IsChecked(ID_MenuCompare_NormalizeIntensity);
  _compare_depend_position     = menuCompare->IsChecked(ID_MenuCompare_DependPosition);
  _compare_depend_intensity    = menuCompare->IsChecked(ID_MenuCompare_DependIntensity);

} // CB_UpdateComparison()

//----------------------------------------------------------------
void DessinImage::CB_UpdateMinMax( wxCommandEvent& event)
//                            ---------------
{
//printf("CB_UpdateComparison\n");

  UpDateMinMax();

} // CB_UpdateMinMax()


//----------------------------------------------------------------
void DessinImage::CB_fonction_intensite( void* cd)
//                            ---------------------
{


     DessinImage*    di = (DessinImage*) cd;

  di->Param._MAJ._intensite = true;
  di->Param._MAJ.MAJCoupes();
//  di->EffaceTousLesEcrans( false);
  di->Paint();

} // CB_fonction_intensite()

  
//----------------------------------------------------------------
void DessinImage::CB_fonction_zoom( wxCommandEvent& event)
//                            ----------------
{


     DessinImage*    di = (DessinImage*) this;

//  if (di->_wxm_zoom->ValueChanged(event))
    Si di->Param._fonction_zoom == FUNC_UNZOOM Alors
      di->Param._Zoom.InitLimites( di->_image.get());
      di->Param._MAJ.MAJCoupes();
      di->EffaceTousLesEcrans( false);
      di->Paint();
    FinSi
  

} // CB_fonction_zoom()


//----------------------------------------------------------------
void DessinImage::CB_type_taille(wxCommandEvent& event )
//                            --------------
{


     DessinImage*    di = (DessinImage*) this;
//     unsigned char         nouvelle_valeur;

//  nouvelle_valeur =  di->_wxm_type_taille->ValueChanged(event);

//  Si Non(nouvelle_valeur) AlorsRetourne;

  switch ( di->Param._type_taille ){

    case TAILLE_FENETRE:
//      di->_param_ZoomFacteur->FermeDialogue( );
      if (_param_zoomfactor->IsShown()) {
        ToggleParamPanel(_param_zoomfactor.get());
      }
      di->Param._MAJ.MAJCoupes();
      di->EffaceTousLesEcrans( false);
      di->Paint();
    break;

    case TAILLE_FACTEUR:
//      di->_param_ZoomFacteur->AfficheDialogue();
      ToggleParamPanel(_param_zoomfactor.get());
      di->Param._MAJ.MAJCoupes();
      di->EffaceTousLesEcrans( false);
      di->Paint();
    break;

  } // end switch
  
} // CB_type_taille()


//----------------------------------------------------------------
void DessinImage::CB_image_size(  wxCommandEvent&)
//
{


     DessinImage*    di = (DessinImage*) this;

  di->SetImageSize();

} // CB_image_size()


//----------------------------------------------------------------
void DessinImage::CB_largeur_lignes( wxCommandEvent& event)
//                            -----------------
{


     DessinImage*    di = (DessinImage*) this;
     unsigned char         nouvelle_valeur;

  nouvelle_valeur =  di->_wxm_linewidth->ValueChanged(event);
  Si Non(nouvelle_valeur) AlorsRetourne;

  di->SetLineParameters( di->_largeur_lignes+1,  PENSTYLE_SOLID, wxCAP_ROUND, wxJOIN_MITER);
  di->EffaceTousLesEcrans( false);
  di->Paint();

} // CB_largeur_lignes()


//----------------------------------------------------------------  
void DessinImage::Create_Toolbar()
{
  //View parameters
/*
#if (wxCHECK_VERSION(2,9,0))
    wxToolBar* tb1 = new wxToolBar(this, wxID_ANY,
                        wxDefaultPosition, wxDefaultSize);
  #else
    wxAuiToolBar* tb1 = new wxAuiToolBar(this, wxID_ANY,
                        wxDefaultPosition, wxDefaultSize,
                        wxAUI_TB_DEFAULT_STYLE |
                        wxAUI_TB_OVERFLOW);
  #endif
  */
  #if (!WIN32)&&(!__WXMAC__)
    ViewParameters = new wxToolBar(this, wxID_ANY,
                          wxDefaultPosition, wxDefaultSize);
                       //   wxAUI_TB_DEFAULT_STYLE  | wxAUI_TB_OVERFLOW );
  #else
    ViewParameters = new wxAuiToolBar(this, wxID_ANY,
                          wxDefaultPosition, wxDefaultSize,
                          wxAUI_TB_DEFAULT_STYLE  | wxAUI_TB_OVERFLOW );
  #endif
  
  ViewParameters->SetToolBitmapSize(wxSize(16,16));
  
  ViewParameters->AddTool(wxID_IMAGE_INFORMATION, wxT("Inf."),
                         wxBitmap(wxImage(Info_xpm).Rescale(16,16)), 
                         wxT("Image information"), wxITEM_CHECK);  
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_VOXEL_SIZE, wxT("V.Size"),
                         wxBitmap(wxImage(Units_xpm).Rescale(16,16)),
                         wxT("Voxel size"), wxITEM_CHECK);
  ViewParameters->AddSeparator();

  ViewParameters->AddTool(wxID_RELOAD, wxT("Rel."),
                         wxBitmap(wxImage(Refresh_xpm).Rescale(16,16)),
                         wxT("Reload image"));
  ViewParameters->AddSeparator();

  ViewParameters->AddTool(wxID_POSITION, wxT("Pos."),
                         wxBitmap(wxImage(Target_xpm).Rescale(16,16)),
                         wxT("Position"), wxITEM_CHECK);
  ViewParameters->AddSeparator();

  ViewParameters->AddTool(wxID_INTENSITY, wxT("Int."),
                         wxBitmap(wxImage(Contrast_xpm).Rescale(16,16)),
                         wxT("Intensity"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_VECTORS, wxT("Vec."),
                         wxBitmap(wxImage(Arrow_xpm).Rescale(16,16)),
                         wxT("Vectors"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_ISO_CONTOURS, wxT("IsoCon."),
                         wxBitmap(wxImage(Curve_xpm).Rescale(16,16)),
                         wxT("IsoContours"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_IMAGE_SURFACE, wxT("Surf."),
                         wxBitmap(wxImage(Layers_xpm).Rescale(16,16)),
                         wxT("Image surface"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_CIRCLES, wxT("Cir.F."),
                         wxBitmap(wxImage(Circle_xpm).Rescale(16,16)),
                         wxT("Circlefield"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_VOXELS3D, wxT("V3D"),
                         wxBitmap(wxImage(Registry_xpm).Rescale(16,16)),
                         wxT("Voxels 3D"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_GLMIP, wxT("GLMIP"),
                         wxBitmap(wxImage(Transparent_background_xpm).Rescale(16,16)),
                         wxT("OpenGL MIP"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_VOLREN, wxT("Vol.Ren."),
                         wxBitmap(wxImage(Sharpness_xpm).Rescale(16,16)),
                         wxT("Volume rendering"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_SECTIONS3D, wxT("Sect. 3D"),
                         wxBitmap(wxImage(Sections3D_xpm).Rescale(16,16)),
                         wxT("Sections 3D"), wxITEM_CHECK);
  ViewParameters->AddSeparator();
  
  ViewParameters->AddTool(wxID_COLORS, wxT("Col."),
                         wxBitmap(wxImage(Color_palete_xpm).Rescale(16,16)),
                         wxT("Colors"), wxITEM_CHECK);
  ViewParameters->Realize();
  
  
  //View style toolbar
  #if (!WIN32) &&(!__WXMAC__)
    ViewStyle = new wxToolBar(this, wxID_ANY,
                          wxDefaultPosition, wxDefaultSize );
                //          wxAUI_TB_DEFAULT_STYLE  | wxAUI_TB_OVERFLOW);
  #else
    ViewStyle = new wxAuiToolBar(this, wxID_ANY,
                          wxDefaultPosition, wxDefaultSize,
                          wxAUI_TB_DEFAULT_STYLE  | wxAUI_TB_OVERFLOW);
  #endif
  
  ViewStyle->SetToolBitmapSize(wxSize(16,16));
  
  wxArrayString strings;
  strings.Add(wxT("Slice"));
  strings.Add(wxT("MIP"));
  strings.Add(wxT("Anim."));
  wxClientDC dc(this);
  wxCoord w = 0,wmax=0,h;
  for (size_t i=0; i<strings.Count(); i++ ) {
    dc.GetTextExtent(strings[i],&w,&h);
    wmax = ((w>wmax)?w:wmax);
  }

  comboView = new wxComboBox(ViewStyle, wxID_VIEW_TYPE, wxT("Slice"),
                                         wxDefaultPosition,wxSize(wmax+40,-1) , strings, wxCB_READONLY); 
  comboView->SetToolTip(wxT("Type of view: Slice, maximun intensity projection or animation"));

  ViewStyle->AddControl(comboView); //, wxT("Option"));
  ViewStyle->AddSeparator();
  
  xyCheck = new wxCheckBox(ViewStyle, wxID_XY, wxT("XY"),
                                         wxDefaultPosition, wxDefaultSize, wxCHK_2STATE);
  xyCheck->SetValue(true);
  xyCheck->SetToolTip(wxT("Show/Hide XY plane"));
  ViewStyle->AddControl(xyCheck); //, wxT("XY"));
  
  xzCheck = new wxCheckBox(ViewStyle, wxID_XZ, wxT("XZ"),
                                         wxDefaultPosition, wxDefaultSize, wxCHK_2STATE);
  if (this->_image->_tz > 1) {
    xzCheck->SetValue(true);
  }
  else {
    xzCheck->Disable();
  }
  xzCheck->SetToolTip(wxT("Show/Hide XZ plane"));
  ViewStyle->AddControl(xzCheck); //, wxT("XZ"));
  
  zyCheck = new wxCheckBox(ViewStyle, wxID_ZY, wxT("ZY"),
                                         wxDefaultPosition, wxDefaultSize, wxCHK_2STATE);
  if (this->_image->_tz > 1) {
    zyCheck->SetValue(true);
  }
  else {
    zyCheck->Disable();
  }
  zyCheck->SetToolTip(wxT("Show/Hide ZY plane"));
  ViewStyle->AddControl(zyCheck); //, wxT("ZY"));
  ViewStyle->AddSeparator();
  
//  wxButton* many = new wxButton(ViewStyle, wxID_MANYXY, wxT("many XY"));
//  many->SetSize(many->GetEffectiveMinSize());
//  ViewStyle->AddControl(many, wxT("manyXY"));
  ViewStyle->AddTool(wxID_MANYXY, wxT("ManyXY"),
                         wxBitmap(wxImage(New_imagelist_xpm).Rescale(16,16)),
                         wxT("Show XY slices."), wxITEM_CHECK);
  if (!(this->_image->_tz > 1)) {
    ViewStyle->EnableTool(wxID_MANYXY, false);
  }
  ViewStyle->AddSeparator();
  
  strings.Clear();
  strings.Add(wxT("Win Size"));
  strings.Add(wxT("Usr Size"));
  wmax=0;
  for (size_t i=0; i<strings.Count(); i++ ) {
    dc.GetTextExtent(strings[i],&w,&h);
    wmax = ((w>wmax)?w:wmax);
  }

  comboSize = new wxComboBox(ViewStyle, wxID_SIZE_TYPE, wxT("Win Size"),
                                        wxDefaultPosition, wxSize(wmax+40,-1), strings, wxCB_READONLY);
  comboSize->SetToolTip(wxT("Select image sizing mode: window size or user size."));
  ViewStyle->AddControl(comboSize); //, wxT("Size"));
  ViewStyle->AddSeparator();


//  zoomCheck = new wxCheckBox(ViewStyle, wxID_CHECK_ZOOM, wxT("Zoom"),
//                                         wxDefaultPosition, wxDefaultSize, wxCHK_2STATE);
//  ViewStyle->AddControl(zoomCheck, wxT("Zoom"));
  ViewStyle->AddTool(wxID_CHECK_ZOOM, wxT("Zoom"),
                         wxBitmap(wxImage(Selection_xpm).Rescale(16,16)),
                         wxT("Zoom inside a region"), wxITEM_CHECK);
  ViewStyle->AddTool(wxID_UNZOOM, wxT("Unzoom"),
                         wxBitmap(wxImage(Zoom_out_xpm).Rescale(16,16)),
                         wxT("Unzoom"));
  
  //Confirm all changes in toolbars  
  //ViewParameters->Realize();
  ViewStyle->Realize();

  //ViewParameters->SetSize(ViewParameters->GetEffectiveMinSize());
  //ViewStyle->SetSize(ViewStyle->GetEffectiveMinSize());

} // Create_Toolbar()
  

//----------------------------------------------------------------
void DessinImage::RestoreView(wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
  di->Param._type_coupe = lastView;
  CB_redraw(event);

  //Checking chekboxes
  switch (lastView) {
    case TYPE_COUPE_XY:
      xyCheck->SetValue(true); xzCheck->SetValue(false); zyCheck->SetValue(false);
      break;
    case TYPE_COUPE_XZ:
      xyCheck->SetValue(false); xzCheck->SetValue(true); zyCheck->SetValue(false);
      break;
    case TYPE_COUPE_ZY:
      xyCheck->SetValue(false); xzCheck->SetValue(false); zyCheck->SetValue(true);
      break;
    case TYPE_COUPE_XY_XZ:
      xyCheck->SetValue(true); xzCheck->SetValue(true); zyCheck->SetValue(false);
      break;
    case TYPE_COUPE_XY_ZY:
      xyCheck->SetValue(true); xzCheck->SetValue(false); zyCheck->SetValue(true);
      break;
    case TYPE_COUPE_XZ_ZY:
      xyCheck->SetValue(false); xzCheck->SetValue(true); zyCheck->SetValue(true);
      break;
    case TYPE_COUPE_XY_XZ_ZY:
      xyCheck->SetValue(true); xzCheck->SetValue(true); zyCheck->SetValue(true);
      break;
    case TYPE_COUPES:
      xyCheck->SetValue(false); xzCheck->SetValue(false); zyCheck->SetValue(false);
      break;
    default:
      break;
  }

}

  
//----------------------------------------------------------------
void DessinImage::CB_OnPositionClick (wxCommandEvent &event)
{
  ParamPanel* p = _param_position.get();
  ToggleParamPanel(_param_position.get());
  if(_param_book->GetSize().GetWidth() < p->GetSize().GetWidth())
    _param_book->SetSize(p->GetSize().GetWidth(), _param_book->GetSize().GetHeight());
} // CB_OnPositionClick()

  
//----------------------------------------------------------------
void DessinImage::CB_OnIntensityClick (wxCommandEvent &event)
{
  ParamPanel* p = _param_intensity.get();
  ToggleParamPanel(_param_intensity.get());
  if(_param_book->GetSize().GetWidth() < p->GetSize().GetWidth())
    _param_book->SetSize(p->GetSize().GetWidth(), _param_book->GetSize().GetHeight());
} // CB_OnIntensityClick()
  
//----------------------------------------------------------------
void DessinImage::CB_OnVectorsClick (wxCommandEvent &event)
{
  ParamPanel* p = _param_vectors.get();
  ToggleParamPanel(_param_vectors.get());
  if(_param_book->GetSize().GetWidth() < p->GetSize().GetWidth())
    _param_book->SetSize(p->GetSize().GetWidth(), _param_book->GetSize().GetHeight());
} // CB_OnVectorsClick()
  
//----------------------------------------------------------------
void DessinImage::CB_OnIsoContoursClick (wxCommandEvent &event)
{
  ParamPanel* p = _param_isocontour.get();
  ToggleParamPanel(_param_isocontour.get());
  if(_param_book->GetSize().GetWidth() < p->GetSize().GetWidth())
    _param_book->SetSize(p->GetSize().GetWidth(), _param_book->GetSize().GetHeight());
} // CB_OnIsoContoursClick()

  
//----------------------------------------------------------------
void DessinImage::CB_OnImageSurfaceClick (wxCommandEvent &event)
{
  ParamPanel* p = _param_imagesurface.get();
  ToggleParamPanel(_param_imagesurface.get());
  if(_param_book->GetSize().GetWidth() < p->GetSize().GetWidth())
    _param_book->SetSize(p->GetSize().GetWidth(), _param_book->GetSize().GetHeight());
} // CB_OnImageSurfaceClick()
  

//----------------------------------------------------------------
void DessinImage::CB_OnViewTypeClick (wxCommandEvent &event)
{ 
  DessinImage*    di = (DessinImage*) this;
  
  switch (event.GetSelection()) {
    case 0:
      if (di->Param._option_traitement == OPTION_COUPE) {
        return;
      }
      di->Param._option_traitement = OPTION_COUPE;
      CB_option_traitement(event);
      break;
    
    case 1:
      if (_param_mip->IsShown()) {
        return;
      }
      di->Param._option_traitement = OPTION_MIP;
      CB_option_traitement(event);
      break;
    
    case 2:
      if (_param_animation->IsShown()) {
        return;
      }
      di->Param._option_traitement = OPTION_ANIM;
      CB_option_traitement(event);
      break;

    default:
      break;
  }
} // CB_OnViewTypeClick()

  
//----------------------------------------------------------------
void DessinImage::CB_OnSizeTypeClick (wxCommandEvent &event)
{
  DessinImage*    di = (DessinImage*) this;
  
  switch (event.GetSelection()) {
    case 0:
      di->Param._type_taille = TAILLE_FENETRE;
      CB_type_taille(event);
      break;
      
    case 1:
      di->Param._type_taille = TAILLE_FACTEUR;
      CB_type_taille(event);
      break;
      
    default:
      break;
  }
} // CB_OnSizeTypeClick()
  
  
//----------------------------------------------------------------
void DessinImage::CB_OnZoomClick (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
  if (di->Param._fonction_zoom == FUNC_ZOOM_DESACTIVE)
  {
    di->Param._fonction_zoom = FUNC_ZOOM_ACTIVE;
  }
  else
  {
    di->Param._fonction_zoom = FUNC_ZOOM_DESACTIVE;
  }

} // CB_OnZoomClick()
  

//----------------------------------------------------------------
void DessinImage:: CB_OnUnzoomClick (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
  int aux = di->Param._fonction_zoom;
  di->Param._fonction_zoom = FUNC_UNZOOM;
  CB_fonction_zoom(event);
  di->Param._fonction_zoom = aux;
  
} // On_UnzoomClick()
  
  
//----------------------------------------------------------------
void DessinImage::CB_OnCheckXYClick (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
    
  if (xyCheck->IsChecked()) {
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY_ZY;
        CB_redraw(event);
        break;
      
      case TYPE_COUPE_XZ:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ_ZY;
        CB_redraw(event);
        break;

      case TYPE_COUPES:
        di->Param._type_coupe = TYPE_COUPE_XY;
        CB_redraw(event);
        break;

      default:
        break;
    }
  }
  else {
    //Are unchecked all checkboxes??
    if (!xzCheck->IsChecked() && !zyCheck->IsChecked()) {
      wxMessageDialog* dialog = new wxMessageDialog(this,
                                                    wxT("You must check at least one plane checkbox on the toolbar."),
                                                    wxT("Viewer Error"), 
                                                    wxOK | wxSTAY_ON_TOP | wxICON_EXCLAMATION);
      dialog->ShowModal();
      xyCheck->SetValue(true);
      di->Param._type_coupe = TYPE_COUPE_XY;
      CB_redraw(event);
      return;
    }
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_XY_ZY:
        di->Param._type_coupe = TYPE_COUPE_ZY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ:
        di->Param._type_coupe = TYPE_COUPE_XZ;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_XZ_ZY;
        CB_redraw(event);
        break;

      default: 
        break;
    }
  }

}


//----------------------------------------------------------------
void DessinImage::CB_OnCheckXZClick (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
  
  if (xzCheck->IsChecked()) {
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_ZY:
        di->Param._type_coupe = TYPE_COUPE_XZ_ZY;
        CB_redraw(event);
        break;
      
      case TYPE_COUPE_XY:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ_ZY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPES:
        di->Param._type_coupe = TYPE_COUPE_XZ;
        CB_redraw(event);
        break;

      default:
        break;
    }
  }
  else {
    //Are unchecked all checkboxes??
    if (!xyCheck->IsChecked() && !zyCheck->IsChecked()) {
      wxMessageDialog* dialog = new wxMessageDialog(this,
                                                    wxT("You must check at least one plane checkbox on the toolbar."),
                                                    wxT("Viewer Error"), 
                                                    wxOK | wxSTAY_ON_TOP | wxICON_EXCLAMATION);
      dialog->ShowModal();
      xzCheck->SetValue(true);
      di->Param._type_coupe = TYPE_COUPE_XZ;
      CB_redraw(event);
      return;
    }
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_ZY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ:
        di->Param._type_coupe = TYPE_COUPE_XY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY_ZY;
        CB_redraw(event);
        break;

      default: 
        break;
    }
  }
  
}


//----------------------------------------------------------------
void DessinImage::CB_OnCheckZYClick (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;
  
  if (zyCheck->IsChecked()) {
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_XY:
        di->Param._type_coupe = TYPE_COUPE_XY_ZY;
        CB_redraw(event);
        break;
      
      case TYPE_COUPE_XZ:
        di->Param._type_coupe = TYPE_COUPE_XZ_ZY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ_ZY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPES:
        di->Param._type_coupe = TYPE_COUPE_ZY;
        CB_redraw(event);
        break;

      default:
        break;
    }
  }
  else {
    //Are unchecked all checkboxes??
    if (!xyCheck->IsChecked() && !xzCheck->IsChecked()) {
      wxMessageDialog* dialog = new wxMessageDialog(this,
                                                    wxT("You must check at least one plane checkbox on the toolbar."),
                                                    wxT("Viewer Error"), 
                                                    wxOK | wxSTAY_ON_TOP | wxICON_EXCLAMATION);
      dialog->ShowModal();
      zyCheck->SetValue(true);
      di->Param._type_coupe = TYPE_COUPE_ZY;
      CB_redraw(event);
      return;
    }
    switch (di->Param._type_coupe) {
      case TYPE_COUPE_XY_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_XZ;
        CB_redraw(event);
        break;
        
      case TYPE_COUPE_XY_XZ_ZY:
        di->Param._type_coupe = TYPE_COUPE_XY_XZ;
        CB_redraw(event);
        break;

      default: 
        break;
    }
  }
  
}


//----------------------------------------------------------------
void DessinImage::CB_OnManyXYClick  (wxCommandEvent &event)
{
  DessinImage* di = (DessinImage*) this;

  if (_param_mip->IsShown()) {
    ToggleParamPanel(_param_mip.get());
    RestoreView(event);
  }

  if (!(di->_image->_tz > 1)) {
    wxMessageDialog* message = new wxMessageDialog(this, wxT("You are showing a two-dimensional image."),
                                                   wxT("Viewer Error"), wxOK | wxICON_EXCLAMATION);
    message->ShowModal();
    return;
  }
  else {
   if (!_param_mip->IsShown() && !_param_coupesxy->IsShown()) {
      lastView = di->Param._type_coupe;
    }
    if (di->Param._type_coupe != TYPE_COUPES) {
      di->Param._type_coupe = TYPE_COUPES;
      xyCheck->Disable();
      xzCheck->Disable();
      zyCheck->Disable();
      comboView->Disable();
      ToggleParamPanel(_param_coupesxy.get());
      CB_redraw(event);
    }
    else {
      ToggleParamPanel(_param_coupesxy.get());
      xyCheck->Enable(true);
      xzCheck->Enable(true);
      zyCheck->Enable(true);
      comboView->Enable(true);
      RestoreView(event);
    }
  }

}

  
