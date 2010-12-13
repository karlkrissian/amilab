/**
 * C++ Interface: wrap_wxStatusBar
 *
 * Description: wrapping wxStatusBar
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

#include "wrap_wxStatusBar.h"

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
#ifndef wxRect_declared
  #define wxRect_declared
  AMI_DECLARE_TYPE(wxRect)
#endif
#ifndef wxDC_declared
  #define wxDC_declared
  AMI_DECLARE_TYPE(wxDC)
#endif
#ifndef wxPaintEvent_declared
  #define wxPaintEvent_declared
  AMI_DECLARE_TYPE(wxPaintEvent)
#endif
#ifndef wxMouseEvent_declared
  #define wxMouseEvent_declared
  AMI_DECLARE_TYPE(wxMouseEvent)
#endif
#ifndef wxSysColourChangedEvent_declared
  #define wxSysColourChangedEvent_declared
  AMI_DECLARE_TYPE(wxSysColourChangedEvent)
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
BasicVariable::ptr WrapClass<wxStatusBar>::CreateVar( ParamList* p)
{
  WrapClass_wxStatusBar::wrap_wxStatusBar construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxStatusBar);
AMI_DEFINE_VARFROMSMTPTR(wxStatusBar);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxStatusBar>::CreateVar( wxStatusBar* val, bool nodeleter)
{ 
  boost::shared_ptr<wxStatusBar> obj_ptr(val,smartpointer_nodeleter<wxStatusBar>());
  return AMILabType<wxStatusBar>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxStatusBar
//
Variable<AMIObject>::ptr WrapClass_wxStatusBar::CreateVar( wxStatusBar* sp)
{
  boost::shared_ptr<wxStatusBar> di_ptr(
    sp,
    wxwindow_nodeleter<wxStatusBar>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxStatusBar>::CreateVar(
      new WrapClass_wxStatusBar(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxStatusBar::AddMethods(WrapClass<wxStatusBar>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Create( this_ptr);
  AddVar_SetFieldsCount( this_ptr);
  AddVar_SetStatusText( this_ptr);
  AddVar_GetStatusText( this_ptr);
  AddVar_SetStatusWidths( this_ptr);
  AddVar_GetFieldRect( this_ptr);
  AddVar_SetMinHeight( this_ptr);
  AddVar_GetBorderX( this_ptr);
  AddVar_GetBorderY( this_ptr);
  AddVar_DrawFieldText( this_ptr);
  AddVar_DrawField( this_ptr);
  AddVar_OnPaint( this_ptr);
  AddVar_OnLeftDown( this_ptr);
  AddVar_OnRightDown( this_ptr);
  AddVar_InitColours( this_ptr);
  AddVar_OnSysColourChanged( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxStatusBarBase
  boost::shared_ptr<wxStatusBarBase > parent_wxStatusBarBase(  boost::dynamic_pointer_cast<wxStatusBarBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxStatusBarBase = AMILabType<wxStatusBarBase >::CreateVarFromSmtPtr(parent_wxStatusBarBase);
  context->AddVar("wxStatusBarBase",var_wxStatusBarBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxStatusBarBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxStatusBarBase);
  context->AddDefault(obj_wxStatusBarBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStatusBar_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxStatusBar");
    WrapClass_wxStatusBar::AddVar_wxStatusBar_1(amiobject->GetContext());
  WrapClass_wxStatusBar::AddVar_wxStatusBar(amiobject->GetContext());
  WrapClass_wxStatusBar::AddVar_wxStatusBar_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxStatusBar::wxStatusBar()
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_wxStatusBar_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_wxStatusBar_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxStatusBar* _newobj = new wxStatusBar();
  BasicVariable::ptr res = WrapClass_wxStatusBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxStatusBar::wxStatusBar(...)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_wxStatusBar::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_wxStatusBar::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxStatusBar::wrap_wxStatusBar_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxStatusBar::wrap_wxStatusBar_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxStatusBar::wxStatusBar(wxWindow * parent, wxWindowID winid = wxID_ANY, long int style = 16, wxString const & name = wxStatusBarNameStr)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_wxStatusBar_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:16)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStatusBarNameStr)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_wxStatusBar_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
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

  long style_long = 16;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxStatusBarNameStr) );

  wxStatusBar* _newobj = new wxStatusBar(parent, winid, style, name);
  BasicVariable::ptr res = WrapClass_wxStatusBar::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of bool wxStatusBar::Create(wxWindow * parent, wxWindowID winid = wxID_ANY, long int style = 16, wxString const & name = wxStatusBarNameStr)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'winid' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:16)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:wxStatusBarNameStr)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
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

  long style_long = 16;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(wxStatusBarNameStr) );

  bool res =   this->_objectptr->GetObj()->Create(parent, winid, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::SetFieldsCount(int number = 1, int const * widths = 0u)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_SetFieldsCount::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:1)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widths' (def:0u)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_SetFieldsCount::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int number = 1;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  int* widths = 0u;
  if (CheckNullVar(_p,_n))  {
    widths=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > widths_smtptr;
    if (!get_val_smtptr_param<int >(widths_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    widths = widths_smtptr.get();
  }

  this->_objectptr->GetObj()->SetFieldsCount(number, widths);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::SetStatusText(wxString const & text, int number = 0)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_SetStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
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
//  Wrapping of wxString wxStatusBar::GetStatusText(int number = 0)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_GetStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number' (def:0)")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_GetStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int number = 0;
  if (!get_val_param<int >(number,_p,_n,false,false)) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetStatusText(number);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::SetStatusWidths(int n, int const * widths_field)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_SetStatusWidths::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'n'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'widths_field'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
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
//  Wrapping of bool wxStatusBar::GetFieldRect(int i, wxRect & rect)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_GetFieldRect::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
  ADDPARAMCOMMENT_TYPE( wxRect, "parameter named 'rect'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_GetFieldRect::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxRect > rect_smtptr;
  if (!get_val_smtptr_param<wxRect >(rect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxRect & rect = *rect_smtptr;

  bool res =   this->_objectptr->GetObj()->GetFieldRect(i, rect);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::SetMinHeight(int height)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_SetMinHeight::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_SetMinHeight::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetMinHeight(height);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxStatusBar::GetBorderX()
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_GetBorderX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_GetBorderX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBorderX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxStatusBar::GetBorderY()
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_GetBorderY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_GetBorderY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBorderY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::DrawFieldText(wxDC & dc, int i)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_DrawFieldText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_DrawFieldText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DrawFieldText(dc, i);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::DrawField(wxDC & dc, int i)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_DrawField::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'i'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_DrawField::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > dc_smtptr;
  if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & dc = *dc_smtptr;

  int i;
  if (!get_val_param<int >(i,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DrawField(dc, i);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::OnPaint(wxPaintEvent & event)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_OnPaint::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPaintEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_OnPaint::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPaintEvent > event_smtptr;
  if (!get_val_smtptr_param<wxPaintEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPaintEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnPaint(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::OnLeftDown(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_OnLeftDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_OnLeftDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnLeftDown(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::OnRightDown(wxMouseEvent & event)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_OnRightDown::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_OnRightDown::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnRightDown(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::InitColours()
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_InitColours::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_InitColours::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->InitColours();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxStatusBar::OnSysColourChanged(wxSysColourChangedEvent & event)
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_OnSysColourChanged::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSysColourChangedEvent, "parameter named 'event'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_OnSysColourChanged::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSysColourChangedEvent > event_smtptr;
  if (!get_val_smtptr_param<wxSysColourChangedEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSysColourChangedEvent & event = *event_smtptr;

  this->_objectptr->GetObj()->OnSysColourChanged(event);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxStatusBar::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxStatusBar::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxStatusBar::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

