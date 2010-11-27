/**
 * C++ Interface: wrap_wxWindowListNode
 *
 * Description: wrapping wxWindowListNode
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxWindowListNode_h_
#define _wrap_wxWindowListNode_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxNodeBase.h"



AMI_DECLARE_TYPE(wxWindowListNode);

// TODO: check for inheritence ...
class WrapClass_wxWindowListNode : public WrapClass<wxWindowListNode>
    , public   WrapClass_wxNodeBase
{
  DEFINE_CLASS(WrapClass_wxWindowListNode);

  protected:
    typedef WrapClass<wxWindowListNode>::ptr _parentclass_ptr;
    typedef wxWindowListNode ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxWindowListNode>& GetObj() const { return WrapClass<wxWindowListNode>::GetObj(); }

    /// Constructor
    WrapClass_wxWindowListNode(boost::shared_ptr<wxWindowListNode > si): 
    WrapClass<wxWindowListNode>(si)
    , WrapClass_wxNodeBase(si)
    {}

    /// Destructor
    ~WrapClass_wxWindowListNode()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxWindowListNode,"Constructor wxWindowListNode::wxWindowListNode(wxListBase * list = 0u, wxWindowListNode * previous = 0u, wxWindowListNode * next = 0u, wxWindow * data = 0u, wxListKey const & key = wxDefaultListKey) (http://docs.wxwidgets.org/stable/wx_wxwindowlistnode.html#wxwindowlistnode).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxWindowListNode*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetNext,"wxWindowListNode * wxWindowListNode::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxwindowlistnode.html#getnext)")
    ADD_CLASS_METHOD(GetPrevious,"wxWindowListNode * wxWindowListNode::GetPrevious()  (http://docs.wxwidgets.org/stable/wx_wxwindowlistnode.html#getprevious)")
    ADD_CLASS_METHOD(GetData,"wxWindow * wxWindowListNode::GetData()  (http://docs.wxwidgets.org/stable/wx_wxwindowlistnode.html#getdata)")
    ADD_CLASS_METHOD(SetData,"void wxWindowListNode::SetData(wxWindow * data)  (http://docs.wxwidgets.org/stable/wx_wxwindowlistnode.html#setdata)")





    void AddMethods(WrapClass<wxWindowListNode>::ptr this_ptr );

};


#endif // _wrap_wxWindowListNode_h
