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

#include "wrap_wxWCharBuffer.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxWCharBuffer.h"
#include "wchar.h"


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



//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(wchar_t const * str = 0l)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size());

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
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_wxWCharBuffer3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(size_t len)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxWCharBuffer* _newobj = new wxWCharBuffer(len);
  BasicVariable::ptr res = WrapClass_wxWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxWCharBuffer::wxWCharBuffer(wxWCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_wxWCharBuffer3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer> src_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer>(src_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxWCharBuffer const & src = *src_smtptr;

  wxWCharBuffer* _newobj = new wxWCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxWCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxWCharBuffer.
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the wxWCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<wxWCharBuffer>::CreateVar( new wxWCharBuffer(*(this->_objectptr->GetObj())));
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
    size_t conv_res = wcstombs(char_conv,val,size);
    if (conv_res==1) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
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
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_extend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  bool res =   this->_objectptr->GetObj()->extend(len);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wchar_t * wxWCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_data1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_data1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wchar_t * res =   this->_objectptr->GetObj()->data();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size);
    if (conv_res==1) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
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
  WrapClass_wxWCharBuffer::wrap_data1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_data2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wchar_t const * wxWCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_data2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_data2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wchar_t const * res =   this->_objectptr->GetObj()->data();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size);
    if (conv_res==1) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer & wxWCharBuffer::=(wchar_t const * str)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size());

  wxWCharBuffer & res =   (*this->_objectptr->GetObj()) = (str);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxWCharBuffer::=(...)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxWCharBuffer::wrap_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxWCharBuffer::wrap_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer & wxWCharBuffer::=(wxWCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'src'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer> src_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer>(src_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWCharBuffer const & src = *src_smtptr;

  wxWCharBuffer & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wchar_t wxWCharBuffer::[](size_t n)
//---------------------------------------------------
void WrapClass_wxWCharBuffer::
    wrap_at::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxWCharBuffer::
    wrap_at::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wchar_t res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res==1) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

