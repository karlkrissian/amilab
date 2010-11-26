/**
 * C++ Interface: wrap_vtkIndent
 *
 * Description: wrapping vtkIndent
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
#include "wrap_vtkIndent.h"


#include "wrap_vtkIndent.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<vtkIndent>::CreateVar( ParamList* p)
{
  WrapClass_vtkIndent::wrap_vtkIndent construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(vtkIndent);
AMI_DEFINE_VARFROMSMTPTR(vtkIndent);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to vtkIndent
//
Variable<AMIObject>::ptr WrapClass_vtkIndent::CreateVar( vtkIndent* sp)
{
  boost::shared_ptr<vtkIndent> di_ptr(
    sp,
    wxwindow_nodeleter<vtkIndent>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<vtkIndent>::CreateVar(
      new WrapClass_vtkIndent(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_vtkIndent::AddMethods(WrapClass<vtkIndent>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Delete( this_ptr);
      AddVar_GetNextIndent( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor vtkIndent::vtkIndent(vtkIndent const & param0)
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_vtkIndent_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_vtkIndent_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<vtkIndent > param0_smtptr;
  if (!get_val_smtptr_param<vtkIndent >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  vtkIndent const & param0 = *param0_smtptr;

  vtkIndent* _newobj = new vtkIndent(param0);
  BasicVariable::ptr res = WrapClass_vtkIndent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor vtkIndent::vtkIndent(...)
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_vtkIndent::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_vtkIndent::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_vtkIndent::wrap_vtkIndent_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_vtkIndent::wrap_vtkIndent_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor vtkIndent::vtkIndent(int ind = 0)
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_vtkIndent_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'ind' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_vtkIndent_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int ind = 0;
  if (!get_val_param<int >(ind,_p,_n,false,true)) ClassReturnEmptyVar;

  vtkIndent* _newobj = new vtkIndent(ind);
  BasicVariable::ptr res = WrapClass_vtkIndent::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of vtkIndent * vtkIndent::New()
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_New::SetParametersComments()
{
  return_comments="returning a variable of type vtkIndent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_New::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIndent * res =   vtkIndent::New();
  BasicVariable::ptr res_var = WrapClass_vtkIndent::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for vtkIndent.
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the vtkIndent object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<vtkIndent >::CreateVar( new vtkIndent(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void vtkIndent::Delete()
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_Delete::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_Delete::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Delete();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of vtkIndent vtkIndent::GetNextIndent()
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap_GetNextIndent::SetParametersComments()
{
  return_comments="returning a variable of type vtkIndent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap_GetNextIndent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  vtkIndent res =   this->_objectptr->GetObj()->GetNextIndent();
  return AMILabType<vtkIndent >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of vtkIndent & vtkIndent::operator =(vtkIndent const & param0)
//---------------------------------------------------
void WrapClass_vtkIndent::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( vtkIndent, "parameter named 'param0'")
  return_comments="returning a variable of type vtkIndent";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_vtkIndent::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<vtkIndent > param0_smtptr;
  if (!get_val_smtptr_param<vtkIndent >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  vtkIndent const & param0 = *param0_smtptr;

  vtkIndent & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<vtkIndent >::CreateVar(res);
}

