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
/***************************************************************************
 * $Author: karl $
 * $Revision: 1.6 $
 * $Log: DessinImageBase.cpp,v $
 * Revision 1.6  2006/03/09 16:49:07  karl
 * evolving for Fluid tutorial + fixed OpenGL pb with GLw
 *
 * Revision 1.5  2005/11/16 14:03:09  karl
 * added LGPL license
 *
 * Revision 1.4  2004/08/18 21:33:12  karl
 * warning and memory pbs
 *
 * Revision 1.3  2004/06/24 04:46:19  karl
 * warnings and trying to unify texture and object matrices
 *
 * Revision 1.2  2004/06/16 02:00:02  karl
 * Starting Volume Rendering
 *
 * Revision 1.1.1.1  2004/02/02 20:47:08  karl
 * source code in C++
 *
 * Revision 1.1.1.1  2003/08/14 07:16:05  karl
 * Source code
 *
 * Revision 1.6  2001/03/02 11:49:32  karl
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
 * Revision 1.2  2000/09/19 12:19:08  karl
 * *** empty log message ***
 *
 * Revision 1.1.1.1  2000/04/07 16:09:31  karl
 * Sources code
 *
 *
 ***************************************************************************/
// Programme de courbes dans l'espace
// fichier DessinImageBase.cpp
//
// Karl KRISSIAN
//
// Sophia Antipolis le 20-10-97
//


#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
//#ifdef wxHAVE_RAW_BITMAP
#include <wx/rawbmp.h>
//#endif

#include "DessinImageBase.hpp"
#include "DessinImageMenu.h"

#include "amilab_messages.h"

//#if  defined(_linux_) || defined(_solaris)
#if  defined(_solaris)
#include <libgen.h>
#else
#define basename(s) s
#endif

extern unsigned char      GB_debug;

// Values for choosing the coordinates printing steps
#define NUM_ACCEP_VAL 7
static  int acceptable_values[7] = {2,5,10,20,50,100,200};
static  int corresp_values[7]    = {1,1, 2, 5,10,20, 50};



//----------------------------------------------------------------
void DessinImageBase::FixeImageCourante( int id_image )
//                    -----------------
{
  CLASS_MESSAGE("begin")

  if (_tab_slices[id_image].image.use_count()) {
    if (GB_debug)
      CLASS_MESSAGE(boost::format( "Selecting slice number %1%") % id_image);
      CLASS_MESSAGE(boost::format( "use_count %1%") % _current_slice.use_count());
      CLASS_MESSAGE(boost::format( "pointer =  %1%") % _current_slice.get());
      // we should not use = here to increase the counter to the pointer
      _current_slice = wxImage_ptr(_tab_slices[id_image].image);
      CLASS_MESSAGE(boost::format( "_tab_slices[id_image].image.get() =  %1%") % _tab_slices[id_image].image.get());
      CLASS_MESSAGE(boost::format( "pointer =  %1%") % _current_slice.get());
  } else {
      cerr << "DessinImageBase::FixeImageCourante( " << id_image
          << "\t image not allocated " << endl;
  }

  CLASS_MESSAGE("end")
} // FixeImageCourante()


//----------------------------------------------------------------
void DessinImageBase :: CreeImage( int id_image, unsigned int largeur, unsigned int hauteur )
//                                 ---------
{
  CLASS_MESSAGE(boost::format(" id_image %1% dim %2% x %3%") 
                      % id_image % (int)largeur % (int) hauteur);

  // if the image with correct dimensions exists, keep it
  if (_tab_slices[id_image].image.use_count()) {
    wxImage_ptr im = _tab_slices[id_image].image;
    if ((im->GetWidth()  == (int) largeur) &&
        (im->GetHeight() == (int) hauteur))
      return;
  }

  CLASS_MESSAGE("allocation");

  // try to avoid the allocation by creating wxImage based on preallocated data of the size of the window ???
  wxImage_ptr newim(new wxImage( (int)largeur,
                              (int)hauteur,
                              bool(false))
                );

  CLASS_MESSAGE(boost::format("swapping use_count = %1%")%_tab_slices[id_image].image.use_count());
  CLASS_MESSAGE(boost::format("newim get = %1%")%newim.get());

  _tab_slices[id_image].image  = newim;
     
/*
  _tab_slices[id_image].context = wxMemoryDC_ptr(new wxMemoryDC);
  _tab_slices[id_image].context->SelectObject(
        *_tab_slices[id_image].bitmap);
*/
  CLASS_MESSAGE("end");

} // CreeImage()


//----------------------------------------------------------------
inline void DessinImageBase::FastImageRectangle(
//                            ------------------
                          rgb_color* image_data,
                          const int& width,
                          const int& x_min, const int& y_min,
                          const int& x_max, const int& y_max,
                          const ClasseCouleur& intensite)
{
  // no more motif version ...

  #ifdef _SAFETY_CHECK_
  if (_current_slice.use_count()) {
    if (GB_debug)
      cerr  << "drawing rectangle at "
            << format("(%d,%d) size (%d x %d) ")
                % x_min % y_min % (x_max-x_min) % (y_max-y_min)
            << format(" color %d %d %d ")
                % (int) intensite.Red()
                % (int) intensite.Green()
                % (int) intensite.Blue()
            << endl;
  #endif

/*
    _current_brush->SetColour(intensite.GetColour());
    _current_slice->SetBrush((*_current_brush));
    _current_slice->DrawRectangle(x_min,y_min,x_max-x_min,y_max-y_min);
*/
    // TODO: use wxImage ...
    register int x, y;

    rgb_color color = intensite.GetCompactColor();

    register rgb_color* data1 = image_data + y_min*width + x_min;
    register rgb_color* data;
    for ( y = y_min; y < y_max; y++, data1+=width)
    {
        data = data1;
        for (x = x_min; x < x_max; x++,data++)
            *data = color;
    }

  #ifdef _SAFETY_CHECK_
  } else {
    cerr << "FastImageRectangle() no drawing context!" << endl;
  }
  #endif


} // FastImageRectangle()


//----------------------------------------------------------------
inline void DessinImageBase::FastImagePoint(
//                            ------------------
                          rgb_color* image_data,
                          const int& width,
                          const int& x, const int& y,
                          const ClasseCouleur& intensite)
{
  #ifdef _SAFETY_CHECK_
  if (_current_slice.use_count()) {
    if (GB_debug)
      cerr  << "drawing rectangle at "
            << format("(%d,%d) size (%d x %d) ")
                % x_min % y_min % (x_max-x_min) % (y_max-y_min)
            << format(" color %d %d %d ")
                % (int) intensite.Red()
                % (int) intensite.Green()
                % (int) intensite.Blue()
            << endl;
  #endif

    // TODO: use wxImage ?
    *(image_data + y*width + x) = intensite.GetCompactColor();

  #ifdef _SAFETY_CHECK_
  } else {
    cerr << "FastImageRectangle() no drawing context!" << endl;
  }
  #endif


} // FastImageRectangle()


/*
//----------------------------------------------------------------
void DessinImageBase :: EffaceImage( int id_image)
//                                 -----------
{


} // EffaceImage()

*/
//----------------------------------------------------------------
void DessinImageBase :: InitTabImagesXY( )
//                                 ---------------
{
#if defined(__WXMOTIF__)
    int n;

  _nb_images_XY = _image->_tz;

  _tab_ximage_XY_data = new char*  [_nb_images_XY];
  _tab_ximage_XY      = new XImage*[_nb_images_XY];
  _image_XY_a_jour    = new unsigned char[_nb_images_XY];

  Pour( n, 0, _nb_images_XY - 1)
    _tab_ximage_XY_data[n] = NULL;
    _tab_ximage_XY[n] = NULL;
    _image_XY_a_jour[n] = false;
  FinPour // n

  _largeur_XY = 0;
  _hauteur_XY = 0;
#endif

} // InitTabImagesXY()


/*
//----------------------------------------------------------------
void DessinImageBase :: LibereTabImagesXY( )
//                                 -----------------
{
} // LibereTabImagesXY()

*/
//----------------------------------------------------------------
void DessinImageBase :: AlloueImagesXY( unsigned int largeur, unsigned int hauteur)
//                                 --------------
{
#if defined(__WXMOTIF__)
    int n;

  Si (largeur != _largeur_XY) Ou (hauteur != _hauteur_XY) Alors

  //    printf("Allocation Images XY \n");

    _ximage_octets = 4;

//    EffaceImagesXY();

    Pour( n, 0, _nb_images_XY - 1)

      _tab_ximage_XY_data[n] = (char*) malloc( largeur*hauteur* _ximage_octets);

      _tab_ximage_XY[n] = XCreateImage( display,
          _palette->_visual,
          _palette->_depth,
          ZPixmap, 0, _tab_ximage_XY_data[n],
          largeur, hauteur,
          8*_ximage_octets, 0 );

      Si (_tab_ximage_XY_data[n] == NULL) Ou (_tab_ximage_XY[n] == NULL) Alors
        printf("DessinImageBase::AlloueImagesXY() \t erreur d'allocation de l'image ... \n");
      FinSi

    FinPour // n

    _largeur_XY = largeur;
    _hauteur_XY = hauteur;

  FinSi
#endif
} // AlloueImagesXY()


//----------------------------------------------------------------
void DessinImageBase :: MAJ_ImagesXY( )
//                                 ------------
{


    int n;

  Pour( n, 0, _nb_images_XY - 1)
    _image_XY_a_jour[n] = false;
  FinPour // n


} // MAJ_ImagesXY()


//----------------------------------------------------------------
/*
void DessinImageBase :: EffaceImagesXY( )
//                                 --------------
{


} // EffaceImagesXY()
*/

/*
//----------------------------------------------------------------
void DessinImageBase :: AfficheImage( int pos_x, int pos_y)
//                                 ------------
{
#if defined(__WXX11__)
  (pos_x,pos_y,_current_slice);
#endif

 PlaceImage( pos_x, pos_y, _ximage);

} // AfficheImage()
*/

//----------------------------------------------------------------
void DessinImageBase :: AfficheImage( int id_image)
//                      ------------
{
  CLASS_MESSAGE("begin")
  if (!_tab_slices[id_image].image.use_count()) {
    CLASS_ERROR(boost::format(" id_image=%1% not valid...") % id_image);
    return;
  }

  PutSlice( _tab_ximage_pos_x[id_image],
            _tab_ximage_pos_y[id_image],
            _tab_slices[id_image].image);

  CLASS_MESSAGE("end")
} // AfficheImage()


//----------------------------------------------------------------
void DessinImageBase::UpdateStatusIntensity( int x, int y, int z)
//                    ---------------------
{
  if (!_image->CoordOK(x,y,z)) {
    cerr << format("%1%::UpdateStatusIntensity( %2%, %3%, %4%)") % get_name() % x % y % z;
    cerr << format("\t position out of image definition \n");
    return;
  }

  string intensity_string;

  if ((_image->_format == WT_RGB)||
      (_image->_format == WT_RGBA)) {
    intensity_string = str(format("%1% %2% %3%")
           % (int)(*_image)(x,y,z,0)
           % (int)(*_image)(x,y,z,1)
           % (int)(*_image)(x,y,z,2));
  } else {
    float valeur = (*_image)(x,y,z);
    switch ( _image->_format ){
      case WT_DOUBLE:
        intensity_string = str(format("%1%") % (FORMAT_DOUBLE) valeur);
      break;
      case WT_FLOAT:
        intensity_string = str(format("%1%") % (FORMAT_FLOAT) valeur);
      break;

      case WT_UNSIGNED_CHAR:
      case WT_UNSIGNED_SHORT:
      case WT_SIGNED_SHORT:
      case WT_SIGNED_INT:
      case WT_UNSIGNED_INT:
        intensity_string = str(format("%1%") % (int) valeur);
      break;
      default: ;
    } // end switch
  }

  this->SetStatusText(GetwxStr(intensity_string),_intensity_statusid);

} // UpdateStatusIntensity()


//-------------------------------------------------------------------------
void DessinImageBase::UpdateStatusPosition(int x, int y, int z)
//                    ---------------------
// writes the current voxel to the corresponding fields
// of the status bar (voxel and spatial positions)
{
  std::string voxpos, spatialpos;
  int im_x,im_y,im_z;

  if (Param._option_traitement == OPTION_MIP) {
    _MIP->PosPoint( x,y,im_x,im_y,im_z);
  } else {
    im_x = x;
    im_y = y;
    im_z = z;
  }

  // TODO: if is OK for MIPs to check dimension of _image ?
  if (this->_image->DimZ()>1) {
    voxpos     = str(boost::format("(%4d, %4d, %4d)") % im_x % im_y % im_z);
    spatialpos = str(boost::format("(%3.2f, %3.2f, %3.2f)")
                        % _image->SpacePosX(im_x)
                        % _image->SpacePosY(im_y)
                        % _image->SpacePosZ(im_z));
  }
  else {
    voxpos     = str(boost::format("(%4d, %4d)") % im_x % im_y );
    spatialpos = str(boost::format("(%3.2f, %3.2f)")
                        % _image->SpacePosX(im_x)
                        % _image->SpacePosY(im_y)
                    );
  }

  this->SetStatusText(GetwxStr(voxpos),    _voxelpos_statusid);
  this->SetStatusText(GetwxStr(spatialpos),_spatialpos_statusid);

} // UpdateStatusPosition()

//----------------------------------------------------------------
// default int pos = 0
void DessinImageBase :: InitBuffer( int pos)
//                                 ---------
{
  _image->InitBuffer(pos);
  InitLookUpTable();
} // InitBuffer()


//----------------------------------------------------------------
// default int pos = 0
void DessinImageBase::InitLookUpTable()
//                    ---------------
{
  switch (  _image->_format ){

    case WT_DOUBLE:
    case WT_FLOAT:
      _rapport_intensite = 255.0 / ( _intensite_float_max - _intensite_float_min );
    break;

    default:
      _rapport_intensite = 255.0 / ( _intensite_entier_max - _intensite_entier_min );
    break;

  } // end switch
}


//----------------------------------------------------------------
inline void DessinImageBase :: BufferPos( int x, int y, int z)
//                                         ---------
{

  _image->BufferPos(x,y,z);

} // BufferPos()


//----------------------------------------------------------------
void DessinImageBase::InitCouleurs( )
//                    ------------
{

  if (GB_debug) cerr << "DessinImageBase::InitCouleurs() begin " << endl;
    int i;

  for(  i = 0 ;  i<=255 ;  i++ Faire

    switch ( _palette->_type_palette ){

      case PALETTE_TC:
        _tab_intensite_couleur[i] = _palette->TC( i);
      break;

      case PALETTE_RGB:
        _tab_intensite_couleur[i] = ClasseCouleur(
          (unsigned char)(_couleur_fond.Red()  +1.0*i/255.0*(_couleur_objet.Red()  -_couleur_fond.Red())  ),
          (unsigned char)(_couleur_fond.Green()+1.0*i/255.0*(_couleur_objet.Green()-_couleur_fond.Green())),
          (unsigned char)(_couleur_fond.Blue() +1.0*i/255.0*(_couleur_objet.Blue() -_couleur_fond.Blue()) ));

      break;

    } // end switch
    if (GB_debug)
      cerr << " position " << i
            << " color " << (int) _tab_intensite_couleur[i].Red()
            << " , " << (int)_tab_intensite_couleur[i].Green()
            << " , " << (int)_tab_intensite_couleur[i].Blue()
            << ": " << (int) _tab_intensite_couleur[i].GetPixel()
            << endl;

  } // end for // i

  switch ( Param._I._type_courbe ){
    case TYPE_COURBE_PENTE:  _couleur_inf = 0; _couleur_sup = 255;  break;

    case TYPE_COURBE_PLATEAU:
    case TYPE_COURBE_PENTE2: _couleur_inf = 0; _couleur_sup = 0;    break;
  } // end switch // Param._I._type_courbe

  if (GB_debug) cerr << "DessinImageBase::InitCouleurs() end " << endl;
} // InitCouleurs()


