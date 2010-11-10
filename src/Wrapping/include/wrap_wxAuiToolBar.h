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
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBar,"Wrapping of wxAuiToolBar.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBar*);

    // here add each method
    
    ADD_CLASS_METHOD(SetWindowStyleFlag,"")
    ADD_CLASS_METHOD(GetWindowStyleFlag,"")
    ADD_CLASS_METHOD(SetArtProvider,"")
    ADD_CLASS_METHOD(GetArtProvider,"")
    ADD_CLASS_METHOD(SetFont,"")
/* The following types are missing: wxItemKind
    ADD_CLASS_METHOD(AddTool,"")
*/
/* The following types are missing: wxItemKind
    ADD_CLASS_METHOD(AddTool1,"")
*/
    ADD_CLASS_METHOD(AddTool2,"")
    ADD_CLASS_METHOD(AddLabel,"")
    ADD_CLASS_METHOD(AddControl,"")
    ADD_CLASS_METHOD(AddSeparator,"")
    ADD_CLASS_METHOD(AddSpacer,"")
    ADD_CLASS_METHOD(AddStretchSpacer,"")
    ADD_CLASS_METHOD(Realize,"")
    ADD_CLASS_METHOD(FindControl,"")
    ADD_CLASS_METHOD(FindToolByPosition,"")
    ADD_CLASS_METHOD(FindToolByIndex,"")
    ADD_CLASS_METHOD(FindTool,"")
    ADD_CLASS_METHOD(ClearTools,"")
    ADD_CLASS_METHOD(Clear,"")
    ADD_CLASS_METHOD(DeleteTool,"")
    ADD_CLASS_METHOD(DeleteByIndex,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(GetToolCount,"")
*/
    ADD_CLASS_METHOD(GetToolPos,"")
    ADD_CLASS_METHOD(GetToolIndex,"")
    ADD_CLASS_METHOD(GetToolFits,"")
    ADD_CLASS_METHOD(GetToolRect,"")
    ADD_CLASS_METHOD(GetToolFitsByIndex,"")
    ADD_CLASS_METHOD(GetToolBarFits,"")
    ADD_CLASS_METHOD(SetMargins,"")
    ADD_CLASS_METHOD(SetMargins1,"")
    ADD_CLASS_METHOD(SetMargins2,"")
    ADD_CLASS_METHOD(SetToolBitmapSize,"")
    ADD_CLASS_METHOD(GetToolBitmapSize,"")
    ADD_CLASS_METHOD(GetOverflowVisible,"")
    ADD_CLASS_METHOD(SetOverflowVisible,"")
    ADD_CLASS_METHOD(GetGripperVisible,"")
    ADD_CLASS_METHOD(SetGripperVisible,"")
    ADD_CLASS_METHOD(ToggleTool,"")
    ADD_CLASS_METHOD(GetToolToggled,"")
    ADD_CLASS_METHOD(EnableTool,"")
    ADD_CLASS_METHOD(GetToolEnabled,"")
    ADD_CLASS_METHOD(SetToolDropDown,"")
    ADD_CLASS_METHOD(GetToolDropDown,"")
    ADD_CLASS_METHOD(SetToolBorderPadding,"")
    ADD_CLASS_METHOD(GetToolBorderPadding,"")
    ADD_CLASS_METHOD(SetToolTextOrientation,"")
    ADD_CLASS_METHOD(GetToolTextOrientation,"")
    ADD_CLASS_METHOD(SetToolPacking,"")
    ADD_CLASS_METHOD(GetToolPacking,"")
    ADD_CLASS_METHOD(SetToolProportion,"")
    ADD_CLASS_METHOD(GetToolProportion,"")
    ADD_CLASS_METHOD(SetToolSeparation,"")
    ADD_CLASS_METHOD(GetToolSeparation,"")
    ADD_CLASS_METHOD(SetToolSticky,"")
    ADD_CLASS_METHOD(GetToolSticky,"")
    ADD_CLASS_METHOD(GetToolLabel,"")
    ADD_CLASS_METHOD(SetToolLabel,"")
    ADD_CLASS_METHOD(GetToolBitmap,"")
    ADD_CLASS_METHOD(SetToolBitmap,"")
    ADD_CLASS_METHOD(GetToolShortHelp,"")
    ADD_CLASS_METHOD(SetToolShortHelp,"")
    ADD_CLASS_METHOD(GetToolLongHelp,"")
    ADD_CLASS_METHOD(SetToolLongHelp,"")
    ADD_CLASS_METHOD(SetCustomOverflowItems,"")
    ADD_CLASS_METHOD(GetClassInfo,"")
    ADD_CLASS_METHOD(wxCreateObject,"")





    void AddMethods(WrapClass<wxAuiToolBar>::ptr this_ptr )
    {
      // here inheritence
      
      // Add members from wxControl
      WrapClass_wxControl::ptr parent_wxControl(        boost::dynamic_pointer_cast<WrapClass_wxControl>(this_ptr));
      parent_wxControl->AddMethods(parent_wxControl);


      // check that the method name is not a token
      
      AddVar_SetWindowStyleFlag( this_ptr);
      AddVar_GetWindowStyleFlag( this_ptr);
      AddVar_SetArtProvider( this_ptr);
      AddVar_GetArtProvider( this_ptr);
      AddVar_SetFont( this_ptr);
/* The following types are missing: wxItemKind
      AddVar_AddTool( this_ptr);
*/
/* The following types are missing: wxItemKind
      AddVar_AddTool1( this_ptr);
*/
      AddVar_AddTool2( this_ptr);
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
/* The following types are missing: long unsigned int
      AddVar_GetToolCount( this_ptr);
*/
      AddVar_GetToolPos( this_ptr);
      AddVar_GetToolIndex( this_ptr);
      AddVar_GetToolFits( this_ptr);
      AddVar_GetToolRect( this_ptr);
      AddVar_GetToolFitsByIndex( this_ptr);
      AddVar_GetToolBarFits( this_ptr);
      AddVar_SetMargins( this_ptr);
      AddVar_SetMargins1( this_ptr);
      AddVar_SetMargins2( this_ptr);
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
      AddVar_wxCreateObject( this_ptr);



    };
};


#endif // _wrap_wxAuiToolBar_h
