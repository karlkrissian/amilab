/**
 * C++ Interface: wrap_wxString
 *
 * Description: wrapping wxString
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxString_h_
#define _wrap_wxString_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxStringBase.h"


AMI_DECLARE_TYPE(wxString);

// TODO: check for inheritence ...
class WrapClass_wxString : public WrapClass<wxString>
    //, public virtual WrapClass_wxStringBase
{
  DEFINE_CLASS(WrapClass_wxString);

  protected:
    typedef WrapClass<wxString>::ptr _parentclass_ptr;
    typedef wxString ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxString>& GetObj() const { return WrapClass<wxString>::GetObj(); }

    /// Constructor
    WrapClass_wxString(boost::shared_ptr<wxString > si): 
    WrapClass<wxString>(si)
    //, WrapClass_wxStringBase(si)
    {}

    /// Destructor
    ~WrapClass_wxString()
    {
      std::cout << "~WrapClass_wxString()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_1,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: wxStringBase
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_2,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_3,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_4,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_5,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_6,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_7,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_8,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> >
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_9,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_10,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_11,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_12,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    /* The following types are missing: void, void
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxString_13,"Wrapping of wxString, http://docs.wxwidgets.org/stable/wx_wxstring.html#wxstring.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxString*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Len,"http://docs.wxwidgets.org/stable/wx_wxstring.html#len")
    ADD_CLASS_METHOD(IsEmpty,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isempty")
    ADD_CLASS_METHOD(Truncate,"http://docs.wxwidgets.org/stable/wx_wxstring.html#truncate")
    ADD_CLASS_METHOD(Empty,"http://docs.wxwidgets.org/stable/wx_wxstring.html#empty")
    ADD_CLASS_METHOD(Clear,"http://docs.wxwidgets.org/stable/wx_wxstring.html#clear")
    ADD_CLASS_METHOD(IsAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isascii")
    ADD_CLASS_METHOD(IsNumber,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isnumber")
    ADD_CLASS_METHOD(IsWord,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isword")
    ADD_CLASS_METHOD(GetChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getchar")
    ADD_CLASS_METHOD(GetWritableChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getwritablechar")
    ADD_CLASS_METHOD(SetChar,"http://docs.wxwidgets.org/stable/wx_wxstring.html#setchar")
    ADD_CLASS_METHOD(Last_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
    ADD_CLASS_METHOD(Last,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
    ADD_CLASS_METHOD(Last_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
    ADD_CLASS_METHOD(wx_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wx_str")
    ADD_CLASS_METHOD(GetData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getdata")
/* The following types are missing: wxWritableCharBuffer
    ADD_CLASS_METHOD(char_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#char_str")
*/
/* The following types are missing: wxWritableWCharBuffer
    ADD_CLASS_METHOD(wchar_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wchar_str")
*/
    ADD_CLASS_METHOD(FromAscii_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(FromAscii_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromascii")
    ADD_CLASS_METHOD(ToAscii,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toascii")
    ADD_CLASS_METHOD(FromUTF8_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
    ADD_CLASS_METHOD(FromUTF8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
    ADD_CLASS_METHOD(FromUTF8_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fromutf8")
    ADD_CLASS_METHOD(utf8_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#utf8_str")
    ADD_CLASS_METHOD(ToUTF8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toutf8")
    ADD_CLASS_METHOD(From8BitData_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
    ADD_CLASS_METHOD(From8BitData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
    ADD_CLASS_METHOD(From8BitData_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#from8bitdata")
    ADD_CLASS_METHOD(To8BitData,"http://docs.wxwidgets.org/stable/wx_wxstring.html#to8bitdata")
    ADD_CLASS_METHOD(mb_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mb_str")
    ADD_CLASS_METHOD(mbc_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mbc_str")
    ADD_CLASS_METHOD(wc_str_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
    ADD_CLASS_METHOD(wc_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
    ADD_CLASS_METHOD(wc_str_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#wc_str")
    ADD_CLASS_METHOD(fn_str,"http://docs.wxwidgets.org/stable/wx_wxstring.html#fn_str")
    ADD_CLASS_METHOD(Append_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Append_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(Prepend,"http://docs.wxwidgets.org/stable/wx_wxstring.html#prepend")
    ADD_CLASS_METHOD(Cmp_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(Cmp,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(Cmp_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmp")
    ADD_CLASS_METHOD(CmpNoCase_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase")
    ADD_CLASS_METHOD(CmpNoCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase")
    ADD_CLASS_METHOD(CmpNoCase_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#cmpnocase")
    ADD_CLASS_METHOD(IsSameAs_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(IsSameAs_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#issameas")
    ADD_CLASS_METHOD(Mid,"http://docs.wxwidgets.org/stable/wx_wxstring.html#mid")
    ADD_CLASS_METHOD(StartsWith,"http://docs.wxwidgets.org/stable/wx_wxstring.html#startswith")
    ADD_CLASS_METHOD(EndsWith,"http://docs.wxwidgets.org/stable/wx_wxstring.html#endswith")
    ADD_CLASS_METHOD(Left,"http://docs.wxwidgets.org/stable/wx_wxstring.html#left")
    ADD_CLASS_METHOD(Right,"http://docs.wxwidgets.org/stable/wx_wxstring.html#right")
    ADD_CLASS_METHOD(BeforeFirst,"http://docs.wxwidgets.org/stable/wx_wxstring.html#beforefirst")
    ADD_CLASS_METHOD(BeforeLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#beforelast")
    ADD_CLASS_METHOD(AfterFirst,"http://docs.wxwidgets.org/stable/wx_wxstring.html#afterfirst")
    ADD_CLASS_METHOD(AfterLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#afterlast")
    ADD_CLASS_METHOD(Before,"http://docs.wxwidgets.org/stable/wx_wxstring.html#before")
    ADD_CLASS_METHOD(After,"http://docs.wxwidgets.org/stable/wx_wxstring.html#after")
    ADD_CLASS_METHOD(MakeUpper,"http://docs.wxwidgets.org/stable/wx_wxstring.html#makeupper")
    ADD_CLASS_METHOD(Upper,"http://docs.wxwidgets.org/stable/wx_wxstring.html#upper")
    ADD_CLASS_METHOD(MakeLower,"http://docs.wxwidgets.org/stable/wx_wxstring.html#makelower")
    ADD_CLASS_METHOD(Lower,"http://docs.wxwidgets.org/stable/wx_wxstring.html#lower")
    ADD_CLASS_METHOD(Trim,"http://docs.wxwidgets.org/stable/wx_wxstring.html#trim")
    ADD_CLASS_METHOD(Pad,"http://docs.wxwidgets.org/stable/wx_wxstring.html#pad")
    ADD_CLASS_METHOD(Find_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Find_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#find")
    ADD_CLASS_METHOD(Replace,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(Matches,"http://docs.wxwidgets.org/stable/wx_wxstring.html#matches")
    ADD_CLASS_METHOD(ToLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tolong")
    ADD_CLASS_METHOD(ToULong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toulong")
/* The following types are missing: long long int
    ADD_CLASS_METHOD(ToLongLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#tolonglong")
*/
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(ToULongLong,"http://docs.wxwidgets.org/stable/wx_wxstring.html#toulonglong")
*/
    ADD_CLASS_METHOD(ToDouble,"http://docs.wxwidgets.org/stable/wx_wxstring.html#todouble")
    ADD_CLASS_METHOD(Printf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#printf")
/* The following types are missing: __va_list_tag
    ADD_CLASS_METHOD(PrintfV,"http://docs.wxwidgets.org/stable/wx_wxstring.html#printfv")
*/
    ADD_CLASS_METHOD(Format,"http://docs.wxwidgets.org/stable/wx_wxstring.html#format")
/* The following types are missing: __va_list_tag
    ADD_CLASS_METHOD(FormatV,"http://docs.wxwidgets.org/stable/wx_wxstring.html#formatv")
*/
    ADD_CLASS_METHOD(Alloc,"http://docs.wxwidgets.org/stable/wx_wxstring.html#alloc")
    ADD_CLASS_METHOD(Shrink,"http://docs.wxwidgets.org/stable/wx_wxstring.html#shrink")
    ADD_CLASS_METHOD(GetWriteBuf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#getwritebuf")
    ADD_CLASS_METHOD(UngetWriteBuf_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf")
    ADD_CLASS_METHOD(UngetWriteBuf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf")
    ADD_CLASS_METHOD(UngetWriteBuf_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#ungetwritebuf")
    ADD_CLASS_METHOD(SubString,"http://docs.wxwidgets.org/stable/wx_wxstring.html#substring")
    ADD_CLASS_METHOD(sprintf,"http://docs.wxwidgets.org/stable/wx_wxstring.html#sprintf")
    ADD_CLASS_METHOD(Length,"http://docs.wxwidgets.org/stable/wx_wxstring.html#length")
    ADD_CLASS_METHOD(Freq,"http://docs.wxwidgets.org/stable/wx_wxstring.html#freq")
    ADD_CLASS_METHOD(LowerCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#lowercase")
    ADD_CLASS_METHOD(UpperCase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#uppercase")
    ADD_CLASS_METHOD(Index_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
    ADD_CLASS_METHOD(Index,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
    ADD_CLASS_METHOD(Index_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#index")
    ADD_CLASS_METHOD(Remove_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
    ADD_CLASS_METHOD(RemoveLast,"http://docs.wxwidgets.org/stable/wx_wxstring.html#removelast")
    ADD_CLASS_METHOD(Remove,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
    ADD_CLASS_METHOD(Remove_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#remove")
    ADD_CLASS_METHOD(First_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(First_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#first")
    ADD_CLASS_METHOD(Last_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#last")
    ADD_CLASS_METHOD(Contains,"http://docs.wxwidgets.org/stable/wx_wxstring.html#contains")
    ADD_CLASS_METHOD(IsNull,"http://docs.wxwidgets.org/stable/wx_wxstring.html#isnull")
    ADD_CLASS_METHOD(append_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(append_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#append")
    ADD_CLASS_METHOD(assign_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(assign_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#assign")
    ADD_CLASS_METHOD(insert_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(insert_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#insert")
    ADD_CLASS_METHOD(erase_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
    ADD_CLASS_METHOD(erase,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
    ADD_CLASS_METHOD(erase_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
    ADD_CLASS_METHOD(erase_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#erase")
    ADD_CLASS_METHOD(replace_1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_6,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_7,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_8,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_9,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")
    ADD_CLASS_METHOD(replace_10,"http://docs.wxwidgets.org/stable/wx_wxstring.html#replace")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#!")
    ADD_CLASS_METHOD(__at___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
    ADD_CLASS_METHOD(__at__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
    ADD_CLASS_METHOD(__at___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
    ADD_CLASS_METHOD(__at___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__at__")
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
/* The following types are missing: wxStringBase
    ADD_CLASS_METHOD(__assign___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
*/
    ADD_CLASS_METHOD(__assign___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    ADD_CLASS_METHOD(__assign___5,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__assign__")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    ADD_CLASS_METHOD(__add_assign___1,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
/* The following types are missing: long long int
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
/* The following types are missing: long long unsigned int
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
*/
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#<<")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxstring.html#()")
    ADD_CLASS_METHOD(__add_assign__,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___2,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___3,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")
    ADD_CLASS_METHOD(__add_assign___4,"http://docs.wxwidgets.org/stable/wx_wxstring.html#__add_assign__")




    void AddMethods(WrapClass<wxString>::ptr this_ptr )
    {
      /*
      // Add members from wxStringBase
      WrapClass_wxStringBase::ptr parent_wxStringBase(        boost::dynamic_pointer_cast<WrapClass_wxStringBase>(this_ptr));
      parent_wxStringBase->AddMethods(parent_wxStringBase);
      */


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Len( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_Truncate( this_ptr);
      AddVar_Empty( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_IsAscii( this_ptr);
      AddVar_IsNumber( this_ptr);
      AddVar_IsWord( this_ptr);
      AddVar_GetChar( this_ptr);
      AddVar_GetWritableChar( this_ptr);
      AddVar_SetChar( this_ptr);
      AddVar_Last_1( this_ptr);
      AddVar_Last( this_ptr);
      AddVar_Last_2( this_ptr);
      AddVar_wx_str( this_ptr);
      AddVar_GetData( this_ptr);
/* The following types are missing: wxWritableCharBuffer
      AddVar_char_str( this_ptr);
*/
/* The following types are missing: wxWritableWCharBuffer
      AddVar_wchar_str( this_ptr);
*/
      AddVar_FromAscii_1( this_ptr);
      AddVar_FromAscii( this_ptr);
      AddVar_FromAscii_2( this_ptr);
      AddVar_ToAscii( this_ptr);
      AddVar_FromUTF8_1( this_ptr);
      AddVar_FromUTF8( this_ptr);
      AddVar_FromUTF8_2( this_ptr);
      AddVar_utf8_str( this_ptr);
      AddVar_ToUTF8( this_ptr);
      AddVar_From8BitData_1( this_ptr);
      AddVar_From8BitData( this_ptr);
      AddVar_From8BitData_2( this_ptr);
      AddVar_To8BitData( this_ptr);
      AddVar_mb_str( this_ptr);
      AddVar_mbc_str( this_ptr);
      AddVar_wc_str_1( this_ptr);
      AddVar_wc_str( this_ptr);
      AddVar_wc_str_2( this_ptr);
      AddVar_fn_str( this_ptr);
      AddVar_Append_1( this_ptr);
      AddVar_Append( this_ptr);
      AddVar_Append_2( this_ptr);
      AddVar_Append_3( this_ptr);
      AddVar_Append_4( this_ptr);
      AddVar_Prepend( this_ptr);
      AddVar_Cmp_1( this_ptr);
      AddVar_Cmp( this_ptr);
      AddVar_Cmp_2( this_ptr);
      AddVar_CmpNoCase_1( this_ptr);
      AddVar_CmpNoCase( this_ptr);
      AddVar_CmpNoCase_2( this_ptr);
      AddVar_IsSameAs_1( this_ptr);
      AddVar_IsSameAs( this_ptr);
      AddVar_IsSameAs_2( this_ptr);
      AddVar_Mid( this_ptr);
      AddVar_StartsWith( this_ptr);
      AddVar_EndsWith( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_BeforeFirst( this_ptr);
      AddVar_BeforeLast( this_ptr);
      AddVar_AfterFirst( this_ptr);
      AddVar_AfterLast( this_ptr);
      AddVar_Before( this_ptr);
      AddVar_After( this_ptr);
      AddVar_MakeUpper( this_ptr);
      AddVar_Upper( this_ptr);
      AddVar_MakeLower( this_ptr);
      AddVar_Lower( this_ptr);
      AddVar_Trim( this_ptr);
      AddVar_Pad( this_ptr);
      AddVar_Find_1( this_ptr);
      AddVar_Find( this_ptr);
      AddVar_Find_2( this_ptr);
      AddVar_Replace( this_ptr);
      AddVar_Matches( this_ptr);
      AddVar_ToLong( this_ptr);
      AddVar_ToULong( this_ptr);
/* The following types are missing: long long int
      AddVar_ToLongLong( this_ptr);
*/
/* The following types are missing: long long unsigned int
      AddVar_ToULongLong( this_ptr);
*/
      AddVar_ToDouble( this_ptr);
      AddVar_Printf( this_ptr);
/* The following types are missing: __va_list_tag
      AddVar_PrintfV( this_ptr);
*/
      AddVar_Format( this_ptr);
/* The following types are missing: __va_list_tag
      AddVar_FormatV( this_ptr);
*/
      AddVar_Alloc( this_ptr);
      AddVar_Shrink( this_ptr);
      AddVar_GetWriteBuf( this_ptr);
      AddVar_UngetWriteBuf_1( this_ptr);
      AddVar_UngetWriteBuf( this_ptr);
      AddVar_UngetWriteBuf_2( this_ptr);
      AddVar_SubString( this_ptr);
      AddVar_sprintf( this_ptr);
      AddVar_Length( this_ptr);
      AddVar_Freq( this_ptr);
      AddVar_LowerCase( this_ptr);
      AddVar_UpperCase( this_ptr);
      AddVar_Index_1( this_ptr);
      AddVar_Index( this_ptr);
      AddVar_Index_2( this_ptr);
      AddVar_Remove_1( this_ptr);
      AddVar_RemoveLast( this_ptr);
      AddVar_Remove( this_ptr);
      AddVar_Remove_2( this_ptr);
      AddVar_First_1( this_ptr);
      AddVar_First( this_ptr);
      AddVar_First_2( this_ptr);
      AddVar_First_3( this_ptr);
      AddVar_Last_3( this_ptr);
      AddVar_Contains( this_ptr);
      AddVar_IsNull( this_ptr);
      AddVar_append_1( this_ptr);
      AddVar_append( this_ptr);
      AddVar_append_2( this_ptr);
      AddVar_append_3( this_ptr);
      AddVar_append_4( this_ptr);
      AddVar_append_5( this_ptr);
      AddVar_append_6( this_ptr);
      AddVar_assign_1( this_ptr);
      AddVar_assign( this_ptr);
      AddVar_assign_2( this_ptr);
      AddVar_assign_3( this_ptr);
      AddVar_assign_4( this_ptr);
      AddVar_assign_5( this_ptr);
      AddVar_assign_6( this_ptr);
      AddVar_insert_1( this_ptr);
      AddVar_insert( this_ptr);
      AddVar_insert_2( this_ptr);
      AddVar_insert_3( this_ptr);
      AddVar_insert_4( this_ptr);
      AddVar_insert_5( this_ptr);
      AddVar_insert_6( this_ptr);
      AddVar_insert_7( this_ptr);
      AddVar_insert_8( this_ptr);
      AddVar_erase_1( this_ptr);
      AddVar_erase( this_ptr);
      AddVar_erase_2( this_ptr);
      AddVar_erase_3( this_ptr);
      AddVar_replace_1( this_ptr);
      AddVar_replace( this_ptr);
      AddVar_replace_2( this_ptr);
      AddVar_replace_3( this_ptr);
      AddVar_replace_4( this_ptr);
      AddVar_replace_5( this_ptr);
      AddVar_replace_6( this_ptr);
      AddVar_replace_7( this_ptr);
      AddVar_replace_8( this_ptr);
      AddVar_replace_9( this_ptr);
      AddVar_replace_10( this_ptr);

      // Adding operators
      AddVar___assign___1( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___at___1( this_ptr);
      AddVar___at__( this_ptr);
      AddVar___at___2( this_ptr);
      AddVar___at___3( this_ptr);
      AddVar___assign__( this_ptr);
/* The following types are missing: wxStringBase
      AddVar___assign___2( this_ptr);
*/
      AddVar___assign___3( this_ptr);
      AddVar___assign___4( this_ptr);
      AddVar___assign___5( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___add_assign___1( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
/* The following types are missing: long long int
      // AddVar_operator not available( this_ptr);
*/
/* The following types are missing: long long unsigned int
      // AddVar_operator not available( this_ptr);
*/
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar___add_assign__( this_ptr);
      AddVar___add_assign___2( this_ptr);
      AddVar___add_assign___3( this_ptr);
      AddVar___add_assign___4( this_ptr);



      
    };
};


#endif // _wrap_wxString_h
