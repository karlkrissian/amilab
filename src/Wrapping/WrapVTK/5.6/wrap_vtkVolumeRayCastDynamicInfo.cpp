/**
 * C++ Interface: wrap_vtkVolumeRayCastDynamicInfo
 *
 * Description: wrapping vtkVolumeRayCastDynamicInfo
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

#include "wrap_vtkVolumeRayCastDynamicInfo.h"

// get all the required includes
// #include "..."
#ifndef vtkVolumeRayCastDynamicInfo_declared
  #define vtkVolumeRayCastDynamicInfo_declared
  AMI_DECLARE_TYPE(vtkVolumeRayCastDynamicInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkVolumeRayCastDynamicInfo>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeRayCastDynamicInfo::wrap_vtkVolumeRayCastDynamicInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkVolumeRayCastDynamicInfo);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastDynamicInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastDynamicInfo
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastDynamicInfo::CreateVar( vtkVolumeRayCastDynamicInfo* sp)
{
  boost::shared_ptr<vtkVolumeRayCastDynamicInfo> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastDynamicInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastDynamicInfo>::CreateVar(
      new WrapClass_vtkVolumeRayCastDynamicInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::AddMethods(WrapClass<vtkVolumeRayCastDynamicInfo>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkVolumeRayCastDynamicInfo_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastDynamicInfo");
    WrapClass_vtkVolumeRayCastDynamicInfo::AddVar_vtkVolumeRayCastDynamicInfo_1(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastDynamicInfo::AddVar_vtkVolumeRayCastDynamicInfo(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastDynamicInfo::AddVar_vtkVolumeRayCastDynamicInfo_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastDynamicInfo::._88(vtkVolumeRayCastDynamicInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastDynamicInfo, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastDynamicInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastDynamicInfo >(param0_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  vtkVolumeRayCastDynamicInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastDynamicInfo* _newobj = new vtkVolumeRayCastDynamicInfo(param0);
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastDynamicInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkVolumeRayCastDynamicInfo::vtkVolumeRayCastDynamicInfo(...)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeRayCastDynamicInfo::wrap_vtkVolumeRayCastDynamicInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeRayCastDynamicInfo::wrap_vtkVolumeRayCastDynamicInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastDynamicInfo::._88()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap_vtkVolumeRayCastDynamicInfo_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastDynamicInfo* _newobj = new vtkVolumeRayCastDynamicInfo();
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastDynamicInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkVolumeRayCastDynamicInfo.
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkVolumeRayCastDynamicInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkVolumeRayCastDynamicInfo >::CreateVar( new vtkVolumeRayCastDynamicInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastDynamicInfo & vtkVolumeRayCastDynamicInfo::operator =(vtkVolumeRayCastDynamicInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastDynamicInfo, "parameter named 'param0'")
  return_comments="returning a variable of type vtkVolumeRayCastDynamicInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastDynamicInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastDynamicInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastDynamicInfo >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastDynamicInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastDynamicInfo & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkVolumeRayCastDynamicInfo >::CreateVar(res);
}