//-----------------------------------------------------------------------
unsigned char DessinImageBase :: VerifieMinMax()
//                                    -------------
{

  switch (  _image->_format ){

    case WT_DOUBLE:
    case WT_FLOAT:
      Si fabs(_intensite_float_min - _intensite_float_max) < 1E-6 AlorsRetourne false;
    break;

    case WT_UNSIGNED_CHAR:
    case WT_UNSIGNED_SHORT:
    case WT_SIGNED_SHORT:
    case WT_SIGNED_INT:
      Si _intensite_entier_min == _intensite_entier_max  AlorsRetourne false;
    break;

    default: ;

  } // end switch

  return true;

} // VerifieMinMax()


//----------------------------------------------------------------
void DessinImageBase::CursorToImage(  const int cursor_x, 
                                      const int cursor_y, 
                                      int& x, int& y, int& z, 
                                      int& slice)
{

    int     pos_x, pos_y;

  slice = -1;
  // On teste si la souris est dans la coupe XY
  if ((Param._type_coupe+1) & (TYPE_COUPE_XY+1)) {

    pos_x = cursor_x - _tab_ximage_pos_x[IMAGE_XY];
    pos_y = cursor_y - _tab_ximage_pos_y[IMAGE_XY];

    if ((pos_x >= 0 )&&
        (pos_x <  GetImageWidth(IMAGE_XY)) &&
        (pos_y >= 0 ) &&
        (pos_y <  GetImageHeight(IMAGE_XY)))
    {

      x = (int) (pos_x/_size_x) + Param._Zoom._xmin;
      y = (int) (pos_y/_size_y) + Param._Zoom._ymin;
      z = Param._pos._z;
      slice = IMAGE_XY;
    } // endif
  } // endif 

  // On teste si la souris est dans la coupe XZ
  if ((slice == -1) && ((Param._type_coupe+1) & (TYPE_COUPE_XZ+1)))
  {
    pos_x = _souris_x - _tab_ximage_pos_x[IMAGE_XZ];
    pos_y = _souris_y - _tab_ximage_pos_y[IMAGE_XZ];

    if (  (pos_x >= 0) &&
          (pos_x <  GetImageWidth(IMAGE_XZ)) &&
          (pos_y >= 0 ) &&
          (pos_y <  GetImageHeight(IMAGE_XZ) ) ) 
    {

      x = (int) (pos_x/_size_x) + Param._Zoom._xmin;
      y = Param._pos._y;
      z = (int) (pos_y/_size_z) + Param._Zoom._zmin;
      slice = IMAGE_XZ;
    } // endif
  } // endif


  // On teste si la souris est dans la coupe ZY
  Si (slice == -1) Et ((Param._type_coupe+1) & (TYPE_COUPE_ZY+1)) Alors
    pos_x = _souris_x - _tab_ximage_pos_x[IMAGE_ZY];
    pos_y = _souris_y - _tab_ximage_pos_y[IMAGE_ZY];

    Si pos_x >= 0                         Et
       pos_x <  GetImageWidth(IMAGE_ZY)   Et
       pos_y >= 0                         Et
       pos_y <  GetImageHeight(IMAGE_ZY)  Alors

      x = Param._pos._x;
      y = (int) (pos_y/_size_y) + Param._Zoom._ymin;
      z = (int) (pos_x/_size_z) + Param._Zoom._zmin;
      slice = IMAGE_ZY;
    FinSi
  FinSi

} // CursorToImage()


//----------------------------------------------------------------
void DessinImageBase::LigneHorizontale( wxDC* dc,
//                    ----------------
                                          int xmin, int xmax,
                                          int xcentre, int y)
// Dessine deux lignes d'ordonn� y entre xmin et xcentre - delta
//                               et entre xcentre + delta et xmax
{
    int marge = 5;

  Si xcentre - marge > xmin Alors
    dc->DrawLine( xmin,    y, xcentre - marge, y);
  Sinon
    dc->DrawLine( xmin,    y, xcentre, y);
  FinSi

  Si xcentre + marge < xmax Alors
    dc->DrawLine( xcentre+marge, y, xmax,    y);
  Sinon
    dc->DrawLine( xcentre, y, xmax,    y);
  FinSi

} // LigneHorizontale()


//----------------------------------------------------------------
void  DessinImageBase::LigneVerticale(  wxDC* dc,
//                     --------------
                                        int ymin, int ymax,
                                        int ycentre, int x)
// Dessine deux lignes d'abscisse y  entre ymin et ycentre - delta
//                                et entre ycentre + delta et ymax
{
    int marge = 5;

  Si ycentre - marge > ymin Alors
    dc->DrawLine( x, ymin, x, ycentre - marge);
  Sinon
    dc->DrawLine( x, ymin, x, ycentre);
  FinSi

  Si ycentre + marge < ymax Alors
    dc->DrawLine( x, ycentre+marge, x, ymax);
  Sinon
    dc->DrawLine( x, ycentre,       x, ymax);
  FinSi

} // LigneVerticale()


//============================================================================================
// MEMBRES PUBLICS
//============================================================================================

//----------------------------------------------------------------
// default int type=CREATE_WINDOW
//
DessinImageBase:: DessinImageBase(
//                            ---------------
                wxWindow* parent,
                const std::string& ATitle,
                int l, int h, int type):
        FenetreDessin( parent, ATitle, l, h, type ),
        _isocontours(3)
{
    char*  method = "DessinImageBase";

  if (GB_debug) printf("FenetreDessin::DessinImageBase title = %s \n",ATitle.c_str());

  Si GB_debug AlorsFait printf("DessinImageBase::DessinImageBase 2\n");


  _nom_image_masque = "";
  _image_masque     = NULL;
  _dessine_masque   = false;
//  printf("DessinImageBase::Constructor\t _dessine_masque false\n");
  _couleur_masque.Set( 0,0,0);



  _MIP              = NULL;
  _MIP_rapide       = false;
  //  _image_MIP = _MIP->CreeMIP( 0, 0, 0);
  _CREST_charge  = false;
  _CREST_dessine = true;


  _tab_intensite_couleur.resize(256);

  _tab_ximage_pos_x = new int [NB_MAX_IMAGES];
  _tab_ximage_pos_y = new int [NB_MAX_IMAGES];

  _tab_slices.resize(NB_MAX_IMAGES);

  // initialisation du tableau des coupes XY
  // impossible d'initialiser sans connaitre la taille en z de l'image
  //  InitTabImagesXY();

//  _ximage = NULL;

  _interpole_image       = false;
  _interpole_subdivision = INTERP_SUB_MAX;

  //#ifdef __APPLE__
  _largeur_lignes = 0;
  //#else
  //  _largeur_lignes = 1;
  //#endif

  _line_style     = wxSOLID;

  _memorise_coupes_XY = false;

  _transf_matrix = NULL;

  _cap_style  = 0; //CapNotLast; //, CapButt, CapRound, or CapProjecting
  _join_style = 0; // JoinMiter; // JoinRound, or JoinBevel

  _compare_normalize_intensity = false;
  _compare_depend_position     = true;
  _compare_depend_intensity    = false;

#if defined(__WXMOTIF__)
  _new_font = NULL;
#endif

  _MIP_parametres_visibles = 0;

  Si GB_debug AlorsFait printf("Fin DessinImageBase::%s\n",method);

} // Constructor


//----------------------------------------------------------------
DessinImageBase :: ~DessinImageBase()
//                           -----------
{

  Si GB_debug AlorsFait fprintf(stderr,
        "DessinImageBase %s destructeur \n",
        (char*) _name);

// Source of bug ?

//  delete _message_erreur;

  Si _image_masque     != NULL Alors
    delete _image_masque;
    _image_masque = NULL;
  FinSi


  delete _MIP;

  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1 \n");

 // LibereTabImagesXY();
/*
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.1 \n");
//  EffaceImage( IMAGE_XY);
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.2 \n");
  EffaceImage( IMAGE_XZ);
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.3 \n");
  EffaceImage( IMAGE_ZY);
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.4 \n");
  EffaceImage( IMAGE_MASQUE_XY);
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.5 \n");
  EffaceImage( IMAGE_COUPES);
*/
  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  1.6 \n");

  delete [] _tab_ximage_pos_x;
  delete [] _tab_ximage_pos_y;


  Si GB_debug AlorsFait fprintf(stderr,"DessinImageBase destructeur  2 \n");



  Si GB_debug AlorsFait fprintf(stderr,
        "DessinImageBase %s destructeur Fin \n",
        (char*) _name);

} // Destructor


