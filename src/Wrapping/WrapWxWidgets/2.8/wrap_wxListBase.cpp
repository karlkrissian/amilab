/**
 * C++ Interface: wrap_wxListBase
 *
 * Description: wrapping wxListBase
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

#include "wrap_wxListBase.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxListBase_declared
  #define wxListBase_declared
  AMI_DECLARE_TYPE(wxListBase)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxListBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxListBase);
AMI_DEFINE_VARFROMSMTPTR(wxListBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxListBase
//
Variable<AMIObject>::ptr WrapClass_wxListBase::CreateVar( wxListBase* sp)
{
  boost::shared_ptr<wxListBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxListBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxListBase>::CreateVar(
      new WrapClass_wxListBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxListBase::AddMethods(WrapClass<wxListBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetCount( this_ptr);
  AddVar_IsEmpty( this_ptr);
  AddVar_Clear( this_ptr);
  AddVar_DeleteContents( this_ptr);
  AddVar_GetDeleteContents( this_ptr);
  AddVar_GetKeyType( this_ptr);
  AddVar_SetKeyType( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxListBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxListBase");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of size_t wxListBase::GetCount()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetCount::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  size_t res =   this->_objectptr->GetObj()->GetCount();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxListBase::IsEmpty()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_IsEmpty::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_IsEmpty::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsEmpty();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxListBase::Clear()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_Clear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_Clear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Clear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxListBase::DeleteContents(bool destroy)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_DeleteContents::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'destroy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_DeleteContents::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool destroy;
  if (!get_val_param<bool >(destroy,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DeleteContents(destroy);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxListBase::GetDeleteContents()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetDeleteContents::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetDeleteContents::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->GetDeleteContents();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxKeyType wxListBase::GetKeyType()
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_GetKeyType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_GetKeyType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxKeyType res =   this->_objectptr->GetObj()->GetKeyType();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxListBase::SetKeyType(wxKeyType keyType)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap_SetKeyType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyType'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap_SetKeyType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int keyType_int;
  if (!get_val_param<int >(keyType_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxKeyType keyType = (wxKeyType) keyType_int;

  this->_objectptr->GetObj()->SetKeyType(keyType);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxListBase & wxListBase::operator =(wxListBase const & param0)
//---------------------------------------------------
void WrapClass_wxListBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxListBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxListBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxListBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxListBase > param0_smtptr;
  if (!get_val_smtptr_param<wxListBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxListBase const & param0 = *param0_smtptr;

  wxListBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxListBase >::CreateVar(res);
}

