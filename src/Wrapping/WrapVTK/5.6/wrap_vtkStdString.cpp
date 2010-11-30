/**
 * C++ Interface: wrap_vtkStdString
 *
 * Description: wrapping vtkStdString
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
#include "wrap_vtkStdString.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkStdString.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkStdString>::CreateVar( ParamList* p)
{
  WrapClass_vtkStdString::wrap_vtkStdString construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkStdString);
AMI_DEFINE_VARFROMSMTPTR(vtkStdString);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkStdString
//
Variable<AMIObject>::ptr WrapClass_vtkStdString::CreateVar( vtkStdString* sp)
{
  boost::shared_ptr<vtkStdString> di_ptr(
    sp,
    wxwindow_nodeleter<vtkStdString>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkStdString>::CreateVar(
      new WrapClass_vtkStdString(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkStdString::AddMethods(WrapClass<vtkStdString>::ptr this_ptr )
{
  /*
      // Add members from basic_string<char,std::char_traits<char>,std::allocator<char> >
      WrapClass_basic_string_char_std::char_traits_char__std::allocator_char_ _::ptr parent_basic_string_char_std::char_traits_char__std::allocator_char_ _(        boost::dynamic_pointer_cast<WrapClass_basic_string_char_std::char_traits_char__std::allocator_char_ _ >(this_ptr));
      parent_basic_string_char_std::char_traits_char__std::allocator_char_ _->AddMethods(parent_basic_string_char_std::char_traits_char__std::allocator_char_ _);
      */


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkStdString::vtkStdString(vtkStdString const & param0)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkStdString, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkStdString > param0_smtptr;
  if (!get_val_smtptr_param<vtkStdString >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  vtkStdString const & param0 = *param0_smtptr;

  vtkStdString* _newobj = new vtkStdString(param0);
  BasicVariable::ptr res = WrapClass_vtkStdString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkStdString::vtkStdString(...)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkStdString::wrap_vtkStdString_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkStdString::wrap_vtkStdString_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_vtkStdString::wrap_vtkStdString_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_vtkStdString::wrap_vtkStdString_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkStdString::vtkStdString()
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkStdString* _newobj = new vtkStdString();
  BasicVariable::ptr res = WrapClass_vtkStdString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkStdString::vtkStdString(char const * s)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * s = s_string->c_str();

  vtkStdString* _newobj = new vtkStdString(s);
  BasicVariable::ptr res = WrapClass_vtkStdString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkStdString::vtkStdString(char const * s, size_t n)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * s = s_string->c_str();

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  vtkStdString* _newobj = new vtkStdString(s, n);
  BasicVariable::ptr res = WrapClass_vtkStdString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of Constructor vtkStdString::vtkStdString(string const & s, size_t pos = 0, size_t n = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::npos)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap_vtkStdString_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<char,std::char_traits<char>,std::allocator<char> >, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:std::basic_string<char, std::char_traits<char>, std::allocator<char> >::npos)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap_vtkStdString_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<char,std::char_traits<char>,std::allocator<char> > > s_smtptr;
  if (!get_val_smtptr_param<basic_string<char,std::char_traits<char>,std::allocator<char> > >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  string const & s = *s_smtptr;

  long pos_long = boost::numeric_cast<long >(0);;
  if (!get_val_param<long >(pos_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  long n_long = boost::numeric_cast<long >(std::basic_string<char, std::char_traits<char>, std::allocator<char> >::npos);;
  if (!get_val_param<long >(n_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  vtkStdString* _newobj = new vtkStdString(s, pos, n);
  BasicVariable::ptr res = WrapClass_vtkStdString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkStdString.
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkStdString object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkStdString >::CreateVar( new vtkStdString(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of vtkStdString & vtkStdString::operator =(vtkStdString const & param0)
//---------------------------------------------------
void WrapClass_vtkStdString::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkStdString, "parameter named 'param0'")
  return_comments="returning a variable of type vtkStdString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkStdString::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkStdString > param0_smtptr;
  if (!get_val_smtptr_param<vtkStdString >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkStdString const & param0 = *param0_smtptr;

  vtkStdString & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkStdString >::CreateVar(res);
}

