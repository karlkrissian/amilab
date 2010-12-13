/**
 * C++ Interface: wrap_wxPoint
 *
 * Description: wrapping wxPoint
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

#include "wrap_wxPoint.h"

// get all the required includes
// #include "..."
#ifndef wxPoint_declared
  #define wxPoint_declared
  AMI_DECLARE_TYPE(wxPoint)
#endif
#ifndef wxSize_declared
  #define wxSize_declared
  AMI_DECLARE_TYPE(wxSize)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxPoint>::CreateVar( ParamList* p)
{
  WrapClass_wxPoint::wrap_wxPoint construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxPoint);
AMI_DEFINE_VARFROMSMTPTR(wxPoint);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxPoint
//
Variable<AMIObject>::ptr WrapClass_wxPoint::CreateVar( wxPoint* sp)
{
  boost::shared_ptr<wxPoint> di_ptr(
    sp,
    wxwindow_nodeleter<wxPoint>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxPoint>::CreateVar(
      new WrapClass_wxPoint(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxPoint::AddMethods(WrapClass<wxPoint>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 

  // Adding operators
  AddVar___assign__( this_ptr);
  AddVar___equal__( this_ptr);
  AddVar___not_equal__( this_ptr);
  AddVar___add___1( this_ptr);
  AddVar___substract___1( this_ptr);
  AddVar___add_assign___1( this_ptr);
  AddVar___sub_assign___1( this_ptr);
  AddVar___add_assign__( this_ptr);
  AddVar___add_assign___2( this_ptr);
  AddVar___sub_assign__( this_ptr);
  AddVar___sub_assign___2( this_ptr);
  AddVar___add__( this_ptr);
  AddVar___add___2( this_ptr);
  AddVar___substract__( this_ptr);
  AddVar___substract___2( this_ptr);
  AddVar___substract___3( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());
  
  // Adding public member x
  boost::shared_ptr<int > var_x_ptr(&GetObj()->x, smartpointer_nodeleter<int >());
  if (var_x_ptr.get()) {
    BasicVariable::ptr var_x = AMILabType<int >::CreateVarFromSmtPtr(var_x_ptr);
    if (var_x.get()) {
      var_x->Rename("x");
      context->AddVar(var_x,context);
    }
  }
  
  // Adding public member y
  boost::shared_ptr<int > var_y_ptr(&GetObj()->y, smartpointer_nodeleter<int >());
  if (var_y_ptr.get()) {
    BasicVariable::ptr var_y = AMILabType<int >::CreateVarFromSmtPtr(var_y_ptr);
    if (var_y.get()) {
      var_y->Rename("y");
      context->AddVar(var_y,context);
    }
  }


  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPoint_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxPoint");
    WrapClass_wxPoint::AddVar_wxPoint_1(amiobject->GetContext());
  WrapClass_wxPoint::AddVar_wxPoint(amiobject->GetContext());
  WrapClass_wxPoint::AddVar_wxPoint_2(amiobject->GetContext());
  WrapClass_wxPoint::AddVar_wxPoint_3(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint(wxPoint const & param0)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > param0_smtptr;
  if (!get_val_smtptr_param<wxPoint >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxPoint const & param0 = *param0_smtptr;

  wxPoint* _newobj = new wxPoint(param0);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxPoint::wxPoint(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap_wxPoint_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap_wxPoint_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap_wxPoint_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint* _newobj = new wxPoint();
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxPoint::wxPoint(int xx, int yy)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap_wxPoint_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'xx'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'yy'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap_wxPoint_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  int xx;
  if (!get_val_param<int >(xx,_p,_n,true,true)) ClassReturnEmptyVar;

  int yy;
  if (!get_val_param<int >(yy,_p,_n,true,true)) ClassReturnEmptyVar;

  wxPoint* _newobj = new wxPoint(xx, yy);
  BasicVariable::ptr res = WrapClass_wxPoint::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxPoint.
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxPoint object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxPoint >::CreateVar( new wxPoint(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::operator =(wxPoint const & param0)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'param0'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > param0_smtptr;
  if (!get_val_smtptr_param<wxPoint >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & param0 = *param0_smtptr;

  wxPoint & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::operator ==(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  bool res =   (*this->_objectptr->GetObj()) == (p);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxPoint::operator !=(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___not_equal__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___not_equal__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPoint const & p = *p_smtptr;

  bool res =   (*this->_objectptr->GetObj()) != (p);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::operator +(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & p = *p_smtptr;

  wxPoint res =   (*this->_objectptr->GetObj()) + (p);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::operator -(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___substract___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___substract___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & p = *p_smtptr;

  wxPoint res =   (*this->_objectptr->GetObj()) - (p);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::operator +=(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & p = *p_smtptr;

  wxPoint & res =   (*this->_objectptr->GetObj()) += (p);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::operator -=(wxPoint const & p)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___sub_assign___1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxPoint, "parameter named 'p'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___sub_assign___1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxPoint > p_smtptr;
  if (!get_val_smtptr_param<wxPoint >(p_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxPoint const & p = *p_smtptr;

  wxPoint & res =   (*this->_objectptr->GetObj()) -= (p);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::+=(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap___add_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap___add_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::operator +=(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & s = *s_smtptr;

  wxPoint & res =   (*this->_objectptr->GetObj()) += (s);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::-=(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___sub_assign__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___sub_assign__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap___sub_assign___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap___sub_assign___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint & wxPoint::operator -=(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___sub_assign___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___sub_assign___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & s = *s_smtptr;

  wxPoint & res =   (*this->_objectptr->GetObj()) -= (s);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::+(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap___add___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap___add___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::operator +(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___add___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___add___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & s = *s_smtptr;

  wxPoint res =   (*this->_objectptr->GetObj()) + (s);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxPoint::-(...)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___substract__::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___substract__::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxPoint::wrap___substract___1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap___substract___2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxPoint::wrap___substract___3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::operator -(wxSize const & s)
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___substract___2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 's'")
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___substract___2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > s_smtptr;
  if (!get_val_smtptr_param<wxSize >(s_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & s = *s_smtptr;

  wxPoint res =   (*this->_objectptr->GetObj()) - (s);
  return AMILabType<wxPoint >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxPoint wxPoint::operator -()
//---------------------------------------------------
void WrapClass_wxPoint::
    wrap___substract___3::SetParametersComments()
{
  return_comments="returning a variable of type wxPoint";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxPoint::
    wrap___substract___3::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxPoint res =  - (*this->_objectptr->GetObj());
  return AMILabType<wxPoint >::CreateVar(res);
}

