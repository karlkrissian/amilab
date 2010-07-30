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
  ADDPARAMCOMMENT_TYPE(string,"The name of the file to be opened.");
  ADDPARAMCOMMENT_TYPE(string,"The file access modes (def: w).");
  return_comments = "A wrapped File object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_File::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sFileName,"");
  GET_PARAM(string,sMode,"w");

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
  ADDPARAMCOMMENT_TYPE(BasicVariable,"Variable to write to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_print::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  BasicVariable::ptr var;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_generic_var_param(var, p, n)) ClassHelpAndReturn;

  if (file.get())
  {
    if (var.get()) {
      fprintf(file.get(),"%s",var->GetValueAsString().c_str());
      fflush(file.get());
    }
    else
      GB_driver.err_print("empty variable");
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  printn
//---------------------------------------------------
void WrapClass_File::
      wrap_printn::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(BasicVariable,"Variable to write to the file.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_printn::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  BasicVariable::ptr var;

  if (!p) ClassHelpAndReturn;
  int n=0;
  if (!get_generic_var_param(var, p, n)) ClassHelpAndReturn;

  if (file.get())
  {
    if (var.get()) {
      fprintf(file.get(),"%s",var->GetValueAsString().c_str());
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
  ADDPARAMCOMMENT_TYPE(string,"Indicates a format specifier.");
  return_comments = "The float number that has been read from the file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_scan_float::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  float val = 0;

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sFormatSpecifier,"");

  /**
    Description:
      Scans a float number in the given file and based on the
      given formatting expression.
  **/

  if (sFormatSpecifier == "")
    ClassHelpAndReturn
  else
  {
    if (file.get())
    {
      float res;
      setlocale(LC_NUMERIC, "C");
      if(fscanf(file.get(),sFormatSpecifier.c_str(),&res) == 0) {
        GB_driver.err_print("Unable to read value from file");
        val = 0;
      }
      else
        val = res;
    }
  }

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  read
//---------------------------------------------------
void WrapClass_File::
      wrap_read::SetParametersComments() 
{
  ADDPARAMCOMMENT("Reference to a variable of type int, float or string (of maximum 512 characters)");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_read::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  int n = 0;
  BasicVariable::ptr param;
  if (!get_generic_var_param(param,p,n,true)) ClassHelpAndReturn;

  if (param->GetTypeName()==to_string<int>::value()) {
    DYNAMIC_CAST_VARIABLE(int,param,intparam);
    if (file.get())
    {
      int res;
      setlocale(LC_NUMERIC, "C");
      if (fscanf(file.get(),"%d",&res) == 0) {
        GB_driver.err_print("Unable to read integer value from file");
      }
      else
        *intparam->Pointer() =  res;
    }
  } else 
  if (param->GetTypeName()==to_string<float>::value()) {
    DYNAMIC_CAST_VARIABLE(float,param,floatparam);
    if (file.get())
    {
      float res;
      setlocale(LC_NUMERIC, "C");
      if (fscanf(file.get(),"%f",&res) == 0) {
        GB_driver.err_print("Unable to read float value from file");
      }
      else
        *floatparam->Pointer() =  res;
    }
  } else 
  if (param->GetTypeName()==to_string<std::string>::value()) {
    DYNAMIC_CAST_VARIABLE(std::string,param,stringparam);
    char res[512];
    //setlocale(LC_NUMERIC, "C");
    if (fscanf(file.get(),"%s",&res) == 0)
      GB_driver.err_print("Unable to read string value from file");
    else
        *stringparam->Pointer() =  res;
  } else 
    ClassHelpAndReturn;

  return BasicVariable::ptr();
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
  FILE_ptr file(this->_objectptr->GetObj());

  float val = 0;

  if (file.get())
  {
    float res;
    setlocale(LC_NUMERIC, "C");
    if (fscanf(file.get(),"%f",&res) == 0) {
      GB_driver.err_print("Unable to read value from file (needs float variable)");
      val = 0;
    }
    else
      val =  res;
  }

  RETURN_VAR(float,val);
}

//---------------------------------------------------
//  read_string
//---------------------------------------------------
void WrapClass_File::
      wrap_read_string::SetParametersComments() 
{
  return_comments = "The string that has been read from the file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_read_string::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  string val = "";

  if (file.get())
  {
    char res[100];
    //setlocale(LC_NUMERIC, "C");
    if (fscanf(file.get(),"%s",&res) == 0)
      GB_driver.err_print("Unable to read value from file (needs string variable)");
    else
      val = res;

 }

  RETURN_VAR(string,val);
}