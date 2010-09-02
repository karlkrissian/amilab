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

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<FenetreDessin>::CreateVar( ParamList* p)
{
  WrapClass_FenetreDessin::wrap_FenetreDessin construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE(FenetreDessin);

//
// static member for creating a variable from a pointer to wxHtmlWindow
//
Variable<AMIObject>::ptr WrapClass_FenetreDessin::CreateVar( FenetreDessin* sp)
{
  return 
    WrapClass<FenetreDessin>::CreateVar(
      new WrapClass_FenetreDessin(
        boost::shared_ptr<FenetreDessin>(sp,
        wxwindow_nodeleter<FenetreDessin>() 
        // deletion will be done by wxwidgets
        ))
    );
}



//---------------------------------------------------
//  FenetreDessin Constructor
//---------------------------------------------------
void  WrapClass_FenetreDessin::
      wrap_FenetreDessin::SetParametersComments() 
{
  ADDPARAMCOMMENT("Object of a type that inherit from FenetreDessin.");
  return_comments = "A wrapped FenetreDessin object.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_FenetreDessin::
      wrap_FenetreDessin::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM2(FenetreDessin,var,varobj);
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

