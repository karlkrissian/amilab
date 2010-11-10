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
    ADD_CLASS_CONSTRUCTOR(wxRect1,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect2,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect3,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect4,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect5,"Wrapping of wxRect.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxRect6,"Wrapping of wxRect.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxRect*);

    // here add each method
    
    ADD_CLASS_METHOD(GetX,"")
    ADD_CLASS_METHOD(SetX,"")
    ADD_CLASS_METHOD(GetY,"")
    ADD_CLASS_METHOD(SetY,"")
    ADD_CLASS_METHOD(GetWidth,"")
    ADD_CLASS_METHOD(SetWidth,"")
    ADD_CLASS_METHOD(GetHeight,"")
    ADD_CLASS_METHOD(SetHeight,"")
    ADD_CLASS_METHOD(GetPosition,"")
    ADD_CLASS_METHOD(SetPosition,"")
    ADD_CLASS_METHOD(GetSize,"")
    ADD_CLASS_METHOD(SetSize,"")
    ADD_CLASS_METHOD(IsEmpty,"")
    ADD_CLASS_METHOD(GetLeft,"")
    ADD_CLASS_METHOD(GetTop,"")
    ADD_CLASS_METHOD(GetBottom,"")
    ADD_CLASS_METHOD(GetRight,"")
    ADD_CLASS_METHOD(SetLeft,"")
    ADD_CLASS_METHOD(SetRight,"")
    ADD_CLASS_METHOD(SetTop,"")
    ADD_CLASS_METHOD(SetBottom,"")
    ADD_CLASS_METHOD(GetTopLeft,"")
    ADD_CLASS_METHOD(GetLeftTop,"")
    ADD_CLASS_METHOD(SetTopLeft,"")
    ADD_CLASS_METHOD(SetLeftTop,"")
    ADD_CLASS_METHOD(GetBottomRight,"")
    ADD_CLASS_METHOD(GetRightBottom,"")
    ADD_CLASS_METHOD(SetBottomRight,"")
    ADD_CLASS_METHOD(SetRightBottom,"")
    ADD_CLASS_METHOD(GetTopRight,"")
    ADD_CLASS_METHOD(GetRightTop,"")
    ADD_CLASS_METHOD(SetTopRight,"")
    ADD_CLASS_METHOD(SetRightTop,"")
    ADD_CLASS_METHOD(GetBottomLeft,"")
    ADD_CLASS_METHOD(GetLeftBottom,"")
    ADD_CLASS_METHOD(SetBottomLeft,"")
    ADD_CLASS_METHOD(SetLeftBottom,"")
    ADD_CLASS_METHOD(Inflate1,"")
    ADD_CLASS_METHOD(Inflate,"")
    ADD_CLASS_METHOD(Inflate2,"")
    ADD_CLASS_METHOD(Inflate3,"")
    ADD_CLASS_METHOD(Inflate4,"")
    ADD_CLASS_METHOD(Deflate1,"")
    ADD_CLASS_METHOD(Deflate,"")
    ADD_CLASS_METHOD(Deflate2,"")
    ADD_CLASS_METHOD(Deflate3,"")
    ADD_CLASS_METHOD(Deflate4,"")
    ADD_CLASS_METHOD(Offset1,"")
    ADD_CLASS_METHOD(Offset,"")
    ADD_CLASS_METHOD(Offset2,"")
    ADD_CLASS_METHOD(Intersect1,"")
    ADD_CLASS_METHOD(Intersect,"")
    ADD_CLASS_METHOD(Intersect2,"")
    ADD_CLASS_METHOD(Union1,"")
    ADD_CLASS_METHOD(Union,"")
    ADD_CLASS_METHOD(Union2,"")
    ADD_CLASS_METHOD(Contains1,"")
    ADD_CLASS_METHOD(Contains,"")
    ADD_CLASS_METHOD(Contains2,"")
    ADD_CLASS_METHOD(Contains3,"")
    ADD_CLASS_METHOD(Inside1,"")
    ADD_CLASS_METHOD(Inside,"")
    ADD_CLASS_METHOD(Inside2,"")
    ADD_CLASS_METHOD(Inside3,"")
    ADD_CLASS_METHOD(Intersects,"")
    ADD_CLASS_METHOD(CentreIn,"")
    ADD_CLASS_METHOD(CenterIn,"")

    // Operators:
    ADD_CLASS_METHOD(assign,"")
    ADD_CLASS_METHOD(equal,"")
    ADD_CLASS_METHOD(not_equal,"")
    ADD_CLASS_METHOD(add,"")
    ADD_CLASS_METHOD(add_assign,"")




    void AddMethods(WrapClass<wxRect>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
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
      AddVar_Inside1( this_ptr);
      AddVar_Inside( this_ptr);
      AddVar_Inside2( this_ptr);
      AddVar_Inside3( this_ptr);
      AddVar_Intersects( this_ptr);
      AddVar_CentreIn( this_ptr);
      AddVar_CenterIn( this_ptr);

      // Operators:
      AddVar_assign( this_ptr);
      AddVar_equal( this_ptr);
      AddVar_not_equal( this_ptr);
      AddVar_add( this_ptr);
      AddVar_add_assign( this_ptr);


    };
};


#endif // _wrap_wxRect_h
