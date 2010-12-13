/**
 * C++ Interface: wrap_wxImageHistogramBase_wxImplementation_HashTable
 *
 * Description: wrapping wxImageHistogramBase_wxImplementation_HashTable
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

#include "wrap_wxImageHistogramBase_wxImplementation_HashTable.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxIntegerHash_declared
  #define wxIntegerHash_declared
  AMI_DECLARE_TYPE(wxIntegerHash)
#endif
#ifndef wxIntegerEqual_declared
  #define wxIntegerEqual_declared
  AMI_DECLARE_TYPE(wxIntegerEqual)
#endif
#ifndef wxImageHistogramBase_wxImplementation_KeyEx_declared
  #define wxImageHistogramBase_wxImplementation_KeyEx_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_KeyEx)
#endif
#ifndef wxImageHistogramBase_wxImplementation_HashTable_declared
  #define wxImageHistogramBase_wxImplementation_HashTable_declared
  AMI_DECLARE_TYPE(wxImageHistogramBase_wxImplementation_HashTable)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::CreateVar( ParamList* p)
{
  WrapClass_wxImageHistogramBase_wxImplementation_HashTable::wrap_wxImageHistogramBase_wxImplementation_HashTable construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImageHistogramBase_wxImplementation_HashTable);
AMI_DEFINE_VARFROMSMTPTR(wxImageHistogramBase_wxImplementation_HashTable);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImageHistogramBase_wxImplementation_HashTable
//
Variable<AMIObject>::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::CreateVar( wxImageHistogramBase_wxImplementation_HashTable* sp)
{
  boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable> di_ptr(
    sp,
    wxwindow_nodeleter<wxImageHistogramBase_wxImplementation_HashTable>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::CreateVar(
      new WrapClass_wxImageHistogramBase_wxImplementation_HashTable(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::AddMethods(WrapClass<wxImageHistogramBase_wxImplementation_HashTable>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_hash_funct( this_ptr);
  AddVar_key_eq( this_ptr);
  AddVar_clear( this_ptr);
  AddVar_size( this_ptr);
  AddVar_max_size( this_ptr);
  AddVar_empty( this_ptr);
/* The following types are missing: const_iterator
  AddVar_end_1( this_ptr);
*/
  AddVar_end( this_ptr);
/* The following types are missing: iterator
  AddVar_end_2( this_ptr);
*/
/* The following types are missing: const_iterator
  AddVar_begin_1( this_ptr);
*/
  AddVar_begin( this_ptr);
