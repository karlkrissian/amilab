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
// Programme de courbes dans l'espace
// fichier CompareImage.cpp
//
// Karl KRISSIAN
// 
// Sophia Antipolis le 21-01-97
//  

#include "CompareImage.hpp"

#ifndef macro_min
  #define macro_min(n1,n2) ((n1)<(n2)?(n1):(n2))
#endif

#ifndef macro_max
  #define macro_max(n1,n2) ((n1)>(n2)?(n1):(n2))
#endif 

extern unsigned char      GB_debug;

//----------------------------------------------------------------
void CompareImage :: InitMinMax( )
//                           ----------
{

  Si _normalise_intensite Alors
    _image_initiale->MinMax(&_val_min, &_val_max);
  Sinon
    _dessin_image->RecupereMinMax( &_val_min, &_val_max);
  FinSi

  _intensite_float_min = _val_min;
  _intensite_float_max = _val_max;

  _intensite_entier_min = (int) _val_min;
  _intensite_entier_max = (int) _val_max;

} // InitMinMax()



//============================================================================================
// MEMBRES PUBLICS
//============================================================================================

//----------------------------------------------------------------
// default int l=650, int h=400
CompareImage ::  CompareImage( wxWindow* parent,
                         char* ATitle, InrImage::ptr image, 
                          DessinImage* dessin_image, int l, int h)
                   : DessinImage( parent, ATitle, image, dessin_image->_param,
                 l, h, CREATE_TOPLEVEL_SHELL)
{

  Si GB_debug AlorsFait
    fprintf(stderr,"  CompareImage() \n");

  // Les parametres ne sont pas visibles au depart
//  _param_dialog->FermeDialogue( );
//  Param._parametres_visible = false;
//  _Moptions_parametres_visible->MAJ();

  _dessin_image = dessin_image;

  _normalise_intensite = false;
  _depend_position  =
  _depend_intensite = true;



  _premier_affichage   = true;

  Fixe_fenetre_dimensions(l,h,true);

// Reste des problemes: enumerations, ...
//  _palette->SetColorsRec(_fenetre);

// I don't know why, but I have to run de SetColorsRec on the parent
// of the pulldown menu, and only once for each menu level ...
//  _palette->SetColorsRec(XtParent(_Mimages->PullDown()));
//  _palette->SetColorsRec(XtParent(_Moptions_interpolation->PullDown()));

/*
  _palette->SetColorsRec(_Mimages_sauver->PullDown());

  _palette->SetColorsRec(_Moptions->PullDown());
  _palette->SetColorsRec(_Moptions_masque       ->PullDown());
  _palette->SetColorsRec(_Moptions_curseur      ->PullDown());
  _palette->SetColorsRec(_Moptions_parametres   ->PullDown());

  _palette->SetColorsRec(_Mmip->PullDown());
  _palette->SetColorsRec(_Mmip_projection->PullDown());
  _palette->SetColorsRec(_Mmip_stereo->PullDown());

  _palette->SetColorsRec(_Maide->PullDown());
*/
  Si GB_debug AlorsFait
    printf("Fin de CompareImage:: \n");

} // Constructor


//----------------------------------------------------------------
CompareImage :: ~CompareImage()
//                       -----------
{

  // 
  Si GB_debug AlorsFait
    printf("CompareImage Destructor\n");
  this->FermerFenetre();

} // Destructor

// -------------------------------------------------------------------------
//
void CompareImage :: FixeTableCouleurs(unsigned char* tab)
//                   -----------------
{

    _palette->TypePaletteTC( tab);
    Param._MAJ._intensite = true;
    Paint();

} // FixeTableCouleurs()


// -------------------------------------------------------------------------
//
void CompareImage :: FixeDecalStereo( int angle)
//                               ---------------
{

  Param._MIP._stereo       = true;
  Param._MIP._decal_stereo = angle;

  Param._MIP._MAJ = Param._MAJ._planXY = true;

} // FixeTableCouleurs()


