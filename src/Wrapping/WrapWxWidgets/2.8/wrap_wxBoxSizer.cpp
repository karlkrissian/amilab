/**
 * C++ Interface: wrap_wxBoxSizer
 *
 * Description: wrapping wxBoxSizer
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
#include "wrap_wxBoxSizer.h"
#include "wrap_wxSize.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxBoxSizer.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBoxSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxBoxSizer::wrap_wxBoxSizer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBoxSizer);
AMI_DEFINE_VARFROMSMTPTR(wxBoxSizer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBoxSizer
//
Variable<AMIObject>::ptr WrapClass_wxBoxSizer::CreateVar( wxBoxSizer* sp)
{
  boost::shared_ptr<wxBoxSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxBoxSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBoxSizer>::CreateVar(
      new WrapClass_wxBoxSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBoxSizer::AddMethods(WrapClass<wxBoxSizer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_RecalcSizes( this_ptr);
      AddVar_CalcMin( this_ptr);
      AddVar_GetOrientation( this_ptr);
      AddVar_SetOrientation( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxSizer
  boost::shared_ptr<wxSizer > parent_wxSizer(  boost::dynamic_pointer_cast<wxSizer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxSizer = AMILabType<wxSizer >::CreateVarFromSmtPtr(parent_wxSizer);
  context->AddVar("wxSizer",var_wxSizer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxSizer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxSizer);
  context->AddDefault(obj_wxSizer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxBoxSizer::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBoxSizer");
    WrapClass_wxBoxSizer::AddVar_wxBoxSizer_1(amiobject->GetContext());
  WrapClass_wxBoxSizer::AddVar_wxBoxSizer(amiobject->GetContext());
  WrapClass_wxBoxSizer::AddVar_wxBoxSizer_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBoxSizer::wxBoxSizer(wxBoxSizer const & param0)
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_wxBoxSizer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBoxSizer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_wxBoxSizer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBoxSizer > param0_smtptr;
  if (!get_val_smtptr_param<wxBoxSizer >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBoxSizer const & param0 = *param0_smtptr;

  wxBoxSizer* _newobj = new wxBoxSizer(param0);
  BasicVariable::ptr res = WrapClass_wxBoxSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBoxSizer::wxBoxSizer(...)
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_wxBoxSizer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_wxBoxSizer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBoxSizer::wrap_wxBoxSizer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBoxSizer::wrap_wxBoxSizer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBoxSizer::wxBoxSizer(int orient)
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_wxBoxSizer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_wxBoxSizer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,true)) ClassReturnEmptyVar;

  wxBoxSizer* _newobj = new wxBoxSizer(orient);
  BasicVariable::ptr res = WrapClass_wxBoxSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBoxSizer.
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBoxSizer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBoxSizer >::CreateVar( new wxBoxSizer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxBoxSizer::RecalcSizes()
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_RecalcSizes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_RecalcSizes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RecalcSizes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxBoxSizer::CalcMin()
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_CalcMin::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_CalcMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->CalcMin();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBoxSizer::GetOrientation()
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_GetOrientation::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_GetOrientation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetOrientation();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBoxSizer::SetOrientation(int orient)
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_SetOrientation::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_SetOrientation::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetOrientation(orient);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBoxSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBoxSizer & wxBoxSizer::operator =(wxBoxSizer const & param0)
//---------------------------------------------------
void WrapClass_wxBoxSizer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBoxSizer, "parameter named 'param0'")
  return_comments="returning a variable of type wxBoxSizer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBoxSizer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBoxSizer > param0_smtptr;
  if (!get_val_smtptr_param<wxBoxSizer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBoxSizer const & param0 = *param0_smtptr;

  wxBoxSizer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBoxSizer >::CreateVar(res);
}

