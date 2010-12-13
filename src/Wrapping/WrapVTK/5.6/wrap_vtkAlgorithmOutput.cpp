/**
 * C++ Interface: wrap_vtkAlgorithmOutput
 *
 * Description: wrapping vtkAlgorithmOutput
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

#include "wrap_vtkAlgorithmOutput.h"

// get all the required includes
// #include "..."
#ifndef vtkAlgorithmOutput_declared
  #define vtkAlgorithmOutput_declared
  AMI_DECLARE_TYPE(vtkAlgorithmOutput)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkAlgorithm_declared
  #define vtkAlgorithm_declared
  AMI_DECLARE_TYPE(vtkAlgorithm)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAlgorithmOutput>::CreateVar( ParamList* p)
{
  WrapClass_vtkAlgorithmOutput::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAlgorithmOutput);
AMI_DEFINE_VARFROMSMTPTR(vtkAlgorithmOutput);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAlgorithmOutput>::CreateVar( vtkAlgorithmOutput* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkAlgorithmOutput> obj_ptr(val,smartpointer_nodeleter<vtkAlgorithmOutput>());
  return AMILabType<vtkAlgorithmOutput>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAlgorithmOutput
//
Variable<AMIObject>::ptr WrapClass_vtkAlgorithmOutput::CreateVar( vtkAlgorithmOutput* sp)
{
  boost::shared_ptr<vtkAlgorithmOutput> di_ptr(
    sp,
    wxwindow_nodeleter<vtkAlgorithmOutput>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAlgorithmOutput>::CreateVar(
      new WrapClass_vtkAlgorithmOutput(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAlgorithmOutput::AddMethods(WrapClass<vtkAlgorithmOutput>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_SetIndex( this_ptr);
  AddVar_GetIndex( this_ptr);
  AddVar_GetProducer( this_ptr);
  AddVar_SetProducer( this_ptr);



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
void WrapClassvtkAlgorithmOutput_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAlgorithmOutput");
  
  // Static methods 
  WrapClass_vtkAlgorithmOutput::AddVar_New(amiobject->GetContext());
  WrapClass_vtkAlgorithmOutput::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAlgorithmOutput::AddVar_SafeDownCast(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithmOutput::New()
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithmOutput * res =   vtkAlgorithmOutput::New();
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithmOutput::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkAlgorithmOutput::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithmOutput::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
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

  vtkAlgorithmOutput * res =   vtkAlgorithmOutput::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithmOutput::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
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
//  Wrapping of vtkAlgorithmOutput * vtkAlgorithmOutput::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithmOutput";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithmOutput * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithmOutput >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkAlgorithmOutput::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
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
//  Wrapping of void vtkAlgorithmOutput::SetIndex(int index)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_SetIndex::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_SetIndex::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetIndex(index);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAlgorithmOutput::GetIndex()
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_GetIndex::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_GetIndex::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetIndex();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAlgorithm * vtkAlgorithmOutput::GetProducer()
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_GetProducer::SetParametersComments()
{
  return_comments="returning a variable of type vtkAlgorithm";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_GetProducer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkAlgorithm * res =   this->_objectptr->GetObj()->GetProducer();
  BasicVariable::ptr res_var = AMILabType<vtkAlgorithm >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void vtkAlgorithmOutput::SetProducer(vtkAlgorithm * producer)
//---------------------------------------------------
void WrapClass_vtkAlgorithmOutput::
    wrap_SetProducer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkAlgorithm, "parameter named 'producer'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAlgorithmOutput::
    wrap_SetProducer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkAlgorithm* producer;
  if (CheckNullVar(_p,_n))  {
    producer=(vtkAlgorithm*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkAlgorithm > producer_smtptr;
    if (!get_val_smtptr_param<vtkAlgorithm >(producer_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    producer = producer_smtptr.get();
  }

  this->_objectptr->GetObj()->SetProducer(producer);
  return BasicVariable::ptr();
}

