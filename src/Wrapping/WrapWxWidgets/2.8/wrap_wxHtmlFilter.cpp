/**
 * C++ Interface: wrap_wxHtmlFilter
 *
 * Description: wrapping wxHtmlFilter
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

#include "wrap_wxHtmlFilter.h"

// get all the required includes
// #include "..."
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxHtmlFilter_declared
  #define wxHtmlFilter_declared
  AMI_DECLARE_TYPE(wxHtmlFilter)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlFilter>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxHtmlFilter);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlFilter);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlFilter
//
Variable<AMIObject>::ptr WrapClass_wxHtmlFilter::CreateVar( wxHtmlFilter* sp)
{
  boost::shared_ptr<wxHtmlFilter> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlFilter>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlFilter>::CreateVar(
      new WrapClass_wxHtmlFilter(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlFilter::AddMethods(WrapClass<wxHtmlFilter>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


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
void WrapClasswxHtmlFilter_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlFilter");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlFilter::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlFilter::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlFilter::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlFilter & wxHtmlFilter::operator =(wxHtmlFilter const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlFilter::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlFilter, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlFilter";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlFilter::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlFilter > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlFilter >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlFilter const & param0 = *param0_smtptr;

  wxHtmlFilter & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlFilter >::CreateVar(res);
}

