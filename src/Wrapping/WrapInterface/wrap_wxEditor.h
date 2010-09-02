//
// C++ Interface: wrap_wxEditor
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxEditor_h_
#define _wrap_wxEditor_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxWindow.h"

#include "wxEditor.h"

AMI_DECLARE_TYPE(wxEditor)

class WrapClass_wxEditor : public WrapClass<wxEditor>, public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxEditor);

  protected: 
    // for nested classes
    typedef WrapClass<wxEditor>::ptr _parentclass_ptr;

  public:
    /// Constructor
    WrapClass_wxEditor(boost::shared_ptr<wxEditor> si):  WrapClass<wxEditor>(si), WrapClass_wxWindow(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxEditor, "Wrapping of wxEditor." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxEditor*);

    ADD_CLASS_METHOD(LoadFile,          "Loads a file in the editor.");
    ADD_CLASS_METHOD(ShowLineNumbers,   "Shows/Hides line numbers.");

    void AddMethods(WrapClass<wxEditor>::ptr this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_LoadFile(         this_ptr);
      AddVar_ShowLineNumbers(  this_ptr);
    }

};



#endif // _wrap_wxEditor_h_
