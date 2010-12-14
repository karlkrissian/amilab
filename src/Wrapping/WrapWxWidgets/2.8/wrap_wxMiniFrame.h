/**
 * C++ Interface: wrap_wxMiniFrame
 *
 * Description: wrapping wxMiniFrame
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMiniFrame_h_
#define _wrap_wxMiniFrame_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxFrame.h"


#ifndef wxMiniFrame_declared
  #define wxMiniFrame_declared
  AMI_DECLARE_TYPE(wxMiniFrame);
#endif

// TODO: check for inheritence ...
class WrapClass_wxMiniFrame : public WrapClass<wxMiniFrame>
    , public   WrapClass_wxFrame
{
  DEFINE_CLASS(WrapClass_wxMiniFrame);

  protected:
    typedef WrapClass<wxMiniFrame>::ptr _parentclass_ptr;
    typedef wxMiniFrame ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMiniFrame>& GetObj() const { return WrapClass<wxMiniFrame>::GetObj(); }

    /// Constructor
    WrapClass_wxMiniFrame(boost::shared_ptr<wxMiniFrame > si): 
    WrapClass<wxMiniFrame>(si)
    , WrapClass_wxFrame(si)
    {}

    /// Destructor
    ~WrapClass_wxMiniFrame()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMiniFrame_1,"Constructor wxMiniFrame::wxMiniFrame() (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#wxminiframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMiniFrame,"Constructor wxMiniFrame::wxMiniFrame() (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#wxminiframe).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxMiniFrame_2,"Constructor wxMiniFrame::wxMiniFrame(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536870976, wxString const & name = wxFrameNameStr) (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#wxminiframe).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMiniFrame*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxMiniFrame::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#getclassinfo)")
    ADD_CLASS_METHOD(Create,"bool wxMiniFrame::Create(wxWindow * parent, wxWindowID id, wxString const & title, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 536870976, wxString const & name = wxFrameNameStr)  (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#create)")
    ADD_CLASS_METHOD(SetTitle,"void wxMiniFrame::SetTitle(wxString const & title)  (http://docs.wxwidgets.org/stable/wx_wxminiframe.html#settitle)")





    void AddMethods(WrapClass<wxMiniFrame>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxMiniFrame_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxMiniFrame_h
