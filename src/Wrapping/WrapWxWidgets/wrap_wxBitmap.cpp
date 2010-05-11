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
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxBitmap(  WrapClass_wxBitmap::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxBitmap");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddMethods(objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxBitmap( wxBitmap* si)
{
  // here wxBitmap can be deleted
  boost::shared_ptr<wxBitmap> si_ptr( 
    si,
    wxwindow_nodeleter<wxBitmap>() // deletion will be done by wxwidgets
  );

  WrapClass_wxBitmap::ptr sip(new WrapClass_wxBitmap(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxBitmap(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxBitmap( ParamList* p)
{
    char functionname[] = "wxBitmap";
    char description[]=" \n\
      Wrapped wxBitmap class. \n\
      See http://docs.wxwidgets.org/stable/wx_wximage.html for details \n\
            ";
    char parameters[] =" wrapped constructors: \n\
        - wxBitmap(): default constructor\n\
        - wxBitmap(const wxImage& img, int depth = -1)\n\
            Creates bitmap object from the image. This has to be done to actually display an image as you cannot draw an image directly on a window. The resulting bitmap will use the provided colour depth (or that of the current system if depth is -1) which entails that a colour reduction has to take place.\n";

  if (p->GetNumParam()==0) 
    return CreateVar_wxBitmap(new wxBitmap());

  if (p->GetNumParam()>=1) 
  {
    int n = 0;
    int depth  = -1;
  
    GET_OBJECT_PARAM(wxImage,image,_obj);
    if (!image.get())  HelpAndReturnVarPtr;
    get_int_param(depth, p, n,false);

    if (image->IsOk()) {
      return CreateVar_wxBitmap(new wxBitmap( *image, depth));
    }
    else
      FILE_ERROR("Input wxImage is not valid.");
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
