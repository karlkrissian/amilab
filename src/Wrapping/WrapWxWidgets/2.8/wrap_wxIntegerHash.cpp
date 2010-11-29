/**
 * C++ Interface: wrap_wxIntegerHash
 *
 * Description: wrapping wxIntegerHash
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
#include "wrap_wxIntegerHash.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxIntegerHash.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxIntegerHash>::CreateVar( ParamList* p)
{
  WrapClass_wxIntegerHash::wrap_wxIntegerHash construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIntegerHash);
AMI_DEFINE_VARFROMSMTPTR(wxIntegerHash);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIntegerHash
//
Variable<AMIObject>::ptr WrapClass_wxIntegerHash::CreateVar( wxIntegerHash* sp)
{
  boost::shared_ptr<wxIntegerHash> di_ptr(
    sp,
    wxwindow_nodeleter<wxIntegerHash>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIntegerHash>::CreateVar(
      new WrapClass_wxIntegerHash(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIntegerHash::AddMethods(WrapClass<wxIntegerHash>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: short int
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
/* The following types are missing: long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: long long unsigned int, long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIntegerHash::wxIntegerHash(wxIntegerHash const & param0)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_wxIntegerHash_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIntegerHash, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_wxIntegerHash_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIntegerHash > param0_smtptr;
  if (!get_val_smtptr_param<wxIntegerHash >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIntegerHash const & param0 = *param0_smtptr;

  wxIntegerHash* _newobj = new wxIntegerHash(param0);
  BasicVariable::ptr res = WrapClass_wxIntegerHash::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIntegerHash::wxIntegerHash(...)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_wxIntegerHash::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_wxIntegerHash::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIntegerHash::wrap_wxIntegerHash_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIntegerHash::wrap_wxIntegerHash_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIntegerHash::wxIntegerHash()
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_wxIntegerHash_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_wxIntegerHash_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxIntegerHash* _newobj = new wxIntegerHash();
  BasicVariable::ptr res = WrapClass_wxIntegerHash::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIntegerHash.
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIntegerHash object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIntegerHash >::CreateVar( new wxIntegerHash(*(this->_objectptr->GetObj())));
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(long int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long x_long;
  if (!get_val_param<long >(x_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int x = x_long;

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxIntegerHash::()(...)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(long unsigned int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long x_long;
  if (!get_val_param<long >(x_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int x = boost::numeric_cast<long unsigned int >(x_long);

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(unsigned int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long x_long;
  if (!get_val_param<long >(x_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int x = boost::numeric_cast<unsigned int >(x_long);

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * The following types are missing: short int
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(short int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( short int, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  short int x;
  if (!get_val_param<short int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int wxIntegerHash::()(short unsigned int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int x_int;
  if (!get_val_param<int >(x_int,_p,_n,true,true)) ClassReturnEmptyVar;
  short unsigned int x = boost::numeric_cast<short unsigned int >(x_int);

  long unsigned int res =   this->_objectptr->GetObj()->()(x);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/
/*
 * The following types are missing: long long unsigned int
 * operator not available 

//---------------------------------------------------
//  Wrapping of long long unsigned int wxIntegerHash::()(long long int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'x'")
  return_comments="returning a variable of type long long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long x_long;
  if (!get_val_param<long >(x_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long long int x = boost::numeric_cast<long long int >(x_long);

  long long unsigned int res =   this->_objectptr->GetObj()->()(x);
  return AMILabType<long long unsigned int >::CreateVar(res);
}
*/
/*
 * The following types are missing: long long unsigned int, long long unsigned int
 * operator not available 

//---------------------------------------------------
//  Wrapping of long long unsigned int wxIntegerHash::()(long long unsigned int x)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'x'")
  return_comments="returning a variable of type long long unsigned int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int x;
  if (!get_val_param<long long unsigned int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  long long unsigned int res =   this->_objectptr->GetObj()->()(x);
  return AMILabType<long long unsigned int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxIntegerHash & wxIntegerHash::operator =(wxIntegerHash const & param0)
//---------------------------------------------------
void WrapClass_wxIntegerHash::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIntegerHash, "parameter named 'param0'")
  return_comments="returning a variable of type wxIntegerHash";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIntegerHash::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIntegerHash > param0_smtptr;
  if (!get_val_smtptr_param<wxIntegerHash >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIntegerHash const & param0 = *param0_smtptr;

  wxIntegerHash & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxIntegerHash >::CreateVar(res);
}

