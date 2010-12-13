/**
 * C++ Interface: wrap_wxToolBarBase
 *
 * Description: wrapping wxToolBarBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxToolBarBase_h_
#define _wrap_wxToolBarBase_h_

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


#ifndef wxToolBarBase_declared
  #define wxToolBarBase_declared
  AMI_DECLARE_TYPE(wxToolBarBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxToolBarBase : public WrapClass<wxToolBarBase>
    , public   WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxToolBarBase);

  protected:
    typedef WrapClass<wxToolBarBase>::ptr _parentclass_ptr;
    typedef wxToolBarBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxToolBarBase>& GetObj() const { return WrapClass<wxToolBarBase>::GetObj(); }

    /// Constructor
    WrapClass_wxToolBarBase(boost::shared_ptr<wxToolBarBase > si): 
    WrapClass<wxToolBarBase>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxToolBarBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxToolBarBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(AddTool_1,"wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, wxItemKind kind = wxITEM_NORMAL, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(AddTool,"wxToolBarBase::AddTool()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(AddTool_2,"wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxString const & shortHelp = wxEmptyString, wxItemKind kind = wxITEM_NORMAL)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(AddCheckTool,"wxToolBarToolBase * wxToolBarBase::AddCheckTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addchecktool)")
    ADD_CLASS_METHOD(AddRadioTool,"wxToolBarToolBase * wxToolBarBase::AddRadioTool(int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * data = 0l)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addradiotool)")
    ADD_CLASS_METHOD(InsertTool_1,"wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, int toolid, wxString const & label, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString, wxObject * clientData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#inserttool)")
    ADD_CLASS_METHOD(AddTool_3,"wxToolBarToolBase * wxToolBarBase::AddTool(wxToolBarToolBase * tool)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(InsertTool,"wxToolBarBase::InsertTool()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#inserttool)")
    ADD_CLASS_METHOD(InsertTool_2,"wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, wxToolBarToolBase * tool)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#inserttool)")
    ADD_CLASS_METHOD(AddControl,"wxToolBarToolBase * wxToolBarBase::AddControl(wxControl * control)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addcontrol)")
    ADD_CLASS_METHOD(InsertControl,"wxToolBarToolBase * wxToolBarBase::InsertControl(size_t pos, wxControl * control)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#insertcontrol)")
    ADD_CLASS_METHOD(FindControl,"wxControl * wxToolBarBase::FindControl(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#findcontrol)")
    ADD_CLASS_METHOD(AddSeparator,"wxToolBarToolBase * wxToolBarBase::AddSeparator()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addseparator)")
    ADD_CLASS_METHOD(InsertSeparator,"wxToolBarToolBase * wxToolBarBase::InsertSeparator(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#insertseparator)")
    ADD_CLASS_METHOD(RemoveTool,"wxToolBarToolBase * wxToolBarBase::RemoveTool(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#removetool)")
    ADD_CLASS_METHOD(DeleteToolByPos,"bool wxToolBarBase::DeleteToolByPos(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#deletetoolbypos)")
    ADD_CLASS_METHOD(DeleteTool,"bool wxToolBarBase::DeleteTool(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#deletetool)")
    ADD_CLASS_METHOD(ClearTools,"void wxToolBarBase::ClearTools()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#cleartools)")
    ADD_CLASS_METHOD(Realize,"bool wxToolBarBase::Realize()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#realize)")
    ADD_CLASS_METHOD(EnableTool,"void wxToolBarBase::EnableTool(int toolid, bool enable)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#enabletool)")
    ADD_CLASS_METHOD(ToggleTool,"void wxToolBarBase::ToggleTool(int toolid, bool toggle)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#toggletool)")
    ADD_CLASS_METHOD(SetToggle,"void wxToolBarBase::SetToggle(int toolid, bool toggle)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoggle)")
    ADD_CLASS_METHOD(GetToolClientData,"wxObject * wxToolBarBase::GetToolClientData(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolclientdata)")
    ADD_CLASS_METHOD(SetToolClientData,"void wxToolBarBase::SetToolClientData(int toolid, wxObject * clientData)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoolclientdata)")
    ADD_CLASS_METHOD(GetToolPos,"int wxToolBarBase::GetToolPos(int id)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolpos)")
    ADD_CLASS_METHOD(GetToolState,"bool wxToolBarBase::GetToolState(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolstate)")
    ADD_CLASS_METHOD(GetToolEnabled,"bool wxToolBarBase::GetToolEnabled(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolenabled)")
    ADD_CLASS_METHOD(SetToolShortHelp,"void wxToolBarBase::SetToolShortHelp(int toolid, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoolshorthelp)")
    ADD_CLASS_METHOD(GetToolShortHelp,"wxString wxToolBarBase::GetToolShortHelp(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolshorthelp)")
    ADD_CLASS_METHOD(SetToolLongHelp,"void wxToolBarBase::SetToolLongHelp(int toolid, wxString const & helpString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoollonghelp)")
    ADD_CLASS_METHOD(GetToolLongHelp,"wxString wxToolBarBase::GetToolLongHelp(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoollonghelp)")
    ADD_CLASS_METHOD(SetMargins_1,"void wxToolBarBase::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#setmargins)")
    ADD_CLASS_METHOD(SetMargins,"wxToolBarBase::SetMargins()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#setmargins)")
    ADD_CLASS_METHOD(SetMargins_2,"void wxToolBarBase::SetMargins(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#setmargins)")
    ADD_CLASS_METHOD(SetToolPacking,"void wxToolBarBase::SetToolPacking(int packing)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoolpacking)")
    ADD_CLASS_METHOD(SetToolSeparation,"void wxToolBarBase::SetToolSeparation(int separation)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoolseparation)")
    ADD_CLASS_METHOD(GetToolMargins,"wxSize wxToolBarBase::GetToolMargins()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolmargins)")
    ADD_CLASS_METHOD(GetToolPacking,"int wxToolBarBase::GetToolPacking()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolpacking)")
    ADD_CLASS_METHOD(GetToolSeparation,"int wxToolBarBase::GetToolSeparation()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolseparation)")
    ADD_CLASS_METHOD(SetRows,"void wxToolBarBase::SetRows(int nRows)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#setrows)")
    ADD_CLASS_METHOD(SetMaxRowsCols,"void wxToolBarBase::SetMaxRowsCols(int rows, int cols)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#setmaxrowscols)")
    ADD_CLASS_METHOD(GetMaxRows,"int wxToolBarBase::GetMaxRows()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#getmaxrows)")
    ADD_CLASS_METHOD(GetMaxCols,"int wxToolBarBase::GetMaxCols()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#getmaxcols)")
    ADD_CLASS_METHOD(SetToolBitmapSize,"void wxToolBarBase::SetToolBitmapSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#settoolbitmapsize)")
    ADD_CLASS_METHOD(GetToolBitmapSize,"wxSize wxToolBarBase::GetToolBitmapSize()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolbitmapsize)")
    ADD_CLASS_METHOD(GetToolSize,"wxSize wxToolBarBase::GetToolSize()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolsize)")
    ADD_CLASS_METHOD(FindById,"wxToolBarToolBase * wxToolBarBase::FindById(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#findbyid)")
    ADD_CLASS_METHOD(IsVertical,"bool wxToolBarBase::IsVertical()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#isvertical)")
    ADD_CLASS_METHOD(AddTool_4,"wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, bool toggle = false, wxObject * clientData = 0l, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(AddTool_5,"wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxString const & shortHelpString = wxEmptyString, wxString const & longHelpString = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(AddTool_6,"wxToolBarToolBase * wxToolBarBase::AddTool(int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled, bool toggle, wxCoord xPos, wxCoord yPos = wxDefaultCoord, wxObject * clientData = 0l, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#addtool)")
    ADD_CLASS_METHOD(InsertTool_3,"wxToolBarToolBase * wxToolBarBase::InsertTool(size_t pos, int toolid, wxBitmap const & bitmap, wxBitmap const & bmpDisabled = wxNullBitmap, bool toggle = false, wxObject * clientData = 0l, wxString const & shortHelp = wxEmptyString, wxString const & longHelp = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#inserttool)")
    ADD_CLASS_METHOD(OnLeftClick,"bool wxToolBarBase::OnLeftClick(int toolid, bool toggleDown)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#onleftclick)")
    ADD_CLASS_METHOD(OnRightClick,"void wxToolBarBase::OnRightClick(int toolid, long int x, long int y)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#onrightclick)")
    ADD_CLASS_METHOD(OnMouseEnter,"void wxToolBarBase::OnMouseEnter(int toolid)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#onmouseenter)")
    ADD_CLASS_METHOD(GetMargins,"wxSize wxToolBarBase::GetMargins()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#getmargins)")
    ADD_CLASS_METHOD(GetToolsCount,"size_t wxToolBarBase::GetToolsCount()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#gettoolscount)")
    ADD_CLASS_METHOD(UpdateWindowUI,"void wxToolBarBase::UpdateWindowUI(long int flags = wxUPDATE_UI_NONE)  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#updatewindowui)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxToolBarBase::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxtoolbarbase.html#acceptsfocus)")





    void AddMethods(WrapClass<wxToolBarBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxToolBarBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxToolBarBase_h
