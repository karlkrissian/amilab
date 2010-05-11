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

#include "wrap_wxImage.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxImage(  WrapClass_wxImage::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxImage");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddMethods(objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxImage( wxImage* si)
{
  // here wxImage can be deleted
  boost::shared_ptr<wxImage> si_ptr( si );

  WrapClass_wxImage::ptr sip(new WrapClass_wxImage(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxImage(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxImage( ParamList* p)
{
    char functionname[] = "wxImage";
    char description[]=" \n\
      Wrapped wxImage class. \n\
      See http://docs.wxwidgets.org/stable/wx_wximage.html for details \n\
            ";
    char parameters[] =" wrapped constructors: \n\
        - wxImage(): default constructor\n\
        - wxImage(const wxString& name, long type = wxBITMAP_TYPE_ANY, int index = -1)\n\
          name is given as a standard amilab string\n\
          index: Index of the image to load in the case that the image file contains multiple images. This is only used by GIF, ICO and TIFF handlers. The default value (-1) means 'choose the default image' and is interpreted as the first image (index=0) by the GIF and TIFF handler and as the largest and most colourful one by the ICO handler.";

  if (p->GetNumParam()==0) 
    return CreateVar_wxImage(new wxImage());

  if (p->GetNumParam()>=1) 
  {
    int n = 0;
    std::string* name=NULL;
    int type   = wxBITMAP_TYPE_ANY;
    int index  = -1;
  
    if (!get_val_ptr_param<string>(name,p,n)) HelpAndReturnVarPtr;
    get_int_param(type,  p, n,false);
    get_int_param(index, p, n,false);

    return CreateVar_wxImage(new wxImage( wxString(name->c_str(), wxConvUTF8),type,index));
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
