/**
 * C++ Interface: wrap_wxEventTable
 *
 * Description: wrapping wxEventTable
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

#include "wrap_wxEventTable.h"

// get all the required includes
// #include "..."
#ifndef wxEventTable_declared
  #define wxEventTable_declared
  AMI_DECLARE_TYPE(wxEventTable)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxEventTable>::CreateVar( ParamList* p)
{
  WrapClass_wxEventTable::wrap_wxEventTable construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxEventTable);
AMI_DEFINE_VARFROMSMTPTR(wxEventTable);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxEventTable
//
Variable<AMIObject>::ptr WrapClass_wxEventTable::CreateVar( wxEventTable* sp)
{
  boost::shared_ptr<wxEventTable> di_ptr(
    sp,
    wxwindow_nodeleter<wxEventTable>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxEventTable>::CreateVar(
      new WrapClass_wxEventTable(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxEventTable::AddMethods(WrapClass<wxEventTable>::ptr this_ptr )
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
void WrapClasswxEventTable_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxEventTable");
    WrapClass_wxEventTable::AddVar_wxEventTable_1(amiobject->GetContext());
  WrapClass_wxEventTable::AddVar_wxEventTable(amiobject->GetContext());
  WrapClass_wxEventTable::AddVar_wxEventTable_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxEventTable::wxEventTable(wxEventTable const & param0)
//---------------------------------------------------
void WrapClass_wxEventTable::
    wrap_wxEventTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEventTable, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTable::
    wrap_wxEventTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxEventTable > param0_smtptr;
  if (!get_val_smtptr_param<wxEventTable >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxEventTable const & param0 = *param0_smtptr;

  wxEventTable* _newobj = new wxEventTable(param0);
  BasicVariable::ptr res = WrapClass_wxEventTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxEventTable::wxEventTable(...)
//---------------------------------------------------
void WrapClass_wxEventTable::
    wrap_wxEventTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTable::
    wrap_wxEventTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxEventTable::wrap_wxEventTable_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxEventTable::wrap_wxEventTable_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxEventTable::wxEventTable()
//---------------------------------------------------
void WrapClass_wxEventTable::
    wrap_wxEventTable_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTable::
    wrap_wxEventTable_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxEventTable* _newobj = new wxEventTable();
  BasicVariable::ptr res = WrapClass_wxEventTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxEventTable.
//---------------------------------------------------
void WrapClass_wxEventTable::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxEventTable object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTable::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxEventTable >::CreateVar( new wxEventTable(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxEventTable & wxEventTable::operator =(wxEventTable const & param0)
//---------------------------------------------------
void WrapClass_wxEventTable::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxEventTable, "parameter named 'param0'")
  return_comments="returning a variable of type wxEventTable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxEventTable::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxEventTable > param0_smtptr;
  if (!get_val_smtptr_param<wxEventTable >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxEventTable const & param0 = *param0_smtptr;

  wxEventTable & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxEventTable >::CreateVar(res);
}

