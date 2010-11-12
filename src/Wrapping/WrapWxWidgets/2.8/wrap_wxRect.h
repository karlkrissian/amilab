/**
 * C++ Interface: wrap_wxRect
 *
 * Description: wrapping wxRect
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxRect_h_
#define _wrap_wxRect_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxRect);

// TODO: check for inheritence ...
class WrapClass_wxRect : public WrapClass<wxRect>
    
{
  DEFINE_CLASS(WrapClass_wxRect);

  protected:
    typedef WrapClass<wxRect>::ptr _parentclass_ptr;
    typedef wxRect ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxRect>& GetObj() const { return WrapClass<wxRect>::GetObj(); }

    /// Constructor
    WrapClass_wxRect(boost::shared_ptr<wxRect > si): 
    WrapClass<wxRect>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxRect()
    {
      std::cout << "~WrapClass_wxRect()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect1,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect2,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect3,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect4,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect5,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect6,"Wrapping of wxRect, http://docs.wxwidgets.org/stable/wx_wxrect.html#wxrect.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxRect*);

    // here add each method
    
    // Adding copy method
    ADD_CLASS_METHOD(copy,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(GetX,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getx")
    ADD_CLASS_METHOD(SetX,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setx")
    ADD_CLASS_METHOD(GetY,"http://docs.wxwidgets.org/stable/wx_wxrect.html#gety")
    ADD_CLASS_METHOD(SetY,"http://docs.wxwidgets.org/stable/wx_wxrect.html#sety")
    ADD_CLASS_METHOD(GetWidth,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getwidth")
    ADD_CLASS_METHOD(SetWidth,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setwidth")
    ADD_CLASS_METHOD(GetHeight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getheight")
    ADD_CLASS_METHOD(SetHeight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setheight")
    ADD_CLASS_METHOD(GetPosition,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getposition")
    ADD_CLASS_METHOD(SetPosition,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setposition")
    ADD_CLASS_METHOD(GetSize,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getsize")
    ADD_CLASS_METHOD(SetSize,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setsize")
    ADD_CLASS_METHOD(IsEmpty,"http://docs.wxwidgets.org/stable/wx_wxrect.html#isempty")
    ADD_CLASS_METHOD(GetLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getleft")
    ADD_CLASS_METHOD(GetTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#gettop")
    ADD_CLASS_METHOD(GetBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottom")
    ADD_CLASS_METHOD(GetRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getright")
    ADD_CLASS_METHOD(SetLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setleft")
    ADD_CLASS_METHOD(SetRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setright")
    ADD_CLASS_METHOD(SetTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#settop")
    ADD_CLASS_METHOD(SetBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottom")
    ADD_CLASS_METHOD(GetTopLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#gettopleft")
    ADD_CLASS_METHOD(GetLeftTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getlefttop")
    ADD_CLASS_METHOD(SetTopLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#settopleft")
    ADD_CLASS_METHOD(SetLeftTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setlefttop")
    ADD_CLASS_METHOD(GetBottomRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottomright")
    ADD_CLASS_METHOD(GetRightBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getrightbottom")
    ADD_CLASS_METHOD(SetBottomRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottomright")
    ADD_CLASS_METHOD(SetRightBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setrightbottom")
    ADD_CLASS_METHOD(GetTopRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#gettopright")
    ADD_CLASS_METHOD(GetRightTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getrighttop")
    ADD_CLASS_METHOD(SetTopRight,"http://docs.wxwidgets.org/stable/wx_wxrect.html#settopright")
    ADD_CLASS_METHOD(SetRightTop,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setrighttop")
    ADD_CLASS_METHOD(GetBottomLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getbottomleft")
    ADD_CLASS_METHOD(GetLeftBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#getleftbottom")
    ADD_CLASS_METHOD(SetBottomLeft,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setbottomleft")
    ADD_CLASS_METHOD(SetLeftBottom,"http://docs.wxwidgets.org/stable/wx_wxrect.html#setleftbottom")
    ADD_CLASS_METHOD(Inflate1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate")
    ADD_CLASS_METHOD(Inflate,"http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate")
    ADD_CLASS_METHOD(Inflate2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate")
    ADD_CLASS_METHOD(Inflate3,"http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate")
    ADD_CLASS_METHOD(Inflate4,"http://docs.wxwidgets.org/stable/wx_wxrect.html#inflate")
    ADD_CLASS_METHOD(Deflate1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate")
    ADD_CLASS_METHOD(Deflate,"http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate")
    ADD_CLASS_METHOD(Deflate2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate")
    ADD_CLASS_METHOD(Deflate3,"http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate")
    ADD_CLASS_METHOD(Deflate4,"http://docs.wxwidgets.org/stable/wx_wxrect.html#deflate")
    ADD_CLASS_METHOD(Offset1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#offset")
    ADD_CLASS_METHOD(Offset,"http://docs.wxwidgets.org/stable/wx_wxrect.html#offset")
    ADD_CLASS_METHOD(Offset2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#offset")
    ADD_CLASS_METHOD(Intersect1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect")
    ADD_CLASS_METHOD(Intersect,"http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect")
    ADD_CLASS_METHOD(Intersect2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#intersect")
    ADD_CLASS_METHOD(Union1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#union")
    ADD_CLASS_METHOD(Union,"http://docs.wxwidgets.org/stable/wx_wxrect.html#union")
    ADD_CLASS_METHOD(Union2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#union")
    ADD_CLASS_METHOD(Contains1,"http://docs.wxwidgets.org/stable/wx_wxrect.html#contains")
    ADD_CLASS_METHOD(Contains,"http://docs.wxwidgets.org/stable/wx_wxrect.html#contains")
    ADD_CLASS_METHOD(Contains2,"http://docs.wxwidgets.org/stable/wx_wxrect.html#contains")
    ADD_CLASS_METHOD(Contains3,"http://docs.wxwidgets.org/stable/wx_wxrect.html#contains")
    ADD_CLASS_METHOD(Intersects,"http://docs.wxwidgets.org/stable/wx_wxrect.html#intersects")
    ADD_CLASS_METHOD(CentreIn,"http://docs.wxwidgets.org/stable/wx_wxrect.html#centrein")
    ADD_CLASS_METHOD(CenterIn,"http://docs.wxwidgets.org/stable/wx_wxrect.html#centerin")

    // Operators:
    ADD_CLASS_METHOD(assign,"http://docs.wxwidgets.org/stable/wx_wxrect.html#assign")
    ADD_CLASS_METHOD(equal,"http://docs.wxwidgets.org/stable/wx_wxrect.html#equal")
    ADD_CLASS_METHOD(not_equal,"http://docs.wxwidgets.org/stable/wx_wxrect.html#not_equal")
    ADD_CLASS_METHOD(add,"http://docs.wxwidgets.org/stable/wx_wxrect.html#add")
    ADD_CLASS_METHOD(add_assign,"http://docs.wxwidgets.org/stable/wx_wxrect.html#add_assign")




    void AddMethods(WrapClass<wxRect>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
      // Adding copy method 
      AddVar_copy( this_ptr);
       // Adding standard methods 
      AddVar_GetX( this_ptr);
      AddVar_SetX( this_ptr);
      AddVar_GetY( this_ptr);
      AddVar_SetY( this_ptr);
      AddVar_GetWidth( this_ptr);
      AddVar_SetWidth( this_ptr);
      AddVar_GetHeight( this_ptr);
      AddVar_SetHeight( this_ptr);
      AddVar_GetPosition( this_ptr);
      AddVar_SetPosition( this_ptr);
      AddVar_GetSize( this_ptr);
      AddVar_SetSize( this_ptr);
      AddVar_IsEmpty( this_ptr);
      AddVar_GetLeft( this_ptr);
      AddVar_GetTop( this_ptr);
      AddVar_GetBottom( this_ptr);
      AddVar_GetRight( this_ptr);
      AddVar_SetLeft( this_ptr);
      AddVar_SetRight( this_ptr);
      AddVar_SetTop( this_ptr);
      AddVar_SetBottom( this_ptr);
      AddVar_GetTopLeft( this_ptr);
      AddVar_GetLeftTop( this_ptr);
      AddVar_SetTopLeft( this_ptr);
      AddVar_SetLeftTop( this_ptr);
      AddVar_GetBottomRight( this_ptr);
      AddVar_GetRightBottom( this_ptr);
      AddVar_SetBottomRight( this_ptr);
      AddVar_SetRightBottom( this_ptr);
      AddVar_GetTopRight( this_ptr);
      AddVar_GetRightTop( this_ptr);
      AddVar_SetTopRight( this_ptr);
      AddVar_SetRightTop( this_ptr);
      AddVar_GetBottomLeft( this_ptr);
      AddVar_GetLeftBottom( this_ptr);
      AddVar_SetBottomLeft( this_ptr);
      AddVar_SetLeftBottom( this_ptr);
      AddVar_Inflate1( this_ptr);
      AddVar_Inflate( this_ptr);
      AddVar_Inflate2( this_ptr);
      AddVar_Inflate3( this_ptr);
      AddVar_Inflate4( this_ptr);
      AddVar_Deflate1( this_ptr);
      AddVar_Deflate( this_ptr);
      AddVar_Deflate2( this_ptr);
      AddVar_Deflate3( this_ptr);
      AddVar_Deflate4( this_ptr);
      AddVar_Offset1( this_ptr);
      AddVar_Offset( this_ptr);
      AddVar_Offset2( this_ptr);
      AddVar_Intersect1( this_ptr);
      AddVar_Intersect( this_ptr);
      AddVar_Intersect2( this_ptr);
      AddVar_Union1( this_ptr);
      AddVar_Union( this_ptr);
      AddVar_Union2( this_ptr);
      AddVar_Contains1( this_ptr);
      AddVar_Contains( this_ptr);
      AddVar_Contains2( this_ptr);
      AddVar_Contains3( this_ptr);
      AddVar_Intersects( this_ptr);
      AddVar_CentreIn( this_ptr);
      AddVar_CenterIn( this_ptr);

      // Adding operators
      AddVar_assign( this_ptr);
      AddVar_equal( this_ptr);
      AddVar_not_equal( this_ptr);
      AddVar_add( this_ptr);
      AddVar_add_assign( this_ptr);


    };
};


#endif // _wrap_wxRect_h
