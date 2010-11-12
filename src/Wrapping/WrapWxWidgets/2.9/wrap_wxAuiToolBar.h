/**
 * C++ Interface: wrap_wxAuiToolBar
 *
 * Description: wrapping wxAuiToolBar
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBar_h_
#define _wrap_wxAuiToolBar_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"


AMI_DECLARE_TYPE(wxAuiToolBar);

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBar : public WrapClass<wxAuiToolBar>
    , public virtual WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxAuiToolBar);

  protected:
    typedef WrapClass<wxAuiToolBar>::ptr _parentclass_ptr;
    typedef wxAuiToolBar ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBar>& GetObj() const { return WrapClass<wxAuiToolBar>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBar(boost::shared_ptr<wxAuiToolBar > si): 
    WrapClass<wxAuiToolBar>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBar()
    {
      std::cout << "~WrapClass_wxAuiToolBar()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBar,"Wrapping of wxAuiToolBar, http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#wxauitoolbar.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBar*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetWindowStyleFlag,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setwindowstyleflag")
    ADD_CLASS_METHOD(GetWindowStyleFlag,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getwindowstyleflag")
    ADD_CLASS_METHOD(SetArtProvider,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setartprovider")
    ADD_CLASS_METHOD(GetArtProvider,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getartprovider")
    ADD_CLASS_METHOD(SetFont,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setfont")
    ADD_CLASS_METHOD(AddTool1,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool")
    ADD_CLASS_METHOD(AddTool,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool")
    ADD_CLASS_METHOD(AddTool2,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool")
    ADD_CLASS_METHOD(AddTool3,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool")
    ADD_CLASS_METHOD(AddLabel,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addlabel")
    ADD_CLASS_METHOD(AddControl,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addcontrol")
    ADD_CLASS_METHOD(AddSeparator,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addseparator")
    ADD_CLASS_METHOD(AddSpacer,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addspacer")
    ADD_CLASS_METHOD(AddStretchSpacer,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addstretchspacer")
    ADD_CLASS_METHOD(Realize,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#realize")
    ADD_CLASS_METHOD(FindControl,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findcontrol")
    ADD_CLASS_METHOD(FindToolByPosition,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtoolbyposition")
    ADD_CLASS_METHOD(FindToolByIndex,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtoolbyindex")
    ADD_CLASS_METHOD(FindTool,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtool")
    ADD_CLASS_METHOD(ClearTools,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#cleartools")
    ADD_CLASS_METHOD(Clear,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#clear")
    ADD_CLASS_METHOD(DeleteTool,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#deletetool")
    ADD_CLASS_METHOD(DeleteByIndex,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#deletebyindex")
    ADD_CLASS_METHOD(GetToolCount,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolcount")
    ADD_CLASS_METHOD(GetToolPos,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolpos")
    ADD_CLASS_METHOD(GetToolIndex,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolindex")
    ADD_CLASS_METHOD(GetToolFits,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolfits")
    ADD_CLASS_METHOD(GetToolRect,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolrect")
    ADD_CLASS_METHOD(GetToolFitsByIndex,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolfitsbyindex")
    ADD_CLASS_METHOD(GetToolBarFits,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbarfits")
    ADD_CLASS_METHOD(SetMargins1,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins")
    ADD_CLASS_METHOD(SetMargins,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins")
    ADD_CLASS_METHOD(SetMargins2,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins")
    ADD_CLASS_METHOD(SetMargins3,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins")
    ADD_CLASS_METHOD(SetToolBitmapSize,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolbitmapsize")
    ADD_CLASS_METHOD(GetToolBitmapSize,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbitmapsize")
    ADD_CLASS_METHOD(GetOverflowVisible,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getoverflowvisible")
    ADD_CLASS_METHOD(SetOverflowVisible,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setoverflowvisible")
    ADD_CLASS_METHOD(GetGripperVisible,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getgrippervisible")
    ADD_CLASS_METHOD(SetGripperVisible,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setgrippervisible")
    ADD_CLASS_METHOD(ToggleTool,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#toggletool")
    ADD_CLASS_METHOD(GetToolToggled,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooltoggled")
    ADD_CLASS_METHOD(EnableTool,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#enabletool")
    ADD_CLASS_METHOD(GetToolEnabled,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolenabled")
    ADD_CLASS_METHOD(SetToolDropDown,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settooldropdown")
    ADD_CLASS_METHOD(GetToolDropDown,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooldropdown")
    ADD_CLASS_METHOD(SetToolBorderPadding,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolborderpadding")
    ADD_CLASS_METHOD(GetToolBorderPadding,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolborderpadding")
    ADD_CLASS_METHOD(SetToolTextOrientation,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settooltextorientation")
    ADD_CLASS_METHOD(GetToolTextOrientation,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooltextorientation")
    ADD_CLASS_METHOD(SetToolPacking,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolpacking")
    ADD_CLASS_METHOD(GetToolPacking,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolpacking")
    ADD_CLASS_METHOD(SetToolProportion,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolproportion")
    ADD_CLASS_METHOD(GetToolProportion,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolproportion")
    ADD_CLASS_METHOD(SetToolSeparation,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolseparation")
    ADD_CLASS_METHOD(GetToolSeparation,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolseparation")
    ADD_CLASS_METHOD(SetToolSticky,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolsticky")
    ADD_CLASS_METHOD(GetToolSticky,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolsticky")
    ADD_CLASS_METHOD(GetToolLabel,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoollabel")
    ADD_CLASS_METHOD(SetToolLabel,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoollabel")
    ADD_CLASS_METHOD(GetToolBitmap,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbitmap")
    ADD_CLASS_METHOD(SetToolBitmap,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolbitmap")
    ADD_CLASS_METHOD(GetToolShortHelp,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolshorthelp")
    ADD_CLASS_METHOD(SetToolShortHelp,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolshorthelp")
    ADD_CLASS_METHOD(GetToolLongHelp,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoollonghelp")
    ADD_CLASS_METHOD(SetToolLongHelp,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoollonghelp")
    ADD_CLASS_METHOD(SetCustomOverflowItems,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setcustomoverflowitems")
    ADD_CLASS_METHOD(GetClassInfo,"http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getclassinfo")





    void AddMethods(WrapClass<wxAuiToolBar>::ptr this_ptr )
    {
      // here inheritence
      
      // Add members from wxControl
      WrapClass_wxControl::ptr parent_wxControl(        boost::dynamic_pointer_cast<WrapClass_wxControl>(this_ptr));
      parent_wxControl->AddMethods(parent_wxControl);


      // check that the method name is not a token
      
       // Adding standard methods 
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_GetWindowStyleFlag( this_ptr);
      AddVar_SetArtProvider( this_ptr);
      AddVar_GetArtProvider( this_ptr);
      AddVar_SetFont( this_ptr);
      AddVar_AddTool1( this_ptr);
      AddVar_AddTool( this_ptr);
      AddVar_AddTool2( this_ptr);
      AddVar_AddTool3( this_ptr);
      AddVar_AddLabel( this_ptr);
      AddVar_AddControl( this_ptr);
      AddVar_AddSeparator( this_ptr);
      AddVar_AddSpacer( this_ptr);
      AddVar_AddStretchSpacer( this_ptr);
      AddVar_Realize( this_ptr);
      AddVar_FindControl( this_ptr);
      AddVar_FindToolByPosition( this_ptr);
      AddVar_FindToolByIndex( this_ptr);
      AddVar_FindTool( this_ptr);
      AddVar_ClearTools( this_ptr);
      AddVar_Clear( this_ptr);
      AddVar_DeleteTool( this_ptr);
      AddVar_DeleteByIndex( this_ptr);
      AddVar_GetToolCount( this_ptr);
      AddVar_GetToolPos( this_ptr);
      AddVar_GetToolIndex( this_ptr);
      AddVar_GetToolFits( this_ptr);
      AddVar_GetToolRect( this_ptr);
      AddVar_GetToolFitsByIndex( this_ptr);
      AddVar_GetToolBarFits( this_ptr);
      AddVar_SetMargins1( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_SetMargins2( this_ptr);
      AddVar_SetMargins3( this_ptr);
      AddVar_SetToolBitmapSize( this_ptr);
      AddVar_GetToolBitmapSize( this_ptr);
      AddVar_GetOverflowVisible( this_ptr);
      AddVar_SetOverflowVisible( this_ptr);
      AddVar_GetGripperVisible( this_ptr);
      AddVar_SetGripperVisible( this_ptr);
      AddVar_ToggleTool( this_ptr);
      AddVar_GetToolToggled( this_ptr);
      AddVar_EnableTool( this_ptr);
      AddVar_GetToolEnabled( this_ptr);
      AddVar_SetToolDropDown( this_ptr);
      AddVar_GetToolDropDown( this_ptr);
      AddVar_SetToolBorderPadding( this_ptr);
      AddVar_GetToolBorderPadding( this_ptr);
      AddVar_SetToolTextOrientation( this_ptr);
      AddVar_GetToolTextOrientation( this_ptr);
      AddVar_SetToolPacking( this_ptr);
      AddVar_GetToolPacking( this_ptr);
      AddVar_SetToolProportion( this_ptr);
      AddVar_GetToolProportion( this_ptr);
      AddVar_SetToolSeparation( this_ptr);
      AddVar_GetToolSeparation( this_ptr);
      AddVar_SetToolSticky( this_ptr);
      AddVar_GetToolSticky( this_ptr);
      AddVar_GetToolLabel( this_ptr);
      AddVar_SetToolLabel( this_ptr);
      AddVar_GetToolBitmap( this_ptr);
      AddVar_SetToolBitmap( this_ptr);
      AddVar_GetToolShortHelp( this_ptr);
      AddVar_SetToolShortHelp( this_ptr);
      AddVar_GetToolLongHelp( this_ptr);
      AddVar_SetToolLongHelp( this_ptr);
      AddVar_SetCustomOverflowItems( this_ptr);
      AddVar_GetClassInfo( this_ptr);


    };
};


#endif // _wrap_wxAuiToolBar_h
