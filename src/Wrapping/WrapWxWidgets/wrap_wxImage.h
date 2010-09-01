//
// C++ Interface: wrap_wxImage
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxImage_h_
#define _wrap_wxImage_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

#include <wx/image.h>

AMI_DECLARE_TYPE(wxImage)

class WrapClass_wxImage : public WrapClass<wxImage>
{
  DEFINE_CLASS(WrapClass_wxImage);


  public:

    /// Constructor
    WrapClass_wxImage(boost::shared_ptr<wxImage> val): WrapClass<wxImage>(val)
    {}

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImage*);

    ADD_CLASS_CONSTRUCTOR( wxImage, "Wrapping of wxImage (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(GetWidth,     "Gets the width of the image in pixels.");
    ADD_CLASS_METHOD(GetHeight,    "Gets the height of the image in pixels.");
    ADD_CLASS_METHOD(IsOk,         "Returns true if image data is present.");
    ADD_CLASS_METHOD(Scale2,        "Returns a scaled version of the image.");
    ADD_CLASS_METHOD(SaveFile,     "Saves an image in the named file. File type is determined from the extension of the file name.");


    void AddMethods( WrapClass<wxImage>::ptr this_ptr ) {
      AddVar_GetWidth(       this_ptr);
      AddVar_GetHeight(      this_ptr);
      AddVar_IsOk(           this_ptr);
      AddVar_Scale2(         this_ptr);
      AddVar_SaveFile(       this_ptr);
    }

};


#endif // _wrap_wxImage_h_
