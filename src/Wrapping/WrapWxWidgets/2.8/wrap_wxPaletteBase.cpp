/**
 * C++ Interface: wrap_wxPaletteBase
 *
 * Description: wrapping wxPaletteBase
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxPaletteBase.h"

// get all the required includes
// #include "..."
#ifndef wxPaletteBase_declared
  #define wxPaletteBase_declared
  AMI_DECLARE_TYPE(wxPaletteBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPaletteBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxPaletteBase);
AMI_DEFINE_VARFROMSMTPTR(wxPaletteBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPaletteBase
//
Variable<AMIObject>::ptr WrapClass_wxPaletteBase::CreateVar( wxPaletteBase* sp)
{
  boost::shared_ptr<wxPaletteBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxPaletteBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPaletteBase>::CreateVar(
      new WrapClass_wxPaletteBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPaletteBase::AddMethods(WrapClass<wxPaletteBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Ok( this_ptr);
  AddVar_GetColoursCount( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxGDIObject
  boost::shared_ptr<wxGDIObject > parent_wxGDIObject(  boost::dynamic_pointer_cast<wxGDIObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxGDIObject = AMILabType<wxGDIObject >::CreateVarFromSmtPtr(parent_wxGDIObject);
  context->AddVar("wxGDIObject",var_wxGDIObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxGDIObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxGDIObject);
  context->AddDefault(obj_wxGDIObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPaletteBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPaletteBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxPaletteBase::Ok()
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxPaletteBase::GetColoursCount()
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap_GetColoursCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap_GetColoursCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColoursCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPaletteBase & wxPaletteBase::operator =(wxPaletteBase const & param0)
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaletteBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxPaletteBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPaletteBase > param0_smtptr;
  if (!get_val_smtptr_param<wxPaletteBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPaletteBase const & param0 = *param0_smtptr;

  wxPaletteBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPaletteBase >::CreateVar(res);
}

