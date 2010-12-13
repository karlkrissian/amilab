/**
 * C++ Interface: wrap_vtkInteractorStyleImage
 *
 * Description: wrapping vtkInteractorStyleImage
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorStyleImage_h_
#define _wrap_vtkInteractorStyleImage_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkInteractorStyleImage.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorStyleTrackballCamera.h"


#ifndef vtkInteractorStyleImage_declared
  #define vtkInteractorStyleImage_declared
  AMI_DECLARE_TYPE(vtkInteractorStyleImage);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkInteractorStyleImage : public WrapClass<vtkInteractorStyleImage>
    , public   WrapClass_vtkInteractorStyleTrackballCamera
{
  DEFINE_CLASS(WrapClass_vtkInteractorStyleImage);

  protected:
    typedef WrapClass<vtkInteractorStyleImage>::ptr _parentclass_ptr;
    typedef vtkInteractorStyleImage ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorStyleImage>& GetObj() const { return WrapClass<vtkInteractorStyleImage>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorStyleImage(boost::shared_ptr<vtkInteractorStyleImage > si): 
    WrapClass<vtkInteractorStyleImage>(si)
    , WrapClass_vtkInteractorStyleTrackballCamera(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorStyleImage()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorStyleImage*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInteractorStyleImage * vtkInteractorStyleImage::New() (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorStyleImage::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorStyleImage * vtkInteractorStyleImage::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorStyleImage::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorStyleImage * vtkInteractorStyleImage::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorStyleImage::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#printself)")
*/
    ADD_CLASS_METHOD(GetWindowLevelStartPosition_1,"int * vtkInteractorStyleImage::GetWindowLevelStartPosition()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelstartposition)")
    ADD_CLASS_METHOD(GetWindowLevelStartPosition,"vtkInteractorStyleImage::GetWindowLevelStartPosition()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelstartposition)")
    ADD_CLASS_METHOD(GetWindowLevelStartPosition_2,"void vtkInteractorStyleImage::GetWindowLevelStartPosition(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelstartposition)")
    ADD_CLASS_METHOD(GetWindowLevelStartPosition_3,"void vtkInteractorStyleImage::GetWindowLevelStartPosition(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelstartposition)")
    ADD_CLASS_METHOD(GetWindowLevelCurrentPosition_1,"int * vtkInteractorStyleImage::GetWindowLevelCurrentPosition()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelcurrentposition)")
    ADD_CLASS_METHOD(GetWindowLevelCurrentPosition,"vtkInteractorStyleImage::GetWindowLevelCurrentPosition()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelcurrentposition)")
    ADD_CLASS_METHOD(GetWindowLevelCurrentPosition_2,"void vtkInteractorStyleImage::GetWindowLevelCurrentPosition(int & _arg1, int & _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelcurrentposition)")
    ADD_CLASS_METHOD(GetWindowLevelCurrentPosition_3,"void vtkInteractorStyleImage::GetWindowLevelCurrentPosition(int * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#getwindowlevelcurrentposition)")
    ADD_CLASS_METHOD(OnMouseMove,"void vtkInteractorStyleImage::OnMouseMove()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onmousemove)")
    ADD_CLASS_METHOD(OnLeftButtonDown,"void vtkInteractorStyleImage::OnLeftButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onleftbuttondown)")
    ADD_CLASS_METHOD(OnLeftButtonUp,"void vtkInteractorStyleImage::OnLeftButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onleftbuttonup)")
    ADD_CLASS_METHOD(OnRightButtonDown,"void vtkInteractorStyleImage::OnRightButtonDown()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onrightbuttondown)")
    ADD_CLASS_METHOD(OnRightButtonUp,"void vtkInteractorStyleImage::OnRightButtonUp()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onrightbuttonup)")
    ADD_CLASS_METHOD(OnChar,"void vtkInteractorStyleImage::OnChar()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#onchar)")
    ADD_CLASS_METHOD(WindowLevel,"void vtkInteractorStyleImage::WindowLevel()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#windowlevel)")
    ADD_CLASS_METHOD(Pick,"void vtkInteractorStyleImage::Pick()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#pick)")
    ADD_CLASS_METHOD(StartWindowLevel,"void vtkInteractorStyleImage::StartWindowLevel()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#startwindowlevel)")
    ADD_CLASS_METHOD(EndWindowLevel,"void vtkInteractorStyleImage::EndWindowLevel()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#endwindowlevel)")
    ADD_CLASS_METHOD(StartPick,"void vtkInteractorStyleImage::StartPick()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#startpick)")
    ADD_CLASS_METHOD(EndPick,"void vtkInteractorStyleImage::EndPick()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyleimage.html#endpick)")





    void AddMethods(WrapClass<vtkInteractorStyleImage>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkInteractorStyleImage_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkInteractorStyleImage_h
