/**
 * C++ Interface: wrap_wxMBConv
 *
 * Description: wrapping wxMBConv
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxMBConv_h_
#define _wrap_wxMBConv_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxMBConv);

// TODO: check for inheritence ...
class WrapClass_wxMBConv : public WrapClass<wxMBConv>
    
{
  DEFINE_CLASS(WrapClass_wxMBConv);

  protected:
    typedef WrapClass<wxMBConv>::ptr _parentclass_ptr;
    typedef wxMBConv ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxMBConv>& GetObj() const { return WrapClass<wxMBConv>::GetObj(); }

    /// Constructor
    WrapClass_wxMBConv(boost::shared_ptr<wxMBConv > si): 
    WrapClass<wxMBConv>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxMBConv()
    {
      std::cout << "~WrapClass_wxMBConv()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxMBConv*);

    // here add each method
    
    // Adding standard methods
    ADD_CLASS_METHOD(ToWChar,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#towchar")
    ADD_CLASS_METHOD(FromWChar,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#fromwchar")
    ADD_CLASS_METHOD(cMB2WC_1,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc")
    ADD_CLASS_METHOD(cWC2MB_1,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb")
    ADD_CLASS_METHOD(cMB2WC,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc")
    ADD_CLASS_METHOD(cMB2WC_2,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wc")
    ADD_CLASS_METHOD(cWC2MB,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb")
    ADD_CLASS_METHOD(cWC2MB_2,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2mb")
    ADD_CLASS_METHOD(cMB2WX,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cmb2wx")
    ADD_CLASS_METHOD(cWX2MB,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwx2mb")
    ADD_CLASS_METHOD(cWC2WX,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwc2wx")
    ADD_CLASS_METHOD(cWX2WC,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#cwx2wc")
    ADD_CLASS_METHOD(GetMBNulLen,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#getmbnullen")
    ADD_CLASS_METHOD(GetMaxMBNulLen,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#getmaxmbnullen")
    ADD_CLASS_METHOD(MB2WC,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#mb2wc")
    ADD_CLASS_METHOD(WC2MB,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#wc2mb")

    // Operators:
    ADD_CLASS_METHOD(__assign__,"http://docs.wxwidgets.org/stable/wx_wxmbconv.html#__assign__")




    void AddMethods(WrapClass<wxMBConv>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding standard methods 
      AddVar_ToWChar( this_ptr);
      AddVar_FromWChar( this_ptr);
      AddVar_cMB2WC_1( this_ptr);
      AddVar_cWC2MB_1( this_ptr);
      AddVar_cMB2WC( this_ptr);
      AddVar_cMB2WC_2( this_ptr);
      AddVar_cWC2MB( this_ptr);
      AddVar_cWC2MB_2( this_ptr);
      AddVar_cMB2WX( this_ptr);
      AddVar_cWX2MB( this_ptr);
      AddVar_cWC2WX( this_ptr);
      AddVar_cWX2WC( this_ptr);
      AddVar_GetMBNulLen( this_ptr);
      AddVar_GetMaxMBNulLen( this_ptr);
      AddVar_MB2WC( this_ptr);
      AddVar_WC2MB( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_wxMBConv_h
