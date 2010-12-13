/**
 * C++ Interface: wrap_wxObject
 *
 * Description: wrapping wxObject
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

#include "wrap_wxObject.h"

// get all the required includes
// #include "..."
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxObjectRefData_declared
  #define wxObjectRefData_declared
  AMI_DECLARE_TYPE(wxObjectRefData)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxObject>::CreateVar( ParamList* p)
{
  WrapClass_wxObject::wrap_wxObject construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxObject);
AMI_DEFINE_VARFROMSMTPTR(wxObject);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxObject
//
Variable<AMIObject>::ptr WrapClass_wxObject::CreateVar( wxObject* sp)
{
  boost::shared_ptr<wxObject> di_ptr(
    sp,
    wxwindow_nodeleter<wxObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxObject>::CreateVar(
      new WrapClass_wxObject(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxObject::AddMethods(WrapClass<wxObject>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_IsKindOf( this_ptr);
  AddVar_GetRefData( this_ptr);
  AddVar_SetRefData( this_ptr);
  AddVar_Ref( this_ptr);
  AddVar_UnRef( this_ptr);
  AddVar_UnShare( this_ptr);
  AddVar_IsSameAs( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxObject_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxObject");
    WrapClass_wxObject::AddVar_wxObject_1(amiobject->GetContext());
  WrapClass_wxObject::AddVar_wxObject(amiobject->GetContext());
  WrapClass_wxObject::AddVar_wxObject_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxObject::wxObject()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_wxObject_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_wxObject_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxObject* _newobj = new wxObject();
  BasicVariable::ptr res = WrapClass_wxObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxObject::wxObject(...)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_wxObject::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_wxObject::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxObject::wrap_wxObject_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxObject::wrap_wxObject_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxObject::wxObject(wxObject const & other)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_wxObject_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'other'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_wxObject_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxObject > other_smtptr;
  if (!get_val_smtptr_param<wxObject >(other_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxObject const & other = *other_smtptr;

  wxObject* _newobj = new wxObject(other);
  BasicVariable::ptr res = WrapClass_wxObject::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxObject.
//---------------------------------------------------
void WrapClass_wxObject::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxObject object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxObject >::CreateVar( new wxObject(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxObject::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxObject::IsKindOf(wxClassInfo * info)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_IsKindOf::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxClassInfo, "parameter named 'info'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_IsKindOf::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxClassInfo* info;
  if (CheckNullVar(_p,_n))  {
    info=(wxClassInfo*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxClassInfo > info_smtptr;
    if (!get_val_smtptr_param<wxClassInfo >(info_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    info = info_smtptr.get();
  }

  bool res =   this->_objectptr->GetObj()->IsKindOf(info);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObjectRefData * wxObject::GetRefData()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_GetRefData::SetParametersComments()
{
  return_comments="returning a variable of type wxObjectRefData";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_GetRefData::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObjectRefData * res =   this->_objectptr->GetObj()->GetRefData();
  BasicVariable::ptr res_var = AMILabType<wxObjectRefData >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxObject::SetRefData(wxObjectRefData * data)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_SetRefData::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObjectRefData, "parameter named 'data'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_SetRefData::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxObjectRefData* data;
  if (CheckNullVar(_p,_n))  {
    data=(wxObjectRefData*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxObjectRefData > data_smtptr;
    if (!get_val_smtptr_param<wxObjectRefData >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    data = data_smtptr.get();
  }

  this->_objectptr->GetObj()->SetRefData(data);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObject::Ref(wxObject const & clone)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_Ref::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'clone'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_Ref::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > clone_smtptr;
  if (!get_val_smtptr_param<wxObject >(clone_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject const & clone = *clone_smtptr;

  this->_objectptr->GetObj()->Ref(clone);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObject::UnRef()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_UnRef::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_UnRef::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UnRef();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxObject::UnShare()
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_UnShare::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_UnShare::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->UnShare();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxObject::IsSameAs(wxObject const & o)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap_IsSameAs::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'o'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap_IsSameAs::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > o_smtptr;
  if (!get_val_smtptr_param<wxObject >(o_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject const & o = *o_smtptr;

  bool res =   this->_objectptr->GetObj()->IsSameAs(o);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxObject & wxObject::operator =(wxObject const & other)
//---------------------------------------------------
void WrapClass_wxObject::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'other'")
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxObject::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > other_smtptr;
  if (!get_val_smtptr_param<wxObject >(other_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject const & other = *other_smtptr;

  wxObject & res =   (*this->_objectptr->GetObj()) = (other);
  return AMILabType<wxObject >::CreateVar(res);
}

