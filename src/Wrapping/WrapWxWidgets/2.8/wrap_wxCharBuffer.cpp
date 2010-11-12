/**
 * C++ Interface: wrap_wxCharBuffer
 *
 * Description: wrapping wxCharBuffer
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxCharBuffer.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxCharBuffer.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCharBuffer>::CreateVar( ParamList* p)
{
  WrapClass_wxCharBuffer::wrap_wxCharBuffer construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxCharBuffer);
AMI_DEFINE_VARFROMSMTPTR(wxCharBuffer);


//
// static member for creating a variable from a pointer to wxCharBuffer
//
Variable<AMIObject>::ptr WrapClass_wxCharBuffer::CreateVar( wxCharBuffer* sp)
{
  boost::shared_ptr<wxCharBuffer> di_ptr(
    sp,
    wxwindow_nodeleter<wxCharBuffer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCharBuffer>::CreateVar(
      new WrapClass_wxCharBuffer(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(char const * str = 0l)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  wxCharBuffer* _newobj = new wxCharBuffer(str);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxCharBuffer::wxCharBuffer(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_wxCharBuffer3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(size_t len)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxCharBuffer* _newobj = new wxCharBuffer(len);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxCharBuffer::wxCharBuffer(wxCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_wxCharBuffer3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCharBuffer, "parameter named 'src'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_wxCharBuffer3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCharBuffer> src_smtptr;
  if (!get_val_smtptr_param<wxCharBuffer>(src_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxCharBuffer const & src = *src_smtptr;

  wxCharBuffer* _newobj = new wxCharBuffer(src);
  BasicVariable::ptr res = WrapClass_wxCharBuffer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxCharBuffer.
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the wxCharBuffer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<wxCharBuffer>::CreateVar( new wxCharBuffer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of char * wxCharBuffer::release()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_release::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_release::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  char * res =   this->_objectptr->GetObj()->release();
  std::string res_string = std::string(res);
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxCharBuffer::reset()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_reset::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_reset::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->reset();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxCharBuffer::extend(size_t len)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_extend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
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
//  Wrapping of char * wxCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  char * res =   this->_objectptr->GetObj()->data();
  std::string res_string = std::string(res);
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxCharBuffer::data(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap_data1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_data2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of char const * wxCharBuffer::data()
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_data2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_data2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  char const * res =   this->_objectptr->GetObj()->data();
  std::string res_string = std::string(res);
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer & wxCharBuffer::=(char const * str)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  wxCharBuffer & res =   (*this->_objectptr->GetObj()) = (str);
  return AMILabType<wxCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxCharBuffer::=(...)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxCharBuffer::wrap_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxCharBuffer::wrap_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer & wxCharBuffer::=(wxCharBuffer const & src)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCharBuffer, "parameter named 'src'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCharBuffer> src_smtptr;
  if (!get_val_smtptr_param<wxCharBuffer>(src_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCharBuffer const & src = *src_smtptr;

  wxCharBuffer & res =   (*this->_objectptr->GetObj()) = (src);
  return AMILabType<wxCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of char wxCharBuffer::[](size_t n)
//---------------------------------------------------
void WrapClass_wxCharBuffer::
    wrap_at::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxCharBuffer::
    wrap_at::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  char res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string = std::string(1,res);
  return AMILabType<std::string>::CreateVar(res_string);
}

