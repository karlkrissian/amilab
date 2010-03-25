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

extern VarContexts  Vars;

void CB_ParamWin( void* cd );
void CB_update_imagelist( void* imagelist_gui);

AMIObject* AddWrapParamPanel( const ParamPanel::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("parampanel");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDMEMBER("BeginBook",       ParamPanel,BeginBook);
  ADDMEMBER("EndBook",         ParamPanel,EndBook);

  ADDMEMBER("BeginHorizontal", ParamPanel,BeginHorizontal);
  ADDMEMBER("EndHorizontal",   ParamPanel,EndHorizontal);

  ADDMEMBER("BeginBoxPanel",   ParamPanel,BeginBoxPanel);
  ADDMEMBER("EndBoxPanel",     ParamPanel,EndBoxPanel);

  ADDMEMBER("BeginPanel",      ParamPanel,BeginPanel);
  ADDMEMBER("EndPanel",        ParamPanel,EndPanel);

  ADDMEMBER("AddPage",         ParamPanel,AddPage);
  ADDMEMBER("SelectPage",      ParamPanel,SelectPage);

  ADDMEMBER("AddFloat",        ParamPanel,AddFloat);
  ADDMEMBER("AddInt",          ParamPanel,AddInt);
  ADDMEMBER("AddEnum",         ParamPanel,AddEnum);
  ADDMEMBER("AddEnumChoice",   ParamPanel,AddEnumChoice);
  ADDMEMBER("AddLabel",        ParamPanel,AddLabel);
  ADDMEMBER("AddFilename",     ParamPanel,AddFilename);
  ADDMEMBER("AddString",       ParamPanel,AddString);
  ADDMEMBER("AddImageChoice",  ParamPanel,AddImageChoice);
  ADDMEMBER("AddButton",       ParamPanel,AddButton);
  ADDMEMBER("AddBoolean",      ParamPanel,AddBoolean);
  ADDMEMBER("SetCallback",     ParamPanel,SetCallback);
  ADDMEMBER("SetDragCallback", ParamPanel,SetDragCallback);
  ADDMEMBER("EnablePanel",     ParamPanel,EnablePanel);

  ADDMEMBER("Display",         ParamPanel,Display);
  ADDMEMBER("HidePanel",       ParamPanel,HidePanel);
  ADDMEMBER("Update",          ParamPanel,Update);

  ADDMEMBER("SetPositionProp", ParamPanel,SetPositionProp);
  ADDMEMBER("ShowSlider",      ParamPanel,ShowSlider);
  ADDMEMBER("Enable",          ParamPanel,Enable);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

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
            ";

  int n = 0;
  std::string* title = NULL;

  if (!get_val_ptr_param<string>(    title, p, n)) HelpAndReturnVarPtr;

  ParamPanel::ptr pp;

  pp = ParamPanel::ptr(
    new ParamPanel(
      GB_main_wxFrame,
      (*title).c_str()),
      wxwindow_nodeleter<ParamPanel>() // deletion will be done by wxwidgets
    );

  AMIObject::ptr amiobject (AddWrapParamPanel(pp));

  Variable<AMIObject>::ptr varres(
    new Variable<AMIObject>("tmp_parampanel",  amiobject));

  return varres;

}


