# -*- coding: windows-1252 -*-

# include everything here: difficult to sort
def get_include_file(classname, filename):
  last = filename.rfind('/wx/')
  incfile=filename[last+1:]
  #print "including class {0} from file {1}".format(classname,filename)
  #return incfile
  # get rid of specific library subdir
  s = incfile
  s = s.replace("/gtk","")
  s = s.replace("/gtk1","")
  s = s.replace("/mac/carbon","")
  s = s.replace("/mac","")
  s = s.replace("/cocoa","")
  s = s.replace("/msw","")
  s = s.replace("/msw/wince","")
  s = s.replace("/univ","")
  s = s.replace("/os2","")
  s = s.replace("/generic","")
  # TODO: check existence of the returned filename
  if s.find("tbar")      !=-1:  s = "wx/toolbar.h"
  if s.find("panelg.h")  !=-1:  s = "wx/panel.h"
  if s.find("paletteg.h")!=-1:  s = "wx/palette.h"
  # AD-HOC fixes, can be improved ...
  if classname.find("Aui")!=-1: s = "wx/aui/aui.h"
  #if classname=="wxDC":         s = "wx_includes.h"
  #if classname=="wxListCtrl":   s = "wx_includes.h"
  #if classname=="wxBitmap":     s = "wx_includes.h"
  #if classname=="wxRegionBase": s = "wx_includes.h"
  #if classname=="wxFontBase":   s = "wx_includes.h"
  #if classname=="wxBrush":      s = "wx_includes.h"
  #if classname=="wxGenericImageList": s = "wx_includes.h"
  #if classname=="wxMouseState": s = "wx_includes.h"
  #if classname=="wxPen":        s = "wx_includes.h"
  if classname=="wxWritableWCharBuffer":   s = "wx/string.h"
  if classname=="wxWritableCharBuffer":   s = "wx/string.h"
  if classname=="wxWCharBuffer":   s = "wx/string.h"
  if classname=="wxCharBuffer":   s = "wx/string.h"
  if classname=="wxStatusBar": s = "wx/statusbr.h"
  #if classname=="wxImageList": s = "wx_includes.h"
  if classname=="wxGDIImage": s = "wx/bitmap.h"
  if classname=="wxGDIImageHandler": s = "wx/bitmap.h"
  #if classname=="wxTextEntry":       s = "wx_includes.h"
  #if classname=="wxTextEntryBase":   s = "wx_includes.h"
  #print "including class {0} from file '{1}' will use '{2}'".format(classname,incfile,s)
  s1 = '#include "{0}"'.format(s)
  #print "s1 = ",s1
  #if classname=="wxScopedCharTypeBuffer<char>":
  #  s1 = '#include <wx/wx.h>\n'+s1
  #if classname=="wxEventTypeTag<wxTimerEvent>":
  #  s1 = '#include <wx/timer.h>\n'+s1
  #if classname=="wxEventTypeTag<wxListEvent>":
  #  s1 = '#include <wx/listctrl.h>\n'+s1
  #if classname=="wxFormatString":
  #  s1 = '#include <wx/string.h>\n'+s1
  return s1
 
def get_var_filter():
  return "wx*"

def wrap_public_fields(classname):
  # only wrap public fields for wxPoint
  return classname=="wxPoint"

def implement_deleter(classname):
  return ", smartpointer_nodeleter<{0} >()".format(classname)
