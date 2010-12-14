/**
 * C++ Interface: wrap_wxAcceleratorTable
 *
 * Description: wrapping wxAcceleratorTable
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

#include "wrap_wxAcceleratorTable.h"

// get all the required includes
// #include "..."
#ifndef wxAcceleratorTable_declared
  #define wxAcceleratorTable_declared
  AMI_DECLARE_TYPE(wxAcceleratorTable)
#endif
#ifndef wxAcceleratorEntry_declared
  #define wxAcceleratorEntry_declared
  AMI_DECLARE_TYPE(wxAcceleratorEntry)
#endif
#ifndef wxMenuItem_declared
  #define wxMenuItem_declared
  AMI_DECLARE_TYPE(wxMenuItem)
#endif
#ifndef wxKeyEvent_declared
  #define wxKeyEvent_declared
  AMI_DECLARE_TYPE(wxKeyEvent)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAcceleratorTable>::CreateVar( ParamList* p)
{
  WrapClass_wxAcceleratorTable::wrap_wxAcceleratorTable construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAcceleratorTable);
AMI_DEFINE_VARFROMSMTPTR(wxAcceleratorTable);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAcceleratorTable
//
Variable<AMIObject>::ptr WrapClass_wxAcceleratorTable::CreateVar( wxAcceleratorTable* sp)
{
  boost::shared_ptr<wxAcceleratorTable> di_ptr(
    sp,
    wxwindow_nodeleter<wxAcceleratorTable>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAcceleratorTable>::CreateVar(
      new WrapClass_wxAcceleratorTable(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAcceleratorTable::AddMethods(WrapClass<wxAcceleratorTable>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Ok( this_ptr);
  AddVar_IsOk( this_ptr);
  AddVar_Add( this_ptr);
  AddVar_Remove( this_ptr);
  AddVar_GetMenuItem( this_ptr);
  AddVar_GetCommand( this_ptr);
  AddVar_GetEntry( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAcceleratorTable_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAcceleratorTable");
    WrapClass_wxAcceleratorTable::AddVar_wxAcceleratorTable_1(amiobject->GetContext());
  WrapClass_wxAcceleratorTable::AddVar_wxAcceleratorTable(amiobject->GetContext());
  WrapClass_wxAcceleratorTable::AddVar_wxAcceleratorTable_2(amiobject->GetContext());
  WrapClass_wxAcceleratorTable::AddVar_wxAcceleratorTable_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAcceleratorTable::wxAcceleratorTable(wxAcceleratorTable const & param0)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorTable, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAcceleratorTable > param0_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorTable >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAcceleratorTable const & param0 = *param0_smtptr;

  wxAcceleratorTable* _newobj = new wxAcceleratorTable(param0);
  BasicVariable::ptr res = WrapClass_wxAcceleratorTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAcceleratorTable::wxAcceleratorTable(...)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAcceleratorTable::wrap_wxAcceleratorTable_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAcceleratorTable::wrap_wxAcceleratorTable_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxAcceleratorTable::wrap_wxAcceleratorTable_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAcceleratorTable::wxAcceleratorTable()
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxAcceleratorTable* _newobj = new wxAcceleratorTable();
  BasicVariable::ptr res = WrapClass_wxAcceleratorTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAcceleratorTable::wxAcceleratorTable(int n, wxAcceleratorEntry const * entries)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entries'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_wxAcceleratorTable_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,true)) ClassReturnEmptyVar;

  wxAcceleratorEntry* entries;
  if (CheckNullVar(_p,_n))  {
    entries=(wxAcceleratorEntry*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxAcceleratorEntry > entries_smtptr;
    if (!get_val_smtptr_param<wxAcceleratorEntry >(entries_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    entries = entries_smtptr.get();
  }

  wxAcceleratorTable* _newobj = new wxAcceleratorTable(n, entries);
  BasicVariable::ptr res = WrapClass_wxAcceleratorTable::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAcceleratorTable.
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAcceleratorTable object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAcceleratorTable >::CreateVar( new wxAcceleratorTable(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorTable::Ok()
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorTable::IsOk()
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAcceleratorTable::Add(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_Add::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_Add::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  this->_objectptr->GetObj()->Add(entry);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAcceleratorTable::Remove(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_Remove::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_Remove::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  this->_objectptr->GetObj()->Remove(entry);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxAcceleratorTable::GetMenuItem(wxKeyEvent const & event)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_GetMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_GetMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent const & event = *event_smtptr;

  wxMenuItem * res =   this->_objectptr->GetObj()->GetMenuItem(event);
  BasicVariable::ptr res_var = AMILabType<wxMenuItem >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxAcceleratorTable::GetCommand(wxKeyEvent const & event)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_GetCommand::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_GetCommand::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent const & event = *event_smtptr;

  int res =   this->_objectptr->GetObj()->GetCommand(event);
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorEntry const * wxAcceleratorTable::GetEntry(wxKeyEvent const & event)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_GetEntry::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxKeyEvent, "parameter named 'event'")
  return_comments="returning a variable of type wxAcceleratorEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_GetEntry::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxKeyEvent const & event = *event_smtptr;

  wxAcceleratorEntry const * res =   this->_objectptr->GetObj()->GetEntry(event);
  BasicVariable::ptr res_var = AMILabType<wxAcceleratorEntry >::CreateVar(const_cast<wxAcceleratorEntry *>(res),true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxAcceleratorTable::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorTable & wxAcceleratorTable::operator =(wxAcceleratorTable const & param0)
//---------------------------------------------------
void WrapClass_wxAcceleratorTable::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorTable, "parameter named 'param0'")
  return_comments="returning a variable of type wxAcceleratorTable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorTable::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorTable > param0_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorTable >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorTable const & param0 = *param0_smtptr;

  wxAcceleratorTable & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxAcceleratorTable >::CreateVar(res);
}

