/**
 * C++ Interface: wrap_wxLongLongNative
 *
 * Description: wrapping wxLongLongNative
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
#include "wrap_wxLongLongNative.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxString.h"
#include "wrap_wxULongLongNative.h"


#include "wrap_wxLongLongNative.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxLongLongNative>::CreateVar( ParamList* p)
{
  WrapClass_wxLongLongNative::wrap_wxLongLongNative construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxLongLongNative);
AMI_DEFINE_VARFROMSMTPTR(wxLongLongNative);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxLongLongNative
//
Variable<AMIObject>::ptr WrapClass_wxLongLongNative::CreateVar( wxLongLongNative* sp)
{
  boost::shared_ptr<wxLongLongNative> di_ptr(
    sp,
    wxwindow_nodeleter<wxLongLongNative>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxLongLongNative>::CreateVar(
      new WrapClass_wxLongLongNative(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxLongLongNative::AddMethods(WrapClass<wxLongLongNative>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Assign( this_ptr);
  AddVar_GetHi( this_ptr);
  AddVar_GetLo( this_ptr);
  AddVar_Abs_1( this_ptr);
  AddVar_Abs( this_ptr);
  AddVar_Abs_2( this_ptr);
  AddVar_GetValue( this_ptr);
  AddVar_ToLong( this_ptr);
  AddVar_ToDouble( this_ptr);
  AddVar_Negate( this_ptr);
  AddVar_ToString( this_ptr);
  AddVar_asArray( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
  AddVar___assign___2( this_ptr);
/* The following types are missing: long long unsigned int
  AddVar___assign___3( this_ptr);
*/
  AddVar___assign___4( this_ptr);
  AddVar___assign___5( this_ptr);
  AddVar___assign___6( this_ptr);
  AddVar___assign___7( this_ptr);
  AddVar___assign___8( this_ptr);
  AddVar___add___1( this_ptr);
  AddVar___add_assign___1( this_ptr);
  AddVar___add__( this_ptr);
  AddVar___add___2( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add_assign___2( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  // AddVar_operator not available( this_ptr);
  AddVar___substract___1( this_ptr);
  AddVar___substract__( this_ptr);
  AddVar___substract___2( this_ptr);
  AddVar___sub_assign___1( this_ptr);
  AddVar___substract___3( this_ptr);
  AddVar___sub_assign__( this_ptr);
  AddVar___sub_assign___2( this_ptr);
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
void WrapClass_wxLongLongNative::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxLongLongNative");
    WrapClass_wxLongLongNative::AddVar_wxLongLongNative_1(amiobject->GetContext());
  WrapClass_wxLongLongNative::AddVar_wxLongLongNative(amiobject->GetContext());
  WrapClass_wxLongLongNative::AddVar_wxLongLongNative_2(amiobject->GetContext());
  WrapClass_wxLongLongNative::AddVar_wxLongLongNative_3(amiobject->GetContext());
  WrapClass_wxLongLongNative::AddVar_wxLongLongNative_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxLongLongNative::wxLongLongNative(wxLongLongNative const & param0)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > param0_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxLongLongNative const & param0 = *param0_smtptr;

  wxLongLongNative* _newobj = new wxLongLongNative(param0);
  BasicVariable::ptr res = WrapClass_wxLongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxLongLongNative::wxLongLongNative(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_wxLongLongNative::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_wxLongLongNative::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap_wxLongLongNative_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap_wxLongLongNative_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap_wxLongLongNative_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap_wxLongLongNative_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxLongLongNative::wxLongLongNative()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative* _newobj = new wxLongLongNative();
  BasicVariable::ptr res = WrapClass_wxLongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxLongLongNative::wxLongLongNative(long long int ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative* _newobj = new wxLongLongNative(ll);
  BasicVariable::ptr res = WrapClass_wxLongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxLongLongNative::wxLongLongNative(wxInt32 hi, wxUint32 lo)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'hi'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'lo'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_wxLongLongNative_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int hi;
  if (!get_val_param<int >(hi,_p,_n,true,true)) ClassReturnEmptyVar;

  long lo_long;
  if (!get_val_param<long >(lo_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int lo = boost::numeric_cast<unsigned int >(lo_long);

  wxLongLongNative* _newobj = new wxLongLongNative(hi, lo);
  BasicVariable::ptr res = WrapClass_wxLongLongNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxLongLongNative.
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxLongLongNative object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxLongLongNative >::CreateVar( new wxLongLongNative(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::Assign(double d)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_Assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'd'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_Assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double d;
  if (!get_val_param<double >(d,_p,_n,true,false)) ClassHelpAndReturn;

  wxLongLongNative & res =   this->_objectptr->GetObj()->Assign(d);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxInt32 wxLongLongNative::GetHi()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_GetHi::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_GetHi::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxInt32 res =   this->_objectptr->GetObj()->GetHi();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxUint32 wxLongLongNative::GetLo()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_GetLo::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_GetLo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxUint32 res =   this->_objectptr->GetObj()->GetLo();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::Abs()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_Abs_1::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_Abs_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative res =   this->_objectptr->GetObj()->Abs();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::Abs(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_Abs::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_Abs::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap_Abs_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap_Abs_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::Abs()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_Abs_2::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_Abs_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative & res =   this->_objectptr->GetObj()->Abs();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of long long int wxLongLongNative::GetValue()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_GetValue::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_GetValue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long long int res =   this->_objectptr->GetObj()->GetValue();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long int wxLongLongNative::ToLong()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_ToLong::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_ToLong::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->ToLong();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of double wxLongLongNative::ToDouble()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_ToDouble::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_ToDouble::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->ToDouble();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::Negate()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_Negate::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_Negate::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxLongLongNative & res =   this->_objectptr->GetObj()->Negate();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxLongLongNative::ToString()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_ToString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_ToString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->ToString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void * wxLongLongNative::asArray()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_asArray::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_asArray::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->asArray();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(wxLongLongNative const & param0)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'param0'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > param0_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & param0 = *param0_smtptr;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___assign___8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(long long int ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
/*
 * The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(long long unsigned int ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ll;
  if (!get_val_param<long long unsigned int >(ll,_p,_n,true,true)) ClassReturnEmptyVar;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(wxULongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxULongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxULongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxULongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxULongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int l;
  if (!get_val_param<int >(l,_p,_n,true,true)) ClassReturnEmptyVar;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(unsigned int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int l = boost::numeric_cast<unsigned int >(l_long);

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator =(long unsigned int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___assign___8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___assign___8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int l = boost::numeric_cast<long unsigned int >(l_long);

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) = (l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::operator +(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   (*this->_objectptr->GetObj()) + (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator +=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) += (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::+(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___add___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___add___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::operator +(long long int const ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative res =   (*this->_objectptr->GetObj()) + (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::+=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___add_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator +=(long long int const ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) += (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::++()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative & res =   this->_objectptr->GetObj()->++();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::++(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::++(int param0)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  wxLongLongNative res =   this->_objectptr->GetObj()->++(param0);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::operator -()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___substract___1::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative res =  - (*this->_objectptr->GetObj());
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::-(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___substract___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___substract___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::operator -(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___substract___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   (*this->_objectptr->GetObj()) - (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator -=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___sub_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___sub_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) -= (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::operator -(long long int const ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___substract___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___substract___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative res =   (*this->_objectptr->GetObj()) - (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::-=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___sub_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___sub_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___sub_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::operator -=(long long int const ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___sub_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___sub_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ll_long;
  if (!get_val_param<long >(ll_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int ll = boost::numeric_cast<long long int >(ll_long);

  wxLongLongNative & res =   (*this->_objectptr->GetObj()) -= (ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::--()
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLongLongNative & res =   this->_objectptr->GetObj()->--();
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::--(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::--(int param0)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int param0;
  if (!get_val_param<int >(param0,_p,_n,true,true)) ClassReturnEmptyVar;

  wxLongLongNative res =   this->_objectptr->GetObj()->--(param0);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::<<(int shift)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxLongLongNative res =   this->_objectptr->GetObj()-><<(shift);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::<<=(int shift)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxLongLongNative & res =   this->_objectptr->GetObj()-><<=(shift);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::>>(int shift)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxLongLongNative res =   this->_objectptr->GetObj()->>>(shift);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::>>=(int shift)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'shift'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int shift;
  if (!get_val_param<int >(shift,_p,_n,true,false)) ClassHelpAndReturn;

  wxLongLongNative & res =   this->_objectptr->GetObj()->>>=(shift);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::&(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->&(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::&=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   this->_objectptr->GetObj()->&=(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::|(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->|(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::|=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   this->_objectptr->GetObj()->|=(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::^(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->^(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::^=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   this->_objectptr->GetObj()->^=(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::*(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->*(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::*(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::*(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative res =   this->_objectptr->GetObj()->*(l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::*=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   this->_objectptr->GetObj()->*=(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::*=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::*=(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative & res =   this->_objectptr->GetObj()->*=(l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::/(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->/(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::/(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::/(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative res =   this->_objectptr->GetObj()->/(l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::/=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative & res =   this->_objectptr->GetObj()->/=(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::/=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative & wxLongLongNative::/=(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative & res =   this->_objectptr->GetObj()->/=(l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::%(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  wxLongLongNative res =   this->_objectptr->GetObj()->%(ll);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::%(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxLongLongNative wxLongLongNative::%(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxLongLongNative";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  wxLongLongNative res =   this->_objectptr->GetObj()->%(l);
  return AMILabType<wxLongLongNative >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::operator ==(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (ll);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::==(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::operator ==(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   (*this->_objectptr->GetObj()) == (l);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::operator !=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___not_equal___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___not_equal___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (ll);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::!=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___not_equal__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLongLongNative::wrap___not_equal___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLongLongNative::wrap___not_equal___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::operator !=(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap___not_equal___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap___not_equal___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   (*this->_objectptr->GetObj()) != (l);
  return AMILabType<bool >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::<(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()-><(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::<(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::<(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   this->_objectptr->GetObj()-><(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::>(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()->>(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::>(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::>(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   this->_objectptr->GetObj()->>(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::<=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()-><=(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::<=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::<=(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   this->_objectptr->GetObj()-><=(l);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::>=(wxLongLongNative const & ll)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLongLongNative, "parameter named 'll'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLongLongNative > ll_smtptr;
  if (!get_val_smtptr_param<wxLongLongNative >(ll_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxLongLongNative const & ll = *ll_smtptr;

  bool res =   this->_objectptr->GetObj()->>=(ll);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxLongLongNative::>=(...)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxLongLongNative::>=(long int l)
//---------------------------------------------------
void WrapClass_wxLongLongNative::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLongLongNative::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long >(l_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int l = l_long;

  bool res =   this->_objectptr->GetObj()->>=(l);
  return AMILabType<bool >::CreateVar(res);
}
*/

