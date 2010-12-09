/**
 * C++ Interface: wrap_wxScrolledWindow
 *
 * Description: wrapping wxScrolledWindow
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
#include "wrap_wxPoint.h"
#include "wrap_wxSize.h"
#include "wrap_wxString.h"
#include "wrap_wxDC.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxScrolledWindow.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxScrolledWindow>::CreateVar( ParamList* p)
{
  WrapClass_wxScrolledWindow::wrap_wxScrolledWindow construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxScrolledWindow);
AMI_DEFINE_VARFROMSMTPTR(wxScrolledWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxScrolledWindow>::CreateVar( wxScrolledWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<wxScrolledWindow> obj_ptr(val,smartpointer_nodeleter<wxScrolledWindow>());
  return AMILabType<wxScrolledWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxScrolledWindow
//
Variable<AMIObject>::ptr WrapClass_wxScrolledWindow::CreateVar( wxScrolledWindow* sp)
{
  boost::shared_ptr<wxScrolledWindow> di_ptr(
    sp,
    wxwindow_nodeleter<wxScrolledWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxScrolledWindow>::CreateVar(
      new WrapClass_wxScrolledWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxScrolledWindow::AddMethods(WrapClass<wxScrolledWindow>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_PrepareDC( this_ptr);
  AddVar_Layout( this_ptr);
  AddVar_DoSetVirtualSize( this_ptr);
  AddVar_GetBestVirtualSize( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxPanel
  boost::shared_ptr<wxPanel > parent_wxPanel(  boost::dynamic_pointer_cast<wxPanel >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxPanel = AMILabType<wxPanel >::CreateVarFromSmtPtr(parent_wxPanel);
  context->AddVar("wxPanel",var_wxPanel);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxPanel = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxPanel);
  context->AddDefault(obj_wxPanel->Pointer()->GetContext());

  // Add base parent wxScrollHelperNative
  boost::shared_ptr<wxScrollHelperNative > parent_wxScrollHelperNative(  boost::dynamic_pointer_cast<wxScrollHelperNative >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxScrollHelperNative = AMILabType<wxScrollHelperNative >::CreateVarFromSmtPtr(parent_wxScrollHelperNative);
  context->AddVar("wxScrollHelperNative",var_wxScrollHelperNative);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxScrollHelperNative = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxScrollHelperNative);
  context->AddDefault(obj_wxScrollHelperNative->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxScrolledWindow::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxScrolledWindow");
    WrapClass_wxScrolledWindow::AddVar_wxScrolledWindow_1(amiobject->GetContext());
  WrapClass_wxScrolledWindow::AddVar_wxScrolledWindow(amiobject->GetContext());
  WrapClass_wxScrolledWindow::AddVar_wxScrolledWindow_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxScrolledWindow::wxScrolledWindow()
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxScrolledWindow* _newobj = new wxScrolledWindow();
  BasicVariable::ptr res = WrapClass_wxScrolledWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxScrolledWindow::wxScrolledWindow(...)
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxScrolledWindow::wrap_wxScrolledWindow_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxScrolledWindow::wrap_wxScrolledWindow_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxScrolledWindow::wxScrolledWindow(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 3221225472u, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:3221225472u)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_wxScrolledWindow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int winid = wxID_ANY;
  if (!get_val_param<int >(winid,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 3221225472u;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  wxScrolledWindow* _newobj = new wxScrolledWindow(parent, winid, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxScrolledWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxScrolledWindow::Create(wxWindow * parent, wxWindowID winid, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 3221225472u, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:3221225472u)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 3221225472u;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, winid, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrolledWindow::PrepareDC(wxDC & dc)
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_PrepareDC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_PrepareDC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  this->_objectptr->GetObj()->PrepareDC(dc);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxScrolledWindow::Layout()
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_Layout::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_Layout::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Layout();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxScrolledWindow::DoSetVirtualSize(int x, int y)
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_DoSetVirtualSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_DoSetVirtualSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoSetVirtualSize(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxSize wxScrolledWindow::GetBestVirtualSize()
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_GetBestVirtualSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSize";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_GetBestVirtualSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSize res =   this->_objectptr->GetObj()->GetBestVirtualSize();
  return AMILabType<wxSize >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxScrolledWindow::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxScrolledWindow::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxScrolledWindow::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

