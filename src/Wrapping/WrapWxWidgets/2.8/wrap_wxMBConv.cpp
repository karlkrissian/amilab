/**
 * C++ Interface: wrap_wxMBConv
 *
 * Description: wrapping wxMBConv
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxMBConv.h"

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
#include "wrap_wxCharBuffer.h"
#include "wchar.h"
#include "wrap_wxMBConv.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMBConv>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxMBConv);
AMI_DEFINE_VARFROMSMTPTR(wxMBConv);


//
// static member for creating a variable from a pointer to wxMBConv
//
Variable<AMIObject>::ptr WrapClass_wxMBConv::CreateVar( wxMBConv* sp)
{
  boost::shared_ptr<wxMBConv> di_ptr(
    sp,
    wxwindow_nodeleter<wxMBConv>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMBConv>::CreateVar(
      new WrapClass_wxMBConv(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of size_t wxMBConv::ToWChar(wchar_t * dst, size_t dstLen, char const * src, size_t srcLen = -1u)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_ToWChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'dst'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'dstLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'src'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'srcLen' (def:-1u)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_ToWChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> dst_string;
  if (!get_val_smtptr_param<std::string>(dst_string,_p,_n)) ClassHelpAndReturn;
  wchar_t dst[dst_string->size()+1];
mbstowcs(dst,dst_string->c_str(),dst_string->size()+1);

  long dstLen_long;
  if (!get_val_param<long>(dstLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int dstLen = boost::numeric_cast<long unsigned int>(dstLen_long);

  boost::shared_ptr<std::string> src_string;
  if (!get_val_smtptr_param<std::string>(src_string,_p,_n)) ClassHelpAndReturn;
  char const * src = src_string->c_str();

  long srcLen_long = boost::numeric_cast<long>(-1u);;
  if (!get_val_param<long>(srcLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int srcLen = boost::numeric_cast<long unsigned int>(srcLen_long);

  size_t res =   this->_objectptr->GetObj()->ToWChar(dst, dstLen, src, srcLen);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxMBConv::FromWChar(char * dst, size_t dstLen, wchar_t const * src, size_t srcLen = -1u)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_FromWChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'dst'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'dstLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'src'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'srcLen' (def:-1u)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_FromWChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> dst_string;
  if (!get_val_smtptr_param<std::string>(dst_string,_p,_n)) ClassHelpAndReturn;
  char * dst = &(*dst_string)[0];

  long dstLen_long;
  if (!get_val_param<long>(dstLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int dstLen = boost::numeric_cast<long unsigned int>(dstLen_long);

  boost::shared_ptr<std::string> src_string;
  if (!get_val_smtptr_param<std::string>(src_string,_p,_n)) ClassHelpAndReturn;
  wchar_t src[src_string->size()+1];
mbstowcs(src,src_string->c_str(),src_string->size()+1);

  long srcLen_long = boost::numeric_cast<long>(-1u);;
  if (!get_val_param<long>(srcLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int srcLen = boost::numeric_cast<long unsigned int>(srcLen_long);

  size_t res =   this->_objectptr->GetObj()->FromWChar(dst, dstLen, src, srcLen);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer const wxMBConv::cMB2WC(char const * in)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cMB2WC_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cMB2WC_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassReturnEmptyVar;
  char const * in = in_string->c_str();

  wxWCharBuffer const res =   this->_objectptr->GetObj()->cMB2WC(in);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxMBConv::cWC2MB(wchar_t const * in)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWC2MB_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWC2MB_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t in[in_string->size()+1];
mbstowcs(in,in_string->c_str(),in_string->size()+1);

  wxCharBuffer const res =   this->_objectptr->GetObj()->cWC2MB(in);
  return AMILabType<wxCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMBConv::cMB2WC(...)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cMB2WC::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cMB2WC::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMBConv::wrap_cMB2WC_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMBConv::wrap_cMB2WC_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer const wxMBConv::cMB2WC(char const * in, size_t inLen, size_t * outLen)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cMB2WC_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'inLen'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'outLen'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cMB2WC_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassReturnEmptyVar;
  char const * in = in_string->c_str();

  long inLen_long;
  if (!get_val_param<long>(inLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int inLen = boost::numeric_cast<long unsigned int>(inLen_long);

  boost::shared_ptr<long> outLen_long;
  if (!get_val_smtptr_param<long>(outLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int outLen_val = boost::numeric_cast<long unsigned int>(*outLen_long);
  long unsigned int* outLen = &outLen_val;

  wxWCharBuffer const res =   this->_objectptr->GetObj()->cMB2WC(in, inLen, outLen);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMBConv::cWC2MB(...)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWC2MB::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWC2MB::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMBConv::wrap_cWC2MB_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMBConv::wrap_cWC2MB_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxMBConv::cWC2MB(wchar_t const * in, size_t inLen, size_t * outLen)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWC2MB_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'inLen'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'outLen'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWC2MB_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t in[in_string->size()+1];
mbstowcs(in,in_string->c_str(),in_string->size()+1);

  long inLen_long;
  if (!get_val_param<long>(inLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int inLen = boost::numeric_cast<long unsigned int>(inLen_long);

  boost::shared_ptr<long> outLen_long;
  if (!get_val_smtptr_param<long>(outLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int outLen_val = boost::numeric_cast<long unsigned int>(*outLen_long);
  long unsigned int* outLen = &outLen_val;

  wxCharBuffer const res =   this->_objectptr->GetObj()->cWC2MB(in, inLen, outLen);
  return AMILabType<wxCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxWCharBuffer const wxMBConv::cMB2WX(char const * psz)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cMB2WX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cMB2WX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassHelpAndReturn;
  char const * psz = psz_string->c_str();

  wxWCharBuffer const res =   this->_objectptr->GetObj()->cMB2WX(psz);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxMBConv::cWX2MB(wchar_t const * psz)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWX2MB::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWX2MB::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassHelpAndReturn;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxCharBuffer const res =   this->_objectptr->GetObj()->cWX2MB(psz);
  return AMILabType<wxCharBuffer>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wchar_t const * wxMBConv::cWC2WX(wchar_t const * psz)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWC2WX::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWC2WX::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassHelpAndReturn;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wchar_t const * res =   this->_objectptr->GetObj()->cWC2WX(psz);
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
//  Wrapping of wchar_t const * wxMBConv::cWX2WC(wchar_t const * psz)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_cWX2WC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_cWX2WC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassHelpAndReturn;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wchar_t const * res =   this->_objectptr->GetObj()->cWX2WC(psz);
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
//  Wrapping of size_t wxMBConv::GetMBNulLen()
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_GetMBNulLen::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_GetMBNulLen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetMBNulLen();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxMBConv::GetMaxMBNulLen()
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_GetMaxMBNulLen::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_GetMaxMBNulLen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetMaxMBNulLen();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxMBConv::MB2WC(wchar_t * out, char const * in, size_t outLen)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_MB2WC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'out'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'outLen'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_MB2WC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> out_string;
  if (!get_val_smtptr_param<std::string>(out_string,_p,_n)) ClassHelpAndReturn;
  wchar_t out[out_string->size()+1];
mbstowcs(out,out_string->c_str(),out_string->size()+1);

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassHelpAndReturn;
  char const * in = in_string->c_str();

  long outLen_long;
  if (!get_val_param<long>(outLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int outLen = boost::numeric_cast<long unsigned int>(outLen_long);

  size_t res =   this->_objectptr->GetObj()->MB2WC(out, in, outLen);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxMBConv::WC2MB(char * out, wchar_t const * in, size_t outLen)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap_WC2MB::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'out'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'in'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'outLen'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap_WC2MB::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string> out_string;
  if (!get_val_smtptr_param<std::string>(out_string,_p,_n)) ClassHelpAndReturn;
  char * out = &(*out_string)[0];

  boost::shared_ptr<std::string> in_string;
  if (!get_val_smtptr_param<std::string>(in_string,_p,_n)) ClassHelpAndReturn;
  wchar_t in[in_string->size()+1];
mbstowcs(in,in_string->c_str(),in_string->size()+1);

  long outLen_long;
  if (!get_val_param<long>(outLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int outLen = boost::numeric_cast<long unsigned int>(outLen_long);

  size_t res =   this->_objectptr->GetObj()->WC2MB(out, in, outLen);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of wxMBConv & wxMBConv::=(wxMBConv const & param0)
//---------------------------------------------------
void WrapClass_wxMBConv::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param0'")
  return_comments="returning a variable of type wxMBConv";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMBConv::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMBConv> param0_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxMBConv const & param0 = *param0_smtptr;

  wxMBConv & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxMBConv>::CreateVar(res);
}

