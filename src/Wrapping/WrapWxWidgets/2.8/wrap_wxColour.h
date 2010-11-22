/**
 * C++ Interface: wrap_wxColour
 *
 * Description: wrapping wxColour
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxColour_h_
#define _wrap_wxColour_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxColourBase.h"


AMI_DECLARE_TYPE(wxColour);

// TODO: check for inheritence ...
class WrapClass_wxColour : public WrapClass<wxColour>
    , public   WrapClass_wxColourBase
{
  DEFINE_CLASS(WrapClass_wxColour);

  protected:
    typedef WrapClass<wxColour>::ptr _parentclass_ptr;
    typedef wxColour ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxColour>& GetObj() const { return WrapClass<wxColour>::GetObj(); }

    /// Constructor
    WrapClass_wxColour(boost::shared_ptr<wxColour > si): 
    WrapClass<wxColour>(si)
    , WrapClass_wxColourBase(si)
    {}

    /// Destructor
    ~WrapClass_wxColour()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_1,"Constructor wxColour::wxColour(wxColour const & param0) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour,"Constructor wxColour::wxColour() (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_2,"Constructor wxColour::wxColour() (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_3,"Constructor wxColour::wxColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = wxALPHA_OPAQUE) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_4,"Constructor wxColour::wxColour(long unsigned int colRGB) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_5,"Constructor wxColour::wxColour(wxString const & colourName) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_6,"Constructor wxColour::wxColour(wxChar const * colourName) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    /* The following types are missing: _GdkColor
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxColour_7,"Constructor wxColour::wxColour(GdkColor const & gdkColor) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#wxcolour).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxColour*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxColour::Ok()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxColour::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#isok)")
    ADD_CLASS_METHOD(Red,"unsigned char wxColour::Red()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#red)")
    ADD_CLASS_METHOD(Green,"unsigned char wxColour::Green()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#green)")
    ADD_CLASS_METHOD(Blue,"unsigned char wxColour::Blue()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#blue)")
    ADD_CLASS_METHOD(Alpha,"unsigned char wxColour::Alpha()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#alpha)")
/* The following types are missing: _GdkColormap
    ADD_CLASS_METHOD(CalcPixel,"void wxColour::CalcPixel(GdkColormap * cmap)  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#calcpixel)")
*/
    ADD_CLASS_METHOD(GetPixel,"int wxColour::GetPixel()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#getpixel)")
/* The following types are missing: _GdkColor
    ADD_CLASS_METHOD(GetColor,"GdkColor const * wxColour::GetColor()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#getcolor)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxColour::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxcolour.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxColour & wxColour::operator =(wxColour const & param0) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxColour::operator ==(wxColour const & col) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxColour::operator !=(wxColour const & col) (http://docs.wxwidgets.org/stable/wx_wxcolour.html#__not_equal__)")




    void AddMethods(WrapClass<wxColour>::ptr this_ptr );

};


#endif // _wrap_wxColour_h
