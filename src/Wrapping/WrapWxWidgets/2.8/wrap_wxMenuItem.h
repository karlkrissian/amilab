/**
 * C++ Interface: wrap_wxMenuItem
 *
 * Description: wrapping wxMenuItem
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMenuItem_h_
#define _wrap_wxMenuItem_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxMenuItemBase.h"


#ifndef wxMenuItem_declared
  #define wxMenuItem_declared
  AMI_DECLARE_TYPE(wxMenuItem);
#endif

// TODO: check for inheritence ...
class WrapClass_wxMenuItem : public WrapClass<wxMenuItem>
    , public   WrapClass_wxMenuItemBase
{
  DEFINE_CLASS(WrapClass_wxMenuItem);

  protected:
    typedef WrapClass<wxMenuItem>::ptr _parentclass_ptr;
    typedef wxMenuItem ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMenuItem>& GetObj() const { return WrapClass<wxMenuItem>::GetObj(); }

    /// Constructor
    WrapClass_wxMenuItem(boost::shared_ptr<wxMenuItem > si): 
    WrapClass<wxMenuItem>(si)
    , WrapClass_wxMenuItemBase(si)
    {}

    /// Destructor
    ~WrapClass_wxMenuItem()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItem_1,"Constructor wxMenuItem::wxMenuItem(wxMenu * parentMenu = 0u, int id = wxID_SEPARATOR, wxString const & text = wxEmptyString, wxString const & help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL, wxMenu * subMenu = 0u) (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#wxmenuitem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItem,"Constructor wxMenuItem::wxMenuItem() (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#wxmenuitem).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMenuItem_2,"Constructor wxMenuItem::wxMenuItem(wxMenu * parentMenu, int id, wxString const & text, wxString const & help, bool isCheckable, wxMenu * subMenu = 0u) (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#wxmenuitem).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMenuItem*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GTKProcessMenuItemLabel,"wxString wxMenuItem::GTKProcessMenuItemLabel(wxString const & str, wxString * hotKey) (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#gtkprocessmenuitemlabel).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetText,"void wxMenuItem::SetText(wxString const & str)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#settext)")
    ADD_CLASS_METHOD(Enable,"void wxMenuItem::Enable(bool enable = 1)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#enable)")
    ADD_CLASS_METHOD(Check,"void wxMenuItem::Check(bool check = 1)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#check)")
    ADD_CLASS_METHOD(IsChecked,"bool wxMenuItem::IsChecked()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#ischecked)")
    ADD_CLASS_METHOD(SetBitmap,"void wxMenuItem::SetBitmap(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#setbitmap)")
    ADD_CLASS_METHOD(GetBitmap,"wxBitmap const & wxMenuItem::GetBitmap()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getbitmap)")
    ADD_CLASS_METHOD(GetAccel,"wxAcceleratorEntry * wxMenuItem::GetAccel()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getaccel)")
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(SetMenuItem,"void wxMenuItem::SetMenuItem(GtkWidget * menuItem)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#setmenuitem)")
*/
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(GetMenuItem,"GtkWidget * wxMenuItem::GetMenuItem()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getmenuitem)")
*/
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(GetLabelWidget,"GtkWidget * wxMenuItem::GetLabelWidget()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getlabelwidget)")
*/
/* The following types are missing: _GtkWidget
    ADD_CLASS_METHOD(SetLabelWidget,"void wxMenuItem::SetLabelWidget(GtkWidget * labelWidget)  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#setlabelwidget)")
*/
    ADD_CLASS_METHOD(GetHotKey,"wxString wxMenuItem::GetHotKey()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#gethotkey)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMenuItem::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getclassinfo)")
    ADD_CLASS_METHOD(GetItemLabel,"wxString wxMenuItem::GetItemLabel()  (http://docs.wxwidgets.org/stable/wx_wxmenuitem.html#getitemlabel)")





    void AddMethods(WrapClass<wxMenuItem>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMenuItem_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxMenuItem_h
