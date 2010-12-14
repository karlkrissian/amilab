/**
 * C++ Interface: wrap_wxScrolledWindow
 *
 * Description: wrapping wxScrolledWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxScrolledWindow_h_
#define _wrap_wxScrolledWindow_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxPanel.h"
#include "wrap_wxScrollHelperNative.h"


#ifndef wxScrolledWindow_declared
  #define wxScrolledWindow_declared
  AMI_DECLARE_TYPE(wxScrolledWindow);
#endif

// TODO: check for inheritence ...
class WrapClass_wxScrolledWindow : public WrapClass<wxScrolledWindow>
    , public   WrapClass_wxPanel, public   WrapClass_wxScrollHelperNative
{
  DEFINE_CLASS(WrapClass_wxScrolledWindow);

  protected:
    typedef WrapClass<wxScrolledWindow>::ptr _parentclass_ptr;
    typedef wxScrolledWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxScrolledWindow>& GetObj() const { return WrapClass<wxScrolledWindow>::GetObj(); }

    /// Constructor
    WrapClass_wxScrolledWindow(boost::shared_ptr<wxScrolledWindow > si): 
    WrapClass<wxScrolledWindow>(si)
    , WrapClass_wxPanel(si), WrapClass_wxScrollHelperNative(si)
    {}

    /// Destructor
    ~WrapClass_wxScrolledWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrolledWindow_1,"Constructor wxScrolledWindow::wxScrolledWindow() (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#wxscrolledwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrolledWindow,"Constructor wxScrolledWindow::wxScrolledWindow() (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#wxscrolledwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrolledWindow_2,"Constructor wxScrolledWindow::wxScrolledWindow(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 3221225472u, wxString const & name = wxPanelNameStr) (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#wxscrolledwindow).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxScrolledWindow*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxScrolledWindow::Create(wxWindow * parent, wxWindowID winid, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 3221225472u, wxString const & name = wxPanelNameStr)  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#create)")
    ADD_CLASS_METHOD(PrepareDC,"void wxScrolledWindow::PrepareDC(wxDC & dc)  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#preparedc)")
    ADD_CLASS_METHOD(Layout,"bool wxScrolledWindow::Layout()  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#layout)")
    ADD_CLASS_METHOD(DoSetVirtualSize,"void wxScrolledWindow::DoSetVirtualSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#dosetvirtualsize)")
    ADD_CLASS_METHOD(GetBestVirtualSize,"wxSize wxScrolledWindow::GetBestVirtualSize()  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#getbestvirtualsize)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxScrolledWindow::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxscrolledwindow.html#getclassinfo)")





    void AddMethods(WrapClass<wxScrolledWindow>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxScrolledWindow_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxScrolledWindow_h
