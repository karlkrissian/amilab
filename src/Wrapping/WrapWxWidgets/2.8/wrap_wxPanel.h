/**
 * C++ Interface: wrap_wxPanel
 *
 * Description: wrapping wxPanel
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPanel_h_
#define _wrap_wxPanel_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"



AMI_DECLARE_TYPE(wxPanel);

// TODO: check for inheritence ...
class WrapClass_wxPanel : public WrapClass<wxPanel>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxPanel);

  protected:
    typedef WrapClass<wxPanel>::ptr _parentclass_ptr;
    typedef wxPanel ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPanel>& GetObj() const { return WrapClass<wxPanel>::GetObj(); }

    /// Constructor
    WrapClass_wxPanel(boost::shared_ptr<wxPanel > si): 
    WrapClass<wxPanel>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxPanel()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPanel_1,"Constructor wxPanel::wxPanel() (http://docs.wxwidgets.org/stable/wx_wxpanel.html#wxpanel).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPanel,"Constructor wxPanel::wxPanel() (http://docs.wxwidgets.org/stable/wx_wxpanel.html#wxpanel).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPanel_2,"Constructor wxPanel::wxPanel(wxWindow * parent, int x, int y, int width, int height, long int style = 2621440, wxString const & name = wxPanelNameStr) (http://docs.wxwidgets.org/stable/wx_wxpanel.html#wxpanel).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPanel_3,"Constructor wxPanel::wxPanel(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 2621440, wxString const & name = wxPanelNameStr) (http://docs.wxwidgets.org/stable/wx_wxpanel.html#wxpanel).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPanel*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxPanel::Create(wxWindow * parent, wxWindowID winid = wxID_ANY, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 2621440, wxString const & name = wxPanelNameStr)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#create)")
    ADD_CLASS_METHOD(OnSize,"void wxPanel::OnSize(wxSizeEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#onsize)")
    ADD_CLASS_METHOD(InitDialog,"void wxPanel::InitDialog()  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#initdialog)")
    ADD_CLASS_METHOD(OnNavigationKey,"void wxPanel::OnNavigationKey(wxNavigationKeyEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#onnavigationkey)")
    ADD_CLASS_METHOD(OnFocus,"void wxPanel::OnFocus(wxFocusEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#onfocus)")
    ADD_CLASS_METHOD(OnChildFocus,"void wxPanel::OnChildFocus(wxChildFocusEvent & event)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#onchildfocus)")
    ADD_CLASS_METHOD(SetFocus,"void wxPanel::SetFocus()  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#setfocus)")
    ADD_CLASS_METHOD(SetFocusIgnoringChildren,"void wxPanel::SetFocusIgnoringChildren()  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#setfocusignoringchildren)")
    ADD_CLASS_METHOD(RemoveChild,"void wxPanel::RemoveChild(wxWindowBase * child)  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#removechild)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxPanel::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#acceptsfocus)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxPanel::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxpanel.html#getclassinfo)")





    void AddMethods(WrapClass<wxPanel>::ptr this_ptr );

};


#endif // _wrap_wxPanel_h
