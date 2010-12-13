/**
 * C++ Interface: wrap_wxHtmlWinParser
 *
 * Description: wrapping wxHtmlWinParser
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

#include "wrap_wxHtmlWinParser.h"

// get all the required includes
// #include "..."
#ifndef wxHtmlWindowInterface_declared
  #define wxHtmlWindowInterface_declared
  AMI_DECLARE_TYPE(wxHtmlWindowInterface)
#endif
#ifndef wxHtmlTagsModule_declared
  #define wxHtmlTagsModule_declared
  AMI_DECLARE_TYPE(wxHtmlTagsModule)
#endif
#ifndef wxClassInfo_declared
  #define wxClassInfo_declared
  AMI_DECLARE_TYPE(wxClassInfo)
#endif
#ifndef wxString_declared
  #define wxString_declared
  AMI_DECLARE_TYPE(wxString)
#endif
#ifndef wxObject_declared
  #define wxObject_declared
  AMI_DECLARE_TYPE(wxObject)
#endif
#ifndef wxFSFile_declared
  #define wxFSFile_declared
  AMI_DECLARE_TYPE(wxFSFile)
#endif
#ifndef wxDC_declared
  #define wxDC_declared
  AMI_DECLARE_TYPE(wxDC)
#endif
#ifndef wxHtmlContainerCell_declared
  #define wxHtmlContainerCell_declared
  AMI_DECLARE_TYPE(wxHtmlContainerCell)
#endif
#ifndef wxColour_declared
  #define wxColour_declared
  AMI_DECLARE_TYPE(wxColour)
#endif
#ifndef wxHtmlLinkInfo_declared
  #define wxHtmlLinkInfo_declared
  AMI_DECLARE_TYPE(wxHtmlLinkInfo)
#endif
#ifndef wxHtmlCell_declared
  #define wxHtmlCell_declared
  AMI_DECLARE_TYPE(wxHtmlCell)
#endif
#ifndef wxFont_declared
  #define wxFont_declared
  AMI_DECLARE_TYPE(wxFont)
#endif



// needed to allow NULL pointer parameter
extern Variable<int>::ptr nullvar;
extern bool CheckNullVar(ParamList* _p, int _n);

//----------------------------------------------------------------------
//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxHtmlWinParser>::CreateVar( ParamList* p)
{
  WrapClass_wxHtmlWinParser::wrap_wxHtmlWinParser construct;
  return construct.CallMember(p);

}


AMI_DEFINE_WRAPPEDTYPE_NOCOPY(wxHtmlWinParser);
AMI_DEFINE_VARFROMSMTPTR(wxHtmlWinParser);

// Implementing CreateVar for AMILabType
BasicVariable::ptr AMILabType<wxHtmlWinParser>::CreateVar( wxHtmlWinParser* val, bool nodeleter)
{ 
  boost::shared_ptr<wxHtmlWinParser> obj_ptr(val,smartpointer_nodeleter<wxHtmlWinParser>());
  return AMILabType<wxHtmlWinParser>::CreateVarFromSmtPtr(obj_ptr);
}


//----------------------------------------------------------------------
//
// static member for creating a variable from a pointer to wxHtmlWinParser
//
Variable<AMIObject>::ptr WrapClass_wxHtmlWinParser::CreateVar( wxHtmlWinParser* sp)
{
  boost::shared_ptr<wxHtmlWinParser> di_ptr(
    sp,
    wxwindow_nodeleter<wxHtmlWinParser>()); // deletion will be done by wxwidgets;
  Variable<AMIObject>::ptr res = 
    WrapClass<wxHtmlWinParser>::CreateVar(
      new WrapClass_wxHtmlWinParser(di_ptr)
    );
  return res;
}

//----------------------------------------------------------------------
void WrapClass_wxHtmlWinParser::AddMethods(WrapClass<wxHtmlWinParser>::ptr this_ptr )
{
  // todo: check that the method name is not a token ?
  
  // Adding standard methods 
  AddVar_GetClassInfo( this_ptr);
  AddVar_InitParser( this_ptr);
  AddVar_DoneParser( this_ptr);
  AddVar_GetProduct( this_ptr);
  AddVar_OpenURL( this_ptr);
  AddVar_SetDC( this_ptr);
  AddVar_GetDC( this_ptr);
  AddVar_GetPixelScale( this_ptr);
  AddVar_GetCharHeight( this_ptr);
  AddVar_GetCharWidth( this_ptr);
  AddVar_GetWindowInterface( this_ptr);
  AddVar_SetFonts( this_ptr);
  AddVar_SetStandardFonts( this_ptr);
  AddVar_GetContainer( this_ptr);
  AddVar_OpenContainer( this_ptr);
  AddVar_SetContainer( this_ptr);
  AddVar_CloseContainer( this_ptr);
  AddVar_GetFontSize( this_ptr);
  AddVar_SetFontSize( this_ptr);
  AddVar_GetFontBold( this_ptr);
  AddVar_SetFontBold( this_ptr);
  AddVar_GetFontItalic( this_ptr);
  AddVar_SetFontItalic( this_ptr);
  AddVar_GetFontUnderlined( this_ptr);
  AddVar_SetFontUnderlined( this_ptr);
  AddVar_GetFontFixed( this_ptr);
  AddVar_SetFontFixed( this_ptr);
  AddVar_GetFontFace( this_ptr);
  AddVar_SetFontFace( this_ptr);
  AddVar_GetAlign( this_ptr);
  AddVar_SetAlign( this_ptr);
  AddVar_GetScriptMode( this_ptr);
  AddVar_SetScriptMode( this_ptr);
  AddVar_GetScriptBaseline( this_ptr);
  AddVar_SetScriptBaseline( this_ptr);
  AddVar_GetLinkColor( this_ptr);
  AddVar_SetLinkColor( this_ptr);
  AddVar_GetActualColor( this_ptr);
  AddVar_SetActualColor( this_ptr);
  AddVar_GetLink( this_ptr);
  AddVar_SetLink( this_ptr);
  AddVar_ApplyStateToCell( this_ptr);
  AddVar_CreateCurrentFont( this_ptr);
  AddVar_SetWhitespaceMode( this_ptr);
  AddVar_GetWhitespaceMode( this_ptr);



  // Add public fields and Enumerations
  AMIObject::ptr tmpobj(amiobject.lock());
  if (!tmpobj.get()) return;
  Variables::ptr context(tmpobj->GetContext());


  
  AMIObject::ptr obj_WhitespaceMode(new AMIObject);
  obj_WhitespaceMode->SetName("WhitespaceMode");

  BasicVariable::ptr var_Whitespace_Normal = AMILabType<int >::CreateVar(0);
  if (var_Whitespace_Normal.get()) {
    var_Whitespace_Normal->Rename("Whitespace_Normal");
    obj_WhitespaceMode->GetContext()->AddVar(var_Whitespace_Normal,obj_WhitespaceMode->GetContext());
  }

  // Add enum to context
  context->AddVar<AMIObject>(obj_WhitespaceMode->GetName().c_str(),obj_WhitespaceMode,context);


  // Adding Bases

  // Add base parent wxHtmlParser
  boost::shared_ptr<wxHtmlParser > parent_wxHtmlParser(  boost::dynamic_pointer_cast<wxHtmlParser >(this_ptr->GetObj()));
  BasicVariable::ptr var_wxHtmlParser = AMILabType<wxHtmlParser >::CreateVarFromSmtPtr(parent_wxHtmlParser);
  context->AddVar("wxHtmlParser",var_wxHtmlParser);
  // Set as a default context
  Variable<AMIObject>::ptr obj_wxHtmlParser = boost::dynamic_pointer_cast<Variable<AMIObject> >(var_wxHtmlParser);
  context->AddDefault(obj_wxHtmlParser->Pointer()->GetContext());

};


/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlWinParser_AddStaticMethods( Variables::ptr& context)
{
  // Create a new context (or namespace) for the class
  AMIObject::ptr amiobject(new AMIObject);
  amiobject->SetName("wxHtmlWinParser");
    WrapClass_wxHtmlWinParser::AddVar_wxHtmlWinParser(amiobject->GetContext());


  // Static methods 
  WrapClass_wxHtmlWinParser::AddVar_AddModule(amiobject->GetContext());
  WrapClass_wxHtmlWinParser::AddVar_RemoveModule(amiobject->GetContext());

  //  add it to the given context
  context->AddVar<AMIObject>( amiobject->GetName().c_str(), amiobject, context);
  
}

//----------------------------------------------------------------------
// PUBLIC METHODS
//----------------------------------------------------------------------


//---------------------------------------------------
//  Wrapping of Constructor wxHtmlWinParser::wxHtmlWinParser(wxHtmlWindowInterface * wndIface = 0l)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_wxHtmlWinParser::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlWindowInterface, "parameter named 'wndIface' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_wxHtmlWinParser::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlWindowInterface* wndIface = 0l;
  if (CheckNullVar(_p,_n))  {
    wndIface=(wxHtmlWindowInterface*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlWindowInterface > wndIface_smtptr;
    if (!get_val_smtptr_param<wxHtmlWindowInterface >(wndIface_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    wndIface = wndIface_smtptr.get();
  }

  wxHtmlWinParser* _newobj = new wxHtmlWinParser(wndIface);
  BasicVariable::ptr res = WrapClass_wxHtmlWinParser::CreateVar(_newobj);
  return res;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::AddModule(wxHtmlTagsModule * module)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_static_AddModule::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagsModule, "parameter named 'module'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_static_AddModule::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlTagsModule* module;
  if (CheckNullVar(_p,_n))  {
    module=(wxHtmlTagsModule*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlTagsModule > module_smtptr;
    if (!get_val_smtptr_param<wxHtmlTagsModule >(module_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    module = module_smtptr.get();
  }

  wxHtmlWinParser::AddModule(module);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::RemoveModule(wxHtmlTagsModule * module)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_static_RemoveModule::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlTagsModule, "parameter named 'module'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_static_RemoveModule::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlTagsModule* module;
  if (CheckNullVar(_p,_n))  {
    module=(wxHtmlTagsModule*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlTagsModule > module_smtptr;
    if (!get_val_smtptr_param<wxHtmlTagsModule >(module_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    module = module_smtptr.get();
  }

  wxHtmlWinParser::RemoveModule(module);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxClassInfo * wxHtmlWinParser::GetClassInfo()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetClassInfo::SetParametersComments()
{
  return_comments="returning a variable of type wxClassInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetClassInfo::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxClassInfo * res =   this->_objectptr->GetObj()->GetClassInfo();
  BasicVariable::ptr res_var = AMILabType<wxClassInfo >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::InitParser(wxString const & source)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_InitParser::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'source'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_InitParser::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > source_smtptr;
  if (!get_val_smtptr_param<wxString >(source_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & source = *source_smtptr;

  this->_objectptr->GetObj()->InitParser(source);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::DoneParser()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_DoneParser::SetParametersComments()
{
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_DoneParser::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  this->_objectptr->GetObj()->DoneParser();
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxObject * wxHtmlWinParser::GetProduct()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetProduct::SetParametersComments()
{
  return_comments="returning a variable of type wxObject";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetProduct::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxObject * res =   this->_objectptr->GetObj()->GetProduct();
  BasicVariable::ptr res_var = AMILabType<wxObject >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxFSFile * wxHtmlWinParser::OpenURL(wxHtmlURLType type, wxString const & url)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_OpenURL::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'type'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'url'")
  return_comments="returning a variable of type wxFSFile";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_OpenURL::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  int type_int;
  if (!get_val_param<int >(type_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlURLType type = (wxHtmlURLType) type_int;

  boost::shared_ptr<wxString > url_smtptr;
  if (!get_val_smtptr_param<wxString >(url_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & url = *url_smtptr;

  wxFSFile * res =   this->_objectptr->GetObj()->OpenURL(type, url);
  BasicVariable::ptr res_var = AMILabType<wxFSFile >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetDC(wxDC * dc, double pixel_scale = 1.0e+0)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetDC::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxDC, "parameter named 'dc'")
  ADDPARAMCOMMENT_TYPE( double, "parameter named 'pixel_scale' (def:1.0e+0)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetDC::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>2) ClassHelpAndReturn;
  int _n=0;

  wxDC* dc;
  if (CheckNullVar(_p,_n))  {
    dc=(wxDC*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxDC > dc_smtptr;
    if (!get_val_smtptr_param<wxDC >(dc_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    dc = dc_smtptr.get();
  }

  double pixel_scale = 1.0e+0;
  if (!get_val_param<double >(pixel_scale,_p,_n,false,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetDC(dc, pixel_scale);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxDC * wxHtmlWinParser::GetDC()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetDC::SetParametersComments()
{
  return_comments="returning a variable of type wxDC";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetDC::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxDC * res =   this->_objectptr->GetObj()->GetDC();
  BasicVariable::ptr res_var = AMILabType<wxDC >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of double wxHtmlWinParser::GetPixelScale()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetPixelScale::SetParametersComments()
{
  return_comments="returning a variable of type double";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetPixelScale::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  double res =   this->_objectptr->GetObj()->GetPixelScale();
  return AMILabType<double >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetCharHeight()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetCharHeight::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetCharHeight::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCharHeight();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetCharWidth()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetCharWidth::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetCharWidth::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetCharWidth();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of wxHtmlWindowInterface * wxHtmlWinParser::GetWindowInterface()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetWindowInterface::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlWindowInterface";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetWindowInterface::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlWindowInterface * res =   this->_objectptr->GetObj()->GetWindowInterface();
  BasicVariable::ptr res_var = AMILabType<wxHtmlWindowInterface >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFonts(wxString const & normal_face, wxString const & fixed_face, int const * sizes = 0l)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFonts::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'normal_face'")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fixed_face'")
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'sizes' (def:0l)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFonts::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > normal_face_smtptr;
  if (!get_val_smtptr_param<wxString >(normal_face_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & normal_face = *normal_face_smtptr;

  boost::shared_ptr<wxString > fixed_face_smtptr;
  if (!get_val_smtptr_param<wxString >(fixed_face_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & fixed_face = *fixed_face_smtptr;

  int* sizes = 0l;
  if (CheckNullVar(_p,_n))  {
    sizes=(int*)NULL;
    _n++;
  } else {
    boost::shared_ptr<int > sizes_smtptr;
    if (!get_val_smtptr_param<int >(sizes_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
    sizes = sizes_smtptr.get();
  }

  this->_objectptr->GetObj()->SetFonts(normal_face, fixed_face, sizes);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetStandardFonts(int size = -0x00000000000000001, wxString const & normal_face = wxEmptyString, wxString const & fixed_face = wxEmptyString)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetStandardFonts::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'size' (def:-0x00000000000000001)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'normal_face' (def:wxEmptyString)")
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'fixed_face' (def:wxEmptyString)")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetStandardFonts::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>3) ClassHelpAndReturn;
  int _n=0;

  int size = -0x00000000000000001;
  if (!get_val_param<int >(size,_p,_n,false,false)) ClassHelpAndReturn;

  boost::shared_ptr<wxString > normal_face_smtptr;
  if (!get_val_smtptr_param<wxString >(normal_face_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & normal_face = ( normal_face_smtptr.get() ? (*normal_face_smtptr) : wxString(wxEmptyString) );

  boost::shared_ptr<wxString > fixed_face_smtptr;
  if (!get_val_smtptr_param<wxString >(fixed_face_smtptr,_p,_n,false,false,false)) ClassHelpAndReturn;
  // Setting default value if no value is returned
  wxString const & fixed_face = ( fixed_face_smtptr.get() ? (*fixed_face_smtptr) : wxString(wxEmptyString) );

  this->_objectptr->GetObj()->SetStandardFonts(size, normal_face, fixed_face);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlWinParser::GetContainer()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetContainer::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetContainer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->GetContainer();
  BasicVariable::ptr res_var = AMILabType<wxHtmlContainerCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlWinParser::OpenContainer()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_OpenContainer::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_OpenContainer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->OpenContainer();
  BasicVariable::ptr res_var = AMILabType<wxHtmlContainerCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlWinParser::SetContainer(wxHtmlContainerCell * c)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetContainer::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlContainerCell, "parameter named 'c'")
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetContainer::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlContainerCell* c;
  if (CheckNullVar(_p,_n))  {
    c=(wxHtmlContainerCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlContainerCell > c_smtptr;
    if (!get_val_smtptr_param<wxHtmlContainerCell >(c_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    c = c_smtptr.get();
  }

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->SetContainer(c);
  BasicVariable::ptr res_var = AMILabType<wxHtmlContainerCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of wxHtmlContainerCell * wxHtmlWinParser::CloseContainer()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_CloseContainer::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlContainerCell";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_CloseContainer::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlContainerCell * res =   this->_objectptr->GetObj()->CloseContainer();
  BasicVariable::ptr res_var = AMILabType<wxHtmlContainerCell >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetFontSize()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontSize::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontSize::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFontSize();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontSize(int s)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontSize::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 's'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontSize::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int s;
  if (!get_val_param<int >(s,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFontSize(s);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetFontBold()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontBold::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontBold::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFontBold();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontBold(int x)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontBold::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontBold::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFontBold(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetFontItalic()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontItalic::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontItalic::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFontItalic();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontItalic(int x)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontItalic::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontItalic::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFontItalic(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetFontUnderlined()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontUnderlined::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontUnderlined::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFontUnderlined();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontUnderlined(int x)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontUnderlined::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontUnderlined::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFontUnderlined(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetFontFixed()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontFixed::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontFixed::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetFontFixed();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontFixed(int x)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontFixed::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'x'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontFixed::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int x;
  if (!get_val_param<int >(x,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetFontFixed(x);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxString wxHtmlWinParser::GetFontFace()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetFontFace::SetParametersComments()
{
  return_comments="returning a variable of type wxString";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetFontFace::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxString res =   this->_objectptr->GetObj()->GetFontFace();
  return AMILabType<wxString >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetFontFace(wxString const & face)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetFontFace::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxString, "parameter named 'face'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetFontFace::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxString > face_smtptr;
  if (!get_val_smtptr_param<wxString >(face_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxString const & face = *face_smtptr;

  this->_objectptr->GetObj()->SetFontFace(face);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of int wxHtmlWinParser::GetAlign()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetAlign::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetAlign::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  int res =   this->_objectptr->GetObj()->GetAlign();
  return AMILabType<int >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetAlign(int a)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetAlign::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'a'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetAlign::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int a;
  if (!get_val_param<int >(a,_p,_n,true,false)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetAlign(a);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlScriptMode wxHtmlWinParser::GetScriptMode()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetScriptMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetScriptMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlScriptMode res =   this->_objectptr->GetObj()->GetScriptMode();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetScriptMode(wxHtmlScriptMode mode)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetScriptMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetScriptMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mode_int;
  if (!get_val_param<int >(mode_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlScriptMode mode = (wxHtmlScriptMode) mode_int;

  this->_objectptr->GetObj()->SetScriptMode(mode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of long int wxHtmlWinParser::GetScriptBaseline()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetScriptBaseline::SetParametersComments()
{
  return_comments="returning a variable of type long";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetScriptBaseline::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  long int res =   this->_objectptr->GetObj()->GetScriptBaseline();
  long res_long = res;
  return AMILabType<long >::CreateVar(res_long);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetScriptBaseline(long int base)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetScriptBaseline::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( long, "parameter named 'base'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetScriptBaseline::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  long base_long;
  if (!get_val_param<long >(base_long,_p,_n,true,false)) ClassHelpAndReturn;
  long int base = base_long;

  this->_objectptr->GetObj()->SetScriptBaseline(base);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxHtmlWinParser::GetLinkColor()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetLinkColor::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetLinkColor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetLinkColor();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetLinkColor(wxColour const & clr)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetLinkColor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetLinkColor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > clr_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr = *clr_smtptr;

  this->_objectptr->GetObj()->SetLinkColor(clr);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxColour const & wxHtmlWinParser::GetActualColor()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetActualColor::SetParametersComments()
{
  return_comments="returning a variable of type wxColour";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetActualColor::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxColour const & res =   this->_objectptr->GetObj()->GetActualColor();
  return AMILabType<wxColour >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetActualColor(wxColour const & clr)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetActualColor::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxColour, "parameter named 'clr'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetActualColor::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxColour > clr_smtptr;
  if (!get_val_smtptr_param<wxColour >(clr_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxColour const & clr = *clr_smtptr;

  this->_objectptr->GetObj()->SetActualColor(clr);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlLinkInfo const & wxHtmlWinParser::GetLink()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetLink::SetParametersComments()
{
  return_comments="returning a variable of type wxHtmlLinkInfo";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetLink::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlLinkInfo const & res =   this->_objectptr->GetObj()->GetLink();
  return AMILabType<wxHtmlLinkInfo >::CreateVar(res);
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetLink(wxHtmlLinkInfo const & link)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetLink::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlLinkInfo, "parameter named 'link'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetLink::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  boost::shared_ptr<wxHtmlLinkInfo > link_smtptr;
  if (!get_val_smtptr_param<wxHtmlLinkInfo >(link_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
  wxHtmlLinkInfo const & link = *link_smtptr;

  this->_objectptr->GetObj()->SetLink(link);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::ApplyStateToCell(wxHtmlCell * cell)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_ApplyStateToCell::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( wxHtmlCell, "parameter named 'cell'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_ApplyStateToCell::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  wxHtmlCell* cell;
  if (CheckNullVar(_p,_n))  {
    cell=(wxHtmlCell*)NULL;
    _n++;
  } else {
    boost::shared_ptr<wxHtmlCell > cell_smtptr;
    if (!get_val_smtptr_param<wxHtmlCell >(cell_smtptr,_p,_n,true,false,false)) ClassHelpAndReturn;
    cell = cell_smtptr.get();
  }

  this->_objectptr->GetObj()->ApplyStateToCell(cell);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxFont * wxHtmlWinParser::CreateCurrentFont()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_CreateCurrentFont::SetParametersComments()
{
  return_comments="returning a variable of type wxFont";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_CreateCurrentFont::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxFont * res =   this->_objectptr->GetObj()->CreateCurrentFont();
  BasicVariable::ptr res_var = AMILabType<wxFont >::CreateVar(res,true);
  return res_var;
}

//---------------------------------------------------
//  Wrapping of void wxHtmlWinParser::SetWhitespaceMode(wxHtmlWinParser::WhitespaceMode mode)
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_SetWhitespaceMode::SetParametersComments()
{
  ADDPARAMCOMMENT_TYPE( int, "parameter named 'mode'")
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_SetWhitespaceMode::CallMember( ParamList* _p)
{
  if (!_p) ClassHelpAndReturn;
  if (_p->GetNumParam()>1) ClassHelpAndReturn;
  int _n=0;

  int mode_int;
  if (!get_val_param<int >(mode_int,_p,_n,true,false)) ClassHelpAndReturn;
  wxHtmlWinParser::WhitespaceMode mode = (wxHtmlWinParser::WhitespaceMode) mode_int;

  this->_objectptr->GetObj()->SetWhitespaceMode(mode);
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Wrapping of wxHtmlWinParser::WhitespaceMode wxHtmlWinParser::GetWhitespaceMode()
//---------------------------------------------------
void WrapClass_wxHtmlWinParser::
    wrap_GetWhitespaceMode::SetParametersComments()
{
  return_comments="returning a variable of type int";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_wxHtmlWinParser::
    wrap_GetWhitespaceMode::CallMember( ParamList* _p)
{
  if (_p)  if (_p->GetNumParam()>0) ClassHelpAndReturn;

  wxHtmlWinParser::WhitespaceMode res =   this->_objectptr->GetObj()->GetWhitespaceMode();
  int res_int = (int) res;
  return AMILabType<int >::CreateVar(res_int);
}

