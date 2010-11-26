/**
 * C++ Interface: wrap_wxString
 *
 * Description: wrapping wxString
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxString.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxString.h"
#include "boost/numeric/conversion/cast.hpp"
#include "stdlib.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxString>::CreateVar( ParamList* p)
{
  WrapClass_wxString::wrap_wxString construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxString);
AMI_DEFINE_VARFROMSMTPTR(wxString);


//
// static member for creating a variable from a pointer to wxString
//
Variable<AMIObject>::ptr WrapClass_wxString::CreateVar( wxString* sp)
{
  boost::shared_ptr<wxString> di_ptr(
    sp,
    wxwindow_nodeleter<wxString>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxString>::CreateVar(
      new WrapClass_wxString(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxString* _newobj = new wxString();
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxString::wxString(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_wxString_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_8 m8;
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_9 m9;
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_10 m10;
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_11 m11;
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_13 m13;
  res = m13.CallMember(_p);
  if (!m13.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_15 m15;
  res = m15.CallMember(_p);
  if (!m15.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_17 m17;
  res = m17.CallMember(_p);
  if (!m17.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_19 m19;
  res = m19.CallMember(_p);
  if (!m19.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_21 m21;
  res = m21.CallMember(_p);
  if (!m21.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_27 m27;
  res = m27.CallMember(_p);
  if (!m27.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_30 m30;
  res = m30.CallMember(_p);
  if (!m30.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_32 m32;
  res = m32.CallMember(_p);
  if (!m32.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_33 m33;
  res = m33.CallMember(_p);
  if (!m33.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxString const & stringSrc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'stringSrc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> stringSrc_smtptr;
  if (!get_val_smtptr_param<wxString>(stringSrc_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxString const & stringSrc = *stringSrc_smtptr;

  wxString* _newobj = new wxString(stringSrc);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxUniChar ch, size_t nRepeat = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long nRepeat_long = boost::numeric_cast<long>(1);;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxString* _newobj = new wxString(ch, nRepeat);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(size_t nRepeat, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nRepeat_long;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString* _newobj = new wxString(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxUniCharRef ch, size_t nRepeat = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nRepeat_long = boost::numeric_cast<long>(1);;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxString* _newobj = new wxString(ch, nRepeat);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(size_t nRepeat, wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nRepeat_long;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString* _newobj = new wxString(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char ch, size_t nRepeat = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nRepeat_long = boost::numeric_cast<long>(1);;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxString* _newobj = new wxString(ch, nRepeat);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(size_t nRepeat, char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nRepeat_long;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString* _newobj = new wxString(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t ch, size_t nRepeat = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_9::CallMember( ParamList* _p)
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


  long nRepeat_long = boost::numeric_cast<long>(1);;
  if (!get_val_param<long>(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int>(nRepeat_long);

  wxString* _newobj = new wxString(ch, nRepeat);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(size_t nRepeat, wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_10::CallMember( ParamList* _p)
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


  wxString* _newobj = new wxString(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  wxString* _newobj = new wxString(psz);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * psz, wxMBConv const & conv)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & conv = *conv_smtptr;

  wxString* _newobj = new wxString(psz, conv);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * psz, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(psz, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * psz, wxMBConv const & conv, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & conv = *conv_smtptr;

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(psz, conv, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(unsigned char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'psz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> psz_smtptr;
  if (!get_val_smtptr_param<unsigned char>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* psz = psz_smtptr.get();

  wxString* _newobj = new wxString(psz);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(unsigned char const * psz, wxMBConv const & conv)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> psz_smtptr;
  if (!get_val_smtptr_param<unsigned char>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* psz = psz_smtptr.get();

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & conv = *conv_smtptr;

  wxString* _newobj = new wxString(psz, conv);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(unsigned char const * psz, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> psz_smtptr;
  if (!get_val_smtptr_param<unsigned char>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* psz = psz_smtptr.get();

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(psz, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(unsigned char const * psz, wxMBConv const & conv, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_18::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> psz_smtptr;
  if (!get_val_smtptr_param<unsigned char>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* psz = psz_smtptr.get();

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & conv = *conv_smtptr;

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(psz, conv, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  wxString* _newobj = new wxString(pwz);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t const * pwz, wxMBConv const & param1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_20::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_20::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  boost::shared_ptr<wxMBConv> param1_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param1 = *param1_smtptr;

  wxString* _newobj = new wxString(pwz, param1);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t const * pwz, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_21::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_21::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(pwz, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxMBConv

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t const * pwz, wxMBConv const & param1, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_22::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_22::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  boost::shared_ptr<wxMBConv> param1_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param1 = *param1_smtptr;

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(pwz, param1, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxScopedCharBuffer const & buf)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_23::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'buf'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_23::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> buf_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(buf_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & buf = *buf_smtptr;

  wxString* _newobj = new wxString(buf);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxScopedWCharBuffer const & buf)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_24::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'buf'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_24::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> buf_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(buf_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & buf = *buf_smtptr;

  wxString* _newobj = new wxString(buf);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxCStrData const & cstr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_25::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'cstr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_25::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> cstr_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(cstr_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & cstr = *cstr_smtptr;

  wxString* _newobj = new wxString(cstr);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxCStrData const & cstr, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_26::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'cstr'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_26::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> cstr_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(cstr_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & cstr = *cstr_smtptr;

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(cstr, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxString const & str, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_27::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_27::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nLength_long;
  if (!get_val_param<long>(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int>(nLength_long);

  wxString* _newobj = new wxString(str, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxStdWideString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_28::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_28::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >> str_smtptr;
  if (!get_val_smtptr_param<basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStdWideString const & str = *str_smtptr;

  wxString* _newobj = new wxString(str);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(string const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_29::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<char,std::char_traits<char>,std::allocator<char> >, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_29::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<char,std::char_traits<char>,std::allocator<char> >> str_smtptr;
  if (!get_val_smtptr_param<basic_string<char,std::char_traits<char>,std::allocator<char> >>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  string const & str = *str_smtptr;

  wxString* _newobj = new wxString(str);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxString const & str, size_t nPos, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_30::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_30::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString* _newobj = new wxString(str, nPos, nLen);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(const_iterator first, const_iterator last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_31::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_31::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator first;
  if (!get_val_param<const_iterator>(first,_p,_n)) ClassReturnEmptyVar;

  const_iterator last;
  if (!get_val_param<const_iterator>(last,_p,_n)) ClassReturnEmptyVar;

  wxString* _newobj = new wxString(first, last);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * first, char const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_32::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_32::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  char const * first = first_string->c_str();

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  char const * last = last_string->c_str();

  wxString* _newobj = new wxString(first, last);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wchar_t const * first, wchar_t const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_33::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_33::CallMember( ParamList* _p)
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

  wxString* _newobj = new wxString(first, last);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxCStrData, wxCStrData

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxCStrData const & first, wxCStrData const & last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_34::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_34::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> first_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & first = *first_smtptr;

  boost::shared_ptr<wxCStrData> last_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & last = *last_smtptr;

  wxString* _newobj = new wxString(first, last);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxString.
//---------------------------------------------------
void WrapClass_wxString::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxString object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxString>::CreateVar( new wxString(*(this->_objectptr->GetObj())));
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of size_t wxString::IterToImplPos(iterator i)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IterToImplPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'i'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IterToImplPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  iterator i;
  if (!get_val_param<iterator>(i,_p,_n)) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->IterToImplPos(i);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxString::GetIterForNthChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetIterForNthChar_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetIterForNthChar_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  iterator res =   this->_objectptr->GetObj()->GetIterForNthChar(n);
  return AMILabType<iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::GetIterForNthChar(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetIterForNthChar::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetIterForNthChar::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxString::GetIterForNthChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetIterForNthChar_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetIterForNthChar_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  const_iterator res =   this->_objectptr->GetObj()->GetIterForNthChar(n);
  return AMILabType<const_iterator>::CreateVar(res);
}
*/
/* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >

//---------------------------------------------------
//  Wrapping of wxStdWideString wxString::ToStdWstring()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToStdWstring::SetParametersComments()
{
  return_comments="returning a variable of type basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToStdWstring::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStdWideString res =   this->_objectptr->GetObj()->ToStdWstring();
  return AMILabType<basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >>::CreateVar(res);
}
*/
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >

