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

#include "wrap_wxSizerItem.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
#include "wrap_wxSize.h"

AMI_DEFINE_WRAPPEDTYPE(wxSizerItem)


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxSizerItem(  WrapClass_wxSizerItem::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("SizerItem");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_GetMinSize(          objectptr);
  objectptr->AddVar_SetProportion(       objectptr);
  objectptr->AddVar_SetDimension(        objectptr);

  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxSizerItem( wxSizerItem* si)
{

  boost::shared_ptr<wxSizerItem> _si_ptr( si,
      // deletion will be done by wxwidgets
      wxwindow_nodeleter<wxSizerItem>() 
    );

  WrapClass_wxSizerItem::ptr sip(new WrapClass_wxSizerItem(_si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxSizerItem(sip));

  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

/*
//---------------------------------------------------
BasicVariable::ptr wrap_wxSizerItem( ParamList* p)
{
    char functionname[] = "wxSizerItem";
    char description[]=" \n\
      Wrapped wxWindow class. \n\
            ";
    char parameters[] =" \n\
      - different constructors \n\
            ";

  int n = 0;
  std::string* title = NULL;

  Variable<AMIObject>::ptr var;
  wxWindow* parent = NULL;

  if (get_var_param<AMIObject>(var, p, n)) 
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_wxSizerItem::ptr obj( boost::dynamic_pointer_cast<WrapClass_wxSizerItem>(object));
    if (obj.get()) {
      parent = obj->_win.get();
    } else {
      FILE_ERROR("Could not cast dynamically the variable to wxWindow.")
      HelpAndReturnVarPtr;
    }
  }  else {
    FILE_ERROR("Need a wrapped wxWindow object as parameter.")
    HelpAndReturnVarPtr;
  }

  return CreateVar_wxSizerItem(new wxSizerItem( parent, wxID_ANY));
}
*/

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
  wxSize minsize = this->_objectptr->_sizeritem->GetMinSize();
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
  this->_objectptr->_sizeritem->SetProportion(prop);

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
    _sizeritem->SetDimension(wxPoint(x,y),wxSize(width,height));

  return BasicVariable::ptr();
}
