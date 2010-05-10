//
// C++ Interface: wrap_wxSize
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxSize_h_
#define _wrap_wxSize_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

#include <wx/sizer.h>

class WrapClass_wxSize : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxSize);

  // for nested classes
  typedef WrapClass_wxSize::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxSize> _size;

    /// Constructor
    WrapClass_wxSize(boost::shared_ptr<wxSize> si): _size(si)
    {}

    ADD_CLASS_METHOD(GetWidth,    "Gets the width member.");
    ADD_CLASS_METHOD(GetHeight,   "Gets the height member.");
    ADD_CLASS_METHOD(Set,         "Sets the width and height members.");
    ADD_CLASS_METHOD(SetWidth,    "Sets the width.");
    ADD_CLASS_METHOD(SetHeight,   "Sets the height.");

};

/**
 * Create a Wrapped object around _wxSize
 * @param objectptr input smart pointer to a WrapClass_wxSize
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxSize(  WrapClass_wxSize::ptr& objectptr);

/**
 * Create a Wrapped object around _wxSize
 * @param si_ptr input smart pointer to a _wxSize
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxSize( wxSize* si);

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxSize( ParamList* p);


#endif // _wrap_wxSize_h_
