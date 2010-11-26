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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxClassInfo.h"
#include "stdlib.h"
#include "wrap_wxObject.h"
#include "wchar.h"


#include "wrap_wxClassInfo.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxClassInfo>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxClassInfo);
AMI_DEFINE_VARFROMSMTPTR(wxClassInfo);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxClassInfo>::CreateVar( wxClassInfo* val, bool nodeleter)
{ 
  boost::shared_ptr<wxClassInfo> obj_ptr(val,smartpointer_nodeleter<wxClassInfo>());
  return AMILabType<wxClassInfo>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxClassInfo
//
Variable<AMIObject>::ptr WrapClass_wxClassInfo::CreateVar( wxClassInfo* sp)
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

//----------------------------------------------------------------------
void WrapClass_wxClassInfo::AddMethods(WrapClass<wxClassInfo>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_CreateObject( this_ptr);
      AddVar_IsDynamic( this_ptr);
      AddVar_GetClassName( this_ptr);
      AddVar_GetBaseClassName1( this_ptr);
      AddVar_GetBaseClassName2( this_ptr);
      AddVar_GetBaseClass1( this_ptr);
      AddVar_GetBaseClass2( this_ptr);
      AddVar_GetSize( this_ptr);
/* The following types are missing: _8997
      AddVar_GetConstructor( this_ptr);
*/
      AddVar_GetNext( this_ptr);
      AddVar_IsKindOf( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member m_className
      boost::shared_ptr<wchar_t > var_m_className_ptr(GetObj()->m_className, smartpointer_nodeleter<wchar_t >());
      BasicVariable::ptr var_m_className = AMILabType<wchar_t >::CreateVarFromSmtPtr(var_m_className_ptr);
      if (var_m_className.get()) {
        var_m_className->Rename("m_className");
        context->AddVar(var_m_className,context);
      }
      */
      
      // Adding public member m_objectSize
      boost::shared_ptr<int > var_m_objectSize_ptr(&GetObj()->m_objectSize, smartpointer_nodeleter<int >());
      BasicVariable::ptr var_m_objectSize = AMILabType<int >::CreateVarFromSmtPtr(var_m_objectSize_ptr);
      if (var_m_objectSize.get()) {
        var_m_objectSize->Rename("m_objectSize");
        context->AddVar(var_m_objectSize,context);
      }
      
      /* type not available
      // Adding public member m_objectConstructor
      boost::shared_ptr<_8997 > var_m_objectConstructor_ptr(&GetObj()->m_objectConstructor, smartpointer_nodeleter<_8997 >());
      BasicVariable::ptr var_m_objectConstructor = AMILabType<_8997 >::CreateVarFromSmtPtr(var_m_objectConstructor_ptr);
      if (var_m_objectConstructor.get()) {
        var_m_objectConstructor->Rename("m_objectConstructor");
        context->AddVar(var_m_objectConstructor,context);
      }
      */
      
      /* Avoiding const pointers for the moment
      // Adding public member m_baseInfo1
      boost::shared_ptr<wxClassInfo > var_m_baseInfo1_ptr(GetObj()->m_baseInfo1, smartpointer_nodeleter<wxClassInfo >());
      BasicVariable::ptr var_m_baseInfo1 = AMILabType<wxClassInfo >::CreateVarFromSmtPtr(var_m_baseInfo1_ptr);
      if (var_m_baseInfo1.get()) {
        var_m_baseInfo1->Rename("m_baseInfo1");
        context->AddVar(var_m_baseInfo1,context);
      }
      */
      
      /* Avoiding const pointers for the moment
      // Adding public member m_baseInfo2
      boost::shared_ptr<wxClassInfo > var_m_baseInfo2_ptr(GetObj()->m_baseInfo2, smartpointer_nodeleter<wxClassInfo >());
      BasicVariable::ptr var_m_baseInfo2 = AMILabType<wxClassInfo >::CreateVarFromSmtPtr(var_m_baseInfo2_ptr);
      if (var_m_baseInfo2.get()) {
        var_m_baseInfo2->Rename("m_baseInfo2");
        context->AddVar(var_m_baseInfo2,context);
      }
      */
      
      // Adding public member m_next
      boost::shared_ptr<wxClassInfo > var_m_next_ptr(GetObj()->m_next, smartpointer_nodeleter<wxClassInfo >());
      BasicVariable::ptr var_m_next = AMILabType<wxClassInfo >::CreateVarFromSmtPtr(var_m_next_ptr);
      if (var_m_next.get()) {
        var_m_next->Rename("m_next");
        context->AddVar(var_m_next,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: _8997

//---------------------------------------------------
//  Wrapping of Constructor wxClassInfo::wxClassInfo(wxChar const * className, wxClassInfo const * baseInfo1, wxClassInfo const * baseInfo2, int size, wxObjectConstructorFn ctor)
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_wxClassInfo::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'className'")
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'baseInfo1'")
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'baseInfo2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( _8997, "parameter named 'ctor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_wxClassInfo::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > className_string;
  if (!get_val_smtptr_param<std::string >(className_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t className[className_string->size()+1];
mbstowcs(className,className_string->c_str(),className_string->size()+1);

  boost::shared_ptr<wxClassInfo > baseInfo1_smtptr;
  if (!get_val_smtptr_param<wxClassInfo >(baseInfo1_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxClassInfo* baseInfo1 = baseInfo1_smtptr.get();

  boost::shared_ptr<wxClassInfo > baseInfo2_smtptr;
  if (!get_val_smtptr_param<wxClassInfo >(baseInfo2_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  wxClassInfo* baseInfo2 = baseInfo2_smtptr.get();

  int size;
  if (!get_val_param<int >(size,_p,_n,true,false)) ClassHelpAndReturn;

  _8997 ctor;
  if (!get_val_param<_8997 >(ctor,_p,_n,true,false)) ClassHelpAndReturn;

  wxClassInfo* _newobj = new wxClassInfo(className, baseInfo1, baseInfo2, size, ctor);
  BasicVariable::ptr res = WrapClass_wxClassInfo::CreateVar(_newobj);
  return res;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo const * res =   wxClassInfo::GetFirst();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(const_cast<wxClassInfo *>(res));
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxClassInfo::FindClass(wxChar const * className)
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_FindClass::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'className'")
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_FindClass::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > className_string;
  if (!get_val_smtptr_param<std::string >(className_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  wchar_t className[className_string->size()+1];
mbstowcs(className,className_string->c_str(),className_string->size()+1);

  wxClassInfo * res =   wxClassInfo::FindClass(className);
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo::InitializeClasses();
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo::CleanUpClasses();
  return BasicVariable::ptr();
}

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsDynamic();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetClassName()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetClassName::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetClassName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetClassName();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetBaseClassName1()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClassName1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClassName1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetBaseClassName1();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxClassInfo::GetBaseClassName2()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetBaseClassName2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetBaseClassName2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetBaseClassName2();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo const * res =   this->_objectptr->GetObj()->GetBaseClass1();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(const_cast<wxClassInfo *>(res));
  return res_var;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo const * res =   this->_objectptr->GetObj()->GetBaseClass2();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(const_cast<wxClassInfo *>(res));
  return res_var;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetSize();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: _8997

//---------------------------------------------------
//  Wrapping of wxObjectConstructorFn wxClassInfo::GetConstructor()
//---------------------------------------------------
void WrapClass_wxClassInfo::
    wrap_GetConstructor::SetParametersComments()
{
  return_comments="returning a variable of type _8997";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClassInfo::
    wrap_GetConstructor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectConstructorFn res =   this->_objectptr->GetObj()->GetConstructor();
  return AMILabType<_8997 >::CreateVar(res);
}
*/

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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo const * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(const_cast<wxClassInfo *>(res));
  return res_var;
}

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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxClassInfo > info_smtptr;
  if (!get_val_smtptr_param<wxClassInfo >(info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxClassInfo* info = info_smtptr.get();

  bool res =   this->_objectptr->GetObj()->IsKindOf(info);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

