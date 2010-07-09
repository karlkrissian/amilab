//
// C++ Implementation: wrap_wxString
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "wrap_wxString.h"

#include "VarContexts.hpp"
#include "wrapfunctions.hpp"
#include "ami_object.h"

#define GET_PARAM(type,varname,defaultval) \
  type varname = defaultval; \
  if (!get_val_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#define GET_SMTPTR_PARAM(type,varname) \
  boost::shared_ptr<type> varname; \
  if (!get_val_smtptr_param<type>( varname, p, n)) \
    ClassHelpAndReturn;

#include <wx/string.h>
#include "driver.h"
#include "MainFrame.h"

extern yyip::Driver GB_driver;
extern MainFrame* GB_main_wxFrame;
extern wxApp* GB_wxApp;


//-------------------------------------------------------------------------
AMIObject::ptr AddWrap_wxString(  WrapClass_wxString::ptr& objectptr)
{
  // Create new instance of the class
  AMIObject::ptr amiobject( new AMIObject);
  amiobject->SetName("wxString");
  amiobject->SetWrappedObject(objectptr);
  objectptr->SetAMIObject(amiobject);
  objectptr->AddMethods( objectptr);
  return amiobject;
}

//----------------------------------------------------------
Variable<AMIObject>::ptr CreateVar_wxString( wxString* si)
{
  // Create smart pointer with own deleter
  boost::shared_ptr<wxString> si_ptr( si );

  WrapClass_wxString::ptr sip(new WrapClass_wxString(si_ptr));
  AMIObject::ptr amiobject(AddWrap_wxString(sip));
  Variable<AMIObject>::ptr varres(
      new Variable<AMIObject>( amiobject));
  return varres;
}

//---------------------------------------------------
// Method that adds wrapping of wxString
//---------------------------------------------------

void  wrap_wxString::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"A string (optional).");
  return_comments = "A wrapped wxString object.";
}

//---------------------------------------------------
BasicVariable::ptr wrap_wxString::CallMember( ParamList* p)
{
  if (!p) ClassHelpAndReturn;
  int n=0;
  wxString* owxString;
  string sString;

  if (get_val_param<string>( sString, p, n))
    owxString = new wxString(wxT(sString.c_str()), wxConvUTF8);
  else
    owxString = new wxString();

  return CreateVar_wxString(owxString);
}

//---------------------------------------------------
//  Clear
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Clear::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Clear::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  owxString->Clear();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SetChar
//---------------------------------------------------
void WrapClass_wxString::
      wrap_SetChar::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"The string position (For example, 0).");
  ADDPARAMCOMMENT_TYPE(string,"The character to be added.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_SetChar::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,iPos,0);
  GET_PARAM(string,sChar,"");

  if(sChar.length() == 1) {
    if (owxString->Len() > 0)
      owxString->SetChar(iPos,wxT(sChar[0]));
    else
      GB_driver.err_print("SetChar can not use (empty string, use Append()).");
  }
  else
    GB_driver.err_print("More than one character has passed (you can add only one.)");

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Append
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Append::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to concatenate.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Append::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  owxString->Append(wxT(sString.c_str()));

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Remove
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Remove::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"The position of the beginning of the string.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Remove::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,iPos, 0);

  owxString->Remove(iPos);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  SubString
//---------------------------------------------------
void WrapClass_wxString::
      wrap_SubString::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"The position of the beginning of the string.");
  ADDPARAMCOMMENT_TYPE(int,"The position of the end of the string.");
  return_comments = "A wrapped wxString object with the part of the string between the indices from and to inclusive.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_SubString::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,iPosBegin, 0);
  GET_PARAM(int,iPosEnd, 0);

  wxString *oString = new wxString(owxString->SubString(iPosBegin, iPosEnd));

  return CreateVar_wxString(oString);
}

