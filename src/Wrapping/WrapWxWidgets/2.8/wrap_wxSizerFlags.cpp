/**
 * C++ Interface: wrap_wxSizerFlags
 *
 * Description: wrapping wxSizerFlags
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
#include "wrap_wxSizerFlags.h"


#include "wrap_wxSizerFlags.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxSizerFlags>::CreateVar( ParamList* p)
{
  WrapClass_wxSizerFlags::wrap_wxSizerFlags construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxSizerFlags);
AMI_DEFINE_VARFROMSMTPTR(wxSizerFlags);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxSizerFlags
//
Variable<AMIObject>::ptr WrapClass_wxSizerFlags::CreateVar( wxSizerFlags* sp)
{
  boost::shared_ptr<wxSizerFlags> di_ptr(
    sp,
    wxwindow_nodeleter<wxSizerFlags>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxSizerFlags>::CreateVar(
      new WrapClass_wxSizerFlags(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxSizerFlags::AddMethods(WrapClass<wxSizerFlags>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Proportion( this_ptr);
      AddVar_Align( this_ptr);
      AddVar_Expand( this_ptr);
      AddVar_Centre( this_ptr);
      AddVar_Center( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_Top( this_ptr);
      AddVar_Bottom( this_ptr);
      AddVar_Border_1( this_ptr);
      AddVar_Border( this_ptr);
      AddVar_Border_2( this_ptr);
      AddVar_DoubleBorder( this_ptr);
      AddVar_TripleBorder( this_ptr);
      AddVar_HorzBorder( this_ptr);
      AddVar_DoubleHorzBorder( this_ptr);
      AddVar_Shaped( this_ptr);
      AddVar_FixedMinSize( this_ptr);
      AddVar_ReserveSpaceEvenIfHidden( this_ptr);
      AddVar_GetProportion( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_GetBorderInPixels( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  

  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxSizerFlags::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxSizerFlags");
    WrapClass_wxSizerFlags::AddVar_wxSizerFlags_1(amiobject->GetContext());
  WrapClass_wxSizerFlags::AddVar_wxSizerFlags(amiobject->GetContext());
  WrapClass_wxSizerFlags::AddVar_wxSizerFlags_2(amiobject->GetContext());


  // Static methods 
  WrapClass_wxSizerFlags::AddVar_GetDefaultBorder(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxSizerFlags::wxSizerFlags(wxSizerFlags const & param0)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_wxSizerFlags_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_wxSizerFlags_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSizerFlags > param0_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxSizerFlags const & param0 = *param0_smtptr;

  wxSizerFlags* _newobj = new wxSizerFlags(param0);
  BasicVariable::ptr res = WrapClass_wxSizerFlags::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxSizerFlags::wxSizerFlags(...)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_wxSizerFlags::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_wxSizerFlags::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerFlags::wrap_wxSizerFlags_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerFlags::wrap_wxSizerFlags_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxSizerFlags::wxSizerFlags(int proportion = 0)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_wxSizerFlags_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion' (def:0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_wxSizerFlags_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int proportion = 0;
  if (!get_val_param<int >(proportion,_p,_n,false,true)) ClassReturnEmptyVar;

  wxSizerFlags* _newobj = new wxSizerFlags(proportion);
  BasicVariable::ptr res = WrapClass_wxSizerFlags::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of int wxSizerFlags::GetDefaultBorder()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_static_GetDefaultBorder::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_static_GetDefaultBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   wxSizerFlags::GetDefaultBorder();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxSizerFlags.
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxSizerFlags object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxSizerFlags >::CreateVar( new wxSizerFlags(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Proportion(int proportion)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Proportion::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'proportion'")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Proportion::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int proportion;
  if (!get_val_param<int >(proportion,_p,_n,true,false)) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Proportion(proportion);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Align(int alignment)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Align::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'alignment'")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Align::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int alignment;
  if (!get_val_param<int >(alignment,_p,_n,true,false)) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Align(alignment);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Expand()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Expand::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Expand::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Expand();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Centre()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Centre::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Centre::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Centre();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Center()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Center::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Center::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Center();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Left()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Left::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Left::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Left();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Right()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Right::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Right::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Right();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Top()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Top::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Top::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Top();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Bottom()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Bottom::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Bottom::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Bottom();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Border(int direction, int borderInPixels)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Border_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'borderInPixels'")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Border_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int direction;
  if (!get_val_param<int >(direction,_p,_n,true,true)) ClassReturnEmptyVar;

  int borderInPixels;
  if (!get_val_param<int >(borderInPixels,_p,_n,true,true)) ClassReturnEmptyVar;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Border(direction, borderInPixels);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxSizerFlags::Border(...)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Border::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Border::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxSizerFlags::wrap_Border_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxSizerFlags::wrap_Border_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Border(int direction = wxALL)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Border_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction' (def:wxALL)")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Border_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int direction = wxALL;
  if (!get_val_param<int >(direction,_p,_n,false,true)) ClassReturnEmptyVar;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Border(direction);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::DoubleBorder(int direction = wxALL)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_DoubleBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction' (def:wxALL)")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_DoubleBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int direction = wxALL;
  if (!get_val_param<int >(direction,_p,_n,false,false)) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->DoubleBorder(direction);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::TripleBorder(int direction = wxALL)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_TripleBorder::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'direction' (def:wxALL)")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_TripleBorder::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int direction = wxALL;
  if (!get_val_param<int >(direction,_p,_n,false,false)) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->TripleBorder(direction);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::HorzBorder()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_HorzBorder::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_HorzBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->HorzBorder();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::DoubleHorzBorder()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_DoubleHorzBorder::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_DoubleHorzBorder::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->DoubleHorzBorder();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::Shaped()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_Shaped::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_Shaped::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->Shaped();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::FixedMinSize()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_FixedMinSize::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_FixedMinSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->FixedMinSize();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::ReserveSpaceEvenIfHidden()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_ReserveSpaceEvenIfHidden::SetParametersComments()
{
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_ReserveSpaceEvenIfHidden::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxSizerFlags & res =   this->_objectptr->GetObj()->ReserveSpaceEvenIfHidden();
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxSizerFlags::GetProportion()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_GetProportion::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_GetProportion::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetProportion();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxSizerFlags::GetFlags()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_GetFlags::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_GetFlags::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFlags();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxSizerFlags::GetBorderInPixels()
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap_GetBorderInPixels::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap_GetBorderInPixels::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetBorderInPixels();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxSizerFlags & wxSizerFlags::operator =(wxSizerFlags const & param0)
//---------------------------------------------------
void WrapClass_wxSizerFlags::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSizerFlags, "parameter named 'param0'")
  return_comments="returning a variable of type wxSizerFlags";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxSizerFlags::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxSizerFlags > param0_smtptr;
  if (!get_val_smtptr_param<wxSizerFlags >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxSizerFlags const & param0 = *param0_smtptr;

  wxSizerFlags & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxSizerFlags >::CreateVar(res);
}