//----------------------------------------------------------------
void CompareImage :: RecupereParametres()
//                             ------------------
{

  
    float   pos_min=0, pos_max=0;

  Si _depend_position Alors
    _dessin_image->RecupereTypeCoupe( &Param._type_coupe);
    _dessin_image->RecuperePosition ( Param);
    _dessin_image->RecupereLimites  ( Param);
    Param.CheckPosition( _image );
//    _dessin_image->RecupereVoxelSize( Param);
  FinSi

   if (_transf_matrix!=NULL) {
    // first apply the transformation matrix
    float x1,y1,z1;

    x1 = Param._pos._x*(*_transf_matrix)[0][0]+
         Param._pos._y*(*_transf_matrix)[0][1]+
         Param._pos._z*(*_transf_matrix)[0][2]+
                       (*_transf_matrix)[0][3];

    y1 = Param._pos._x*(*_transf_matrix)[1][0]+
         Param._pos._y*(*_transf_matrix)[1][1]+
         Param._pos._z*(*_transf_matrix)[1][2]+
                       (*_transf_matrix)[1][3];

    z1 = Param._pos._x*(*_transf_matrix)[2][0]+
         Param._pos._y*(*_transf_matrix)[2][1]+
         Param._pos._z*(*_transf_matrix)[2][2]+
                       (*_transf_matrix)[2][3];
  
    Param._pos._x = (int) (x1+0.5);
    Param._pos._y = (int) (y1+0.5);
    Param._pos._z = (int) (z1+0.5);
    Param.CheckPosition( _image );

  }
 

  _dessin_image->RecupereOptionTraitement( &Param._option_traitement);

  //------ Param�res de l'option  MIP
  Si Param._option_traitement == OPTION_MIP Alors

    _dessin_image->RecupereMIP( Param);
    Si Param._MIP._MAJ Ou _premier_affichage Alors
      _MIP->FixeDepthCue( true, Param._MIP._depth_cue);
      _MIP->FixeVoxelSize( Param._dim._voxel_size_x, 
               Param._dim._voxel_size_y, 
               Param._dim._voxel_size_z);
      _MIP->FixeRotation( Param._MIP._rot_X, 
              Param._MIP._rot_Y, 
              Param._MIP._rot_Z);
      _MIP->FixeLimites( Param._Zoom._xmin, Param._Zoom._xmax, 
             Param._Zoom._ymin, Param._Zoom._ymax, 
             Param._Zoom._zmin, Param._Zoom._zmax);
      Si Param._MIP._stereo Alors
        _MIP->RotationY( Param._MIP._decal_stereo);
      FinSi
      _image_MIP = InrImage::ptr(_MIP->CreeMIP( ));
    FinSi
    _image = _image_MIP;
  Sinon
    _image = _image_initiale;
  FinSi

  //------- Si normalisation de l'intensit�  
  Si _depend_intensite Alors
    Si _normalise_intensite Alors
      _dessin_image->RecupereIntervalleIntensiteNormalise( &pos_min,  &pos_max);
      _intensite_float_min = _val_min + pos_min*(_val_max - _val_min);
      _intensite_float_max = _val_min + pos_max*(_val_max - _val_min);
      _intensite_entier_min = (int) (_val_min + pos_min*(_val_max - _val_min));
      _intensite_entier_max = (int) (_val_min + pos_max*(_val_max - _val_min));
    Sinon
      _dessin_image->RecupereIntervalleIntensite(
               &_intensite_float_min,  &_intensite_float_max,
               &_intensite_entier_min, &_intensite_entier_max);
    FinSi

    _dessin_image->RecupereTypeCourbe( &Param._I._type_courbe);
    _dessin_image->RecupereTypeCurseur( &Param._curseur._type);
  FinSi

  //-------- Mises �jour et premier affichage
  Si _premier_affichage Alors
    _premier_affichage = false;
    Param._MAJ._intensite =  true;
    Param._MAJ.MAJCoupes();
  Sinon
    _dessin_image->RecupereMAJ( Param );
  FinSi

} // RecupereParametres()


