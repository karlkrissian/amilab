/**
 * C++ Interface: wrap_wxIntegerEqual
 *
 * Description: wrapping wxIntegerEqual
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
#include "wrap_wxIntegerEqual.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxIntegerEqual.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxIntegerEqual>::CreateVar( ParamList* p)
{
  WrapClass_wxIntegerEqual::wrap_wxIntegerEqual construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIntegerEqual);
AMI_DEFINE_VARFROMSMTPTR(wxIntegerEqual);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIntegerEqual
//
Variable<AMIObject>::ptr WrapClass_wxIntegerEqual::CreateVar( wxIntegerEqual* sp)
{
  boost::shared_ptr<wxIntegerEqual> di_ptr(
    sp,
    wxwindow_nodeleter<wxIntegerEqual>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIntegerEqual>::CreateVar(
      new WrapClass_wxIntegerEqual(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIntegerEqual::AddMethods(WrapClass<wxIntegerEqual>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: short int, short int
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: long long unsigned int, long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
      AddVar___assign__( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxIntegerEqual::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIntegerEqual");
    WrapClass_wxIntegerEqual::AddVar_wxIntegerEqual_1(amiobject->GetContext());
  WrapClass_wxIntegerEqual::AddVar_wxIntegerEqual(amiobject->GetContext());
  WrapClass_wxIntegerEqual::AddVar_wxIntegerEqual_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIntegerEqual::wxIntegerEqual(wxIntegerEqual const & param0)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIntegerEqual, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIntegerEqual > param0_smtptr;
  if (!get_val_smtptr_param<wxIntegerEqual >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIntegerEqual const & param0 = *param0_smtptr;

  wxIntegerEqual* _newobj = new wxIntegerEqual(param0);
  BasicVariable::ptr res = WrapClass_wxIntegerEqual::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIntegerEqual::wxIntegerEqual(...)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIntegerEqual::wrap_wxIntegerEqual_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIntegerEqual::wrap_wxIntegerEqual_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIntegerEqual::wxIntegerEqual()
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_wxIntegerEqual_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxIntegerEqual* _newobj = new wxIntegerEqual();
  BasicVariable::ptr res = WrapClass_wxIntegerEqual::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIntegerEqual.
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIntegerEqual object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIntegerEqual >::CreateVar( new wxIntegerEqual(*(this->_objectptr->GetObj())));
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(long int a, long int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long a_long;
  if (!get_val_param<long >(a_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int a = a_long;

  long b_long;
  if (!get_val_param<long >(b_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int b = b_long;

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxIntegerEqual::()(...)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(long unsigned int a, long unsigned int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long a_long;
  if (!get_val_param<long >(a_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int a = boost::numeric_cast<long unsigned int >(a_long);

  long b_long;
  if (!get_val_param<long >(b_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int b = boost::numeric_cast<long unsigned int >(b_long);

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(int a, int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int a;
  if (!get_val_param<int >(a,_p,_n,true,true)) ClassReturnEmptyVar;

  int b;
  if (!get_val_param<int >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(unsigned int a, unsigned int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long a_long;
  if (!get_val_param<long >(a_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int a = boost::numeric_cast<unsigned int >(a_long);

  long b_long;
  if (!get_val_param<long >(b_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int b = boost::numeric_cast<unsigned int >(b_long);

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * The following types are missing: short int, short int
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(short int a, short int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( short int, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( short int, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  short int a;
  if (!get_val_param<short int >(a,_p,_n,true,true)) ClassReturnEmptyVar;

  short int b;
  if (!get_val_param<short int >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(short unsigned int a, short unsigned int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int a_int;
  if (!get_val_param<int >(a_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int a = boost::numeric_cast<short unsigned int >(a_int);

  int b_int;
  if (!get_val_param<int >(b_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int b = boost::numeric_cast<short unsigned int >(b_int);

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(long long int a, long long int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long a_long;
  if (!get_val_param<long >(a_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int a = boost::numeric_cast<long long int >(a_long);

  long b_long;
  if (!get_val_param<long >(b_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int b = boost::numeric_cast<long long int >(b_long);

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/
/*
 * The following types are missing: long long unsigned int, long long unsigned int
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxIntegerEqual::()(long long unsigned int a, long long unsigned int b)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'a'")
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'b'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int a;
  if (!get_val_param<long long unsigned int >(a,_p,_n,true,true)) ClassReturnEmptyVar;

  long long unsigned int b;
  if (!get_val_param<long long unsigned int >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->()(a, b);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxIntegerEqual & wxIntegerEqual::operator =(wxIntegerEqual const & param0)
//---------------------------------------------------
void WrapClass_wxIntegerEqual::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIntegerEqual, "parameter named 'param0'")
  return_comments="returning a variable of type wxIntegerEqual";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerEqual::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIntegerEqual > param0_smtptr;
  if (!get_val_smtptr_param<wxIntegerEqual >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIntegerEqual const & param0 = *param0_smtptr;

  wxIntegerEqual & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxIntegerEqual >::CreateVar(res);
}

