/**
 * C++ Interface: wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper
 *
 * Description: wrapping vtkAMILabOpenGLGPUMultiVolumeRayCastMapper
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

#include "wrap_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper.h"

// get all the required includes
// #include "..."
#include "/home/karl/projects/Sourceforge/amilab/trunk/Modules/vtkAmiVolRen/src/vtkAMILabOpenGLGPUMultiVolumeRayCastMapper.h"
#include "/usr/local/include/vtk-5.8/vtkObjectBase.h"
#include "boost/numeric/conversion/cast.hpp"

#include "/usr/local/include/vtk-5.8/vtkIndent.h"
#ifndef vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_declared
  #define vtkAMILabOpenGLGPUMultiVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkAMILabOpenGLGPUMultiVolumeRayCastMapper)
#endif
#ifndef vtkObjectBase_declared
  #define vtkObjectBase_declared
  AMI_DECLARE_TYPE(vtkObjectBase)
#endif
#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent)
#endif
#ifndef vtkRenderWindow_declared
  #define vtkRenderWindow_declared
  AMI_DECLARE_TYPE(vtkRenderWindow)
#endif
#ifndef vtkVolumeProperty_declared
  #define vtkVolumeProperty_declared
  AMI_DECLARE_TYPE(vtkVolumeProperty)
#endif
#ifndef vtkWindow_declared
  #define vtkWindow_declared
  AMI_DECLARE_TYPE(vtkWindow)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::CreateVar( ParamList* p, bool quiet)
{
  // No constructor available !!
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkAMILabOpenGLGPUMultiVolumeRayCastMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkAMILabOpenGLGPUMultiVolumeRayCastMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >::CreateVar( vtkAMILabOpenGLGPUMultiVolumeRayCastMapper* val, bool nodeleter)
{ 
    boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper > obj_ptr;
  if (nodeleter)
    obj_ptr = boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >(val, smartpointer_nodeleter<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >());
  else
    obj_ptr = boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >(val , smartpointer_nodeleter<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >());
  return AMILabType<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkAMILabOpenGLGPUMultiVolumeRayCastMapper
//
Variable<AMIObject>::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::CreateVar( vtkAMILabOpenGLGPUMultiVolumeRayCastMapper* sp)
{
  boost::shared_ptr<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper> di_ptr(
    sp  
    , smartpointer_nodeleter<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >() ); 
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::CreateVar(
      new WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddMethods(WrapClass<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: std::ostream
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_IsRenderSupported( this_ptr);
  AddVar_ReleaseGraphicsResources( this_ptr);



  // Add public fields 
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  // Adding Bases

  // Add base parent vtkGPUVolumeRayCastMapper
  boost::shared_ptr<vtkGPUVolumeRayCastMapper > parent_vtkGPUVolumeRayCastMapper(  boost::dynamic_pointer_cast<vtkGPUVolumeRayCastMapper >(this_ptr->GetObj()));
  BasicVariable::ptr var_vtkGPUVolumeRayCastMapper = AMILabType<vtkGPUVolumeRayCastMapper >::CreateVarFromSmtPtr(parent_vtkGPUVolumeRayCastMapper);
  context->AddVar("vtkGPUVolumeRayCastMapper",var_vtkGPUVolumeRayCastMapper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_vtkGPUVolumeRayCastMapper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_vtkGPUVolumeRayCastMapper);
  context->AddDefault(obj_vtkGPUVolumeRayCastMapper->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAMILabOpenGLGPUMultiVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkAMILabOpenGLGPUMultiVolumeRayCastMapper");
  
  // Static methods 
  WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddVar_New(amiobject->GetContext());
  WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddVar_OpenGLErrorMessage(amiobject->GetContext());
  WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::AddVar_PrintError(amiobject->GetContext());

  
// Add public enumerations 

  // Adding public typedefs 
  BasicVariable::ptr type_0 = AMILabType<std::string>::CreateVar(new std::string("vtkGPUVolumeRayCastMapper  --  vtkGPUVolumeRayCastMapper"));
  type_0->Rename("Superclass");
  amiobject->GetContext()->AddVar(type_0->Name(),type_0,context);


  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::New()
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkAMILabOpenGLGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * res = vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::New();
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!AMILabType<std::string >::get_val_smtptr_param(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();
  // -------- Calling the class method with all parameter(s)
  int res = vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkAMILabOpenGLGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
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
    if (!AMILabType<vtkObjectBase >::get_val_smtptr_param(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    o = o_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * res = vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::SafeDownCast(o);
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of char const * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::OpenGLErrorMessage(unsigned int errorCode)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_OpenGLErrorMessage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'errorCode'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_OpenGLErrorMessage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long errorCode_long;
  if (!AMILabType<long >::get_val_param(errorCode_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  unsigned int errorCode = boost::numeric_cast<unsigned int >(errorCode_long);
  // -------- Calling the class method with all parameter(s)
  char const * res = vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::OpenGLErrorMessage(errorCode);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::PrintError(char const * headerMessage)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_PrintError::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'headerMessage'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_static_PrintError::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > headerMessage_string;
  if (!AMILabType<std::string >::get_val_smtptr_param(headerMessage_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * headerMessage = headerMessage_string->c_str();
  // -------- Calling the class method with all parameter(s)
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::PrintError(headerMessage);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_IsA::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!AMILabType<std::string >::get_val_smtptr_param(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->IsA(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkAMILabOpenGLGPUMultiVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper * res = this->_objectptr->GetObj()->NewInstance();
  if (res==NULL) return nullvar;
  BasicVariable::ptr res_var = AMILabType<vtkAMILabOpenGLGPUMultiVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: std::ostream

//---------------------------------------------------
//  Wrapping of void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::PrintSelf(std::ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::ostream, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_PrintSelf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::ostream > os_smtptr;
  if (!AMILabType<std::ostream >::get_val_smtptr_param(os_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  std::ostream & os = *os_smtptr;

  vtkIndent indent;
  if (!AMILabType<vtkIndent >::get_val_param(indent,_p,_n,true,false,false)) ClassHelpAndReturn;
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->PrintSelf(os, indent);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of int vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * window, vtkVolumeProperty * property)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_IsRenderSupported::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'property'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_IsRenderSupported::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  vtkRenderWindow* window;
  if (CheckNullVar(_p,_n))  {
    window=(vtkRenderWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkRenderWindow > window_smtptr;
    if (!AMILabType<vtkRenderWindow >::get_val_smtptr_param(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    window = window_smtptr.get();
  }

  vtkVolumeProperty* property;
  if (CheckNullVar(_p,_n))  {
    property=(vtkVolumeProperty*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolumeProperty > property_smtptr;
    if (!AMILabType<vtkVolumeProperty >::get_val_smtptr_param(property_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    property = property_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  int res = this->_objectptr->GetObj()->IsRenderSupported(window, property);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::ReleaseGraphicsResources(vtkWindow * window)
//---------------------------------------------------
void WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkWindow, "parameter named 'window'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkAMILabOpenGLGPUMultiVolumeRayCastMapper::
    wrap_ReleaseGraphicsResources::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  vtkWindow* window;
  if (CheckNullVar(_p,_n))  {
    window=(vtkWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkWindow > window_smtptr;
    if (!AMILabType<vtkWindow >::get_val_smtptr_param(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    window = window_smtptr.get();
  }
  // -------- Calling the class method with all parameter(s)
  if (!this->_objectptr->GetObj().get()) return BasicVariable::ptr();
  this->_objectptr->GetObj()->ReleaseGraphicsResources(window);
  return BasicVariable::ptr();
}

