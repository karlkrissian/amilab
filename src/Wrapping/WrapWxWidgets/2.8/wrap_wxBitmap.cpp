/**
 * C++ Interface: wrap_wxBitmap
 *
 * Description: wrapping wxBitmap
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

#include "wrap_wxBitmap.h"

// get all the required includes
// #include "..."
#ifndef wxBitmap_declared
  #define wxBitmap_declared
  AMI_DECLARE_TYPE(wxBitmap)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxImage_declared
  #define wxImage_declared
  AMI_DECLARE_TYPE(wxImage)
#endif
#ifndef wxIcon_declared
  #define wxIcon_declared
  AMI_DECLARE_TYPE(wxIcon)
#endif
#ifndef wxMask_declared
  #define wxMask_declared
  AMI_DECLARE_TYPE(wxMask)
#endif
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
#endif
#ifndef wxPalette_declared
  #define wxPalette_declared
  AMI_DECLARE_TYPE(wxPalette)
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
BasicVariable::ptr WrapClass<wxBitmap>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmap::wrap_wxBitmap construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBitmap);
AMI_DEFINE_VARFROMSMTPTR(wxBitmap);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmap
//
Variable<AMIObject>::ptr WrapClass_wxBitmap::CreateVar( wxBitmap* sp)
{
  boost::shared_ptr<wxBitmap> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmap>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmap>::CreateVar(
      new WrapClass_wxBitmap(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmap::AddMethods(WrapClass<wxBitmap>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Ok( this_ptr);
  AddVar_IsOk( this_ptr);
  AddVar_Create( this_ptr);
  AddVar_GetHeight( this_ptr);
  AddVar_GetWidth( this_ptr);
  AddVar_GetDepth( this_ptr);
  AddVar_ConvertToImage( this_ptr);
  AddVar_CopyFromIcon( this_ptr);
  AddVar_GetMask( this_ptr);
  AddVar_SetMask( this_ptr);
  AddVar_GetSubBitmap( this_ptr);
  AddVar_SaveFile( this_ptr);
  AddVar_LoadFile( this_ptr);
  AddVar_GetPalette( this_ptr);
  AddVar_SetPalette( this_ptr);
  AddVar_GetColourMap( this_ptr);
  AddVar_SetHeight( this_ptr);
  AddVar_SetWidth( this_ptr);
  AddVar_SetDepth( this_ptr);
/* The following types are missing: _GdkDrawable
  AddVar_SetPixmap( this_ptr);
*/
/* The following types are missing: _GdkPixbuf
  AddVar_SetPixbuf( this_ptr);
*/
/* The following types are missing: _GdkDrawable
  AddVar_GetPixmap( this_ptr);
*/
  AddVar_HasPixmap( this_ptr);
  AddVar_HasPixbuf( this_ptr);
/* The following types are missing: _GdkPixbuf
  AddVar_GetPixbuf( this_ptr);
*/
  AddVar_Rescale( this_ptr);
