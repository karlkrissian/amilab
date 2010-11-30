/**
 * C++ Interface: wrap_vtkRenderWindow
 *
 * Description: wrapping vtkRenderWindow
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_vtkRenderWindow.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkRenderer.h"
#include "wrap_vtkRendererCollection.h"
#include "wrap_vtkRenderWindowInteractor.h"


#include "wrap_vtkRenderWindow.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkRenderWindow>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkRenderWindow);
AMI_DEFINE_VARFROMSMTPTR(vtkRenderWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkRenderWindow>::CreateVar( vtkRenderWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkRenderWindow> obj_ptr(val,smartpointer_nodeleter<vtkRenderWindow>());
  return AMILabType<vtkRenderWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkRenderWindow
//
Variable<AMIObject>::ptr WrapClass_vtkRenderWindow::CreateVar( vtkRenderWindow* sp)
{
  boost::shared_ptr<vtkRenderWindow> di_ptr(
    sp,
    wxwindow_nodeleter<vtkRenderWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkRenderWindow>::CreateVar(
      new WrapClass_vtkRenderWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkRenderWindow::AddMethods(WrapClass<vtkRenderWindow>::ptr this_ptr )
{
  
      // Add members from vtkWindow
      WrapClass_vtkWindow::ptr parent_vtkWindow(        boost::dynamic_pointer_cast<WrapClass_vtkWindow >(this_ptr));
      parent_vtkWindow->AddMethods(parent_vtkWindow);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_AddRenderer( this_ptr);
      AddVar_RemoveRenderer( this_ptr);
      AddVar_HasRenderer( this_ptr);
      AddVar_GetRenderers( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_CopyResultFrame( this_ptr);
      AddVar_MakeRenderWindowInteractor( this_ptr);
      AddVar_SetCursorPosition( this_ptr);
      AddVar_SetCurrentCursor( this_ptr);
      AddVar_GetCurrentCursor( this_ptr);
      AddVar_GetFullScreen( this_ptr);
      AddVar_FullScreenOn( this_ptr);
      AddVar_FullScreenOff( this_ptr);
      AddVar_SetBorders( this_ptr);
      AddVar_GetBorders( this_ptr);
      AddVar_BordersOn( this_ptr);
      AddVar_BordersOff( this_ptr);
      AddVar_GetStereoCapableWindow( this_ptr);
      AddVar_StereoCapableWindowOn( this_ptr);
      AddVar_StereoCapableWindowOff( this_ptr);
      AddVar_SetStereoCapableWindow( this_ptr);
      AddVar_GetStereoRender( this_ptr);
      AddVar_SetStereoRender( this_ptr);
      AddVar_StereoRenderOn( this_ptr);
      AddVar_StereoRenderOff( this_ptr);
      AddVar_SetAlphaBitPlanes( this_ptr);
      AddVar_GetAlphaBitPlanes( this_ptr);
      AddVar_AlphaBitPlanesOn( this_ptr);
      AddVar_AlphaBitPlanesOff( this_ptr);
      AddVar_SetPointSmoothing( this_ptr);
      AddVar_GetPointSmoothing( this_ptr);
      AddVar_PointSmoothingOn( this_ptr);
      AddVar_PointSmoothingOff( this_ptr);
      AddVar_SetLineSmoothing( this_ptr);
      AddVar_GetLineSmoothing( this_ptr);
      AddVar_LineSmoothingOn( this_ptr);
      AddVar_LineSmoothingOff( this_ptr);
      AddVar_SetPolygonSmoothing( this_ptr);
      AddVar_GetPolygonSmoothing( this_ptr);
      AddVar_PolygonSmoothingOn( this_ptr);
      AddVar_PolygonSmoothingOff( this_ptr);
      AddVar_GetStereoType( this_ptr);
      AddVar_SetStereoType( this_ptr);
      AddVar_SetStereoTypeToCrystalEyes( this_ptr);
      AddVar_SetStereoTypeToRedBlue( this_ptr);
      AddVar_SetStereoTypeToInterlaced( this_ptr);
      AddVar_SetStereoTypeToLeft( this_ptr);
      AddVar_SetStereoTypeToRight( this_ptr);
      AddVar_SetStereoTypeToDresden( this_ptr);
      AddVar_SetStereoTypeToAnaglyph( this_ptr);
      AddVar_SetStereoTypeToCheckerboard( this_ptr);
      AddVar_GetStereoTypeAsString( this_ptr);
      AddVar_StereoUpdate( this_ptr);
      AddVar_StereoMidpoint( this_ptr);
      AddVar_StereoRenderComplete( this_ptr);
      AddVar_SetAnaglyphColorSaturation( this_ptr);
      AddVar_GetAnaglyphColorSaturationMinValue( this_ptr);
      AddVar_GetAnaglyphColorSaturationMaxValue( this_ptr);
      AddVar_GetAnaglyphColorSaturation( this_ptr);
      AddVar_SetAnaglyphColorMask_1( this_ptr);
      AddVar_SetAnaglyphColorMask( this_ptr);
      AddVar_SetAnaglyphColorMask_2( this_ptr);
      AddVar_GetAnaglyphColorMask_1( this_ptr);
      AddVar_GetAnaglyphColorMask( this_ptr);
      AddVar_GetAnaglyphColorMask_2( this_ptr);
      AddVar_SetSwapBuffers( this_ptr);
      AddVar_GetSwapBuffers( this_ptr);
      AddVar_SwapBuffersOn( this_ptr);
      AddVar_SwapBuffersOff( this_ptr);
      AddVar_GetZbufferDataAtPoint( this_ptr);
      AddVar_GetAAFrames( this_ptr);
      AddVar_SetAAFrames( this_ptr);
      AddVar_GetFDFrames( this_ptr);
      AddVar_SetFDFrames( this_ptr);
      AddVar_GetSubFrames( this_ptr);
      AddVar_SetSubFrames( this_ptr);
      AddVar_GetNeverRendered( this_ptr);
      AddVar_GetAbortRender( this_ptr);
      AddVar_SetAbortRender( this_ptr);
      AddVar_GetInAbortCheck( this_ptr);
      AddVar_SetInAbortCheck( this_ptr);
      AddVar_CheckAbortStatus( this_ptr);
      AddVar_GetIsPicking( this_ptr);
      AddVar_SetIsPicking( this_ptr);
      AddVar_IsPickingOn( this_ptr);
      AddVar_IsPickingOff( this_ptr);
      AddVar_CheckInRenderStatus( this_ptr);
      AddVar_ClearInRenderStatus( this_ptr);
      AddVar_SetDesiredUpdateRate( this_ptr);
      AddVar_GetDesiredUpdateRate( this_ptr);
      AddVar_GetNumberOfLayers( this_ptr);
      AddVar_SetNumberOfLayers( this_ptr);
      AddVar_GetNumberOfLayersMinValue( this_ptr);
      AddVar_GetNumberOfLayersMaxValue( this_ptr);
      AddVar_GetInteractor( this_ptr);
      AddVar_SetInteractor( this_ptr);
      AddVar_UnRegister( this_ptr);
      AddVar_SetForceMakeCurrent( this_ptr);
      AddVar_ReportCapabilities( this_ptr);
      AddVar_SupportsOpenGL( this_ptr);
      AddVar_IsDirect( this_ptr);
/* The following types are missing: vtkPainterDeviceAdapter
      AddVar_GetPainterDeviceAdapter( this_ptr);
*/
      AddVar_SetMultiSamples( this_ptr);
      AddVar_GetMultiSamples( this_ptr);
      AddVar_SetStencilCapable( this_ptr);
      AddVar_GetStencilCapable( this_ptr);
      AddVar_StencilCapableOn( this_ptr);
      AddVar_StencilCapableOff( this_ptr);
      AddVar_SetReportGraphicErrors( this_ptr);
      AddVar_GetReportGraphicErrors( this_ptr);
      AddVar_ReportGraphicErrorsOn( this_ptr);
      AddVar_ReportGraphicErrorsOff( this_ptr);



  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkRenderWindow::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkRenderWindow");
  
  // Static methods 
  WrapClass_vtkRenderWindow::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkRenderWindow::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkRenderWindow::AddVar_New(amiobject->GetContext());
  WrapClass_vtkRenderWindow::AddVar_GetRenderLibrary(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkRenderWindow::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindow * vtkRenderWindow::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkRenderWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkRenderWindow * res =   vtkRenderWindow::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindow * vtkRenderWindow::New()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindow * res =   vtkRenderWindow::New();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of char const * vtkRenderWindow::GetRenderLibrary()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_static_GetRenderLibrary::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_static_GetRenderLibrary::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   vtkRenderWindow::GetRenderLibrary();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindow * vtkRenderWindow::NewInstance()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindow * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindow::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::AddRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_AddRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_AddRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->AddRenderer(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::RemoveRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_RemoveRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_RemoveRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->RemoveRenderer(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::HasRenderer(vtkRenderer * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_HasRenderer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_HasRenderer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderer > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderer* param0 = param0_smtptr.get();

  int res =   this->_objectptr->GetObj()->HasRenderer(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRendererCollection * vtkRenderWindow::GetRenderers()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetRenderers::SetParametersComments()
{
  return_comments="returning a variable of type vtkRendererCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetRenderers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRendererCollection * res =   this->_objectptr->GetObj()->GetRenderers();
  BasicVariable::ptr res_var = WrapClass_vtkRendererCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::Render()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_Render::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_Render::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Render();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::CopyResultFrame()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_CopyResultFrame::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_CopyResultFrame::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CopyResultFrame();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindowInteractor * vtkRenderWindow::MakeRenderWindowInteractor()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_MakeRenderWindowInteractor::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_MakeRenderWindowInteractor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindowInteractor * res =   this->_objectptr->GetObj()->MakeRenderWindowInteractor();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetCursorPosition(int param0, int param1)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetCursorPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetCursorPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCursorPosition(param0, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetCurrentCursor(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetCurrentCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetCurrentCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCurrentCursor(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetCurrentCursor()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetCurrentCursor::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetCurrentCursor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCurrentCursor();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetFullScreen()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetFullScreen::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetFullScreen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFullScreen();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::FullScreenOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_FullScreenOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_FullScreenOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FullScreenOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::FullScreenOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_FullScreenOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_FullScreenOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->FullScreenOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetBorders(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetBorders::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetBorders::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBorders(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetBorders()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetBorders::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetBorders::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBorders();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::BordersOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_BordersOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_BordersOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BordersOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::BordersOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_BordersOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_BordersOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->BordersOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetStereoCapableWindow()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetStereoCapableWindow::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetStereoCapableWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStereoCapableWindow();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoCapableWindowOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoCapableWindowOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoCapableWindowOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoCapableWindowOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoCapableWindowOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoCapableWindowOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoCapableWindowOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoCapableWindowOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoCapableWindow(int capable)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoCapableWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'capable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoCapableWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int capable;
  if (!get_val_param<int >(capable,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoCapableWindow(capable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetStereoRender()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetStereoRender::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetStereoRender::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStereoRender();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoRender(int stereo)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'stereo'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int stereo;
  if (!get_val_param<int >(stereo,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoRender(stereo);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoRenderOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoRenderOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoRenderOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoRenderOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoRenderOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoRenderOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoRenderOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoRenderOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAlphaBitPlanes(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAlphaBitPlanes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAlphaBitPlanes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAlphaBitPlanes(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetAlphaBitPlanes()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAlphaBitPlanes::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAlphaBitPlanes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlphaBitPlanes();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::AlphaBitPlanesOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_AlphaBitPlanesOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_AlphaBitPlanesOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AlphaBitPlanesOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::AlphaBitPlanesOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_AlphaBitPlanesOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_AlphaBitPlanesOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AlphaBitPlanesOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetPointSmoothing(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetPointSmoothing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetPointSmoothing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPointSmoothing(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetPointSmoothing()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetPointSmoothing::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetPointSmoothing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPointSmoothing();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::PointSmoothingOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_PointSmoothingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_PointSmoothingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PointSmoothingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::PointSmoothingOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_PointSmoothingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_PointSmoothingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PointSmoothingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetLineSmoothing(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetLineSmoothing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetLineSmoothing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLineSmoothing(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetLineSmoothing()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetLineSmoothing::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetLineSmoothing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetLineSmoothing();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::LineSmoothingOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_LineSmoothingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_LineSmoothingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LineSmoothingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::LineSmoothingOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_LineSmoothingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_LineSmoothingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LineSmoothingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetPolygonSmoothing(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetPolygonSmoothing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetPolygonSmoothing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPolygonSmoothing(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetPolygonSmoothing()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetPolygonSmoothing::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetPolygonSmoothing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPolygonSmoothing();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::PolygonSmoothingOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_PolygonSmoothingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_PolygonSmoothingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PolygonSmoothingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::PolygonSmoothingOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_PolygonSmoothingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_PolygonSmoothingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PolygonSmoothingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetStereoType()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetStereoType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetStereoType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStereoType();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoType(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoType(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToCrystalEyes()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToCrystalEyes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToCrystalEyes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToCrystalEyes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToRedBlue()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToRedBlue::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToRedBlue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToRedBlue();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToInterlaced()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToInterlaced::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToInterlaced::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToInterlaced();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToLeft()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToLeft::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToLeft::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToLeft();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToRight()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToRight::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToRight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToRight();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToDresden()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToDresden::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToDresden::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToDresden();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToAnaglyph()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToAnaglyph::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToAnaglyph::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToAnaglyph();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStereoTypeToCheckerboard()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToCheckerboard::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStereoTypeToCheckerboard::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereoTypeToCheckerboard();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkRenderWindow::GetStereoTypeAsString()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetStereoTypeAsString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetStereoTypeAsString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->GetStereoTypeAsString();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoUpdate()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoUpdate::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoUpdate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoUpdate();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoMidpoint()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoMidpoint::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoMidpoint::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoMidpoint();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StereoRenderComplete()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StereoRenderComplete::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StereoRenderComplete::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoRenderComplete();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAnaglyphColorSaturation(float _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorSaturation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorSaturation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  float _arg;
  if (!get_val_param<float >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAnaglyphColorSaturation(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkRenderWindow::GetAnaglyphColorSaturationMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturationMinValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturationMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetAnaglyphColorSaturationMinValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkRenderWindow::GetAnaglyphColorSaturationMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturationMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturationMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetAnaglyphColorSaturationMaxValue();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of float vtkRenderWindow::GetAnaglyphColorSaturation()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturation::SetParametersComments()
{
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorSaturation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetAnaglyphColorSaturation();
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAnaglyphColorMask(int _arg1, int _arg2)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int _arg1;
  if (!get_val_param<int >(_arg1,_p,_n,true,true)) ClassReturnEmptyVar;

  int _arg2;
  if (!get_val_param<int >(_arg2,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAnaglyphColorMask(_arg1, _arg2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindow::SetAnaglyphColorMask(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindow::wrap_SetAnaglyphColorMask_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindow::wrap_SetAnaglyphColorMask_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAnaglyphColorMask(int * _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAnaglyphColorMask_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > _arg_smtptr;
  if (!get_val_smtptr_param<int >(_arg_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* _arg = _arg_smtptr.get();

  this->_objectptr->GetObj()->SetAnaglyphColorMask(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int * vtkRenderWindow::GetAnaglyphColorMask()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  int * res =   this->_objectptr->GetObj()->GetAnaglyphColorMask();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkRenderWindow::GetAnaglyphColorMask(...)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkRenderWindow::wrap_GetAnaglyphColorMask_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkRenderWindow::wrap_GetAnaglyphColorMask_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::GetAnaglyphColorMask(int * data)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAnaglyphColorMask_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<int > data_smtptr;
  if (!get_val_smtptr_param<int >(data_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* data = data_smtptr.get();

  this->_objectptr->GetObj()->GetAnaglyphColorMask(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetSwapBuffers(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetSwapBuffers::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetSwapBuffers::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSwapBuffers(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetSwapBuffers()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetSwapBuffers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetSwapBuffers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSwapBuffers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SwapBuffersOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SwapBuffersOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SwapBuffersOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SwapBuffersOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SwapBuffersOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SwapBuffersOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SwapBuffersOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SwapBuffersOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of float vtkRenderWindow::GetZbufferDataAtPoint(int x, int y)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetZbufferDataAtPoint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type float";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetZbufferDataAtPoint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  float res =   this->_objectptr->GetObj()->GetZbufferDataAtPoint(x, y);
  return AMILabType<float >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetAAFrames()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAAFrames::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAAFrames::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAAFrames();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAAFrames(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAAFrames::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAAFrames::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAAFrames(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetFDFrames()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetFDFrames::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetFDFrames::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFDFrames();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetFDFrames(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetFDFrames::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetFDFrames::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFDFrames(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetSubFrames()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetSubFrames::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetSubFrames::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSubFrames();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetSubFrames(int subFrames)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetSubFrames::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'subFrames'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetSubFrames::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int subFrames;
  if (!get_val_param<int >(subFrames,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetSubFrames(subFrames);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetNeverRendered()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetNeverRendered::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetNeverRendered::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNeverRendered();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetAbortRender()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetAbortRender::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetAbortRender::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAbortRender();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetAbortRender(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetAbortRender::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetAbortRender::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAbortRender(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetInAbortCheck()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetInAbortCheck::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetInAbortCheck::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetInAbortCheck();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetInAbortCheck(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetInAbortCheck::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetInAbortCheck::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetInAbortCheck(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::CheckAbortStatus()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_CheckAbortStatus::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_CheckAbortStatus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CheckAbortStatus();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetIsPicking()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetIsPicking::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetIsPicking::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIsPicking();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetIsPicking(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetIsPicking::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetIsPicking::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIsPicking(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::IsPickingOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_IsPickingOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_IsPickingOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IsPickingOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::IsPickingOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_IsPickingOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_IsPickingOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->IsPickingOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::CheckInRenderStatus()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_CheckInRenderStatus::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_CheckInRenderStatus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CheckInRenderStatus();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::ClearInRenderStatus()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_ClearInRenderStatus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_ClearInRenderStatus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ClearInRenderStatus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetDesiredUpdateRate(double param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetDesiredUpdateRate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetDesiredUpdateRate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double param0;
  if (!get_val_param<double >(param0,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDesiredUpdateRate(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of double vtkRenderWindow::GetDesiredUpdateRate()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetDesiredUpdateRate::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetDesiredUpdateRate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetDesiredUpdateRate();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetNumberOfLayers()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayers::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfLayers();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetNumberOfLayers(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetNumberOfLayers::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetNumberOfLayers::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNumberOfLayers(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetNumberOfLayersMinValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayersMinValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayersMinValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfLayersMinValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetNumberOfLayersMaxValue()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayersMaxValue::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetNumberOfLayersMaxValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfLayersMaxValue();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkRenderWindowInteractor * vtkRenderWindow::GetInteractor()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetInteractor::SetParametersComments()
{
  return_comments="returning a variable of type vtkRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetInteractor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkRenderWindowInteractor * res =   this->_objectptr->GetObj()->GetInteractor();
  BasicVariable::ptr res_var = WrapClass_vtkRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetInteractor(vtkRenderWindowInteractor * param0)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetInteractor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindowInteractor, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetInteractor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkRenderWindowInteractor > param0_smtptr;
  if (!get_val_smtptr_param<vtkRenderWindowInteractor >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkRenderWindowInteractor* param0 = param0_smtptr.get();

  this->_objectptr->GetObj()->SetInteractor(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_UnRegister::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetForceMakeCurrent()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetForceMakeCurrent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetForceMakeCurrent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetForceMakeCurrent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of char const * vtkRenderWindow::ReportCapabilities()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_ReportCapabilities::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_ReportCapabilities::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char const * res =   this->_objectptr->GetObj()->ReportCapabilities();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::SupportsOpenGL()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SupportsOpenGL::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SupportsOpenGL::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->SupportsOpenGL();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::IsDirect()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_IsDirect::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_IsDirect::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->IsDirect();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: vtkPainterDeviceAdapter

//---------------------------------------------------
//  Wrapping of vtkPainterDeviceAdapter * vtkRenderWindow::GetPainterDeviceAdapter()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetPainterDeviceAdapter::SetParametersComments()
{
  return_comments="returning a variable of type vtkPainterDeviceAdapter";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetPainterDeviceAdapter::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPainterDeviceAdapter * res =   this->_objectptr->GetObj()->GetPainterDeviceAdapter();
  return AMILabType<vtkPainterDeviceAdapter >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetMultiSamples(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetMultiSamples::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetMultiSamples::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMultiSamples(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetMultiSamples()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetMultiSamples::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetMultiSamples::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMultiSamples();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetStencilCapable(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetStencilCapable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetStencilCapable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStencilCapable(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetStencilCapable()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetStencilCapable::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetStencilCapable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStencilCapable();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StencilCapableOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StencilCapableOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StencilCapableOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StencilCapableOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::StencilCapableOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_StencilCapableOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_StencilCapableOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StencilCapableOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::SetReportGraphicErrors(int _arg)
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_SetReportGraphicErrors::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_SetReportGraphicErrors::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetReportGraphicErrors(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkRenderWindow::GetReportGraphicErrors()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_GetReportGraphicErrors::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_GetReportGraphicErrors::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetReportGraphicErrors();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::ReportGraphicErrorsOn()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_ReportGraphicErrorsOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_ReportGraphicErrorsOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReportGraphicErrorsOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkRenderWindow::ReportGraphicErrorsOff()
//---------------------------------------------------
void WrapClass_vtkRenderWindow::
    wrap_ReportGraphicErrorsOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkRenderWindow::
    wrap_ReportGraphicErrorsOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReportGraphicErrorsOff();
  return BasicVariable::ptr();
}

