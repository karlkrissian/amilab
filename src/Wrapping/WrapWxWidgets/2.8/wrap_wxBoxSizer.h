//
// C++ Interface: wrap_wxBoxSizer
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxBoxSizer_h_
#define _wrap_wxBoxSizer_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include <wx/sizer.h>

#include "wrap_wxSizer.h"

AMI_DECLARE_TYPE(wxBoxSizer);

class WrapClass_wxBoxSizer : public WrapClass<wxBoxSizer>, public WrapClass_wxSizer
{
  DEFINE_CLASS(WrapClass_wxBoxSizer);

  protected:
    // for nested classes
    typedef WrapClass<wxBoxSizer>::ptr _parentclass_ptr;
    typedef wxBoxSizer ObjectType;

  public:

    /// Constructor
    WrapClass_wxBoxSizer(boost::shared_ptr<wxBoxSizer> val): WrapClass<wxBoxSizer>(val), WrapClass_wxSizer(val)
    {}

/*
    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBoxSizer*);
*/

    ADD_CLASS_CONSTRUCTOR( wxBoxSizer, "Wrapping of wxBoxSizer (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(GetOrientation,"Returns the box sizer orientation.");

    void AddMethods( WrapClass<wxBoxSizer>::ptr this_ptr ) {

      // Add members from wxSizer
      WrapClass_wxSizer::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxSizer>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_GetOrientation(       this_ptr);
    }

};


#endif // _wrap_wxBoxSizer_h_
