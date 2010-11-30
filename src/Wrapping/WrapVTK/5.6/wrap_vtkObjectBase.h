/**
 * C++ Interface: wrap_vtkObjectBase
 *
 * Description: wrapping vtkObjectBase
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkObjectBase_h_
#define _wrap_vtkObjectBase_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(vtkObjectBase);

// TODO: check for inheritence ...
class WrapClass_vtkObjectBase : public WrapClass<vtkObjectBase>
    
{
  DEFINE_CLASS(WrapClass_vtkObjectBase);

  protected:
    typedef WrapClass<vtkObjectBase>::ptr _parentclass_ptr;
    typedef vtkObjectBase ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkObjectBase>& GetObj() const { return WrapClass<vtkObjectBase>::GetObj(); }

    /// Constructor
    WrapClass_vtkObjectBase(boost::shared_ptr<vtkObjectBase > si): 
    WrapClass<vtkObjectBase>(si)
    
    {}

    /// Destructor
    ~WrapClass_vtkObjectBase()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkObjectBase*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkObjectBase::IsTypeOf(char const * name) (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#istypeof).");
    ADD_CLASS_STATICMETHOD(New,"vtkObjectBase * vtkObjectBase::New() (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#new).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetClassName,"char const * vtkObjectBase::GetClassName()  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#getclassname)")
    ADD_CLASS_METHOD(IsA,"int vtkObjectBase::IsA(char const * name)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#isa)")
    ADD_CLASS_METHOD(Delete,"void vtkObjectBase::Delete()  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#delete)")
    ADD_CLASS_METHOD(FastDelete,"void vtkObjectBase::FastDelete()  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#fastdelete)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(Print,"void vtkObjectBase::Print(ostream & os)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#print)")
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkObjectBase::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#printself)")
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintHeader,"void vtkObjectBase::PrintHeader(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#printheader)")
*/
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintTrailer,"void vtkObjectBase::PrintTrailer(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#printtrailer)")
*/
    ADD_CLASS_METHOD(Register,"void vtkObjectBase::Register(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#register)")
    ADD_CLASS_METHOD(UnRegister,"void vtkObjectBase::UnRegister(vtkObjectBase * o)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#unregister)")
    ADD_CLASS_METHOD(GetReferenceCount,"int vtkObjectBase::GetReferenceCount()  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#getreferencecount)")
    ADD_CLASS_METHOD(SetReferenceCount,"void vtkObjectBase::SetReferenceCount(int param0)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#setreferencecount)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintRevisions,"void vtkObjectBase::PrintRevisions(ostream & os)  (http://docs.wxwidgets.org/stable/wx_vtkobjectbase.html#printrevisions)")
*/





    void AddMethods(WrapClass<vtkObjectBase>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkObjectBase_h
