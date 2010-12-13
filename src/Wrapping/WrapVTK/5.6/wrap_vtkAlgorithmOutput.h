/**
 * C++ Interface: wrap_vtkAlgorithmOutput
 *
 * Description: wrapping vtkAlgorithmOutput
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkAlgorithmOutput_h_
#define _wrap_vtkAlgorithmOutput_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkAlgorithmOutput.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkAlgorithmOutput_declared
  #define vtkAlgorithmOutput_declared
  AMI_DECLARE_TYPE(vtkAlgorithmOutput);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkAlgorithmOutput : public WrapClass<vtkAlgorithmOutput>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkAlgorithmOutput);

  protected:
    typedef WrapClass<vtkAlgorithmOutput>::ptr _parentclass_ptr;
    typedef vtkAlgorithmOutput ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkAlgorithmOutput>& GetObj() const { return WrapClass<vtkAlgorithmOutput>::GetObj(); }

    /// Constructor
    WrapClass_vtkAlgorithmOutput(boost::shared_ptr<vtkAlgorithmOutput > si): 
    WrapClass<vtkAlgorithmOutput>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkAlgorithmOutput()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkAlgorithmOutput*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkAlgorithmOutput * vtkAlgorithmOutput::New() (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkAlgorithmOutput::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkAlgorithmOutput * vtkAlgorithmOutput::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkAlgorithmOutput::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkAlgorithmOutput * vtkAlgorithmOutput::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkAlgorithmOutput::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#printself)")
*/
    ADD_CLASS_METHOD(SetIndex,"void vtkAlgorithmOutput::SetIndex(int index)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#setindex)")
    ADD_CLASS_METHOD(GetIndex,"int vtkAlgorithmOutput::GetIndex()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#getindex)")
    ADD_CLASS_METHOD(GetProducer,"vtkAlgorithm * vtkAlgorithmOutput::GetProducer()  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#getproducer)")
    ADD_CLASS_METHOD(SetProducer,"void vtkAlgorithmOutput::SetProducer(vtkAlgorithm * producer)  (http://docs.wxwidgets.org/stable/wx_vtkalgorithmoutput.html#setproducer)")





    void AddMethods(WrapClass<vtkAlgorithmOutput>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkAlgorithmOutput_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkAlgorithmOutput_h