//----------------------------------------------------
//
void DessinImageBase :: CreateWxMenu()
{

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Image \n");

    // Image Menu
    menuImage = new wxMenu;
    menuImage->Append( ID_MenuImage_Display,   GetwxStr("&Display")         );
    menuImage->Append( ID_MenuImage_Reload,    GetwxStr("&Reload")          );
    menuImage->Append( ID_MenuImage_Compare,   GetwxStr("&Compare")         );
    menuImage->Append( ID_MenuImage_VoxelSize, GetwxStr("&Voxel Size")      );

    menuImage->AppendSeparator();
    wxMenu* save_submenu = new wxMenu;
    save_submenu->Append(ID_MenuImage_Save_param, GetwxStr("Save Parameters"));
//    save_submenu->Append(ID_MenuImage_Save_image, GetwxStr("Save Image"));
    menuImage->Append( ID_MenuImage_Save,      GetwxStr("&Save"),save_submenu  );

    menuImage->AppendSeparator();
    menuImage->Append( ID_MenuImage_info, GetwxStr("Image &Info" )     );

    menuImage->AppendSeparator();
    menuImage->Append( ID_MenuImage_close, GetwxStr("&Close" )     );

    menuBar = new wxMenuBar;
  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() MenuBar \n");
  SetMenuBar( menuBar );

    menuBar->Append( menuImage, GetwxStr("&Image") );
    //menuBar->SetOwnBackgroundColour("GREEN");

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Options \n");


    // Option Menu
    menuOptions = new wxMenu;

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Option \n");

    _wxm_mode = new wxMenuEnum( menuOptions,
                                &Param._option_traitement,
                                "&Option");
    _wxm_mode->AddChoice( ID_MenuOptions_option_slice,
                          GetwxStr("&Slice"),
                          GetwxStr("Slice View"));
    _wxm_mode->AddChoice( ID_MenuOptions_option_mip,
                          GetwxStr("&MIP"),
                          GetwxStr("Maximum Intensity Projection View"));
    _wxm_mode->AddChoice( ID_MenuOptions_option_anim,
                          GetwxStr("&Animation"),
                          GetwxStr("Temporal Animation in the 3rd dimension"));
    _wxm_mode->SetSelection(ID_MenuOptions_option_slice);

    menuOptions->AppendSeparator();

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Slice \n");

    _wxm_type_coupe = new wxMenuEnum(menuOptions,&Param._type_coupe, "&Slice");
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXY,
                                GetwxStr("XY"),
                                GetwxStr("XY           Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXZ,
                                GetwxStr("XZ"),
                                GetwxStr("XZ           Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXY_XZ,
                                GetwxStr("XY+XZ"),
                                GetwxStr("XY & XZ      Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceZY,
                                GetwxStr("ZY"),
                                GetwxStr("ZY           Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXY_ZY,
                                GetwxStr("XY+ZY"),
                                GetwxStr("XY & ZY      Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXZ_ZY,
                                GetwxStr("XZ+ZY"),
                                GetwxStr("XZ & ZY      Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_sliceXY_XZ_ZY,
                                GetwxStr("XY+XZ+ZY"),
                                GetwxStr("GetwxStr(XY & XZ & ZY Slice"));
    _wxm_type_coupe->AddChoice( ID_MenuOptions_XYslices,
                                GetwxStr("many XY"),
                                GetwxStr("XY Slices"));
    _wxm_type_coupe->SetSelection(ID_MenuOptions_sliceXY_XZ_ZY);

    menuOptions->AppendSeparator();

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Size \n");

    _wxm_type_taille = new wxMenuEnum(  menuOptions,
                                        &Param._type_taille,
                                        "&Size");
    _wxm_type_taille->AddChoice(ID_MenuOptions_window_size,
                                GetwxStr("Window size"),
                                GetwxStr("Adapt to window size"));
    _wxm_type_taille->AddChoice(ID_MenuOptions_fixed_size,
                                GetwxStr("Selected factor"),
                                GetwxStr("Selected fixed size"));
    _wxm_type_taille->SetSelection(ID_MenuOptions_window_size);

    menuOptions->AppendSeparator();

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Original Size \n");

    menuOptions->Append( ID_MenuImage_original_size, GetwxStr("&Original Size"));

    _wxm_zoom = new wxMenuEnum(menuOptions,&Param._fonction_zoom, "&Zoom");
    _wxm_zoom->AddChoice( ID_MenuImage_zoom_activated,
                          GetwxStr("Zoom activated"),
                          GetwxStr("Activate zoom"));
    _wxm_zoom->AddChoice( ID_MenuImage_zoom_desactivated,
                          GetwxStr("Zoom desactivated"),
                          GetwxStr("Desactivate zoom"));
    _wxm_zoom->AddChoice( ID_MenuImage_unzoom,
                          GetwxStr("Unzoom"),
                          GetwxStr("Unzoom"));
    _wxm_zoom->SetSelection(ID_MenuImage_zoom_desactivated);


    wxMenu* interp_submenu = new wxMenu;
    interp_submenu->AppendCheckItem(ID_MenuOptions_Interp_Active, GetwxStr("Active"));

    _wxm_interp_subdiv = new wxMenuEnum(interp_submenu,&_interpole_subdivision, "Sub&division");
    _wxm_interp_subdiv->AddChoice(ID_MenuOptions_interp_sub2,    GetwxStr(" 2 "),    GetwxStr("2"));
    _wxm_interp_subdiv->AddChoice(ID_MenuOptions_interp_sub3,    GetwxStr(" 3 "),    GetwxStr("3"));
    _wxm_interp_subdiv->AddChoice(ID_MenuOptions_interp_sub4,    GetwxStr(" 4 "),    GetwxStr("4"));
    _wxm_interp_subdiv->AddChoice(ID_MenuOptions_interp_sub8,    GetwxStr(" 8 "),    GetwxStr("8"));
    _wxm_interp_subdiv->AddChoice(ID_MenuOptions_interp_submax,  GetwxStr("max"),    GetwxStr("max"));
    _wxm_interp_subdiv->SetSelection(ID_MenuOptions_interp_submax);

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Interpolation \n");

    menuOptions->Append( ID_MenuOptions_Interpolation, GetwxStr("&Interpolation")  ,interp_submenu  );
    menuOptions->AppendSeparator();

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Vector Field \n");

    menuOptions->Append( ID_MenuOptions_circlefield,  GetwxStr("&Circle field"   ));
    menuOptions->AppendSeparator();

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() Voxels 3D \n");

    menuOptions->Append( ID_MenuOptions_voxels3D,     GetwxStr("Vo&xels 3D"        ));
    menuOptions->Append( ID_MenuOptions_OpenGLMIP,    GetwxStr("OpenGL &MIP"       ));
    menuOptions->Append( ID_MenuOptions_VolRen,       GetwxStr("Volume &Rendering" ));
    menuOptions->Append( ID_MenuOptions_Sections3D,   GetwxStr("Sections &3D"      ));
    menuOptions->Append( ID_MenuOptions_Colors,       GetwxStr("C&olors"           ));

    _wxm_linewidth = new wxMenuEnum(menuOptions,&_largeur_lignes,"Line &Width");
    _wxm_linewidth->AddChoice(ID_MenuOptions_linewidth1,  GetwxStr("width 1"),
                              GetwxStr("line thickness 1 pixel"));
    _wxm_linewidth->AddChoice(ID_MenuOptions_linewidth2,  GetwxStr("width 2"),
                              GetwxStr("line thickness 2 pixels"));
    _wxm_linewidth->AddChoice(ID_MenuOptions_linewidth3,  GetwxStr("width 3"),
                              GetwxStr("line thickness 3 pixels"));
    _wxm_linewidth->AddChoice(ID_MenuOptions_linewidth4,  GetwxStr("width 4"),
                              GetwxStr("line thickness 4 pixels"));

    menuOptions->AppendSeparator();

    menuOptions->AppendCheckItem( ID_MenuOptions_display_mask,     GetwxStr("Display &Mask"  ));
    menuOptions->Check(ID_MenuOptions_display_mask,_dessine_masque);
    menuOptions->AppendCheckItem( ID_MenuOptions_display_cursor,   GetwxStr("Display &Cursor"  ));
    menuOptions->Check(ID_MenuOptions_display_cursor,Param._curseur._visible);
    menuOptions->AppendCheckItem( ID_MenuOptions_paramwin,         GetwxStr("&Parameters"  ));
    menuOptions->Check(ID_MenuOptions_paramwin,Param._parametres_visible);


    menuBar->Append( menuOptions, GetwxStr("&Options" ));

  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() MIP \n");

    // Option MIP
    menuMIP = new wxMenu;

    menuMIP->AppendCheckItem(  ID_MenuMIP_param,       GetwxStr("Show &Parameters"));
    menuMIP->Check(            ID_MenuMIP_param,       _MIP_parametres_visibles);
    menuMIP->AppendCheckItem(  ID_MenuMIP_minmax,      GetwxStr("Use &min max"));
    menuMIP->Check(            ID_MenuMIP_minmax,      Param._MIP._min_max);
    menuMIP->AppendCheckItem(  ID_MenuMIP_boundingbox, GetwxStr("&Bounding Box"));
    menuMIP->Check(            ID_MenuMIP_boundingbox, Param._MIP._bounding_box);

    menuMIP->Append(           ID_MenuMIP_zoombb,      GetwxStr("&Zoom bounding box"));

    wxMenu* MIP_proj = new wxMenu;
    MIP_proj->Append(         ID_MenuMIP_Proj_morepoints, GetwxStr("&More Points"));
    MIP_proj->Append(         ID_MenuMIP_Proj_interp,     GetwxStr("&Linear Interpolation"));
    MIP_proj->AppendCheckItem(ID_MenuMIP_Proj_fast,       GetwxStr("&Fast"));
    MIP_proj->Check(          ID_MenuMIP_Proj_fast,       _MIP_rapide);
    MIP_proj->Append(         ID_MenuMIP_ReadCrest, GetwxStr("&Read Crest Files"));

    menuMIP->Append(          ID_MenuImage_MIPproj,
                              GetwxStr("&Projection"),
                              MIP_proj );

    wxMenu* MIP_stereo = new wxMenu;
    MIP_stereo->AppendCheckItem(  ID_MIPstereo_active,
                                  GetwxStr("&Active"));
    MIP_stereo->Check(            ID_MIPstereo_active, Param._MIP._stereo);
    MIP_stereo->Append         (  ID_MIPstereo_anim,
                                   GetwxStr("&Animate"));
    MIP_stereo->Append         (  ID_MIPstereo_colors,
                                  GetwxStr("&Colors"));
    menuMIP->Append(              ID_MenuImage_MIPstereo,
                                  GetwxStr("&Stereo"),
                                  MIP_stereo );

    menuBar->Append( menuMIP, GetwxStr("&MIP") );

    // Comparison Menu
    menuCompare = new wxMenu;

    menuCompare->AppendCheckItem( ID_MenuCompare_DependPosition,
                                  GetwxStr("Depend &Position"));
    menuCompare->Check(           ID_MenuCompare_DependPosition,  _compare_depend_position);
    menuCompare->AppendSeparator();

    menuCompare->AppendCheckItem(
                          ID_MenuCompare_DependIntensity,
                          GetwxStr("Depend &Intensity"));
    menuCompare->Check(    ID_MenuCompare_DependIntensity,
                           _compare_depend_intensity);
    menuCompare->AppendCheckItem(
                          ID_MenuCompare_NormalizeIntensity,
                          GetwxStr("&Normalize Intensity"));
    menuCompare->Check(   ID_MenuCompare_NormalizeIntensity,
                          _compare_normalize_intensity);
    menuCompare->Append(  ID_MenuCompare_UpdateMinMax,
                          GetwxStr("&Update Intensity Limits"));
    menuBar->Append( menuCompare, GetwxStr("&Comparison") );


/*

  //====================
  _Maide = new KmSousMenus( _menu, FrAn("Aide","Help"));

  //---------------
  _Maide_html = new KmSousMenu( _Maide,
                FrAn("Page Web","Web Page"),
                CB_aide_HTML, (void*) this);
  //---------------
  _Maide_motcle  = new KmSousMenu( _Maide,
                   FrAn("Mot cle","Key word"),     NULL, NULL);
  _Maide_motcle->Desactive();
  //---------------
  _Maide_version = new KmSousMenu( _Maide, "Version",     NULL, NULL);
  _Maide_version->Desactive();

  _menu->MenuAide( _Maide);
*/


  Si GB_debug AlorsFait printf("DessinImageBase::CreateWxMenu() End \n");

}



// -------------------------------------------------------------------------
//
void DessinImageBase :: InitFenetre()
//                                -----------
{

  FenetreDessin::InitFenetre();

} // InitFenetre()


//----------------------------------------------------------------
void DessinImageBase :: DessineCurseur(  int x, int y, int z, int type)
//                                --------------
//  Dessine la position du curseur sur toutes les coupes
{
    int pos_x, pos_y;
    int     height[NB_MAX_IMAGES];
    int     width[NB_MAX_IMAGES];

    wxDC* drawcontext;
    wxClientDC dc(_drawing_window);

  if (Param._curseur._visible)
    drawcontext = _memory_dc.get();
  else {
    if (!dc.IsOk()) {
      cerr  << "DessinImageBase::DessineCurseur()"
            << "\t bad client dc" << endl;
      return;
    } else
      drawcontext = &dc;
  }

  for(int i=0;i<NB_MAX_IMAGES;i++) {
    if (_tab_slices[i].image.use_count()) {
      height[i] = _tab_slices[i].image->GetHeight();
      width[i]  = _tab_slices[i].image->GetWidth();
    } else {
      height[i] = 0;
      width[i]  = 0;
    }
  }

  Si GB_debug AlorsFait
    fprintf(stderr,"DessineCurseur() \tdebut\n");

  if (_transf_matrix!=NULL) {
    // first apply the transformation matrix
    float x1,y1,z1;

    x1 = x*(*_transf_matrix)[0][0]+
         y*(*_transf_matrix)[0][1]+
         z*(*_transf_matrix)[0][2]+
           (*_transf_matrix)[0][3];

    y1 = x*(*_transf_matrix)[1][0]+
         y*(*_transf_matrix)[1][1]+
         z*(*_transf_matrix)[1][2]+
           (*_transf_matrix)[1][3];

    z1 = x*(*_transf_matrix)[2][0]+
         y*(*_transf_matrix)[2][1]+
         z*(*_transf_matrix)[2][2]+
           (*_transf_matrix)[2][3];

    x = (int) (x1+0.5);
    y = (int) (y1+0.5);
    z = (int) (z1+0.5);

  }

  Si x<0 AlorsFait x = 0;
  Si y<0 AlorsFait y = 0;
  Si z<0 AlorsFait z = 0;

  Si x>=_image->_tx AlorsFait x = _image->_tx-1;
  Si y>=_image->_ty AlorsFait y = _image->_ty-1;
  Si z>=_image->_tz AlorsFait z = _image->_tz-1;


  switch ( type ){
    case TYPE_CURSEUR_equiv:
        drawcontext->SetLogicalFunction( wxEQUIV);
    break;
    case TYPE_CURSEUR_copy:
        drawcontext->SetLogicalFunction( wxCOPY);
    break;
  } // end switch

  _current_pen->SetColour(_couleur_curseur);
  _current_pen->SetWidth(_largeur_lignes+1);

  /// @cond wxCHECK

  #if (wxCHECK_VERSION(2,9,0))
    _current_pen->SetStyle((wxPenStyle)wxSOLID);
  #else
    _current_pen->SetStyle(wxSOLID);
  #endif
  /// @endcond

  drawcontext->SetPen(*_current_pen);

  Si (Param._type_coupe+1) & (TYPE_COUPE_XY+1) Alors

    pos_x = (int) (_tab_ximage_pos_x[IMAGE_XY] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) (_tab_ximage_pos_y[IMAGE_XY] + (y - Param._Zoom._ymin + 0.5)*_size_y);

    LigneHorizontale( drawcontext, _tab_ximage_pos_x[IMAGE_XY],
                      _tab_ximage_pos_x[IMAGE_XY]+ width[IMAGE_XY],
                      pos_x, pos_y);

    LigneVerticale(  drawcontext, _tab_ximage_pos_y[IMAGE_XY],
                     _tab_ximage_pos_y[IMAGE_XY]+ height[IMAGE_XY],
                     pos_y, pos_x);
  FinSi

  Si (Param._type_coupe+1) & (TYPE_COUPE_XZ+1) Alors

    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_XZ] + (x - Param._Zoom._xmin + 0.5)*_size_x);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_XZ] + (z - Param._Zoom._zmin + 0.5)*_size_z);

    LigneHorizontale( drawcontext,_tab_ximage_pos_x[IMAGE_XZ],
                      _tab_ximage_pos_x[IMAGE_XZ]+
                      width[IMAGE_XZ],
                      pos_x, pos_y);

    LigneVerticale(  drawcontext,_tab_ximage_pos_y[IMAGE_XZ],
                     _tab_ximage_pos_y[IMAGE_XZ]+
                     height[IMAGE_XZ],
                     pos_y, pos_x);
  FinSi


  Si (Param._type_coupe+1) & (TYPE_COUPE_ZY+1) Alors

    pos_x = (int) ( _tab_ximage_pos_x[IMAGE_ZY] + (z - Param._Zoom._zmin + 0.5)*_size_z);
    pos_y = (int) ( _tab_ximage_pos_y[IMAGE_ZY] + (y - Param._Zoom._ymin + 0.5)*_size_y);

    LigneHorizontale( drawcontext,_tab_ximage_pos_x[IMAGE_ZY],
                      _tab_ximage_pos_x[IMAGE_ZY]+
                      width[IMAGE_ZY],
                      pos_x, pos_y);

    LigneVerticale(  drawcontext,_tab_ximage_pos_y[IMAGE_ZY],
                     _tab_ximage_pos_y[IMAGE_ZY]+
                     height[IMAGE_ZY],
                     pos_y, pos_x);


  FinSi

  Param._curseur._ON = Non(Param._curseur._ON);

  drawcontext->SetLogicalFunction( wxCOPY);

  Si GB_debug AlorsFait
    fprintf(stderr,"DessineCurseur() \tfin\n");

} // DessineCurseur()


//----------------------------------------------------------------
void DessinImageBase :: DessineSpatialCurseur(  float x, float y, float z, int type)
//                                --------------
//  Dessine la position du curseur sur toutes les coupes
{

  // convert to voxel position
  float posx,posy,posz;
  posx = _image->SpaceToVoxelX(x);
  posy = _image->SpaceToVoxelY(y);
  posz = _image->SpaceToVoxelZ(z);

  DessineCurseur((int)(posx+0.5),(int)(posy+0.5),(int)(posz+0.5),type);

} // DessineSpatialCurseur()


//----------------------------------------------------------------
void DessinImageBase ::  MemoriseCoupesXY( unsigned char activation )
//                                 ----------------
{

  Si activation == _memorise_coupes_XY AlorsRetourne; // pas de changement

  cerr << "MemoriseCoupesXY() not yet available in this platform" << endl;

} // MemoriseCoupesXY()


//----------------------------------------------------------------
void DessinImageBase ::  InitMasque( Chaine nom_masque )
//                                 ----------
{

  _nom_image_masque = nom_masque;

  Si _image_masque != NULL Alors
    delete _image_masque;
  Sinon
    _image_masque = new InrImage( _nom_image_masque);
    Si _image_masque->_tx != _image->_tx Ou
       _image_masque->_ty != _image->_ty Ou
       _image_masque->_tz != _image->_tz
    Alors
      printf("DessinImageBase::InitMasque\t erreur\t");
      printf("masque de dimensions diff�entes de l'image initiale\n");
      delete _image_masque;
      _image_masque = NULL;
    FinSi

    Si _image_masque->_format != WT_UNSIGNED_CHAR
    Alors
      printf("DessinImageBase::InitMasque\t erreur\t");
      printf("masque de format diff�ent de WT_UNSIGNED_CHAR\n");
      delete _image_masque;
      _image_masque = NULL;
    FinSi
  FinSi

} // InitMasque()


//----------------------------------------------------------------
void DessinImageBase :: FixeMasque( unsigned char active)
//                                ----------
{

  Si _image_masque == NULL Alors
    _dessine_masque = false;
  Sinon
    _dessine_masque = active;
  FinSi
//  _Moptions_masque_visible->MAJ();
  Param._MAJ.MAJCoupes();
  Paint();

  //  printf("_dessine_masque %d\n",_dessine_masque);

} // FixeMasque()


//----------------------------------------------------------------
void DessinImageBase ::  InitIsoContour( InrImage::ptr image_isocontour,
//                                 --------------
               float seuil, int num )
{
    // check that the image number is correct
    if ((num<0)||(num>(int)_isocontours.size())) {
        fprintf(stderr,"DessinImageBase::InitIsocontour()\t contour number not valid %d \n",num);
        return;
    }


  Si image_isocontour->DimX() != _image->DimX() Ou
     image_isocontour->DimY() != _image->DimY() Ou
     image_isocontour->DimZ() != _image->DimZ()
  Alors
    printf("DessinImageBase::InitIsocontour\t Error\t");
    printf("The isocontour image needs to have the same size as the image drawn !\n");
    return;
  Sinon
    _isocontours[num].image     = image_isocontour;
    _isocontours[num].threshold = seuil;
  FinSi


} // InitIsoContour()


//----------------------------------------------------------------
void DessinImageBase ::  DrawIsoContour( int num, int val )
//                                 --------------
{

  if ((num<0)||(num>(int)_isocontours.size()-1)) {
    fprintf(stderr,"DessinImageBase::DrawIsoContour() bad contour number \n");
    return;
  }

  _isocontours[num].visible = (val>0);

} // DrawIsoContour()


//------------------------------------------------------
void DessinImageBase::SetIsoContourParam( int num, int thickness, int style)
//   ------------------
{
    Si num<0                    AlorsFait num = 0;
    Si num>=(int)_isocontours.size() AlorsFait num = _isocontours.size()-1;
    _isocontours[num].thickness = thickness;
    Si style<0 AlorsFait style=0;
    Si style>2 AlorsFait style=2;
    _isocontours[num].style = style;
} // SetIsoContourParam()


//------------------------------------------------------
void DessinImageBase::SetIsoContourColor( int num,
//                    ------------------
        unsigned char r, unsigned char g, unsigned char b)
{
    if (num<0)  num = 0;
    if (num>=(int)_isocontours.size())
        num = _isocontours.size()-1;
    _isocontours[num].color.FixeValeur(r,g,b);
} // SetIsoContourColor()

/*
//--------------------------------------------------------
void DessinImageBase::DessineIsoContour( int n)
//                    -----------------
{
    InrImage::ptr            image;
    float                   seuil;
    int                     size;
    int                     style;

  if ((n<0) || (n>=_isocontours.size()) {
    printf("DessinImageBase::DessineIsoContour \t bad contour number %d \n",n);
    return;
  }

  _isocontours[n].visible = true;
  seuil = _isocontours.threshold[n];

  // Set the parameters
  FixeFonctionDessin( GXcopy);
  size = _isocontours[n].thickness
  if (size==0)  size = _largeur_lignes;
  style = _isocontours[n].style;
  FixeParametresLigne( size, style, _cap_style, _join_style);
  SetPenColor( isocontours[n].color.RetourneCouleur());

  if ((_isocontours[n].image.expired()) ||
      (Param._option_traitement == OPTION_MIP))
    image = _image;
  else
    image = InrImage::ptr(_isocontours[n].image);


  Si ((Param._type_coupe+1) & (TYPE_COUPE_ZY+1)) Alors
    AfficheImage( IMAGE_ZY);
    DessinePlanXIsoContour(image,seuil);
  FinSi

  Si ((Param._type_coupe+1) & (TYPE_COUPE_XZ+1)) Alors
    AfficheImage( IMAGE_XZ);
    DessinePlanYIsoContour(image,seuil);
  FinSi

  Si ((Param._type_coupe+1) & (TYPE_COUPE_XY+1)) Alors
    AfficheImage( IMAGE_XY);
    DessinePlanZIsoContour(image,seuil);
  FinSi

} // DessineIsoContour()
*/

/*
//----------------------------------------------------------------
void DessinImageBase ::  InitImage( inrimage* image)
//                                 ---------
{

  Si _image_initiale->_tx != image->ncols Ou
     _image_initiale->_ty != image->nrows Ou
     _image_initiale->_tz != image->nplanes
  Alors
    printf(" %d %d %d \n", image->ncols, image->nrows, image->nplanes);
    printf("DessinImageBase::InitImage\t erreur\t");
    printf("image de dimensions diff�entes de l'image initiale\n");
  Sinon
    _image = InrImage::ptr(new InrImage(image));
  FinSi


} // InitImage()
*/

//----------------------------------------------------------------
void DessinImageBase :: Paint( unsigned char affiche)
//                                -----
{


} // Paint()


//----------------------------------------------------------------
void DessinImageBase :: ReDimensionne( )
//                      -------------
{
  DrawingAreaInit( );
  Param._MAJ.MAJCoupes();
  Paint();
} // ReDimensionne()


//----------------------------------------------------------------
void DessinImageBase::DrawAxis( int orientation, // 0: horiz, 1: vert
//                    --------
                                int axis, // 0: X, 1: Y, 2: Z
                                int Ox, int Oy)
{
  float   px,py;
  string  num_str;
  int     text_pixel_step;
  float   unit,text_unit_step;
  int     unit_scale = 0;
  int     small_pixel_step;
  int     i;
  int     max_textwidth=10;
  int     max_textheight;

  float   voxsize=1;
  int     posmin=0, posmax=0;
  int     small_tick_size=1;
  int     large_tick_size=3;

  switch(axis) {
    case 0:
      voxsize = _size_x;
      posmin = Param._Zoom._xmin;
      posmax = Param._Zoom._xmax;
    break;
    case 1:
      voxsize = _size_y;
      posmin = Param._Zoom._ymin;
      posmax = Param._Zoom._ymax;
    break;
    case 2:
      voxsize = _size_z;
      posmin = Param._Zoom._zmin;
      posmax = Param._Zoom._zmax;
    break;
  }

  SetPenColor( *wxBLACK);
  FixeParametresLigne( 1, wxSOLID);

  wxCoord maxCharWidth,maxCharHeight;
  _memory_dc->GetTextExtent(wxString::FromAscii("X"),
                            &maxCharWidth,
                            &maxCharHeight);

  // compute text_pixel_step: how many pixels per displayed text value
  switch (Param._axes_info) {
    case AXES_VOXEL_POS: unit=1.0;  break;
    case AXES_SPACE_POS:
      unit=_image->VoxSize(axis);
      // check if the unit should be scaled
      // try to have approx. 100 values within range
      if ((posmax-posmin)*unit>=0) {
        double range = ceil(log((posmax-posmin)*unit)/log(10.0));
        unit_scale = 2-(int) range;
        unit = unit*exp(log(10.0)*unit_scale);
        //cout << "unit " << axis << "scaled by 10^" << unit_scale << endl;
      }
    break;
  }
  if (orientation==0) {
    // Horizontal range bar
    switch (Param._axes_info) {
      case AXES_VOXEL_POS: max_textwidth = (int) 3*maxCharWidth;
      break;
      case AXES_SPACE_POS: max_textwidth = (int) 4*maxCharWidth;
      break;
    }
    text_pixel_step  = (int) (max_textwidth/voxsize+0.99);
    text_unit_step   = max_textwidth/voxsize*unit;
  } else {
    // Vertical range bar
    max_textheight   = (int) maxCharHeight;
    text_pixel_step  = (int) ((max_textheight+2)/voxsize);
    text_unit_step   = max_textheight/voxsize*unit;
  }

  // look for nearest higher acceptable value
  Pour(i,0,NUM_ACCEP_VAL-1)
    Si acceptable_values[i]>=text_unit_step
    AlorsFait break;
  FinPour
  Si i==NUM_ACCEP_VAL AlorsFait i=NUM_ACCEP_VAL-1;
  text_pixel_step  = acceptable_values[i];
  small_pixel_step = corresp_values[i];

  switch(axis) {
    case 0: num_str = "X"; break;
    case 1: num_str = "Y"; break;
    case 2: num_str = "Z"; break;
  }
  if (Param._axes_info==AXES_SPACE_POS)
    switch(unit_scale) {
      case -3: num_str = num_str+".10³";
      break;
      case -2: num_str = num_str+".10²";
      break;
      case -1: num_str = num_str+".10";
      break;
    }

  // Draw the remaining text and sticks
  // compute starting position
  double min_value=0,max_value=0;
  int    current_value=0;
  if (Param._axes_info==AXES_VOXEL_POS) {
    min_value=posmin;
    max_value=posmax;
  }
  if (Param._axes_info==AXES_SPACE_POS) {
    min_value=_image->SpacePos(axis,posmin)*exp(log(10.0)*unit_scale);
    max_value=_image->SpacePos(axis,posmax)*exp(log(10.0)*unit_scale);
  }
  current_value = (int) ((floor(min_value/(1.0*small_pixel_step))
                                +1)
                          *small_pixel_step);

  if (orientation==0) {

    // Horizontal range bar
    px  = Ox + voxsize/2.0;
    py  = Oy+5;
    // draw the main line
    float pxmax = px+voxsize*(posmax-posmin);
    Ligne((int) px,   (int)py,
          (int) pxmax,(int)py);

    // draw an arrow at the end and the name of the axis
    // draw a small arrow
    int arrow_size = 4;
    Ligne((int)(pxmax),(int)py,
          (int)(pxmax-arrow_size),(int)(py-arrow_size));
    Ligne((int)(pxmax),(int)py,
          (int)(pxmax-arrow_size),(int)(py+arrow_size));

    _memory_dc->GetTextExtent(wxString::FromAscii(num_str.c_str()),
                    &maxCharWidth,
                    &maxCharHeight);
    int starttext = (int)(pxmax-maxCharWidth/2);
    Texte(  starttext,(int)(py+arrow_size+1), num_str.c_str());

    while(current_value<=max_value) {
      px = Ox+voxsize/2.0+(current_value-min_value)/unit*voxsize;
      if ((current_value%text_pixel_step) == 0) {
        Ligne((int)px,(int)py,(int)px,(int)(py-large_tick_size-1));
        switch(unit_scale) {
          case 1: num_str = str(format("%1%")%(current_value/10.0));
          break;
          case 2: num_str = str(format("%1%")%(current_value/100.0));
          break;
          case 3: num_str = str(format("%1%")%(current_value/1000.0));
          break;
          default:num_str = str(format("%1%")%current_value);
        }

        /*
        switch (Param._axes_info) {
          case AXES_VOXEL_POS: num_str = str(format("%d")%x); break;
          case AXES_SPACE_POS:
             num_str = str(format("%2.1f")%_image->SpacePos(axis,x));
          break;
        }
        */

        _memory_dc->GetTextExtent(wxString::FromAscii(num_str.c_str()),
                        &maxCharWidth,
                        &maxCharHeight);
        if ((px-maxCharWidth/2>Ox)&&
            (px+maxCharWidth/2 < starttext))
          Texte((int)(px-maxCharWidth/2),(int)(py+2),num_str.c_str());
      } else
          Ligne((int)px,(int)py,(int)px,(int)(py-small_tick_size-1));
      current_value += small_pixel_step;
      //px += voxsize;
    } // end while
  } else {

    // Vertical range bar
    px  = Ox+5;
    py  = Oy + voxsize/2.0;
    // draw the main line
    float pymax = py+voxsize*(posmax-posmin);
    Ligne((int) px, (int) py,
          (int) px, (int) pymax);

    // draw an arrow at the end and the name of the axis
    // draw a small arrow
    int arrow_size = 4;
    Ligne((int) px,(int) (pymax),
          (int) (px-arrow_size),(int) (pymax-arrow_size));
    Ligne((int) px,(int) (pymax),
          (int) (px+arrow_size),(int) (pymax-arrow_size));

    _memory_dc->GetTextExtent(wxString::FromAscii(num_str.c_str()),
                    &maxCharWidth,
                    &maxCharHeight);
    int starttext = (int)(pymax-maxCharHeight/2);
    Texte((int)(px+arrow_size+1),
          starttext,
          num_str.c_str());

    while(current_value<=max_value) {
      py = Oy+voxsize/2.0+(current_value-min_value)/unit*voxsize;
      if ((current_value%text_pixel_step) == 0) {
        Ligne((int) px,(int) py,(int) (px-large_tick_size-1),(int) py);
        switch(unit_scale) {
          case 1: num_str = str(format("%1%")%(current_value/10.0));
          break;
          case 2: num_str = str(format("%1%")%(current_value/100.0));
          break;
          case 3: num_str = str(format("%1%")%(current_value/1000.0));
          break;
          default:num_str = str(format("%1%")%current_value);
        }
        /*
        switch ( Param._axes_info ){
          case AXES_VOXEL_POS: num_str = str(format("%d")%y); break;
          case AXES_SPACE_POS:
            switch(axis) {
              case 0: num_str = str(format("%2.1f")%_image->SpacePosX(y));
              break;
              case 1: num_str = str(format("%2.1f")%_image->SpacePosY(y));
              break;
              case 2: num_str = str(format("%2.1f")%_image->SpacePosZ(y));
              break;
            }
          break;
        } // end switch
        */
        _memory_dc->GetTextExtent(wxString::FromAscii(num_str.c_str()),
                        &maxCharWidth,
                        &maxCharHeight);
        if ((py-maxCharHeight/2>Oy)&&
            (py+maxCharHeight/2 < starttext))
          Texte((int)(px+2),(int)(py-maxCharHeight/2),num_str.c_str());
      } else
        Ligne((int) px,(int) py,(int) (px-small_tick_size-1),(int) py);

      current_value += small_pixel_step;
      //py += voxsize;
    } // end while
  } // end if orientation

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DrawAxis() end\n");

} // DrawAxis()



//----------------------------------------------------------------
void DessinImageBase :: DessineAxesXY( )
//                      -------------
{
  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesXY() begin\n");

  if (!(Param._show_axes)) return;
  if (Param._type_coupe == TYPE_COUPES) return;

  DrawAxis( 0,
            0,
            _tab_ximage_pos_x[IMAGE_XY],
            _tab_ximage_pos_y[IMAGE_XY] +
              GetImageHeight(IMAGE_XY)
          );

  DrawAxis( 1,
            1,
            _tab_ximage_pos_x[IMAGE_XY] +
              GetImageWidth(IMAGE_XY),
            _tab_ximage_pos_y[IMAGE_XY]
          );

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesXY() end\n");

} // DessineAxesXY()


//----------------------------------------------------------------
void DessinImageBase :: DessineAxesXZ( )
//                                ------------
{
  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesXZ() begin\n");

  if (!(Param._show_axes)) return;
  if (Param._type_coupe == TYPE_COUPES) return;

  DrawAxis( 1,
            2,
            _tab_ximage_pos_x[IMAGE_XZ] +
              GetImageWidth(IMAGE_XZ),
            _tab_ximage_pos_y[IMAGE_XZ]
          );


  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesXZ() end\n");
} // DessineAxesXZ()


//----------------------------------------------------------------
void DessinImageBase :: DessineAxesZY( )
//                                ------------
{
  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesZY() begin\n");

  if (!(Param._show_axes)) return;
  if (Param._type_coupe == TYPE_COUPES) return;

  DrawAxis( 0,
            2,
            _tab_ximage_pos_x[IMAGE_ZY],
            _tab_ximage_pos_y[IMAGE_ZY] +
              GetImageHeight(IMAGE_ZY)
          );

  Si GB_debug AlorsFait
    fprintf(stderr,"DessinImageBase::DessineAxesZY() end\n");

} // DessineAxesZY()


//----------------------------------------------------------------
void DessinImageBase :: DrawColorBar( )
//                      ------------
{
  Si Non(Param._show_colorbar) AlorsFait return;

  Si _image->_format == WT_RGB AlorsFait return;
  Si _image->_format == WT_RGBA AlorsFait return;

  if (Param._type_coupe == TYPE_COUPES) return;

    int i;
    int l,r,t,b;
    int text_step;
    char     Istring[20];
    char     Istring_min[20];
    char     Istring_max[20];
    register float          val,val_step,step,vpos2;
    register ClasseCouleur  couleur;
    float                   valmin, valmax;
    float                   Imin, Imax;

  int char_xmax;
  int char_ymax;

  wxFont font = _memory_dc->GetFont();
  wxCoord maxCharWidth, maxCharHeight;
  _memory_dc->GetTextExtent(wxT("W"),
                    &maxCharWidth,
                    &maxCharHeight);
  char_xmax = maxCharWidth;
  char_ymax = maxCharHeight;

  Si (_image->_format == WT_FLOAT ) Ou
     (_image->_format == WT_DOUBLE) Alors
    Imin = _intensite_float_min;
    Imax = _intensite_float_max;
  Sinon
    Imin = _intensite_entier_min;
    Imax = _intensite_entier_max;
  FinSi

  valmin = _val_min;
  valmax = _val_max;

  Si valmax - valmin >= 100 Alors
    sprintf(Istring_max,"%3.0f",valmax);
    sprintf(Istring_min,"%3.0f",valmin);
  Autrement
  Si valmax - valmin >= 10 Alors
    sprintf(Istring_max,"%2.1f",valmax);
    sprintf(Istring_min,"%2.1f",valmin);
  Sinon
    sprintf(Istring_max,"%1.2f",valmax);
    sprintf(Istring_min,"%1.2f",valmin);
  FinSi

  int maxwidth1,maxwidth2,maxwidth;
  wxCoord descent;
  wxCoord externalLeading;
  _memory_dc->GetTextExtent(wxString::FromAscii(Istring_max),
                    &maxCharWidth,
                    &maxCharHeight,
                    &descent,
                    &externalLeading);
  maxwidth1 = (int) maxCharWidth;
  _memory_dc->GetTextExtent(wxString::FromAscii(Istring_min),
                    &maxCharWidth,
                    &maxCharHeight);
  maxwidth2 = (int) maxCharWidth;
  maxwidth = macro_max(maxwidth1, maxwidth2);
  r    = _largeur-maxwidth-4;
  l    = r-20;
  t    = 20;
  b    = _hauteur-20;

  step = (b-t)/256.0;

  text_step = 256;
  TantQue ((step*text_step)>2*(char_ymax+1)) Et (text_step>1) Faire
    text_step/=2;
  FinTantQue

  Si l<0 Ou t>b Alors
  //    fprintf(stderr,"DessinImageBase::DrawColorBar() \t");
  //    fprintf(stderr," l=%d r=%d t=%d b=%d \n",l,r,t,b);
    return;
  FinSi

  vpos2 = b;

  FixeParametresLigne(0,wxTRANSPARENT);

  val = valmin;
  val_step = (valmax-valmin)/255.0;

  //cout << "steps = " << step << endl;

  Pour(i,0,255)
   couleur = _tab_intensite_couleur[IntensiteBuffer(val)];
   vpos2 -= step;
   FixeCouleurRemplissage( couleur);

   Rectangle(
              l,
              (int) vpos2,
              r,
              (int) (step+vpos2));

   Si (i==0) Ou ((i+1)%text_step==0) Alors
     Si valmax - valmin >= 100 Alors
      sprintf(Istring,"%3.0f",val);
     Autrement
     Si valmax - valmin >= 10 Alors
      sprintf(Istring,"%2.1f",val);
     Sinon
      sprintf(Istring,"%1.2f",val);
     FinSi

     SetTextFg( *wxBLACK);
     //Texte(r+2,(int)(vpos2+step+char_ymax/2),Istring);
     FixeParametresLigne(1,wxSHORT_DASH);
     SetPenColor(*wxBLACK);
     //cout << "drawing line for " << Istring
     //     << " at " << (int) (vpos2+step/2) << endl;
     Ligne(
            l,
            (int) (vpos2+step/2),
            r,
            (int) (vpos2+step/2)
          );
     FixeParametresLigne(0,wxTRANSPARENT);
     Texte(r+2,(int)(vpos2-char_ymax/2),Istring);
   FinSi

   val += val_step;
  FinPour

  SetPenColor( *wxBLACK);
  FixeStyleRemplissage(wxTRANSPARENT);
//wxBRUSHSTYLE_TRANSPARENT);
  FixeParametresLigne(1,wxSOLID);
  Rectangle(l,(int)t,r,(int) b+1);
  FixeStyleRemplissage(wxSOLID);
//wxBRUSHSTYLE_SOLID);


} // DrawColorBar()


//----------------------------------------------------------------
// slice_id: IMAGE_XY (0), IMAGE_XZ (1), IMAGE ZY (2)
//
//
void DessinImageBase::DrawSlice( int slice_id )
//                    ---------
{
  register int             x,y;
  register double           px, py;
  register double           px1, py1;

  int ix[3] = {0,0,2}; // 3D image axis to draw on display X coordinates
  int iy[3] = {1,2,1}; // 3D image axis to draw on display Y coordinates
  int ip[3] = {2,1,0}; // third axis

  int cix = ix[slice_id]; // current ix
  int ciy = iy[slice_id]; // current iy
  int cip = ip[slice_id]; // current ip

  int zoom_dim[3] = {  Param._Zoom._zoom_size_x,
                       Param._Zoom._zoom_size_y,
                       Param._Zoom._zoom_size_z};
  int zdx = zoom_dim[cix]; // dim (in pixels/voxels) along displayed X coord
  int zdy = zoom_dim[ciy]; // dim (in pixels/voxels) along displayed Y coord

  float voxel_size[3] = {_size_x,_size_y,_size_z};
  float vsx = voxel_size[cix];
  float vsy = voxel_size[ciy];

  int zoom_min[3] = { Param._Zoom._xmin, Param._Zoom._ymin, Param._Zoom._zmin };
  int zoom_max[3] = { Param._Zoom._xmax, Param._Zoom._ymax, Param._Zoom._zmax };
  int cmin_x = zoom_min[cix];
  int cmax_x = zoom_max[cix];
  int cmin_y = zoom_min[ciy];
  int cmax_y = zoom_max[ciy];

  int pos[3] = { Param._pos._x, Param._pos._y, Param._pos._z };
  int cpos = pos[cip]; // current voxel position on the 3rd axis

  int incr[3] = { 1,  _image->DimX(), _image->DimX()*_image->DimY()};
  int incr_x = incr[cix];

  register double displ_dimx, displ_dimy; // display size (in screen pixels) in X and Y

  /* todo: adapt these methods
  // Dans le cas d'un masque
  Si _dessine_masque Et Param._option_traitement != OPTION_MIP Alors
    DessinePlanMasqueZ();
    return;
  FinSi

  // Si interpolation lineaire:
  Si _interpole_image Alors
    DessinePlanInterpZ();
    return;
  FinSi
  */

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur
  //    superieure et d'eviter
  //--- un plantage
  displ_dimx = zdx*vsx;
  displ_dimy = zdy*vsy; // full display size

    
  #ifdef AMI_BUILD_Debug
    CLASS_MESSAGE(boost::format("displ_dimx = %1%, displ_dimy = %2%") % displ_dimx % displ_dimy );
  #endif

  CreeImage( slice_id, (int) (displ_dimx+1-1E-4), (int) (displ_dimy+1-1E-4));


  FixeImageCourante( slice_id);

  if (!_current_slice.get()) {
    CLASS_ERROR(" Problem with _current_slice smart pointer !");
    return;
  }

  register rgb_color* image_data  = (rgb_color*)
                                    _current_slice->GetData();
  register int        image_width = _current_slice->GetWidth();

//  _current_slice->SetPen(*wxTRANSPARENT_PEN);
  if (!_image) {
    CLASS_ERROR(" image not allocated !");
    return;
  }

  // lock the image to be sure it cannot be deleted!
  InrImage::ptr image_lock(_image);
  register InrImage* image = image_lock.get();
  register WORDTYPE image_format = image->GetFormat();
  register ClasseCouleur* colors = &_tab_intensite_couleur.front();
  register ClasseCouleur couleur;
  register int buf_pos[3];

  buf_pos[cip] = cpos;

  image->InitBuffer( );
  InitLookUpTable();

  // compute increments in X an Y to be sure to move to next pixel
  short stepx = floor(macro_max(1, 1.0/vsx));
  short stepy = floor(macro_max(1, 1.0/vsy));
  float nvsx    = vsx*stepx;
  float nvsy    = vsy*stepy;
  int   nincr_x = stepx*incr_x;
  int   maxy    = cmax_y-stepy+1; // max value in Y where we can draw using stepy
  int   maxx    = cmax_x-stepx+1; // max value in X where we can draw using stepx

  CLASS_MESSAGE( boost::format(" vsx %1% vsy %2%") % vsx % vsy );
  CLASS_MESSAGE( boost::format(" stepx %1% stepy %2%") % stepx % stepy );

  // if we have to step several image pixels, then each displayed pixel is drawn separately
  bool  pointlevel = (stepx>1)&&(stepy>1);

  py = 0;
  for( y = cmin_y; y  <= maxy; y+=stepy)
  {
    py1=py+nvsy;
    buf_pos[cix] = cmin_x;
    buf_pos[ciy] = y;
    //if (_dessine_masque)
    //  _image_masque->BufferPos( buf_pos[0], buf_pos[1], buf_pos[2]);
    image->BufferPos( buf_pos[0], buf_pos[1], buf_pos[2]);
    px = 0;
    for( x = cmin_x; x  <= maxx; x+=stepx )
    {
      px1=px+nvsx; // add epsilon ??

      Si (image_format != WT_RGB)&&
         (image_format != WT_RGBA)
      Alors
        couleur = colors[ LookUpTable(image->ValeurBuffer(),
                          image_format) ];
      Sinon
        couleur = ClasseCouleur(
        (unsigned char) image->VectValeurBuffer(0),
        (unsigned char) image->VectValeurBuffer(1),
        (unsigned char) image->VectValeurBuffer(2)
                               );
      FinSi

      if (pointlevel) {

        #ifdef AMI_BUILD_Debug
          // check for image limits
          if (  (((int)px)>=image_width)||
                (((int)py)>=_current_slice->GetHeight()) ) 
          {
            CLASS_ERROR( boost::format(" cmin_{x,y} cmax_{x,y} %1% %2%, %3% %4%")
                          % cmin_x % cmin_y % cmax_x % cmax_y );
            CLASS_ERROR( boost::format(" px py = %1%, %2% --> %3%, %4% size is %3%x%4%")
                          % px % py 
                          % ((int)px) % ((int)py) 
                          % image_width % _current_slice->GetHeight() );
          } else
        #endif

        FastImagePoint( image_data, image_width,
                            (int) px,
                            (int) py,
                            couleur);
      } else {

        #ifdef AMI_BUILD_Debug
          // check for image limits
          if (  (((int)px1)>image_width)||
                (((int)py1)>_current_slice->GetHeight()) ) 
          {
            CLASS_ERROR( boost::format(" cmin_{x,y} cmax_{x,y} %1% %2%, %3% %4%")
                          % cmin_x % cmin_y % cmax_x % cmax_y );
            CLASS_ERROR( boost::format(" px1, py1 = %1%, %2% size is %3%x%4%")
                          % ((int)px1) % ((int)py1) % image_width % _current_slice->GetHeight() );
          } else
        #endif

        FastImageRectangle( image_data, image_width,
                            (int) round(px),
                            (int) round(py),
                            (int) round(px1),
                            (int) round(py1),
                            couleur);
      }
      image->IncBuffer(nincr_x);
      px = px1;
    } // x
    py = py1;
  } // y

  //--- Si on memorise les coupes, on precise que cette coupe XY est a jour
#if defined(__MOTIF__)
  Si _memorise_coupes_XY AlorsFait
    _image_XY_a_jour[ Param._pos._z] = true;
#endif

} // DrawSlice()



//----------------------------------------------------------------
void DessinImageBase::DessinePlanZ( )
//                    ------------
{
     register int             x,y;
     register double           px, py;
     register double           px1, py1;

  // Dans le cas d'un masque
  Si _dessine_masque Et Param._option_traitement != OPTION_MIP Alors
    DessinePlanMasqueZ();
    return;
  FinSi

  // Si interpolation lineaire:
  Si _interpole_image Alors
    DessinePlanInterpZ();
    return;
  FinSi

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur
  //    superieure et d'eviter
  //--- un plantage
  Si _memorise_coupes_XY Alors
#if defined(__MOTIF__)
    //--- On verifie l'allocation des images avec les bonnes dimensions
    AlloueImagesXY( (int) (Param._Zoom._zoom_size_x*_size_x+1E-4), (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
    //--- On utilise la coupe deja allouee
    _tab_ximage_data[IMAGE_XY] = _tab_ximage_XY_data[ Param._pos._z];
    _tab_ximage[IMAGE_XY] = _tab_ximage_XY[ Param._pos._z];
    //--- Si l'image est a jour, on sort de la fonction
    Si _image_XY_a_jour[ Param._pos._z] AlorsRetourne;
#endif
  Sinon
    CreeImage( IMAGE_XY,
         (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
         (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
  FinSi

  FixeImageCourante( IMAGE_XY);
  register rgb_color* image_data  = (rgb_color*)
                                    _current_slice->GetData();
  register int        image_width = _current_slice->GetWidth();

//  _current_slice->SetPen(*wxTRANSPARENT_PEN);
  if (!_image) {
    cerr << "DessinImageBase::DessinePlanZ( )"
        << "\t image not allocated !" << endl;
    return;
  }

  // lock the image to be sure it cannot be deleted!
  InrImage::ptr image_lock(_image);
  register InrImage* image = image_lock.get();
  register WORDTYPE image_format = image->GetFormat();
  register ClasseCouleur* colors = &_tab_intensite_couleur.front();
  register ClasseCouleur couleur;

  image->InitBuffer( );
  InitLookUpTable();

  py = 0;
  for( y = Param._Zoom._ymin; y  <= Param._Zoom._ymax; y++)
  {
    py1=py+_size_y;

    if (_dessine_masque)
      _image_masque->BufferPos( Param._Zoom._xmin,
                                y,
                                Param._pos._z);
    image->BufferPos( Param._Zoom._xmin,
                      y,
                      Param._pos._z);
    px = 0;
    for( x = Param._Zoom._xmin; x  <= Param._Zoom._xmax; x++ )
      {
      px1=px+_size_x; // add epsilon ??

      Si (image_format != WT_RGB)&&
         (image_format != WT_RGBA)
      Alors
        couleur = colors[ LookUpTable(image->ValeurBuffer(),
                          image_format) ];
      Sinon
        couleur = ClasseCouleur(
        (unsigned char) image->VectValeurBuffer(0),
        (unsigned char) image->VectValeurBuffer(1),
        (unsigned char) image->VectValeurBuffer(2)
                               );
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) round(px),
                          (int) round(py),
                          (int) round(px1),
                          (int) round(py1),
                          couleur);

      image->IncBuffer();
      px = px1;
    } // x
    py = py1;
  } // y

  //--- Si on memorise les coupes, on precise que cette coupe XY est a jour
  Si _memorise_coupes_XY AlorsFait
    _image_XY_a_jour[ Param._pos._z] = true;

} // DessinePlanZ()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanY( )
//                                ------------
{
     register int             x, z;
     register float           px, pz;
     register float           px1,pz1;
     register ClasseCouleur   couleur;

  // Dans le cas d'un masque
  Si _dessine_masque Et Param._option_traitement != OPTION_MIP Alors
    DessinePlanMasqueY();
    return;
  FinSi

  // Si interpolation lineaire:
  Si _interpole_image Alors
    DessinePlanInterpY();
    return;
  FinSi

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur superieure
  //    et d'eviter
  //--- un plantage
  CreeImage( IMAGE_XZ,
       (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
       (int) (Param._Zoom._zoom_size_z*_size_z+1E-4));

  FixeImageCourante( IMAGE_XZ);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  InitBuffer( );

  pz = 0;
  for(  z = Param._Zoom._zmin
  ;  z  <= Param._Zoom._zmax
  ;  z++ Faire

    pz1 = pz + _size_z;

    Si _dessine_masque AlorsFait _image_masque->BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    px = 0;
    for(  x = Param._Zoom._xmin
    ;  x <= Param._Zoom._xmax
    ;  x++ Faire

      px1 = px+_size_x;

      Si (_image->GetFormat() != WT_RGB)&&
         (_image->GetFormat() != WT_RGBA)
      Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur.Set(
        (unsigned char) _image->VectValeurBuffer(0),
        (unsigned char) _image->VectValeurBuffer(1),
        (unsigned char) _image->VectValeurBuffer(2)
                               );
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) round(px) ,  
                          (int) round(pz),
                          (int) round(px1),
                          (int) round(pz1),
                          couleur);

      IncBuffer();
      px = px1;

    } // end for // x

    pz = pz1;

  } // end for // z

} // DessinePlanY()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanX( )
//                     ------------
{


     register int             y,z;
     register float           py,pz;
     register float           py1,pz1;
     register ClasseCouleur   couleur;

  // Dans le cas d'un masque
  Si _dessine_masque Et Param._option_traitement != OPTION_MIP Alors
    DessinePlanMasqueX();
    return;
  FinSi

  // Si interpolation lineaire:
  Si _interpole_image Alors
    DessinePlanInterpX();
    return;
  FinSi

  //--- On rajoute 1E-4 pour etre sur d'arrondir a la valeur superieure et d'eviter
  //--- un plantage
  CreeImage( IMAGE_ZY,
       (int) (Param._Zoom._zoom_size_z*_size_z+1E-4),
       (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));

  FixeImageCourante( IMAGE_ZY);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );
  InitBuffer( );

  pz = 0;
  Pour( z, Param._Zoom._zmin, Param._Zoom._zmax)

    pz1 = pz+_size_z;

    BufferPos( Param._pos._x, Param._Zoom._ymin, z);
    py = 0;

    Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

      py1 = py+_size_y;

      Si (_image->_format != WT_RGB)&&
          (_image->_format != WT_RGBA)
     Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur = ClasseCouleur(
        (unsigned short) _image->VectValeurBuffer(0),
        (unsigned short) _image->VectValeurBuffer(1),
        (unsigned short) _image->VectValeurBuffer(2)
                               );
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) round(pz),
                          (int) round(py),
                          (int) round(pz1),
                          (int) round(py1),
                          couleur);

      IncBuffer( _image->_tx);
      py = py1;

    FinPour // y

    pz = pz1;
  FinPour // z

} // DessinePlanX()


