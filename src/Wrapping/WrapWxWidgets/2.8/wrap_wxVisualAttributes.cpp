/**
 * C++ Interface: wrap_wxVisualAttributes
 *
 * Description: wrapping wxVisualAttributes
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
#include "wrap_wxVisualAttributes.h"


#include "wrap_wxVisualAttributes.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxVisualAttributes>::CreateVar( ParamList* p)
{
  WrapClass_wxVisualAttributes::wrap_wxVisualAttributes construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxVisualAttributes);
AMI_DEFINE_VARFROMSMTPTR(wxVisualAttributes);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxVisualAttributes
//
Variable<AMIObject>::ptr WrapClass_wxVisualAttributes::CreateVar( wxVisualAttributes* sp)
{
  boost::shared_ptr<wxVisualAttributes> di_ptr(
    sp,
    wxwindow_nodeleter<wxVisualAttributes>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxVisualAttributes>::CreateVar(
      new WrapClass_wxVisualAttributes(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxVisualAttributes::AddMethods(WrapClass<wxVisualAttributes>::ptr this_ptr )
{
  


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member font
      boost::shared_ptr<wxFont > var_font_ptr(&GetObj()->font, smartpointer_nodeleter<wxFont >());
      BasicVariable::ptr var_font = AMILabType<wxFont >::CreateVarFromSmtPtr(var_font_ptr);
      if (var_font.get()) {
        var_font->Rename("font");
        context->AddVar(var_font,context);
      }
      
      // Adding public member colFg
      boost::shared_ptr<wxColour > var_colFg_ptr(&GetObj()->colFg, smartpointer_nodeleter<wxColour >());
      BasicVariable::ptr var_colFg = AMILabType<wxColour >::CreateVarFromSmtPtr(var_colFg_ptr);
      if (var_colFg.get()) {
        var_colFg->Rename("colFg");
        context->AddVar(var_colFg,context);
      }
      
      // Adding public member colBg
      boost::shared_ptr<wxColour > var_colBg_ptr(&GetObj()->colBg, smartpointer_nodeleter<wxColour >());
      BasicVariable::ptr var_colBg = AMILabType<wxColour >::CreateVarFromSmtPtr(var_colBg_ptr);
      if (var_colBg.get()) {
        var_colBg->Rename("colBg");
        context->AddVar(var_colBg,context);
      }

};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxVisualAttributes::wxVisualAttributes(wxVisualAttributes const & param0)
//---------------------------------------------------
void WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxVisualAttributes, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxVisualAttributes > param0_smtptr;
  if (!get_val_smtptr_param<wxVisualAttributes >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxVisualAttributes const & param0 = *param0_smtptr;

  wxVisualAttributes* _newobj = new wxVisualAttributes(param0);
  BasicVariable::ptr res = WrapClass_wxVisualAttributes::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxVisualAttributes::wxVisualAttributes(...)
//---------------------------------------------------
void WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxVisualAttributes::wrap_wxVisualAttributes_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxVisualAttributes::wrap_wxVisualAttributes_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxVisualAttributes::wxVisualAttributes()
//---------------------------------------------------
void WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVisualAttributes::
    wrap_wxVisualAttributes_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxVisualAttributes* _newobj = new wxVisualAttributes();
  BasicVariable::ptr res = WrapClass_wxVisualAttributes::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxVisualAttributes.
//---------------------------------------------------
void WrapClass_wxVisualAttributes::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxVisualAttributes object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVisualAttributes::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxVisualAttributes >::CreateVar( new wxVisualAttributes(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes & wxVisualAttributes::operator =(wxVisualAttributes const & param0)
//---------------------------------------------------
void WrapClass_wxVisualAttributes::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxVisualAttributes, "parameter named 'param0'")
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxVisualAttributes::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxVisualAttributes > param0_smtptr;
  if (!get_val_smtptr_param<wxVisualAttributes >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxVisualAttributes const & param0 = *param0_smtptr;

  wxVisualAttributes & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}

