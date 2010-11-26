/**
 * C++ Interface: wrap_wxList
 *
 * Description: wrapping wxList
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
#include "wrap_wxList.h"
#include "wrap_wxObjectListNode.h"
#include "wrap_wxObject.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxList.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxList>::CreateVar( ParamList* p)
{
  WrapClass_wxList::wrap_wxList construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxList);
AMI_DEFINE_VARFROMSMTPTR(wxList);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxList
//
Variable<AMIObject>::ptr WrapClass_wxList::CreateVar( wxList* sp)
{
  boost::shared_ptr<wxList> di_ptr(
    sp,
    wxwindow_nodeleter<wxList>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxList>::CreateVar(
      new WrapClass_wxList(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxList::AddMethods(WrapClass<wxList>::ptr this_ptr )
{
  
      // Add members from wxObjectList
      WrapClass_wxObjectList::ptr parent_wxObjectList(        boost::dynamic_pointer_cast<WrapClass_wxObjectList >(this_ptr));
      parent_wxObjectList->AddMethods(parent_wxObjectList);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: _9495
      AddVar_Sort( this_ptr);
*/
      AddVar_Member( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxList::wxList(wxList const & param0)
//---------------------------------------------------
void WrapClass_wxList::
    wrap_wxList_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxList, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_wxList_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxList > param0_smtptr;
  if (!get_val_smtptr_param<wxList >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxList const & param0 = *param0_smtptr;

  wxList* _newobj = new wxList(param0);
  BasicVariable::ptr res = WrapClass_wxList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxList::wxList(...)
//---------------------------------------------------
void WrapClass_wxList::
    wrap_wxList::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_wxList::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxList::wrap_wxList_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxList::wrap_wxList_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxList::wxList(int key_type = wxKEY_NONE)
//---------------------------------------------------
void WrapClass_wxList::
    wrap_wxList_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'key_type' (def:wxKEY_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_wxList_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int key_type = wxKEY_NONE;
  if (!get_val_param<int >(key_type,_p,_n,false,true)) ClassReturnEmptyVar;

  wxList* _newobj = new wxList(key_type);
  BasicVariable::ptr res = WrapClass_wxList::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxList.
//---------------------------------------------------
void WrapClass_wxList::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxList object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxList >::CreateVar( new wxList(*(this->_objectptr->GetObj())));
}
/* The following types are missing: _9495

//---------------------------------------------------
//  Wrapping of void wxList::Sort(wxSortCompareFunction compfunc)
//---------------------------------------------------
void WrapClass_wxList::
    wrap_Sort::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( _9495, "parameter named 'compfunc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_Sort::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  _9495 compfunc;
  if (!get_val_param<_9495 >(compfunc,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Sort(compfunc);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxNode * wxList::Member(wxObject * object)
//---------------------------------------------------
void WrapClass_wxList::
    wrap_Member::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxObject, "parameter named 'object'")
  return_comments="returning a variable of type wxObjectListNode";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_Member::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxObject > object_smtptr;
  if (!get_val_smtptr_param<wxObject >(object_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxObject* object = object_smtptr.get();

  wxNode * res =   this->_objectptr->GetObj()->Member(object);
  BasicVariable::ptr res_var = WrapClass_wxObjectListNode::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxList::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxList::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxList & wxList::operator =(wxList const & list)
//---------------------------------------------------
void WrapClass_wxList::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxList, "parameter named 'list'")
  return_comments="returning a variable of type wxList";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxList::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxList > list_smtptr;
  if (!get_val_smtptr_param<wxList >(list_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxList const & list = *list_smtptr;

  wxList & res =   (*this->_objectptr->GetObj()) = (list);
  return AMILabType<wxList >::CreateVar(res);
}

