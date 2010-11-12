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
    ADD_CLASS_CONSTRUCTOR(wxPoint1,"Wrapping of wxPoint, http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint,"Wrapping of wxPoint, http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint2,"Wrapping of wxPoint, http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxPoint3,"Wrapping of wxPoint, http://docs.wxwidgets.org/stable/wx_wxpoint.html#wxpoint.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPoint*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#assign")
    ADD_CLASS_METHOD(equal,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#equal")
    ADD_CLASS_METHOD(not_equal,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#not_equal")
    ADD_CLASS_METHOD(add1,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add")
    ADD_CLASS_METHOD(op_substract1,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#op_substract")
    ADD_CLASS_METHOD(add_assign1,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add_assign")
    ADD_CLASS_METHOD(sub_assign1,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#sub_assign")
    ADD_CLASS_METHOD(add_assign,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add_assign")
    ADD_CLASS_METHOD(add_assign2,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add_assign")
    ADD_CLASS_METHOD(sub_assign,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#sub_assign")
    ADD_CLASS_METHOD(sub_assign2,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#sub_assign")
    ADD_CLASS_METHOD(add,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add")
    ADD_CLASS_METHOD(add2,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#add")
    ADD_CLASS_METHOD(op_substract,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#op_substract")
    ADD_CLASS_METHOD(op_substract2,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#op_substract")
    ADD_CLASS_METHOD(op_substract3,"http://docs.wxwidgets.org/stable/wx_wxpoint.html#op_substract")




    void AddMethods(WrapClass<wxPoint>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
      // Adding standard methods 

      // Adding operators
      AddVar_assign( this_ptr);
      AddVar_equal( this_ptr);
      AddVar_not_equal( this_ptr);
      AddVar_add1( this_ptr);
      AddVar_op_substract1( this_ptr);
      AddVar_add_assign1( this_ptr);
      AddVar_sub_assign1( this_ptr);
      AddVar_add_assign( this_ptr);
      AddVar_add_assign2( this_ptr);
      AddVar_sub_assign( this_ptr);
      AddVar_sub_assign2( this_ptr);
      AddVar_add( this_ptr);
      AddVar_add2( this_ptr);
      AddVar_op_substract( this_ptr);
      AddVar_op_substract2( this_ptr);
      AddVar_op_substract3( this_ptr);



      // Add public fields
      AMIObject::ptr tmpobj(amiobject.lock());
      if (!tmpobj.get()) return;
      Variables::ptr context(tmpobj->GetContext());
      
      // Adding public member x
      boost::shared_ptr<int> var_x_ptr(&GetObj()->x, smartpointer_nodeleter<int>());
      BasicVariable::ptr var_x = AMILabType<int>::CreateVarFromSmtPtr(var_x_ptr);
      if (var_x.get()) {
        var_x->Rename("x");
        context->AddVar(var_x,context);
      }
      
      // Adding public member y
      boost::shared_ptr<int> var_y_ptr(&GetObj()->y, smartpointer_nodeleter<int>());
      BasicVariable::ptr var_y = AMILabType<int>::CreateVarFromSmtPtr(var_y_ptr);
      if (var_y.get()) {
        var_y->Rename("y");
        context->AddVar(var_y,context);
      }

    };
};


#endif // _wrap_wxPoint_h
