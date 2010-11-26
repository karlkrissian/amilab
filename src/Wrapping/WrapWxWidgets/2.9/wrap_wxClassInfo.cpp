/**
 * C++ Interface: wrap_wxClassInfo
 *
 * Description: wrapping wxClassInfo
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxClassInfo.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxClassInfo.h"
#include "wrap_wxObject.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxClassInfo>::CreateVar( ParamList* p)
{
/*
WrapClass_wxClassInfo::wrap_wxClassInfo construct;
  return construct.CallMember(p);
  */
  return BasicVariable::ptr();
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxClassInfo);

//
// static member for creating a variable from a pointer to wxClassInfo
//
Variable<AMIObject>::ptr WrapClass_wxClassInfo::CreateVar(  wxClassInfo* sp)
{
  boost::shared_ptr<wxClassInfo> di_ptr(
    sp,
    wxwindow_nodeleter<wxClassInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxClassInfo>::CreateVar(
      new WrapClass_wxClassInfo(di_ptr)
    );
  return res;
}


/* The following types are missing: wchar_t, _8995

//---------------------------------------------------
//  Wrapping of Constructor wxClassInfo::wxClassInfo(wxChar const * className, wxClassInfo const * baseInfo1, wxClassInfo const * baseInfo2, int size, wxObjectConstructorFn ctor)
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_wxClassInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wchar_t, "parameter named 'className'")
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'baseInfo1'")
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'baseInfo2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( _8995, "parameter named 'ctor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_wxClassInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wchar_t* className;
  if (!get_val_ptr_param<wchar_t>(className,_p,_n)) ClassHelpAndReturn;
  wxClassInfo* baseInfo1;
  if (!get_val_ptr_param<wxClassInfo>(baseInfo1,_p,_n)) ClassHelpAndReturn;
  wxClassInfo* baseInfo2;
  if (!get_val_ptr_param<wxClassInfo>(baseInfo2,_p,_n)) ClassHelpAndReturn;
  int size;
  if (!get_val_param<int>(size,_p,_n)) ClassHelpAndReturn;
  _8995 ctor;
  if (!get_val_param<_8995>(ctor,_p,_n)) ClassHelpAndReturn;
  wxClassInfo* _newobj = new wxClassInfo(className, baseInfo1, baseInfo2, size, ctor);
  BasicVariable::ptr res = WrapClass_wxClassInfo::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of wxObject * wxClassInfo::CreateObject()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_CreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_CreateObject::CallMember( ParamList* _p)
{
  wxObject * res =   this->_objectptr->GetObj()->CreateObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxClassInfo::IsDynamic()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_IsDynamic::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_IsDynamic::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->IsDynamic();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wchar_t

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetClassName()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetClassName::SetParametersComments()
{
  return_comments="returning a variable of type wchar_t";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetClassName::CallMember( ParamList* _p)
{
  wxChar const * res =   this->_objectptr->GetObj()->GetClassName();
  return AMILabType<wchar_t>::CreateVar(res);
}
*/
/* The following types are missing: wchar_t

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetBaseClassName1()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClassName1::SetParametersComments()
{
  return_comments="returning a variable of type wchar_t";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClassName1::CallMember( ParamList* _p)
{
  wxChar const * res =   this->_objectptr->GetObj()->GetBaseClassName1();
  return AMILabType<wchar_t>::CreateVar(res);
}
*/
/* The following types are missing: wchar_t

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetBaseClassName2()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClassName2::SetParametersComments()
{
  return_comments="returning a variable of type wchar_t";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClassName2::CallMember( ParamList* _p)
{
  wxChar const * res =   this->_objectptr->GetObj()->GetBaseClassName2();
  return AMILabType<wchar_t>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo const * wxClassInfo::GetBaseClass1()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClass1::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClass1::CallMember( ParamList* _p)
{
  wxClassInfo const * res =   this->_objectptr->GetObj()->GetBaseClass1();
  //BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  //return res_var;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo const * wxClassInfo::GetBaseClass2()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClass2::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClass2::CallMember( ParamList* _p)
{
  wxClassInfo const * res =   this->_objectptr->GetObj()->GetBaseClass2();

  //BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  //return res_var;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxClassInfo::GetSize()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetSize::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: _8995

//---------------------------------------------------
//  Wrapping of wxObjectConstructorFn wxClassInfo::GetConstructor()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetConstructor::SetParametersComments()
{
  return_comments="returning a variable of type _8995";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetConstructor::CallMember( ParamList* _p)
{
  wxObjectConstructorFn res =   this->_objectptr->GetObj()->GetConstructor();
  return AMILabType<_8995>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo const * wxClassInfo::GetFirst()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetFirst::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetFirst::CallMember( ParamList* _p)
{
  //wxClassInfo const * res =   this->_objectptr->GetObj()->GetFirst();
  //BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  //return res_var;
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo const * wxClassInfo::GetNext()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetNext::CallMember( ParamList* _p)
{
  //wxClassInfo const * res =   this->_objectptr->GetObj()->GetNext();
  //BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  //return res_var;
  return BasicVariable::ptr();
}
/* The following types are missing: wchar_t

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxClassInfo::FindClass(wxChar const * className)
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_FindClass::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wchar_t, "parameter named 'className'")
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_FindClass::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wchar_t* className;
  if (!get_val_ptr_param<wchar_t>(className,_p,_n)) ClassHelpAndReturn;
  wxClassInfo * res =   this->_objectptr->GetObj()->FindClass(className);
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of bool wxClassInfo::IsKindOf(wxClassInfo const * info)
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_IsKindOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
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

//---------------------------------------------------
//  Wrapping of void wxClassInfo::InitializeClasses()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_InitializeClasses::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_InitializeClasses::CallMember( ParamList* _p)
{
//  this->_objectptr->GetObj()->InitializeClasses();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxClassInfo::CleanUpClasses()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_CleanUpClasses::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_CleanUpClasses::CallMember( ParamList* _p)
{
//  this->_objectptr->GetObj()->CleanUpClasses();
  return BasicVariable::ptr();
}

