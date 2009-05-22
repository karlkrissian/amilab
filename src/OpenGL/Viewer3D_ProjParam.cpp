

#include "Viewer3D.hpp"

#include "proj_ortho.xpm"
#include "proj_persp.xpm"


Viewer3D_ProjParam::Viewer3D_ProjParam(Viewer3D* parent): 
  ParamPanel(parent->GetParamBook(),"Proj")
{
  parent_class = parent;
  CreateParameters();
  SetToolTip(_T("Projection Parameters"));
}

void Viewer3D_ProjParam::CreateParameters()
{
  ami_wxGLCanvas* mc = parent_class->m_canvas;

  AddEnumeration( &_id_type_proj, 
                  2, 
                  &mc->_GLProjParam.type_proj , 
                  "Mode",
                  EnumPixmapButton,
                  "Projection Mode");
  AddEnumChoice( _id_type_proj,
      &_id_proj_ortho,
      "Orthogonal",
      proj_ortho_string);

  AddEnumChoice( _id_type_proj, 
                &_id_proj_persp,
                "Perspective",
                proj_persp_string);

  EnumerationDefaut( _id_type_proj, 
      mc->_GLProjParam.type_proj);
  ChangedValueCallback( _id_type_proj, 
    (void*) CB_proj_type, 
    (void*) parent_class);

  BeginBox("Limits");

    //-------------- Left Side 
    AddFloat( &_id_left, 
              &mc->_GLProjParam.left,
              "L",2,
              "Left side limit");
    FloatConstraints( _id_left, -2.0, 2.0, mc->_GLProjParam.left);
    ChangedValueCallback( _id_left,
              (void*) CB_proj_param, 
              (void*) parent_class);
  
  
    //-------------- Right Side 
    AddFloat( &_id_right, 
          &mc->_GLProjParam.right,
          "R",2,
          "Right side limit");
    FloatConstraints( _id_right, -2.0, 2.0, mc->_GLProjParam.right);
    ChangedValueCallback( _id_right,
                  (void*) CB_proj_param, 
                  (void*) parent_class);
  
    //-------------- Bottom Side 
    AddFloat( &_id_bottom, 
          &mc->_GLProjParam.bottom,
          "B",
          2,
          "Bottom limit");
    FloatConstraints( _id_bottom, -2.0, 2.0, mc->_GLProjParam.bottom);
    ChangedValueCallback( _id_bottom,
                (void*) CB_proj_param, 
                (void*) parent_class);
  
    //-------------- Top Side 
    AddFloat( &_id_top, 
          &mc->_GLProjParam.top,
          "T",2,
          "Top limit");
    FloatConstraints( _id_top, -2.0, 2.0, mc->_GLProjParam.top);
    ChangedValueCallback( _id_top,
                  (void*) CB_proj_param, 
                  (void*) parent_class);
  
    //-------------- Near Side 
    AddFloat( &_id_near, 
          &mc->_GLProjParam._near,
          "N",2,
          "Near Distance");
    FloatConstraints( _id_near, -20.0, 20.0, mc->_GLProjParam._near);
    ChangedValueCallback( _id_near,
                    (void*) CB_proj_param, 
                    (void*) parent_class);
  
    //-------------- Far Side 
    AddFloat( &_id_far, 
      &mc->_GLProjParam._far,
      "F",2,
      "Far Distance");
    FloatConstraints( _id_far, -2.0, 2.0, mc->_GLProjParam._far);
    ChangedValueCallback( _id_far,
                  (void*) CB_proj_param, 
                  (void*) parent_class);
  
  EndBox();

  //-------------- Basis Far Distance
  AddFloat( &_id_basis_far, 
      &mc->_GLProjParam.eye_distance,
      "Eye dist",2,
      "Eye to origin distance");

  FloatConstraints( _id_basis_far, 
      0.1, 20.0, 
      mc->_GLProjParam.eye_distance);
      ChangedValueCallback( _id_basis_far,
      (void*) CB_proj_param, 
      (void*) parent_class);

  //--------------
  EnleveBouttons();
  CreeDialogue( );

  FixeVisible( _id_basis_far,
	    (mc->_GLProjParam.type_proj==PROJ_PERSP));

  ReAfficheParametres();
  MAJ();

}


//------------------------------------------------------
void Viewer3D_ProjParam::CB_proj_type(  void* cd)
//                       ------------
{
  Viewer3D*  tgl = (Viewer3D*) cd;
  Viewer3D_ProjParam*  param = (Viewer3D_ProjParam*) tgl->_param_proj.get();

  ami_wxGLCanvas* glc = tgl->m_canvas;

  param->FixeVisible( param->_id_basis_far, 
      (glc->_GLProjParam.type_proj==PROJ_PERSP));

  param->ReAfficheParametres();
  //  tgl->_GLProjParam.SetProjection(tgl->_Tfar._translation[2]);
  glc->Paint();
} // CB_proj_type()


//--------------------------------------------------------
void Viewer3D_ProjParam::CB_proj_param(  void* cd)
//                       -------------
{
  Viewer3D*  tgl = (Viewer3D*) cd;
  ami_wxGLCanvas* glc = tgl->m_canvas;

  glc->Paint();
} // CB_proj_param()


