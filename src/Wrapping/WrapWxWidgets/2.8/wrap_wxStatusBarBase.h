/**
 * C++ Interface: wrap_wxStatusBarBase
 *
 * Description: wrapping wxStatusBarBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStatusBarBase_h_
#define _wrap_wxStatusBarBase_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxWindow.h"


#ifndef wxStatusBarBase_declared
  #define wxStatusBarBase_declared
  AMI_DECLARE_TYPE(wxStatusBarBase);
#endif

// TODO: check for inheritence ...
class WrapClass_wxStatusBarBase : public WrapClass<wxStatusBarBase>
    , public   WrapClass_wxWindow
{
  DEFINE_CLASS(WrapClass_wxStatusBarBase);

  protected:
    typedef WrapClass<wxStatusBarBase>::ptr _parentclass_ptr;
    typedef wxStatusBarBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStatusBarBase>& GetObj() const { return WrapClass<wxStatusBarBase>::GetObj(); }

    /// Constructor
    WrapClass_wxStatusBarBase(boost::shared_ptr<wxStatusBarBase > si): 
    WrapClass<wxStatusBarBase>(si)
    , WrapClass_wxWindow(si)
    {}

    /// Destructor
    ~WrapClass_wxStatusBarBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStatusBarBase*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(SetFieldsCount,"void wxStatusBarBase::SetFieldsCount(int number = 1, int const * widths = 0l)  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#setfieldscount)")
    ADD_CLASS_METHOD(GetFieldsCount,"int wxStatusBarBase::GetFieldsCount()  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#getfieldscount)")
    ADD_CLASS_METHOD(PushStatusText,"void wxStatusBarBase::PushStatusText(wxString const & text, int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#pushstatustext)")
    ADD_CLASS_METHOD(PopStatusText,"void wxStatusBarBase::PopStatusText(int number = 0)  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#popstatustext)")
    ADD_CLASS_METHOD(SetStatusWidths,"void wxStatusBarBase::SetStatusWidths(int n, int const * widths)  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#setstatuswidths)")
    ADD_CLASS_METHOD(SetStatusStyles,"void wxStatusBarBase::SetStatusStyles(int n, int const * styles)  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#setstatusstyles)")
    ADD_CLASS_METHOD(AcceptsFocus,"bool wxStatusBarBase::AcceptsFocus()  (http://docs.wxwidgets.org/stable/wx_wxstatusbarbase.html#acceptsfocus)")





    void AddMethods(WrapClass<wxStatusBarBase>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStatusBarBase_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxStatusBarBase_h
