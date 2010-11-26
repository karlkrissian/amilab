/**
 * C++ Interface: wrap_wxListKey
 *
 * Description: wrapping wxListKey
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
#include "wrap_wxListKey.h"
#include "stdlib.h"
#include "wrap_wxString.h"
#include "wchar.h"


#include "wrap_wxListKey.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxListKey>::CreateVar( ParamList* p)
{
  WrapClass_wxListKey::wrap_wxListKey construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxListKey);
AMI_DEFINE_VARFROMSMTPTR(wxListKey);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxListKey
//
Variable<AMIObject>::ptr WrapClass_wxListKey::CreateVar( wxListKey* sp)
{
  boost::shared_ptr<wxListKey> di_ptr(
    sp,
    wxwindow_nodeleter<wxListKey>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxListKey>::CreateVar(
      new WrapClass_wxListKey(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxListKey::AddMethods(WrapClass<wxListKey>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: wxKeyType
      AddVar_GetKeyType( this_ptr);
*/
      AddVar_GetString( this_ptr);
      AddVar_GetNumber( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
/* The following types are missing: wxListKeyValue
      AddVar___equal__( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxListKey::wxListKey(wxListKey const & param0)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxListKey > param0_smtptr;
  if (!get_val_smtptr_param<wxListKey >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxListKey const & param0 = *param0_smtptr;

  wxListKey* _newobj = new wxListKey(param0);
  BasicVariable::ptr res = WrapClass_wxListKey::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxListKey::wxListKey(...)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxListKey::wrap_wxListKey_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxListKey::wrap_wxListKey_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxListKey::wrap_wxListKey_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxListKey::wrap_wxListKey_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxListKey::wrap_wxListKey_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxListKey::wxListKey()
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxListKey* _newobj = new wxListKey();
  BasicVariable::ptr res = WrapClass_wxListKey::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxListKey::wxListKey(long int i)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long i_long;
  if (!get_val_param<long >(i_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int i = i_long;

  wxListKey* _newobj = new wxListKey(i);
  BasicVariable::ptr res = WrapClass_wxListKey::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxListKey::wxListKey(wxChar const * s)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  wxListKey* _newobj = new wxListKey(s);
  BasicVariable::ptr res = WrapClass_wxListKey::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxListKey::wxListKey(wxString const & s)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_wxListKey_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_wxListKey_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxListKey* _newobj = new wxListKey(s);
  BasicVariable::ptr res = WrapClass_wxListKey::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxListKey.
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxListKey object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxListKey >::CreateVar( new wxListKey(*(this->_objectptr->GetObj())));
}
/* The following types are missing: wxKeyType

//---------------------------------------------------
//  Wrapping of wxKeyType wxListKey::GetKeyType()
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_GetKeyType::SetParametersComments()
{
  return_comments="returning a variable of type wxKeyType";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_GetKeyType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxKeyType res =   this->_objectptr->GetObj()->GetKeyType();
  return AMILabType<wxKeyType >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxChar const * wxListKey::GetString()
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_GetString::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_GetString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetString();
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
//  Wrapping of long int wxListKey::GetNumber()
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap_GetNumber::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap_GetNumber::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetNumber();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxListKey & wxListKey::operator =(wxListKey const & param0)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKey, "parameter named 'param0'")
  return_comments="returning a variable of type wxListKey";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListKey > param0_smtptr;
  if (!get_val_smtptr_param<wxListKey >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxListKey const & param0 = *param0_smtptr;

  wxListKey & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxListKey >::CreateVar(res);
}
/*
 * The following types are missing: wxListKeyValue

//---------------------------------------------------
//  Wrapping of bool wxListKey::operator ==(wxListKeyValue value)
//---------------------------------------------------
void WrapClass_wxListKey::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListKeyValue, "parameter named 'value'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListKey::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxListKeyValue value;
  if (!get_val_param<wxListKeyValue >(value,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   (*this->_objectptr->GetObj()) == (value);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

