/**
 * C++ Interface: wrap_wxFileSystem
 *
 * Description: wrapping wxFileSystem
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFileSystem_h_
#define _wrap_wxFileSystem_h_

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


#ifndef wxFileSystem_declared
  #define wxFileSystem_declared
  AMI_DECLARE_TYPE(wxFileSystem);
#endif

// TODO: check for inheritence ...
class WrapClass_wxFileSystem : public WrapClass<wxFileSystem>
    , public   WrapClass_wxObject
{
  DEFINE_CLASS(WrapClass_wxFileSystem);

  protected:
    typedef WrapClass<wxFileSystem>::ptr _parentclass_ptr;
    typedef wxFileSystem ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFileSystem>& GetObj() const { return WrapClass<wxFileSystem>::GetObj(); }

    /// Constructor
    WrapClass_wxFileSystem(boost::shared_ptr<wxFileSystem > si): 
    WrapClass<wxFileSystem>(si)
    , WrapClass_wxObject(si)
    {}

    /// Destructor
    ~WrapClass_wxFileSystem()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileSystem,"Constructor wxFileSystem::wxFileSystem() (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#wxfilesystem).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFileSystem*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(AddHandler,"void wxFileSystem::AddHandler(wxFileSystemHandler * handler) (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#addhandler).");
    ADD_CLASS_STATICMETHOD(RemoveHandler,"wxFileSystemHandler * wxFileSystem::RemoveHandler(wxFileSystemHandler * handler) (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#removehandler).");
    ADD_CLASS_STATICMETHOD(HasHandlerForPath,"bool wxFileSystem::HasHandlerForPath(wxString const & location) (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#hashandlerforpath).");
    ADD_CLASS_STATICMETHOD(CleanUpHandlers,"void wxFileSystem::CleanUpHandlers() (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#cleanuphandlers).");
    ADD_CLASS_STATICMETHOD(URLToFileName,"wxFileName wxFileSystem::URLToFileName(wxString const & url) (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#urltofilename).");
    ADD_CLASS_STATICMETHOD(FileNameToURL,"wxString wxFileSystem::FileNameToURL(wxFileName const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#filenametourl).");



    // Standard methods
    
    // Adding standard methods
    ADD_CLASS_METHOD(ChangePathTo,"void wxFileSystem::ChangePathTo(wxString const & location, bool is_dir = false)  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#changepathto)")
    ADD_CLASS_METHOD(GetPath,"wxString wxFileSystem::GetPath()  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#getpath)")
    ADD_CLASS_METHOD(OpenFile,"wxFSFile * wxFileSystem::OpenFile(wxString const & location, int flags = wxFS_READ)  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#openfile)")
    ADD_CLASS_METHOD(FindFirst,"wxString wxFileSystem::FindFirst(wxString const & spec, int flags = 0)  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#findfirst)")
    ADD_CLASS_METHOD(FindNext,"wxString wxFileSystem::FindNext()  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#findnext)")
    ADD_CLASS_METHOD(FindFileInPath,"bool wxFileSystem::FindFileInPath(wxString * pStr, wxChar const * path, wxChar const * file)  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#findfileinpath)")
    ADD_CLASS_METHOD(GetClassInfo,"wxClassInfo * wxFileSystem::GetClassInfo()  (http://docs.wxwidgets.org/stable/wx_wxfilesystem.html#getclassinfo)")





    void AddMethods(WrapClass<wxFileSystem>::ptr this_ptr );
    

};

/*
  * Adds the constructor and the static methods to the given context
  */
void WrapClasswxFileSystem_AddStaticMethods( Variables::ptr& context);


#endif // _wrap_wxFileSystem_h
