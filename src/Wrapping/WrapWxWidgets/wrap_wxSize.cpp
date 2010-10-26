//
// C++ Implementation: wrap_wxSize
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

#include "wrap_wxSize.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxSize(  WrapClass_wxSize::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxSize");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_GetWidth(       objectptr);
  objectptr->AddVar_GetHeight(      objectptr);
  objectptr->AddVar_Set(            objectptr);
  objectptr->AddVar_SetWidth(       objectptr);
  objectptr->AddVar_SetHeight(      objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxSize( wxSize* si)
{
  // here wxSize can be deleted
  boost::shared_ptr<wxSize> _si_ptr( si );

  WrapClass_wxSize::ptr sip(new WrapClass_wxSize(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxSize(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  wxSize Constructor
//---------------------------------------------------
void  wrap_wxSize::SetParametersComments() 
{
  ADDPARAMCOMMENT("width (def:-1)");
  ADDPARAMCOMMENT("height (def:-1)");
  return_comments = "A wrapped wxSize object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_wxSize::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  if (p->GetNumParam()==0) 
    return CreateVar_wxSize(new wxSize());

  int n = 0;
  int width = -1;
  int height = -1;
  if (!get_int_param(width, p, n))  ClassHelpAndReturn;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;
  return CreateVar_wxSize(new wxSize( width,height));
}

//---------------------------------------------------
//  GetWidth
//---------------------------------------------------
void WrapClass_wxSize::
      wrap_GetWidth::SetParametersComments() 
{
  return_comments = "integer: width";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
      wrap_GetWidth::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetWidth();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  GetHeight
//---------------------------------------------------
void WrapClass_wxSize::
      wrap_GetHeight::SetParametersComments() 
{
  return_comments = "integer: height";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
      wrap_GetHeight::CallMember( ParamList* p)
{
  int res = this->_objectptr->_obj->GetHeight();
  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Set
//---------------------------------------------------
void WrapClass_wxSize::
      wrap_Set::SetParametersComments() 
{
  ADDPARAMCOMMENT("width (def:-1)");
  ADDPARAMCOMMENT("height (def:-1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
      wrap_Set::CallMember( ParamList* p)
{
  int width=-1;
  int height=-1;
  int n = 0;
  if (!get_int_param(width, p, n)) ClassHelpAndReturn;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->Set(width,height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetWidth
//---------------------------------------------------
void WrapClass_wxSize::
      wrap_SetWidth::SetParametersComments() 
{
  ADDPARAMCOMMENT("width (def:-1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
      wrap_SetWidth::CallMember( ParamList* p)
{
  int width=-1;
  int n = 0;
  if (!get_int_param(width, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetWidth(width);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetHeigth
//---------------------------------------------------
void WrapClass_wxSize::
      wrap_SetHeight::SetParametersComments() 
{
  ADDPARAMCOMMENT("height (def:-1)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSize::
      wrap_SetHeight::CallMember( ParamList* p)
{
  int height=-1;
  int n = 0;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;
  this->_objectptr->_obj->SetHeight(height);
  return BasicVariable::ptr();
}
