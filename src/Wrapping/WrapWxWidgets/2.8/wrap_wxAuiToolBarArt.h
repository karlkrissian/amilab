/**
 * C++ Interface: wrap_wxAuiToolBarArt
 *
 * Description: wrapping wxAuiToolBarArt
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBarArt_h_
#define _wrap_wxAuiToolBarArt_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxAuiToolBarArt_declared
  #define wxAuiToolBarArt_declared
  AMI_DECLARE_TYPE(wxAuiToolBarArt);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBarArt : public WrapClass<wxAuiToolBarArt>
    
{
  DEFINE_CLASS(WrapClass_wxAuiToolBarArt);

  protected:
    typedef WrapClass<wxAuiToolBarArt>::ptr _parentclass_ptr;
    typedef wxAuiToolBarArt ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBarArt>& GetObj() const { return WrapClass<wxAuiToolBarArt>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBarArt(boost::shared_ptr<wxAuiToolBarArt > si): 
    WrapClass<wxAuiToolBarArt>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBarArt()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarArt*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiToolBarArt & wxAuiToolBarArt::operator =(wxAuiToolBarArt const & param0) (http://docs.wxwidgets.org/stable/wx_wxauitoolbarart.html#__assign__)")




    void AddMethods(WrapClass<wxAuiToolBarArt>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiToolBarArt_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiToolBarArt_h
