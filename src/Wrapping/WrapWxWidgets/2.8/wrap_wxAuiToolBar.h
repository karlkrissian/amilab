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

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"


#ifndef wxAuiToolBar_declared
  #define wxAuiToolBar_declared
  AMI_DECLARE_TYPE(wxAuiToolBar);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBar : public WrapClass<wxAuiToolBar>
    , public   WrapClass_wxControl
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
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBar,"Constructor wxAuiToolBar::wxAuiToolBar(wxWindow * parent, wxWindowID id = -0x00000000000000001, wxPoint const & position = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = wxAUI_TB_DEFAULT_STYLE) (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#wxauitoolbar).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBar*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetWindowStyleFlag,"void wxAuiToolBar::SetWindowStyleFlag(long int style)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setwindowstyleflag)")
    ADD_CLASS_METHOD(GetWindowStyleFlag,"long int wxAuiToolBar::GetWindowStyleFlag()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getwindowstyleflag)")
    ADD_CLASS_METHOD(SetArtProvider,"void wxAuiToolBar::SetArtProvider(wxAuiToolBarArt * art)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setartprovider)")
    ADD_CLASS_METHOD(GetArtProvider,"wxAuiToolBarArt * wxAuiToolBar::GetArtProvider()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getartprovider)")
    ADD_CLASS_METHOD(SetFont,"bool wxAuiToolBar::SetFont(wxFont const & font)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setfont)")
    ADD_CLASS_METHOD(AddTool_1,"void wxAuiToolBar::AddTool(int tool_id, wxString const & label, wxBitmap const & bitmap, wxString const & short_help_string = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool)")
    ADD_CLASS_METHOD(AddTool,"wxAuiToolBar::AddTool()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool)")
    ADD_CLASS_METHOD(AddTool_2,"void wxAuiToolBar::AddTool(int tool_id, wxString const & label, wxBitmap const & bitmap, wxBitmap const & disabled_bitmap, wxItemKind kind, wxString const & short_help_string, wxString const & long_help_string, wxObject * client_data)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool)")
    ADD_CLASS_METHOD(AddTool_3,"void wxAuiToolBar::AddTool(int tool_id, wxBitmap const & bitmap, wxBitmap const & disabled_bitmap, bool toggle = false, wxObject * client_data = 0l, wxString const & short_help_string = wxEmptyString, wxString const & long_help_string = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addtool)")
    ADD_CLASS_METHOD(AddLabel,"void wxAuiToolBar::AddLabel(int tool_id, wxString const & label = wxEmptyString, int const width = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addlabel)")
    ADD_CLASS_METHOD(AddControl,"void wxAuiToolBar::AddControl(wxControl * control, wxString const & label = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addcontrol)")
    ADD_CLASS_METHOD(AddSeparator,"void wxAuiToolBar::AddSeparator()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addseparator)")
    ADD_CLASS_METHOD(AddSpacer,"void wxAuiToolBar::AddSpacer(int pixels)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addspacer)")
    ADD_CLASS_METHOD(AddStretchSpacer,"void wxAuiToolBar::AddStretchSpacer(int proportion = 1)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#addstretchspacer)")
    ADD_CLASS_METHOD(Realize,"bool wxAuiToolBar::Realize()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#realize)")
    ADD_CLASS_METHOD(FindControl,"wxControl * wxAuiToolBar::FindControl(int window_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findcontrol)")
    ADD_CLASS_METHOD(FindToolByPosition,"wxAuiToolBarItem * wxAuiToolBar::FindToolByPosition(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtoolbyposition)")
    ADD_CLASS_METHOD(FindToolByIndex,"wxAuiToolBarItem * wxAuiToolBar::FindToolByIndex(int idx)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtoolbyindex)")
    ADD_CLASS_METHOD(FindTool,"wxAuiToolBarItem * wxAuiToolBar::FindTool(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#findtool)")
    ADD_CLASS_METHOD(ClearTools,"void wxAuiToolBar::ClearTools()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#cleartools)")
    ADD_CLASS_METHOD(Clear,"void wxAuiToolBar::Clear()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#clear)")
    ADD_CLASS_METHOD(DeleteTool,"bool wxAuiToolBar::DeleteTool(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#deletetool)")
    ADD_CLASS_METHOD(DeleteByIndex,"bool wxAuiToolBar::DeleteByIndex(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#deletebyindex)")
    ADD_CLASS_METHOD(GetToolCount,"size_t wxAuiToolBar::GetToolCount()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolcount)")
    ADD_CLASS_METHOD(GetToolPos,"int wxAuiToolBar::GetToolPos(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolpos)")
    ADD_CLASS_METHOD(GetToolIndex,"int wxAuiToolBar::GetToolIndex(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolindex)")
    ADD_CLASS_METHOD(GetToolFits,"bool wxAuiToolBar::GetToolFits(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolfits)")
    ADD_CLASS_METHOD(GetToolRect,"wxRect wxAuiToolBar::GetToolRect(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolrect)")
    ADD_CLASS_METHOD(GetToolFitsByIndex,"bool wxAuiToolBar::GetToolFitsByIndex(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolfitsbyindex)")
    ADD_CLASS_METHOD(GetToolBarFits,"bool wxAuiToolBar::GetToolBarFits()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbarfits)")
    ADD_CLASS_METHOD(SetMargins_1,"void wxAuiToolBar::SetMargins(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetMargins,"wxAuiToolBar::SetMargins()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetMargins_2,"void wxAuiToolBar::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetMargins_3,"void wxAuiToolBar::SetMargins(int left, int right, int top, int bottom)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setmargins)")
    ADD_CLASS_METHOD(SetToolBitmapSize,"void wxAuiToolBar::SetToolBitmapSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolbitmapsize)")
    ADD_CLASS_METHOD(GetToolBitmapSize,"wxSize wxAuiToolBar::GetToolBitmapSize()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbitmapsize)")
    ADD_CLASS_METHOD(GetOverflowVisible,"bool wxAuiToolBar::GetOverflowVisible()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getoverflowvisible)")
    ADD_CLASS_METHOD(SetOverflowVisible,"void wxAuiToolBar::SetOverflowVisible(bool visible)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setoverflowvisible)")
    ADD_CLASS_METHOD(GetGripperVisible,"bool wxAuiToolBar::GetGripperVisible()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getgrippervisible)")
    ADD_CLASS_METHOD(SetGripperVisible,"void wxAuiToolBar::SetGripperVisible(bool visible)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setgrippervisible)")
    ADD_CLASS_METHOD(ToggleTool,"void wxAuiToolBar::ToggleTool(int tool_id, bool state)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#toggletool)")
    ADD_CLASS_METHOD(GetToolToggled,"bool wxAuiToolBar::GetToolToggled(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooltoggled)")
    ADD_CLASS_METHOD(EnableTool,"void wxAuiToolBar::EnableTool(int tool_id, bool state)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#enabletool)")
    ADD_CLASS_METHOD(GetToolEnabled,"bool wxAuiToolBar::GetToolEnabled(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolenabled)")
    ADD_CLASS_METHOD(SetToolDropDown,"void wxAuiToolBar::SetToolDropDown(int tool_id, bool dropdown)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settooldropdown)")
    ADD_CLASS_METHOD(GetToolDropDown,"bool wxAuiToolBar::GetToolDropDown(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooldropdown)")
    ADD_CLASS_METHOD(SetToolBorderPadding,"void wxAuiToolBar::SetToolBorderPadding(int padding)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolborderpadding)")
    ADD_CLASS_METHOD(GetToolBorderPadding,"int wxAuiToolBar::GetToolBorderPadding()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolborderpadding)")
    ADD_CLASS_METHOD(SetToolTextOrientation,"void wxAuiToolBar::SetToolTextOrientation(int orientation)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settooltextorientation)")
    ADD_CLASS_METHOD(GetToolTextOrientation,"int wxAuiToolBar::GetToolTextOrientation()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettooltextorientation)")
    ADD_CLASS_METHOD(SetToolPacking,"void wxAuiToolBar::SetToolPacking(int packing)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolpacking)")
    ADD_CLASS_METHOD(GetToolPacking,"int wxAuiToolBar::GetToolPacking()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolpacking)")
    ADD_CLASS_METHOD(SetToolProportion,"void wxAuiToolBar::SetToolProportion(int tool_id, int proportion)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolproportion)")
    ADD_CLASS_METHOD(GetToolProportion,"int wxAuiToolBar::GetToolProportion(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolproportion)")
    ADD_CLASS_METHOD(SetToolSeparation,"void wxAuiToolBar::SetToolSeparation(int separation)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolseparation)")
    ADD_CLASS_METHOD(GetToolSeparation,"int wxAuiToolBar::GetToolSeparation()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolseparation)")
    ADD_CLASS_METHOD(SetToolSticky,"void wxAuiToolBar::SetToolSticky(int tool_id, bool sticky)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolsticky)")
    ADD_CLASS_METHOD(GetToolSticky,"bool wxAuiToolBar::GetToolSticky(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolsticky)")
    ADD_CLASS_METHOD(GetToolLabel,"wxString wxAuiToolBar::GetToolLabel(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoollabel)")
    ADD_CLASS_METHOD(SetToolLabel,"void wxAuiToolBar::SetToolLabel(int tool_id, wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoollabel)")
    ADD_CLASS_METHOD(GetToolBitmap,"wxBitmap wxAuiToolBar::GetToolBitmap(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolbitmap)")
    ADD_CLASS_METHOD(SetToolBitmap,"void wxAuiToolBar::SetToolBitmap(int tool_id, wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolbitmap)")
    ADD_CLASS_METHOD(GetToolShortHelp,"wxString wxAuiToolBar::GetToolShortHelp(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoolshorthelp)")
    ADD_CLASS_METHOD(SetToolShortHelp,"void wxAuiToolBar::SetToolShortHelp(int tool_id, wxString const & help_string)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoolshorthelp)")
    ADD_CLASS_METHOD(GetToolLongHelp,"wxString wxAuiToolBar::GetToolLongHelp(int tool_id)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#gettoollonghelp)")
    ADD_CLASS_METHOD(SetToolLongHelp,"void wxAuiToolBar::SetToolLongHelp(int tool_id, wxString const & help_string)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#settoollonghelp)")
    ADD_CLASS_METHOD(SetCustomOverflowItems,"void wxAuiToolBar::SetCustomOverflowItems(wxAuiToolBarItemArray const & prepend, wxAuiToolBarItemArray const & append)  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#setcustomoverflowitems)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAuiToolBar::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxauitoolbar.html#getclassinfo)")





    void AddMethods(WrapClass<wxAuiToolBar>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiToolBar_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiToolBar_h
