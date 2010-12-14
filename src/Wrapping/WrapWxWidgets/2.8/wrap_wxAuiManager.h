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

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxEvtHandler.h"


#ifndef wxAuiManager_declared
  #define wxAuiManager_declared
  AMI_DECLARE_TYPE(wxAuiManager);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiManager : public WrapClass<wxAuiManager>
    , public   WrapClass_wxEvtHandler
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
    , WrapClass_wxEvtHandler(si)
    {}

    /// Destructor
    ~WrapClass_wxAuiManager()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiManager,"Constructor wxAuiManager::wxAuiManager(wxWindow * managed_wnd = 0l, unsigned int flags = wxAUI_MGR_DEFAULT) (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#wxauimanager).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiManager*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetManager,"wxAuiManager * wxAuiManager::GetManager(wxWindow * window) (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getmanager).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(UnInit,"void wxAuiManager::UnInit()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#uninit)")
    ADD_CLASS_METHOD(SetFlags,"void wxAuiManager::SetFlags(unsigned int flags)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setflags)")
    ADD_CLASS_METHOD(GetFlags,"unsigned int wxAuiManager::GetFlags()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getflags)")
    ADD_CLASS_METHOD(SetManagedWindow,"void wxAuiManager::SetManagedWindow(wxWindow * managed_wnd)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setmanagedwindow)")
    ADD_CLASS_METHOD(GetManagedWindow,"wxWindow * wxAuiManager::GetManagedWindow()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getmanagedwindow)")
    ADD_CLASS_METHOD(SetArtProvider,"void wxAuiManager::SetArtProvider(wxAuiDockArt * art_provider)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setartprovider)")
    ADD_CLASS_METHOD(GetArtProvider,"wxAuiDockArt * wxAuiManager::GetArtProvider()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getartprovider)")
    ADD_CLASS_METHOD(GetPane_1,"wxAuiPaneInfo & wxAuiManager::GetPane(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane)")
    ADD_CLASS_METHOD(GetPane,"wxAuiManager::GetPane()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane)")
    ADD_CLASS_METHOD(GetPane_2,"wxAuiPaneInfo & wxAuiManager::GetPane(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getpane)")
    ADD_CLASS_METHOD(GetAllPanes,"wxAuiPaneInfoArray & wxAuiManager::GetAllPanes()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getallpanes)")
    ADD_CLASS_METHOD(AddPane_1,"bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo const & pane_info)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane)")
    ADD_CLASS_METHOD(AddPane,"wxAuiManager::AddPane()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane)")
    ADD_CLASS_METHOD(AddPane_2,"bool wxAuiManager::AddPane(wxWindow * window, wxAuiPaneInfo const & pane_info, wxPoint const & drop_pos)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane)")
    ADD_CLASS_METHOD(AddPane_3,"bool wxAuiManager::AddPane(wxWindow * window, int direction = wxLEFT, wxString const & caption = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#addpane)")
    ADD_CLASS_METHOD(InsertPane,"bool wxAuiManager::InsertPane(wxWindow * window, wxAuiPaneInfo const & insert_location, int insert_level = wxAUI_INSERT_PANE)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#insertpane)")
    ADD_CLASS_METHOD(DetachPane,"bool wxAuiManager::DetachPane(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#detachpane)")
    ADD_CLASS_METHOD(Update,"void wxAuiManager::Update()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#update)")
    ADD_CLASS_METHOD(SavePaneInfo,"wxString wxAuiManager::SavePaneInfo(wxAuiPaneInfo & pane)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#savepaneinfo)")
    ADD_CLASS_METHOD(LoadPaneInfo,"void wxAuiManager::LoadPaneInfo(wxString pane_part, wxAuiPaneInfo & pane)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#loadpaneinfo)")
    ADD_CLASS_METHOD(SavePerspective,"wxString wxAuiManager::SavePerspective()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#saveperspective)")
    ADD_CLASS_METHOD(LoadPerspective,"bool wxAuiManager::LoadPerspective(wxString const & perspective, bool update = true)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#loadperspective)")
    ADD_CLASS_METHOD(SetDockSizeConstraint,"void wxAuiManager::SetDockSizeConstraint(double width_pct, double height_pct)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#setdocksizeconstraint)")
    ADD_CLASS_METHOD(GetDockSizeConstraint,"void wxAuiManager::GetDockSizeConstraint(double * width_pct, double * height_pct)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getdocksizeconstraint)")
    ADD_CLASS_METHOD(ClosePane,"void wxAuiManager::ClosePane(wxAuiPaneInfo & pane_info)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#closepane)")
    ADD_CLASS_METHOD(MaximizePane,"void wxAuiManager::MaximizePane(wxAuiPaneInfo & pane_info)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#maximizepane)")
    ADD_CLASS_METHOD(RestorePane,"void wxAuiManager::RestorePane(wxAuiPaneInfo & pane_info)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#restorepane)")
    ADD_CLASS_METHOD(RestoreMaximizedPane,"void wxAuiManager::RestoreMaximizedPane()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#restoremaximizedpane)")
    ADD_CLASS_METHOD(CreateFloatingFrame,"wxAuiFloatingFrame * wxAuiManager::CreateFloatingFrame(wxWindow * parent, wxAuiPaneInfo const & p)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#createfloatingframe)")
    ADD_CLASS_METHOD(StartPaneDrag,"void wxAuiManager::StartPaneDrag(wxWindow * pane_window, wxPoint const & offset)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#startpanedrag)")
    ADD_CLASS_METHOD(CalculateHintRect,"wxRect wxAuiManager::CalculateHintRect(wxWindow * pane_window, wxPoint const & pt, wxPoint const & offset)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#calculatehintrect)")
    ADD_CLASS_METHOD(DrawHintRect,"void wxAuiManager::DrawHintRect(wxWindow * pane_window, wxPoint const & pt, wxPoint const & offset)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#drawhintrect)")
    ADD_CLASS_METHOD(ShowHint,"void wxAuiManager::ShowHint(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#showhint)")
    ADD_CLASS_METHOD(HideHint,"void wxAuiManager::HideHint()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#hidehint)")
    ADD_CLASS_METHOD(OnRender,"void wxAuiManager::OnRender(wxAuiManagerEvent & evt)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#onrender)")
    ADD_CLASS_METHOD(OnPaneButton,"void wxAuiManager::OnPaneButton(wxAuiManagerEvent & evt)  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#onpanebutton)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxAuiManager::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxauimanager.html#getclassinfo)")





    void AddMethods(WrapClass<wxAuiManager>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiManager_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiManager_h
