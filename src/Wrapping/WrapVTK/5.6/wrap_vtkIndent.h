/**
 * C++ Interface: wrap_vtkIndent
 *
 * Description: wrapping vtkIndent
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkIndent_h_
#define _wrap_vtkIndent_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkIndent.h"

// include what is needed for inheritence and for types ...



#ifndef vtkIndent_declared
  #define vtkIndent_declared
  AMI_DECLARE_TYPE(vtkIndent);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkIndent : public WrapClass<vtkIndent>
    
{
  DEFINE_CLASS(WrapClass_vtkIndent);

  protected:
    typedef WrapClass<vtkIndent>::ptr _parentclass_ptr;
    typedef vtkIndent ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkIndent>& GetObj() const { return WrapClass<vtkIndent>::GetObj(); }

    /// Constructor
    WrapClass_vtkIndent(boost::shared_ptr<vtkIndent > si): 
    WrapClass<vtkIndent>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkIndent()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkIndent_1,"Constructor vtkIndent::vtkIndent(vtkIndent const & param0) (http://docs.wxwidgets.org/stable/wx_vtkindent.html#vtkindent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkIndent,"Constructor vtkIndent::vtkIndent() (http://docs.wxwidgets.org/stable/wx_vtkindent.html#vtkindent).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkIndent_2,"Constructor vtkIndent::vtkIndent(int ind = 0) (http://docs.wxwidgets.org/stable/wx_vtkindent.html#vtkindent).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkIndent*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkIndent * vtkIndent::New() (http://docs.wxwidgets.org/stable/wx_vtkindent.html#new).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Delete,"void vtkIndent::Delete()  (http://docs.wxwidgets.org/stable/wx_vtkindent.html#delete)")
    ADD_CLASS_METHOD(GetNextIndent,"vtkIndent vtkIndent::GetNextIndent()  (http://docs.wxwidgets.org/stable/wx_vtkindent.html#getnextindent)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkIndent & vtkIndent::operator =(vtkIndent const & param0) (http://docs.wxwidgets.org/stable/wx_vtkindent.html#__assign__)")




    void AddMethods(WrapClass<vtkIndent>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkIndent_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkIndent_h
