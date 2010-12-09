/**
 * C++ Interface: wrap_wxScrollHelperNative
 *
 * Description: wrapping wxScrollHelperNative
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxScrollHelperNative_h_
#define _wrap_wxScrollHelperNative_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxScrollHelper.h"



AMI_DECLARE_TYPE(wxScrollHelperNative);

// TODO: check for inheritence ...
class WrapClass_wxScrollHelperNative : public WrapClass<wxScrollHelperNative>
    , public   WrapClass_wxScrollHelper
{
  DEFINE_CLASS(WrapClass_wxScrollHelperNative);

  protected:
    typedef WrapClass<wxScrollHelperNative>::ptr _parentclass_ptr;
    typedef wxScrollHelperNative ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxScrollHelperNative>& GetObj() const { return WrapClass<wxScrollHelperNative>::GetObj(); }

    /// Constructor
    WrapClass_wxScrollHelperNative(boost::shared_ptr<wxScrollHelperNative > si): 
    WrapClass<wxScrollHelperNative>(si)
    , WrapClass_wxScrollHelper(si)
    {}

    /// Destructor
    ~WrapClass_wxScrollHelperNative()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxScrollHelperNative,"Constructor wxScrollHelperNative::wxScrollHelperNative(wxWindow * win) (http://docs.wxwidgets.org/stable/wx_wxscrollhelpernative.html#wxscrollhelpernative).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxScrollHelperNative*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetScrollbars,"void wxScrollHelperNative::SetScrollbars(int pixelsPerUnitX, int pixelsPerUnitY, int noUnitsX, int noUnitsY, int xPos = 0, int yPos = 0, bool noRefresh = false)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelpernative.html#setscrollbars)")
    ADD_CLASS_METHOD(AdjustScrollbars,"void wxScrollHelperNative::AdjustScrollbars()  (http://docs.wxwidgets.org/stable/wx_wxscrollhelpernative.html#adjustscrollbars)")
    ADD_CLASS_METHOD(Scroll,"void wxScrollHelperNative::Scroll(int x, int y)  (http://docs.wxwidgets.org/stable/wx_wxscrollhelpernative.html#scroll)")





    void AddMethods(WrapClass<wxScrollHelperNative>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxScrollHelperNative_h
