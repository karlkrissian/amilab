/**
 * C++ Interface: wrap_wxHtmlRenderingState
 *
 * Description: wrapping wxHtmlRenderingState
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxHtmlRenderingState_h_
#define _wrap_wxHtmlRenderingState_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxHtmlRenderingState_declared
  #define wxHtmlRenderingState_declared
  AMI_DECLARE_TYPE(wxHtmlRenderingState);
#endif

// TODO: check for inheritence ...
class WrapClass_wxHtmlRenderingState : public WrapClass<wxHtmlRenderingState>
    
{
  DEFINE_CLASS(WrapClass_wxHtmlRenderingState);

  protected:
    typedef WrapClass<wxHtmlRenderingState>::ptr _parentclass_ptr;
    typedef wxHtmlRenderingState ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxHtmlRenderingState>& GetObj() const { return WrapClass<wxHtmlRenderingState>::GetObj(); }

    /// Constructor
    WrapClass_wxHtmlRenderingState(boost::shared_ptr<wxHtmlRenderingState > si): 
    WrapClass<wxHtmlRenderingState>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxHtmlRenderingState()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingState_1,"Constructor wxHtmlRenderingState::wxHtmlRenderingState(wxHtmlRenderingState const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#wxhtmlrenderingstate).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingState,"Constructor wxHtmlRenderingState::wxHtmlRenderingState() (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#wxhtmlrenderingstate).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxHtmlRenderingState_2,"Constructor wxHtmlRenderingState::wxHtmlRenderingState() (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#wxhtmlrenderingstate).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxHtmlRenderingState*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(SetSelectionState,"void wxHtmlRenderingState::SetSelectionState(wxHtmlSelectionState s)  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#setselectionstate)")
    ADD_CLASS_METHOD(GetSelectionState,"wxHtmlSelectionState wxHtmlRenderingState::GetSelectionState()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#getselectionstate)")
    ADD_CLASS_METHOD(SetFgColour,"void wxHtmlRenderingState::SetFgColour(wxColour const & c)  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#setfgcolour)")
    ADD_CLASS_METHOD(GetFgColour,"wxColour const & wxHtmlRenderingState::GetFgColour()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#getfgcolour)")
    ADD_CLASS_METHOD(SetBgColour,"void wxHtmlRenderingState::SetBgColour(wxColour const & c)  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#setbgcolour)")
    ADD_CLASS_METHOD(GetBgColour,"wxColour const & wxHtmlRenderingState::GetBgColour()  (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#getbgcolour)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxHtmlRenderingState & wxHtmlRenderingState::operator =(wxHtmlRenderingState const & param0) (http://docs.wxwidgets.org/stable/wx_wxhtmlrenderingstate.html#__assign__)")




    void AddMethods(WrapClass<wxHtmlRenderingState>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxHtmlRenderingState_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxHtmlRenderingState_h
