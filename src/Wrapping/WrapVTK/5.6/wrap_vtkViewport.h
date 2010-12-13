/**
 * C++ Interface: wrap_vtkViewport
 *
 * Description: wrapping vtkViewport
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkViewport_h_
#define _wrap_vtkViewport_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkViewport.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"


#ifndef vtkViewport_declared
  #define vtkViewport_declared
  AMI_DECLARE_TYPE(vtkViewport);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkViewport : public WrapClass<vtkViewport>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkViewport);

  protected:
    typedef WrapClass<vtkViewport>::ptr _parentclass_ptr;
    typedef vtkViewport ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkViewport>& GetObj() const { return WrapClass<vtkViewport>::GetObj(); }

    /// Constructor
    WrapClass_vtkViewport(boost::shared_ptr<vtkViewport > si): 
    WrapClass<vtkViewport>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkViewport()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkViewport*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkViewport::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkViewport * vtkViewport::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkViewport::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkViewport * vtkViewport::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkViewport::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#printself)")
*/
    ADD_CLASS_METHOD(AddViewProp,"void vtkViewport::AddViewProp(vtkProp * param0)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#addviewprop)")
    ADD_CLASS_METHOD(GetViewProps,"vtkPropCollection * vtkViewport::GetViewProps()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewprops)")
    ADD_CLASS_METHOD(HasViewProp,"int vtkViewport::HasViewProp(vtkProp * param0)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#hasviewprop)")
    ADD_CLASS_METHOD(RemoveViewProp,"void vtkViewport::RemoveViewProp(vtkProp * param0)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#removeviewprop)")
    ADD_CLASS_METHOD(RemoveAllViewProps,"void vtkViewport::RemoveAllViewProps()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#removeallviewprops)")
    ADD_CLASS_METHOD(AddActor2D,"void vtkViewport::AddActor2D(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#addactor2d)")
    ADD_CLASS_METHOD(RemoveActor2D,"void vtkViewport::RemoveActor2D(vtkProp * p)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#removeactor2d)")
