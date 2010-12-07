/**
 * C++ Interface: wrap_wxStatusBarBase
 *
 * Description: wrapping wxStatusBarBase
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
#include "wrap_wxString.h"


#include "wrap_wxStatusBarBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStatusBarBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStatusBarBase);
AMI_DEFINE_VARFROMSMTPTR(wxStatusBarBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStatusBarBase>::CreateVar( wxStatusBarBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStatusBarBase> obj_ptr(val,smartpointer_nodeleter<wxStatusBarBase>());
  return AMILabType<wxStatusBarBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStatusBarBase
//
Variable<AMIObject>::ptr WrapClass_wxStatusBarBase::CreateVar( wxStatusBarBase* sp)
{
  boost::shared_ptr<wxStatusBarBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxStatusBarBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStatusBarBase>::CreateVar(
      new WrapClass_wxStatusBarBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStatusBarBase::AddMethods(WrapClass<wxStatusBarBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_SetFieldsCount( this_ptr);
      AddVar_GetFieldsCount( this_ptr);
      AddVar_PushStatusText( this_ptr);
      AddVar_PopStatusText( this_ptr);
      AddVar_SetStatusWidths( this_ptr);
      AddVar_SetStatusStyles( this_ptr);
      AddVar_AcceptsFocus( this_ptr);



  

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
void WrapClass_wxStatusBarBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxStatusBarBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxStatusBarBase::SetFieldsCount(int number = 1, int const * widths = 0l)
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_SetFieldsCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:1)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widths' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_SetFieldsCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int number = 1;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > widths_smtptr;
  if (!get_val_smtptr_param<int >(widths_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* widths = widths_smtptr.get();

  this->_objectptr->GetObj()->SetFieldsCount(number, widths);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxStatusBarBase::GetFieldsCount()
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_GetFieldsCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_GetFieldsCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFieldsCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStatusBarBase::PushStatusText(wxString const & text, int number = 0)
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_PushStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_PushStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PushStatusText(text, number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBarBase::PopStatusText(int number = 0)
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_PopStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_PopStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PopStatusText(number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBarBase::SetStatusWidths(int n, int const * widths)
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_SetStatusWidths::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widths'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_SetStatusWidths::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > widths_smtptr;
  if (!get_val_smtptr_param<int >(widths_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* widths = widths_smtptr.get();

  this->_objectptr->GetObj()->SetStatusWidths(n, widths);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBarBase::SetStatusStyles(int n, int const * styles)
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_SetStatusStyles::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'styles'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_SetStatusStyles::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<int > styles_smtptr;
  if (!get_val_smtptr_param<int >(styles_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* styles = styles_smtptr.get();

  this->_objectptr->GetObj()->SetStatusStyles(n, styles);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxStatusBarBase::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxStatusBarBase::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBarBase::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

