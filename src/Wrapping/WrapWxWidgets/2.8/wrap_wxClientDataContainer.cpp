/**
 * C++ Interface: wrap_wxClientDataContainer
 *
 * Description: wrapping wxClientDataContainer
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

#include "wrap_wxClientDataContainer.h"

// get all the required includes
// #include "..."
#ifndef wxClientDataContainer_declared
  #define wxClientDataContainer_declared
  AMI_DECLARE_TYPE(wxClientDataContainer)
#endif
#ifndef wxClientData_declared
  #define wxClientData_declared
  AMI_DECLARE_TYPE(wxClientData)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxClientDataContainer>::CreateVar( ParamList* p)
{
  WrapClass_wxClientDataContainer::wrap_wxClientDataContainer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxClientDataContainer);
AMI_DEFINE_VARFROMSMTPTR(wxClientDataContainer);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxClientDataContainer
//
Variable<AMIObject>::ptr WrapClass_wxClientDataContainer::CreateVar( wxClientDataContainer* sp)
{
  boost::shared_ptr<wxClientDataContainer> di_ptr(
    sp,
    wxwindow_nodeleter<wxClientDataContainer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxClientDataContainer>::CreateVar(
      new WrapClass_wxClientDataContainer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxClientDataContainer::AddMethods(WrapClass<wxClientDataContainer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_SetClientObject( this_ptr);
  AddVar_GetClientObject( this_ptr);
/* The following types are missing: void
  AddVar_SetClientData( this_ptr);
*/
  AddVar_GetClientData( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxClientDataContainer_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxClientDataContainer");
    WrapClass_wxClientDataContainer::AddVar_wxClientDataContainer_1(amiobject->GetContext());
  WrapClass_wxClientDataContainer::AddVar_wxClientDataContainer(amiobject->GetContext());
  WrapClass_wxClientDataContainer::AddVar_wxClientDataContainer_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxClientDataContainer::wxClientDataContainer(wxClientDataContainer const & param0)
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientDataContainer, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxClientDataContainer > param0_smtptr;
  if (!get_val_smtptr_param<wxClientDataContainer >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxClientDataContainer const & param0 = *param0_smtptr;

  wxClientDataContainer* _newobj = new wxClientDataContainer(param0);
  BasicVariable::ptr res = WrapClass_wxClientDataContainer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxClientDataContainer::wxClientDataContainer(...)
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxClientDataContainer::wrap_wxClientDataContainer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxClientDataContainer::wrap_wxClientDataContainer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxClientDataContainer::wxClientDataContainer()
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_wxClientDataContainer_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxClientDataContainer* _newobj = new wxClientDataContainer();
  BasicVariable::ptr res = WrapClass_wxClientDataContainer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxClientDataContainer.
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxClientDataContainer object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxClientDataContainer >::CreateVar( new wxClientDataContainer(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxClientDataContainer::SetClientObject(wxClientData * data)
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_SetClientObject::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientData, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_SetClientObject::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxClientData* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxClientData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxClientData > data_smtptr;
    if (!get_val_smtptr_param<wxClientData >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetClientObject(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClientData * wxClientDataContainer::GetClientObject()
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_GetClientObject::SetParametersComments()
{
  return_comments="returning a variable of type wxClientData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_GetClientObject::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClientData * res =   this->_objectptr->GetObj()->GetClientObject();
  BasicVariable::ptr res_var = AMILabType<wxClientData >::CreateVar(res,true);
  return res_var;
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of void wxClientDataContainer::SetClientData(void * data)
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_SetClientData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_SetClientData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  void* data;
  if (CheckNullVar(_p,_n))  {
    data=(void*)NULL;
    _n++;
  } else {
    boost::shared_ptr<void > data_smtptr;
    if (!get_val_smtptr_param<void >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetClientData(data);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void * wxClientDataContainer::GetClientData()
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap_GetClientData::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap_GetClientData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->GetClientData();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClientDataContainer & wxClientDataContainer::operator =(wxClientDataContainer const & param0)
//---------------------------------------------------
void WrapClass_wxClientDataContainer::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClientDataContainer, "parameter named 'param0'")
  return_comments="returning a variable of type wxClientDataContainer";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxClientDataContainer::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxClientDataContainer > param0_smtptr;
  if (!get_val_smtptr_param<wxClientDataContainer >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxClientDataContainer const & param0 = *param0_smtptr;

  wxClientDataContainer & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxClientDataContainer >::CreateVar(res);
}

