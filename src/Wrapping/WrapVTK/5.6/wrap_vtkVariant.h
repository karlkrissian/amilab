/**
 * C++ Interface: wrap_vtkVariant
 *
 * Description: wrapping vtkVariant
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkVariant_h_
#define _wrap_vtkVariant_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkVariant.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(vtkVariant);

// TODO: check for inheritence ...
class WrapClass_vtkVariant : public WrapClass<vtkVariant>
    
{
  DEFINE_CLASS(WrapClass_vtkVariant);

  protected:
    typedef WrapClass<vtkVariant>::ptr _parentclass_ptr;
    typedef vtkVariant ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkVariant>& GetObj() const { return WrapClass<vtkVariant>::GetObj(); }

    /// Constructor
    WrapClass_vtkVariant(boost::shared_ptr<vtkVariant > si): 
    WrapClass<vtkVariant>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkVariant()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_1,"Constructor vtkVariant::vtkVariant() (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant,"Constructor vtkVariant::vtkVariant() (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_2,"Constructor vtkVariant::vtkVariant(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_3,"Constructor vtkVariant::vtkVariant(bool value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_4,"Constructor vtkVariant::vtkVariant(char value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_5,"Constructor vtkVariant::vtkVariant(unsigned char value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /* The following types are missing: signed char
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_6,"Constructor vtkVariant::vtkVariant(signed char value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    */
    /* The following types are missing: short int
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_7,"Constructor vtkVariant::vtkVariant(short int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_8,"Constructor vtkVariant::vtkVariant(short unsigned int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_9,"Constructor vtkVariant::vtkVariant(int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_10,"Constructor vtkVariant::vtkVariant(unsigned int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_11,"Constructor vtkVariant::vtkVariant(long int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_12,"Constructor vtkVariant::vtkVariant(long unsigned int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_13,"Constructor vtkVariant::vtkVariant(long long int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /* The following types are missing: long long unsigned int
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_14,"Constructor vtkVariant::vtkVariant(long long unsigned int value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    */
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_15,"Constructor vtkVariant::vtkVariant(float value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_16,"Constructor vtkVariant::vtkVariant(double value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_17,"Constructor vtkVariant::vtkVariant(char const * value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_18,"Constructor vtkVariant::vtkVariant(vtkStdString value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_19,"Constructor vtkVariant::vtkVariant(vtkUnicodeString const & value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkVariant_20,"Constructor vtkVariant::vtkVariant(vtkObjectBase * value) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#vtkvariant).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkVariant*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IsValid,"bool vtkVariant::IsValid()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isvalid)")
    ADD_CLASS_METHOD(IsString,"bool vtkVariant::IsString()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isstring)")
    ADD_CLASS_METHOD(IsUnicodeString,"bool vtkVariant::IsUnicodeString()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunicodestring)")
    ADD_CLASS_METHOD(IsNumeric,"bool vtkVariant::IsNumeric()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isnumeric)")
    ADD_CLASS_METHOD(IsFloat,"bool vtkVariant::IsFloat()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isfloat)")
    ADD_CLASS_METHOD(IsDouble,"bool vtkVariant::IsDouble()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isdouble)")
    ADD_CLASS_METHOD(IsChar,"bool vtkVariant::IsChar()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#ischar)")
    ADD_CLASS_METHOD(IsUnsignedChar,"bool vtkVariant::IsUnsignedChar()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsignedchar)")
    ADD_CLASS_METHOD(IsSignedChar,"bool vtkVariant::IsSignedChar()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#issignedchar)")
    ADD_CLASS_METHOD(IsShort,"bool vtkVariant::IsShort()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isshort)")
    ADD_CLASS_METHOD(IsUnsignedShort,"bool vtkVariant::IsUnsignedShort()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsignedshort)")
    ADD_CLASS_METHOD(IsInt,"bool vtkVariant::IsInt()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isint)")
    ADD_CLASS_METHOD(IsUnsignedInt,"bool vtkVariant::IsUnsignedInt()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsignedint)")
    ADD_CLASS_METHOD(IsLong,"bool vtkVariant::IsLong()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#islong)")
    ADD_CLASS_METHOD(IsUnsignedLong,"bool vtkVariant::IsUnsignedLong()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsignedlong)")
    ADD_CLASS_METHOD(Is__Int64,"bool vtkVariant::Is__Int64()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#is__int64)")
    ADD_CLASS_METHOD(IsUnsigned__Int64,"bool vtkVariant::IsUnsigned__Int64()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsigned__int64)")
    ADD_CLASS_METHOD(IsLongLong,"bool vtkVariant::IsLongLong()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#islonglong)")
    ADD_CLASS_METHOD(IsUnsignedLongLong,"bool vtkVariant::IsUnsignedLongLong()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isunsignedlonglong)")
    ADD_CLASS_METHOD(IsVTKObject,"bool vtkVariant::IsVTKObject()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isvtkobject)")
    ADD_CLASS_METHOD(IsArray,"bool vtkVariant::IsArray()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isarray)")
    ADD_CLASS_METHOD(GetType,"unsigned int vtkVariant::GetType()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#gettype)")
    ADD_CLASS_METHOD(GetTypeAsString,"char const * vtkVariant::GetTypeAsString()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#gettypeasstring)")
    ADD_CLASS_METHOD(ToString,"vtkStdString vtkVariant::ToString()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tostring)")
    ADD_CLASS_METHOD(ToUnicodeString,"vtkUnicodeString vtkVariant::ToUnicodeString()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounicodestring)")
    ADD_CLASS_METHOD(ToFloat,"float vtkVariant::ToFloat(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tofloat)")
    ADD_CLASS_METHOD(ToDouble,"double vtkVariant::ToDouble(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#todouble)")
    ADD_CLASS_METHOD(ToChar,"char vtkVariant::ToChar(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tochar)")
    ADD_CLASS_METHOD(ToUnsignedChar,"unsigned char vtkVariant::ToUnsignedChar(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounsignedchar)")
/* The following types are missing: signed char
    ADD_CLASS_METHOD(ToSignedChar,"signed char vtkVariant::ToSignedChar(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tosignedchar)")
*/
/* The following types are missing: short int
    ADD_CLASS_METHOD(ToShort,"short int vtkVariant::ToShort(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#toshort)")
*/
    ADD_CLASS_METHOD(ToUnsignedShort,"short unsigned int vtkVariant::ToUnsignedShort(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounsignedshort)")
    ADD_CLASS_METHOD(ToInt,"int vtkVariant::ToInt(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#toint)")
    ADD_CLASS_METHOD(ToUnsignedInt,"unsigned int vtkVariant::ToUnsignedInt(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounsignedint)")
    ADD_CLASS_METHOD(ToLong,"long int vtkVariant::ToLong(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tolong)")
    ADD_CLASS_METHOD(ToUnsignedLong,"long unsigned int vtkVariant::ToUnsignedLong(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounsignedlong)")
    ADD_CLASS_METHOD(ToLongLong,"long long int vtkVariant::ToLongLong(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tolonglong)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(ToUnsignedLongLong,"long long unsigned int vtkVariant::ToUnsignedLongLong(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tounsignedlonglong)")
*/
    ADD_CLASS_METHOD(ToTypeInt64,"vtkTypeInt64 vtkVariant::ToTypeInt64(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#totypeint64)")
/* The following types are missing: long long unsigned int
    ADD_CLASS_METHOD(ToTypeUInt64,"vtkTypeUInt64 vtkVariant::ToTypeUInt64(bool * valid = 0)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#totypeuint64)")
*/
    ADD_CLASS_METHOD(ToVTKObject,"vtkObjectBase * vtkVariant::ToVTKObject()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#tovtkobject)")
    ADD_CLASS_METHOD(ToArray,"vtkAbstractArray * vtkVariant::ToArray()  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#toarray)")
    ADD_CLASS_METHOD(IsEqual,"bool vtkVariant::IsEqual(vtkVariant const & other)  (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#isequal)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkVariant const & vtkVariant::operator =(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#__assign__)")
    ADD_CLASS_METHOD(__equal__,            "bool vtkVariant::operator ==(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "bool vtkVariant::operator !=(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#__not_equal__)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkVariant::<(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#<)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkVariant::>(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkVariant::<=(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#<=)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkVariant::>=(vtkVariant const & other) (http://docs.wxwidgets.org/stable/wx_vtkvariant.html#>=)")




    void AddMethods(WrapClass<vtkVariant>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkVariant_h
