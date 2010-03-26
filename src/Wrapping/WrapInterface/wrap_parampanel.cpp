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

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "wrapfunctions_draw.h"
#include "ami_class.h"
#include "ami_object.h"
#include "ParamPanel.hpp"
#include "wrap_parampanel.h"
#include "MainFrame.h"
#include "ami_function.h"


#define RETURN_VARINT(val,name)             \
  std::string varname = (boost::format("%1%_id")%name).str();\
  int_ptr varint(new int(val));\
  Variable<int>::ptr varres( new Variable<int>(varname, varint));\
  return varres;


extern MainFrame*     GB_main_wxFrame;
extern VarContexts Vars;

void CB_ParamWin( void* cd );
void CB_update_imagelist( void* imagelist_gui);

//-------------------------------------------------------------------------
AMIObject::ptr AddWrapParamPanel(  WrapClass_parampanel::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("parampanel");

  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);

  objectptr->AddVar_BeginBook(        objectptr);
  objectptr->AddVar_EndBook(          objectptr);
  objectptr->AddVar_BeginHorizontal(  objectptr);
  objectptr->AddVar_EndHorizontal(    objectptr);
  objectptr->AddVar_BeginBoxPanel(    objectptr);
  objectptr->AddVar_EndBoxPanel(      objectptr);

  objectptr->AddVar_BeginPanel(       objectptr);
  objectptr->AddVar_EndPanel(         objectptr);

  objectptr->AddVar_AddPage(          objectptr);
  objectptr->AddVar_SelectPage(       objectptr);

  objectptr->AddVar_AddFloat(         objectptr);
  objectptr->AddVar_AddInt(           objectptr);
  objectptr->AddVar_AddEnum(          objectptr);
  objectptr->AddVar_AddEnumChoice(    objectptr);
  objectptr->AddVar_AddLabel(         objectptr);
  objectptr->AddVar_AddFilename(      objectptr);
  objectptr->AddVar_AddString(        objectptr);
  objectptr->AddVar_AddImageChoice(   objectptr);
  objectptr->AddVar_AddButton(        objectptr);
  objectptr->AddVar_AddBoolean(       objectptr);
  objectptr->AddVar_SetCallback(      objectptr);
  objectptr->AddVar_SetDragCallback(  objectptr);
  objectptr->AddVar_EnablePanel(      objectptr);

  objectptr->AddVar_Display(          objectptr);
  objectptr->AddVar_HidePanel(        objectptr);
  objectptr->AddVar_Update(           objectptr);
  objectptr->AddVar_ShowPanel(        objectptr);

  objectptr->AddVar_SetPositionProp(  objectptr);
  objectptr->AddVar_ShowSlider(       objectptr);
  objectptr->AddVar_Enable(           objectptr);

  return amiobject;
}

//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanel( ParamList* p)
{
    char functionname[] = "ParamPanel";
    char description[]=" \n\
      New ParamPanel object, for creating GUI. \n\
            ";
    char parameters[] =" \n\
      - title of the tab \n\
      - Optional: other parent parampanel with a notebook \n\
            ";

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
    WrapClass_parampanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_parampanel>(object));
    if (obj.get()) {
      parent = obj->_parampanel->GetBookCtrl();
    }
  }

  ParamPanel::ptr pp;
  pp = ParamPanel::ptr(
    new ParamPanel(
      parent,
      (*title).c_str()),
      wxwindow_nodeleter<ParamPanel>() // deletion will be done by wxwidgets
    );

  WrapClass_parampanel::ptr wpp(new WrapClass_parampanel());
  wpp->_parampanel = pp;


  AMIObject::ptr amiobject (AddWrapParamPanel(wpp));

  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>("tmp_parampanel",  amiobject));

  return varres;

}
/*
  Variable<AMIObject>::ptr var;
  int   n = 0;

  if (!get_val_ptr_param<string>( title,  p, n)) ClassHelpAndReturn;

  int var_id;

  if (!get_var_param<AMIObject>(var, p, n)) 
    var_id = this->_objectptr->_parampanel->AddPage( title->c_str());
  else
  {
    // how to : 1. check the object type 2. get the object pointer
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_parampanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_parampanel>(object));
    if (obj.get()) {
      var_id = this->_objectptr->_parampanel->AddPage(obj->_parampanel.get(), 
                                                      title->c_str());
      this->_objectptr->_parampanel->Fit();
      obj->_parampanel->Show();
    } else
    {
      CLASS_ERROR("Could not cast dynamically the parameter ..., check its type");
      ClassHelpAndReturn;
    }
  }
*/

