/**
 * C++ Interface: wrap_wxVTKRenderWindowInteractor
 *
 * Description: wrapping wxVTKRenderWindowInteractor
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
#include "wrap_wxWindow.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxString.h"
#include "wrap_wxVTKRenderWindowInteractor.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_wxClassInfo.h"
#include "wrap_vtkIndent.h"
#include "wrap_wxPaintEvent.h"
#include "wrap_wxMouseEvent.h"
#include "wrap_wxKeyEvent.h"
#include "wrap_wxSizeEvent.h"


#include "wrap_wxVTKRenderWindowInteractor.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxVTKRenderWindowInteractor>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_wxVTKRenderWindowInteractor::wrap_wxVTKRenderWindowInteractor construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxVTKRenderWindowInteractor);
AMI_DEFINE_VARFROMSMTPTR(wxVTKRenderWindowInteractor);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxVTKRenderWindowInteractor>::CreateVar( wxVTKRenderWindowInteractor* val, bool nodeleter)
{ 
  boost::shared_ptr<wxVTKRenderWindowInteractor> obj_ptr(val,smartpointer_nodeleter<wxVTKRenderWindowInteractor>());
  return AMILabType<wxVTKRenderWindowInteractor>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxVTKRenderWindowInteractor
//
Variable<AMIObject>::ptr WrapClass_wxVTKRenderWindowInteractor::CreateVar( wxVTKRenderWindowInteractor* sp)
{
  boost::shared_ptr<wxVTKRenderWindowInteractor> di_ptr(
    sp,
    wxwindow_nodeleter<wxVTKRenderWindowInteractor>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxVTKRenderWindowInteractor>::CreateVar(
      new WrapClass_wxVTKRenderWindowInteractor(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::AddMethods(WrapClass<wxVTKRenderWindowInteractor>::ptr this_ptr )
{
  
      // Add members from wxWindow
      boost::shared_ptr<WrapClass_wxWindow> parent_wxWindow(
        boost::dynamic_pointer_cast<WrapClass_wxWindow >(this_ptr));
      parent_wxWindow->AddMethods(parent_wxWindow);
      // Add members from vtkRenderWindowInteractor
      boost::shared_ptr<WrapClass_vtkRenderWindowInteractor>
        parent_vtkRenderWindowInteractor(        
          boost::dynamic_pointer_cast<WrapClass_vtkRenderWindowInteractor >(this_ptr));
      parent_vtkRenderWindowInteractor->AddMethods(parent_vtkRenderWindowInteractor);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_GetClassInfo( this_ptr);
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_Initialize( this_ptr);
      AddVar_Enable_1( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_Enable_2( this_ptr);
      AddVar_Disable( this_ptr);
      AddVar_Start( this_ptr);
      AddVar_UpdateSize( this_ptr);
      AddVar_CreateTimer( this_ptr);
      AddVar_DestroyTimer( this_ptr);
      AddVar_TerminateApp( this_ptr);
      AddVar_OnPaint( this_ptr);
/* The following types are missing: wxEraseEvent
      AddVar_OnEraseBackground( this_ptr);
*/
      AddVar_OnMotion( this_ptr);
      AddVar_OnButtonDown( this_ptr);
      AddVar_OnButtonUp( this_ptr);
      AddVar_OnEnter( this_ptr);
      AddVar_OnLeave( this_ptr);
      AddVar_OnKeyDown( this_ptr);
      AddVar_OnKeyUp( this_ptr);
      AddVar_OnChar( this_ptr);
