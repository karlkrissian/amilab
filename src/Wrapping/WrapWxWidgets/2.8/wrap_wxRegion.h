/**
 * C++ Interface: wrap_wxRegion
 *
 * Description: wrapping wxRegion
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxRegion_h_
#define _wrap_wxRegion_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxRegionBase.h"


#ifndef wxRegion_declared
  #define wxRegion_declared
  AMI_DECLARE_TYPE(wxRegion);
#endif

// TODO: check for inheritence ...
class WrapClass_wxRegion : public WrapClass<wxRegion>
    , public   WrapClass_wxRegionBase
{
  DEFINE_CLASS(WrapClass_wxRegion);

  protected:
    typedef WrapClass<wxRegion>::ptr _parentclass_ptr;
    typedef wxRegion ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxRegion>& GetObj() const { return WrapClass<wxRegion>::GetObj(); }

    /// Constructor
    WrapClass_wxRegion(boost::shared_ptr<wxRegion > si): 
    WrapClass<wxRegion>(si)
    , WrapClass_wxRegionBase(si)
    {}

    /// Destructor
    ~WrapClass_wxRegion()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_1,"Constructor wxRegion::wxRegion(wxRegion const & param0) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion,"Constructor wxRegion::wxRegion() (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_2,"Constructor wxRegion::wxRegion() (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_3,"Constructor wxRegion::wxRegion(wxCoord x, wxCoord y, wxCoord w, wxCoord h) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_4,"Constructor wxRegion::wxRegion(wxPoint const & topLeft, wxPoint const & bottomRight) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_5,"Constructor wxRegion::wxRegion(wxRect const & rect) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_6,"Constructor wxRegion::wxRegion(size_t n, wxPoint const * points, int fillStyle = wxODDEVEN_RULE) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_7,"Constructor wxRegion::wxRegion(wxBitmap const & bmp) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_8,"Constructor wxRegion::wxRegion(wxBitmap const & bmp, wxColour const & transColour, int tolerance = 0) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    /* The following types are missing: _GdkRegion
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRegion_9,"Constructor wxRegion::wxRegion(GdkRegion * region) (http://docs.wxwidgets.org/stable/wx_wxregion.html#wxregion).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxRegion*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Clear,"void wxRegion::Clear()  (http://docs.wxwidgets.org/stable/wx_wxregion.html#clear)")
    ADD_CLASS_METHOD(IsEmpty,"bool wxRegion::IsEmpty()  (http://docs.wxwidgets.org/stable/wx_wxregion.html#isempty)")
/* The following types are missing: _GdkRegion
    ADD_CLASS_METHOD(GetRegion,"GdkRegion * wxRegion::GetRegion()  (http://docs.wxwidgets.org/stable/wx_wxregion.html#getregion)")
*/
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxRegion::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxregion.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxRegion & wxRegion::operator =(wxRegion const & param0) (http://docs.wxwidgets.org/stable/wx_wxregion.html#__assign__)")




    void AddMethods(WrapClass<wxRegion>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxRegion_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxRegion_h
