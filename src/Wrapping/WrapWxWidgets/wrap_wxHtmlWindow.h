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


class WrapClass_wxHtmlWindow : public WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxHtmlWindow);

  // for nested classes
  typedef WrapClass_wxHtmlWindow::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxHtmlWindow> _obj;

    /// Constructor
    WrapClass_wxHtmlWindow(boost::shared_ptr<wxHtmlWindow> w): WrapClass_wxWindow(w), _obj(w)
    {}


    ADD_CLASS_METHOD(LoadFile,        "Loads HTML page from file and displays it.");
    ADD_CLASS_METHOD(HistoryBack,     "Moves back to the previous page.");
    ADD_CLASS_METHOD(HistoryForward,  "Moves to next page in history.");

};

/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxHtmlWindow( ParamList* p);


#endif // _wrap_wxHtmlWindow_h_
