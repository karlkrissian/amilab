/**
 * C++ Interface: wrap_wxRegionBase
 *
 * Description: wrapping wxRegionBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxRegionBase_h_
#define _wrap_wxRegionBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"


#ifndef wxRegionBase_declared
  #define wxRegionBase_declared
  AMI_DECLARE_TYPE(wxRegionBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxRegionBase : public WrapClass<wxRegionBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxRegionBase);

  protected:
    typedef WrapClass<wxRegionBase>::ptr _parentclass_ptr;
    typedef wxRegionBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxRegionBase>& GetObj() const { return WrapClass<wxRegionBase>::GetObj(); }

    /// Constructor
    WrapClass_wxRegionBase(boost::shared_ptr<wxRegionBase > si): 
    WrapClass<wxRegionBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxRegionBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxRegionBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxRegionBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#ok)")
    ADD_CLASS_METHOD(IsOk,"bool wxRegionBase::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#isok)")
    ADD_CLASS_METHOD(Empty,"bool wxRegionBase::Empty()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#empty)")
    ADD_CLASS_METHOD(IsEqual,"bool wxRegionBase::IsEqual(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#isequal)")
    ADD_CLASS_METHOD(GetBox_1,"bool wxRegionBase::GetBox(wxCoord & x, wxCoord & y, wxCoord & w, wxCoord & h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#getbox)")
    ADD_CLASS_METHOD(GetBox,"wxRegionBase::GetBox()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#getbox)")
    ADD_CLASS_METHOD(GetBox_2,"wxRect wxRegionBase::GetBox()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#getbox)")
    ADD_CLASS_METHOD(Contains_1,"wxRegionContain wxRegionBase::Contains(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#contains)")
    ADD_CLASS_METHOD(Contains,"wxRegionBase::Contains()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#contains)")
    ADD_CLASS_METHOD(Contains_2,"wxRegionContain wxRegionBase::Contains(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#contains)")
    ADD_CLASS_METHOD(Contains_3,"wxRegionContain wxRegionBase::Contains(wxCoord x, wxCoord y, wxCoord w, wxCoord h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#contains)")
    ADD_CLASS_METHOD(Contains_4,"wxRegionContain wxRegionBase::Contains(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#contains)")
    ADD_CLASS_METHOD(Offset_1,"bool wxRegionBase::Offset(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#offset)")
    ADD_CLASS_METHOD(Offset,"wxRegionBase::Offset()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#offset)")
    ADD_CLASS_METHOD(Offset_2,"bool wxRegionBase::Offset(wxPoint const & pt)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#offset)")
    ADD_CLASS_METHOD(Union_1,"bool wxRegionBase::Union(wxCoord x, wxCoord y, wxCoord w, wxCoord h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Union,"wxRegionBase::Union()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Union_2,"bool wxRegionBase::Union(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Union_3,"bool wxRegionBase::Union(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Union_4,"bool wxRegionBase::Union(wxBitmap const & bmp)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Union_5,"bool wxRegionBase::Union(wxBitmap const & bmp, wxColour const & transp, int tolerance = 0)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#union)")
    ADD_CLASS_METHOD(Intersect_1,"bool wxRegionBase::Intersect(wxCoord x, wxCoord y, wxCoord w, wxCoord h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#intersect)")
    ADD_CLASS_METHOD(Intersect,"wxRegionBase::Intersect()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#intersect)")
    ADD_CLASS_METHOD(Intersect_2,"bool wxRegionBase::Intersect(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#intersect)")
    ADD_CLASS_METHOD(Intersect_3,"bool wxRegionBase::Intersect(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#intersect)")
    ADD_CLASS_METHOD(Subtract_1,"bool wxRegionBase::Subtract(wxCoord x, wxCoord y, wxCoord w, wxCoord h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#subtract)")
    ADD_CLASS_METHOD(Subtract,"wxRegionBase::Subtract()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#subtract)")
    ADD_CLASS_METHOD(Subtract_2,"bool wxRegionBase::Subtract(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#subtract)")
    ADD_CLASS_METHOD(Subtract_3,"bool wxRegionBase::Subtract(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#subtract)")
    ADD_CLASS_METHOD(Xor_1,"bool wxRegionBase::Xor(wxCoord x, wxCoord y, wxCoord w, wxCoord h)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#xor)")
    ADD_CLASS_METHOD(Xor,"wxRegionBase::Xor()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#xor)")
    ADD_CLASS_METHOD(Xor_2,"bool wxRegionBase::Xor(wxRect const & rect)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#xor)")
    ADD_CLASS_METHOD(Xor_3,"bool wxRegionBase::Xor(wxRegion const & region)  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#xor)")
    ADD_CLASS_METHOD(ConvertToBitmap,"wxBitmap wxRegionBase::ConvertToBitmap()  (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#converttobitmap)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxRegionBase & wxRegionBase::operator =(wxRegionBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool wxRegionBase::operator ==(wxRegion const & region) (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool wxRegionBase::operator !=(wxRegion const & region) (http://docs.wxwidgets.org/stable/wx_wxregionbase.html#__not_equal__)")




    void AddMethods(WrapClass<wxRegionBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxRegionBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxRegionBase_h
