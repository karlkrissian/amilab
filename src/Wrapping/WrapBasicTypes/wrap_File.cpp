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
#include "wrapfunction_class.h"
#include "ami_class.h"
#include "ami_object.h"
#include "ami_function.h"

#ifndef BasicVariable_declared
  #define BasicVariable_declared
  AMI_DECLARE_TYPE(BasicVariable);
#endif

#include "driver.h"
extern yyip::Driver GB_driver;

//
// static member for creating a variable from a ParamList
//
template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<FILE>::CreateVar( ParamList* p, bool quiet )
{
  WrapClass_File::wrap_File construct;
  return construct.CallMember(p);
}

AMI_DEFINE_WRAPPEDTYPE_NOCOPY(FILE);

/*
 * readline.h
 *
 * Graham Watt
*/

#include <stdlib.h>
#include <stdio.h>

std::string readline(FILE* f)
{
  /*
   * calloc is like malloc, except it allocates cleared memory
   * so you don't have random bytes in the memory space 
  */
  char* line = NULL;
  std::string res;
  char c;
  int len = 0;
  
  /*
   * If the readline reaches the end of a file,
   * I want it to stop just the same
  */
  while ( (c = fgetc(f) ) != EOF && c != '\n')
  {
    /*
     * The actual size allocated needs to be 1 more
     * character than the string itself because '\0'
     * needs to be added to the end of the string
     * to prevent garbage
    */
    if (line==NULL) 
        line = (char*) calloc(sizeof(char) * (len + 2), sizeof(char) );
    else
        line = (char*) realloc(line, sizeof(char) * (len + 2) );
    line[len++] = c;
  }
  if (line!=NULL) 
  {
    line[len] = '\0';
    res = line;
    delete line;
  }
  
  return res;
}

//---------------------------------------------------
// Method that adds wrapping of File
//---------------------------------------------------

void  WrapClass_File::wrap_File::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(std::string,"The name of the file to be opened.");
  ADDPARAMCOMMENT_TYPE(std::string,"The file access modes (def: w).");
  return_comments = "A wrapped File object.";
}

//---------------------------------------------------
BasicVariable::ptr WrapClass_File::wrap_File::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(std::string,sFileName,"");
  GET_PARAM(std::string,sMode,"w");

  if ((sMode == "") || (sFileName == "")) {
    ClassHelpAndReturn;
  }
  else
  {
    FILE* file = fopen(sFileName.c_str(),sMode.c_str());
    // Create smart pointer with own deleter
    FILE_ptr file_ptr(file,file_deleter());

    if (file_ptr.get())
    {
      return WrapClass<FILE>::CreateVar(new WrapClass_File(file_ptr));
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
  ADDPARAMCOMMENT_TYPE(std::string,"Indicates a format specifier.");
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
  GET_PARAM(std::string,sFormatSpecifier,"");

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

  if (param->GetTypeName()==AMILabType<int>::name_as_string()) {
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
  if (param->GetTypeName()==AMILabType<float>::name_as_string()) {
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
  if (param->GetTypeName()==AMILabType<std::string>::name_as_string()) {
    DYNAMIC_CAST_VARIABLE(std::string,param,stringparam);
    char res[512];
    //setlocale(LC_NUMERIC, "C");
    if (fscanf(file.get(),"%s",res) == 0)
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

  std::string val = "";

  if (file.get())
  {
    char res[512];
    //setlocale(LC_NUMERIC, "C");
    if (fscanf(file.get(),"%s",res) == 0)
      GB_driver.err_print("Unable to read value from file (needs string variable)");
    else
      val = res;

 }

  RETURN_VAR(std::string,val);
}

//---------------------------------------------------
//  read_string
//---------------------------------------------------
void WrapClass_File::
      wrap_read_line::SetParametersComments() 
{
  return_comments = "The current line as a string.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_read_line::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());

  std::string val = "";

  if (file.get())
  {
    //setlocale(LC_NUMERIC, "C");
    val = readline(file.get());
 }

  RETURN_VAR(std::string,val);
}

//---------------------------------------------------
//  eof
//---------------------------------------------------
void WrapClass_File::
      wrap_eof::SetParametersComments() 
{
  return_comments = "The boolean for end of file.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_File::
      wrap_eof::CallMember( ParamList* p)
{
  FILE_ptr file(this->_objectptr->GetObj());
  bool res = (feof(file.get())!=0);
  return AMILabType<bool>::CreateVar(res);
}

