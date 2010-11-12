/**
 * C++ Interface: wrap_wxAuiToolBarArt
 *
 * Description: wrapping wxAuiToolBarArt
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_wxAuiToolBarArt.h"

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxAuiToolBarArt.h"


//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiToolBarArt>::CreateVar( ParamList* p)
{
//  WrapClass_wxAuiToolBarArt::wrap_wxAuiToolBarArt construct;
//  return construct.CallMember(p);
  return BasicVariable::ptr();
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxAuiToolBarArt);

//
// static member for creating a variable from a pointer to wxAuiToolBarArt
//
Variable<AMIObject>::ptr WrapClass_wxAuiToolBarArt::CreateVar( wxAuiToolBarArt* sp)
{
  boost::shared_ptr<wxAuiToolBarArt> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiToolBarArt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiToolBarArt>::CreateVar(
      new WrapClass_wxAuiToolBarArt(di_ptr)
    );
  return res;
}



//---------------------------------------------------
//  Wrapping of wxAuiToolBarArt & wxAuiToolBarArt::=(wxAuiToolBarArt & param0)
//---------------------------------------------------
void WrapClass_wxAuiToolBarArt::
    wrap_assign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiToolBarArt, "parameter named 'param0'")
  return_comments="returning a variable of type wxAuiToolBarArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiToolBarArt::
    wrap_assign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  int _n=0;
  wxAuiToolBarArt* param0_ptr;
  if (!get_val_ptr_param<wxAuiToolBarArt>(param0_ptr,_p,_n)) ClassHelpAndReturn;
  wxAuiToolBarArt& param0 = *param0_ptr;
  wxAuiToolBarArt & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxAuiToolBarArt>::CreateVar(res);
}

