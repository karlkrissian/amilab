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

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiToolBarArt);

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
      std::cout << "~WrapClass_wxAuiToolBarArt()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarArt*);

    // here add each method
    

    // Operators:
    ADD_CLASS_METHOD(assign,"")




    void AddMethods(WrapClass<wxAuiToolBarArt>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      

      // Operators:
      AddVar_assign( this_ptr);


    };
};


#endif // _wrap_wxAuiToolBarArt_h
