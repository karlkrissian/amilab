/**
 * C++ Interface: wrap_vtkInteractorStyleTrackball
 *
 * Description: wrapping vtkInteractorStyleTrackball
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

#include "wrap_vtkInteractorStyleTrackball.h"

// get all the required includes
// #include "..."
#ifndef vtkInteractorStyleTrackball_declared
  #define vtkInteractorStyleTrackball_declared
  AMI_DECLARE_TYPE(vtkInteractorStyleTrackball)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkInteractorStyleTrackball>::CreateVar( ParamList* p)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkInteractorStyleTrackball);
AMI_DEFINE_VARFROMSMTPTR(vtkInteractorStyleTrackball);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkInteractorStyleTrackball>::CreateVar( vtkInteractorStyleTrackball* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkInteractorStyleTrackball> obj_ptr(val,smartpointer_nodeleter<vtkInteractorStyleTrackball>());
  return AMILabType<vtkInteractorStyleTrackball>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkInteractorStyleTrackball
//
Variable<AMIObject>::ptr WrapClass_vtkInteractorStyleTrackball::CreateVar( vtkInteractorStyleTrackball* sp)
{
  boost::shared_ptr<vtkInteractorStyleTrackball> di_ptr(
    sp,
    wxwindow_nodeleter<vtkInteractorStyleTrackball>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkInteractorStyleTrackball>::CreateVar(
      new WrapClass_vtkInteractorStyleTrackball(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::AddMethods(WrapClass<vtkInteractorStyleTrackball>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent vtkInteractorStyleSwitch
  boost::shared_ptr<vtkInteractorStyleSwitch > parent_vtkInteractorStyleSwitch(  boost::dynamic_pointer_cast<vtkInteractorStyleSwitch >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkInteractorStyleSwitch = AMILabType<vtkInteractorStyleSwitch >::CreateVarFromSmtPtr(parent_vtkInteractorStyleSwitch);
  context->AddVar("vtkInteractorStyleSwitch",var_vtkInteractorStyleSwitch);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkInteractorStyleSwitch = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkInteractorStyleSwitch);
  context->AddDefault(obj_vtkInteractorStyleSwitch->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyleTrackball_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkInteractorStyleTrackball");
  
  // Static methods 
  WrapClass_vtkInteractorStyleTrackball::AddVar_New(amiobject->GetContext());
  WrapClass_vtkInteractorStyleTrackball::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkInteractorStyleTrackball::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::New()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleTrackball";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleTrackball * res =   vtkInteractorStyleTrackball::New();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleTrackball >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleTrackball::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkInteractorStyleTrackball::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkInteractorStyleTrackball";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
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

  vtkInteractorStyleTrackball * res =   vtkInteractorStyleTrackball::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleTrackball >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkInteractorStyleTrackball::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
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
//  Wrapping of vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::NewInstance()
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkInteractorStyleTrackball";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkInteractorStyleTrackball * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkInteractorStyleTrackball >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkInteractorStyleTrackball::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkInteractorStyleTrackball::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkInteractorStyleTrackball::
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

