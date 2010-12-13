/**
 * C++ Interface: wrap_wxBrushBase
 *
 * Description: wrapping wxBrushBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxBrushBase_h_
#define _wrap_wxBrushBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"


#ifndef wxBrushBase_declared
  #define wxBrushBase_declared
  AMI_DECLARE_TYPE(wxBrushBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxBrushBase : public WrapClass<wxBrushBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxBrushBase);

  protected:
    typedef WrapClass<wxBrushBase>::ptr _parentclass_ptr;
    typedef wxBrushBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxBrushBase>& GetObj() const { return WrapClass<wxBrushBase>::GetObj(); }

    /// Constructor
    WrapClass_wxBrushBase(boost::shared_ptr<wxBrushBase > si): 
    WrapClass<wxBrushBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxBrushBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxBrushBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsHatch,"bool wxBrushBase::IsHatch()  (http://docs.wxwidgets.org/stable/wx_wxbrushbase.html#ishatch)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxBrushBase & wxBrushBase::operator =(wxBrushBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxbrushbase.html#__assign__)")




    void AddMethods(WrapClass<wxBrushBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxBrushBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxBrushBase_h
