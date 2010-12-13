/**
 * C++ Interface: wrap_wxCommandEventFunction
 *
 * Description: wrapping wxCommandEventFunction
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

#include "wrap_wxCommandEventFunction.h"

// get all the required includes
// #include "..."



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxCommandEventFunction>::CreateVar( ParamList* p)
{
  // No variable creation for methodtype ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxCommandEventFunction);
AMI_DEFINE_VARFROMSMTPTR(wxCommandEventFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxCommandEventFunction>::CreateVar( wxCommandEventFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<wxCommandEventFunction> obj_ptr(val,smartpointer_nodeleter<wxCommandEventFunction>());
  return AMILabType<wxCommandEventFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxCommandEventFunction
//
Variable<AMIObject>::ptr WrapClass_wxCommandEventFunction::CreateVar( wxCommandEventFunction* sp)
{
  boost::shared_ptr<wxCommandEventFunction> di_ptr(
    sp,
    wxwindow_nodeleter<wxCommandEventFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxCommandEventFunction>::CreateVar(
      new WrapClass_wxCommandEventFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxCommandEventFunction::AddMethods(WrapClass<wxCommandEventFunction>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  

  

  

  
};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxCommandEventFunction_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxCommandEventFunction");
  
  
  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


