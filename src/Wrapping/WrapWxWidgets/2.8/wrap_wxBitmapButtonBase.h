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

#include "wx_includes.h"

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

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetBitmapLabel,"void wxBitmapButtonBase::SetBitmapLabel(wxBitmap const & bitmap)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setbitmaplabel)")
    ADD_CLASS_METHOD(SetBitmapSelected,"void wxBitmapButtonBase::SetBitmapSelected(wxBitmap const & sel)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setbitmapselected)")
    ADD_CLASS_METHOD(SetBitmapFocus,"void wxBitmapButtonBase::SetBitmapFocus(wxBitmap const & focus)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setbitmapfocus)")
    ADD_CLASS_METHOD(SetBitmapDisabled,"void wxBitmapButtonBase::SetBitmapDisabled(wxBitmap const & disabled)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setbitmapdisabled)")
    ADD_CLASS_METHOD(SetBitmapHover,"void wxBitmapButtonBase::SetBitmapHover(wxBitmap const & hover)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setbitmaphover)")
    ADD_CLASS_METHOD(GetBitmapLabel_1,"wxBitmap const & wxBitmapButtonBase::GetBitmapLabel()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaplabel)")
    ADD_CLASS_METHOD(GetBitmapSelected_1,"wxBitmap const & wxBitmapButtonBase::GetBitmapSelected()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapselected)")
    ADD_CLASS_METHOD(GetBitmapFocus_1,"wxBitmap const & wxBitmapButtonBase::GetBitmapFocus()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapfocus)")
    ADD_CLASS_METHOD(GetBitmapDisabled_1,"wxBitmap const & wxBitmapButtonBase::GetBitmapDisabled()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapdisabled)")
    ADD_CLASS_METHOD(GetBitmapHover_1,"wxBitmap const & wxBitmapButtonBase::GetBitmapHover()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaphover)")
    ADD_CLASS_METHOD(GetBitmapLabel,"wxBitmapButtonBase::GetBitmapLabel()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaplabel)")
    ADD_CLASS_METHOD(GetBitmapLabel_2,"wxBitmap & wxBitmapButtonBase::GetBitmapLabel()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaplabel)")
    ADD_CLASS_METHOD(GetBitmapSelected,"wxBitmapButtonBase::GetBitmapSelected()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapselected)")
    ADD_CLASS_METHOD(GetBitmapSelected_2,"wxBitmap & wxBitmapButtonBase::GetBitmapSelected()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapselected)")
    ADD_CLASS_METHOD(GetBitmapFocus,"wxBitmapButtonBase::GetBitmapFocus()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapfocus)")
    ADD_CLASS_METHOD(GetBitmapFocus_2,"wxBitmap & wxBitmapButtonBase::GetBitmapFocus()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapfocus)")
    ADD_CLASS_METHOD(GetBitmapDisabled,"wxBitmapButtonBase::GetBitmapDisabled()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapdisabled)")
    ADD_CLASS_METHOD(GetBitmapDisabled_2,"wxBitmap & wxBitmapButtonBase::GetBitmapDisabled()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmapdisabled)")
    ADD_CLASS_METHOD(GetBitmapHover,"wxBitmapButtonBase::GetBitmapHover()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaphover)")
    ADD_CLASS_METHOD(GetBitmapHover_2,"wxBitmap & wxBitmapButtonBase::GetBitmapHover()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getbitmaphover)")
    ADD_CLASS_METHOD(SetMargins,"void wxBitmapButtonBase::SetMargins(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#setmargins)")
    ADD_CLASS_METHOD(GetMarginX,"int wxBitmapButtonBase::GetMarginX()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getmarginx)")
    ADD_CLASS_METHOD(GetMarginY,"int wxBitmapButtonBase::GetMarginY()  (http://docs.wxwidgets.org/stable/wx_wxbitmapbuttonbase.html#getmarginy)")





    void AddMethods(WrapClass<wxBitmapButtonBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxBitmapButtonBase_h
