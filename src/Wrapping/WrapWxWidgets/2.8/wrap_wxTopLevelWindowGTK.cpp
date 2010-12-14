/**
 * C++ Interface: wrap_wxTopLevelWindowGTK
 *
 * Description: wrapping wxTopLevelWindowGTK
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxTopLevelWindowGTK.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxIcon_declared
  #define wxIcon_declared
  AMI_DECLARE_TYPE(wxIcon)
#endif
#ifndef wxIconBundle_declared
  #define wxIconBundle_declared
  AMI_DECLARE_TYPE(wxIconBundle)
#endif
#ifndef wxRegion_declared
  #define wxRegion_declared
  AMI_DECLARE_TYPE(wxRegion)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxTopLevelWindowGTK>::CreateVar( ParamList* p)
{
  WrapClass_wxTopLevelWindowGTK::wrap_wxTopLevelWindowGTK construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxTopLevelWindowGTK);
AMI_DEFINE_VARFROMSMTPTR(wxTopLevelWindowGTK);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxTopLevelWindowGTK>::CreateVar( wxTopLevelWindowGTK* val, bool nodeleter)
{ 
  boost::shared_ptr<wxTopLevelWindowGTK> obj_ptr(val,smartpointer_nodeleter<wxTopLevelWindowGTK>());
  return AMILabType<wxTopLevelWindowGTK>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxTopLevelWindowGTK
//
Variable<AMIObject>::ptr WrapClass_wxTopLevelWindowGTK::CreateVar( wxTopLevelWindowGTK* sp)
{
  boost::shared_ptr<wxTopLevelWindowGTK> di_ptr(
    sp,
    wxwindow_nodeleter<wxTopLevelWindowGTK>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxTopLevelWindowGTK>::CreateVar(
      new WrapClass_wxTopLevelWindowGTK(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::AddMethods(WrapClass<wxTopLevelWindowGTK>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_Maximize( this_ptr);
  AddVar_IsMaximized( this_ptr);
  AddVar_Iconize( this_ptr);
  AddVar_IsIconized( this_ptr);
  AddVar_SetIcon( this_ptr);
  AddVar_SetIcons( this_ptr);
  AddVar_Restore( this_ptr);
  AddVar_EnableCloseButton( this_ptr);
  AddVar_ShowFullScreen( this_ptr);
  AddVar_IsFullScreen( this_ptr);
  AddVar_SetShape( this_ptr);
  AddVar_RequestUserAttention( this_ptr);
  AddVar_SetWindowStyleFlag( this_ptr);
  AddVar_Show( this_ptr);
  AddVar_Raise( this_ptr);
  AddVar_IsActive( this_ptr);
  AddVar_SetTitle( this_ptr);
  AddVar_GetTitle( this_ptr);
  AddVar_SetTransparent( this_ptr);
  AddVar_CanSetTransparent( this_ptr);
  AddVar_AddGrab( this_ptr);
  AddVar_RemoveGrab( this_ptr);
  AddVar_IsGrabbed( this_ptr);
  AddVar_GtkOnSize( this_ptr);
  AddVar_OnInternalIdle( this_ptr);
  AddVar_SetIconizeState( this_ptr);
  AddVar_DoSetSizeHints( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxTopLevelWindowBase
  boost::shared_ptr<wxTopLevelWindowBase > parent_wxTopLevelWindowBase(  boost::dynamic_pointer_cast<wxTopLevelWindowBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxTopLevelWindowBase = AMILabType<wxTopLevelWindowBase >::CreateVarFromSmtPtr(parent_wxTopLevelWindowBase);
  context->AddVar("wxTopLevelWindowBase",var_wxTopLevelWindowBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxTopLevelWindowBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxTopLevelWindowBase);
  context->AddDefault(obj_wxTopLevelWindowBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxTopLevelWindowGTK_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxTopLevelWindowGTK");
    WrapClass_wxTopLevelWindowGTK::AddVar_wxTopLevelWindowGTK_1(amiobject->GetContext());
  WrapClass_wxTopLevelWindowGTK::AddVar_wxTopLevelWindowGTK(amiobject->GetContext());
  WrapClass_wxTopLevelWindowGTK::AddVar_wxTopLevelWindowGTK_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxTopLevelWindowGTK* _newobj = new wxTopLevelWindowGTK();
  BasicVariable::ptr res = WrapClass_wxTopLevelWindowGTK::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK(...)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxTopLevelWindowGTK::wrap_wxTopLevelWindowGTK_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxTopLevelWindowGTK::wrap_wxTopLevelWindowGTK_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxTopLevelWindowGTK::wxTopLevelWindowGTK(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_wxTopLevelWindowGTK_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  wxTopLevelWindowGTK* _newobj = new wxTopLevelWindowGTK(parent, id, title, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxTopLevelWindowGTK::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, title, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::Maximize(bool maximize = true)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Maximize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'maximize' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Maximize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool maximize = true;
  if (!get_val_param<bool >(maximize,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Maximize(maximize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::IsMaximized()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_IsMaximized::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_IsMaximized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsMaximized();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::Iconize(bool iconize = true)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Iconize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'iconize' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Iconize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool iconize = true;
  if (!get_val_param<bool >(iconize,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Iconize(iconize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::IsIconized()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_IsIconized::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_IsIconized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsIconized();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::SetIcon(wxIcon const & icon)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetIcon::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetIcon::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIcon const & icon = *icon_smtptr;

  this->_objectptr->GetObj()->SetIcon(icon);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::SetIcons(wxIconBundle const & icons)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetIcons::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconBundle, "parameter named 'icons'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetIcons::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIconBundle > icons_smtptr;
  if (!get_val_smtptr_param<wxIconBundle >(icons_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIconBundle const & icons = *icons_smtptr;

  this->_objectptr->GetObj()->SetIcons(icons);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::Restore()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Restore::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Restore::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Restore();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::EnableCloseButton(bool enable = true)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_EnableCloseButton::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'enable' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_EnableCloseButton::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool enable = true;
  if (!get_val_param<bool >(enable,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->EnableCloseButton(enable);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::ShowFullScreen(bool show, long int style = wxFULLSCREEN_ALL)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_ShowFullScreen::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:wxFULLSCREEN_ALL)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_ShowFullScreen::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  bool show;
  if (!get_val_param<bool >(show,_p,_n,true,false)) ClassHelpAndReturn;

  long style_long = wxFULLSCREEN_ALL;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  bool res =   this->_objectptr->GetObj()->ShowFullScreen(show, style);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::IsFullScreen()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_IsFullScreen::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_IsFullScreen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFullScreen();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::SetShape(wxRegion const & region)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetShape::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRegion, "parameter named 'region'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetShape::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRegion > region_smtptr;
  if (!get_val_smtptr_param<wxRegion >(region_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRegion const & region = *region_smtptr;

  bool res =   this->_objectptr->GetObj()->SetShape(region);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::RequestUserAttention(int flags = wxUSER_ATTENTION_INFO)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_RequestUserAttention::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxUSER_ATTENTION_INFO)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_RequestUserAttention::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int flags = wxUSER_ATTENTION_INFO;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RequestUserAttention(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetWindowStyleFlag::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetWindowStyleFlag(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::Show(bool show = true)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Show::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show' (def:true)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Show::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool show = true;
  if (!get_val_param<bool >(show,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Show(show);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::Raise()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_Raise::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_Raise::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Raise();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::IsActive()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_IsActive::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_IsActive::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsActive();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::SetTitle(wxString const & title)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetTitle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetTitle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  this->_objectptr->GetObj()->SetTitle(title);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxTopLevelWindowGTK::GetTitle()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_GetTitle::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_GetTitle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetTitle();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::SetTransparent(wxByte alpha)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetTransparent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetTransparent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char alpha;
  if (!get_val_param<unsigned char >(alpha,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetTransparent(alpha);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::CanSetTransparent()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_CanSetTransparent::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_CanSetTransparent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->CanSetTransparent();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::AddGrab()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_AddGrab::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_AddGrab::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddGrab();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::RemoveGrab()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_RemoveGrab::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_RemoveGrab::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveGrab();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxTopLevelWindowGTK::IsGrabbed()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_IsGrabbed::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_IsGrabbed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsGrabbed();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::GtkOnSize()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_GtkOnSize::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_GtkOnSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GtkOnSize();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::SetIconizeState(bool iconic)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_SetIconizeState::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'iconic'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_SetIconizeState::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool iconic;
  if (!get_val_param<bool >(iconic,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIconizeState(iconic);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxTopLevelWindowGTK::DoSetSizeHints(int minW, int minH, int maxW = wxDefaultCoord, int maxH = wxDefaultCoord, int incW = wxDefaultCoord, int incH = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxTopLevelWindowGTK::
    wrap_DoSetSizeHints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minW'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'minH'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'maxH' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incW' (def:wxDefaultCoord)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'incH' (def:wxDefaultCoord)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxTopLevelWindowGTK::
    wrap_DoSetSizeHints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  int minW;
  if (!get_val_param<int >(minW,_p,_n,true,false)) ClassHelpAndReturn;

  int minH;
  if (!get_val_param<int >(minH,_p,_n,true,false)) ClassHelpAndReturn;

  int maxW = wxDefaultCoord;
  if (!get_val_param<int >(maxW,_p,_n,false,false)) ClassHelpAndReturn;

  int maxH = wxDefaultCoord;
  if (!get_val_param<int >(maxH,_p,_n,false,false)) ClassHelpAndReturn;

  int incW = wxDefaultCoord;
  if (!get_val_param<int >(incW,_p,_n,false,false)) ClassHelpAndReturn;

  int incH = wxDefaultCoord;
  if (!get_val_param<int >(incH,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoSetSizeHints(minW, minH, maxW, maxH, incW, incH);
  return BasicVariable::ptr();
}

