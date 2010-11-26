/**
 * C++ Interface: wrap_wxSize
 *
 * Description: wrapping wxSize
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSize_h_
#define _wrap_wxSize_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxSize);

// TODO: check for inheritence ...
class WrapClass_wxSize : public WrapClass<wxSize>
    
{
  DEFINE_CLASS(WrapClass_wxSize);

  protected:
    typedef WrapClass<wxSize>::ptr _parentclass_ptr;
    typedef wxSize ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSize>& GetObj() const { return WrapClass<wxSize>::GetObj(); }

    /// Constructor
    WrapClass_wxSize(boost::shared_ptr<wxSize > si): 
    WrapClass<wxSize>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxSize()
    {
      std::cout << "~WrapClass_wxSize()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize1,"Wrapping of wxSize, http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize,"Wrapping of wxSize, http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize2,"Wrapping of wxSize, http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSize3,"Wrapping of wxSize, http://docs.wxwidgets.org/stable/wx_wxsize.html#wxsize.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSize*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(IncTo,"http://docs.wxwidgets.org/stable/wx_wxsize.html#incto")
    ADD_CLASS_METHOD(DecTo,"http://docs.wxwidgets.org/stable/wx_wxsize.html#decto")
    ADD_CLASS_METHOD(IncBy1,"http://docs.wxwidgets.org/stable/wx_wxsize.html#incby")
    ADD_CLASS_METHOD(IncBy,"http://docs.wxwidgets.org/stable/wx_wxsize.html#incby")
    ADD_CLASS_METHOD(IncBy2,"http://docs.wxwidgets.org/stable/wx_wxsize.html#incby")
    ADD_CLASS_METHOD(IncBy3,"http://docs.wxwidgets.org/stable/wx_wxsize.html#incby")
    ADD_CLASS_METHOD(DecBy1,"http://docs.wxwidgets.org/stable/wx_wxsize.html#decby")
    ADD_CLASS_METHOD(DecBy,"http://docs.wxwidgets.org/stable/wx_wxsize.html#decby")
    ADD_CLASS_METHOD(DecBy2,"http://docs.wxwidgets.org/stable/wx_wxsize.html#decby")
    ADD_CLASS_METHOD(DecBy3,"http://docs.wxwidgets.org/stable/wx_wxsize.html#decby")
    ADD_CLASS_METHOD(Scale,"http://docs.wxwidgets.org/stable/wx_wxsize.html#scale")
    ADD_CLASS_METHOD(Set,"http://docs.wxwidgets.org/stable/wx_wxsize.html#set")
    ADD_CLASS_METHOD(SetWidth,"http://docs.wxwidgets.org/stable/wx_wxsize.html#setwidth")
    ADD_CLASS_METHOD(SetHeight,"http://docs.wxwidgets.org/stable/wx_wxsize.html#setheight")
    ADD_CLASS_METHOD(GetWidth,"http://docs.wxwidgets.org/stable/wx_wxsize.html#getwidth")
    ADD_CLASS_METHOD(GetHeight,"http://docs.wxwidgets.org/stable/wx_wxsize.html#getheight")
    ADD_CLASS_METHOD(IsFullySpecified,"http://docs.wxwidgets.org/stable/wx_wxsize.html#isfullyspecified")
    ADD_CLASS_METHOD(SetDefaults,"http://docs.wxwidgets.org/stable/wx_wxsize.html#setdefaults")
    ADD_CLASS_METHOD(GetX,"http://docs.wxwidgets.org/stable/wx_wxsize.html#getx")
    ADD_CLASS_METHOD(GetY,"http://docs.wxwidgets.org/stable/wx_wxsize.html#gety")

    // Operators:
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxsize.html#assign")
    ADD_CLASS_METHOD(equal,"http://docs.wxwidgets.org/stable/wx_wxsize.html#equal")
    ADD_CLASS_METHOD(not_equal,"http://docs.wxwidgets.org/stable/wx_wxsize.html#not_equal")
    ADD_CLASS_METHOD(add,"http://docs.wxwidgets.org/stable/wx_wxsize.html#add")
    ADD_CLASS_METHOD(op_substract,"http://docs.wxwidgets.org/stable/wx_wxsize.html#op_substract")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxsize.html#/")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxsize.html#*")
    ADD_CLASS_METHOD(add_assign,"http://docs.wxwidgets.org/stable/wx_wxsize.html#add_assign")
    ADD_CLASS_METHOD(sub_assign,"http://docs.wxwidgets.org/stable/wx_wxsize.html#sub_assign")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxsize.html#/=")
    // ADD_CLASS_METHOD(operator not available,"http://docs.wxwidgets.org/stable/wx_wxsize.html#*=")




    void AddMethods(WrapClass<wxSize>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
       // Adding standard methods 
      AddVar_IncTo( this_ptr);
      AddVar_DecTo( this_ptr);
      AddVar_IncBy1( this_ptr);
      AddVar_IncBy( this_ptr);
      AddVar_IncBy2( this_ptr);
      AddVar_IncBy3( this_ptr);
      AddVar_DecBy1( this_ptr);
      AddVar_DecBy( this_ptr);
      AddVar_DecBy2( this_ptr);
      AddVar_DecBy3( this_ptr);
      AddVar_Scale( this_ptr);
      AddVar_Set( this_ptr);
      AddVar_SetWidth( this_ptr);
      AddVar_SetHeight( this_ptr);
      AddVar_GetWidth( this_ptr);
      AddVar_GetHeight( this_ptr);
      AddVar_IsFullySpecified( this_ptr);
      AddVar_SetDefaults( this_ptr);
      AddVar_GetX( this_ptr);
      AddVar_GetY( this_ptr);

      // Adding operators
      AddVar_assign( this_ptr);
      AddVar_equal( this_ptr);
      AddVar_not_equal( this_ptr);
      AddVar_add( this_ptr);
      AddVar_op_substract( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar_add_assign( this_ptr);
      AddVar_sub_assign( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);


    };
};


#endif // _wrap_wxSize_h
