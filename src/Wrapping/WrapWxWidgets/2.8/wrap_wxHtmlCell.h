/**
 * C++ Interface: wrap_wxHtmlCell
 *
 * Description: wrapping wxHtmlCell
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlCell_h_
#define _wrap_wxHtmlCell_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxHtmlCell_declared
  #define wxHtmlCell_declared
  AMI_DECLARE_TYPE(wxHtmlCell);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlCell : public WrapClass<wxHtmlCell>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxHtmlCell);

  protected:
    typedef WrapClass<wxHtmlCell>::ptr _parentclass_ptr;
    typedef wxHtmlCell ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlCell>& GetObj() const { return WrapClass<wxHtmlCell>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlCell(boost::shared_ptr<wxHtmlCell > si): 
    WrapClass<wxHtmlCell>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlCell()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlCell,"Constructor wxHtmlCell::wxHtmlCell() (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#wxhtmlcell).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlCell*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetParent,"void wxHtmlCell::SetParent(wxHtmlContainerCell * p)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setparent)")
    ADD_CLASS_METHOD(GetParent,"wxHtmlContainerCell * wxHtmlCell::GetParent()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getparent)")
    ADD_CLASS_METHOD(GetPosX,"int wxHtmlCell::GetPosX()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getposx)")
    ADD_CLASS_METHOD(GetPosY,"int wxHtmlCell::GetPosY()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getposy)")
    ADD_CLASS_METHOD(GetWidth,"int wxHtmlCell::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getwidth)")
    ADD_CLASS_METHOD(GetMaxTotalWidth,"int wxHtmlCell::GetMaxTotalWidth()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getmaxtotalwidth)")
    ADD_CLASS_METHOD(GetHeight,"int wxHtmlCell::GetHeight()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getheight)")
    ADD_CLASS_METHOD(GetDescent,"int wxHtmlCell::GetDescent()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getdescent)")
    ADD_CLASS_METHOD(SetScriptMode,"void wxHtmlCell::SetScriptMode(wxHtmlScriptMode mode, long int previousBase)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setscriptmode)")
    ADD_CLASS_METHOD(GetScriptMode,"wxHtmlScriptMode wxHtmlCell::GetScriptMode()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getscriptmode)")
    ADD_CLASS_METHOD(GetScriptBaseline,"long int wxHtmlCell::GetScriptBaseline()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getscriptbaseline)")
    ADD_CLASS_METHOD(IsFormattingCell,"bool wxHtmlCell::IsFormattingCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#isformattingcell)")
    ADD_CLASS_METHOD(GetId,"wxString const & wxHtmlCell::GetId()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getid)")
    ADD_CLASS_METHOD(SetId,"void wxHtmlCell::SetId(wxString const & id)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setid)")
    ADD_CLASS_METHOD(GetLink,"wxHtmlLinkInfo * wxHtmlCell::GetLink(int param0 = 0, int param1 = 0)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getlink)")
    ADD_CLASS_METHOD(GetMouseCursor,"wxCursor wxHtmlCell::GetMouseCursor(wxHtmlWindowInterface * window)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getmousecursor)")
    ADD_CLASS_METHOD(GetNext,"wxHtmlCell * wxHtmlCell::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getnext)")
    ADD_CLASS_METHOD(GetFirstChild,"wxHtmlCell * wxHtmlCell::GetFirstChild()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getfirstchild)")
    ADD_CLASS_METHOD(SetPos,"void wxHtmlCell::SetPos(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setpos)")
    ADD_CLASS_METHOD(SetLink,"void wxHtmlCell::SetLink(wxHtmlLinkInfo const & link)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setlink)")
    ADD_CLASS_METHOD(SetNext,"void wxHtmlCell::SetNext(wxHtmlCell * cell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setnext)")
    ADD_CLASS_METHOD(Layout,"void wxHtmlCell::Layout(int w)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#layout)")
    ADD_CLASS_METHOD(Draw,"void wxHtmlCell::Draw(wxDC & param0, int param1, int param2, int param3, int param4, wxHtmlRenderingInfo & param5)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#draw)")
    ADD_CLASS_METHOD(DrawInvisible,"void wxHtmlCell::DrawInvisible(wxDC & param0, int param1, int param2, wxHtmlRenderingInfo & param3)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#drawinvisible)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Find,"wxHtmlCell const * wxHtmlCell::Find(int condition, void const * param)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#find)")
*/
    ADD_CLASS_METHOD(ProcessMouseClick,"bool wxHtmlCell::ProcessMouseClick(wxHtmlWindowInterface * window, wxPoint const & pos, wxMouseEvent const & event)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#processmouseclick)")
    ADD_CLASS_METHOD(AdjustPagebreak,"bool wxHtmlCell::AdjustPagebreak(int * pagebreak, wxArrayInt & known_pagebreaks)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#adjustpagebreak)")
    ADD_CLASS_METHOD(SetCanLiveOnPagebreak,"void wxHtmlCell::SetCanLiveOnPagebreak(bool can)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#setcanliveonpagebreak)")
    ADD_CLASS_METHOD(IsLinebreakAllowed,"bool wxHtmlCell::IsLinebreakAllowed()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#islinebreakallowed)")
    ADD_CLASS_METHOD(IsTerminalCell,"bool wxHtmlCell::IsTerminalCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#isterminalcell)")
    ADD_CLASS_METHOD(FindCellByPos,"wxHtmlCell * wxHtmlCell::FindCellByPos(wxCoord x, wxCoord y, unsigned int flags = wxHTML_FIND_EXACT)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#findcellbypos)")
    ADD_CLASS_METHOD(GetAbsPos,"wxPoint wxHtmlCell::GetAbsPos(wxHtmlCell * rootCell = 0l)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getabspos)")
    ADD_CLASS_METHOD(GetRootCell,"wxHtmlCell * wxHtmlCell::GetRootCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getrootcell)")
    ADD_CLASS_METHOD(GetFirstTerminal,"wxHtmlCell * wxHtmlCell::GetFirstTerminal()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getfirstterminal)")
    ADD_CLASS_METHOD(GetLastTerminal,"wxHtmlCell * wxHtmlCell::GetLastTerminal()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getlastterminal)")
    ADD_CLASS_METHOD(GetDepth,"unsigned int wxHtmlCell::GetDepth()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getdepth)")
    ADD_CLASS_METHOD(IsBefore,"bool wxHtmlCell::IsBefore(wxHtmlCell * cell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#isbefore)")
    ADD_CLASS_METHOD(ConvertToText,"wxString wxHtmlCell::ConvertToText(wxHtmlSelection * param0)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#converttotext)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlCell::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcell.html#getclassinfo)")





    void AddMethods(WrapClass<wxHtmlCell>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlCell_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlCell_h
