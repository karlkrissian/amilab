/**
 * C++ Interface: wrap_File
 *
 * Description: wrapping File
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#include "wrap_File.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

//#include "vtkwrap.h"
//#include "FluidProject.h"
//#include "Func_ReadCTALine.h"
//#include "fonctions.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include "driver.h"
//#include "MainFrame.h"
#include "CallBackAMIFunction.h"

extern yyip::Driver GB_driver;
//extern MainFrame* GB_main_wxFrame;
extern wxApp* GB_wxApp;

//extern void CB_delete_variable( void* var);
//extern void CB_delete_varlist( void* var);


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_File(  WrapClass_File::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("File");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_File( FILE* si)
{
  // Create smart pointer with own deleter
  FILE_ptr si_ptr(si,file_deleter());

  WrapClass_File::ptr sip(new WrapClass_File(si_ptr));
  AMIObject::ptr amiobject(AddWrap_File(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of File
//---------------------------------------------------

void  wrap_File::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The file access modes.");
  ADDPARAMCOMMENT_TYPE(string,"The name of the file to be opened.");
  return_comments = "A wrapped File object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_File::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sMode,"");
  GET_PARAM(string,sFileName,"");

  if ((sMode == "") || (sFileName == ""))
    ClassHelpAndReturn
  else
  {
    FILE* file = fopen(sFileName.c_str(),sMode.c_str());

    if (file)
    {
      return CreateVar_File(file);
    }
    else
    {
        fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                    sFileName.c_str(),sMode.c_str());
        return BasicVariable::ptr();
    }
  }
}

//---------------------------------------------------
//  rewind
//---------------------------------------------------
void WrapClass_File::
      wrap_rewind::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_rewind::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  if (file.get())
    rewind(file.get());

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  print
//---------------------------------------------------
void WrapClass_File::
      wrap_print::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Text written to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_print::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sText,"");

  /**
    Warning: The rule appears as deprecated in improcess_bison.ypp
  **/

  if (file.get())
  {
    fprintf(file.get(),"%s",sText.c_str());
    fflush(file.get());
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  printn
//---------------------------------------------------
void WrapClass_File::
      wrap_printn::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"Text written to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_printn::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sText,"");

  /**
    Warning: The rule appears as deprecated in improcess_bison.ypp
  **/

  if (file.get())
  {
    fprintf(file.get(),"%s\n",sText.c_str());
    fflush(file.get());
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  printvar
//---------------------------------------------------
void WrapClass_File::
      wrap_printvar::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(BasicVariable,"Variable to write to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_printvar::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  BasicVariable::ptr var;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_generic_var_param(var, p, n)) ClassHelpAndReturn;

  if (file.get())
  {
    if (var.get()) {
      fprintf(file.get(),var->GetValueAsString().c_str());
      fflush(file.get());
    }
    else
      GB_driver.err_print("empty variable");
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  printnvar
//---------------------------------------------------
void WrapClass_File::
      wrap_printnvar::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(BasicVariable,"Variable to write to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_printnvar::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  BasicVariable::ptr var;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_generic_var_param(var, p, n)) ClassHelpAndReturn;

  if (file.get())
  {
    if (var.get()) {
      fprintf(file.get(),var->GetValueAsString().c_str());
      fprintf(file.get(),"\n");
      fflush(file.get());
    }
    else
      GB_driver.err_print("empty variable");
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  close
//---------------------------------------------------
void WrapClass_File::
      wrap_close::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_close::CallMember( ParamList* p)
{
  printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  scan_float
//---------------------------------------------------
void WrapClass_File::
      wrap_scan_float::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The name of the file to be read.");
  return_comments = "The float number that has been read from the file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_scan_float::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  float val = 0;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sNameFile,"");

  /**
    Description:
      Scans a float number in the given file and based on the
      given formatting expression.
  **/

  if (sNameFile == "")
    ClassHelpAndReturn
  else
  {
    if (file.get())
    {
      float res;
      setlocale(LC_NUMERIC, "C");
      fscanf(file.get(),sNameFile.c_str(),&res);
      val =  res;
    }
  }

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  read_float
//---------------------------------------------------
void WrapClass_File::
      wrap_read_float::SetParametersComments() 
{
  return_comments = "The float number that has been read from the file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_read_float::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  float val = 0;

  if (file.get())
  {
    float res;
    setlocale(LC_NUMERIC, "C");
    fscanf(file.get(),"%f",&res);
    val =  res;

/*
    | VAR_FILE T_POINT T_read T_OP_PAR PROCESSED_VAR T_CL_PAR
    {
      GET_VARSTACK_VALUE(float,val_ptr);
      if (!val_ptr.get()) {
        driver.err_print("needs float variable");
        YYABORT;
      }
      GET_VARSTACK_VALUE(FILE,file);

      float*  var = val_ptr.get();
      setlocale(LC_NUMERIC, "C");
      float val = 0;
      if (var!=NULL) {
        val = fscanf(file.get(),"%f",var);
      } else {
        // TODO: error message here ...
      }
      ADD_VARSTACK_FLOAT(val);
    }
*/
  }

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  read_string
//---------------------------------------------------
void WrapClass_File::
      wrap_read_string::SetParametersComments() 
{
  return_comments = "The float number that has been read from the file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_read_string::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->_obj);

  string val = "";

  if (file.get())
  {
    char res[100];
    setlocale(LC_NUMERIC, "C");
    fscanf(file.get(),"%s",&res);
    val = res;

/*
    | VAR_FILE T_POINT T_read T_OP_PAR VAR_STRING T_CL_PAR
    {
      GET_VARSTACK_VALUE(std::string,st);
      GET_VARSTACK_VALUE(FILE,file);
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      float val = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      (*st) = res;
      ADD_VARSTACK_FLOAT(val);
    }
*/
 }

  RETURN_VAR(string,val);
}