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

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxFont.h"

// get all the required includes
// #include "..."
#ifndef wxFont_declared
  #define wxFont_declared
  AMI_DECLARE_TYPE(wxFont)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
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


//----------------------------------------------------------------------
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

//----------------------------------------------------------------------
void WrapClass_wxFont::AddMethods(WrapClass<wxFont>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Create_1( this_ptr);
  AddVar_Create( this_ptr);
  AddVar_Create_2( this_ptr);
  AddVar_GetPointSize( this_ptr);
  AddVar_GetFamily( this_ptr);
  AddVar_GetStyle( this_ptr);
  AddVar_GetWeight( this_ptr);
  AddVar_GetFaceName( this_ptr);
  AddVar_GetUnderlined( this_ptr);
  AddVar_GetEncoding( this_ptr);
/* The following types are missing: wxNativeFontInfo
  AddVar_GetNativeFontInfo( this_ptr);
*/
  AddVar_IsFixedWidth( this_ptr);
  AddVar_SetPointSize( this_ptr);
  AddVar_SetFamily( this_ptr);
  AddVar_SetStyle( this_ptr);
  AddVar_SetWeight( this_ptr);
  AddVar_SetFaceName( this_ptr);
  AddVar_SetUnderlined( this_ptr);
  AddVar_SetEncoding( this_ptr);
  AddVar_SetNoAntiAliasing( this_ptr);
  AddVar_GetNoAntiAliasing( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxFontBase
  boost::shared_ptr<wxFontBase > parent_wxFontBase(  boost::dynamic_pointer_cast<wxFontBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxFontBase = AMILabType<wxFontBase >::CreateVarFromSmtPtr(parent_wxFontBase);
  context->AddVar("wxFontBase",var_wxFontBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxFontBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxFontBase);
  context->AddDefault(obj_wxFontBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFont_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFont");
    WrapClass_wxFont::AddVar_wxFont_1(amiobject->GetContext());
  WrapClass_wxFont::AddVar_wxFont(amiobject->GetContext());
  WrapClass_wxFont::AddVar_wxFont_2(amiobject->GetContext());
  WrapClass_wxFont::AddVar_wxFont_3(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxFont::AddVar_wxFont_4(amiobject->GetContext());
  */
  WrapClass_wxFont::AddVar_wxFont_5(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxFont const & param0)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxFont > param0_smtptr;
  if (!get_val_smtptr_param<wxFont >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxFont const & param0 = *param0_smtptr;

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
  WrapClass_wxFont::wrap_wxFont_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFont::wrap_wxFont_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxFont::wrap_wxFont_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxFont::wrap_wxFont_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont_2::CallMember( ParamList* _p)
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
    wrap_wxFont_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fontname_smtptr;
  if (!get_val_smtptr_param<wxString >(fontname_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fontname = *fontname_smtptr;

  wxFont* _newobj = new wxFont(fontname);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(wxNativeFontInfo const & info)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNativeFontInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxNativeFontInfo > info_smtptr;
  if (!get_val_smtptr_param<wxNativeFontInfo >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxNativeFontInfo const & info = *info_smtptr;

  wxFont* _newobj = new wxFont(info);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxFont::wxFont(int size, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_wxFont_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'underlined' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_wxFont_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,true)) ClassReturnEmptyVar;

  int family;
  if (!get_val_param<int >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int style;
  if (!get_val_param<int >(style,_p,_n,true,true)) ClassReturnEmptyVar;

  int weight;
  if (!get_val_param<int >(weight,_p,_n,true,true)) ClassReturnEmptyVar;

  bool underlined = false;
  if (!get_val_param<bool >(underlined,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  int encoding_int = (int) wxFONTENCODING_DEFAULT;;
  if (!get_val_param<int >(encoding_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxFontEncoding encoding = (wxFontEncoding) encoding_int;

  wxFont* _newobj = new wxFont(size, family, style, weight, underlined, face, encoding);
  BasicVariable::ptr res = WrapClass_wxFont::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxFont.
//---------------------------------------------------
void WrapClass_wxFont::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxFont object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxFont >::CreateVar( new wxFont(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(int size, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'underlined' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int size;
  if (!get_val_param<int >(size,_p,_n,true,true)) ClassReturnEmptyVar;

  int family;
  if (!get_val_param<int >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int style;
  if (!get_val_param<int >(style,_p,_n,true,true)) ClassReturnEmptyVar;

  int weight;
  if (!get_val_param<int >(weight,_p,_n,true,true)) ClassReturnEmptyVar;

  bool underlined = false;
  if (!get_val_param<bool >(underlined,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  int encoding_int = (int) wxFONTENCODING_DEFAULT;;
  if (!get_val_param<int >(encoding_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxFontEncoding encoding = (wxFontEncoding) encoding_int;

  bool res =   this->_objectptr->GetObj()->Create(size, family, style, weight, underlined, face, encoding);
  return AMILabType<bool >::CreateVar(res);
}

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
  WrapClass_wxFont::wrap_Create_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxFont::wrap_Create_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxFont::Create(wxString const & fontname)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_Create_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fontname'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_Create_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > fontname_smtptr;
  if (!get_val_smtptr_param<wxString >(fontname_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & fontname = *fontname_smtptr;

  bool res =   this->_objectptr->GetObj()->Create(fontname);
  return AMILabType<bool >::CreateVar(res);
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
  return AMILabType<int >::CreateVar(res);
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
  return AMILabType<int >::CreateVar(res);
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
  return AMILabType<int >::CreateVar(res);
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
  return AMILabType<int >::CreateVar(res);
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
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFont::GetUnderlined()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetUnderlined::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetUnderlined::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetUnderlined();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxFontEncoding wxFont::GetEncoding()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetEncoding::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetEncoding::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFontEncoding res =   this->_objectptr->GetObj()->GetEncoding();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}
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
  return AMILabType<wxNativeFontInfo >::CreateVar(const_cast<wxNativeFontInfo *>(res),true);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFont::IsFixedWidth()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_IsFixedWidth::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_IsFixedWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFixedWidth();
  return AMILabType<bool >::CreateVar(res);
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
  if (!get_val_param<int >(pointSize,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (!get_val_param<int >(family,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (!get_val_param<int >(style,_p,_n,true,false)) ClassHelpAndReturn;

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
  if (!get_val_param<int >(weight,_p,_n,true,false)) ClassHelpAndReturn;

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
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetFaceName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > faceName_smtptr;
  if (!get_val_smtptr_param<wxString >(faceName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & faceName = *faceName_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFaceName(faceName);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetUnderlined(bool underlined)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetUnderlined::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'underlined'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetUnderlined::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool underlined;
  if (!get_val_param<bool >(underlined,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetUnderlined(underlined);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetEncoding(wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetEncoding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'encoding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetEncoding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int encoding_int;
  if (!get_val_param<int >(encoding_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxFontEncoding encoding = (wxFontEncoding) encoding_int;

  this->_objectptr->GetObj()->SetEncoding(encoding);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFont::SetNoAntiAliasing(bool no = true)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_SetNoAntiAliasing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'no' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_SetNoAntiAliasing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool no = true;
  if (!get_val_param<bool >(no,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetNoAntiAliasing(no);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFont::GetNoAntiAliasing()
//---------------------------------------------------
void WrapClass_wxFont::
    wrap_GetNoAntiAliasing::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap_GetNoAntiAliasing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetNoAntiAliasing();
  return AMILabType<bool >::CreateVar(res);
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
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxFont & wxFont::operator =(wxFont const & param0)
//---------------------------------------------------
void WrapClass_wxFont::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'param0'")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFont::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > param0_smtptr;
  if (!get_val_smtptr_param<wxFont >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & param0 = *param0_smtptr;

  wxFont & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxFont >::CreateVar(res);
}

