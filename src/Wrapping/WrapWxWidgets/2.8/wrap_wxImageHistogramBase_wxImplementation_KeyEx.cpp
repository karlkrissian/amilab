/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_KeyEx
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_KeyEx
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxImageHistogramBase_wxImplementation_KeyEx.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxImageHistogramBase_wxImplementation_KeyEx_declared
  #define wxImageHistogramBase_wxImplementation_KeyEx_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_KeyEx)
#endif
#ifndef wxImageHistogramBase_wxImplementation_Pair_declared
  #define wxImageHistogramBase_wxImplementation_Pair_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_Pair)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::wrap_wxImageHistogramBase_wxImplementation_KeyEx construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogramBase_wxImplementation_KeyEx);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogramBase_wxImplementation_KeyEx);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogramBase_wxImplementation_KeyEx
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::CreateVar( wxImageHistogramBase_wxImplementation_KeyEx* sp)
{
  boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogramBase_wxImplementation_KeyEx>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::CreateVar(
      new WrapClass_wxImageHistogramBase_wxImplementation_KeyEx(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_KeyEx>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  // AddVar_operator not available( this_ptr);
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHistogramBase_wxImplementation_KeyEx_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxImageHistogramBase_wxImplementation_KeyEx");
    WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::AddVar_wxImageHistogramBase_wxImplementation_KeyEx_1(amiobject->GetContext());
  WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::AddVar_wxImageHistogramBase_wxImplementation_KeyEx(amiobject->GetContext());
  WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::AddVar_wxImageHistogramBase_wxImplementation_KeyEx_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx(wxImageHistogramBase_wxImplementation_KeyEx const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_KeyEx, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_KeyEx >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxImageHistogramBase_wxImplementation_KeyEx const & param0 = *param0_smtptr;

  wxImageHistogramBase_wxImplementation_KeyEx* _newobj = new wxImageHistogramBase_wxImplementation_KeyEx(param0);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::wrap_wxImageHistogramBase_wxImplementation_KeyEx_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::wrap_wxImageHistogramBase_wxImplementation_KeyEx_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_KeyEx::wxImageHistogramBase_wxImplementation_KeyEx()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_wxImageHistogramBase_wxImplementation_KeyEx_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxImageHistogramBase_wxImplementation_KeyEx* _newobj = new wxImageHistogramBase_wxImplementation_KeyEx();
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogramBase_wxImplementation_KeyEx.
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogramBase_wxImplementation_KeyEx object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogramBase_wxImplementation_KeyEx >::CreateVar( new wxImageHistogramBase_wxImplementation_KeyEx(*(this->_objectptr->GetObj())));
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of long unsigned int const & wxImageHistogramBase_wxImplementation_KeyEx::()(wxImageHistogramBase_wxImplementation_Pair const & pair)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_Pair, "parameter named 'pair'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair > pair_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_Pair >(pair_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramBase_wxImplementation_Pair const & pair = *pair_smtptr;

  long unsigned int const & res =   this->_objectptr->GetObj()->()(pair);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of wxImageHistogramBase_wxImplementation_KeyEx & wxImageHistogramBase_wxImplementation_KeyEx::operator =(wxImageHistogramBase_wxImplementation_KeyEx const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_KeyEx, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHistogramBase_wxImplementation_KeyEx";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_KeyEx::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_KeyEx >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramBase_wxImplementation_KeyEx const & param0 = *param0_smtptr;

  wxImageHistogramBase_wxImplementation_KeyEx & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHistogramBase_wxImplementation_KeyEx >::CreateVar(res);
}

