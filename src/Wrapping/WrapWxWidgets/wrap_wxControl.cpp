/**
 * C++ Interface: wrap_wxControl
 *
 * Description: wrapping wxControl
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxControl.h"

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
#include "wrap_wxObject.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxControl>::CreateVar( ParamList* p)
{
  WrapClass_wxControl::wrap_wxControl construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxControl);

//
// static member for creating a variable from a pointer to wxControl
//
Variable<AMIObject>::ptr WrapClass_wxControl::CreateVar( wxControl* sp)
{
  boost::shared_ptr<wxControl> di_ptr(
    sp,
    wxwindow_nodeleter<wxControl>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxControl>::CreateVar(
      new WrapClass_wxControl(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxControl::wxControl()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl::CallMember( ParamList* _p)
{
  wxControl* _newobj = new wxControl();
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of Constructor wxControl::wxControl(wxWindow * parent, wxWindowID id, wxPoint & pos, wxSize & size, long int style, wxValidator & validator, wxString & name)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,_p,_n)) ClassHelpAndReturn;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxPoint* pos_ptr;
  if (!get_val_ptr_param<wxPoint>(pos_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_ptr;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  wxValidator* validator_ptr;
  if (!get_val_ptr_param<wxValidator>(validator_ptr,_p,_n)) ClassHelpAndReturn;
  wxValidator& validator = *validator_ptr;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  wxControl* _newobj = new wxControl(parent, id, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxControl::Create(wxWindow * parent, wxWindowID id, wxPoint & pos, wxSize & size, long int style, wxValidator & validator, wxString & name)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxWindow* parent;
  if (!get_val_ptr_param<wxWindow>(parent,_p,_n)) ClassHelpAndReturn;
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  wxPoint* pos_ptr;
  if (!get_val_ptr_param<wxPoint>(pos_ptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_ptr;
  wxSize* size_ptr;
  if (!get_val_ptr_param<wxSize>(size_ptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_ptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  wxValidator* validator_ptr;
  if (!get_val_ptr_param<wxValidator>(validator_ptr,_p,_n)) ClassHelpAndReturn;
  wxValidator& validator = *validator_ptr;
  wxString* name_ptr;
  if (!get_val_ptr_param<wxString>(name_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_ptr;
  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, validator, name);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of void wxControl::SetLabel(wxString & label)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* label_ptr;
  if (!get_val_ptr_param<wxString>(label_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_ptr;
  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxControl::GetLabel()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetLabel::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetLabel::CallMember( ParamList* _p)
{
  wxString res =   this->_objectptr->GetObj()->GetLabel();
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxVisualAttributes

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxControl::GetDefaultAttributes()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetDefaultAttributes::SetParametersComments()
{
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetDefaultAttributes::CallMember( ParamList* _p)
{
  wxVisualAttributes res =   this->_objectptr->GetObj()->GetDefaultAttributes();
  return AMILabType<wxVisualAttributes>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxControl::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}
/* The following types are missing: wxClassInfo

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxControl::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  return AMILabType<wxClassInfo>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxObject * wxControl::wxCreateObject()
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxCreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxCreateObject::CallMember( ParamList* _p)
{
  wxObject * res =   this->_objectptr->GetObj()->wxCreateObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

