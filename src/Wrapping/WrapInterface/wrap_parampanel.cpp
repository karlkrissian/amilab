//
// C++ Implementation: wrap_parampanel
//
// Description: 
//
//
// Author: Karl Krissian <>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <iomanip>
#include <cassert>
#include "boost/format.hpp"

#include "paramlist.h"
#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
//#include "wrapfunctions_draw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "ParamPanel.hpp"
#include "wrap_parampanel.h"
#include "MainFrame.h"
#include "ami_function.h"
#include "wrap_wxWindow.h"
#include "wrap_wxNotebook.h"
#include "wrap_wxSizerItem.h"
#include "wrap_wxBoxSizer.h"

#include "wrap_wxBitmap.h"
#include "wrap_wxColour.h"

#define RETURN_VARINT(val,name)             \
  std::string varname = (boost::format("%1%_id")%name).str();\
  int_ptr varint(new int(val));\
  Variable<int>::ptr varres( new Variable<int>(varname, varint));\
  return varres;


extern MainFrame*     GB_main_wxFrame;
extern VarContexts Vars;

void CB_ParamWin( void* cd );
void CB_update_imagelist( void* imagelist_gui);
void CB_update_AMIObjectlist( void* AMIObjectlist_gui);



//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<ParamPanel>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_ParamPanel::wrap_ParamPanel construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(ParamPanel);

//
// static member for creating a variable from a pointer to wxHtmlWindow
//
Variable<AMIObject>::ptr WrapClass_ParamPanel::CreateVar( ParamPanel* sp)
{
  return 
    WrapClass<ParamPanel>::CreateVar(
      new WrapClass_ParamPanel(
        boost::shared_ptr<ParamPanel>(sp,
        wxwindow_nodeleter<ParamPanel>() 
        // deletion will be done by wxwidgets
        ))
    );
}


/*
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanel( ParamList* p)
{

  int n = 0;
  std::string* title = NULL;

  if (!get_val_ptr_param<string>(    title, p, n)) HelpAndReturnVarPtr;

  Variable<AMIObject>::ptr var;
  wxWindow* parent = GB_main_wxFrame;
  if (!get_var_param<AMIObject>(var, p, n)) 
    parent = GB_main_wxFrame;
  else
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_ParamPanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_ParamPanel>(object));
    if (obj.get()) {
      parent = obj->GetObj()->GetBookCtrl();
    }
  }

  ParamPanel::ptr pp;
  pp = ParamPanel::ptr(
    new ParamPanel(
      parent,
      (*title).c_str()),
      wxwindow_nodeleter<ParamPanel>() // deletion will be done by wxwidgets
    );

  WrapClass_ParamPanel::ptr wpp(new WrapClass_ParamPanel(pp));

  AMIObject::ptr amiobject (AddWrapParamPanel(wpp));

  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>("tmp_parampanel",  amiobject));

  return varres;

}
*/

//---------------------------------------------------
// Method that adds wrapping of ParamPanel
//---------------------------------------------------

void  WrapClass_ParamPanel::
      wrap_ParamPanel::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"title of the tab.");
  ADDPARAMCOMMENT_TYPE(wxWindow,"Optional: other parent parampanel with a notebook.");
  return_comments = "A wrapped ParamPanel object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::
      wrap_ParamPanel::CallMember( ParamList* p)
{

  int n = 0;
  std::string* title = NULL;

  if (!get_val_ptr_param<string>(    title, p, n)) ClassHelpAndReturn;

  Variable<AMIObject>::ptr var;
  wxWindow* parent = GB_main_wxFrame;
  if (!get_var_param<AMIObject>(var, p, n)) 
    parent = GB_main_wxFrame;
  else
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass<ParamPanel>::ptr obj( boost::dynamic_pointer_cast<WrapClass_ParamPanel>(object));
    if (obj.get()) {
      parent = obj->GetObj()->GetBookCtrl();
    } else {
      WrapClass<wxWindow>::ptr obj( boost::dynamic_pointer_cast<WrapClass_wxWindow>(object));
      if (obj.get()) {
        parent = obj->GetObj().get();
      }
    }
  }

  ParamPanel* pp =  new ParamPanel( parent, (*title).c_str());
  return WrapClass_ParamPanel::CreateVar(pp);

}


