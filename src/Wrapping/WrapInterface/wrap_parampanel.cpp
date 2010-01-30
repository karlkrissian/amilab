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

extern MainFrame*     GB_main_wxFrame;

extern VarContexts  Vars;


AMIObject* AddWrapParamPanel( const ParamPanel::ptr& pp)
{
  // Create new instance of the class
  AMIObject* amiobject = new AMIObject;
  amiobject->SetName("parampanel");

  // Set the object context
  Variables::ptr previous_ocontext = Vars.GetObjectContext();
  Vars.SetObjectContext(amiobject->GetContext());

#define ADDPROC(str_name,proc_name) \
  Vars.AddVar(  type_class_procedure, str_name,  \
                (void*)  new wrap_ParamPanel##proc_name(pp), \
                OBJECT_CONTEXT_NUMBER);

  ADDPROC("_BeginBook",       BeginBook);
  ADDPROC("_EndBook",         EndBook);

  ADDPROC("_BeginHorizontal", BeginHorizontal);
  ADDPROC("_EndHorizontal",   EndHorizontal);

  ADDPROC("_BeginBoxPanel",   BeginBoxPanel);
  ADDPROC("_EndBoxPanel",     EndBoxPanel);

  ADDPROC("_AddPage",         AddPage);

  ADDPROC("_AddFloat",        AddFloat);
  ADDPROC("_AddInt",          AddInt);

  ADDPROC("_Display",         Display);

  // Restore the object context
  Vars.SetObjectContext(previous_ocontext);

  return amiobject;
}

// Adds the ParamPanel wrapping
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

  if (!get_var_param<string>(    title, p, n)) HelpAndReturnVarPtr;

  ParamPanel::ptr pp;

  pp = ParamPanel::ptr(new ParamPanel(GB_main_wxFrame,(*title).c_str()));

  AMIObject* amiobject = AddWrapParamPanel(pp);

  Variable::ptr varres(new Variable());

  varres->Init(type_ami_object,"tmp_parampanel", (void*) amiobject);

  return varres;

}



// set the line parameters on an image drawing window
void wrap_ParamPanelBeginBook::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";

  this->_pp->BeginBook();

}


//---------------------------------------------------
void wrap_ParamPanelEndBook::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";
  this->_pp->EndBook();

}


//---------------------------------------------------
void wrap_ParamPanelBeginHorizontal::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";
  this->_pp->BeginHorizontal();
}


//---------------------------------------------------
void wrap_ParamPanelEndHorizontal::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";
  this->_pp->EndHorizontal();
}


//---------------------------------------------------
void wrap_ParamPanelBeginBoxPanel::CallProc( ParamList* p)
{
    char parameters[] =" \n\
        - string: box panel title\n\
            ";

  std::string* label = NULL;
  int n = 0;
  if (!get_var_param<string>(   label,  p, n)) HelpAndReturn;

  this->_pp->BeginBox( label->c_str());
  int id = this->_pp->BeginPanel( label->c_str());
  //    $$=id;
}


//---------------------------------------------------
void wrap_ParamPanelEndBoxPanel::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";
  this->_pp->EndPanel();
  this->_pp->EndBox( );
}


//---------------------------------------------------
void wrap_ParamPanelAddFloat::CallProc( ParamList* p)
{
    char parameters[] =" \n\
        - float variable \n\
        - string: label for the parameter \n\
        - minimum value (def:0)\n\
        - maximum value (def:1)\n\
            ";

  float* var;
  std::string* label = NULL;
  float minval = 0;
  float maxval = 1;
  int   n = 0;

  if (!get_var_param<float>( var,    p, n)) HelpAndReturn;
  if (!get_var_param<string>(   label,  p, n)) HelpAndReturn;
  if (!get_param<float>(    minval, p, n)) HelpAndReturn;
  if (!get_param<float>(    maxval, p, n)) HelpAndReturn;


  // how to get the variable comments here ...
/*
  std::string tooltip = (boost::format("%s  (%s)") % $5->GetComments() % $5->Name()).str();
  int var_id = this->_pp->AddFloat( var, label->c_str(),2,tooltip);
*/
  int var_id = this->_pp->AddFloat( var, label->c_str(),2);
  this->_pp->FloatConstraints( var_id, minval, maxval, *var );

  //    $$ = var_id;
}

//---------------------------------------------------
void wrap_ParamPanelAddInt::CallProc( ParamList* p)
{
    char parameters[] =" \n\
        - int variable \n\
        - string: label for the parameter \n\
        - minimum value (def:0)\n\
        - maximum value (def:100)\n\
            ";

  int* var;
  std::string* label = NULL;
  int  minval = 0;
  int  maxval = 100;
  int   n = 0;

  if (!get_var_param<int>(   var,    p, n)) HelpAndReturn;
  if (!get_var_param<string>(   label,  p, n)) HelpAndReturn;
  if (!get_int_param(      minval, p, n)) HelpAndReturn;
  if (!get_int_param(      maxval, p, n)) HelpAndReturn;


  // how to get the variable comments here ...
  int var_id = this->_pp->AddInteger( var, label->c_str());
  this->_pp->IntegerConstraints( var_id, minval, maxval, *var );

  //    $$ = var_id;
}


//--------------------------------------------------
void wrap_ParamPanelDisplay::CallProc( ParamList* p)
{
    char parameters[] =" \n\
            ";

  GB_main_wxFrame->AddParamPanelPage( this->_pp,
                                this->_pp->GetName(),
                                true // select as current page
                                );

}

//--------------------------------------------------
void wrap_ParamPanelAddPage::CallProc( ParamList* p)
{
    char parameters[] =" \n\
      - string: page title. \n\
            ";

  std::string* title = NULL;
  int   n = 0;

  if (!get_var_param<string>( title,  p, n)) HelpAndReturn;
  int id = this->_pp->AddPage( title->c_str());
}

