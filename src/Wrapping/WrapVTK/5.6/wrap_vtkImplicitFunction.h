/**
 * C++ Interface: wrap_vtkImplicitFunction
 *
 * Description: wrapping vtkImplicitFunction
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkImplicitFunction_h_
#define _wrap_vtkImplicitFunction_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtkImplicitFunction.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkImplicitFunction);

// TODO: check for inheritence ...
class WrapClass_vtkImplicitFunction : public WrapClass<vtkImplicitFunction>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkImplicitFunction);

  protected:
    typedef WrapClass<vtkImplicitFunction>::ptr _parentclass_ptr;
    typedef vtkImplicitFunction ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkImplicitFunction>& GetObj() const { return WrapClass<vtkImplicitFunction>::GetObj(); }

    /// Constructor
    WrapClass_vtkImplicitFunction(boost::shared_ptr<vtkImplicitFunction > si): 
    WrapClass<vtkImplicitFunction>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkImplicitFunction()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkImplicitFunction*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkImplicitFunction::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkImplicitFunction * vtkImplicitFunction::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkImplicitFunction::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkImplicitFunction * vtkImplicitFunction::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkImplicitFunction::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#printself)")
*/
    ADD_CLASS_METHOD(GetMTime,"long unsigned int vtkImplicitFunction::GetMTime()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#getmtime)")
    ADD_CLASS_METHOD(FunctionValue_1,"double vtkImplicitFunction::FunctionValue(double const * x)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functionvalue)")
    ADD_CLASS_METHOD(FunctionValue,"vtkImplicitFunction::FunctionValue()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functionvalue)")
    ADD_CLASS_METHOD(FunctionValue_2,"double vtkImplicitFunction::FunctionValue(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functionvalue)")
    ADD_CLASS_METHOD(FunctionGradient_1,"void vtkImplicitFunction::FunctionGradient(double const * x, double * g)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functiongradient)")
    ADD_CLASS_METHOD(FunctionGradient,"vtkImplicitFunction::FunctionGradient()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functiongradient)")
    ADD_CLASS_METHOD(FunctionGradient_2,"double * vtkImplicitFunction::FunctionGradient(double const * x)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functiongradient)")
    ADD_CLASS_METHOD(FunctionGradient_3,"double * vtkImplicitFunction::FunctionGradient(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#functiongradient)")
    ADD_CLASS_METHOD(SetTransform_1,"void vtkImplicitFunction::SetTransform(vtkAbstractTransform * param0)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#settransform)")
    ADD_CLASS_METHOD(SetTransform,"vtkImplicitFunction::SetTransform()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#settransform)")
    ADD_CLASS_METHOD(SetTransform_2,"void vtkImplicitFunction::SetTransform(double * elements)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#settransform)")
    ADD_CLASS_METHOD(GetTransform,"vtkAbstractTransform * vtkImplicitFunction::GetTransform()  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#gettransform)")
    ADD_CLASS_METHOD(EvaluateFunction,"double vtkImplicitFunction::EvaluateFunction(double x, double y, double z)  (http://docs.wxwidgets.org/stable/wx_vtkimplicitfunction.html#evaluatefunction)")





    void AddMethods(WrapClass<vtkImplicitFunction>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkImplicitFunction_h
