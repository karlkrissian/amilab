/**
 * C++ Interface: wrap_wxAuiManager
 *
 * Description: wrapping wxAuiManager
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiManager_h_
#define _wrap_wxAuiManager_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...

//#include "wrap_wxEvtHandler.h"


AMI_DECLARE_TYPE(wxAuiManager);

// TODO: check for inheritence ...
class WrapClass_wxAuiManager : public WrapClass<wxAuiManager>
    //, public virtual WrapClass_wxEvtHandler
{
  DEFINE_CLASS(WrapClass_wxAuiManager);

  protected:
    typedef WrapClass<wxAuiManager>::ptr _parentclass_ptr;
    typedef wxAuiManager ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiManager>& GetObj() const { return WrapClass<wxAuiManager>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiManager(boost::shared_ptr<wxAuiManager > si): 
    WrapClass<wxAuiManager>(si)
    //, WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiManager()
    {
      std::cout << "~WrapClass_wxAuiManager()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManager,"Wrapping of wxAuiManager, http://docs.wxwidgets.org/stable/wx_wxauimanager.html#wxauimanager.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiManager*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(UnInit,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#uninit")
    ADD_CLASS_METHOD(SetFlags,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setflags")
    ADD_CLASS_METHOD(GetFlags,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getflags")
    ADD_CLASS_METHOD(SetManagedWindow,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setmanagedwindow")
    ADD_CLASS_METHOD(GetManagedWindow,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getmanagedwindow")
    ADD_CLASS_METHOD(GetManager,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getmanager")
/* The following types are missing: wxAuiDockArt
    ADD_CLASS_METHOD(SetArtProvider,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setartprovider")
*/
/* The following types are missing: wxAuiDockArt
    ADD_CLASS_METHOD(GetArtProvider,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getartprovider")
*/
    ADD_CLASS_METHOD(GetPane1,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane")
    ADD_CLASS_METHOD(GetPane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane")
    ADD_CLASS_METHOD(GetPane2,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane")
/* The following types are missing: wxAuiPaneInfoArray
    ADD_CLASS_METHOD(GetAllPanes,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getallpanes")
*/
    ADD_CLASS_METHOD(AddPane1,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane")
    ADD_CLASS_METHOD(AddPane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane")
    ADD_CLASS_METHOD(AddPane2,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane")
    ADD_CLASS_METHOD(AddPane3,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane")
    ADD_CLASS_METHOD(InsertPane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#insertpane")
    ADD_CLASS_METHOD(DetachPane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#detachpane")
    ADD_CLASS_METHOD(Update,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#update")
    ADD_CLASS_METHOD(SavePaneInfo,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#savepaneinfo")
    ADD_CLASS_METHOD(LoadPaneInfo,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#loadpaneinfo")
    ADD_CLASS_METHOD(SavePerspective,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#saveperspective")
    ADD_CLASS_METHOD(LoadPerspective,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#loadperspective")
    ADD_CLASS_METHOD(SetDockSizeConstraint,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setdocksizeconstraint")
    ADD_CLASS_METHOD(GetDockSizeConstraint,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getdocksizeconstraint")
    ADD_CLASS_METHOD(ClosePane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#closepane")
    ADD_CLASS_METHOD(MaximizePane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#maximizepane")
    ADD_CLASS_METHOD(RestorePane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#restorepane")
    ADD_CLASS_METHOD(RestoreMaximizedPane,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#restoremaximizedpane")
/* The following types are missing: wxAuiFloatingFrame
    ADD_CLASS_METHOD(CreateFloatingFrame,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#createfloatingframe")
*/
    ADD_CLASS_METHOD(StartPaneDrag,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#startpanedrag")
    ADD_CLASS_METHOD(CalculateHintRect,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#calculatehintrect")
    ADD_CLASS_METHOD(DrawHintRect,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#drawhintrect")
    ADD_CLASS_METHOD(ShowHint,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#showhint")
    ADD_CLASS_METHOD(HideHint,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#hidehint")
/* The following types are missing: wxAuiManagerEvent
    ADD_CLASS_METHOD(OnRender,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#onrender")
*/
/* The following types are missing: wxAuiManagerEvent
    ADD_CLASS_METHOD(OnPaneButton,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#onpanebutton")
*/
    ADD_CLASS_METHOD(GetClassInfo,"http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getclassinfo")





    void AddMethods(WrapClass<wxAuiManager>::ptr this_ptr )
    {
      /*
      // Add members from wxEvtHandler
      WrapClass_wxEvtHandler::ptr parent_wxEvtHandler(        boost::dynamic_pointer_cast<WrapClass_wxEvtHandler>(this_ptr));
      parent_wxEvtHandler->AddMethods(parent_wxEvtHandler);
      */


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_UnInit( this_ptr);
      AddVar_SetFlags( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_SetManagedWindow( this_ptr);
      AddVar_GetManagedWindow( this_ptr);
      AddVar_GetManager( this_ptr);
/* The following types are missing: wxAuiDockArt
      AddVar_SetArtProvider( this_ptr);
*/
/* The following types are missing: wxAuiDockArt
      AddVar_GetArtProvider( this_ptr);
*/
      AddVar_GetPane1( this_ptr);
      AddVar_GetPane( this_ptr);
      AddVar_GetPane2( this_ptr);
/* The following types are missing: wxAuiPaneInfoArray
      AddVar_GetAllPanes( this_ptr);
*/
      AddVar_AddPane1( this_ptr);
      AddVar_AddPane( this_ptr);
      AddVar_AddPane2( this_ptr);
      AddVar_AddPane3( this_ptr);
      AddVar_InsertPane( this_ptr);
      AddVar_DetachPane( this_ptr);
      AddVar_Update( this_ptr);
      AddVar_SavePaneInfo( this_ptr);
      AddVar_LoadPaneInfo( this_ptr);
      AddVar_SavePerspective( this_ptr);
      AddVar_LoadPerspective( this_ptr);
      AddVar_SetDockSizeConstraint( this_ptr);
      AddVar_GetDockSizeConstraint( this_ptr);
      AddVar_ClosePane( this_ptr);
      AddVar_MaximizePane( this_ptr);
      AddVar_RestorePane( this_ptr);
      AddVar_RestoreMaximizedPane( this_ptr);
/* The following types are missing: wxAuiFloatingFrame
      AddVar_CreateFloatingFrame( this_ptr);
*/
      AddVar_StartPaneDrag( this_ptr);
      AddVar_CalculateHintRect( this_ptr);
      AddVar_DrawHintRect( this_ptr);
      AddVar_ShowHint( this_ptr);
      AddVar_HideHint( this_ptr);
/* The following types are missing: wxAuiManagerEvent
      AddVar_OnRender( this_ptr);
*/
/* The following types are missing: wxAuiManagerEvent
      AddVar_OnPaneButton( this_ptr);
*/
      AddVar_GetClassInfo( this_ptr);



      
    };
};


#endif // _wrap_wxAuiManager_h
