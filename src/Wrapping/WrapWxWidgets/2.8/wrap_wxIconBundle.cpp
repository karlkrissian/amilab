/**
 * C++ Interface: wrap_wxIconBundle
 *
 * Description: wrapping wxIconBundle
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
#include "wrap_wxString.h"
#include "wrap_wxIcon.h"
#include "wrap_wxIconBundle.h"
#include "wrap_wxSize.h"


#include "wrap_wxIconBundle.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxIconBundle>::CreateVar( ParamList* p)
{
  WrapClass_wxIconBundle::wrap_wxIconBundle construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIconBundle);
AMI_DEFINE_VARFROMSMTPTR(wxIconBundle);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIconBundle
//
Variable<AMIObject>::ptr WrapClass_wxIconBundle::CreateVar( wxIconBundle* sp)
{
  boost::shared_ptr<wxIconBundle> di_ptr(
    sp,
    wxwindow_nodeleter<wxIconBundle>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIconBundle>::CreateVar(
      new WrapClass_wxIconBundle(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIconBundle::AddMethods(WrapClass<wxIconBundle>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_AddIcon_1( this_ptr);
      AddVar_AddIcon( this_ptr);
      AddVar_AddIcon_2( this_ptr);
      AddVar_GetIcon_1( this_ptr);
      AddVar_GetIcon( this_ptr);
      AddVar_GetIcon_2( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* Type not available
      // Adding public member m_icons
      boost::shared_ptr<wxIconArray > var_m_icons_ptr(&GetObj()->m_icons, smartpointer_nodeleter<wxIconArray >());
      if (var_m_icons_ptr.get()) {
        BasicVariable::ptr var_m_icons = AMILabType<wxIconArray >::CreateVarFromSmtPtr(var_m_icons_ptr);
        if (var_m_icons.get()) {
          var_m_icons->Rename("m_icons");
          context->AddVar(var_m_icons,context);
        }
      }
      */


  // Adding Bases

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClass_wxIconBundle::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIconBundle");
    WrapClass_wxIconBundle::AddVar_wxIconBundle_1(amiobject->GetContext());
  WrapClass_wxIconBundle::AddVar_wxIconBundle(amiobject->GetContext());
  WrapClass_wxIconBundle::AddVar_wxIconBundle_2(amiobject->GetContext());
  WrapClass_wxIconBundle::AddVar_wxIconBundle_3(amiobject->GetContext());
  WrapClass_wxIconBundle::AddVar_wxIconBundle_4(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIconBundle::wxIconBundle()
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_wxIconBundle_1::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_wxIconBundle_1::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxIconBundle* _newobj = new wxIconBundle();
  BasicVariable::ptr res = WrapClass_wxIconBundle::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIconBundle::wxIconBundle(...)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_wxIconBundle::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_wxIconBundle::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIconBundle::wrap_wxIconBundle_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIconBundle::wrap_wxIconBundle_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxIconBundle::wrap_wxIconBundle_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxIconBundle::wrap_wxIconBundle_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIconBundle::wxIconBundle(wxString const & file, long int type)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_wxIconBundle_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'file'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_wxIconBundle_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > file_smtptr;
  if (!get_val_smtptr_param<wxString >(file_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & file = *file_smtptr;

  long type_long;
  if (!get_val_param<long >(type_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int type = type_long;

  wxIconBundle* _newobj = new wxIconBundle(file, type);
  BasicVariable::ptr res = WrapClass_wxIconBundle::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIconBundle::wxIconBundle(wxIcon const & icon)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_wxIconBundle_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_wxIconBundle_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxIcon const & icon = *icon_smtptr;

  wxIconBundle* _newobj = new wxIconBundle(icon);
  BasicVariable::ptr res = WrapClass_wxIconBundle::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIconBundle::wxIconBundle(wxIconBundle const & ic)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_wxIconBundle_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconBundle, "parameter named 'ic'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_wxIconBundle_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIconBundle > ic_smtptr;
  if (!get_val_smtptr_param<wxIconBundle >(ic_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIconBundle const & ic = *ic_smtptr;

  wxIconBundle* _newobj = new wxIconBundle(ic);
  BasicVariable::ptr res = WrapClass_wxIconBundle::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIconBundle.
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIconBundle object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIconBundle >::CreateVar( new wxIconBundle(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxIconBundle::AddIcon(wxString const & file, long int type)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_AddIcon_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'file'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'type'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_AddIcon_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > file_smtptr;
  if (!get_val_smtptr_param<wxString >(file_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & file = *file_smtptr;

  long type_long;
  if (!get_val_param<long >(type_long,_p,_n,true,true)) ClassReturnEmptyVar;
  long int type = type_long;

  this->_objectptr->GetObj()->AddIcon(file, type);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxIconBundle::AddIcon(...)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_AddIcon::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_AddIcon::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIconBundle::wrap_AddIcon_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIconBundle::wrap_AddIcon_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of void wxIconBundle::AddIcon(wxIcon const & icon)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_AddIcon_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'icon'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_AddIcon_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIcon > icon_smtptr;
  if (!get_val_smtptr_param<wxIcon >(icon_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxIcon const & icon = *icon_smtptr;

  this->_objectptr->GetObj()->AddIcon(icon);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxIcon const & wxIconBundle::GetIcon(wxSize const & size)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_GetIcon_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxSize, "parameter named 'size'")
  return_comments="returning a variable of type wxIcon";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_GetIcon_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxSize > size_smtptr;
  if (!get_val_smtptr_param<wxSize >(size_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxSize const & size = *size_smtptr;

  wxIcon const & res =   this->_objectptr->GetObj()->GetIcon(size);
  return AMILabType<wxIcon >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxIconBundle::GetIcon(...)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_GetIcon::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_GetIcon::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIconBundle::wrap_GetIcon_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIconBundle::wrap_GetIcon_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of wxIcon const & wxIconBundle::GetIcon(wxCoord size = wxDefaultCoord)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap_GetIcon_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size' (def:wxDefaultCoord)")
  return_comments="returning a variable of type wxIcon";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap_GetIcon_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  int size = wxDefaultCoord;
  if (!get_val_param<int >(size,_p,_n,false,true)) ClassReturnEmptyVar;

  wxIcon const & res =   this->_objectptr->GetObj()->GetIcon(size);
  return AMILabType<wxIcon >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxIconBundle const & wxIconBundle::operator =(wxIconBundle const & ic)
//---------------------------------------------------
void WrapClass_wxIconBundle::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconBundle, "parameter named 'ic'")
  return_comments="returning a variable of type wxIconBundle";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIconBundle::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIconBundle > ic_smtptr;
  if (!get_val_smtptr_param<wxIconBundle >(ic_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIconBundle const & ic = *ic_smtptr;

  wxIconBundle const & res =   (*this->_objectptr->GetObj()) = (ic);
  return AMILabType<wxIconBundle >::CreateVar(res);
}

