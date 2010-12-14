/**
 * C++ Interface: wrap_wxSizer
 *
 * Description: wrapping wxSizer
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxSizer_h_
#define _wrap_wxSizer_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"
#include "wrap_wxClientDataContainer.h"


#ifndef wxSizer_declared
  #define wxSizer_declared
  AMI_DECLARE_TYPE(wxSizer);
#endif

// TODO: check for inheritence ...
class WrapClass_wxSizer : public WrapClass<wxSizer>
    , public   WrapClass_wxObject, public   WrapClass_wxClientDataContainer
{
  DEFINE_CLASS(WrapClass_wxSizer);

  protected:
    typedef WrapClass<wxSizer>::ptr _parentclass_ptr;
    typedef wxSizer ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxSizer>& GetObj() const { return WrapClass<wxSizer>::GetObj(); }

    /// Constructor
    WrapClass_wxSizer(boost::shared_ptr<wxSizer > si): 
    WrapClass<wxSizer>(si)
    , WrapClass_wxObject(si), WrapClass_wxClientDataContainer(si)
    {}

    /// Destructor
    ~WrapClass_wxSizer()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxSizer*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(Add_1,"wxSizerItem * wxSizer::Add(wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add,"wxSizer::Add()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add_2,"wxSizerItem * wxSizer::Add(wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add_3,"wxSizerItem * wxSizer::Add(int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add_4,"wxSizerItem * wxSizer::Add(wxWindow * window, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add_5,"wxSizerItem * wxSizer::Add(wxSizer * sizer, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(Add_6,"wxSizerItem * wxSizer::Add(wxSizerItem * item)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#add)")
    ADD_CLASS_METHOD(AddSpacer,"wxSizerItem * wxSizer::AddSpacer(int size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#addspacer)")
    ADD_CLASS_METHOD(AddStretchSpacer,"wxSizerItem * wxSizer::AddStretchSpacer(int prop = 1)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#addstretchspacer)")
    ADD_CLASS_METHOD(Insert_1,"wxSizerItem * wxSizer::Insert(size_t index, wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert,"wxSizer::Insert()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert_2,"wxSizerItem * wxSizer::Insert(size_t index, wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert_3,"wxSizerItem * wxSizer::Insert(size_t index, int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert_4,"wxSizerItem * wxSizer::Insert(size_t index, wxWindow * window, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert_5,"wxSizerItem * wxSizer::Insert(size_t index, wxSizer * sizer, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(Insert_6,"wxSizerItem * wxSizer::Insert(size_t index, wxSizerItem * item)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insert)")
    ADD_CLASS_METHOD(InsertSpacer,"wxSizerItem * wxSizer::InsertSpacer(size_t index, int size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insertspacer)")
    ADD_CLASS_METHOD(InsertStretchSpacer,"wxSizerItem * wxSizer::InsertStretchSpacer(size_t index, int prop = 1)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#insertstretchspacer)")
    ADD_CLASS_METHOD(Prepend_1,"wxSizerItem * wxSizer::Prepend(wxWindow * window, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend,"wxSizer::Prepend()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend_2,"wxSizerItem * wxSizer::Prepend(wxSizer * sizer, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend_3,"wxSizerItem * wxSizer::Prepend(int width, int height, int proportion = 0, int flag = 0, int border = 0, wxObject * userData = 0l)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend_4,"wxSizerItem * wxSizer::Prepend(wxWindow * window, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend_5,"wxSizerItem * wxSizer::Prepend(wxSizer * sizer, wxSizerFlags const & flags)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(Prepend_6,"wxSizerItem * wxSizer::Prepend(wxSizerItem * item)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prepend)")
    ADD_CLASS_METHOD(PrependSpacer,"wxSizerItem * wxSizer::PrependSpacer(int size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prependspacer)")
    ADD_CLASS_METHOD(PrependStretchSpacer,"wxSizerItem * wxSizer::PrependStretchSpacer(int prop = 1)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#prependstretchspacer)")
    ADD_CLASS_METHOD(SetContainingWindow,"void wxSizer::SetContainingWindow(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setcontainingwindow)")
    ADD_CLASS_METHOD(GetContainingWindow,"wxWindow * wxSizer::GetContainingWindow()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getcontainingwindow)")
    ADD_CLASS_METHOD(Remove_1,"bool wxSizer::Remove(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#remove)")
    ADD_CLASS_METHOD(Remove,"wxSizer::Remove()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#remove)")
    ADD_CLASS_METHOD(Remove_2,"bool wxSizer::Remove(int index)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#remove)")
    ADD_CLASS_METHOD(Detach_1,"bool wxSizer::Detach(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach,"wxSizer::Detach()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach_2,"bool wxSizer::Detach(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#detach)")
    ADD_CLASS_METHOD(Detach_3,"bool wxSizer::Detach(int index)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#detach)")
    ADD_CLASS_METHOD(Replace_1,"bool wxSizer::Replace(wxWindow * oldwin, wxWindow * newwin, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#replace)")
    ADD_CLASS_METHOD(Replace,"wxSizer::Replace()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#replace)")
    ADD_CLASS_METHOD(Replace_2,"bool wxSizer::Replace(wxSizer * oldsz, wxSizer * newsz, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#replace)")
    ADD_CLASS_METHOD(Replace_3,"bool wxSizer::Replace(size_t index, wxSizerItem * newitem)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#replace)")
    ADD_CLASS_METHOD(Clear,"void wxSizer::Clear(bool delete_windows = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#clear)")
    ADD_CLASS_METHOD(DeleteWindows,"void wxSizer::DeleteWindows()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#deletewindows)")
    ADD_CLASS_METHOD(SetMinSize_1,"void wxSizer::SetMinSize(int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setminsize)")
    ADD_CLASS_METHOD(SetMinSize,"wxSizer::SetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setminsize)")
    ADD_CLASS_METHOD(SetMinSize_2,"void wxSizer::SetMinSize(wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_1,"bool wxSizer::SetItemMinSize(wxWindow * window, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize,"wxSizer::SetItemMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_2,"bool wxSizer::SetItemMinSize(wxWindow * window, wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_3,"bool wxSizer::SetItemMinSize(wxSizer * sizer, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_4,"bool wxSizer::SetItemMinSize(wxSizer * sizer, wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_5,"bool wxSizer::SetItemMinSize(size_t index, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(SetItemMinSize_6,"bool wxSizer::SetItemMinSize(size_t index, wxSize const & size)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setitemminsize)")
    ADD_CLASS_METHOD(GetSize,"wxSize wxSizer::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getsize)")
    ADD_CLASS_METHOD(GetPosition,"wxPoint wxSizer::GetPosition()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getposition)")
    ADD_CLASS_METHOD(GetMinSize,"wxSize wxSizer::GetMinSize()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getminsize)")
    ADD_CLASS_METHOD(Layout,"void wxSizer::Layout()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#layout)")
    ADD_CLASS_METHOD(ComputeFittingClientSize,"wxSize wxSizer::ComputeFittingClientSize(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#computefittingclientsize)")
    ADD_CLASS_METHOD(ComputeFittingWindowSize,"wxSize wxSizer::ComputeFittingWindowSize(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#computefittingwindowsize)")
    ADD_CLASS_METHOD(Fit,"wxSize wxSizer::Fit(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#fit)")
    ADD_CLASS_METHOD(FitInside,"void wxSizer::FitInside(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#fitinside)")
    ADD_CLASS_METHOD(SetSizeHints,"void wxSizer::SetSizeHints(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setsizehints)")
    ADD_CLASS_METHOD(SetVirtualSizeHints,"void wxSizer::SetVirtualSizeHints(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setvirtualsizehints)")
    ADD_CLASS_METHOD(GetChildren,"wxSizerItemList & wxSizer::GetChildren()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getchildren)")
    ADD_CLASS_METHOD(SetDimension,"void wxSizer::SetDimension(int x, int y, int width, int height)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#setdimension)")
    ADD_CLASS_METHOD(GetItem_1,"wxSizerItem * wxSizer::GetItem(wxWindow * window, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getitem)")
    ADD_CLASS_METHOD(GetItem,"wxSizer::GetItem()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getitem)")
    ADD_CLASS_METHOD(GetItem_2,"wxSizerItem * wxSizer::GetItem(wxSizer * sizer, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getitem)")
    ADD_CLASS_METHOD(GetItem_3,"wxSizerItem * wxSizer::GetItem(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getitem)")
    ADD_CLASS_METHOD(Show_1,"bool wxSizer::Show(wxWindow * window, bool show = true, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#show)")
    ADD_CLASS_METHOD(Show,"wxSizer::Show()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#show)")
    ADD_CLASS_METHOD(Show_2,"bool wxSizer::Show(wxSizer * sizer, bool show = true, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#show)")
    ADD_CLASS_METHOD(Show_3,"bool wxSizer::Show(size_t index, bool show = true)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#show)")
    ADD_CLASS_METHOD(Hide_1,"bool wxSizer::Hide(wxSizer * sizer, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#hide)")
    ADD_CLASS_METHOD(Hide,"wxSizer::Hide()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#hide)")
    ADD_CLASS_METHOD(Hide_2,"bool wxSizer::Hide(wxWindow * window, bool recursive = false)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#hide)")
    ADD_CLASS_METHOD(Hide_3,"bool wxSizer::Hide(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#hide)")
    ADD_CLASS_METHOD(IsShown_1,"bool wxSizer::IsShown(wxWindow * window)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#isshown)")
    ADD_CLASS_METHOD(IsShown,"wxSizer::IsShown()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#isshown)")
    ADD_CLASS_METHOD(IsShown_2,"bool wxSizer::IsShown(wxSizer * sizer)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#isshown)")
    ADD_CLASS_METHOD(IsShown_3,"bool wxSizer::IsShown(size_t index)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#isshown)")
    ADD_CLASS_METHOD(ShowItems,"void wxSizer::ShowItems(bool show)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#showitems)")
    ADD_CLASS_METHOD(Show_4,"void wxSizer::Show(bool show)  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#show)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxSizer::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxsizer.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxSizer & wxSizer::operator =(wxSizer const & param0) (http://docs.wxwidgets.org/stable/wx_wxsizer.html#__assign__)")




    void AddMethods(WrapClass<wxSizer>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxSizer_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxSizer_h
