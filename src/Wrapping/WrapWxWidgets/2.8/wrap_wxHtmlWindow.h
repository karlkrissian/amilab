/**
 * C++ Interface: wrap_wxHtmlWindow
 *
 * Description: wrapping wxHtmlWindow
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlWindow_h_
#define _wrap_wxHtmlWindow_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxScrolledWindow.h"
#include "wrap_wxHtmlWindowInterface.h"
//#include "wrap_wxHtmlWindowMouseHelper.h"


#ifndef wxHtmlWindow_declared
  #define wxHtmlWindow_declared
  AMI_DECLARE_TYPE(wxHtmlWindow);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlWindow : public WrapClass<wxHtmlWindow>
    , public   WrapClass_wxScrolledWindow, public   WrapClass_wxHtmlWindowInterface//, public  WrapClass_wxHtmlWindowMouseHelper
{
  DEFINE_CLASS(WrapClass_wxHtmlWindow);

  protected:
    typedef WrapClass<wxHtmlWindow>::ptr _parentclass_ptr;
    typedef wxHtmlWindow ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlWindow>& GetObj() const { return WrapClass<wxHtmlWindow>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlWindow(boost::shared_ptr<wxHtmlWindow > si): 
    WrapClass<wxHtmlWindow>(si)
    , WrapClass_wxScrolledWindow(si), WrapClass_wxHtmlWindowInterface(si)//, WrapClass_wxHtmlWindowMouseHelper(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlWindow()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlWindow_1,"Constructor wxHtmlWindow::wxHtmlWindow() (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#wxhtmlwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlWindow,"Constructor wxHtmlWindow::wxHtmlWindow() (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#wxhtmlwindow).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlWindow_2,"Constructor wxHtmlWindow::wxHtmlWindow(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxString const & name = 'htmlWindow') (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#wxhtmlwindow).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlWindow*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(AddFilter,"void wxHtmlWindow::AddFilter(wxHtmlFilter * filter) (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#addfilter).");
    /* The following types are missing: wxHtmlProcessor
    ADD_CLASS_STATICMETHOD(AddGlobalProcessor,"void wxHtmlWindow::AddGlobalProcessor(wxHtmlProcessor * processor) (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#addglobalprocessor).");
    */
    ADD_CLASS_STATICMETHOD(GetDefaultHTMLCursor,"wxCursor wxHtmlWindow::GetDefaultHTMLCursor(wxHtmlWindowInterface::HTMLCursor type) (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getdefaulthtmlcursor).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlWindow::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getclassinfo)")
    ADD_CLASS_METHOD(Create,"bool wxHtmlWindow::Create(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 4, wxString const & name = 'htmlWindow')  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#create)")
    ADD_CLASS_METHOD(SetPage,"bool wxHtmlWindow::SetPage(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setpage)")
    ADD_CLASS_METHOD(AppendToPage,"bool wxHtmlWindow::AppendToPage(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#appendtopage)")
    ADD_CLASS_METHOD(LoadPage,"bool wxHtmlWindow::LoadPage(wxString const & location)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#loadpage)")
    ADD_CLASS_METHOD(LoadFile,"bool wxHtmlWindow::LoadFile(wxFileName const & filename)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#loadfile)")
    ADD_CLASS_METHOD(GetOpenedPage,"wxString wxHtmlWindow::GetOpenedPage()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getopenedpage)")
    ADD_CLASS_METHOD(GetOpenedAnchor,"wxString wxHtmlWindow::GetOpenedAnchor()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getopenedanchor)")
    ADD_CLASS_METHOD(GetOpenedPageTitle,"wxString wxHtmlWindow::GetOpenedPageTitle()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getopenedpagetitle)")
    ADD_CLASS_METHOD(SetRelatedFrame,"void wxHtmlWindow::SetRelatedFrame(wxFrame * frame, wxString const & format)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setrelatedframe)")
    ADD_CLASS_METHOD(GetRelatedFrame,"wxFrame * wxHtmlWindow::GetRelatedFrame()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getrelatedframe)")
    ADD_CLASS_METHOD(SetRelatedStatusBar,"void wxHtmlWindow::SetRelatedStatusBar(int bar)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setrelatedstatusbar)")
    ADD_CLASS_METHOD(SetFonts,"void wxHtmlWindow::SetFonts(wxString const & normal_face, wxString const & fixed_face, int const * sizes = 0l)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setfonts)")
    ADD_CLASS_METHOD(SetStandardFonts,"void wxHtmlWindow::SetStandardFonts(int size = -0x00000000000000001, wxString const & normal_face = wxEmptyString, wxString const & fixed_face = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setstandardfonts)")
    ADD_CLASS_METHOD(SetBorders,"void wxHtmlWindow::SetBorders(int b)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setborders)")
    ADD_CLASS_METHOD(SetBackgroundImage,"void wxHtmlWindow::SetBackgroundImage(wxBitmap const & bmpBg)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#setbackgroundimage)")
    ADD_CLASS_METHOD(ReadCustomization,"void wxHtmlWindow::ReadCustomization(wxConfigBase * cfg, wxString path = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#readcustomization)")
    ADD_CLASS_METHOD(WriteCustomization,"void wxHtmlWindow::WriteCustomization(wxConfigBase * cfg, wxString path = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#writecustomization)")
    ADD_CLASS_METHOD(HistoryBack,"bool wxHtmlWindow::HistoryBack()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#historyback)")
    ADD_CLASS_METHOD(HistoryForward,"bool wxHtmlWindow::HistoryForward()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#historyforward)")
    ADD_CLASS_METHOD(HistoryCanBack,"bool wxHtmlWindow::HistoryCanBack()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#historycanback)")
    ADD_CLASS_METHOD(HistoryCanForward,"bool wxHtmlWindow::HistoryCanForward()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#historycanforward)")
    ADD_CLASS_METHOD(HistoryClear,"void wxHtmlWindow::HistoryClear()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#historyclear)")
    ADD_CLASS_METHOD(GetInternalRepresentation,"wxHtmlContainerCell * wxHtmlWindow::GetInternalRepresentation()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getinternalrepresentation)")
    ADD_CLASS_METHOD(GetParser,"wxHtmlWinParser * wxHtmlWindow::GetParser()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#getparser)")
