//
// C++ Interface: wrap_MainFrame
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_MainFrame_h_
#define _wrap_MainFrame_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include "wrap_wxFrame.h"

#include "MainFrame.h"
//class MainFrame;

AMI_DECLARE_TYPE(MainFrame);

class WrapClass_MainFrame : public WrapClass<MainFrame>, public WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_MainFrame);

  protected:  
    // needed to resolve ambiguity from multiple inheritance
    typedef boost::shared_ptr<WrapClass<MainFrame> > _parentclass_ptr;
    typedef MainFrame ObjectType;

  public:

    /// Constructor
    WrapClass_MainFrame(boost::shared_ptr<MainFrame> si): WrapClass<MainFrame>(si), WrapClass_wxFrame(si)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(MainFrame, "Wrapping of MainFrame (this object cannot be constructed from scratch)." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( MainFrame*);


    ADD_CLASS_METHOD(GetAmilabEditor,  "Opens or get the amilab editor frame.");
    ADD_CLASS_METHOD(AddMenuScript,    "Adds a new link to a script from the 'Scripts' menu.");
    ADD_CLASS_METHOD(AddToMenu,        "Adds a new link to a script from any menu.");

    ADD_CLASS_METHOD(GetAuiManager, "Gets the wxAuiManager");
    ADD_CLASS_METHOD(GetMainBook,   "Gets the main notebook as wxAuiNotebook");

    ADD_CLASS_METHOD(GetAuiPaneInfo, "Gets ....");

    void AddMethods(WrapClass<MainFrame>::ptr this_ptr )
    {
      // Add members from wxFrame
      WrapClass_wxFrame::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxFrame>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_GetAmilabEditor(  this_ptr);
      AddVar_AddMenuScript(    this_ptr);
      AddVar_AddToMenu(        this_ptr);
      AddVar_GetAuiManager(    this_ptr);
      AddVar_GetMainBook(      this_ptr);
      AddVar_GetAuiPaneInfo(   this_ptr);
    }

};


#endif // _wrap_MainFrame_h_
