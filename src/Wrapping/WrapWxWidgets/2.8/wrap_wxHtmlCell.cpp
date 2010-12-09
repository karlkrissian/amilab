/**
 * C++ Interface: wrap_wxHtmlCell
 *
 * Description: wrapping wxHtmlCell
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
#include "wrap_wxHtmlContainerCell.h"
#include "wrap_wxString.h"
#include "wrap_wxHtmlLinkInfo.h"
#include "wrap_wxCursor.h"
#include "wrap_wxHtmlWindowInterface.h"
#include "wrap_wxHtmlCell.h"
#include "wrap_wxDC.h"
#include "wrap_wxHtmlRenderingInfo.h"
#include "wrap_wxPoint.h"
#include "wrap_wxMouseEvent.h"
#include "wrap_wxArrayInt.h"
#include "boost/numeric/conversion/cast.hpp"
#include "wrap_wxHtmlSelection.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxHtmlCell.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlCell>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlCell::wrap_wxHtmlCell construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlCell);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlCell);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlCell>::CreateVar( wxHtmlCell* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlCell> obj_ptr(val,smartpointer_nodeleter<wxHtmlCell>());
  return AMILabType<wxHtmlCell>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlCell
//
Variable<AMIObject>::ptr WrapClass_wxHtmlCell::CreateVar( wxHtmlCell* sp)
{
  boost::shared_ptr<wxHtmlCell> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlCell>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlCell>::CreateVar(
      new WrapClass_wxHtmlCell(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlCell::AddMethods(WrapClass<wxHtmlCell>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_SetParent( this_ptr);
  AddVar_GetParent( this_ptr);
  AddVar_GetPosX( this_ptr);
  AddVar_GetPosY( this_ptr);
  AddVar_GetWidth( this_ptr);
  AddVar_GetMaxTotalWidth( this_ptr);
  AddVar_GetHeight( this_ptr);
  AddVar_GetDescent( this_ptr);
  AddVar_SetScriptMode( this_ptr);
  AddVar_GetScriptMode( this_ptr);
  AddVar_GetScriptBaseline( this_ptr);
  AddVar_IsFormattingCell( this_ptr);
  AddVar_GetId( this_ptr);
  AddVar_SetId( this_ptr);
  AddVar_GetLink( this_ptr);
  AddVar_GetMouseCursor( this_ptr);
  AddVar_GetNext( this_ptr);
  AddVar_GetFirstChild( this_ptr);
  AddVar_SetPos( this_ptr);
  AddVar_SetLink( this_ptr);
  AddVar_SetNext( this_ptr);
  AddVar_Layout( this_ptr);
  AddVar_Draw( this_ptr);
  AddVar_DrawInvisible( this_ptr);
/* The following types are missing: void
  AddVar_Find( this_ptr);
*/
  AddVar_ProcessMouseClick( this_ptr);
  AddVar_AdjustPagebreak( this_ptr);
  AddVar_SetCanLiveOnPagebreak( this_ptr);
  AddVar_IsLinebreakAllowed( this_ptr);
  AddVar_IsTerminalCell( this_ptr);
  AddVar_FindCellByPos( this_ptr);
  AddVar_GetAbsPos( this_ptr);
  AddVar_GetRootCell( this_ptr);
  AddVar_GetFirstTerminal( this_ptr);
  AddVar_GetLastTerminal( this_ptr);
  AddVar_GetDepth( this_ptr);
  AddVar_IsBefore( this_ptr);
  AddVar_ConvertToText( this_ptr);
  AddVar_GetClassInfo( this_ptr);



  

  


  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxObject
  boost::shared_ptr<wxObject > parent_wxObject(  boost::dynamic_pointer_cast<wxObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxObject = AMILabType<wxObject >::CreateVarFromSmtPtr(parent_wxObject);
  context->AddVar("wxObject",var_wxObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxObject);
  context->AddDefault(obj_wxObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxHtmlCell::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlCell");
    WrapClass_wxHtmlCell::AddVar_wxHtmlCell(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlCell::wxHtmlCell()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_wxHtmlCell::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_wxHtmlCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell* _newobj = new wxHtmlCell();
  BasicVariable::ptr res = WrapClass_wxHtmlCell::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetParent(wxHtmlContainerCell * p)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetParent::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlContainerCell, "parameter named 'p'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetParent::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlContainerCell > p_smtptr;
  if (!get_val_smtptr_param<wxHtmlContainerCell >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlContainerCell* p = p_smtptr.get();

  this->_objectptr->GetObj()->SetParent(p);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlCell::GetParent()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetParent::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetParent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->GetParent();
  BasicVariable::ptr res_var = WrapClass_wxHtmlContainerCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetPosX()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetPosX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetPosX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPosX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetPosY()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetPosY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetPosY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetPosY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetWidth()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetMaxTotalWidth()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetMaxTotalWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetMaxTotalWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetMaxTotalWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetHeight()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlCell::GetDescent()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetDescent::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetDescent::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDescent();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetScriptMode(wxHtmlScriptMode mode, long int previousBase)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetScriptMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'previousBase'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetScriptMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int mode_int;
  if (!get_val_param<int >(mode_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlScriptMode mode = (wxHtmlScriptMode) mode_int;

  long previousBase_long;
  if (!get_val_param<long >(previousBase_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int previousBase = previousBase_long;

  this->_objectptr->GetObj()->SetScriptMode(mode, previousBase);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlScriptMode wxHtmlCell::GetScriptMode()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetScriptMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetScriptMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlScriptMode res =   this->_objectptr->GetObj()->GetScriptMode();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of long int wxHtmlCell::GetScriptBaseline()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetScriptBaseline::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetScriptBaseline::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetScriptBaseline();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::IsFormattingCell()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_IsFormattingCell::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_IsFormattingCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsFormattingCell();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxHtmlCell::GetId()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetId::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetId::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetId();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetId(wxString const & id)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetId::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'id'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetId::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > id_smtptr;
  if (!get_val_smtptr_param<wxString >(id_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & id = *id_smtptr;

  this->_objectptr->GetObj()->SetId(id);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlLinkInfo * wxHtmlCell::GetLink(int param0 = 0, int param1 = 0)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetLink::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param0' (def:0)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1' (def:0)")
  return_comments="returning a variable of type wxHtmlLinkInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetLink::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int param0 = 0;
  if (!get_val_param<int >(param0,_p,_n,false,false)) ClassHelpAndReturn;

  int param1 = 0;
  if (!get_val_param<int >(param1,_p,_n,false,false)) ClassHelpAndReturn;

  wxHtmlLinkInfo * res =   this->_objectptr->GetObj()->GetLink(param0, param1);
  BasicVariable::ptr res_var = WrapClass_wxHtmlLinkInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxCursor wxHtmlCell::GetMouseCursor(wxHtmlWindowInterface * window)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetMouseCursor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWindowInterface, "parameter named 'window'")
  return_comments="returning a variable of type wxCursor";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetMouseCursor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlWindowInterface > window_smtptr;
  if (!get_val_smtptr_param<wxHtmlWindowInterface >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlWindowInterface* window = window_smtptr.get();

  wxCursor res =   this->_objectptr->GetObj()->GetMouseCursor(window);
  return AMILabType<wxCursor >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::GetNext()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetNext::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetNext::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetNext();
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::GetFirstChild()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetFirstChild::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetFirstChild::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetFirstChild();
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetPos(int x, int y)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetPos(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetLink(wxHtmlLinkInfo const & link)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetLink::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'link'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetLink::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > link_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(link_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlLinkInfo const & link = *link_smtptr;

  this->_objectptr->GetObj()->SetLink(link);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetNext(wxHtmlCell * cell)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetNext::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'cell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetNext::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlCell > cell_smtptr;
  if (!get_val_smtptr_param<wxHtmlCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlCell* cell = cell_smtptr.get();

  this->_objectptr->GetObj()->SetNext(cell);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::Layout(int w)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_Layout::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'w'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_Layout::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int w;
  if (!get_val_param<int >(w,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->Layout(w);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::Draw(wxDC & param0, int param1, int param2, int param3, int param4, wxHtmlRenderingInfo & param5)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_Draw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param2'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param3'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param4'")
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'param5'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_Draw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > param0_smtptr;
  if (!get_val_smtptr_param<wxDC >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & param0 = *param0_smtptr;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,false)) ClassHelpAndReturn;

  int param2;
  if (!get_val_param<int >(param2,_p,_n,true,false)) ClassHelpAndReturn;

  int param3;
  if (!get_val_param<int >(param3,_p,_n,true,false)) ClassHelpAndReturn;

  int param4;
  if (!get_val_param<int >(param4,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxHtmlRenderingInfo > param5_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(param5_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingInfo & param5 = *param5_smtptr;

  this->_objectptr->GetObj()->Draw(param0, param1, param2, param3, param4, param5);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::DrawInvisible(wxDC & param0, int param1, int param2, wxHtmlRenderingInfo & param3)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_DrawInvisible::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'param0'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param1'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param2'")
  ADDPARAMCOMMENT_TYPE( wxHtmlRenderingInfo, "parameter named 'param3'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_DrawInvisible::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDC > param0_smtptr;
  if (!get_val_smtptr_param<wxDC >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDC & param0 = *param0_smtptr;

  int param1;
  if (!get_val_param<int >(param1,_p,_n,true,false)) ClassHelpAndReturn;

  int param2;
  if (!get_val_param<int >(param2,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxHtmlRenderingInfo > param3_smtptr;
  if (!get_val_smtptr_param<wxHtmlRenderingInfo >(param3_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlRenderingInfo & param3 = *param3_smtptr;

  this->_objectptr->GetObj()->DrawInvisible(param0, param1, param2, param3);
  return BasicVariable::ptr();
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of wxHtmlCell const * wxHtmlCell::Find(int condition, void const * param)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_Find::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'condition'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'param'")
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_Find::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int condition;
  if (!get_val_param<int >(condition,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<void > param_smtptr;
  if (!get_val_smtptr_param<void >(param_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* param = param_smtptr.get();

  wxHtmlCell const * res =   this->_objectptr->GetObj()->Find(condition, param);
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(const_cast<wxHtmlCell *>(res));
  return res_var;
}
*/

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::ProcessMouseClick(wxHtmlWindowInterface * window, wxPoint const & pos, wxMouseEvent const & event)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_ProcessMouseClick::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWindowInterface, "parameter named 'window'")
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'pos'")
  ADDPARAMCOMMENT_TYPE( wxMouseEvent, "parameter named 'event'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_ProcessMouseClick::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlWindowInterface > window_smtptr;
  if (!get_val_smtptr_param<wxHtmlWindowInterface >(window_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlWindowInterface* window = window_smtptr.get();

  boost::shared_ptr<wxPoint > pos_smtptr;
  if (!get_val_smtptr_param<wxPoint >(pos_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & pos = *pos_smtptr;

  boost::shared_ptr<wxMouseEvent > event_smtptr;
  if (!get_val_smtptr_param<wxMouseEvent >(event_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMouseEvent const & event = *event_smtptr;

  bool res =   this->_objectptr->GetObj()->ProcessMouseClick(window, pos, event);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::AdjustPagebreak(int * pagebreak, wxArrayInt & known_pagebreaks)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_AdjustPagebreak::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'pagebreak'")
  ADDPARAMCOMMENT_TYPE( wxArrayInt, "parameter named 'known_pagebreaks'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_AdjustPagebreak::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<int > pagebreak_smtptr;
  if (!get_val_smtptr_param<int >(pagebreak_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  int* pagebreak = pagebreak_smtptr.get();

  boost::shared_ptr<wxArrayInt > known_pagebreaks_smtptr;
  if (!get_val_smtptr_param<wxArrayInt >(known_pagebreaks_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxArrayInt & known_pagebreaks = *known_pagebreaks_smtptr;

  bool res =   this->_objectptr->GetObj()->AdjustPagebreak(pagebreak, known_pagebreaks);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlCell::SetCanLiveOnPagebreak(bool can)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_SetCanLiveOnPagebreak::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( bool, "parameter named 'can'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_SetCanLiveOnPagebreak::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  bool can;
  if (!get_val_param<bool >(can,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCanLiveOnPagebreak(can);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::IsLinebreakAllowed()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_IsLinebreakAllowed::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_IsLinebreakAllowed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsLinebreakAllowed();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::IsTerminalCell()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_IsTerminalCell::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_IsTerminalCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsTerminalCell();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::FindCellByPos(wxCoord x, wxCoord y, unsigned int flags = wxHTML_FIND_EXACT)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_FindCellByPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags' (def:wxHTML_FIND_EXACT)")
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_FindCellByPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  long flags_long = boost::numeric_cast<long >((unsigned int)wxHTML_FIND_EXACT);;
  if (!get_val_param<long >(flags_long,_p,_n,false,false)) ClassHelpAndReturn;
  unsigned int flags = boost::numeric_cast<unsigned int >(flags_long);

  wxHtmlCell * res =   this->_objectptr->GetObj()->FindCellByPos(x, y, flags);
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxHtmlCell::GetAbsPos(wxHtmlCell * rootCell = 0l)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetAbsPos::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'rootCell' (def:0l)")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetAbsPos::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlCell > rootCell_smtptr;
  if (!get_val_smtptr_param<wxHtmlCell >(rootCell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlCell* rootCell = rootCell_smtptr.get();

  wxPoint res =   this->_objectptr->GetObj()->GetAbsPos(rootCell);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::GetRootCell()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetRootCell::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetRootCell::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetRootCell();
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::GetFirstTerminal()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetFirstTerminal::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetFirstTerminal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetFirstTerminal();
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlCell * wxHtmlCell::GetLastTerminal()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetLastTerminal::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetLastTerminal::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlCell * res =   this->_objectptr->GetObj()->GetLastTerminal();
  BasicVariable::ptr res_var = WrapClass_wxHtmlCell::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of unsigned int wxHtmlCell::GetDepth()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetDepth::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetDepth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  unsigned int res =   this->_objectptr->GetObj()->GetDepth();
  long res_long = boost::numeric_cast<long >((unsigned int)res);
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of bool wxHtmlCell::IsBefore(wxHtmlCell * cell)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_IsBefore::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'cell'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_IsBefore::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlCell > cell_smtptr;
  if (!get_val_smtptr_param<wxHtmlCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlCell* cell = cell_smtptr.get();

  bool res =   this->_objectptr->GetObj()->IsBefore(cell);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlCell::ConvertToText(wxHtmlSelection * param0)
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_ConvertToText::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlSelection, "parameter named 'param0'")
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_ConvertToText::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlSelection > param0_smtptr;
  if (!get_val_smtptr_param<wxHtmlSelection >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlSelection* param0 = param0_smtptr.get();

  wxString res =   this->_objectptr->GetObj()->ConvertToText(param0);
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlCell::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlCell::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlCell::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

