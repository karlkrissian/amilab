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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxEventTable.h"


#include "wrap_wxEventTable.h"

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
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* Avoiding const pointers for the moment
      // Adding public member baseTable
      boost::shared_ptr<wxEventTable > var_baseTable_ptr(GetObj()->baseTable, smartpointer_nodeleter<wxEventTable >());
      BasicVariable::ptr var_baseTable = AMILabType<wxEventTable >::CreateVarFromSmtPtr(var_baseTable_ptr);
      if (var_baseTable.get()) {
        var_baseTable->Rename("baseTable");
        context->AddVar(var_baseTable,context);
      }
      */
      
      /* type not available
      // Adding public member entries
      boost::shared_ptr<wxEventTableEntry > var_entries_ptr(GetObj()->entries, smartpointer_nodeleter<wxEventTableEntry >());
      BasicVariable::ptr var_entries = AMILabType<wxEventTableEntry >::CreateVarFromSmtPtr(var_entries_ptr);
      if (var_entries.get()) {
        var_entries->Rename("entries");
        context->AddVar(var_entries,context);
      }
      */

};

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

