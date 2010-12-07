/**
 * C++ Interface: wrap_wxwxSizerItemListNode
 *
 * Description: wrapping wxwxSizerItemListNode
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxwxSizerItemListNode_h_
#define _wrap_wxwxSizerItemListNode_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxNodeBase.h"



AMI_DECLARE_TYPE(wxwxSizerItemListNode);

// TODO: check for inheritence ...
class WrapClass_wxwxSizerItemListNode : public WrapClass<wxwxSizerItemListNode>
    , public   WrapClass_wxNodeBase
{
  DEFINE_CLASS(WrapClass_wxwxSizerItemListNode);

  protected:
    typedef WrapClass<wxwxSizerItemListNode>::ptr _parentclass_ptr;
    typedef wxwxSizerItemListNode ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxwxSizerItemListNode>& GetObj() const { return WrapClass<wxwxSizerItemListNode>::GetObj(); }

    /// Constructor
    WrapClass_wxwxSizerItemListNode(boost::shared_ptr<wxwxSizerItemListNode > si): 
    WrapClass<wxwxSizerItemListNode>(si)
    , WrapClass_wxNodeBase(si)
    {}

    /// Destructor
    ~WrapClass_wxwxSizerItemListNode()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxwxSizerItemListNode,"Constructor wxwxSizerItemListNode::wxwxSizerItemListNode(wxListBase * list = 0u, wxwxSizerItemListNode * previous = 0u, wxwxSizerItemListNode * next = 0u, wxSizerItem * data = 0u, wxListKey const & key = wxDefaultListKey) (http://docs.wxwidgets.org/stable/wx_wxwxsizeritemlistnode.html#wxwxsizeritemlistnode).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxwxSizerItemListNode*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetNext,"wxwxSizerItemListNode * wxwxSizerItemListNode::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxwxsizeritemlistnode.html#getnext)")
    ADD_CLASS_METHOD(GetPrevious,"wxwxSizerItemListNode * wxwxSizerItemListNode::GetPrevious()  (http://docs.wxwidgets.org/stable/wx_wxwxsizeritemlistnode.html#getprevious)")
    ADD_CLASS_METHOD(GetData,"wxSizerItem * wxwxSizerItemListNode::GetData()  (http://docs.wxwidgets.org/stable/wx_wxwxsizeritemlistnode.html#getdata)")
    ADD_CLASS_METHOD(SetData,"void wxwxSizerItemListNode::SetData(wxSizerItem * data)  (http://docs.wxwidgets.org/stable/wx_wxwxsizeritemlistnode.html#setdata)")





    void AddMethods(WrapClass<wxwxSizerItemListNode>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxwxSizerItemListNode_h
