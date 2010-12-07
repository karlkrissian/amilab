/**
 * C++ Interface: wrap_wxBaseArrayInt
 *
 * Description: wrapping wxBaseArrayInt
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
#include "wrap_wxBaseArrayInt.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_wxBaseArrayInt.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBaseArrayInt>::CreateVar( ParamList* p)
{
  WrapClass_wxBaseArrayInt::wrap_wxBaseArrayInt construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBaseArrayInt);
AMI_DEFINE_VARFROMSMTPTR(wxBaseArrayInt);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBaseArrayInt
//
Variable<AMIObject>::ptr WrapClass_wxBaseArrayInt::CreateVar( wxBaseArrayInt* sp)
{
  boost::shared_ptr<wxBaseArrayInt> di_ptr(
    sp,
    wxwindow_nodeleter<wxBaseArrayInt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBaseArrayInt>::CreateVar(
      new WrapClass_wxBaseArrayInt(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBaseArrayInt::AddMethods(WrapClass<wxBaseArrayInt>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Empty( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_Alloc( this_ptr);
      AddVar_Shrink( this_ptr);
      AddVar_GetCount( this_ptr);
      AddVar_SetCount( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_Count( this_ptr);
      AddVar_clear( this_ptr);
      AddVar_empty( this_ptr);
      AddVar_max_size( this_ptr);
      AddVar_size( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxBaseArrayInt::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBaseArrayInt");
    WrapClass_wxBaseArrayInt::AddVar_wxBaseArrayInt_1(amiobject->GetContext());
  WrapClass_wxBaseArrayInt::AddVar_wxBaseArrayInt(amiobject->GetContext());
  WrapClass_wxBaseArrayInt::AddVar_wxBaseArrayInt_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBaseArrayInt::wxBaseArrayInt()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBaseArrayInt* _newobj = new wxBaseArrayInt();
  BasicVariable::ptr res = WrapClass_wxBaseArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBaseArrayInt::wxBaseArrayInt(...)
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBaseArrayInt::wrap_wxBaseArrayInt_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBaseArrayInt::wrap_wxBaseArrayInt_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBaseArrayInt::wxBaseArrayInt(wxBaseArrayInt const & array)
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBaseArrayInt, "parameter named 'array'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_wxBaseArrayInt_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBaseArrayInt > array_smtptr;
  if (!get_val_smtptr_param<wxBaseArrayInt >(array_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBaseArrayInt const & array = *array_smtptr;

  wxBaseArrayInt* _newobj = new wxBaseArrayInt(array);
  BasicVariable::ptr res = WrapClass_wxBaseArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBaseArrayInt.
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBaseArrayInt object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBaseArrayInt >::CreateVar( new wxBaseArrayInt(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::Empty()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_Empty::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Empty();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::Clear()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::Alloc(size_t n)
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_Alloc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  this->_objectptr->GetObj()->Alloc(n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::Shrink()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_Shrink::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_Shrink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Shrink();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxBaseArrayInt::GetCount()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::SetCount(size_t n, _wxArraywxBaseArrayInt defval = 0)
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_SetCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'defval' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_SetCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  int defval = 0;
  if (!get_val_param<int >(defval,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCount(n, defval);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxBaseArrayInt::IsEmpty()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxBaseArrayInt::Count()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_Count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_Count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxBaseArrayInt::clear()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxBaseArrayInt::empty()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxBaseArrayInt::max_size()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxBaseArrayInt::size()
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxBaseArrayInt & wxBaseArrayInt::operator =(wxBaseArrayInt const & src)
//---------------------------------------------------
void WrapClass_wxBaseArrayInt::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBaseArrayInt, "parameter named 'src'")
  return_comments="returning a variable of type wxBaseArrayInt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBaseArrayInt::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBaseArrayInt > src_smtptr;
  if (!get_val_smtptr_param<wxBaseArrayInt >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBaseArrayInt const & src = *src_smtptr;

  wxBaseArrayInt & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxBaseArrayInt >::CreateVar(res);
}

