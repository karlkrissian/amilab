/**
 * C++ Interface: wrap_vtkImageAlgorithm
 *
 * Description: wrapping vtkImageAlgorithm
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkImageAlgorithm_h_
#define _wrap_vtkImageAlgorithm_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkImageAlgorithm.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkAlgorithm.h"


#ifndef vtkImageAlgorithm_declared
  #define vtkImageAlgorithm_declared
  AMI_DECLARE_TYPE(vtkImageAlgorithm);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkImageAlgorithm : public WrapClass<vtkImageAlgorithm>
    , public   WrapClass_vtkAlgorithm
{
  DEFINE_CLASS(WrapClass_vtkImageAlgorithm);

  protected:
    typedef WrapClass<vtkImageAlgorithm>::ptr _parentclass_ptr;
    typedef vtkImageAlgorithm ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkImageAlgorithm>& GetObj() const { return WrapClass<vtkImageAlgorithm>::GetObj(); }

    /// Constructor
    WrapClass_vtkImageAlgorithm(boost::shared_ptr<vtkImageAlgorithm > si): 
    WrapClass<vtkImageAlgorithm>(si)
    , WrapClass_vtkAlgorithm(si)
    {}

    /// Destructor
    ~WrapClass_vtkImageAlgorithm()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkImageAlgorithm*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkImageAlgorithm::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkImageAlgorithm * vtkImageAlgorithm::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkImageAlgorithm::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkImageAlgorithm * vtkImageAlgorithm::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkImageAlgorithm::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#printself)")
*/
    ADD_CLASS_METHOD(GetOutput_1,"vtkImageData * vtkImageAlgorithm::GetOutput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getoutput)")
    ADD_CLASS_METHOD(GetOutput,"vtkImageAlgorithm::GetOutput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getoutput)")
    ADD_CLASS_METHOD(GetOutput_2,"vtkImageData * vtkImageAlgorithm::GetOutput(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getoutput)")
    ADD_CLASS_METHOD(SetOutput,"void vtkImageAlgorithm::SetOutput(vtkDataObject * d)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#setoutput)")
/* The following types are missing: vtkInformation, vtkInformationVector, vtkInformationVector
    ADD_CLASS_METHOD(ProcessRequest,"int vtkImageAlgorithm::ProcessRequest(vtkInformation * param0, vtkInformationVector * * param1, vtkInformationVector * param2)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#processrequest)")
*/
    ADD_CLASS_METHOD(SetInput_1,"void vtkImageAlgorithm::SetInput(vtkDataObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#setinput)")
    ADD_CLASS_METHOD(SetInput,"vtkImageAlgorithm::SetInput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#setinput)")
    ADD_CLASS_METHOD(SetInput_2,"void vtkImageAlgorithm::SetInput(int param0, vtkDataObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#setinput)")
    ADD_CLASS_METHOD(GetInput_1,"vtkDataObject * vtkImageAlgorithm::GetInput(int port)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetInput,"vtkImageAlgorithm::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetInput_2,"vtkDataObject * vtkImageAlgorithm::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getinput)")
    ADD_CLASS_METHOD(GetImageDataInput,"vtkImageData * vtkImageAlgorithm::GetImageDataInput(int port)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#getimagedatainput)")
    ADD_CLASS_METHOD(AddInput_1,"void vtkImageAlgorithm::AddInput(vtkDataObject * param0)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#addinput)")
    ADD_CLASS_METHOD(AddInput,"vtkImageAlgorithm::AddInput()  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#addinput)")
    ADD_CLASS_METHOD(AddInput_2,"void vtkImageAlgorithm::AddInput(int param0, vtkDataObject * param1)  (http://docs.wxwidgets.org/stable/wx_vtkimagealgorithm.html#addinput)")





    void AddMethods(WrapClass<vtkImageAlgorithm>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkImageAlgorithm_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkImageAlgorithm_h
