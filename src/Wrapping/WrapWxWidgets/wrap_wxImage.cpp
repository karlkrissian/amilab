//
// C++ Implementation: wrap_wxImage
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "AMILabConfig.h"

#ifdef AMI_USE_PRECOM_HEADERS
  #include "WrapWxWidgets_header.h"
#endif

#include "wrap_wxImage.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"


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


/*
//
// static member for creating a variable from a pointer to wxImage
//
Variable<AMIObject>::ptr WrapClass_wxImage::CreateVar( wxImage* p)
{
  boost::shared_ptr<wxImage> _obj_ptr( p);
  return WrapClass<wxImage>::CreateVar( new WrapClass_wxImage(_obj_ptr));
}
*/

//---------------------------------------------------
// Method that adds wrapping of wxBitmap
//---------------------------------------------------

void WrapClass_wxImage::
      wrap_wxImage::SetParametersComments() 
{
  ADDPARAMCOMMENT("no parameter (MODE 1) or a string (MODE 2).");
  ADDPARAMCOMMENT_TYPE(int,"The image type (def:wxBITMAP_TYPE_ANY) (MODE 2).");
  ADDPARAMCOMMENT_TYPE(int,"The image index for multiple images (def:-1) (MODE 2).");
  return_comments = "A wrapped wxImage object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_wxImage::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  if (p->GetNumParam()==0) 
    return AMILabType<wxImage>::CreateVar(new wxImage());

  if (p->GetNumParam()>=1) 
  {
    int n = 0;
    std::string* name=NULL;
  
    if (!get_val_ptr_param<std::string>(name,p,n)) ClassHelpAndReturn;
    GET_PARAM(int,type, wxBITMAP_TYPE_ANY);
    GET_PARAM(int,index,-1);

    wxImage* im = new wxImage();
    //bool res = 
    im->LoadFile( wxString(name->c_str(), wxConvUTF8),type,index);
    return AMILabType<wxImage>::CreateVar(im);
  }
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetWidth
//---------------------------------------------------
void WrapClass_wxImage::
      wrap_GetWidth::SetParametersComments() 
{
  return_comments="Image width.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_GetWidth::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetWidth();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  GetHeight
//---------------------------------------------------
void WrapClass_wxImage::
      wrap_GetHeight::SetParametersComments() 
{
  return_comments="Image height.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_GetHeight::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetHeight();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  IsOk
//---------------------------------------------------
void WrapClass_wxImage::
      wrap_IsOk::SetParametersComments() 
{
  return_comments="if image data is present.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_IsOk::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->IsOk();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Scale2
//---------------------------------------------------
void WrapClass_wxImage::
      wrap_Scale2::SetParametersComments() 
{
  ADDPARAMCOMMENT("width: new width.");
  ADDPARAMCOMMENT("height: new height.");
  return_comments="Scaled image.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_Scale2::CallMember( ParamList* p)
{
  int width=-1;
  int height=-1;
  int n = 0;
  if (!get_int_param(width, p, n)) ClassHelpAndReturn;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;

  return AMILabType<wxImage>::CreateVar(
    new wxImage(this->_objectptr->_obj->Scale(width,height)));
}


//---------------------------------------------------
//  SaveFile
//---------------------------------------------------
void WrapClass_wxImage::
      wrap_SaveFile::SetParametersComments() 
{
  ADDPARAMCOMMENT("string: name of the filename to save as.");
  return_comments="boolean: success information.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxImage::
      wrap_SaveFile::CallMember( ParamList* p)
{
  std::string* filename = NULL;
  int n = 0;
  if (!get_val_ptr_param<std::string>( filename,  p, n)) 
    ClassHelpAndReturn;

  int res = this->_objectptr->_obj->SaveFile(wxString(filename->c_str(),wxConvUTF8));
  RETURN_VAR(int,res);
}
