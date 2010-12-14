/**
 * C++ Interface: wrap_wxPalette
 *
 * Description: wrapping wxPalette
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPalette_h_
#define _wrap_wxPalette_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxPaletteBase.h"


#ifndef wxPalette_declared
  #define wxPalette_declared
  AMI_DECLARE_TYPE(wxPalette);
#endif

// TODO: check for inheritence ...
class WrapClass_wxPalette : public WrapClass<wxPalette>
    , public   WrapClass_wxPaletteBase
{
  DEFINE_CLASS(WrapClass_wxPalette);

  protected:
    typedef WrapClass<wxPalette>::ptr _parentclass_ptr;
    typedef wxPalette ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPalette>& GetObj() const { return WrapClass<wxPalette>::GetObj(); }

    /// Constructor
    WrapClass_wxPalette(boost::shared_ptr<wxPalette > si): 
    WrapClass<wxPalette>(si)
    , WrapClass_wxPaletteBase(si)
    {}

    /// Destructor
    ~WrapClass_wxPalette()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPalette_1,"Constructor wxPalette::wxPalette(wxPalette const & param0) (http://docs.wxwidgets.org/stable/wx_wxpalette.html#wxpalette).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPalette,"Constructor wxPalette::wxPalette() (http://docs.wxwidgets.org/stable/wx_wxpalette.html#wxpalette).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPalette_2,"Constructor wxPalette::wxPalette() (http://docs.wxwidgets.org/stable/wx_wxpalette.html#wxpalette).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPalette_3,"Constructor wxPalette::wxPalette(int n, unsigned char const * red, unsigned char const * green, unsigned char const * blue) (http://docs.wxwidgets.org/stable/wx_wxpalette.html#wxpalette).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPalette*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxPalette::Ok()  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxPalette::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#isok)")
    ADD_CLASS_METHOD(Create,"bool wxPalette::Create(int n, unsigned char const * red, unsigned char const * green, unsigned char const * blue)  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#create)")
    ADD_CLASS_METHOD(GetPixel,"int wxPalette::GetPixel(unsigned char red, unsigned char green, unsigned char blue)  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#getpixel)")
    ADD_CLASS_METHOD(GetRGB,"bool wxPalette::GetRGB(int pixel, unsigned char * red, unsigned char * green, unsigned char * blue)  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#getrgb)")
    ADD_CLASS_METHOD(GetColoursCount,"int wxPalette::GetColoursCount()  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#getcolourscount)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxPalette::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxpalette.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPalette & wxPalette::operator =(wxPalette const & param0) (http://docs.wxwidgets.org/stable/wx_wxpalette.html#__assign__)")




    void AddMethods(WrapClass<wxPalette>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPalette_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxPalette_h
