/**
 * C++ Interface: wrap_wxObjectEventFunction
 *
 * Description: wrapping wxObjectEventFunction
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


#include "wrap_wxObjectEventFunction.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxObjectEventFunction>::CreateVar( ParamList* p)
{
  // No variable creation for methodtype ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxObjectEventFunction);
AMI_DEFINE_VARFROMSMTPTR(wxObjectEventFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxObjectEventFunction>::CreateVar( wxObjectEventFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<wxObjectEventFunction> obj_ptr(val,smartpointer_nodeleter<wxObjectEventFunction>());
  return AMILabType<wxObjectEventFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxObjectEventFunction
//
Variable<AMIObject>::ptr WrapClass_wxObjectEventFunction::CreateVar( wxObjectEventFunction* sp)
{
  boost::shared_ptr<wxObjectEventFunction> di_ptr(
    sp,
    wxwindow_nodeleter<wxObjectEventFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObjectEventFunction>::CreateVar(
      new WrapClass_wxObjectEventFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxObjectEventFunction::AddMethods(WrapClass<wxObjectEventFunction>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  

  

  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxObjectEventFunction::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxObjectEventFunction");
  
  
  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


