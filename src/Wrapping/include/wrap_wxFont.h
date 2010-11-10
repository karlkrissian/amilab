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
    ADD_CLASS_CONSTRUCTOR(wxFont,"Wrapping of wxFont.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont1,"Wrapping of wxFont.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont2,"Wrapping of wxFont.");
    /* The following types are missing: wxNativeFontInfo
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont3,"Wrapping of wxFont.");
    */
    /* The following types are missing: wxFontEncoding
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFont4,"Wrapping of wxFont.");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFont*);

    // here add each method
    
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(Create,"")
*/
    ADD_CLASS_METHOD(Create1,"")
    ADD_CLASS_METHOD(GetPointSize,"")
    ADD_CLASS_METHOD(GetFamily,"")
    ADD_CLASS_METHOD(GetStyle,"")
    ADD_CLASS_METHOD(GetWeight,"")
    ADD_CLASS_METHOD(GetFaceName,"")
    ADD_CLASS_METHOD(GetUnderlined,"")
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(GetEncoding,"")
*/
/* The following types are missing: wxNativeFontInfo
    ADD_CLASS_METHOD(GetNativeFontInfo,"")
*/
    ADD_CLASS_METHOD(IsFixedWidth,"")
    ADD_CLASS_METHOD(SetPointSize,"")
    ADD_CLASS_METHOD(SetFamily,"")
    ADD_CLASS_METHOD(SetStyle,"")
    ADD_CLASS_METHOD(SetWeight,"")
    ADD_CLASS_METHOD(SetFaceName,"")
    ADD_CLASS_METHOD(SetUnderlined,"")
/* The following types are missing: wxFontEncoding
    ADD_CLASS_METHOD(SetEncoding,"")
*/
    ADD_CLASS_METHOD(SetNoAntiAliasing,"")
    ADD_CLASS_METHOD(GetNoAntiAliasing,"")
    ADD_CLASS_METHOD(Unshare,"")
    ADD_CLASS_METHOD(GetClassInfo,"")
    ADD_CLASS_METHOD(wxCreateObject,"")

    // Operators:
    ADD_CLASS_METHOD(assign,"")




    void AddMethods(WrapClass<wxFont>::ptr this_ptr )
    {
      // here inheritence
      /*
      // Add members from wxFontBase
      WrapClass_wxFontBase::ptr parent_wxFontBase(        boost::dynamic_pointer_cast<WrapClass_wxFontBase>(this_ptr));
      parent_wxFontBase->AddMethods(parent_wxFontBase);
      */


      // check that the method name is not a token
      
/* The following types are missing: wxFontEncoding
      AddVar_Create( this_ptr);
*/
      AddVar_Create1( this_ptr);
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

      // Operators:
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxFont_h