//----------------------------------------------------------------
void CompareImage :: Paint( unsigned char esclave )
//                             -----
{
    int i;

  Si GB_debug AlorsFait
    fprintf(stderr,"CompareImage::Paint() \t Debut\n");


  Si VerifieMinMax() Alors

    ComputeBasicSizes();
    InitVoxelSize();

    Si Param._MAJ._intensite Alors
      InitCouleurs();
      Param._MAJ.MAJCoupes();
    FinSi

    InitPositionImages();
 
    DrawingAreaClear();

    Si esclave Alors
      _dessin_image->RecupereAnimation( &_memorise_coupes_XY);
      MemoriseCoupesXY( _memorise_coupes_XY);
    FinSi

    Si Param._option_traitement == OPTION_MIP Alors

      Si Param._MAJ._planXY AlorsFait DessinePlanZ();
      Si Non(_MIP_stereo_lunettes) Alors
        AfficheImage( IMAGE_XY); 
      FinSi

    Sinon
      Si (Param._type_coupe+1) & (TYPE_COUPE_XY+1) Alors
          Si Param._MAJ._planXY AlorsFait DessinePlanZ();
          Si Param._MAJ._planXY Ou esclave Alors
        AfficheImage( IMAGE_XY); 
            DessineAxesXY();
          FinSi
      FinSi

      Si (Param._type_coupe+1) & (TYPE_COUPE_XZ+1) Alors
          Si Param._MAJ._planXZ AlorsFait DessinePlanY();
          Si Param._MAJ._planXZ Ou esclave Alors
            AfficheImage( IMAGE_XZ); 
            DessineAxesXZ();
          FinSi
      FinSi

      Si (Param._type_coupe+1) & (TYPE_COUPE_ZY+1) Alors
          Si Param._MAJ._planZY AlorsFait DessinePlanX();
          Si Param._MAJ._planZY Ou esclave Alors
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

    printf("Warning, CompareImage::Paint() \t  intensit�min = intensit�max\n");

  FinSi

  DrawColorBar();

  Si _circles_ON AlorsFait DessineChampCercles();

  Si _all_contours Alors
    DrawAllContours();
  Sinon
    // better use iterator here
    Pour(i,0,(int)_isocontours.size()-1)
      if (_isocontours[i].visible) 
        // will use the isocontour parameter for 
        // style and thickness
        DrawContour(i); 
    FinPour
  FinSi

  DrawingAreaDisplay();
  
  Param._MIP._MAJ = false;
  Param._MAJ.MAJCoupes( false);
  Param._MAJ._intensite = false;
//  _vecteur_ON    = false;

  Si Param._curseur._visible Alors
    DessineCurseurs( Param._pos._x, Param._pos._y, Param._pos._z);
    Param._curseur._ON    = true;
  Sinon
    Param._curseur._ON    = false;
  FinSi

//  _MAJ_positions = false; // pour l'instant, je recalcule systematiquement les positions


  Si GB_debug AlorsFait
    fprintf(stderr,"CompareImage::Paint() \t Fin\n");

} // Paint()


//----------------------------------------------------------------
void CompareImage :: DessineAnimation( int planZ)
//                   ----------------
{
  Param._pos._z = planZ;
  DessinePlanZ();
  AfficheImage( IMAGE_XY); 
  DrawingAreaDisplay();
} // DessineAnimation()


//----------------------------------------------------------------
void CompareImage :: MAJ_label( int im_x, int im_y, int im_z, int trouve)
//                            -----------
{
/* will disappear !
  

  Si GB_debug AlorsFait
    fprintf(stderr,"CompareImage::MAJ_label()\n");

  Si (trouve != -1) Et (_image->CoordOK(im_x,im_y,im_z)) Alors
    sprintf(_label_texte,"(%4d,%4d,%4d)", im_x, im_y, im_z);
    ValeurBuffer(im_x, im_y, im_z, _label_texte);
  Sinon
      sprintf(_label_texte,"999.99 (X=9999,Y=9999,Z=9999)");
  FinSi

  SetStatusText(_label_texte);

  Si GB_debug AlorsFait
    fprintf(stderr,"CompareImage::MAJ_label() Fin\n");
*/
} // MAJ_label()


//----------------------------------------------------------------
void CompareImage :: ReDimensionne( )
//                            -------------
{

  Param._MAJ._planXY =Param._MAJ._planZY = Param._MAJ._planXZ = Param._MAJ._coupes = true;
  Paint();

} // ReDimensionne()


//----------------------------------------------------------------
void CompareImage :: FermerFenetre()
//                             -------------
{

  Si GB_debug AlorsFait
    fprintf(stderr,"CompareImage::FermerFenetre() \n");

  Si Non(Param._MIP._stereo) AlorsFait
    (_dessin_image)->LibereCompareImage(_numero_fenetre,0);

} // FermerFenetre()

//----------------------------------------------------------------
void CompareImage :: CB_Normalise( void* cd )
//                             ------------
{

   
    CompareImage*    ci = (CompareImage*) cd;


  ci->InitMinMax();

  // Pour forcer le re-affichage
  ci->Param._MAJ._intensite = true;
  ci->_premier_affichage = true;
  ci->Paint();

} // CB_Normalise()


