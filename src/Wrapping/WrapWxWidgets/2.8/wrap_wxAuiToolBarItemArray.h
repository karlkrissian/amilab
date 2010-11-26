/**
 * C++ Interface: wrap_wxAuiToolBarItemArray
 *
 * Description: wrapping wxAuiToolBarItemArray
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxAuiToolBarItemArray_h_
#define _wrap_wxAuiToolBarItemArray_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx/aui/aui.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxAuiToolBarItemArray);

// TODO: check for inheritence ...
class WrapClass_wxAuiToolBarItemArray : public WrapClass<wxAuiToolBarItemArray>
    
{
  DEFINE_CLASS(WrapClass_wxAuiToolBarItemArray);

  protected:
    typedef WrapClass<wxAuiToolBarItemArray>::ptr _parentclass_ptr;
    typedef wxAuiToolBarItemArray ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxAuiToolBarItemArray>& GetObj() const { return WrapClass<wxAuiToolBarItemArray>::GetObj(); }

    /// Constructor
    WrapClass_wxAuiToolBarItemArray(boost::shared_ptr<wxAuiToolBarItemArray > si): 
    WrapClass<wxAuiToolBarItemArray>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxAuiToolBarItemArray()
    {
      std::cout << "~WrapClass_wxAuiToolBarItemArray()" << std::endl;
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItemArray,"Wrapping of wxAuiToolBarItemArray.");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxAuiToolBarItemArray1,"Wrapping of wxAuiToolBarItemArray.");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxAuiToolBarItemArray*);

    // here add each method
    
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Alloc,"")
*/
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(GetCount,"")
*/
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(size,"")
*/
    ADD_CLASS_METHOD(IsEmpty,"")
    ADD_CLASS_METHOD(empty,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Count,"")
*/
    ADD_CLASS_METHOD(Shrink,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Item,"")
*/
    ADD_CLASS_METHOD(Last,"")
    ADD_CLASS_METHOD(Index,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Add,"")
*/
    ADD_CLASS_METHOD(Add1,"")
    ADD_CLASS_METHOD(push_back,"")
    ADD_CLASS_METHOD(push_back1,"")
/* The following types are missing: long unsigned int, long unsigned int
    ADD_CLASS_METHOD(Insert,"")
*/
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Insert1,"")
*/
    ADD_CLASS_METHOD(Empty,"")
    ADD_CLASS_METHOD(Clear,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(Detach,"")
*/
/* The following types are missing: long unsigned int, long unsigned int
    ADD_CLASS_METHOD(RemoveAt,"")
*/
/* The following types are missing: _9596
    ADD_CLASS_METHOD(Sort,"")
*/

    // Operators:
    ADD_CLASS_METHOD(assign,"")
/* The following types are missing: long unsigned int
    ADD_CLASS_METHOD(at,"")
*/




    void AddMethods(WrapClass<wxAuiToolBarItemArray>::ptr this_ptr )
    {
      // here inheritence
      


      // check that the method name is not a token
      
/* The following types are missing: long unsigned int
      AddVar_Alloc( this_ptr);
*/
/* The following types are missing: long unsigned int
      AddVar_GetCount( this_ptr);
*/
/* The following types are missing: long unsigned int
      AddVar_size( this_ptr);
*/
      AddVar_IsEmpty( this_ptr);
      AddVar_empty( this_ptr);
/* The following types are missing: long unsigned int
      AddVar_Count( this_ptr);
*/
      AddVar_Shrink( this_ptr);
/* The following types are missing: long unsigned int
      AddVar_Item( this_ptr);
*/
      AddVar_Last( this_ptr);
      AddVar_Index( this_ptr);
/* The following types are missing: long unsigned int
      AddVar_Add( this_ptr);
*/
      AddVar_Add1( this_ptr);
      AddVar_push_back( this_ptr);
      AddVar_push_back1( this_ptr);
/* The following types are missing: long unsigned int, long unsigned int
      AddVar_Insert( this_ptr);
*/
/* The following types are missing: long unsigned int
      AddVar_Insert1( this_ptr);
*/
      AddVar_Empty( this_ptr);
      AddVar_Clear( this_ptr);
/* The following types are missing: long unsigned int
      AddVar_Detach( this_ptr);
*/
/* The following types are missing: long unsigned int, long unsigned int
      AddVar_RemoveAt( this_ptr);
*/
/* The following types are missing: _9596
      AddVar_Sort( this_ptr);
*/

      // Operators:
      AddVar_assign( this_ptr);
/* The following types are missing: long unsigned int
      AddVar_at( this_ptr);
*/


    };
};


#endif // _wrap_wxAuiToolBarItemArray_h
