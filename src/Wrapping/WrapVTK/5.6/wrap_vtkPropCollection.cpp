/**
 * C++ Interface: wrap_vtkPropCollection
 *
 * Description: wrapping vtkPropCollection
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
#include "wrap_vtkPropCollection.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkProp.h"


#include "wrap_vtkPropCollection.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkPropCollection>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkPropCollection);
AMI_DEFINE_VARFROMSMTPTR(vtkPropCollection);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkPropCollection>::CreateVar( vtkPropCollection* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkPropCollection> obj_ptr(val,smartpointer_nodeleter<vtkPropCollection>());
  return AMILabType<vtkPropCollection>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkPropCollection
//
Variable<AMIObject>::ptr WrapClass_vtkPropCollection::CreateVar( vtkPropCollection* sp)
{
  boost::shared_ptr<vtkPropCollection> di_ptr(
    sp,
    wxwindow_nodeleter<vtkPropCollection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkPropCollection>::CreateVar(
      new WrapClass_vtkPropCollection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkPropCollection::AddMethods(WrapClass<vtkPropCollection>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
  AddVar_AddItem( this_ptr);
  AddVar_GetNextProp_1( this_ptr);
  AddVar_GetLastProp( this_ptr);
  AddVar_GetNumberOfPaths( this_ptr);
  AddVar_GetNextProp( this_ptr);
/* The following types are missing: void
  AddVar_GetNextProp_2( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkCollection
  boost::shared_ptr<vtkCollection > parent_vtkCollection(  boost::dynamic_pointer_cast<vtkCollection >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkCollection = AMILabType<vtkCollection >::CreateVarFromSmtPtr(parent_vtkCollection);
  context->AddVar("vtkCollection",var_vtkCollection);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkCollection = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkCollection);
  context->AddDefault(obj_vtkCollection->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkPropCollection::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkPropCollection");
  
  // Static methods 
  WrapClass_vtkPropCollection::AddVar_New(amiobject->GetContext());
  WrapClass_vtkPropCollection::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkPropCollection::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkPropCollection::New()
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPropCollection * res =   vtkPropCollection::New();
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPropCollection::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkPropCollection::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkPropCollection::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObjectBase* o;
  if (CheckNullVar(_p,_n))  {
    o=(vtkObjectBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObjectBase > o_smtptr;
    if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }

  vtkPropCollection * res =   vtkPropCollection::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPropCollection::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkPropCollection * vtkPropCollection::NewInstance()
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkPropCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkPropCollection * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkPropCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkPropCollection::AddItem(vtkProp * a)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_AddItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProp, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_AddItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkProp* a;
  if (CheckNullVar(_p,_n))  {
    a=(vtkProp*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkProp > a_smtptr;
    if (!get_val_smtptr_param<vtkProp >(a_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    a = a_smtptr.get();
  }

  this->_objectptr->GetObj()->AddItem(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkProp * vtkPropCollection::GetNextProp()
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_GetNextProp_1::SetParametersComments()
{
  return_comments="returning a variable of type vtkProp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_GetNextProp_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkProp * res =   this->_objectptr->GetObj()->GetNextProp();
  BasicVariable::ptr res_var = WrapClass_vtkProp::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkProp * vtkPropCollection::GetLastProp()
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_GetLastProp::SetParametersComments()
{
  return_comments="returning a variable of type vtkProp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_GetLastProp::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkProp * res =   this->_objectptr->GetObj()->GetLastProp();
  BasicVariable::ptr res_var = WrapClass_vtkProp::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkPropCollection::GetNumberOfPaths()
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_GetNumberOfPaths::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_GetNumberOfPaths::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfPaths();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkPropCollection::GetNextProp(...)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_GetNextProp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_GetNextProp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkPropCollection::wrap_GetNextProp_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of vtkProp * vtkPropCollection::GetNextProp(vtkCollectionSimpleIterator & cookie)
//---------------------------------------------------
void WrapClass_vtkPropCollection::
    wrap_GetNextProp_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
  return_comments="returning a variable of type vtkProp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkPropCollection::
    wrap_GetNextProp_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCollectionSimpleIterator & cookie = *cookie_smtptr;

  vtkProp * res =   this->_objectptr->GetObj()->GetNextProp(cookie);
  BasicVariable::ptr res_var = WrapClass_vtkProp::CreateVar(res);
  return res_var;
}
*/

