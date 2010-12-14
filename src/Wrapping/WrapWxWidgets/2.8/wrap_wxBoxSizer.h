/**
 * C++ Interface: wrap_wxBoxSizer
 *
 * Description: wrapping wxBoxSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBoxSizer_h_
#define _wrap_wxBoxSizer_h_

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


#ifndef wxBoxSizer_declared
  #define wxBoxSizer_declared
  AMI_DECLARE_TYPE(wxBoxSizer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxBoxSizer : public WrapClass<wxBoxSizer>
    , public   WrapClass_wxSizer
{
  DEFINE_CLASS(WrapClass_wxBoxSizer);

  protected:
    typedef WrapClass<wxBoxSizer>::ptr _parentclass_ptr;
    typedef wxBoxSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBoxSizer>& GetObj() const { return WrapClass<wxBoxSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxBoxSizer(boost::shared_ptr<wxBoxSizer > si): 
    WrapClass<wxBoxSizer>(si)
    , WrapClass_wxSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxBoxSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer_1,"Constructor wxBoxSizer::wxBoxSizer(wxBoxSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer,"Constructor wxBoxSizer::wxBoxSizer() (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxBoxSizer_2,"Constructor wxBoxSizer::wxBoxSizer(int orient) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#wxboxsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBoxSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(RecalcSizes,"void wxBoxSizer::RecalcSizes()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#recalcsizes)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxBoxSizer::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#calcmin)")
    ADD_CLASS_METHOD(GetOrientation,"int wxBoxSizer::GetOrientation()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#getorientation)")
    ADD_CLASS_METHOD(SetOrientation,"void wxBoxSizer::SetOrientation(int orient)  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#setorientation)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxBoxSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBoxSizer & wxBoxSizer::operator =(wxBoxSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxboxsizer.html#__assign__)")




    void AddMethods(WrapClass<wxBoxSizer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBoxSizer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxBoxSizer_h
