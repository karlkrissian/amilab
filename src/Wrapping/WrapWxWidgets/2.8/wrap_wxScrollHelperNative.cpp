/**
 * C++ Interface: wrap_wxScrollHelperNative
 *
 * Description: wrapping wxScrollHelperNative
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
#include "wrap_wxWindow.h"


#include "wrap_wxScrollHelperNative.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxScrollHelperNative>::CreateVar( ParamList* p)
{
  WrapClass_wxScrollHelperNative::wrap_wxScrollHelperNative construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxScrollHelperNative);
AMI_DEFINE_VARFROMSMTPTR(wxScrollHelperNative);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxScrollHelperNative>::CreateVar( wxScrollHelperNative* val, bool nodeleter)
{ 
  boost::shared_ptr<wxScrollHelperNative> obj_ptr(val,smartpointer_nodeleter<wxScrollHelperNative>());
  return AMILabType<wxScrollHelperNative>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxScrollHelperNative
//
Variable<AMIObject>::ptr WrapClass_wxScrollHelperNative::CreateVar( wxScrollHelperNative* sp)
{
  boost::shared_ptr<wxScrollHelperNative> di_ptr(
    sp,
    wxwindow_nodeleter<wxScrollHelperNative>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxScrollHelperNative>::CreateVar(
      new WrapClass_wxScrollHelperNative(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxScrollHelperNative::AddMethods(WrapClass<wxScrollHelperNative>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetScrollbars( this_ptr);
  AddVar_AdjustScrollbars( this_ptr);
  AddVar_Scroll( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxScrollHelper
  boost::shared_ptr<wxScrollHelper > parent_wxScrollHelper(  boost::dynamic_pointer_cast<wxScrollHelper >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxScrollHelper = AMILabType<wxScrollHelper >::CreateVarFromSmtPtr(parent_wxScrollHelper);
  context->AddVar("wxScrollHelper",var_wxScrollHelper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxScrollHelper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxScrollHelper);
  context->AddDefault(obj_wxScrollHelper->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxScrollHelperNative::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxScrollHelperNative");
    WrapClass_wxScrollHelperNative::AddVar_wxScrollHelperNative(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxScrollHelperNative::wxScrollHelperNative(wxWindow * win)
//---------------------------------------------------
void WrapClass_wxScrollHelperNative::
    wrap_wxScrollHelperNative::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelperNative::
    wrap_wxScrollHelperNative::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* win = win_smtptr.get();

  wxScrollHelperNative* _newobj = new wxScrollHelperNative(win);
  BasicVariable::ptr res = WrapClass_wxScrollHelperNative::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelperNative::SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY, int noUnitsX, int noUnitsY, int xPos = 0, int yPos = 0, bool noRefresh = false)
//---------------------------------------------------
void WrapClass_wxScrollHelperNative::
    wrap_SetScrollbars::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pixelsPerUnitY'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noUnitsX'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'noUnitsY'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xPos' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yPos' (def:0)")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'noRefresh' (def:false)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelperNative::
    wrap_SetScrollbars::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  int pixelsPerUnitX;
  if (!get_val_param<int >(pixelsPerUnitX,_p,_n,true,false)) ClassHelpAndReturn;

  int pixelsPerUnitY;
  if (!get_val_param<int >(pixelsPerUnitY,_p,_n,true,false)) ClassHelpAndReturn;

  int noUnitsX;
  if (!get_val_param<int >(noUnitsX,_p,_n,true,false)) ClassHelpAndReturn;

  int noUnitsY;
  if (!get_val_param<int >(noUnitsY,_p,_n,true,false)) ClassHelpAndReturn;

  int xPos = 0;
  if (!get_val_param<int >(xPos,_p,_n,false,false)) ClassHelpAndReturn;

  int yPos = 0;
  if (!get_val_param<int >(yPos,_p,_n,false,false)) ClassHelpAndReturn;

  bool noRefresh = false;
  if (!get_val_param<bool >(noRefresh,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY, xPos, yPos, noRefresh);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelperNative::AdjustScrollbars()
//---------------------------------------------------
void WrapClass_wxScrollHelperNative::
    wrap_AdjustScrollbars::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelperNative::
    wrap_AdjustScrollbars::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AdjustScrollbars();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxScrollHelperNative::Scroll(int x, int y)
//---------------------------------------------------
void WrapClass_wxScrollHelperNative::
    wrap_Scroll::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrollHelperNative::
    wrap_Scroll::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Scroll(x, y);
  return BasicVariable::ptr();
}

