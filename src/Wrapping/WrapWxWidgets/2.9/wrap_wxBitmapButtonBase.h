/**
 * C++ Interface: wrap_wxBitmapButtonBase
 *
 * Description: wrapping wxBitmapButtonBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBitmapButtonBase_h_
#define _wrap_wxBitmapButtonBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxButton.h"


AMI_DECLARE_TYPE(wxBitmapButtonBase);

// TODO: check for inheritence ...
class WrapClass_wxBitmapButtonBase : public WrapClass<wxBitmapButtonBase>
    , public   WrapClass_wxButton
{
  DEFINE_CLASS(WrapClass_wxBitmapButtonBase);

  protected:
    typedef WrapClass<wxBitmapButtonBase>::ptr _parentclass_ptr;
    typedef wxBitmapButtonBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBitmapButtonBase>& GetObj() const { return WrapClass<wxBitmapButtonBase>::GetObj(); }

    /// Constructor
    WrapClass_wxBitmapButtonBase(boost::shared_ptr<wxBitmapButtonBase > si): 
    WrapClass<wxBitmapButtonBase>(si)
    , WrapClass_wxButton(si)
    {}

    /// Destructor
    ~WrapClass_wxBitmapButtonBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBitmapButtonBase,"Constructor wxBitmapButtonBase::wxBitmapButtonBase() (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#wxbitmapbuttonbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBitmapButtonBase*);

    // here add each method
    
    // Adding standard methods
/* The following types are missing: wxValidator
    ADD_CLASS_METHOD(Create,"bool wxBitmapButtonBase::Create(wxWindow * parent, wxWindowID winid, wxPoint const & pos, wxSize const & size, long int style, wxValidator const & validator, wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#create)")
*/
    ADD_CLASS_METHOD(SetMargins,"void wxBitmapButtonBase::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setmargins)")
    ADD_CLASS_METHOD(GetMarginX,"int wxBitmapButtonBase::GetMarginX()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getmarginx)")
    ADD_CLASS_METHOD(GetMarginY,"int wxBitmapButtonBase::GetMarginY()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getmarginy)")





    void AddMethods(WrapClass<wxBitmapButtonBase>::ptr this_ptr );

};


#endif // _wrap_wxBitmapButtonBase_h
