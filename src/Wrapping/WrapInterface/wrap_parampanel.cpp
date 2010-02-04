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


extern MainFrame*     GB_main_wxFrame;

extern VarContexts  Vars;

void CB_ParamWin( void* cd );

AMIObject* AddWrapParamPanel( const ParamPanel::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("parampanel");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

  ADDMEMBER("_BeginBook",       ParamPanel,BeginBook);
  ADDMEMBER("_EndBook",         ParamPanel,EndBook);

  ADDMEMBER("_BeginHorizontal", ParamPanel,BeginHorizontal);
  ADDMEMBER("_EndHorizontal",   ParamPanel,EndHorizontal);

  ADDMEMBER("_BeginBoxPanel",   ParamPanel,BeginBoxPanel);
  ADDMEMBER("_EndBoxPanel",     ParamPanel,EndBoxPanel);

  ADDMEMBER("_AddPage",         ParamPanel,AddPage);

  ADDMEMBER("_AddFloat",        ParamPanel,AddFloat);
  ADDMEMBER("_AddInt",          ParamPanel,AddInt);
  ADDMEMBER("_AddEnum",         ParamPanel,AddEnum);
  ADDMEMBER("_AddEnumChoice",   ParamPanel,AddEnumChoice);
  ADDMEMBER("_AddFilename",     ParamPanel,AddFilename);
  ADDMEMBER("_AddButton",       ParamPanel,AddButton);

  ADDMEMBER("_Display",         ParamPanel,Display);
  ADDMEMBER("_Hide",            ParamPanel,Hide);
  ADDMEMBER("_Update",          ParamPanel,Update);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  return amiobject;
}

//---------------------------------------------------
Variable::ptr wrap_ParamPanel( ParamList* p)
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

  AMIObject* amiobject = AddWrapParamPanel(pp);

  Variable::ptr varres(new Variable());

  varres->Init(type_ami_object,"tmp_parampanel", (void*) amiobject);

  return varres;

}


//---------------------------------------------------
//  BeginBook
//---------------------------------------------------
void wrap_ParamPanelBeginBook::SetParametersComments() {}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelBeginBook::CallMember( ParamList* p)
{
  this->_objectptr->BeginBook();
  return Variable::ptr();
}


//---------------------------------------------------
//  EndBook
//---------------------------------------------------
void wrap_ParamPanelEndBook::SetParametersComments() {}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelEndBook::CallMember( ParamList* p)
{
  this->_objectptr->EndBook();
  return Variable::ptr();
}


//---------------------------------------------------
//  BeginHorizontal
//---------------------------------------------------
void wrap_ParamPanelBeginHorizontal::SetParametersComments() {}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelBeginHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->BeginHorizontal();
  return Variable::ptr();
}


//---------------------------------------------------
//  EndHorizontal
//---------------------------------------------------
void wrap_ParamPanelEndHorizontal::SetParametersComments() {}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelEndHorizontal::CallMember( ParamList* p)
{
  this->_objectptr->EndHorizontal();
  return Variable::ptr();
}


//---------------------------------------------------
//  BeginBoxPanel
//---------------------------------------------------
void wrap_ParamPanelBeginBoxPanel::SetParametersComments()
{
  ADDPARAMCOMMENT("string: box panel title.");
}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelBeginBoxPanel::CallMember( ParamList* p)
{
  std::string* label = NULL;
  int n = 0;
  if (!get_val_ptr_param<string>( label,  p, n)) 
    ClassHelpAndReturn;

  this->_objectptr->BeginBox( label->c_str());
  int id = this->_objectptr->BeginPanel( label->c_str());
  return Variable::ptr();
  //    $$=id;
}


//---------------------------------------------------
//  EndBoxPanel
//---------------------------------------------------
void wrap_ParamPanelEndBoxPanel::SetParametersComments(){}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelEndBoxPanel::CallMember( ParamList* p)
{
  this->_objectptr->EndPanel();
  this->_objectptr->EndBox( );
  return Variable::ptr();
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
}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelAddFloat::CallMember( ParamList* p)
{
  Variable::ptr var;
  float* varval;
  std::string* label = NULL;
  float minval = 0;
  float maxval = 1;
  int   n = 0;

  if (!get_var_param<float>(var, p, n))         ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;
  if (!get_val_param<float>( minval, p, n))     ClassHelpAndReturn;
  if (!get_val_param<float>( maxval, p, n))     ClassHelpAndReturn;

  varval = ((boost::shared_ptr<float>*) var->Pointer())->get();
  // Setting comments
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  int var_id = this->_objectptr->AddFloat( varval, label->c_str(),2,tooltip);

  this->_objectptr->FloatConstraints( var_id, minval, maxval, *varval );
  return Variable::ptr();
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
}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelAddInt::CallMember( ParamList* p)
{
  Variable::ptr var;
  int* varval;
  std::string* label = NULL;
  int  minval = 0;
  int  maxval = 100;
  int  n = 0;

  if (!get_var_param<int>(var, p, n))          ClassHelpAndReturn;
  if (!get_val_ptr_param<string>(label, p, n)) ClassHelpAndReturn;
  if (!get_int_param(minval, p, n))            ClassHelpAndReturn;
  if (!get_int_param(maxval, p, n))            ClassHelpAndReturn;

  varval = ((boost::shared_ptr<int>*) var->Pointer())->get();
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  int var_id = this->_objectptr->AddInteger( varval, label->c_str(), tooltip);
  this->_objectptr->IntegerConstraints( var_id, minval, maxval, *varval );
  return Variable::ptr();
  //    $$ = var_id;
}