//---------------------------------------------------
//  ReplaceFirst
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ReplaceFirst::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The pattern to find.");
  ADDPARAMCOMMENT_TYPE(string,"The string to replace.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ReplaceFirst::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sPattern, "");
  GET_PARAM(string,sToReplace, "");

  owxString->Replace(wxT(sPattern.c_str()), wxT(sToReplace.c_str()), false);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  ReplaceAll
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ReplaceAll::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The pattern to find.");
  ADDPARAMCOMMENT_TYPE(string,"The string to replace.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ReplaceAll::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sPattern, "");
  GET_PARAM(string,sToReplace, "");

  owxString->Replace(wxT(sPattern.c_str()), wxT(sToReplace.c_str()), true);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Truncate
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Truncate::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(int,"The new length of string.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Truncate::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(int,iLen, owxString->Len());

  owxString->Truncate(iLen);

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Trim
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Trim::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(unsigned char,"Flag indicating if the process starts with the left side of the string or the right (By Default, 1).");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Trim::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(unsigned char,ucFlag, 1);

  /**
    Don't work in wxWidgets.
   **/

  if (ucFlag == 1)
    owxString->Trim(true);
  else
    owxString->Trim(false);

  printf("\n%s\n", owxString->c_str());
  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Length
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Length::SetParametersComments() 
{
  return_comments = "The length of the string (integer value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Length::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  int val = owxString->Len();

  RETURN_VAR(int,val);
}

//---------------------------------------------------
//  IsEmpty
//---------------------------------------------------
void WrapClass_wxString::
      wrap_IsEmpty::SetParametersComments() 
{ 
  return_comments = "True if the string contains only ASCII characters (unsigned char value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_IsEmpty::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  unsigned char res = (unsigned char) owxString->IsEmpty();

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  IsSameAs
//---------------------------------------------------
void WrapClass_wxString::
      wrap_IsSameAs::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to compare.");
  ADDPARAMCOMMENT_TYPE(unsigned char,"Whether it is case sensitive (0: sensitive, 1: no sensitive).");
  return_comments = "True if strings are equal, false otherwise (unsigned char value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_IsSameAs::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  unsigned char res;
  GET_PARAM(string,sString,"");
  GET_PARAM(unsigned char,ucSensitive,0);

  if (ucSensitive)
    res = (unsigned char) owxString->IsSameAs(wxT(sString.c_str()),false);
  else
    res = (unsigned char) owxString->IsSameAs(wxT(sString.c_str()),true);

  RETURN_VAR(unsigned char,res);
}

//---------------------------------------------------
//  Cmp
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Cmp::SetParametersComments() 
{ 
  ADDPARAMCOMMENT_TYPE(string,"The string to compare.");
  return_comments = "Returns a positive value if the string is greater than the argument, zero if it is equal to it or a negative value if it is less than the argument (same semantics as the standard strcmp() function) (unsigned char value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Cmp::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  if (sString != "")
  {
    unsigned char res = (unsigned char) owxString->Cmp(wxT(sString.c_str()));

    RETURN_VAR(unsigned char,res);
  }
  else
       ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  CmpNoCase
//---------------------------------------------------
void WrapClass_wxString::
      wrap_CmpNoCase::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to compare.");
  return_comments = "Returns a positive value if the string is greater than the argument, zero if it is equal to it or a negative value if it is less than the argument (same semantics as the standard strcmp() function) (unsigned char value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_CmpNoCase::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  if (sString != "")
  {
    unsigned char res = (unsigned char) owxString->CmpNoCase(wxT(sString.c_str()));

    RETURN_VAR(unsigned char,res);
  }
  else
       ClassHelpAndReturn;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Empty
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Empty::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Empty::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  owxString->Empty();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Find
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Find::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to find.");
  return_comments = "Returns the starting index if found (integer value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Find::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  int res = owxString->Find(wxT(sString.c_str()));

  RETURN_VAR(int,res);
}

//---------------------------------------------------
//  Matches
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Matches::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to matches.");
  return_comments = "True if the string contents matches a mask containing '*' and '?' (unsigned char value).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Matches::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  if (sString != "")
  {
    unsigned char res = (unsigned char) owxString->Matches(wxT(sString.c_str()));

    RETURN_VAR(unsigned char,res);
  }
  else
  {
    ClassHelpAndReturn;
    return BasicVariable::ptr();
  }
}

//---------------------------------------------------
//  Lower
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Lower::SetParametersComments() 
{
  return_comments = "This string converted to the lower case.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Lower::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  wxString oString = owxString->Lower();

  return CreateVar_wxString(&oString);
}

//---------------------------------------------------
//  MakeLower
//---------------------------------------------------
void WrapClass_wxString::
      wrap_MakeLower::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_MakeLower::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  owxString->MakeLower();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  MakeUpper
//---------------------------------------------------
void WrapClass_wxString::
      wrap_MakeUpper::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_MakeUpper::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  owxString->MakeUpper();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  Upper
//---------------------------------------------------
void WrapClass_wxString::
      wrap_Upper::SetParametersComments() 
{
  return_comments = "This string converted to the upper case.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_Upper::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  wxString oString = owxString->Upper();

  return CreateVar_wxString(&oString);
}

//---------------------------------------------------
//  FromAscii
//---------------------------------------------------
void WrapClass_wxString::
      wrap_FromAscii::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to Convert.");
  return_comments = "The string value converted to the native wxString representation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_FromAscii::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  if (sString != "")
  {
    wxString oString = owxString->FromAscii(sString.c_str());
    return CreateVar_wxString(&oString);
  }
  else
  {
    ClassHelpAndReturn;
    return BasicVariable::ptr();
  }
}

//---------------------------------------------------
//  FromUTF8
//---------------------------------------------------
void WrapClass_wxString::
      wrap_FromUTF8::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(string,"The string to convert.");
  return_comments = "The string value converted to the native wxString representation.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_FromUTF8::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  GET_PARAM(string,sString,"");

  if (sString != "")
  {
    wxString oString = owxString->FromUTF8(sString.c_str());
    return CreateVar_wxString(&oString);
  }
  else
  {
    ClassHelpAndReturn;
    return BasicVariable::ptr();
  }
}

