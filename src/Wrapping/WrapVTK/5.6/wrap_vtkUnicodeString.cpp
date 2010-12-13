/**
 * C++ Interface: wrap_vtkUnicodeString
 *
 * Description: wrapping vtkUnicodeString
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

#include "wrap_vtkUnicodeString.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkUnicodeString_declared
  #define vtkUnicodeString_declared
  AMI_DECLARE_TYPE(vtkUnicodeString)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkUnicodeString>::CreateVar( ParamList* p)
{
  WrapClass_vtkUnicodeString::wrap_vtkUnicodeString construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkUnicodeString);
AMI_DEFINE_VARFROMSMTPTR(vtkUnicodeString);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkUnicodeString
//
Variable<AMIObject>::ptr WrapClass_vtkUnicodeString::CreateVar( vtkUnicodeString* sp)
{
  boost::shared_ptr<vtkUnicodeString> di_ptr(
    sp,
    wxwindow_nodeleter<vtkUnicodeString>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkUnicodeString>::CreateVar(
      new WrapClass_vtkUnicodeString(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkUnicodeString::AddMethods(WrapClass<vtkUnicodeString>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
/* The following types are missing: const_iterator
  AddVar_begin( this_ptr);
*/
/* The following types are missing: const_iterator
  AddVar_end( this_ptr);
*/
  AddVar_at( this_ptr);
  AddVar_utf8_str_1( this_ptr);
  AddVar_utf8_str( this_ptr);
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
  AddVar_utf8_str_2( this_ptr);
*/
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >
  AddVar_utf16_str_1( this_ptr);
*/
  AddVar_utf16_str( this_ptr);
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >
  AddVar_utf16_str_2( this_ptr);
*/
  AddVar_byte_count( this_ptr);
  AddVar_character_count( this_ptr);
  AddVar_empty( this_ptr);
  AddVar_push_back( this_ptr);
  AddVar_append_1( this_ptr);
  AddVar_append( this_ptr);
  AddVar_append_2( this_ptr);
/* The following types are missing: const_iterator, const_iterator
  AddVar_append_3( this_ptr);
*/
  AddVar_assign_1( this_ptr);
  AddVar_assign( this_ptr);
  AddVar_assign_2( this_ptr);
