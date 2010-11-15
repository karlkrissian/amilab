/**
 * C++ Interface: wrap_wxSize
 *
 * Description: wrapping wxSize
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSize_h_
#define _wrap_wxSize_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxSize);

// TODO: check for inheritence ...
class WrapClass_wxSize : public WrapClass<wxSize>
    
{
  DEFINE_CLASS(WrapClass_wxSize);

  protected:
    typedef WrapClass<wxSize>::ptr _parentclass_ptr;
    typedef wxSize ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSize>& GetObj() const { return WrapClass<wxSize>::GetObj(); }

    /// Constructor
    WrapClass_wxSize(boost::shared_ptr<wxSize > si): 
    WrapClass<wxSize>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxSize()
    {
      std::cout << "~WrapClass_wxSize()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize_1,"Constructor wxSize::wxSize(wxSize const & param0) (http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize,"Constructor wxSize::wxSize() (http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize_2,"Constructor wxSize::wxSize() (http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize_3,"Constructor wxSize::wxSize(int xx, int yy) (http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSize*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IncTo,"void wxSize::IncTo(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#incto)")
    ADD_CLASS_METHOD(DecTo,"void wxSize::DecTo(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#decto)")
    ADD_CLASS_METHOD(IncBy_1,"void wxSize::IncBy(int dx, int dy)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#incby)")
    ADD_CLASS_METHOD(IncBy,"wxSize::IncBy()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#incby)")
    ADD_CLASS_METHOD(IncBy_2,"void wxSize::IncBy(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#incby)")
    ADD_CLASS_METHOD(IncBy_3,"void wxSize::IncBy(int d)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#incby)")
    ADD_CLASS_METHOD(DecBy_1,"void wxSize::DecBy(int dx, int dy)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#decby)")
    ADD_CLASS_METHOD(DecBy,"wxSize::DecBy()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#decby)")
    ADD_CLASS_METHOD(DecBy_2,"void wxSize::DecBy(wxSize const & sz)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#decby)")
    ADD_CLASS_METHOD(DecBy_3,"void wxSize::DecBy(int d)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#decby)")
    ADD_CLASS_METHOD(Scale,"wxSize & wxSize::Scale(float xscale, float yscale)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#scale)")
    ADD_CLASS_METHOD(Set,"void wxSize::Set(int xx, int yy)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#set)")
    ADD_CLASS_METHOD(SetWidth,"void wxSize::SetWidth(int w)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#setwidth)")
    ADD_CLASS_METHOD(SetHeight,"void wxSize::SetHeight(int h)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#setheight)")
    ADD_CLASS_METHOD(GetWidth,"int wxSize::GetWidth()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#getwidth)")
    ADD_CLASS_METHOD(GetHeight,"int wxSize::GetHeight()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#getheight)")
    ADD_CLASS_METHOD(IsFullySpecified,"bool wxSize::IsFullySpecified()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#isfullyspecified)")
    ADD_CLASS_METHOD(SetDefaults,"void wxSize::SetDefaults(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsize.html#setdefaults)")
    ADD_CLASS_METHOD(GetX,"int wxSize::GetX()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#getx)")
    ADD_CLASS_METHOD(GetY,"int wxSize::GetY()  (http://docs.wxwidgets.org/stable/wx_wxsize.html#gety)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxSize & wxSize::=(wxSize const & param0) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxSize::==(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxSize::!=(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__not_equal__)")
    ADD_CLASS_METHOD(__add__,            "wxSize wxSize::+(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__add__)")
    ADD_CLASS_METHOD(__substract__,            "wxSize wxSize::-(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__substract__)")
    // ADD_CLASS_METHOD(operator not available,"wxSize wxSize::/(int i) (http://docs.wxwidgets.org/stable/wx_wxsize.html#/)")
    // ADD_CLASS_METHOD(operator not available,"wxSize wxSize::*(int i) (http://docs.wxwidgets.org/stable/wx_wxsize.html#*)")
    ADD_CLASS_METHOD(__add_assign__,            "wxSize & wxSize::+=(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__add_assign__)")
    ADD_CLASS_METHOD(__sub_assign__,            "wxSize & wxSize::-=(wxSize const & sz) (http://docs.wxwidgets.org/stable/wx_wxsize.html#__sub_assign__)")
    // ADD_CLASS_METHOD(operator not available,"wxSize & wxSize::/=(int const i) (http://docs.wxwidgets.org/stable/wx_wxsize.html#/=)")
    // ADD_CLASS_METHOD(operator not available,"wxSize & wxSize::*=(int const i) (http://docs.wxwidgets.org/stable/wx_wxsize.html#*=)")




    void AddMethods(WrapClass<wxSize>::ptr this_ptr );

};


#endif // _wrap_wxSize_h
