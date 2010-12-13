/**
 * C++ Interface: wrap_wxAuiDockArt
 *
 * Description: wrapping wxAuiDockArt
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

#include "wrap_wxAuiDockArt.h"

// get all the required includes
// #include "..."
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxAuiDockArt_declared
  #define wxAuiDockArt_declared
  AMI_DECLARE_TYPE(wxAuiDockArt)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxAuiDockArt>::CreateVar( ParamList* p)
{
  // No variable creation for an abstract class ...
  return BasicVariable::ptr();

}


AMI_DEFINE_WRAPPEDTYPE_ABSTRACT(wxAuiDockArt);
AMI_DEFINE_VARFROMSMTPTR(wxAuiDockArt);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxAuiDockArt
//
Variable<AMIObject>::ptr WrapClass_wxAuiDockArt::CreateVar( wxAuiDockArt* sp)
{
  boost::shared_ptr<wxAuiDockArt> di_ptr(
    sp,
    wxwindow_nodeleter<wxAuiDockArt>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxAuiDockArt>::CreateVar(
      new WrapClass_wxAuiDockArt(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxAuiDockArt::AddMethods(WrapClass<wxAuiDockArt>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetColor( this_ptr);
  AddVar_SetColor( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  

  


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiDockArt_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxAuiDockArt");
  
  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of wxColour wxAuiDockArt::GetColor(int id)
//---------------------------------------------------
void WrapClass_wxAuiDockArt::
    wrap_GetColor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiDockArt::
    wrap_GetColor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  wxColour res =   this->_objectptr->GetObj()->GetColor(id);
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxAuiDockArt::SetColor(int id, wxColour const & color)
//---------------------------------------------------
void WrapClass_wxAuiDockArt::
    wrap_SetColor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'id'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'color'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiDockArt::
    wrap_SetColor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int id;
  if (!get_val_param<int >(id,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxColour > color_smtptr;
  if (!get_val_smtptr_param<wxColour >(color_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & color = *color_smtptr;

  this->_objectptr->GetObj()->SetColor(id, color);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxAuiDockArt & wxAuiDockArt::operator =(wxAuiDockArt const & param0)
//---------------------------------------------------
void WrapClass_wxAuiDockArt::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxAuiDockArt, "parameter named 'param0'")
  return_comments="returning a variable of type wxAuiDockArt";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxAuiDockArt::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxAuiDockArt > param0_smtptr;
  if (!get_val_smtptr_param<wxAuiDockArt >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxAuiDockArt const & param0 = *param0_smtptr;

  wxAuiDockArt & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxAuiDockArt >::CreateVar(res);
}

