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

//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

// get all the required includes
// #include "..."
#include "wrap_wxLayoutConstraints.h"
#include "wrap_wxWindowBase.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxLayoutConstraints.h"

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
  
      // Add members from wxObject
      WrapClass_wxObject::ptr parent_wxObject(        boost::dynamic_pointer_cast<WrapClass_wxObject >(this_ptr));
      parent_wxObject->AddMethods(parent_wxObject);


  // check that the method name is not a token
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_SatisfyConstraints( this_ptr);
      AddVar_AreSatisfied( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* type not available
      // Adding public member left
      boost::shared_ptr<wxIndividualLayoutConstraint > var_left_ptr(&GetObj()->left, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_left = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_left_ptr);
      if (var_left.get()) {
        var_left->Rename("left");
        context->AddVar(var_left,context);
      }
      */
      
      /* type not available
      // Adding public member top
      boost::shared_ptr<wxIndividualLayoutConstraint > var_top_ptr(&GetObj()->top, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_top = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_top_ptr);
      if (var_top.get()) {
        var_top->Rename("top");
        context->AddVar(var_top,context);
      }
      */
      
      /* type not available
      // Adding public member right
      boost::shared_ptr<wxIndividualLayoutConstraint > var_right_ptr(&GetObj()->right, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_right = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_right_ptr);
      if (var_right.get()) {
        var_right->Rename("right");
        context->AddVar(var_right,context);
      }
      */
      
      /* type not available
      // Adding public member bottom
      boost::shared_ptr<wxIndividualLayoutConstraint > var_bottom_ptr(&GetObj()->bottom, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_bottom = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_bottom_ptr);
      if (var_bottom.get()) {
        var_bottom->Rename("bottom");
        context->AddVar(var_bottom,context);
      }
      */
      
      /* type not available
      // Adding public member width
      boost::shared_ptr<wxIndividualLayoutConstraint > var_width_ptr(&GetObj()->width, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_width = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_width_ptr);
      if (var_width.get()) {
        var_width->Rename("width");
        context->AddVar(var_width,context);
      }
      */
      
      /* type not available
      // Adding public member height
      boost::shared_ptr<wxIndividualLayoutConstraint > var_height_ptr(&GetObj()->height, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_height = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_height_ptr);
      if (var_height.get()) {
        var_height->Rename("height");
        context->AddVar(var_height,context);
      }
      */
      
      /* type not available
      // Adding public member centreX
      boost::shared_ptr<wxIndividualLayoutConstraint > var_centreX_ptr(&GetObj()->centreX, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_centreX = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_centreX_ptr);
      if (var_centreX.get()) {
        var_centreX->Rename("centreX");
        context->AddVar(var_centreX,context);
      }
      */
      
      /* type not available
      // Adding public member centreY
      boost::shared_ptr<wxIndividualLayoutConstraint > var_centreY_ptr(&GetObj()->centreY, smartpointer_nodeleter<wxIndividualLayoutConstraint >());
      BasicVariable::ptr var_centreY = AMILabType<wxIndividualLayoutConstraint >::CreateVarFromSmtPtr(var_centreY_ptr);
      if (var_centreY.get()) {
        var_centreY->Rename("centreY");
        context->AddVar(var_centreY,context);
      }
      */

};

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
  if (!get_val_smtptr_param<wxLayoutConstraints >(param0_smtptr,_p,_n,true,true)) ClassReturnEmptyVar;
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
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_SatisfyConstraints::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindowBase > win_smtptr;
  if (!get_val_smtptr_param<wxWindowBase >(win_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindowBase* win = win_smtptr.get();

  boost::shared_ptr<int > noChanges_smtptr;
  if (!get_val_smtptr_param<int >(noChanges_smtptr,_p,_n)) ClassHelpAndReturn;
  int* noChanges = noChanges_smtptr.get();

  bool res =   this->_objectptr->GetObj()->SatisfyConstraints(win, noChanges);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxLayoutConstraints::AreSatisfied()
//---------------------------------------------------
void WrapClass_wxLayoutConstraints::
    wrap_AreSatisfied::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxLayoutConstraints::
    wrap_AreSatisfied::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AreSatisfied();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
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
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
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
  if (!get_val_smtptr_param<wxLayoutConstraints >(param0_smtptr,_p,_n)) ClassHelpAndReturn;
  wxLayoutConstraints const & param0 = *param0_smtptr;

  wxLayoutConstraints & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxLayoutConstraints >::CreateVar(res);
}

