/**
 * C++ Interface: wrap_wxAuiToolBarArt
 *
 * Description: wrapping wxAuiToolBarArt
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

#include "wrap_wxAuiToolBarArt.h"

// get all the required includes
// #include "..."
#ifndef wxAuiToolBarArt_declared
  #define wxAuiToolBarArt_declared
  AMI_DECLARE_TYPE(wxAuiToolBarArt)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarArt>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxAuiToolBarArt);
AMI_DEFINE_VARFROMSMTPTR(wxAuiToolBarArt);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiToolBarArt
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBarArt::CreateVar( wxAuiToolBarArt* sp)
{
  boost::shared_ptr<wxAuiToolBarArt> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBarArt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBarArt>::CreateVar(
      new WrapClass_wxAuiToolBarArt(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiToolBarArt::AddMethods(WrapClass<wxAuiToolBarArt>::ptr this_ptr )
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
void WrapClasswxAuiToolBarArt_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiToolBarArt");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxAuiToolBarArt & wxAuiToolBarArt::operator =(wxAuiToolBarArt const & param0)
//---------------------------------------------------
void WrapClass_wxAuiToolBarArt::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarArt, "parameter named 'param0'")
  return_comments="returning a variable of type wxAuiToolBarArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarArt::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiToolBarArt > param0_smtptr;
  if (!get_val_smtptr_param<wxAuiToolBarArt >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiToolBarArt const & param0 = *param0_smtptr;

  wxAuiToolBarArt & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxAuiToolBarArt >::CreateVar(res);
}

