/**
 * C++ Interface: wrap_vtkOpenGLGPUVolumeRayCastMapper
 *
 * Description: wrapping vtkOpenGLGPUVolumeRayCastMapper
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

#include "wrap_vtkOpenGLGPUVolumeRayCastMapper.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef vtkOpenGLGPUVolumeRayCastMapper_declared
  #define vtkOpenGLGPUVolumeRayCastMapper_declared
  AMI_DECLARE_TYPE(vtkOpenGLGPUVolumeRayCastMapper)
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



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::CreateVar( ParamList* p)
{
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::wrap_static_New construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(vtkOpenGLGPUVolumeRayCastMapper);
AMI_DEFINE_VARFROMSMTPTR(vtkOpenGLGPUVolumeRayCastMapper);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<vtkOpenGLGPUVolumeRayCastMapper>::CreateVar( vtkOpenGLGPUVolumeRayCastMapper* val, bool nodeleter)
{ 
  boost::shared_ptr<vtkOpenGLGPUVolumeRayCastMapper> obj_ptr(val,smartpointer_nodeleter<vtkOpenGLGPUVolumeRayCastMapper>());
  return AMILabType<vtkOpenGLGPUVolumeRayCastMapper>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkOpenGLGPUVolumeRayCastMapper
//
Variable<AMIObject>::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::CreateVar( vtkOpenGLGPUVolumeRayCastMapper* sp)
{
  boost::shared_ptr<vtkOpenGLGPUVolumeRayCastMapper> di_ptr(
    sp,
    wxwindow_nodeleter<vtkOpenGLGPUVolumeRayCastMapper>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::CreateVar(
      new WrapClass_vtkOpenGLGPUVolumeRayCastMapper(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddMethods(WrapClass<vtkOpenGLGPUVolumeRayCastMapper>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_IsA( this_ptr);
  AddVar_NewInstance( this_ptr);
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
  AddVar_PrintSelf( this_ptr);
*/
  AddVar_IsRenderSupported( this_ptr);



  // Add public fields and Enumerations
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
void WrapClassvtkOpenGLGPUVolumeRayCastMapper_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkOpenGLGPUVolumeRayCastMapper");
  
  // Static methods 
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddVar_New(amiobject->GetContext());
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddVar_IsTypeOf(amiobject->GetContext());
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddVar_SafeDownCast(amiobject->GetContext());
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddVar_OpenGLErrorMessage(amiobject->GetContext());
  WrapClass_vtkOpenGLGPUVolumeRayCastMapper::AddVar_PrintError(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::New()
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkOpenGLGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkOpenGLGPUVolumeRayCastMapper * res =   vtkOpenGLGPUVolumeRayCastMapper::New();
  BasicVariable::ptr res_var = AMILabType<vtkOpenGLGPUVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int vtkOpenGLGPUVolumeRayCastMapper::IsTypeOf(char const * type)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_IsTypeOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_IsTypeOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > type_string;
  if (!get_val_smtptr_param<std::string >(type_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * type = type_string->c_str();

  int res =   vtkOpenGLGPUVolumeRayCastMapper::IsTypeOf(type);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::SafeDownCast(vtkObjectBase * o)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_SafeDownCast::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkObjectBase, "parameter named 'o'")
  return_comments="returning a variable of type vtkOpenGLGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
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

  vtkOpenGLGPUVolumeRayCastMapper * res =   vtkOpenGLGPUVolumeRayCastMapper::SafeDownCast(o);
  BasicVariable::ptr res_var = AMILabType<vtkOpenGLGPUVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of char const * vtkOpenGLGPUVolumeRayCastMapper::OpenGLErrorMessage(unsigned int errorCode)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_OpenGLErrorMessage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'errorCode'")
  return_comments="returning a variable of type std::string";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_OpenGLErrorMessage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long errorCode_long;
  if (!get_val_param<long >(errorCode_long,_p,_n,true,false)) ClassHelpAndReturn;
  unsigned int errorCode = boost::numeric_cast<unsigned int >(errorCode_long);

  char const * res =   vtkOpenGLGPUVolumeRayCastMapper::OpenGLErrorMessage(errorCode);
  std::string res_string = std::string(res);
  return AMILabType<std::string >::CreateVar(res_string);
}

//---------------------------------------------------
//  Wrapping of void vtkOpenGLGPUVolumeRayCastMapper::PrintError(char const * headerMessage)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_PrintError::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'headerMessage'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_static_PrintError::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<std::string > headerMessage_string;
  if (!get_val_smtptr_param<std::string >(headerMessage_string,_p,_n,true,false,false)) ClassHelpAndReturn;
  char const * headerMessage = headerMessage_string->c_str();

  vtkOpenGLGPUVolumeRayCastMapper::PrintError(headerMessage);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int vtkOpenGLGPUVolumeRayCastMapper::IsA(char const * type)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_IsA::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'type'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
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
//  Wrapping of vtkOpenGLGPUVolumeRayCastMapper * vtkOpenGLGPUVolumeRayCastMapper::NewInstance()
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_NewInstance::SetParametersComments()
{
  return_comments="returning a variable of type vtkOpenGLGPUVolumeRayCastMapper";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_NewInstance::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkOpenGLGPUVolumeRayCastMapper * res =   this->_objectptr->GetObj()->NewInstance();
  BasicVariable::ptr res_var = AMILabType<vtkOpenGLGPUVolumeRayCastMapper >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: basic_ostream<char,std::char_traits<char> >

//---------------------------------------------------
//  Wrapping of void vtkOpenGLGPUVolumeRayCastMapper::PrintSelf(ostream & os, vtkIndent indent)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_PrintSelf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( basic_ostream<char,std::char_traits<char> >, "parameter named 'os'")
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'indent'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
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
//  Wrapping of int vtkOpenGLGPUVolumeRayCastMapper::IsRenderSupported(vtkRenderWindow * window, vtkVolumeProperty * property)
//---------------------------------------------------
void WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
    wrap_IsRenderSupported::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkRenderWindow, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( vtkVolumeProperty, "parameter named 'property'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkOpenGLGPUVolumeRayCastMapper::
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
    if (!get_val_smtptr_param<vtkRenderWindow >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    window = window_smtptr.get();
  }

  vtkVolumeProperty* property;
  if (CheckNullVar(_p,_n))  {
    property=(vtkVolumeProperty*)NULL;
    _n++;
  } else {
    boost::shared_ptr<vtkVolumeProperty > property_smtptr;
    if (!get_val_smtptr_param<vtkVolumeProperty >(property_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    property = property_smtptr.get();
  }

  int res =   this->_objectptr->GetObj()->IsRenderSupported(window, property);
  return AMILabType<int >::CreateVar(res);
}

