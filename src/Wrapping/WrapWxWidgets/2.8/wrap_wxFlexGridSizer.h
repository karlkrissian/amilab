/**
 * C++ Interface: wrap_wxFlexGridSizer
 *
 * Description: wrapping wxFlexGridSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFlexGridSizer_h_
#define _wrap_wxFlexGridSizer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxGridSizer.h"


#ifndef wxFlexGridSizer_declared
  #define wxFlexGridSizer_declared
  AMI_DECLARE_TYPE(wxFlexGridSizer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxFlexGridSizer : public WrapClass<wxFlexGridSizer>
    , public   WrapClass_wxGridSizer
{
  DEFINE_CLASS(WrapClass_wxFlexGridSizer);

  protected:
    typedef WrapClass<wxFlexGridSizer>::ptr _parentclass_ptr;
    typedef wxFlexGridSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFlexGridSizer>& GetObj() const { return WrapClass<wxFlexGridSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxFlexGridSizer(boost::shared_ptr<wxFlexGridSizer > si): 
    WrapClass<wxFlexGridSizer>(si)
    , WrapClass_wxGridSizer(si)
    {}

    /// Destructor
    ~WrapClass_wxFlexGridSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFlexGridSizer_1,"Constructor wxFlexGridSizer::wxFlexGridSizer(int rows, int cols, int vgap, int hgap) (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#wxflexgridsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFlexGridSizer,"Constructor wxFlexGridSizer::wxFlexGridSizer() (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#wxflexgridsizer).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFlexGridSizer_2,"Constructor wxFlexGridSizer::wxFlexGridSizer(int cols, int vgap = 0, int hgap = 0) (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#wxflexgridsizer).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFlexGridSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(AddGrowableRow,"void wxFlexGridSizer::AddGrowableRow(size_t idx, int proportion = 0)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#addgrowablerow)")
    ADD_CLASS_METHOD(RemoveGrowableRow,"void wxFlexGridSizer::RemoveGrowableRow(size_t idx)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#removegrowablerow)")
    ADD_CLASS_METHOD(AddGrowableCol,"void wxFlexGridSizer::AddGrowableCol(size_t idx, int proportion = 0)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#addgrowablecol)")
    ADD_CLASS_METHOD(RemoveGrowableCol,"void wxFlexGridSizer::RemoveGrowableCol(size_t idx)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#removegrowablecol)")
    ADD_CLASS_METHOD(SetFlexibleDirection,"void wxFlexGridSizer::SetFlexibleDirection(int direction)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#setflexibledirection)")
    ADD_CLASS_METHOD(GetFlexibleDirection,"int wxFlexGridSizer::GetFlexibleDirection()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#getflexibledirection)")
    ADD_CLASS_METHOD(SetNonFlexibleGrowMode,"void wxFlexGridSizer::SetNonFlexibleGrowMode(wxFlexSizerGrowMode mode)  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#setnonflexiblegrowmode)")
    ADD_CLASS_METHOD(GetNonFlexibleGrowMode,"wxFlexSizerGrowMode wxFlexGridSizer::GetNonFlexibleGrowMode()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#getnonflexiblegrowmode)")
    ADD_CLASS_METHOD(GetRowHeights,"wxArrayInt const & wxFlexGridSizer::GetRowHeights()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#getrowheights)")
    ADD_CLASS_METHOD(GetColWidths,"wxArrayInt const & wxFlexGridSizer::GetColWidths()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#getcolwidths)")
    ADD_CLASS_METHOD(RecalcSizes,"void wxFlexGridSizer::RecalcSizes()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#recalcsizes)")
    ADD_CLASS_METHOD(CalcMin,"wxSize wxFlexGridSizer::CalcMin()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#calcmin)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFlexGridSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxflexgridsizer.html#getclassinfo)")





    void AddMethods(WrapClass<wxFlexGridSizer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFlexGridSizer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxFlexGridSizer_h
