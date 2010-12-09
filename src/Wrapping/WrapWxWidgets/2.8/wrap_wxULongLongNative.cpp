/**
 * C++ Interface: wrap_wxULongLongNative
 *
 * Description: wrapping wxULongLongNative
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
#include "wrap_wxULongLongNative.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxString.h"
#include "wrap_wxLongLongNative.h"


#include "wrap_wxULongLongNative.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxULongLongNative>::CreateVar( ParamList* p)
{
  WrapClass_wxULongLongNative::wrap_wxULongLongNative construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxULongLongNative);
AMI_DEFINE_VARFROMSMTPTR(wxULongLongNative);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxULongLongNative
//
Variable<AMIObject>::ptr WrapClass_wxULongLongNative::CreateVar( wxULongLongNative* sp)
{
  boost::shared_ptr<wxULongLongNative> di_ptr(
    sp,
    wxwindow_nodeleter<wxULongLongNative>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxULongLongNative>::CreateVar(
      new WrapClass_wxULongLongNative(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxULongLongNative::AddMethods(WrapClass<wxULongLongNative>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetHi( this_ptr);
  AddVar_GetLo( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar_GetValue( this_ptr);
*/
  AddVar_ToULong( this_ptr);
  AddVar_ToDouble( this_ptr);
  AddVar_ToString( this_ptr);
  AddVar_asArray( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___assign___2( this_ptr);
*/
  AddVar___assign___3( this_ptr);
  AddVar___assign___4( this_ptr);
  AddVar___assign___5( this_ptr);
  AddVar___assign___6( this_ptr);
  AddVar___assign___7( this_ptr);
  AddVar___assign___8( this_ptr);
  AddVar___add___1( this_ptr);
  AddVar___add_assign___1( this_ptr);
  AddVar___add__( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___add___2( this_ptr);
*/
  AddVar___add_assign__( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___add_assign___2( this_ptr);
*/
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___substract___1( this_ptr);
  AddVar___sub_assign___1( this_ptr);
  AddVar___substract__( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___substract___2( this_ptr);
*/
  AddVar___sub_assign__( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___sub_assign___2( this_ptr);
*/
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___equal___1( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___equal___2( this_ptr);
  AddVar___not_equal___1( this_ptr);
  AddVar___not_equal__( this_ptr);
  AddVar___not_equal___2( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxULongLongNative::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxULongLongNative");
    WrapClass_wxULongLongNative::AddVar_wxULongLongNative_1(amiobject->GetContext());
  WrapClass_wxULongLongNative::AddVar_wxULongLongNative(amiobject->GetContext());
  WrapClass_wxULongLongNative::AddVar_wxULongLongNative_2(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxULongLongNative::AddVar_wxULongLongNative_3(amiobject->GetContext());
  */
  WrapClass_wxULongLongNative::AddVar_wxULongLongNative_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxULongLongNative::wxULongLongNative(wxULongLongNative const & param0)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > param0_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxULongLongNative const & param0 = *param0_smtptr;

  wxULongLongNative* _newobj = new wxULongLongNative(param0);
  BasicVariable::ptr res = WrapClass_wxULongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxULongLongNative::wxULongLongNative(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_wxULongLongNative::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_wxULongLongNative::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap_wxULongLongNative_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap_wxULongLongNative_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap_wxULongLongNative_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxULongLongNative::wxULongLongNative()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxULongLongNative* _newobj = new wxULongLongNative();
  BasicVariable::ptr res = WrapClass_wxULongLongNative::CreateVar(_newobj);
  return res;
}
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of Constructor wxULongLongNative::wxULongLongNative(long long unsigned int ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative* _newobj = new wxULongLongNative(ll);
  BasicVariable::ptr res = WrapClass_wxULongLongNative::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxULongLongNative::wxULongLongNative(wxUint32 hi, wxUint32 lo)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'hi'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'lo'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_wxULongLongNative_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long hi_long;
  if (!get_val_param<long >(hi_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int hi = boost::numeric_cast<unsigned int >(hi_long);

  long lo_long;
  if (!get_val_param<long >(lo_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int lo = boost::numeric_cast<unsigned int >(lo_long);

  wxULongLongNative* _newobj = new wxULongLongNative(hi, lo);
  BasicVariable::ptr res = WrapClass_wxULongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxULongLongNative.
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxULongLongNative object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxULongLongNative >::CreateVar( new wxULongLongNative(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxUint32 wxULongLongNative::GetHi()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_GetHi::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_GetHi::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUint32 res =   this->_objectptr->GetObj()->GetHi();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxUint32 wxULongLongNative::GetLo()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_GetLo::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_GetLo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUint32 res =   this->_objectptr->GetObj()->GetLo();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of long long unsigned int wxULongLongNative::GetValue()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_GetValue::SetParametersComments()
{
  return_comments="returning a variable of type long long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long long unsigned int res =   this->_objectptr->GetObj()->GetValue();
  return AMILabType<long long unsigned int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of long unsigned int wxULongLongNative::ToULong()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_ToULong::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_ToULong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->ToULong();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double wxULongLongNative::ToDouble()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_ToDouble::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_ToDouble::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->ToDouble();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxULongLongNative::ToString()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_ToString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_ToString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->ToString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void * wxULongLongNative::asArray()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_asArray::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_asArray::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->asArray();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(wxULongLongNative const & param0)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'param0'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > param0_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & param0 = *param0_smtptr;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___assign___8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(long long unsigned int ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(long long int ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int l;
  if (!get_val_param<int >(l,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(long int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int l = boost::numeric_cast<unsigned int >(l_long);

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator =(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___assign___8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___assign___8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::operator +(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   (*this->_objectptr->GetObj()) + (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator +=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) += (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::+(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___add___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::operator +(long long unsigned int const ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative res =   (*this->_objectptr->GetObj()) + (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::+=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator +=(long long unsigned int const ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) += (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::++()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxULongLongNative & res =   this->_objectptr->GetObj()->++();
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::++(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::++(int param0)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative res =   this->_objectptr->GetObj()->++(param0);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::operator -(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___substract___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   (*this->_objectptr->GetObj()) - (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator -=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___sub_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___sub_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) -= (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::-(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::operator -(long long unsigned int const ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___substract___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative res =   (*this->_objectptr->GetObj()) - (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::-=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___sub_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___sub_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::operator -=(long long unsigned int const ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___sub_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___sub_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative & res =   (*this->_objectptr->GetObj()) -= (ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::--()
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxULongLongNative & res =   this->_objectptr->GetObj()->--();
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::--(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::--(int param0)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  wxULongLongNative res =   this->_objectptr->GetObj()->--(param0);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::<<(int shift)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxULongLongNative res =   this->_objectptr->GetObj()-><<(shift);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::<<=(int shift)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxULongLongNative & res =   this->_objectptr->GetObj()-><<=(shift);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::>>(int shift)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxULongLongNative res =   this->_objectptr->GetObj()->>>(shift);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::>>=(int shift)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxULongLongNative & res =   this->_objectptr->GetObj()->>>=(shift);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::&(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->&(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::&=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   this->_objectptr->GetObj()->&=(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::|(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->|(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::|=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   this->_objectptr->GetObj()->|=(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::^(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->^(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::^=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   this->_objectptr->GetObj()->^=(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::*(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->*(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::*(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::*(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative res =   this->_objectptr->GetObj()->*(l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::*=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   this->_objectptr->GetObj()->*=(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::*=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::*=(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative & res =   this->_objectptr->GetObj()->*=(l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::/(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->/(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::/(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::/(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative res =   this->_objectptr->GetObj()->/(l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::/=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative & res =   this->_objectptr->GetObj()->/=(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::/=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative & wxULongLongNative::/=(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative & res =   this->_objectptr->GetObj()->/=(l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::%(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxULongLongNative res =   this->_objectptr->GetObj()->%(ll);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::%(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxULongLongNative wxULongLongNative::%(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxULongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxULongLongNative res =   this->_objectptr->GetObj()->%(l);
  return AMILabType<wxULongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::operator ==(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (ll);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::==(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::operator ==(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   (*this->_objectptr->GetObj()) == (l);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::operator !=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___not_equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___not_equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (ll);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::!=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___not_equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxULongLongNative::wrap___not_equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxULongLongNative::wrap___not_equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::operator !=(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap___not_equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap___not_equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   (*this->_objectptr->GetObj()) != (l);
  return AMILabType<bool >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::<(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()-><(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::<(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::<(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   this->_objectptr->GetObj()-><(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::>(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()->>(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::>(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::>(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   this->_objectptr->GetObj()->>(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::<=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()-><=(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::<=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::<=(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   this->_objectptr->GetObj()-><=(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::>=(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()->>=(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxULongLongNative::>=(...)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxULongLongNative::>=(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxULongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxULongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  bool res =   this->_objectptr->GetObj()->>=(l);
  return AMILabType<bool >::CreateVar(res);
}
*/

