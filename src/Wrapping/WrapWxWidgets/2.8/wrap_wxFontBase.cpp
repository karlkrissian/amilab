/**
 * C++ Interface: wrap_wxFontBase
 *
 * Description: wrapping wxFontBase
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
#include "wrap_wxFont.h"
#include "wrap_wxString.h"
#include "wrap_wxSize.h"
#include "wrap_wxFontBase.h"


#include "wrap_wxFontBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFontBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxFontBase);
AMI_DEFINE_VARFROMSMTPTR(wxFontBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFontBase
//
Variable<AMIObject>::ptr WrapClass_wxFontBase::CreateVar( wxFontBase* sp)
{
  boost::shared_ptr<wxFontBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxFontBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFontBase>::CreateVar(
      new WrapClass_wxFontBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFontBase::AddMethods(WrapClass<wxFontBase>::ptr this_ptr )
{
  
      // Add members from wxGDIObject
      WrapClass_wxGDIObject::ptr parent_wxGDIObject(        boost::dynamic_pointer_cast<WrapClass_wxGDIObject >(this_ptr));
      parent_wxGDIObject->AddMethods(parent_wxGDIObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_GetPixelSize( this_ptr);
      AddVar_IsUsingSizeInPixels( this_ptr);
      AddVar_IsFixedWidth( this_ptr);
      AddVar_GetNativeFontInfoDesc( this_ptr);
      AddVar_GetNativeFontInfoUserDesc( this_ptr);
      AddVar_SetPixelSize( this_ptr);
      AddVar_SetFaceName( this_ptr);
/* The following types are missing: wxNativeFontInfo
      AddVar_SetNativeFontInfo_1( this_ptr);
*/
      AddVar_SetNativeFontInfo( this_ptr);
      AddVar_SetNativeFontInfo_2( this_ptr);
      AddVar_SetNativeFontInfoUserDesc( this_ptr);
      AddVar_GetFamilyString( this_ptr);
      AddVar_GetStyleString( this_ptr);
      AddVar_GetWeightString( this_ptr);
      AddVar_SetNoAntiAliasing( this_ptr);
      AddVar_GetNoAntiAliasing( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------

/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(int pointSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pointSize'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'underlined' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  int pointSize;
  if (!get_val_param<int >(pointSize,_p,_n,true,true)) ClassReturnEmptyVar;

  int family;
  if (!get_val_param<int >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int style;
  if (!get_val_param<int >(style,_p,_n,true,true)) ClassReturnEmptyVar;

  int weight;
  if (!get_val_param<int >(weight,_p,_n,true,true)) ClassReturnEmptyVar;

  int underlined_int = ((false==true)?1:0);;
  if (!get_val_param<int >(underlined_int,_p,_n,false,true)) ClassReturnEmptyVar;
  bool underlined = (bool) (underlined_int>0.5);

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
  if (!get_val_param<wxFontEncoding >(encoding,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFont * res =   wxFontBase::New(pointSize, family, style, weight, underlined, face, encoding);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... static wxFontBase::New(...)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFontBase::wrap_static_New_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: wxFontFamily, wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(int pointSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pointSize'")
  ADDPARAMCOMMENT_TYPE( wxFontFamily, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxFONTFLAG_DEFAULT)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int pointSize;
  if (!get_val_param<int >(pointSize,_p,_n,true,true)) ClassReturnEmptyVar;

  wxFontFamily family;
  if (!get_val_param<wxFontFamily >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int flags = wxFONTFLAG_DEFAULT;
  if (!get_val_param<int >(flags,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
  if (!get_val_param<wxFontEncoding >(encoding,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFont * res =   wxFontBase::New(pointSize, family, flags, face, encoding);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(wxSize const & pixelSize, int family, int style, int weight, bool underlined = false, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'pixelSize'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'weight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'underlined' (def:false)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > pixelSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(pixelSize_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & pixelSize = *pixelSize_smtptr;

  int family;
  if (!get_val_param<int >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int style;
  if (!get_val_param<int >(style,_p,_n,true,true)) ClassReturnEmptyVar;

  int weight;
  if (!get_val_param<int >(weight,_p,_n,true,true)) ClassReturnEmptyVar;

  int underlined_int = ((false==true)?1:0);;
  if (!get_val_param<int >(underlined_int,_p,_n,false,true)) ClassReturnEmptyVar;
  bool underlined = (bool) (underlined_int>0.5);

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
  if (!get_val_param<wxFontEncoding >(encoding,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFont * res =   wxFontBase::New(pixelSize, family, style, weight, underlined, face, encoding);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: wxFontFamily, wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(wxSize const & pixelSize, wxFontFamily family, int flags = wxFONTFLAG_DEFAULT, wxString const & face = wxEmptyString, wxFontEncoding encoding = wxFONTENCODING_DEFAULT)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'pixelSize'")
  ADDPARAMCOMMENT_TYPE( wxFontFamily, "parameter named 'family'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:wxFONTFLAG_DEFAULT)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding' (def:wxFONTENCODING_DEFAULT)")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > pixelSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(pixelSize_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & pixelSize = *pixelSize_smtptr;

  wxFontFamily family;
  if (!get_val_param<wxFontFamily >(family,_p,_n,true,true)) ClassReturnEmptyVar;

  int flags = wxFONTFLAG_DEFAULT;
  if (!get_val_param<int >(flags,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & face = ( face_smtptr.get() ? (*face_smtptr) : wxString(wxEmptyString) );

  wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
  if (!get_val_param<wxFontEncoding >(encoding,_p,_n,false,true)) ClassReturnEmptyVar;

  wxFont * res =   wxFontBase::New(pixelSize, family, flags, face, encoding);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(wxNativeFontInfo const & nativeFontDesc)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNativeFontInfo, "parameter named 'nativeFontDesc'")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxNativeFontInfo > nativeFontDesc_smtptr;
  if (!get_val_smtptr_param<wxNativeFontInfo >(nativeFontDesc_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxNativeFontInfo const & nativeFontDesc = *nativeFontDesc_smtptr;

  wxFont * res =   wxFontBase::New(nativeFontDesc);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of wxFont * wxFontBase::New(wxString const & strNativeFontDesc)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_New_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'strNativeFontDesc'")
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_New_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > strNativeFontDesc_smtptr;
  if (!get_val_smtptr_param<wxString >(strNativeFontDesc_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & strNativeFontDesc = *strNativeFontDesc_smtptr;

  wxFont * res =   wxFontBase::New(strNativeFontDesc);
  BasicVariable::ptr res_var = WrapClass_wxFont::CreateVar(res);
  return res_var;
}
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of wxFontEncoding wxFontBase::GetDefaultEncoding()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_GetDefaultEncoding::SetParametersComments()
{
  return_comments="returning a variable of type wxFontEncoding";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_GetDefaultEncoding::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFontEncoding res =   wxFontBase::GetDefaultEncoding();
  return AMILabType<wxFontEncoding >::CreateVar(res);
}
*/
/* The following types are missing: wxFontEncoding

//---------------------------------------------------
//  Wrapping of void wxFontBase::SetDefaultEncoding(wxFontEncoding encoding)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_static_SetDefaultEncoding::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFontEncoding, "parameter named 'encoding'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_static_SetDefaultEncoding::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxFontEncoding encoding;
  if (!get_val_param<wxFontEncoding >(encoding,_p,_n,true,false)) ClassHelpAndReturn;

  wxFontBase::SetDefaultEncoding(encoding);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxFontBase::Ok()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::IsOk()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxSize wxFontBase::GetPixelSize()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetPixelSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetPixelSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetPixelSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::IsUsingSizeInPixels()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_IsUsingSizeInPixels::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_IsUsingSizeInPixels::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsUsingSizeInPixels();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::IsFixedWidth()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_IsFixedWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_IsFixedWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFixedWidth();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxFontBase::GetNativeFontInfoDesc()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetNativeFontInfoDesc::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetNativeFontInfoDesc::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetNativeFontInfoDesc();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFontBase::GetNativeFontInfoUserDesc()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetNativeFontInfoUserDesc::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetNativeFontInfoUserDesc::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetNativeFontInfoUserDesc();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFontBase::SetPixelSize(wxSize const & pixelSize)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetPixelSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'pixelSize'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetPixelSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > pixelSize_smtptr;
  if (!get_val_smtptr_param<wxSize >(pixelSize_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSize const & pixelSize = *pixelSize_smtptr;

  this->_objectptr->GetObj()->SetPixelSize(pixelSize);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::SetFaceName(wxString const & faceName)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetFaceName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'faceName'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetFaceName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > faceName_smtptr;
  if (!get_val_smtptr_param<wxString >(faceName_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & faceName = *faceName_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFaceName(faceName);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: wxNativeFontInfo

//---------------------------------------------------
//  Wrapping of void wxFontBase::SetNativeFontInfo(wxNativeFontInfo const & info)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetNativeFontInfo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNativeFontInfo, "parameter named 'info'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetNativeFontInfo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxNativeFontInfo > info_smtptr;
  if (!get_val_smtptr_param<wxNativeFontInfo >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxNativeFontInfo const & info = *info_smtptr;

  this->_objectptr->GetObj()->SetNativeFontInfo(info);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxFontBase::SetNativeFontInfo(...)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetNativeFontInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetNativeFontInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxFontBase::wrap_SetNativeFontInfo_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::SetNativeFontInfo(wxString const & info)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetNativeFontInfo_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetNativeFontInfo_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > info_smtptr;
  if (!get_val_smtptr_param<wxString >(info_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & info = *info_smtptr;

  bool res =   this->_objectptr->GetObj()->SetNativeFontInfo(info);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::SetNativeFontInfoUserDesc(wxString const & info)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetNativeFontInfoUserDesc::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'info'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetNativeFontInfoUserDesc::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > info_smtptr;
  if (!get_val_smtptr_param<wxString >(info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & info = *info_smtptr;

  bool res =   this->_objectptr->GetObj()->SetNativeFontInfoUserDesc(info);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxString wxFontBase::GetFamilyString()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetFamilyString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetFamilyString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetFamilyString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFontBase::GetStyleString()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetStyleString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetStyleString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetStyleString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFontBase::GetWeightString()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetWeightString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetWeightString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetWeightString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFontBase::SetNoAntiAliasing(bool param0 = true)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_SetNoAntiAliasing::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_SetNoAntiAliasing::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int param0_int = ((true==true)?1:0);;
  if (!get_val_param<int >(param0_int,_p,_n,false,false)) ClassHelpAndReturn;
  bool param0 = (bool) (param0_int>0.5);

  this->_objectptr->GetObj()->SetNoAntiAliasing(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::GetNoAntiAliasing()
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap_GetNoAntiAliasing::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap_GetNoAntiAliasing::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetNoAntiAliasing();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxFontBase & wxFontBase::operator =(wxFontBase const & param0)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFontBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxFontBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFontBase > param0_smtptr;
  if (!get_val_smtptr_param<wxFontBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFontBase const & param0 = *param0_smtptr;

  wxFontBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxFontBase >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::operator ==(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (font);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxFontBase::operator !=(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxFontBase::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFontBase::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (font);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

