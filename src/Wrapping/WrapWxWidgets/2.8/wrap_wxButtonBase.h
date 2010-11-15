/**
 * C++ Interface: wrap_wxButtonBase
 *
 * Description: wrapping wxButtonBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxButtonBase_h_
#define _wrap_wxButtonBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"


AMI_DECLARE_TYPE(wxButtonBase);

// TODO: check for inheritence ...
class WrapClass_wxButtonBase : public WrapClass<wxButtonBase>
    , public   WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxButtonBase);

  protected:
    typedef WrapClass<wxButtonBase>::ptr _parentclass_ptr;
    typedef wxButtonBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxButtonBase>& GetObj() const { return WrapClass<wxButtonBase>::GetObj(); }

    /// Constructor
    WrapClass_wxButtonBase(boost::shared_ptr<wxButtonBase > si): 
    WrapClass<wxButtonBase>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxButtonBase()
    {
      std::cout << "~WrapClass_wxButtonBase()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxButtonBase,"Constructor wxButtonBase::wxButtonBase() (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#wxbuttonbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxButtonBase*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetImageLabel,"void wxButtonBase::SetImageLabel(wxBitmap const & param0)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setimagelabel)")
    ADD_CLASS_METHOD(SetImageMargins,"void wxButtonBase::SetImageMargins(wxCoord param0, wxCoord param1)  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setimagemargins)")
    ADD_CLASS_METHOD(SetDefault,"void wxButtonBase::SetDefault()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#setdefault)")
    ADD_CLASS_METHOD(ShouldInheritColours,"bool wxButtonBase::ShouldInheritColours()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#shouldinheritcolours)")
    ADD_CLASS_METHOD(GetDefaultSize,"wxSize wxButtonBase::GetDefaultSize()  (http://docs.wxwidgets.org/stable/wx_wxbuttonbase.html#getdefaultsize)")





    void AddMethods(WrapClass<wxButtonBase>::ptr this_ptr )
    {
      
      // Add members from wxControl
      WrapClass_wxControl::ptr parent_wxControl(        boost::dynamic_pointer_cast<WrapClass_wxControl >(this_ptr));
      parent_wxControl->AddMethods(parent_wxControl);


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_SetImageLabel( this_ptr);
      AddVar_SetImageMargins( this_ptr);
      AddVar_SetDefault( this_ptr);
      AddVar_ShouldInheritColours( this_ptr);
      AddVar_GetDefaultSize( this_ptr);



      
    };
};


#endif // _wrap_wxButtonBase_h
