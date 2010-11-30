/**
 * C++ Interface: wrap_vtkActorCollection
 *
 * Description: wrapping vtkActorCollection
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
#include "wrap_vtkActorCollection.h"
#include "wrap_vtkObjectBase.h"
#include "wrap_vtkIndent.h"
#include "wrap_vtkActor.h"
#include "wrap_vtkProperty.h"


#include "wrap_vtkActorCollection.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkActorCollection>::CreateVar( ParamList* p)
{
  WrapClass_vtkActorCollection::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkActorCollection);
AMI_DEFINE_VARFROMSMTPTR(vtkActorCollection);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkActorCollection>::CreateVar( vtkActorCollection* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkActorCollection> obj_ptr(val,smartpointer_nodeleter<vtkActorCollection>());
  return AMILabType<vtkActorCollection>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkActorCollection
//
Variable<AMIObject>::ptr WrapClass_vtkActorCollection::CreateVar( vtkActorCollection* sp)
{
  boost::shared_ptr<vtkActorCollection> di_ptr(
    sp,
    wxwindow_nodeleter<vtkActorCollection>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkActorCollection>::CreateVar(
      new WrapClass_vtkActorCollection(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkActorCollection::AddMethods(WrapClass<vtkActorCollection>::ptr this_ptr )
{
  
      // Add members from vtkPropCollection
      WrapClass_vtkPropCollection::ptr parent_vtkPropCollection(        boost::dynamic_pointer_cast<WrapClass_vtkPropCollection >(this_ptr));
      parent_vtkPropCollection->AddMethods(parent_vtkPropCollection);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsA( this_ptr);
      AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
      AddVar_PrintSelf( this_ptr);
*/
      AddVar_AddItem( this_ptr);
      AddVar_GetNextActor_1( this_ptr);
      AddVar_GetLastActor( this_ptr);
      AddVar_GetNextItem( this_ptr);
      AddVar_GetLastItem( this_ptr);
      AddVar_ApplyProperties( this_ptr);
      AddVar_GetNextActor( this_ptr);
/* The following types are missing: void
      AddVar_GetNextActor_2( this_ptr);
*/



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkActorCollection * vtkActorCollection::New()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkActorCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActorCollection * res =   vtkActorCollection::New();
  BasicVariable::ptr res_var = WrapClass_vtkActorCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkActorCollection::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkActorCollection::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkActorCollection * vtkActorCollection::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkActorCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_static_SafeDownCast::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkObjectBase > o_smtptr;
  if (!get_val_smtptr_param<vtkObjectBase >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkObjectBase* o = o_smtptr.get();

  vtkActorCollection * res =   vtkActorCollection::SafeDownCast(o);
  BasicVariable::ptr res_var = WrapClass_vtkActorCollection::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkActorCollection::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
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
//  Wrapping of vtkActorCollection * vtkActorCollection::NewInstance()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkActorCollection";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActorCollection * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = WrapClass_vtkActorCollection::CreateVar(res);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkActorCollection::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
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
//  Wrapping of void vtkActorCollection::AddItem(vtkActor * a)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_AddItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkActor, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_AddItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkActor > a_smtptr;
  if (!get_val_smtptr_param<vtkActor >(a_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkActor* a = a_smtptr.get();

  this->_objectptr->GetObj()->AddItem(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActorCollection::GetNextActor()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetNextActor_1::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetNextActor_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkActor * res =   this->_objectptr->GetObj()->GetNextActor();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActorCollection::GetLastActor()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetLastActor::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetLastActor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   this->_objectptr->GetObj()->GetLastActor();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActorCollection::GetNextItem()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetNextItem::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetNextItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   this->_objectptr->GetObj()->GetNextItem();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActorCollection::GetLastItem()
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetLastItem::SetParametersComments()
{
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetLastItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkActor * res =   this->_objectptr->GetObj()->GetLastItem();
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkActorCollection::ApplyProperties(vtkProperty * p)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_ApplyProperties::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkProperty, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_ApplyProperties::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkProperty > p_smtptr;
  if (!get_val_smtptr_param<vtkProperty >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkProperty* p = p_smtptr.get();

  this->_objectptr->GetObj()->ApplyProperties(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... vtkActorCollection::GetNextActor(...)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetNextActor::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetNextActor::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkActorCollection::wrap_GetNextActor_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of vtkActor * vtkActorCollection::GetNextActor(vtkCollectionSimpleIterator & cookie)
//---------------------------------------------------
void WrapClass_vtkActorCollection::
    wrap_GetNextActor_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'cookie'")
  return_comments="returning a variable of type vtkActor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkActorCollection::
    wrap_GetNextActor_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<void > cookie_smtptr;
  if (!get_val_smtptr_param<void >(cookie_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  vtkCollectionSimpleIterator & cookie = *cookie_smtptr;

  vtkActor * res =   this->_objectptr->GetObj()->GetNextActor(cookie);
  BasicVariable::ptr res_var = WrapClass_vtkActor::CreateVar(res);
  return res_var;
}
*/

