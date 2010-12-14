/**
 * C++ Interface: wrap_wxBrush
 *
 * Description: wrapping wxBrush
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

#include "wrap_wxBrush.h"

// get all the required includes
// #include "..."
#ifndef wxBrush_declared
  #define wxBrush_declared
  AMI_DECLARE_TYPE(wxBrush)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxBitmap_declared
  #define wxBitmap_declared
  AMI_DECLARE_TYPE(wxBitmap)
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
BasicVariable::ptr WrapClass<wxBrush>::CreateVar( ParamList* p)
{
  WrapClass_wxBrush::wrap_wxBrush construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBrush);
AMI_DEFINE_VARFROMSMTPTR(wxBrush);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBrush
//
Variable<AMIObject>::ptr WrapClass_wxBrush::CreateVar( wxBrush* sp)
{
  boost::shared_ptr<wxBrush> di_ptr(
    sp,
    wxwindow_nodeleter<wxBrush>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBrush>::CreateVar(
      new WrapClass_wxBrush(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBrush::AddMethods(WrapClass<wxBrush>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_Ok( this_ptr);
  AddVar_IsOk( this_ptr);
  AddVar_GetStyle( this_ptr);
  AddVar_GetColour( this_ptr);
  AddVar_GetStipple( this_ptr);
  AddVar_SetColour_1( this_ptr);
  AddVar_SetColour( this_ptr);
  AddVar_SetColour_2( this_ptr);
  AddVar_SetStyle( this_ptr);
  AddVar_SetStipple( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___not_equal__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxBrushBase
  boost::shared_ptr<wxBrushBase > parent_wxBrushBase(  boost::dynamic_pointer_cast<wxBrushBase >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBrushBase = AMILabType<wxBrushBase >::CreateVarFromSmtPtr(parent_wxBrushBase);
  context->AddVar("wxBrushBase",var_wxBrushBase);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBrushBase = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBrushBase);
  context->AddDefault(obj_wxBrushBase->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBrush_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBrush");
    WrapClass_wxBrush::AddVar_wxBrush_1(amiobject->GetContext());
  WrapClass_wxBrush::AddVar_wxBrush(amiobject->GetContext());
  WrapClass_wxBrush::AddVar_wxBrush_2(amiobject->GetContext());
  WrapClass_wxBrush::AddVar_wxBrush_3(amiobject->GetContext());
  WrapClass_wxBrush::AddVar_wxBrush_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBrush::wxBrush(wxBrush const & param0)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_wxBrush_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBrush, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_wxBrush_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBrush > param0_smtptr;
  if (!get_val_smtptr_param<wxBrush >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBrush const & param0 = *param0_smtptr;

  wxBrush* _newobj = new wxBrush(param0);
  BasicVariable::ptr res = WrapClass_wxBrush::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBrush::wxBrush(...)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_wxBrush::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_wxBrush::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBrush::wrap_wxBrush_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBrush::wrap_wxBrush_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxBrush::wrap_wxBrush_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxBrush::wrap_wxBrush_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBrush::wxBrush()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_wxBrush_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_wxBrush_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBrush* _newobj = new wxBrush();
  BasicVariable::ptr res = WrapClass_wxBrush::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBrush::wxBrush(wxColour const & colour, int style = wxSOLID)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_wxBrush_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style' (def:wxSOLID)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_wxBrush_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & colour = *colour_smtptr;

  int style = wxSOLID;
  if (!get_val_param<int >(style,_p,_n,false,true)) ClassReturnEmptyVar;

  wxBrush* _newobj = new wxBrush(colour, style);
  BasicVariable::ptr res = WrapClass_wxBrush::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBrush::wxBrush(wxBitmap const & stippleBitmap)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_wxBrush_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'stippleBitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_wxBrush_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > stippleBitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(stippleBitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & stippleBitmap = *stippleBitmap_smtptr;

  wxBrush* _newobj = new wxBrush(stippleBitmap);
  BasicVariable::ptr res = WrapClass_wxBrush::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBrush.
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBrush object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBrush >::CreateVar( new wxBrush(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxBrush::Ok()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_Ok::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_Ok::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Ok();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBrush::IsOk()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_IsOk::SetParametersComments()
{
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_IsOk::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->IsOk();
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxBrush::GetStyle()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_GetStyle::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_GetStyle::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetStyle();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxColour & wxBrush::GetColour()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_GetColour::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_GetColour::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour & res =   this->_objectptr->GetObj()->GetColour();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmap * wxBrush::GetStipple()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_GetStipple::SetParametersComments()
{
  return_comments="returning a variable of type wxBitmap";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_GetStipple::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmap * res =   this->_objectptr->GetObj()->GetStipple();
  BasicVariable::ptr res_var = AMILabType<wxBitmap >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxBrush::SetColour(wxColour const & col)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_SetColour_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'col'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_SetColour_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxColour > col_smtptr;
  if (!get_val_smtptr_param<wxColour >(col_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & col = *col_smtptr;

  this->_objectptr->GetObj()->SetColour(col);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxBrush::SetColour(...)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_SetColour::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_SetColour::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBrush::wrap_SetColour_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBrush::wrap_SetColour_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxBrush::SetColour(unsigned char r, unsigned char g, unsigned char b)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_SetColour_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'r'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'g'")
  ADDPARAMCOMMENT_TYPE( unsigned char, "parameter named 'b'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_SetColour_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  unsigned char r;
  if (!get_val_param<unsigned char >(r,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char g;
  if (!get_val_param<unsigned char >(g,_p,_n,true,true)) ClassReturnEmptyVar;

  unsigned char b;
  if (!get_val_param<unsigned char >(b,_p,_n,true,true)) ClassReturnEmptyVar;

  this->_objectptr->GetObj()->SetColour(r, g, b);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBrush::SetStyle(int style)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_SetStyle::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'style'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
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
//  Wrapping of void wxBrush::SetStipple(wxBitmap const & stipple)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_SetStipple::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'stipple'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_SetStipple::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > stipple_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(stipple_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & stipple = *stipple_smtptr;

  this->_objectptr->GetObj()->SetStipple(stipple);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBrush::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBrush & wxBrush::operator =(wxBrush const & param0)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBrush, "parameter named 'param0'")
  return_comments="returning a variable of type wxBrush";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBrush > param0_smtptr;
  if (!get_val_smtptr_param<wxBrush >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBrush const & param0 = *param0_smtptr;

  wxBrush & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBrush >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBrush::operator ==(wxBrush const & brush)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBrush, "parameter named 'brush'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBrush > brush_smtptr;
  if (!get_val_smtptr_param<wxBrush >(brush_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBrush const & brush = *brush_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (brush);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBrush::operator !=(wxBrush const & brush)
//---------------------------------------------------
void WrapClass_wxBrush::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBrush, "parameter named 'brush'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBrush::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBrush > brush_smtptr;
  if (!get_val_smtptr_param<wxBrush >(brush_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBrush const & brush = *brush_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (brush);
  return AMILabType<bool >::CreateVar(res);
}

