/**
 * C++ Interface: wrap_wxDrawObject
 *
 * Description: wrapping wxDrawObject
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDrawObject_h_
#define _wrap_wxDrawObject_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxDrawObject);

// TODO: check for inheritence ...
class WrapClass_wxDrawObject : public WrapClass<wxDrawObject>
    
{
  DEFINE_CLASS(WrapClass_wxDrawObject);

  protected:
    typedef WrapClass<wxDrawObject>::ptr _parentclass_ptr;
    typedef wxDrawObject ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDrawObject>& GetObj() const { return WrapClass<wxDrawObject>::GetObj(); }

    /// Constructor
    WrapClass_wxDrawObject(boost::shared_ptr<wxDrawObject > si): 
    WrapClass<wxDrawObject>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxDrawObject()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDrawObject*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Draw,"void wxDrawObject::Draw(wxDCBase & param0)  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#draw)")
    ADD_CLASS_METHOD(CalcBoundingBox,"void wxDrawObject::CalcBoundingBox(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#calcboundingbox)")
    ADD_CLASS_METHOD(ResetBoundingBox,"void wxDrawObject::ResetBoundingBox()  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#resetboundingbox)")
    ADD_CLASS_METHOD(MinX,"wxCoord wxDrawObject::MinX()  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#minx)")
    ADD_CLASS_METHOD(MaxX,"wxCoord wxDrawObject::MaxX()  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#maxx)")
    ADD_CLASS_METHOD(MinY,"wxCoord wxDrawObject::MinY()  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#miny)")
    ADD_CLASS_METHOD(MaxY,"wxCoord wxDrawObject::MaxY()  (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#maxy)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxDrawObject & wxDrawObject::operator =(wxDrawObject const & param0) (http://docs.wxwidgets.org/stable/wx_wxdrawobject.html#__assign__)")




    void AddMethods(WrapClass<wxDrawObject>::ptr this_ptr );

};


#endif // _wrap_wxDrawObject_h
