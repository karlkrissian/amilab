/**
 * C++ Interface: wrap_vtkVolumeCollection
 *
 * Description: wrapping vtkVolumeCollection
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

#include "wrap_vtkVolumeCollection.h"

// get all the required includes
// #include "..."
#ifndef vtkVolumeCollection_declared
  #define vtkVolumeCollection_declared
  AMI_DECLARE_TYPE(vtkVolumeCollection)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkVolume_declared
  #define vtkVolume_declared
  AMI_DECLARE_TYPE(vtkVolume)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeCollection>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeCollection);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeCollection);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeCollection>::CreateVar( vtkVolumeCollection* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeCollection> obj_ptr(val,smartpointer_nodeleter<vtkVolumeCollection>());
  return AMILabType<vtkVolumeCollection>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeCollection
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeCollection::CreateVar( vtkVolumeCollection* sp)
{
  boost::shared_ptr<vtkVolumeCollection> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeCollection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeCollection>::CreateVar(
      new WrapClass_vtkVolumeCollection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeCollection::AddMethods(WrapClass<vtkVolumeCollection>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_AddItem( this_ptr);
  AddVar_GetNextVolume_1( this_ptr);
  AddVar_GetNextItem( this_ptr);
  AddVar_GetNextVolume( this_ptr);
/* The following types are missing: void
  AddVar_GetNextVolume_2( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkPropCollection
  boost::shared_ptr<vtkPropCollection > parent_vtkPropCollection(  boost::dynamic_pointer_cast<vtkPropCollection >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkPropCollection = AMILabType<vtkPropCollection >::CreateVarFromSmtPtr(parent_vtkPropCollection);
  context->AddVar("vtkPropCollection",var_vtkPropCollection);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkPropCollection = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkPropCollection);
  context->AddDefault(obj_vtkPropCollection->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeCollection_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeCollection");
  
  // Static methods 
  WrapClass_vtkVolumeCollection::AddVar_New(amiobject->GetContext());
  WrapClass_vtkVolumeCollection::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeCollection::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkVolumeCollection * vtkVolumeCollection::New()
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeCollection * res =   vtkVolumeCollection::New();
  BasicVariable::ptr res_var = AMILabType<vtkVolumeCollection >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeCollection::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeCollection::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeCollection * vtkVolumeCollection::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
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

  vtkVolumeCollection * res =   vtkVolumeCollection::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkVolumeCollection >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeCollection::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
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
//  Wrapping of vtkVolumeCollection * vtkVolumeCollection::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeCollection * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkVolumeCollection >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeCollection::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
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
//  Wrapping of void vtkVolumeCollection::AddItem(vtkVolume * a)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_AddItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_AddItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkVolume* a;
  if (CheckNullVar(_p,_n))  {
    a=(vtkVolume*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolume > a_smtptr;
    if (!get_val_smtptr_param<vtkVolume >(a_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    a = a_smtptr.get();
  }

  this->_objectptr->GetObj()->AddItem(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkVolume * vtkVolumeCollection::GetNextVolume()
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume_1::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkVolume * res =   this->_objectptr->GetObj()->GetNextVolume();
  BasicVariable::ptr res_var = AMILabType<vtkVolume >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkVolume * vtkVolumeCollection::GetNextItem()
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_GetNextItem::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_GetNextItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolume * res =   this->_objectptr->GetObj()->GetNextItem();
  BasicVariable::ptr res_var = AMILabType<vtkVolume >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkVolumeCollection::GetNextVolume(...)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeCollection::wrap_GetNextVolume_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of vtkVolume * vtkVolumeCollection::GetNextVolume(vtkCollectionSimpleIterator & cookie)
//---------------------------------------------------
void WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
  return_comments="returning a variable of type vtkVolume";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeCollection::
    wrap_GetNextVolume_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCollectionSimpleIterator & cookie = *cookie_smtptr;

  vtkVolume * res =   this->_objectptr->GetObj()->GetNextVolume(cookie);
  BasicVariable::ptr res_var = AMILabType<vtkVolume >::CreateVar(res,true);
  return res_var;
}
*/

