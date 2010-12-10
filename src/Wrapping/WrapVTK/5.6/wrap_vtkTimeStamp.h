/**
 * C++ Interface: wrap_vtkTimeStamp
 *
 * Description: wrapping vtkTimeStamp
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkTimeStamp_h_
#define _wrap_vtkTimeStamp_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkTimeStamp.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(vtkTimeStamp);

// TODO: check for inheritence ...
class WrapClass_vtkTimeStamp : public WrapClass<vtkTimeStamp>
    
{
  DEFINE_CLASS(WrapClass_vtkTimeStamp);

  protected:
    typedef WrapClass<vtkTimeStamp>::ptr _parentclass_ptr;
    typedef vtkTimeStamp ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkTimeStamp>& GetObj() const { return WrapClass<vtkTimeStamp>::GetObj(); }

    /// Constructor
    WrapClass_vtkTimeStamp(boost::shared_ptr<vtkTimeStamp > si): 
    WrapClass<vtkTimeStamp>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkTimeStamp()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkTimeStamp_1,"Constructor vtkTimeStamp::vtkTimeStamp(vtkTimeStamp const & param0) (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#vtktimestamp).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkTimeStamp,"Constructor vtkTimeStamp::vtkTimeStamp() (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#vtktimestamp).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(vtkTimeStamp_2,"Constructor vtkTimeStamp::vtkTimeStamp() (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#vtktimestamp).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkTimeStamp*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkTimeStamp * vtkTimeStamp::New() (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#new).");



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Delete,"void vtkTimeStamp::Delete()  (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#delete)")
    ADD_CLASS_METHOD(Modified,"void vtkTimeStamp::Modified()  (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#modified)")
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkTimeStamp::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#getmtime)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "vtkTimeStamp & vtkTimeStamp::operator =(vtkTimeStamp const & param0) (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#__assign__)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkTimeStamp::>(vtkTimeStamp & ts) (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#>)")
    // ADD_CLASS_METHOD(operator not available,"bool vtkTimeStamp::<(vtkTimeStamp & ts) (http://docs.wxwidgets.org/stable/wx_vtktimestamp.html#<)")




    void AddMethods(WrapClass<vtkTimeStamp>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkTimeStamp_h
