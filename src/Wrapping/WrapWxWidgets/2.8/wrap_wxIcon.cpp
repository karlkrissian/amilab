/**
 * C++ Interface: wrap_wxIcon
 *
 * Description: wrapping wxIcon
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

#include "wrap_wxIcon.h"

// get all the required includes
// #include "..."
#ifndef wxIcon_declared
  #define wxIcon_declared
  AMI_DECLARE_TYPE(wxIcon)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxIconLocation_declared
  #define wxIconLocation_declared
  AMI_DECLARE_TYPE(wxIconLocation)
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
BasicVariable::ptr WrapClass<wxIcon>::CreateVar( ParamList* p)
{
  WrapClass_wxIcon::wrap_wxIcon construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_HASCOPY(wxIcon);
AMI_DEFINE_VARFROMSMTPTR(wxIcon);


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxIcon
//
Variable<AMIObject>::ptr WrapClass_wxIcon::CreateVar( wxIcon* sp)
{
  boost::shared_ptr<wxIcon> di_ptr(
    sp,
    wxwindow_nodeleter<wxIcon>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxIcon>::CreateVar(
      new WrapClass_wxIcon(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxIcon::AddMethods(WrapClass<wxIcon>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding copy method 
  AddVar___copy__( this_ptr);
  // Adding standard methods 
  AddVar_CopyFromBitmap( this_ptr);
  AddVar_GetClassInfo( this_ptr);

  // Adding operators
  AddVar___assign__( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  


  // Adding Bases

  // Add base parent wxBitmap
  boost::shared_ptr<wxBitmap > parent_wxBitmap(  boost::dynamic_pointer_cast<wxBitmap >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxBitmap = AMILabType<wxBitmap >::CreateVarFromSmtPtr(parent_wxBitmap);
  context->AddVar("wxBitmap",var_wxBitmap);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxBitmap = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxBitmap);
  context->AddDefault(obj_wxBitmap->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxIcon_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxIcon");
    WrapClass_wxIcon::AddVar_wxIcon_1(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon_2(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon_3(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon_4(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon_5(amiobject->GetContext());
  WrapClass_wxIcon::AddVar_wxIcon_6(amiobject->GetContext());


  // Static methods 

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon(wxIcon const & param0)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_1::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'param0'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_1::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIcon > param0_smtptr;
  if (!get_val_smtptr_param<wxIcon >(param0_smtptr,_p,_n,true,true,true)) ClassReturnEmptyVar;
  wxIcon const & param0 = *param0_smtptr;

  wxIcon* _newobj = new wxIcon(param0);
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of multipled defined method:... Constructor wxIcon::wxIcon(...)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon::SetParametersComments()
{}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon::CallMember( ParamList* _p)
{
  BasicVariable::ptr res;
  WrapClass_wxIcon::wrap_wxIcon_1 m1;
  res = m1.CallMember(_p);
  if (!m1.Get_arg_failure()) return res;
  WrapClass_wxIcon::wrap_wxIcon_2 m2;
  res = m2.CallMember(_p);
  if (!m2.Get_arg_failure()) return res;
  WrapClass_wxIcon::wrap_wxIcon_3 m3;
  res = m3.CallMember(_p);
  if (!m3.Get_arg_failure()) return res;
  WrapClass_wxIcon::wrap_wxIcon_4 m4;
  res = m4.CallMember(_p);
  if (!m4.Get_arg_failure()) return res;
  WrapClass_wxIcon::wrap_wxIcon_5 m5;
  res = m5.CallMember(_p);
  if (!m5.Get_arg_failure()) return res;
  WrapClass_wxIcon::wrap_wxIcon_6 m6;
  res = m6.CallMember(_p);
  if (!m6.Get_arg_failure()) return res;
  ClassHelpAndReturn;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon()
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_2::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_2::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassReturnEmptyVar;

  wxIcon* _newobj = new wxIcon();
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon(char const * * bits, int width = -0x00000000000000001, int height = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_3::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'bits'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_3::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > bits_string;
  if (!get_val_smtptr_param<std::string >(bits_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  // this conversion is probably not correct but should compile
char* bits_pointer = (char*)bits_string->c_str();
char const * * bits = (char const * *) &bits_pointer;

  int width = -0x00000000000000001;
  if (!get_val_param<int >(width,_p,_n,false,true)) ClassReturnEmptyVar;

  int height = -0x00000000000000001;
  if (!get_val_param<int >(height,_p,_n,false,true)) ClassReturnEmptyVar;

  wxIcon* _newobj = new wxIcon(bits, width, height);
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon(char * * bits, int width = -0x00000000000000001, int height = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_4::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( std::string, "parameter named 'bits'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'width' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'height' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_4::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>3) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<std::string > bits_string;
  if (!get_val_smtptr_param<std::string >(bits_string,_p,_n,true,false,true)) ClassReturnEmptyVar;
  // this conversion is probably not correct but should compile
char* bits_pointer = (char*)bits_string->c_str();
char * * bits = (char * *) &bits_pointer;

  int width = -0x00000000000000001;
  if (!get_val_param<int >(width,_p,_n,false,true)) ClassReturnEmptyVar;

  int height = -0x00000000000000001;
  if (!get_val_param<int >(height,_p,_n,false,true)) ClassReturnEmptyVar;

  wxIcon* _newobj = new wxIcon(bits, width, height);
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon(wxString const & filename, wxBitmapType type = wxBITMAP_TYPE_XPM, int param2 = -0x00000000000000001, int param3 = -0x00000000000000001)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_5::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'filename'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type' (def:wxBITMAP_TYPE_XPM)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param2' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'param3' (def:-0x00000000000000001)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_5::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>4) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxString > filename_smtptr;
  if (!get_val_smtptr_param<wxString >(filename_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxString const & filename = *filename_smtptr;

  int type_int = (int) wxBITMAP_TYPE_XPM;;
  if (!get_val_param<int >(type_int,_p,_n,false,true)) ClassReturnEmptyVar;
  wxBitmapType type = (wxBitmapType) type_int;

  int param2 = -0x00000000000000001;
  if (!get_val_param<int >(param2,_p,_n,false,true)) ClassReturnEmptyVar;

  int param3 = -0x00000000000000001;
  if (!get_val_param<int >(param3,_p,_n,false,true)) ClassReturnEmptyVar;

  wxIcon* _newobj = new wxIcon(filename, type, param2, param3);
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of Constructor wxIcon::wxIcon(wxIconLocation const & loc)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_wxIcon_6::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIconLocation, "parameter named 'loc'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_wxIcon_6::CallMember( ParamList* _p)
{
  if (!_p) ClassReturnEmptyVar;
  if (_p->GetNumParam()>1) ClassReturnEmptyVar;
  int _n=0;

  boost::shared_ptr<wxIconLocation > loc_smtptr;
  if (!get_val_smtptr_param<wxIconLocation >(loc_smtptr,_p,_n,true,false,true)) ClassReturnEmptyVar;
  wxIconLocation const & loc = *loc_smtptr;

  wxIcon* _newobj = new wxIcon(loc);
  BasicVariable::ptr res = WrapClass_wxIcon::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of 'copy' method for wxIcon.
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap___copy__::SetParametersComments()
{
  return_comments="A copy of the wxIcon object within a new variable.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap___copy__::CallMember( ParamList* _p)
{
    return AMILabType<wxIcon >::CreateVar( new wxIcon(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  Wrapping of void wxIcon::CopyFromBitmap(wxBitmap const & bmp)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_CopyFromBitmap::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxBitmap, "parameter named 'bmp'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_CopyFromBitmap::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxBitmap > bmp_smtptr;
  if (!get_val_smtptr_param<wxBitmap >(bmp_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxBitmap const & bmp = *bmp_smtptr;

  this->_objectptr->GetObj()->CopyFromBitmap(bmp);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxIcon::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxIcon & wxIcon::operator =(wxIcon const & param0)
//---------------------------------------------------
void WrapClass_wxIcon::
    wrap___assign__::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxIcon, "parameter named 'param0'")
  return_comments="returning a variable of type wxIcon";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxIcon::
    wrap___assign__::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxIcon > param0_smtptr;
  if (!get_val_smtptr_param<wxIcon >(param0_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxIcon const & param0 = *param0_smtptr;

  wxIcon & res =   (*this->_objectptr->GetObj()) = (param0);
  return AMILabType<wxIcon >::CreateVar(res);
}

