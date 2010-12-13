/**
 * C++ Interface: wrap_vtkPolyDataAlgorithm
 *
 * Description: wrapping vtkPolyDataAlgorithm
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPolyDataAlgorithm_h_
#define _wrap_vtkPolyDataAlgorithm_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkPolyDataAlgorithm.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAlgorithm.h"


#ifndef vtkPolyDataAlgorithm_declared
  #define vtkPolyDataAlgorithm_declared
  AMI_DECLARE_TYPE(vtkPolyDataAlgorithm);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkPolyDataAlgorithm : public WrapClass<vtkPolyDataAlgorithm>
    , public   WrapClass_vtkAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkPolyDataAlgorithm);

  protected:
    typedef WrapClass<vtkPolyDataAlgorithm>::ptr _parentclass_ptr;
    typedef vtkPolyDataAlgorithm ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPolyDataAlgorithm>& GetObj() const { return WrapClass<vtkPolyDataAlgorithm>::GetObj(); }

    /// Constructor
    WrapClass_vtkPolyDataAlgorithm(boost::shared_ptr<vtkPolyDataAlgorithm > si): 
    WrapClass<vtkPolyDataAlgorithm>(si)
    , WrapClass_vtkAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkPolyDataAlgorithm()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPolyDataAlgorithm*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPolyDataAlgorithm * vtkPolyDataAlgorithm::New() (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPolyDataAlgorithm::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPolyDataAlgorithm * vtkPolyDataAlgorithm::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPolyDataAlgorithm::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPolyDataAlgorithm * vtkPolyDataAlgorithm::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPolyDataAlgorithm::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#printself)")
*/
    ADD_CLASS_METHOD(GetOutput_1,"vtkPolyData * vtkPolyDataAlgorithm::GetOutput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getoutput)")
    ADD_CLASS_METHOD(GetOutput,"vtkPolyDataAlgorithm::GetOutput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getoutput)")
    ADD_CLASS_METHOD(GetOutput_2,"vtkPolyData * vtkPolyDataAlgorithm::GetOutput(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getoutput)")
    ADD_CLASS_METHOD(SetOutput,"void vtkPolyDataAlgorithm::SetOutput(vtkDataObject * d)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#setoutput)")
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
    ADD_CLASS_METHOD(ProcessRequest,"int vtkPolyDataAlgorithm::ProcessRequest(vtkInformation * param0, vtkInformationVector * * param1, vtkInformationVector * param2)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#processrequest)")
*/
    ADD_CLASS_METHOD(GetInput_1,"vtkDataObject * vtkPolyDataAlgorithm::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetInput,"vtkPolyDataAlgorithm::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetInput_2,"vtkDataObject * vtkPolyDataAlgorithm::GetInput(int port)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetPolyDataInput,"vtkPolyData * vtkPolyDataAlgorithm::GetPolyDataInput(int port)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#getpolydatainput)")
    ADD_CLASS_METHOD(SetInput_1,"void vtkPolyDataAlgorithm::SetInput(vtkDataObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#setinput)")
    ADD_CLASS_METHOD(SetInput,"vtkPolyDataAlgorithm::SetInput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#setinput)")
    ADD_CLASS_METHOD(SetInput_2,"void vtkPolyDataAlgorithm::SetInput(int param0, vtkDataObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#setinput)")
    ADD_CLASS_METHOD(AddInput_1,"void vtkPolyDataAlgorithm::AddInput(vtkDataObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#addinput)")
    ADD_CLASS_METHOD(AddInput,"vtkPolyDataAlgorithm::AddInput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#addinput)")
    ADD_CLASS_METHOD(AddInput_2,"void vtkPolyDataAlgorithm::AddInput(int param0, vtkDataObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkpolydataalgorithm.html#addinput)")





    void AddMethods(WrapClass<vtkPolyDataAlgorithm>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyDataAlgorithm_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkPolyDataAlgorithm_h
