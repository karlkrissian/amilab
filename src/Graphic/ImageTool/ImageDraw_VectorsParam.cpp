/*
 *  ImageDraw_VectorsParam.cpp
 *  AMILab
 */

#include "ImageDraw_VectorsParam.h"

#include "DessinImage.hpp"

#include "amilab_messages.h"


//----------------------------------------------------
ImageDraw_VectorsParam::ImageDraw_VectorsParam (DessinImage* parent): ParamPanel(parent, "Vectors")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Vectors Parameters"));
//  SetMinSize(wxSize(300,525));
  SetMinSize(GetEffectiveMinSize());
}

//----------------------------------------------------
void ImageDraw_VectorsParam::CreateParameters ()
{
  unsigned char* _display_vectors = parent_class->Get_display_vectors();
  int* _vector_distance_unit = parent_class->Get_vector_distance_unit();
  //int* _id_vector_screen_pixels = parent_class->Get_id_vector_screen_pixels();
  float* _taille_vecteur = parent_class->Get_taille_vecteur();
  int* _espacement_vecteur = parent_class->Get_espacement_vecteur();
  int* _vecteur_type = parent_class->Get_vecteur_type();
  int* _id_vecteur_direction = parent_class->Get_id_vecteur_direction();
  std::vector<vectorfield_info>* _vector_fields = parent_class->Get_vector_fields();

  BeginBox("First Vector Field");
    BeginHorizontal();
      //------------- Affichage des valeurs des vecteurs
      AddButton( &_id_print_vectors, "Print Vectors",
              (void*) ImageDraw_VectorsParam::CB_AfficheVecteurs,
              (void*) this);

      //------------- Affichage du champ de vecteurs
      AddBoolean( &_id_display_vectors,
                      _display_vectors,
                           "Display Vectors");
      BooleanDefault( _id_display_vectors, *_display_vectors);

      ChangedValueCallback( _id_display_vectors,
                         (void*) ImageDraw_VectorsParam::CB_taille_vecteurs,
                         (void*) this);
    EndHorizontal();


    //--------------
    AddEnumeration( &_id_vector_distance_unit, 2, _vector_distance_unit ,
                    "Vector unit");

    AddEnumChoice( _id_vector_distance_unit, &_id_vector_image_pixels,
                     "Image Pixels");
    AddEnumChoice( _id_vector_distance_unit,
                     &_id_vector_screen_pixels,
                     "Screen Pixels");
    EnumerationDefaut( _id_vector_distance_unit, _id_vector_image_pixels);

    ChangedValueCallback( _id_vector_distance_unit,
                      (void*) ImageDraw_VectorsParam::CB_taille_vecteurs, (void*) this);

    //--------------
    AddFloat( &_id_vecteurs_taille, _taille_vecteur, "Size", 2, "Vector size");
    FloatConstraints(    _id_vecteurs_taille, 0.01, 100, *_taille_vecteur);
    ChangedValueCallback( _id_vecteurs_taille,
                                          (void*) ImageDraw_VectorsParam::CB_taille_vecteurs, (void*) this);


    //--------------
    AddInteger( &_id_vecteurs_espacement, _espacement_vecteur, "Spacing", "Space between vectors");
    IntegerConstraints(    _id_vecteurs_espacement, 1, 20, *_espacement_vecteur);
    ChangedValueCallback( _id_vecteurs_espacement,
                                          (void*) ImageDraw_VectorsParam::CB_taille_vecteurs, (void*) this);


    //--------------
    AddEnumeration( &_id_vecteur_type, 3, _vecteur_type ,
                        "Vector type");

    AddEnumChoice( _id_vecteur_type, &_id_vecteur_fleche,
                        " Arrow");
    AddEnumChoice( _id_vecteur_type,
                      _id_vecteur_direction,
                      " Direction");
    AddEnumChoice( _id_vecteur_type,
                      &_id_vecteur_fleche_prop,
                      "Prop. arrow");
    EnumerationDefaut( _id_vecteur_type, _id_vecteur_fleche_prop);

    ChangedValueCallback( _id_vecteur_type,
                            (void*) ImageDraw_VectorsParam::CB_type_vecteur, (void*) this);

  EndBox();

  
  BeginBook();
    int vect_id;
    char name[100];

    vect_id = 0;
    std::vector<vectorfield_info>::iterator Iter;
    for (Iter  = _vector_fields->begin();
         Iter != _vector_fields->end()  ; Iter++, vect_id++ )
    //if (!(*Iter).vector.expired())
    {

      sprintf(name,"Vector %d",vect_id+1);
      vectorfield_info& vf = (*Iter);
      //BeginBox(name);
      AddPage(name);
      BeginHorizontal();
          //------------- Dessin du premier vecteur
          AddBoolean(
                  &(vf._id_affiche_vecteur),
                  &(vf.visible),
                  "Display");
          BooleanDefault(
                  vf._id_affiche_vecteur,
                  true);
          ChangedValueCallback(
                  vf._id_affiche_vecteur,
                  (void*) ImageDraw_VectorsParam::CB_taille_vecteurs,
                  (void*) this);

          //---------------- Color
          AddColor(
                  &(vf._id_couleur_vecteur),
                  "Color",
                  &vf.color,
                  "Vector color");

          ChangedValueCallback(
                  vf._id_couleur_vecteur,
                  (void*) ImageDraw_VectorsParam::CB_taille_vecteurs,
                  (void*) this);
      EndHorizontal();
      //EndBox();
    }
  EndBook();

  EnleveBouttons();
  CreeDialogue();
  MAJ();

}

