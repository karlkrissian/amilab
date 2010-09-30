//
// C++ Interface: wrap_wxHtmlWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxHtmlWindow_h_
#define _wrap_wxHtmlWindow_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>
#include "wrap_wxWindow.h"


AMI_DECLARE_TYPE(wxHtmlWindow);

class WrapClass_wxHtmlWindow : public WrapClass<wxHtmlWindow>, public WrapClass_wxWindow
{

  DEFINE_CLASS(WrapClass_wxHtmlWindow);

  protected:  
    // needed to resolve ambiguity from multiple inheritance
    typedef boost::shared_ptr<WrapClass<wxHtmlWindow> > _parentclass_ptr;
    typedef wxHtmlWindow ObjectType;

  public:

    /// Constructor
    WrapClass_wxHtmlWindow(boost::shared_ptr<wxHtmlWindow> w):WrapClass<wxHtmlWindow>(w), WrapClass_wxWindow(w)
    {}

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlWindow, "Wrapping of wxHtmlWindow (see http://docs.wxwidgets.org/)." )

    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlWindow*);

    ADD_CLASS_METHOD(LoadFile,        "Loads HTML page from file and displays it.");
    ADD_CLASS_METHOD(LoadPage,        "Loads HTML page and displays it.");
    ADD_CLASS_METHOD(HistoryBack,     "Moves back to the previous page.");
    ADD_CLASS_METHOD(HistoryForward,  "Moves to next page in history.");


    void AddMethods(WrapClass<wxHtmlWindow>::ptr this_ptr )
    {
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_obj(boost::dynamic_pointer_cast<WrapClass_wxWindow>(this_ptr));
      parent_obj->AddMethods(parent_obj);

      AddVar_LoadFile(       this_ptr);
      AddVar_LoadPage(       this_ptr);
      AddVar_HistoryBack(    this_ptr);
      AddVar_HistoryForward( this_ptr);
    }

};



#endif // _wrap_wxHtmlWindow_h_
