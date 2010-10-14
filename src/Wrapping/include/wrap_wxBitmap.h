//
// C++ Interface: wrap_wxBitmap
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxBitmap_h_
#define _wrap_wxBitmap_h_

#ifdef _AMIPREC_
  #include "WrapWxWidgets_header.h"
#else
  #include "wrapfunction_class.h"
  #include "Variable.hpp"
  #include "paramlist.h"
  #include "ami_object.h"
  #include <wx/bitmap.h>
#endif

AMI_DECLARE_TYPE(wxBitmap)


class WrapClass_wxBitmap : public WrapClass<wxBitmap>
{
  DEFINE_CLASS(WrapClass_wxBitmap);


  public:

    /// Constructor
    WrapClass_wxBitmap(boost::shared_ptr<wxBitmap> val): WrapClass<wxBitmap>(val)
    {}

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmap*);

    ADD_CLASS_CONSTRUCTOR( wxBitmap, "Wrapping of wxBitmap (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(GetWidth,     "Gets the width of the bitmap in pixels.");
    ADD_CLASS_METHOD(GetHeight,    "Gets the height of the bitmap in pixels.");
    ADD_CLASS_METHOD(IsOk,         "Returns true if bitmap data is present.");
    ADD_CLASS_METHOD(copy,         "Bitmap copy constructor.");

    void AddMethods( WrapClass<wxBitmap>::ptr this_ptr ) {
      AddVar_GetWidth(    this_ptr);
      AddVar_GetHeight(   this_ptr);
      AddVar_IsOk(        this_ptr);
      AddVar_copy(        this_ptr);
    }

};



#endif // _wrap_wxBitmap_h_
