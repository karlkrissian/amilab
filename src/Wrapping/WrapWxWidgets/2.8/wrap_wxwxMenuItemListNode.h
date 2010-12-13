/**
 * C++ Interface: wrap_wxwxMenuItemListNode
 *
 * Description: wrapping wxwxMenuItemListNode
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxwxMenuItemListNode_h_
#define _wrap_wxwxMenuItemListNode_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxNodeBase.h"


#ifndef wxwxMenuItemListNode_declared
  #define wxwxMenuItemListNode_declared
  AMI_DECLARE_TYPE(wxwxMenuItemListNode);
#endif

// TODO: check for inheritence ...
class WrapClass_wxwxMenuItemListNode : public WrapClass<wxwxMenuItemListNode>
    , public   WrapClass_wxNodeBase
{
  DEFINE_CLASS(WrapClass_wxwxMenuItemListNode);

  protected:
    typedef WrapClass<wxwxMenuItemListNode>::ptr _parentclass_ptr;
    typedef wxwxMenuItemListNode ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxwxMenuItemListNode>& GetObj() const { return WrapClass<wxwxMenuItemListNode>::GetObj(); }

    /// Constructor
    WrapClass_wxwxMenuItemListNode(boost::shared_ptr<wxwxMenuItemListNode > si): 
    WrapClass<wxwxMenuItemListNode>(si)
    , WrapClass_wxNodeBase(si)
    {}

    /// Destructor
    ~WrapClass_wxwxMenuItemListNode()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxwxMenuItemListNode,"Constructor wxwxMenuItemListNode::wxwxMenuItemListNode(wxListBase * list = 0u, wxwxMenuItemListNode * previous = 0u, wxwxMenuItemListNode * next = 0u, wxMenuItem * data = 0u, wxListKey const & key = wxDefaultListKey) (http://docs.wxwidgets.org/stable/wx_wxwxmenuitemlistnode.html#wxwxmenuitemlistnode).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxwxMenuItemListNode*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetNext,"wxwxMenuItemListNode * wxwxMenuItemListNode::GetNext()  (http://docs.wxwidgets.org/stable/wx_wxwxmenuitemlistnode.html#getnext)")
    ADD_CLASS_METHOD(GetPrevious,"wxwxMenuItemListNode * wxwxMenuItemListNode::GetPrevious()  (http://docs.wxwidgets.org/stable/wx_wxwxmenuitemlistnode.html#getprevious)")
    ADD_CLASS_METHOD(GetData,"wxMenuItem * wxwxMenuItemListNode::GetData()  (http://docs.wxwidgets.org/stable/wx_wxwxmenuitemlistnode.html#getdata)")
    ADD_CLASS_METHOD(SetData,"void wxwxMenuItemListNode::SetData(wxMenuItem * data)  (http://docs.wxwidgets.org/stable/wx_wxwxmenuitemlistnode.html#setdata)")





    void AddMethods(WrapClass<wxwxMenuItemListNode>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxwxMenuItemListNode_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxwxMenuItemListNode_h
