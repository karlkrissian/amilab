//
// C++ Interface: wrap_wxSizerItem
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxSizerItem_h_
#define _wrap_wxSizerItem_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

#include <wx/sizer.h>

class WrapClass_wxSizerItem : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxSizerItem);

  // for nested classes
  typedef WrapClass_wxSizerItem::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxSizerItem> _sizeritem;

    /// Constructor
    WrapClass_wxSizerItem(boost::shared_ptr<wxSizerItem> si): _sizeritem(si)
    {}

    
    ADD_CLASS_METHOD(GetMinSize,  "Get the minimum size needed for the item.");
    ADD_CLASS_METHOD(SetProportion,  "Set the proportion item attribute.");
    ADD_CLASS_METHOD(SetDimension,  "Set the position and size of the space allocated to the sizer, and adjust the position and size of the item to be within that space taking alignment and borders into account.");

};

/**
 * Create a Wrapped object around wxSizerItem
 * @param objectptr input smart pointer to a WrapClass_wxSizerItem
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxSizerItem(  WrapClass_wxSizerItem::ptr& objectptr);

/**
 * Create a Wrapped object around wxSizerItem
 * @param si_ptr input smart pointer to a wxSizerItem
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxSizerItem(  wxSizerItem* si);

/** function that add wrapping of the Image Drawing window
 */
//BasicVariable::ptr wrap_wxSizerItem( ParamList* p);


#endif // _wrap_wxSizerItem_h_
