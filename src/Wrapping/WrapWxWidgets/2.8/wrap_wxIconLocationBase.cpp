/**
 * C++ Interface: wrap_wxIconLocationBase
 *
 * Description: wrapping wxIconLocationBase
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

#include "wrap_wxIconLocationBase.h"

// get all the required includes
// #include "..."
#ifndef wxIconLocationBase_declared
  #define wxIconLocationBase_declared
  AMI_DECLARE_TYPE(wxIconLocationBase)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxIconLocationBase>::CreateVar( ParamList* p)
{
  WrapClass_wxIconLocationBase::wrap_wxIconLocationBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIconLocationBase);
AMI_DEFINE_VARFROMSMTPTR(wxIconLocationBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIconLocationBase
//
Variable<AMIObject>::ptr WrapClass_wxIconLocationBase::CreateVar( wxIconLocationBase* sp)
{
  boost::shared_ptr<wxIconLocationBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxIconLocationBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIconLocationBase>::CreateVar(
      new WrapClass_wxIconLocationBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIconLocationBase::AddMethods(WrapClass<wxIconLocationBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_IsOk( this_ptr);
  AddVar_SetFileName( this_ptr);
  AddVar_GetFileName( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIconLocationBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIconLocationBase");
    WrapClass_wxIconLocationBase::AddVar_wxIconLocationBase_1(amiobject->GetContext());
  WrapClass_wxIconLocationBase::AddVar_wxIconLocationBase(amiobject->GetContext());
  WrapClass_wxIconLocationBase::AddVar_wxIconLocationBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIconLocationBase::wxIconLocationBase(wxIconLocationBase const & param0)
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconLocationBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIconLocationBase > param0_smtptr;
  if (!get_val_smtptr_param<wxIconLocationBase >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIconLocationBase const & param0 = *param0_smtptr;

  wxIconLocationBase* _newobj = new wxIconLocationBase(param0);
  BasicVariable::ptr res = WrapClass_wxIconLocationBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIconLocationBase::wxIconLocationBase(...)
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIconLocationBase::wrap_wxIconLocationBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIconLocationBase::wrap_wxIconLocationBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIconLocationBase::wxIconLocationBase(wxString const & filename = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_wxIconLocationBase_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & filename = ( filename_smtptr.get() ? (*filename_smtptr) : wxString(wxEmptyString) );

  wxIconLocationBase* _newobj = new wxIconLocationBase(filename);
  BasicVariable::ptr res = WrapClass_wxIconLocationBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIconLocationBase.
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIconLocationBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIconLocationBase >::CreateVar( new wxIconLocationBase(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxIconLocationBase::IsOk()
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxIconLocationBase::SetFileName(wxString const & filename)
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_SetFileName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_SetFileName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & filename = *filename_smtptr;

  this->_objectptr->GetObj()->SetFileName(filename);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxIconLocationBase::GetFileName()
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap_GetFileName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap_GetFileName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetFileName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxIconLocationBase & wxIconLocationBase::operator =(wxIconLocationBase const & param0)
//---------------------------------------------------
void WrapClass_wxIconLocationBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconLocationBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxIconLocationBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocationBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIconLocationBase > param0_smtptr;
  if (!get_val_smtptr_param<wxIconLocationBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIconLocationBase const & param0 = *param0_smtptr;

  wxIconLocationBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxIconLocationBase >::CreateVar(res);
}