/* The following types are missing: vtkActor2DCollection
    ADD_CLASS_METHOD(GetActors2D,"vtkActor2DCollection * vtkViewport::GetActors2D()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getactors2d)")
*/
    ADD_CLASS_METHOD(SetBackground_1,"void vtkViewport::SetBackground(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground)")
    ADD_CLASS_METHOD(SetBackground,"vtkViewport::SetBackground()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground)")
    ADD_CLASS_METHOD(SetBackground_2,"void vtkViewport::SetBackground(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground)")
    ADD_CLASS_METHOD(GetBackground_1,"double * vtkViewport::GetBackground()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground)")
    ADD_CLASS_METHOD(GetBackground,"vtkViewport::GetBackground()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground)")
    ADD_CLASS_METHOD(GetBackground_2,"void vtkViewport::GetBackground(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground)")
    ADD_CLASS_METHOD(GetBackground_3,"void vtkViewport::GetBackground(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground)")
    ADD_CLASS_METHOD(SetBackground2_1,"void vtkViewport::SetBackground2(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground2)")
    ADD_CLASS_METHOD(SetBackground2,"vtkViewport::SetBackground2()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground2)")
    ADD_CLASS_METHOD(SetBackground2_2,"void vtkViewport::SetBackground2(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setbackground2)")
    ADD_CLASS_METHOD(GetBackground2_1,"double * vtkViewport::GetBackground2()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground2)")
    ADD_CLASS_METHOD(GetBackground2,"vtkViewport::GetBackground2()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground2)")
    ADD_CLASS_METHOD(GetBackground2_2,"void vtkViewport::GetBackground2(double & _arg1, double & _arg2, double & _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground2)")
    ADD_CLASS_METHOD(GetBackground2_3,"void vtkViewport::GetBackground2(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getbackground2)")
    ADD_CLASS_METHOD(SetGradientBackground,"void vtkViewport::SetGradientBackground(bool _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setgradientbackground)")
    ADD_CLASS_METHOD(GetGradientBackground,"bool vtkViewport::GetGradientBackground()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getgradientbackground)")
    ADD_CLASS_METHOD(GradientBackgroundOn,"void vtkViewport::GradientBackgroundOn()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#gradientbackgroundon)")
    ADD_CLASS_METHOD(GradientBackgroundOff,"void vtkViewport::GradientBackgroundOff()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#gradientbackgroundoff)")
    ADD_CLASS_METHOD(SetAspect_1,"void vtkViewport::SetAspect(double _arg1, double _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setaspect)")
    ADD_CLASS_METHOD(SetAspect,"vtkViewport::SetAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setaspect)")
    ADD_CLASS_METHOD(SetAspect_2,"void vtkViewport::SetAspect(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setaspect)")
    ADD_CLASS_METHOD(GetAspect_1,"double * vtkViewport::GetAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getaspect)")
    ADD_CLASS_METHOD(GetAspect,"vtkViewport::GetAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getaspect)")
    ADD_CLASS_METHOD(GetAspect_2,"void vtkViewport::GetAspect(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getaspect)")
    ADD_CLASS_METHOD(ComputeAspect,"void vtkViewport::ComputeAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#computeaspect)")
    ADD_CLASS_METHOD(SetPixelAspect_1,"void vtkViewport::SetPixelAspect(double _arg1, double _arg2)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setpixelaspect)")
    ADD_CLASS_METHOD(SetPixelAspect,"vtkViewport::SetPixelAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setpixelaspect)")
    ADD_CLASS_METHOD(SetPixelAspect_2,"void vtkViewport::SetPixelAspect(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setpixelaspect)")
    ADD_CLASS_METHOD(GetPixelAspect_1,"double * vtkViewport::GetPixelAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpixelaspect)")
    ADD_CLASS_METHOD(GetPixelAspect,"vtkViewport::GetPixelAspect()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpixelaspect)")
    ADD_CLASS_METHOD(GetPixelAspect_2,"void vtkViewport::GetPixelAspect(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpixelaspect)")
    ADD_CLASS_METHOD(SetViewport_1,"void vtkViewport::SetViewport(double _arg1, double _arg2, double _arg3, double _arg4)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewport)")
    ADD_CLASS_METHOD(SetViewport,"vtkViewport::SetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewport)")
    ADD_CLASS_METHOD(SetViewport_2,"void vtkViewport::SetViewport(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewport)")
    ADD_CLASS_METHOD(GetViewport_1,"double * vtkViewport::GetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewport)")
    ADD_CLASS_METHOD(GetViewport,"vtkViewport::GetViewport()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewport)")
    ADD_CLASS_METHOD(GetViewport_2,"void vtkViewport::GetViewport(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewport)")
    ADD_CLASS_METHOD(SetDisplayPoint_1,"void vtkViewport::SetDisplayPoint(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setdisplaypoint)")
    ADD_CLASS_METHOD(SetDisplayPoint,"vtkViewport::SetDisplayPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setdisplaypoint)")
    ADD_CLASS_METHOD(SetDisplayPoint_2,"void vtkViewport::SetDisplayPoint(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setdisplaypoint)")
    ADD_CLASS_METHOD(GetDisplayPoint_1,"double * vtkViewport::GetDisplayPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getdisplaypoint)")
    ADD_CLASS_METHOD(GetDisplayPoint,"vtkViewport::GetDisplayPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getdisplaypoint)")
    ADD_CLASS_METHOD(GetDisplayPoint_2,"void vtkViewport::GetDisplayPoint(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getdisplaypoint)")
    ADD_CLASS_METHOD(SetViewPoint_1,"void vtkViewport::SetViewPoint(double _arg1, double _arg2, double _arg3)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewpoint)")
    ADD_CLASS_METHOD(SetViewPoint,"vtkViewport::SetViewPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewpoint)")
    ADD_CLASS_METHOD(SetViewPoint_2,"void vtkViewport::SetViewPoint(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setviewpoint)")
    ADD_CLASS_METHOD(GetViewPoint_1,"double * vtkViewport::GetViewPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewpoint)")
    ADD_CLASS_METHOD(GetViewPoint,"vtkViewport::GetViewPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewpoint)")
    ADD_CLASS_METHOD(GetViewPoint_2,"void vtkViewport::GetViewPoint(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getviewpoint)")
    ADD_CLASS_METHOD(SetWorldPoint_1,"void vtkViewport::SetWorldPoint(double _arg1, double _arg2, double _arg3, double _arg4)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setworldpoint)")
    ADD_CLASS_METHOD(SetWorldPoint,"vtkViewport::SetWorldPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setworldpoint)")
    ADD_CLASS_METHOD(SetWorldPoint_2,"void vtkViewport::SetWorldPoint(double * _arg)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#setworldpoint)")
    ADD_CLASS_METHOD(GetWorldPoint_1,"double * vtkViewport::GetWorldPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getworldpoint)")
    ADD_CLASS_METHOD(GetWorldPoint,"vtkViewport::GetWorldPoint()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getworldpoint)")
    ADD_CLASS_METHOD(GetWorldPoint_2,"void vtkViewport::GetWorldPoint(double * data)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getworldpoint)")
    ADD_CLASS_METHOD(GetCenter,"double * vtkViewport::GetCenter()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getcenter)")
    ADD_CLASS_METHOD(IsInViewport,"int vtkViewport::IsInViewport(int x, int y)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#isinviewport)")
    ADD_CLASS_METHOD(DisplayToView,"void vtkViewport::DisplayToView()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#displaytoview)")
    ADD_CLASS_METHOD(ViewToDisplay,"void vtkViewport::ViewToDisplay()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewtodisplay)")
    ADD_CLASS_METHOD(WorldToView_1,"void vtkViewport::WorldToView()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#worldtoview)")
    ADD_CLASS_METHOD(ViewToWorld_1,"void vtkViewport::ViewToWorld()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewtoworld)")
    ADD_CLASS_METHOD(DisplayToWorld,"void vtkViewport::DisplayToWorld()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#displaytoworld)")
    ADD_CLASS_METHOD(WorldToDisplay,"void vtkViewport::WorldToDisplay()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#worldtodisplay)")
    ADD_CLASS_METHOD(LocalDisplayToDisplay,"void vtkViewport::LocalDisplayToDisplay(double & x, double & y)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#localdisplaytodisplay)")
    ADD_CLASS_METHOD(DisplayToNormalizedDisplay,"void vtkViewport::DisplayToNormalizedDisplay(double & u, double & v)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#displaytonormalizeddisplay)")
    ADD_CLASS_METHOD(NormalizedDisplayToViewport,"void vtkViewport::NormalizedDisplayToViewport(double & x, double & y)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#normalizeddisplaytoviewport)")
    ADD_CLASS_METHOD(ViewportToNormalizedViewport,"void vtkViewport::ViewportToNormalizedViewport(double & u, double & v)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewporttonormalizedviewport)")
    ADD_CLASS_METHOD(NormalizedViewportToView,"void vtkViewport::NormalizedViewportToView(double & x, double & y, double & z)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#normalizedviewporttoview)")
    ADD_CLASS_METHOD(ViewToWorld,"vtkViewport::ViewToWorld()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewtoworld)")
    ADD_CLASS_METHOD(ViewToWorld_2,"void vtkViewport::ViewToWorld(double & param0, double & param1, double & param2)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewtoworld)")
    ADD_CLASS_METHOD(DisplayToLocalDisplay,"void vtkViewport::DisplayToLocalDisplay(double & x, double & y)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#displaytolocaldisplay)")
    ADD_CLASS_METHOD(NormalizedDisplayToDisplay,"void vtkViewport::NormalizedDisplayToDisplay(double & u, double & v)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#normalizeddisplaytodisplay)")
    ADD_CLASS_METHOD(ViewportToNormalizedDisplay,"void vtkViewport::ViewportToNormalizedDisplay(double & x, double & y)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewporttonormalizeddisplay)")
    ADD_CLASS_METHOD(NormalizedViewportToViewport,"void vtkViewport::NormalizedViewportToViewport(double & u, double & v)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#normalizedviewporttoviewport)")
    ADD_CLASS_METHOD(ViewToNormalizedViewport,"void vtkViewport::ViewToNormalizedViewport(double & x, double & y, double & z)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#viewtonormalizedviewport)")
    ADD_CLASS_METHOD(WorldToView,"vtkViewport::WorldToView()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#worldtoview)")
    ADD_CLASS_METHOD(WorldToView_2,"void vtkViewport::WorldToView(double & param0, double & param1, double & param2)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#worldtoview)")
    ADD_CLASS_METHOD(GetSize,"int * vtkViewport::GetSize()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getsize)")
    ADD_CLASS_METHOD(GetOrigin,"int * vtkViewport::GetOrigin()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getorigin)")
    ADD_CLASS_METHOD(GetTiledSize,"void vtkViewport::GetTiledSize(int * width, int * height)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#gettiledsize)")
    ADD_CLASS_METHOD(GetTiledSizeAndOrigin,"void vtkViewport::GetTiledSizeAndOrigin(int * width, int * height, int * lowerLeftX, int * lowerLeftY)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#gettiledsizeandorigin)")
