/**
 * C++ Interface: wrap_wxFont
 *
 * Description: wrapping wxFont
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxFont.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxFont.h"
#include "wrap_wxString.h"
#include "wrap_wxClassInfo.h"
#include "wrap_wxObject.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFont>::CreateVar( ParamList* p)
{
  WrapClass_wxFont::wrap_wxFont construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFont);

//
// static member for creating a variable from a pointer to wxFont
//
Variable<AMIObject>::ptr WrapClass_wxFont::CreateVar( wxFont* sp)
{
  boost::shared_ptr<wxFont> di_ptr(
    sp,
    wxwindow_nodeleter<wxFont>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFont>::CreateVar(
      new WrapClass_wxFont(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxFont const & param0)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxFont* param0_ptr;
  if (!get_val_ptr_param<wxFont>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxFont& param0 = *param0_ptr;
  wxFont* _newobj = new wxFont(param0);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont1::CallMember( ParamList* _p)
{
  wxFont* _newobj = new wxFont();
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxString const & fontname)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont2::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* fontname_ptr;
  if (!get_val_ptr_param<wxString>(fontname_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& fontname = *fontname_ptr;
  wxFont* _newobj = new wxFont(fontname);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxNativeFontInfo const & info)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNativeFontInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont3::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxNativeFontInfo* info_ptr;
  if (!get_val_ptr_param<wxNativeFontInfo>(info_ptr,_p,_n)) ClassHelpAndReturn;
  wxNativeFontInfo& info = *info_ptr;
  wxFont* _newobj = new wxFont(info);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(int size, int family, int style, int weight, bool underlined, wxString const & face, wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'underlined'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face'")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont4::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int size;
  if (!get_val_param<int>(size,_p,_n)) ClassHelpAndReturn;
  int family;
  if (!get_val_param<int>(family,_p,_n)) ClassHelpAndReturn;
  int style;
  if (!get_val_param<int>(style,_p,_n)) ClassHelpAndReturn;
  int weight;
  if (!get_val_param<int>(weight,_p,_n)) ClassHelpAndReturn;
  int underlined_int;
  if (!get_val_param<int>(underlined_int,_p,_n)) ClassHelpAndReturn;
  bool underlined = (bool) (underlined_int>0.5);
  wxString* face_ptr;
  if (!get_val_ptr_param<wxString>(face_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& face = *face_ptr;
  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding>(encoding,_p,_n)) ClassHelpAndReturn;
  wxFont* _newobj = new wxFont(size, family, style, weight, underlined, face, encoding);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
*/
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(int size, int family, int style, int weight, bool underlined, wxString const & face, wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'underlined'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face'")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int size;
  if (!get_val_param<int>(size,_p,_n)) ClassHelpAndReturn;
  int family;
  if (!get_val_param<int>(family,_p,_n)) ClassHelpAndReturn;
  int style;
  if (!get_val_param<int>(style,_p,_n)) ClassHelpAndReturn;
  int weight;
  if (!get_val_param<int>(weight,_p,_n)) ClassHelpAndReturn;
  int underlined_int;
  if (!get_val_param<int>(underlined_int,_p,_n)) ClassHelpAndReturn;
  bool underlined = (bool) (underlined_int>0.5);
  wxString* face_ptr;
  if (!get_val_ptr_param<wxString>(face_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& face = *face_ptr;
  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding>(encoding,_p,_n)) ClassHelpAndReturn;
  bool res =   this->_objectptr->GetObj()->Create(size, family, style, weight, underlined, face, encoding);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(wxString const & fontname)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* fontname_ptr;
  if (!get_val_ptr_param<wxString>(fontname_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& fontname = *fontname_ptr;
  bool res =   this->_objectptr->GetObj()->Create(fontname);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxFont::GetPointSize()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetPointSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetPointSize::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetPointSize();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxFont::GetFamily()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetFamily::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetFamily::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetFamily();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxFont::GetStyle()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetStyle();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxFont::GetWeight()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetWeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetWeight::CallMember( ParamList* _p)
{
  int res =   this->_objectptr->GetObj()->GetWeight();
  return AMILabType<int>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFont::GetFaceName()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetFaceName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetFaceName::CallMember( ParamList* _p)
{
  wxString res =   this->_objectptr->GetObj()->GetFaceName();
  return AMILabType<wxString>::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFont::GetUnderlined()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetUnderlined::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetUnderlined::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->GetUnderlined();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFontEncoding wxFont::GetEncoding()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetEncoding::SetParametersComments()
{
  return_comments="returning a variable of type wxFontEncoding";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetEncoding::CallMember( ParamList* _p)
{
  wxFontEncoding res =   this->_objectptr->GetObj()->GetEncoding();
  return AMILabType<wxFontEncoding>::CreateVar(res);
}
*/
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of wxNativeFontInfo const * wxFont::GetNativeFontInfo()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetNativeFontInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxNativeFontInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetNativeFontInfo::CallMember( ParamList* _p)
{
  wxNativeFontInfo const * res =   this->_objectptr->GetObj()->GetNativeFontInfo();
  return AMILabType<wxNativeFontInfo>::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFont::IsFixedWidth()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_IsFixedWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_IsFixedWidth::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->IsFixedWidth();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetPointSize(int pointSize)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetPointSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pointSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetPointSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int pointSize;
  if (!get_val_param<int>(pointSize,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetPointSize(pointSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetFamily(int family)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetFamily::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetFamily::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int family;
  if (!get_val_param<int>(family,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetFamily(family);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetStyle(int style)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int style;
  if (!get_val_param<int>(style,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetStyle(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetWeight(int weight)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetWeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetWeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int weight;
  if (!get_val_param<int>(weight,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetWeight(weight);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFont::SetFaceName(wxString const & faceName)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetFaceName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'faceName'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetFaceName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxString* faceName_ptr;
  if (!get_val_ptr_param<wxString>(faceName_ptr,_p,_n)) ClassHelpAndReturn;
  wxString& faceName = *faceName_ptr;
  bool res =   this->_objectptr->GetObj()->SetFaceName(faceName);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetUnderlined(bool underlined)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetUnderlined::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'underlined'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetUnderlined::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int underlined_int;
  if (!get_val_param<int>(underlined_int,_p,_n)) ClassHelpAndReturn;
  bool underlined = (bool) (underlined_int>0.5);
  this->_objectptr->GetObj()->SetUnderlined(underlined);
  return BasicVariable::ptr();
}
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of void wxFont::SetEncoding(wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetEncoding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetEncoding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding>(encoding,_p,_n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetEncoding(encoding);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxFont::SetNoAntiAliasing(bool no)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetNoAntiAliasing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'no'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetNoAntiAliasing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  int no_int;
  if (!get_val_param<int>(no_int,_p,_n)) ClassHelpAndReturn;
  bool no = (bool) (no_int>0.5);
  this->_objectptr->GetObj()->SetNoAntiAliasing(no);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFont::GetNoAntiAliasing()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetNoAntiAliasing::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetNoAntiAliasing::CallMember( ParamList* _p)
{
  bool res =   this->_objectptr->GetObj()->GetNoAntiAliasing();
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxFont::Unshare()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Unshare::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Unshare::CallMember( ParamList* _p)
{
  this->_objectptr->GetObj()->Unshare();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFont::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxObject * wxFont::wxCreateObject()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxCreateObject::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxCreateObject::CallMember( ParamList* _p)
{
  wxObject * res =   this->_objectptr->GetObj()->wxCreateObject();
  BasicVariable::ptr res_var = WrapClass_wxObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxFont & wxFont::=(wxFont const & param0)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'param0'")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxFont* param0_ptr;
  if (!get_val_ptr_param<wxFont>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxFont& param0 = *param0_ptr;
  wxFont & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxFont>::CreateVar(res);
}

