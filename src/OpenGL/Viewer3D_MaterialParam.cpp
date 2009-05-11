

#include "Viewer3D.hpp"


Viewer3D_MaterialParam::Viewer3D_MaterialParam(
  Viewer3D* parent): 
  ParamPanel(parent->GetParamBook(), "ObjMat")
{
  parent_class = parent;
  _object_number = 0;
  _current_object_visible = 1;
  SetToolTip(_T("Objects material properties"));
  CreateParameters();
}


void Viewer3D_MaterialParam::CreateParameters()
{
  //  ami_wxGLCanvas* mc = parent_class->m_canvas;

  //-------------- Object Number
  AddInteger( &_id_object_number,
                &_object_number,
                "Nb",
                "Object number");
  
  IntegerConstraints( _id_object_number,
	   0, 1,
	   _object_number);

  ChangedValueCallback( _id_object_number,
		 (void*) CB_object_number,
	         (void*) parent_class);


  BeginHorizontal();
  //-------------- Display Object
  AddBoolean( &_id_display_object, 
				  &_current_object_visible,
				  "On",
				  CaractereToggle,
          "Display object");

  BooleanDefault( _id_display_object, _current_object_visible);

  ChangedValueCallback( 
                     _id_display_object,
		     (void*) CB_material_update,
		     (void*) parent_class);



  //-------------- Enable ColorMaterial
  AddBoolean( &_id_colormaterial, 
				  &_GLMaterial_display._colormaterial,
				  "ColorMat",
				  CaractereToggle,
          "Use ColorMaterial mode");

  BooleanDefault( _id_colormaterial, _GLMaterial_display._colormaterial);

  ChangedValueCallback( 
                     _id_colormaterial,
		     (void*) CB_material_update,
		     (void*) parent_class);


  EndHorizontal();
  BeginBox("Material properties:");

  //-------------- ColorMaterial Mode
  AddEnumeration( &_id_colormaterial_mode,5, 
				      &_GLMaterial_display._colormaterial_mode,
				      "Mode");

  AddEnumChoice( _id_colormaterial_mode,
				    &_id_colormaterial_emission,
					   "Emission");

  AddEnumChoice( _id_colormaterial_mode,
				    &_id_colormaterial_ambient,
					   "Ambient");

  AddEnumChoice( _id_colormaterial_mode,
				    &_id_colormaterial_diffuse,
					   "Diffusion");

  AddEnumChoice( _id_colormaterial_mode,
				    &_id_colormaterial_specular,
					   "Specular");

  AddEnumChoice( _id_colormaterial_mode,
				    &_id_colormaterial_ambient_and_diffuse,
					   "Amb & Diff");

  ChangedValueCallback( 
                     _id_colormaterial_mode,
		     (void*) CB_material_update,
		     (void*) parent_class);

  BeginHorizontal(2);
    //-------------- Ambient
    AddColor( &_id_mat_ambient,
        "Ambient",
        &_GLMaterial_display._ambient,
        "Ambient Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_mat_ambient,
        (void*) CB_material_update,
        (void*) parent_class);
  
    //-------------- Diffuse
    AddColor( &_id_mat_diffuse,
            "Diffuse",
            &_GLMaterial_display._diffuse,
            "Diffuse Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_mat_diffuse,
            (void*) CB_material_update,
            (void*) parent_class);
  
  EndHorizontal();
  BeginHorizontal(2);
  
    //-------------- Specular
    AddColor( &_id_mat_specular,
          "Specular",
          &_GLMaterial_display._specular,
          "Specular Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_mat_specular,
        (void*) CB_material_update,
        (void*) parent_class);
  
    //-------------- Emission
    AddColor( &_id_mat_emission,
        "Emission",
        &_GLMaterial_display._emission,
        "Emission Color");
    // Set proportional position
    SetLastPositionProperties(1);
  
    ChangedValueCallback( _id_mat_emission,
      (void*) CB_material_update,
      (void*) parent_class);
  EndHorizontal();

  //-------------- Shininess
  AddFloat( &_id_mat_shininess, 
		   &_GLMaterial_display._shininess,
		   "Shin", 1, "Shininess");
  FloatConstraints( _id_mat_shininess, 
		0.0, 100.0,
		_GLMaterial_display._shininess);

  ChangedValueCallback( _id_mat_shininess,
			 (void*) CB_material_update,
			 (void*) parent_class);

  //-------------- Opacity
  AddFloat( &_id_mat_opacity, 
			   &_GLMaterial_display._opacity,
			   "Opac", 2, "Opacity");
  FloatConstraints( _id_mat_opacity, 
				0.0, 1.0,
				_GLMaterial_display._opacity);

  ChangedValueCallback( _id_mat_opacity,
					 (void*) CB_material_update,
					 (void*) parent_class);


  EndBox();

  //--------------
  EnleveBouttons();
  CreeDialogue( );

  MAJ();

  SetDragCallback(_id_mat_opacity);
  SetDragCallback(_id_mat_shininess);

}

//-------------------------------------------------
// Updates the GUI depending on the changes
// in the graphical objects
//
void Viewer3D_MaterialParam::UpdateGui()
{
  ami_wxGLCanvas* mcanv = parent_class->m_canvas;
  GLObject::ptr    current;

  // check for corrent _object_number
  _object_number = mcanv->GetCurrentObjectNum();

  int maxobj = mcanv->_globject.size()-1;
  if (maxobj<1) maxobj = 1;
  IntegerConstraints( _id_object_number,
	   0, maxobj,
	   _object_number);

  current = mcanv->_current_globject;
  if (current.use_count()) {
    _current_object_visible = current->Visible();
    _GLMaterial_display     = current->GetMaterial();
  }

  MAJ();

} // UpdateGui()


//----------------------------------------------------------------
void Viewer3D_MaterialParam::CB_object_number( void* cd)
//              ---------------
{
    Viewer3D*       tgl = (Viewer3D*) cd;
    Viewer3D_MaterialParam* _this = tgl->_param_material;
    ami_wxGLCanvas* mcanv = tgl->m_canvas;
    GLObject::ptr    current;
  
  _this->_object_number = mcanv->SetCurrentObject(_this->_object_number);

  current = mcanv->_current_globject;
  if (current.use_count()) {
    _this->_current_object_visible = current->Visible();
    _this->_GLMaterial_display     = current->GetMaterial();
  }

  _this->MAJ();

} // CB_object_number()


//----------------------------------------------------------------
void Viewer3D_MaterialParam::CB_material_update( void* cd)
//              ------------------
{
  Viewer3D* tgl = (Viewer3D*) cd;
  Viewer3D_MaterialParam* _this = tgl->_param_material;
  ami_wxGLCanvas* mcanv = tgl->m_canvas;
  GLObject::ptr   current;

  tgl->_param_material->RecupereValeurs( );

  current = mcanv->_current_globject;
  if (current.use_count()) {
    current->GetMaterial() = _this->_GLMaterial_display;
    current->SetVisible(_this->_current_object_visible);
 }

  mcanv->Paint();

} // CB_material_update()

