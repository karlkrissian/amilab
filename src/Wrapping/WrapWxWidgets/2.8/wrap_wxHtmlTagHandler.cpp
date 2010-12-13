/**
 * C++ Interface: wrap_wxHtmlTagHandler
 *
 * Description: wrapping wxHtmlTagHandler
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

#include "wrap_wxHtmlTagHandler.h"

// get all the required includes
// #include "..."
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxHtmlParser_declared
  #define wxHtmlParser_declared
  AMI_DECLARE_TYPE(wxHtmlParser)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlTagHandler>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlTagHandler);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlTagHandler);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlTagHandler>::CreateVar( wxHtmlTagHandler* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlTagHandler> obj_ptr(val,smartpointer_nodeleter<wxHtmlTagHandler>());
  return AMILabType<wxHtmlTagHandler>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlTagHandler
//
Variable<AMIObject>::ptr WrapClass_wxHtmlTagHandler::CreateVar( wxHtmlTagHandler* sp)
{
  boost::shared_ptr<wxHtmlTagHandler> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlTagHandler>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlTagHandler>::CreateVar(
      new WrapClass_wxHtmlTagHandler(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlTagHandler::AddMethods(WrapClass<wxHtmlTagHandler>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_SetParser( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

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
void WrapClasswxHtmlTagHandler_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlTagHandler");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlTagHandler::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlTagHandler::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagHandler::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlTagHandler::SetParser(wxHtmlParser * parser)
//---------------------------------------------------
void WrapClass_wxHtmlTagHandler::
    wrap_SetParser::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlParser, "parameter named 'parser'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlTagHandler::
    wrap_SetParser::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlParser* parser;
  if (CheckNullVar(_p,_n))  {
    parser=(wxHtmlParser*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlParser > parser_smtptr;
    if (!get_val_smtptr_param<wxHtmlParser >(parser_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parser = parser_smtptr.get();
  }

  this->_objectptr->GetObj()->SetParser(parser);
  return BasicVariable::ptr();
}

