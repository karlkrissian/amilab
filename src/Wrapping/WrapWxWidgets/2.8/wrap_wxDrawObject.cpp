/**
 * C++ Interface: wrap_wxDrawObject
 *
 * Description: wrapping wxDrawObject
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

#include "wrap_wxDrawObject.h"

// get all the required includes
// #include "..."
#ifndef wxDCBase_declared
  #define wxDCBase_declared
  AMI_DECLARE_TYPE(wxDCBase)
#endif
#ifndef wxDrawObject_declared
  #define wxDrawObject_declared
  AMI_DECLARE_TYPE(wxDrawObject)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxDrawObject>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxDrawObject);
AMI_DEFINE_VARFROMSMTPTR(wxDrawObject);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxDrawObject
//
Variable<AMIObject>::ptr WrapClass_wxDrawObject::CreateVar( wxDrawObject* sp)
{
  boost::shared_ptr<wxDrawObject> di_ptr(
    sp,
    wxwindow_nodeleter<wxDrawObject>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxDrawObject>::CreateVar(
      new WrapClass_wxDrawObject(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxDrawObject::AddMethods(WrapClass<wxDrawObject>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_Draw( this_ptr);
  AddVar_CalcBoundingBox( this_ptr);
  AddVar_ResetBoundingBox( this_ptr);
  AddVar_MinX( this_ptr);
  AddVar_MaxX( this_ptr);
  AddVar_MinY( this_ptr);
  AddVar_MaxY( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDrawObject_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxDrawObject");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of void wxDrawObject::Draw(wxDCBase & param0)
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_Draw::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDCBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_Draw::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDCBase > param0_smtptr;
  if (!get_val_smtptr_param<wxDCBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDCBase & param0 = *param0_smtptr;

  this->_objectptr->GetObj()->Draw(param0);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDrawObject::CalcBoundingBox(wxCoord x, wxCoord y)
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_CalcBoundingBox::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'y'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_CalcBoundingBox::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  int y;
  if (!get_val_param<int >(y,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->CalcBoundingBox(x, y);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxDrawObject::ResetBoundingBox()
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_ResetBoundingBox::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_ResetBoundingBox::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ResetBoundingBox();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDrawObject::MinX()
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_MinX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_MinX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MinX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDrawObject::MaxX()
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_MaxX::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_MaxX::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MaxX();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDrawObject::MinY()
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_MinY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_MinY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MinY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxCoord wxDrawObject::MaxY()
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap_MaxY::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap_MaxY::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxCoord res =   this->_objectptr->GetObj()->MaxY();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxDrawObject & wxDrawObject::operator =(wxDrawObject const & param0)
//---------------------------------------------------
void WrapClass_wxDrawObject::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDrawObject, "parameter named 'param0'")
  return_comments="returning a variable of type wxDrawObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxDrawObject::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxDrawObject > param0_smtptr;
  if (!get_val_smtptr_param<wxDrawObject >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxDrawObject const & param0 = *param0_smtptr;

  wxDrawObject & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxDrawObject >::CreateVar(res);
}

