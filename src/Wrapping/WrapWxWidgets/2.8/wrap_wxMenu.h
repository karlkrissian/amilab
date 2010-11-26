/**
 * C++ Interface: wrap_wxMenu
 *
 * Description: wrapping wxMenu
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenu_h_
#define _wrap_wxMenu_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxMenuBase.h"


AMI_DECLARE_TYPE(wxMenu);

// TODO: check for inheritence ...
class WrapClass_wxMenu : public WrapClass<wxMenu>
    , public   WrapClass_wxMenuBase
{
  DEFINE_CLASS(WrapClass_wxMenu);

  protected:
    typedef WrapClass<wxMenu>::ptr _parentclass_ptr;
    typedef wxMenu ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenu>& GetObj() const { return WrapClass<wxMenu>::GetObj(); }

    /// Constructor
    WrapClass_wxMenu(boost::shared_ptr<wxMenu > si): 
    WrapClass<wxMenu>(si)
    , WrapClass_wxMenuBase(si)
    {}

    /// Destructor
    ~WrapClass_wxMenu()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenu_1,"Constructor wxMenu::wxMenu(wxString const & title, long int style = 0) (http://docs.wxwidgets.org/stable/wx_wxmenu.html#wxmenu).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenu,"Constructor wxMenu::wxMenu() (http://docs.wxwidgets.org/stable/wx_wxmenu.html#wxmenu).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenu_2,"Constructor wxMenu::wxMenu(long int style = 0) (http://docs.wxwidgets.org/stable/wx_wxmenu.html#wxmenu).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenu*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Attach,"void wxMenu::Attach(wxMenuBarBase * menubar)  (http://docs.wxwidgets.org/stable/wx_wxmenu.html#attach)")
    ADD_CLASS_METHOD(SetLayoutDirection,"void wxMenu::SetLayoutDirection(wxLayoutDirection const dir)  (http://docs.wxwidgets.org/stable/wx_wxmenu.html#setlayoutdirection)")
    ADD_CLASS_METHOD(GetLayoutDirection,"wxLayoutDirection wxMenu::GetLayoutDirection()  (http://docs.wxwidgets.org/stable/wx_wxmenu.html#getlayoutdirection)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(FindMenuIdByMenuItem,"int wxMenu::FindMenuIdByMenuItem(GtkWidget * menuItem)  (http://docs.wxwidgets.org/stable/wx_wxmenu.html#findmenuidbymenuitem)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMenu::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmenu.html#getclassinfo)")





    void AddMethods(WrapClass<wxMenu>::ptr this_ptr );

};


#endif // _wrap_wxMenu_h
