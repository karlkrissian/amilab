
#ifndef __GCCXML__
  #pragma once
#endif

#include "wx_includes_common.h"

//#include "wrapfunction_class.h"
//#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/html/htmlwin.h>
#include <wx/dynlib.h>
#include "wxPluginManager.h"
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/radiobox.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextstyles.h>
#include <wx/stdpaths.h>
#include <wx/stc/stc.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/cmdline.h>
#include <wx/config.h>
#include <wx/fileconf.h>
#include <wx/scrolwin.h>
#include <wx/timer.h>
#include <wx/url.h>

#ifdef __GCCXML__
  // declare classes to instantiate them
  // The correct number does not matter here, because it is for gccxml to 
  // to be able to instantiate the template class ...
      int id=0;
      class wxEventTypeTag<wxCommandEvent>  et1(id);
      class wxEventTypeTag<wxMouseEvent>    et2(id);
      class wxEventTypeTag<wxKeyEvent>      et3(id);
      class wxEventTypeTag<wxSizeEvent>     et4(id);
      class wxEventTypeTag<wxPaintEvent>    et5(id);
      class wxEventTypeTag<wxEraseEvent>    et6(id);
      class wxEventTypeTag<wxMoveEvent>     et7(id);
      class wxEventTypeTag<wxFocusEvent>    et8(id);
      class wxEventTypeTag<wxCloseEvent>    et9(id);
      class wxEventTypeTag<wxMenuEvent>     et10(id);
      class wxEventTypeTag<wxTimerEvent>    et11(id);
      class wxEventTypeTag<wxListEvent>     et12(id);
      class wxEventTypeTag<wxHtmlCellEvent> et13(id);
      class wxEventTypeTag<wxHtmlLinkEvent> et14(id);
  // TODO list all the possible types of events here ...
  namespace wrap_wx {

    // force include headers in namespace
    #undef _WX_TRACKER_H_
    #undef _WX_REGEX_H_
    #undef _WX_TIMER_H_BASE_
    #undef _WX_FILENAME_H_

    #include <wx/regex.h>
    #include <wx/timer.h>
    #include <wx/filename.h>

//    enum
//    {
//      wxPATH_NO_SEPARATOR = 0x0000,  // for symmetry with wxPATH_GET_SEPARATOR
//      wxPATH_GET_VOLUME = 0x0001,  // include the volume if applicable
//      wxPATH_GET_SEPARATOR = 0x0002   // terminate the path with the separator
//    };

  };
#endif // __GCCXML__