//---------------------------------------------------
//  BeginBook
//---------------------------------------------------
void wrap_ParamPanelBeginBook::SetParametersComments() 
{
  return_comments = "Identifier of the new book (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelBeginBook::CallMember( ParamList* p)
{
  int id = this->_objectptr->BeginBook();

  // create integer variable to return
  string name = (boost::format("book_%1%")%id).str();
  RETURN_VARINT(id,name.c_str());
}


//---------------------------------------------------
//  EndBook
//---------------------------------------------------
void wrap_ParamPanelEndBook::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEndBook::CallMember( ParamList* p)
{
  this->_objectptr->EndBook();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginHorizontal
//---------------------------------------------------
void wrap_ParamPanelBeginHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelBeginHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->BeginHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  EndHorizontal
//---------------------------------------------------
void wrap_ParamPanelEndHorizontal::SetParametersComments() {}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEndHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->EndHorizontal();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginBoxPanel
//---------------------------------------------------
void wrap_ParamPanelBeginBoxPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: box panel title.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelBeginBoxPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  this->_objectptr->BeginBox( label->c_str());
  int id = this->_objectptr->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndBoxPanel
//---------------------------------------------------
void wrap_ParamPanelEndBoxPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEndBoxPanel::CallMember( ParamList* p)
{
  this->_objectptr->EndPanel();
  this->_objectptr->EndBox( );
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  BeginPanel
//---------------------------------------------------
void wrap_ParamPanelBeginPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: panel title.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelBeginPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  int id = this->_objectptr->BeginPanel( label->c_str());

  // create integer variable to return
  RETURN_VARINT(id,label->c_str());
}


//---------------------------------------------------
//  EndPanel
//---------------------------------------------------
void wrap_ParamPanelEndPanel::SetParametersComments(){}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEndPanel::CallMember( ParamList* p)
{
  this->_objectptr->EndPanel();
  return BasicVariable::ptr();
}


//---------------------------------------------------
//  AddFloat
//---------------------------------------------------
void wrap_ParamPanelAddFloat::SetParametersComments()
{
  ADDPARAMCOMMENT("float variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:1)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddFloat::CallMember( ParamList* p)
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

  int var_id = this->_objectptr->AddFloat( varval.get(), label->c_str(),2,tooltip);
  this->_objectptr->FloatConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}

//--------------------------------------------------
// AddInt
//--------------------------------------------------
void wrap_ParamPanelAddInt::SetParametersComments()
{
  ADDPARAMCOMMENT("int   : input variable");
  ADDPARAMCOMMENT("string: label for the parameter");
  ADDPARAMCOMMENT("minimum value (def:0)");
  ADDPARAMCOMMENT("maximum value (def:100)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddInt::CallMember( ParamList* p)
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
  int var_id = this->_objectptr->AddInteger( varval, label->c_str(), tooltip);
  this->_objectptr->IntegerConstraints( var_id, minval, maxval, *varval );

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddEnum
//--------------------------------------------------
void wrap_ParamPanelAddEnum::SetParametersComments()
{
  ADDPARAMCOMMENT("int var: input variable");
  ADDPARAMCOMMENT("string label (def: variable name)");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddEnum::CallMember( ParamList* p)
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
  this->_objectptr->AddEnumeration(  
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
void wrap_ParamPanelAddEnumChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("expression: identificator of the enumeration parameter.");
  ADDPARAMCOMMENT("string expression: text associated to this choice.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddEnumChoice::CallMember( ParamList* p)
{
  int id;
  std::string* label = NULL;
  int  n = 0;
  int var_id;

  if (!get_int_param(id, p, n))                 ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;

  this->_objectptr->AddEnumChoice( id, &var_id, label->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label->c_str())
}


//--------------------------------------------------
//  Display
//--------------------------------------------------
void wrap_ParamPanelDisplay::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr wrap_ParamPanelDisplay::CallMember( ParamList* p)
{
  GB_main_wxFrame->AddParamPanelPage( this->_objectptr,
      this->_objectptr->GetName(),
      true // select as current page
      );
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  HidePanel
//--------------------------------------------------
void wrap_ParamPanelHidePanel::SetParametersComments() {}
//--------------------------------------------------
BasicVariable::ptr wrap_ParamPanelHidePanel::CallMember( ParamList* p)
{
  GB_main_wxFrame->RemoveParamPanelPage(this->_objectptr);
  return BasicVariable::ptr();
}

//--------------------------------------------------
// Update 
//--------------------------------------------------
void wrap_ParamPanelUpdate::SetParametersComments()
{
  ADDPARAMCOMMENT( "int (default:-1): parameter to update, -1 for all the parameters.");
}
//--------------------------------------------------
BasicVariable::ptr wrap_ParamPanelUpdate::CallMember( ParamList* p)
{
  int paramnumber = -1;
  int   n = 0;
  if (!get_int_param( paramnumber, p, n)) ClassHelpAndReturn;

  this->_objectptr->MAJ();
  if (paramnumber==-1) {
    GB_main_wxFrame->GetAuiManager().Update();
  } else {
    this->_objectptr->UpdateParameter(paramnumber);
  }
  return BasicVariable::ptr();
}

//--------------------------------------------------
//  AddPage
//--------------------------------------------------
void wrap_ParamPanelAddPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "string: page title.");
  return_comments = "Identifier of the new widget (int variable).";
}
//--------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddPage::CallMember( ParamList* p)
{
  std::string* title = NULL;
  int   n = 0;

  if (!get_val_ptr_param<string>( title,  p, n)) ClassHelpAndReturn;
  int var_id = this->_objectptr->AddPage( title->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,title->c_str())
}


//--------------------------------------------------
//  SelectPage
//--------------------------------------------------
void wrap_ParamPanelSelectPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "integer: book id.");
  ADDPARAMCOMMENT( "integer: page to select.");
}
//--------------------------------------------------
BasicVariable::ptr wrap_ParamPanelSelectPage::CallMember( ParamList* p)
{
  int book_id;
  int page_id;
  int   n = 0;

  if (!get_int_param( book_id,  p, n)) ClassHelpAndReturn;
  if (!get_int_param( page_id,  p, n)) ClassHelpAndReturn;

  this->_objectptr->SelectPage(book_id,page_id);
}


//--------------------------------------------------
// AddLabel
//--------------------------------------------------
void wrap_ParamPanelAddLabel::SetParametersComments()
{
  ADDPARAMCOMMENT("string expression: label name");
  ADDPARAMCOMMENT("string expression: label value");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddLabel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  std::string* label_name = NULL;
  std::string* label_val = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label_name, p, n)) ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label_val, p, n)) ClassHelpAndReturn;

  this->_objectptr->AddLabel( &var_id,
                label_name->c_str(),
                label_val->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,label_name->c_str());
}



//--------------------------------------------------
// AddFilename
//--------------------------------------------------
void wrap_ParamPanelAddFilename::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  ADDPARAMCOMMENT("default path");
  ADDPARAMCOMMENT("default mask");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddFilename::CallMember( ParamList* p)
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
  this->_objectptr->AjouteNomFichier( &var_id, 
                                      val_ptr,
                                      label->c_str(),
                                      tooltip);
  this->_objectptr->ContraintesNomFichier(var_id,
                            defpath->c_str(),
                            (char*)"",
                            defmask->c_str());

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddString
//--------------------------------------------------
void wrap_ParamPanelAddString::SetParametersComments()
{
  ADDPARAMCOMMENT("String variable to interface");
  ADDPARAMCOMMENT("string label");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddString::CallMember( ParamList* p)
{
  Variable<string>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<string>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  this->_objectptr->AjouteChaine( &var_id,
                                  var->Pointer(),
                                  label->c_str(),
                                  tooltip);
  this->_objectptr->ContraintesChaine(var_id, (char*) var->Pointer()->c_str());


  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}


//--------------------------------------------------
// AddImageChoice
//--------------------------------------------------
void wrap_ParamPanelAddImageChoice::SetParametersComments()
{
  ADDPARAMCOMMENT("string variable that will contain the name of the selected image");
  ADDPARAMCOMMENT("string label: description of the image to select");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddImageChoice::CallMember( ParamList* p)
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
  this->_objectptr->AddListChoice( &var_id,
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
void wrap_ParamPanelAddBoolean::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type UCHAR.");
  ADDPARAMCOMMENT("String expression: label (def: variable name).");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddBoolean::CallMember( ParamList* p)
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
  this->_objectptr->AddBoolean( &var_id,
                valptr,
                label_val.c_str(),
                CaractereToggle,
                tooltip);
  this->_objectptr->BooleanDefault( var_id, *valptr);

  // create integer variable to return
  RETURN_VARINT(var_id,var->Name());
}



//--------------------------------------------------
// AddButton
//--------------------------------------------------
void wrap_ParamPanelAddButton::SetParametersComments()
{
  ADDPARAMCOMMENT("String: button label.");
  ADDPARAMCOMMENT("Variable of type ami_function.");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelAddButton::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_val_ptr_param<string>( label, p, n))   ClassHelpAndReturn;
  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();

  //cout << " button pointer  = "<<  ((AMIFunction::ptr*) var->Pointer())->get() << endl;
  this->_objectptr->AddButton( &var_id, 
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
void wrap_ParamPanelSetCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Variable of type ami_function.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelSetCallback::CallMember( ParamList* p)
{
  Variable<AMIFunction>::ptr var;
  int  n = 0;

  if (!get_var_param<AMIFunction>(var, p, n))     ClassHelpAndReturn;

  int nbp = this->_objectptr->NbParameters();

  this->_objectptr->ChangedValueCallback(nbp-1,
              (void*) CB_ParamWin,
              (void*) var->Pointer().get() );

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetDragCallback
//--------------------------------------------------
void wrap_ParamPanelSetDragCallback::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the parameter for which to set the drag callback.");
  ADDPARAMCOMMENT("Boolean value: activate or desactivate the drag callbacks (def:true).");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelSetDragCallback::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int paramid = 0;
  int activate = 1;
  int  n = 0;

  if (!get_int_param(paramid, p, n))     ClassHelpAndReturn;
  if (!get_int_param(activate, p, n))    ClassHelpAndReturn;

  int nbp = this->_objectptr->NbParameters();

  if ((paramid>=0)&&(paramid<n))
    this->_objectptr->SetDragCallback(paramid,activate);
  else
    FILE_ERROR(boost::format("bad parameter number %1%") % paramid);

  return BasicVariable::ptr();
}


//--------------------------------------------------
// EnablePanel
//--------------------------------------------------
void wrap_ParamPanelEnablePanel::SetParametersComments()
{
  ADDPARAMCOMMENT("Index of the panel.");
  ADDPARAMCOMMENT("Value enable:1 disable:0.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEnablePanel::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int id;
  int enable=1;
  int  n = 0;

  if (!get_int_param(id, p, n))          ClassHelpAndReturn;
  if (!get_int_param(enable, p, n))      ClassHelpAndReturn;

  int nbp = this->_objectptr->NbPanels();
  if ((id>=0)&&(id<nbp))
    this->_objectptr->EnablePanel(id,enable);
  else
    FILE_ERROR(boost::format(" bad parameter number %1% ")%id);

  return BasicVariable::ptr();
}


//--------------------------------------------------
// SetPositionProp
//--------------------------------------------------
void wrap_ParamPanelSetPositionProp::SetParametersComments()
{
  ADDPARAMCOMMENT("proportion property (0: not proportional, \
                               1: standard proportion,\
                               -1: keeps previous value)");
  ADDPARAMCOMMENT("border size ( def:-1 keeps previous value)");
  ADDPARAMCOMMENT("flags       ( -1 keeps previous value)");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelSetPositionProp::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  prop_property = -1;
  int  border_size = -1;
  int  flags = -1;
  int  n = 0;

  if (!get_int_param(prop_property, p, n)) ClassHelpAndReturn;
  if (!get_int_param(border_size,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(flags,         p, n)) ClassHelpAndReturn;

  int nbp = this->_objectptr->NbPanels();
  this->_objectptr->SetPositionProperties(
              nbp-1, 
              prop_property, 
              border_size,
              flags);

  return BasicVariable::ptr();
}

//--------------------------------------------------
// ShowSlider
//--------------------------------------------------
void wrap_ParamPanelShowSlider::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for show/hide.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelShowSlider::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  show = 1;
  int  n = 0;

  if (!get_int_param(id,   p, n)) ClassHelpAndReturn;
  if (!get_int_param(show, p, n)) ClassHelpAndReturn;

  this->_objectptr->ParamShowSlider(id,show );

  return BasicVariable::ptr();
}

//--------------------------------------------------
// Enable
//--------------------------------------------------
void wrap_ParamPanelEnable::SetParametersComments()
{
  ADDPARAMCOMMENT("Parameter id.");
  ADDPARAMCOMMENT("Boolean: 1/0 for enable/disable.");
}
//---------------------------------------------------
BasicVariable::ptr wrap_ParamPanelEnable::CallMember( ParamList* p)
{
  BasicVariable::ptr var;
  int  id;
  int  enable = 1;
  int  n = 0;

  if (!get_int_param(id,     p, n)) ClassHelpAndReturn;
  if (!get_int_param(enable, p, n)) ClassHelpAndReturn;

  int nb = this->_objectptr->NbParameters();

  if ((id>=0)&&(id<nb))
    this->_objectptr->Enable(id,enable);
  else
    FILE_ERROR(boost::format(" %d  \t bad parameter number ")%id);

  return BasicVariable::ptr();
}
