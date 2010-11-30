/**
 * C++ Interface: wrap_wxPaletteBase
 *
 * Description: wrapping wxPaletteBase
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
#include "wrap_wxPaletteBase.h"


#include "wrap_wxPaletteBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPaletteBase>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxPaletteBase);
AMI_DEFINE_VARFROMSMTPTR(wxPaletteBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPaletteBase
//
Variable<AMIObject>::ptr WrapClass_wxPaletteBase::CreateVar( wxPaletteBase* sp)
{
  boost::shared_ptr<wxPaletteBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxPaletteBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPaletteBase>::CreateVar(
      new WrapClass_wxPaletteBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPaletteBase::AddMethods(WrapClass<wxPaletteBase>::ptr this_ptr )
{
  
      // Add members from wxGDIObject
      WrapClass_wxGDIObject::ptr parent_wxGDIObject(        boost::dynamic_pointer_cast<WrapClass_wxGDIObject >(this_ptr));
      parent_wxGDIObject->AddMethods(parent_wxGDIObject);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_GetColoursCount( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of bool wxPaletteBase::Ok()
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of int wxPaletteBase::GetColoursCount()
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap_GetColoursCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap_GetColoursCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetColoursCount();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPaletteBase & wxPaletteBase::operator =(wxPaletteBase const & param0)
//---------------------------------------------------
void WrapClass_wxPaletteBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaletteBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxPaletteBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPaletteBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPaletteBase > param0_smtptr;
  if (!get_val_smtptr_param<wxPaletteBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPaletteBase const & param0 = *param0_smtptr;

  wxPaletteBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPaletteBase >::CreateVar(res);
}

