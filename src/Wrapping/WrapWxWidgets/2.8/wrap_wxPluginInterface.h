/**
 * C++ Interface: wrap_wxPluginInterface
 *
 * Description: wrapping wxPluginInterface
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxPluginInterface_h_
#define _wrap_wxPluginInterface_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...



#ifndef wxPluginInterface_declared
  #define wxPluginInterface_declared
  AMI_DECLARE_TYPE(wxPluginInterface);
#endif

// TODO: check for inheritence ...
class WrapClass_wxPluginInterface : public WrapClass<wxPluginInterface>
    
{
  DEFINE_CLASS(WrapClass_wxPluginInterface);

  protected:
    typedef WrapClass<wxPluginInterface>::ptr _parentclass_ptr;
    typedef wxPluginInterface ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxPluginInterface>& GetObj() const { return WrapClass<wxPluginInterface>::GetObj(); }

    /// Constructor
    WrapClass_wxPluginInterface(boost::shared_ptr<wxPluginInterface > si): 
    WrapClass<wxPluginInterface>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxPluginInterface()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxPluginInterface*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxPluginInterface & wxPluginInterface::operator =(wxPluginInterface const & param0) (http://docs.wxwidgets.org/stable/wx_wxplugininterface.html#__assign__)")




    void AddMethods(WrapClass<wxPluginInterface>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxPluginInterface_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxPluginInterface_h
