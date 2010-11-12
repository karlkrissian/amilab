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

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiPaneInfo);

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
      std::cout << "~WrapClass_wxAuiPaneInfo()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo1,"Wrapping of wxAuiPaneInfo, http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo,"Wrapping of wxAuiPaneInfo, http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo2,"Wrapping of wxAuiPaneInfo, http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#wxauipaneinfo.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiPaneInfo*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SafeSet,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#safeset")
    ADD_CLASS_METHOD(IsOk,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isok")
    ADD_CLASS_METHOD(IsFixed,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfixed")
    ADD_CLASS_METHOD(IsResizable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isresizable")
    ADD_CLASS_METHOD(IsShown,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isshown")
    ADD_CLASS_METHOD(IsFloating,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfloating")
    ADD_CLASS_METHOD(IsDocked,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isdocked")
    ADD_CLASS_METHOD(IsToolbar,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#istoolbar")
    ADD_CLASS_METHOD(IsTopDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#istopdockable")
    ADD_CLASS_METHOD(IsBottomDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isbottomdockable")
    ADD_CLASS_METHOD(IsLeftDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isleftdockable")
    ADD_CLASS_METHOD(IsRightDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isrightdockable")
    ADD_CLASS_METHOD(IsFloatable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isfloatable")
    ADD_CLASS_METHOD(IsMovable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#ismovable")
    ADD_CLASS_METHOD(IsDestroyOnClose,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#isdestroyonclose")
    ADD_CLASS_METHOD(IsMaximized,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#ismaximized")
    ADD_CLASS_METHOD(HasCaption,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hascaption")
    ADD_CLASS_METHOD(HasGripper,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasgripper")
    ADD_CLASS_METHOD(HasBorder,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasborder")
    ADD_CLASS_METHOD(HasCloseButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasclosebutton")
    ADD_CLASS_METHOD(HasMaximizeButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasmaximizebutton")
    ADD_CLASS_METHOD(HasMinimizeButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasminimizebutton")
    ADD_CLASS_METHOD(HasPinButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#haspinbutton")
    ADD_CLASS_METHOD(HasGripperTop,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasgrippertop")
    ADD_CLASS_METHOD(Window,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#window")
    ADD_CLASS_METHOD(Name,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#name")
    ADD_CLASS_METHOD(Caption,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#caption")
    ADD_CLASS_METHOD(Left,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#left")
    ADD_CLASS_METHOD(Right,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#right")
    ADD_CLASS_METHOD(Top,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#top")
    ADD_CLASS_METHOD(Bottom,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bottom")
    ADD_CLASS_METHOD(Center,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#center")
    ADD_CLASS_METHOD(Centre,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centre")
    ADD_CLASS_METHOD(Direction,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#direction")
    ADD_CLASS_METHOD(Layer,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#layer")
    ADD_CLASS_METHOD(Row,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#row")
    ADD_CLASS_METHOD(Position,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#position")
    ADD_CLASS_METHOD(BestSize1,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize")
    ADD_CLASS_METHOD(MinSize1,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize")
    ADD_CLASS_METHOD(MaxSize1,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize")
    ADD_CLASS_METHOD(BestSize,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize")
    ADD_CLASS_METHOD(BestSize2,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bestsize")
    ADD_CLASS_METHOD(MinSize,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize")
    ADD_CLASS_METHOD(MinSize2,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minsize")
    ADD_CLASS_METHOD(MaxSize,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize")
    ADD_CLASS_METHOD(MaxSize2,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maxsize")
    ADD_CLASS_METHOD(FloatingPosition1,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition")
    ADD_CLASS_METHOD(FloatingPosition,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition")
    ADD_CLASS_METHOD(FloatingPosition2,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingposition")
    ADD_CLASS_METHOD(FloatingSize1,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize")
    ADD_CLASS_METHOD(FloatingSize,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize")
    ADD_CLASS_METHOD(FloatingSize2,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatingsize")
    ADD_CLASS_METHOD(Fixed,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#fixed")
    ADD_CLASS_METHOD(Resizable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#resizable")
    ADD_CLASS_METHOD(Dock,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dock")
    ADD_CLASS_METHOD(Float,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#float")
    ADD_CLASS_METHOD(Hide,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hide")
    ADD_CLASS_METHOD(Show,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#show")
    ADD_CLASS_METHOD(CaptionVisible,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#captionvisible")
    ADD_CLASS_METHOD(Maximize,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maximize")
    ADD_CLASS_METHOD(Restore,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#restore")
    ADD_CLASS_METHOD(PaneBorder,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#paneborder")
    ADD_CLASS_METHOD(Gripper,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#gripper")
    ADD_CLASS_METHOD(GripperTop,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#grippertop")
    ADD_CLASS_METHOD(CloseButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#closebutton")
    ADD_CLASS_METHOD(MaximizeButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#maximizebutton")
    ADD_CLASS_METHOD(MinimizeButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#minimizebutton")
    ADD_CLASS_METHOD(PinButton,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#pinbutton")
    ADD_CLASS_METHOD(DestroyOnClose,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#destroyonclose")
    ADD_CLASS_METHOD(TopDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#topdockable")
    ADD_CLASS_METHOD(BottomDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#bottomdockable")
    ADD_CLASS_METHOD(LeftDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#leftdockable")
    ADD_CLASS_METHOD(RightDockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#rightdockable")
    ADD_CLASS_METHOD(Floatable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#floatable")
    ADD_CLASS_METHOD(Movable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#movable")
    ADD_CLASS_METHOD(DockFixed,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dockfixed")
    ADD_CLASS_METHOD(Dockable,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#dockable")
    ADD_CLASS_METHOD(DefaultPane,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#defaultpane")
    ADD_CLASS_METHOD(CentrePane,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centrepane")
    ADD_CLASS_METHOD(CenterPane,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#centerpane")
    ADD_CLASS_METHOD(ToolbarPane,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#toolbarpane")
    ADD_CLASS_METHOD(SetFlag,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#setflag")
    ADD_CLASS_METHOD(HasFlag,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#hasflag")

    // Operators:
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxauipaneinfo.html#assign")




    void AddMethods(WrapClass<wxAuiPaneInfo>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
       // Adding standard methods 
      AddVar_SafeSet( this_ptr);
      AddVar_IsOk( this_ptr);
      AddVar_IsFixed( this_ptr);
      AddVar_IsResizable( this_ptr);
      AddVar_IsShown( this_ptr);
      AddVar_IsFloating( this_ptr);
      AddVar_IsDocked( this_ptr);
      AddVar_IsToolbar( this_ptr);
      AddVar_IsTopDockable( this_ptr);
      AddVar_IsBottomDockable( this_ptr);
      AddVar_IsLeftDockable( this_ptr);
      AddVar_IsRightDockable( this_ptr);
      AddVar_IsFloatable( this_ptr);
      AddVar_IsMovable( this_ptr);
      AddVar_IsDestroyOnClose( this_ptr);
      AddVar_IsMaximized( this_ptr);
      AddVar_HasCaption( this_ptr);
      AddVar_HasGripper( this_ptr);
      AddVar_HasBorder( this_ptr);
      AddVar_HasCloseButton( this_ptr);
      AddVar_HasMaximizeButton( this_ptr);
      AddVar_HasMinimizeButton( this_ptr);
      AddVar_HasPinButton( this_ptr);
      AddVar_HasGripperTop( this_ptr);
      AddVar_Window( this_ptr);
      AddVar_Name( this_ptr);
      AddVar_Caption( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_Top( this_ptr);
      AddVar_Bottom( this_ptr);
      AddVar_Center( this_ptr);
      AddVar_Centre( this_ptr);
      AddVar_Direction( this_ptr);
      AddVar_Layer( this_ptr);
      AddVar_Row( this_ptr);
      AddVar_Position( this_ptr);
      AddVar_BestSize1( this_ptr);
      AddVar_MinSize1( this_ptr);
      AddVar_MaxSize1( this_ptr);
      AddVar_BestSize( this_ptr);
      AddVar_BestSize2( this_ptr);
      AddVar_MinSize( this_ptr);
      AddVar_MinSize2( this_ptr);
      AddVar_MaxSize( this_ptr);
      AddVar_MaxSize2( this_ptr);
      AddVar_FloatingPosition1( this_ptr);
      AddVar_FloatingPosition( this_ptr);
      AddVar_FloatingPosition2( this_ptr);
      AddVar_FloatingSize1( this_ptr);
      AddVar_FloatingSize( this_ptr);
      AddVar_FloatingSize2( this_ptr);
      AddVar_Fixed( this_ptr);
      AddVar_Resizable( this_ptr);
      AddVar_Dock( this_ptr);
      AddVar_Float( this_ptr);
      AddVar_Hide( this_ptr);
      AddVar_Show( this_ptr);
      AddVar_CaptionVisible( this_ptr);
      AddVar_Maximize( this_ptr);
      AddVar_Restore( this_ptr);
      AddVar_PaneBorder( this_ptr);
      AddVar_Gripper( this_ptr);
      AddVar_GripperTop( this_ptr);
      AddVar_CloseButton( this_ptr);
      AddVar_MaximizeButton( this_ptr);
      AddVar_MinimizeButton( this_ptr);
      AddVar_PinButton( this_ptr);
      AddVar_DestroyOnClose( this_ptr);
      AddVar_TopDockable( this_ptr);
      AddVar_BottomDockable( this_ptr);
      AddVar_LeftDockable( this_ptr);
      AddVar_RightDockable( this_ptr);
      AddVar_Floatable( this_ptr);
      AddVar_Movable( this_ptr);
      AddVar_DockFixed( this_ptr);
      AddVar_Dockable( this_ptr);
      AddVar_DefaultPane( this_ptr);
      AddVar_CentrePane( this_ptr);
      AddVar_CenterPane( this_ptr);
      AddVar_ToolbarPane( this_ptr);
      AddVar_SetFlag( this_ptr);
      AddVar_HasFlag( this_ptr);

      // Adding operators
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxAuiPaneInfo_h
