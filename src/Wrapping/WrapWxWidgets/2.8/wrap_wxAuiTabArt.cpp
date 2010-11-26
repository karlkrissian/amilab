/**
 * C++ Interface: wrap_wxAuiTabArt
 *
 * Description: wrapping wxAuiTabArt
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
#include "wrap_wxAuiTabArt.h"


#include "wrap_wxAuiTabArt.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiTabArt>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxAuiTabArt);
AMI_DEFINE_VARFROMSMTPTR(wxAuiTabArt);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiTabArt
//
Variable<AMIObject>::ptr WrapClass_wxAuiTabArt::CreateVar( wxAuiTabArt* sp)
{
  boost::shared_ptr<wxAuiTabArt> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiTabArt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiTabArt>::CreateVar(
      new WrapClass_wxAuiTabArt(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiTabArt::AddMethods(WrapClass<wxAuiTabArt>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxAuiTabArt & wxAuiTabArt::operator =(wxAuiTabArt const & param0)
//---------------------------------------------------
void WrapClass_wxAuiTabArt::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiTabArt, "parameter named 'param0'")
  return_comments="returning a variable of type wxAuiTabArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiTabArt::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiTabArt > param0_smtptr;
  if (!get_val_smtptr_param<wxAuiTabArt >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiTabArt const & param0 = *param0_smtptr;

  wxAuiTabArt & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxAuiTabArt >::CreateVar(res);
}

