//
// C++ Implementation: wrap_wxColour
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

#include "wrap_wxColour.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunction_class.h"
#include "ami_object.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxColour>::CreateVar( ParamList* p)
{
  WrapClass_wxColour::wrap_wxColour construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxColour);
AMI_DEFINE_VARFROMSMTPTR(wxColour);

/*
//
// static member for creating a variable from a pointer to wxColour
//
Variable<AMIObject>::ptr WrapClass_wxColour::CreateVar( wxColour* sp)
{
  boost::shared_ptr<wxColour> _obj_ptr(sp);
  return 
    WrapClass<wxColour>::CreateVar(
      new WrapClass_wxColour(_obj_ptr));
}
*/

//---------------------------------------------------
// Method that adds wrapping of wxColour
//---------------------------------------------------

void  WrapClass_wxColour::
    wrap_wxColour::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(unsigned char,"Red Component (0-255) (MODE 1)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Green Component (0-255) (MODE 1)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Blue Component (0-255) (MODE 1)");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Alpha Component (By default, wxALPHA_OPAQUE) (MODE 1)");
  return_comments = "A wrapped wxColour object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
    wrap_wxColour::CallMember( ParamList* p)
{
  int n=0;

  if (!p) ClassHelpAndReturn;
  if (p->GetNumParam()==0) 
    return AMILabType<wxColour>::CreateVar(new wxColour());

  if (p->GetNumParam()>=3) 
  {
    n = 0;

    GET_PARAM(unsigned char,red,0);
    GET_PARAM(unsigned char,green,0);
    GET_PARAM(unsigned char,blue,0);
    GET_PARAM(unsigned char,alpha,wxALPHA_OPAQUE);

    return AMILabType<wxColour>::CreateVar(new wxColour(
      (unsigned char)red,
      (unsigned char)green,
      (unsigned char)blue,
      (unsigned char)alpha));
  }
  else
    ClassHelpAndReturn;
}

//---------------------------------------------------
//  Alpha
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_Alpha::SetParametersComments() 
{
  return_comments="Alpha value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_Alpha::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->Alpha();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Blue
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_Blue::SetParametersComments() 
{
  return_comments="Blue value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_Blue::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->Blue();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  GetAsString
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_GetAsString::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_GetAsString::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  GetPixel
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_GetPixel::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_GetPixel::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Green
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_Green::SetParametersComments() 
{
  return_comments="Green value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_Green::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->Green();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  IsOk
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_IsOk::SetParametersComments() 
{}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_IsOk::CallMember( ParamList* p)
{
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Red
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_Red::SetParametersComments() 
{
  return_comments="Red value.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_Red::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->Red();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Set
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_Set::SetParametersComments() 
{
  ADDPARAMCOMMENT("red (if number of param>=3)");
  ADDPARAMCOMMENT("green (if number of param>=3)");
  ADDPARAMCOMMENT("blue (if number of param>=3)");
  ADDPARAMCOMMENT("alpha (if number of param>=3)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_Set::CallMember( ParamList* p)
{
  if (p->GetNumParam()>=3) 
  {
    int n = 0;
    int red   = 0;
    int green = 0;
    int blue  = 0;
    int alpha = wxALPHA_OPAQUE;
  
    if (!get_int_param(red, p, n))   ClassHelpAndReturn;
    if (!get_int_param(green, p, n)) ClassHelpAndReturn;
    if (!get_int_param(blue, p, n))  ClassHelpAndReturn;
    get_int_param(alpha, p, n,false);

    this->_objectptr->_obj->Set( 
      (unsigned char)red,
      (unsigned char)green,
      (unsigned char)blue,
      (unsigned char)alpha);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_copy::SetParametersComments() 
{
  return_comments = "Copy of the colour within a new variable.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_copy::CallMember( ParamList* p)
{
  return AMILabType<wxColour>::CreateVar( new wxColour(*(_objectptr->_obj)));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_wxColour::
      wrap_assign::SetParametersComments() 
{
  return_comments = "wxColour assignment operation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxColour::
      wrap_assign::CallMember( ParamList* p)
{
  int n = 0;
  CLASS_GET_OBJECT_PARAM(wxColour,var,_obj);

  if (_obj.get()) {
    this->_objectptr->_obj = _obj;
  }
  return BasicVariable::ptr();
}

