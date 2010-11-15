/**
 * C++ Interface: wrap_wxTopLevelWindowBase
 *
 * Description: wrapping wxTopLevelWindowBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxTopLevelWindowBase_h_
#define _wrap_wxTopLevelWindowBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"


AMI_DECLARE_TYPE(wxTopLevelWindowBase);

// TODO: check for inheritence ...
class WrapClass_wxTopLevelWindowBase : public WrapClass<wxTopLevelWindowBase>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxTopLevelWindowBase);

  protected:
    typedef WrapClass<wxTopLevelWindowBase>::ptr _parentclass_ptr;
    typedef wxTopLevelWindowBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxTopLevelWindowBase>& GetObj() const { return WrapClass<wxTopLevelWindowBase>::GetObj(); }

    /// Constructor
    WrapClass_wxTopLevelWindowBase(boost::shared_ptr<wxTopLevelWindowBase > si): 
    WrapClass<wxTopLevelWindowBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxTopLevelWindowBase()
    {
      std::cout << "~WrapClass_wxTopLevelWindowBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxTopLevelWindowBase*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsAlwaysMaximized,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isalwaysmaximized")
/* The following types are missing: wxIcon
    ADD_CLASS_METHOD(GetIcon,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#geticon")
*/
/* The following types are missing: wxIconBundle
    ADD_CLASS_METHOD(GetIcons,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#geticons")
*/
/* The following types are missing: wxIcon
    ADD_CLASS_METHOD(SetIcon,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#seticon")
*/
/* The following types are missing: wxIconBundle
    ADD_CLASS_METHOD(SetIcons,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#seticons")
*/
    ADD_CLASS_METHOD(EnableCloseButton,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#enableclosebutton")
/* The following types are missing: wxRegion
    ADD_CLASS_METHOD(SetShape,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setshape")
*/
    ADD_CLASS_METHOD(RequestUserAttention,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#requestuserattention")
    ADD_CLASS_METHOD(IsActive,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isactive")
    ADD_CLASS_METHOD(ShouldPreventAppExit,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#shouldpreventappexit")
    ADD_CLASS_METHOD(CentreOnScreen,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#centreonscreen")
    ADD_CLASS_METHOD(CenterOnScreen,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#centeronscreen")
    ADD_CLASS_METHOD(RemoveChild,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#removechild")
    ADD_CLASS_METHOD(GetDefaultItem,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#getdefaultitem")
    ADD_CLASS_METHOD(SetDefaultItem,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setdefaultitem")
    ADD_CLASS_METHOD(GetTmpDefaultItem,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#gettmpdefaultitem")
    ADD_CLASS_METHOD(SetTmpDefaultItem,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#settmpdefaultitem")
    ADD_CLASS_METHOD(Destroy,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#destroy")
    ADD_CLASS_METHOD(IsTopLevel,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#istoplevel")
    ADD_CLASS_METHOD(IsVisible,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#isvisible")
/* The following types are missing: wxCloseEvent
    ADD_CLASS_METHOD(OnCloseWindow,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onclosewindow")
*/
/* The following types are missing: wxSizeEvent
    ADD_CLASS_METHOD(OnSize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onsize")
*/
    ADD_CLASS_METHOD(GetRectForTopLevelChildren,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#getrectfortoplevelchildren")
/* The following types are missing: wxActivateEvent
    ADD_CLASS_METHOD(OnActivate,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#onactivate")
*/
/* The following types are missing: wxUpdateUIEvent
    ADD_CLASS_METHOD(DoUpdateWindowUI,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#doupdatewindowui")
*/
    ADD_CLASS_METHOD(SetMinSize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setminsize")
    ADD_CLASS_METHOD(SetMaxSize,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#setmaxsize")
    ADD_CLASS_METHOD(DoSetSizeHints,"http://docs.wxwidgets.org/stable/wx_wxtoplevelwindowbase.html#dosetsizehints")





    void AddMethods(WrapClass<wxTopLevelWindowBase>::ptr this_ptr )
    {
      
      // Add members from wxWindow
      WrapClass_wxWindow::ptr parent_wxWindow(        boost::dynamic_pointer_cast<WrapClass_wxWindow >(this_ptr));
      parent_wxWindow->AddMethods(parent_wxWindow);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_IsAlwaysMaximized( this_ptr);
/* The following types are missing: wxIcon
      AddVar_GetIcon( this_ptr);
*/
/* The following types are missing: wxIconBundle
      AddVar_GetIcons( this_ptr);
*/
/* The following types are missing: wxIcon
      AddVar_SetIcon( this_ptr);
*/
/* The following types are missing: wxIconBundle
      AddVar_SetIcons( this_ptr);
*/
      AddVar_EnableCloseButton( this_ptr);
/* The following types are missing: wxRegion
      AddVar_SetShape( this_ptr);
*/
      AddVar_RequestUserAttention( this_ptr);
      AddVar_IsActive( this_ptr);
      AddVar_ShouldPreventAppExit( this_ptr);
      AddVar_CentreOnScreen( this_ptr);
      AddVar_CenterOnScreen( this_ptr);
      AddVar_RemoveChild( this_ptr);
      AddVar_GetDefaultItem( this_ptr);
      AddVar_SetDefaultItem( this_ptr);
      AddVar_GetTmpDefaultItem( this_ptr);
      AddVar_SetTmpDefaultItem( this_ptr);
      AddVar_Destroy( this_ptr);
      AddVar_IsTopLevel( this_ptr);
      AddVar_IsVisible( this_ptr);
/* The following types are missing: wxCloseEvent
      AddVar_OnCloseWindow( this_ptr);
*/
/* The following types are missing: wxSizeEvent
      AddVar_OnSize( this_ptr);
*/
      AddVar_GetRectForTopLevelChildren( this_ptr);
/* The following types are missing: wxActivateEvent
      AddVar_OnActivate( this_ptr);
*/
/* The following types are missing: wxUpdateUIEvent
      AddVar_DoUpdateWindowUI( this_ptr);
*/
      AddVar_SetMinSize( this_ptr);
      AddVar_SetMaxSize( this_ptr);
      AddVar_DoSetSizeHints( this_ptr);



      
    };
};


#endif // _wrap_wxTopLevelWindowBase_h
