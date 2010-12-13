/**
 * C++ Interface: wrap_wxImageHandler
 *
 * Description: wrapping wxImageHandler
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxImageHandler_h_
#define _wrap_wxImageHandler_h_

/*
#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"
*/

#include "wx_includes.h"

// include what is needed for inheritence and for types ...

#include "wrap_wxObject.h"


#ifndef wxImageHandler_declared
  #define wxImageHandler_declared
  AMI_DECLARE_TYPE(wxImageHandler);
#endif

// TODO: check for inheritence ...
class WrapClass_wxImageHandler : public WrapClass<wxImageHandler>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxImageHandler);

  protected:
    typedef WrapClass<wxImageHandler>::ptr _parentclass_ptr;
    typedef wxImageHandler ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxImageHandler>& GetObj() const { return WrapClass<wxImageHandler>::GetObj(); }

    /// Constructor
    WrapClass_wxImageHandler(boost::shared_ptr<wxImageHandler > si): 
    WrapClass<wxImageHandler>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxImageHandler()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    


    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxImageHandler*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(LoadFile,"bool wxImageHandler::LoadFile(wxImage * image, wxInputStream & stream, bool verbose = true, int index = -0x00000000000000001)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#loadfile)")
    ADD_CLASS_METHOD(SaveFile,"bool wxImageHandler::SaveFile(wxImage * image, wxOutputStream & stream, bool verbose = true)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#savefile)")
    ADD_CLASS_METHOD(GetImageCount,"int wxImageHandler::GetImageCount(wxInputStream & stream)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#getimagecount)")
    ADD_CLASS_METHOD(CanRead_1,"bool wxImageHandler::CanRead(wxInputStream & stream)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#canread)")
    ADD_CLASS_METHOD(CanRead,"wxImageHandler::CanRead()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#canread)")
    ADD_CLASS_METHOD(CanRead_2,"bool wxImageHandler::CanRead(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#canread)")
    ADD_CLASS_METHOD(SetName,"void wxImageHandler::SetName(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#setname)")
    ADD_CLASS_METHOD(SetExtension,"void wxImageHandler::SetExtension(wxString const & ext)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#setextension)")
    ADD_CLASS_METHOD(SetType,"void wxImageHandler::SetType(long int type)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#settype)")
    ADD_CLASS_METHOD(SetMimeType,"void wxImageHandler::SetMimeType(wxString const & type)  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#setmimetype)")
    ADD_CLASS_METHOD(GetName,"wxString const & wxImageHandler::GetName()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#getname)")
    ADD_CLASS_METHOD(GetExtension,"wxString const & wxImageHandler::GetExtension()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#getextension)")
    ADD_CLASS_METHOD(GetType,"long int wxImageHandler::GetType()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#gettype)")
    ADD_CLASS_METHOD(GetMimeType,"wxString const & wxImageHandler::GetMimeType()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#getmimetype)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxImageHandler::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#getclassinfo)")

    // Operators:
    ADD_CLASS_METHOD(__assign__,            "wxImageHandler & wxImageHandler::operator =(wxImageHandler const & param0) (http://docs.wxwidgets.org/stable/wx_wximagehandler.html#__assign__)")




    void AddMethods(WrapClass<wxImageHandler>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxImageHandler_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxImageHandler_h
