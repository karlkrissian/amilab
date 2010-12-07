/**
 * C++ Interface: wrap_wxControlBase
 *
 * Description: wrapping wxControlBase
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxWindow.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxValidator.h"
#include "wrap_wxString.h"
#include "wrap_wxCommandEvent.h"
#include "wrap_wxFont.h"
#include "wrap_wxUpdateUIEvent.h"


#include "wrap_wxControlBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxControlBase>::CreateVar( ParamList* p)
{
  WrapClass_wxControlBase::wrap_wxControlBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxControlBase);
AMI_DEFINE_VARFROMSMTPTR(wxControlBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxControlBase>::CreateVar( wxControlBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxControlBase> obj_ptr(val,smartpointer_nodeleter<wxControlBase>());
  return AMILabType<wxControlBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxControlBase
//
Variable<AMIObject>::ptr WrapClass_wxControlBase::CreateVar( wxControlBase* sp)
{
  boost::shared_ptr<wxControlBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxControlBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxControlBase>::CreateVar(
      new WrapClass_wxControlBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxControlBase::AddMethods(WrapClass<wxControlBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_GetAlignment( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
      AddVar_Command( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_SetFont( this_ptr);
      AddVar_DoUpdateWindowUI( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxWindow
  boost::shared_ptr<wxWindow > parent_wxWindow(  boost::dynamic_pointer_cast<wxWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxWindow = AMILabType<wxWindow >::CreateVarFromSmtPtr(parent_wxWindow);
  context->AddVar("wxWindow",var_wxWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWindow);
  context->AddDefault(obj_wxWindow->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxControlBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxControlBase");
    WrapClass_wxControlBase::AddVar_wxControlBase(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxControlBase::wxControlBase()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_wxControlBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_wxControlBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxControlBase* _newobj = new wxControlBase();
  BasicVariable::ptr res = WrapClass_wxControlBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxControlBase::Create(wxWindow * parent, wxWindowID id, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxControlNameStr)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxControlNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxControlNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, validator, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxControlBase::GetAlignment()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_GetAlignment::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_GetAlignment::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlignment();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxControlBase::ShouldInheritColours()
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_ShouldInheritColours::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_ShouldInheritColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldInheritColours();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxControlBase::Command(wxCommandEvent & event)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_Command::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxCommandEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_Command::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxCommandEvent > event_smtptr;
  if (!get_val_smtptr_param<wxCommandEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxCommandEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->Command(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxControlBase::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxControlBase::SetFont(wxFont const & font)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_SetFont::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFont, "parameter named 'font'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_SetFont::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFont > font_smtptr;
  if (!get_val_smtptr_param<wxFont >(font_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFont const & font = *font_smtptr;

  bool res =   this->_objectptr->GetObj()->SetFont(font);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxControlBase::DoUpdateWindowUI(wxUpdateUIEvent & event)
//---------------------------------------------------
void WrapClass_wxControlBase::
    wrap_DoUpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxUpdateUIEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxControlBase::
    wrap_DoUpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxUpdateUIEvent > event_smtptr;
  if (!get_val_smtptr_param<wxUpdateUIEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxUpdateUIEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->DoUpdateWindowUI(event);
  return BasicVariable::ptr();
}