//---------------------------------------------------
//  BeginBook
//---------------------------------------------------
void WrapClass_parampanel::wrap_BeginBook::SetParametersComments() 
{
  return_comments = "Identifier of the new book (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_BeginBook::CallMember( ParamList* p)
{
  int id = this->_objectptr->_parampanel->BeginBook();

  // create integer variable to return
  string name = (boost::format("book_%1%")%id).str();
  RETURN_VARINT(id,name.c_str());
}


//---------------------------------------------------
//  EndBook
//---------------------------------------------------
void WrapClass_parampanel::wrap_EndBook::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_EndBook::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->EndBook();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginHorizontal
//---------------------------------------------------
void WrapClass_parampanel::wrap_BeginHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_BeginHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->BeginHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  EndHorizontal
//---------------------------------------------------
void WrapClass_parampanel::wrap_EndHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_EndHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->EndHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginBoxPanel
//---------------------------------------------------
void WrapClass_parampanel::wrap_BeginBoxPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: box panel title.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_BeginBoxPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  this->_objectptr->_parampanel->BeginBox( label->c_str());
  int id = this->_objectptr->_parampanel->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndBoxPanel
//---------------------------------------------------
void WrapClass_parampanel::wrap_EndBoxPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_EndBoxPanel::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->EndPanel();
  this->_objectptr->_parampanel->EndBox( );
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginPanel
//---------------------------------------------------
void WrapClass_parampanel::wrap_BeginPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: panel title.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_BeginPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  int id = this->_objectptr->_parampanel->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndPanel
//---------------------------------------------------
void WrapClass_parampanel::wrap_EndPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_EndPanel::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->EndPanel();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  AddFloat
//---------------------------------------------------
void WrapClass_parampanel::wrap_AddFloat::SetParametersComments()
{
  ADDPARAMCOMMENT("float variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:1)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddFloat::CallMember( ParamList* p)
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

  int var_id = this->_objectptr->_parampanel->AddFloat( varval.get(), label->c_str(),2,tooltip);
  this->_objectptr->_parampanel->FloatConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}

//--------------------------------------------------
// AddInt
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddInt::SetParametersComments()
{
  ADDPARAMCOMMENT("int   : input variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:100)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddInt::CallMember( ParamList* p)
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
  int var_id = this->_objectptr->_parampanel->AddInteger( varval, label->c_str(), tooltip);
  this->_objectptr->_parampanel->IntegerConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddEnum
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddEnum::SetParametersComments()
{
  ADDPARAMCOMMENT("int var: input variable");
  ADDPARAMCOMMENT("string label (def: variable name)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddEnum::CallMember( ParamList* p)
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
  this->_objectptr->_parampanel->AddEnumeration(  
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
void WrapClass_parampanel::wrap_AddEnumChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("expression: identificator of the enumeration parameter.");
  ADDPARAMCOMMENT("string expression: text associated to this choice.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddEnumChoice::CallMember( ParamList* p)
{
  int id;
  std::string* label = NULL;
  int  n = 0;
  int var_id;

  if (!get_int_param(id, p, n))                 ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;

  this->_objectptr->_parampanel->AddEnumChoice( id, &var_id, label->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label->c_str())
}


//--------------------------------------------------
//  Display
//--------------------------------------------------
void WrapClass_parampanel::wrap_Display::SetParametersComments() {
  ADDPARAMCOMMENT("Another parampanel object to display within other parameters (default: main notebook).");
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_Display::CallMember( ParamList* p)
{
  Variable<AMIObject>::ptr var;

  int  n = 0;

  if (!get_var_param<AMIObject>(var, p, n)) 
  {
    GB_main_wxFrame->AddParamPanelPage( this->_objectptr->_parampanel,
        this->_objectptr->_parampanel->GetName(),
        true // select as current page
        );
  } else
  {
    // how to : 1. check the object type 2. get the object pointer
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_parampanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_parampanel>(object));
    if (obj.get()) {
      obj->_parampanel->AddPage(this->_objectptr->_parampanel.get(), this->_objectptr->_parampanel->GetName().mb_str());
    } else
    {
      CLASS_ERROR("Could not cast dynamically the parameter ..., check its type");
      ClassHelpAndReturn;
    }
  }
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  HidePanel
//--------------------------------------------------
void WrapClass_parampanel::wrap_HidePanel::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_HidePanel::CallMember( ParamList* p)
{
  GB_main_wxFrame->RemoveParamPanelPage(this->_objectptr->_parampanel);
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  ShowPanel
//--------------------------------------------------
void WrapClass_parampanel::wrap_ShowPanel::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_ShowPanel::CallMember( ParamList* p)
{
  this->_objectptr->_parampanel->AfficheDialogue();
  return BasicVariable::ptr();
}


//--------------------------------------------------
// Update 
//--------------------------------------------------
void WrapClass_parampanel::wrap_Update::SetParametersComments()
{
  ADDPARAMCOMMENT( "int (default:-1): parameter to update, -1 for all the parameters.");
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_Update::CallMember( ParamList* p)
{
  int paramnumber = -1;
  int   n = 0;
  if (!get_int_param( paramnumber, p, n)) ClassHelpAndReturn;

  this->_objectptr->_parampanel->MAJ();
  if (paramnumber==-1) {
    GB_main_wxFrame->GetAuiManager().Update();
  } else {
    this->_objectptr->_parampanel->UpdateParameter(paramnumber);
  }
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  AddPage
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "string: page title.");
  ADDPARAMCOMMENT(" Another parampanel object (optional).");
  return_comments = "Identifier of the new widget (int variable).";
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddPage::CallMember( ParamList* p)
{
  std::string* title = NULL;
  Variable<AMIObject>::ptr var;
  int   n = 0;

  if (!get_val_ptr_param<string>( title,  p, n)) ClassHelpAndReturn;

  int var_id;

  if (!get_var_param<AMIObject>(var, p, n)) 
    var_id = this->_objectptr->_parampanel->AddPage( title->c_str());
  else
  {
    // how to : 1. check the object type 2. get the object pointer
    WrapClassBase::ptr object( var->Pointer()->GetWrappedObject());
    WrapClass_parampanel::ptr obj( boost::dynamic_pointer_cast<WrapClass_parampanel>(object));
    if (obj.get()) {
      var_id = this->_objectptr->_parampanel->AddPage(obj->_parampanel.get(), 
                                                      title->c_str());
      this->_objectptr->_parampanel->Fit();
      obj->_parampanel->Show();
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
void WrapClass_parampanel::wrap_SelectPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "integer: book id.");
  ADDPARAMCOMMENT( "integer: page to select.");
}
//--------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_SelectPage::CallMember( ParamList* p)
{
  int book_id;
  int page_id;
  int   n = 0;

  if (!get_int_param( book_id,  p, n)) ClassHelpAndReturn;
  if (!get_int_param( page_id,  p, n)) ClassHelpAndReturn;

  this->_objectptr->_parampanel->SelectPage(book_id,page_id);
}


//--------------------------------------------------
// AddLabel
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddLabel::SetParametersComments()
{
  ADDPARAMCOMMENT("string expression: label name");
  ADDPARAMCOMMENT("string expression: label value");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddLabel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  std::string* label_name = NULL;
  std::string* label_val = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label_name, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label_val, p, n)) ClassHelpAndReturn;

  this->_objectptr->_parampanel->AddLabel( &var_id,
                label_name->c_str(),
                label_val->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label_name->c_str());
}



//--------------------------------------------------
// AddFilename
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddFilename::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  ADDPARAMCOMMENT("default path");
  ADDPARAMCOMMENT("default mask");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddFilename::CallMember( ParamList* p)
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
  this->_objectptr->_parampanel->AjouteNomFichier( &var_id, 
                                      val_ptr,
                                      label->c_str(),
                                      tooltip);
  this->_objectptr->_parampanel->ContraintesNomFichier(var_id,
                            defpath->c_str(),
                            (char*)"",
                            defmask->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddString
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddString::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddString::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  this->_objectptr->_parampanel->AjouteChaine( &var_id,
                                  var->Pointer(),
                                  label->c_str(),
                                  tooltip);
  this->_objectptr->_parampanel->ContraintesChaine(var_id, (char*) var->Pointer()->c_str());


  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddImageChoice
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddImageChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("string variable that will contain the name of the selected image");
  ADDPARAMCOMMENT("string label: description of the image to select");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddImageChoice::CallMember( ParamList* p)
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
  imagelist->Add(_T("Image"));

  // Get list of image names
  this->_objectptr->_parampanel->AddListChoice( &var_id,
      var->Pointer(),
      label->c_str(), // TODO: check param type
      imagelist,
      (void*)CB_update_imagelist, // TODO: check declaration
      EnumOptionMenu,
      tooltip);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddBoolean
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddBoolean::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type UCHAR.");
  ADDPARAMCOMMENT("String expression: label (def: variable name).");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddBoolean::CallMember( ParamList* p)
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

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << endl;
  this->_objectptr->_parampanel->AddBoolean( &var_id,
                valptr,
                label_val.c_str(),
                CaractereToggle,
                tooltip);
  this->_objectptr->_parampanel->BooleanDefault( var_id, *valptr);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}



//--------------------------------------------------
// AddButton
//--------------------------------------------------
void WrapClass_parampanel::wrap_AddButton::SetParametersComments()
{
  ADDPARAMCOMMENT("String: button label.");
  ADDPARAMCOMMENT("Variable of type ami_function.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_AddButton::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;
  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << endl;
  this->_objectptr->_parampanel->AddButton( &var_id, 
                label->c_str(),
                (void*) CB_ParamWin,
                (void*) var->Pointer().get(),
                tooltip);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// SetCallback
//--------------------------------------------------
void WrapClass_parampanel::wrap_SetCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type ami_function.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_SetCallback::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  int  n = 0;

  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  int nbp = this->_objectptr->_parampanel->NbParameters();

  this->_objectptr->_parampanel->ChangedValueCallback(nbp-1,
              (void*) CB_ParamWin,
              (void*) var->Pointer().get() );

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetDragCallback
//--------------------------------------------------
void WrapClass_parampanel::wrap_SetDragCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the parameter for which to set the drag callback.");
  ADDPARAMCOMMENT("Boolean value: activate or desactivate the drag callbacks (def:true).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_SetDragCallback::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int paramid = 0;
  int activate = 1;
  int  n = 0;

  if (!get_int_param(paramid, p, n))     ClassHelpAndReturn;
  if (!get_int_param(activate, p, n))    ClassHelpAndReturn;

  int nbp = this->_objectptr->_parampanel->NbParameters();

  if ((paramid>=0)&&(paramid<n))
    this->_objectptr->_parampanel->SetDragCallback(paramid,activate);
  else
    FILE_ERROR(boost::format("bad parameter number %1%") % paramid);

  return BasicVariable::ptr();
}


//--------------------------------------------------
// EnablePanel
//--------------------------------------------------
void WrapClass_parampanel::wrap_EnablePanel::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the panel.");
  ADDPARAMCOMMENT("Value enable:1 disable:0.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_EnablePanel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int id;
  int enable=1;
  int  n = 0;

  if (!get_int_param(id, p, n))          ClassHelpAndReturn;
  if (!get_int_param(enable, p, n))      ClassHelpAndReturn;

  int nbp = this->_objectptr->_parampanel->NbPanels();
  if ((id>=0)&&(id<nbp))
    this->_objectptr->_parampanel->EnablePanel(id,enable);
  else
    FILE_ERROR(boost::format(" bad parameter number %1% ")%id);

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetPositionProp
//--------------------------------------------------
void WrapClass_parampanel::wrap_SetPositionProp::SetParametersComments()
{
  ADDPARAMCOMMENT("proportion property (0: not proportional, \
                               1: standard proportion,\
                               -1: keeps previous value)");
  ADDPARAMCOMMENT("border size ( def:-1 keeps previous value)");
  ADDPARAMCOMMENT("flags       ( -1 keeps previous value)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_SetPositionProp::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  prop_property = -1;
  int  border_size = -1;
  int  flags = -1;
  int  n = 0;

  if (!get_int_param(prop_property, p, n)) ClassHelpAndReturn;
  if (!get_int_param(border_size,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(flags,         p, n)) ClassHelpAndReturn;

  int nbp = this->_objectptr->_parampanel->NbPanels();
  this->_objectptr->_parampanel->SetPositionProperties(
              nbp-1, 
              prop_property, 
              border_size,
              flags);

  return BasicVariable::ptr();
}

//--------------------------------------------------
// ShowSlider
//--------------------------------------------------
void WrapClass_parampanel::wrap_ShowSlider::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for show/hide.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_ShowSlider::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  show = 1;
  int  n = 0;

  if (!get_int_param(id,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(show, p, n)) ClassHelpAndReturn;

  this->_objectptr->_parampanel->ParamShowSlider(id,show );

  return BasicVariable::ptr();
}

//--------------------------------------------------
// Enable
//--------------------------------------------------
void WrapClass_parampanel::wrap_Enable::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for enable/disable.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_parampanel::wrap_Enable::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  enable = 1;
  int  n = 0;

  if (!get_int_param(id,     p, n)) ClassHelpAndReturn;
  if (!get_int_param(enable, p, n)) ClassHelpAndReturn;

  int nb = this->_objectptr->_parampanel->NbParameters();

  if ((id>=0)&&(id<nb))
    this->_objectptr->_parampanel->Enable(id,enable);
  else
    FILE_ERROR(boost::format(" %d  \t bad parameter number ")%id);

  return BasicVariable::ptr();
}
