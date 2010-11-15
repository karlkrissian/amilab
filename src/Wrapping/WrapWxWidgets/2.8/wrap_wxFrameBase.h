/**
 * C++ Interface: wrap_wxFrameBase
 *
 * Description: wrapping wxFrameBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFrameBase_h_
#define _wrap_wxFrameBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxTopLevelWindow.h"


AMI_DECLARE_TYPE(wxFrameBase);

// TODO: check for inheritence ...
class WrapClass_wxFrameBase : public WrapClass<wxFrameBase>
    , public   WrapClass_wxTopLevelWindow
{
  DEFINE_CLASS(WrapClass_wxFrameBase);

  protected:
    typedef WrapClass<wxFrameBase>::ptr _parentclass_ptr;
    typedef wxFrameBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFrameBase>& GetObj() const { return WrapClass<wxFrameBase>::GetObj(); }

    /// Constructor
    WrapClass_wxFrameBase(boost::shared_ptr<wxFrameBase > si): 
    WrapClass<wxFrameBase>(si)
    , WrapClass_wxTopLevelWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxFrameBase()
    {
      std::cout << "~WrapClass_wxFrameBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFrameBase,"Wrapping of wxFrameBase, http://docs.wxwidgets.org/stable/wx_wxframebase.html#wxframebase.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFrameBase*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(New,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#new")
    ADD_CLASS_METHOD(GetClientAreaOrigin,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#getclientareaorigin")
    ADD_CLASS_METHOD(SendSizeEvent,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#sendsizeevent")
/* The following types are missing: wxMenuBar
    ADD_CLASS_METHOD(SetMenuBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#setmenubar")
*/
/* The following types are missing: wxMenuBar
    ADD_CLASS_METHOD(GetMenuBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#getmenubar")
*/
    ADD_CLASS_METHOD(ProcessCommand,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#processcommand")
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(CreateStatusBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#createstatusbar")
*/
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(OnCreateStatusBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#oncreatestatusbar")
*/
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(GetStatusBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#getstatusbar")
*/
/* The following types are missing: wxStatusBar
    ADD_CLASS_METHOD(SetStatusBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatusbar")
*/
    ADD_CLASS_METHOD(SetStatusText,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatustext")
    ADD_CLASS_METHOD(SetStatusWidths,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatuswidths")
    ADD_CLASS_METHOD(PushStatusText,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#pushstatustext")
    ADD_CLASS_METHOD(PopStatusText,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#popstatustext")
    ADD_CLASS_METHOD(SetStatusBarPane,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#setstatusbarpane")
    ADD_CLASS_METHOD(GetStatusBarPane,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#getstatusbarpane")
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(CreateToolBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#createtoolbar")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(OnCreateToolBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#oncreatetoolbar")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(GetToolBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#gettoolbar")
*/
/* The following types are missing: wxToolBar
    ADD_CLASS_METHOD(SetToolBar,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#settoolbar")
*/
/* The following types are missing: wxMenuEvent
    ADD_CLASS_METHOD(OnMenuOpen,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuopen")
*/
/* The following types are missing: wxMenuEvent
    ADD_CLASS_METHOD(OnMenuClose,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuclose")
*/
/* The following types are missing: wxMenuEvent
    ADD_CLASS_METHOD(OnMenuHighlight,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#onmenuhighlight")
*/
/* The following types are missing: wxMenu
    ADD_CLASS_METHOD(DoMenuUpdates,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#domenuupdates")
*/
    ADD_CLASS_METHOD(UpdateWindowUI,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#updatewindowui")
    ADD_CLASS_METHOD(OnInternalIdle,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#oninternalidle")
    ADD_CLASS_METHOD(DoGiveHelp,"http://docs.wxwidgets.org/stable/wx_wxframebase.html#dogivehelp")





    void AddMethods(WrapClass<wxFrameBase>::ptr this_ptr )
    {
      
      // Add members from wxTopLevelWindow
      WrapClass_wxTopLevelWindow::ptr parent_wxTopLevelWindow(        boost::dynamic_pointer_cast<WrapClass_wxTopLevelWindow >(this_ptr));
      parent_wxTopLevelWindow->AddMethods(parent_wxTopLevelWindow);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_New( this_ptr);
      AddVar_GetClientAreaOrigin( this_ptr);
      AddVar_SendSizeEvent( this_ptr);
/* The following types are missing: wxMenuBar
      AddVar_SetMenuBar( this_ptr);
*/
/* The following types are missing: wxMenuBar
      AddVar_GetMenuBar( this_ptr);
*/
      AddVar_ProcessCommand( this_ptr);
/* The following types are missing: wxStatusBar
      AddVar_CreateStatusBar( this_ptr);
*/
/* The following types are missing: wxStatusBar
      AddVar_OnCreateStatusBar( this_ptr);
*/
/* The following types are missing: wxStatusBar
      AddVar_GetStatusBar( this_ptr);
*/
/* The following types are missing: wxStatusBar
      AddVar_SetStatusBar( this_ptr);
*/
      AddVar_SetStatusText( this_ptr);
      AddVar_SetStatusWidths( this_ptr);
      AddVar_PushStatusText( this_ptr);
      AddVar_PopStatusText( this_ptr);
      AddVar_SetStatusBarPane( this_ptr);
      AddVar_GetStatusBarPane( this_ptr);
/* The following types are missing: wxToolBar
      AddVar_CreateToolBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_OnCreateToolBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_GetToolBar( this_ptr);
*/
/* The following types are missing: wxToolBar
      AddVar_SetToolBar( this_ptr);
*/
/* The following types are missing: wxMenuEvent
      AddVar_OnMenuOpen( this_ptr);
*/
/* The following types are missing: wxMenuEvent
      AddVar_OnMenuClose( this_ptr);
*/
/* The following types are missing: wxMenuEvent
      AddVar_OnMenuHighlight( this_ptr);
*/
/* The following types are missing: wxMenu
      AddVar_DoMenuUpdates( this_ptr);
*/
      AddVar_UpdateWindowUI( this_ptr);
      AddVar_OnInternalIdle( this_ptr);
      AddVar_DoGiveHelp( this_ptr);



      
    };
};


#endif // _wrap_wxFrameBase_h
