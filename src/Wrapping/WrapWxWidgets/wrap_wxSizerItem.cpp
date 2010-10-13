//
// C++ Implementation: wrap_wxSizerItem
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifdef _AMIPREC_
  #include "WrapWxWidgets_header.h"
#endif

#include "wrap_wxSizerItem.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxSize.h"

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSizerItem>::CreateVar( ParamList* p)
{
  WrapClass_wxSizerItem::wrap_wxSizerItem construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxSizerItem);

//
// static member for creating a variable from a pointer to dwControlPoint
//
Variable<AMIObject>::ptr WrapClass_wxSizerItem::CreateVar( wxSizerItem* sp)
{
  return 
    WrapClass<wxSizerItem>::CreateVar(
      new WrapClass_wxSizerItem(
        boost::shared_ptr<wxSizerItem>(sp,
          // deletion will be done by wxwidgets
          wxwindow_nodeleter<wxSizerItem>() 
)));
}



//---------------------------------------------------
// Method that adds wrapping of wxSizerItem
//---------------------------------------------------

void  WrapClass_wxSizerItem::
      wrap_wxSizerItem::SetParametersComments() 
{
  return_comments = "not implemented.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
      wrap_wxSizerItem::CallMember( ParamList* p)
{
  // Not implemented ... TODO
  return BasicVariable::ptr();
}



//---------------------------------------------------
//  GetMinSize
//---------------------------------------------------
void WrapClass_wxSizerItem::
      wrap_GetMinSize::SetParametersComments() 
{
  return_comments="value of the minimal size (wxSize object)";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
      wrap_GetMinSize::CallMember( ParamList* p)
{
  wxSize minsize = this->_objectptr->GetObj()->GetMinSize();
  return CreateVar_wxSize(new wxSize(minsize));
}

//---------------------------------------------------
//  SetProportion
//---------------------------------------------------
void WrapClass_wxSizerItem::
      wrap_SetProportion::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: proportion item attribute.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
      wrap_SetProportion::CallMember( ParamList* p)
{
  int prop;
  int n = 0;

  if (!get_int_param(prop, p, n)) ClassHelpAndReturn;
  this->_objectptr->GetObj()->SetProportion(prop);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetDimension
//---------------------------------------------------
void WrapClass_wxSizerItem::
      wrap_SetDimension::SetParametersComments() 
{
  ADDPARAMCOMMENT("integer: x");
  ADDPARAMCOMMENT("integer: y");
  ADDPARAMCOMMENT("integer: width");
  ADDPARAMCOMMENT("integer: height");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerItem::
      wrap_SetDimension::CallMember( ParamList* p)
{
  int x;
  int y;
  int width;
  int height;
  int n = 0;

  if (!get_int_param(x, p, n)) ClassHelpAndReturn;
  if (!get_int_param(y, p, n)) ClassHelpAndReturn;
  if (!get_int_param(width, p, n)) ClassHelpAndReturn;
  if (!get_int_param(height, p, n)) ClassHelpAndReturn;
  this->_objectptr->
    GetObj()->SetDimension(wxPoint(x,y),wxSize(width,height));

  return BasicVariable::ptr();
}
