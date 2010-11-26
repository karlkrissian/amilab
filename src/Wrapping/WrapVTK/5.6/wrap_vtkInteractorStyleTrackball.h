/**
 * C++ Interface: wrap_vtkInteractorStyleTrackball
 *
 * Description: wrapping vtkInteractorStyleTrackball
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkInteractorStyleTrackball_h_
#define _wrap_vtkInteractorStyleTrackball_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkInteractorStyleSwitch.h"



AMI_DECLARE_TYPE(vtkInteractorStyleTrackball);

// TODO: check for inheritence ...
class WrapClass_vtkInteractorStyleTrackball : public WrapClass<vtkInteractorStyleTrackball>
    , public   WrapClass_vtkInteractorStyleSwitch
{
  DEFINE_CLASS(WrapClass_vtkInteractorStyleTrackball);

  protected:
    typedef WrapClass<vtkInteractorStyleTrackball>::ptr _parentclass_ptr;
    typedef vtkInteractorStyleTrackball ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkInteractorStyleTrackball>& GetObj() const { return WrapClass<vtkInteractorStyleTrackball>::GetObj(); }

    /// Constructor
    WrapClass_vtkInteractorStyleTrackball(boost::shared_ptr<vtkInteractorStyleTrackball > si): 
    WrapClass<vtkInteractorStyleTrackball>(si)
    , WrapClass_vtkInteractorStyleSwitch(si)
    {}

    /// Destructor
    ~WrapClass_vtkInteractorStyleTrackball()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkInteractorStyleTrackball*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::New() (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkInteractorStyleTrackball::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkInteractorStyleTrackball::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkInteractorStyleTrackball * vtkInteractorStyleTrackball::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkInteractorStyleTrackball::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkinteractorstyletrackball.html#printself)")
*/





    void AddMethods(WrapClass<vtkInteractorStyleTrackball>::ptr this_ptr );

};


#endif // _wrap_vtkInteractorStyleTrackball_h
