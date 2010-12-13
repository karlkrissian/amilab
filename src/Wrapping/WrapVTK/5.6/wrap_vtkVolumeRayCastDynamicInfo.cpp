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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

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



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  /* ArrayType not implemented
  // Adding public member Color
  boost::shared_ptr<float > var_Color_ptr(&GetObj()->Color, smartpointer_nodeleter<float >());
  if (var_Color_ptr.get()) {
    BasicVariable::ptr var_Color = AMILabType<float >::CreateVarFromSmtPtr(var_Color_ptr);
    if (var_Color.get()) {
      var_Color->Rename("Color");
      context->AddVar(var_Color,context);
    }
  }
  */
  
  // Adding public member ScalarValue
  boost::shared_ptr<float > var_ScalarValue_ptr(&GetObj()->ScalarValue, smartpointer_nodeleter<float >());
  if (var_ScalarValue_ptr.get()) {
    BasicVariable::ptr var_ScalarValue = AMILabType<float >::CreateVarFromSmtPtr(var_ScalarValue_ptr);
    if (var_ScalarValue.get()) {
      var_ScalarValue->Rename("ScalarValue");
      context->AddVar(var_ScalarValue,context);
    }
  }
  
  /* ArrayType not implemented
  // Adding public member TransformedStart
  boost::shared_ptr<float > var_TransformedStart_ptr(&GetObj()->TransformedStart, smartpointer_nodeleter<float >());
  if (var_TransformedStart_ptr.get()) {
    BasicVariable::ptr var_TransformedStart = AMILabType<float >::CreateVarFromSmtPtr(var_TransformedStart_ptr);
    if (var_TransformedStart.get()) {
      var_TransformedStart->Rename("TransformedStart");
      context->AddVar(var_TransformedStart,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member TransformedEnd
  boost::shared_ptr<float > var_TransformedEnd_ptr(&GetObj()->TransformedEnd, smartpointer_nodeleter<float >());
  if (var_TransformedEnd_ptr.get()) {
    BasicVariable::ptr var_TransformedEnd = AMILabType<float >::CreateVarFromSmtPtr(var_TransformedEnd_ptr);
    if (var_TransformedEnd.get()) {
      var_TransformedEnd->Rename("TransformedEnd");
      context->AddVar(var_TransformedEnd,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member TransformedDirection
  boost::shared_ptr<float > var_TransformedDirection_ptr(&GetObj()->TransformedDirection, smartpointer_nodeleter<float >());
  if (var_TransformedDirection_ptr.get()) {
    BasicVariable::ptr var_TransformedDirection = AMILabType<float >::CreateVarFromSmtPtr(var_TransformedDirection_ptr);
    if (var_TransformedDirection.get()) {
      var_TransformedDirection->Rename("TransformedDirection");
      context->AddVar(var_TransformedDirection,context);
    }
  }
  */
  
  /* ArrayType not implemented
  // Adding public member TransformedIncrement
  boost::shared_ptr<float > var_TransformedIncrement_ptr(&GetObj()->TransformedIncrement, smartpointer_nodeleter<float >());
  if (var_TransformedIncrement_ptr.get()) {
    BasicVariable::ptr var_TransformedIncrement = AMILabType<float >::CreateVarFromSmtPtr(var_TransformedIncrement_ptr);
    if (var_TransformedIncrement.get()) {
      var_TransformedIncrement->Rename("TransformedIncrement");
      context->AddVar(var_TransformedIncrement,context);
    }
  }
  */
  
  // Adding public member NumberOfStepsToTake
  boost::shared_ptr<int > var_NumberOfStepsToTake_ptr(&GetObj()->NumberOfStepsToTake, smartpointer_nodeleter<int >());
  if (var_NumberOfStepsToTake_ptr.get()) {
    BasicVariable::ptr var_NumberOfStepsToTake = AMILabType<int >::CreateVarFromSmtPtr(var_NumberOfStepsToTake_ptr);
    if (var_NumberOfStepsToTake.get()) {
      var_NumberOfStepsToTake->Rename("NumberOfStepsToTake");
      context->AddVar(var_NumberOfStepsToTake,context);
    }
  }
  
  // Adding public member NumberOfStepsTaken
  boost::shared_ptr<int > var_NumberOfStepsTaken_ptr(&GetObj()->NumberOfStepsTaken, smartpointer_nodeleter<int >());
  if (var_NumberOfStepsTaken_ptr.get()) {
    BasicVariable::ptr var_NumberOfStepsTaken = AMILabType<int >::CreateVarFromSmtPtr(var_NumberOfStepsTaken_ptr);
    if (var_NumberOfStepsTaken.get()) {
      var_NumberOfStepsTaken->Rename("NumberOfStepsTaken");
      context->AddVar(var_NumberOfStepsTaken,context);
    }
  }


  


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
//  Wrapping of Constructor vtkVolumeRayCastDynamicInfo::._87(vtkVolumeRayCastDynamicInfo const & param0)
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
//  Wrapping of Constructor vtkVolumeRayCastDynamicInfo::._87()
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

