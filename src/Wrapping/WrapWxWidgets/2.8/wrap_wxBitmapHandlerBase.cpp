/**
 * C++ Interface: wrap_wxBitmapHandlerBase
 *
 * Description: wrapping wxBitmapHandlerBase
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
#include "wrap_wxBitmapHandlerBase.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxString.h"
#include "wrap_wxPalette.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxBitmapHandlerBase.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxBitmapHandlerBase>::CreateVar( ParamList* p)
{
  WrapClass_wxBitmapHandlerBase::wrap_wxBitmapHandlerBase construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxBitmapHandlerBase);
AMI_DEFINE_VARFROMSMTPTR(wxBitmapHandlerBase);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxBitmapHandlerBase
//
Variable<AMIObject>::ptr WrapClass_wxBitmapHandlerBase::CreateVar( wxBitmapHandlerBase* sp)
{
  boost::shared_ptr<wxBitmapHandlerBase> di_ptr(
    sp,
    wxwindow_nodeleter<wxBitmapHandlerBase>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxBitmapHandlerBase>::CreateVar(
      new WrapClass_wxBitmapHandlerBase(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxBitmapHandlerBase::AddMethods(WrapClass<wxBitmapHandlerBase>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
/* The following types are missing: void
      AddVar_Create( this_ptr);
*/
      AddVar_LoadFile( this_ptr);
      AddVar_SaveFile( this_ptr);
      AddVar_SetName( this_ptr);
      AddVar_SetExtension( this_ptr);
      AddVar_SetType( this_ptr);
      AddVar_GetName( this_ptr);
      AddVar_GetExtension( this_ptr);
      AddVar_GetType( this_ptr);
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  

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
void WrapClass_wxBitmapHandlerBase::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxBitmapHandlerBase");
    WrapClass_wxBitmapHandlerBase::AddVar_wxBitmapHandlerBase_1(amiobject->GetContext());
  WrapClass_wxBitmapHandlerBase::AddVar_wxBitmapHandlerBase(amiobject->GetContext());
  WrapClass_wxBitmapHandlerBase::AddVar_wxBitmapHandlerBase_2(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxBitmapHandlerBase::wxBitmapHandlerBase(wxBitmapHandlerBase const & param0)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandlerBase, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmapHandlerBase > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmapHandlerBase >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxBitmapHandlerBase const & param0 = *param0_smtptr;

  wxBitmapHandlerBase* _newobj = new wxBitmapHandlerBase(param0);
  BasicVariable::ptr res = WrapClass_wxBitmapHandlerBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxBitmapHandlerBase::wxBitmapHandlerBase(...)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxBitmapHandlerBase::wrap_wxBitmapHandlerBase_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxBitmapHandlerBase::wrap_wxBitmapHandlerBase_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxBitmapHandlerBase::wxBitmapHandlerBase()
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_wxBitmapHandlerBase_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxBitmapHandlerBase* _newobj = new wxBitmapHandlerBase();
  BasicVariable::ptr res = WrapClass_wxBitmapHandlerBase::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxBitmapHandlerBase.
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxBitmapHandlerBase object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxBitmapHandlerBase >::CreateVar( new wxBitmapHandlerBase(*(this->_objectptr->GetObj())));
}
/* The following types are missing: void

//---------------------------------------------------
//  Wrapping of bool wxBitmapHandlerBase::Create(wxBitmap * bitmap, void const * data, long int flags, int width, int height, int depth = 1)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_Create::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( void, "parameter named 'data'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'depth' (def:1)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_Create::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>6) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap* bitmap = bitmap_smtptr.get();

  boost::shared_ptr<void > data_smtptr;
  if (!get_val_smtptr_param<void >(data_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  void* data = data_smtptr.get();

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  int width;
  if (!get_val_param<int >(width,_p,_n,true,false)) ClassHelpAndReturn;

  int height;
  if (!get_val_param<int >(height,_p,_n,true,false)) ClassHelpAndReturn;

  int depth = 1;
  if (!get_val_param<int >(depth,_p,_n,false,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->Create(bitmap, data, flags, width, height, depth);
  return AMILabType<bool >::CreateVar(res);
}
*/

//---------------------------------------------------
//  Wrapping of bool wxBitmapHandlerBase::LoadFile(wxBitmap * bitmap, wxString const & name, long int flags, int desiredWidth, int desiredHeight)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_LoadFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'flags'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'desiredWidth'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'desiredHeight'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_LoadFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>5) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap* bitmap = bitmap_smtptr.get();

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  long flags_long;
  if (!get_val_param<long >(flags_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int flags = flags_long;

  int desiredWidth;
  if (!get_val_param<int >(desiredWidth,_p,_n,true,false)) ClassHelpAndReturn;

  int desiredHeight;
  if (!get_val_param<int >(desiredHeight,_p,_n,true,false)) ClassHelpAndReturn;

  bool res =   this->_objectptr->GetObj()->LoadFile(bitmap, name, flags, desiredWidth, desiredHeight);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxBitmapHandlerBase::SaveFile(wxBitmap const * bitmap, wxString const & name, int type, wxPalette const * palette = 0l)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_SaveFile::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( wxPalette, "parameter named 'palette' (def:0l)")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_SaveFile::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>4) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap* bitmap = bitmap_smtptr.get();

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  int type;
  if (!get_val_param<int >(type,_p,_n,true,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxPalette > palette_smtptr;
  if (!get_val_smtptr_param<wxPalette >(palette_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxPalette* palette = palette_smtptr.get();

  bool res =   this->_objectptr->GetObj()->SaveFile(bitmap, name, type, palette);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxBitmapHandlerBase::SetName(wxString const & name)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_SetName::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'name'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_SetName::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > name_smtptr;
  if (!get_val_smtptr_param<wxString >(name_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & name = *name_smtptr;

  this->_objectptr->GetObj()->SetName(name);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapHandlerBase::SetExtension(wxString const & ext)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_SetExtension::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'ext'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_SetExtension::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > ext_smtptr;
  if (!get_val_smtptr_param<wxString >(ext_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & ext = *ext_smtptr;

  this->_objectptr->GetObj()->SetExtension(ext);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxBitmapHandlerBase::SetType(wxBitmapType type)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_SetType::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_SetType::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxBitmapType type = (wxBitmapType) type_int;

  this->_objectptr->GetObj()->SetType(type);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString const & wxBitmapHandlerBase::GetName()
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_GetName::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_GetName::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetName();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxString const & wxBitmapHandlerBase::GetExtension()
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_GetExtension::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_GetExtension::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString const & res =   this->_objectptr->GetObj()->GetExtension();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxBitmapType wxBitmapHandlerBase::GetType()
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_GetType::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_GetType::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxBitmapType res =   this->_objectptr->GetObj()->GetType();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxBitmapHandlerBase::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxBitmapHandlerBase & wxBitmapHandlerBase::operator =(wxBitmapHandlerBase const & param0)
//---------------------------------------------------
void WrapClass_wxBitmapHandlerBase::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmapHandlerBase, "parameter named 'param0'")
  return_comments="returning a variable of type wxBitmapHandlerBase";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxBitmapHandlerBase::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmapHandlerBase > param0_smtptr;
  if (!get_val_smtptr_param<wxBitmapHandlerBase >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmapHandlerBase const & param0 = *param0_smtptr;

  wxBitmapHandlerBase & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxBitmapHandlerBase >::CreateVar(res);
}

