/**
 * C++ Interface: wrap_wxStaticBoxBase
 *
 * Description: wrapping wxStaticBoxBase
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


#include "wrap_wxStaticBoxBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStaticBoxBase>::CreateVar( ParamList* p)
{
  WrapClass_wxStaticBoxBase::wrap_wxStaticBoxBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStaticBoxBase);
AMI_DEFINE_VARFROMSMTPTR(wxStaticBoxBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStaticBoxBase>::CreateVar( wxStaticBoxBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStaticBoxBase> obj_ptr(val,smartpointer_nodeleter<wxStaticBoxBase>());
  return AMILabType<wxStaticBoxBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStaticBoxBase
//
Variable<AMIObject>::ptr WrapClass_wxStaticBoxBase::CreateVar( wxStaticBoxBase* sp)
{
  boost::shared_ptr<wxStaticBoxBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxStaticBoxBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStaticBoxBase>::CreateVar(
      new WrapClass_wxStaticBoxBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStaticBoxBase::AddMethods(WrapClass<wxStaticBoxBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_AcceptsFocus( this_ptr);
      AddVar_HasTransparentBackground( this_ptr);
      AddVar_GetBordersForSizer( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxControl
  boost::shared_ptr<wxControl > parent_wxControl(  boost::dynamic_pointer_cast<wxControl >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxControl = AMILabType<wxControl >::CreateVarFromSmtPtr(parent_wxControl);
  context->AddVar("wxControl",var_wxControl);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxControl = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxControl);
  context->AddDefault(obj_wxControl->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxStaticBoxBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxStaticBoxBase");
    WrapClass_wxStaticBoxBase::AddVar_wxStaticBoxBase(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStaticBoxBase::wxStaticBoxBase()
//---------------------------------------------------
void WrapClass_wxStaticBoxBase::
    wrap_wxStaticBoxBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxBase::
    wrap_wxStaticBoxBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStaticBoxBase* _newobj = new wxStaticBoxBase();
  BasicVariable::ptr res = WrapClass_wxStaticBoxBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBoxBase::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxStaticBoxBase::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxBase::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBoxBase::HasTransparentBackground()
//---------------------------------------------------
void WrapClass_wxStaticBoxBase::
    wrap_HasTransparentBackground::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxBase::
    wrap_HasTransparentBackground::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HasTransparentBackground();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStaticBoxBase::GetBordersForSizer(int * borderTop, int * borderOther)
//---------------------------------------------------
void WrapClass_wxStaticBoxBase::
    wrap_GetBordersForSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'borderTop'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'borderOther'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxBase::
    wrap_GetBordersForSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > borderTop_smtptr;
  if (!get_val_smtptr_param<int >(borderTop_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* borderTop = borderTop_smtptr.get();

  boost::shared_ptr<int > borderOther_smtptr;
  if (!get_val_smtptr_param<int >(borderOther_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* borderOther = borderOther_smtptr.get();

  this->_objectptr->GetObj()->GetBordersForSizer(borderTop, borderOther);
  return BasicVariable::ptr();
}

