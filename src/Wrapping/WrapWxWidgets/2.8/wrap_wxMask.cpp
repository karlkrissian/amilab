/**
 * C++ Interface: wrap_wxMask
 *
 * Description: wrapping wxMask
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
#include "wrap_wxMask.h"
#include "wrap_wxBitmap.h"
#include "wrap_wxColour.h"
#include "wrap_wxClassInfo.h"


#include "wrap_wxMask.h"

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxMask>::CreateVar( ParamList* p)
{
  WrapClass_wxMask::wrap_wxMask construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxMask);
AMI_DEFINE_VARFROMSMTPTR(wxMask);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxMask
//
Variable<AMIObject>::ptr WrapClass_wxMask::CreateVar( wxMask* sp)
{
  boost::shared_ptr<wxMask> di_ptr(
    sp,
    wxwindow_nodeleter<wxMask>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxMask>::CreateVar(
      new WrapClass_wxMask(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxMask::AddMethods(WrapClass<wxMask>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Create_1( this_ptr);
      AddVar_Create( this_ptr);
      AddVar_Create_2( this_ptr);
      AddVar_Create_3( this_ptr);
/* The following types are missing: _GdkDrawable
      AddVar_GetBitmap( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



  // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      /* Type not available
      // Adding public member m_bitmap
      boost::shared_ptr<_GdkDrawable > var_m_bitmap_ptr(GetObj()->m_bitmap, smartpointer_nodeleter<_GdkDrawable >());
      if (var_m_bitmap_ptr.get()) {
        BasicVariable::ptr var_m_bitmap = AMILabType<_GdkDrawable >::CreateVarFromSmtPtr(var_m_bitmap_ptr);
        if (var_m_bitmap.get()) {
          var_m_bitmap->Rename("m_bitmap");
          context->AddVar(var_m_bitmap,context);
        }
      }
      */


  // Adding Bases

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
void WrapClass_wxMask::AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxMask");
    WrapClass_wxMask::AddVar_wxMask_1(amiobject->GetContext());
  WrapClass_wxMask::AddVar_wxMask(amiobject->GetContext());
  WrapClass_wxMask::AddVar_wxMask_2(amiobject->GetContext());
  WrapClass_wxMask::AddVar_wxMask_3(amiobject->GetContext());
  WrapClass_wxMask::AddVar_wxMask_4(amiobject->GetContext());
  WrapClass_wxMask::AddVar_wxMask_5(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxMask::wxMask(wxMask const & param0)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMask, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxMask > param0_smtptr;
  if (!get_val_smtptr_param<wxMask >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxMask const & param0 = *param0_smtptr;

  wxMask* _newobj = new wxMask(param0);
  BasicVariable::ptr res = WrapClass_wxMask::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxMask::wxMask(...)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMask::wrap_wxMask_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_wxMask_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_wxMask_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_wxMask_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_wxMask_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMask::wxMask()
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxMask* _newobj = new wxMask();
  BasicVariable::ptr res = WrapClass_wxMask::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMask::wxMask(wxBitmap const & bitmap, wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & colour = *colour_smtptr;

  wxMask* _newobj = new wxMask(bitmap, colour);
  BasicVariable::ptr res = WrapClass_wxMask::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMask::wxMask(wxBitmap const & bitmap, int paletteIndex)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'paletteIndex'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  int paletteIndex;
  if (!get_val_param<int >(paletteIndex,_p,_n,true,true)) ClassReturnEmptyVar;

  wxMask* _newobj = new wxMask(bitmap, paletteIndex);
  BasicVariable::ptr res = WrapClass_wxMask::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxMask::wxMask(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_wxMask_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_wxMask_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  wxMask* _newobj = new wxMask(bitmap);
  BasicVariable::ptr res = WrapClass_wxMask::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxMask.
//---------------------------------------------------
void WrapClass_wxMask::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxMask object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxMask >::CreateVar( new wxMask(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of bool wxMask::Create(wxBitmap const & bitmap, wxColour const & colour)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_Create_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'colour'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_Create_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  boost::shared_ptr<wxColour > colour_smtptr;
  if (!get_val_smtptr_param<wxColour >(colour_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxColour const & colour = *colour_smtptr;

  bool res =   this->_objectptr->GetObj()->Create(bitmap, colour);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... wxMask::Create(...)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_Create::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_Create::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxMask::wrap_Create_1 m1(this->_objectptr);
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_Create_2 m2(this->_objectptr);
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxMask::wrap_Create_3 m3(this->_objectptr);
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of bool wxMask::Create(wxBitmap const & bitmap, int paletteIndex)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_Create_2::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'paletteIndex'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_Create_2::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>2) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  int paletteIndex;
  if (!get_val_param<int >(paletteIndex,_p,_n,true,true)) ClassReturnEmptyVar;

  bool res =   this->_objectptr->GetObj()->Create(bitmap, paletteIndex);
  return AMILabType<bool >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of bool wxMask::Create(wxBitmap const & bitmap)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_Create_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bitmap'")
  return_comments="returning a variable of type bool";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_Create_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxBitmap > bitmap_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bitmap_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxBitmap const & bitmap = *bitmap_smtptr;

  bool res =   this->_objectptr->GetObj()->Create(bitmap);
  return AMILabType<bool >::CreateVar(res);
}
/* The following types are missing: _GdkDrawable

//---------------------------------------------------
//  Wrapping of GdkBitmap * wxMask::GetBitmap()
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_GetBitmap::SetParametersComments()
{
  return_comments="returning a variable of type _GdkDrawable";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_GetBitmap::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  GdkBitmap * res =   this->_objectptr->GetObj()->GetBitmap();
  return AMILabType<_GdkDrawable >::CreateVar(res,true);
}
*/

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxMask::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxMask::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = WrapClass_wxClassInfo::CreateVar(res);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxMask & wxMask::operator =(wxMask const & param0)
//---------------------------------------------------
void WrapClass_wxMask::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxMask, "parameter named 'param0'")
  return_comments="returning a variable of type wxMask";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxMask::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxMask > param0_smtptr;
  if (!get_val_smtptr_param<wxMask >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxMask const & param0 = *param0_smtptr;

  wxMask & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxMask >::CreateVar(res);
}

