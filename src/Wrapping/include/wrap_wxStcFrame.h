//
// C++ Interface: wrap_wxStcFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxStcFrame_h_
#define _wrap_wxStcFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxFrame.h"

#include "wxStcFrame.h"

AMI_DECLARE_TYPE(wxStcFrame)

class WrapClass_wxStcFrame : public WrapClass<wxStcFrame>, public WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_wxStcFrame);

  protected:
    // for nested classes
    typedef WrapClass<wxStcFrame>::ptr _parentclass_ptr;
    typedef wxStcFrame ObjectType;

  public:

    /// Constructor
    WrapClass_wxStcFrame(boost::shared_ptr<wxStcFrame> si):  WrapClass<wxStcFrame>(si), WrapClass_wxFrame(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStcFrame, "Wrapping of wxStcFrame." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStcFrame*);

    ADD_CLASS_METHOD(GetActiveEditor,   "Gets the active editor window as a wxEditor object.");
    ADD_CLASS_METHOD(FileOpen,          "Opens the given file.");

    void AddMethods(WrapClass<wxStcFrame>::ptr this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_GetActiveEditor(  this_ptr);
      AddVar_FileOpen(         this_ptr);
    }

};


#endif // _wrap_wxStcFrame_h_
