/**
 * C++ Interface: wrap_vtkUnicodeString
 *
 * Description: wrapping vtkUnicodeString
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkUnicodeString_h_
#define _wrap_vtkUnicodeString_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkUnicodeString.h"

// include what is needed for inheritence and for types ...



#ifndef vtkUnicodeString_declared
  #define vtkUnicodeString_declared
  AMI_DECLARE_TYPE(vtkUnicodeString);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkUnicodeString : public WrapClass<vtkUnicodeString>
    
{
  DEFINE_CLASS(WrapClass_vtkUnicodeString);

  protected:
    typedef WrapClass<vtkUnicodeString>::ptr _parentclass_ptr;
    typedef vtkUnicodeString ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkUnicodeString>& GetObj() const { return WrapClass<vtkUnicodeString>::GetObj(); }

    /// Constructor
    WrapClass_vtkUnicodeString(boost::shared_ptr<vtkUnicodeString > si): 
    WrapClass<vtkUnicodeString>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkUnicodeString()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkUnicodeString_1,"Constructor vtkUnicodeString::vtkUnicodeString() (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#vtkunicodestring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkUnicodeString,"Constructor vtkUnicodeString::vtkUnicodeString() (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#vtkunicodestring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkUnicodeString_2,"Constructor vtkUnicodeString::vtkUnicodeString(vtkUnicodeString const & param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#vtkunicodestring).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkUnicodeString_3,"Constructor vtkUnicodeString::vtkUnicodeString(size_t count, vtkUnicodeStringValueType character) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#vtkunicodestring).");
    /* The following types are missing: const_iterator, const_iterator
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkUnicodeString_4,"Constructor vtkUnicodeString::vtkUnicodeString(const_iterator begin, const_iterator end) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#vtkunicodestring).");
    */



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkUnicodeString*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(is_utf8_1,"bool vtkUnicodeString::is_utf8(char const * param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#is_utf8).");
    ADD_CLASS_STATICMETHOD(is_utf8,"vtkUnicodeString::is_utf8() (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#is_utf8).");
    /* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    ADD_CLASS_STATICMETHOD(is_utf8_2,"bool vtkUnicodeString::is_utf8(string const & param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#is_utf8).");
    */
    ADD_CLASS_STATICMETHOD(from_utf8_1,"vtkUnicodeString vtkUnicodeString::from_utf8(char const * param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#from_utf8).");
    ADD_CLASS_STATICMETHOD(from_utf8,"vtkUnicodeString::from_utf8() (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#from_utf8).");
    ADD_CLASS_STATICMETHOD(from_utf8_2,"vtkUnicodeString vtkUnicodeString::from_utf8(char const * begin, char const * end) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#from_utf8).");
    /* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    ADD_CLASS_STATICMETHOD(from_utf8_3,"vtkUnicodeString vtkUnicodeString::from_utf8(string const & param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#from_utf8).");
    */
    ADD_CLASS_STATICMETHOD(from_utf16,"vtkUnicodeString vtkUnicodeString::from_utf16(vtkTypeUInt16 const * param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#from_utf16).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(begin,"const_iterator vtkUnicodeString::begin()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#begin)")
*/
/* The following types are missing: const_iterator
    ADD_CLASS_METHOD(end,"const_iterator vtkUnicodeString::end()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#end)")
*/
    ADD_CLASS_METHOD(at,"vtkUnicodeStringValueType vtkUnicodeString::at(size_t offset)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#at)")
    ADD_CLASS_METHOD(utf8_str_1,"char const * vtkUnicodeString::utf8_str()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf8_str)")
    ADD_CLASS_METHOD(utf8_str,"vtkUnicodeString::utf8_str()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf8_str)")
/* The following types are missing: basic_string<char,std::char_traits<char>,std::allocator<char> >
    ADD_CLASS_METHOD(utf8_str_2,"void vtkUnicodeString::utf8_str(string & result)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf8_str)")
*/
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >
    ADD_CLASS_METHOD(utf16_str_1,"vector<short unsigned int,std::allocator<short unsigned int> > vtkUnicodeString::utf16_str()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf16_str)")
*/
    ADD_CLASS_METHOD(utf16_str,"vtkUnicodeString::utf16_str()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf16_str)")
/* The following types are missing: vector<short unsigned int,std::allocator<short unsigned int> >
    ADD_CLASS_METHOD(utf16_str_2,"void vtkUnicodeString::utf16_str(vector<short unsigned int,std::allocator<short unsigned int> > & result)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#utf16_str)")
*/
    ADD_CLASS_METHOD(byte_count,"size_t vtkUnicodeString::byte_count()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#byte_count)")
    ADD_CLASS_METHOD(character_count,"size_t vtkUnicodeString::character_count()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#character_count)")
    ADD_CLASS_METHOD(empty,"bool vtkUnicodeString::empty()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#empty)")
    ADD_CLASS_METHOD(push_back,"void vtkUnicodeString::push_back(vtkUnicodeStringValueType param0)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#push_back)")
    ADD_CLASS_METHOD(append_1,"void vtkUnicodeString::append(vtkUnicodeString const & value)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#append)")
    ADD_CLASS_METHOD(append,"vtkUnicodeString::append()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#append)")
    ADD_CLASS_METHOD(append_2,"void vtkUnicodeString::append(size_t count, vtkUnicodeStringValueType character)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#append)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(append_3,"void vtkUnicodeString::append(const_iterator begin, const_iterator end)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#append)")
*/
    ADD_CLASS_METHOD(assign_1,"void vtkUnicodeString::assign(vtkUnicodeString const & value)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#assign)")
    ADD_CLASS_METHOD(assign,"vtkUnicodeString::assign()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#assign)")
    ADD_CLASS_METHOD(assign_2,"void vtkUnicodeString::assign(size_t count, vtkUnicodeStringValueType character)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#assign)")
/* The following types are missing: const_iterator, const_iterator
    ADD_CLASS_METHOD(assign_3,"void vtkUnicodeString::assign(const_iterator begin, const_iterator end)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#assign)")
*/
    ADD_CLASS_METHOD(clear,"void vtkUnicodeString::clear()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#clear)")
    ADD_CLASS_METHOD(fold_case,"vtkUnicodeString vtkUnicodeString::fold_case()  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#fold_case)")
    ADD_CLASS_METHOD(compare,"int vtkUnicodeString::compare(vtkUnicodeString const & param0)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#compare)")
    ADD_CLASS_METHOD(substr,"vtkUnicodeString vtkUnicodeString::substr(size_t offset = 0, size_t count = vtkUnicodeString::npos)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#substr)")
    ADD_CLASS_METHOD(swap,"void vtkUnicodeString::swap(vtkUnicodeString & param0)  (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#swap)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkUnicodeString & vtkUnicodeString::operator =(vtkUnicodeString const & param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#__assign__)")
    ADD_CLASS_METHOD(__at__,            "vtkUnicodeStringValueType vtkUnicodeString::operator [](size_t offset) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#__at__)")
    ADD_CLASS_METHOD(__add_assign___1,            "vtkUnicodeString & vtkUnicodeString::operator +=(vtkUnicodeStringValueType param0) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign__,            "vtkUnicodeString::operator +=() (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#__add_assign__)")
    ADD_CLASS_METHOD(__add_assign___2,            "vtkUnicodeString & vtkUnicodeString::operator +=(vtkUnicodeString const & rhs) (http://docs.wxwidgets.org/stable/wx_vtkunicodestring.html#__add_assign__)")




    void AddMethods(WrapClass<vtkUnicodeString>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkUnicodeString_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkUnicodeString_h
