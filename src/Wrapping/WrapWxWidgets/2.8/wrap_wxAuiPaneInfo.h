/**
 * C++ Interface: wrap_wxAuiPaneInfo
 *
 * Description: wrapping wxAuiPaneInfo
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiPaneInfo_h_
#define _wrap_wxAuiPaneInfo_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxAuiPaneInfo_declared
  #define wxAuiPaneInfo_declared
  AMI_DECLARE_TYPE(wxAuiPaneInfo);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiPaneInfo : public WrapClass<wxAuiPaneInfo>
    
{
  DEFINE_CLASS(WrapClass_wxAuiPaneInfo);

  protected:
    typedef WrapClass<wxAuiPaneInfo>::ptr _parentclass_ptr;
    typedef wxAuiPaneInfo ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiPaneInfo>& GetObj() const { return WrapClass<wxAuiPaneInfo>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiPaneInfo(boost::shared_ptr<wxAuiPaneInfo > si): 
    WrapClass<wxAuiPaneInfo>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiPaneInfo()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo_1,"Constructor wxAuiPaneInfo::wxAuiPaneInfo() (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo,"Constructor wxAuiPaneInfo::wxAuiPaneInfo() (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo_2,"Constructor wxAuiPaneInfo::wxAuiPaneInfo(wxAuiPaneInfo const & c) (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiPaneInfo*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SafeSet,"void wxAuiPaneInfo::SafeSet(wxAuiPaneInfo source)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#safeset)")
    ADD_CLASS_METHOD(IsOk,"bool wxAuiPaneInfo::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isok)")
    ADD_CLASS_METHOD(IsFixed,"bool wxAuiPaneInfo::IsFixed()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfixed)")
    ADD_CLASS_METHOD(IsResizable,"bool wxAuiPaneInfo::IsResizable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isresizable)")
    ADD_CLASS_METHOD(IsShown,"bool wxAuiPaneInfo::IsShown()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isshown)")
    ADD_CLASS_METHOD(IsFloating,"bool wxAuiPaneInfo::IsFloating()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfloating)")
    ADD_CLASS_METHOD(IsDocked,"bool wxAuiPaneInfo::IsDocked()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isdocked)")
    ADD_CLASS_METHOD(IsToolbar,"bool wxAuiPaneInfo::IsToolbar()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#istoolbar)")
    ADD_CLASS_METHOD(IsTopDockable,"bool wxAuiPaneInfo::IsTopDockable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#istopdockable)")
    ADD_CLASS_METHOD(IsBottomDockable,"bool wxAuiPaneInfo::IsBottomDockable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isbottomdockable)")
    ADD_CLASS_METHOD(IsLeftDockable,"bool wxAuiPaneInfo::IsLeftDockable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isleftdockable)")
    ADD_CLASS_METHOD(IsRightDockable,"bool wxAuiPaneInfo::IsRightDockable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isrightdockable)")
    ADD_CLASS_METHOD(IsFloatable,"bool wxAuiPaneInfo::IsFloatable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfloatable)")
    ADD_CLASS_METHOD(IsMovable,"bool wxAuiPaneInfo::IsMovable()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#ismovable)")
    ADD_CLASS_METHOD(IsDestroyOnClose,"bool wxAuiPaneInfo::IsDestroyOnClose()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isdestroyonclose)")
    ADD_CLASS_METHOD(IsMaximized,"bool wxAuiPaneInfo::IsMaximized()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#ismaximized)")
    ADD_CLASS_METHOD(HasCaption,"bool wxAuiPaneInfo::HasCaption()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hascaption)")
    ADD_CLASS_METHOD(HasGripper,"bool wxAuiPaneInfo::HasGripper()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasgripper)")
    ADD_CLASS_METHOD(HasBorder,"bool wxAuiPaneInfo::HasBorder()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasborder)")
    ADD_CLASS_METHOD(HasCloseButton,"bool wxAuiPaneInfo::HasCloseButton()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasclosebutton)")
    ADD_CLASS_METHOD(HasMaximizeButton,"bool wxAuiPaneInfo::HasMaximizeButton()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasmaximizebutton)")
    ADD_CLASS_METHOD(HasMinimizeButton,"bool wxAuiPaneInfo::HasMinimizeButton()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasminimizebutton)")
    ADD_CLASS_METHOD(HasPinButton,"bool wxAuiPaneInfo::HasPinButton()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#haspinbutton)")
    ADD_CLASS_METHOD(HasGripperTop,"bool wxAuiPaneInfo::HasGripperTop()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasgrippertop)")
    ADD_CLASS_METHOD(Window,"wxAuiPaneInfo & wxAuiPaneInfo::Window(wxWindow * w)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#window)")
    ADD_CLASS_METHOD(Name,"wxAuiPaneInfo & wxAuiPaneInfo::Name(wxString const & n)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#name)")
    ADD_CLASS_METHOD(Caption,"wxAuiPaneInfo & wxAuiPaneInfo::Caption(wxString const & c)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#caption)")
    ADD_CLASS_METHOD(Left,"wxAuiPaneInfo & wxAuiPaneInfo::Left()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#left)")
    ADD_CLASS_METHOD(Right,"wxAuiPaneInfo & wxAuiPaneInfo::Right()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#right)")
    ADD_CLASS_METHOD(Top,"wxAuiPaneInfo & wxAuiPaneInfo::Top()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#top)")
    ADD_CLASS_METHOD(Bottom,"wxAuiPaneInfo & wxAuiPaneInfo::Bottom()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bottom)")
    ADD_CLASS_METHOD(Center,"wxAuiPaneInfo & wxAuiPaneInfo::Center()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#center)")
    ADD_CLASS_METHOD(Centre,"wxAuiPaneInfo & wxAuiPaneInfo::Centre()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centre)")
    ADD_CLASS_METHOD(Direction,"wxAuiPaneInfo & wxAuiPaneInfo::Direction(int direction)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#direction)")
    ADD_CLASS_METHOD(Layer,"wxAuiPaneInfo & wxAuiPaneInfo::Layer(int layer)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#layer)")
    ADD_CLASS_METHOD(Row,"wxAuiPaneInfo & wxAuiPaneInfo::Row(int row)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#row)")
    ADD_CLASS_METHOD(Position,"wxAuiPaneInfo & wxAuiPaneInfo::Position(int pos)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#position)")
    ADD_CLASS_METHOD(BestSize_1,"wxAuiPaneInfo & wxAuiPaneInfo::BestSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize)")
    ADD_CLASS_METHOD(MinSize_1,"wxAuiPaneInfo & wxAuiPaneInfo::MinSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize)")
    ADD_CLASS_METHOD(MaxSize_1,"wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize)")
    ADD_CLASS_METHOD(BestSize,"wxAuiPaneInfo::BestSize()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize)")
    ADD_CLASS_METHOD(BestSize_2,"wxAuiPaneInfo & wxAuiPaneInfo::BestSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize)")
    ADD_CLASS_METHOD(MinSize,"wxAuiPaneInfo::MinSize()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize)")
    ADD_CLASS_METHOD(MinSize_2,"wxAuiPaneInfo & wxAuiPaneInfo::MinSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize)")
    ADD_CLASS_METHOD(MaxSize,"wxAuiPaneInfo::MaxSize()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize)")
    ADD_CLASS_METHOD(MaxSize_2,"wxAuiPaneInfo & wxAuiPaneInfo::MaxSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize)")
    ADD_CLASS_METHOD(FloatingPosition_1,"wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition)")
    ADD_CLASS_METHOD(FloatingPosition,"wxAuiPaneInfo::FloatingPosition()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition)")
    ADD_CLASS_METHOD(FloatingPosition_2,"wxAuiPaneInfo & wxAuiPaneInfo::FloatingPosition(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition)")
    ADD_CLASS_METHOD(FloatingSize_1,"wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize)")
    ADD_CLASS_METHOD(FloatingSize,"wxAuiPaneInfo::FloatingSize()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize)")
    ADD_CLASS_METHOD(FloatingSize_2,"wxAuiPaneInfo & wxAuiPaneInfo::FloatingSize(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize)")
    ADD_CLASS_METHOD(Fixed,"wxAuiPaneInfo & wxAuiPaneInfo::Fixed()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#fixed)")
    ADD_CLASS_METHOD(Resizable,"wxAuiPaneInfo & wxAuiPaneInfo::Resizable(bool resizable = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#resizable)")
    ADD_CLASS_METHOD(Dock,"wxAuiPaneInfo & wxAuiPaneInfo::Dock()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dock)")
    ADD_CLASS_METHOD(Float,"wxAuiPaneInfo & wxAuiPaneInfo::Float()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#float)")
    ADD_CLASS_METHOD(Hide,"wxAuiPaneInfo & wxAuiPaneInfo::Hide()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hide)")
    ADD_CLASS_METHOD(Show,"wxAuiPaneInfo & wxAuiPaneInfo::Show(bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#show)")
    ADD_CLASS_METHOD(CaptionVisible,"wxAuiPaneInfo & wxAuiPaneInfo::CaptionVisible(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#captionvisible)")
    ADD_CLASS_METHOD(Maximize,"wxAuiPaneInfo & wxAuiPaneInfo::Maximize()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maximize)")
    ADD_CLASS_METHOD(Restore,"wxAuiPaneInfo & wxAuiPaneInfo::Restore()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#restore)")
    ADD_CLASS_METHOD(PaneBorder,"wxAuiPaneInfo & wxAuiPaneInfo::PaneBorder(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#paneborder)")
    ADD_CLASS_METHOD(Gripper,"wxAuiPaneInfo & wxAuiPaneInfo::Gripper(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#gripper)")
    ADD_CLASS_METHOD(GripperTop,"wxAuiPaneInfo & wxAuiPaneInfo::GripperTop(bool attop = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#grippertop)")
    ADD_CLASS_METHOD(CloseButton,"wxAuiPaneInfo & wxAuiPaneInfo::CloseButton(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#closebutton)")
    ADD_CLASS_METHOD(MaximizeButton,"wxAuiPaneInfo & wxAuiPaneInfo::MaximizeButton(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maximizebutton)")
    ADD_CLASS_METHOD(MinimizeButton,"wxAuiPaneInfo & wxAuiPaneInfo::MinimizeButton(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minimizebutton)")
    ADD_CLASS_METHOD(PinButton,"wxAuiPaneInfo & wxAuiPaneInfo::PinButton(bool visible = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#pinbutton)")
    ADD_CLASS_METHOD(DestroyOnClose,"wxAuiPaneInfo & wxAuiPaneInfo::DestroyOnClose(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#destroyonclose)")
    ADD_CLASS_METHOD(TopDockable,"wxAuiPaneInfo & wxAuiPaneInfo::TopDockable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#topdockable)")
    ADD_CLASS_METHOD(BottomDockable,"wxAuiPaneInfo & wxAuiPaneInfo::BottomDockable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bottomdockable)")
    ADD_CLASS_METHOD(LeftDockable,"wxAuiPaneInfo & wxAuiPaneInfo::LeftDockable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#leftdockable)")
    ADD_CLASS_METHOD(RightDockable,"wxAuiPaneInfo & wxAuiPaneInfo::RightDockable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#rightdockable)")
    ADD_CLASS_METHOD(Floatable,"wxAuiPaneInfo & wxAuiPaneInfo::Floatable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatable)")
    ADD_CLASS_METHOD(Movable,"wxAuiPaneInfo & wxAuiPaneInfo::Movable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#movable)")
    ADD_CLASS_METHOD(DockFixed,"wxAuiPaneInfo & wxAuiPaneInfo::DockFixed(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dockfixed)")
    ADD_CLASS_METHOD(Dockable,"wxAuiPaneInfo & wxAuiPaneInfo::Dockable(bool b = true)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dockable)")
    ADD_CLASS_METHOD(DefaultPane,"wxAuiPaneInfo & wxAuiPaneInfo::DefaultPane()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#defaultpane)")
    ADD_CLASS_METHOD(CentrePane,"wxAuiPaneInfo & wxAuiPaneInfo::CentrePane()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centrepane)")
    ADD_CLASS_METHOD(CenterPane,"wxAuiPaneInfo & wxAuiPaneInfo::CenterPane()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centerpane)")
    ADD_CLASS_METHOD(ToolbarPane,"wxAuiPaneInfo & wxAuiPaneInfo::ToolbarPane()  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#toolbarpane)")
    ADD_CLASS_METHOD(SetFlag,"wxAuiPaneInfo & wxAuiPaneInfo::SetFlag(unsigned int flag, bool option_state)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#setflag)")
    ADD_CLASS_METHOD(HasFlag,"bool wxAuiPaneInfo::HasFlag(unsigned int flag)  (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasflag)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiPaneInfo & wxAuiPaneInfo::operator =(wxAuiPaneInfo const & c) (http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#__assign__)")




    void AddMethods(WrapClass<wxAuiPaneInfo>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiPaneInfo_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiPaneInfo_h
