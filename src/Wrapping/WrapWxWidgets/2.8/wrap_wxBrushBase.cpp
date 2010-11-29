/**
 * C++ Interface: wrap_wxBrushBase
 *
 * Description: wrapping wxBrushBase
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
#include "wrap_wxBrushBase.h"


#include "wrap_wxBrushBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBrushBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxBrushBase);
AMI_DEFINE_VARFROMSMTPTR(wxBrushBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBrushBase
//
Variable<AMIObject>::ptr WrapClass_wxBrushBase::CreateVar( wxBrushBase* sp)
{
  boost::shared_ptr<wxBrushBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxBrushBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBrushBase>::CreateVar(
      new WrapClass_wxBrushBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBrushBase::AddMethods(WrapClass<wxBrushBase>::ptr this_ptr )
{
  
      // Add members from wxGDIObject
      WrapClass_wxGDIObject::ptr parent_wxGDIObject(        boost::dynamic_pointer_cast<WrapClass_wxGDIObject >(this_ptr));
      parent_wxGDIObject->AddMethods(parent_wxGDIObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_IsHatch( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxBrushBase::IsHatch()
//---------------------------------------------------
void WrapClass_wxBrushBase::
    wrap_IsHatch::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrushBase::
    wrap_IsHatch::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsHatch();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxBrushBase & wxBrushBase::operator =(wxBrushBase const & param0)
//---------------------------------------------------
void WrapClass_wxBrushBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBrushBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxBrushBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrushBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBrushBase > param0_smtptr;
  if (!get_val_smtptr_param<wxBrushBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBrushBase const & param0 = *param0_smtptr;

  wxBrushBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBrushBase >::CreateVar(res);
}

