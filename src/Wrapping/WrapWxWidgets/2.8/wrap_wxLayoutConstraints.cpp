/**
 * C++ Interface: wrap_wxLayoutConstraints
 *
 * Description: wrapping wxLayoutConstraints
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

#include "wrap_wxLayoutConstraints.h"

// get all the required includes
// #include "..."
#ifndef wxLayoutConstraints_declared
  #define wxLayoutConstraints_declared
  AMI_DECLARE_TYPE(wxLayoutConstraints)
#endif
#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase)
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
BasicVariable::ptr WrapClass<wxLayoutConstraints>::CreateVar( ParamList* p)
{
  WrapClass_wxLayoutConstraints::wrap_wxLayoutConstraints construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxLayoutConstraints);
AMI_DEFINE_VARFROMSMTPTR(wxLayoutConstraints);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxLayoutConstraints
//
Variable<AMIObject>::ptr WrapClass_wxLayoutConstraints::CreateVar( wxLayoutConstraints* sp)
{
  boost::shared_ptr<wxLayoutConstraints> di_ptr(
    sp,
    wxwindow_nodeleter<wxLayoutConstraints>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxLayoutConstraints>::CreateVar(
      new WrapClass_wxLayoutConstraints(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxLayoutConstraints::AddMethods(WrapClass<wxLayoutConstraints>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SatisfyConstraints( this_ptr);
  AddVar_AreSatisfied( this_ptr);
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
void WrapClasswxLayoutConstraints_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxLayoutConstraints");
    WrapClass_wxLayoutConstraints::AddVar_wxLayoutConstraints_1(amiobject->GetContext());
  WrapClass_wxLayoutConstraints::AddVar_wxLayoutConstraints(amiobject->GetContext());
  WrapClass_wxLayoutConstraints::AddVar_wxLayoutConstraints_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxLayoutConstraints::wxLayoutConstraints(wxLayoutConstraints const & param0)
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLayoutConstraints, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxLayoutConstraints > param0_smtptr;
  if (!get_val_smtptr_param<wxLayoutConstraints >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxLayoutConstraints const & param0 = *param0_smtptr;

  wxLayoutConstraints* _newobj = new wxLayoutConstraints(param0);
  BasicVariable::ptr res = WrapClass_wxLayoutConstraints::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxLayoutConstraints::wxLayoutConstraints(...)
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxLayoutConstraints::wrap_wxLayoutConstraints_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxLayoutConstraints::wrap_wxLayoutConstraints_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxLayoutConstraints::wxLayoutConstraints()
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_wxLayoutConstraints_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxLayoutConstraints* _newobj = new wxLayoutConstraints();
  BasicVariable::ptr res = WrapClass_wxLayoutConstraints::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxLayoutConstraints.
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxLayoutConstraints object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxLayoutConstraints >::CreateVar( new wxLayoutConstraints(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxLayoutConstraints::SatisfyConstraints(wxWindowBase * win, int * noChanges)
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_SatisfyConstraints::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'win'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noChanges'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_SatisfyConstraints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* win;
  if (CheckNullVar(_p,_n))  {
    win=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > win_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    win = win_smtptr.get();
  }

  int* noChanges;
  if (CheckNullVar(_p,_n))  {
    noChanges=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > noChanges_smtptr;
    if (!get_val_smtptr_param<int >(noChanges_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    noChanges = noChanges_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->SatisfyConstraints(win, noChanges);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxLayoutConstraints::AreSatisfied()
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_AreSatisfied::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_AreSatisfied::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AreSatisfied();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxLayoutConstraints::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxLayoutConstraints & wxLayoutConstraints::operator =(wxLayoutConstraints const & param0)
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxLayoutConstraints, "parameter named 'param0'")
  return_comments="returning a variable of type wxLayoutConstraints";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxLayoutConstraints > param0_smtptr;
  if (!get_val_smtptr_param<wxLayoutConstraints >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxLayoutConstraints const & param0 = *param0_smtptr;

  wxLayoutConstraints & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxLayoutConstraints >::CreateVar(res);
}

