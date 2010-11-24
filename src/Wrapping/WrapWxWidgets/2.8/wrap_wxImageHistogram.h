/**
 * C++ Interface: wrap_wxImageHistogram
 *
 * Description: wrapping wxImageHistogram
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHistogram_h_
#define _wrap_wxImageHistogram_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxImageHistogramBase.h"



AMI_DECLARE_TYPE(wxImageHistogram);

// TODO: check for inheritence ...
class WrapClass_wxImageHistogram : public WrapClass<wxImageHistogram>
    , public   WrapClass_wxImageHistogramBase
{
  DEFINE_CLASS(WrapClass_wxImageHistogram);

  protected:
    typedef WrapClass<wxImageHistogram>::ptr _parentclass_ptr;
    typedef wxImageHistogram ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHistogram>& GetObj() const { return WrapClass<wxImageHistogram>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHistogram(boost::shared_ptr<wxImageHistogram > si): 
    WrapClass<wxImageHistogram>(si)
    , WrapClass_wxImageHistogramBase(si)
    {}

    /// Destructor
    ~WrapClass_wxImageHistogram()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogram_1,"Constructor wxImageHistogram::wxImageHistogram(wxImageHistogram const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#wximagehistogram).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogram,"Constructor wxImageHistogram::wxImageHistogram() (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#wximagehistogram).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxImageHistogram_2,"Constructor wxImageHistogram::wxImageHistogram() (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#wximagehistogram).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHistogram*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(MakeKey,"long unsigned int wxImageHistogram::MakeKey(unsigned char r, unsigned char g, unsigned char b) (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#makekey).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(FindFirstUnusedColour,"bool wxImageHistogram::FindFirstUnusedColour(unsigned char * r, unsigned char * g, unsigned char * b, unsigned char startR = 1, unsigned char startG = 0, unsigned char startB = 0)  (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#findfirstunusedcolour)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHistogram & wxImageHistogram::operator =(wxImageHistogram const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehistogram.html#__assign__)")




    void AddMethods(WrapClass<wxImageHistogram>::ptr this_ptr );

};


#endif // _wrap_wxImageHistogram_h