#define min(a,b) ( (a)<(b) ? (a) : (b))

//----------------------------------------------------------------
void DessinImageBase :: DessineCoupes( )
//                      -------------
{
     register int      x,y;
     register float        px, py; // position de dessin du pixel
     register int      planZ;
     register int      pos_x, pos_y; // position de l'image en x et y
     register int      nx, ny; // nombre de lignes et de colonnes
     register int      qx, qy; // position en ligne et en colonne
     register ClasseCouleur couleur;
     float     val,dimx,dimy;

  // Dans le cas d'un masque
  Si _dessine_masque Et Param._option_traitement != OPTION_MIP Alors
    DessineMasqueCoupes();
    return;
  FinSi

  //--- Calcul de la disposition des coupes ------------------
  // dimensions d'une image, on respecte le rappport dimx/dimy
  dimx = Param._Zoom._zoom_size_x*Param._dim._voxel_size_x;
  dimy = Param._Zoom._zoom_size_y*Param._dim._voxel_size_y;

  nx = (int) sqrt(1.0*(_largeur/dimx)/(_hauteur/dimy)*Param._Zoom._zoom_size_z);
  ny = (int) (Param._Zoom._zoom_size_z/nx);
  Si nx*ny < Param._Zoom._zoom_size_z AlorsFait nx++;
  Si nx*ny < Param._Zoom._zoom_size_z AlorsFait ny++;

  _size_x = (1.0 * _largeur / nx - 2.0) / dimx;
  _size_y = (1.0 * _hauteur / ny - 2.0) / dimy;
  val = min(_size_x,_size_y);
  _size_x = val * Param._dim._voxel_size_x;
  _size_y = val * Param._dim._voxel_size_y;

//  printf("nx %d ny %d sizeX %d sizeY %d \n",nx,ny,(int) _size_x,(int) _size_y);

  //--- Initialisation de l'image -------------------------------
  CreeImage( IMAGE_COUPES, (int) (nx*(2+_size_x*Param._Zoom._zoom_size_x)), (int) (ny*(2+_size_y*Param._Zoom._zoom_size_y)));

  FixeImageCourante( IMAGE_COUPES);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  FastImageRectangle( image_data, image_width,
                      0,     0,
                      GetImageWidth(IMAGE_COUPES)  - 1,
                      GetImageHeight(IMAGE_COUPES) - 1,
                      _tab_intensite_couleur[255]);

  //--- Dessin des coupes
  planZ = Param._Zoom._zmin;

  for(  qy = 0, pos_y = 0
  ;  (qy < ny) Et (planZ <= Param._Zoom._zmax)
  ;  qy++, pos_y += (int) (Param._Zoom._zoom_size_y*_size_y + 2) Faire

    for(  qx = 0, pos_x = 0
    ;  (qx < nx)  Et (planZ <= Param._Zoom._zmax)
    ;  qx++, pos_x += (int) (Param._Zoom._zoom_size_x*_size_x + 2) Faire


    py = 0;

    Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

      BufferPos( Param._Zoom._xmin, y, planZ);

      px = 0;

      Pour( x, Param._Zoom._xmin, Param._Zoom._xmax)
        Si (_image->_format != WT_RGB)&&(_image->_format != WT_RGBA)
        Alors
          couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
        Sinon
          couleur.Set(
        (unsigned char) _image->VectValeurBuffer(0),
        (unsigned char) _image->VectValeurBuffer(1),
        (unsigned char) _image->VectValeurBuffer(2)
                               );
        FinSi

        FastImageRectangle( image_data, image_width,
                            (int) round(px + pos_x),    
                            (int) round(py + pos_y),
                            (int) round(px + pos_x + _size_x),
                            (int) round(py + pos_y + _size_y), 
                            couleur);
        IncBuffer();
        px += _size_x;
      FinPour // x

      py += _size_y;
    FinPour // y

    planZ++;

    } // end for // qx
  } // end for // qy

} // DessineCoupes()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanMasqueZ( )
//                      ------------------
{
     register int             x,y;
     register float           px, py;
     register float           px1, py1;
     register ClasseCouleur   couleur;

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur superieure et d'eviter
  //--- un plantage
  Si _memorise_coupes_XY Alors
#if defined(__MOTIF__)
    //--- On verifie l'allocation des images avec les bonnes dimensions
    AlloueImagesXY( (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
                    (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
    //--- On utilise la coupe deja allouee
    _tab_ximage_data[IMAGE_XY]  = _tab_ximage_XY_data[ Param._pos._z];
    _tab_ximage[IMAGE_XY]       = _tab_ximage_XY[ Param._pos._z];
    //--- Si l'image est a jour, on sort de la fonction
    Si _image_XY_a_jour[ Param._pos._z] AlorsRetourne;
#endif
  Sinon
    CreeImage( IMAGE_XY,(int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
                        (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
  FinSi

  FixeImageCourante( IMAGE_XY);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );

  InitBuffer( );

  py = 0;
  for(  y = Param._Zoom._ymin
  ;  y  <= Param._Zoom._ymax
  ;  y++ Faire

    py1 = py + _size_y;

    Si _dessine_masque AlorsFait _image_masque->BufferPos( Param._Zoom._xmin, y, Param._pos._z);
    BufferPos( Param._Zoom._xmin, y, Param._pos._z);
    px = 0;
    for(  x = Param._Zoom._xmin
    ;  x  <= Param._Zoom._xmax
    ;  x++ Faire

      px1 = px + _size_x;

      Si  (_image->_format != WT_RGB)&&
          (_image->_format != WT_RGBA)
      Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur = ClasseCouleur(
        (unsigned short) _image->VectValeurBuffer(0),
        (unsigned short) _image->VectValeurBuffer(1),
        (unsigned short) _image->VectValeurBuffer(2)
                               );
      FinSi

      Si _dessine_masque Alors
        Si _image_masque->ValeurBuffer() > 127 Alors
          couleur = _couleur_masque;
        FinSi
        _image_masque->IncBuffer();
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) px,  (int) py,
                          (int) px1, (int) py1,
                          couleur);

      IncBuffer();
      px = px1;

    } // end for // x

    py = py1;

  } // end for // y

  //--- Si on memorise les coupes, on precise que cette coupe XY est a jour
  Si _memorise_coupes_XY AlorsFait
    _image_XY_a_jour[ Param._pos._z] = true;

} // DessinePlanMasqueZ()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanMasqueY( )
//                      ------------------
{
     register int            x, z;
     register float          px,pz;
     register float          px1,pz1;
     register ClasseCouleur  couleur;

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur superieure et d'eviter
  //--- un plantage
  CreeImage( IMAGE_XZ, (int) (Param._Zoom._zoom_size_x*_size_x+1E-4), (int) (Param._Zoom._zoom_size_z*_size_z+1E-4));

  FixeImageCourante( IMAGE_XZ);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );
  InitBuffer( );

  pz = 0;
  for(  z = Param._Zoom._zmin
  ;  z  <= Param._Zoom._zmax
  ;  z++ Faire

    pz1 = pz + _size_z;

    Si _dessine_masque AlorsFait _image_masque->BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    px = 0;
    for(  x = Param._Zoom._xmin
    ;  x <= Param._Zoom._xmax
    ;  x++ Faire

      px1 = px + _size_x;

      Si (_image->_format != WT_RGB)&&
          (_image->_format != WT_RGBA)
      Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur.Set(
        (unsigned char) _image->VectValeurBuffer(0),
        (unsigned char) _image->VectValeurBuffer(1),
        (unsigned char) _image->VectValeurBuffer(2)
                               );
      FinSi

      Si _dessine_masque Alors
        Si _image_masque->ValeurBuffer() > 127 Alors
          couleur = _couleur_masque;
        FinSi
        _image_masque->IncBuffer();
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) px, (int) pz,
                          (int) px1,(int) pz1,
                          couleur);

      IncBuffer();
      px = px1;

    } // end for // x

    pz = pz1;

  } // end for // z

} // DessinePlanMasqueY()


