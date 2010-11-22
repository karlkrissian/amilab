/**
 * C++ Interface: wrap_wxImage
 *
 * Description: wrapping wxImage
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
#include "wrap_wxImage.h"
#include "wrap_wxString.h"
#include "wrap_wxInputStream.h"
#include "wrap_wxList.h"
#include "wrap_wxImageHandler.h"
#include "wrap_wxRect.h"
#include "wrap_wxSize.h"
#include "wrap_wxPoint.h"
#include "wrap_wxOutputStream.h"
#include "wrap_wxPalette.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxImageHistogram.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxImage.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxImage>::CreateVar( ParamList* p)
{
  WrapClass_wxImage::wrap_wxImage construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxImage);
AMI_DEFINE_VARFROMSMTPTR(wxImage);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxImage
//
Variable<AMIObject>::ptr WrapClass_wxImage::CreateVar( wxImage* sp)
{
  boost::shared_ptr<wxImage> di_ptr(
    sp,
    wxwindow_nodeleter<wxImage>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxImage>::CreateVar(
      new WrapClass_wxImage(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxImage::AddMethods(WrapClass<wxImage>::ptr this_ptr )
{
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Create_1( this_ptr);
      AddVar_Create( this_ptr);
      AddVar_Create_2( this_ptr);
      AddVar_Create_3( this_ptr);
/* The following types are missing: char const * const *
      AddVar_Create_4( this_ptr);
*/
      AddVar_Destroy( this_ptr);
      AddVar_Copy( this_ptr);
      AddVar_GetSubImage( this_ptr);
      AddVar_Size( this_ptr);
      AddVar_Paste( this_ptr);
      AddVar_Scale( this_ptr);
      AddVar_ResampleBox( this_ptr);
      AddVar_ResampleBicubic( this_ptr);
      AddVar_Blur( this_ptr);
      AddVar_BlurHorizontal( this_ptr);
      AddVar_BlurVertical( this_ptr);
      AddVar_ShrinkBy( this_ptr);
      AddVar_Rescale( this_ptr);
      AddVar_Resize( this_ptr);
      AddVar_Rotate( this_ptr);
      AddVar_Rotate90( this_ptr);
      AddVar_Mirror( this_ptr);
      AddVar_Replace( this_ptr);
      AddVar_ConvertToGreyscale( this_ptr);
      AddVar_ConvertToMono( this_ptr);
      AddVar_SetRGB_1( this_ptr);
      AddVar_SetRGB( this_ptr);
      AddVar_SetRGB_2( this_ptr);
      AddVar_GetRed( this_ptr);
      AddVar_GetGreen( this_ptr);
      AddVar_GetBlue( this_ptr);
      AddVar_SetAlpha_1( this_ptr);
      AddVar_GetAlpha_1( this_ptr);
      AddVar_FindFirstUnusedColour( this_ptr);
      AddVar_SetMaskFromImage( this_ptr);
      AddVar_ConvertAlphaToMask( this_ptr);
      AddVar_ConvertColourToAlpha( this_ptr);
      AddVar_LoadFile_1( this_ptr);
      AddVar_LoadFile( this_ptr);
      AddVar_LoadFile_2( this_ptr);
      AddVar_LoadFile_3( this_ptr);
      AddVar_LoadFile_4( this_ptr);
      AddVar_SaveFile_1( this_ptr);
      AddVar_SaveFile( this_ptr);
      AddVar_SaveFile_2( this_ptr);
      AddVar_SaveFile_3( this_ptr);
      AddVar_SaveFile_4( this_ptr);
      AddVar_SaveFile_5( this_ptr);
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_GetWidth( this_ptr);
      AddVar_GetHeight( this_ptr);
      AddVar_GetData( this_ptr);
      AddVar_SetData_1( this_ptr);
      AddVar_SetData( this_ptr);
      AddVar_SetData_2( this_ptr);
      AddVar_GetAlpha( this_ptr);
      AddVar_GetAlpha_2( this_ptr);
      AddVar_HasAlpha( this_ptr);
      AddVar_SetAlpha( this_ptr);
      AddVar_SetAlpha_2( this_ptr);
      AddVar_InitAlpha( this_ptr);
      AddVar_IsTransparent( this_ptr);
      AddVar_SetMaskColour( this_ptr);
      AddVar_GetOrFindMaskColour( this_ptr);
      AddVar_GetMaskRed( this_ptr);
      AddVar_GetMaskGreen( this_ptr);
      AddVar_GetMaskBlue( this_ptr);
      AddVar_SetMask( this_ptr);
      AddVar_HasMask( this_ptr);
      AddVar_HasPalette( this_ptr);
      AddVar_GetPalette( this_ptr);
      AddVar_SetPalette( this_ptr);
      AddVar_SetOption_1( this_ptr);
      AddVar_SetOption( this_ptr);
      AddVar_SetOption_2( this_ptr);
      AddVar_GetOption( this_ptr);
      AddVar_GetOptionInt( this_ptr);
      AddVar_HasOption( this_ptr);
      AddVar_CountColours( this_ptr);
      AddVar_ComputeHistogram( this_ptr);
      AddVar_RotateHue( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(wxImage const & param0)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxImage > param0_smtptr;
  if (!get_val_smtptr_param<wxImage >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
  wxImage const & param0 = *param0_smtptr;

  wxImage* _newobj = new wxImage(param0);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxImage::wxImage(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_wxImage_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_7 m7;
  res = m7.CallMember(_p);
  if (!m7.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_9 m9;
  res = m9.CallMember(_p);
  if (!m9.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_wxImage_10 m10;
  res = m10.CallMember(_p);
  if (!m10.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxImage* _newobj = new wxImage();
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(int width, int height, bool clear = true)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clear' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int clear_int = ((true==true)?1:0);;
  if (!get_val_param<int >(clear_int,_p,_n)) ClassReturnEmptyVar;
  bool clear = (bool) (clear_int>0.5);

  wxImage* _newobj = new wxImage(width, height, clear);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(int width, int height, unsigned char * data, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  wxImage* _newobj = new wxImage(width, height, data, static_data);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(int width, int height, unsigned char * data, unsigned char * alpha, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  boost::shared_ptr<unsigned char > alpha_smtptr;
  if (!get_val_smtptr_param<unsigned char >(alpha_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* alpha = alpha_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  wxImage* _newobj = new wxImage(width, height, data, alpha, static_data);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(wxString const & name, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  wxImage* _newobj = new wxImage(name, type, index);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(wxString const & name, wxString const & mimetype, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_7::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_7::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  wxImage* _newobj = new wxImage(name, mimetype, index);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}
/* The following types are missing: char const * const *

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(char const * const * xpmData)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_8::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'xpmData'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_8::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > xpmData_string;
  if (!get_val_smtptr_param<std::string >(xpmData_string,_p,_n)) ClassReturnEmptyVar;
  char const * const * xpmData = xpmData_string->c_str();

  wxImage* _newobj = new wxImage(xpmData);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}
*/

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_9::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_9::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  wxImage* _newobj = new wxImage(stream, type, index);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxImage::wxImage(wxInputStream & stream, wxString const & mimetype, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_wxImage_10::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_wxImage_10::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  wxImage* _newobj = new wxImage(stream, mimetype, index);
  BasicVariable::ptr res = WrapClass_wxImage::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxImage::CanRead(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_CanRead_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_CanRead_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  bool res =   wxImage::CanRead(name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxImage::GetImageCount(wxString const & name, long int type = wxBITMAP_TYPE_ANY)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetImageCount_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetImageCount_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int res =   wxImage::GetImageCount(name, type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::CanRead(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_CanRead::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_CanRead::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_CanRead_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_CanRead_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxImage::CanRead(wxInputStream & stream)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_CanRead_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_CanRead_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  bool res =   wxImage::CanRead(stream);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::GetImageCount(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetImageCount::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetImageCount::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_GetImageCount_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_GetImageCount_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of int wxImage::GetImageCount(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetImageCount_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetImageCount_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int res =   wxImage::GetImageCount(stream, type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxList & wxImage::GetHandlers()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetHandlers::SetParametersComments()
{
  return_comments="returning a variable of type wxList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxList & res =   wxImage::GetHandlers();
  return AMILabType<wxList >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::AddHandler(wxImageHandler * handler)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_AddHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_AddHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxImageHandler >(handler_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImageHandler* handler = handler_smtptr.get();

  wxImage::AddHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImage::InsertHandler(wxImageHandler * handler)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_InsertHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHandler, "parameter named 'handler'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_InsertHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHandler > handler_smtptr;
  if (!get_val_smtptr_param<wxImageHandler >(handler_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImageHandler* handler = handler_smtptr.get();

  wxImage::InsertHandler(handler);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxImage::RemoveHandler(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_RemoveHandler::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_RemoveHandler::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool res =   wxImage::RemoveHandler(name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxImageHandler * wxImage::FindHandler(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindHandler_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxImageHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindHandler_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  wxImageHandler * res =   wxImage::FindHandler(name);
  BasicVariable::ptr res_var = WrapClass_wxImageHandler::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::FindHandler(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindHandler::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindHandler::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_FindHandler_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_FindHandler_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_FindHandler_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxImageHandler * wxImage::FindHandler(wxString const & extension, long int imageType)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindHandler_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'extension'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'imageType'")
  return_comments="returning a variable of type wxImageHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindHandler_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > extension_smtptr;
  if (!get_val_smtptr_param<wxString >(extension_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & extension = *extension_smtptr;

  long imageType_long;
  if (!get_val_param<long >(imageType_long,_p,_n)) ClassReturnEmptyVar;
  long int imageType = imageType_long;

  wxImageHandler * res =   wxImage::FindHandler(extension, imageType);
  BasicVariable::ptr res_var = WrapClass_wxImageHandler::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxImageHandler * wxImage::FindHandler(long int imageType)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindHandler_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'imageType'")
  return_comments="returning a variable of type wxImageHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindHandler_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  long imageType_long;
  if (!get_val_param<long >(imageType_long,_p,_n)) ClassReturnEmptyVar;
  long int imageType = imageType_long;

  wxImageHandler * res =   wxImage::FindHandler(imageType);
  BasicVariable::ptr res_var = WrapClass_wxImageHandler::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxImageHandler * wxImage::FindHandlerMime(wxString const & mimetype)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindHandlerMime::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  return_comments="returning a variable of type wxImageHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindHandlerMime::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & mimetype = *mimetype_smtptr;

  wxImageHandler * res =   wxImage::FindHandlerMime(mimetype);
  BasicVariable::ptr res_var = WrapClass_wxImageHandler::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxString wxImage::GetImageExtWildcard()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetImageExtWildcard::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetImageExtWildcard::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   wxImage::GetImageExtWildcard();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::CleanUpHandlers()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_CleanUpHandlers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_CleanUpHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxImage::CleanUpHandlers();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImage::InitStandardHandlers()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_InitStandardHandlers::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_InitStandardHandlers::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxImage::InitStandardHandlers();
  return BasicVariable::ptr();
}
/* The following types are missing: HSVValue, RGBValue

//---------------------------------------------------
//  Wrapping of HSVValue wxImage::RGBtoHSV(RGBValue const & rgb)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_RGBtoHSV::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( RGBValue, "parameter named 'rgb'")
  return_comments="returning a variable of type HSVValue";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_RGBtoHSV::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<RGBValue > rgb_smtptr;
  if (!get_val_smtptr_param<RGBValue >(rgb_smtptr,_p,_n)) ClassHelpAndReturn;
  RGBValue const & rgb = *rgb_smtptr;

  HSVValue res =   wxImage::RGBtoHSV(rgb);
  return AMILabType<HSVValue >::CreateVar(res);
}
*/
/* The following types are missing: RGBValue, HSVValue

//---------------------------------------------------
//  Wrapping of RGBValue wxImage::HSVtoRGB(HSVValue const & hsv)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_HSVtoRGB::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( HSVValue, "parameter named 'hsv'")
  return_comments="returning a variable of type RGBValue";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_HSVtoRGB::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<HSVValue > hsv_smtptr;
  if (!get_val_smtptr_param<HSVValue >(hsv_smtptr,_p,_n)) ClassHelpAndReturn;
  HSVValue const & hsv = *hsv_smtptr;

  RGBValue res =   wxImage::HSVtoRGB(hsv);
  return AMILabType<RGBValue >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of 'copy' method for wxImage.
//---------------------------------------------------
void WrapClass_wxImage::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxImage object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxImage >::CreateVar( new wxImage(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxImage::Create(int width, int height, bool clear = true)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Create_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clear' (def:true)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Create_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  int clear_int = ((true==true)?1:0);;
  if (!get_val_param<int >(clear_int,_p,_n)) ClassReturnEmptyVar;
  bool clear = (bool) (clear_int>0.5);

  bool res =   this->_objectptr->GetObj()->Create(width, height, clear);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::Create(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Create::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Create::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_Create_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_Create_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_Create_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxImage::Create(int width, int height, unsigned char * data, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Create_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Create_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  bool res =   this->_objectptr->GetObj()->Create(width, height, data, static_data);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::Create(int width, int height, unsigned char * data, unsigned char * alpha, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Create_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Create_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  boost::shared_ptr<unsigned char > alpha_smtptr;
  if (!get_val_smtptr_param<unsigned char >(alpha_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* alpha = alpha_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  bool res =   this->_objectptr->GetObj()->Create(width, height, data, alpha, static_data);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
/* The following types are missing: char const * const *

//---------------------------------------------------
//  Wrapping of bool wxImage::Create(char const * const * xpmData)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Create_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'xpmData'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Create_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > xpmData_string;
  if (!get_val_smtptr_param<std::string >(xpmData_string,_p,_n)) ClassReturnEmptyVar;
  char const * const * xpmData = xpmData_string->c_str();

  bool res =   this->_objectptr->GetObj()->Create(xpmData);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

//---------------------------------------------------
//  Wrapping of void wxImage::Destroy()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Destroy::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Destroy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Destroy();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Copy()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Copy::SetParametersComments()
{
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Copy::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->Copy();
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::GetSubImage(wxRect const & rect)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetSubImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetSubImage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassHelpAndReturn;
  wxRect const & rect = *rect_smtptr;

  wxImage res =   this->_objectptr->GetObj()->GetSubImage(rect);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Size(wxSize const & size, wxPoint const & pos, int r = -0x00000000000000001, int g = -0x00000000000000001, int b = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Size::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'r' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'g' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:-0x00000000000000001)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Size::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  int r = -0x00000000000000001;
  if (!get_val_param<int >(r,_p,_n)) ClassHelpAndReturn;

  int g = -0x00000000000000001;
  if (!get_val_param<int >(g,_p,_n)) ClassHelpAndReturn;

  int b = -0x00000000000000001;
  if (!get_val_param<int >(b,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->Size(size, pos, r, g, b);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::Paste(wxImage const & image, int x, int y)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Paste::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'image'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Paste::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImage > image_smtptr;
  if (!get_val_smtptr_param<wxImage >(image_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImage const & image = *image_smtptr;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Paste(image, x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Scale(int width, int height, int quality = wxIMAGE_QUALITY_NORMAL)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Scale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'quality' (def:wxIMAGE_QUALITY_NORMAL)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Scale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  int quality = wxIMAGE_QUALITY_NORMAL;
  if (!get_val_param<int >(quality,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->Scale(width, height, quality);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::ResampleBox(int width, int height)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ResampleBox::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ResampleBox::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ResampleBox(width, height);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::ResampleBicubic(int width, int height)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ResampleBicubic::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ResampleBicubic::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ResampleBicubic(width, height);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Blur(int radius)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Blur::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'radius'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Blur::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int radius;
  if (!get_val_param<int >(radius,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->Blur(radius);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::BlurHorizontal(int radius)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_BlurHorizontal::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'radius'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_BlurHorizontal::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int radius;
  if (!get_val_param<int >(radius,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->BlurHorizontal(radius);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::BlurVertical(int radius)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_BlurVertical::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'radius'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_BlurVertical::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int radius;
  if (!get_val_param<int >(radius,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->BlurVertical(radius);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::ShrinkBy(int xFactor, int yFactor)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ShrinkBy::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xFactor'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yFactor'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ShrinkBy::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int xFactor;
  if (!get_val_param<int >(xFactor,_p,_n)) ClassHelpAndReturn;

  int yFactor;
  if (!get_val_param<int >(yFactor,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ShrinkBy(xFactor, yFactor);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage & wxImage::Rescale(int width, int height, int quality = wxIMAGE_QUALITY_NORMAL)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Rescale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'quality' (def:wxIMAGE_QUALITY_NORMAL)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Rescale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  int quality = wxIMAGE_QUALITY_NORMAL;
  if (!get_val_param<int >(quality,_p,_n)) ClassHelpAndReturn;

  wxImage & res =   this->_objectptr->GetObj()->Rescale(width, height, quality);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage & wxImage::Resize(wxSize const & size, wxPoint const & pos, int r = -0x00000000000000001, int g = -0x00000000000000001, int b = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Resize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'r' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'g' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b' (def:-0x00000000000000001)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Resize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n)) ClassHelpAndReturn;
  wxSize const & size = *size_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  int r = -0x00000000000000001;
  if (!get_val_param<int >(r,_p,_n)) ClassHelpAndReturn;

  int g = -0x00000000000000001;
  if (!get_val_param<int >(g,_p,_n)) ClassHelpAndReturn;

  int b = -0x00000000000000001;
  if (!get_val_param<int >(b,_p,_n)) ClassHelpAndReturn;

  wxImage & res =   this->_objectptr->GetObj()->Resize(size, pos, r, g, b);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Rotate(double angle, wxPoint const & centre_of_rotation, bool interpolating = true, wxPoint * offset_after_rotation = 0u)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Rotate::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'centre_of_rotation'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'interpolating' (def:true)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'offset_after_rotation' (def:0u)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Rotate::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > centre_of_rotation_smtptr;
  if (!get_val_smtptr_param<wxPoint >(centre_of_rotation_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint const & centre_of_rotation = *centre_of_rotation_smtptr;

  int interpolating_int = ((true==true)?1:0);;
  if (!get_val_param<int >(interpolating_int,_p,_n)) ClassHelpAndReturn;
  bool interpolating = (bool) (interpolating_int>0.5);

  boost::shared_ptr<wxPoint > offset_after_rotation_smtptr;
  if (!get_val_smtptr_param<wxPoint >(offset_after_rotation_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPoint* offset_after_rotation = offset_after_rotation_smtptr.get();

  wxImage res =   this->_objectptr->GetObj()->Rotate(angle, centre_of_rotation, interpolating, offset_after_rotation);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Rotate90(bool clockwise = true)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Rotate90::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'clockwise' (def:true)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Rotate90::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int clockwise_int = ((true==true)?1:0);;
  if (!get_val_param<int >(clockwise_int,_p,_n)) ClassHelpAndReturn;
  bool clockwise = (bool) (clockwise_int>0.5);

  wxImage res =   this->_objectptr->GetObj()->Rotate90(clockwise);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::Mirror(bool horizontally = true)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Mirror::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'horizontally' (def:true)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Mirror::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int horizontally_int = ((true==true)?1:0);;
  if (!get_val_param<int >(horizontally_int,_p,_n)) ClassHelpAndReturn;
  bool horizontally = (bool) (horizontally_int>0.5);

  wxImage res =   this->_objectptr->GetObj()->Mirror(horizontally);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::Replace(unsigned char r1, unsigned char g1, unsigned char b1, unsigned char r2, unsigned char g2, unsigned char b2)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Replace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r1'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g1'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b1'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r2'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g2'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b2'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Replace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  unsigned char r1;
  if (!get_val_param<unsigned char >(r1,_p,_n)) ClassHelpAndReturn;

  unsigned char g1;
  if (!get_val_param<unsigned char >(g1,_p,_n)) ClassHelpAndReturn;

  unsigned char b1;
  if (!get_val_param<unsigned char >(b1,_p,_n)) ClassHelpAndReturn;

  unsigned char r2;
  if (!get_val_param<unsigned char >(r2,_p,_n)) ClassHelpAndReturn;

  unsigned char g2;
  if (!get_val_param<unsigned char >(g2,_p,_n)) ClassHelpAndReturn;

  unsigned char b2;
  if (!get_val_param<unsigned char >(b2,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Replace(r1, g1, b1, r2, g2, b2);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::ConvertToGreyscale(double lr = 2.98999999999999988009591334048309363424777984619140625e-1, double lg = 5.869999999999999662492200513952411711215972900390625e-1, double lb = 1.1400000000000000410782519111307919956743717193603515625e-1)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ConvertToGreyscale::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'lr' (def:2.98999999999999988009591334048309363424777984619140625e-1)")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'lg' (def:5.869999999999999662492200513952411711215972900390625e-1)")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'lb' (def:1.1400000000000000410782519111307919956743717193603515625e-1)")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ConvertToGreyscale::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  double lr = 2.98999999999999988009591334048309363424777984619140625e-1;
  if (!get_val_param<double >(lr,_p,_n)) ClassHelpAndReturn;

  double lg = 5.869999999999999662492200513952411711215972900390625e-1;
  if (!get_val_param<double >(lg,_p,_n)) ClassHelpAndReturn;

  double lb = 1.1400000000000000410782519111307919956743717193603515625e-1;
  if (!get_val_param<double >(lb,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ConvertToGreyscale(lr, lg, lb);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxImage wxImage::ConvertToMono(unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ConvertToMono::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ConvertToMono::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n)) ClassHelpAndReturn;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n)) ClassHelpAndReturn;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n)) ClassHelpAndReturn;

  wxImage res =   this->_objectptr->GetObj()->ConvertToMono(r, g, b);
  return AMILabType<wxImage >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetRGB(int x, int y, unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetRGB_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetRGB_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>5) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n)) ClassReturnEmptyVar;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n)) ClassReturnEmptyVar;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetRGB(x, y, r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::SetRGB(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetRGB::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetRGB::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_SetRGB_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SetRGB_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetRGB(wxRect const & rect, unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetRGB_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetRGB_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxRect const & rect = *rect_smtptr;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n)) ClassReturnEmptyVar;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n)) ClassReturnEmptyVar;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetRGB(rect, r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetRed(int x, int y)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetRed::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetRed::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetRed(x, y);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetGreen(int x, int y)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetGreen::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetGreen::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetGreen(x, y);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetBlue(int x, int y)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetBlue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetBlue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetBlue(x, y);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetAlpha(int x, int y, unsigned char alpha)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetAlpha_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetAlpha_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  unsigned char alpha;
  if (!get_val_param<unsigned char >(alpha,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetAlpha(x, y, alpha);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetAlpha(int x, int y)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetAlpha_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetAlpha_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassReturnEmptyVar;

  unsigned char res =   this->_objectptr->GetObj()->GetAlpha(x, y);
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::FindFirstUnusedColour(unsigned char * r, unsigned char * g, unsigned char * b, unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_FindFirstUnusedColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startR' (def:1)")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startG' (def:0)")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'startB' (def:0)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_FindFirstUnusedColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<unsigned char > r_smtptr;
  if (!get_val_smtptr_param<unsigned char >(r_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* r = r_smtptr.get();

  boost::shared_ptr<unsigned char > g_smtptr;
  if (!get_val_smtptr_param<unsigned char >(g_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* g = g_smtptr.get();

  boost::shared_ptr<unsigned char > b_smtptr;
  if (!get_val_smtptr_param<unsigned char >(b_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* b = b_smtptr.get();

  unsigned char startR = 1;
  if (!get_val_param<unsigned char >(startR,_p,_n)) ClassHelpAndReturn;

  unsigned char startG = 0;
  if (!get_val_param<unsigned char >(startG,_p,_n)) ClassHelpAndReturn;

  unsigned char startB = 0;
  if (!get_val_param<unsigned char >(startB,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->FindFirstUnusedColour(r, g, b, startR, startG, startB);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SetMaskFromImage(wxImage const & mask, unsigned char mr, unsigned char mg, unsigned char mb)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetMaskFromImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'mask'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'mr'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'mg'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'mb'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetMaskFromImage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImage > mask_smtptr;
  if (!get_val_smtptr_param<wxImage >(mask_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImage const & mask = *mask_smtptr;

  unsigned char mr;
  if (!get_val_param<unsigned char >(mr,_p,_n)) ClassHelpAndReturn;

  unsigned char mg;
  if (!get_val_param<unsigned char >(mg,_p,_n)) ClassHelpAndReturn;

  unsigned char mb;
  if (!get_val_param<unsigned char >(mb,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->SetMaskFromImage(mask, mr, mg, mb);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::ConvertAlphaToMask(unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ConvertAlphaToMask::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'threshold' (def:wxIMAGE_ALPHA_THRESHOLD)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ConvertAlphaToMask::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD;
  if (!get_val_param<unsigned char >(threshold,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ConvertAlphaToMask(threshold);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::ConvertColourToAlpha(unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ConvertColourToAlpha::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ConvertColourToAlpha::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n)) ClassHelpAndReturn;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n)) ClassHelpAndReturn;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ConvertColourToAlpha(r, g, b);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::LoadFile(wxString const & name, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_LoadFile_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_LoadFile_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->LoadFile(name, type, index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::LoadFile(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_LoadFile::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_LoadFile::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_LoadFile_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_LoadFile_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_LoadFile_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_LoadFile_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxImage::LoadFile(wxString const & name, wxString const & mimetype, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_LoadFile_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_LoadFile_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->LoadFile(name, mimetype, index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::LoadFile(wxInputStream & stream, long int type = wxBITMAP_TYPE_ANY, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_LoadFile_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type' (def:wxBITMAP_TYPE_ANY)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_LoadFile_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  long type_long = wxBITMAP_TYPE_ANY;;
  if (!get_val_param<long >(type_long,_p,_n)) ClassReturnEmptyVar;
  long int type = type_long;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->LoadFile(stream, type, index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::LoadFile(wxInputStream & stream, wxString const & mimetype, int index = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_LoadFile_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxInputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index' (def:-0x00000000000000001)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_LoadFile_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxInputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxInputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxInputStream & stream = *stream_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  int index = -0x00000000000000001;
  if (!get_val_param<int >(index,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->LoadFile(stream, mimetype, index);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SaveFile(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  bool res =   this->_objectptr->GetObj()->SaveFile(name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::SaveFile(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_SaveFile_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SaveFile_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SaveFile_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SaveFile_4 m4(this->_objectptr);
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SaveFile_5 m5(this->_objectptr);
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SaveFile(wxString const & name, int type)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  int type;
  if (!get_val_param<int >(type,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->SaveFile(name, type);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SaveFile(wxString const & name, wxString const & mimetype)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  bool res =   this->_objectptr->GetObj()->SaveFile(name, mimetype);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SaveFile(wxOutputStream & stream, int type)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxOutputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxOutputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxOutputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxOutputStream & stream = *stream_smtptr;

  int type;
  if (!get_val_param<int >(type,_p,_n)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->SaveFile(stream, type);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::SaveFile(wxOutputStream & stream, wxString const & mimetype)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SaveFile_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxOutputStream, "parameter named 'stream'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'mimetype'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SaveFile_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxOutputStream > stream_smtptr;
  if (!get_val_smtptr_param<wxOutputStream >(stream_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxOutputStream & stream = *stream_smtptr;

  boost::shared_ptr<wxString > mimetype_smtptr;
  if (!get_val_smtptr_param<wxString >(mimetype_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & mimetype = *mimetype_smtptr;

  bool res =   this->_objectptr->GetObj()->SaveFile(stream, mimetype);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::Ok()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::IsOk()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxImage::GetWidth()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxImage::GetHeight()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char * wxImage::GetData()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetData::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char * res =   this->_objectptr->GetObj()->GetData();
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetData(unsigned char * data, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetData_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetData_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  this->_objectptr->GetObj()->SetData(data, static_data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::SetData(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetData::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetData::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_SetData_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SetData_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetData(unsigned char * data, int new_width, int new_height, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetData_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'new_width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'new_height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetData_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char > data_smtptr;
  if (!get_val_smtptr_param<unsigned char >(data_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* data = data_smtptr.get();

  int new_width;
  if (!get_val_param<int >(new_width,_p,_n)) ClassReturnEmptyVar;

  int new_height;
  if (!get_val_param<int >(new_height,_p,_n)) ClassReturnEmptyVar;

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  this->_objectptr->GetObj()->SetData(data, new_width, new_height, static_data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::GetAlpha(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetAlpha::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetAlpha::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_GetAlpha_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_GetAlpha_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of unsigned char * wxImage::GetAlpha()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetAlpha_2::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetAlpha_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  unsigned char * res =   this->_objectptr->GetObj()->GetAlpha();
  return AMILabType<unsigned char >::CreateVar(res,true);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::HasAlpha()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_HasAlpha::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_HasAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasAlpha();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::SetAlpha(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetAlpha::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetAlpha::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_SetAlpha_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SetAlpha_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetAlpha(unsigned char * alpha = 0l, bool static_data = false)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetAlpha_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'alpha' (def:0l)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'static_data' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetAlpha_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<unsigned char > alpha_smtptr;
  if (!get_val_smtptr_param<unsigned char >(alpha_smtptr,_p,_n)) ClassReturnEmptyVar;
  unsigned char* alpha = alpha_smtptr.get();

  int static_data_int = ((false==true)?1:0);;
  if (!get_val_param<int >(static_data_int,_p,_n)) ClassReturnEmptyVar;
  bool static_data = (bool) (static_data_int>0.5);

  this->_objectptr->GetObj()->SetAlpha(alpha, static_data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImage::InitAlpha()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_InitAlpha::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_InitAlpha::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitAlpha();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxImage::IsTransparent(int x, int y, unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_IsTransparent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'threshold' (def:wxIMAGE_ALPHA_THRESHOLD)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_IsTransparent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  unsigned char threshold = wxIMAGE_ALPHA_THRESHOLD;
  if (!get_val_param<unsigned char >(threshold,_p,_n)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTransparent(x, y, threshold);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetMaskColour(unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetMaskColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetMaskColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n)) ClassHelpAndReturn;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n)) ClassHelpAndReturn;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMaskColour(r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxImage::GetOrFindMaskColour(unsigned char * r, unsigned char * g, unsigned char * b)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetOrFindMaskColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetOrFindMaskColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<unsigned char > r_smtptr;
  if (!get_val_smtptr_param<unsigned char >(r_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* r = r_smtptr.get();

  boost::shared_ptr<unsigned char > g_smtptr;
  if (!get_val_smtptr_param<unsigned char >(g_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* g = g_smtptr.get();

  boost::shared_ptr<unsigned char > b_smtptr;
  if (!get_val_smtptr_param<unsigned char >(b_smtptr,_p,_n)) ClassHelpAndReturn;
  unsigned char* b = b_smtptr.get();

  bool res =   this->_objectptr->GetObj()->GetOrFindMaskColour(r, g, b);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetMaskRed()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetMaskRed::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetMaskRed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetMaskRed();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetMaskGreen()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetMaskGreen::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetMaskGreen::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetMaskGreen();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of unsigned char wxImage::GetMaskBlue()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetMaskBlue::SetParametersComments()
{
  return_comments="returning a variable of type unsigned char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetMaskBlue::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned char res =   this->_objectptr->GetObj()->GetMaskBlue();
  return AMILabType<unsigned char >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetMask(bool mask = true)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetMask::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mask' (def:true)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetMask::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mask_int = ((true==true)?1:0);;
  if (!get_val_param<int >(mask_int,_p,_n)) ClassHelpAndReturn;
  bool mask = (bool) (mask_int>0.5);

  this->_objectptr->GetObj()->SetMask(mask);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxImage::HasMask()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_HasMask::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_HasMask::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasMask();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::HasPalette()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_HasPalette::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_HasPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasPalette();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxPalette const & wxImage::GetPalette()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetPalette::SetParametersComments()
{
  return_comments="returning a variable of type wxPalette";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetPalette::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPalette const & res =   this->_objectptr->GetObj()->GetPalette();
  return AMILabType<wxPalette >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetPalette(wxPalette const & palette)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetPalette::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'palette'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetPalette::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPalette > palette_smtptr;
  if (!get_val_smtptr_param<wxPalette >(palette_smtptr,_p,_n)) ClassHelpAndReturn;
  wxPalette const & palette = *palette_smtptr;

  this->_objectptr->GetObj()->SetPalette(palette);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetOption(wxString const & name, wxString const & value)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetOption_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetOption_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  boost::shared_ptr<wxString > value_smtptr;
  if (!get_val_smtptr_param<wxString >(value_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & value = *value_smtptr;

  this->_objectptr->GetObj()->SetOption(name, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxImage::SetOption(...)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetOption::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetOption::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxImage::wrap_SetOption_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxImage::wrap_SetOption_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxImage::SetOption(wxString const & name, int value)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_SetOption_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'value'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_SetOption_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxString const & name = *name_smtptr;

  int value;
  if (!get_val_param<int >(value,_p,_n)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetOption(name, value);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxImage::GetOption(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetOption::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetOption::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  wxString res =   this->_objectptr->GetObj()->GetOption(name);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxImage::GetOptionInt(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetOptionInt::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetOptionInt::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int res =   this->_objectptr->GetObj()->GetOptionInt(name);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxImage::HasOption(wxString const & name)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_HasOption::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_HasOption::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  bool res =   this->_objectptr->GetObj()->HasOption(name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of long unsigned int wxImage::CountColours(long unsigned int stopafter = -1ul)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_CountColours::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'stopafter' (def:-1ul)")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_CountColours::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long stopafter_long = boost::numeric_cast<long >(-1ul);;
  if (!get_val_param<long >(stopafter_long,_p,_n)) ClassHelpAndReturn;
  long unsigned int stopafter = boost::numeric_cast<long unsigned int >(stopafter_long);

  long unsigned int res =   this->_objectptr->GetObj()->CountColours(stopafter);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of long unsigned int wxImage::ComputeHistogram(wxImageHistogram & h)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_ComputeHistogram::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImageHistogram, "parameter named 'h'")
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_ComputeHistogram::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImageHistogram > h_smtptr;
  if (!get_val_smtptr_param<wxImageHistogram >(h_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImageHistogram & h = *h_smtptr;

  long unsigned int res =   this->_objectptr->GetObj()->ComputeHistogram(h);
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxImage::RotateHue(double angle)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_RotateHue::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'angle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_RotateHue::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  double angle;
  if (!get_val_param<double >(angle,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RotateHue(angle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxImage::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxImage::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxImage & wxImage::operator =(wxImage const & param0)
//---------------------------------------------------
void WrapClass_wxImage::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxImage, "parameter named 'param0'")
  return_comments="returning a variable of type wxImage";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxImage > param0_smtptr;
  if (!get_val_smtptr_param<wxImage >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxImage const & param0 = *param0_smtptr;

  wxImage & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxImage >::CreateVar(res);
}

