

#include "Viewer3D.hpp"


Viewer3D_VectorsParam::Viewer3D_VectorsParam(Viewer3D* parent): ParamPanel(parent->GetParamBook(), "Vect")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Vector Field Parameters"));
}


void Viewer3D_VectorsParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;



  //--------------------------------------------------
  //  VECTOR TYPE
  //--------------------------------------------------

  AddEnumeration( &_id_vecttype, 
      2, 
      &mc->_GLParam._vector_type,
      "Type",
      EnumOptionMenu,
      "Vector Type");

  AddEnumChoice( _id_vecttype, 
	   &_id_vecttype_orient, "Orientation");
  AddEnumChoice( _id_vecttype, 
	   &_id_vecttype_dir, "Direction");
  EnumerationDefaut( _id_vecttype, 
	     mc->_GLParam._vector_type);
  ChangedValueCallback( _id_vecttype, 
		(void*) CB_recompute_allvect, 
		(void*) parent_class);


  //--------------------------------------------------
  //  VECTOR FIELD 1
  //--------------------------------------------------
  BeginBox("First Vector Fied");
    /*
      //-------------- Vector Field image
      AjouteNomFichier( &_id_vect1image, 
            &mc->_GLParam._vect1_image_name, 
            "Vect. Field");
    
      ContraintesNomFichier( _id_vect1image, "", ".", 
          "*.ami.gz");
    
      ChangedValueCallback( _id_vect1image, 		  
          (void*) Viewer3D_VectorsParam::CB_vect1_image,
          (void*) parent_class);
    */

    BeginHorizontal();
      //-------------- Display
      AddBoolean( &_id_display_vect1, 
            &mc->_GLParam._display_vect1,
            "Display",
            CaractereToggle,
            "Display Vector Field");
    
      BooleanDefault( _id_display_vect1, mc->_GLParam._display_vect1);
    
      ChangedValueCallback( 
                        _id_display_vect1,
            (void*) Viewer3D::CB_redessine,
            (void*) parent_class);
    
      //-------------- Color
      AddColor( &_id_vect1color,
            "Color",
            &mc->_GLParam._vect1_color);
    
      ChangedValueCallback( 
                            _id_vect1color,
          (void*) Viewer3D_VectorsParam::CB_recompute_vect1,
          (void*) parent_class);
    EndHorizontal();
  
    //-------------- Size
    AddFloat( &_id_vect1size,
              &mc->_GLParam._vect1_size,
              "Size",2,"Vector Size");
  
    FloatConstraints( _id_vect1size,
            0.0, 1.0,
            mc->_GLParam._vect1_size);
  
  
    ChangedValueCallback(
                    _id_vect1size,
        (void*) Viewer3D_VectorsParam::CB_recompute_vect1,
        (void*) parent_class);
  
    //-------------- Width
    AddInteger( &_id_vect1width,
          &mc->_GLParam._vect1_width,
          "Width", "Vector Width");
  
    IntegerConstraints( _id_vect1width,
            1, 10,
            mc->_GLParam._vect1_width);
  
  
    ChangedValueCallback(
                    _id_vect1width,
        (void*) Viewer3D_VectorsParam::CB_recompute_vect1,
        (void*) parent_class);
  
  EndBox();
  //--------------------------------------------------
  //  VECTOR FIELD 2
  //--------------------------------------------------
  BeginBox("Second Vector Fied");
  
  /*
  
    //-------------- Vector Field image
    AjouteNomFichier( &_id_vect2image, 
              &mc->_GLParam._vect2_image_name, 
              "Vect. Field");
  
    ContraintesNomFichier( _id_vect2image, "", ".", "*.inr.gz");
  
    ChangedValueCallback( _id_vect2image, 
    (void*) Viewer3D_VectorsParam::CB_vect2_image,
    (void*) parent_class);
  
  */
    BeginHorizontal();
      //-------------- Display
      AddBoolean( &_id_display_vect2, 
            &mc->_GLParam._display_vect2,
            "Display",
            CaractereToggle,
            "Display 2nd Vector Field");
    
      BooleanDefault( _id_display_vect2, mc->_GLParam._display_vect2);
    
      ChangedValueCallback( 
                        _id_display_vect2,
            (void*) Viewer3D::CB_redessine,
            (void*) parent_class);
    
      //-------------- Color
      AddColor( &_id_vect2color,
            "Color",
            &mc->_GLParam._vect2_color,
            "Set Vector Field Color");
    
      ChangedValueCallback( 
            _id_vect2color,
      (void*) Viewer3D_VectorsParam::CB_recompute_vect2,
      (void*) parent_class);
    EndHorizontal();

    //-------------- Size
    AddFloat( &_id_vect2size,
              &mc->_GLParam._vect2_size,
              "Size",2,"Vector Field Size");
  
    FloatConstraints( _id_vect2size,
            0.0, 1.0,
            mc->_GLParam._vect2_size);
  
  
    ChangedValueCallback(
          _id_vect2size,
          (void*) Viewer3D_VectorsParam::CB_recompute_vect2,
          (void*) parent_class);
  
    //-------------- Width
    AddInteger( &_id_vect2width,
          &mc->_GLParam._vect2_width,
          "Width", "Vector Field Width");
  
    IntegerConstraints( _id_vect2width,
            1, 10,
            mc->_GLParam._vect2_width);
  
  
    ChangedValueCallback(
            _id_vect2width,
      (void*) Viewer3D_VectorsParam::CB_recompute_vect2,
      (void*) parent_class);
  
  EndBox();

  //--------------
  EnleveBouttons();
  CreeDialogue( );

  MAJ();


}


