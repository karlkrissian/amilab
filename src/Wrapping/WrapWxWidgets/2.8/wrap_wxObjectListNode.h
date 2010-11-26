/**
 * C++ Interface: wrap_wxObjectListNode
 *
 * Description: wrapping wxObjectListNode
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxObjectListNode_h_
#define _wrap_wxObjectListNode_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxNodeBase.h"



AMI_DECLARE_TYPE(wxObjectListNode);

// TODO: check for inheritence ...
class WrapClass_wxObjectListNode : public WrapClass<wxObjectListNode>
    , public   WrapClass_wxNodeBase
{
  DEFINE_CLASS(WrapClass_wxObjectListNode);

  protected:
    typedef WrapClass<wxObjectListNode>::ptr _parentclass_ptr;
    typedef wxObjectListNode ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxObjectListNode>& GetObj() const { return WrapClass<wxObjectListNode>::GetObj(); }

    /// Constructor
    WrapClass_wxObjectListNode(boost::shared_ptr<wxObjectListNode > si): 
    WrapClass<wxObjectListNode>(si)
    , WrapClass_wxNodeBase(si)
    {}

    /// Destructor
    ~WrapClass_wxObjectListNode()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxObjectListNode,"Constructor wxObjectListNode::wxObjectListNode(wxListBase * list = 0u, wxObjectListNode * previous = 0u, wxObjectListNode * next = 0u, wxObject * data = 0u, wxListKey const & key = wxDefaultListKey) (http://docs.wxwidgets.org/stable/wx_wxobjectlistnode.html#wxobjectlistnode).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxObjectListNode*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetNext,"wxObjectListNode * wxObjectListNode::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxobjectlistnode.html#getnext)")
    ADD_CLASS_METHOD(GetPrevious,"wxObjectListNode * wxObjectListNode::GetPrevious()  (http://docs.wxwidgets.org/stable/wx_wxobjectlistnode.html#getprevious)")
    ADD_CLASS_METHOD(GetData,"wxObject * wxObjectListNode::GetData()  (http://docs.wxwidgets.org/stable/wx_wxobjectlistnode.html#getdata)")
    ADD_CLASS_METHOD(SetData,"void wxObjectListNode::SetData(wxObject * data)  (http://docs.wxwidgets.org/stable/wx_wxobjectlistnode.html#setdata)")





    void AddMethods(WrapClass<wxObjectListNode>::ptr this_ptr );

};


#endif // _wrap_wxObjectListNode_h
