/**
 * C++ Interface: wrap_wxPanel
 *
 * Description: wrapping wxPanel
 * File generated automatically using CableSwig xml output and a python script
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

/*
//#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"
*/

#include "wrap_wxPanel.h"

// get all the required includes
// #include "..."
#ifndef wxWindow_declared
  #define wxWindow_declared
  AMI_DECLARE_TYPE(wxWindow)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif
#ifndef wxSizeEvent_declared
  #define wxSizeEvent_declared
  AMI_DECLARE_TYPE(wxSizeEvent)
#endif
#ifndef wxNavigationKeyEvent_declared
  #define wxNavigationKeyEvent_declared
  AMI_DECLARE_TYPE(wxNavigationKeyEvent)
#endif
#ifndef wxFocusEvent_declared
  #define wxFocusEvent_declared
  AMI_DECLARE_TYPE(wxFocusEvent)
#endif
#ifndef wxChildFocusEvent_declared
  #define wxChildFocusEvent_declared
  AMI_DECLARE_TYPE(wxChildFocusEvent)
#endif
#ifndef wxWindowBase_declared
  #define wxWindowBase_declared
  AMI_DECLARE_TYPE(wxWindowBase)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPanel>::CreateVar( ParamList* p)
{
  WrapClass_wxPanel::wrap_wxPanel construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxPanel);
AMI_DEFINE_VARFROMSMTPTR(wxPanel);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxPanel>::CreateVar( wxPanel* val, bool nodeleter)
{ 
  boost::shared_ptr<wxPanel> obj_ptr(val,smartpointer_nodeleter<wxPanel>());
  return AMILabType<wxPanel>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPanel
//
Variable<AMIObject>::ptr WrapClass_wxPanel::CreateVar( wxPanel* sp)
{
  boost::shared_ptr<wxPanel> di_ptr(
    sp,
    wxwindow_nodeleter<wxPanel>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPanel>::CreateVar(
      new WrapClass_wxPanel(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPanel::AddMethods(WrapClass<wxPanel>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_OnSize( this_ptr);
  AddVar_InitDialog( this_ptr);
  AddVar_OnNavigationKey( this_ptr);
  AddVar_OnFocus( this_ptr);
  AddVar_OnChildFocus( this_ptr);
  AddVar_SetFocus( this_ptr);
  AddVar_SetFocusIgnoringChildren( this_ptr);
  AddVar_RemoveChild( this_ptr);
  AddVar_AcceptsFocus( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxWindow
  boost::shared_ptr<wxWindow > parent_wxWindow(  boost::dynamic_pointer_cast<wxWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxWindow = AMILabType<wxWindow >::CreateVarFromSmtPtr(parent_wxWindow);
  context->AddVar("wxWindow",var_wxWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxWindow);
  context->AddDefault(obj_wxWindow->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPanel_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPanel");
    WrapClass_wxPanel::AddVar_wxPanel_1(amiobject->GetContext());
  WrapClass_wxPanel::AddVar_wxPanel(amiobject->GetContext());
  WrapClass_wxPanel::AddVar_wxPanel_2(amiobject->GetContext());
  WrapClass_wxPanel::AddVar_wxPanel_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPanel::wxPanel()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_wxPanel_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_wxPanel_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPanel* _newobj = new wxPanel();
  BasicVariable::ptr res = WrapClass_wxPanel::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPanel::wxPanel(...)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_wxPanel::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_wxPanel::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPanel::wrap_wxPanel_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPanel::wrap_wxPanel_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxPanel::wrap_wxPanel_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPanel::wxPanel(wxWindow * parent, int x, int y, int width, int height, long int style = 2621440, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_wxPanel_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:2621440)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_wxPanel_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>7) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

  int x;
  if (!get_val_param<int >(x,_p,_n,true,true)) ClassReturnEmptyVar;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,true)) ClassReturnEmptyVar;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,true)) ClassReturnEmptyVar;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,true)) ClassReturnEmptyVar;

  long style_long = 2621440;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  wxPanel* _newobj = new wxPanel(parent, x, y, width, height, style, name);
  BasicVariable::ptr res = WrapClass_wxPanel::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPanel::wxPanel(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 2621440, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_wxPanel_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:2621440)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_wxPanel_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
    parent = parent_smtptr.get();
  }

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

  long style_long = 2621440;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxPanelNameStr) );

  wxPanel* _newobj = new wxPanel(parent, winid, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxPanel::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxPanel::Create(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 2621440, wxString const & name = wxPanelNameStr)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:2621440)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxPanelNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  wxWindow* parent;
  if (CheckNullVar(_p,_n))  {
    parent=(wxWindow*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindow > parent_smtptr;
    if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    parent = parent_smtptr.get();
  }

  int winid = wxID_ANY;
  if (!get_val_param<int >(winid,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 2621440;;
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
//  Wrapping of void wxPanel::OnSize(wxSizeEvent & event)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_OnSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizeEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_OnSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizeEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSizeEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizeEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnSize(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::InitDialog()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_InitDialog::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_InitDialog::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitDialog();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::OnNavigationKey(wxNavigationKeyEvent & event)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_OnNavigationKey::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxNavigationKeyEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_OnNavigationKey::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxNavigationKeyEvent > event_smtptr;
  if (!get_val_smtptr_param<wxNavigationKeyEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxNavigationKeyEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnNavigationKey(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::OnFocus(wxFocusEvent & event)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_OnFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_OnFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxFocusEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFocusEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnFocus(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::OnChildFocus(wxChildFocusEvent & event)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_OnChildFocus::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxChildFocusEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_OnChildFocus::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxChildFocusEvent > event_smtptr;
  if (!get_val_smtptr_param<wxChildFocusEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxChildFocusEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnChildFocus(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::SetFocus()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_SetFocus::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_SetFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocus();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::SetFocusIgnoringChildren()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_SetFocusIgnoringChildren::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_SetFocusIgnoringChildren::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFocusIgnoringChildren();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPanel::RemoveChild(wxWindowBase * child)
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_RemoveChild::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindowBase, "parameter named 'child'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_RemoveChild::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxWindowBase* child;
  if (CheckNullVar(_p,_n))  {
    child=(wxWindowBase*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxWindowBase > child_smtptr;
    if (!get_val_smtptr_param<wxWindowBase >(child_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    child = child_smtptr.get();
  }

  this->_objectptr->GetObj()->RemoveChild(child);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxPanel::AcceptsFocus()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_AcceptsFocus::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_AcceptsFocus::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->AcceptsFocus();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxPanel::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxPanel::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPanel::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

