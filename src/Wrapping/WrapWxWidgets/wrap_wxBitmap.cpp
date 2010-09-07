//
// C++ Implementation: wrap_wxBitmap
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxBitmap.h"
#include "wrap_wxImage.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmap>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmap::wrap_wxBitmap construct;
  return construct.CallMember(p);
}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxBitmap)

//
// static member for creating a variable from a pointer to wxColour
//
Variable<AMIObject>::ptr WrapClass_wxBitmap::CreateVar( wxBitmap* sp)
{
  boost::shared_ptr<wxBitmap> _obj_ptr( 
    sp,
    wxwindow_nodeleter<wxBitmap>() // deletion will be done by wxwidgets
  );
  return WrapClass<wxBitmap>::CreateVar( new WrapClass_wxBitmap(_obj_ptr));
}


/*
//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxBitmap( wxBitmap* si)
{
  // here wxBitmap can be deleted
  boost::shared_ptr<wxBitmap> _si_ptr( 
    si,
    wxwindow_nodeleter<wxBitmap>() // deletion will be done by wxwidgets
  );

  WrapClass_wxBitmap::ptr sip(new WrapClass_wxBitmap(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxBitmap(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}
*/


//---------------------------------------------------
// Method that adds wrapping of wxBitmap
//---------------------------------------------------

void WrapClass_wxBitmap::
      wrap_wxBitmap::SetParametersComments() 
{
  ADDPARAMCOMMENT("A wxBitmap (MODE 1) or a wxImage (MODE 2).");
  ADDPARAMCOMMENT("The image depth (def:-1) (MODE 2).");
  return_comments = "A wrapped wxBitmap object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
      wrap_wxBitmap::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  if (p->GetNumParam()==0) 
    return WrapClass_wxBitmap::CreateVar(new wxBitmap());

  if (p->GetNumParam()>=1) 
  {
    int n = 0;
    int depth  = -1;
  
    GET_OBJECT_PARAM(wxImage,image,_obj);
    if (!image.get())  ClassHelpAndReturn;
    get_int_param(depth, p, n,false);

    if (image->IsOk()) {
      return WrapClass_wxBitmap::CreateVar(new wxBitmap( *image, depth));
    }
    else {
      FILE_ERROR("Input wxImage is not valid.");
      return WrapClass_wxBitmap::CreateVar(new wxBitmap());
    }
  }
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  GetWidth
//---------------------------------------------------
void WrapClass_wxBitmap::
      wrap_GetWidth::SetParametersComments() 
{
  return_comments="Image width.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
      wrap_GetWidth::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetWidth();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  GetHeight
//---------------------------------------------------
void WrapClass_wxBitmap::
      wrap_GetHeight::SetParametersComments() 
{
  return_comments="Image height.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
      wrap_GetHeight::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetHeight();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  IsOk
//---------------------------------------------------
void WrapClass_wxBitmap::
      wrap_IsOk::SetParametersComments() 
{
  return_comments="if image data is present.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
      wrap_IsOk::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->IsOk();
  RETURN_VAR(int,res);
}


//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_wxBitmap::
      wrap_copy::SetParametersComments() 
{
  return_comments="A copy of the bitmap.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmap::
      wrap_copy::CallMember( ParamList* p)
{
  // not a real copy ...
  return WrapClass_wxBitmap::CreateVar( new wxBitmap(*(_objectptr->_obj)));
}
