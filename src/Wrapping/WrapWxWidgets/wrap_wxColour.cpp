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

#include "wrap_wxColour.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxColour(  WrapClass_wxColour::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxColour");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddMethods(objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxColour( wxColour* si)
{
  // here wxColour can be deleted
  boost::shared_ptr<wxColour> si_ptr( si );

  WrapClass_wxColour::ptr sip(new WrapClass_wxColour(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxColour(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxColour( ParamList* p)
{
    char functionname[] = "wxColour";
    char description[]=" \n\
      Wrapped wxWindow class. \n\
See http://docs.wxwidgets.org/stable/wx_wxcolour.html for details \n\
            ";
    char parameters[] =" wrapped constructors: \n\
        - wxColour(): default constructor\n\
        - wxColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha=wxALPHA_OPAQUE) \n";


  if (!p) HelpAndReturnVarPtr;
  if (p->GetNumParam()==0) 
    return CreateVar_wxColour(new wxColour());

  if (p->GetNumParam()>=3) 
  {
    int n = 0;
    int red   = 0;
    int green = 0;
    int blue  = 0;
    int alpha = wxALPHA_OPAQUE;
  
    if (!get_int_param(red, p, n))   HelpAndReturnVarPtr;
    if (!get_int_param(green, p, n)) HelpAndReturnVarPtr;
    if (!get_int_param(blue, p, n))  HelpAndReturnVarPtr;
    get_int_param(alpha, p, n,false);

    return CreateVar_wxColour(new wxColour( 
      (unsigned char)red,
      (unsigned char)green,
      (unsigned char)blue,
      (unsigned char)alpha));
  } else
    HelpAndReturnVarPtr;
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
  return CreateVar_wxColour( new wxColour(*(_objectptr->_obj)));
}

