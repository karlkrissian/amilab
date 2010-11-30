/**
 * C++ Interface: wrap_vtkCellTypes
 *
 * Description: wrapping vtkCellTypes
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkCellTypes_h_
#define _wrap_vtkCellTypes_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "vtk_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkObject.h"



AMI_DECLARE_TYPE(vtkCellTypes);

// TODO: check for inheritence ...
class WrapClass_vtkCellTypes : public WrapClass<vtkCellTypes>
    , public   WrapClass_vtkObject
{
  DEFINE_CLASS(WrapClass_vtkCellTypes);

  protected:
    typedef WrapClass<vtkCellTypes>::ptr _parentclass_ptr;
    typedef vtkCellTypes ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkCellTypes>& GetObj() const { return WrapClass<vtkCellTypes>::GetObj(); }

    /// Constructor
    WrapClass_vtkCellTypes(boost::shared_ptr<vtkCellTypes > si): 
    WrapClass<vtkCellTypes>(si)
    , WrapClass_vtkObject(si)
    {}

    /// Destructor
    ~WrapClass_vtkCellTypes()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkCellTypes*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkCellTypes * vtkCellTypes::New() (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkCellTypes::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkCellTypes * vtkCellTypes::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#safedowncast).");
    ADD_CLASS_STATICMETHOD(GetClassNameFromTypeId,"char const * vtkCellTypes::GetClassNameFromTypeId(int typeId) (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#getclassnamefromtypeid).");
    ADD_CLASS_STATICMETHOD(GetTypeIdFromClassName,"int vtkCellTypes::GetTypeIdFromClassName(char const * classname) (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#gettypeidfromclassname).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkCellTypes::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkCellTypes * vtkCellTypes::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkCellTypes::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#printself)")
*/
    ADD_CLASS_METHOD(Allocate,"int vtkCellTypes::Allocate(int sz = 512, int ext = 1000)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#allocate)")
    ADD_CLASS_METHOD(InsertCell,"void vtkCellTypes::InsertCell(int id, unsigned char type, int loc)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#insertcell)")
    ADD_CLASS_METHOD(InsertNextCell,"int vtkCellTypes::InsertNextCell(unsigned char type, int loc)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#insertnextcell)")
    ADD_CLASS_METHOD(SetCellTypes,"void vtkCellTypes::SetCellTypes(int ncells, vtkUnsignedCharArray * cellTypes, vtkIntArray * cellLocations)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#setcelltypes)")
    ADD_CLASS_METHOD(GetCellLocation,"int vtkCellTypes::GetCellLocation(int cellId)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#getcelllocation)")
    ADD_CLASS_METHOD(DeleteCell,"void vtkCellTypes::DeleteCell(vtkIdType cellId)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#deletecell)")
    ADD_CLASS_METHOD(GetNumberOfTypes,"int vtkCellTypes::GetNumberOfTypes()  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#getnumberoftypes)")
    ADD_CLASS_METHOD(IsType,"int vtkCellTypes::IsType(unsigned char type)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#istype)")
    ADD_CLASS_METHOD(InsertNextType,"int vtkCellTypes::InsertNextType(unsigned char type)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#insertnexttype)")
    ADD_CLASS_METHOD(GetCellType,"unsigned char vtkCellTypes::GetCellType(int cellId)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#getcelltype)")
    ADD_CLASS_METHOD(Squeeze,"void vtkCellTypes::Squeeze()  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#squeeze)")
    ADD_CLASS_METHOD(Reset,"void vtkCellTypes::Reset()  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#reset)")
    ADD_CLASS_METHOD(GetActualMemorySize,"long unsigned int vtkCellTypes::GetActualMemorySize()  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#getactualmemorysize)")
    ADD_CLASS_METHOD(DeepCopy,"void vtkCellTypes::DeepCopy(vtkCellTypes * src)  (http://docs.wxwidgets.org/stable/wx_vtkcelltypes.html#deepcopy)")





    void AddMethods(WrapClass<vtkCellTypes>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_vtkCellTypes_h
