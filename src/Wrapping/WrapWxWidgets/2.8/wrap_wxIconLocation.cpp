/**
 * C++ Interface: wrap_wxIconLocation
 *
 * Description: wrapping wxIconLocation
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

#include "wrap_wxIconLocation.h"

// get all the required includes
// #include "..."
#ifndef wxIconLocation_declared
  #define wxIconLocation_declared
  AMI_DECLARE_TYPE(wxIconLocation)
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
BasicVariable::ptr WrapClass<wxIconLocation>::CreateVar( ParamList* p)
{
  WrapClass_wxIconLocation::wrap_wxIconLocation construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIconLocation);
AMI_DEFINE_VARFROMSMTPTR(wxIconLocation);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIconLocation
//
Variable<AMIObject>::ptr WrapClass_wxIconLocation::CreateVar( wxIconLocation* sp)
{
  boost::shared_ptr<wxIconLocation> di_ptr(
    sp,
    wxwindow_nodeleter<wxIconLocation>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIconLocation>::CreateVar(
      new WrapClass_wxIconLocation(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIconLocation::AddMethods(WrapClass<wxIconLocation>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxIconLocationBase
  boost::shared_ptr<wxIconLocationBase > parent_wxIconLocationBase(  boost::dynamic_pointer_cast<wxIconLocationBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxIconLocationBase = AMILabType<wxIconLocationBase >::CreateVarFromSmtPtr(parent_wxIconLocationBase);
  context->AddVar("wxIconLocationBase",var_wxIconLocationBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxIconLocationBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxIconLocationBase);
  context->AddDefault(obj_wxIconLocationBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIconLocation_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIconLocation");
    WrapClass_wxIconLocation::AddVar_wxIconLocation_1(amiobject->GetContext());
  WrapClass_wxIconLocation::AddVar_wxIconLocation(amiobject->GetContext());
  WrapClass_wxIconLocation::AddVar_wxIconLocation_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIconLocation::wxIconLocation(wxIconLocation const & param0)
//---------------------------------------------------
void WrapClass_wxIconLocation::
    wrap_wxIconLocation_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconLocation, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocation::
    wrap_wxIconLocation_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIconLocation > param0_smtptr;
  if (!get_val_smtptr_param<wxIconLocation >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIconLocation const & param0 = *param0_smtptr;

  wxIconLocation* _newobj = new wxIconLocation(param0);
  BasicVariable::ptr res = WrapClass_wxIconLocation::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIconLocation::wxIconLocation(...)
//---------------------------------------------------
void WrapClass_wxIconLocation::
    wrap_wxIconLocation::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocation::
    wrap_wxIconLocation::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIconLocation::wrap_wxIconLocation_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIconLocation::wrap_wxIconLocation_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIconLocation::wxIconLocation(wxString const & filename = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxIconLocation::
    wrap_wxIconLocation_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocation::
    wrap_wxIconLocation_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & filename = ( filename_smtptr.get() ? (*filename_smtptr) : wxString(wxEmptyString) );

  wxIconLocation* _newobj = new wxIconLocation(filename);
  BasicVariable::ptr res = WrapClass_wxIconLocation::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIconLocation.
//---------------------------------------------------
void WrapClass_wxIconLocation::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIconLocation object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocation::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIconLocation >::CreateVar( new wxIconLocation(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxIconLocation & wxIconLocation::operator =(wxIconLocation const & param0)
//---------------------------------------------------
void WrapClass_wxIconLocation::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconLocation, "parameter named 'param0'")
  return_comments="returning a variable of type wxIconLocation";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconLocation::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIconLocation > param0_smtptr;
  if (!get_val_smtptr_param<wxIconLocation >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIconLocation const & param0 = *param0_smtptr;

  wxIconLocation & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxIconLocation >::CreateVar(res);
}

