/**
 * C++ Interface: wrap_wxFileSystemHandler
 *
 * Description: wrapping wxFileSystemHandler
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

#include "wrap_wxFileSystemHandler.h"

// get all the required includes
// #include "..."
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxFileSystemHandler_declared
  #define wxFileSystemHandler_declared
  AMI_DECLARE_TYPE(wxFileSystemHandler)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFileSystemHandler>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxFileSystemHandler);
AMI_DEFINE_VARFROMSMTPTR(wxFileSystemHandler);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFileSystemHandler
//
Variable<AMIObject>::ptr WrapClass_wxFileSystemHandler::CreateVar( wxFileSystemHandler* sp)
{
  boost::shared_ptr<wxFileSystemHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxFileSystemHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFileSystemHandler>::CreateVar(
      new WrapClass_wxFileSystemHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFileSystemHandler::AddMethods(WrapClass<wxFileSystemHandler>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_FindFirst( this_ptr);
  AddVar_FindNext( this_ptr);
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
void WrapClasswxFileSystemHandler_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFileSystemHandler");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxString wxFileSystemHandler::FindFirst(wxString const & spec, int flags = 0)
//---------------------------------------------------
void WrapClass_wxFileSystemHandler::
    wrap_FindFirst::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'spec'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'flags' (def:0)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystemHandler::
    wrap_FindFirst::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > spec_smtptr;
  if (!get_val_smtptr_param<wxString >(spec_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & spec = *spec_smtptr;

  int flags = 0;
  if (!get_val_param<int >(flags,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FindFirst(spec, flags);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxFileSystemHandler::FindNext()
//---------------------------------------------------
void WrapClass_wxFileSystemHandler::
    wrap_FindNext::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystemHandler::
    wrap_FindNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->FindNext();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxFileSystemHandler::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxFileSystemHandler::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystemHandler::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxFileSystemHandler & wxFileSystemHandler::operator =(wxFileSystemHandler const & param0)
//---------------------------------------------------
void WrapClass_wxFileSystemHandler::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileSystemHandler, "parameter named 'param0'")
  return_comments="returning a variable of type wxFileSystemHandler";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFileSystemHandler::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFileSystemHandler > param0_smtptr;
  if (!get_val_smtptr_param<wxFileSystemHandler >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFileSystemHandler const & param0 = *param0_smtptr;

  wxFileSystemHandler & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxFileSystemHandler >::CreateVar(res);
}