/* The following types are missing: iterator
  AddVar_begin_2( this_ptr);
*/
  AddVar_erase( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHistogramBase_wxImplementation_HashTable_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxImageHistogramBase_wxImplementation_HashTable");
    WrapClass_wxImageHistogramBase_wxImplementation_HashTable::AddVar_wxImageHistogramBase_wxImplementation_HashTable_1(amiobject->GetContext());
  WrapClass_wxImageHistogramBase_wxImplementation_HashTable::AddVar_wxImageHistogramBase_wxImplementation_HashTable(amiobject->GetContext());
  WrapClass_wxImageHistogramBase_wxImplementation_HashTable::AddVar_wxImageHistogramBase_wxImplementation_HashTable_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable(size_t sz = 10, wxIntegerHash const & hfun = wxIntegerHash(), wxIntegerEqual const & k_eq = wxIntegerEqual(), wxImageHistogramBase_wxImplementation_KeyEx const & k_ex = wxImageHistogramBase_wxImplementation_KeyEx())
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'sz' (def:10)")
  ADDPARAMCOMMENT_TYPE( wxIntegerHash, "parameter named 'hfun' (def:wxIntegerHash())")
  ADDPARAMCOMMENT_TYPE( wxIntegerEqual, "parameter named 'k_eq' (def:wxIntegerEqual())")
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_KeyEx, "parameter named 'k_ex' (def:wxImageHistogramBase_wxImplementation_KeyEx())")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long sz_long = boost::numeric_cast<long >(10);;
  if (!get_val_param<long >(sz_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int sz = boost::numeric_cast<long unsigned int >(sz_long);

  boost::shared_ptr<wxIntegerHash > hfun_smtptr;
  if (!get_val_smtptr_param<wxIntegerHash >(hfun_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxIntegerHash const & hfun = ( hfun_smtptr.get() ? (*hfun_smtptr) : wxIntegerHash(wxIntegerHash()) );

  boost::shared_ptr<wxIntegerEqual > k_eq_smtptr;
  if (!get_val_smtptr_param<wxIntegerEqual >(k_eq_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxIntegerEqual const & k_eq = ( k_eq_smtptr.get() ? (*k_eq_smtptr) : wxIntegerEqual(wxIntegerEqual()) );

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_KeyEx > k_ex_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_KeyEx >(k_ex_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxImageHistogramBase_wxImplementation_KeyEx const & k_ex = ( k_ex_smtptr.get() ? (*k_ex_smtptr) : wxImageHistogramBase_wxImplementation_KeyEx(wxImageHistogramBase_wxImplementation_KeyEx()) );

  wxImageHistogramBase_wxImplementation_HashTable* _newobj = new wxImageHistogramBase_wxImplementation_HashTable(sz, hfun, k_eq, k_ex);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_HashTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImageHistogramBase_wxImplementation_HashTable::wrap_wxImageHistogramBase_wxImplementation_HashTable_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImageHistogramBase_wxImplementation_HashTable::wrap_wxImageHistogramBase_wxImplementation_HashTable_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImageHistogramBase_wxImplementation_HashTable::wxImageHistogramBase_wxImplementation_HashTable(wxImageHistogramBase_wxImplementation_HashTable const & ht)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_HashTable, "parameter named 'ht'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_wxImageHistogramBase_wxImplementation_HashTable_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable > ht_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_HashTable >(ht_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxImageHistogramBase_wxImplementation_HashTable const & ht = *ht_smtptr;

  wxImageHistogramBase_wxImplementation_HashTable* _newobj = new wxImageHistogramBase_wxImplementation_HashTable(ht);
  BasicVariable::ptr res = WrapClass_wxImageHistogramBase_wxImplementation_HashTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImageHistogramBase_wxImplementation_HashTable.
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImageHistogramBase_wxImplementation_HashTable object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImageHistogramBase_wxImplementation_HashTable >::CreateVar( new wxImageHistogramBase_wxImplementation_HashTable(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxIntegerHash wxImageHistogramBase_wxImplementation_HashTable::hash_funct()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_hash_funct::SetParametersComments()
{
  return_comments="returning a variable of type wxIntegerHash";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_hash_funct::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxIntegerHash res =   this->_objectptr->GetObj()->hash_funct();
  return AMILabType<wxIntegerHash >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxIntegerEqual wxImageHistogramBase_wxImplementation_HashTable::key_eq()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_key_eq::SetParametersComments()
{
  return_comments="returning a variable of type wxIntegerEqual";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_key_eq::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxIntegerEqual res =   this->_objectptr->GetObj()->key_eq();
  return AMILabType<wxIntegerEqual >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImageHistogramBase_wxImplementation_HashTable::clear()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxImageHistogramBase_wxImplementation_HashTable::size()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxImageHistogramBase_wxImplementation_HashTable::max_size()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxImageHistogramBase_wxImplementation_HashTable::empty()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxImageHistogramBase_wxImplementation_HashTable::end()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImageHistogramBase_wxImplementation_HashTable::end(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxImageHistogramBase_wxImplementation_HashTable::end()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator >::CreateVar(res);
}
*/
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxImageHistogramBase_wxImplementation_HashTable::begin()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImageHistogramBase_wxImplementation_HashTable::begin(...)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxImageHistogramBase_wxImplementation_HashTable::begin()
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxImageHistogramBase_wxImplementation_HashTable::erase(long unsigned int const & key)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_erase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'key'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap_erase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long unsigned int > key_smtptr;
  if (!get_val_smtptr_param<long unsigned int >(key_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int const & key = *key_smtptr;

  size_t res =   this->_objectptr->GetObj()->erase(key);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxImageHistogramBase_wxImplementation_HashTable const & wxImageHistogramBase_wxImplementation_HashTable::operator =(wxImageHistogramBase_wxImplementation_HashTable const & ht)
//---------------------------------------------------
void WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogramBase_wxImplementation_HashTable, "parameter named 'ht'")
  return_comments="returning a variable of type wxImageHistogramBase_wxImplementation_HashTable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImageHistogramBase_wxImplementation_HashTable::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogramBase_wxImplementation_HashTable > ht_smtptr;
  if (!get_val_smtptr_param<wxImageHistogramBase_wxImplementation_HashTable >(ht_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxImageHistogramBase_wxImplementation_HashTable const & ht = *ht_smtptr;

  wxImageHistogramBase_wxImplementation_HashTable const & res =   (*this->_objectptr->GetObj()) = (ht);
  return AMILabType<wxImageHistogramBase_wxImplementation_HashTable >::CreateVar(res);
}

