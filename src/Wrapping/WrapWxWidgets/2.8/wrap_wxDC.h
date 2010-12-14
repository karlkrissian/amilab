/**
 * C++ Interface: wrap_wxDC
 *
 * Description: wrapping wxDC
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxDC_h_
#define _wrap_wxDC_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxDCBase.h"


#ifndef wxDC_declared
  #define wxDC_declared
  AMI_DECLARE_TYPE(wxDC);
#endif

// TODO: check for inheritence ...
class WrapClass_wxDC : public WrapClass<wxDC>
    , public   WrapClass_wxDCBase
{
  DEFINE_CLASS(WrapClass_wxDC);

  protected:
    typedef WrapClass<wxDC>::ptr _parentclass_ptr;
    typedef wxDC ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxDC>& GetObj() const { return WrapClass<wxDC>::GetObj(); }

    /// Constructor
    WrapClass_wxDC(boost::shared_ptr<wxDC > si): 
    WrapClass<wxDC>(si)
    , WrapClass_wxDCBase(si)
    {}

    /// Destructor
    ~WrapClass_wxDC()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxDC*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetColourMap,"void wxDC::SetColourMap(wxPalette const & palette)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setcolourmap)")
    ADD_CLASS_METHOD(GetPPI,"wxSize wxDC::GetPPI()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#getppi)")
    ADD_CLASS_METHOD(StartDoc,"bool wxDC::StartDoc(wxString const & param0)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#startdoc)")
    ADD_CLASS_METHOD(EndDoc,"void wxDC::EndDoc()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#enddoc)")
    ADD_CLASS_METHOD(StartPage,"void wxDC::StartPage()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#startpage)")
    ADD_CLASS_METHOD(EndPage,"void wxDC::EndPage()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#endpage)")
    ADD_CLASS_METHOD(SetMapMode,"void wxDC::SetMapMode(int mode)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setmapmode)")
    ADD_CLASS_METHOD(SetUserScale,"void wxDC::SetUserScale(double x, double y)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setuserscale)")
    ADD_CLASS_METHOD(SetLogicalScale,"void wxDC::SetLogicalScale(double x, double y)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setlogicalscale)")
    ADD_CLASS_METHOD(SetLogicalOrigin,"void wxDC::SetLogicalOrigin(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setlogicalorigin)")
    ADD_CLASS_METHOD(SetDeviceOrigin,"void wxDC::SetDeviceOrigin(wxCoord x, wxCoord y)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setdeviceorigin)")
    ADD_CLASS_METHOD(SetAxisOrientation,"void wxDC::SetAxisOrientation(bool xLeftRight, bool yBottomUp)  (http://docs.wxwidgets.org/stable/wx_wxdc.html#setaxisorientation)")
    ADD_CLASS_METHOD(ComputeScaleAndOrigin,"void wxDC::ComputeScaleAndOrigin()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#computescaleandorigin)")
/* The following types are missing: _GdkDrawable
    ADD_CLASS_METHOD(GetGDKWindow,"GdkWindow * wxDC::GetGDKWindow()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#getgdkwindow)")
*/
    ADD_CLASS_METHOD(GetSelectedBitmap,"wxBitmap wxDC::GetSelectedBitmap()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#getselectedbitmap)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxDC::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxdc.html#getclassinfo)")





    void AddMethods(WrapClass<wxDC>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxDC_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxDC_h
