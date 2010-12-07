/**
 * C++ Interface: wrap_wxStaticBoxSizer
 *
 * Description: wrapping wxStaticBoxSizer
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
#include "wrap_wxStaticBox.h"
#include "wrap_wxWindow.h"
#include "wrap_wxString.h"
#include "wrap_wxSize.h"
#include "wrap_wxSizer.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxStaticBoxSizer.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStaticBoxSizer>::CreateVar( ParamList* p)
{
  WrapClass_wxStaticBoxSizer::wrap_wxStaticBoxSizer construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStaticBoxSizer);
AMI_DEFINE_VARFROMSMTPTR(wxStaticBoxSizer);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStaticBoxSizer>::CreateVar( wxStaticBoxSizer* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStaticBoxSizer> obj_ptr(val,smartpointer_nodeleter<wxStaticBoxSizer>());
  return AMILabType<wxStaticBoxSizer>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStaticBoxSizer
//
Variable<AMIObject>::ptr WrapClass_wxStaticBoxSizer::CreateVar( wxStaticBoxSizer* sp)
{
  boost::shared_ptr<wxStaticBoxSizer> di_ptr(
    sp,
    wxwindow_nodeleter<wxStaticBoxSizer>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStaticBoxSizer>::CreateVar(
      new WrapClass_wxStaticBoxSizer(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStaticBoxSizer::AddMethods(WrapClass<wxStaticBoxSizer>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding standard methods 
      AddVar_RecalcSizes( this_ptr);
      AddVar_CalcMin( this_ptr);
      AddVar_GetStaticBox( this_ptr);
      AddVar_ShowItems( this_ptr);
      AddVar_Detach_1( this_ptr);
      AddVar_Detach( this_ptr);
      AddVar_Detach_2( this_ptr);
      AddVar_Detach_3( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxBoxSizer
  boost::shared_ptr<wxBoxSizer > parent_wxBoxSizer(  boost::dynamic_pointer_cast<wxBoxSizer >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBoxSizer = AMILabType<wxBoxSizer >::CreateVarFromSmtPtr(parent_wxBoxSizer);
  context->AddVar("wxBoxSizer",var_wxBoxSizer);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBoxSizer = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBoxSizer);
  context->AddDefault(obj_wxBoxSizer->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxStaticBoxSizer::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxStaticBoxSizer");
    WrapClass_wxStaticBoxSizer::AddVar_wxStaticBoxSizer_1(amiobject->GetContext());
  WrapClass_wxStaticBoxSizer::AddVar_wxStaticBoxSizer(amiobject->GetContext());
  WrapClass_wxStaticBoxSizer::AddVar_wxStaticBoxSizer_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStaticBoxSizer::wxStaticBoxSizer(wxStaticBox * box, int orient)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStaticBox, "parameter named 'box'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxStaticBox > box_smtptr;
  if (!get_val_smtptr_param<wxStaticBox >(box_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxStaticBox* box = box_smtptr.get();

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,true)) ClassReturnEmptyVar;

  wxStaticBoxSizer* _newobj = new wxStaticBoxSizer(box, orient);
  BasicVariable::ptr res = WrapClass_wxStaticBoxSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxStaticBoxSizer::wxStaticBoxSizer(...)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStaticBoxSizer::wrap_wxStaticBoxSizer_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStaticBoxSizer::wrap_wxStaticBoxSizer_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStaticBoxSizer::wxStaticBoxSizer(int orient, wxWindow * win, wxString const & label = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'orient'")
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'win'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_wxStaticBoxSizer_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  int orient;
  if (!get_val_param<int >(orient,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxWindow > win_smtptr;
  if (!get_val_smtptr_param<wxWindow >(win_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* win = win_smtptr.get();

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  wxStaticBoxSizer* _newobj = new wxStaticBoxSizer(orient, win, label);
  BasicVariable::ptr res = WrapClass_wxStaticBoxSizer::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxStaticBoxSizer::RecalcSizes()
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_RecalcSizes::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_RecalcSizes::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->RecalcSizes();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxStaticBoxSizer::CalcMin()
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_CalcMin::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_CalcMin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->CalcMin();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStaticBox * wxStaticBoxSizer::GetStaticBox()
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_GetStaticBox::SetParametersComments()
{
  return_comments="returning a variable of type wxStaticBox";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_GetStaticBox::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStaticBox * res =   this->_objectptr->GetObj()->GetStaticBox();
  BasicVariable::ptr res_var = WrapClass_wxStaticBox::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxStaticBoxSizer::ShowItems(bool show)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_ShowItems::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_ShowItems::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool show;
  if (!get_val_param<bool >(show,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ShowItems(show);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBoxSizer::Detach(wxWindow * window)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_Detach_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'window'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_Detach_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > window_smtptr;
  if (!get_val_smtptr_param<wxWindow >(window_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* window = window_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Detach(window);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxStaticBoxSizer::Detach(...)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_Detach::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_Detach::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStaticBoxSizer::wrap_Detach_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStaticBoxSizer::wrap_Detach_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxStaticBoxSizer::wrap_Detach_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBoxSizer::Detach(wxSizer * sizer)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_Detach_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizer, "parameter named 'sizer'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_Detach_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizer > sizer_smtptr;
  if (!get_val_smtptr_param<wxSizer >(sizer_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSizer* sizer = sizer_smtptr.get();

  bool res =   this->_objectptr->GetObj()->Detach(sizer);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBoxSizer::Detach(int index)
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_Detach_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'index'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_Detach_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int index;
  if (!get_val_param<int >(index,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Detach(index);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxStaticBoxSizer::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxStaticBoxSizer::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBoxSizer::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