//--------------------------------------------------
// AddEnum
//--------------------------------------------------
void wrap_ParamPanelAddEnum::SetParametersComments()
{
  ADDPARAMCOMMENT("int var: input variable");
  ADDPARAMCOMMENT("string label");
  return_comments = "Identifier of the new widget (int variable).";
}
//---------------------------------------------------
Variable::ptr wrap_ParamPanelAddEnum::CallMember( ParamList* p)
{
  Variable::ptr var;
  int* varval;
  std::string* label = NULL;
  int  n = 0;
  int  var_id;

  if (!get_var_param<int>(var, p, n))           ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;

  varval = ((boost::shared_ptr<int>*) var->Pointer())->get();
  std::string tooltip = (boost::format("%s  (%s)") % var->GetComments() % var->Name()).str();
  this->_objectptr->AddEnumeration(  
                        &var_id,
                        varval,
                        label->c_str(),
                        EnumOptionMenu,
                        tooltip);
  //pw->EnumerationDefaut( var_id,  *var);

  // create integer variable to return
  Variable::ptr varres(new Variable());
  std::string varname = (boost::format("%1%_id")%var->Name()).str();
  int* varint = new int(var_id);
  varres->Init(type_int,varname.c_str(),(void*) varint);

  return varres;
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
Variable::ptr wrap_ParamPanelAddEnumChoice::CallMember( ParamList* p)
{
  int id;
  std::string* label = NULL;
  int  n = 0;
  int var_id;

  if (!get_int_param(id, p, n))                 ClassHelpAndReturn;
  if (!get_val_ptr_param<string>( label, p, n)) ClassHelpAndReturn;

  this->_objectptr->AddEnumChoice( id, &var_id, label->c_str());

  // create integer variable to return
  Variable::ptr varres(new Variable());
  std::string varname = (boost::format("%1%_id")%label->c_str()).str();
  int* varint = new int(var_id);
  varres->Init(type_int,varname.c_str(),(void*) varint);

  return varres;
}


//--------------------------------------------------
//  Display
//--------------------------------------------------
void wrap_ParamPanelDisplay::SetParametersComments() {}
//--------------------------------------------------
Variable::ptr wrap_ParamPanelDisplay::CallMember( ParamList* p)
{
  GB_main_wxFrame->AddParamPanelPage( this->_objectptr,
      this->_objectptr->GetName(),
      true // select as current page
      );
  return Variable::ptr();
}

//--------------------------------------------------
//  Hide
//--------------------------------------------------
void wrap_ParamPanelHide::SetParametersComments() {}
//--------------------------------------------------
Variable::ptr wrap_ParamPanelHide::CallMember( ParamList* p)
{
  GB_main_wxFrame->RemoveParamPanelPage(this->_objectptr);
  return Variable::ptr();
}

//--------------------------------------------------
// Update 
//--------------------------------------------------
void wrap_ParamPanelUpdate::SetParametersComments()
{
  ADDPARAMCOMMENT( "int (default:-1): parameter to update, -1 for all the parameters.");
}
//--------------------------------------------------
Variable::ptr wrap_ParamPanelUpdate::CallMember( ParamList* p)
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
  return Variable::ptr();
}

//--------------------------------------------------
//  AddPage
//--------------------------------------------------
void wrap_ParamPanelAddPage::SetParametersComments()
{
  ADDPARAMCOMMENT( "string: page title.");
}
//--------------------------------------------------
Variable::ptr wrap_ParamPanelAddPage::CallMember( ParamList* p)
{
  std::string* title = NULL;
  int   n = 0;

  if (!get_val_ptr_param<string>( title,  p, n)) ClassHelpAndReturn;
  int id = this->_objectptr->AddPage( title->c_str());
  return Variable::ptr();
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
Variable::ptr wrap_ParamPanelAddFilename::CallMember( ParamList* p)
{
  Variable::ptr var;
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

  // passer AjouteNomFichier a std::string !!!!
  this->_objectptr->AjouteNomFichier( &var_id, 
                                      (string_ptr*)var->Pointer(), 
                                      label->c_str(), 
                                      tooltip);
  this->_objectptr->ContraintesNomFichier(var_id,
                            defpath->c_str(),
                            (char*)"",
                            defmask->c_str());

  // create integer variable to return
  Variable::ptr varres(new Variable());
  std::string varname = (boost::format("%1%_id")%var->Name()).str();
  int* varint = new int(var_id);
  varres->Init(type_int,varname.c_str(),(void*) varint);

  return varres;
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
Variable::ptr wrap_ParamPanelAddButton::CallMember( ParamList* p)
{
  Variable::ptr var;
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
                (void*) ((AMIFunction::ptr*) var->Pointer())->get(),
                tooltip);

  // create integer variable to return
  Variable::ptr varres(new Variable());
  std::string varname = (boost::format("%1%_id")%var->Name()).str();
  int* varint = new int(var_id);
  varres->Init(type_int,varname.c_str(),(void*) varint);

  return varres;


}

