/**
 * C++ Interface: wrap_wxSizerFlags
 *
 * Description: wrapping wxSizerFlags
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSizerFlags_h_
#define _wrap_wxSizerFlags_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxSizerFlags);

// TODO: check for inheritence ...
class WrapClass_wxSizerFlags : public WrapClass<wxSizerFlags>
    
{
  DEFINE_CLASS(WrapClass_wxSizerFlags);

  protected:
    typedef WrapClass<wxSizerFlags>::ptr _parentclass_ptr;
    typedef wxSizerFlags ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSizerFlags>& GetObj() const { return WrapClass<wxSizerFlags>::GetObj(); }

    /// Constructor
    WrapClass_wxSizerFlags(boost::shared_ptr<wxSizerFlags > si): 
    WrapClass<wxSizerFlags>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxSizerFlags()
    {
      std::cout << "~WrapClass_wxSizerFlags()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerFlags_1,"Constructor wxSizerFlags::wxSizerFlags(wxSizerFlags const & param0) (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#wxsizerflags).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerFlags,"Constructor wxSizerFlags::wxSizerFlags() (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#wxsizerflags).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxSizerFlags_2,"Constructor wxSizerFlags::wxSizerFlags(int proportion = 0) (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#wxsizerflags).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizerFlags*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Proportion,"wxSizerFlags & wxSizerFlags::Proportion(int proportion)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#proportion)")
    ADD_CLASS_METHOD(Align,"wxSizerFlags & wxSizerFlags::Align(int alignment)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#align)")
    ADD_CLASS_METHOD(Expand,"wxSizerFlags & wxSizerFlags::Expand()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#expand)")
    ADD_CLASS_METHOD(Centre,"wxSizerFlags & wxSizerFlags::Centre()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#centre)")
    ADD_CLASS_METHOD(Center,"wxSizerFlags & wxSizerFlags::Center()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#center)")
    ADD_CLASS_METHOD(Left,"wxSizerFlags & wxSizerFlags::Left()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#left)")
    ADD_CLASS_METHOD(Right,"wxSizerFlags & wxSizerFlags::Right()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#right)")
    ADD_CLASS_METHOD(Top,"wxSizerFlags & wxSizerFlags::Top()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#top)")
    ADD_CLASS_METHOD(Bottom,"wxSizerFlags & wxSizerFlags::Bottom()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#bottom)")
    ADD_CLASS_METHOD(GetDefaultBorder,"int wxSizerFlags::GetDefaultBorder()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#getdefaultborder)")
    ADD_CLASS_METHOD(Border_1,"wxSizerFlags & wxSizerFlags::Border(int direction, int borderInPixels)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#border)")
    ADD_CLASS_METHOD(Border,"wxSizerFlags::Border()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#border)")
    ADD_CLASS_METHOD(Border_2,"wxSizerFlags & wxSizerFlags::Border(int direction = wxALL)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#border)")
    ADD_CLASS_METHOD(DoubleBorder,"wxSizerFlags & wxSizerFlags::DoubleBorder(int direction = wxALL)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#doubleborder)")
    ADD_CLASS_METHOD(TripleBorder,"wxSizerFlags & wxSizerFlags::TripleBorder(int direction = wxALL)  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#tripleborder)")
    ADD_CLASS_METHOD(HorzBorder,"wxSizerFlags & wxSizerFlags::HorzBorder()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#horzborder)")
    ADD_CLASS_METHOD(DoubleHorzBorder,"wxSizerFlags & wxSizerFlags::DoubleHorzBorder()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#doublehorzborder)")
    ADD_CLASS_METHOD(Shaped,"wxSizerFlags & wxSizerFlags::Shaped()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#shaped)")
    ADD_CLASS_METHOD(FixedMinSize,"wxSizerFlags & wxSizerFlags::FixedMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#fixedminsize)")
    ADD_CLASS_METHOD(ReserveSpaceEvenIfHidden,"wxSizerFlags & wxSizerFlags::ReserveSpaceEvenIfHidden()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#reservespaceevenifhidden)")
    ADD_CLASS_METHOD(GetProportion,"int wxSizerFlags::GetProportion()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#getproportion)")
    ADD_CLASS_METHOD(GetFlags,"int wxSizerFlags::GetFlags()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#getflags)")
    ADD_CLASS_METHOD(GetBorderInPixels,"int wxSizerFlags::GetBorderInPixels()  (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#getborderinpixels)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxSizerFlags & wxSizerFlags::=(wxSizerFlags const & param0) (http://docs.wxwidgets.org/stable/wx_wxsizerflags.html#__assign__)")




    void AddMethods(WrapClass<wxSizerFlags>::ptr this_ptr )
    {
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar___copy__( this_ptr);
      // Adding standard methods 
      AddVar_Proportion( this_ptr);
      AddVar_Align( this_ptr);
      AddVar_Expand( this_ptr);
      AddVar_Centre( this_ptr);
      AddVar_Center( this_ptr);
      AddVar_Left( this_ptr);
      AddVar_Right( this_ptr);
      AddVar_Top( this_ptr);
      AddVar_Bottom( this_ptr);
      AddVar_GetDefaultBorder( this_ptr);
      AddVar_Border_1( this_ptr);
      AddVar_Border( this_ptr);
      AddVar_Border_2( this_ptr);
      AddVar_DoubleBorder( this_ptr);
      AddVar_TripleBorder( this_ptr);
      AddVar_HorzBorder( this_ptr);
      AddVar_DoubleHorzBorder( this_ptr);
      AddVar_Shaped( this_ptr);
      AddVar_FixedMinSize( this_ptr);
      AddVar_ReserveSpaceEvenIfHidden( this_ptr);
      AddVar_GetProportion( this_ptr);
      AddVar_GetFlags( this_ptr);
      AddVar_GetBorderInPixels( this_ptr);

      // Adding operators
      AddVar___assign__( this_ptr);



      
    };
};


#endif // _wrap_wxSizerFlags_h
