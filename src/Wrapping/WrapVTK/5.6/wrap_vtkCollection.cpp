/**
 * C++ Interface: wrap_vtkCollection
 *
 * Description: wrapping vtkCollection
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
#include "wrap_vtkCollection.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkObject.h"


#include "wrap_vtkCollection.h"

// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkCollection>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkCollection);
AMI_DEFINE_VARFROMSMTPTR(vtkCollection);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkCollection>::CreateVar( vtkCollection* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkCollection> obj_ptr(val,smartpointer_nodeleter<vtkCollection>());
  return AMILabType<vtkCollection>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkCollection
//
Variable<AMIObject>::ptr WrapClass_vtkCollection::CreateVar( vtkCollection* sp)
{
  boost::shared_ptr<vtkCollection> di_ptr(
    sp,
    wxwindow_nodeleter<vtkCollection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkCollection>::CreateVar(
      new WrapClass_vtkCollection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkCollection::AddMethods(WrapClass<vtkCollection>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_AddItem( this_ptr);
  AddVar_InsertItem( this_ptr);
  AddVar_ReplaceItem( this_ptr);
  AddVar_RemoveItem_1( this_ptr);
  AddVar_RemoveItem( this_ptr);
  AddVar_RemoveItem_2( this_ptr);
  AddVar_RemoveAllItems( this_ptr);
  AddVar_IsItemPresent( this_ptr);
  AddVar_GetNumberOfItems( this_ptr);
  AddVar_InitTraversal_1( this_ptr);
  AddVar_InitTraversal( this_ptr);
/* The following types are missing: void
  AddVar_InitTraversal_2( this_ptr);
*/
  AddVar_GetNextItemAsObject_1( this_ptr);
  AddVar_GetItemAsObject( this_ptr);
  AddVar_GetNextItemAsObject( this_ptr);
/* The following types are missing: void
  AddVar_GetNextItemAsObject_2( this_ptr);
*/
/* The following types are missing: vtkCollectionIterator
  AddVar_NewIterator( this_ptr);
*/
  AddVar_Register( this_ptr);
  AddVar_UnRegister( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkObject
  boost::shared_ptr<vtkObject > parent_vtkObject(  boost::dynamic_pointer_cast<vtkObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkObject = AMILabType<vtkObject >::CreateVarFromSmtPtr(parent_vtkObject);
  context->AddVar("vtkObject",var_vtkObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkObject);
  context->AddDefault(obj_vtkObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_vtkCollection::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkCollection");
  
  // Static methods 
  WrapClass_vtkCollection::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkCollection::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkCollection::AddVar_New(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkCollection::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkCollection::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkCollection * vtkCollection::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
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

  vtkCollection * res =   vtkCollection::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkCollection * vtkCollection::New()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCollection * res =   vtkCollection::New();
  BasicVariable::ptr res_var = WrapClass_vtkCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkCollection::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
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
//  Wrapping of vtkCollection * vtkCollection::NewInstance()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCollection * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkCollection::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkCollection::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<basic_ostream<char,std::char_traits<char> > > os_smtptr;
  if (!get_val_smtptr_param<basic_ostream<char,std::char_traits<char> > >(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!get_val_param<vtkIndent >(indent,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void vtkCollection::AddItem(vtkObject * param0)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_AddItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_AddItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObject* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObject > param0_smtptr;
    if (!get_val_smtptr_param<vtkObject >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->AddItem(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::InsertItem(int i, vtkObject * param1)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_InsertItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_InsertItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  vtkObject* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObject > param1_smtptr;
    if (!get_val_smtptr_param<vtkObject >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->InsertItem(i, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::ReplaceItem(int i, vtkObject * param1)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_ReplaceItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'param1'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_ReplaceItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  vtkObject* param1;
  if (CheckNullVar(_p,_n))  {
    param1=(vtkObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObject > param1_smtptr;
    if (!get_val_smtptr_param<vtkObject >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param1 = param1_smtptr.get();
  }

  this->_objectptr->GetObj()->ReplaceItem(i, param1);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::RemoveItem(int i)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_RemoveItem_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_RemoveItem_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->RemoveItem(i);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCollection::RemoveItem(...)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_RemoveItem::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_RemoveItem::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCollection::wrap_RemoveItem_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkCollection::wrap_RemoveItem_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::RemoveItem(vtkObject * param0)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_RemoveItem_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_RemoveItem_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  vtkObject* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(vtkObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObject > param0_smtptr;
    if (!get_val_smtptr_param<vtkObject >(param0_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveItem(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::RemoveAllItems()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_RemoveAllItems::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_RemoveAllItems::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RemoveAllItems();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkCollection::IsItemPresent(vtkObject * a)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_IsItemPresent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObject, "parameter named 'a'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_IsItemPresent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkObject* a;
  if (CheckNullVar(_p,_n))  {
    a=(vtkObject*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkObject > a_smtptr;
    if (!get_val_smtptr_param<vtkObject >(a_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    a = a_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->IsItemPresent(a);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int vtkCollection::GetNumberOfItems()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_GetNumberOfItems::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_GetNumberOfItems::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetNumberOfItems();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::InitTraversal()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_InitTraversal_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_InitTraversal_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->InitTraversal();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCollection::InitTraversal(...)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_InitTraversal::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_InitTraversal::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCollection::wrap_InitTraversal_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void vtkCollection::InitTraversal(vtkCollectionSimpleIterator & cookie)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_InitTraversal_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_InitTraversal_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCollectionSimpleIterator & cookie = *cookie_smtptr;

  this->_objectptr->GetObj()->InitTraversal(cookie);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of vtkObject * vtkCollection::GetNextItemAsObject()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_GetNextItemAsObject_1::SetParametersComments()
{
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_GetNextItemAsObject_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkObject * res =   this->_objectptr->GetObj()->GetNextItemAsObject();
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkObject * vtkCollection::GetItemAsObject(int i)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_GetItemAsObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_GetItemAsObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  vtkObject * res =   this->_objectptr->GetObj()->GetItemAsObject(i);
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkCollection::GetNextItemAsObject(...)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_GetNextItemAsObject::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_GetNextItemAsObject::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkCollection::wrap_GetNextItemAsObject_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of vtkObject * vtkCollection::GetNextItemAsObject(void * & cookie)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_GetNextItemAsObject_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
  return_comments="returning a variable of type vtkObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_GetNextItemAsObject_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  void * & cookie = cookie_smtptr.get();

  vtkObject * res =   this->_objectptr->GetObj()->GetNextItemAsObject(cookie);
  BasicVariable::ptr res_var = WrapClass_vtkObject::CreateVar(res);
  return res_var;
}
*/
/* The following types are missing: vtkCollectionIterator

//---------------------------------------------------
//  Wrapping of vtkCollectionIterator * vtkCollection::NewIterator()
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_NewIterator::SetParametersComments()
{
  return_comments="returning a variable of type vtkCollectionIterator";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_NewIterator::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkCollectionIterator * res =   this->_objectptr->GetObj()->NewIterator();
  return AMILabType<vtkCollectionIterator >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of void vtkCollection::Register(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_Register::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_Register::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->Register(o);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkCollection::UnRegister(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkCollection::
    wrap_UnRegister::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkCollection::
    wrap_UnRegister::CallMember( ParamList* _p)
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

  this->_objectptr->GetObj()->UnRegister(o);
  return BasicVariable::ptr();
}

