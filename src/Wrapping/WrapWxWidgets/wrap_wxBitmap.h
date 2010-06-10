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

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

#include <wx/bitmap.h>


class WrapClass_wxBitmap : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxBitmap);

  // for nested classes
  typedef WrapClass_wxBitmap::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxBitmap> _obj;

    /// Constructor
    WrapClass_wxBitmap(boost::shared_ptr<wxBitmap> val): _obj(val)
    {}

    ADD_CLASS_METHOD(GetWidth,     "Gets the width of the bitmap in pixels.");
    ADD_CLASS_METHOD(GetHeight,    "Gets the height of the bitmap in pixels.");
    ADD_CLASS_METHOD(IsOk,         "Returns true if bitmap data is present.");

    ADD_CLASS_METHOD(copy,         "Bitmap copy constructor.");

    void AddMethods( _parentclass_ptr& this_ptr ) {
      AddVar_GetWidth(       this_ptr);
      AddVar_GetHeight(      this_ptr);
      AddVar_IsOk(        this_ptr);
      AddVar_copy(        this_ptr);
    }

};

/**
 * Create a Wrapped object around _wxBitmap
 * @param objectptr input smart pointer to a WrapClass_wxBitmap
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxBitmap(  WrapClass_wxBitmap::ptr& objectptr);

/**
 * Create a Wrapped object around _wxBitmap
 * @param si_ptr input smart pointer to a _wxBitmap
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxBitmap( wxBitmap* si);

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxBitmap( ParamList* p);


#endif // _wrap_wxBitmap_h_
