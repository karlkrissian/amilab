/**
 * C++ Interface: wrap_wxStaticBoxSizer
 *
 * Description: wrapping wxStaticBoxSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxStaticBoxSizer_h_
#define _wrap_wxStaticBoxSizer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxBoxSizer.h"


#ifndef wxStaticBoxSizer_declared
  #define wxStaticBoxSizer_declared
  AMI_DECLARE_TYPE(wxStaticBoxSizer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxStaticBoxSizer : public WrapClass<wxStaticBoxSizer>
    , public   WrapClass_wxBoxSizer
{
  DEFINE_CLASS(WrapClass_wxStaticBoxSizer);

  protected:
    typedef WrapClass<wxStaticBoxSizer>::ptr _parentclass_ptr;
    typedef wxStaticBoxSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxStaticBoxSizer>& GetObj() const { return WrapClass<wxStaticBoxSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxStaticBoxSizer(boost::shared_ptr<wxStaticBoxSizer > si): 
    WrapClass<wxStaticBoxSizer>(si)
    , WrapClass_wxBoxSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxStaticBoxSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBoxSizer_1,"Constructor wxStaticBoxSizer::wxStaticBoxSizer(wxStaticBox * box, int orient) (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#wxstaticboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBoxSizer,"Constructor wxStaticBoxSizer::wxStaticBoxSizer() (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#wxstaticboxsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxStaticBoxSizer_2,"Constructor wxStaticBoxSizer::wxStaticBoxSizer(int orient, wxWindow * win, wxString const & label = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#wxstaticboxsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxStaticBoxSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(RecalcSizes,"void wxStaticBoxSizer::RecalcSizes()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#recalcsizes)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxStaticBoxSizer::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#calcmin)")
    ADD_CLASS_METHOD(GetStaticBox,"wxStaticBox * wxStaticBoxSizer::GetStaticBox()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#getstaticbox)")
    ADD_CLASS_METHOD(ShowItems,"void wxStaticBoxSizer::ShowItems(bool show)  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#showitems)")
    ADD_CLASS_METHOD(Detach_1,"bool wxStaticBoxSizer::Detach(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach,"wxStaticBoxSizer::Detach()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach_2,"bool wxStaticBoxSizer::Detach(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach_3,"bool wxStaticBoxSizer::Detach(int index)  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#detach)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxStaticBoxSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxstaticboxsizer.html#getclassinfo)")





    void AddMethods(WrapClass<wxStaticBoxSizer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxStaticBoxSizer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxStaticBoxSizer_h
