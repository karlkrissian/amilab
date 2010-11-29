/**
 * C++ Interface: wrap_vtkTimeStamp
 *
 * Description: wrapping vtkTimeStamp
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
#include "wrap_vtkTimeStamp.h"
#include "boost/numeric/conversion/cast.hpp"


#include "wrap_vtkTimeStamp.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkTimeStamp>::CreateVar( ParamList* p)
{
  WrapClass_vtkTimeStamp::wrap_vtkTimeStamp construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkTimeStamp);
AMI_DEFINE_VARFROMSMTPTR(vtkTimeStamp);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkTimeStamp
//
Variable<AMIObject>::ptr WrapClass_vtkTimeStamp::CreateVar( vtkTimeStamp* sp)
{
  boost::shared_ptr<vtkTimeStamp> di_ptr(
    sp,
    wxwindow_nodeleter<vtkTimeStamp>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkTimeStamp>::CreateVar(
      new WrapClass_vtkTimeStamp(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkTimeStamp::AddMethods(WrapClass<vtkTimeStamp>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Delete( this_ptr);
      AddVar_Modified( this_ptr);
      AddVar_GetMTime( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkTimeStamp::vtkTimeStamp(vtkTimeStamp const & param0)
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTimeStamp, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkTimeStamp > param0_smtptr;
  if (!get_val_smtptr_param<vtkTimeStamp >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  vtkTimeStamp const & param0 = *param0_smtptr;

  vtkTimeStamp* _newobj = new vtkTimeStamp(param0);
  BasicVariable::ptr res = WrapClass_vtkTimeStamp::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkTimeStamp::vtkTimeStamp(...)
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkTimeStamp::wrap_vtkTimeStamp_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkTimeStamp::wrap_vtkTimeStamp_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkTimeStamp::vtkTimeStamp()
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_vtkTimeStamp_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  vtkTimeStamp* _newobj = new vtkTimeStamp();
  BasicVariable::ptr res = WrapClass_vtkTimeStamp::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp * vtkTimeStamp::New()
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_static_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_static_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkTimeStamp * res =   vtkTimeStamp::New();
  BasicVariable::ptr res_var = WrapClass_vtkTimeStamp::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkTimeStamp.
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkTimeStamp object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkTimeStamp >::CreateVar( new vtkTimeStamp(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void vtkTimeStamp::Delete()
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_Delete::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_Delete::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Delete();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void vtkTimeStamp::Modified()
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_Modified::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_Modified::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Modified();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long unsigned int vtkTimeStamp::GetMTime()
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_GetMTime::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_GetMTime::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long unsigned int res =   this->_objectptr->GetObj()->GetMTime();
  long res_long = boost::numeric_cast<long >(res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of vtkTimeStamp & vtkTimeStamp::operator =(vtkTimeStamp const & param0)
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTimeStamp, "parameter named 'param0'")
  return_comments="returning a variable of type vtkTimeStamp";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTimeStamp > param0_smtptr;
  if (!get_val_smtptr_param<vtkTimeStamp >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkTimeStamp const & param0 = *param0_smtptr;

  vtkTimeStamp & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkTimeStamp >::CreateVar(res);
}
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkTimeStamp::>(vtkTimeStamp & ts)
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTimeStamp, "parameter named 'ts'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTimeStamp > ts_smtptr;
  if (!get_val_smtptr_param<vtkTimeStamp >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkTimeStamp & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()->>(ts);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/
/*
 * operator not available 

//---------------------------------------------------
//  Wrapping of bool vtkTimeStamp::<(vtkTimeStamp & ts)
//---------------------------------------------------
void WrapClass_vtkTimeStamp::
    wrap_operator not available::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkTimeStamp, "parameter named 'ts'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkTimeStamp::
    wrap_operator not available::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkTimeStamp > ts_smtptr;
  if (!get_val_smtptr_param<vtkTimeStamp >(ts_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkTimeStamp & ts = *ts_smtptr;

  bool res =   this->_objectptr->GetObj()-><(ts);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}
*/

