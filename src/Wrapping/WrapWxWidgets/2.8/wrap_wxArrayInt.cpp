/**
 * C++ Interface: wrap_wxArrayInt
 *
 * Description: wrapping wxArrayInt
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

#include "wrap_wxArrayInt.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxArrayInt_declared
  #define wxArrayInt_declared
  AMI_DECLARE_TYPE(wxArrayInt)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxArrayInt>::CreateVar( ParamList* p)
{
  WrapClass_wxArrayInt::wrap_wxArrayInt construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxArrayInt);
AMI_DEFINE_VARFROMSMTPTR(wxArrayInt);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxArrayInt
//
Variable<AMIObject>::ptr WrapClass_wxArrayInt::CreateVar( wxArrayInt* sp)
{
  boost::shared_ptr<wxArrayInt> di_ptr(
    sp,
    wxwindow_nodeleter<wxArrayInt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxArrayInt>::CreateVar(
      new WrapClass_wxArrayInt(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxArrayInt::AddMethods(WrapClass<wxArrayInt>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Item( this_ptr);
  AddVar_Last( this_ptr);
  AddVar_Index( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Insert( this_ptr);
  AddVar_RemoveAt( this_ptr);
  AddVar_Remove( this_ptr);
/* The following types are missing: _17784
  AddVar_Sort( this_ptr);
*/
  AddVar_assign_1( this_ptr);
  AddVar_assign( this_ptr);
  AddVar_assign_2( this_ptr);
  AddVar_back_1( this_ptr);
  AddVar_back( this_ptr);
  AddVar_back_2( this_ptr);
  AddVar_begin_1( this_ptr);
  AddVar_begin( this_ptr);
  AddVar_begin_2( this_ptr);
  AddVar_capacity( this_ptr);
  AddVar_end_1( this_ptr);
  AddVar_end( this_ptr);
  AddVar_end_2( this_ptr);
  AddVar_erase_1( this_ptr);
  AddVar_erase( this_ptr);
  AddVar_erase_2( this_ptr);
  AddVar_front_1( this_ptr);
  AddVar_front( this_ptr);
  AddVar_front_2( this_ptr);
  AddVar_insert_1( this_ptr);
  AddVar_insert( this_ptr);
  AddVar_insert_2( this_ptr);
  AddVar_insert_3( this_ptr);
  AddVar_pop_back( this_ptr);
  AddVar_push_back( this_ptr);
/* The following types are missing: reverse_iterator
  AddVar_rbegin_1( this_ptr);
*/
  AddVar_rbegin( this_ptr);
/* The following types are missing: const_reverse_iterator
  AddVar_rbegin_2( this_ptr);
*/
/* The following types are missing: reverse_iterator
  AddVar_rend_1( this_ptr);
*/
  AddVar_rend( this_ptr);