/* The following types are missing: wxPixelDataBase
  AddVar_GetRawData( this_ptr);
*/
/* The following types are missing: wxPixelDataBase
  AddVar_UngetRawData( this_ptr);
*/
  AddVar_HasAlpha( this_ptr);
  AddVar_UseAlpha( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxBitmapBase
  boost::shared_ptr<wxBitmapBase > parent_wxBitmapBase(  boost::dynamic_pointer_cast<wxBitmapBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBitmapBase = AMILabType<wxBitmapBase >::CreateVarFromSmtPtr(parent_wxBitmapBase);
  context->AddVar("wxBitmapBase",var_wxBitmapBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBitmapBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBitmapBase);
  context->AddDefault(obj_wxBitmapBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBitmap_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBitmap");
    WrapClass_wxBitmap::AddVar_wxBitmap_1(amiobject->GetContext());
  WrapClass_wxBitmap::AddVar_wxBitmap(amiobject->GetContext());
  WrapClass_wxBitmap::AddVar_wxBitmap_2(amiobject->GetContext());
  WrapClass_wxBitmap::AddVar_wxBitmap_3(amiobject->GetContext());
  WrapClass_wxBitmap::AddVar_wxBitmap_4(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxBitmap::AddVar_wxBitmap_5(amiobject->GetContext());
  */
  WrapClass_wxBitmap::AddVar_wxBitmap_6(amiobject->GetContext());
  WrapClass_wxBitmap::AddVar_wxBitmap_7(amiobject->GetContext());


  // Static methods 
  WrapClass_wxBitmap::AddVar_InitStandardHandlers(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(wxBitmap const & param0)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBitmap const & param0 = *param0_smtptr;

  wxBitmap* _newobj = new wxBitmap(param0);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBitmap::wxBitmap(...)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmap::wrap_wxBitmap_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmap::wrap_wxBitmap_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxBitmap::wrap_wxBitmap_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxBitmap::wrap_wxBitmap_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxBitmap::wrap_wxBitmap_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxBitmap::wrap_wxBitmap_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmap* _newobj = new wxBitmap();
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(int width, int height, int depth = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  int depth = -0x00000000000000001;
  if (!get_val_param<int >(depth,_p,_n,false,true)) ClassReturnEmptyVar;

  wxBitmap* _newobj = new wxBitmap(width, height, depth);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(char const * bits, int width, int height, int depth = 1)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'bits'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:1)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > bits_string;
  if (!get_val_smtptr_param<std::string >(bits_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * bits = bits_string->c_str();

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  int depth = 1;
  if (!get_val_param<int >(depth,_p,_n,false,true)) ClassReturnEmptyVar;

  wxBitmap* _newobj = new wxBitmap(bits, width, height, depth);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}
/* The following types are missing: char const * const *

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(char const * const * bits)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'bits'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > bits_string;
  if (!get_val_smtptr_param<std::string >(bits_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  char const * const * bits = bits_string->c_str();

  wxBitmap* _newobj = new wxBitmap(bits);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(wxString const & filename, wxBitmapType type = wxBITMAP_TYPE_XPM)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxBITMAP_TYPE_XPM)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & filename = *filename_smtptr;

  int type_int = (int) wxBITMAP_TYPE_XPM;;
  if (!get_val_param<int >(type_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxBitmapType type = (wxBitmapType) type_int;

  wxBitmap* _newobj = new wxBitmap(filename, type);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmap::wxBitmap(wxImage const & image, int depth = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_wxBitmap_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_wxBitmap_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImage > image_smtptr;
  if (!get_val_smtptr_param<wxImage >(image_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxImage const & image = *image_smtptr;

  int depth = -0x00000000000000001;
  if (!get_val_param<int >(depth,_p,_n,false,true)) ClassReturnEmptyVar;

  wxBitmap* _newobj = new wxBitmap(image, depth);
  BasicVariable::ptr res = WrapClass_wxBitmap::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::InitStandardHandlers()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_static_InitStandardHandlers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_static_InitStandardHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap::InitStandardHandlers();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBitmap.
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBitmap object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBitmap >::CreateVar( new wxBitmap(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::Ok()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::IsOk()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::Create(int width, int height, int depth = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:-0x00000000000000001)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  int depth = -0x00000000000000001;
  if (!get_val_param<int >(depth,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Create(width, height, depth);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBitmap::GetHeight()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBitmap::GetWidth()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBitmap::GetDepth()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetDepth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetDepth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDepth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxBitmap::ConvertToImage()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_ConvertToImage::SetParametersComments()
{
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_ConvertToImage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ConvertToImage();
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::CopyFromIcon(wxIcon const & icon)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_CopyFromIcon::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_CopyFromIcon::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIcon const & icon = *icon_smtptr;

  bool res =   this->_objectptr->GetObj()->CopyFromIcon(icon);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMask * wxBitmap::GetMask()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetMask::SetParametersComments()
{
  return_comments="returning a variable of type wxMask";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetMask::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMask * res =   this->_objectptr->GetObj()->GetMask();
  BasicVariable::ptr res_var = AMILabType<wxMask >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetMask(wxMask * mask)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetMask::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMask, "parameter named 'mask'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetMask::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxMask* mask;
  if (CheckNullVar(_p,_n))  {
    mask=(wxMask*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMask > mask_smtptr;
    if (!get_val_smtptr_param<wxMask >(mask_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    mask = mask_smtptr.get();
  }

  this->_objectptr->GetObj()->SetMask(mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxBitmap wxBitmap::GetSubBitmap(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetSubBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetSubBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  wxBitmap res =   this->_objectptr->GetObj()->GetSubBitmap(rect);
  return AMILabType<wxBitmap >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::SaveFile(wxString const & name, wxBitmapType type, wxPalette const * palette = 0u)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SaveFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'palette' (def:0u)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SaveFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxBitmapType type = (wxBitmapType) type_int;

  wxPalette* palette = 0u;
  if (CheckNullVar(_p,_n))  {
    palette=(wxPalette*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxPalette > palette_smtptr;
    if (!get_val_smtptr_param<wxPalette >(palette_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    palette = palette_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->SaveFile(name, type, palette);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::LoadFile(wxString const & name, wxBitmapType type = wxBITMAP_TYPE_XPM)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_LoadFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxBITMAP_TYPE_XPM)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_LoadFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int type_int = (int) wxBITMAP_TYPE_XPM;;
  if (!get_val_param<int >(type_int,_p,_n,false,false)) ClassHelpAndReturn;
  wxBitmapType type = (wxBitmapType) type_int;

  bool res =   this->_objectptr->GetObj()->LoadFile(name, type);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPalette * wxBitmap::GetPalette()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetPalette::SetParametersComments()
{
  return_comments="returning a variable of type wxPalette";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPalette * res =   this->_objectptr->GetObj()->GetPalette();
  BasicVariable::ptr res_var = AMILabType<wxPalette >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetPalette(wxPalette const & palette)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetPalette::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'palette'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetPalette::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPalette > palette_smtptr;
  if (!get_val_smtptr_param<wxPalette >(palette_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPalette const & palette = *palette_smtptr;

  this->_objectptr->GetObj()->SetPalette(palette);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxPalette * wxBitmap::GetColourMap()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetColourMap::SetParametersComments()
{
  return_comments="returning a variable of type wxPalette";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetColourMap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPalette * res =   this->_objectptr->GetObj()->GetColourMap();
  BasicVariable::ptr res_var = AMILabType<wxPalette >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetHeight(int height)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetHeight(height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetWidth(int width)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetWidth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetWidth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetWidth(width);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetDepth(int depth)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetDepth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetDepth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int depth;
  if (!get_val_param<int >(depth,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDepth(depth);
  return BasicVariable::ptr();
}
/* The following types are missing: _GdkDrawable

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetPixmap(GdkPixmap * pixmap)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetPixmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkDrawable, "parameter named 'pixmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetPixmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _GdkDrawable* pixmap;
  if (CheckNullVar(_p,_n))  {
    pixmap=(_GdkDrawable*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GdkDrawable > pixmap_smtptr;
    if (!get_val_smtptr_param<_GdkDrawable >(pixmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    pixmap = pixmap_smtptr.get();
  }

  this->_objectptr->GetObj()->SetPixmap(pixmap);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: _GdkPixbuf

//---------------------------------------------------
//  Wrapping of void wxBitmap::SetPixbuf(GdkPixbuf * pixbuf, int depth = 0)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_SetPixbuf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _GdkPixbuf, "parameter named 'pixbuf'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_SetPixbuf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  _GdkPixbuf* pixbuf;
  if (CheckNullVar(_p,_n))  {
    pixbuf=(_GdkPixbuf*)NULL;
    _n++;
  } else {
    boost::shared_ptr<_GdkPixbuf > pixbuf_smtptr;
    if (!get_val_smtptr_param<_GdkPixbuf >(pixbuf_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    pixbuf = pixbuf_smtptr.get();
  }

  int depth = 0;
  if (!get_val_param<int >(depth,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPixbuf(pixbuf, depth);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: _GdkDrawable

//---------------------------------------------------
//  Wrapping of GdkPixmap * wxBitmap::GetPixmap()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetPixmap::SetParametersComments()
{
  return_comments="returning a variable of type _GdkDrawable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetPixmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkPixmap * res =   this->_objectptr->GetObj()->GetPixmap();
  return AMILabType<_GdkDrawable >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxBitmap::HasPixmap()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_HasPixmap::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_HasPixmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasPixmap();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmap::HasPixbuf()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_HasPixbuf::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_HasPixbuf::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasPixbuf();
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _GdkPixbuf

//---------------------------------------------------
//  Wrapping of GdkPixbuf * wxBitmap::GetPixbuf()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetPixbuf::SetParametersComments()
{
  return_comments="returning a variable of type _GdkPixbuf";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetPixbuf::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkPixbuf * res =   this->_objectptr->GetObj()->GetPixbuf();
  return AMILabType<_GdkPixbuf >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxBitmap wxBitmap::Rescale(int clipx, int clipy, int clipwidth, int clipheight, int width, int height)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_Rescale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clipx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clipy'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clipwidth'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clipheight'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_Rescale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  int clipx;
  if (!get_val_param<int >(clipx,_p,_n,true,false)) ClassHelpAndReturn;

  int clipy;
  if (!get_val_param<int >(clipy,_p,_n,true,false)) ClassHelpAndReturn;

  int clipwidth;
  if (!get_val_param<int >(clipwidth,_p,_n,true,false)) ClassHelpAndReturn;

  int clipheight;
  if (!get_val_param<int >(clipheight,_p,_n,true,false)) ClassHelpAndReturn;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  wxBitmap res =   this->_objectptr->GetObj()->Rescale(clipx, clipy, clipwidth, clipheight, width, height);
  return AMILabType<wxBitmap >::CreateVar(res);
}
/* The following types are missing: wxPixelDataBase

//---------------------------------------------------
//  Wrapping of void * wxBitmap::GetRawData(wxPixelDataBase & data, int bpp)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetRawData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPixelDataBase, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bpp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetRawData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPixelDataBase > data_smtptr;
  if (!get_val_smtptr_param<wxPixelDataBase >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPixelDataBase & data = *data_smtptr;

  int bpp;
  if (!get_val_param<int >(bpp,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetRawData(data, bpp);
  return BasicVariable::ptr();
}
*/
/* The following types are missing: wxPixelDataBase

//---------------------------------------------------
//  Wrapping of void wxBitmap::UngetRawData(wxPixelDataBase & data)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_UngetRawData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPixelDataBase, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_UngetRawData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPixelDataBase > data_smtptr;
  if (!get_val_smtptr_param<wxPixelDataBase >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPixelDataBase & data = *data_smtptr;

  this->_objectptr->GetObj()->UngetRawData(data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of bool wxBitmap::HasAlpha()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_HasAlpha::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_HasAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasAlpha();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBitmap::UseAlpha()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_UseAlpha::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_UseAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UseAlpha();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBitmap::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBitmap & wxBitmap::operator =(wxBitmap const & param0)
//---------------------------------------------------
void WrapClass_wxBitmap::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'param0'")
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & param0 = *param0_smtptr;

  wxBitmap & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBitmap >::CreateVar(res);
}

