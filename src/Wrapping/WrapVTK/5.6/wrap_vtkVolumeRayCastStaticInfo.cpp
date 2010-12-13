/**
 * C++ Interface: wrap_vtkVolumeRayCastStaticInfo
 *
 * Description: wrapping vtkVolumeRayCastStaticInfo
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

#include "wrap_vtkVolumeRayCastStaticInfo.h"

// get all the required includes
// #include "..."
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
BasicVariable::ptr WrapClass<vtkVolumeRayCastStaticInfo>::CreateVar( ParamList* p)
{
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkVolumeRayCastStaticInfo);
AMI_DEFINE_VARFROMSMTPTR(vtkVolumeRayCastStaticInfo);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkVolumeRayCastStaticInfo
//
Variable<AMIObject>::ptr WrapClass_vtkVolumeRayCastStaticInfo::CreateVar( vtkVolumeRayCastStaticInfo* sp)
{
  boost::shared_ptr<vtkVolumeRayCastStaticInfo> di_ptr(
    sp,
    wxwindow_nodeleter<vtkVolumeRayCastStaticInfo>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkVolumeRayCastStaticInfo>::CreateVar(
      new WrapClass_vtkVolumeRayCastStaticInfo(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::AddMethods(WrapClass<vtkVolumeRayCastStaticInfo>::ptr this_ptr )
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
void WrapClassvtkVolumeRayCastStaticInfo_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("vtkVolumeRayCastStaticInfo");
    WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo_1(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo(amiobject->GetContext());
  WrapClass_vtkVolumeRayCastStaticInfo::AddVar_vtkVolumeRayCastStaticInfo_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastStaticInfo::._89(vtkVolumeRayCastStaticInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_1::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastStaticInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(param0_smtptr,_p,_n,true,true,false)) ClassHelpAndReturn;
  vtkVolumeRayCastStaticInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastStaticInfo* _newobj = new vtkVolumeRayCastStaticInfo(param0);
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastStaticInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkVolumeRayCastStaticInfo::vtkVolumeRayCastStaticInfo(...)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkVolumeRayCastStaticInfo::wrap_vtkVolumeRayCastStaticInfo_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkVolumeRayCastStaticInfo::._89()
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap_vtkVolumeRayCastStaticInfo_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkVolumeRayCastStaticInfo* _newobj = new vtkVolumeRayCastStaticInfo();
  BasicVariable::ptr res = WrapClass_vtkVolumeRayCastStaticInfo::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkVolumeRayCastStaticInfo.
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkVolumeRayCastStaticInfo object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkVolumeRayCastStaticInfo >::CreateVar( new vtkVolumeRayCastStaticInfo(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of vtkVolumeRayCastStaticInfo & vtkVolumeRayCastStaticInfo::operator =(vtkVolumeRayCastStaticInfo const & param0)
//---------------------------------------------------
void WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkVolumeRayCastStaticInfo, "parameter named 'param0'")
  return_comments="returning a variable of type vtkVolumeRayCastStaticInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkVolumeRayCastStaticInfo::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkVolumeRayCastStaticInfo > param0_smtptr;
  if (!get_val_smtptr_param<vtkVolumeRayCastStaticInfo >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkVolumeRayCastStaticInfo const & param0 = *param0_smtptr;

  vtkVolumeRayCastStaticInfo & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkVolumeRayCastStaticInfo >::CreateVar(res);
}

