/**
 * C++ Interface: wrap_wxWCharBuffer
 *
 * Description: wrapping wxWCharBuffer
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

#include "wrap_wxWCharBuffer.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wchar.h"
#ifndef wxWCharBuffer_declared
  #define wxWCharBuffer_declared
  AMI_DECLARE_TYPE(wxWCharBuffer)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWCharBuffer>::CreateVar( ParamList* p)
{
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxWCharBuffer);
AMI_DEFINE_VARFROMSMTPTR(wxWCharBuffer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxWCharBuffer
//
Variable<AMIObject>::ptr WrapClass_wxWCharBuffer::CreateVar( wxWCharBuffer* sp)
{
  boost::shared_ptr<wxWCharBuffer> di_ptr(
    sp,
    wxwindow_nodeleter<wxWCharBuffer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxWCharBuffer>::CreateVar(
      new WrapClass_wxWCharBuffer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxWCharBuffer::AddMethods(WrapClass<wxWCharBuffer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_release( this_ptr);
  AddVar_reset( this_ptr);
  AddVar_extend( this_ptr);
  AddVar_data_1( this_ptr);
  AddVar_data( this_ptr);
  AddVar_data_2( this_ptr);

  // Adding operators
  AddVar___assign___1( this_ptr);
  AddVar___assign__( this_ptr);
  AddVar___assign___2( this_ptr);
  AddVar___at__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxWCharBuffer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxWCharBuffer");
    WrapClass_wxWCharBuffer::AddVar_wxWCharBuffer_1(amiobject->GetContext());
  WrapClass_wxWCharBuffer::AddVar_wxWCharBuffer(amiobject->GetContext());
  WrapClass_wxWCharBuffer::AddVar_wxWCharBuffer_2(amiobject->GetContext());
  WrapClass_wxWCharBuffer::AddVar_wxWCharBuffer_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(wchar_t const * str = 0l)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size()+1);

  wxWCharBuffer* _newobj = new wxWCharBuffer(str);
  BasicVariable::ptr res = WrapClass_wxWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxWCharBuffer::wxWCharBuffer(...)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(size_t len)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  wxWCharBuffer* _newobj = new wxWCharBuffer(len);
  BasicVariable::ptr res = WrapClass_wxWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(wxWCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(src_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxWCharBuffer const & src = *src_smtptr;

  wxWCharBuffer* _newobj = new wxWCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxWCharBuffer.
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxWCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxWCharBuffer >::CreateVar( new wxWCharBuffer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wchar_t * wxWCharBuffer::release()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_release::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_release::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wchar_t * res =   this->_objectptr->GetObj()->release();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxWCharBuffer::reset()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxWCharBuffer::extend(size_t len)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_extend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_extend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  bool res =   this->_objectptr->GetObj()->extend(len);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wchar_t * wxWCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_data_1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_data_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wchar_t * res =   this->_objectptr->GetObj()->data();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWCharBuffer::data(...)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_data::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_data::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWCharBuffer::wrap_data_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_data_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wchar_t const * wxWCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_data_2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_data_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wchar_t const * res =   this->_objectptr->GetObj()->data();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer & wxWCharBuffer::operator =(wchar_t const * str)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > str_string;
  if (!get_val_smtptr_param<std::string >(str_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size()+1);

  wxWCharBuffer & res =   (*this->_objectptr->GetObj()) = (str);
  return AMILabType<wxWCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWCharBuffer::=(...)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWCharBuffer::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer & wxWCharBuffer::operator =(wxWCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'src'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > src_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(src_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWCharBuffer const & src = *src_smtptr;

  wxWCharBuffer & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxWCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wchar_t wxWCharBuffer::operator [](size_t n)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap___at__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap___at__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n,true,false)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wchar_t res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

