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


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxFont);
AMI_DEFINE_VARFROMSMTPTR(wxFont);


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
    wrap_wxFont1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxFont> param0_smtptr;
  if (!get_val_smtptr_param<wxFont>(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxFont& param0 = *param0_smtptr;
  wxFont* _newobj = new wxFont(param0);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxFont::wxFont(...)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFont::wrap_wxFont1 m1;
  res = m1.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxFont::wrap_wxFont2 m2;
  res = m2.CallMember(_p);
  if (res.get()) return res;
  WrapClass_wxFont::wrap_wxFont3 m3;
  res = m3.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;
  wxFont* _newobj = new wxFont();
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxString const & fontname)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxString> fontname_smtptr;
  if (!get_val_smtptr_param<wxString>(fontname_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString& fontname = *fontname_smtptr;
  wxFont* _newobj = new wxFont(fontname);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxNativeFontInfo const & info)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNativeFontInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxNativeFontInfo> info_smtptr;
  if (!get_val_smtptr_param<wxNativeFontInfo>(info_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxNativeFontInfo& info = *info_smtptr;
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
    wrap_wxFont5::SetParametersComments()
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
    wrap_wxFont5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;
  int size;
  if (!get_val_param<int>(size,_p,_n)) ClassReturnEmptyVar;
  int family;
  if (!get_val_param<int>(family,_p,_n)) ClassReturnEmptyVar;
  int style;
  if (!get_val_param<int>(style,_p,_n)) ClassReturnEmptyVar;
  int weight;
  if (!get_val_param<int>(weight,_p,_n)) ClassReturnEmptyVar;
  int underlined_int;
  if (!get_val_param<int>(underlined_int,_p,_n)) ClassReturnEmptyVar;
  bool underlined = (bool) (underlined_int>0.5);
  boost::shared_ptr<wxString> face_smtptr;
  if (!get_val_smtptr_param<wxString>(face_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString& face = *face_smtptr;
  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding>(encoding,_p,_n)) ClassReturnEmptyVar;
  wxFont* _newobj = new wxFont(size, family, style, weight, underlined, face, encoding);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxFont.
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_copy::SetParametersComments()
{
  return_comments="A copy of the wxFont object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_copy::CallMember( ParamList* _p)
{
    return AMILabType<wxFont>::CreateVar( new wxFont(*(this->_objectptr->GetObj())));
}
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(int size, int family, int style, int weight, bool underlined, wxString const & face, wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create1::SetParametersComments()
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
    wrap_Create1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;
  int size;
  if (!get_val_param<int>(size,_p,_n)) ClassReturnEmptyVar;
  int family;
  if (!get_val_param<int>(family,_p,_n)) ClassReturnEmptyVar;
  int style;
  if (!get_val_param<int>(style,_p,_n)) ClassReturnEmptyVar;
  int weight;
  if (!get_val_param<int>(weight,_p,_n)) ClassReturnEmptyVar;
  int underlined_int;
  if (!get_val_param<int>(underlined_int,_p,_n)) ClassReturnEmptyVar;
  bool underlined = (bool) (underlined_int>0.5);
  boost::shared_ptr<wxString> face_smtptr;
  if (!get_val_smtptr_param<wxString>(face_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString& face = *face_smtptr;
  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding>(encoding,_p,_n)) ClassReturnEmptyVar;
  bool res =   this->_objectptr->GetObj()->Create(size, family, style, weight, underlined, face, encoding);
  int  res_int = ((res==true)?1:0);
  return AMILabType<int>::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFont::Create(...)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFont::wrap_Create2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (res.get()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(wxString const & fontname)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;
  boost::shared_ptr<wxString> fontname_smtptr;
  if (!get_val_smtptr_param<wxString>(fontname_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString& fontname = *fontname_smtptr;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxString> faceName_smtptr;
  if (!get_val_smtptr_param<wxString>(faceName_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString& faceName = *faceName_smtptr;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
//  this->_objectptr->GetObj()->Unshare();
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
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
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;
  boost::shared_ptr<wxFont> param0_smtptr;
  if (!get_val_smtptr_param<wxFont>(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxFont& param0 = *param0_smtptr;
  wxFont & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxFont>::CreateVar(res);
}

