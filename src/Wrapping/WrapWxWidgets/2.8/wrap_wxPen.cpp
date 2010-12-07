/**
 * C++ Interface: wrap_wxPen
 *
 * Description: wrapping wxPen
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
#include "wrap_wxPen.h"
#include "wrap_wxColour.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxPen.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPen>::CreateVar( ParamList* p)
{
  WrapClass_wxPen::wrap_wxPen construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPen);
AMI_DEFINE_VARFROMSMTPTR(wxPen);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPen
//
Variable<AMIObject>::ptr WrapClass_wxPen::CreateVar( wxPen* sp)
{
  boost::shared_ptr<wxPen> di_ptr(
    sp,
    wxwindow_nodeleter<wxPen>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPen>::CreateVar(
      new WrapClass_wxPen(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPen::AddMethods(WrapClass<wxPen>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Ok( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_SetColour_1( this_ptr);
      AddVar_SetColour( this_ptr);
      AddVar_SetColour_2( this_ptr);
      AddVar_SetCap( this_ptr);
      AddVar_SetJoin( this_ptr);
      AddVar_SetStyle( this_ptr);
      AddVar_SetWidth( this_ptr);
/* The following types are missing: signed char
      AddVar_SetDashes( this_ptr);
*/
      AddVar_GetColour( this_ptr);
      AddVar_GetCap( this_ptr);
      AddVar_GetJoin( this_ptr);
      AddVar_GetStyle( this_ptr);
      AddVar_GetWidth( this_ptr);
/* The following types are missing: wxDash * *
      AddVar_GetDashes( this_ptr);
*/
      AddVar_GetDashCount( this_ptr);
/* The following types are missing: signed char
      AddVar_GetDash( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);
      AddVar___equal__( this_ptr);
      AddVar___not_equal__( this_ptr);



  

  // Get the current context
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());

  // Add base parent wxGDIObject
  boost::shared_ptr<wxGDIObject > parent_wxGDIObject(  boost::dynamic_pointer_cast<wxGDIObject >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxGDIObject = AMILabType<wxGDIObject >::CreateVarFromSmtPtr(parent_wxGDIObject);
  context->AddVar("wxGDIObject",var_wxGDIObject);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxGDIObject = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxGDIObject);
  context->AddDefault(obj_wxGDIObject->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxPen::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPen");
    WrapClass_wxPen::AddVar_wxPen_1(amiobject->GetContext());
  WrapClass_wxPen::AddVar_wxPen(amiobject->GetContext());
  WrapClass_wxPen::AddVar_wxPen_2(amiobject->GetContext());
  WrapClass_wxPen::AddVar_wxPen_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPen::wxPen(wxPen const & param0)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_wxPen_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPen, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_wxPen_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPen > param0_smtptr;
  if (!get_val_smtptr_param<wxPen >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxPen const & param0 = *param0_smtptr;

  wxPen* _newobj = new wxPen(param0);
  BasicVariable::ptr res = WrapClass_wxPen::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPen::wxPen(...)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_wxPen::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_wxPen::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPen::wrap_wxPen_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPen::wrap_wxPen_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxPen::wrap_wxPen_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPen::wxPen()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_wxPen_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_wxPen_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPen* _newobj = new wxPen();
  BasicVariable::ptr res = WrapClass_wxPen::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPen::wxPen(wxColour const & colour, int width = 1, int style = wxSOLID)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_wxPen_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width' (def:1)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style' (def:wxSOLID)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_wxPen_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & colour = *colour_smtptr;

  int width = 1;
  if (!get_val_param<int >(width,_p,_n,false,true)) ClassReturnEmptyVar;

  int style = wxSOLID;
  if (!get_val_param<int >(style,_p,_n,false,true)) ClassReturnEmptyVar;

  wxPen* _newobj = new wxPen(colour, width, style);
  BasicVariable::ptr res = WrapClass_wxPen::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxPen.
//---------------------------------------------------
void WrapClass_wxPen::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxPen object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxPen >::CreateVar( new wxPen(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxPen::Ok()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPen::IsOk()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetColour(wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetColour_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetColour_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & colour = *colour_smtptr;

  this->_objectptr->GetObj()->SetColour(colour);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPen::SetColour(...)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetColour::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetColour::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPen::wrap_SetColour_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPen::wrap_SetColour_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetColour(unsigned char red, unsigned char green, unsigned char blue)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetColour_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'red'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'green'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'blue'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetColour_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  unsigned char red;
  if (!get_val_param<unsigned char >(red,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char green;
  if (!get_val_param<unsigned char >(green,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char blue;
  if (!get_val_param<unsigned char >(blue,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetColour(red, green, blue);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetCap(int capStyle)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetCap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'capStyle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetCap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int capStyle;
  if (!get_val_param<int >(capStyle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetCap(capStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetJoin(int joinStyle)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetJoin::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'joinStyle'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetJoin::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int joinStyle;
  if (!get_val_param<int >(joinStyle,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetJoin(joinStyle);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetStyle(int style)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetStyle::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int style;
  if (!get_val_param<int >(style,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetStyle(style);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxPen::SetWidth(int width)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetWidth::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetWidth::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetWidth(width);
  return BasicVariable::ptr();
}
/* The following types are missing: signed char

//---------------------------------------------------
//  Wrapping of void wxPen::SetDashes(int number_of_dashes, wxDash const * dash)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_SetDashes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'number_of_dashes'")
  ADDPARAMCOMMENT_TYPE( signed char, "parameter named 'dash'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_SetDashes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int number_of_dashes;
  if (!get_val_param<int >(number_of_dashes,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<signed char > dash_smtptr;
  if (!get_val_smtptr_param<signed char >(dash_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  signed char* dash = dash_smtptr.get();

  this->_objectptr->GetObj()->SetDashes(number_of_dashes, dash);
  return BasicVariable::ptr();
}
*/

