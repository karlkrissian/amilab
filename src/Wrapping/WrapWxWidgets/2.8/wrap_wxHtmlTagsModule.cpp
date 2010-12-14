/**
 * C++ Interface: wrap_wxHtmlTagsModule
 *
 * Description: wrapping wxHtmlTagsModule
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

#include "wrap_wxHtmlTagsModule.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlTagsModule_declared
  #define wxHtmlTagsModule_declared
  AMI_DECLARE_TYPE(wxHtmlTagsModule)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxHtmlWinParser_declared
  #define wxHtmlWinParser_declared
  AMI_DECLARE_TYPE(wxHtmlWinParser)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlTagsModule>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlTagsModule::wrap_wxHtmlTagsModule construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxHtmlTagsModule);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlTagsModule);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlTagsModule
//
Variable<AMIObject>::ptr WrapClass_wxHtmlTagsModule::CreateVar( wxHtmlTagsModule* sp)
{
  boost::shared_ptr<wxHtmlTagsModule> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlTagsModule>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlTagsModule>::CreateVar(
      new WrapClass_wxHtmlTagsModule(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlTagsModule::AddMethods(WrapClass<wxHtmlTagsModule>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_OnInit( this_ptr);
  AddVar_OnExit( this_ptr);
  AddVar_FillHandlersTable( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxModule
  boost::shared_ptr<wxModule > parent_wxModule(  boost::dynamic_pointer_cast<wxModule >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxModule = AMILabType<wxModule >::CreateVarFromSmtPtr(parent_wxModule);
  context->AddVar("wxModule",var_wxModule);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxModule = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxModule);
  context->AddDefault(obj_wxModule->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlTagsModule_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlTagsModule");
    WrapClass_wxHtmlTagsModule::AddVar_wxHtmlTagsModule_1(amiobject->GetContext());
  WrapClass_wxHtmlTagsModule::AddVar_wxHtmlTagsModule(amiobject->GetContext());
  WrapClass_wxHtmlTagsModule::AddVar_wxHtmlTagsModule_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlTagsModule::wxHtmlTagsModule(wxHtmlTagsModule const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagsModule, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxHtmlTagsModule > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlTagsModule >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxHtmlTagsModule const & param0 = *param0_smtptr;

  wxHtmlTagsModule* _newobj = new wxHtmlTagsModule(param0);
  BasicVariable::ptr res = WrapClass_wxHtmlTagsModule::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlTagsModule::wxHtmlTagsModule(...)
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlTagsModule::wrap_wxHtmlTagsModule_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlTagsModule::wrap_wxHtmlTagsModule_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlTagsModule::wxHtmlTagsModule()
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_wxHtmlTagsModule_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlTagsModule* _newobj = new wxHtmlTagsModule();
  BasicVariable::ptr res = WrapClass_wxHtmlTagsModule::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxHtmlTagsModule.
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxHtmlTagsModule object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxHtmlTagsModule >::CreateVar( new wxHtmlTagsModule(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlTagsModule::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlTagsModule::OnInit()
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_OnInit::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_OnInit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->OnInit();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlTagsModule::OnExit()
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_OnExit::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_OnExit::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnExit();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlTagsModule::FillHandlersTable(wxHtmlWinParser * param0)
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap_FillHandlersTable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWinParser, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap_FillHandlersTable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlWinParser* param0;
  if (CheckNullVar(_p,_n))  {
    param0=(wxHtmlWinParser*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlWinParser > param0_smtptr;
    if (!get_val_smtptr_param<wxHtmlWinParser >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    param0 = param0_smtptr.get();
  }

  this->_objectptr->GetObj()->FillHandlersTable(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlTagsModule & wxHtmlTagsModule::operator =(wxHtmlTagsModule const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlTagsModule::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagsModule, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlTagsModule";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagsModule::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlTagsModule > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlTagsModule >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlTagsModule const & param0 = *param0_smtptr;

  wxHtmlTagsModule & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlTagsModule >::CreateVar(res);
}

