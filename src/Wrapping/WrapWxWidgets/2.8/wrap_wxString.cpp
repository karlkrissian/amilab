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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxStringBase.h"
#include "wrap_wxString.h"
#include "stdlib.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxMBConv.h"
#include "wrap_wxWCharBuffer.h"
#include "wchar.h"
#include "wrap_wxCharBuffer.h"


#include "wrap_wxString.h"

//----------------------------------------------------------------------
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


//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
void WrapClass_wxString::AddMethods(WrapClass<wxString>::ptr this_ptr )
{
  
      // Add members from wxStringBase
      WrapClass_wxStringBase::ptr parent_wxStringBase(        boost::dynamic_pointer_cast<WrapClass_wxStringBase >(this_ptr));
      parent_wxStringBase->AddMethods(parent_wxStringBase);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Len( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_Truncate( this_ptr);
      AddVar_Empty( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_IsAscii( this_ptr);
      AddVar_IsNumber( this_ptr);
      AddVar_IsWord( this_ptr);
      AddVar_GetChar( this_ptr);
      AddVar_GetWritableChar( this_ptr);
      AddVar_SetChar( this_ptr);
      AddVar_Last_1( this_ptr);
      AddVar_Last( this_ptr);
      AddVar_Last_2( this_ptr);
      AddVar_wx_str( this_ptr);
      AddVar_GetData( this_ptr);
/* The following types are missing: wxWritableCharBuffer
      AddVar_char_str( this_ptr);
*/
/* The following types are missing: wxWritableWCharBuffer
      AddVar_wchar_str( this_ptr);
*/
      AddVar_FromAscii_1( this_ptr);
      AddVar_FromAscii( this_ptr);
      AddVar_FromAscii_2( this_ptr);
      AddVar_ToAscii( this_ptr);
      AddVar_FromUTF8_1( this_ptr);
      AddVar_FromUTF8( this_ptr);
      AddVar_FromUTF8_2( this_ptr);
      AddVar_utf8_str( this_ptr);
      AddVar_ToUTF8( this_ptr);
      AddVar_From8BitData_1( this_ptr);
      AddVar_From8BitData( this_ptr);
      AddVar_From8BitData_2( this_ptr);
      AddVar_To8BitData( this_ptr);
      AddVar_mb_str( this_ptr);
      AddVar_mbc_str( this_ptr);
      AddVar_wc_str_1( this_ptr);
      AddVar_wc_str( this_ptr);
      AddVar_wc_str_2( this_ptr);
      AddVar_fn_str( this_ptr);
      AddVar_Append_1( this_ptr);
      AddVar_Append( this_ptr);
      AddVar_Append_2( this_ptr);
      AddVar_Append_3( this_ptr);
      AddVar_Append_4( this_ptr);
      AddVar_Prepend( this_ptr);
      AddVar_Cmp_1( this_ptr);
      AddVar_Cmp( this_ptr);
      AddVar_Cmp_2( this_ptr);
      AddVar_CmpNoCase_1( this_ptr);
      AddVar_CmpNoCase( this_ptr);
      AddVar_CmpNoCase_2( this_ptr);
      AddVar_IsSameAs_1( this_ptr);
      AddVar_IsSameAs( this_ptr);
      AddVar_IsSameAs_2( this_ptr);
      AddVar_Mid( this_ptr);
      AddVar_StartsWith( this_ptr);
      AddVar_EndsWith( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_BeforeFirst( this_ptr);
      AddVar_BeforeLast( this_ptr);
      AddVar_AfterFirst( this_ptr);
      AddVar_AfterLast( this_ptr);
      AddVar_Before( this_ptr);
      AddVar_After( this_ptr);
      AddVar_MakeUpper( this_ptr);
      AddVar_Upper( this_ptr);
      AddVar_MakeLower( this_ptr);
      AddVar_Lower( this_ptr);
      AddVar_Trim( this_ptr);
      AddVar_Pad( this_ptr);
      AddVar_Find_1( this_ptr);
      AddVar_Find( this_ptr);
      AddVar_Find_2( this_ptr);
      AddVar_Replace( this_ptr);
      AddVar_Matches( this_ptr);
      AddVar_ToLong( this_ptr);
      AddVar_ToULong( this_ptr);
/* The following types are missing: long long int
      AddVar_ToLongLong( this_ptr);
*/
/* The following types are missing: long long unsigned int
      AddVar_ToULongLong( this_ptr);
*/
      AddVar_ToDouble( this_ptr);
      AddVar_Printf( this_ptr);
/* The following types are missing: __va_list_tag
      AddVar_PrintfV( this_ptr);
*/
      AddVar_Format( this_ptr);
/* The following types are missing: __va_list_tag
      AddVar_FormatV( this_ptr);
*/
      AddVar_Alloc( this_ptr);
      AddVar_Shrink( this_ptr);
      AddVar_GetWriteBuf( this_ptr);
      AddVar_UngetWriteBuf_1( this_ptr);
      AddVar_UngetWriteBuf( this_ptr);
      AddVar_UngetWriteBuf_2( this_ptr);
      AddVar_SubString( this_ptr);
      AddVar_sprintf( this_ptr);
      AddVar_Length( this_ptr);
      AddVar_Freq( this_ptr);
      AddVar_LowerCase( this_ptr);
      AddVar_UpperCase( this_ptr);
      AddVar_Index_1( this_ptr);
      AddVar_Index( this_ptr);
      AddVar_Index_2( this_ptr);
      AddVar_Remove_1( this_ptr);
      AddVar_RemoveLast( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_Remove_2( this_ptr);
      AddVar_First_1( this_ptr);
      AddVar_First( this_ptr);
      AddVar_First_2( this_ptr);
      AddVar_First_3( this_ptr);
      AddVar_Last_3( this_ptr);
      AddVar_Contains( this_ptr);
      AddVar_IsNull( this_ptr);
      AddVar_append_1( this_ptr);
      AddVar_append( this_ptr);
      AddVar_append_2( this_ptr);
      AddVar_append_3( this_ptr);
      AddVar_append_4( this_ptr);
      AddVar_append_5( this_ptr);
      AddVar_append_6( this_ptr);
      AddVar_assign_1( this_ptr);
      AddVar_assign( this_ptr);
      AddVar_assign_2( this_ptr);
      AddVar_assign_3( this_ptr);
      AddVar_assign_4( this_ptr);
      AddVar_assign_5( this_ptr);
      AddVar_assign_6( this_ptr);
      AddVar_insert_1( this_ptr);
      AddVar_insert( this_ptr);
      AddVar_insert_2( this_ptr);
      AddVar_insert_3( this_ptr);
      AddVar_insert_4( this_ptr);
      AddVar_insert_5( this_ptr);
      AddVar_insert_6( this_ptr);
      AddVar_insert_7( this_ptr);
      AddVar_insert_8( this_ptr);
      AddVar_erase_1( this_ptr);
      AddVar_erase( this_ptr);
      AddVar_erase_2( this_ptr);
      AddVar_erase_3( this_ptr);
      AddVar_replace_1( this_ptr);
      AddVar_replace( this_ptr);
      AddVar_replace_2( this_ptr);
      AddVar_replace_3( this_ptr);
      AddVar_replace_4( this_ptr);
      AddVar_replace_5( this_ptr);
      AddVar_replace_6( this_ptr);
      AddVar_replace_7( this_ptr);
      AddVar_replace_8( this_ptr);
      AddVar_replace_9( this_ptr);
      AddVar_replace_10( this_ptr);

      // Adding operators
      AddVar___assign___1( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___at___1( this_ptr);
      AddVar___at__( this_ptr);
      AddVar___at___2( this_ptr);
      AddVar___at___3( this_ptr);
      AddVar___assign__( this_ptr);
      AddVar___assign___2( this_ptr);
      AddVar___assign___3( this_ptr);
      AddVar___assign___4( this_ptr);
      AddVar___assign___5( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___add_assign___1( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: long long int
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___add_assign__( this_ptr);
      AddVar___add_assign___2( this_ptr);
      AddVar___add_assign___3( this_ptr);
      AddVar___add_assign___4( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


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
  WrapClass_wxString::wrap_wxString_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_8 m8;
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_10 m10;
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_11 m11;
  res = m11.CallMember(_p);
  if (!m11.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wxString_12 m12;
  res = m12.CallMember(_p);
  if (!m12.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxStringBase const & stringSrc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'stringSrc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase > stringSrc_smtptr;
  if (!get_val_smtptr_param<wxStringBase >(stringSrc_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & stringSrc = *stringSrc_smtptr;

  wxString* _newobj = new wxString(stringSrc);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxString const & stringSrc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'stringSrc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > stringSrc_smtptr;
  if (!get_val_smtptr_param<wxString >(stringSrc_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxString const & stringSrc = *stringSrc_smtptr;

  wxString* _newobj = new wxString(stringSrc);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxChar ch, size_t nRepeat = 1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long nRepeat_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int >(nRepeat_long);

  wxString* _newobj = new wxString(ch, nRepeat);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(size_t nRepeat, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nRepeat'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long nRepeat_long;
  if (!get_val_param<long >(nRepeat_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nRepeat = boost::numeric_cast<long unsigned int >(nRepeat_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString* _newobj = new wxString(nRepeat, ch);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxString* _newobj = new wxString(psz);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxChar const * psz, size_t nLength)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  long nLength_long;
  if (!get_val_param<long >(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int >(nLength_long);

  wxString* _newobj = new wxString(psz, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxChar const * psz, wxMBConv const & param1, size_t nLength = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength' (def:wxStringBase::npos)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  boost::shared_ptr<wxMBConv > param1_smtptr;
  if (!get_val_smtptr_param<wxMBConv >(param1_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param1 = *param1_smtptr;

  long nLength_long = boost::numeric_cast<long >(wxStringBase::npos);;
  if (!get_val_param<long >(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int >(nLength_long);

  wxString* _newobj = new wxString(psz, param1, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxStdString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > > s_smtptr;
  if (!get_val_smtptr_param<basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStdString const & s = *s_smtptr;

  wxString* _newobj = new wxString(s);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(char const * psz, wxMBConv const & conv, size_t nLength = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLength' (def:wxStringBase::npos)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  char const * psz = psz_string->c_str();

  boost::shared_ptr<wxMBConv > conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv >(conv_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & conv = *conv_smtptr;

  long nLength_long = boost::numeric_cast<long >(wxStringBase::npos);;
  if (!get_val_param<long >(nLength_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLength = boost::numeric_cast<long unsigned int >(nLength_long);

  wxString* _newobj = new wxString(psz, conv, nLength);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxWCharBuffer const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_11::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'psz'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_11::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > psz_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWCharBuffer const & psz = *psz_smtptr;

  wxString* _newobj = new wxString(psz);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(wxString const & str, size_t nPos, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_12::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_12::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nPos_long;
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  wxString* _newobj = new wxString(str, nPos, nLen);
  BasicVariable::ptr res = WrapClass_wxString::CreateVar(_newobj);
  return res;
}
/* The following types are missing: void, void

//---------------------------------------------------
//  Wrapping of Constructor wxString::wxString(void const * pStart, void const * pEnd)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wxString_13::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'pStart'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'pEnd'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wxString_13::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > pStart_smtptr;
  if (!get_val_smtptr_param<void >(pStart_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* pStart = pStart_smtptr.get();

  boost::shared_ptr<void > pEnd_smtptr;
  if (!get_val_smtptr_param<void >(pEnd_smtptr,_p,_n)) ClassReturnEmptyVar;
  void* pEnd = pEnd_smtptr.get();

  wxString* _newobj = new wxString(pStart, pEnd);
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
    return AMILabType<wxString >::CreateVar( new wxString(*(this->_objectptr->GetObj())));
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
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
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
  return AMILabType<int >::CreateVar(res_int);
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
  if (!get_val_param<long >(uiLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int uiLen = boost::numeric_cast<long unsigned int >(uiLen_long);

  wxString & res =   this->_objectptr->GetObj()->Truncate(uiLen);
  return AMILabType<wxString >::CreateVar(res);
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
  return AMILabType<int >::CreateVar(res_int);
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
  return AMILabType<int >::CreateVar(res_int);
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
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxChar wxString::GetChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxChar res =   this->_objectptr->GetObj()->GetChar(n);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar & wxString::GetWritableChar(size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetWritableChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetWritableChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxChar & res =   this->_objectptr->GetObj()->GetWritableChar(n);
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxString::SetChar(size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_SetChar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_SetChar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  this->_objectptr->GetObj()->SetChar(n, ch);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxChar wxString::Last()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar res =   this->_objectptr->GetObj()->Last();
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

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
  WrapClass_wxString::wrap_Last_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Last_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Last_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar & wxString::Last()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_2::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar & res =   this->_objectptr->GetObj()->Last();
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxString::wx_str()
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

  wxChar const * res =   this->_objectptr->GetObj()->wx_str();
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
//  Wrapping of wxChar const * wxString::GetData()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxChar const * res =   this->_objectptr->GetObj()->GetData();
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
/* The following types are missing: wxWritableCharBuffer

//---------------------------------------------------
//  Wrapping of wxWritableCharBuffer wxString::char_str(wxMBConv const & conv = wxConvLibc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_char_str::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv' (def:wxConvLibc)")
  return_comments="returning a variable of type wxWritableCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_char_str::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMBConv > conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv >(conv_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMBConv const & conv = (conv_smtptr.get()?
    (wxMBConv const &) (*conv_smtptr):
    (wxMBConv const &) wxConvLibc);

  wxWritableCharBuffer res =   this->_objectptr->GetObj()->char_str(conv);
  return AMILabType<wxWritableCharBuffer >::CreateVar(res);
}
*/
/* The following types are missing: wxWritableWCharBuffer

//---------------------------------------------------
//  Wrapping of wxWritableWCharBuffer wxString::wchar_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wchar_str::SetParametersComments()
{
  return_comments="returning a variable of type wxWritableWCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wchar_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWritableWCharBuffer res =   this->_objectptr->GetObj()->wchar_str();
  return AMILabType<wxWritableWCharBuffer >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(char const * ascii)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FromAscii_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ascii'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_FromAscii_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > ascii_string;
  if (!get_val_smtptr_param<std::string >(ascii_string,_p,_n)) ClassReturnEmptyVar;
  char const * ascii = ascii_string->c_str();

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii);
  return AMILabType<wxString >::CreateVar(res);
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
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString wxString::FromAscii(char const ascii)
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

  std::string ascii_string;
  if (!get_val_param<std::string >(ascii_string,_p,_n)) ClassReturnEmptyVar;
  char ascii = ' ';
if (ascii_string.size()>0) ascii = ascii_string[0];

  wxString res =   this->_objectptr->GetObj()->FromAscii(ascii);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::ToAscii()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToAscii::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToAscii::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->ToAscii();
  return AMILabType<wxCharBuffer >::CreateVar(res);
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

  boost::shared_ptr<std::string > utf8_string;
  if (!get_val_smtptr_param<std::string >(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  wxString res =   this->_objectptr->GetObj()->FromUTF8(utf8);
  return AMILabType<wxString >::CreateVar(res);
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

  boost::shared_ptr<std::string > utf8_string;
  if (!get_val_smtptr_param<std::string >(utf8_string,_p,_n)) ClassReturnEmptyVar;
  char const * utf8 = utf8_string->c_str();

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  wxString res =   this->_objectptr->GetObj()->FromUTF8(utf8, len);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::utf8_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_utf8_str::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_utf8_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->utf8_str();
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::ToUTF8()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_ToUTF8::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_ToUTF8::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->ToUTF8();
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

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

  boost::shared_ptr<std::string > data_string;
  if (!get_val_smtptr_param<std::string >(data_string,_p,_n)) ClassReturnEmptyVar;
  char const * data = data_string->c_str();

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  wxString res =   this->_objectptr->GetObj()->From8BitData(data, len);
  return AMILabType<wxString >::CreateVar(res);
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

  boost::shared_ptr<std::string > data_string;
  if (!get_val_smtptr_param<std::string >(data_string,_p,_n)) ClassReturnEmptyVar;
  char const * data = data_string->c_str();

  wxString res =   this->_objectptr->GetObj()->From8BitData(data);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::To8BitData()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_To8BitData::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_To8BitData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->To8BitData();
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCharBuffer const wxString::mb_str(wxMBConv const & conv = wxConvLibc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_mb_str::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'conv' (def:wxConvLibc)")
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_mb_str::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMBConv > conv_smtptr;
  if (!get_val_smtptr_param<wxMBConv >(conv_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxMBConv const & conv = (conv_smtptr.get()?
    (wxMBConv const &) (*conv_smtptr):
    (wxMBConv const &) wxConvLibc);

  wxCharBuffer const res =   this->_objectptr->GetObj()->mb_str(conv);
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

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
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxString::wc_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wc_str_1::SetParametersComments()
{
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wc_str_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxChar const * res =   this->_objectptr->GetObj()->wc_str();
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
  WrapClass_wxString::wrap_wc_str_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_wc_str_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar const * wxString::wc_str(wxMBConv const & param0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_wc_str_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMBConv, "parameter named 'param0'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_wc_str_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMBConv > param0_smtptr;
  if (!get_val_smtptr_param<wxMBConv >(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxMBConv const & param0 = *param0_smtptr;

  wxChar const * res =   this->_objectptr->GetObj()->wc_str(param0);
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
//  Wrapping of wxCharBuffer const wxString::fn_str()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_fn_str::SetParametersComments()
{
  return_comments="returning a variable of type wxCharBuffer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_fn_str::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCharBuffer const res =   this->_objectptr->GetObj()->fn_str();
  return AMILabType<wxCharBuffer >::CreateVar(res);
}

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

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Append(s);
  return AMILabType<wxString >::CreateVar(res);
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
  WrapClass_wxString::wrap_Append_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxChar const * psz)
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

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->Append(psz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxChar ch, size_t count = 1u)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'count' (def:1u)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  long count_long = boost::numeric_cast<long >(1u);;
  if (!get_val_param<long >(count_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int count = boost::numeric_cast<long unsigned int >(count_long);

  wxString & res =   this->_objectptr->GetObj()->Append(ch, count);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Append(wxChar const * psz, size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Append(psz, nLen);
  return AMILabType<wxString >::CreateVar(res);
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

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->Prepend(str);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxChar const * psz)
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

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  int res =   this->_objectptr->GetObj()->Cmp(psz);
  return AMILabType<int >::CreateVar(res);
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
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::Cmp(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Cmp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Cmp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->Cmp(s);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::CmpNoCase(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_CmpNoCase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_CmpNoCase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  int res =   this->_objectptr->GetObj()->CmpNoCase(psz);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::CmpNoCase(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_CmpNoCase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_CmpNoCase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_CmpNoCase_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_CmpNoCase_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::CmpNoCase(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_CmpNoCase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_CmpNoCase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  int res =   this->_objectptr->GetObj()->CmpNoCase(s);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxChar const * psz, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
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

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int >(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(psz, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxString::IsSameAs(wxChar c, bool compareWithCase = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_IsSameAs_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
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

  std::string c_string;
  if (!get_val_param<std::string >(c_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t c = 0;
{
  if (c_string.size()>0) mbstowcs(&c, &c_string[0],1);
}


  int compareWithCase_int = ((true==true)?1:0);;
  if (!get_val_param<int >(compareWithCase_int,_p,_n)) ClassReturnEmptyVar;
  bool compareWithCase = (bool) (compareWithCase_int>0.5);

  bool res =   this->_objectptr->GetObj()->IsSameAs(c, compareWithCase);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Mid(size_t nFirst, size_t nCount = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Mid::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nFirst'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount' (def:wxStringBase::npos)")
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
  if (!get_val_param<long >(nFirst_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nFirst = boost::numeric_cast<long unsigned int >(nFirst_long);

  long nCount_long = boost::numeric_cast<long >(wxStringBase::npos);;
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Mid(nFirst, nCount);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxString::StartsWith(wxChar const * prefix, wxString * rest = 0l)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_StartsWith::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'prefix'")
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

  boost::shared_ptr<std::string > prefix_string;
  if (!get_val_smtptr_param<std::string >(prefix_string,_p,_n)) ClassHelpAndReturn;
  wchar_t prefix[prefix_string->size()+1];
mbstowcs(prefix,prefix_string->c_str(),prefix_string->size()+1);

  boost::shared_ptr<wxString > rest_smtptr;
  if (!get_val_smtptr_param<wxString >(rest_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString* rest = rest_smtptr.get();

  bool res =   this->_objectptr->GetObj()->StartsWith(prefix, rest);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxString::EndsWith(wxChar const * suffix, wxString * rest = 0l)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_EndsWith::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'suffix'")
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

  boost::shared_ptr<std::string > suffix_string;
  if (!get_val_smtptr_param<std::string >(suffix_string,_p,_n)) ClassHelpAndReturn;
  wchar_t suffix[suffix_string->size()+1];
mbstowcs(suffix,suffix_string->c_str(),suffix_string->size()+1);

  boost::shared_ptr<wxString > rest_smtptr;
  if (!get_val_smtptr_param<wxString >(rest_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString* rest = rest_smtptr.get();

  bool res =   this->_objectptr->GetObj()->EndsWith(suffix, rest);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Left(nCount);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  wxString res =   this->_objectptr->GetObj()->Right(nCount);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::BeforeFirst(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_BeforeFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_BeforeFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->BeforeFirst(ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::BeforeLast(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_BeforeLast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_BeforeLast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->BeforeLast(ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::AfterFirst(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_AfterFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_AfterFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->AfterFirst(ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::AfterLast(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_AfterLast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_AfterLast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->AfterLast(ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::Before(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Before::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Before::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->Before(ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxString::After(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_After::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_After::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString res =   this->_objectptr->GetObj()->After(ch);
  return AMILabType<wxString >::CreateVar(res);
}

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
  return AMILabType<wxString >::CreateVar(res);
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
  return AMILabType<wxString >::CreateVar(res);
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
  return AMILabType<wxString >::CreateVar(res);
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
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<int >(bFromRight_int,_p,_n)) ClassHelpAndReturn;
  bool bFromRight = (bool) (bFromRight_int>0.5);

  wxString & res =   this->_objectptr->GetObj()->Trim(bFromRight);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::Pad(size_t nCount, wxChar chPad = 32, bool bFromRight = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Pad::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'chPad' (def:32)")
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
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  std::string chPad_string;
  {
    wchar_t val = 32;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) chPad_string = std::string(1,char_conv);
  };
  if (!get_val_param<std::string >(chPad_string,_p,_n)) ClassHelpAndReturn;
  wchar_t chPad = 0;
{
  if (chPad_string.size()>0) mbstowcs(&chPad, &chPad_string[0],1);
}


  int bFromRight_int = ((true==true)?1:0);;
  if (!get_val_param<int >(bFromRight_int,_p,_n)) ClassHelpAndReturn;
  bool bFromRight = (bool) (bFromRight_int>0.5);

  wxString & res =   this->_objectptr->GetObj()->Pad(nCount, chPad, bFromRight);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxChar ch, bool bFromEnd = false)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
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

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  int bFromEnd_int = ((false==true)?1:0);;
  if (!get_val_param<int >(bFromEnd_int,_p,_n)) ClassReturnEmptyVar;
  bool bFromEnd = (bool) (bFromEnd_int>0.5);

  int res =   this->_objectptr->GetObj()->Find(ch, bFromEnd);
  return AMILabType<int >::CreateVar(res);
}

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
  WrapClass_wxString::wrap_Find_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_Find_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::Find(wxChar const * pszSub)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Find_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszSub'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Find_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > pszSub_string;
  if (!get_val_smtptr_param<std::string >(pszSub_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t pszSub[pszSub_string->size()+1];
mbstowcs(pszSub,pszSub_string->c_str(),pszSub_string->size()+1);

  int res =   this->_objectptr->GetObj()->Find(pszSub);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of size_t wxString::Replace(wxChar const * szOld, wxChar const * szNew, bool bReplaceAll = true)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Replace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'szOld'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'szNew'")
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

  boost::shared_ptr<std::string > szOld_string;
  if (!get_val_smtptr_param<std::string >(szOld_string,_p,_n)) ClassHelpAndReturn;
  wchar_t szOld[szOld_string->size()+1];
mbstowcs(szOld,szOld_string->c_str(),szOld_string->size()+1);

  boost::shared_ptr<std::string > szNew_string;
  if (!get_val_smtptr_param<std::string >(szNew_string,_p,_n)) ClassHelpAndReturn;
  wchar_t szNew[szNew_string->size()+1];
mbstowcs(szNew,szNew_string->c_str(),szNew_string->size()+1);

  int bReplaceAll_int = ((true==true)?1:0);;
  if (!get_val_param<int >(bReplaceAll_int,_p,_n)) ClassHelpAndReturn;
  bool bReplaceAll = (bool) (bReplaceAll_int>0.5);

  size_t res =   this->_objectptr->GetObj()->Replace(szOld, szNew, bReplaceAll);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxString::Matches(wxChar const * szMask)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Matches::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'szMask'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Matches::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > szMask_string;
  if (!get_val_smtptr_param<std::string >(szMask_string,_p,_n)) ClassHelpAndReturn;
  wchar_t szMask[szMask_string->size()+1];
mbstowcs(szMask,szMask_string->c_str(),szMask_string->size()+1);

  bool res =   this->_objectptr->GetObj()->Matches(szMask);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<long > val_long;
  if (!get_val_smtptr_param<long >(val_long,_p,_n)) ClassHelpAndReturn;
  long int val_val = *val_long;
  long int* val = &val_val;

  int base = 10;
  if (!get_val_param<int >(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<long > val_long;
  if (!get_val_smtptr_param<long >(val_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int val_val = boost::numeric_cast<long unsigned int >(*val_long);
  long unsigned int* val = &val_val;

  int base = 10;
  if (!get_val_param<int >(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToULong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<long long int > val_smtptr;
  if (!get_val_smtptr_param<long long int >(val_smtptr,_p,_n)) ClassHelpAndReturn;
  long long int* val = val_smtptr.get();

  int base = 10;
  if (!get_val_param<int >(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToLongLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<long long unsigned int > val_smtptr;
  if (!get_val_smtptr_param<long long unsigned int >(val_smtptr,_p,_n)) ClassHelpAndReturn;
  long long unsigned int* val = val_smtptr.get();

  int base = 10;
  if (!get_val_param<int >(base,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ToULongLong(val, base);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<double > val_smtptr;
  if (!get_val_smtptr_param<double >(val_smtptr,_p,_n)) ClassHelpAndReturn;
  double* val = val_smtptr.get();

  bool res =   this->_objectptr->GetObj()->ToDouble(val);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxString::Printf(wxChar const * pszFormat)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Printf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszFormat'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Printf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > pszFormat_string;
  if (!get_val_smtptr_param<std::string >(pszFormat_string,_p,_n)) ClassHelpAndReturn;
  wchar_t pszFormat[pszFormat_string->size()+1];
mbstowcs(pszFormat,pszFormat_string->c_str(),pszFormat_string->size()+1);

  int res =   this->_objectptr->GetObj()->Printf(pszFormat);
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: __va_list_tag

//---------------------------------------------------
//  Wrapping of int wxString::PrintfV(wxChar const * pszFormat, __va_list_tag * argptr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_PrintfV::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszFormat'")
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

  boost::shared_ptr<std::string > pszFormat_string;
  if (!get_val_smtptr_param<std::string >(pszFormat_string,_p,_n)) ClassHelpAndReturn;
  wchar_t pszFormat[pszFormat_string->size()+1];
mbstowcs(pszFormat,pszFormat_string->c_str(),pszFormat_string->size()+1);

  boost::shared_ptr<__va_list_tag > argptr_smtptr;
  if (!get_val_smtptr_param<__va_list_tag >(argptr_smtptr,_p,_n)) ClassHelpAndReturn;
  __va_list_tag* argptr = argptr_smtptr.get();

  int res =   this->_objectptr->GetObj()->PrintfV(pszFormat, argptr);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxString::Format(wxChar const * pszFormat)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Format::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszFormat'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Format::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > pszFormat_string;
  if (!get_val_smtptr_param<std::string >(pszFormat_string,_p,_n)) ClassHelpAndReturn;
  wchar_t pszFormat[pszFormat_string->size()+1];
mbstowcs(pszFormat,pszFormat_string->c_str(),pszFormat_string->size()+1);

  wxString res =   this->_objectptr->GetObj()->Format(pszFormat);
  return AMILabType<wxString >::CreateVar(res);
}
/* The following types are missing: __va_list_tag

//---------------------------------------------------
//  Wrapping of wxString wxString::FormatV(wxChar const * pszFormat, __va_list_tag * argptr)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_FormatV::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszFormat'")
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

  boost::shared_ptr<std::string > pszFormat_string;
  if (!get_val_smtptr_param<std::string >(pszFormat_string,_p,_n)) ClassHelpAndReturn;
  wchar_t pszFormat[pszFormat_string->size()+1];
mbstowcs(pszFormat,pszFormat_string->c_str(),pszFormat_string->size()+1);

  boost::shared_ptr<__va_list_tag > argptr_smtptr;
  if (!get_val_smtptr_param<__va_list_tag >(argptr_smtptr,_p,_n)) ClassHelpAndReturn;
  __va_list_tag* argptr = argptr_smtptr.get();

  wxString res =   this->_objectptr->GetObj()->FormatV(pszFormat, argptr);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  bool res =   this->_objectptr->GetObj()->Alloc(nLen);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxChar * wxString::GetWriteBuf(size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_GetWriteBuf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_GetWriteBuf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  wxChar * res =   this->_objectptr->GetObj()->GetWriteBuf(nLen);
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
//  Wrapping of void wxString::UngetWriteBuf()
//---------------------------------------------------
void WrapClass_wxString::
    wrap_UngetWriteBuf_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_UngetWriteBuf_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->UngetWriteBuf();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxString::UngetWriteBuf(...)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_UngetWriteBuf::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_UngetWriteBuf::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxString::wrap_UngetWriteBuf_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_UngetWriteBuf_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxString::UngetWriteBuf(size_t nLen)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_UngetWriteBuf_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_UngetWriteBuf_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  this->_objectptr->GetObj()->UngetWriteBuf(nLen);
  return BasicVariable::ptr();
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
  if (!get_val_param<long >(from_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int from = boost::numeric_cast<long unsigned int >(from_long);

  long to_long;
  if (!get_val_param<long >(to_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int to = boost::numeric_cast<long unsigned int >(to_long);

  wxString res =   this->_objectptr->GetObj()->SubString(from, to);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::sprintf(wxChar const * pszFormat)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_sprintf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'pszFormat'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_sprintf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > pszFormat_string;
  if (!get_val_smtptr_param<std::string >(pszFormat_string,_p,_n)) ClassHelpAndReturn;
  wchar_t pszFormat[pszFormat_string->size()+1];
mbstowcs(pszFormat,pszFormat_string->c_str(),pszFormat_string->size()+1);

  int res =   this->_objectptr->GetObj()->sprintf(pszFormat);
  return AMILabType<int >::CreateVar(res);
}

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
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of int wxString::Freq(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Freq::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Freq::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassHelpAndReturn;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  int res =   this->_objectptr->GetObj()->Freq(ch);
  return AMILabType<int >::CreateVar(res);
}

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

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  size_t res =   this->_objectptr->GetObj()->Index(psz);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
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
  WrapClass_wxString::wrap_Index_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of size_t wxString::Index(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Index_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Index_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  size_t res =   this->_objectptr->GetObj()->Index(ch);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

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
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  wxString & res =   this->_objectptr->GetObj()->Remove(pos);
  return AMILabType<wxString >::CreateVar(res);
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

  long n_long = boost::numeric_cast<long >(1);;
  if (!get_val_param<long >(n_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->RemoveLast(n);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  wxString & res =   this->_objectptr->GetObj()->Remove(nStart, nLen);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::First(wxChar const ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  int res =   this->_objectptr->GetObj()->First(ch);
  return AMILabType<int >::CreateVar(res);
}

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
  WrapClass_wxString::wrap_First_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_First_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_First_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxString::First(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  int res =   this->_objectptr->GetObj()->First(psz);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::First(wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_First_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_First_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  int res =   this->_objectptr->GetObj()->First(str);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxString::Last(wxChar const ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_Last_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_Last_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  int res =   this->_objectptr->GetObj()->Last(ch);
  return AMILabType<int >::CreateVar(res);
}

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

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  bool res =   this->_objectptr->GetObj()->Contains(str);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
  return AMILabType<int >::CreateVar(res_int);
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

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(str, pos, n);
  return AMILabType<wxString >::CreateVar(res);
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

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->append(str);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxChar const * sz)
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

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->append(sz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxChar const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->append(sz, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()->append(n, ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::append(wxChar const * first, wxChar const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_append_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_append_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->append(first, last);
  return AMILabType<wxString >::CreateVar(res);
}

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

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->assign(str);
  return AMILabType<wxString >::CreateVar(res);
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
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxString const & str, size_t pos, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long pos_long;
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->assign(str, pos, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxChar const * sz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->assign(sz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxChar const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->assign(sz, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()->assign(n, ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::assign(wxChar const * first, wxChar const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_assign_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_assign_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->assign(first, last);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, str);
  return AMILabType<wxString >::CreateVar(res);
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
  WrapClass_wxString::wrap_insert_7 m7(this->_objectptr);
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_insert_8 m8(this->_objectptr);
  res = m8.CallMember(_p);
  if (!m8.Get_arg_failure()) return res;
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
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart_long;
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, str, nStart, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wxChar const * sz)
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
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, wxChar const * sz, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  long nPos_long;
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->insert(nPos, sz, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::insert(size_t nPos, size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nPos'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
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
  if (!get_val_param<long >(nPos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nPos = boost::numeric_cast<long unsigned int >(nPos_long);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()->insert(nPos, n, ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxChar * wxString::insert(wxChar * it, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > it_string;
  if (!get_val_smtptr_param<std::string >(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
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
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void wxString::insert(wxChar * it, wxChar const * first, wxChar const * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > it_string;
  if (!get_val_smtptr_param<std::string >(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  this->_objectptr->GetObj()->insert(it, first, last);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxString::insert(wxChar * it, size_t n, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_insert_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'it'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_insert_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > it_string;
  if (!get_val_smtptr_param<std::string >(it_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t it[it_string->size()+1];
mbstowcs(it,it_string->c_str(),it_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  this->_objectptr->GetObj()->insert(it, n, ch);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::erase(size_t pos = 0, size_t n = wxStringBase::npos)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'pos' (def:0)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n' (def:wxStringBase::npos)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  long pos_long = boost::numeric_cast<long >(0);;
  if (!get_val_param<long >(pos_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int pos = boost::numeric_cast<long unsigned int >(pos_long);

  long n_long = boost::numeric_cast<long >(wxStringBase::npos);;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->erase(pos, n);
  return AMILabType<wxString >::CreateVar(res);
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
  WrapClass_wxString::wrap_erase_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_erase_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar * wxString::erase(wxChar * first, wxChar * last)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
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
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar * wxString::erase(wxChar * first)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_erase_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_erase_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
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
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxChar const * sz)
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
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz);
  return AMILabType<wxString >::CreateVar(res);
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
  WrapClass_wxString::wrap_replace_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
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
  WrapClass_wxString::wrap_replace_9 m9(this->_objectptr);
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxString::wrap_replace_10 m10(this->_objectptr);
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
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
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, size_t nCount, wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  long nCount_long;
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, nCount, ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxString const & str, size_t nStart2, size_t nLen2)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_4::SetParametersComments()
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
    wrap_replace_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & str = *str_smtptr;

  long nStart2_long;
  if (!get_val_param<long >(nStart2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart2 = boost::numeric_cast<long unsigned int >(nStart2_long);

  long nLen2_long;
  if (!get_val_param<long >(nLen2_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen2 = boost::numeric_cast<long unsigned int >(nLen2_long);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, str, nStart2, nLen2);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(size_t nStart, size_t nLen, wxChar const * sz, size_t nCount)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nStart'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nLen'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'sz'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'nCount'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  long nStart_long;
  if (!get_val_param<long >(nStart_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nStart = boost::numeric_cast<long unsigned int >(nStart_long);

  long nLen_long;
  if (!get_val_param<long >(nLen_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nLen = boost::numeric_cast<long unsigned int >(nLen_long);

  boost::shared_ptr<std::string > sz_string;
  if (!get_val_smtptr_param<std::string >(sz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t sz[sz_string->size()+1];
mbstowcs(sz,sz_string->c_str(),sz_string->size()+1);

  long nCount_long;
  if (!get_val_param<long >(nCount_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int nCount = boost::numeric_cast<long unsigned int >(nCount_long);

  wxString & res =   this->_objectptr->GetObj()->replace(nStart, nLen, sz, nCount);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * s, size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 's'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string > s_string;
  if (!get_val_smtptr_param<std::string >(s_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t s[s_string->size()+1];
mbstowcs(s,s_string->c_str(),s_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s, n);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(wxChar * first, wxChar * last, wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, s);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(wxChar * first, wxChar * last, size_t n, wxChar c)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'c'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  std::string c_string;
  if (!get_val_param<std::string >(c_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t c = 0;
{
  if (c_string.size()>0) mbstowcs(&c, &c_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()->replace(first, last, n, c);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::replace(wxChar * first, wxChar * last, wxChar const * first1, wxChar const * last1)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_replace_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'first1'")
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'last1'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_replace_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > first_string;
  if (!get_val_smtptr_param<std::string >(first_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first[first_string->size()+1];
mbstowcs(first,first_string->c_str(),first_string->size()+1);

  boost::shared_ptr<std::string > last_string;
  if (!get_val_smtptr_param<std::string >(last_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last[last_string->size()+1];
mbstowcs(last,last_string->c_str(),last_string->size()+1);

  boost::shared_ptr<std::string > first1_string;
  if (!get_val_smtptr_param<std::string >(first1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t first1[first1_string->size()+1];
mbstowcs(first1,first1_string->c_str(),first1_string->size()+1);

  boost::shared_ptr<std::string > last1_string;
  if (!get_val_smtptr_param<std::string >(last1_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t last1[last1_string->size()+1];
mbstowcs(last1,last1_string->c_str(),last1_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()->replace(first, last, first1, last1);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxString const & param0)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param0'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > param0_smtptr;
  if (!get_val_smtptr_param<wxString >(param0_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & param0 = *param0_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxString >::CreateVar(res);
}
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
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of wxChar & wxString::[](int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n)) ClassReturnEmptyVar;

  wxChar & res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

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
  WrapClass_wxString::wrap___at___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___at___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___at___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxChar & wxString::[](size_t n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int n = boost::numeric_cast<long unsigned int >(n_long);

  wxChar & res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of wxChar & wxString::[](unsigned int n)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___at___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'n'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___at___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long n_long;
  if (!get_val_param<long >(n_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int n = boost::numeric_cast<unsigned int >(n_long);

  wxChar & res =   (*this->_objectptr->GetObj()) [ (n)];
  std::string res_string;
  {
    wchar_t val = res;
    char char_conv;
    size_t conv_res = wcstombs(&char_conv,&val,1);
    if (conv_res>0) res_string = std::string(1,char_conv);
  }
  return AMILabType<std::string >::CreateVar(res_string);
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
  WrapClass_wxString::wrap___assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxString::wrap___assign___5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxStringBase const & stringSrc)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStringBase, "parameter named 'stringSrc'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStringBase > stringSrc_smtptr;
  if (!get_val_smtptr_param<wxStringBase >(stringSrc_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxStringBase const & stringSrc = *stringSrc_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (stringSrc);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   (*this->_objectptr->GetObj()) = (ch);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxString & res =   (*this->_objectptr->GetObj()) = (psz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::=(wxWCharBuffer const & psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___assign___5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___assign___5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > psz_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(psz_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWCharBuffer const & psz = *psz_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) = (psz);
  return AMILabType<wxString >::CreateVar(res);
}
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

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(s);
  return AMILabType<wxString >::CreateVar(res);
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
  ClassHelpAndReturn;
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxChar const * psz)
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

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxString & res =   this->_objectptr->GetObj()-><<(psz);
  return AMILabType<wxString >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxChar ch)
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
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   this->_objectptr->GetObj()-><<(ch);
  return AMILabType<wxString >::CreateVar(res);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of wxString & wxString::<<(wxWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > s_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWCharBuffer const & s = *s_smtptr;

  wxString & res =   this->_objectptr->GetObj()-><<(s);
  return AMILabType<wxString >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of void wxString::+=(wxWCharBuffer const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWCharBuffer, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWCharBuffer > s_smtptr;
  if (!get_val_smtptr_param<wxWCharBuffer >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWCharBuffer const & s = *s_smtptr;

  (*this->_objectptr->GetObj()) += (s);
  return BasicVariable::ptr();
}
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
  if (!get_val_param<int >(i,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(i);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(ui_long,_p,_n)) ClassReturnEmptyVar;
  unsigned int ui = boost::numeric_cast<unsigned int >(ui_long);

  wxString & res =   this->_objectptr->GetObj()-><<(ui);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(l_long,_p,_n)) ClassReturnEmptyVar;
  long int l = l_long;

  wxString & res =   this->_objectptr->GetObj()-><<(l);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(ul_long,_p,_n)) ClassReturnEmptyVar;
  long unsigned int ul = boost::numeric_cast<long unsigned int >(ul_long);

  wxString & res =   this->_objectptr->GetObj()-><<(ul);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long long int >(ll,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ll);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long long unsigned int >(ull,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(ull);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<float >(f,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(f);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<double >(d,_p,_n)) ClassReturnEmptyVar;

  wxString & res =   this->_objectptr->GetObj()-><<(d);
  return AMILabType<wxString >::CreateVar(res);
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
  if (!get_val_param<long >(start_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int start = boost::numeric_cast<long unsigned int >(start_long);

  long len_long;
  if (!get_val_param<long >(len_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int len = boost::numeric_cast<long unsigned int >(len_long);

  wxString res =   this->_objectptr->GetObj()->()(start, len);
  return AMILabType<wxString >::CreateVar(res);
}
*/

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
  WrapClass_wxString::wrap___add_assign___4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxString const & s)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 's'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > s_smtptr;
  if (!get_val_smtptr_param<wxString >(s_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & s = *s_smtptr;

  wxString & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxChar const * psz)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'psz'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > psz_string;
  if (!get_val_smtptr_param<std::string >(psz_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t psz[psz_string->size()+1];
mbstowcs(psz,psz_string->c_str(),psz_string->size()+1);

  wxString & res =   (*this->_objectptr->GetObj()) += (psz);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString & wxString::+=(wxChar ch)
//---------------------------------------------------
void WrapClass_wxString::
    wrap___add_assign___4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'ch'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
    wrap___add_assign___4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  std::string ch_string;
  if (!get_val_param<std::string >(ch_string,_p,_n)) ClassReturnEmptyVar;
  wchar_t ch = 0;
{
  if (ch_string.size()>0) mbstowcs(&ch, &ch_string[0],1);
}


  wxString & res =   (*this->_objectptr->GetObj()) += (ch);
  return AMILabType<wxString >::CreateVar(res);
}

