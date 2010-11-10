/**
 * C++ Interface: wrap_wxPoint
 *
 * Description: wrapping wxPoint
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPoint_h_
#define _wrap_wxPoint_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxPoint);

// TODO: check for inheritence ...
class WrapClass_wxPoint : public WrapClass<wxPoint>
    
{
  DEFINE_CLASS(WrapClass_wxPoint);

  protected:
    typedef WrapClass<wxPoint>::ptr _parentclass_ptr;
    typedef wxPoint ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPoint>& GetObj() const { return WrapClass<wxPoint>::GetObj(); }

    /// Constructor
    WrapClass_wxPoint(boost::shared_ptr<wxPoint > si): 
    WrapClass<wxPoint>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxPoint()
    {
      std::cout << "~WrapClass_wxPoint()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint,"Wrapping of wxPoint.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint1,"Wrapping of wxPoint.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint2,"Wrapping of wxPoint.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPoint*);

    // here add each method
    

    // Operators:
    ADD_CLASS_METHOD(assign,"")
    ADD_CLASS_METHOD(equal,"")
    ADD_CLASS_METHOD(not_equal,"")
    ADD_CLASS_METHOD(add,"")
    // ADD_CLASS_METHOD(operator not available,"")
    ADD_CLASS_METHOD(add_assign,"")
    ADD_CLASS_METHOD(sub_assign,"")
    ADD_CLASS_METHOD(add_assign1,"")
    ADD_CLASS_METHOD(sub_assign1,"")
    ADD_CLASS_METHOD(add1,"")
    // ADD_CLASS_METHOD(operator not available,"")
    // ADD_CLASS_METHOD(operator not available,"")




    void AddMethods(WrapClass<wxPoint>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      

      // Operators:
      AddVar_assign( this_ptr);
      AddVar_equal( this_ptr);
      AddVar_not_equal( this_ptr);
      AddVar_add( this_ptr);
      // AddVar_operator not available( this_ptr);
      AddVar_add_assign( this_ptr);
      AddVar_sub_assign( this_ptr);
      AddVar_add_assign1( this_ptr);
      AddVar_sub_assign1( this_ptr);
      AddVar_add1( this_ptr);
      // AddVar_operator not available( this_ptr);
      // AddVar_operator not available( this_ptr);


    };
};


#endif // _wrap_wxPoint_h
