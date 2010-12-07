/**
 * C++ Interface: wrap_wxToolBar
 *
 * Description: wrapping wxToolBar
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
#include "wrap_wxVisualAttributes.h"
#include "wrap_wxToolBarToolBase.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxToolBar.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxToolBar>::CreateVar( ParamList* p)
{
  WrapClass_wxToolBar::wrap_wxToolBar construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxToolBar);
AMI_DEFINE_VARFROMSMTPTR(wxToolBar);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxToolBar>::CreateVar( wxToolBar* val, bool nodeleter)
{ 
  boost::shared_ptr<wxToolBar> obj_ptr(val,smartpointer_nodeleter<wxToolBar>());
  return AMILabType<wxToolBar>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxToolBar
//
Variable<AMIObject>::ptr WrapClass_wxToolBar::CreateVar( wxToolBar* sp)
{
  boost::shared_ptr<wxToolBar> di_ptr(
    sp,
    wxwindow_nodeleter<wxToolBar>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxToolBar>::CreateVar(
      new WrapClass_wxToolBar(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxToolBar::AddMethods(WrapClass<wxToolBar>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_SetToolSeparation( this_ptr);
      AddVar_FindToolForPosition( this_ptr);
      AddVar_SetToolShortHelp( this_ptr);
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_SetToolNormalBitmap( this_ptr);
      AddVar_SetToolDisabledBitmap( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* Type not available
      // Adding public member m_toolbar
      boost::shared_ptr<_GtkToolbar > var_m_toolbar_ptr(GetObj()->m_toolbar, smartpointer_nodeleter<_GtkToolbar >());
      if (var_m_toolbar_ptr.get()) {
        BasicVariable::ptr var_m_toolbar = AMILabType<_GtkToolbar >::CreateVarFromSmtPtr(var_m_toolbar_ptr);
        if (var_m_toolbar.get()) {
          var_m_toolbar->Rename("m_toolbar");
          context->AddVar(var_m_toolbar,context);
        }
      }
      */
      
      // Adding public member m_blockEvent
      boost::shared_ptr<bool > var_m_blockEvent_ptr(&GetObj()->m_blockEvent, smartpointer_nodeleter<bool >());
      if (var_m_blockEvent_ptr.get()) {
        BasicVariable::ptr var_m_blockEvent = AMILabType<bool >::CreateVarFromSmtPtr(var_m_blockEvent_ptr);
        if (var_m_blockEvent.get()) {
          var_m_blockEvent->Rename("m_blockEvent");
          context->AddVar(var_m_blockEvent,context);
        }
      }


  // Adding Bases

  // Add base parent wxToolBarBase
  boost::shared_ptr<wxToolBarBase > parent_wxToolBarBase(  boost::dynamic_pointer_cast<wxToolBarBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxToolBarBase = AMILabType<wxToolBarBase >::CreateVarFromSmtPtr(parent_wxToolBarBase);
  context->AddVar("wxToolBarBase",var_wxToolBarBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxToolBarBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxToolBarBase);
  context->AddDefault(obj_wxToolBarBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxToolBar::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxToolBar");
    WrapClass_wxToolBar::AddVar_wxToolBar_1(amiobject->GetContext());
  WrapClass_wxToolBar::AddVar_wxToolBar(amiobject->GetContext());
  WrapClass_wxToolBar::AddVar_wxToolBar_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxToolBar::AddVar_GetClassDefaultAttributes(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxToolBar::wxToolBar()
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_wxToolBar_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_wxToolBar_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxToolBar* _newobj = new wxToolBar();
  BasicVariable::ptr res = WrapClass_wxToolBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxToolBar::wxToolBar(...)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_wxToolBar::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_wxToolBar::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxToolBar::wrap_wxToolBar_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxToolBar::wrap_wxToolBar_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxToolBar::wxToolBar(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxTB_HORIZONTAL, wxString const & name = wxToolBarNameStr)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_wxToolBar_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:wxTB_HORIZONTAL)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxToolBarNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_wxToolBar_2::CallMember( ParamList* _p)
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

  long style_long = wxTB_HORIZONTAL;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxToolBarNameStr) );

  wxToolBar* _newobj = new wxToolBar(parent, id, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxToolBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxToolBar::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_static_GetClassDefaultAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'variant' (def:wxWINDOW_VARIANT_NORMAL)")
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_static_GetClassDefaultAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int variant_int = (int) wxWINDOW_VARIANT_NORMAL;;
  if (!get_val_param<int >(variant_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxWindowVariant variant = (wxWindowVariant) variant_int;

  wxVisualAttributes res =   wxToolBar::GetClassDefaultAttributes(variant);
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxToolBar::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxToolBarNameStr)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxToolBarNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxToolBarNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::SetMargins(int x, int y)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetMargins::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_SetMargins::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMargins(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::SetToolSeparation(int separation)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetToolSeparation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'separation'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_SetToolSeparation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int separation;
  if (!get_val_param<int >(separation,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetToolSeparation(separation);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxToolBarToolBase * wxToolBar::FindToolForPosition(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_FindToolForPosition::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type wxToolBarToolBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_FindToolForPosition::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  wxToolBarToolBase * res =   this->_objectptr->GetObj()->FindToolForPosition(x, y);
  BasicVariable::ptr res_var = WrapClass_wxToolBarToolBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::SetToolShortHelp(int id, wxString const & helpString)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetToolShortHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'helpString'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_SetToolShortHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > helpString_smtptr;
  if (!get_val_smtptr_param<wxString >(helpString_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & helpString = *helpString_smtptr;

  this->_objectptr->GetObj()->SetToolShortHelp(id, helpString);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::SetWindowStyleFlag(long int style)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetWindowStyleFlag::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
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
//  Wrapping of void wxToolBar::SetToolNormalBitmap(int id, wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetToolNormalBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_SetToolNormalBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetToolNormalBitmap(id, bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::SetToolDisabledBitmap(int id, wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_SetToolDisabledBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_SetToolDisabledBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bitmap = *bitmap_smtptr;

  this->_objectptr->GetObj()->SetToolDisabledBitmap(id, bitmap);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxToolBar::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxToolBar::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxToolBar::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxToolBar::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

