/**
 * C++ Interface: wrap_vtkPolyDataMapper
 *
 * Description: wrapping vtkPolyDataMapper
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_vtkPolyDataMapper_h_
#define _wrap_vtkPolyDataMapper_h_

/*
#include "Variable.hpp"
#include "ami_object.h"
*/
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "paramlist.h"

#include "vtkPolyDataMapper.h"

// include what is needed for inheritence and for types ...

#include "wrap_vtkMapper.h"


#ifndef vtkPolyDataMapper_declared
  #define vtkPolyDataMapper_declared
  AMI_DECLARE_TYPE(vtkPolyDataMapper);
#endif

// TODO: check for inheritence ...
class WrapClass_vtkPolyDataMapper : public WrapClass<vtkPolyDataMapper>
    , public   WrapClass_vtkMapper
{
  DEFINE_CLASS(WrapClass_vtkPolyDataMapper);

  protected:
    typedef WrapClass<vtkPolyDataMapper>::ptr _parentclass_ptr;
    typedef vtkPolyDataMapper ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<vtkPolyDataMapper>& GetObj() const { return WrapClass<vtkPolyDataMapper>::GetObj(); }

    /// Constructor
    WrapClass_vtkPolyDataMapper(boost::shared_ptr<vtkPolyDataMapper > si): 
    WrapClass<vtkPolyDataMapper>(si)
    , WrapClass_vtkMapper(si)
    {}

    /// Destructor
    ~WrapClass_vtkPolyDataMapper()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( vtkPolyDataMapper*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(New,"vtkPolyDataMapper * vtkPolyDataMapper::New() (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#new).");
    ADD_CLASS_STATICMETHOD(IsTypeOf,"int vtkPolyDataMapper::IsTypeOf(char const * type) (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#istypeof).");
    ADD_CLASS_STATICMETHOD(SafeDownCast,"vtkPolyDataMapper * vtkPolyDataMapper::SafeDownCast(vtkObjectBase * o) (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#safedowncast).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(IsA,"int vtkPolyDataMapper::IsA(char const * type)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#isa)")
    ADD_CLASS_METHOD(NewInstance,"vtkPolyDataMapper * vtkPolyDataMapper::NewInstance()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#newinstance)")
/* The following types are missing: basic_ostream<char,std::char_traits<char> >
    ADD_CLASS_METHOD(PrintSelf,"void vtkPolyDataMapper::PrintSelf(ostream & os, vtkIndent indent)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#printself)")
*/
    ADD_CLASS_METHOD(Render,"void vtkPolyDataMapper::Render(vtkRenderer * ren, vtkActor * act)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#render)")
    ADD_CLASS_METHOD(SetInput,"void vtkPolyDataMapper::SetInput(vtkPolyData * in)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#setinput)")
    ADD_CLASS_METHOD(GetInput,"vtkPolyData * vtkPolyDataMapper::GetInput()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getinput)")
    ADD_CLASS_METHOD(Update,"void vtkPolyDataMapper::Update()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#update)")
    ADD_CLASS_METHOD(SetPiece,"void vtkPolyDataMapper::SetPiece(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#setpiece)")
    ADD_CLASS_METHOD(GetPiece,"int vtkPolyDataMapper::GetPiece()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getpiece)")
    ADD_CLASS_METHOD(SetNumberOfPieces,"void vtkPolyDataMapper::SetNumberOfPieces(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#setnumberofpieces)")
    ADD_CLASS_METHOD(GetNumberOfPieces,"int vtkPolyDataMapper::GetNumberOfPieces()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getnumberofpieces)")
    ADD_CLASS_METHOD(SetNumberOfSubPieces,"void vtkPolyDataMapper::SetNumberOfSubPieces(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#setnumberofsubpieces)")
    ADD_CLASS_METHOD(GetNumberOfSubPieces,"int vtkPolyDataMapper::GetNumberOfSubPieces()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getnumberofsubpieces)")
    ADD_CLASS_METHOD(SetGhostLevel,"void vtkPolyDataMapper::SetGhostLevel(int _arg)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#setghostlevel)")
    ADD_CLASS_METHOD(GetGhostLevel,"int vtkPolyDataMapper::GetGhostLevel()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getghostlevel)")
    ADD_CLASS_METHOD(GetBounds_1,"double * vtkPolyDataMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds,"vtkPolyDataMapper::GetBounds()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getbounds)")
    ADD_CLASS_METHOD(GetBounds_2,"void vtkPolyDataMapper::GetBounds(double * bounds)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#getbounds)")
    ADD_CLASS_METHOD(ShallowCopy,"void vtkPolyDataMapper::ShallowCopy(vtkAbstractMapper * m)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#shallowcopy)")
    ADD_CLASS_METHOD(MapDataArrayToVertexAttribute,"void vtkPolyDataMapper::MapDataArrayToVertexAttribute(char const * vertexAttributeName, char const * dataArrayName, int fieldAssociation, int componentno = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#mapdataarraytovertexattribute)")
    ADD_CLASS_METHOD(MapDataArrayToMultiTextureAttribute,"void vtkPolyDataMapper::MapDataArrayToMultiTextureAttribute(int unit, char const * dataArrayName, int fieldAssociation, int componentno = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#mapdataarraytomultitextureattribute)")
    ADD_CLASS_METHOD(RemoveVertexAttributeMapping,"void vtkPolyDataMapper::RemoveVertexAttributeMapping(char const * vertexAttributeName)  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#removevertexattributemapping)")
    ADD_CLASS_METHOD(RemoveAllVertexAttributeMappings,"void vtkPolyDataMapper::RemoveAllVertexAttributeMappings()  (http://docs.wxwidgets.org/stable/wx_vtkpolydatamapper.html#removeallvertexattributemappings)")





    void AddMethods(WrapClass<vtkPolyDataMapper>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClassvtkPolyDataMapper_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_vtkPolyDataMapper_h
