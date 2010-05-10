//
// C++ Interface: wrap_wxWindow
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxWindow_h_
#define _wrap_wxWindow_h_

#include "wrapfunction_class.h"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
#include <wx/html/htmlwin.h>


class WrapClass_wxWindow : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxWindow);

  // for nested classes
  typedef WrapClass_wxWindow::ptr _parentclass_ptr;

  public:
    boost::shared_ptr<wxWindow> _win;

    /// Constructor
    WrapClass_wxWindow(boost::shared_ptr<wxWindow> w): _win(w)
    {}

    ADD_CLASS_METHOD(GetMinSize,     "Returns the minimum size of the window, an indication to the sizer layout mechanism that this is the minimum required size. It normally just returns the value set by SetMinSize, but it can be overridden to do the calculation on demand.");
    ADD_CLASS_METHOD(SetMinSize,     "Sets the minimum size of the window, to indicate to the sizer layout mechanism that this is the minimum required size. You may need to call this if you change the window size after construction and before adding to its parent sizer.");
    ADD_CLASS_METHOD(ShowWin,        "Shows or hides the window.");
    ADD_CLASS_METHOD(SetSize,        "Sets the size and position of the window in pixels.\n\
    http://docs.wxwidgets.org/stable/wx_wxwindow.html#wxwindowsetsize");

    void AddMethods( _parentclass_ptr& this_ptr ) {

      AddVar_GetMinSize(     this_ptr);
      AddVar_SetMinSize(     this_ptr);
      AddVar_ShowWin(        this_ptr);
      AddVar_SetSize(        this_ptr);
    }

};

/**
 * Create a Wrapped object around wxWindow
 * @param objectptr input smart pointer to a WrapClass_wxWindow
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxWindow(  WrapClass_wxWindow::ptr& objectptr);


/** function that add wrapping of the Image Drawing window
 */
BasicVariable::ptr wrap_wxWindow( ParamList* p);


#endif // _wrap_wxWindow_h_