//----------------------------------------------------------------
void Viewer3D_VectorsParam::CB_vect1_image( void* cd)
//                          --------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

   InrImage::ptr  im;

   // should be a lock with weak pointers
   GLObject::ptr current = glc->_current_globject;
   if (!current.use_count()) return;

   SurfacePoly*    surf_poly = (SurfacePoly*) current.get();
  
  if (surf_poly==NULL) return;

  try {
    im = InrImage::ptr(new InrImage( (char*)glc->_GLParam._vect1_image_name.c_str()));
  }
  catch (InrImage::ErreurLecture) {
    cerr << "Error in reading file " << glc->_GLParam._vect1_image_name << endl;
    im = InrImage::ptr();
  }

  Si (im.use_count()) Alors
    Si (im->VectorialFormat()) Alors
      glc->_GLParam.SetVector(1,im);
      surf_poly->NewVectors1();
      glc->Paint();
    Sinon
      cerr << " Image not vectorial " << endl;
    FinSi
  FinSi

} // CB_vect1_image()


//----------------------------------------------------------------
void Viewer3D_VectorsParam :: CB_vect2_image( void* cd)
//                       --------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

    InrImage::ptr  im;

   // should be a lock with weak pointers
   GLObject::ptr current = glc->_current_globject;
   if (!current.use_count()) return;

   SurfacePoly*    surf_poly = (SurfacePoly*) current.get();

  if (surf_poly==NULL) return;

  try {
    im = InrImage::ptr(new InrImage( (char*)glc->_GLParam._vect2_image_name.c_str()));
  }
  catch (InrImage::ErreurLecture) {
    cerr << "Error in reading file " << glc->_GLParam._vect2_image_name << endl;
    im = InrImage::ptr();
  }

  Si (im.use_count()) Alors
    Si (im->VectorialFormat()) Alors
      glc->_GLParam.SetVector(2,im);
      surf_poly->NewVectors2();
      glc->Paint();
    Sinon
      cerr << " Image not vectorial " << endl;
    FinSi
  FinSi

} // CB_vect2_image()


//--------------------------------------------------------
void Viewer3D_VectorsParam::CB_recompute_allvect( void* cd )
//                          --------------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

   // should be a lock with weak pointers
   GLObject::ptr current = glc->_current_globject;
   if (!current.use_count()) return;

   SurfacePoly*    surf_poly = (SurfacePoly*) current.get();

  if (surf_poly==NULL) return;

  surf_poly->NewVectors1();
  surf_poly->NewVectors2();
  glc->Paint();

} //  CB_recompute_allvect()


//----------------------------------------------------------------
void Viewer3D_VectorsParam :: CB_recompute_vect1( void* cd )
//                       ------------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

  GLObject::ptr current = glc->_current_globject;
  if (!current.use_count()) return;

   SurfacePoly*    surf_poly = (SurfacePoly*) current.get();

  if (surf_poly==NULL) return;

  surf_poly->NewVectors1();
  glc->Paint();

} //  CB_recompute_vect1()


//----------------------------------------------------------------
void Viewer3D_VectorsParam :: CB_recompute_vect2( void* cd )
//                       ------------------
{
   Viewer3D*  tgl = (Viewer3D*) cd;
   ami_wxGLCanvas* glc = tgl->m_canvas;

  GLObject::ptr current = glc->_current_globject;
  if (!current.use_count()) return;

   SurfacePoly*    surf_poly = (SurfacePoly*) current.get();

  if (surf_poly==NULL) return;
  surf_poly->NewVectors2();
  glc->Paint();

} //  CB_recompute_vect2()

