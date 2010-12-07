/**
 * C++ Interface: wrap_wxPaletteBase
 *
 * Description: wrapping wxPaletteBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPaletteBase_h_
#define _wrap_wxPaletteBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGDIObject.h"



AMI_DECLARE_TYPE(wxPaletteBase);

// TODO: check for inheritence ...
class WrapClass_wxPaletteBase : public WrapClass<wxPaletteBase>
    , public   WrapClass_wxGDIObject
{
  DEFINE_CLASS(WrapClass_wxPaletteBase);

  protected:
    typedef WrapClass<wxPaletteBase>::ptr _parentclass_ptr;
    typedef wxPaletteBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPaletteBase>& GetObj() const { return WrapClass<wxPaletteBase>::GetObj(); }

    /// Constructor
    WrapClass_wxPaletteBase(boost::shared_ptr<wxPaletteBase > si): 
    WrapClass<wxPaletteBase>(si)
    , WrapClass_wxGDIObject(si)
    {}

    /// Destructor
    ~WrapClass_wxPaletteBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPaletteBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Ok,"bool wxPaletteBase::Ok()  (http://docs.wxwidgets.org/stable/wx_wxpalettebase.html#ok)")
    ADD_CLASS_METHOD(GetColoursCount,"int wxPaletteBase::GetColoursCount()  (http://docs.wxwidgets.org/stable/wx_wxpalettebase.html#getcolourscount)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPaletteBase & wxPaletteBase::operator =(wxPaletteBase const & param0) (http://docs.wxwidgets.org/stable/wx_wxpalettebase.html#__assign__)")




    void AddMethods(WrapClass<wxPaletteBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxPaletteBase_h
