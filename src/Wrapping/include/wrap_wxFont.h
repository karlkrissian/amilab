/**
 * C++ Interface: wrap_wxFont
 *
 * Description: wrapping wxFont
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFont_h_
#define _wrap_wxFont_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxFontBase.h"


AMI_DECLARE_TYPE(wxFont);

// TODO: check for inheritence ...
class WrapClass_wxFont : public WrapClass<wxFont>
    //, public virtual WrapClass_wxFontBase
{
  DEFINE_CLASS(WrapClass_wxFont);

  protected:
    typedef WrapClass<wxFont>::ptr _parentclass_ptr;
    typedef wxFont ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFont>& GetObj() const { return WrapClass<wxFont>::GetObj(); }

    /// Constructor
    WrapClass_wxFont(boost::shared_ptr<wxFont > si): 
    WrapClass<wxFont>(si)
    //, WrapClass_wxFontBase(si)
    {}

    /// Destructor
    ~WrapClass_wxFont()
    {
      std::cout << "~WrapClass_wxFont()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont1,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont2,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont3,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    /* The following types are missing: wxNativeFontInfo
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont4,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    */
    /* The following types are missing: wxFontEncoding
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont5,"Wrapping of wxFont, http://docs.wxwidgets.org/stable/wx_wxfont.html#wxfont.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFont*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(Create1,"http://docs.wxwidgets.org/stable/wx_wxfont.html#create")
*/
    ADD_CLASS_METHOD(Create,"http://docs.wxwidgets.org/stable/wx_wxfont.html#create")
    ADD_CLASS_METHOD(Create2,"http://docs.wxwidgets.org/stable/wx_wxfont.html#create")
    ADD_CLASS_METHOD(GetPointSize,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getpointsize")
    ADD_CLASS_METHOD(GetFamily,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getfamily")
    ADD_CLASS_METHOD(GetStyle,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getstyle")
    ADD_CLASS_METHOD(GetWeight,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getweight")
    ADD_CLASS_METHOD(GetFaceName,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getfacename")
    ADD_CLASS_METHOD(GetUnderlined,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getunderlined")
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(GetEncoding,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getencoding")
*/
/* The following types are missing: wxNativeFontInfo
    ADD_CLASS_METHOD(GetNativeFontInfo,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getnativefontinfo")
*/
    ADD_CLASS_METHOD(IsFixedWidth,"http://docs.wxwidgets.org/stable/wx_wxfont.html#isfixedwidth")
    ADD_CLASS_METHOD(SetPointSize,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setpointsize")
    ADD_CLASS_METHOD(SetFamily,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setfamily")
    ADD_CLASS_METHOD(SetStyle,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setstyle")
    ADD_CLASS_METHOD(SetWeight,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setweight")
    ADD_CLASS_METHOD(SetFaceName,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setfacename")
    ADD_CLASS_METHOD(SetUnderlined,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setunderlined")
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(SetEncoding,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setencoding")
*/
    ADD_CLASS_METHOD(SetNoAntiAliasing,"http://docs.wxwidgets.org/stable/wx_wxfont.html#setnoantialiasing")
    ADD_CLASS_METHOD(GetNoAntiAliasing,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getnoantialiasing")
    ADD_CLASS_METHOD(Unshare,"http://docs.wxwidgets.org/stable/wx_wxfont.html#unshare")
    ADD_CLASS_METHOD(GetClassInfo,"http://docs.wxwidgets.org/stable/wx_wxfont.html#getclassinfo")
    ADD_CLASS_METHOD(wxCreateObject,"http://docs.wxwidgets.org/stable/wx_wxfont.html#wxcreateobject")

    // Operators:
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxfont.html#assign")




    void AddMethods(WrapClass<wxFont>::ptr this_ptr )
    {
      // here inheritence
      /*
      // Add members from wxFontBase
      WrapClass_wxFontBase::ptr parent_wxFontBase(        boost::dynamic_pointer_cast<WrapClass_wxFontBase>(this_ptr));
      parent_wxFontBase->AddMethods(parent_wxFontBase);
      */


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
       // Adding standard methods 
/* The following types are missing: wxFontEncoding
      AddVar_Create1( this_ptr);
*/
      AddVar_Create( this_ptr);
      AddVar_Create2( this_ptr);
      AddVar_GetPointSize( this_ptr);
      AddVar_GetFamily( this_ptr);
      AddVar_GetStyle( this_ptr);
      AddVar_GetWeight( this_ptr);
      AddVar_GetFaceName( this_ptr);
      AddVar_GetUnderlined( this_ptr);
/* The following types are missing: wxFontEncoding
      AddVar_GetEncoding( this_ptr);
*/
/* The following types are missing: wxNativeFontInfo
      AddVar_GetNativeFontInfo( this_ptr);
*/
      AddVar_IsFixedWidth( this_ptr);
      AddVar_SetPointSize( this_ptr);
      AddVar_SetFamily( this_ptr);
      AddVar_SetStyle( this_ptr);
      AddVar_SetWeight( this_ptr);
      AddVar_SetFaceName( this_ptr);
      AddVar_SetUnderlined( this_ptr);
/* The following types are missing: wxFontEncoding
      AddVar_SetEncoding( this_ptr);
*/
      AddVar_SetNoAntiAliasing( this_ptr);
      AddVar_GetNoAntiAliasing( this_ptr);
      AddVar_Unshare( this_ptr);
      AddVar_GetClassInfo( this_ptr);
      AddVar_wxCreateObject( this_ptr);

      // Adding operators
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxFont_h