//------------------------------------------------------------
void DessinImageBase :: DessinePlanMasqueX( )
//                      ------------------
{
     register int             y,z;
     register float           py,pz;
     register float           py1,pz1;
     register ClasseCouleur   couleur;

  //--- On rajoute 1E-4 pour etre sur d'arrondir a la valeur superieure et d'eviter
  //--- un plantage
  CreeImage( IMAGE_ZY, (int) (Param._Zoom._zoom_size_z*_size_z+1E-4), (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));

  FixeImageCourante( IMAGE_ZY);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );
  InitBuffer( );

  pz = 0;
  for(  z = Param._Zoom._zmin
  ;  z <= Param._Zoom._zmax
  ;  z++ Faire

    pz1 = pz + _size_z;

    Si _dessine_masque AlorsFait _image_masque->BufferPos( Param._pos._x, Param._Zoom._ymin, z);
    BufferPos( Param._pos._x, Param._Zoom._ymin, z);
    py = 0;
    for(  y = Param._Zoom._ymin
    ;  y <= Param._Zoom._ymax
    ;  y++ Faire

      py1 = py + _size_y;

      Si  (_image->_format != WT_RGB) &&
          (_image->_format != WT_RGBA)
      Alors
        couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
      Sinon
        couleur.Set(
        (unsigned char) _image->VectValeurBuffer(0),
        (unsigned char) _image->VectValeurBuffer(1),
        (unsigned char) _image->VectValeurBuffer(2)
                               );
      FinSi

      Si _dessine_masque Alors
        Si _image_masque->ValeurBuffer() > 127 Alors
          couleur = _couleur_masque;
        FinSi
        _image_masque->IncBuffer( _image->_tx);
      FinSi

      FastImageRectangle( image_data, image_width,
                          (int) pz,  (int) py,
                          (int) pz1, (int) py1,
                          couleur);

      IncBuffer( _image->_tx);
      py = py1;

    } // end for // y

    pz = pz1;
  } // end for // z

} // DessinePlanMasqueX()


