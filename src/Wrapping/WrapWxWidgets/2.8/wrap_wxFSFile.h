/**
 * C++ Interface: wrap_wxFSFile
 *
 * Description: wrapping wxFSFile
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFSFile_h_
#define _wrap_wxFSFile_h_

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


#ifndef wxFSFile_declared
  #define wxFSFile_declared
  AMI_DECLARE_TYPE(wxFSFile);
#endif

// TODO: check for inheritence ...
class WrapClass_wxFSFile : public WrapClass<wxFSFile>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxFSFile);

  protected:
    typedef WrapClass<wxFSFile>::ptr _parentclass_ptr;
    typedef wxFSFile ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFSFile>& GetObj() const { return WrapClass<wxFSFile>::GetObj(); }

    /// Constructor
    WrapClass_wxFSFile(boost::shared_ptr<wxFSFile > si): 
    WrapClass<wxFSFile>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxFSFile()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFSFile,"Constructor wxFSFile::wxFSFile(wxInputStream * stream, wxString const & loc, wxString const & mimetype, wxString const & anchor, wxDateTime modif) (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#wxfsfile).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFSFile*);

    // Static methods
    



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(GetStream,"wxInputStream * wxFSFile::GetStream()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getstream)")
    ADD_CLASS_METHOD(DetachStream,"wxInputStream * wxFSFile::DetachStream()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#detachstream)")
    ADD_CLASS_METHOD(SetStream,"void wxFSFile::SetStream(wxInputStream * stream)  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#setstream)")
    ADD_CLASS_METHOD(GetMimeType,"wxString const & wxFSFile::GetMimeType()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getmimetype)")
    ADD_CLASS_METHOD(GetLocation,"wxString const & wxFSFile::GetLocation()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getlocation)")
    ADD_CLASS_METHOD(GetAnchor,"wxString const & wxFSFile::GetAnchor()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getanchor)")
    ADD_CLASS_METHOD(GetModificationTime,"wxDateTime wxFSFile::GetModificationTime()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getmodificationtime)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFSFile::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxfsfile.html#getclassinfo)")





    void AddMethods(WrapClass<wxFSFile>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFSFile_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxFSFile_h
