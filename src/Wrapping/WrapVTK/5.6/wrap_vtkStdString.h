/**
 * C++ Interface: wrap_vtkStdString
 *
 * Description: wrapping vtkStdString
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkStdString_h_
#define _wrap_vtkStdString_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

//#include "wrap_basic_string_char_std::char_traits_char__std::allocator_char_ _.h"



AMI_DECLARE_TYPE(vtkStdString);

// TODO: check for inheritence ...
class WrapClass_vtkStdString : public WrapClass<vtkStdString>
    //, public  WrapClass_basic_string_char_std::char_traits_char__std::allocator_char_ _
{
  DEFINE_CLASS(WrapClass_vtkStdString);

  protected:
    typedef WrapClass<vtkStdString>::ptr _parentclass_ptr;
    typedef vtkStdString ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkStdString>& GetObj() const { return WrapClass<vtkStdString>::GetObj(); }

    /// Constructor
    WrapClass_vtkStdString(boost::shared_ptr<vtkStdString > si): 
    WrapClass<vtkStdString>(si)
    //, WrapClass_basic_string_char_std::char_traits_char__std::allocator_char_ _(si)
    {}

    /// Destructor
    ~WrapClass_vtkStdString()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString_1,"Constructor vtkStdString::vtkStdString(vtkStdString const & param0) (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString,"Constructor vtkStdString::vtkStdString() (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString_2,"Constructor vtkStdString::vtkStdString() (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString_3,"Constructor vtkStdString::vtkStdString(char const * s) (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString_4,"Constructor vtkStdString::vtkStdString(char const * s, size_t n) (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    /* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkStdString_5,"Constructor vtkStdString::vtkStdString(string const & s, size_t pos = 0, size_t n = std::basic_string<char, std::char_traits<char>, std::allocator<char> >::npos) (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#vtkstdstring).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkStdString*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkStdString & vtkStdString::operator =(vtkStdString const & param0) (http://docs.wxwidgets.org/stable/wx_vtkstdstring.html#__assign__)")




    void AddMethods(WrapClass<vtkStdString>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkStdString_h
