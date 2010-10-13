//
// C++ Interface: wrap_wxSizer
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxSizer_h_
#define _wrap_wxSizer_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>

#include <wx/image.h>

AMI_DECLARE_TYPE(wxSizer)

class WrapClass_wxSizer : public WrapClass<wxSizer>
{
  DEFINE_CLASS(WrapClass_wxSizer);


  public:

    /// Constructor
    WrapClass_wxSizer(boost::shared_ptr<wxSizer> val): WrapClass<wxSizer>(val)
    {}

/*
    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizer*);
*/

    ADD_CLASS_CONSTRUCTOR( wxSizer, "Wrapping of wxSizer (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(Add1,    "Adds a wxWindow to the sizer, using wxSizerFlags.");
    ADD_CLASS_METHOD(Add2,    "Adds a wxWindow to the sizer, using proportion, flag, border and user data.");
    ADD_CLASS_METHOD(Add3,    "Adds a wxSizer to the sizer, using wxSizerFlags.");
    ADD_CLASS_METHOD(Add4,    "Adds a wxSizer to the sizer, using proportion, flag, border and user data.");
    ADD_CLASS_METHOD(Add5,    "Adds a spacer.");
    ADD_CLASS_METHOD(Add,     "Adds an element to the sizer using one of the Add1-Add5 methods.");


    void AddMethods( WrapClass<wxSizer>::ptr this_ptr ) {
      AddVar_Add1(       this_ptr);
      AddVar_Add2(       this_ptr);
      AddVar_Add3(       this_ptr);
      AddVar_Add4(       this_ptr);
      AddVar_Add5(       this_ptr);
      AddVar_Add (       this_ptr);
    }

};


#endif // _wrap_wxSizer_h_
