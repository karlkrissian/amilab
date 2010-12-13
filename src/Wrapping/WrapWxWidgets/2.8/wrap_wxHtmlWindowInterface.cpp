/**
 * C++ Interface: wrap_wxHtmlWindowInterface
 *
 * Description: wrapping wxHtmlWindowInterface
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

#include "wrap_wxHtmlWindowInterface.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlWindowInterface_declared
  #define wxHtmlWindowInterface_declared
  AMI_DECLARE_TYPE(wxHtmlWindowInterface)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlWindowInterface>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxHtmlWindowInterface);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlWindowInterface);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlWindowInterface
//
Variable<AMIObject>::ptr WrapClass_wxHtmlWindowInterface::CreateVar( wxHtmlWindowInterface* sp)
{
  boost::shared_ptr<wxHtmlWindowInterface> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlWindowInterface>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlWindowInterface>::CreateVar(
      new WrapClass_wxHtmlWindowInterface(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlWindowInterface::AddMethods(WrapClass<wxHtmlWindowInterface>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_HTMLCursor(new AMIObject);
  obj_HTMLCursor->SetName("HTMLCursor");

  BasicVariable::ptr var_HTMLCursor_Default = AMILabType<int >::CreateVar(0);
  if (var_HTMLCursor_Default.get()) {
    var_HTMLCursor_Default->Rename("HTMLCursor_Default");
    obj_HTMLCursor->GetContext()->AddVar(var_HTMLCursor_Default,obj_HTMLCursor->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_HTMLCursor->GetName().c_str(),obj_HTMLCursor,context);


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlWindowInterface_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlWindowInterface");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxHtmlWindowInterface & wxHtmlWindowInterface::operator =(wxHtmlWindowInterface const & param0)
//---------------------------------------------------
void WrapClass_wxHtmlWindowInterface::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWindowInterface, "parameter named 'param0'")
  return_comments="returning a variable of type wxHtmlWindowInterface";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindowInterface::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlWindowInterface > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlWindowInterface >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlWindowInterface const & param0 = *param0_smtptr;

  wxHtmlWindowInterface & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxHtmlWindowInterface >::CreateVar(res);
}

