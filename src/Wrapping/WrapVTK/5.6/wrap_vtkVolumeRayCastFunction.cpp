/**
 * C++ Interface: wrap_vtkVolumeRayCastFunction
 *
 * Description: wrapping vtkVolumeRayCastFunction
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

#include "wrap_vtkVolumeRayCastFunction.h"

// get all the required includes
// #include "..."
#ifndef vtkVolumeRayCastFunction_declared
  #define vtkVolumeRayCastFunction_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastFunction)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderer_declared
  #define vtkRenderer_declared
  AMI_DECLARE_TYPE(vtkRenderer)
#endif
#ifndef vtkVolume_declared
  #define vtkVolume_declared
  AMI_DECLARE_TYPE(vtkVolume)
#endif
#ifndef vtkVolumeRayCastStaticInfo_declared
  #define vtkVolumeRayCastStaticInfo_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastStaticInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeRayCastFunction>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkVolumeRayCastFunction);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastFunction);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkVolumeRayCastFunction>::CreateVar( vtkVolumeRayCastFunction* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkVolumeRayCastFunction> obj_ptr(val,smartpointer_nodeleter<vtkVolumeRayCastFunction>());
  return AMILabType<vtkVolumeRayCastFunction>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastFunction
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastFunction::CreateVar( vtkVolumeRayCastFunction* sp)
{
  boost::shared_ptr<vtkVolumeRayCastFunction> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastFunction>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastFunction>::CreateVar(
      new WrapClass_vtkVolumeRayCastFunction(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::AddMethods(WrapClass<vtkVolumeRayCastFunction>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_FunctionInitialize( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

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
void WrapClassvtkVolumeRayCastFunction_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastFunction");
  
  // Static methods 
  WrapClass_vtkVolumeRayCastFunction::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastFunction::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastFunction::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkVolumeRayCastFunction::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastFunction * vtkVolumeRayCastFunction::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkVolumeRayCastFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
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

  vtkVolumeRayCastFunction * res =   vtkVolumeRayCastFunction::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkVolumeRayCastFunction >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkVolumeRayCastFunction::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
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
//  Wrapping of vtkVolumeRayCastFunction * vtkVolumeRayCastFunction::NewInstance()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkVolumeRayCastFunction";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastFunction * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkVolumeRayCastFunction >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkVolumeRayCastFunction::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
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
//  Wrapping of void vtkVolumeRayCastFunction::FunctionInitialize(vtkRenderer * ren, vtkVolume * vol, vtkVolumeRayCastStaticInfo * staticInfo)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastFunction::
    wrap_FunctionInitialize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderer, "parameter named 'ren'")
  ADDPARAMCOMMENT_TYPE( vtkVolume, "parameter named 'vol'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'staticInfo'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastFunction::
    wrap_FunctionInitialize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  vtkRenderer* ren;
  if (CheckNullVar(_p,_n))  {
    ren=(vtkRenderer*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderer > ren_smtptr;
    if (!get_val_smtptr_param<vtkRenderer >(ren_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    ren = ren_smtptr.get();
  }

  vtkVolume* vol;
  if (CheckNullVar(_p,_n))  {
    vol=(vtkVolume*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolume > vol_smtptr;
    if (!get_val_smtptr_param<vtkVolume >(vol_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    vol = vol_smtptr.get();
  }

  vtkVolumeRayCastStaticInfo* staticInfo;
  if (CheckNullVar(_p,_n))  {
    staticInfo=(vtkVolumeRayCastStaticInfo*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolumeRayCastStaticInfo > staticInfo_smtptr;
    if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(staticInfo_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    staticInfo = staticInfo_smtptr.get();
  }

  this->_objectptr->GetObj()->FunctionInitialize(ren, vol, staticInfo);
  return BasicVariable::ptr();
}

