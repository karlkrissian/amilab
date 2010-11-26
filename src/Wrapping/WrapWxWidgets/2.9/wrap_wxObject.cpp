/**
 * C++ Interface: wrap_wxObject
 *
 * Description: wrapping wxObject
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxObject.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxObject.h"
#include "wrap_wxClassInfo.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxObject>::CreateVar( ParamList* p)
{
  WrapClass_wxObject::wrap_wxObject construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxObject);

//
// static member for creating a variable from a pointer to wxObject
//
Variable<AMIObject>::ptr WrapClass_wxObject::CreateVar( wxObject* sp)
{
  boost::shared_ptr<wxObject> di_ptr(
    sp,
    wxwindow_nodeleter<wxObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObject>::CreateVar(
      new WrapClass_wxObject(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxObject::wxObject()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_wxObject::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_wxObject::CallMember( ParamList* _p)
{
  wxObject* _newobj = new wxObject();
  BasicVariable::ptr res = WrapClass_wxObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObject::wxObject(wxObject & other)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_wxObject1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'other'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_wxObject1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxObject* other_ptr;
  if (!get_val_ptr_param<wxObject>(other_ptr,_p,_n)) ClassHelpAndReturn;
  wxObject& other = *other_ptr;
  wxObject* _newobj = new wxObject(other);
  BasicVariable::ptr res = WrapClass_wxObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxObject::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxObject::IsKindOf(wxClassInfo * info)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_IsKindOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_IsKindOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxClassInfo* info;
  if (!get_val_ptr_param<wxClassInfo>(info,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->IsKindOf(info);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxObjectRefData

//---------------------------------------------------
//  Wrapping of wxObjectRefData * wxObject::GetRefData()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_GetRefData::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectRefData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_GetRefData::CallMember( ParamList* _p)
{
  wxObjectRefData * res =   this->_objectptr->GetObj()->GetRefData();
  return AMILabType<wxObjectRefData>::CreateVar(res);
}
*/
/* The following types are missing: wxObjectRefData

//---------------------------------------------------
//  Wrapping of void wxObject::SetRefData(wxObjectRefData * data)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_SetRefData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectRefData, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_SetRefData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxObjectRefData* data;
  if (!get_val_ptr_param<wxObjectRefData>(data,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetRefData(data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxObject::Ref(wxObject & clone)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_Ref::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clone'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_Ref::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxObject* clone_ptr;
  if (!get_val_ptr_param<wxObject>(clone_ptr,_p,_n)) ClassHelpAndReturn;
  wxObject& clone = *clone_ptr;
  this->_objectptr->GetObj()->Ref(clone);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObject::UnRef()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_UnRef::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_UnRef::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->UnRef();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObject::UnShare()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_UnShare::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_UnShare::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->UnShare();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxObject::IsSameAs(wxObject & o)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_IsSameAs::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'o'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_IsSameAs::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxObject* o_ptr;
  if (!get_val_ptr_param<wxObject>(o_ptr,_p,_n)) ClassHelpAndReturn;
  wxObject& o = *o_ptr;
  bool res =   this->_objectptr->GetObj()->IsSameAs(o);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxObject & wxObject::=(wxObject & other)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'other'")
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxObject* other_ptr;
  if (!get_val_ptr_param<wxObject>(other_ptr,_p,_n)) ClassHelpAndReturn;
  wxObject& other = *other_ptr;
  wxObject & res =   (*this->_objectptr->GetObj()) = (other);
  return AMILabType<wxObject>::CreateVar(res);
}