/* The following types are missing: wxHtmlProcessor
    ADD_CLASS_METHOD(AddProcessor,"void wxHtmlWindow::AddProcessor(wxHtmlProcessor * processor)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#addprocessor)")
*/
    ADD_CLASS_METHOD(OnSetTitle,"void wxHtmlWindow::OnSetTitle(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#onsettitle)")
    ADD_CLASS_METHOD(OnLinkClicked,"void wxHtmlWindow::OnLinkClicked(wxHtmlLinkInfo const & link)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#onlinkclicked)")
    ADD_CLASS_METHOD(OnOpeningURL,"wxHtmlOpeningStatus wxHtmlWindow::OnOpeningURL(wxHtmlURLType param0, wxString const & param1, wxString * param2)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#onopeningurl)")
    ADD_CLASS_METHOD(SelectWord,"void wxHtmlWindow::SelectWord(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#selectword)")
    ADD_CLASS_METHOD(SelectLine,"void wxHtmlWindow::SelectLine(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#selectline)")
    ADD_CLASS_METHOD(SelectAll,"void wxHtmlWindow::SelectAll()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#selectall)")
    ADD_CLASS_METHOD(SelectionToText,"wxString wxHtmlWindow::SelectionToText()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#selectiontotext)")
    ADD_CLASS_METHOD(ToText,"wxString wxHtmlWindow::ToText()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#totext)")
    ADD_CLASS_METHOD(OnInternalIdle,"void wxHtmlWindow::OnInternalIdle()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#oninternalidle)")
    ADD_CLASS_METHOD(SetHTMLWindowTitle,"void wxHtmlWindow::SetHTMLWindowTitle(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#sethtmlwindowtitle)")
    ADD_CLASS_METHOD(OnHTMLLinkClicked,"void wxHtmlWindow::OnHTMLLinkClicked(wxHtmlLinkInfo const & link)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#onhtmllinkclicked)")
    ADD_CLASS_METHOD(OnHTMLOpeningURL,"wxHtmlOpeningStatus wxHtmlWindow::OnHTMLOpeningURL(wxHtmlURLType type, wxString const & url, wxString * redirect)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#onhtmlopeningurl)")
    ADD_CLASS_METHOD(HTMLCoordsToWindow,"wxPoint wxHtmlWindow::HTMLCoordsToWindow(wxHtmlCell * cell, wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#htmlcoordstowindow)")
    ADD_CLASS_METHOD(GetHTMLWindow,"wxWindow * wxHtmlWindow::GetHTMLWindow()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#gethtmlwindow)")
    ADD_CLASS_METHOD(GetHTMLBackgroundColour,"wxColour wxHtmlWindow::GetHTMLBackgroundColour()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#gethtmlbackgroundcolour)")
    ADD_CLASS_METHOD(SetHTMLBackgroundColour,"void wxHtmlWindow::SetHTMLBackgroundColour(wxColour const & clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#sethtmlbackgroundcolour)")
    ADD_CLASS_METHOD(SetHTMLBackgroundImage,"void wxHtmlWindow::SetHTMLBackgroundImage(wxBitmap const & bmpBg)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#sethtmlbackgroundimage)")
    ADD_CLASS_METHOD(SetHTMLStatusText,"void wxHtmlWindow::SetHTMLStatusText(wxString const & text)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#sethtmlstatustext)")
    ADD_CLASS_METHOD(GetHTMLCursor,"wxCursor wxHtmlWindow::GetHTMLCursor(wxHtmlWindowInterface::HTMLCursor type)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#gethtmlcursor)")
    ADD_CLASS_METHOD(DoSetPage,"bool wxHtmlWindow::DoSetPage(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwindow.html#dosetpage)")





    void AddMethods(WrapClass<wxHtmlWindow>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlWindow_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlWindow_h