//---------------------------------------------------
//  Wrapping of string wxString::ToStdString()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToStdString::SetParametersComments()
{
  return_comments="returning a variable of type basic_string<char,std::char_traits<char>,std::allocator<char> >";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToStdString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  string res =   this->_objectptr->GetObj()->ToStdString();
  return AMILabType<basic_string<char,std::char_traits<char>,std::allocator<char> >>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::Clone()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Clone::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Clone::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->Clone();
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxString::begin()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_begin_1::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_begin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<const_iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::begin(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_begin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_begin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxString::begin()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_begin_2::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_begin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->begin();
  return AMILabType<iterator>::CreateVar(res);
}
*/
/* The following types are missing: const_iterator

//---------------------------------------------------
//  Wrapping of const_iterator wxString::end()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_end_1::SetParametersComments()
{
  return_comments="returning a variable of type const_iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_end_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  const_iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<const_iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::end(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_end::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_end::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of iterator wxString::end()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_end_2::SetParametersComments()
{
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_end_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->end();
  return AMILabType<iterator>::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>

//---------------------------------------------------
//  Wrapping of reverse_iterator_impl<wxString::const_iterator> wxString::rbegin()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rbegin_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator_impl<wxString::const_iterator>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rbegin_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator_impl<wxString::const_iterator> res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator_impl<wxString::const_iterator>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::rbegin(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rbegin::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rbegin::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: reverse_iterator_impl<wxString::iterator>

//---------------------------------------------------
//  Wrapping of reverse_iterator_impl<wxString::iterator> wxString::rbegin()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rbegin_2::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator_impl<wxString::iterator>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rbegin_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator_impl<wxString::iterator> res =   this->_objectptr->GetObj()->rbegin();
  return AMILabType<reverse_iterator_impl<wxString::iterator>>::CreateVar(res);
}
*/
/* The following types are missing: reverse_iterator_impl<wxString::const_iterator>

//---------------------------------------------------
//  Wrapping of reverse_iterator_impl<wxString::const_iterator> wxString::rend()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rend_1::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator_impl<wxString::const_iterator>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rend_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator_impl<wxString::const_iterator> res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator_impl<wxString::const_iterator>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::rend(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rend::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rend::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: reverse_iterator_impl<wxString::iterator>

//---------------------------------------------------
//  Wrapping of reverse_iterator_impl<wxString::iterator> wxString::rend()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rend_2::SetParametersComments()
{
  return_comments="returning a variable of type reverse_iterator_impl<wxString::iterator>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rend_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  reverse_iterator_impl<wxString::iterator> res =   this->_objectptr->GetObj()->rend();
  return AMILabType<reverse_iterator_impl<wxString::iterator>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::length()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_length::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_length::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->length();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::size()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->size();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::max_size()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_max_size::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_max_size::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->max_size();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxString::empty()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_empty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->empty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::capacity()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_capacity::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_capacity::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->capacity();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxString::reserve(size_t sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_reserve::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'sz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
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
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of void wxString::resize(size_t nSize, wxUniChar ch = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nSize'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long nSize_long;
  if (!get_val_param<long>(nSize_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nSize = boost::numeric_cast<long unsigned int>(nSize_long);

  wxUniChar ch = 0;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->resize(nSize, ch);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::substr(size_t nStart = 0, size_t nLen = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_substr::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen' (def:wxString::npos)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_substr::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString res =   this->_objectptr->GetObj()->substr(nStart, nLen);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::Len()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Len::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Len::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Len();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsEmpty()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Truncate(size_t uiLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Truncate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'uiLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Truncate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long uiLen_long;
  if (!get_val_param<long>(uiLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int uiLen = boost::numeric_cast<long unsigned int>(uiLen_long);

  wxString & res =   this->_objectptr->GetObj()->Truncate(uiLen);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxString::Empty()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Empty::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Empty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Empty();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxString::Clear()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsAscii()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsAscii::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsAscii::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsAscii();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsNumber()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsNumber::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsNumber::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNumber();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsWord()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsWord::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsWord::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsWord();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::at(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_at_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_at_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar res =   this->_objectptr->GetObj()->at(n);
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::GetChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar res =   this->_objectptr->GetObj()->GetChar(n);
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::at(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_at::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_at::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::at(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_at_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_at_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniCharRef res =   this->_objectptr->GetObj()->at(n);
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::GetWritableChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetWritableChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetWritableChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniCharRef res =   this->_objectptr->GetObj()->GetWritableChar(n);
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of void wxString::SetChar(size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_SetChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_SetChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetChar(n, ch);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::Last()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_1::SetParametersComments()
{
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxUniChar res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Last(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::Last()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_2::SetParametersComments()
{
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxUniCharRef res =   this->_objectptr->GetObj()->Last();
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxCStrData wxString::c_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_c_str::SetParametersComments()
{
  return_comments="returning a variable of type wxCStrData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_c_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCStrData res =   this->_objectptr->GetObj()->c_str();
  return AMILabType<wxCStrData>::CreateVar(res);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxCStrData wxString::data()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_data::SetParametersComments()
{
  return_comments="returning a variable of type wxCStrData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_data::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCStrData res =   this->_objectptr->GetObj()->data();
  return AMILabType<wxCStrData>::CreateVar(res);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxCStrData const wxString::GetData()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type wxCStrData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCStrData const res =   this->_objectptr->GetObj()->GetData();
  return AMILabType<wxCStrData>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxStringCharType const * wxString::wx_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wx_str::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wx_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStringCharType const * res =   this->_objectptr->GetObj()->wx_str();
  std::string res_string = std::string(res);
  return AMILabType<std::string>::CreateVar(res_string);
}
/* The following types are missing: wxWritableCharTypeBuffer<char>, wxMBConv

//---------------------------------------------------
//  Wrapping of wxWritableCharBuffer wxString::char_str(wxMBConv const & conv = wxGet_wxConvLibc())
//---------------------------------------------------
void WrapClass_wxString::
    wrap_char_str::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv' (def:wxGet_wxConvLibc())")
  return_comments="returning a variable of type wxWritableCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_char_str::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMBConv const & conv = (conv_smtptr.get()?
    (wxMBConv const &) (*conv_smtptr):
    (wxMBConv const &) wxGet_wxConvLibc());

  wxWritableCharBuffer res =   this->_objectptr->GetObj()->char_str(conv);
  return AMILabType<wxWritableCharTypeBuffer<char>>::CreateVar(res);
}
*/
/* The following types are missing: wxWritableCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxWritableWCharBuffer wxString::wchar_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wchar_str::SetParametersComments()
{
  return_comments="returning a variable of type wxWritableCharTypeBuffer<wchar_t>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wchar_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWritableWCharBuffer res =   this->_objectptr->GetObj()->wchar_str();
  return AMILabType<wxWritableCharTypeBuffer<wchar_t>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(char const * ascii, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ascii'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> ascii_string;
  if (!get_val_smtptr_param<std::string>(ascii_string,_p,_n)) ClassReturnEmptyVar;
  char const * ascii = ascii_string->c_str();

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii, len);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::FromAscii(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_FromAscii_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromAscii_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromAscii_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromAscii_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromAscii_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(char const * ascii)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ascii'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> ascii_string;
  if (!get_val_smtptr_param<std::string>(ascii_string,_p,_n)) ClassReturnEmptyVar;
  char const * ascii = ascii_string->c_str();

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(char ascii)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ascii'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ascii_string;
  if (!get_val_param<std::string>(ascii_string,_p,_n)) ClassReturnEmptyVar;
  char ascii = ' ';
if (ascii_string.size()>0) ascii = ascii_string[0];

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::ToAscii()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToAscii::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToAscii::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->ToAscii();
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(unsigned char const * ascii)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ascii'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> ascii_smtptr;
  if (!get_val_smtptr_param<unsigned char>(ascii_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* ascii = ascii_smtptr.get();

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(unsigned char const * ascii, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ascii'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> ascii_smtptr;
  if (!get_val_smtptr_param<unsigned char>(ascii_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* ascii = ascii_smtptr.get();

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii, len);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromUTF8Unchecked(char const * utf8)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8Unchecked_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'utf8'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8Unchecked_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> utf8_string;
  if (!get_val_smtptr_param<std::string>(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  wxString res =   this->_objectptr->GetObj()->FromUTF8Unchecked(utf8);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::FromUTF8Unchecked(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8Unchecked::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8Unchecked::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_FromUTF8Unchecked_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromUTF8Unchecked_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromUTF8Unchecked(char const * utf8, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8Unchecked_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'utf8'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8Unchecked_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> utf8_string;
  if (!get_val_smtptr_param<std::string>(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->FromUTF8Unchecked(utf8, len);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromUTF8(char const * utf8)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'utf8'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> utf8_string;
  if (!get_val_smtptr_param<std::string>(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  wxString res =   this->_objectptr->GetObj()->FromUTF8(utf8);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::FromUTF8(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_FromUTF8_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_FromUTF8_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromUTF8(char const * utf8, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromUTF8_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'utf8'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromUTF8_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> utf8_string;
  if (!get_val_smtptr_param<std::string>(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->FromUTF8(utf8, len);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::utf8_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_utf8_str::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_utf8_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->utf8_str();
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::utf8_length()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_utf8_length::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_utf8_length::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->utf8_length();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::ToUTF8()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToUTF8::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToUTF8::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->ToUTF8();
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::From8BitData(char const * data, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_From8BitData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_From8BitData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> data_string;
  if (!get_val_smtptr_param<std::string>(data_string,_p,_n)) ClassReturnEmptyVar;
  char const * data = data_string->c_str();

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->From8BitData(data, len);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::From8BitData(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_From8BitData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_From8BitData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_From8BitData_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_From8BitData_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxString::From8BitData(char const * data)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_From8BitData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'data'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_From8BitData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> data_string;
  if (!get_val_smtptr_param<std::string>(data_string,_p,_n)) ClassReturnEmptyVar;
  char const * data = data_string->c_str();

  wxString res =   this->_objectptr->GetObj()->From8BitData(data);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::To8BitData()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_To8BitData::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_To8BitData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->To8BitData();
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>, wxMBConv

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::mb_str(wxMBConv const & conv = wxGet_wxConvLibc())
//---------------------------------------------------
void WrapClass_wxString::
    wrap_mb_str::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv' (def:wxGet_wxConvLibc())")
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_mb_str::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMBConv> conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(conv_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMBConv const & conv = (conv_smtptr.get()?
    (wxMBConv const &) (*conv_smtptr):
    (wxMBConv const &) wxGet_wxConvLibc());

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->mb_str(conv);
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/
/* The following types are missing: wxCharBuffer

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::mbc_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_mbc_str::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_mbc_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->mbc_str();
  return AMILabType<wxCharBuffer>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxScopedWCharBuffer const wxString::wc_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wc_str_1::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<wchar_t>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wc_str_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxScopedWCharBuffer const res =   this->_objectptr->GetObj()->wc_str();
  return AMILabType<wxScopedCharTypeBuffer<wchar_t>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::wc_str(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wc_str::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wc_str::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxWCharBuffer, wxMBConv

//---------------------------------------------------
//  Wrapping of wxWCharBuffer const wxString::wc_str(wxMBConv const & param0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wc_str_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param0'")
  return_comments="returning a variable of type wxWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wc_str_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMBConv> param0_smtptr;
  if (!get_val_smtptr_param<wxMBConv>(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param0 = *param0_smtptr;

  wxWCharBuffer const res =   this->_objectptr->GetObj()->wc_str(param0);
  return AMILabType<wxWCharBuffer>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxScopedCharBuffer const wxString::fn_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_fn_str::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<char>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_fn_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedCharBuffer const res =   this->_objectptr->GetObj()->fn_str();
  return AMILabType<wxScopedCharTypeBuffer<char>>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxScopedWCharBuffer const wxString::t_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_t_str::SetParametersComments()
{
  return_comments="returning a variable of type wxScopedCharTypeBuffer<wchar_t>";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_t_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxScopedWCharBuffer const res =   this->_objectptr->GetObj()->t_str();
  return AMILabType<wxScopedCharTypeBuffer<wchar_t>>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Append(s);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Append(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_Append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_14 m14(this->_objectptr);
  res = m14.CallMember(_p);
  if (!m14.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_15 m15(this->_objectptr);
  res = m15.CallMember(_p);
  if (!m15.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Append_16 m16(this->_objectptr);
  res = m16.CallMember(_p);
  if (!m16.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->Append(psz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->Append(pwz);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxCStrData const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> psz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & psz = *psz_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Append(psz);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxScopedCharBuffer const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> psz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & psz = *psz_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Append(psz);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxScopedWCharBuffer const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> psz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & psz = *psz_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Append(psz);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(char const * psz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(psz, nLen);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wchar_t const * pwz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(pwz, nLen);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxCStrData const & psz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> psz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & psz = *psz_smtptr;

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(psz, nLen);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxScopedCharBuffer const & psz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> psz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & psz = *psz_smtptr;

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(psz, nLen);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxScopedWCharBuffer const & psz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> psz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & psz = *psz_smtptr;

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(psz, nLen);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxUniChar ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long count_long = boost::numeric_cast<long>(1u);;
  if (!get_val_param<long>(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int>(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxUniCharRef ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long count_long = boost::numeric_cast<long>(1u);;
  if (!get_val_param<long>(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int>(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(char ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long count_long = boost::numeric_cast<long>(1u);;
  if (!get_val_param<long>(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int>(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(unsigned char ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long count_long = boost::numeric_cast<long>(1u);;
  if (!get_val_param<long>(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int>(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wchar_t ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_16::CallMember( ParamList* _p)
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


  long count_long = boost::numeric_cast<long>(1u);;
  if (!get_val_param<long>(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int>(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Prepend(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Prepend::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Prepend::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Prepend(str);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  int res =   this->_objectptr->GetObj()->Cmp(psz);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Cmp(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_Cmp_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Cmp_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Cmp_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  int res =   this->_objectptr->GetObj()->Cmp(pwz);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->Cmp(s);
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxCStrData const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> s_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->Cmp(s);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxScopedCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->Cmp(s);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxScopedWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->Cmp(s);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxString::CmpNoCase(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_CmpNoCase::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_CmpNoCase::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->CmpNoCase(s);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxString const & str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::IsSameAs(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_IsSameAs_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_IsSameAs_12 m12(this->_objectptr);
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(char const * str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  char const * str = str_string->c_str();

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wchar_t const * str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> str_string;
  if (!get_val_smtptr_param<std::string>(str_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t str[str_string->size()+1];
mbstowcs(str,str_string->c_str(),str_string->size()+1);

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxCStrData const & str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxScopedCharBuffer const & str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxScopedWCharBuffer const & str, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(str, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxUniChar c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar c;
  if (!get_val_param<wxUniChar>(c,_p,_n)) ClassReturnEmptyVar;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxUniCharRef c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef c;
  if (!get_val_param<wxUniCharRef>(c,_p,_n)) ClassReturnEmptyVar;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(char c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string c_string;
  if (!get_val_param<std::string>(c_string,_p,_n)) ClassReturnEmptyVar;
  char c = ' ';
if (c_string.size()>0) c = c_string[0];

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(unsigned char c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char c;
  if (!get_val_param<unsigned char>(c,_p,_n)) ClassReturnEmptyVar;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wchar_t c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_11::CallMember( ParamList* _p)
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


  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(int c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'compareWithCase' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsSameAs_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int c;
  if (!get_val_param<int>(c,_p,_n)) ClassReturnEmptyVar;

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int>(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Mid(size_t nFirst, size_t nCount = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Mid::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nFirst'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount' (def:wxString::npos)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Mid::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long nFirst_long;
  if (!get_val_param<long>(nFirst_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nFirst = boost::numeric_cast<long unsigned int>(nFirst_long);

  long nCount_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Mid(nFirst, nCount);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxString::StartsWith(wxString const & prefix, wxString * rest = 0l)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_StartsWith::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'prefix'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'rest' (def:0l)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_StartsWith::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> prefix_smtptr;
  if (!get_val_smtptr_param<wxString>(prefix_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & prefix = *prefix_smtptr;

  boost::shared_ptr<wxString> rest_smtptr;
  if (!get_val_smtptr_param<wxString>(rest_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString* rest = rest_smtptr.get();

  bool res =   this->_objectptr->GetObj()->StartsWith(prefix, rest);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::EndsWith(wxString const & suffix, wxString * rest = 0l)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_EndsWith::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'suffix'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'rest' (def:0l)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_EndsWith::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> suffix_smtptr;
  if (!get_val_smtptr_param<wxString>(suffix_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & suffix = *suffix_smtptr;

  boost::shared_ptr<wxString> rest_smtptr;
  if (!get_val_smtptr_param<wxString>(rest_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString* rest = rest_smtptr.get();

  bool res =   this->_objectptr->GetObj()->EndsWith(suffix, rest);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Left(size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Left::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Left::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Left(nCount);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Right(size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Right::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Right::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Right(nCount);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::BeforeFirst(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_BeforeFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_BeforeFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->BeforeFirst(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::BeforeLast(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_BeforeLast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_BeforeLast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->BeforeLast(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::AfterFirst(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_AfterFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_AfterFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->AfterFirst(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::AfterLast(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_AfterLast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_AfterLast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->AfterLast(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::Before(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Before::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Before::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->Before(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString wxString::After(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_After::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_After::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->After(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::MakeUpper()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_MakeUpper::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_MakeUpper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString & res =   this->_objectptr->GetObj()->MakeUpper();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Upper()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Upper::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Upper::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->Upper();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::MakeLower()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_MakeLower::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_MakeLower::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString & res =   this->_objectptr->GetObj()->MakeLower();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Lower()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Lower::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Lower::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->Lower();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::MakeCapitalized()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_MakeCapitalized::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_MakeCapitalized::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString & res =   this->_objectptr->GetObj()->MakeCapitalized();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Capitalize()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Capitalize::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Capitalize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->Capitalize();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Trim(bool bFromRight = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Trim::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromRight' (def:true)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Trim::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int bFromRight_int = ((true==true)?1:0);;
  if (!get_val_param<int>(bFromRight_int,_p,_n)) ClassHelpAndReturn;
  bool bFromRight = (bool) (bFromRight_int>0.5);

  wxString & res =   this->_objectptr->GetObj()->Trim(bFromRight);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::Pad(size_t nCount, wxUniChar chPad = 32, bool bFromRight = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Pad::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'chPad' (def:32)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromRight' (def:true)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Pad::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxUniChar chPad = 32;
  if (!get_val_param<wxUniChar>(chPad,_p,_n)) ClassHelpAndReturn;

  int bFromRight_int = ((true==true)?1:0);;
  if (!get_val_param<int>(bFromRight_int,_p,_n)) ClassHelpAndReturn;
  bool bFromRight = (bool) (bFromRight_int>0.5);

  wxString & res =   this->_objectptr->GetObj()->Pad(nCount, chPad, bFromRight);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxUniChar ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Find(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_Find_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxUniCharRef ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxString::Find(char ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(unsigned char ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(wchar_t ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bFromEnd' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_5::CallMember( ParamList* _p)
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


  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int>(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxString const & sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> sub_smtptr;
  if (!get_val_smtptr_param<wxString>(sub_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & sub = *sub_smtptr;

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(char const * sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sub_string;
  if (!get_val_smtptr_param<std::string>(sub_string,_p,_n)) ClassReturnEmptyVar;
  char const * sub = sub_string->c_str();

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(wchar_t const * sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sub_string;
  if (!get_val_smtptr_param<std::string>(sub_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sub[sub_string->size()+1];
mbstowcs(sub,sub_string->c_str(),sub_string->size()+1);

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxCStrData const & sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sub_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sub_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sub = *sub_smtptr;

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxScopedCharBuffer const & sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sub_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sub_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sub = *sub_smtptr;

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxScopedWCharBuffer const & sub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sub_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sub_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sub = *sub_smtptr;

  int res =   this->_objectptr->GetObj()->Find(sub);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::Replace(wxString const & strOld, wxString const & strNew, bool bReplaceAll = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Replace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'strOld'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'strNew'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bReplaceAll' (def:true)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Replace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> strOld_smtptr;
  if (!get_val_smtptr_param<wxString>(strOld_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & strOld = *strOld_smtptr;

  boost::shared_ptr<wxString> strNew_smtptr;
  if (!get_val_smtptr_param<wxString>(strNew_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & strNew = *strNew_smtptr;

  int bReplaceAll_int = ((true==true)?1:0);;
  if (!get_val_param<int>(bReplaceAll_int,_p,_n)) ClassHelpAndReturn;
  bool bReplaceAll = (bool) (bReplaceAll_int>0.5);

  size_t res =   this->_objectptr->GetObj()->Replace(strOld, strNew, bReplaceAll);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxString::Matches(wxString const & mask)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Matches::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mask'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Matches::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> mask_smtptr;
  if (!get_val_smtptr_param<wxString>(mask_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & mask = *mask_smtptr;

  bool res =   this->_objectptr->GetObj()->Matches(mask);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::ToLong(long int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long> val_long;
  if (!get_val_smtptr_param<long>(val_long,_p,_n)) ClassHelpAndReturn;
  long int val_val = *val_long;
  long int* val = &val_val;

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::ToULong(long unsigned int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToULong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToULong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long> val_long;
  if (!get_val_smtptr_param<long>(val_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int val_val = boost::numeric_cast<long unsigned int>(*val_long);
  long unsigned int* val = &val_val;

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToULong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: long long int

//---------------------------------------------------
//  Wrapping of bool wxString::ToLongLong(long long int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToLongLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long int, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToLongLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long long int> val_smtptr;
  if (!get_val_smtptr_param<long long int>(val_smtptr,_p,_n)) ClassHelpAndReturn;
  long long int* val = val_smtptr.get();

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToLongLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/* The following types are missing: long long unsigned int

//---------------------------------------------------
//  Wrapping of bool wxString::ToULongLong(long long unsigned int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToULongLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToULongLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long long unsigned int> val_smtptr;
  if (!get_val_smtptr_param<long long unsigned int>(val_smtptr,_p,_n)) ClassHelpAndReturn;
  long long unsigned int* val = val_smtptr.get();

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToULongLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxString::ToDouble(double * val)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double> val_smtptr;
  if (!get_val_smtptr_param<double>(val_smtptr,_p,_n)) ClassHelpAndReturn;
  double* val = val_smtptr.get();

  bool res =   this->_objectptr->GetObj()->ToDouble(val);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::ToCLong(long int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToCLong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToCLong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long> val_long;
  if (!get_val_smtptr_param<long>(val_long,_p,_n)) ClassHelpAndReturn;
  long int val_val = *val_long;
  long int* val = &val_val;

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToCLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::ToCULong(long unsigned int * val, int base = 10)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToCULong::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'val'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'base' (def:10)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToCULong::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<long> val_long;
  if (!get_val_smtptr_param<long>(val_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int val_val = boost::numeric_cast<long unsigned int>(*val_long);
  long unsigned int* val = &val_val;

  int base = 10;
  if (!get_val_param<int>(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToCULong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::ToCDouble(double * val)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToCDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToCDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<double> val_smtptr;
  if (!get_val_smtptr_param<double>(val_smtptr,_p,_n)) ClassHelpAndReturn;
  double* val = val_smtptr.get();

  bool res =   this->_objectptr->GetObj()->ToCDouble(val);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromDouble(double val)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double val;
  if (!get_val_param<double>(val,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FromDouble(val);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromCDouble(double val)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromCDouble::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'val'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromCDouble::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double val;
  if (!get_val_param<double>(val,_p,_n)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FromCDouble(val);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of int wxString::Printf(wxFormatString const & f1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Printf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Printf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassHelpAndReturn;
  wxFormatString const & f1 = *f1_smtptr;

  int res =   this->_objectptr->GetObj()->Printf(f1);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: __va_list_tag

//---------------------------------------------------
//  Wrapping of int wxString::PrintfV(wxString const & format, __va_list_tag * argptr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_PrintfV::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'format'")
  ADDPARAMCOMMENT_TYPE( __va_list_tag, "parameter named 'argptr'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_PrintfV::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> format_smtptr;
  if (!get_val_smtptr_param<wxString>(format_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & format = *format_smtptr;

  boost::shared_ptr<__va_list_tag> argptr_smtptr;
  if (!get_val_smtptr_param<__va_list_tag>(argptr_smtptr,_p,_n)) ClassHelpAndReturn;
  __va_list_tag* argptr = argptr_smtptr.get();

  int res =   this->_objectptr->GetObj()->PrintfV(format, argptr);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  wxString res =   this->_objectptr->GetObj()->Format(f1);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Format(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, double a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  double a1;
  if (!get_val_param<double>(a1,_p,_n)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, float a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  float a1;
  if (!get_val_param<float>(a1,_p,_n)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString, long long unsigned int

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, long long unsigned int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  long long unsigned int a1;
  if (!get_val_param<long long unsigned int>(a1,_p,_n)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString, long long int

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, long long int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( long long int, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  long long int a1;
  if (!get_val_param<long long int>(a1,_p,_n)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, long unsigned int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  long a1_long;
  if (!get_val_param<long>(a1_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int a1 = boost::numeric_cast<long unsigned int>(a1_long);

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, long int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  long a1_long;
  if (!get_val_param<long>(a1_long,_p,_n)) ClassReturnEmptyVar;
  long int a1 = a1_long;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, unsigned int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  long a1_long;
  if (!get_val_param<long>(a1_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int a1 = boost::numeric_cast<unsigned int>(a1_long);

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxFormatString const & f1, int a1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxFormatString const & f1 = *f1_smtptr;

  int a1;
  if (!get_val_param<int>(a1,_p,_n)) ClassReturnEmptyVar;

  wxString res =   this->_objectptr->GetObj()->Format(f1, a1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: __va_list_tag

//---------------------------------------------------
//  Wrapping of wxString wxString::FormatV(wxString const & format, __va_list_tag * argptr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FormatV::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'format'")
  ADDPARAMCOMMENT_TYPE( __va_list_tag, "parameter named 'argptr'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FormatV::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> format_smtptr;
  if (!get_val_smtptr_param<wxString>(format_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & format = *format_smtptr;

  boost::shared_ptr<__va_list_tag> argptr_smtptr;
  if (!get_val_smtptr_param<__va_list_tag>(argptr_smtptr,_p,_n)) ClassHelpAndReturn;
  __va_list_tag* argptr = argptr_smtptr.get();

  wxString res =   this->_objectptr->GetObj()->FormatV(format, argptr);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxString::Alloc(size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Alloc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Alloc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  bool res =   this->_objectptr->GetObj()->Alloc(nLen);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::Shrink()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Shrink::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Shrink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Shrink();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::SubString(size_t from, size_t to)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_SubString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'from'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'to'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_SubString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long from_long;
  if (!get_val_param<long>(from_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int from = boost::numeric_cast<long unsigned int>(from_long);

  long to_long;
  if (!get_val_param<long>(to_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int to = boost::numeric_cast<long unsigned int>(to_long);

  wxString res =   this->_objectptr->GetObj()->SubString(from, to);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxFormatString

//---------------------------------------------------
//  Wrapping of int wxString::sprintf(wxFormatString const & f1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_sprintf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFormatString, "parameter named 'f1'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_sprintf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFormatString> f1_smtptr;
  if (!get_val_smtptr_param<wxFormatString>(f1_smtptr,_p,_n)) ClassHelpAndReturn;
  wxFormatString const & f1 = *f1_smtptr;

  int res =   this->_objectptr->GetObj()->sprintf(f1);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::Length()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Length::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Length::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->Length();
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of int wxString::Freq(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Freq::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Freq::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->Freq(ch);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxString::LowerCase()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_LowerCase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_LowerCase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->LowerCase();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxString::UpperCase()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_UpperCase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_UpperCase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UpperCase();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxString::Index(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Index_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Index_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  size_t res =   this->_objectptr->GetObj()->Index(psz);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Index(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Index::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Index::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_Index_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::Index(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Index_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Index_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  size_t res =   this->_objectptr->GetObj()->Index(ch);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::Remove(size_t pos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Remove_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Remove_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long pos_long;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  wxString & res =   this->_objectptr->GetObj()->Remove(pos);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::RemoveLast(size_t n = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_RemoveLast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:1)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_RemoveLast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long = boost::numeric_cast<long>(1);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->RemoveLast(n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::Remove(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Remove::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Remove::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_Remove_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Remove_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Remove(size_t nStart, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Remove_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Remove_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long nLen_long;
  if (!get_val_param<long>(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int>(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Remove(nStart, nLen);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of int wxString::First(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::First(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_First_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_First_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_First_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_First_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of int wxString::First(wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxString::First(char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::First(unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::First(wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_5::CallMember( ParamList* _p)
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


  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::First(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->First(str);
  return AMILabType<int>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of int wxString::Last(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  int res =   this->_objectptr->GetObj()->Last(ch);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxString::Contains(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Contains::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Contains::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  bool res =   this->_objectptr->GetObj()->Contains(str);
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsNull()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsNull::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_IsNull::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNull();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxString const & str, size_t pos, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long pos_long;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(str, pos, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::append(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_append_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_15 m15(this->_objectptr);
  res = m15.CallMember(_p);
  if (!m15.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_16 m16(this->_objectptr);
  res = m16.CallMember(_p);
  if (!m16.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_17 m17(this->_objectptr);
  res = m17.CallMember(_p);
  if (!m17.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_19 m19(this->_objectptr);
  res = m19.CallMember(_p);
  if (!m19.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_append_20 m20(this->_objectptr);
  res = m20.CallMember(_p);
  if (!m20.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(char const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->append(sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wchar_t const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->append(sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(char const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(sz, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wchar_t const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_6::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->append(sz, n);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxCStrData const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxScopedCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxScopedWCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxCStrData const & str, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(str, n);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxScopedCharBuffer const & str, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(str, n);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxScopedWCharBuffer const & str, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(str, n);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_17::CallMember( ParamList* _p)
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


  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(const_iterator first, const_iterator last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_18::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator first;
  if (!get_val_param<const_iterator>(first,_p,_n)) ClassReturnEmptyVar;

  const_iterator last;
  if (!get_val_param<const_iterator>(last,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(char const * first, char const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  char const * first = first_string->c_str();

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  char const * last = last_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wchar_t const * first, wchar_t const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_20::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_20::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData, wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxCStrData const & first, wxCStrData const & last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_21::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_21::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> first_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & first = *first_smtptr;

  boost::shared_ptr<wxCStrData> last_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & last = *last_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(str);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::assign(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_assign_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_16 m16(this->_objectptr);
  res = m16.CallMember(_p);
  if (!m16.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_17 m17(this->_objectptr);
  res = m17.CallMember(_p);
  if (!m17.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_18 m18(this->_objectptr);
  res = m18.CallMember(_p);
  if (!m18.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_20 m20(this->_objectptr);
  res = m20.CallMember(_p);
  if (!m20.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_assign_21 m21(this->_objectptr);
  res = m21.CallMember(_p);
  if (!m21.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxString const & str, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, len);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxString const & str, size_t pos, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long pos_long;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, pos, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(char const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->assign(sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wchar_t const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->assign(sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(char const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->assign(sz, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wchar_t const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_7::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->assign(sz, n);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxCStrData const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxScopedCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxScopedWCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(str);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxCStrData const & str, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, len);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxScopedCharBuffer const & str, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, len);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxScopedWCharBuffer const & str, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, len);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_18::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_18::CallMember( ParamList* _p)
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


  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(const_iterator first, const_iterator last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_19::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_19::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  const_iterator first;
  if (!get_val_param<const_iterator>(first,_p,_n)) ClassReturnEmptyVar;

  const_iterator last;
  if (!get_val_param<const_iterator>(last,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->assign(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(char const * first, char const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_20::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_20::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  char const * first = first_string->c_str();

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  char const * last = last_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->assign(first, last);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wchar_t const * first, wchar_t const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_21::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_21::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->assign(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxCStrData, wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxCStrData const & first, wxCStrData const & last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_22::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_22::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> first_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & first = *first_smtptr;

  boost::shared_ptr<wxCStrData> last_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & last = *last_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(first, last);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxString::compare(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(str);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::compare(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_compare_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_compare_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::compare(char const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  int res =   this->_objectptr->GetObj()->compare(sz);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::compare(wchar_t const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_3::CallMember( ParamList* _p)
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
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of int wxString::compare(wxCStrData const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> str_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(str);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of int wxString::compare(wxScopedCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(str);
  return AMILabType<int>::CreateVar(res);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of int wxString::compare(wxScopedWCharBuffer const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> str_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(str);
  return AMILabType<int>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxString::compare(size_t nStart, size_t nLen, wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_7::CallMember( ParamList* _p)
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

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, str);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::compare(size_t nStart, size_t nLen, wxString const & str, size_t nStart2, size_t nLen2)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart2'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_8::CallMember( ParamList* _p)
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

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

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
//  Wrapping of int wxString::compare(size_t nStart, size_t nLen, char const * sz, size_t nCount = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount' (def:wxString::npos)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_9::CallMember( ParamList* _p)
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
  char const * sz = sz_string->c_str();

  long nCount_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, sz, nCount);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::compare(size_t nStart, size_t nLen, wchar_t const * sz, size_t nCount = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_compare_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount' (def:wxString::npos)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_compare_10::CallMember( ParamList* _p)
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

  long nCount_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  int res =   this->_objectptr->GetObj()->compare(nStart, nLen, sz, nCount);
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, str);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::insert(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_insert_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wxString const & str, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, str, nStart, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, char const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wchar_t const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, char const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long>(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int>(nPos_long);

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wchar_t const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_6::CallMember( ParamList* _p)
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

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz, n);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_7::CallMember( ParamList* _p)
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

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator, wxUniChar

//---------------------------------------------------
//  Wrapping of iterator wxString::insert(iterator it, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->insert(it, ch);
  return AMILabType<iterator>::CreateVar(res);
}
*/
/* The following types are missing: iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of void wxString::insert(iterator it, const_iterator first, const_iterator last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

  const_iterator first;
  if (!get_val_param<const_iterator>(first,_p,_n)) ClassReturnEmptyVar;

  const_iterator last;
  if (!get_val_param<const_iterator>(last,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxString::insert(iterator it, char const * first, char const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> first_string;
  if (!get_val_smtptr_param<std::string>(first_string,_p,_n)) ClassReturnEmptyVar;
  char const * first = first_string->c_str();

  boost::shared_ptr<std::string> last_string;
  if (!get_val_smtptr_param<std::string>(last_string,_p,_n)) ClassReturnEmptyVar;
  char const * last = last_string->c_str();

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator

//---------------------------------------------------
//  Wrapping of void wxString::insert(iterator it, wchar_t const * first, wchar_t const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

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
*/
/* The following types are missing: iterator, wxCStrData, wxCStrData

//---------------------------------------------------
//  Wrapping of void wxString::insert(iterator it, wxCStrData const & first, wxCStrData const & last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxCStrData> first_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(first_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & first = *first_smtptr;

  boost::shared_ptr<wxCStrData> last_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(last_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & last = *last_smtptr;

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: iterator, wxUniChar

//---------------------------------------------------
//  Wrapping of void wxString::insert(iterator it, size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator it;
  if (!get_val_param<iterator>(it,_p,_n)) ClassReturnEmptyVar;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->insert(it, n, ch);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::erase(size_t pos = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int>(pos_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->erase(pos, n);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::erase(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_erase_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: iterator, iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxString::erase(iterator first, iterator last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->erase(first, last);
  return AMILabType<iterator>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of iterator wxString::erase(iterator first)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  return_comments="returning a variable of type iterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator res =   this->_objectptr->GetObj()->erase(first);
  return AMILabType<iterator>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxString::clear()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, char const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_1::CallMember( ParamList* _p)
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
  char const * sz = sz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::replace(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_replace_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wchar_t const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_2::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_3::CallMember( ParamList* _p)
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

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, size_t nCount, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_4::CallMember( ParamList* _p)
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

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, nCount, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str, size_t nStart2, size_t nLen2)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart2'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen2'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_5::CallMember( ParamList* _p)
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

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart2_long;
  if (!get_val_param<long>(nStart2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart2 = boost::numeric_cast<long unsigned int>(nStart2_long);

  long nLen2_long;
  if (!get_val_param<long>(nLen2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen2 = boost::numeric_cast<long unsigned int>(nLen2_long);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str, nStart2, nLen2);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, char const * sz, size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_6::CallMember( ParamList* _p)
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
  char const * sz = sz_string->c_str();

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz, nCount);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wchar_t const * sz, size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_7::CallMember( ParamList* _p)
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

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz, nCount);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & s, size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_8::CallMember( ParamList* _p)
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

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  long nCount_long;
  if (!get_val_param<long>(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int>(nCount_long);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, s, nCount);
  return AMILabType<wxString>::CreateVar(res);
}
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, char const * s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  char const * s = s_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, wchar_t const * s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, char const * s, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  char const * s = s_string->c_str();

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s, n);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, wchar_t const * s, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> s_string;
  if (!get_val_smtptr_param<std::string>(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s, n);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator, wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, size_t n, wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, n, ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator, const_iterator, const_iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, const_iterator first1, const_iterator last1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'first1'")
  ADDPARAMCOMMENT_TYPE( const_iterator, "parameter named 'last1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  const_iterator first1;
  if (!get_val_param<const_iterator>(first1,_p,_n)) ClassReturnEmptyVar;

  const_iterator last1;
  if (!get_val_param<const_iterator>(last1,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, first1, last1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, char const * first1, char const * last1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first1'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> first1_string;
  if (!get_val_smtptr_param<std::string>(first1_string,_p,_n)) ClassReturnEmptyVar;
  char const * first1 = first1_string->c_str();

  boost::shared_ptr<std::string> last1_string;
  if (!get_val_smtptr_param<std::string>(last1_string,_p,_n)) ClassReturnEmptyVar;
  char const * last1 = last1_string->c_str();

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, first1, last1);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/* The following types are missing: iterator, iterator

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(iterator first, iterator last, wchar_t const * first1, wchar_t const * last1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_17::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( iterator, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first1'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_17::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  iterator first;
  if (!get_val_param<iterator>(first,_p,_n)) ClassReturnEmptyVar;

  iterator last;
  if (!get_val_param<iterator>(last,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<std::string> first1_string;
  if (!get_val_smtptr_param<std::string>(first1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first1[first1_string->size()+1];
mbstowcs(first1,first1_string->c_str(),first1_string->size()+1);

  boost::shared_ptr<std::string> last1_string;
  if (!get_val_smtptr_param<std::string>(last1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last1[last1_string->size()+1];
mbstowcs(last1,last1_string->c_str(),last1_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, first1, last1);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxString::swap(wxString & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_swap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_swap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString & str = *str_smtptr;

  this->_objectptr->GetObj()->swap(str);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxString const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::find(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find(char const * sz, size_t nStart = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wchar_t const * sz, size_t nStart = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_3::CallMember( ParamList* _p)
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

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxScopedCharBuffer const & s, size_t nStart = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxScopedWCharBuffer const & s, size_t nStart = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxCStrData const & s, size_t nStart = 0, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> s_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->find(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxUniChar ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wxUniCharRef ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find(char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find(unsigned char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find(wchar_t ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_11::CallMember( ParamList* _p)
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
//  Wrapping of size_t wxString::rfind(wxString const & str, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::rfind(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_rfind_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_rfind_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_rfind_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_rfind_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_rfind_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_rfind_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(char const * sz, size_t nStart = wxString::npos, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wchar_t const * sz, size_t nStart = wxString::npos, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(sz, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wxScopedCharBuffer const & s, size_t nStart = wxString::npos, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wxScopedWCharBuffer const & s, size_t nStart = wxString::npos, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wxCStrData const & s, size_t nStart = wxString::npos, size_t n = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> s_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & s = *s_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  long n_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  size_t res =   this->_objectptr->GetObj()->rfind(s, nStart, n);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wxUniChar ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wxUniCharRef ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(unsigned char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::rfind(wchar_t ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_rfind_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_rfind_11::CallMember( ParamList* _p)
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


  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->rfind(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxString const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::find_first_of(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_find_first_of_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_of_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(char const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wchar_t const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_3::CallMember( ParamList* _p)
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
//  Wrapping of size_t wxString::find_first_of(char const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

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
//  Wrapping of size_t wxString::find_first_of(wchar_t const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_5::CallMember( ParamList* _p)
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
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxUniChar c, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar c;
  if (!get_val_param<wxUniChar>(c,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(c, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxString const & str, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::find_last_of(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_find_last_of_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_of_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(char const * sz, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wchar_t const * sz, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(char const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

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
//  Wrapping of size_t wxString::find_last_of(wchar_t const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_5::CallMember( ParamList* _p)
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
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxUniChar c, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'c'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar c;
  if (!get_val_param<wxUniChar>(c,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(c, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxString const & str, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::find_first_not_of(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_find_first_not_of_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_first_not_of_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(char const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wchar_t const * sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_3::CallMember( ParamList* _p)
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
//  Wrapping of size_t wxString::find_first_not_of(char const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

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
//  Wrapping of size_t wxString::find_first_not_of(wchar_t const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_5::CallMember( ParamList* _p)
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
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxUniChar ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxString const & str, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> str_smtptr;
  if (!get_val_smtptr_param<wxString>(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(str, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::find_last_not_of(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_find_last_not_of_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_find_last_not_of_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(char const * sz, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wchar_t const * sz, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(char const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> sz_string;
  if (!get_val_smtptr_param<std::string>(sz_string,_p,_n)) ClassReturnEmptyVar;
  char const * sz = sz_string->c_str();

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
//  Wrapping of size_t wxString::find_last_not_of(wchar_t const * sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_5::CallMember( ParamList* _p)
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
/* The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxUniChar ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxUniCharRef ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(unsigned char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wchar_t ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_10::CallMember( ParamList* _p)
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

  size_t res =   this->_objectptr->GetObj()->find_first_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxUniCharRef ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(unsigned char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wchar_t ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_10::CallMember( ParamList* _p)
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


  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxUniCharRef ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(unsigned char ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wchar_t ch, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_10::CallMember( ParamList* _p)
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
/* The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxUniCharRef ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(unsigned char ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wchar_t ch, size_t nStart = wxString::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:wxString::npos)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_10::CallMember( ParamList* _p)
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


  long nStart_long = boost::numeric_cast<long>(wxString::npos);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(ch, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxCStrData const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxScopedCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxScopedWCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxCStrData const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxScopedCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_of(wxScopedWCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_of_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_of_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxCStrData const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxScopedCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxScopedWCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxCStrData const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxScopedCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_of(wxScopedWCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_of_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_of_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxCStrData const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxScopedCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxScopedWCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_first_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxCStrData const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxScopedCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_first_not_of(wxScopedWCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_first_not_of_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_first_not_of_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxCStrData const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxScopedCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxScopedWCharBuffer const & sz, size_t nStart = 0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart' (def:0)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

  long nStart_long = boost::numeric_cast<long>(0);;
  if (!get_val_param<long>(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int>(nStart_long);

  size_t res =   this->_objectptr->GetObj()->find_last_not_of(sz, nStart);
  long res_long = boost::numeric_cast<long>(res);
  return AMILabType<long>::CreateVar(res_long);
}
*/
/* The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxCStrData const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_14::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_14::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> sz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxScopedCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_15::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_15::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & sz = *sz_smtptr;

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
*/
/* The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of size_t wxString::find_last_not_of(wxScopedWCharBuffer const & sz, size_t nStart, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_find_last_not_of_16::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_find_last_not_of_16::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> sz_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(sz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & sz = *sz_smtptr;

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
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool wxString::!()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->!();
  int res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::[](int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int>(n,_p,_n)) ClassReturnEmptyVar;

  wxUniChar res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::[](...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::[](long int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long int n = n_long;

  wxUniChar res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::[](size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniChar res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxUniChar wxString::[](unsigned int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniChar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int n = boost::numeric_cast<unsigned int>(n_long);

  wxUniChar res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniChar>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::[](int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int>(n,_p,_n)) ClassReturnEmptyVar;

  wxUniCharRef res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::[](long int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long int n = n_long;

  wxUniCharRef res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::[](size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int>(n_long);

  wxUniCharRef res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxUniCharRef wxString::[](unsigned int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxUniCharRef";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long>(n_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int n = boost::numeric_cast<unsigned int>(n_long);

  wxUniCharRef res =   (*this->_objectptr->GetObj()) [ (n)];
  return AMILabType<wxUniCharRef>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxString const & stringSrc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'stringSrc'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> stringSrc_smtptr;
  if (!get_val_smtptr_param<wxString>(stringSrc_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & stringSrc = *stringSrc_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (stringSrc);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::=(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap___assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/*
 * The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxCStrData const & cstr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'cstr'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> cstr_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(cstr_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & cstr = *cstr_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (cstr);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___7::CallMember( ParamList* _p)
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


  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  wxString & res =   (*this->_objectptr->GetObj()) = (psz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  wxString & res =   (*this->_objectptr->GetObj()) = (pwz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(unsigned char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char> psz_smtptr;
  if (!get_val_smtptr_param<unsigned char>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* psz = psz_smtptr.get();

  wxString & res =   (*this->_objectptr->GetObj()) = (psz);
  return AMILabType<wxString>::CreateVar(res);
}
/*
 * The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxScopedWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxScopedCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::<<(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_operator not available_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_6 m6(this->_objectptr);
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_12 m12(this->_objectptr);
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_13 m13(this->_objectptr);
  res = m13.CallMember(_p);
  if (!m13.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_14 m14(this->_objectptr);
  res = m14.CallMember(_p);
  if (!m14.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_15 m15(this->_objectptr);
  res = m15.CallMember(_p);
  if (!m15.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_16 m16(this->_objectptr);
  res = m16.CallMember(_p);
  if (!m16.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_17 m17(this->_objectptr);
  res = m17.CallMember(_p);
  if (!m17.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_18 m18(this->_objectptr);
  res = m18.CallMember(_p);
  if (!m18.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_operator not available_19 m19(this->_objectptr);
  res = m19.CallMember(_p);
  if (!m19.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  wxString & res =   this->_objectptr->GetObj()-><<(psz);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()-><<(pwz);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxCStrData
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxCStrData const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> psz_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & psz = *psz_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(psz);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniChar
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
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


  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxScopedCharTypeBuffer<wchar_t>
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxScopedWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxScopedCharTypeBuffer<char>
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxScopedCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(int i)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int i;
  if (!get_val_param<int>(i,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(i);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(unsigned int ui)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ui'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ui_long;
  if (!get_val_param<long>(ui_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int ui = boost::numeric_cast<unsigned int>(ui_long);

  wxString & res =   this->_objectptr->GetObj()-><<(ui);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(long int l)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'l'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long l_long;
  if (!get_val_param<long>(l_long,_p,_n)) ClassReturnEmptyVar;
  long int l = l_long;

  wxString & res =   this->_objectptr->GetObj()-><<(l);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(long unsigned int ul)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'ul'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long ul_long;
  if (!get_val_param<long>(ul_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int ul = boost::numeric_cast<long unsigned int>(ul_long);

  wxString & res =   this->_objectptr->GetObj()-><<(ul);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: long long int
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(long long int ll)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long int, "parameter named 'll'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long int ll;
  if (!get_val_param<long long int>(ll,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ll);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: long long unsigned int
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(long long unsigned int ull)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long long unsigned int, "parameter named 'ull'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long long unsigned int ull;
  if (!get_val_param<long long unsigned int>(ull,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ull);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(float f)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( float, "parameter named 'f'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  float f;
  if (!get_val_param<float>(f,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(f);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(double d)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'd'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  double d;
  if (!get_val_param<double>(d,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(d);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString wxString::()(size_t start, size_t len)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'start'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long start_long;
  if (!get_val_param<long>(start_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int start = boost::numeric_cast<long unsigned int>(start_long);

  long len_long;
  if (!get_val_param<long>(len_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int len = boost::numeric_cast<long unsigned int>(len_long);

  wxString res =   this->_objectptr->GetObj()->()(start, len);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString> s_smtptr;
  if (!get_val_smtptr_param<wxString>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::+=(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___11 m11(this->_objectptr);
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___add_assign___12 m12(this->_objectptr);
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(char const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> psz_string;
  if (!get_val_smtptr_param<std::string>(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  wxString & res =   (*this->_objectptr->GetObj()) += (psz);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wchar_t const * pwz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pwz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string> pwz_string;
  if (!get_val_smtptr_param<std::string>(pwz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pwz[pwz_string->size()+1];
mbstowcs(pwz,pwz_string->c_str(),pwz_string->size()+1);

  wxString & res =   (*this->_objectptr->GetObj()) += (pwz);
  return AMILabType<wxString>::CreateVar(res);
}
/*
 * The following types are missing: wxCStrData

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxCStrData const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCStrData, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxCStrData> s_smtptr;
  if (!get_val_smtptr_param<wxCStrData>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxCStrData const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxScopedCharTypeBuffer<char>

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxScopedCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<char>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<char>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<char>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedCharBuffer const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxScopedCharTypeBuffer<wchar_t>

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxScopedWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxScopedCharTypeBuffer<wchar_t>, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxScopedCharTypeBuffer<wchar_t>> s_smtptr;
  if (!get_val_smtptr_param<wxScopedCharTypeBuffer<wchar_t>>(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxScopedWCharBuffer const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniChar

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxUniChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniChar, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniChar ch;
  if (!get_val_param<wxUniChar>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/
/*
 * The following types are missing: wxUniCharRef

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxUniCharRef ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUniCharRef, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  wxUniCharRef ch;
  if (!get_val_param<wxUniCharRef>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(int ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int ch;
  if (!get_val_param<int>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string>(ch_string,_p,_n)) ClassReturnEmptyVar;
  char ch = ' ';
if (ch_string.size()>0) ch = ch_string[0];

  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(unsigned char ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  unsigned char ch;
  if (!get_val_param<unsigned char>(ch,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wchar_t ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___12::CallMember( ParamList* _p)
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


  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString>::CreateVar(res);
}