//---------------------------------------------------
//  ToAscii
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ToAscii::SetParametersComments() 
{
  return_comments = "This string converted to ASCII.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ToAscii::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  string val = owxString->ToAscii();

  RETURN_VAR(string,val);
}

//---------------------------------------------------
//  ToDouble
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ToDouble::SetParametersComments() 
{
  return_comments = "This string value converted to double (return -1 in error case).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ToDouble::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  double val;

  if (!owxString->ToDouble(&val))
    val = -1;

  RETURN_VAR(double,val);
}

//---------------------------------------------------
//  ToLong
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ToLong::SetParametersComments() 
{
  return_comments = "This string value converted to double (return -1 in error case).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ToLong::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  long val;

  if (!owxString->ToLong(&val))
    val = -1;

  RETURN_VAR(long,val);
}

//---------------------------------------------------
//  ToUTF8
//---------------------------------------------------
void WrapClass_wxString::
      wrap_ToUTF8::SetParametersComments() 
{ }
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_ToUTF8::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  owxString->ToUTF8();

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  c_str
//---------------------------------------------------
void WrapClass_wxString::
      wrap_c_str::SetParametersComments() 
{
  return_comments="A string data.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_c_str::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  string val = owxString->c_str();

  RETURN_VAR(string,val);
}

//---------------------------------------------------
//  copy
//---------------------------------------------------
void WrapClass_wxString::
      wrap_copy::SetParametersComments() 
{
  return_comments="A copy of the wxString.";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_copy::CallMember( ParamList* p)
{
  return CreateVar_wxString( new wxString(*(this->_objectptr->GetObj())));
}

//---------------------------------------------------
//  assign
//---------------------------------------------------
void WrapClass_wxString::
      wrap_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxString,"A wrapped wxString object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_assign::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxString,varstring,owxStringParameter);
  if (!owxStringParameter.get()) ClassHelpAndReturn;

  if (owxStringParameter.get())
    owxString = owxStringParameter;

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  add_assign
//---------------------------------------------------
void WrapClass_wxString::
      wrap_add_assign::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxString,"A wrapped wxString object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_add_assign::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  int n=0;
  string sVal;
  CLASS_GET_OBJECT_PARAM(wxString,varstring,owxStringParameter);
  if (!owxStringParameter.get()) ClassHelpAndReturn;

  if (owxStringParameter.get())
  {
    sVal = owxStringParameter.get()->c_str();
    owxString->Append(sVal.c_str());
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  add
//---------------------------------------------------
void WrapClass_wxString::
      wrap_add::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxString,"A wrapped wxString object.");
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_add::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  string sVal;
  int n=0;
  CLASS_GET_OBJECT_PARAM(wxString,varstring,owxStringParameter);
  if (!owxStringParameter.get()) ClassHelpAndReturn;

  if (owxStringParameter.get())
  {
    sVal = owxStringParameter.get()->c_str();
    owxString->Append(sVal.c_str());
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  equal
//---------------------------------------------------
void WrapClass_wxString::
      wrap_equal::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxString,"A wrapped wxString object.");
  return_comments = "True if strings are equal, false otherwise (0: False, 1: True).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_equal::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  string sVal;
  int n=0;
  unsigned char res;

  CLASS_GET_OBJECT_PARAM(wxString,varstring,owxStringParameter);
  if (!owxStringParameter.get()) ClassHelpAndReturn;

  if (owxStringParameter.get())
  {
    sVal = owxStringParameter.get()->c_str();
    res = (unsigned char)owxString->IsSameAs(wxT(sVal.c_str()),true);

    RETURN_VAR(unsigned char,res);
  }

  return BasicVariable::ptr();
}

//---------------------------------------------------
//  not_equal
//---------------------------------------------------
void WrapClass_wxString::
      wrap_not_equal::SetParametersComments() 
{
  ADDPARAMCOMMENT_TYPE(wxString,"A wrapped wxString object.");
  return_comments = "True if strings aren't equal, false otherwise (0: False, 1: True).";
}
//---------------------------------------------------
BasicVariable::ptr WrapClass_wxString::
      wrap_not_equal::CallMember( ParamList* p)
{
  boost::shared_ptr<wxString> owxString(this->_objectptr->GetObj());

  if (!p) ClassHelpAndReturn;
  string sVal;
  int n=0;
  unsigned char res;

  CLASS_GET_OBJECT_PARAM(wxString,varstring,owxStringParameter);
  if (!owxStringParameter.get()) ClassHelpAndReturn;

  if (owxStringParameter.get())
  {
    sVal = owxStringParameter.get()->c_str();
    res = (unsigned char)owxString->IsSameAs(wxT(sVal.c_str()),true);

    if (res==1)
      res=0;
    else
      res=1;

    RETURN_VAR(unsigned char,res);
  }

  return BasicVariable::ptr();
}