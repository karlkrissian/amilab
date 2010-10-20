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
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

//#include "wrap_wxSizer.h"
//#include <wx/sizer.h>

#include <wx/html/htmlwin.h>

AMI_DECLARE_TYPE(wxWindow);

template <> AMI_DLLEXPORT
BasicVariable::ptr WrapClass<wxWindow>::CreateVar( ParamList* p);


class WrapClass_wxWindow : public WrapClass<wxWindow>
{
  DEFINE_CLASS(WrapClass_wxWindow);

  public:

    /// Constructor
    WrapClass_wxWindow(boost::shared_ptr<wxWindow> w): WrapClass<wxWindow>(w)
    {}

    ~WrapClass_wxWindow()
    {
      std::cout << "~WrapClass_wxWindow()" << std::endl;
    }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( wxWindow, "Wrapping of wxWindow (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(GetMinSize,     "Returns the minimum size of the window, an indication to the sizer layout mechanism that this is the minimum required size. It normally just returns the value set by SetMinSize, but it can be overridden to do the calculation on demand.");
    ADD_CLASS_METHOD(SetMinSize,     "Sets the minimum size of the window, to indicate to the sizer layout mechanism that this is the minimum required size. You may need to call this if you change the window size after construction and before adding to its parent sizer.");
    ADD_CLASS_METHOD(ShowWin,        "Shows or hides the window.");
    ADD_CLASS_METHOD(SetSize,        "Sets the size and position of the window in pixels.\n\
    http://docs.wxwidgets.org/stable/wx_wxwindow.html#wxwindowsetsize");

    ADD_CLASS_METHOD(Update,         "repaints the invalidated area of the window and all of its children recursively");
    ADD_CLASS_METHOD(Refresh,        "Causes this window, and all of its children recursively (except under wxGTK1 where this is not implemented), to be repainted");

    ADD_CLASS_METHOD(SetBackgroundColour,   "Sets the background colour of the window.");

    ADD_CLASS_METHOD(GetSizer,     "Gets the sizer associated with the window.");



    void AddMethods( WrapClass<wxWindow>::ptr this_ptr ) {
      AddVar_GetMinSize(          this_ptr);
      AddVar_SetMinSize(          this_ptr);
      AddVar_ShowWin(             this_ptr);
      AddVar_SetSize(             this_ptr);
      AddVar_SetBackgroundColour( this_ptr);
      AddVar_Update(              this_ptr);
      AddVar_Refresh(             this_ptr);
      AddVar_GetSizer(            this_ptr);
    }

};


#endif // _wrap_wxWindow_h_