/* The following types are missing: vtkAssemblyPath
    ADD_CLASS_METHOD(PickPropFrom,"vtkAssemblyPath * vtkViewport::PickPropFrom(double selectionX, double selectionY, vtkPropCollection * param2)  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#pickpropfrom)")
*/
    ADD_CLASS_METHOD(GetPickX,"double vtkViewport::GetPickX()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickx)")
    ADD_CLASS_METHOD(GetPickY,"double vtkViewport::GetPickY()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpicky)")
    ADD_CLASS_METHOD(GetPickWidth,"double vtkViewport::GetPickWidth()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickwidth)")
    ADD_CLASS_METHOD(GetPickHeight,"double vtkViewport::GetPickHeight()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickheight)")
    ADD_CLASS_METHOD(GetPickX1,"double vtkViewport::GetPickX1()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickx1)")
    ADD_CLASS_METHOD(GetPickY1,"double vtkViewport::GetPickY1()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpicky1)")
    ADD_CLASS_METHOD(GetPickX2,"double vtkViewport::GetPickX2()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickx2)")
    ADD_CLASS_METHOD(GetPickY2,"double vtkViewport::GetPickY2()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpicky2)")
    ADD_CLASS_METHOD(GetIsPicking,"int vtkViewport::GetIsPicking()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getispicking)")
    ADD_CLASS_METHOD(GetPickResultProps,"vtkPropCollection * vtkViewport::GetPickResultProps()  (http://docs.wxwidgets.org/stable/wx_vtkviewport.html#getpickresultprops)")





    void AddMethods(WrapClass<vtkViewport>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkViewport_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkViewport_h
