/*
 *  ImageDraw_IsoContourParam.cpp
 *  AMILab
 */

#include "ImageDraw_IsoContourParam.h"

#include "DessinImage.hpp"
#include "Viewer3D.hpp"

#include "amilab_messages.h"

#define MAX_ISOCONTOURS 3

//----------------------------------------------------
ImageDraw_IsoContourParam::ImageDraw_IsoContourParam (DessinImage* parent): ParamPanel(parent, "Iso Contour")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Iso Contour Parameters"));
//  SetMinSize(wxSize(250,300));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_IsoContourParam::CreateParameters ()
{
  char boxname[200];
  std::vector<isocontour_info>* _isocontours = parent_class->Get_isocontours();
  unsigned char* _all_contours = parent_class->Get_all_contours();
  float* _val_min = parent_class->Get_val_min();
  float* _val_max = parent_class->Get_val_max();
  float* _step_contours = parent_class->Get_step_contours();
  float* _contours_winsize = parent_class->Get_contours_winsize();

  //=============

  for (int i = 0; i <= MAX_ISOCONTOURS-1; i++)
  {
    sprintf(boxname,"Contour %d param.:",i);
    BeginBox(boxname);
      BeginHorizontal();
        //------------- Dessin de l'isocontour ?
        AddBoolean( &_id_dessine_contour[i],
                                          &(*_isocontours)[i].visible,
                                          "Draw",
                          CaractereToggle);
        BooleanDefault( _id_dessine_contour[i],
                           (*_isocontours)[i].visible);
        ChangedValueCallback( _id_dessine_contour[i],
                             (void*) ImageDraw_IsoContourParam::CB_IsoContourVisible,
                             (void*) this);

        //---------------- Couleur
        AddColor( &_id_couleur_contour[i],
                      "Color",
                      &(*_isocontours)[i].color);
        if (i==0) {
          //------------- Draw all contours
          AddBoolean( &_id_all_contours,
                                          _all_contours,
                                          "all contours",
                                          CaractereToggle);

          BooleanDefault( _id_all_contours,
                                          *_all_contours);

          ChangedValueCallback( _id_all_contours,
                                  (void*) ImageDraw_IsoContourParam::CB_DessineIsoContour,
                                                 (void*) this);
        }
      EndHorizontal();

      ChangedValueCallback( _id_couleur_contour[i],
                           (void*) ImageDraw_IsoContourParam::CB_DessineIsoContour,
                           (void*) this);


      //-------------- Seuil de l'isocontour
      AddFloat( &_id_seuil_contour[i],
                      &(*_isocontours)[i].threshold,
                      "Threshold",
                      2,
                      "Iso contour threshold");
      FloatConstraints( _id_seuil_contour[i],
                      *_val_min, *_val_max, *_val_min);
      ChangedValueCallback( _id_seuil_contour[i],
                             (void*) ImageDraw_IsoContourParam::CB_DessineIsoContour,
                           (void*) this);


      if (i==0) {
        //-------------- Contours step
        AddFloat( &_id_step_contours,
                                       _step_contours,
                                        "Step",
                                        2,
                                        "Iso contour step");
        FloatConstraints( _id_step_contours,
                                          0, _val_max-_val_min,
                                          *_step_contours);
        ChangedValueCallback( _id_step_contours,
                             (void*) ImageDraw_IsoContourParam::CB_DessineIsoContour,
                                             (void*) this);

        //-------------- Contours Window Size
        AddFloat( &_id_contours_winsize,
                                       _contours_winsize,
                                        "Size",
                                        2,
                                        "Window size");
        FloatConstraints( _id_contours_winsize,
                                          0, _val_max-_val_min,
                                          *_contours_winsize);
        ChangedValueCallback( _id_contours_winsize,
                             (void*) ImageDraw_IsoContourParam::CB_DessineIsoContour,
                                             (void*) this);

        //-------------- Creation de l'isosurface
        BeginHorizontal();
          AddButton( &_id_isosurface,
                        "IsoSurface",
                        (void*) ImageDraw_IsoContourParam::CB_isosurface,
                        (void*) this);

          AddButton( &_id_use_compareimage_colors,
                        "Use Compare Colors",
                        (void*) ImageDraw_IsoContourParam::CB_UseCompareColors,
                        (void*) this);
        EndHorizontal();
      }

    EndBox();
  }

  for (int i = 0; i <= MAX_ISOCONTOURS-1; i++)
  {
    SetDragCallback(_id_seuil_contour[i],true);
  }

  for(int i = 0; i <= MAX_ISOCONTOURS-1; i++)
  {
    FixeVisible(_id_seuil_contour[i],
                   (*_isocontours)[i].visible);

    FixeVisible(_id_couleur_contour[i],
                   (*_isocontours)[i].visible);
  }

  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_IsoContourParam::CB_IsoContourVisible (void* cd)
{
  ImageDraw_IsoContourParam* _this = (ImageDraw_IsoContourParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  std::vector<isocontour_info>* _isocontours = di->Get_isocontours();
  //printf("CB_IsoContourVisible\n");
  for(int i = 0; i <= MAX_ISOCONTOURS-1; i++)
  {
    _this->FixeVisible(_this->_id_seuil_contour[i],
                        (*_isocontours)[i].visible);
    _this->FixeVisible(_this->_id_couleur_contour[i],
                        (*_isocontours)[i].visible);
  }

  _this->Layout();

  Param->_MAJ.MAJCoupes();
  di->Paint();
} // CB_IsoContourVisible()

//----------------------------------------------------
void ImageDraw_IsoContourParam::CB_DessineIsoContour (void* cd)
{
  ImageDraw_IsoContourParam* _this = (ImageDraw_IsoContourParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();

  Param->_MAJ.MAJCoupes();
  di->Paint();
} // CB_DessineIsoContour()

//----------------------------------------------------
void ImageDraw_IsoContourParam::CB_isosurface (void* cd)
{
  ImageDraw_IsoContourParam* _this = (ImageDraw_IsoContourParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  InrImage::ptr _image = di->Get_image();
  std::vector<isocontour_info>* _isocontours = di->Get_isocontours();
  std::vector<vectorfield_info>* _vector_fields = di->Get_vector_fields();
  
  static SurfacePoly::ptr isosurf_ptr;

  bool      init;
  InrImage* mask;

  if (!(di->Call_CheckGLWindow()))
  {
    di->CreateGLWindow();
    init = true;
  }
  else 
  {
    init = false;
  }

  mask = new InrImage(WT_UNSIGNED_CHAR,"isomask.inr.gz", _image.get());
  mask->InitBuffer();
  for (int z = 0; z <= mask->_tz-1; z++)
  {
    for (int y = 0; y <= mask->_ty-1; y++)
    {
      for (int x = 0; x <= mask->_tx-1; x++)
      {
        mask->FixeValeur(255*( (x >= Param->_Zoom._xmin) &&
               (x <= Param->_Zoom._xmax) &&
               (y >= Param->_Zoom._ymin) &&
               (y <= Param->_Zoom._ymax) &&
               (z >= Param->_Zoom._zmin) &&
               (z <= Param->_Zoom._zmax)
                         )
                    );
        mask->IncBuffer();
      }
    }
  }

  Viewer3D_ptr glwin =  di->Lock_GLWindow();
  // replacing the previous isosurface
  if (isosurf_ptr.use_count())
    glwin->GetCanvas()->RemoveSurface(isosurf_ptr);

  isosurf_ptr = glwin->GetCanvas()->CreeIsosurface(
      _image,
      (*_isocontours)[0].threshold,
      mask);

  if (init)
  {
    glwin->GetCanvas()->Normalize();
    glwin->GetCanvas()->Center();
  }

  if (!(*_vector_fields)[0].vector.expired())
    glwin->GetCanvas()->SetVectors1(
        InrImage::ptr((*_vector_fields)[0].vector));
  if (!(*_vector_fields)[1].vector.expired())
    glwin->GetCanvas()->SetVectors2(
        InrImage::ptr((*_vector_fields)[1].vector));

  glwin->Paint();

  delete mask;

} // CB_isosurface()

//----------------------------------------------------
void ImageDraw_IsoContourParam::CB_UseCompareColors (void* cd)
{
//  ImageDraw_IsoContourParam* _this = (ImageDraw_IsoContourParam*) cd;
//  if (!_this) {
//    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
//    return;
//  }
//  DessinImage*    di = (DessinImage*) _this->parent_class;
//  DessinImageParametres* Param = di->GetParam();

  
  /* deprecated
#ifndef _NO_GL_

    DessinImage*    di = (DessinImage*) cd;

  Si (!di->CheckGLWindow())       AlorsFait return;
  Si di->ComparisonNumber() == 0  AlorsFait return;

  Viewer3D_ptr glwin =  di->_GLWindow.lock();
  glwin->GetCanvas()->SetColors((di->GetCompareWindow(0))->GetImage().get(),
               (di->GetCompareWindow(0))->GetMinIntensity(),
               (di->GetCompareWindow(0))->GetMaxIntensity()
               );
  glwin->Paint();
#endif
*/
} // CB_UseCompareColors()

