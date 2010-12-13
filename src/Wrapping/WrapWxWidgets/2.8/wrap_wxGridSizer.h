/**
 * C++ Interface: wrap_wxGridSizer
 *
 * Description: wrapping wxGridSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxGridSizer_h_
#define _wrap_wxGridSizer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxSizer.h"


#ifndef wxGridSizer_declared
  #define wxGridSizer_declared
  AMI_DECLARE_TYPE(wxGridSizer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxGridSizer : public WrapClass<wxGridSizer>
    , public   WrapClass_wxSizer
{
  DEFINE_CLASS(WrapClass_wxGridSizer);

  protected:
    typedef WrapClass<wxGridSizer>::ptr _parentclass_ptr;
    typedef wxGridSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxGridSizer>& GetObj() const { return WrapClass<wxGridSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxGridSizer(boost::shared_ptr<wxGridSizer > si): 
    WrapClass<wxGridSizer>(si)
    , WrapClass_wxSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxGridSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGridSizer_1,"Constructor wxGridSizer::wxGridSizer(wxGridSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#wxgridsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGridSizer,"Constructor wxGridSizer::wxGridSizer() (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#wxgridsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGridSizer_2,"Constructor wxGridSizer::wxGridSizer(int rows, int cols, int vgap, int hgap) (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#wxgridsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxGridSizer_3,"Constructor wxGridSizer::wxGridSizer(int cols, int vgap = 0, int hgap = 0) (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#wxgridsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxGridSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(RecalcSizes,"void wxGridSizer::RecalcSizes()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#recalcsizes)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxGridSizer::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#calcmin)")
    ADD_CLASS_METHOD(SetCols,"void wxGridSizer::SetCols(int cols)  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#setcols)")
    ADD_CLASS_METHOD(SetRows,"void wxGridSizer::SetRows(int rows)  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#setrows)")
    ADD_CLASS_METHOD(SetVGap,"void wxGridSizer::SetVGap(int gap)  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#setvgap)")
    ADD_CLASS_METHOD(SetHGap,"void wxGridSizer::SetHGap(int gap)  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#sethgap)")
    ADD_CLASS_METHOD(GetCols,"int wxGridSizer::GetCols()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#getcols)")
    ADD_CLASS_METHOD(GetRows,"int wxGridSizer::GetRows()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#getrows)")
    ADD_CLASS_METHOD(GetVGap,"int wxGridSizer::GetVGap()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#getvgap)")
    ADD_CLASS_METHOD(GetHGap,"int wxGridSizer::GetHGap()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#gethgap)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxGridSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxGridSizer & wxGridSizer::operator =(wxGridSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxgridsizer.html#__assign__)")




    void AddMethods(WrapClass<wxGridSizer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxGridSizer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxGridSizer_h
