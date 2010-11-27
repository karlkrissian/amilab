/**
 * C++ Interface: wrap_wxStaticBox
 *
 * Description: wrapping wxStaticBox
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
#include "wrap_wxVisualAttributes.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxStaticBox.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxStaticBox>::CreateVar( ParamList* p)
{
  WrapClass_wxStaticBox::wrap_wxStaticBox construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStaticBox);
AMI_DEFINE_VARFROMSMTPTR(wxStaticBox);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStaticBox>::CreateVar( wxStaticBox* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStaticBox> obj_ptr(val,smartpointer_nodeleter<wxStaticBox>());
  return AMILabType<wxStaticBox>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStaticBox
//
Variable<AMIObject>::ptr WrapClass_wxStaticBox::CreateVar( wxStaticBox* sp)
{
  boost::shared_ptr<wxStaticBox> di_ptr(
    sp,
    wxwindow_nodeleter<wxStaticBox>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStaticBox>::CreateVar(
      new WrapClass_wxStaticBox(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStaticBox::AddMethods(WrapClass<wxStaticBox>::ptr this_ptr )
{
  
      // Add members from wxStaticBoxBase
      WrapClass_wxStaticBoxBase::ptr parent_wxStaticBoxBase(        boost::dynamic_pointer_cast<WrapClass_wxStaticBoxBase >(this_ptr));
      parent_wxStaticBoxBase->AddMethods(parent_wxStaticBoxBase);


  // check that the method name is not a token
  
      // Adding standard methods 
      AddVar_Create( this_ptr);
      AddVar_SetLabel( this_ptr);
      AddVar_IsTransparentForMouse( this_ptr);
      AddVar_GetBordersForSizer( this_ptr);
      AddVar_GetClassInfo( this_ptr);



  
};

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStaticBox::wxStaticBox()
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_wxStaticBox_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_wxStaticBox_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxStaticBox* _newobj = new wxStaticBox();
  BasicVariable::ptr res = WrapClass_wxStaticBox::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxStaticBox::wxStaticBox(...)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_wxStaticBox::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_wxStaticBox::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStaticBox::wrap_wxStaticBox_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStaticBox::wrap_wxStaticBox_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStaticBox::wxStaticBox(wxWindow * parent, wxWindowID id, wxString const & label, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxStaticBoxNameStr)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_wxStaticBox_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStaticBoxNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_wxStaticBox_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxStaticBoxNameStr) );

  wxStaticBox* _newobj = new wxStaticBox(parent, id, label, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxStaticBox::CreateVar(_newobj);
  return res;
}
/* The following types are missing: wxWindowVariant

//---------------------------------------------------
//  Wrapping of wxVisualAttributes wxStaticBox::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_GetClassDefaultAttributes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowVariant, "parameter named 'variant' (def:wxWINDOW_VARIANT_NORMAL)")
  return_comments="returning a variable of type wxVisualAttributes";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_GetClassDefaultAttributes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL;
  if (!get_val_param<wxWindowVariant >(variant,_p,_n,false,false)) ClassHelpAndReturn;

  wxVisualAttributes res =   wxStaticBox::GetClassDefaultAttributes(variant);
  return AMILabType<wxVisualAttributes >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxStaticBox::Create(wxWindow * parent, wxWindowID id, wxString const & label, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxStaticBoxNameStr)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStaticBoxNameStr)")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 0;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxStaticBoxNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, label, pos, size, style, name);
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxStaticBox::SetLabel(wxString const & label)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_SetLabel::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'label'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_SetLabel::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > label_smtptr;
  if (!get_val_smtptr_param<wxString >(label_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & label = *label_smtptr;

  this->_objectptr->GetObj()->SetLabel(label);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxStaticBox::IsTransparentForMouse()
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_IsTransparentForMouse::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_IsTransparentForMouse::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTransparentForMouse();
  int res_int = ((res==true)?1:0);
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxStaticBox::GetBordersForSizer(int * borderTop, int * borderOther)
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_GetBordersForSizer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'borderTop'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'borderOther'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_GetBordersForSizer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > borderTop_smtptr;
  if (!get_val_smtptr_param<int >(borderTop_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* borderTop = borderTop_smtptr.get();

  boost::shared_ptr<int > borderOther_smtptr;
  if (!get_val_smtptr_param<int >(borderOther_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* borderOther = borderOther_smtptr.get();

  this->_objectptr->GetObj()->GetBordersForSizer(borderTop, borderOther);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxStaticBox::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxStaticBox::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStaticBox::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