//----------------------------------------------------------------
void DessinImageBase :: DessineMasqueCoupes( )
//                      -------------------
{
     register int      x,y;
     register float        px, py; // position de dessin du pixel
     register int      planZ;
     register int      pos_x, pos_y; // position de l'image en x et y
     register int      nx, ny; // nombre de lignes et de colonnes
     register int      qx, qy; // position en ligne et en colonne
     register ClasseCouleur couleur;
     float     val,dimx,dimy;

  //--- Calcul de la disposition des coupes ------------------
  // dimensions d'une image, on respecte le rappport dimx/dimy
  dimx = Param._Zoom._zoom_size_x*Param._dim._voxel_size_x;
  dimy = Param._Zoom._zoom_size_y*Param._dim._voxel_size_y;

  nx = (int) sqrt(1.0*(_largeur/dimx)/(_hauteur/dimy)*Param._Zoom._zoom_size_z);
  ny = (int) (Param._Zoom._zoom_size_z/nx);
  Si nx*ny < Param._Zoom._zoom_size_z AlorsFait nx++;
  Si nx*ny < Param._Zoom._zoom_size_z AlorsFait ny++;

  _size_x = (1.0 * _largeur / nx - 2.0) / dimx;
  _size_y = (1.0 * _hauteur / ny - 2.0) / dimy;
  val = min(_size_x,_size_y);
  _size_x = val * Param._dim._voxel_size_x;
  _size_y = val * Param._dim._voxel_size_y;

//  printf("nx %d ny %d sizeX %d sizeY %d \n",nx,ny,(int) _size_x,(int) _size_y);

  //--- Initialisation de l'image -------------------------------
  CreeImage( IMAGE_COUPES, (int) (nx*(2+_size_x*Param._Zoom._zoom_size_x)), (int) (ny*(2+_size_y*Param._Zoom._zoom_size_y)));

  FixeImageCourante( IMAGE_COUPES);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  FastImageRectangle( image_data, image_width,
                      0,     0,
                      GetImageWidth(IMAGE_COUPES)  - 1,
                      GetImageHeight(IMAGE_COUPES) - 1,
                      _tab_intensite_couleur[255]);

  //--- Dessin des coupes
  planZ = Param._Zoom._zmin;

  for(  qy = 0, pos_y = 0
  ;  (qy < ny) Et (planZ <= Param._Zoom._zmax)
  ;  qy++, pos_y += (int) (Param._Zoom._zoom_size_y*_size_y + 2) Faire

    for(  qx = 0, pos_x = 0
    ;  (qx < nx)  Et (planZ <= Param._Zoom._zmax)
    ;  qx++, pos_x += (int) (Param._Zoom._zoom_size_x*_size_x + 2) Faire


    py = 0;

    Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

      Si _dessine_masque AlorsFait _image_masque->BufferPos( Param._Zoom._xmin, y, planZ);
      BufferPos( Param._Zoom._xmin, y, planZ);

      px = 0;

      Pour( x, Param._Zoom._xmin, Param._Zoom._xmax)
        Si  (_image->_format != WT_RGB)&&
            (_image->_format != WT_RGBA)
        Alors
          couleur = _tab_intensite_couleur[ IntensiteBuffer() ];
        Sinon
          couleur.Set(
            (unsigned char) _image->VectValeurBuffer(0),
            (unsigned char) _image->VectValeurBuffer(1),
            (unsigned char) _image->VectValeurBuffer(2)
                     );
        FinSi

        Si _dessine_masque Alors
          Si _image_masque->ValeurBuffer() > 127 Alors
            couleur = _couleur_masque;
          FinSi
          _image_masque->IncBuffer();
        FinSi

        FastImageRectangle( image_data, image_width,
                            (int) (px + pos_x),    (int) (py + pos_y),
                            (int) (px + pos_x + _size_x),
          (int) (py + pos_y + _size_y), couleur);
        IncBuffer();
        px += _size_x;
      FinPour // x

      py += _size_y;
    FinPour // y

    planZ++;

    } // end for // qx
  } // end for // qy

} // DessineMasqueCoupes()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanXIsoContour(
//                                ----------------------
     InrImage::ptr&            image,
     float                   seuil)
{
     register int        y,z;
     register float          val00,val10,val01,val11;
     register float          p1,p2,p3,p4;
     register float          pos_z, pos_y;

     int                    P1y,P1z,P2y,P2z,P3y,P3z,P4y,P4z;
     float                   S,f;


  image->InitBuffer();

  val01=val11=0; // initialize to avoid compilation warning

  Pour( z, Param._Zoom._zmin, Param._Zoom._zmax)

    image->BufferPos( Param._pos._x, Param._Zoom._ymin, z);
    Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

      val00 = val01;
      val10 = val11;
      Si (z > Param._Zoom._zmin) AlorsFait
        val01 = image->ValeurBuffer( -image->_tx*image->_ty )-seuil;
      val11 = image->ValeurBuffer()-seuil;

      Si (_image_masque == NULL) Ou
         ((*_image_masque)(Param._pos._x, y, z)>127) AlorsFait
      Si (y > Param._Zoom._ymin) Et (z > Param._Zoom._zmin) Alors

        p1 = InterpoleZero( val00, val01);
        p3 = InterpoleZero( val01, val11);
        p4 = InterpoleZero( val10, val11);
        p2 = InterpoleZero( val00, val10);

        pos_z = _tab_ximage_pos_x[IMAGE_ZY] +  (z-1 - Param._Zoom._zmin + 0.5)*_size_z;
        pos_y = _tab_ximage_pos_y[IMAGE_ZY] +  (y-1 - Param._Zoom._ymin + 0.5)*_size_y;

        P1z = (int) pos_z;
        P1y = (int) (pos_y+p1*_size_y);
        P2z = (int) (pos_z+p2*_size_z);
        P2y = (int) pos_y;
        P3z = (int) (pos_z+p3*_size_z);
        P3y = (int) (pos_y+   _size_y);
        P4z = (int) (pos_z+   _size_z);
        P4y = (int) (pos_y+p4*_size_y);

        // in the case of 4 points, resolve the ambiguity ...
        Si (p1!=-1)&&(p2!=-1)&&(p3!=-1)&&(p4!=-1) Alors

          S = val10+val01-val00-val11;

          Si fabs((double)S)<1E-10 Alors
            fprintf(stderr,"DessinImageBase::DessinePlanZIsoContour() \t fabsf(S) < 1E-10 \n");
          Sinon
            f = val00 + (val10-val00)*(val01-val00)/S;

            // If a and f have the same sign, connect a to d
            Si ((val00>0)Et(f>0)) Ou ((val00<0)Et(f<0)) Alors
          Ligne( P1z,P1y,P3z,P3y);
              Ligne( P2z,P2y,P4z,P4y);
            Sinon
          Ligne( P1z,P1y,P2z,P2y);
              Ligne( P3z,P3y,P4z,P4y);
            FinSi
          FinSi

        Sinon

      // otherwise, connect the 2 points found
          Si p1 != -1 Alors
            Si p2 != -1 AlorsFait Ligne( P1z,P1y,P2z,P2y);
            Si p3 != -1 AlorsFait Ligne( P1z,P1y,P3z,P3y);
            Si p4 != -1 AlorsFait Ligne( P1z,P1y,P4z,P4y);
          Autrement
          Si p2 != -1 Alors
            Si p4 != -1 AlorsFait Ligne( P2z,P2y,P4z,P4y);
            Si p3 != -1 AlorsFait Ligne( P2z,P2y,P3z,P3y);
          FinSi

          Si (p3 != -1) Et (p4 != -1) AlorsFait Ligne( P3z,P3y,P4z,P4y);

        FinSi

      FinSi

      image->IncBuffer( image->_tx);

    FinPour // y

  FinPour // z

} // DessinePlanXIsoContour()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanYIsoContour(
//                                ----------------------
     InrImage::ptr&            image,
     float                   seuil)
{
     register int            x,z;
     register float          val00,val10,val01,val11;
     register float          p1,p2,p3,p4;
     register float          pos_x, pos_z;

     int                    P1x,P1z,P2x,P2z,P3x,P3z,P4x,P4z;
     float                   S,f;


  image->InitBuffer();

  val10=val11=0; // initialize to avoid compilation warning

  Pour( z, Param._Zoom._zmin, Param._Zoom._zmax)

    image->BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    Pour( x, Param._Zoom._xmin, Param._Zoom._xmax)

      val00 = val10;
      val01 = val11;
      Si (z > Param._Zoom._zmin) AlorsFait
        val10 = image->ValeurBuffer( -image->_tx*image->_ty ) - seuil;
      val11 = image->ValeurBuffer() - seuil;

      Si (_image_masque == NULL) Ou
         ((*_image_masque)(x, Param._pos._y, z)>127) AlorsFait
      Si (x > Param._Zoom._xmin) Et (z > Param._Zoom._zmin) Alors

        p1 = InterpoleZero( val00, val01);
        p3 = InterpoleZero( val01, val11);
        p4 = InterpoleZero( val10, val11);
        p2 = InterpoleZero( val00, val10);

        pos_x = _tab_ximage_pos_x[IMAGE_XZ] +  (x-1 - Param._Zoom._xmin + 0.5)*_size_x;
        pos_z = _tab_ximage_pos_y[IMAGE_XZ] +  (z-1 - Param._Zoom._zmin + 0.5)*_size_z;

        P1x = (int) pos_x;
        P1z = (int) (pos_z+p1*_size_z);
        P2x = (int) (pos_x+p2*_size_x);
        P2z = (int) pos_z;
        P3x = (int) (pos_x+p3*_size_x);
        P3z = (int) (pos_z+   _size_z);
        P4x = (int) (pos_x+   _size_x);
        P4z = (int) (pos_z+p4*_size_z);

        // in the case of 4 points, resolve the ambiguity ...
        Si (p1!=-1)&&(p2!=-1)&&(p3!=-1)&&(p4!=-1) Alors

          S = val10+val01-val00-val11;

          Si fabs((double)S)<1E-10 Alors
            fprintf(stderr,"DessinImageBase::DessinePlanZIsoContour() \t fabsf(S) < 1E-10 \n");
          Sinon
            f = val00 + (val10-val00)*(val01-val00)/S;

            // If val00 and f have the same sign, connect a to d
            Si ((val00>0)Et(f>0)) Ou ((val00<0)Et(f<0)) Alors
          Ligne( P1x,P1z,P3x,P3z);
              Ligne( P2x,P2z,P4x,P4z);
            Sinon
          Ligne( P1x,P1z,P2x,P2z);
              Ligne( P3x,P3z,P4x,P4z);
            FinSi
          FinSi


        Sinon

      // otherwise, connect the 2 points found
          Si p1 != -1 Alors
            Si p2 != -1 AlorsFait Ligne( P1x,P1z,P2x,P2z);
            Si p3 != -1 AlorsFait Ligne( P1x,P1z,P3x,P3z);
            Si p4 != -1 AlorsFait Ligne( P1x,P1z,P4x,P4z);
          Autrement
          Si p2 != -1 Alors
            Si p4 != -1 AlorsFait Ligne( P2x,P2z,P4x,P4z);
            Si p3 != -1 AlorsFait Ligne( P2x,P2z,P3x,P3z);
          FinSi

          Si (p3 != -1) Et (p4 != -1) AlorsFait Ligne( P3x,P3z,P4x,P4z);

        FinSi
      FinSi

      image->IncBuffer();

    FinPour // x

  FinPour // z

} // DessinePlanYIsoContour()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanZIsoContour(
//                      ----------------------
     InrImage::ptr&            image,
     float                   seuil)
{
     register int            x,y;
     register float          val00,val10,val01,val11;
     register float          p1,p2,p3,p4;
     register float          pos_x, pos_y;

     int                    P1x,P1y,P2x,P2y,P3x,P3y,P4x,P4y;
     float                   S,f;


  image->InitBuffer();
  val10=val11=0; // initialize to avoid compilation warning

  Pour(y, Param._Zoom._ymin, Param._Zoom._ymax)

    image->BufferPos( Param._Zoom._xmin, y, Param._pos._z);

    Pour(x, Param._Zoom._xmin, Param._Zoom._xmax)

      val00 = val10;
      val01 = val11;
      Si (y > Param._Zoom._ymin) AlorsFait
        val10 = image->ValeurBuffer( -image->_tx ) - seuil;
      val11 = image->ValeurBuffer() - seuil;

      Si (_image_masque == NULL) Ou
         ((*_image_masque)(x, y, Param._pos._z)>127) AlorsFait
      Si (x > Param._Zoom._xmin) Et (y > Param._Zoom._ymin) Alors

        p1 = InterpoleZero( val00, val01);
        p3 = InterpoleZero( val01, val11);
        p4 = InterpoleZero( val10, val11);
        p2 = InterpoleZero( val00, val10);

        pos_x = _tab_ximage_pos_x[IMAGE_XY] +  (x-1 - Param._Zoom._xmin + 0.5)*_size_x;
        pos_y = _tab_ximage_pos_y[IMAGE_XY] +  (y-1 - Param._Zoom._ymin + 0.5)*_size_y;

        P1x = (int) pos_x;
        P1y = (int) (pos_y+p1*_size_y);
        P2x = (int) (pos_x+p2*_size_x);
        P2y = (int) pos_y;
        P3x = (int) (pos_x+p3*_size_x);
        P3y = (int) (pos_y+   _size_y);
        P4x = (int) (pos_x+   _size_x);
        P4y = (int) (pos_y+p4*_size_y);

        // in the case of 4 points, resolve the ambiguity ...
        Si (p1!=-1)&&(p2!=-1)&&(p3!=-1)&&(p4!=-1) Alors

          S = val10+val01-val00-val11;

          Si fabs((double)S)<1E-10 Alors
            fprintf(stderr,"DessinImageBase::DessinePlanZIsoContour() \t fabsf(S) < 1E-10 \n");
          Sinon
            f = val00 + (val10-val00)*(val01-val00)/S;

            // If val00 and f have the same sign, connect a to d
            Si ((val00>0)Et(f>0)) Ou ((val00<0)Et(f<0)) Alors
          Ligne( P1x,P1y,P3x,P3y);
              Ligne( P2x,P2y,P4x,P4y);
            Sinon
          Ligne( P1x,P1y,P2x,P2y);
              Ligne( P3x,P3y,P4x,P4y);
            FinSi
          FinSi

        Sinon

      // otherwise, connect the 2 points found
          Si p1 != -1 Alors
            Si p2 != -1 AlorsFait Ligne( P1x,P1y,P2x,P2y);
            Si p3 != -1 AlorsFait Ligne( P1x,P1y,P3x,P3y);
            Si p4 != -1 AlorsFait Ligne( P1x,P1y,P4x,P4y);
          Autrement
          Si p2 != -1 Alors
            Si p4 != -1 AlorsFait Ligne( P2x,P2y,P4x,P4y);
            Si p3 != -1 AlorsFait Ligne( P2x,P2y,P3x,P3y);
          FinSi

          Si (p3 != -1) Et (p4 != -1) AlorsFait Ligne( P3x,P3y,P4x,P4y);

        FinSi
      FinSi

      image->IncBuffer();

    FinPour // x

  FinPour // y

} // DessinePlanZIsoContour()


