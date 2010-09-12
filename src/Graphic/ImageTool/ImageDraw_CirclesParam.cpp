/*
 *  ImageDraw_CirclesParam.cpp
 *  AMILab
 */

#include "ImageDraw_CirclesParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_CirclesParam::ImageDraw_CirclesParam (DessinImage* parent): ParamPanel(parent, "Circles")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Circles Parameters"));
//  SetMinSize(wxSize(200,200));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_CirclesParam::CreateParameters ()
{
  
  float* _circles_min_radius = parent_class->Get_circles_min_radius();
  float* _circles_max_radius = parent_class->Get_circles_max_radius();
  unsigned char* _circles_fill = parent_class->Get_circles_fill();
  ClasseCouleur* _circles_positive_color = parent_class->Get_circles_positive_color();
  ClasseCouleur* _circles_negative_color = parent_class->Get_circles_negative_color();
  unsigned char* _circles_ON = parent_class->Get_circles_ON();

  //------------- Affichage du champ de cercles
  AddBoolean( &_id_circles_ON,
                 _circles_ON,
                 "Display Circles");
  BooleanDefault( _id_circles_ON, false);
  ChangedValueCallback( _id_circles_ON,
                        (void*) DessinImage::CB_redessine,
                        (void*) parent_class);

  BeginBox("Circles radius");
    //------------- Intervalle de rayons
    AddFloat( &_id_circles_min_radius,
                    _circles_min_radius,
                    "min",
                    2,
                    "Circles min radius");
    FloatConstraints(_id_circles_min_radius,
                     -2, 2,
                     *_circles_min_radius);
    ChangedValueCallback( _id_circles_min_radius,
                         (void*) DessinImage::CB_redessine,
                         (void*) parent_class);

    //--------------
    AddFloat( &_id_circles_max_radius,
                    _circles_max_radius,
                    "max",
                     2,
                     "Circles max radius");
    FloatConstraints(_id_circles_max_radius,
                     -2, 2,
                     *_circles_max_radius);
    ChangedValueCallback( _id_circles_max_radius,
                         (void*) DessinImage::CB_redessine,
                         (void*) parent_class);
  EndBox();
  //------------- Affichage du champ de cercles
  AddBoolean( &_id_circles_fill,
                 _circles_fill,
                       "Fill Circles");
  BooleanDefault( _id_circles_fill, false);
  ChangedValueCallback( _id_circles_fill,
                    (void*) DessinImage::CB_redessine,
                    (void*) parent_class);

  //---------------- Positive Color
  AddColor( &_id_circles_positive_color,
                  "Positive",
                  _circles_positive_color,
                  "Circles positive color");

  ChangedValueCallback( _id_circles_positive_color,
                    (void*) DessinImage::CB_redessine,
                    (void*) parent_class);

  //---------------- Negative Color
  AddColor( &_id_circles_negative_color,
                  "Negative",
                  _circles_negative_color,
                  "Circles negative color");

  ChangedValueCallback( _id_circles_negative_color,
                    (void*) DessinImage::CB_redessine,
                    (void*) parent_class);

  
    
  ReAfficheParametres();
  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

