/**
 * C++ Interface: wrap_wxVisualAttributes
 *
 * Description: wrapping wxVisualAttributes
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxVisualAttributes_h_
#define _wrap_wxVisualAttributes_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxVisualAttributes_declared
  #define wxVisualAttributes_declared
  AMI_DECLARE_TYPE(wxVisualAttributes);
#endif

// TODO: check for inheritence ...
class WrapClass_wxVisualAttributes : public WrapClass<wxVisualAttributes>
    
{
  DEFINE_CLASS(WrapClass_wxVisualAttributes);

  protected:
    typedef WrapClass<wxVisualAttributes>::ptr _parentclass_ptr;
    typedef wxVisualAttributes ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxVisualAttributes>& GetObj() const { return WrapClass<wxVisualAttributes>::GetObj(); }

    /// Constructor
    WrapClass_wxVisualAttributes(boost::shared_ptr<wxVisualAttributes > si): 
    WrapClass<wxVisualAttributes>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxVisualAttributes()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVisualAttributes_1,"Constructor wxVisualAttributes::wxVisualAttributes(wxVisualAttributes const & param0) (http://docs.wxwidgets.org/stable/wx_wxvisualattributes.html#wxvisualattributes).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVisualAttributes,"Constructor wxVisualAttributes::wxVisualAttributes() (http://docs.wxwidgets.org/stable/wx_wxvisualattributes.html#wxvisualattributes).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxVisualAttributes_2,"Constructor wxVisualAttributes::wxVisualAttributes() (http://docs.wxwidgets.org/stable/wx_wxvisualattributes.html#wxvisualattributes).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxVisualAttributes*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxVisualAttributes & wxVisualAttributes::operator =(wxVisualAttributes const & param0) (http://docs.wxwidgets.org/stable/wx_wxvisualattributes.html#__assign__)")




    void AddMethods(WrapClass<wxVisualAttributes>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxVisualAttributes_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxVisualAttributes_h
