/*
 *  wxPropagateEvent.cpp
 *
 */

#include "wxPropagateEvent.h"

CEventPropagator::CEventPropagator()
{
  // Event connections
  this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(CEventPropagator::onKeyDown));
  this->Connect(wxEVT_KEY_UP,   wxKeyEventHandler(CEventPropagator::onKeyUp));
}
 
void CEventPropagator::onKeyDown(wxKeyEvent& aEvent)
{
  aEvent.ResumePropagation(1);
  aEvent.Skip();
}
 
void CEventPropagator::onKeyUp(wxKeyEvent& aEvent)
{
  aEvent.ResumePropagation(1);
  aEvent.Skip();
}
 
void CEventPropagator::registerFor(wxWindow* win)
{
  wxWindowListNode* childNode = win->GetChildren().GetFirst();
  while (childNode)
  {
    childNode->GetData()->PushEventHandler(new CEventPropagator());
    childNode = childNode->GetNext();
  } 
}
 

