/**
 * C++ Interface: wrap_wxPluginInterface
 *
 * Description: wrapping wxPluginInterface
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

#include "wrap_wxPluginInterface.h"

// get all the required includes
// #include "..."
#ifndef wxPluginInterface_declared
  #define wxPluginInterface_declared
  AMI_DECLARE_TYPE(wxPluginInterface)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPluginInterface>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxPluginInterface);
AMI_DEFINE_VARFROMSMTPTR(wxPluginInterface);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPluginInterface
//
Variable<AMIObject>::ptr WrapClass_wxPluginInterface::CreateVar( wxPluginInterface* sp)
{
  boost::shared_ptr<wxPluginInterface> di_ptr(
    sp,
    wxwindow_nodeleter<wxPluginInterface>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPluginInterface>::CreateVar(
      new WrapClass_wxPluginInterface(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPluginInterface::AddMethods(WrapClass<wxPluginInterface>::ptr this_ptr )
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
void WrapClasswxPluginInterface_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPluginInterface");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxPluginInterface & wxPluginInterface::operator =(wxPluginInterface const & param0)
//---------------------------------------------------
void WrapClass_wxPluginInterface::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPluginInterface, "parameter named 'param0'")
  return_comments="returning a variable of type wxPluginInterface";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPluginInterface::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPluginInterface > param0_smtptr;
  if (!get_val_smtptr_param<wxPluginInterface >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPluginInterface const & param0 = *param0_smtptr;

  wxPluginInterface & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPluginInterface >::CreateVar(res);
}

