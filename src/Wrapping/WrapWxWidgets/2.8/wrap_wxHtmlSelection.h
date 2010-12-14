/**
 * C++ Interface: wrap_wxHtmlSelection
 *
 * Description: wrapping wxHtmlSelection
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlSelection_h_
#define _wrap_wxHtmlSelection_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxHtmlSelection_declared
  #define wxHtmlSelection_declared
  AMI_DECLARE_TYPE(wxHtmlSelection);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlSelection : public WrapClass<wxHtmlSelection>
    
{
  DEFINE_CLASS(WrapClass_wxHtmlSelection);

  protected:
    typedef WrapClass<wxHtmlSelection>::ptr _parentclass_ptr;
    typedef wxHtmlSelection ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlSelection>& GetObj() const { return WrapClass<wxHtmlSelection>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlSelection(boost::shared_ptr<wxHtmlSelection > si): 
    WrapClass<wxHtmlSelection>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxHtmlSelection()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlSelection_1,"Constructor wxHtmlSelection::wxHtmlSelection(wxHtmlSelection const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#wxhtmlselection).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlSelection,"Constructor wxHtmlSelection::wxHtmlSelection() (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#wxhtmlselection).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlSelection_2,"Constructor wxHtmlSelection::wxHtmlSelection() (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#wxhtmlselection).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlSelection*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Set_1,"void wxHtmlSelection::Set(wxPoint const & fromPos, wxHtmlCell const * fromCell, wxPoint const & toPos, wxHtmlCell const * toCell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#set)")
    ADD_CLASS_METHOD(Set,"wxHtmlSelection::Set()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#set)")
    ADD_CLASS_METHOD(Set_2,"void wxHtmlSelection::Set(wxHtmlCell const * fromCell, wxHtmlCell const * toCell)  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#set)")
    ADD_CLASS_METHOD(GetFromCell,"wxHtmlCell const * wxHtmlSelection::GetFromCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#getfromcell)")
    ADD_CLASS_METHOD(GetToCell,"wxHtmlCell const * wxHtmlSelection::GetToCell()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#gettocell)")
    ADD_CLASS_METHOD(GetFromPos,"wxPoint const & wxHtmlSelection::GetFromPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#getfrompos)")
    ADD_CLASS_METHOD(GetToPos,"wxPoint const & wxHtmlSelection::GetToPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#gettopos)")
    ADD_CLASS_METHOD(GetFromPrivPos,"wxPoint const & wxHtmlSelection::GetFromPrivPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#getfromprivpos)")
    ADD_CLASS_METHOD(GetToPrivPos,"wxPoint const & wxHtmlSelection::GetToPrivPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#gettoprivpos)")
    ADD_CLASS_METHOD(SetFromPrivPos,"void wxHtmlSelection::SetFromPrivPos(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#setfromprivpos)")
    ADD_CLASS_METHOD(SetToPrivPos,"void wxHtmlSelection::SetToPrivPos(wxPoint const & pos)  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#settoprivpos)")
    ADD_CLASS_METHOD(ClearPrivPos,"void wxHtmlSelection::ClearPrivPos()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#clearprivpos)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxHtmlSelection::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#isempty)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlSelection & wxHtmlSelection::operator =(wxHtmlSelection const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlselection.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlSelection>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlSelection_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlSelection_h
