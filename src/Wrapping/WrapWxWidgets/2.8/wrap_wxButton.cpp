/**
 * C++ Interface: wrap_wxButton
 *
 * Description: wrapping wxButton
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
#include "wrap_wxString.h"
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxValidator.h"
#include "wrap_wxVisualAttributes.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxButton.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxButton>::CreateVar( ParamList* p)
{
  WrapClass_wxButton::wrap_wxButton construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxButton);
AMI_DEFINE_VARFROMSMTPTR(wxButton);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxButton>::CreateVar( wxButton* val, bool nodeleter)
{ 
  boost::shared_ptr<wxButton> obj_ptr(val,smartpointer_nodeleter<wxButton>());
  return AMILabType<wxButton>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxButton
//
Variable<AMIObject>::ptr WrapClass_wxButton::CreateVar( wxButton* sp)
{
  boost::shared_ptr<wxButton> di_ptr(
    sp,
    wxwindow_nodeleter<wxButton>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxButton>::CreateVar(
      new WrapClass_wxButton(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxButton::AddMethods(WrapClass<wxButton>::ptr this_ptr )
{
  /*
      // Add members from wxButtonBase
      WrapClass_wxButtonBase::ptr parent_wxButtonBase(        boost::dynamic_pointer_cast<WrapClass_wxButtonBase >(this_ptr));
      parent_wxButtonBase->AddMethods(parent_wxButtonBase);
      */


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetDefault( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_Enable( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
      AddVar_MoveWindow( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxButton::wxButton()
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_wxButton_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_wxButton_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxButton* _newobj = new wxButton();
  BasicVariable::ptr res = WrapClass_wxButton::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxButton::wxButton(...)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_wxButton::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_wxButton::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxButton::wrap_wxButton_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxButton::wrap_wxButton_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxButton::wxButton(wxWindow * parent, wxWindowID id, wxString const & label = wxEmptyString, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_wxButton_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxButtonNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_wxButton_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>8) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxPoint(wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxSize(wxDefaultSize) );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxButtonNameStr) );

  wxButton* _newobj = new wxButton(parent, id, label, pos, size, style, validator, name);
  BasicVariable::ptr res = WrapClass_wxButton::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxButton::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_GetClassDefaultAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'variant' (def:wxWINDOW_VARIANT_NORMAL)")
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_GetClassDefaultAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int variant_int = (int) wxWINDOW_VARIANT_NORMAL;;
  if (!get_val_param<int >(variant_int,_p,_n)) ClassHelpAndReturn;
  wxWindowVariant variant = (wxWindowVariant) variant_int;

  wxVisualAttributes res =   wxButton::GetClassDefaultAttributes(variant);
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxButton::Create(wxWindow * parent, wxWindowID id, wxString const & label = wxEmptyString, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxValidator const & validator = wxDefaultValidator, wxString const & name = wxButtonNameStr)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxValidator, "parameter named 'validator' (def:wxDefaultValidator)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxButtonNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>8) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & label = ( label_smtptr.get() ? (*label_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxPoint(wxDefaultPosition) );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxSize(wxDefaultSize) );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxValidator > validator_smtptr;
  if (!get_val_smtptr_param<wxValidator >(validator_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxValidator const & validator = ( validator_smtptr.get() ? (*validator_smtptr) : wxDefaultValidator );

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxButtonNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, label, pos, size, style, validator, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxButton::SetDefault()
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_SetDefault::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_SetDefault::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDefault();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxButton::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxButton::Enable(bool enable = 1)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'enable' (def:1)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_Enable::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int enable_int = ((1==true)?1:0);;
  if (!get_val_param<int >(enable_int,_p,_n)) ClassHelpAndReturn;
  bool enable = (bool) (enable_int>0.5);

  bool res =   this->_objectptr->GetObj()->Enable(enable);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of bool wxButton::ShouldInheritColours()
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_ShouldInheritColours::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_ShouldInheritColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ShouldInheritColours();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxButton::MoveWindow(int x, int y, int width, int height)
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_MoveWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_MoveWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n)) ClassHelpAndReturn;

  int width;
  if (!get_val_param<int >(width,_p,_n)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MoveWindow(x, y, width, height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxButton::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxButton::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxButton::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

