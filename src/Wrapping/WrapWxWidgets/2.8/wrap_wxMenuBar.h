/**
 * C++ Interface: wrap_wxMenuBar
 *
 * Description: wrapping wxMenuBar
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuBar_h_
#define _wrap_wxMenuBar_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxMenuBarBase.h"


#ifndef wxMenuBar_declared
  #define wxMenuBar_declared
  AMI_DECLARE_TYPE(wxMenuBar);
#endif

// TODO: check for inheritence ...
class WrapClass_wxMenuBar : public WrapClass<wxMenuBar>
    , public   WrapClass_wxMenuBarBase
{
  DEFINE_CLASS(WrapClass_wxMenuBar);

  protected:
    typedef WrapClass<wxMenuBar>::ptr _parentclass_ptr;
    typedef wxMenuBar ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuBar>& GetObj() const { return WrapClass<wxMenuBar>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuBar(boost::shared_ptr<wxMenuBar > si): 
    WrapClass<wxMenuBar>(si)
    , WrapClass_wxMenuBarBase(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuBar()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBar_1,"Constructor wxMenuBar::wxMenuBar() (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#wxmenubar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBar,"Constructor wxMenuBar::wxMenuBar() (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#wxmenubar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBar_2,"Constructor wxMenuBar::wxMenuBar(long int style) (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#wxmenubar).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuBar_3,"Constructor wxMenuBar::wxMenuBar(size_t n, wxMenu * * menus, wxString const * titles, long int style = 0) (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#wxmenubar).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuBar*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Append,"bool wxMenuBar::Append(wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#append)")
    ADD_CLASS_METHOD(Insert,"bool wxMenuBar::Insert(size_t pos, wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#insert)")
    ADD_CLASS_METHOD(Replace,"wxMenu * wxMenuBar::Replace(size_t pos, wxMenu * menu, wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#replace)")
    ADD_CLASS_METHOD(Remove,"wxMenu * wxMenuBar::Remove(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#remove)")
    ADD_CLASS_METHOD(FindMenuItem,"int wxMenuBar::FindMenuItem(wxString const & menuString, wxString const & itemString)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#findmenuitem)")
    ADD_CLASS_METHOD(FindItem,"wxMenuItem * wxMenuBar::FindItem(int id, wxMenu * * menu = 0l)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#finditem)")
    ADD_CLASS_METHOD(EnableTop,"void wxMenuBar::EnableTop(size_t pos, bool flag)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#enabletop)")
    ADD_CLASS_METHOD(SetLabelTop,"void wxMenuBar::SetLabelTop(size_t pos, wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#setlabeltop)")
    ADD_CLASS_METHOD(GetLabelTop,"wxString wxMenuBar::GetLabelTop(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#getlabeltop)")
    ADD_CLASS_METHOD(SetLayoutDirection,"void wxMenuBar::SetLayoutDirection(wxLayoutDirection dir)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#setlayoutdirection)")
    ADD_CLASS_METHOD(GetLayoutDirection,"wxLayoutDirection wxMenuBar::GetLayoutDirection()  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#getlayoutdirection)")
    ADD_CLASS_METHOD(Attach,"void wxMenuBar::Attach(wxFrame * frame)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#attach)")
    ADD_CLASS_METHOD(SetInvokingWindow,"void wxMenuBar::SetInvokingWindow(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#setinvokingwindow)")
    ADD_CLASS_METHOD(UnsetInvokingWindow,"void wxMenuBar::UnsetInvokingWindow(wxWindow * win)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#unsetinvokingwindow)")
    ADD_CLASS_METHOD(GtkAppend,"bool wxMenuBar::GtkAppend(wxMenu * menu, wxString const & title, int pos = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#gtkappend)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMenuBar::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#getclassinfo)")
    ADD_CLASS_METHOD(GetMenuLabel,"wxString wxMenuBar::GetMenuLabel(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxmenubar.html#getmenulabel)")





    void AddMethods(WrapClass<wxMenuBar>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMenuBar_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxMenuBar_h
