#include "wx/wx.h"

/** 
 *  The CEventPropagator custom event handler class: It forces key events to propagate up.
 *  @author Inspired from code by Rostfrei (http://wiki.wxwidgets.org/Catching_key_events_globally)
 */
class CEventPropagator : public wxEvtHandler
{
public:
  CEventPropagator();
  /**
   *  Push an event handler in every window's child.
   *  @param win A pointer to a wxWindow object.
   *  @return Nothing
   */
  static void registerFor(wxWindow* win);
 
private:
  void onKeyDown(wxKeyEvent& aEvent);
  void onKeyUp(wxKeyEvent& aEvent);
};

