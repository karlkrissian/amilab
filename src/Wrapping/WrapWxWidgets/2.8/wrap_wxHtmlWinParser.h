/**
 * C++ Interface: wrap_wxHtmlWinParser
 *
 * Description: wrapping wxHtmlWinParser
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlWinParser_h_
#define _wrap_wxHtmlWinParser_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxHtmlParser.h"


#ifndef wxHtmlWinParser_declared
  #define wxHtmlWinParser_declared
  AMI_DECLARE_TYPE(wxHtmlWinParser);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlWinParser : public WrapClass<wxHtmlWinParser>
    , public   WrapClass_wxHtmlParser
{
  DEFINE_CLASS(WrapClass_wxHtmlWinParser);

  protected:
    typedef WrapClass<wxHtmlWinParser>::ptr _parentclass_ptr;
    typedef wxHtmlWinParser ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlWinParser>& GetObj() const { return WrapClass<wxHtmlWinParser>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlWinParser(boost::shared_ptr<wxHtmlWinParser > si): 
    WrapClass<wxHtmlWinParser>(si)
    , WrapClass_wxHtmlParser(si)
    {}

    /// Destructor
    ~WrapClass_wxHtmlWinParser()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlWinParser,"Constructor wxHtmlWinParser::wxHtmlWinParser(wxHtmlWindowInterface * wndIface = 0l) (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#wxhtmlwinparser).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlWinParser*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(AddModule,"void wxHtmlWinParser::AddModule(wxHtmlTagsModule * module) (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#addmodule).");
    ADD_CLASS_STATICMETHOD(RemoveModule,"void wxHtmlWinParser::RemoveModule(wxHtmlTagsModule * module) (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#removemodule).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxHtmlWinParser::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getclassinfo)")
    ADD_CLASS_METHOD(InitParser,"void wxHtmlWinParser::InitParser(wxString const & source)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#initparser)")
    ADD_CLASS_METHOD(DoneParser,"void wxHtmlWinParser::DoneParser()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#doneparser)")
    ADD_CLASS_METHOD(GetProduct,"wxObject * wxHtmlWinParser::GetProduct()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getproduct)")
    ADD_CLASS_METHOD(OpenURL,"wxFSFile * wxHtmlWinParser::OpenURL(wxHtmlURLType type, wxString const & url)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#openurl)")
    ADD_CLASS_METHOD(SetDC,"void wxHtmlWinParser::SetDC(wxDC * dc, double pixel_scale = 1.0e+0)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setdc)")
    ADD_CLASS_METHOD(GetDC,"wxDC * wxHtmlWinParser::GetDC()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getdc)")
    ADD_CLASS_METHOD(GetPixelScale,"double wxHtmlWinParser::GetPixelScale()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getpixelscale)")
    ADD_CLASS_METHOD(GetCharHeight,"int wxHtmlWinParser::GetCharHeight()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getcharheight)")
    ADD_CLASS_METHOD(GetCharWidth,"int wxHtmlWinParser::GetCharWidth()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getcharwidth)")
    ADD_CLASS_METHOD(GetWindowInterface,"wxHtmlWindowInterface * wxHtmlWinParser::GetWindowInterface()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getwindowinterface)")
    ADD_CLASS_METHOD(SetFonts,"void wxHtmlWinParser::SetFonts(wxString const & normal_face, wxString const & fixed_face, int const * sizes = 0l)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfonts)")
    ADD_CLASS_METHOD(SetStandardFonts,"void wxHtmlWinParser::SetStandardFonts(int size = -0x00000000000000001, wxString const & normal_face = wxEmptyString, wxString const & fixed_face = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setstandardfonts)")
    ADD_CLASS_METHOD(GetContainer,"wxHtmlContainerCell * wxHtmlWinParser::GetContainer()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getcontainer)")
    ADD_CLASS_METHOD(OpenContainer,"wxHtmlContainerCell * wxHtmlWinParser::OpenContainer()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#opencontainer)")
    ADD_CLASS_METHOD(SetContainer,"wxHtmlContainerCell * wxHtmlWinParser::SetContainer(wxHtmlContainerCell * c)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setcontainer)")
    ADD_CLASS_METHOD(CloseContainer,"wxHtmlContainerCell * wxHtmlWinParser::CloseContainer()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#closecontainer)")
    ADD_CLASS_METHOD(GetFontSize,"int wxHtmlWinParser::GetFontSize()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontsize)")
    ADD_CLASS_METHOD(SetFontSize,"void wxHtmlWinParser::SetFontSize(int s)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontsize)")
    ADD_CLASS_METHOD(GetFontBold,"int wxHtmlWinParser::GetFontBold()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontbold)")
    ADD_CLASS_METHOD(SetFontBold,"void wxHtmlWinParser::SetFontBold(int x)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontbold)")
    ADD_CLASS_METHOD(GetFontItalic,"int wxHtmlWinParser::GetFontItalic()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontitalic)")
    ADD_CLASS_METHOD(SetFontItalic,"void wxHtmlWinParser::SetFontItalic(int x)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontitalic)")
    ADD_CLASS_METHOD(GetFontUnderlined,"int wxHtmlWinParser::GetFontUnderlined()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontunderlined)")
    ADD_CLASS_METHOD(SetFontUnderlined,"void wxHtmlWinParser::SetFontUnderlined(int x)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontunderlined)")
    ADD_CLASS_METHOD(GetFontFixed,"int wxHtmlWinParser::GetFontFixed()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontfixed)")
    ADD_CLASS_METHOD(SetFontFixed,"void wxHtmlWinParser::SetFontFixed(int x)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontfixed)")
    ADD_CLASS_METHOD(GetFontFace,"wxString wxHtmlWinParser::GetFontFace()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getfontface)")
    ADD_CLASS_METHOD(SetFontFace,"void wxHtmlWinParser::SetFontFace(wxString const & face)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setfontface)")
    ADD_CLASS_METHOD(GetAlign,"int wxHtmlWinParser::GetAlign()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getalign)")
    ADD_CLASS_METHOD(SetAlign,"void wxHtmlWinParser::SetAlign(int a)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setalign)")
    ADD_CLASS_METHOD(GetScriptMode,"wxHtmlScriptMode wxHtmlWinParser::GetScriptMode()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getscriptmode)")
    ADD_CLASS_METHOD(SetScriptMode,"void wxHtmlWinParser::SetScriptMode(wxHtmlScriptMode mode)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setscriptmode)")
    ADD_CLASS_METHOD(GetScriptBaseline,"long int wxHtmlWinParser::GetScriptBaseline()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getscriptbaseline)")
    ADD_CLASS_METHOD(SetScriptBaseline,"void wxHtmlWinParser::SetScriptBaseline(long int base)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setscriptbaseline)")
    ADD_CLASS_METHOD(GetLinkColor,"wxColour const & wxHtmlWinParser::GetLinkColor()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getlinkcolor)")
    ADD_CLASS_METHOD(SetLinkColor,"void wxHtmlWinParser::SetLinkColor(wxColour const & clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setlinkcolor)")
    ADD_CLASS_METHOD(GetActualColor,"wxColour const & wxHtmlWinParser::GetActualColor()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getactualcolor)")
    ADD_CLASS_METHOD(SetActualColor,"void wxHtmlWinParser::SetActualColor(wxColour const & clr)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setactualcolor)")
    ADD_CLASS_METHOD(GetLink,"wxHtmlLinkInfo const & wxHtmlWinParser::GetLink()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getlink)")
    ADD_CLASS_METHOD(SetLink,"void wxHtmlWinParser::SetLink(wxHtmlLinkInfo const & link)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setlink)")
    ADD_CLASS_METHOD(ApplyStateToCell,"void wxHtmlWinParser::ApplyStateToCell(wxHtmlCell * cell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#applystatetocell)")
    ADD_CLASS_METHOD(CreateCurrentFont,"wxFont * wxHtmlWinParser::CreateCurrentFont()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#createcurrentfont)")
    ADD_CLASS_METHOD(SetWhitespaceMode,"void wxHtmlWinParser::SetWhitespaceMode(wxHtmlWinParser::WhitespaceMode mode)  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#setwhitespacemode)")
    ADD_CLASS_METHOD(GetWhitespaceMode,"wxHtmlWinParser::WhitespaceMode wxHtmlWinParser::GetWhitespaceMode()  (http://docs.wxwidgets.org/stable/wx_wxhtmlwinparser.html#getwhitespacemode)")





    void AddMethods(WrapClass<wxHtmlWinParser>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlWinParser_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlWinParser_h
