//
// C++ Implementation: wrap_FenetreDessin
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_FenetreDessin.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "FenetreDessin.hpp"
#include "wrap_wxColour.h"
#include <boost/shared_ptr.hpp>


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_FenetreDessin(  WrapClass_FenetreDessin::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("FenetreDessin");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_FenetreDessin( FenetreDessin* si)
{
  // here FenetreDessin can be deleted
  boost::shared_ptr<FenetreDessin> _si_ptr( si );
  WrapClass_FenetreDessin::ptr sip(new WrapClass_FenetreDessin(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_FenetreDessin(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
//  FenetreDessin Constructor
//---------------------------------------------------
void  wrap_FenetreDessin::SetParametersComments() 
{
  ADDPARAMCOMMENT("Object of a type that inherit from FenetreDessin.");
  return_comments = "A wrapped FenetreDessin object.";
}
//---------------------------------------------------
BasicVariable::ptr wrap_FenetreDessin::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(FenetreDessin,var,varobj);
  return var;
}

//---------------------------------------------------
//  DrawingAreaDisplay
//---------------------------------------------------
void WrapClass_FenetreDessin::
      wrap_DrawingAreaDisplay::SetParametersComments() 
{ }

//---------------------------------------------------
BasicVariable::ptr WrapClass_FenetreDessin::
      wrap_DrawingAreaDisplay::CallMember( ParamList* p)
{
  FenetreDessin::ptr fd(this->_objectptr->GetObj());
  fd->DrawingAreaDisplay();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetPenColor
//---------------------------------------------------
void WrapClass_FenetreDessin::
      wrap_SetPenColor::SetParametersComments() 
{ 
  ADDPARAMCOMMENT("wxColour object: input color.");
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_FenetreDessin::
      wrap_SetPenColor::CallMember( ParamList* p)
{
  FenetreDessin::ptr fd(this->_objectptr->GetObj());
  int n=0;
  CLASS_GET_OBJECT_PARAM2(wxColour,var,varobj);
  if (varobj.get()) {
    fd->SetPenColor( *varobj);
  }
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetLineParameters
//---------------------------------------------------
void WrapClass_FenetreDessin::
      wrap_SetLineParameters::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int, " thickness (def:1): line thickness.");
  ADDPARAMCOMMENT_TYPE(int, " style (def:0): line style, 0 for SOLID, 1 for DOT.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_FenetreDessin::
      wrap_SetLineParameters::CallMember( ParamList* p)
{
  FenetreDessin::ptr fd(this->_objectptr->GetObj());

  int thickness = 1;
  int style = 0;
  int n=0;

  if (!get_val_param<int>( thickness, p, n)) ClassHelpAndReturn;
  if (!get_val_param<int>( style, p, n))     ClassHelpAndReturn;

  int wxstyle;
  switch (style) {
    case 0: wxstyle = wxSOLID; break;
    case 1: wxstyle = wxDOT; break;
    default: wxstyle = wxSOLID;
  }
  fd->SetLineParameters( thickness, wxstyle, wxCAP_ROUND, wxJOIN_MITER);
  return BasicVariable::ptr();
}

