/**
 * C++ Interface: wrap_wxHtmlContainerCell
 *
 * Description: wrapping wxHtmlContainerCell
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlContainerCell_h_
#define _wrap_wxHtmlContainerCell_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxHtmlCell.h"



AMI_DECLARE_TYPE(wxHtmlContainerCell);

// TODO: check for inheritence ...
class WrapClass_wxHtmlContainerCell : public WrapClass<wxHtmlContainerCell>
    , public   WrapClass_wxHtmlCell
{
  DEFINE_CLASS(WrapClass_wxHtmlContainerCell);

  protected:
    typedef WrapClass<wxHtmlContainerCell>::ptr _parentclass_ptr;
    typedef wxHtmlContainerCell ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlContainerCell>& GetObj() const { return WrapClass<wxHtmlContainerCell>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlContainerCell(boost::shared_ptr<wxHtmlContainerCell > si): 
    WrapClass<wxHtmlContainerCell>(si)
    , WrapClass_wxHtmlCell(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlContainerCell()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlContainerCell,"Constructor wxHtmlContainerCell::wxHtmlContainerCell(wxHtmlContainerCell * parent) (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#wxhtmlcontainercell).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlContainerCell*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Layout,"void wxHtmlContainerCell::Layout(int w)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#layout)")
    ADD_CLASS_METHOD(Draw,"void wxHtmlContainerCell::Draw(wxDC & dc, int x, int y, int view_y1, int view_y2, wxHtmlRenderingInfo & info)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#draw)")
    ADD_CLASS_METHOD(DrawInvisible,"void wxHtmlContainerCell::DrawInvisible(wxDC & dc, int x, int y, wxHtmlRenderingInfo & info)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#drawinvisible)")
    ADD_CLASS_METHOD(AdjustPagebreak,"bool wxHtmlContainerCell::AdjustPagebreak(int * pagebreak, wxArrayInt & known_pagebreaks)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#adjustpagebreak)")
    ADD_CLASS_METHOD(InsertCell,"void wxHtmlContainerCell::InsertCell(wxHtmlCell * cell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#insertcell)")
    ADD_CLASS_METHOD(SetAlignHor,"void wxHtmlContainerCell::SetAlignHor(int al)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setalignhor)")
    ADD_CLASS_METHOD(GetAlignHor,"int wxHtmlContainerCell::GetAlignHor()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getalignhor)")
    ADD_CLASS_METHOD(SetAlignVer,"void wxHtmlContainerCell::SetAlignVer(int al)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setalignver)")
    ADD_CLASS_METHOD(GetAlignVer,"int wxHtmlContainerCell::GetAlignVer()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getalignver)")
    ADD_CLASS_METHOD(SetIndent,"void wxHtmlContainerCell::SetIndent(int i, int what, int units = 1)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setindent)")
    ADD_CLASS_METHOD(GetIndent,"int wxHtmlContainerCell::GetIndent(int ind)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getindent)")
    ADD_CLASS_METHOD(GetIndentUnits,"int wxHtmlContainerCell::GetIndentUnits(int ind)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getindentunits)")
    ADD_CLASS_METHOD(SetAlign,"void wxHtmlContainerCell::SetAlign(wxHtmlTag const & tag)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setalign)")
    ADD_CLASS_METHOD(SetWidthFloat_1,"void wxHtmlContainerCell::SetWidthFloat(int w, int units)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setwidthfloat)")
    ADD_CLASS_METHOD(SetWidthFloat,"wxHtmlContainerCell::SetWidthFloat()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setwidthfloat)")
    ADD_CLASS_METHOD(SetWidthFloat_2,"void wxHtmlContainerCell::SetWidthFloat(wxHtmlTag const & tag, double pixel_scale = 1.0e+0)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setwidthfloat)")
    ADD_CLASS_METHOD(SetMinHeight,"void wxHtmlContainerCell::SetMinHeight(int h, int align = 4)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setminheight)")
    ADD_CLASS_METHOD(SetBackgroundColour,"void wxHtmlContainerCell::SetBackgroundColour(wxColour const & clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setbackgroundcolour)")
    ADD_CLASS_METHOD(GetBackgroundColour,"wxColour wxHtmlContainerCell::GetBackgroundColour()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getbackgroundcolour)")
    ADD_CLASS_METHOD(SetBorder,"void wxHtmlContainerCell::SetBorder(wxColour const & clr1, wxColour const & clr2)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#setborder)")
    ADD_CLASS_METHOD(GetLink,"wxHtmlLinkInfo * wxHtmlContainerCell::GetLink(int x = 0, int y = 0)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getlink)")
/* The following types are missing: void
    ADD_CLASS_METHOD(Find,"wxHtmlCell const * wxHtmlContainerCell::Find(int condition, void const * param)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#find)")
*/
    ADD_CLASS_METHOD(ProcessMouseClick,"bool wxHtmlContainerCell::ProcessMouseClick(wxHtmlWindowInterface * window, wxPoint const & pos, wxMouseEvent const & event)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#processmouseclick)")
    ADD_CLASS_METHOD(GetFirstChild,"wxHtmlCell * wxHtmlContainerCell::GetFirstChild()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getfirstchild)")
    ADD_CLASS_METHOD(GetLastChild,"wxHtmlCell * wxHtmlContainerCell::GetLastChild()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getlastchild)")
    ADD_CLASS_METHOD(IsTerminalCell,"bool wxHtmlContainerCell::IsTerminalCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#isterminalcell)")
    ADD_CLASS_METHOD(FindCellByPos,"wxHtmlCell * wxHtmlContainerCell::FindCellByPos(wxCoord x, wxCoord y, unsigned int flags = wxHTML_FIND_EXACT)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#findcellbypos)")
    ADD_CLASS_METHOD(GetFirstTerminal,"wxHtmlCell * wxHtmlContainerCell::GetFirstTerminal()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getfirstterminal)")
    ADD_CLASS_METHOD(GetLastTerminal,"wxHtmlCell * wxHtmlContainerCell::GetLastTerminal()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getlastterminal)")
    ADD_CLASS_METHOD(RemoveExtraSpacing,"void wxHtmlContainerCell::RemoveExtraSpacing(bool top, bool bottom)  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#removeextraspacing)")
    ADD_CLASS_METHOD(GetMaxTotalWidth,"int wxHtmlContainerCell::GetMaxTotalWidth()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getmaxtotalwidth)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlContainerCell::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlcontainercell.html#getclassinfo)")





    void AddMethods(WrapClass<wxHtmlContainerCell>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxHtmlContainerCell_h
