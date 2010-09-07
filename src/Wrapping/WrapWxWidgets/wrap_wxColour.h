//
// C++ Interface: wrap_wxColour
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxColour_h_
#define _wrap_wxColour_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include <wx/colour.h>

AMI_DECLARE_TYPE(wxColour)

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxColour>::CreateVar( ParamList* p);


class WrapClass_wxColour : public WrapClass<wxColour>
{
  DEFINE_CLASS(WrapClass_wxColour);

  public:

    /// Constructor
    WrapClass_wxColour(boost::shared_ptr<wxColour> sp): 
      WrapClass<wxColour>(sp) { }

/*
    /// Create a variable from a standard pointer
     static Variable<AMIObject>::ptr CreateVar( wxColour* sp);
*/

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( wxColour,  "Wrapping of wxColour (see http://docs.wxwidgets.org/).");

    ADD_CLASS_METHOD(Alpha,       "Returns the alpha value, on platforms where alpha is not yet supported, this always returns wxALPHA_OPAQUE.");
    ADD_CLASS_METHOD(Blue,        "Returns the blue intensity.");
    ADD_CLASS_METHOD(GetAsString, "Converts this colour to a wxString using the given flags.The supported flags are wxC2S_NAME, to obtain the colour name (e.g. wxColour(255,0,0) -> \"red\"), wxC2S_CSS_SYNTAX, to obtain the colour in the \"rgb(r,g,b)\" syntax (e.g. wxColour(255,0,0) -> \"rgb(255,0,0)\"), and wxC2S_HTML_SYNTAX, to obtain the colour as \"#\" followed by 6 hexadecimal digits (e.g. wxColour(255,0,0) -> \"#FF0000\").This function never fails and always returns a non-empty string.");
    ADD_CLASS_METHOD(GetPixel,    "Returns a pixel value which is platform-dependent. On Windows, a COLORREF is returned. On X, an allocated pixel value is returned. -1 is returned if the pixel is invalid (on X, unallocated).");
    ADD_CLASS_METHOD(Green,       "Returns the green intensity.");
    ADD_CLASS_METHOD(IsOk,        "Returns true if the colour object is valid (the colour has been initialised with RGB values).");
    ADD_CLASS_METHOD(Red,         "Returns the red intensity.");
    ADD_CLASS_METHOD(Set,         "Sets the RGB intensity values using the given values (first overload), extracting them from the packed long (second overload), using the given string (third overloard). When using third form, Set() accepts: colour names (those listed in wxTheColourDatabase), the CSS-like \"RGB(r,g,b)\" syntax (case insensitive) and the HTML-like syntax (i.e. \"#\" followed by 6 hexadecimal digits for red, green, blue components).Returns true if the conversion was successful, false otherwise.");
    ADD_CLASS_METHOD(copy,        "Copy constructor.");
    ADD_CLASS_METHOD(assign,    "assign operation.");

    void AddMethods(WrapClass<wxColour>::ptr this_ptr )
    {
      AddVar_Alpha(       this_ptr);
      AddVar_Blue(        this_ptr);
      AddVar_GetAsString( this_ptr);
      AddVar_GetPixel(    this_ptr);
      AddVar_Green(       this_ptr);
      AddVar_IsOk(        this_ptr);
      AddVar_Red(         this_ptr);
      AddVar_Set(         this_ptr);
      AddVar_copy(        this_ptr);
      AddVar_assign(      this_ptr);
    }

};

#endif // _wrap_wxColour_h_
