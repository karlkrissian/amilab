/**
 * C++ Interface: wrap_wxAuiNotebook
 *
 * Description: wrapping wxAuiNotebook
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiNotebook_h_
#define _wrap_wxAuiNotebook_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"



AMI_DECLARE_TYPE(wxAuiNotebook);

// TODO: check for inheritence ...
class WrapClass_wxAuiNotebook : public WrapClass<wxAuiNotebook>
    , public   WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxAuiNotebook);

  protected:
    typedef WrapClass<wxAuiNotebook>::ptr _parentclass_ptr;
    typedef wxAuiNotebook ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiNotebook>& GetObj() const { return WrapClass<wxAuiNotebook>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiNotebook(boost::shared_ptr<wxAuiNotebook > si): 
    WrapClass<wxAuiNotebook>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiNotebook()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiNotebook_1,"Constructor wxAuiNotebook::wxAuiNotebook() (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#wxauinotebook).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiNotebook,"Constructor wxAuiNotebook::wxAuiNotebook() (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#wxauinotebook).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiNotebook_2,"Constructor wxAuiNotebook::wxAuiNotebook(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxAUI_NB_DEFAULT_STYLE) (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#wxauinotebook).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiNotebook*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxAuiNotebook::Create(wxWindow * parent, wxWindowID id = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#create)")
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxAuiNotebook::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(SetArtProvider,"void wxAuiNotebook::SetArtProvider(wxAuiTabArt * art)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setartprovider)")
    ADD_CLASS_METHOD(GetArtProvider,"wxAuiTabArt * wxAuiNotebook::GetArtProvider()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getartprovider)")
    ADD_CLASS_METHOD(SetUniformBitmapSize,"void wxAuiNotebook::SetUniformBitmapSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setuniformbitmapsize)")
    ADD_CLASS_METHOD(SetTabCtrlHeight,"void wxAuiNotebook::SetTabCtrlHeight(int height)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#settabctrlheight)")
    ADD_CLASS_METHOD(AddPage,"bool wxAuiNotebook::AddPage(wxWindow * page, wxString const & caption, bool select = false, wxBitmap const & bitmap = wxNullBitmap)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#addpage)")
    ADD_CLASS_METHOD(InsertPage,"bool wxAuiNotebook::InsertPage(size_t page_idx, wxWindow * page, wxString const & caption, bool select = false, wxBitmap const & bitmap = wxNullBitmap)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#insertpage)")
    ADD_CLASS_METHOD(DeletePage,"bool wxAuiNotebook::DeletePage(size_t page)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#deletepage)")
    ADD_CLASS_METHOD(RemovePage,"bool wxAuiNotebook::RemovePage(size_t page)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#removepage)")
    ADD_CLASS_METHOD(GetPageCount,"size_t wxAuiNotebook::GetPageCount()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getpagecount)")
    ADD_CLASS_METHOD(GetPage,"wxWindow * wxAuiNotebook::GetPage(size_t page_idx)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getpage)")
    ADD_CLASS_METHOD(GetPageIndex,"int wxAuiNotebook::GetPageIndex(wxWindow * page_wnd)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getpageindex)")
    ADD_CLASS_METHOD(SetPageText,"bool wxAuiNotebook::SetPageText(size_t page, wxString const & text)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setpagetext)")
    ADD_CLASS_METHOD(GetPageText,"wxString wxAuiNotebook::GetPageText(size_t page_idx)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getpagetext)")
    ADD_CLASS_METHOD(SetPageBitmap,"bool wxAuiNotebook::SetPageBitmap(size_t page, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setpagebitmap)")
    ADD_CLASS_METHOD(GetPageBitmap,"wxBitmap wxAuiNotebook::GetPageBitmap(size_t page_idx)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getpagebitmap)")
    ADD_CLASS_METHOD(SetSelection,"size_t wxAuiNotebook::SetSelection(size_t new_page)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setselection)")
    ADD_CLASS_METHOD(GetSelection,"int wxAuiNotebook::GetSelection()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getselection)")
    ADD_CLASS_METHOD(Split,"void wxAuiNotebook::Split(size_t page, int direction)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#split)")
    ADD_CLASS_METHOD(GetAuiManager,"wxAuiManager const & wxAuiNotebook::GetAuiManager()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getauimanager)")
    ADD_CLASS_METHOD(SetNormalFont,"void wxAuiNotebook::SetNormalFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setnormalfont)")
    ADD_CLASS_METHOD(SetSelectedFont,"void wxAuiNotebook::SetSelectedFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setselectedfont)")
    ADD_CLASS_METHOD(SetMeasuringFont,"void wxAuiNotebook::SetMeasuringFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setmeasuringfont)")
    ADD_CLASS_METHOD(SetFont,"bool wxAuiNotebook::SetFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#setfont)")
    ADD_CLASS_METHOD(GetTabCtrlHeight,"int wxAuiNotebook::GetTabCtrlHeight()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#gettabctrlheight)")
    ADD_CLASS_METHOD(GetHeightForPageHeight,"int wxAuiNotebook::GetHeightForPageHeight(int pageHeight)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getheightforpageheight)")
    ADD_CLASS_METHOD(AdvanceSelection,"void wxAuiNotebook::AdvanceSelection(bool forward = true)  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#advanceselection)")
    ADD_CLASS_METHOD(ShowWindowMenu,"bool wxAuiNotebook::ShowWindowMenu()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#showwindowmenu)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAuiNotebook::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxauinotebook.html#getclassinfo)")





    void AddMethods(WrapClass<wxAuiNotebook>::ptr this_ptr );

};


#endif // _wrap_wxAuiNotebook_h
