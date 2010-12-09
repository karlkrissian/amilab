/**
 * C++ Interface: wrap_wxHtmlWindow
 *
 * Description: wrapping wxHtmlWindow
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
#include "wrap_wxHtmlFilter.h"
#include "wrap_wxCursor.h"
#include "wrap_wxClassInfo.h"
#include "wrap_wxFileName.h"
#include "wrap_wxFrame.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxConfigBase.h"
#include "wrap_wxHtmlContainerCell.h"
#include "wrap_wxHtmlWinParser.h"
#include "wrap_wxHtmlLinkInfo.h"
#include "wrap_wxHtmlCell.h"
#include "wrap_wxColour.h"


#include "wrap_wxHtmlWindow.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlWindow>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlWindow::wrap_wxHtmlWindow construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlWindow);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlWindow);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlWindow>::CreateVar( wxHtmlWindow* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlWindow> obj_ptr(val,smartpointer_nodeleter<wxHtmlWindow>());
  return AMILabType<wxHtmlWindow>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlWindow
//
Variable<AMIObject>::ptr WrapClass_wxHtmlWindow::CreateVar( wxHtmlWindow* sp)
{
  boost::shared_ptr<wxHtmlWindow> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlWindow>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlWindow>::CreateVar(
      new WrapClass_wxHtmlWindow(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlWindow::AddMethods(WrapClass<wxHtmlWindow>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_Create( this_ptr);
  AddVar_SetPage( this_ptr);
  AddVar_AppendToPage( this_ptr);
  AddVar_LoadPage( this_ptr);
  AddVar_LoadFile( this_ptr);
  AddVar_GetOpenedPage( this_ptr);
  AddVar_GetOpenedAnchor( this_ptr);
  AddVar_GetOpenedPageTitle( this_ptr);
  AddVar_SetRelatedFrame( this_ptr);
  AddVar_GetRelatedFrame( this_ptr);
  AddVar_SetRelatedStatusBar( this_ptr);
  AddVar_SetFonts( this_ptr);
  AddVar_SetStandardFonts( this_ptr);
  AddVar_SetBorders( this_ptr);
  AddVar_SetBackgroundImage( this_ptr);
  AddVar_ReadCustomization( this_ptr);
  AddVar_WriteCustomization( this_ptr);
  AddVar_HistoryBack( this_ptr);
  AddVar_HistoryForward( this_ptr);
  AddVar_HistoryCanBack( this_ptr);
  AddVar_HistoryCanForward( this_ptr);
  AddVar_HistoryClear( this_ptr);
  AddVar_GetInternalRepresentation( this_ptr);
  AddVar_GetParser( this_ptr);
/* The following types are missing: wxHtmlProcessor
  AddVar_AddProcessor( this_ptr);
*/
  AddVar_OnSetTitle( this_ptr);
  AddVar_OnLinkClicked( this_ptr);
  AddVar_OnOpeningURL( this_ptr);
  AddVar_SelectWord( this_ptr);
  AddVar_SelectLine( this_ptr);
  AddVar_SelectAll( this_ptr);
  AddVar_SelectionToText( this_ptr);
  AddVar_ToText( this_ptr);
  AddVar_OnInternalIdle( this_ptr);
  AddVar_SetHTMLWindowTitle( this_ptr);
  AddVar_OnHTMLLinkClicked( this_ptr);
  AddVar_OnHTMLOpeningURL( this_ptr);
  AddVar_HTMLCoordsToWindow( this_ptr);
  AddVar_GetHTMLWindow( this_ptr);
  AddVar_GetHTMLBackgroundColour( this_ptr);
  AddVar_SetHTMLBackgroundColour( this_ptr);
  AddVar_SetHTMLBackgroundImage( this_ptr);
  AddVar_SetHTMLStatusText( this_ptr);
  AddVar_GetHTMLCursor( this_ptr);
  AddVar_DoSetPage( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxScrolledWindow
  boost::shared_ptr<wxScrolledWindow > parent_wxScrolledWindow(  boost::dynamic_pointer_cast<wxScrolledWindow >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxScrolledWindow = AMILabType<wxScrolledWindow >::CreateVarFromSmtPtr(parent_wxScrolledWindow);
  context->AddVar("wxScrolledWindow",var_wxScrolledWindow);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxScrolledWindow = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxScrolledWindow);
  context->AddDefault(obj_wxScrolledWindow->Pointer()->GetContext());

  // Add base parent wxHtmlWindowInterface
  boost::shared_ptr<wxHtmlWindowInterface > parent_wxHtmlWindowInterface(  boost::dynamic_pointer_cast<wxHtmlWindowInterface >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxHtmlWindowInterface = AMILabType<wxHtmlWindowInterface >::CreateVarFromSmtPtr(parent_wxHtmlWindowInterface);
  context->AddVar("wxHtmlWindowInterface",var_wxHtmlWindowInterface);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxHtmlWindowInterface = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxHtmlWindowInterface);
  context->AddDefault(obj_wxHtmlWindowInterface->Pointer()->GetContext());
/*
  // Add base parent wxHtmlWindowMouseHelper
  boost::shared_ptr<wxHtmlWindowMouseHelper > parent_wxHtmlWindowMouseHelper(  boost::dynamic_pointer_cast<wxHtmlWindowMouseHelper >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxHtmlWindowMouseHelper = AMILabType<wxHtmlWindowMouseHelper >::CreateVarFromSmtPtr(parent_wxHtmlWindowMouseHelper);
  context->AddVar("wxHtmlWindowMouseHelper",var_wxHtmlWindowMouseHelper);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxHtmlWindowMouseHelper = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxHtmlWindowMouseHelper);
  context->AddDefault(obj_wxHtmlWindowMouseHelper->Pointer()->GetContext());
*/

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxHtmlWindow::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlWindow");
    WrapClass_wxHtmlWindow::AddVar_wxHtmlWindow_1(amiobject->GetContext());
  WrapClass_wxHtmlWindow::AddVar_wxHtmlWindow(amiobject->GetContext());
  WrapClass_wxHtmlWindow::AddVar_wxHtmlWindow_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxHtmlWindow::AddVar_AddFilter(amiobject->GetContext());
  /* Types are missing
  WrapClass_wxHtmlWindow::AddVar_AddGlobalProcessor(amiobject->GetContext());
  */
  WrapClass_wxHtmlWindow::AddVar_GetDefaultHTMLCursor(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlWindow::wxHtmlWindow()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxHtmlWindow* _newobj = new wxHtmlWindow();
  BasicVariable::ptr res = WrapClass_wxHtmlWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxHtmlWindow::wxHtmlWindow(...)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxHtmlWindow::wrap_wxHtmlWindow_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxHtmlWindow::wrap_wxHtmlWindow_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxHtmlWindow::wxHtmlWindow(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxString const & name = 'htmlWindow')
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:4)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:'htmlWindow')")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_wxHtmlWindow_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>6) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxWindow* parent = parent_smtptr.get();

  int id = wxID_ANY;
  if (!get_val_param<int >(id,_p,_n,false,true)) ClassReturnEmptyVar;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 4;;
  if (!get_val_param<long >(style_long,_p,_n,false,true)) ClassReturnEmptyVar;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,true)) ClassReturnEmptyVar;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(L"htmlWindow") );

  wxHtmlWindow* _newobj = new wxHtmlWindow(parent, id, pos, size, style, name);
  BasicVariable::ptr res = WrapClass_wxHtmlWindow::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::AddFilter(wxHtmlFilter * filter)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_static_AddFilter::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlFilter, "parameter named 'filter'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_static_AddFilter::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlFilter > filter_smtptr;
  if (!get_val_smtptr_param<wxHtmlFilter >(filter_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlFilter* filter = filter_smtptr.get();

  wxHtmlWindow::AddFilter(filter);
  return BasicVariable::ptr();
}
/* The following types are missing: wxHtmlProcessor

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::AddGlobalProcessor(wxHtmlProcessor * processor)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_static_AddGlobalProcessor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlProcessor, "parameter named 'processor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_static_AddGlobalProcessor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlProcessor > processor_smtptr;
  if (!get_val_smtptr_param<wxHtmlProcessor >(processor_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlProcessor* processor = processor_smtptr.get();

  wxHtmlWindow::AddGlobalProcessor(processor);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxCursor wxHtmlWindow::GetDefaultHTMLCursor(wxHtmlWindowInterface::HTMLCursor type)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_static_GetDefaultHTMLCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type wxCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_static_GetDefaultHTMLCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlWindowInterface::HTMLCursor type = (wxHtmlWindowInterface::HTMLCursor) type_int;

  wxCursor res =   wxHtmlWindow::GetDefaultHTMLCursor(type);
  return AMILabType<wxCursor >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlWindow::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::Create(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxString const & name = 'htmlWindow')
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxWindow, "parameter named 'parent'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id' (def:wxID_ANY)")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos' (def:wxDefaultPosition)")
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size' (def:wxDefaultSize)")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'style' (def:4)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name' (def:'htmlWindow')")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxWindow > parent_smtptr;
  if (!get_val_smtptr_param<wxWindow >(parent_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxWindow* parent = parent_smtptr.get();

  int id = wxID_ANY;
  if (!get_val_param<int >(id,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxPoint const & pos = ( pos_smtptr.get() ? (*pos_smtptr) : wxDefaultPosition );

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxSize const & size = ( size_smtptr.get() ? (*size_smtptr) : wxDefaultSize );

  long style_long = 4;;
  if (!get_val_param<long >(style_long,_p,_n,false,false)) ClassHelpAndReturn;
  long int style = style_long;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & name = ( name_smtptr.get() ? (*name_smtptr) : wxString(L"htmlWindow") );

  bool res =   this->_objectptr->GetObj()->Create(parent, id, pos, size, style, name);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::SetPage(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  bool res =   this->_objectptr->GetObj()->SetPage(source);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::AppendToPage(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_AppendToPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_AppendToPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  bool res =   this->_objectptr->GetObj()->AppendToPage(source);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::LoadPage(wxString const & location)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_LoadPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'location'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_LoadPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > location_smtptr;
  if (!get_val_smtptr_param<wxString >(location_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & location = *location_smtptr;

  bool res =   this->_objectptr->GetObj()->LoadPage(location);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::LoadFile(wxFileName const & filename)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_LoadFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFileName, "parameter named 'filename'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_LoadFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFileName > filename_smtptr;
  if (!get_val_smtptr_param<wxFileName >(filename_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFileName const & filename = *filename_smtptr;

  bool res =   this->_objectptr->GetObj()->LoadFile(filename);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWindow::GetOpenedPage()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetOpenedPage::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetOpenedPage::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetOpenedPage();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWindow::GetOpenedAnchor()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetOpenedAnchor::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetOpenedAnchor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetOpenedAnchor();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWindow::GetOpenedPageTitle()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetOpenedPageTitle::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetOpenedPageTitle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetOpenedPageTitle();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetRelatedFrame(wxFrame * frame, wxString const & format)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetRelatedFrame::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxFrame, "parameter named 'frame'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'format'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetRelatedFrame::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxFrame > frame_smtptr;
  if (!get_val_smtptr_param<wxFrame >(frame_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxFrame* frame = frame_smtptr.get();

  boost::shared_ptr<wxString > format_smtptr;
  if (!get_val_smtptr_param<wxString >(format_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & format = *format_smtptr;

  this->_objectptr->GetObj()->SetRelatedFrame(frame, format);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFrame * wxHtmlWindow::GetRelatedFrame()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetRelatedFrame::SetParametersComments()
{
  return_comments="returning a variable of type wxFrame";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetRelatedFrame::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFrame * res =   this->_objectptr->GetObj()->GetRelatedFrame();
  BasicVariable::ptr res_var = WrapClass_wxFrame::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetRelatedStatusBar(int bar)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetRelatedStatusBar::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'bar'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetRelatedStatusBar::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int bar;
  if (!get_val_param<int >(bar,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetRelatedStatusBar(bar);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetFonts(wxString const & normal_face, wxString const & fixed_face, int const * sizes = 0l)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetFonts::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'normal_face'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fixed_face'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sizes' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetFonts::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > normal_face_smtptr;
  if (!get_val_smtptr_param<wxString >(normal_face_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & normal_face = *normal_face_smtptr;

  boost::shared_ptr<wxString > fixed_face_smtptr;
  if (!get_val_smtptr_param<wxString >(fixed_face_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & fixed_face = *fixed_face_smtptr;

  boost::shared_ptr<int > sizes_smtptr;
  if (!get_val_smtptr_param<int >(sizes_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* sizes = sizes_smtptr.get();

  this->_objectptr->GetObj()->SetFonts(normal_face, fixed_face, sizes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetStandardFonts(int size = -0x00000000000000001, wxString const & normal_face = wxEmptyString, wxString const & fixed_face = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetStandardFonts::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'normal_face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fixed_face' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetStandardFonts::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int size = -0x00000000000000001;
  if (!get_val_param<int >(size,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > normal_face_smtptr;
  if (!get_val_smtptr_param<wxString >(normal_face_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & normal_face = ( normal_face_smtptr.get() ? (*normal_face_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > fixed_face_smtptr;
  if (!get_val_smtptr_param<wxString >(fixed_face_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & fixed_face = ( fixed_face_smtptr.get() ? (*fixed_face_smtptr) : wxString(wxEmptyString) );

  this->_objectptr->GetObj()->SetStandardFonts(size, normal_face, fixed_face);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetBorders(int b)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetBorders::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetBorders::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int b;
  if (!get_val_param<int >(b,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetBorders(b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetBackgroundImage(wxBitmap const & bmpBg)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetBackgroundImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpBg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetBackgroundImage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmpBg_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpBg_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmpBg = *bmpBg_smtptr;

  this->_objectptr->GetObj()->SetBackgroundImage(bmpBg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::ReadCustomization(wxConfigBase * cfg, wxString path = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_ReadCustomization::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxConfigBase, "parameter named 'cfg'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_ReadCustomization::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxConfigBase > cfg_smtptr;
  if (!get_val_smtptr_param<wxConfigBase >(cfg_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxConfigBase* cfg = cfg_smtptr.get();

  wxString path = wxEmptyString;
  if (!get_val_param<wxString >(path,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ReadCustomization(cfg, path);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::WriteCustomization(wxConfigBase * cfg, wxString path = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_WriteCustomization::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxConfigBase, "parameter named 'cfg'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'path' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_WriteCustomization::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxConfigBase > cfg_smtptr;
  if (!get_val_smtptr_param<wxConfigBase >(cfg_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxConfigBase* cfg = cfg_smtptr.get();

  wxString path = wxEmptyString;
  if (!get_val_param<wxString >(path,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->WriteCustomization(cfg, path);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::HistoryBack()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HistoryBack::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HistoryBack::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HistoryBack();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::HistoryForward()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HistoryForward::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HistoryForward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HistoryForward();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::HistoryCanBack()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HistoryCanBack::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HistoryCanBack::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HistoryCanBack();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::HistoryCanForward()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HistoryCanForward::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HistoryCanForward::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->HistoryCanForward();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::HistoryClear()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HistoryClear::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HistoryClear::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->HistoryClear();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlWindow::GetInternalRepresentation()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetInternalRepresentation::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetInternalRepresentation::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->GetInternalRepresentation();
  BasicVariable::ptr res_var = WrapClass_wxHtmlContainerCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlWinParser * wxHtmlWindow::GetParser()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetParser::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlWinParser";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetParser::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlWinParser * res =   this->_objectptr->GetObj()->GetParser();
  BasicVariable::ptr res_var = WrapClass_wxHtmlWinParser::CreateVar(res);
  return res_var;
}
/* The following types are missing: wxHtmlProcessor

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::AddProcessor(wxHtmlProcessor * processor)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_AddProcessor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlProcessor, "parameter named 'processor'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_AddProcessor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlProcessor > processor_smtptr;
  if (!get_val_smtptr_param<wxHtmlProcessor >(processor_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlProcessor* processor = processor_smtptr.get();

  this->_objectptr->GetObj()->AddProcessor(processor);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::OnSetTitle(wxString const & title)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnSetTitle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnSetTitle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  this->_objectptr->GetObj()->OnSetTitle(title);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::OnLinkClicked(wxHtmlLinkInfo const & link)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnLinkClicked::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'link'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnLinkClicked::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > link_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(link_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlLinkInfo const & link = *link_smtptr;

  this->_objectptr->GetObj()->OnLinkClicked(link);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlOpeningStatus wxHtmlWindow::OnOpeningURL(wxHtmlURLType param0, wxString const & param1, wxString * param2)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnOpeningURL::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'param2'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnOpeningURL::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int param0_int;
  if (!get_val_param<int >(param0_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlURLType param0 = (wxHtmlURLType) param0_int;

  boost::shared_ptr<wxString > param1_smtptr;
  if (!get_val_smtptr_param<wxString >(param1_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & param1 = *param1_smtptr;

  boost::shared_ptr<wxString > param2_smtptr;
  if (!get_val_smtptr_param<wxString >(param2_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString* param2 = param2_smtptr.get();

  wxHtmlOpeningStatus res =   this->_objectptr->GetObj()->OnOpeningURL(param0, param1, param2);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SelectWord(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SelectWord::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SelectWord::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  this->_objectptr->GetObj()->SelectWord(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SelectLine(wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SelectLine::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SelectLine::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  this->_objectptr->GetObj()->SelectLine(pos);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SelectAll()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SelectAll::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SelectAll::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SelectAll();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWindow::SelectionToText()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SelectionToText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SelectionToText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->SelectionToText();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWindow::ToText()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_ToText::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_ToText::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->ToText();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::OnInternalIdle()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnInternalIdle::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnInternalIdle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->OnInternalIdle();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetHTMLWindowTitle(wxString const & title)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetHTMLWindowTitle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'title'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetHTMLWindowTitle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > title_smtptr;
  if (!get_val_smtptr_param<wxString >(title_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & title = *title_smtptr;

  this->_objectptr->GetObj()->SetHTMLWindowTitle(title);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::OnHTMLLinkClicked(wxHtmlLinkInfo const & link)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnHTMLLinkClicked::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'link'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnHTMLLinkClicked::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > link_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(link_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlLinkInfo const & link = *link_smtptr;

  this->_objectptr->GetObj()->OnHTMLLinkClicked(link);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlOpeningStatus wxHtmlWindow::OnHTMLOpeningURL(wxHtmlURLType type, wxString const & url, wxString * redirect)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_OnHTMLOpeningURL::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'url'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'redirect'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_OnHTMLOpeningURL::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlURLType type = (wxHtmlURLType) type_int;

  boost::shared_ptr<wxString > url_smtptr;
  if (!get_val_smtptr_param<wxString >(url_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & url = *url_smtptr;

  boost::shared_ptr<wxString > redirect_smtptr;
  if (!get_val_smtptr_param<wxString >(redirect_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString* redirect = redirect_smtptr.get();

  wxHtmlOpeningStatus res =   this->_objectptr->GetObj()->OnHTMLOpeningURL(type, url, redirect);
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxHtmlWindow::HTMLCoordsToWindow(wxHtmlCell * cell, wxPoint const & pos)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_HTMLCoordsToWindow::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'cell'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_HTMLCoordsToWindow::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlCell > cell_smtptr;
  if (!get_val_smtptr_param<wxHtmlCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlCell* cell = cell_smtptr.get();

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  wxPoint res =   this->_objectptr->GetObj()->HTMLCoordsToWindow(cell, pos);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxWindow * wxHtmlWindow::GetHTMLWindow()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetHTMLWindow::SetParametersComments()
{
  return_comments="returning a variable of type wxWindow";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetHTMLWindow::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxWindow * res =   this->_objectptr->GetObj()->GetHTMLWindow();
  BasicVariable::ptr res_var = WrapClass_wxWindow::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxColour wxHtmlWindow::GetHTMLBackgroundColour()
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetHTMLBackgroundColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetHTMLBackgroundColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour res =   this->_objectptr->GetObj()->GetHTMLBackgroundColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetHTMLBackgroundColour(wxColour const & clr)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetHTMLBackgroundColour::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetHTMLBackgroundColour::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > clr_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr = *clr_smtptr;

  this->_objectptr->GetObj()->SetHTMLBackgroundColour(clr);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetHTMLBackgroundImage(wxBitmap const & bmpBg)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetHTMLBackgroundImage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmpBg'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetHTMLBackgroundImage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmpBg_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmpBg_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmpBg = *bmpBg_smtptr;

  this->_objectptr->GetObj()->SetHTMLBackgroundImage(bmpBg);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWindow::SetHTMLStatusText(wxString const & text)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_SetHTMLStatusText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'text'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_SetHTMLStatusText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > text_smtptr;
  if (!get_val_smtptr_param<wxString >(text_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & text = *text_smtptr;

  this->_objectptr->GetObj()->SetHTMLStatusText(text);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxCursor wxHtmlWindow::GetHTMLCursor(wxHtmlWindowInterface::HTMLCursor type)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_GetHTMLCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  return_comments="returning a variable of type wxCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_GetHTMLCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlWindowInterface::HTMLCursor type = (wxHtmlWindowInterface::HTMLCursor) type_int;

  wxCursor res =   this->_objectptr->GetObj()->GetHTMLCursor(type);
  return AMILabType<wxCursor >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlWindow::DoSetPage(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlWindow::
    wrap_DoSetPage::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWindow::
    wrap_DoSetPage::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  bool res =   this->_objectptr->GetObj()->DoSetPage(source);
  return AMILabType<bool >::CreateVar(res);
}

