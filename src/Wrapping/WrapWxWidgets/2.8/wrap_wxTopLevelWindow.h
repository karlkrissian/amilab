/**
 * C++ Interface: wrap_wxTopLevelWindow
 *
 * Description: wrapping wxTopLevelWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTopLevelWindow_h_
#define _wrap_wxTopLevelWindow_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindowGTK.h"



AMI_DECLARE_TYPE(wxTopLevelWindow);

// TODO: check for inheritence ...
class WrapClass_wxTopLevelWindow : public WrapClass<wxTopLevelWindow>
    , public   WrapClass_wxTopLevelWindowGTK
{
  DEFINE_CLASS(WrapClass_wxTopLevelWindow);

  protected:
    typedef WrapClass<wxTopLevelWindow>::ptr _parentclass_ptr;
    typedef wxTopLevelWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTopLevelWindow>& GetObj() const { return WrapClass<wxTopLevelWindow>::GetObj(); }

    /// Constructor
    WrapClass_wxTopLevelWindow(boost::shared_ptr<wxTopLevelWindow > si): 
    WrapClass<wxTopLevelWindow>(si)
    , WrapClass_wxTopLevelWindowGTK(si)
    {}

    /// Destructor
    ~WrapClass_wxTopLevelWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindow_1,"Constructor wxTopLevelWindow::wxTopLevelWindow() (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindow.html#wxtoplevelwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindow,"Constructor wxTopLevelWindow::wxTopLevelWindow() (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindow.html#wxtoplevelwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxTopLevelWindow_2,"Constructor wxTopLevelWindow::wxTopLevelWindow(wxWindow * parent, wxWindowID winid, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 541072960, wxString const & name = wxFrameNameStr) (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindow.html#wxtoplevelwindow).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTopLevelWindow*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxTopLevelWindow::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxtoplevelwindow.html#getclassinfo)")





    void AddMethods(WrapClass<wxTopLevelWindow>::ptr this_ptr );

};


#endif // _wrap_wxTopLevelWindow_h
