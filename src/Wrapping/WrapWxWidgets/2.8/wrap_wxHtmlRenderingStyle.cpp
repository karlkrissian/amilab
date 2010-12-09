/**
 * C++ Interface: wrap_wxHtmlRenderingStyle
 *
 * Description: wrapping wxHtmlRenderingStyle
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
#include "wrap_wxHtmlRenderingStyle.h"


#include "wrap_wxHtmlRenderingStyle.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlRenderingStyle>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxHtmlRenderingStyle);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlRenderingStyle);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlRenderingStyle
//
Variable<AMIObject>::ptr WrapClass_wxHtmlRenderingStyle::CreateVar( wxHtmlRenderingStyle* sp)
{
  boost::shared_ptr<wxHtmlRenderingStyle> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlRenderingStyle>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlRenderingStyle>::CreateVar(
      new WrapClass_wxHtmlRenderingStyle(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlRenderingStyle::AddMethods(WrapClass<wxHtmlRenderingStyle>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxHtmlRenderingStyle::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlRenderingStyle");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxHtmlRenderingStyle & wxHtmlRenderingStyle::operator =(wxHtmlRenderingStyle const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlRenderingStyle::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingStyle, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlRenderingStyle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlRenderingStyle::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlRenderingStyle > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingStyle >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingStyle const & param0 = *param0_smtptr;

  wxHtmlRenderingStyle & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlRenderingStyle >::CreateVar(res);
}

