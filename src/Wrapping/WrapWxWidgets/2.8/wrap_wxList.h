/**
 * C++ Interface: wrap_wxList
 *
 * Description: wrapping wxList
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxList_h_
#define _wrap_wxList_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/wx.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObjectList.h"


AMI_DECLARE_TYPE(wxList);

// TODO: check for inheritence ...
class WrapClass_wxList : public WrapClass<wxList>
    , public   WrapClass_wxObjectList
{
  DEFINE_CLASS(WrapClass_wxList);

  protected:
    typedef WrapClass<wxList>::ptr _parentclass_ptr;
    typedef wxList ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxList>& GetObj() const { return WrapClass<wxList>::GetObj(); }

    /// Constructor
    WrapClass_wxList(boost::shared_ptr<wxList > si): 
    WrapClass<wxList>(si)
    , WrapClass_wxObjectList(si)
    {}

    /// Destructor
    ~WrapClass_wxList()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxList_1,"Constructor wxList::wxList(wxList const & param0) (http://docs.wxwidgets.org/stable/wx_wxlist.html#wxlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxList,"Constructor wxList::wxList() (http://docs.wxwidgets.org/stable/wx_wxlist.html#wxlist).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxList_2,"Constructor wxList::wxList(int key_type = wxKEY_NONE) (http://docs.wxwidgets.org/stable/wx_wxlist.html#wxlist).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxList*);

    // Static methods
    



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
/* The following types are missing: _9505
    ADD_CLASS_METHOD(Sort,"void wxList::Sort(wxSortCompareFunction compfunc)  (http://docs.wxwidgets.org/stable/wx_wxlist.html#sort)")
*/
    ADD_CLASS_METHOD(Member,"wxNode * wxList::Member(wxObject * object)  (http://docs.wxwidgets.org/stable/wx_wxlist.html#member)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxList::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxlist.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxList & wxList::operator =(wxList const & list) (http://docs.wxwidgets.org/stable/wx_wxlist.html#__assign__)")




    void AddMethods(WrapClass<wxList>::ptr this_ptr );

};


#endif // _wrap_wxList_h
