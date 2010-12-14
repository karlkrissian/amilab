/**
 * C++ Interface: wrap_wxDynamicLibraryDetails
 *
 * Description: wrapping wxDynamicLibraryDetails
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

#include "wrap_wxDynamicLibraryDetails.h"

// get all the required includes
// #include "..."
#include "boost/numeric/conversion/cast.hpp"
#ifndef wxDynamicLibraryDetails_declared
  #define wxDynamicLibraryDetails_declared
  AMI_DECLARE_TYPE(wxDynamicLibraryDetails)
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
BasicVariable::ptr WrapClass<wxDynamicLibraryDetails>::CreateVar( ParamList* p)
{
  WrapClass_wxDynamicLibraryDetails::wrap_wxDynamicLibraryDetails construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxDynamicLibraryDetails);
AMI_DEFINE_VARFROMSMTPTR(wxDynamicLibraryDetails);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDynamicLibraryDetails
//
Variable<AMIObject>::ptr WrapClass_wxDynamicLibraryDetails::CreateVar( wxDynamicLibraryDetails* sp)
{
  boost::shared_ptr<wxDynamicLibraryDetails> di_ptr(
    sp,
    wxwindow_nodeleter<wxDynamicLibraryDetails>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDynamicLibraryDetails>::CreateVar(
      new WrapClass_wxDynamicLibraryDetails(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::AddMethods(WrapClass<wxDynamicLibraryDetails>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetName( this_ptr);
  AddVar_GetPath( this_ptr);
/* The following types are missing: void
  AddVar_GetAddress( this_ptr);
*/
  AddVar_GetVersion( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDynamicLibraryDetails_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDynamicLibraryDetails");
    WrapClass_wxDynamicLibraryDetails::AddVar_wxDynamicLibraryDetails_1(amiobject->GetContext());
  WrapClass_wxDynamicLibraryDetails::AddVar_wxDynamicLibraryDetails(amiobject->GetContext());
  WrapClass_wxDynamicLibraryDetails::AddVar_wxDynamicLibraryDetails_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails(wxDynamicLibraryDetails const & param0)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > param0_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxDynamicLibraryDetails const & param0 = *param0_smtptr;

  wxDynamicLibraryDetails* _newobj = new wxDynamicLibraryDetails(param0);
  BasicVariable::ptr res = WrapClass_wxDynamicLibraryDetails::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails(...)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxDynamicLibraryDetails::wrap_wxDynamicLibraryDetails_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxDynamicLibraryDetails::wrap_wxDynamicLibraryDetails_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxDynamicLibraryDetails::wxDynamicLibraryDetails()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_wxDynamicLibraryDetails_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxDynamicLibraryDetails* _newobj = new wxDynamicLibraryDetails();
  BasicVariable::ptr res = WrapClass_wxDynamicLibraryDetails::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxDynamicLibraryDetails.
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxDynamicLibraryDetails object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxDynamicLibraryDetails >::CreateVar( new wxDynamicLibraryDetails(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibraryDetails::GetName()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibraryDetails::GetPath()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_GetPath::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_GetPath::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetPath();
  return AMILabType<wxString >::CreateVar(res);
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of bool wxDynamicLibraryDetails::GetAddress(void * * addr, size_t * len)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_GetAddress::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'addr'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'len'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_GetAddress::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  void* local_addr = NULL;
  void** addr;
  if (CheckNullVar(_p,_n))  {
    addr=(void**)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > addr_smtptr;
    if (!get_val_smtptr_param<void >(addr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    local_addr = addr_smtptr.get();
    addr = &local_addr;
  }

  boost::shared_ptr<long > len_long;
  if (!get_val_smtptr_param<long >(len_long,_p,_n,true,false,false)) ClassHelpAndReturn;
  long unsigned int len_val = boost::numeric_cast<long unsigned int >(*len_long);
  long unsigned int* len = &len_val;

  bool res =   this->_objectptr->GetObj()->GetAddress(addr, len);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of wxString wxDynamicLibraryDetails::GetVersion()
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap_GetVersion::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap_GetVersion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetVersion();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDynamicLibraryDetails & wxDynamicLibraryDetails::operator =(wxDynamicLibraryDetails const & param0)
//---------------------------------------------------
void WrapClass_wxDynamicLibraryDetails::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDynamicLibraryDetails, "parameter named 'param0'")
  return_comments="returning a variable of type wxDynamicLibraryDetails";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDynamicLibraryDetails::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDynamicLibraryDetails > param0_smtptr;
  if (!get_val_smtptr_param<wxDynamicLibraryDetails >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDynamicLibraryDetails const & param0 = *param0_smtptr;

  wxDynamicLibraryDetails & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxDynamicLibraryDetails >::CreateVar(res);
}

