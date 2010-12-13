/**
 * C++ Interface: wrap_wxGDIObject
 *
 * Description: wrapping wxGDIObject
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

#include "wrap_wxGDIObject.h"

// get all the required includes
// #include "..."
#ifndef wxGDIObject_declared
  #define wxGDIObject_declared
  AMI_DECLARE_TYPE(wxGDIObject)
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
BasicVariable::ptr WrapClass<wxGDIObject>::CreateVar( ParamList* p)
{
  WrapClass_wxGDIObject::wrap_wxGDIObject construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxGDIObject);
AMI_DEFINE_VARFROMSMTPTR(wxGDIObject);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxGDIObject
//
Variable<AMIObject>::ptr WrapClass_wxGDIObject::CreateVar( wxGDIObject* sp)
{
  boost::shared_ptr<wxGDIObject> di_ptr(
    sp,
    wxwindow_nodeleter<wxGDIObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxGDIObject>::CreateVar(
      new WrapClass_wxGDIObject(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxGDIObject::AddMethods(WrapClass<wxGDIObject>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_IsNull( this_ptr);
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
void WrapClasswxGDIObject_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxGDIObject");
    WrapClass_wxGDIObject::AddVar_wxGDIObject_1(amiobject->GetContext());
  WrapClass_wxGDIObject::AddVar_wxGDIObject(amiobject->GetContext());
  WrapClass_wxGDIObject::AddVar_wxGDIObject_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxGDIObject::wxGDIObject(wxGDIObject const & param0)
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap_wxGDIObject_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxGDIObject, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap_wxGDIObject_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxGDIObject > param0_smtptr;
  if (!get_val_smtptr_param<wxGDIObject >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxGDIObject const & param0 = *param0_smtptr;

  wxGDIObject* _newobj = new wxGDIObject(param0);
  BasicVariable::ptr res = WrapClass_wxGDIObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxGDIObject::wxGDIObject(...)
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap_wxGDIObject::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap_wxGDIObject::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxGDIObject::wrap_wxGDIObject_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxGDIObject::wrap_wxGDIObject_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxGDIObject::wxGDIObject()
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap_wxGDIObject_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap_wxGDIObject_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxGDIObject* _newobj = new wxGDIObject();
  BasicVariable::ptr res = WrapClass_wxGDIObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxGDIObject.
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxGDIObject object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxGDIObject >::CreateVar( new wxGDIObject(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxGDIObject::IsNull()
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap_IsNull::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap_IsNull::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsNull();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxGDIObject::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxGDIObject & wxGDIObject::operator =(wxGDIObject const & param0)
//---------------------------------------------------
void WrapClass_wxGDIObject::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxGDIObject, "parameter named 'param0'")
  return_comments="returning a variable of type wxGDIObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxGDIObject::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxGDIObject > param0_smtptr;
  if (!get_val_smtptr_param<wxGDIObject >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxGDIObject const & param0 = *param0_smtptr;

  wxGDIObject & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxGDIObject >::CreateVar(res);
}

