/**
 * C++ Interface: wrap_wxConfigBase
 *
 * Description: wrapping wxConfigBase
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
#include "wrap_wxConfigBase.h"
#include "wrap_wxString.h"
#include "stdlib.h"


#include "wrap_wxConfigBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxConfigBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxConfigBase);
AMI_DEFINE_VARFROMSMTPTR(wxConfigBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxConfigBase
//
Variable<AMIObject>::ptr WrapClass_wxConfigBase::CreateVar( wxConfigBase* sp)
{
  boost::shared_ptr<wxConfigBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxConfigBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxConfigBase>::CreateVar(
      new WrapClass_wxConfigBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxConfigBase::AddMethods(WrapClass<wxConfigBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Exists( this_ptr);
  AddVar_GetEntryType( this_ptr);
  AddVar_Read_1( this_ptr);
  AddVar_Read( this_ptr);
  AddVar_Read_2( this_ptr);
  AddVar_Read_3( this_ptr);
  AddVar_Read_4( this_ptr);
  AddVar_Read_5( this_ptr);
  AddVar_Read_6( this_ptr);
  AddVar_Read_7( this_ptr);
  AddVar_Read_8( this_ptr);
  AddVar_Read_9( this_ptr);
  AddVar_Read_10( this_ptr);
  AddVar_Read_11( this_ptr);
  AddVar_Read_12( this_ptr);
  AddVar_Write_1( this_ptr);
  AddVar_Write( this_ptr);
  AddVar_Write_2( this_ptr);
  AddVar_Write_3( this_ptr);
  AddVar_Write_4( this_ptr);
  AddVar_Write_5( this_ptr);
  AddVar_Write_6( this_ptr);
  AddVar_IsExpandingEnvVars( this_ptr);
  AddVar_SetExpandEnvVars( this_ptr);
  AddVar_SetRecordDefaults( this_ptr);
  AddVar_IsRecordingDefaults( this_ptr);
  AddVar_ExpandEnvVars( this_ptr);
  AddVar_GetAppName( this_ptr);
  AddVar_GetVendorName( this_ptr);
  AddVar_SetAppName( this_ptr);
  AddVar_SetVendorName( this_ptr);
  AddVar_SetStyle( this_ptr);
  AddVar_GetStyle( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_EntryType(new AMIObject);
  obj_EntryType->SetName("EntryType");

  BasicVariable::ptr var_Type_Unknown = AMILabType<int >::CreateVar(0);
  if (var_Type_Unknown.get()) {
    var_Type_Unknown->Rename("Type_Unknown");
    obj_EntryType->GetContext()->AddVar(var_Type_Unknown,obj_EntryType->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_EntryType->GetName().c_str(),obj_EntryType,context);


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxConfigBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxConfigBase");
  
  // Static methods 
  WrapClass_wxConfigBase::AddVar_Set(amiobject->GetContext());
  WrapClass_wxConfigBase::AddVar_Get(amiobject->GetContext());
  WrapClass_wxConfigBase::AddVar_Create(amiobject->GetContext());
  WrapClass_wxConfigBase::AddVar_DontCreateOnDemand(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxConfigBase * wxConfigBase::Set(wxConfigBase * pConfig)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_static_Set::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxConfigBase, "parameter named 'pConfig'")
  return_comments="returning a variable of type wxConfigBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_static_Set::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxConfigBase > pConfig_smtptr;
  if (!get_val_smtptr_param<wxConfigBase >(pConfig_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxConfigBase* pConfig = pConfig_smtptr.get();

  wxConfigBase * res =   wxConfigBase::Set(pConfig);
  BasicVariable::ptr res_var = WrapClass_wxConfigBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxConfigBase * wxConfigBase::Get(bool createOnDemand = true)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_static_Get::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'createOnDemand' (def:true)")
  return_comments="returning a variable of type wxConfigBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_static_Get::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool createOnDemand = true;
  if (!get_val_param<bool >(createOnDemand,_p,_n,false,false)) ClassHelpAndReturn;

  wxConfigBase * res =   wxConfigBase::Get(createOnDemand);
  BasicVariable::ptr res_var = WrapClass_wxConfigBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxConfigBase * wxConfigBase::Create()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_static_Create::SetParametersComments()
{
  return_comments="returning a variable of type wxConfigBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_static_Create::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxConfigBase * res =   wxConfigBase::Create();
  BasicVariable::ptr res_var = WrapClass_wxConfigBase::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::DontCreateOnDemand()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_static_DontCreateOnDemand::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_static_DontCreateOnDemand::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxConfigBase::DontCreateOnDemand();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Exists(wxString const & strName)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Exists::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'strName'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Exists::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > strName_smtptr;
  if (!get_val_smtptr_param<wxString >(strName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & strName = *strName_smtptr;

  bool res =   this->_objectptr->GetObj()->Exists(strName);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxConfigBase::EntryType wxConfigBase::GetEntryType(wxString const & name)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_GetEntryType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_GetEntryType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  wxConfigBase::EntryType res =   this->_objectptr->GetObj()->GetEntryType(name);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, wxString * pStr)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pStr'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<wxString > pStr_smtptr;
  if (!get_val_smtptr_param<wxString >(pStr_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString* pStr = pStr_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Read(key, pStr);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxConfigBase::Read(...)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxConfigBase::wrap_Read_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Read_12 m12(this->_objectptr);
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, wxString * pStr, wxString const & defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'pStr'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'defVal'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<wxString > pStr_smtptr;
  if (!get_val_smtptr_param<wxString >(pStr_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString* pStr = pStr_smtptr.get();

  boost::shared_ptr<wxString > defVal_smtptr;
  if (!get_val_smtptr_param<wxString >(defVal_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & defVal = *defVal_smtptr;

  bool res =   this->_objectptr->GetObj()->Read(key, pStr, defVal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, long int * pl)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pl'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<long > pl_long;
  if (!get_val_smtptr_param<long >(pl_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int pl_val = *pl_long;
  long int* pl = &pl_val;

  bool res =   this->_objectptr->GetObj()->Read(key, pl);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, long int * pl, long int defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pl'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'defVal'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<long > pl_long;
  if (!get_val_smtptr_param<long >(pl_long,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long int pl_val = *pl_long;
  long int* pl = &pl_val;

  long defVal_long;
  if (!get_val_param<long >(defVal_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int defVal = defVal_long;

  bool res =   this->_objectptr->GetObj()->Read(key, pl, defVal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, int * pi)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pi'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<int > pi_smtptr;
  if (!get_val_smtptr_param<int >(pi_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* pi = pi_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Read(key, pi);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, int * pi, int defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pi'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'defVal'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<int > pi_smtptr;
  if (!get_val_smtptr_param<int >(pi_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  int* pi = pi_smtptr.get();

  int defVal;
  if (!get_val_param<int >(defVal,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Read(key, pi, defVal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, double * val)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<double > val_smtptr;
  if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* val = val_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Read(key, val);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, double * val, double defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'defVal'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<double > val_smtptr;
  if (!get_val_smtptr_param<double >(val_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  double* val = val_smtptr.get();

  double defVal;
  if (!get_val_param<double >(defVal,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Read(key, val, defVal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, bool * val)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'val'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<bool > val_smtptr;
  if (!get_val_smtptr_param<bool >(val_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  bool* val = val_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Read(key, val);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Read(wxString const & key, bool * val, bool defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'defVal'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<bool > val_smtptr;
  if (!get_val_smtptr_param<bool >(val_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  bool* val = val_smtptr.get();

  bool defVal;
  if (!get_val_param<bool >(defVal,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Read(key, val, defVal);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxConfigBase::Read(wxString const & key, wxString const & defVal = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'defVal' (def:wxEmptyString)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<wxString > defVal_smtptr;
  if (!get_val_smtptr_param<wxString >(defVal_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & defVal = ( defVal_smtptr.get() ? (*defVal_smtptr) : wxString(wxEmptyString) );

  wxString res =   this->_objectptr->GetObj()->Read(key, defVal);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long int wxConfigBase::Read(wxString const & key, long int defVal)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Read_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'defVal'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Read_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  long defVal_long;
  if (!get_val_param<long >(defVal_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int defVal = defVal_long;

  long int res =   this->_objectptr->GetObj()->Read(key, defVal);
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, wxString const & value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<wxString > value_smtptr;
  if (!get_val_smtptr_param<wxString >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & value = *value_smtptr;

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxConfigBase::Write(...)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxConfigBase::wrap_Write_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Write_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Write_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Write_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Write_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxConfigBase::wrap_Write_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, long int value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  long value_long;
  if (!get_val_param<long >(value_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int value = value_long;

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, int value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  int value;
  if (!get_val_param<int >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, double value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  double value;
  if (!get_val_param<double >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, bool value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  bool value;
  if (!get_val_param<bool >(value,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::Write(wxString const & key, wxChar const * value)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_Write_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'key'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'value'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_Write_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > key_smtptr;
  if (!get_val_smtptr_param<wxString >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & key = *key_smtptr;

  boost::shared_ptr<std::string > value_string;
  if (!get_val_smtptr_param<std::string >(value_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t value[value_string->size()+1];
mbstowcs(value,value_string->c_str(),value_string->size()+1);

  bool res =   this->_objectptr->GetObj()->Write(key, value);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::IsExpandingEnvVars()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_IsExpandingEnvVars::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_IsExpandingEnvVars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsExpandingEnvVars();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::SetExpandEnvVars(bool bDoIt = true)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_SetExpandEnvVars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bDoIt' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_SetExpandEnvVars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool bDoIt = true;
  if (!get_val_param<bool >(bDoIt,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetExpandEnvVars(bDoIt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::SetRecordDefaults(bool bDoIt = true)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_SetRecordDefaults::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bDoIt' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_SetRecordDefaults::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool bDoIt = true;
  if (!get_val_param<bool >(bDoIt,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRecordDefaults(bDoIt);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxConfigBase::IsRecordingDefaults()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_IsRecordingDefaults::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_IsRecordingDefaults::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsRecordingDefaults();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxConfigBase::ExpandEnvVars(wxString const & str)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_ExpandEnvVars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_ExpandEnvVars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  wxString res =   this->_objectptr->GetObj()->ExpandEnvVars(str);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxConfigBase::GetAppName()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_GetAppName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_GetAppName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetAppName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxConfigBase::GetVendorName()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_GetVendorName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_GetVendorName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetVendorName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::SetAppName(wxString const & appName)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_SetAppName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'appName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_SetAppName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > appName_smtptr;
  if (!get_val_smtptr_param<wxString >(appName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & appName = *appName_smtptr;

  this->_objectptr->GetObj()->SetAppName(appName);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::SetVendorName(wxString const & vendorName)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_SetVendorName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'vendorName'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_SetVendorName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > vendorName_smtptr;
  if (!get_val_smtptr_param<wxString >(vendorName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & vendorName = *vendorName_smtptr;

  this->_objectptr->GetObj()->SetVendorName(vendorName);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxConfigBase::SetStyle(long int style)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_SetStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_SetStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  this->_objectptr->GetObj()->SetStyle(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxConfigBase::GetStyle()
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetStyle();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxConfigBase & wxConfigBase::operator =(wxConfigBase const & param0)
//---------------------------------------------------
void WrapClass_wxConfigBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxConfigBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxConfigBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxConfigBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxConfigBase > param0_smtptr;
  if (!get_val_smtptr_param<wxConfigBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxConfigBase const & param0 = *param0_smtptr;

  wxConfigBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxConfigBase >::CreateVar(res);
}