/* The following types are missing: const_iterator, const_iterator
  AddVar_assign_3( this_ptr);
*/
  AddVar_clear( this_ptr);
  AddVar_fold_case( this_ptr);
  AddVar_compare( this_ptr);
  AddVar_substr( this_ptr);
  AddVar_swap( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___at__( this_ptr);
  AddVar___add_assign___1( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add_assign___2( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkUnicodeString_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkUnicodeString");
    WrapClass_vtkUnicodeString::AddVar_vtkUnicodeString_1(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_vtkUnicodeString(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_vtkUnicodeString_2(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_vtkUnicodeString_3(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkUnicodeString::AddVar_vtkUnicodeString_4(amiobject->GetContext());
  */


  // Static methods 
  WrapClass_vtkUnicodeString::AddVar_is_utf8_1(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_is_utf8(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkUnicodeString::AddVar_is_utf8_2(amiobject->GetContext());
  */
  WrapClass_vtkUnicodeString::AddVar_from_utf8_1(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_from_utf8(amiobject->GetContext());
  WrapClass_vtkUnicodeString::AddVar_from_utf8_2(amiobject->GetContext());
  /* Types are missing
  WrapClass_vtkUnicodeString::AddVar_from_utf8_3(amiobject->GetContext());
  */
  WrapClass_vtkUnicodeString::AddVar_from_utf16(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkUnicodeString::vtkUnicodeString()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkUnicodeString* _newobj = new vtkUnicodeString();
  BasicVariable::ptr res = WrapClass_vtkUnicodeString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkUnicodeString::vtkUnicodeString(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_vtkUnicodeString_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap_vtkUnicodeString_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap_vtkUnicodeString_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkUnicodeString::vtkUnicodeString(vtkUnicodeString const & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > param0_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  vtkUnicodeString const & param0 = *param0_smtptr;

  vtkUnicodeString* _newobj = new vtkUnicodeString(param0);
  BasicVariable::ptr res = WrapClass_vtkUnicodeString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkUnicodeString::vtkUnicodeString(size_t count, vtkUnicodeStringValueType character)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'character'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  long character_long;
  if (!get_val_param<long >(character_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int character = boost::numeric_cast<unsigned int >(character_long);

  vtkUnicodeString* _newobj = new vtkUnicodeString(count, character);
  BasicVariable::ptr res = WrapClass_vtkUnicodeString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor vtkUnicodeString::vtkUnicodeString(const_iterator begin, const_iterator end)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'begin'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'end'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_vtkUnicodeString_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator begin;
  if (!get_val_param<const_iterator >(begin,_p,_n,true,true)) ClassReturnEmptyVar;

  const_iterator end;
  if (!get_val_param<const_iterator >(end,_p,_n,true,true)) ClassReturnEmptyVar;

  vtkUnicodeString* _newobj = new vtkUnicodeString(begin, end);
  BasicVariable::ptr res = WrapClass_vtkUnicodeString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of bool vtkUnicodeString::is_utf8(char const * param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_is_utf8_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'param0'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_is_utf8_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > param0_string;
  if (!get_val_smtptr_param<std::string >(param0_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * param0 = param0_string->c_str();

  bool res =   vtkUnicodeString::is_utf8(param0);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkUnicodeString::is_utf8(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_is_utf8::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_is_utf8::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_static_is_utf8_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of bool vtkUnicodeString::is_utf8(string const & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_is_utf8_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<char,std::char_traits<char>,std::allocator<char> >, "parameter named 'param0'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_is_utf8_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<char,std::char_traits<char>,std::allocator<char> > > param0_smtptr;
  if (!get_val_smtptr_param<basic_string<char,std::char_traits<char>,std::allocator<char> > >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  string const & param0 = *param0_smtptr;

  bool res =   vtkUnicodeString::is_utf8(param0);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::from_utf8(char const * param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'param0'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > param0_string;
  if (!get_val_smtptr_param<std::string >(param0_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * param0 = param0_string->c_str();

  vtkUnicodeString res =   vtkUnicodeString::from_utf8(param0);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... static vtkUnicodeString::from_utf8(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_from_utf8::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_from_utf8::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_static_from_utf8_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap_static_from_utf8_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::from_utf8(char const * begin, char const * end)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'begin'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'end'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > begin_string;
  if (!get_val_smtptr_param<std::string >(begin_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * begin = begin_string->c_str();

  boost::shared_ptr<std::string > end_string;
  if (!get_val_smtptr_param<std::string >(end_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * end = end_string->c_str();

  vtkUnicodeString res =   vtkUnicodeString::from_utf8(begin, end);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::from_utf8(string const & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<char,std::char_traits<char>,std::allocator<char> >, "parameter named 'param0'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_from_utf8_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<char,std::char_traits<char>,std::allocator<char> > > param0_smtptr;
  if (!get_val_smtptr_param<basic_string<char,std::char_traits<char>,std::allocator<char> > >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  string const & param0 = *param0_smtptr;

  vtkUnicodeString res =   vtkUnicodeString::from_utf8(param0);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::from_utf16(vtkTypeUInt16 const * param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_static_from_utf16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_static_from_utf16::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > param0_int;
  if (!get_val_smtptr_param<int >(param0_int,_p,_n,true,false,false)) ClassHelpAndReturn;
  short unsigned int param0_val = boost::numeric_cast<short unsigned int >(*param0_int);
  short unsigned int* param0 = &param0_val;

  vtkUnicodeString res =   vtkUnicodeString::from_utf16(param0);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkUnicodeString.
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkUnicodeString object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkUnicodeString >::CreateVar( new vtkUnicodeString(*(this->_objectptr->GetObj())));
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator vtkUnicodeString::begin()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_begin::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_begin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator vtkUnicodeString::end()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_end::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_end::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of vtkUnicodeStringValueType vtkUnicodeString::at(size_t offset)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_at::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'offset'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_at::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long offset_long;
  if (!get_val_param<long >(offset_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int offset = boost::numeric_cast<long unsigned int >(offset_long);

  vtkUnicodeStringValueType res =   this->_objectptr->GetObj()->at(offset);
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of char const * vtkUnicodeString::utf8_str()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf8_str_1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf8_str_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  char const * res =   this->_objectptr->GetObj()->utf8_str();
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnicodeString::utf8_str(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf8_str::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf8_str::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_utf8_str_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::utf8_str(string & result)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf8_str_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<char,std::char_traits<char>,std::allocator<char> >, "parameter named 'result'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf8_str_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<char,std::char_traits<char>,std::allocator<char> > > result_smtptr;
  if (!get_val_smtptr_param<basic_string<char,std::char_traits<char>,std::allocator<char> > >(result_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  string & result = *result_smtptr;

  this->_objectptr->GetObj()->utf8_str(result);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >

//---------------------------------------------------
//  Wrapping of vector<short unsigned int,std::allocator<short unsigned int> > vtkUnicodeString::utf16_str()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf16_str_1::SetParametersComments()
{
  return_comments="returning a variable of type vector<short unsigned int,std::allocator<short unsigned int> >";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf16_str_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vector<short unsigned int,std::allocator<short unsigned int> > res =   this->_objectptr->GetObj()->utf16_str();
  return AMILabType<vector<short unsigned int,std::allocator<short unsigned int> > >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnicodeString::utf16_str(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf16_str::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf16_str::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::utf16_str(vector<short unsigned int,std::allocator<short unsigned int> > & result)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_utf16_str_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vector<short unsigned int,std::allocator<short unsigned int> >, "parameter named 'result'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_utf16_str_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vector<short unsigned int,std::allocator<short unsigned int> > > result_smtptr;
  if (!get_val_smtptr_param<vector<short unsigned int,std::allocator<short unsigned int> > >(result_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vector<short unsigned int,std::allocator<short unsigned int> > & result = *result_smtptr;

  this->_objectptr->GetObj()->utf16_str(result);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of size_t vtkUnicodeString::byte_count()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_byte_count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_byte_count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->byte_count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t vtkUnicodeString::character_count()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_character_count::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_character_count::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->character_count();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool vtkUnicodeString::empty()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::push_back(vtkUnicodeStringValueType param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_push_back::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_push_back::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long param0_long;
  if (!get_val_param<long >(param0_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int param0 = boost::numeric_cast<unsigned int >(param0_long);

  this->_objectptr->GetObj()->push_back(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::append(vtkUnicodeString const & value)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > value_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkUnicodeString const & value = *value_smtptr;

  this->_objectptr->GetObj()->append(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnicodeString::append(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap_append_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::append(size_t count, vtkUnicodeStringValueType character)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'character'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  long character_long;
  if (!get_val_param<long >(character_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int character = boost::numeric_cast<unsigned int >(character_long);

  this->_objectptr->GetObj()->append(count, character);
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::append(const_iterator begin, const_iterator end)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'begin'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'end'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator begin;
  if (!get_val_param<const_iterator >(begin,_p,_n,true,true)) ClassReturnEmptyVar;

  const_iterator end;
  if (!get_val_param<const_iterator >(end,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->append(begin, end);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::assign(vtkUnicodeString const & value)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > value_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(value_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkUnicodeString const & value = *value_smtptr;

  this->_objectptr->GetObj()->assign(value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnicodeString::assign(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap_assign_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::assign(size_t count, vtkUnicodeStringValueType character)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'character'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long count_long;
  if (!get_val_param<long >(count_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  long character_long;
  if (!get_val_param<long >(character_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int character = boost::numeric_cast<unsigned int >(character_long);

  this->_objectptr->GetObj()->assign(count, character);
  return BasicVariable::ptr();
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::assign(const_iterator begin, const_iterator end)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_assign_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'begin'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'end'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_assign_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator begin;
  if (!get_val_param<const_iterator >(begin,_p,_n,true,true)) ClassReturnEmptyVar;

  const_iterator end;
  if (!get_val_param<const_iterator >(end,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->assign(begin, end);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::clear()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::fold_case()
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_fold_case::SetParametersComments()
{
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_fold_case::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkUnicodeString res =   this->_objectptr->GetObj()->fold_case();
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkUnicodeString::compare(vtkUnicodeString const & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_compare::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'param0'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_compare::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > param0_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkUnicodeString const & param0 = *param0_smtptr;

  int res =   this->_objectptr->GetObj()->compare(param0);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString vtkUnicodeString::substr(size_t offset = 0, size_t count = vtkUnicodeString::npos)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_substr::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'offset' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:vtkUnicodeString::npos)")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_substr::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long offset_long = boost::numeric_cast<long >(0);;
  if (!get_val_param<long >(offset_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int offset = boost::numeric_cast<long unsigned int >(offset_long);

  long count_long = boost::numeric_cast<long >(vtkUnicodeString::npos);;
  if (!get_val_param<long >(count_long,_p,_n,false,false)) ClassHelpAndReturn;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  vtkUnicodeString res =   this->_objectptr->GetObj()->substr(offset, count);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkUnicodeString::swap(vtkUnicodeString & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap_swap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap_swap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > param0_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkUnicodeString & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->swap(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString & vtkUnicodeString::operator =(vtkUnicodeString const & param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'param0'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > param0_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkUnicodeString const & param0 = *param0_smtptr;

  vtkUnicodeString & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeStringValueType vtkUnicodeString::operator [](size_t offset)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'offset'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long offset_long;
  if (!get_val_param<long >(offset_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int offset = boost::numeric_cast<long unsigned int >(offset_long);

  vtkUnicodeStringValueType res =   (*this->_objectptr->GetObj()) [ (offset)];
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString & vtkUnicodeString::operator +=(vtkUnicodeStringValueType param0)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'param0'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long param0_long;
  if (!get_val_param<long >(param0_long,_p,_n,true,true)) ClassReturnEmptyVar;
  unsigned int param0 = boost::numeric_cast<unsigned int >(param0_long);

  vtkUnicodeString & res =   (*this->_objectptr->GetObj()) += (param0);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkUnicodeString::+=(...)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkUnicodeString::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkUnicodeString::wrap___add_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of vtkUnicodeString & vtkUnicodeString::operator +=(vtkUnicodeString const & rhs)
//---------------------------------------------------
void WrapClass_vtkUnicodeString::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkUnicodeString, "parameter named 'rhs'")
  return_comments="returning a variable of type vtkUnicodeString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkUnicodeString::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkUnicodeString > rhs_smtptr;
  if (!get_val_smtptr_param<vtkUnicodeString >(rhs_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkUnicodeString const & rhs = *rhs_smtptr;

  vtkUnicodeString & res =   (*this->_objectptr->GetObj()) += (rhs);
  return AMILabType<vtkUnicodeString >::CreateVar(res);
}

