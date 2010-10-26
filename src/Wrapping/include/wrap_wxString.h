//
// C++ Interface: wrap_wxString
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxString_h_
#define _wrap_wxString_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include <wx/string.h>

AMI_DECLARE_TYPE(wxString);

class WrapClass_wxString : public WrapClass<wxString>
{
  DEFINE_CLASS(WrapClass_wxString);

  public:

    /// Constructor
    WrapClass_wxString(boost::shared_ptr<wxString> si): WrapClass<wxString>(si) 
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString, "Wrapping of wxString (see http://docs.wxwidgets.org/)." );

/*
    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxString* sp);
*/

    ADD_CLASS_METHOD(Clear,        "Empties the string and frees memory occupied by it.");
    ADD_CLASS_METHOD(SetChar,      "Sets the character at position n");
    ADD_CLASS_METHOD(Append,       "Concatenated the string passed by parameter.");
    ADD_CLASS_METHOD(Remove,       "Removes the portion from pos to the end of the string.");
    ADD_CLASS_METHOD(SubString,    "Returns the part of the string between the indices from and to inclusive.");
    ADD_CLASS_METHOD(ReplaceFirst, "Replace first occurrences of substring with another one.");
    ADD_CLASS_METHOD(ReplaceAll,   "Replace all occurrences of substring with another one.");
    ADD_CLASS_METHOD(Truncate,     "Truncate the string to the given length.");
    ADD_CLASS_METHOD(Trim,         "Removes white-space (space, tabs, form feed, newline and carriage return) from the left or from the right end of the string (right is default).");
    ADD_CLASS_METHOD(Length,       "Returns the length of the string.");
    ADD_CLASS_METHOD(IsEmpty,      "Returns true if the string is empty.");
    ADD_CLASS_METHOD(IsSameAs,     "Test for string equality, case-sensitive (default) or not.");
    ADD_CLASS_METHOD(Cmp,          "Case-sensitive comparison."); 
    ADD_CLASS_METHOD(CmpNoCase,    "Case-insensitive comparison.");
    ADD_CLASS_METHOD(Empty,        "Makes the string empty, but doesn't free memory occupied by the string.");
    ADD_CLASS_METHOD(Find,         "Searches for the given string");
    ADD_CLASS_METHOD(Matches,      "Returns true if the string contents matches a mask containing '*' and '?'.");
    ADD_CLASS_METHOD(Lower,        "Returns this string converted to the lower case.");
    ADD_CLASS_METHOD(MakeLower,    "Converts all characters to lower case.");
    ADD_CLASS_METHOD(MakeUpper,    "Converts all characters to upper case.");
    ADD_CLASS_METHOD(Upper,        "Returns this string converted to upper case.");
    ADD_CLASS_METHOD(FromAscii,    "Converts the string or character from an ASCII, 7-bit form to the native wxString representation.");
    ADD_CLASS_METHOD(FromUTF8,     "Converts C string encoded in UTF-8 to wxString. Note that this method assumes that string parameter is a valid UTF-8 sequence and doesn't do any validation in release builds, it's validity is only checked in debug builds.");
    ADD_CLASS_METHOD(ToAscii,      "Converts the string to an ASCII. Note that this conversion only works if the string contains only ASCII characters.");
    ADD_CLASS_METHOD(ToDouble,     "Attempts to convert the string to a floating point number. Return -1 if the string does not represent such number.");
    ADD_CLASS_METHOD(ToLong,       "Attempts to convert the string to a signed integer in base 10. Return if the string does not represent a valid number.");
    ADD_CLASS_METHOD(ToUTF8,       "Converts the strings contents to UTF-8.");
    ADD_CLASS_METHOD(c_str,        "Returns a string data.");
    ADD_CLASS_METHOD(copy,         "Copy constructor.");

    //Operators.
    ADD_CLASS_METHOD(assign,       "Operator =, assing a new wxString object to the current.");
    ADD_CLASS_METHOD(add_assign,   "Operator +=, assing and add the value of new wxString object to the current.");
    ADD_CLASS_METHOD(add,          "Operator +, concatenate the value of new wxString object to the current.");
    ADD_CLASS_METHOD(equal,        "Operator ==, compare a wxString objects with the current.");
    ADD_CLASS_METHOD(not_equal,    "Operator !=, compare a wxString objects with the current.");

    //Try cast.
    ADD_CLASS_METHOD(try_cast,     "Try cast the current wxString object to string.");

//    ADD_CLASS_METHOD(GetChar,   "");
//    ADD_CLASS_METHOD(Printf,       "");
//    ADD_CLASS_METHOD(PrintfV,      "");

    void AddMethods(WrapClass<wxString>::ptr this_ptr )
    {
      AddVar_Append(       this_ptr);
      AddVar_SetChar(      this_ptr);
      AddVar_Clear(        this_ptr);
      AddVar_Remove(       this_ptr);
      AddVar_SubString(    this_ptr);
      AddVar_ReplaceFirst( this_ptr);
      AddVar_ReplaceAll(   this_ptr);
      AddVar_Truncate(     this_ptr);
      AddVar_Trim(         this_ptr);
      AddVar_Length(       this_ptr);
      AddVar_IsEmpty(      this_ptr);
      AddVar_IsSameAs(     this_ptr);
      AddVar_Cmp(          this_ptr);
      AddVar_CmpNoCase(    this_ptr);
      AddVar_Empty(        this_ptr);
      AddVar_Find(         this_ptr);
      AddVar_Matches(      this_ptr);
      AddVar_Lower(        this_ptr);
      AddVar_MakeLower(    this_ptr);
      AddVar_MakeUpper(    this_ptr);
      AddVar_Upper(        this_ptr);
      AddVar_FromAscii(    this_ptr);
      AddVar_FromUTF8(     this_ptr);
      AddVar_ToAscii(      this_ptr);
      AddVar_ToDouble(     this_ptr);
      AddVar_ToLong(       this_ptr);
      AddVar_ToUTF8(       this_ptr);
      AddVar_copy(         this_ptr);
      AddVar_c_str(        this_ptr);

      // Operators
      AddVar_assign(       this_ptr);
      AddVar_add_assign(   this_ptr);
      AddVar_add(          this_ptr);
      AddVar_equal(        this_ptr);
      AddVar_not_equal(    this_ptr);

      //Try cast.
      AddVar_try_cast(     this_ptr);
    }

};


#endif // _wrap_wxString_h_
