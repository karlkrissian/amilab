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
//#include "wrap_BaseClass1.h"
//#include "wrap_BaseClass2.h"
// ...


AMI_DECLARE_TYPE(wxAuiPaneInfo);

// TODO: check for inheritence ...
class WrapClass_wxAuiPaneInfo : public WrapClass<wxAuiPaneInfo>
// inheritence, public virtual WrapClass_BaseClass1, ...
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
    // inheritence WrapClass_BaseClass1(si), ... 
    WrapClass<wxAuiPaneInfo>(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiPaneInfo()
    {
      std::cout << "~WrapClass_wxAuiPaneInfo()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo,"Wrapping of $wxAuiPaneInfo.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiPaneInfo1,"Wrapping of $wxAuiPaneInfo.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiPaneInfo*);

    // here add each method
    
    ADD_CLASS_METHOD(SafeSet,"")
    ADD_CLASS_METHOD(IsOk,"")
    ADD_CLASS_METHOD(IsFixed,"")
    ADD_CLASS_METHOD(IsResizable,"")
    ADD_CLASS_METHOD(IsShown,"")
    ADD_CLASS_METHOD(IsFloating,"")
    ADD_CLASS_METHOD(IsDocked,"")
    ADD_CLASS_METHOD(IsToolbar,"")
    ADD_CLASS_METHOD(IsTopDockable,"")
    ADD_CLASS_METHOD(IsBottomDockable,"")
    ADD_CLASS_METHOD(IsLeftDockable,"")
    ADD_CLASS_METHOD(IsRightDockable,"")
    ADD_CLASS_METHOD(IsFloatable,"")
    ADD_CLASS_METHOD(IsMovable,"")
    ADD_CLASS_METHOD(IsDestroyOnClose,"")
    ADD_CLASS_METHOD(IsMaximized,"")
    ADD_CLASS_METHOD(HasCaption,"")
    ADD_CLASS_METHOD(HasGripper,"")
    ADD_CLASS_METHOD(HasBorder,"")
    ADD_CLASS_METHOD(HasCloseButton,"")
    ADD_CLASS_METHOD(HasMaximizeButton,"")
    ADD_CLASS_METHOD(HasMinimizeButton,"")
    ADD_CLASS_METHOD(HasPinButton,"")
    ADD_CLASS_METHOD(HasGripperTop,"")
    ADD_CLASS_METHOD(Window,"")
    ADD_CLASS_METHOD(Name,"")
    ADD_CLASS_METHOD(Caption,"")
    ADD_CLASS_METHOD(Left,"")
    ADD_CLASS_METHOD(Right,"")
    ADD_CLASS_METHOD(Top,"")
    ADD_CLASS_METHOD(Bottom,"")
    ADD_CLASS_METHOD(Center,"")
    ADD_CLASS_METHOD(Centre,"")
    ADD_CLASS_METHOD(Direction,"")
    ADD_CLASS_METHOD(Layer,"")
    ADD_CLASS_METHOD(Row,"")
    ADD_CLASS_METHOD(Position,"")
    ADD_CLASS_METHOD(BestSize,"")
    ADD_CLASS_METHOD(MinSize,"")
    ADD_CLASS_METHOD(MaxSize,"")
    ADD_CLASS_METHOD(BestSize1,"")
    ADD_CLASS_METHOD(MinSize1,"")
    ADD_CLASS_METHOD(MaxSize1,"")
    ADD_CLASS_METHOD(FloatingPosition,"")
    ADD_CLASS_METHOD(FloatingPosition1,"")
    ADD_CLASS_METHOD(FloatingSize,"")
    ADD_CLASS_METHOD(FloatingSize1,"")
    ADD_CLASS_METHOD(Fixed,"")
    ADD_CLASS_METHOD(Resizable,"")
    ADD_CLASS_METHOD(Dock,"")
    ADD_CLASS_METHOD(Float,"")
    ADD_CLASS_METHOD(Hide,"")
    ADD_CLASS_METHOD(Show,"")
    ADD_CLASS_METHOD(CaptionVisible,"")
    ADD_CLASS_METHOD(Maximize,"")
    ADD_CLASS_METHOD(Restore,"")
    ADD_CLASS_METHOD(PaneBorder,"")
    ADD_CLASS_METHOD(Gripper,"")
    ADD_CLASS_METHOD(GripperTop,"")
    ADD_CLASS_METHOD(CloseButton,"")
    ADD_CLASS_METHOD(MaximizeButton,"")
    ADD_CLASS_METHOD(MinimizeButton,"")
    ADD_CLASS_METHOD(PinButton,"")
    ADD_CLASS_METHOD(DestroyOnClose,"")
    ADD_CLASS_METHOD(TopDockable,"")
    ADD_CLASS_METHOD(BottomDockable,"")
    ADD_CLASS_METHOD(LeftDockable,"")
    ADD_CLASS_METHOD(RightDockable,"")
    ADD_CLASS_METHOD(Floatable,"")
    ADD_CLASS_METHOD(Movable,"")
    ADD_CLASS_METHOD(DockFixed,"")
    ADD_CLASS_METHOD(Dockable,"")
    ADD_CLASS_METHOD(DefaultPane,"")
    ADD_CLASS_METHOD(CentrePane,"")
    ADD_CLASS_METHOD(CenterPane,"")
    ADD_CLASS_METHOD(ToolbarPane,"")
    ADD_CLASS_METHOD(SetFlag,"")
    ADD_CLASS_METHOD(HasFlag,"")




    void AddMethods(WrapClass<wxAuiPaneInfo>::ptr this_ptr )
    {
      // here inheritence
      // Add members from wxWindow
      //WrapClass_BaseClass1::ptr parent_obj(
      //  boost::dynamic_pointer_cast<WrapClass_BaseClass1>(this_ptr));
      //parent_obj->AddMethods(parent_obj);

      // check that the method name is not a token
      
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
      AddVar_BestSize( this_ptr);
      AddVar_MinSize( this_ptr);
      AddVar_MaxSize( this_ptr);
      AddVar_BestSize1( this_ptr);
      AddVar_MinSize1( this_ptr);
      AddVar_MaxSize1( this_ptr);
      AddVar_FloatingPosition( this_ptr);
      AddVar_FloatingPosition1( this_ptr);
      AddVar_FloatingSize( this_ptr);
      AddVar_FloatingSize1( this_ptr);
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


    };
};


#endif // _wrap_wxAuiPaneInfo_h
