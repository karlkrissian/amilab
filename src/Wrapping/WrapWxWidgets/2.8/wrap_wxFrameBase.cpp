/**
 * C++ Interface: wrap_wxFrameBase
 *
 * Description: wrapping wxFrameBase
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

#include "wrap_wxFrameBase.h"

// get all the required includes
// #include "..."
#ifndef wxFrame_declared
  #define wxFrame_declared
  AMI_DECLARE_TYPE(wxFrame)
#endif
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
#ifndef wxMenuBar_declared
  #define wxMenuBar_declared
  AMI_DECLARE_TYPE(wxMenuBar)
#endif
#ifndef wxStatusBar_declared
  #define wxStatusBar_declared
  AMI_DECLARE_TYPE(wxStatusBar)
#endif
#ifndef wxToolBar_declared
  #define wxToolBar_declared
  AMI_DECLARE_TYPE(wxToolBar)
#endif
#ifndef wxMenuEvent_declared
  #define wxMenuEvent_declared
  AMI_DECLARE_TYPE(wxMenuEvent)
#endif
#ifndef wxMenu_declared
  #define wxMenu_declared
  AMI_DECLARE_TYPE(wxMenu)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxFrameBase>::CreateVar( ParamList* p)
{
  WrapClass_wxFrameBase::wrap_wxFrameBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxFrameBase);
AMI_DEFINE_VARFROMSMTPTR(wxFrameBase);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxFrameBase>::CreateVar( wxFrameBase* val, bool nodeleter)
{ 
  boost::shared_ptr<wxFrameBase> obj_ptr(val,smartpointer_nodeleter<wxFrameBase>());
  return AMILabType<wxFrameBase>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxFrameBase
//
Variable<AMIObject>::ptr WrapClass_wxFrameBase::CreateVar( wxFrameBase* sp)
{
  boost::shared_ptr<wxFrameBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxFrameBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxFrameBase>::CreateVar(
      new WrapClass_wxFrameBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxFrameBase::AddMethods(WrapClass<wxFrameBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_New( this_ptr);
  AddVar_GetClientAreaOrigin( this_ptr);
  AddVar_SendSizeEvent( this_ptr);
  AddVar_SetMenuBar( this_ptr);
  AddVar_GetMenuBar( this_ptr);
  AddVar_ProcessCommand( this_ptr);
  AddVar_CreateStatusBar( this_ptr);
  AddVar_OnCreateStatusBar( this_ptr);
  AddVar_GetStatusBar( this_ptr);
  AddVar_SetStatusBar( this_ptr);
  AddVar_SetStatusText( this_ptr);
  AddVar_SetStatusWidths( this_ptr);
  AddVar_PushStatusText( this_ptr);
  AddVar_PopStatusText( this_ptr);
  AddVar_SetStatusBarPane( this_ptr);
  AddVar_GetStatusBarPane( this_ptr);
  AddVar_CreateToolBar( this_ptr);
  AddVar_OnCreateToolBar( this_ptr);
  AddVar_GetToolBar( this_ptr);
  AddVar_SetToolBar( this_ptr);
  AddVar_OnMenuOpen( this_ptr);
  AddVar_OnMenuClose( this_ptr);
  AddVar_OnMenuHighlight( this_ptr);
  AddVar_DoMenuUpdates( this_ptr);
  AddVar_UpdateWindowUI( this_ptr);
  AddVar_OnInternalIdle( this_ptr);
  AddVar_DoGiveHelp( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxTopLevelWindow
  boost::shared_ptr<wxTopLevelWindow > parent_wxTopLevelWindow(  boost::dynamic_pointer_cast<wxTopLevelWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxTopLevelWindow = AMILabType<wxTopLevelWindow >::CreateVarFromSmtPtr(parent_wxTopLevelWindow);
  context->AddVar("wxTopLevelWindow",var_wxTopLevelWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxTopLevelWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxTopLevelWindow);
  context->AddDefault(obj_wxTopLevelWindow->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFrameBase_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxFrameBase");
    WrapClass_wxFrameBase::AddVar_wxFrameBase(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxFrameBase::wxFrameBase()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_wxFrameBase::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_wxFrameBase::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFrameBase* _newobj = new wxFrameBase();
  BasicVariable::ptr res = WrapClass_wxFrameBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of wxFrame * wxFrameBase::New(wxWindow * parent, wxWindowID winid, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_New::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:541072960)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxFrameNameStr)")
  return_comments="returning a variable of type wxFrame";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_New::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>7) ClassHelpAndReturn;
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

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 541072960;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxFrameNameStr) );

  wxFrame * res =   this->_objectptr->GetObj()->New(parent, winid, title, pos, size, style, name);
  BasicVariable::ptr res_var = AMILabType<wxFrame >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxFrameBase::GetClientAreaOrigin()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_GetClientAreaOrigin::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_GetClientAreaOrigin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxPoint res =   this->_objectptr->GetObj()->GetClientAreaOrigin();
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SendSizeEvent()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SendSizeEvent::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SendSizeEvent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SendSizeEvent();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetMenuBar(wxMenuBar * menubar)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetMenuBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuBar, "parameter named 'menubar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetMenuBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxMenuBar* menubar;
  if (CheckNullVar(_p,_n))  {
    menubar=(wxMenuBar*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenuBar > menubar_smtptr;
    if (!get_val_smtptr_param<wxMenuBar >(menubar_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    menubar = menubar_smtptr.get();
  }

  this->_objectptr->GetObj()->SetMenuBar(menubar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxMenuBar * wxFrameBase::GetMenuBar()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_GetMenuBar::SetParametersComments()
{
  return_comments="returning a variable of type wxMenuBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_GetMenuBar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxMenuBar * res =   this->_objectptr->GetObj()->GetMenuBar();
  BasicVariable::ptr res_var = AMILabType<wxMenuBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxFrameBase::ProcessCommand(int winid)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_ProcessCommand::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_ProcessCommand::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->ProcessCommand(winid);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxStatusBar * wxFrameBase::CreateStatusBar(int number = 1, long int style = 65552, wxWindowID winid = 0, wxString const & name = wxStatusLineNameStr)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_CreateStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:1)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:65552)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:0)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStatusLineNameStr)")
  return_comments="returning a variable of type wxStatusBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_CreateStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int number = 1;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  long style_long = 65552;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  int winid = 0;
  if (!get_val_param<int >(winid,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxStatusLineNameStr) );

  wxStatusBar * res =   this->_objectptr->GetObj()->CreateStatusBar(number, style, winid, name);
  BasicVariable::ptr res_var = AMILabType<wxStatusBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxStatusBar * wxFrameBase::OnCreateStatusBar(int number, long int style, wxWindowID winid, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnCreateStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxStatusBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnCreateStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  int number;
  if (!get_val_param<int >(number,_p,_n,true,false)) ClassHelpAndReturn;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  wxStatusBar * res =   this->_objectptr->GetObj()->OnCreateStatusBar(number, style, winid, name);
  BasicVariable::ptr res_var = AMILabType<wxStatusBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxStatusBar * wxFrameBase::GetStatusBar()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_GetStatusBar::SetParametersComments()
{
  return_comments="returning a variable of type wxStatusBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_GetStatusBar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxStatusBar * res =   this->_objectptr->GetObj()->GetStatusBar();
  BasicVariable::ptr res_var = AMILabType<wxStatusBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetStatusBar(wxStatusBar * statBar)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxStatusBar, "parameter named 'statBar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxStatusBar* statBar;
  if (CheckNullVar(_p,_n))  {
    statBar=(wxStatusBar*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxStatusBar > statBar_smtptr;
    if (!get_val_smtptr_param<wxStatusBar >(statBar_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    statBar = statBar_smtptr.get();
  }

  this->_objectptr->GetObj()->SetStatusBar(statBar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetStatusText(wxString const & text, int number = 0)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStatusText(text, number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetStatusWidths(int n, int const * widths_field)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetStatusWidths::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widths_field'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetStatusWidths::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  int* widths_field;
  if (CheckNullVar(_p,_n))  {
    widths_field=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > widths_field_smtptr;
    if (!get_val_smtptr_param<int >(widths_field_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    widths_field = widths_field_smtptr.get();
  }

  this->_objectptr->GetObj()->SetStatusWidths(n, widths_field);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::PushStatusText(wxString const & text, int number = 0)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_PushStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_PushStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PushStatusText(text, number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::PopStatusText(int number = 0)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_PopStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_PopStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->PopStatusText(number);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetStatusBarPane(int n)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetStatusBarPane::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetStatusBarPane::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int n;
  if (!get_val_param<int >(n,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStatusBarPane(n);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxFrameBase::GetStatusBarPane()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_GetStatusBarPane::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_GetStatusBarPane::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStatusBarPane();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxToolBar * wxFrameBase::CreateToolBar(long int style = -0x00000000000000001, wxWindowID winid = wxID_ANY, wxString const & name = wxToolBarNameStr)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_CreateToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxToolBarNameStr)")
  return_comments="returning a variable of type wxToolBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_CreateToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long style_long = -0x00000000000000001;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  int winid = wxID_ANY;
  if (!get_val_param<int >(winid,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxToolBarNameStr) );

  wxToolBar * res =   this->_objectptr->GetObj()->CreateToolBar(style, winid, name);
  BasicVariable::ptr res_var = AMILabType<wxToolBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBar * wxFrameBase::OnCreateToolBar(long int style, wxWindowID winid, wxString const & name)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnCreateToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  return_comments="returning a variable of type wxToolBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnCreateToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  long style_long;
  if (!get_val_param<long >(style_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int style = style_long;

  int winid;
  if (!get_val_param<int >(winid,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  wxToolBar * res =   this->_objectptr->GetObj()->OnCreateToolBar(style, winid, name);
  BasicVariable::ptr res_var = AMILabType<wxToolBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxToolBar * wxFrameBase::GetToolBar()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_GetToolBar::SetParametersComments()
{
  return_comments="returning a variable of type wxToolBar";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_GetToolBar::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxToolBar * res =   this->_objectptr->GetObj()->GetToolBar();
  BasicVariable::ptr res_var = AMILabType<wxToolBar >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::SetToolBar(wxToolBar * toolbar)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_SetToolBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxToolBar, "parameter named 'toolbar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_SetToolBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxToolBar* toolbar;
  if (CheckNullVar(_p,_n))  {
    toolbar=(wxToolBar*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxToolBar > toolbar_smtptr;
    if (!get_val_smtptr_param<wxToolBar >(toolbar_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    toolbar = toolbar_smtptr.get();
  }

  this->_objectptr->GetObj()->SetToolBar(toolbar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::OnMenuOpen(wxMenuEvent & event)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnMenuOpen::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnMenuOpen::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMenuEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMenuOpen(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::OnMenuClose(wxMenuEvent & event)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnMenuClose::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnMenuClose::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMenuEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMenuClose(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::OnMenuHighlight(wxMenuEvent & event)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnMenuHighlight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenuEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnMenuHighlight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMenuEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMenuEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMenuEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnMenuHighlight(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::DoMenuUpdates(wxMenu * menu = 0l)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_DoMenuUpdates::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMenu, "parameter named 'menu' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_DoMenuUpdates::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxMenu* menu = 0l;
  if (CheckNullVar(_p,_n))  {
    menu=(wxMenu*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxMenu > menu_smtptr;
    if (!get_val_smtptr_param<wxMenu >(menu_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    menu = menu_smtptr.get();
  }

  this->_objectptr->GetObj()->DoMenuUpdates(menu);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_UpdateWindowUI::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxUPDATE_UI_NONE)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_UpdateWindowUI::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long flags_long = wxUPDATE_UI_NONE;;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  this->_objectptr->GetObj()->UpdateWindowUI(flags);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxFrameBase::DoGiveHelp(wxString const & text, bool show)
//---------------------------------------------------
void WrapClass_wxFrameBase::
    wrap_DoGiveHelp::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'show'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxFrameBase::
    wrap_DoGiveHelp::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  bool show;
  if (!get_val_param<bool >(show,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoGiveHelp(text, show);
  return BasicVariable::ptr();
}