//---------------------------------------------------
//  GetBookCtrl
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_GetBookCtrl::SetParametersComments() 
{
  return_comments = "The control book.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_GetBookCtrl::CallMember( ParamList* p)
{
  wxNotebook* b = this->_objectptr->GetObj()->GetBookCtrl();

  if (b==NULL)
    return BasicVariable::ptr();
  else
    return AMILabType<wxNotebook>::CreateVar(b);

}


//---------------------------------------------------
//  BeginBook
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_BeginBook::SetParametersComments() 
{
  return_comments = "Identifier of the new book (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_BeginBook::CallMember( ParamList* p)
{
  int id = this->_objectptr->GetObj()->BeginBook();

  // create integer variable to return
  string name = (boost::format("book_%1%")%id).str();
  RETURN_VARINT(id,name.c_str());
}


//---------------------------------------------------
//  EndBook
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_EndBook::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_EndBook::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->EndBook();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginHorizontal
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_BeginHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_BeginHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->BeginHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  EndHorizontal
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_EndHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_EndHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->EndHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginBoxPanel
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_BeginBoxPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: box panel title.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_BeginBoxPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  this->_objectptr->GetObj()->BeginBox( label->c_str());
  int id = this->_objectptr->GetObj()->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndBoxPanel
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_EndBoxPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_EndBoxPanel::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->EndPanel();
  this->_objectptr->GetObj()->EndBox( );
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginPanel
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_BeginPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: panel title.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_BeginPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  int id = this->_objectptr->GetObj()->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndPanel
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_EndPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_EndPanel::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->EndPanel();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  AddFloat
//---------------------------------------------------
void WrapClass_ParamPanel::wrap_AddFloat::SetParametersComments()
{
  ADDPARAMCOMMENT("float variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:1)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddFloat::CallMember( ParamList* p)
{
  Variable<float>::ptr var;
  std::string* label = NULL;
  float minval = 0;
  float maxval = 1;
  int   n = 0;

  if (!get_var_param<float>(var, p, n))         ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( minval, p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( maxval, p, n))     ClassHelpAndReturn;

  float_ptr varval ( var->Pointer());
  // Setting comments
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  int var_id = this->_objectptr->GetObj()->AddFloat( varval.get(), label->c_str(),2,tooltip);
  this->_objectptr->GetObj()->FloatConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}

//---------------------------------------------------
//  FloatConstraints
//---------------------------------------------------
void WrapClass_ParamPanel::
      wrap_FloatConstraints::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"identifier of the parameter.");
  ADDPARAMCOMMENT_TYPE(float,"minimal value.");
  ADDPARAMCOMMENT_TYPE(float,"maximal value.");
  ADDPARAMCOMMENT_TYPE(float,"default value (def: (min+max)/2 ).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::
      wrap_FloatConstraints::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(int,id,0)
  GET_PARAM(float,minval,0)
  GET_PARAM(float,maxval,10)
  GET_PARAM(float,defval,(minval+maxval)/2.0)
  this->_objectptr->GetObj()->FloatConstraints(id,minval,maxval,defval);
  return BasicVariable::ptr();
}


//--------------------------------------------------
// AddInt
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddInt::SetParametersComments()
{
  ADDPARAMCOMMENT("int   : input variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:100)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddInt::CallMember( ParamList* p)
{
  Variable<int>::ptr var;
  std::string* label = NULL;
  int  minval = 0;
  int  maxval = 100;
  int  n = 0;

  if (!get_var_param<int>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>(label, p, n)) ClassHelpAndReturn;
  if (!get_int_param(minval, p, n))            ClassHelpAndReturn;
  if (!get_int_param(maxval, p, n))            ClassHelpAndReturn;

  int* varval =  var->Pointer().get();
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  int var_id = this->_objectptr->GetObj()->AddInteger( varval, label->c_str(), tooltip);
  this->_objectptr->GetObj()->IntegerConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//---------------------------------------------------
//  IntegerConstraints
//---------------------------------------------------
void WrapClass_ParamPanel::
      wrap_IntegerConstraints::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"identifier of the parameter.");
  ADDPARAMCOMMENT_TYPE(int,"minimal value.");
  ADDPARAMCOMMENT_TYPE(int,"maximal value.");
  ADDPARAMCOMMENT_TYPE(int,"default value (def: (min+max)/2 ).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::
      wrap_IntegerConstraints::CallMember( ParamList* p)
{
  int n=0;
  GET_PARAM(int,id,0)
  GET_PARAM(int,minval,0)
  GET_PARAM(int,maxval,10)
  GET_PARAM(int,defval,(int)(minval+maxval)/2.0)
  this->_objectptr->GetObj()->IntegerConstraints(id,minval,maxval,defval);
  return BasicVariable::ptr();
}


//--------------------------------------------------
// AddEnum
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddEnum::SetParametersComments()
{
  ADDPARAMCOMMENT("int var: input variable");
  ADDPARAMCOMMENT("string label (def: variable name)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddEnum::CallMember( ParamList* p)
{
  Variable<int>::ptr var;
  std::string* label = NULL;
  std::string label_val;
  int  n = 0;
  int  var_id;

  if (!get_var_param<int>(var, p, n))           ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n,false))
      ClassHelpAndReturn;

  // take care of default label value
  if (label==NULL)
    label_val = var->Name();
  else
    label_val = *label;

  int* varval =  var->Pointer().get();
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  this->_objectptr->GetObj()->AddEnumeration(  
                        &var_id,
                        varval,
                        label_val.c_str(),
                        EnumOptionMenu,
                        tooltip);
  //pw->EnumerationDefaut( var_id,  *var);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}

//--------------------------------------------------
// AddEnumChoice
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddEnumChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("expression: identificator of the enumeration parameter.");
  ADDPARAMCOMMENT("string expression: text associated to this choice.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddEnumChoice::CallMember( ParamList* p)
{
  int id;
  std::string* label = NULL;
  int  n = 0;
  int var_id;

  if (!get_int_param(id, p, n))                 ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddEnumChoice( id, &var_id, label->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label->c_str())
}


//--------------------------------------------------
//  Display
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_Display::SetParametersComments() {
/*
  ADDPARAMCOMMENT("Another parampanel object to display within other parameters (default: main notebook).");
*/
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_Display::CallMember( ParamList* p)
{
  //int  n = 0;

/*
  Variable<AMIObject>::ptr var;
  if (!get_var_param<AMIObject>(var, p, n)) 
  {
*/
    GB_main_wxFrame->AddParamPanelPage( this->_objectptr->GetObj(),
        this->_objectptr->GetObj()->GetName(),
        true // select as current page
        );
/*
  } else
  {
    // how to : 1. check the object type 2. get the object pointer
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_ParamPanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_ParamPanel>(object));
    if (obj.get()) {
      obj->GetObj()->AddPage(this->_objectptr->GetObj().get(), this->_objectptr->GetObj()->GetName().mb_str());
    } else
    {
      CLASS_ERROR("Could not cast dynamically the parameter ..., check its type");
      ClassHelpAndReturn;
    }
  }
*/
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  HidePanel
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_HidePanel::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_HidePanel::CallMember( ParamList* p)
{
  GB_main_wxFrame->RemoveParamPanelPage(this->_objectptr->GetObj());
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  ShowPanel
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_ShowPanel::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_ShowPanel::CallMember( ParamList* p)
{
  this->_objectptr->GetObj()->AfficheDialogue();
  return BasicVariable::ptr();
}


//--------------------------------------------------
// Update 
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_Update::SetParametersComments()
{
  ADDPARAMCOMMENT( "int (default:-1): parameter to update, -1 for all the parameters.");
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_Update::CallMember( ParamList* p)
{
  int paramnumber = -1;
  int   n = 0;
  if (!get_int_param( paramnumber, p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->MAJ();
  if (paramnumber==-1) {
    GB_main_wxFrame->GetAuiManager().Update();
  } else {
    this->_objectptr->GetObj()->UpdateParameter(paramnumber);
  }
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  AddPage
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "string: page title.");
  ADDPARAMCOMMENT(" Another parampanel object (optional).");
  return_comments = "Identifier of the new widget (int variable).";
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddPage::CallMember( ParamList* p)
{
  std::string* title = NULL;
  Variable<AMIObject>::ptr var;
  int   n = 0;

  if (!get_val_ptr_param<string>( title,  p, n)) ClassHelpAndReturn;

  int var_id;

  if (!get_var_param<AMIObject>(var, p, n)) 
    var_id = this->_objectptr->GetObj()->AddPage( title->c_str());
  else
  {
    // how to : 1. check the object type 2. get the object pointer
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass<ParamPanel>::ptr obj( boost::dynamic_pointer_cast<WrapClass_ParamPanel>(object));
    if (obj.get()) {
      var_id = this->_objectptr->GetObj()->AddPage(obj->GetObj().get(), 
                                                      title->c_str());
      this->_objectptr->GetObj()->Fit();
      obj->GetObj()->Show();
    } else
    {
      CLASS_ERROR("Could not cast dynamically the parameter ..., check its type");
      ClassHelpAndReturn;
    }
  }

  // create integer variable to return
  RETURN_VARINT(var_id,title->c_str())
}


//--------------------------------------------------
//  SelectPage
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_SelectPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "integer: book id.");
  ADDPARAMCOMMENT( "integer: page to select.");
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_SelectPage::CallMember( ParamList* p)
{
  int book_id;
  int page_id;
  int   n = 0;

  if (!get_int_param( book_id,  p, n)) ClassHelpAndReturn;
  if (!get_int_param( page_id,  p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SelectPage(book_id,page_id);
  return BasicVariable::ptr();
}


//--------------------------------------------------
// AddLabel
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddLabel::SetParametersComments()
{
  ADDPARAMCOMMENT("string expression: label name");
  ADDPARAMCOMMENT("string expression: label value");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddLabel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  std::string* label_name = NULL;
  std::string* label_val = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label_name, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label_val, p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->AddLabel( &var_id,
                label_name->c_str(),
                label_val->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label_name->c_str());
}


//--------------------------------------------------
// SetLabelValue
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_SetLabelValue::SetParametersComments()
{
  ADDPARAMCOMMENT("int: index");
  ADDPARAMCOMMENT("string expression: label value");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_SetLabelValue::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int label_id = 0;
  std::string* label_val = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_param<int>( label_id, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label_val, p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->SetLabelValue( label_id,
                label_val->c_str());

  return BasicVariable::ptr();
}




//--------------------------------------------------
// AddFilename
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddFilename::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  ADDPARAMCOMMENT("default path");
  ADDPARAMCOMMENT("default mask");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddFilename::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  std::string* defpath = NULL;
  std::string* defmask = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( defpath, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( defmask, p, n)) ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  
  string_ptr val_ptr(var->Pointer());
  this->_objectptr->GetObj()->AddFilename( &var_id, 
                                      val_ptr,
                                      label->c_str(),
                                      tooltip);
  this->_objectptr->GetObj()->ContraintesNomFichier(var_id,
                            defpath->c_str(),
                            (char*)"",
                            defmask->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddDirname
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddDirname::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddDirname::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
//  std::string* defpath = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  
  string_ptr val_ptr(var->Pointer());
  this->_objectptr->GetObj()->AddDirname( &var_id, 
                                      val_ptr,
                                      label->c_str(),
                                      tooltip);
  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddString
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddString::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddString::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  this->_objectptr->GetObj()->AjouteChaine( &var_id,
                                  var->Pointer(),
                                  label->c_str(),
                                  tooltip);
  this->_objectptr->GetObj()->ContraintesChaine(var_id, (char*) var->Pointer()->c_str());


  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddImageChoice
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddImageChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("string variable that will contain the name of the selected image");
  ADDPARAMCOMMENT("string label: description of the image to select");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddImageChoice::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  boost::shared_ptr<wxArrayString> imagelist;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  imagelist = Vars.SearchVariables(type_image);
  imagelist->Add(_T("BrowseImage"));

  // Get list of image names
  this->_objectptr->GetObj()->AddListChoice( &var_id,
      var->Pointer(),
      label->c_str(), // TODO: check param type
      imagelist,
      (void*)CB_update_imagelist, // TODO: check declaration
      EnumOptionMenu,
      tooltip,
      true // allowing drop
                              );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}

//--------------------------------------------------
// AddAMIObjectChoice
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddAMIObjectChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("string variable that will contain the name of the selected AMIObject");
  ADDPARAMCOMMENT("string label: description of the AMIObject to select");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddAMIObjectChoice::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  boost::shared_ptr<wxArrayString> AMIObjectlist;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  AMIObjectlist = Vars.SearchAMIObjectTypeVariables("SurfacePoly");
  AMIObjectlist->Add(_T("Select surface image..."));

  // Get list of image names
  this->_objectptr->GetObj()->AddListChoice( &var_id,
      var->Pointer(),
      label->c_str(), // TODO: check param type
      AMIObjectlist,
      (void*)CB_update_AMIObjectlist, // TODO: check declaration
      EnumOptionMenu,
      tooltip,
      true // allowing drop
                              );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddBoolean
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddBoolean::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type UCHAR.");
  ADDPARAMCOMMENT("String expression: label (def: variable name).");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddBoolean::CallMember( ParamList* p)
{
  Variable<unsigned char>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<unsigned char>(var, p, n))     ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n,false))   ClassHelpAndReturn;

  // take care of default label value
  std::string label_val;
  if (label==NULL)
    label_val = var->Name();
  else
    label_val = *label;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  unsigned char* valptr = var->Pointer().get();

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << std::endl;
  this->_objectptr->GetObj()->AddBoolean( &var_id,
                valptr,
                label_val.c_str(),
                CaractereToggle,
                tooltip);
  this->_objectptr->GetObj()->BooleanDefault( var_id, *valptr);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}



//--------------------------------------------------
// AddButton
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddButton::SetParametersComments()
{
  ADDPARAMCOMMENT("String: button label.");
  ADDPARAMCOMMENT("Variable of type ami_function.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddButton::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;
  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << std::endl;
  this->_objectptr->GetObj()->AddButton( &var_id, 
                label->c_str(),
                (void*) CB_ParamWin,
                (void*) var->Pointer().get(),
                tooltip);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddBitmapButton
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddBitmapButton::SetParametersComments()
{
  ADDPARAMCOMMENT("String: button label.");
  ADDPARAMCOMMENT("Variable of type ami_function.");
  ADDPARAMCOMMENT("wxBitmap parameter for bitmap.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddBitmapButton::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr varfunc;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;
  if (!get_var_param<AMIFunction>(varfunc, p, n))     ClassHelpAndReturn;
  GET_OBJECT_PARAM(wxBitmap,bitmap,GetObj());
  if (!bitmap.get())                              ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)")  % varfunc->GetComments() 
                                                    % varfunc->Name()).str();

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << std::endl;
  this->_objectptr->GetObj()->AddBitmapButton( &var_id, 
                label->c_str(),
                (void*) CB_ParamWin,
                (void*) varfunc->Pointer().get(),
                *bitmap,
                tooltip);

  // create integer variable to return
  RETURN_VARINT(var_id,varfunc->Name());
}

//--------------------------------------------------
// AddColor
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddColor::SetParametersComments()
{
  ADDPARAMCOMMENT("String: button label.");
  ADDPARAMCOMMENT("wxColour parameter.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddColor::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  GET_OBJECT_PARAM(wxColour,colour,GetObj());
  if (!colour.get())                              ClassHelpAndReturn;

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << std::endl;
  this->_objectptr->GetObj()->AddColor( &var_id, 
                label->c_str(),
                colour.get());

  // create integer variable to return
  RETURN_VAR(int,var_id);
}



//--------------------------------------------------
// SetCallback
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_SetCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type ami_function.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_SetCallback::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  int  n = 0;

  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  int nbp = this->_objectptr->GetObj()->NbParameters();

  this->_objectptr->GetObj()->ChangedValueCallback(nbp-1,
              (void*) CB_ParamWin,
              (void*) var->Pointer().get() );

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetDragCallback
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_SetDragCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the parameter for which to set the drag callback.");
  ADDPARAMCOMMENT("Boolean value: activate or desactivate the drag callbacks (def:true).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_SetDragCallback::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int paramid = 0;
  int activate = 1;
  int  n = 0;

  if (!get_int_param(paramid, p, n))     ClassHelpAndReturn;
  if (!get_int_param(activate, p, n))    ClassHelpAndReturn;

  int nbp = this->_objectptr->GetObj()->NbParameters();

  if ((paramid>=0)&&(paramid<nbp))
    this->_objectptr->GetObj()->SetDragCallback(paramid,activate);
  else
    FILE_ERROR((boost::format("bad parameter number %1%") % paramid).str().c_str());

  return BasicVariable::ptr();
}


//--------------------------------------------------
// EnablePanel
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_EnablePanel::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the panel.");
  ADDPARAMCOMMENT("Value enable:1 disable:0.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_EnablePanel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int id;
  int enable=1;
  int  n = 0;

  if (!get_int_param(id, p, n))          ClassHelpAndReturn;
  if (!get_int_param(enable, p, n))      ClassHelpAndReturn;

  int nbp = this->_objectptr->GetObj()->NbPanels();
  if ((id>=0)&&(id<nbp))
    this->_objectptr->GetObj()->EnablePanel(id,enable);
  else
    FILE_ERROR((boost::format(" bad parameter number %1% ")%id).str().c_str());

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetPositionProp
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_SetPositionProp::SetParametersComments()
{
  ADDPARAMCOMMENT("proportion property (0: not proportional, \
                               1: standard proportion,\
                               -1: keeps previous value)");
  ADDPARAMCOMMENT("border size ( def:-1 keeps previous value)");
  ADDPARAMCOMMENT("flags       ( -1 keeps previous value)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_SetPositionProp::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  prop_property = -1;
  int  border_size = -1;
  int  flags = -1;
  int  n = 0;

  if (!get_int_param(prop_property, p, n)) ClassHelpAndReturn;
  if (!get_int_param(border_size,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(flags,         p, n)) ClassHelpAndReturn;

/*
  int nbp = this->_objectptr->GetObj()->NbPanels();
  this->_objectptr->GetObj()->SetPositionProperties(
              nbp-1, 
              prop_property, 
              border_size,
              flags);
*/

  this->_objectptr->GetObj()->SetLastPositionProperties(
              prop_property, 
              border_size,
              flags);

  return BasicVariable::ptr();
}

//--------------------------------------------------
// ShowSlider
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_ShowSlider::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for show/hide.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_ShowSlider::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  show = 1;
  int  n = 0;

  if (!get_int_param(id,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(show, p, n)) ClassHelpAndReturn;

  this->_objectptr->GetObj()->ParamShowSlider(id,show );

  return BasicVariable::ptr();
}

//--------------------------------------------------
// Enable
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for enable/disable.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_Enable::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  enable = 1;
  int  n = 0;

  if (!get_int_param(id,     p, n)) ClassHelpAndReturn;
  if (!get_int_param(enable, p, n)) ClassHelpAndReturn;

  int nb = this->_objectptr->GetObj()->NbParameters();

  if ((id>=0)&&(id<nb))
    this->_objectptr->GetObj()->Enable(id,enable);
  else
    FILE_ERROR((boost::format(" %d  \t bad parameter number ")%id).str().c_str());

  return BasicVariable::ptr();
}


//--------------------------------------------------
// CurrentParent
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_CurrentParent::SetParametersComments()
{
  return_comments = "Returns the current parent for new parameters (object variable of type wxWindow).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_CurrentParent::CallMember( ParamList* p)
{
  wxWindow* parent = this->_objectptr->GetObj()->CurrentParent();

  // create the variable
  // Smart pointer to the wxWindow
  boost::shared_ptr<wxWindow> wxw_ptr(
      parent,
      wxwindow_nodeleter<wxWindow>()    );

  // Create the AMIObject with its methods
  return WrapClass<wxWindow>::CreateVar(new WrapClass_wxWindow(wxw_ptr));

}


//--------------------------------------------------
// GetCurrentSizer
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_GetCurrentSizer::SetParametersComments()
{
  return_comments = "Returns the current wxBoxSizer for new parameters ).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_GetCurrentSizer::CallMember( ParamList* p)
{
  wxBoxSizer* bsizer = this->_objectptr->GetObj()->GetCurrentSizer();

  // create the variable
  // Smart pointer to the wxWindow
  boost::shared_ptr<wxBoxSizer> wxw_ptr(
      bsizer,
      wxwindow_nodeleter<wxBoxSizer>()    );

  // Create the AMIObject with its methods
  return WrapClass<wxBoxSizer>::CreateVar(new WrapClass_wxBoxSizer(wxw_ptr));

}


//--------------------------------------------------
// AddWidget
//--------------------------------------------------
void WrapClass_ParamPanel::wrap_AddWidget::SetParametersComments()
{
  ADDPARAMCOMMENT("AMIObject variable wrapping a wxWindow.");
  ADDPARAMCOMMENT("integer: sizer proportion (default is 0).");
  return_comments = "Return corresponding wrapped wxSizerItem or empty variable if it fails.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_ParamPanel::wrap_AddWidget::CallMember( ParamList* p)
{
  Variable<AMIObject>::ptr var;
  wxSizerItem* res = NULL;
  int proportion=0;
  int n=0;

  bool getvar = get_var_param<AMIObject>(var, p, n);
  get_int_param(proportion, p, n, false);

  if (getvar) 
  {
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_wxWindow::ptr obj( boost::dynamic_pointer_cast<WrapClass_wxWindow>(object));
    if (obj.get()) {

      res = this->_objectptr->GetObj()->AddWidget(obj->GetObj().get(), proportion);
    } else {
      FILE_ERROR("Could not cast dynamically the variable to wxWindow.")
      ClassHelpAndReturn;
    }
  }  else {
    FILE_ERROR("Need a wrapped wxWindow object as parameter.")
    ClassHelpAndReturn;
  }

  return WrapClass_wxSizerItem::CreateVar(res);
}
