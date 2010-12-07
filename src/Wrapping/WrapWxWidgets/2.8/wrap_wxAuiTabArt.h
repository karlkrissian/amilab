/**
 * C++ Interface: wrap_wxAuiTabArt
 *
 * Description: wrapping wxAuiTabArt
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiTabArt_h_
#define _wrap_wxAuiTabArt_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiTabArt);

// TODO: check for inheritence ...
class WrapClass_wxAuiTabArt : public WrapClass<wxAuiTabArt>
    
{
  DEFINE_CLASS(WrapClass_wxAuiTabArt);

  protected:
    typedef WrapClass<wxAuiTabArt>::ptr _parentclass_ptr;
    typedef wxAuiTabArt ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiTabArt>& GetObj() const { return WrapClass<wxAuiTabArt>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiTabArt(boost::shared_ptr<wxAuiTabArt > si): 
    WrapClass<wxAuiTabArt>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiTabArt()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiTabArt*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiTabArt & wxAuiTabArt::operator =(wxAuiTabArt const & param0) (http://docs.wxwidgets.org/stable/wx_wxauitabart.html#__assign__)")




    void AddMethods(WrapClass<wxAuiTabArt>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxAuiTabArt_h
