/**
 * C++ Interface: wrap_wxStringBase
 *
 * Description: wrapping wxStringBase
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxStringBase.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxStringBase.h"
#include "boost/numeric/conversion/cast.hpp"
#include "stdlib.h"
#include "wrap_wxMBConv.h"
#include "wchar.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStringBase>::CreateVar( ParamList* p)
{
  WrapClass_wxStringBase::wrap_wxStringBase construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxStringBase);
AMI_DEFINE_VARFROMSMTPTR(wxStringBase);


//
// static member for creating a variable from a pointer to wxStringBase
//
Variable<AMIObject>::ptr WrapClass_wxStringBase::CreateVar( wxStringBase* sp)
{
  boost::shared_ptr<wxStringBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxStringBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStringBase>::CreateVar(
      new WrapClass_wxStringBase(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxStringBase* _newobj = new wxStringBase();
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxStringBase::wxStringBase(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_wxStringBase1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_wxStringBase7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(wxStringBase const & stringSrc)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'stringSrc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> stringSrc_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(stringSrc_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxStringBase const & stringSrc = *stringSrc_smtptr;

  wxStringBase* _newobj = new wxStringBase(stringSrc);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(size_t nRepeat, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nRepeat_long;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase* _newobj = new wxStringBase(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxStringBase* _newobj = new wxStringBase(psz);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(wxChar const * psz, size_t nLength)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxStringBase* _newobj = new wxStringBase(psz, nLength);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(wxChar const * psz, wxMBConv const & param1, size_t nLength = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength' (def:wxStringBase::npos)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  boost::shared_ptr<wxMBConv> param1_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param1 = *param1_smtptr;

  long nLength_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxStringBase* _newobj = new wxStringBase(psz, param1, nLength);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(wxStringBase const & str, size_t nPos, size_t nLen)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxStringBase* _newobj = new wxStringBase(str, nPos, nLen);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}
/* The following types are missing: void, void

//---------------------------------------------------
//  Wrapping of Constructor wxStringBase::wxStringBase(void const * pStart, void const * pEnd)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_wxStringBase8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'pStart'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'pEnd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_wxStringBase8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void> pStart_smtptr;
  if (!get_val_smtptr_param<void>(pStart_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* pStart = pStart_smtptr.get();

  boost::shared_ptr<void> pEnd_smtptr;
  if (!get_val_smtptr_param<void>(pEnd_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* pEnd = pEnd_smtptr.get();

  wxStringBase* _newobj = new wxStringBase(pStart, pEnd);
  BasicVariable::ptr res = WrapClass_wxStringBase::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxStringBase.
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the wxStringBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<wxStringBase>::CreateVar( new wxStringBase(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::length()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_length::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_length::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->length();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::size()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::max_size()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::resize(size_t nSize, wxChar ch = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nSize'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long nSize_long;
  if (!get_val_param<long>(nSize_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nSize = boost::numeric_cast<long unsigned int>(nSize_long);

  std::string ch_string;
  {
    wchar_t val = 0;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) ch_string = std::string(1,char_conv);
  };
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  this->_objectptr->GetObj()->resize(nSize, ch);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::clear()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxStringBase::empty()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::reserve(size_t sz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_reserve::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_reserve::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long sz_long;
  if (!get_val_param<long>(sz_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int sz = boost::numeric_cast<long unsigned int>(sz_long);

  this->_objectptr->GetObj()->reserve(sz);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::capacity()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_capacity::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_capacity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->capacity();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxChar wxStringBase::at(size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_at1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_at1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxChar res =   this->_objectptr->GetObj()->at(n);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::at(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_at::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_at::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_at1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_at2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar & wxStringBase::at(size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_at2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_at2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxChar & res =   this->_objectptr->GetObj()->at(n);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(wxStringBase const & str, size_t pos, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long pos_long;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->append(str, pos, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::append(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_append1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_append2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_append3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_append4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_append5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_append6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(wxStringBase const & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  wxStringBase & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(wxChar const * sz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxStringBase & res =   this->_objectptr->GetObj()->append(sz);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(wxChar const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->append(sz, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::append(wxChar const * first, wxChar const * last)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_append6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_append6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  wxStringBase & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxStringBase::begin()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_begin1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_begin1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar const * res =   this->_objectptr->GetObj()->begin();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::begin(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_begin1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_begin2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar * wxStringBase::begin()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_begin2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_begin2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar * res =   this->_objectptr->GetObj()->begin();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxStringBase::end()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_end1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_end1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar const * res =   this->_objectptr->GetObj()->end();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::end(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_end1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_end2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar * wxStringBase::end()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_end2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_end2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar * res =   this->_objectptr->GetObj()->end();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxStringBase::rbegin()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rbegin1::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rbegin1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<const_reverse_iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::rbegin(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxStringBase::rbegin()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rbegin2::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rbegin2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator>::CreateVar(res);
}
*/
/* The following types are missing: const_reverse_iterator

//---------------------------------------------------
//  Wrapping of const_reverse_iterator wxStringBase::rend()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rend1::SetParametersComments()
{
  return_comments="returning a variable of type const_reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rend1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<const_reverse_iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::rend(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: reverse_iterator

//---------------------------------------------------
//  Wrapping of reverse_iterator wxStringBase::rend()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rend2::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rend2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::insert(size_t nPos, wxStringBase const & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  wxStringBase & res =   this->_objectptr->GetObj()->insert(nPos, str);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::insert(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_insert1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_insert7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::insert(size_t nPos, wxStringBase const & str, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->insert(nPos, str, nStart, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::insert(size_t nPos, wxChar const * sz, size_t n = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxStringBase::npos)")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long n_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->insert(nPos, sz, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::insert(size_t nPos, size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase & res =   this->_objectptr->GetObj()->insert(nPos, n, ch);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar * wxStringBase::insert(wxChar * it, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> it_string;
  if (!get_val_smtptr_param<std::string>(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxChar * res =   this->_objectptr->GetObj()->insert(it, ch);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::insert(wxChar * it, wxChar const * first, wxChar const * last)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> it_string;
  if (!get_val_smtptr_param<std::string>(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::insert(wxChar * it, size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_insert7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_insert7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> it_string;
  if (!get_val_smtptr_param<std::string>(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  this->_objectptr->GetObj()->insert(it, n, ch);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::erase(size_t pos = 0, size_t n = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_erase1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxStringBase::npos)")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_erase1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  long n_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->erase(pos, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::erase(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_erase1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_erase2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_erase3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar * wxStringBase::erase(wxChar * first, wxChar * last)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_erase2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_erase2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  wxChar * res =   this->_objectptr->GetObj()->erase(first, last);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar * wxStringBase::erase(wxChar * first)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_erase3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_erase3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  wxChar * res =   this->_objectptr->GetObj()->erase(first);
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxStringBase::c_str()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_c_str::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_c_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->c_str();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxStringBase::data()
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_data::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_data::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->data();
  std::string res_string;
  {
    const wchar_t* val = res;
    size_t size = wcslen(val);
    char char_conv[size+1];
    size_t conv_res = wcstombs(char_conv,val,size+1);
    if (conv_res>0) res_string = std::string(char_conv);
  }
  return AMILabType<std::string>::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxChar const * sz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::replace(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_replace1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_replace10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxStringBase const & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  wxStringBase & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, size_t nCount, wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase & res =   this->_objectptr->GetObj()->replace(nStart, nLen, nCount, ch);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxStringBase const & str, size_t nStart2, size_t nLen2)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart2'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen2'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart2_long;
  if (!get_val_param<long>(nStart2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart2 = boost::numeric_cast<long unsigned int>(nStart2_long);

  long nLen2_long;
  if (!get_val_param<long>(nLen2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen2 = boost::numeric_cast<long unsigned int>(nLen2_long);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str, nStart2, nLen2);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz, nCount);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * s)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * s, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(first, last, s, n);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxStringBase const & s)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 's'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<wxStringBase> s_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & s = *s_smtptr;

  wxStringBase & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, size_t n, wxChar c)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string c_string;
  if (!get_val_param<std::string>(c_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t c = 0;
{
  if (c_string.size()>0) mbstowcs(&c, &c_string[0],1);
}


  wxStringBase & res =   this->_objectptr->GetObj()->replace(first, last, n, c);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::replace(wxChar * first, wxChar * last, wxChar const * first1, wxChar const * last1)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_replace10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first1'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last1'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_replace10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string> first1_string;
  if (!get_val_smtptr_param<std::string>(first1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first1[first1_string->size()+1];
mbstowcs(first1,first1_string->c_str(),first1_string->size()+1);

  boost::shared_ptr<std::string> last1_string;
  if (!get_val_smtptr_param<std::string>(last1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last1[last1_string->size()+1];
mbstowcs(last1,last1_string->c_str(),last1_string->size()+1);

  wxStringBase & res =   this->_objectptr->GetObj()->replace(first, last, first1, last1);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStringBase::swap(wxStringBase & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_swap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_swap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxStringBase & str = *str_smtptr;

  this->_objectptr->GetObj()->swap(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find(wxStringBase const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::find(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_find1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find(wxChar const * sz, size_t nStart = 0, size_t n = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find(wxChar ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::rfind(wxStringBase const & str, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rfind1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rfind1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::rfind(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rfind::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rfind::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_rfind1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_rfind2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_rfind3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::rfind(wxChar const * sz, size_t nStart = wxStringBase::npos, size_t n = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rfind2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rfind2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::rfind(wxChar ch, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_rfind3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_rfind3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_of(wxStringBase const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_of1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_of1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::find_first_of(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_find_first_of1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_of2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_of3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_of4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_of(wxChar const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_of2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_of2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_of(wxChar const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_of3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_of3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_of(wxChar c, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_of4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_of4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string c_string;
  if (!get_val_param<std::string>(c_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t c = 0;
{
  if (c_string.size()>0) mbstowcs(&c, &c_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(c, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_of(wxStringBase const & str, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_of1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_of1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::find_last_of(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_find_last_of1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_of2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_of3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_of4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_of(wxChar const * sz, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_of2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_of2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_of(wxChar const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_of3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_of3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_of(wxChar c, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_of4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_of4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string c_string;
  if (!get_val_param<std::string>(c_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t c = 0;
{
  if (c_string.size()>0) mbstowcs(&c, &c_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(c, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_not_of(wxStringBase const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_not_of1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_not_of1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::find_first_not_of(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_not_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_not_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_find_first_not_of1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_not_of2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_not_of3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_first_not_of4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_not_of(wxChar const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_not_of2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_not_of2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_not_of(wxChar const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_not_of3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_not_of3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_first_not_of(wxChar ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_first_not_of4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_first_not_of4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_not_of(wxStringBase const & str, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_not_of1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_not_of1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::find_last_not_of(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_not_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_not_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_find_last_not_of1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_not_of2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_not_of3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_find_last_not_of4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_not_of(wxChar const * sz, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_not_of2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_not_of2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_not_of(wxChar const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_not_of3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_not_of3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxStringBase::find_last_not_of(wxChar ch, size_t nStart = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_find_last_not_of4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxStringBase::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_find_last_not_of4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long nStart_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int wxStringBase::compare(wxStringBase const & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(str);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::compare(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_compare1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_compare2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_compare3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_compare4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_compare5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxStringBase::compare(size_t nStart, size_t nLen, wxStringBase const & str)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, str);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxStringBase::compare(size_t nStart, size_t nLen, wxStringBase const & str, size_t nStart2, size_t nLen2)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart2'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<wxStringBase> str_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & str = *str_smtptr;

  long nStart2_long;
  if (!get_val_param<long>(nStart2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart2 = boost::numeric_cast<long unsigned int>(nStart2_long);

  long nLen2_long;
  if (!get_val_param<long>(nLen2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen2 = boost::numeric_cast<long unsigned int>(nLen2_long);

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, str, nStart2, nLen2);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxStringBase::compare(wxChar const * sz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  int res =   this->_objectptr->GetObj()->compare(sz);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxStringBase::compare(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_compare5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount' (def:wxStringBase::npos)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_compare5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nCount_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, sz, nCount);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase wxStringBase::substr(size_t nStart = 0, size_t nLen = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_substr::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen' (def:wxStringBase::npos)")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_substr::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long = boost::numeric_cast<long>(wxStringBase::npos);;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxStringBase res =   this->_objectptr->GetObj()->substr(nStart, nLen);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::=(wxStringBase const & stringSrc)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'stringSrc'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> stringSrc_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(stringSrc_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & stringSrc = *stringSrc_smtptr;

  wxStringBase & res =   (*this->_objectptr->GetObj()) = (stringSrc);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::=(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_assign3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::=(wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::=(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_assign3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_assign3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxStringBase & res =   (*this->_objectptr->GetObj()) = (psz);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::+=(wxStringBase const & s)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_add_assign1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 's'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_add_assign1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase> s_smtptr;
  if (!get_val_smtptr_param<wxStringBase>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & s = *s_smtptr;

  wxStringBase & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStringBase::+=(...)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_add_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_add_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStringBase::wrap_add_assign1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_add_assign2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStringBase::wrap_add_assign3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::+=(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_add_assign2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_add_assign2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxStringBase & res =   (*this->_objectptr->GetObj()) += (psz);
  return AMILabType<wxStringBase>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStringBase & wxStringBase::+=(wxChar ch)
//---------------------------------------------------
void WrapClass_wxStringBase::
    wrap_add_assign3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxStringBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStringBase::
    wrap_add_assign3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxStringBase & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxStringBase>::CreateVar(res);
}

