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

AMI_DECLARE_TYPE(wxSizerItem)

class WrapClass_wxSizerItem : public WrapClass<wxSizerItem>
{
  DEFINE_CLASS(WrapClass_wxSizerItem);

  public:

    /// Constructor
    WrapClass_wxSizerItem(boost::shared_ptr<wxSizerItem> si): WrapClass<wxSizerItem>(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerItem, "Wrapping of wxSizerItem (see http://docs.wxwidgets.org/)." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizerItem* sp);

    
    ADD_CLASS_METHOD(GetMinSize,  "Get the minimum size needed for the item.");
    ADD_CLASS_METHOD(SetProportion,  "Set the proportion item attribute.");
    ADD_CLASS_METHOD(SetDimension,  "Set the position and size of the space allocated to the sizer, and adjust the position and size of the item to be within that space taking alignment and borders into account.");

    void AddMethods(WrapClass<wxSizerItem>::ptr this_ptr )
    {
       AddVar_GetMinSize(    this_ptr);
       AddVar_SetProportion( this_ptr);
       AddVar_SetDimension(  this_ptr);
   }

};



#endif // _wrap_wxSizerItem_h_
