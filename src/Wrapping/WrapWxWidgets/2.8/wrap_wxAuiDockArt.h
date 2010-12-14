/**
 * C++ Interface: wrap_wxAuiDockArt
 *
 * Description: wrapping wxAuiDockArt
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiDockArt_h_
#define _wrap_wxAuiDockArt_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxAuiDockArt_declared
  #define wxAuiDockArt_declared
  AMI_DECLARE_TYPE(wxAuiDockArt);
#endif

// TODO: check for inheritence ...
class WrapClass_wxAuiDockArt : public WrapClass<wxAuiDockArt>
    
{
  DEFINE_CLASS(WrapClass_wxAuiDockArt);

  protected:
    typedef WrapClass<wxAuiDockArt>::ptr _parentclass_ptr;
    typedef wxAuiDockArt ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiDockArt>& GetObj() const { return WrapClass<wxAuiDockArt>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiDockArt(boost::shared_ptr<wxAuiDockArt > si): 
    WrapClass<wxAuiDockArt>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiDockArt()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiDockArt*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetColor,"wxColour wxAuiDockArt::GetColor(int id)  (http://docs.wxwidgets.org/stable/wx_wxauidockart.html#getcolor)")
    ADD_CLASS_METHOD(SetColor,"void wxAuiDockArt::SetColor(int id, wxColour const & color)  (http://docs.wxwidgets.org/stable/wx_wxauidockart.html#setcolor)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxAuiDockArt & wxAuiDockArt::operator =(wxAuiDockArt const & param0) (http://docs.wxwidgets.org/stable/wx_wxauidockart.html#__assign__)")




    void AddMethods(WrapClass<wxAuiDockArt>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxAuiDockArt_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxAuiDockArt_h