/* The following types are missing: wxTimerEvent
      AddVar_OnTimer( this_ptr);
*/
      AddVar_OnSize( this_ptr);
      AddVar_OnMouseWheel( this_ptr);
      AddVar_Render( this_ptr);
      AddVar_SetRenderWhenDisabled( this_ptr);
      AddVar_GetStereo( this_ptr);
      AddVar_StereoOn( this_ptr);
      AddVar_StereoOff( this_ptr);
      AddVar_SetStereo( this_ptr);
      AddVar_SetUseCaptureMouse( this_ptr);
      AddVar_UseCaptureMouseOn( this_ptr);
      AddVar_UseCaptureMouseOff( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxVTKRenderWindowInteractor* _newobj = new wxVTKRenderWindowInteractor();
  BasicVariable::ptr res = WrapClass_wxVTKRenderWindowInteractor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor(...)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxVTKRenderWindowInteractor::wrap_wxVTKRenderWindowInteractor_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxVTKRenderWindowInteractor::wrap_wxVTKRenderWindowInteractor_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxVTKRenderWindowInteractor::wxVTKRenderWindowInteractor(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 262144, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:262144)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_wxVTKRenderWindowInteractor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 262144;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  wxVTKRenderWindowInteractor* _newobj = new wxVTKRenderWindowInteractor(parent, id, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxVTKRenderWindowInteractor::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of int wxVTKRenderWindowInteractor::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   wxVTKRenderWindowInteractor::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type wxVTKRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  wxVTKRenderWindowInteractor * res =   wxVTKRenderWindowInteractor::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_wxVTKRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::New()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type wxVTKRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxVTKRenderWindowInteractor * res =   wxVTKRenderWindowInteractor::New();
  BasicVariable::ptr res_var = WrapClass_wxVTKRenderWindowInteractor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxVTKRenderWindowInteractor::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxVTKRenderWindowInteractor::IsA(char const * type)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
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
//  Wrapping of wxVTKRenderWindowInteractor * wxVTKRenderWindowInteractor::NewInstance()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type wxVTKRenderWindowInteractor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxVTKRenderWindowInteractor * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_wxVTKRenderWindowInteractor::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
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
//  Wrapping of void wxVTKRenderWindowInteractor::Initialize()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Initialize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Initialize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Initialize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::Enable()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->Enable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxVTKRenderWindowInteractor::Enable(...)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxVTKRenderWindowInteractor::wrap_Enable_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxVTKRenderWindowInteractor::wrap_Enable_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxVTKRenderWindowInteractor::Enable(bool enable)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Enable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int enable_int;
  if (!get_val_param<int >(enable_int,_p,_n,true,true)) ClassReturnEmptyVar;
  bool enable = (bool) (enable_int>0.5);

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::Disable()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Disable::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Disable::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Disable();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::Start()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Start::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Start::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Start();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::UpdateSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_UpdateSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_UpdateSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpdateSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxVTKRenderWindowInteractor::CreateTimer(int timertype)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_CreateTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'timertype'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_CreateTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int timertype;
  if (!get_val_param<int >(timertype,_p,_n,true,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->CreateTimer(timertype);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxVTKRenderWindowInteractor::DestroyTimer()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_DestroyTimer::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_DestroyTimer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->DestroyTimer();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::TerminateApp()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_TerminateApp::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_TerminateApp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->TerminateApp();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnPaint(wxPaintEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnPaint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaintEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnPaint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPaintEvent > event_smtptr;
  if (!get_val_smtptr_param<wxPaintEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPaintEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnPaint(event);
  return BasicVariable::ptr();
}
/* The following types are missing: wxEraseEvent

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnEraseBackground(wxEraseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnEraseBackground::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEraseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnEraseBackground::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEraseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxEraseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEraseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnEraseBackground(event);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnMotion(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnMotion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnMotion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMotion(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnButtonDown(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnButtonDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnButtonDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnButtonDown(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnButtonUp(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnButtonUp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnButtonUp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnButtonUp(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnEnter(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnEnter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnEnter::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnEnter(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnLeave(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnLeave::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnLeave::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnLeave(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnKeyDown(wxKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnKeyDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnKeyDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnKeyDown(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnKeyUp(wxKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnKeyUp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnKeyUp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnKeyUp(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnChar(wxKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnChar(event);
  return BasicVariable::ptr();
}
/* The following types are missing: wxTimerEvent

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnTimer(wxTimerEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnTimer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxTimerEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnTimer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxTimerEvent > event_smtptr;
  if (!get_val_smtptr_param<wxTimerEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxTimerEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnTimer(event);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnSize(wxSizeEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizeEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizeEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSizeEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizeEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnSize(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::OnMouseWheel(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnMouseWheel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_OnMouseWheel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMouseWheel(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::Render()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_Render::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_Render::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Render();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::SetRenderWhenDisabled(int newValue)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetRenderWhenDisabled::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'newValue'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetRenderWhenDisabled::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int newValue;
  if (!get_val_param<int >(newValue,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRenderWhenDisabled(newValue);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxVTKRenderWindowInteractor::GetStereo()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_GetStereo::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_GetStereo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStereo();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::StereoOn()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_StereoOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_StereoOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::StereoOff()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_StereoOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_StereoOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->StereoOff();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::SetStereo(int capable)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetStereo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'capable'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetStereo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int capable;
  if (!get_val_param<int >(capable,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStereo(capable);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::SetUseCaptureMouse(int _arg)
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetUseCaptureMouse::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named '_arg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_SetUseCaptureMouse::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int _arg;
  if (!get_val_param<int >(_arg,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUseCaptureMouse(_arg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::UseCaptureMouseOn()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_UseCaptureMouseOn::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_UseCaptureMouseOn::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseCaptureMouseOn();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxVTKRenderWindowInteractor::UseCaptureMouseOff()
//---------------------------------------------------
void WrapClass_wxVTKRenderWindowInteractor::
    wrap_UseCaptureMouseOff::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVTKRenderWindowInteractor::
    wrap_UseCaptureMouseOff::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseCaptureMouseOff();
  return BasicVariable::ptr();
}

