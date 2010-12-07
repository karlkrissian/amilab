/**
 * C++ Interface: wrap_wxAcceleratorEntry
 *
 * Description: wrapping wxAcceleratorEntry
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
#include "wrap_wxMenuItem.h"
#include "wrap_wxAcceleratorEntry.h"
#include "wrap_wxString.h"


#include "wrap_wxAcceleratorEntry.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAcceleratorEntry>::CreateVar( ParamList* p)
{
  WrapClass_wxAcceleratorEntry::wrap_wxAcceleratorEntry construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxAcceleratorEntry);
AMI_DEFINE_VARFROMSMTPTR(wxAcceleratorEntry);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAcceleratorEntry
//
Variable<AMIObject>::ptr WrapClass_wxAcceleratorEntry::CreateVar( wxAcceleratorEntry* sp)
{
  boost::shared_ptr<wxAcceleratorEntry> di_ptr(
    sp,
    wxwindow_nodeleter<wxAcceleratorEntry>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAcceleratorEntry>::CreateVar(
      new WrapClass_wxAcceleratorEntry(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAcceleratorEntry::AddMethods(WrapClass<wxAcceleratorEntry>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Set( this_ptr);
      AddVar_SetMenuItem( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_GetKeyCode( this_ptr);
      AddVar_GetCommand( this_ptr);
      AddVar_GetMenuItem( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_ToString( this_ptr);
      AddVar_FromString( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxAcceleratorEntry::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAcceleratorEntry");
    WrapClass_wxAcceleratorEntry::AddVar_wxAcceleratorEntry_1(amiobject->GetContext());
  WrapClass_wxAcceleratorEntry::AddVar_wxAcceleratorEntry(amiobject->GetContext());
  WrapClass_wxAcceleratorEntry::AddVar_wxAcceleratorEntry_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxAcceleratorEntry::AddVar_Create(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxAcceleratorEntry::wxAcceleratorEntry(int flags = 0, int keyCode = 0, int cmd = 0, wxMenuItem * item = 0l)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyCode' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cmd' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n,false,true)) ClassReturnEmptyVar;

  int keyCode = 0;
  if (!get_val_param<int >(keyCode,_p,_n,false,true)) ClassReturnEmptyVar;

  int cmd = 0;
  if (!get_val_param<int >(cmd,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxMenuItem* item = item_smtptr.get();

  wxAcceleratorEntry* _newobj = new wxAcceleratorEntry(flags, keyCode, cmd, item);
  BasicVariable::ptr res = WrapClass_wxAcceleratorEntry::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxAcceleratorEntry::wxAcceleratorEntry(...)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxAcceleratorEntry::wrap_wxAcceleratorEntry_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxAcceleratorEntry::wrap_wxAcceleratorEntry_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxAcceleratorEntry::wxAcceleratorEntry(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_wxAcceleratorEntry_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  wxAcceleratorEntry* _newobj = new wxAcceleratorEntry(entry);
  BasicVariable::ptr res = WrapClass_wxAcceleratorEntry::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorEntry * wxAcceleratorEntry::Create(wxString const & str)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_static_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type wxAcceleratorEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_static_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  wxAcceleratorEntry * res =   wxAcceleratorEntry::Create(str);
  BasicVariable::ptr res_var = WrapClass_wxAcceleratorEntry::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxAcceleratorEntry.
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxAcceleratorEntry object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxAcceleratorEntry >::CreateVar( new wxAcceleratorEntry(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxAcceleratorEntry::Set(int flags, int keyCode, int cmd, wxMenuItem * item = 0l)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_Set::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'keyCode'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'cmd'")
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_Set::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int flags;
  if (!get_val_param<int >(flags,_p,_n,true,false)) ClassHelpAndReturn;

  int keyCode;
  if (!get_val_param<int >(keyCode,_p,_n,true,false)) ClassHelpAndReturn;

  int cmd;
  if (!get_val_param<int >(cmd,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* item = item_smtptr.get();

  this->_objectptr->GetObj()->Set(flags, keyCode, cmd, item);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxAcceleratorEntry::SetMenuItem(wxMenuItem * item)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_SetMenuItem::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuItem, "parameter named 'item'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_SetMenuItem::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuItem > item_smtptr;
  if (!get_val_smtptr_param<wxMenuItem >(item_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuItem* item = item_smtptr.get();

  this->_objectptr->GetObj()->SetMenuItem(item);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxAcceleratorEntry::GetFlags()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_GetFlags::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_GetFlags::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFlags();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAcceleratorEntry::GetKeyCode()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_GetKeyCode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_GetKeyCode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetKeyCode();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxAcceleratorEntry::GetCommand()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_GetCommand::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_GetCommand::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCommand();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxMenuItem * wxAcceleratorEntry::GetMenuItem()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_GetMenuItem::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuItem";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_GetMenuItem::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuItem * res =   this->_objectptr->GetObj()->GetMenuItem();
  BasicVariable::ptr res_var = WrapClass_wxMenuItem::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorEntry::IsOk()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxAcceleratorEntry::ToString()
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_ToString::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_ToString::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->ToString();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorEntry::FromString(wxString const & str)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap_FromString::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'str'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap_FromString::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > str_smtptr;
  if (!get_val_smtptr_param<wxString >(str_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & str = *str_smtptr;

  bool res =   this->_objectptr->GetObj()->FromString(str);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxAcceleratorEntry & wxAcceleratorEntry::operator =(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
  return_comments="returning a variable of type wxAcceleratorEntry";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  wxAcceleratorEntry & res =   (*this->_objectptr->GetObj()) = (entry);
  return AMILabType<wxAcceleratorEntry >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorEntry::operator ==(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (entry);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxAcceleratorEntry::operator !=(wxAcceleratorEntry const & entry)
//---------------------------------------------------
void WrapClass_wxAcceleratorEntry::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAcceleratorEntry, "parameter named 'entry'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAcceleratorEntry::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAcceleratorEntry > entry_smtptr;
  if (!get_val_smtptr_param<wxAcceleratorEntry >(entry_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAcceleratorEntry const & entry = *entry_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (entry);
  return AMILabType<bool >::CreateVar(res);
}

