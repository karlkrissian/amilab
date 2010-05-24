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

class WrapClass_wxImage : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxImage);

  // for nested classes
  typedef WrapClass_wxImage::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxImage> _obj;

    /// Constructor
    WrapClass_wxImage(boost::shared_ptr<wxImage> val): _obj(val)
    {}

    ADD_CLASS_METHOD(GetWidth,     "Gets the width of the image in pixels.");
    ADD_CLASS_METHOD(GetHeight,    "Gets the height of the image in pixels.");
    ADD_CLASS_METHOD(IsOk,         "Returns true if image data is present.");
    ADD_CLASS_METHOD(Scale2,        "Returns a scaled version of the image.");
    ADD_CLASS_METHOD(SaveFile,     "Saves an image in the named file. File type is determined from the extension of the file name.");


    void AddMethods( _parentclass_ptr& this_ptr ) {
      AddVar_GetWidth(       this_ptr);
      AddVar_GetHeight(      this_ptr);
      AddVar_IsOk(           this_ptr);
      AddVar_Scale2(         this_ptr);
      AddVar_SaveFile(       this_ptr);
    }

};

/**
 * Create a Wrapped object around _wxImage
 * @param objectptr input smart pointer to a WrapClass_wxImage
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxImage(  WrapClass_wxImage::ptr& objectptr);

/**
 * Create a Wrapped object around _wxImage
 * @param si_ptr input smart pointer to a _wxImage
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxImage( wxImage* si);

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxImage( ParamList* p);


#endif // _wrap_wxImage_h_
