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
#include "wrap_wxClassInfo.h"


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
    wrap_wxControl1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;
  wxControl* _newobj = new wxControl();
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxControl::wxControl(...)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControl::
    wrap_wxControl::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxControl::wrap_wxControl1 m1;
  res = m1.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of Constructor wxControl::wxControl(wxWindow * parent, wxWindowID id, wxPoint const & pos, wxSize const & size, long int style, wxValidator const & validator, wxString const & name)
//---------------------------------------------------
void WrapClass_wxControl::
    wrap_wxControl2::SetParametersComments()
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
    wrap_wxControl2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxWindow> parent_smtptr;
  if (!get_val_smtptr_param<wxWindow>(parent_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassReturnEmptyVar;
  boost::shared_ptr<wxPoint> pos_smtptr;
  if (!get_val_smtptr_param<wxPoint>(pos_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxPoint& pos = *pos_smtptr;
  boost::shared_ptr<wxSize> size_smtptr;
  if (!get_val_smtptr_param<wxSize>(size_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxSize& size = *size_smtptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;
  boost::shared_ptr<wxValidator> validator_smtptr;
  if (!get_val_smtptr_param<wxValidator>(validator_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxValidator& validator = *validator_smtptr;
  boost::shared_ptr<wxString> name_smtptr;
  if (!get_val_smtptr_param<wxString>(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString& name = *name_smtptr;
  wxControl* _newobj = new wxControl(parent, id, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxControl::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxValidator

//---------------------------------------------------
//  Wrapping of bool wxControl::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos, wxSize const & size, long int style, wxValidator const & validator, wxString const & name)
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
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxWindow> parent_smtptr;
  if (!get_val_smtptr_param<wxWindow>(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();
  int id;
  if (!get_val_param<int>(id,_p,_n)) ClassHelpAndReturn;
  boost::shared_ptr<wxPoint> pos_smtptr;
  if (!get_val_smtptr_param<wxPoint>(pos_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint& pos = *pos_smtptr;
  boost::shared_ptr<wxSize> size_smtptr;
  if (!get_val_smtptr_param<wxSize>(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize& size = *size_smtptr;
  long style_long;
  if (!get_val_param<long>(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;
  boost::shared_ptr<wxValidator> validator_smtptr;
  if (!get_val_smtptr_param<wxValidator>(validator_smtptr,_p,_n)) ClassHelpAndReturn;
  wxValidator& validator = *validator_smtptr;
  boost::shared_ptr<wxString> name_smtptr;
  if (!get_val_smtptr_param<wxString>(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString& name = *name_smtptr;
  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, validator, name);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of void wxControl::SetLabel(wxString const & label)
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxString> label_smtptr;
  if (!get_val_smtptr_param<wxString>(label_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString& label = *label_smtptr;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

