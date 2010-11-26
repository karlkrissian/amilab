/**
 * C++ Interface: wrap_wxPoint
 *
 * Description: wrapping wxPoint
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPoint_h_
#define _wrap_wxPoint_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxPoint);

// TODO: check for inheritence ...
class WrapClass_wxPoint : public WrapClass<wxPoint>
    
{
  DEFINE_CLASS(WrapClass_wxPoint);

  protected:
    typedef WrapClass<wxPoint>::ptr _parentclass_ptr;
    typedef wxPoint ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPoint>& GetObj() const { return WrapClass<wxPoint>::GetObj(); }

    /// Constructor
    WrapClass_wxPoint(boost::shared_ptr<wxPoint > si): 
    WrapClass<wxPoint>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxPoint()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint_1,"Constructor wxPoint::wxPoint(wxPoint const & param0) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint,"Constructor wxPoint::wxPoint() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint_2,"Constructor wxPoint::wxPoint() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint_3,"Constructor wxPoint::wxPoint(int xx, int yy) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPoint*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPoint & wxPoint::operator =(wxPoint const & param0) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxPoint::operator ==(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxPoint::operator !=(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__not_equal__)")
    ADD_CLASS_METHOD(__add___1,            "wxPoint wxPoint::operator +(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add__)")
    ADD_CLASS_METHOD(__substract___1,            "wxPoint wxPoint::operator -(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__substract__)")
    ADD_CLASS_METHOD(__add_assign___1,            "wxPoint & wxPoint::operator +=(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add_assign__)")
    ADD_CLASS_METHOD(__sub_assign___1,            "wxPoint & wxPoint::operator -=(wxPoint const & p) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__sub_assign__)")
    ADD_CLASS_METHOD(__add_assign__,            "wxPoint::operator +=() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "wxPoint & wxPoint::operator +=(wxSize const & s) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add_assign__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxPoint::operator -=() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__sub_assign__)")
    ADD_CLASS_METHOD(__sub_assign___2,            "wxPoint & wxPoint::operator -=(wxSize const & s) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__sub_assign__)")
    ADD_CLASS_METHOD(__add__,            "wxPoint::operator +() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add__)")
    ADD_CLASS_METHOD(__add___2,            "wxPoint wxPoint::operator +(wxSize const & s) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__add__)")
    ADD_CLASS_METHOD(__substract__,            "wxPoint::operator -() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__substract__)")
    ADD_CLASS_METHOD(__substract___2,            "wxPoint wxPoint::operator -(wxSize const & s) (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__substract__)")
    ADD_CLASS_METHOD(__substract___3,            "wxPoint wxPoint::operator -() (http://docs.wxwidgets.org/stable/wx_wxpoint.html#__substract__)")




    void AddMethods(WrapClass<wxPoint>::ptr this_ptr );

};


#endif // _wrap_wxPoint_h
