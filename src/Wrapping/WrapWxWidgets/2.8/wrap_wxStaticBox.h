/**
 * C++ Interface: wrap_wxStaticBox
 *
 * Description: wrapping wxStaticBox
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStaticBox_h_
#define _wrap_wxStaticBox_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxStaticBoxBase.h"


#ifndef wxStaticBox_declared
  #define wxStaticBox_declared
  AMI_DECLARE_TYPE(wxStaticBox);
#endif

// TODO: check for inheritence ...
class WrapClass_wxStaticBox : public WrapClass<wxStaticBox>
    , public   WrapClass_wxStaticBoxBase
{
  DEFINE_CLASS(WrapClass_wxStaticBox);

  protected:
    typedef WrapClass<wxStaticBox>::ptr _parentclass_ptr;
    typedef wxStaticBox ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStaticBox>& GetObj() const { return WrapClass<wxStaticBox>::GetObj(); }

    /// Constructor
    WrapClass_wxStaticBox(boost::shared_ptr<wxStaticBox > si): 
    WrapClass<wxStaticBox>(si)
    , WrapClass_wxStaticBoxBase(si)
    {}

    /// Destructor
    ~WrapClass_wxStaticBox()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBox_1,"Constructor wxStaticBox::wxStaticBox() (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#wxstaticbox).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBox,"Constructor wxStaticBox::wxStaticBox() (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#wxstaticbox).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBox_2,"Constructor wxStaticBox::wxStaticBox(wxWindow * parent, wxWindowID id, wxString const & label, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxStaticBoxNameStr) (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#wxstaticbox).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStaticBox*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(GetClassDefaultAttributes,"wxVisualAttributes wxStaticBox::GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL) (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#getclassdefaultattributes).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Create,"bool wxStaticBox::Create(wxWindow * parent, wxWindowID id, wxString const & label, wxPoint const & pos = wxDefaultPosition, wxSize const & size = wxDefaultSize, long int style = 0, wxString const & name = wxStaticBoxNameStr)  (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#create)")
    ADD_CLASS_METHOD(SetLabel,"void wxStaticBox::SetLabel(wxString const & label)  (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#setlabel)")
    ADD_CLASS_METHOD(IsTransparentForMouse,"bool wxStaticBox::IsTransparentForMouse()  (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#istransparentformouse)")
    ADD_CLASS_METHOD(GetBordersForSizer,"void wxStaticBox::GetBordersForSizer(int * borderTop, int * borderOther)  (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#getbordersforsizer)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxStaticBox::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxstaticbox.html#getclassinfo)")





    void AddMethods(WrapClass<wxStaticBox>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStaticBox_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxStaticBox_h
