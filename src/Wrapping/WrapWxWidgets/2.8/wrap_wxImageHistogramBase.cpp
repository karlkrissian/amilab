/**
 * C++ Interface: wrap_wxImageHistogramBase
 *
 * Description: wrapping wxImageHistogramBase
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
#include "wrap_wxImageHistogramBase.h"
#include "wrap_wxIntegerHash.h"
#include "wrap_wxIntegerEqual.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxImageHistogramBase_wxImplementation_Pair.h"
#include "wrap_wxImageHistogramEntry.h"


#include "wrap_wxImageHistogramBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogramBase>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogramBase::wrap_wxImageHistogramBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogramBase);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogramBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogramBase
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogramBase::CreateVar( wxImageHistogramBase* sp)
{
  boost::shared_ptr<wxImageHistogramBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogramBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogramBase>::CreateVar(
      new WrapClass_wxImageHistogramBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogramBase::AddMethods(WrapClass<wxImageHistogramBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: const_iterator
      AddVar_find_1( this_ptr);
*/
      AddVar_find( this_ptr);
/* The following types are missing: iterator
      AddVar_find_2( this_ptr);
*/
/* The following types are missing: Insert_Result
      AddVar_insert( this_ptr);
*/
      AddVar_erase_1( this_ptr);
      AddVar_erase( this_ptr);
/* The following types are missing: iterator
      AddVar_erase_2( this_ptr);
*/
/* The following types are missing: const_iterator
      AddVar_erase_3( this_ptr);
*/
      AddVar_count( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___at__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxImageHistogramBase_wxImplementation_HashTable
  boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable > parent_wxImageHistogramBase_wxImplementation_HashTable(  boost::dynamic_pointer_cast<wxImageHistogramBase_wxImplementation_HashTable >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxImageHistogramBase_wxImplementation_HashTable = AMILabType<wxImageHistogramBase_wxImplementation_HashTable >::CreateVarFromSmtPtr(parent_wxImageHistogramBase_wxImplementation_HashTable);
  context->AddVar("wxImageHistogramBase_wxImplementation_HashTable",var_wxImageHistogramBase_wxImplementation_HashTable);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxImageHistogramBase_wxImplementation_HashTable = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxImageHistogramBase_wxImplementation_HashTable);
  context->AddDefault(obj_wxImageHistogramBase_wxImplementation_HashTable->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxImageHistogramBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxImageHistogramBase");
    WrapClass_wxImageHistogramBase::AddVar_wxImageHistogramBase_1(amiobject->GetContext());
  WrapClass_wxImageHistogramBase::AddVar_wxImageHistogramBase(amiobject->GetContext());
  WrapClass_wxImageHistogramBase::AddVar_wxImageHistogramBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase::wxImageHistogramBase(wxImageHistogramBase const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxImageHistogramBase const & param0 = *param0_smtptr;

  wxImageHistogramBase* _newobj = new wxImageHistogramBase(param0);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogramBase::wxImageHistogramBase(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramBase::wrap_wxImageHistogramBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogramBase::wrap_wxImageHistogramBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase::wxImageHistogramBase(size_t hint = 100, wxIntegerHash hf = wxIntegerHash(), wxIntegerEqual eq = wxIntegerEqual())
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'hint' (def:100)")
  ADDPARAMCOMMENT_TYPE( wxIntegerHash, "parameter named 'hf' (def:wxIntegerHash())")
  ADDPARAMCOMMENT_TYPE( wxIntegerEqual, "parameter named 'eq' (def:wxIntegerEqual())")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_wxImageHistogramBase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long hint_long = boost::numeric_cast<long >(100);;
  if (!get_val_param<long >(hint_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int hint = boost::numeric_cast<long unsigned int >(hint_long);

  wxIntegerHash hf = wxIntegerHash();
  if (!get_val_param<wxIntegerHash >(hf,_p,_n,false,true)) ClassReturnEmptyVar;

  wxIntegerEqual eq = wxIntegerEqual();
  if (!get_val_param<wxIntegerEqual >(eq,_p,_n,false,true)) ClassReturnEmptyVar;

  wxImageHistogramBase* _newobj = new wxImageHistogramBase(hint, hf, eq);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogramBase.
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogramBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogramBase >::CreateVar( new wxImageHistogramBase(*(this->_objectptr->GetObj())));
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxImageHistogramBase::find(long unsigned int const & key)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long unsigned int > key_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long unsigned int const & key = *key_smtptr;

  const_iterator res =   this->_objectptr->GetObj()->find(key);
  return AMILabType<const_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImageHistogramBase::find(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxImageHistogramBase::find(long unsigned int const & key)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long unsigned int > key_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(key_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long unsigned int const & key = *key_smtptr;

  iterator res =   this->_objectptr->GetObj()->find(key);
  return AMILabType<iterator >::CreateVar(res);
}
*/
/* The following types are missing: Insert_Result

//---------------------------------------------------
//  Wrapping of Insert_Result wxImageHistogramBase::insert(wxImageHistogramBase_wxImplementation_Pair const & v)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_insert::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_Pair, "parameter named 'v'")
  return_comments="returning a variable of type Insert_Result";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_insert::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_Pair > v_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_Pair >(v_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramBase_wxImplementation_Pair const & v = *v_smtptr;

  Insert_Result res =   this->_objectptr->GetObj()->insert(v);
  return AMILabType<Insert_Result >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxImageHistogramBase::erase(long unsigned int const & k)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'k'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<long unsigned int > k_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(k_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  long unsigned int const & k = *k_smtptr;

  size_t res =   this->_objectptr->GetObj()->erase(k);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImageHistogramBase::erase(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramBase::wrap_erase_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxImageHistogramBase::erase(iterator const & it)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<iterator > it_smtptr;
  if (!get_val_smtptr_param<iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  iterator const & it = *it_smtptr;

  this->_objectptr->GetObj()->erase(it);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of void wxImageHistogramBase::erase(const_iterator const & it)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_erase_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'it'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_erase_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<const_iterator > it_smtptr;
  if (!get_val_smtptr_param<const_iterator >(it_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  const_iterator const & it = *it_smtptr;

  this->_objectptr->GetObj()->erase(it);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxImageHistogramBase::count(long unsigned int const & key)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap_count::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap_count::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long unsigned int > key_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(key_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int const & key = *key_smtptr;

  size_t res =   this->_objectptr->GetObj()->count(key);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxImageHistogramBase & wxImageHistogramBase::operator =(wxImageHistogramBase const & param0)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxImageHistogramBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase > param0_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramBase const & param0 = *param0_smtptr;

  wxImageHistogramBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImageHistogramBase >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImageHistogramEntry & wxImageHistogramBase::operator [](long unsigned int const & key)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  return_comments="returning a variable of type wxImageHistogramEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long unsigned int > key_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(key_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int const & key = *key_smtptr;

  wxImageHistogramEntry & res =   (*this->_objectptr->GetObj()) [ (key)];
  return AMILabType<wxImageHistogramEntry >::CreateVar(res);
}