//----------------------------------------------------
void ImageDraw_VectorsParam::CB_AfficheVecteurs (void* cd)
{
  ImageDraw_VectorsParam* _this = (ImageDraw_VectorsParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  std::vector<vectorfield_info>* _vector_fields = di->Get_vector_fields();
  
  int          x,y,z;
  int          x0=0,y0=0,z0=0;

  x = Param->_pos._x;
  y = Param->_pos._y;
  z = Param->_pos._z;

  if (Param->_option_traitement == OPTION_MIP)
  {
    di->Set_PosPoint( x,y, x0, y0, z0);
  }
  else
  {
    x0 = x; y0 = y; z0 = z;
  }

  cout << x0 << ";" << y0 << ";" << z0  << endl;

  int i = 0;
  std::vector<vectorfield_info>::iterator Iter;
  for (Iter  = _vector_fields->begin();
       Iter != _vector_fields->end()  ; Iter++,i++ )
  if (!(*Iter).vector.expired()) {
    vectorfield_info vf = (*Iter);
    if  (vf.visible) {
        InrImage::ptr v(vf.vector);
        cout << "Vector " << i << " :"
                << "x = " << v->GetValue(x0,y0,z0,0) << ";"
                << "y = " << v->GetValue(x0,y0,z0,1) << ";"
                << "z = " << v->GetValue(x0,y0,z0,2) << endl;
     }
  }

} // CB_AfficheVecteurs()

//----------------------------------------------------
void ImageDraw_VectorsParam::CB_taille_vecteurs (void* cd)
{
  ImageDraw_VectorsParam* _this = (ImageDraw_VectorsParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();
  unsigned char* _display_vectors = _this->parent_class->Get_display_vectors();

  Param->_MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();

  if (*_display_vectors) di->Call_DessineChampVecteurs( );
} // CB_taille_vecteurs()

//----------------------------------------------------
void ImageDraw_VectorsParam::CB_type_vecteur (void* cd)
{
  ImageDraw_VectorsParam* _this = (ImageDraw_VectorsParam*) cd;
  if (!_this) {
    CLASS_MESSAGE_STATIC(_this, "Invalid parameter");
    return;
  }
  DessinImage*    di = (DessinImage*) _this->parent_class;
  DessinImageParametres* Param = di->GetParam();

  Param->_MAJ.MAJCoupes();
  di->EffaceTousLesEcrans( false);
  di->Paint();
} // CB_type_vecteur()