//----------------------------------------------------------------
void DessinImageBase::DessinePlanInterpZ( )
//                    ------------------
{
     register int            x,y,n,n2,i,j;
     register float          px, py;
     register ClasseCouleur  couleur;

  switch ( _interpole_subdivision ){
    case INTERP_SUB_2:   n = 2; break;
    case INTERP_SUB_3:   n = 3; break;
    case INTERP_SUB_4:   n = 4; break;
    case INTERP_SUB_8:   n = 8; break;
    case INTERP_SUB_MAX:
       n = (int) macro_max(_size_x, _size_y);
       Si n < 1 AlorsFait n = 1;
    break;
    default:
       cerr << "DessinImageBase::DessinePlanInterpZ() \t";
       cerr << " _interpole_subdivision a une valeur inconnue ... : ";
       cerr << _interpole_subdivision  << endl;
       n = 2;
  } // end switch

  n2 = (int) (n/2);

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur superieure et d'eviter
  //--- un plantage
  Si _memorise_coupes_XY Alors
#if defined(__MOTIF__)
    //--- On verifie l'allocation des images avec les bonnes dimensions
    AlloueImagesXY( (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
        (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
    //--- On utilise la coupe deja allouee
    _tab_ximage_data[IMAGE_XY] = _tab_ximage_XY_data[ Param._pos._z];
    _tab_ximage[IMAGE_XY] = _tab_ximage_XY[ Param._pos._z];
    //--- Si l'image est a jour, on sort de la fonction
    Si _image_XY_a_jour[ Param._pos._z] AlorsRetourne;
#endif
  Sinon
    CreeImage( IMAGE_XY,
               (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
         (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
  FinSi

  FixeImageCourante( IMAGE_XY);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );

  InitBuffer( );

  py = _size_y/2.0;
  Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

    Pour(j, -n2, n-1-n2)

    BufferPos( Param._Zoom._xmin, y, Param._pos._z);
    px = _size_x/2.0;
    Pour( x, Param._Zoom._xmin, Param._Zoom._xmax)

      Pour(i, -n2, n-1-n2)

        Si  (_image->_format != WT_RGB)&&
            (_image->_format != WT_RGBA)
        Alors
          couleur = _tab_intensite_couleur[ IntensiteBuffer(x+i*1.0/n,
                  y+j*1.0/n,
                  Param._pos._z) ];
        Sinon

          float R,G,B;
          R = _image->InterpLinIntensite(x+i*1.0/n, y+j*1.0/n, Param._pos._z, 0);
          G = _image->InterpLinIntensite(x+i*1.0/n, y+j*1.0/n, Param._pos._z, 1);
          B = _image->InterpLinIntensite(x+i*1.0/n, y+j*1.0/n, Param._pos._z, 2);
          couleur.Set((unsigned char) R,
                      (unsigned char) G,
                      (unsigned char) B);
        FinSi

        FastImageRectangle(
          image_data, image_width,
          (int) (px +  (i-0.5) *_size_x/n),
          (int) (py +  (j-0.5) *_size_y/n),
          (int) (px +  (i+0.5) *_size_x/n),
          (int) (py +  (j+0.5) *_size_y/n),
          couleur);

      FinPour // i

      px += _size_x;
      IncBuffer();
    FinPour // x

    FinPour // j

    py += _size_y;

  FinPour // y

  //--- Si on memorise les coupes, on precise que cette coupe XY est a jour
  Si _memorise_coupes_XY AlorsFait
    _image_XY_a_jour[ Param._pos._z] = true;

} // DessinePlanInterpZ()


//----------------------------------------------------------------
void DessinImageBase :: DessinePlanInterpY( )
//                                ------------------
{
     register int            x, z,n,n2,i,j;
     register float          px,pz;
     register ClasseCouleur  couleur;

  switch ( _interpole_subdivision ){
    case INTERP_SUB_2:   n = 2; break;
    case INTERP_SUB_3:   n = 3; break;
    case INTERP_SUB_4:   n = 4; break;
    case INTERP_SUB_8:   n = 8; break;
    case INTERP_SUB_MAX:
       n = (int) macro_max(_size_x, _size_z);
       Si n < 1 AlorsFait n = 1;
    break;
    default:
       cerr << "DessinImageBase::DessinePlanInterpY() \t";
       cerr << " _interpole_subdivision a une valeur inconnue ... : ";
       cerr << _interpole_subdivision  << endl;
       n = 2;
  } // end switch

  n2 = (int) (n/2);

  //--- On rajoute 1E-4 pour etre sur d'arrondir 0.99999 a la valeur superieure et d'eviter
  //--- un plantage
  CreeImage( IMAGE_XZ,
       (int) (Param._Zoom._zoom_size_x*_size_x+1E-4),
       (int) (Param._Zoom._zoom_size_z*_size_z+1E-4));

  FixeImageCourante( IMAGE_XZ);
  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  Si _dessine_masque AlorsFait _image_masque->InitBuffer( );
  InitBuffer( );

  pz = _size_z/2.0;
  Pour(z, Param._Zoom._zmin, Param._Zoom._zmax)

    BufferPos( Param._Zoom._xmin, Param._pos._y, z);
    Pour(j, -n2, n-1-n2)

    px = _size_x/2.0;
    Pour( x, Param._Zoom._xmin, Param._Zoom._xmax)

      Pour(i,-n2,n-1-n2)

        Si  (_image->_format != WT_RGB)&&
            (_image->_format != WT_RGBA)
        Alors
          couleur = _tab_intensite_couleur[ IntensiteBuffer(x+i*1.0/n,
                  Param._pos._y,
                  z+j*1.0/n ) ];
        Sinon
          couleur.Set(
              (unsigned char) _image->VectValeurBuffer(0),
              (unsigned char) _image->VectValeurBuffer(1),
              (unsigned char) _image->VectValeurBuffer(2)
          );
        FinSi

        FastImageRectangle(
          image_data, image_width,
          (int) (px + (i-0.5) *_size_x/n),
          (int) (pz + (j-0.5) *_size_z/n),
          (int) (px + (i+0.5) *_size_x/n),
          (int) (pz + (j+0.5) *_size_z/n),
          couleur);

      FinPour // i

      IncBuffer();
      px += _size_x;

    FinPour // x

    FinPour // j
    pz += _size_z;

  FinPour // z

} // DessinePlanInterpY()


//----------------------------------------------------------------
void DessinImageBase::DessinePlanInterpX( )
//                    ------------------
{
    register  int               y,z,n,n2,i,j;
    register  float             py,pz;
    register  ClasseCouleur     couleur;

  switch ( _interpole_subdivision ){
    case INTERP_SUB_2:   n = 2; break;
    case INTERP_SUB_3:   n = 3; break;
    case INTERP_SUB_4:   n = 4; break;
    case INTERP_SUB_8:   n = 8; break;
    case INTERP_SUB_MAX:
       n = (int) macro_max(_size_z, _size_y);
       Si n < 1 AlorsFait n = 1;
    break;
    default:
       cerr << "DessinImageBase::DessinePlanInterpX() \t";
       cerr << " _interpole_subdivision a une valeur inconnue ... : ";
       cerr << _interpole_subdivision  << endl;
       n = 2;
  } // end switch

  n2 = (int) (n/2);

  //--- On rajoute 1E-4 pour etre sur d'arrondir a la valeur superieure et d'eviter
  //--- un plantage
  CreeImage( IMAGE_ZY, (int) (Param._Zoom._zoom_size_z*_size_z+1E-4),
                       (int) (Param._Zoom._zoom_size_y*_size_y+1E-4));
  FixeImageCourante( IMAGE_ZY);

  if (!_current_slice.use_count()) {
    cerr  << "DessinImageBase::DessinePlanInterpX() \t pb with current slicer pointer "
          << endl;
    return;
  }

  register  rgb_color*        image_data  = (rgb_color*) _current_slice->GetData();
  register  int               image_width = _current_slice->GetWidth();

  InitBuffer( );

  pz = _size_z/2.0;
  Pour(z, Param._Zoom._zmin, Param._Zoom._zmax)

    BufferPos( Param._pos._x, Param._Zoom._ymin, z);

    Pour(j, -n2, n-1-n2)

    py = _size_y/2.0;
    Pour( y, Param._Zoom._ymin, Param._Zoom._ymax)

      Pour(i,-n2,n-1-n2)

        Si  (_image->_format != WT_RGB)&&
            (_image->_format != WT_RGBA)
        Alors
          couleur = _tab_intensite_couleur[ IntensiteBuffer( Param._pos._x,
                   y+i*1.0/n,
                   z+j*1.0/n
                   ) ];
        Sinon
          couleur.Set(
            (unsigned char) _image->VectValeurBuffer(0),
            (unsigned char) _image->VectValeurBuffer(1),
            (unsigned char) _image->VectValeurBuffer(2)
                      );
        FinSi

        FastImageRectangle(
          image_data, image_width,
          (int) (pz + (j-0.5) *_size_z/n),
          (int) (py + (i-0.5) *_size_y/n),
          (int) (pz + (j+0.5) *_size_z/n),
          (int) (py + (i+0.5) *_size_y/n),
          couleur);

      FinPour // i

      IncBuffer( _image->_tx);
      py += _size_y;

    FinPour // y

    FinPour // j
    pz += _size_z;

  FinPour // z

} // DessinePlanInterpX()


///
/// Draw a line in XY slice using (x,y) coordinates as input
///
void DessinImageBase :: DrawLineZ( float x1, float y1,
//                                  ---------
                 float x2, float y2)
{

     register float          pos_x1, pos_y1;
     register float          pos_x2, pos_y2;

     //  FixeParametresLigne( size, style, _cap_style, _join_style);
     //SetPenColor( _couleur_masque);
     //     printf(" DrawLineZ(%3.1f,%3.1f,%3.1f,%3.1f)\n",x1,y1,x2,y2);
    // TODO: check why we need +/- 0.5 and create coordinate conversion functions
     pos_x1 = _tab_ximage_pos_x[IMAGE_XY] +  (x1+0.5 - Param._Zoom._xmin )*_size_x;
     pos_y1 = _tab_ximage_pos_y[IMAGE_XY] +  (y1+0.5 - Param._Zoom._ymin )*_size_y;

     pos_x2 = _tab_ximage_pos_x[IMAGE_XY] +  (x2+0.5 - Param._Zoom._xmin )*_size_x;
     pos_y2 = _tab_ximage_pos_y[IMAGE_XY] +  (y2+0.5 - Param._Zoom._ymin )*_size_y;

     Ligne( (int) round(pos_x1),
            (int) round(pos_y1),
            (int) round(pos_x2),
            (int) round(pos_y2));

} // DrawLineZ()


// -------------------------------------------------------------------------
//
void DessinImageBase :: SetCoupe( int coupe)
//                                  ---------
{

  Param._pos._z = coupe;
  Si Param._pos._z > Param._Zoom._zmax
  AlorsFait
    Param._pos._z = Param._Zoom._zmax;

  Si Param._pos._z < Param._Zoom._zmin
  AlorsFait
    Param._pos._z = Param._Zoom._zmin;

  Param._MAJ._planXY = true;

  Paint( false);

} // SetCoupe()


// -------------------------------------------------------------------------
//
void DessinImageBase :: IncCoupe()
//                      ---------
{


    Point_3D<int> pt;
    int etat;

  CursorToImage(_souris_x, _souris_y, pt.x,pt.y,pt.z,etat);
  //  cout << pt << endl;
  Si etat != -1 Alors
    switch ( etat ){

      case IMAGE_XY:
         Param._pos._z++;
         Si Param._pos._z > Param._Zoom._zmax AlorsFait Param._pos._z = Param._Zoom._zmin;
   //         _param_dialog->UpdateParameter(_id_planZ);
         Param._MAJ._planXY = true;
      break;

      case IMAGE_XZ:
         Param._pos._y++;
         Si Param._pos._y > Param._Zoom._ymax AlorsFait Param._pos._y = Param._Zoom._ymin;
         Param._MAJ._planXZ = true;
      break;

      case IMAGE_ZY:
         Param._pos._x++;
         Si Param._pos._x > Param._Zoom._xmax AlorsFait Param._pos._x = Param._Zoom._xmin;
         Param._MAJ._planZY = true;
      break;

    } // end switch
    Paint( false);
  FinSi


} // IncCoupe()


// -------------------------------------------------------------------------
//
void DessinImageBase :: DecCoupe()
//                                  ---------
{

    Point_3D<int> pt;
    int etat;

  CursorToImage(_souris_x, _souris_y, pt.x,pt.y,pt.z,etat);
  //  cout << pt << endl;
  Si etat != -1 Alors
    switch ( etat ){

      case IMAGE_XY:
         Param._pos._z--;
         Si Param._pos._z <  Param._Zoom._zmin AlorsFait Param._pos._z = Param._Zoom._zmax;
         Param._MAJ._planXY = true;
      break;

      case IMAGE_XZ:
         Param._pos._y--;
         Si Param._pos._y < Param._Zoom._ymin AlorsFait Param._pos._y = Param._Zoom._ymax;
         Param._MAJ._planXZ = true;
      break;

      case IMAGE_ZY:
         Param._pos._x--;
         Si Param._pos._x < Param._Zoom._xmin AlorsFait Param._pos._x = Param._Zoom._xmax;
         Param._MAJ._planZY = true;
      break;

    } // end switch
    Paint( false);
  FinSi


} // DecCoupe()


// -------------------------------------------------------------------------
//
void DessinImageBase :: SwapMenuVisible()
//                                  ---------------
{
  // TODO

} // SwapMenuVisible();


// -------------------------------------------------------------------------
//
void DessinImageBase :: ShowHideStatusBar()
//                      ---------------
{
  GetStatusBar()->Show(!GetStatusBar()->IsShown());

} // ShowHideStatusBar();


// -------------------------------------------------------------------------
//
void DessinImageBase::OnChar(wxKeyEvent& event)
//                    ------
{
    switch( event.GetKeyCode() )
    {
      case WXK_ESCAPE:
        this->Close(true);
      break;

      case WXK_F3:
      case 'M':
      case 'm':        SwapMenuVisible();   break;

      case WXK_F2:
      case 'l':
      case 'L':        ShowHideStatusBar(); break;

      case 'x':
      case 'X':  // show/Hide ZY slice
      {
          int type;

        type = Param._type_coupe;
        Param._type_coupe = ((type+1) & (TYPE_COUPE_XY+1)) +
                            ((type+1) & (TYPE_COUPE_XZ+1));
        Si ((type+1) & (TYPE_COUPE_ZY+1)) == 0  AlorsFait
          Param._type_coupe += TYPE_COUPE_ZY+1;
        Param._type_coupe -= 1;
        cout << " type " <<  Param._type_coupe << endl;
        Param._MAJ.MAJCoupes();
        EffaceEcran( false);
        Paint();
      }
      break;

      case 'y':
      case 'Y':  // show/Hide XZ slice
      {
          int type;

        type = Param._type_coupe;
        Param._type_coupe = ((type+1) & (TYPE_COUPE_XY+1)) +
                            ((type+1) & (TYPE_COUPE_ZY+1));
        Si ((type+1) & (TYPE_COUPE_XZ+1)) == 0  AlorsFait
          Param._type_coupe += TYPE_COUPE_XZ+1;
        Param._type_coupe -= 1;
        cout << " type " <<  Param._type_coupe << endl;
        Param._MAJ.MAJCoupes();
        EffaceEcran( false);
        Paint();
      }
      break;

      case 'z':
      case 'Z':  // show/Hide XY slice
      {
        int type;

        type = Param._type_coupe;
        Param._type_coupe = ((type+1) & (TYPE_COUPE_XZ+1)) +
                            ((type+1) & (TYPE_COUPE_ZY+1));
        Si ((type+1) & (TYPE_COUPE_XY+1)) == 0  AlorsFait
          Param._type_coupe += TYPE_COUPE_XY+1;
        Param._type_coupe -= 1;
        cout << " type " <<  Param._type_coupe << endl;
        Param._MAJ.MAJCoupes();
        EffaceEcran( false);
        Paint();
      }
      break;

      case '+':
      case WXK_UP:
      case WXK_NUMPAD_UP:
      case WXK_NUMPAD_ADD:
      case WXK_ADD:       IncCoupe(); break;

      case '-':
      case WXK_DOWN:
      case WXK_NUMPAD_DOWN:
      case WXK_NUMPAD_SUBTRACT:
      case WXK_SUBTRACT:  DecCoupe(); break;

      default:
        Si _keypressed_callback != NULL Alors
/* TODO
          ((XtCallbackProc) _keypressed_callback)(_drawing_area,
              _keypressed_data,
              _key_event);
*/
        FinSi
        event.Skip();
        return;
    }



      /*
      // Touche I
      case 73:
        _interpole_image = Non(_interpole_image);
        Param._MAJ.MAJCoupes();
        Paint();
      break;
      */


} // OnChar()


/*
//----------------------------------------------------------------
void DessinImageBase :: CB_aide_HTML(  Widget, void* , void*)
//                                ------------
{

  Chaine commande;

  commande =  "netscape  -raise -remote 'OpenURL(";
  commande += "http://serdis.dis.ulpgc.es/~krissian/InrView1/InrView.html";
  commande += ",new-window)'";
  system( (char*) commande);

} // CB_aide_HTML()
*/

//----------------------------------------------------------------
void DessinImageBase :: CB_interpole(  wxCommandEvent& event)
//                                ------------
{


     DessinImageBase*    di = (DessinImageBase*) this;

  _interpole_image = menuOptions->IsChecked(ID_MenuOptions_Interp_Active);
  di->_wxm_interp_subdiv->ValueChanged(event);

  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_interpole()


//----------------------------------------------------------------
void DessinImageBase :: CB_curseur_visible( wxCommandEvent& event)
//                                ------------------
{


     DessinImageBase*    di = (DessinImageBase*) this;

  Param._curseur._visible = menuOptions->IsChecked(ID_MenuOptions_display_cursor);

//cout << "curseur_visible \n";
  di->Param._MAJ.MAJCoupes();
  di->Paint();

} // CB_curseur_visible()


