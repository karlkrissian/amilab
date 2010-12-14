/**
 * C++ Interface: wrap_wxStaticBoxBase
 *
 * Description: wrapping wxStaticBoxBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStaticBoxBase_h_
#define _wrap_wxStaticBoxBase_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxControl.h"


#ifndef wxStaticBoxBase_declared
  #define wxStaticBoxBase_declared
  AMI_DECLARE_TYPE(wxStaticBoxBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxStaticBoxBase : public WrapClass<wxStaticBoxBase>
    , public   WrapClass_wxControl
{
  DEFINE_CLASS(WrapClass_wxStaticBoxBase);

  protected:
    typedef WrapClass<wxStaticBoxBase>::ptr _parentclass_ptr;
    typedef wxStaticBoxBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStaticBoxBase>& GetObj() const { return WrapClass<wxStaticBoxBase>::GetObj(); }

    /// Constructor
    WrapClass_wxStaticBoxBase(boost::shared_ptr<wxStaticBoxBase > si): 
    WrapClass<wxStaticBoxBase>(si)
    , WrapClass_wxControl(si)
    {}

    /// Destructor
    ~WrapClass_wxStaticBoxBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBoxBase,"Constructor wxStaticBoxBase::wxStaticBoxBase() (http://docs.wxwidgets.org/stable/wx_wxstaticboxbase.html#wxstaticboxbase).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStaticBoxBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxStaticBoxBase::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxbase.html#acceptsfocus)")
    ADD_CLASS_METHOD(HasTransparentBackground,"bool wxStaticBoxBase::HasTransparentBackground()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxbase.html#hastransparentbackground)")
    ADD_CLASS_METHOD(GetBordersForSizer,"void wxStaticBoxBase::GetBordersForSizer(int * borderTop, int * borderOther)  (http://docs.wxwidgets.org/stable/wx_wxstaticboxbase.html#getbordersforsizer)")





    void AddMethods(WrapClass<wxStaticBoxBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStaticBoxBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxStaticBoxBase_h