/* The following types are missing: const_reverse_iterator
  AddVar_rend_2( this_ptr);
*/
  AddVar_reserve( this_ptr);
  AddVar_resize( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___at__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxBaseArrayInt
  boost::shared_ptr<wxBaseArrayInt > parent_wxBaseArrayInt(  boost::dynamic_pointer_cast<wxBaseArrayInt >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBaseArrayInt = AMILabType<wxBaseArrayInt >::CreateVarFromSmtPtr(parent_wxBaseArrayInt);
  context->AddVar("wxBaseArrayInt",var_wxBaseArrayInt);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBaseArrayInt = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBaseArrayInt);
  context->AddDefault(obj_wxBaseArrayInt->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxArrayInt_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxArrayInt");
    WrapClass_wxArrayInt::AddVar_wxArrayInt_1(amiobject->GetContext());
  WrapClass_wxArrayInt::AddVar_wxArrayInt(amiobject->GetContext());
  WrapClass_wxArrayInt::AddVar_wxArrayInt_2(amiobject->GetContext());
  WrapClass_wxArrayInt::AddVar_wxArrayInt_3(amiobject->GetContext());
  WrapClass_wxArrayInt::AddVar_wxArrayInt_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxArrayInt::wxArrayInt(wxArrayInt const & param0)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_wxArrayInt_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArrayInt, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_wxArrayInt_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxArrayInt > param0_smtptr;
  if (!get_val_smtptr_param<wxArrayInt >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxArrayInt const & param0 = *param0_smtptr;

  wxArrayInt* _newobj = new wxArrayInt(param0);
  BasicVariable::ptr res = WrapClass_wxArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxArrayInt::wxArrayInt(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_wxArrayInt::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_wxArrayInt::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_wxArrayInt_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_wxArrayInt_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_wxArrayInt_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_wxArrayInt_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxArrayInt::wxArrayInt()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_wxArrayInt_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_wxArrayInt_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxArrayInt* _newobj = new wxArrayInt();
  BasicVariable::ptr res = WrapClass_wxArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxArrayInt::wxArrayInt(size_t n, _wxArraywxArrayInt const & v)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_wxArrayInt_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_wxArrayInt_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<int > v_smtptr;
  if (!get_val_smtptr_param<int >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxArraywxArrayInt const & v = *v_smtptr;

  wxArrayInt* _newobj = new wxArrayInt(n, v);
  BasicVariable::ptr res = WrapClass_wxArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxArrayInt::wxArrayInt(_wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_wxArrayInt_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_wxArrayInt_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int* first;
  if (CheckNullVar(_p,_n))  {
    first=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > first_smtptr;
    if (!get_val_smtptr_param<int >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    first = first_smtptr.get();
  }

  int* last;
  if (CheckNullVar(_p,_n))  {
    last=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > last_smtptr;
    if (!get_val_smtptr_param<int >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    last = last_smtptr.get();
  }

  wxArrayInt* _newobj = new wxArrayInt(first, last);
  BasicVariable::ptr res = WrapClass_wxArrayInt::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxArrayInt.
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxArrayInt object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxArrayInt >::CreateVar( new wxArrayInt(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt & wxArrayInt::Item(size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Item::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Item::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxArraywxArrayInt & res =   this->_objectptr->GetObj()->Item(uiIndex);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt & wxArrayInt::Last()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Last::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Last::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  _wxArraywxArrayInt & res =   this->_objectptr->GetObj()->Last();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxArrayInt::Index(_wxArraywxArrayInt lItem, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Index::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Index::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int lItem;
  if (!get_val_param<int >(lItem,_p,_n,true,false)) ClassHelpAndReturn;

  bool bFromEnd = false;
  if (!get_val_param<bool >(bFromEnd,_p,_n,false,false)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Index(lItem, bFromEnd);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::Add(_wxArraywxArrayInt lItem, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int lItem;
  if (!get_val_param<int >(lItem,_p,_n,true,false)) ClassHelpAndReturn;

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Add(lItem, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::Insert(_wxArraywxArrayInt lItem, size_t uiIndex, size_t nInsert = 1)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lItem'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nInsert' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int lItem;
  if (!get_val_param<int >(lItem,_p,_n,true,false)) ClassHelpAndReturn;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  long nInsert_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nInsert_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int nInsert = boost::numeric_cast<long unsigned int >(nInsert_long);

  this->_objectptr->GetObj()->Insert(lItem, uiIndex, nInsert);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::RemoveAt(size_t uiIndex, size_t nRemove = 1)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_RemoveAt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRemove' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_RemoveAt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  long nRemove_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nRemove_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int nRemove = boost::numeric_cast<long unsigned int >(nRemove_long);

  this->_objectptr->GetObj()->RemoveAt(uiIndex, nRemove);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::Remove(_wxArraywxArrayInt lItem)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'lItem'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int lItem;
  if (!get_val_param<int >(lItem,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Remove(lItem);
  return BasicVariable::ptr();
}
/* The following types are missing: _17784

//---------------------------------------------------
//  Wrapping of void wxArrayInt::Sort(CMPFUNC_wxArraywxArrayInt fCmp)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _17784, "parameter named 'fCmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _17784 fCmp;
  if (!get_val_param<_17784 >(fCmp,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sort(fCmp);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxArrayInt::assign(_wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int* first;
  if (CheckNullVar(_p,_n))  {
    first=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > first_smtptr;
    if (!get_val_smtptr_param<int >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    first = first_smtptr.get();
  }

  int* last;
  if (CheckNullVar(_p,_n))  {
    last=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > last_smtptr;
    if (!get_val_smtptr_param<int >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    last = last_smtptr.get();
  }

  this->_objectptr->GetObj()->assign(first, last);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::assign(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_assign_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::assign(size_t n, _wxArraywxArrayInt const & v)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<int > v_smtptr;
  if (!get_val_smtptr_param<int >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxArraywxArrayInt const & v = *v_smtptr;

  this->_objectptr->GetObj()->assign(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt & wxArrayInt::back()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_back_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_back_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt & res =   this->_objectptr->GetObj()->back();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::back(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_back::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_back::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_back_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_back_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt const & wxArrayInt::back()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_back_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_back_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt const & res =   this->_objectptr->GetObj()->back();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt * wxArrayInt::begin()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt * res =   this->_objectptr->GetObj()->begin();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::begin(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_begin_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_begin_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt const * wxArrayInt::begin()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt const * res =   this->_objectptr->GetObj()->begin();
  return AMILabType<int >::CreateVar(const_cast<_wxArraywxArrayInt *>(res),true);
}

//---------------------------------------------------
//  Wrapping of size_t wxArrayInt::capacity()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_capacity::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_capacity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->capacity();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt * wxArrayInt::end()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt * res =   this->_objectptr->GetObj()->end();
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::end(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_end_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_end_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt const * wxArrayInt::end()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt const * res =   this->_objectptr->GetObj()->end();
  return AMILabType<int >::CreateVar(const_cast<_wxArraywxArrayInt *>(res),true);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt * wxArrayInt::erase(_wxArraywxArrayInt * first, _wxArraywxArrayInt * last)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'last'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int* first;
  if (CheckNullVar(_p,_n))  {
    first=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > first_smtptr;
    if (!get_val_smtptr_param<int >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    first = first_smtptr.get();
  }

  int* last;
  if (CheckNullVar(_p,_n))  {
    last=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > last_smtptr;
    if (!get_val_smtptr_param<int >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    last = last_smtptr.get();
  }

  _wxArraywxArrayInt * res =   this->_objectptr->GetObj()->erase(first, last);
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::erase(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_erase_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_erase_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt * wxArrayInt::erase(_wxArraywxArrayInt * it)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'it'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int* it;
  if (CheckNullVar(_p,_n))  {
    it=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > it_smtptr;
    if (!get_val_smtptr_param<int >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    it = it_smtptr.get();
  }

  _wxArraywxArrayInt * res =   this->_objectptr->GetObj()->erase(it);
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt & wxArrayInt::front()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_front_1::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_front_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt & res =   this->_objectptr->GetObj()->front();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::front(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_front::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_front::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_front_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_front_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt const & wxArrayInt::front()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_front_2::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_front_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  _wxArraywxArrayInt const & res =   this->_objectptr->GetObj()->front();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::insert(_wxArraywxArrayInt * it, size_t n, _wxArraywxArrayInt const & v)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int* it;
  if (CheckNullVar(_p,_n))  {
    it=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > it_smtptr;
    if (!get_val_smtptr_param<int >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    it = it_smtptr.get();
  }

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  boost::shared_ptr<int > v_smtptr;
  if (!get_val_smtptr_param<int >(v_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  _wxArraywxArrayInt const & v = *v_smtptr;

  this->_objectptr->GetObj()->insert(it, n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::insert(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxArrayInt::wrap_insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxArrayInt::wrap_insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt * wxArrayInt::insert(_wxArraywxArrayInt * it, _wxArraywxArrayInt const & v = 0)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int* it;
  if (CheckNullVar(_p,_n))  {
    it=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > it_smtptr;
    if (!get_val_smtptr_param<int >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    it = it_smtptr.get();
  }

  boost::shared_ptr<int > v_smtptr;
  if (!get_val_smtptr_param<int >(v_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  _wxArraywxArrayInt const & v = ( v_smtptr.get() ? (*v_smtptr) : int(0) );

  _wxArraywxArrayInt * res =   this->_objectptr->GetObj()->insert(it, v);
  return AMILabType<int >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::insert(_wxArraywxArrayInt * it, _wxArraywxArrayInt const * first, _wxArraywxArrayInt const * last)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int* it;
  if (CheckNullVar(_p,_n))  {
    it=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > it_smtptr;
    if (!get_val_smtptr_param<int >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    it = it_smtptr.get();
  }

  int* first;
  if (CheckNullVar(_p,_n))  {
    first=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > first_smtptr;
    if (!get_val_smtptr_param<int >(first_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    first = first_smtptr.get();
  }

  int* last;
  if (CheckNullVar(_p,_n))  {
    last=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > last_smtptr;
    if (!get_val_smtptr_param<int >(last_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    last = last_smtptr.get();
  }

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::pop_back()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_pop_back::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_pop_back::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->pop_back();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::push_back(_wxArraywxArrayInt const & v)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > v_smtptr;
  if (!get_val_smtptr_param<int >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  _wxArraywxArrayInt const & v = *v_smtptr;

  this->_objectptr->GetObj()->push_back(v);
  return BasicVariable::ptr();
}
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxArrayInt::rbegin()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::rbegin(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxArrayInt::rbegin()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxArrayInt::rend()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxArrayInt::rend(...)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxArrayInt::rend()
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxArrayInt::reserve(size_t n)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_reserve::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_reserve::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  this->_objectptr->GetObj()->reserve(n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxArrayInt::resize(size_t n, _wxArraywxArrayInt v = 0)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'v' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  int v = 0;
  if (!get_val_param<int >(v,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->resize(n, v);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxArrayInt & wxArrayInt::operator =(wxArrayInt const & src)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxArrayInt, "parameter named 'src'")
  return_comments="returning a variable of type wxArrayInt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxArrayInt > src_smtptr;
  if (!get_val_smtptr_param<wxArrayInt >(src_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArrayInt const & src = *src_smtptr;

  wxArrayInt & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxArrayInt >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of _wxArraywxArrayInt & wxArrayInt::operator [](size_t uiIndex)
//---------------------------------------------------
void WrapClass_wxArrayInt::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiIndex'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxArrayInt::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiIndex_long;
  if (!get_val_param<long >(uiIndex_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int uiIndex = boost::numeric_cast<long unsigned int >(uiIndex_long);

  _wxArraywxArrayInt & res =   (*this->_objectptr->GetObj()) [ (uiIndex)];
  return AMILabType<int >::CreateVar(res);
}