//---------------------------------------------------
//  Wrapping of wxColour & wxPen::GetColour()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour & res =   this->_objectptr->GetObj()->GetColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxPen::GetCap()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetCap::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetCap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCap();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxPen::GetJoin()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetJoin::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetJoin::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetJoin();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxPen::GetStyle()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStyle();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxPen::GetWidth()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetWidth();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: wxDash * *

//---------------------------------------------------
//  Wrapping of int wxPen::GetDashes(wxDash * * ptr)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetDashes::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( signed char, "parameter named 'ptr'")
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetDashes::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<signed char > ptr_smtptr;
  if (!get_val_smtptr_param<signed char >(ptr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  signed char* ptr = ptr_smtptr.get();

  int res =   this->_objectptr->GetObj()->GetDashes(ptr);
  return AMILabType<int >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of int wxPen::GetDashCount()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetDashCount::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetDashCount::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetDashCount();
  return AMILabType<int >::CreateVar(res);
}
/* The following types are missing: signed char

//---------------------------------------------------
//  Wrapping of wxDash * wxPen::GetDash()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetDash::SetParametersComments()
{
  return_comments="returning a variable of type signed char";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetDash::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDash * res =   this->_objectptr->GetObj()->GetDash();
  return AMILabType<signed char >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxPen::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxPen::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxPen & wxPen::operator =(wxPen const & param0)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPen, "parameter named 'param0'")
  return_comments="returning a variable of type wxPen";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPen > param0_smtptr;
  if (!get_val_smtptr_param<wxPen >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPen const & param0 = *param0_smtptr;

  wxPen & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPen >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPen::operator ==(wxPen const & pen)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPen, "parameter named 'pen'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPen > pen_smtptr;
  if (!get_val_smtptr_param<wxPen >(pen_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPen const & pen = *pen_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (pen);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPen::operator !=(wxPen const & pen)
//---------------------------------------------------
void WrapClass_wxPen::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPen, "parameter named 'pen'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPen::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPen > pen_smtptr;
  if (!get_val_smtptr_param<wxPen >(pen_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPen const & pen = *pen_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (pen);
  return AMILabType<bool >::CreateVar(res);
}

