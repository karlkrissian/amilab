/**
 * C++ Interface: wrap_wxFileName
 *
 * Description: wrapping wxFileName
 * File generated automatically
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_wxFileName_h_
#define _wrap_wxFileName_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "wx_includes.h"

// include what is needed for inheritence and for types ...




AMI_DECLARE_TYPE(wxFileName);

// TODO: check for inheritence ...
class WrapClass_wxFileName : public WrapClass<wxFileName>
    
{
  DEFINE_CLASS(WrapClass_wxFileName);

  protected:
    typedef WrapClass<wxFileName>::ptr _parentclass_ptr;
    typedef wxFileName ObjectType;

  public:
    // resolve ambiguity
    const boost::shared_ptr<wxFileName>& GetObj() const { return WrapClass<wxFileName>::GetObj(); }

    /// Constructor
    WrapClass_wxFileName(boost::shared_ptr<wxFileName > si): 
    WrapClass<wxFileName>(si)
    
    {}

    /// Destructor
    ~WrapClass_wxFileName()
    {
      CLASS_MESSAGE("*** Destroying ***");
    }

    
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_1,"Constructor wxFileName::wxFileName() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName,"Constructor wxFileName::wxFileName() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_2,"Constructor wxFileName::wxFileName(wxFileName const & filepath) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_3,"Constructor wxFileName::wxFileName(wxString const & fullpath, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_4,"Constructor wxFileName::wxFileName(wxString const & path, wxString const & name, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_5,"Constructor wxFileName::wxFileName(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");
    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR(wxFileName_6,"Constructor wxFileName::wxFileName(wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#wxfilename).");



    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFileName*);

    // Static methods
    
    ADD_CLASS_STATICMETHOD(FileName,"wxFileName wxFileName::FileName(wxString const & file, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#filename).");
    ADD_CLASS_STATICMETHOD(DirName,"wxFileName wxFileName::DirName(wxString const & dir, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#dirname).");
    ADD_CLASS_STATICMETHOD(FileExists,"bool wxFileName::FileExists(wxString const & file) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#fileexists).");
    ADD_CLASS_STATICMETHOD(DirExists,"bool wxFileName::DirExists(wxString const & dir) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#direxists).");
    ADD_CLASS_STATICMETHOD(IsDirWritable,"bool wxFileName::IsDirWritable(wxString const & path) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isdirwritable).");
    ADD_CLASS_STATICMETHOD(IsDirReadable,"bool wxFileName::IsDirReadable(wxString const & path) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isdirreadable).");
    ADD_CLASS_STATICMETHOD(IsFileWritable,"bool wxFileName::IsFileWritable(wxString const & path) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfilewritable).");
    ADD_CLASS_STATICMETHOD(IsFileReadable,"bool wxFileName::IsFileReadable(wxString const & path) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfilereadable).");
    ADD_CLASS_STATICMETHOD(IsFileExecutable,"bool wxFileName::IsFileExecutable(wxString const & path) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfileexecutable).");
    ADD_CLASS_STATICMETHOD(GetCwd,"wxString wxFileName::GetCwd(wxString const & volume = wxEmptyString) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getcwd).");
    ADD_CLASS_STATICMETHOD(SetCwd,"bool wxFileName::SetCwd(wxString const & cwd) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setcwd).");
    ADD_CLASS_STATICMETHOD(GetHomeDir,"wxString wxFileName::GetHomeDir() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#gethomedir).");
    ADD_CLASS_STATICMETHOD(GetTempDir,"wxString wxFileName::GetTempDir() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#gettempdir).");
    ADD_CLASS_STATICMETHOD(CreateTempFileName_1,"wxString wxFileName::CreateTempFileName(wxString const & prefix) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#createtempfilename).");
    ADD_CLASS_STATICMETHOD(CreateTempFileName,"wxFileName::CreateTempFileName() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#createtempfilename).");
    /* The following types are missing: wxFile
    ADD_CLASS_STATICMETHOD(CreateTempFileName_2,"wxString wxFileName::CreateTempFileName(wxString const & prefix, wxFile * fileTemp) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#createtempfilename).");
    */
    /* The following types are missing: wxFFile
    ADD_CLASS_STATICMETHOD(CreateTempFileName_3,"wxString wxFileName::CreateTempFileName(wxString const & prefix, wxFFile * fileTemp) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#createtempfilename).");
    */
    ADD_CLASS_STATICMETHOD(Mkdir,"bool wxFileName::Mkdir(wxString const & dir, int perm = 511, int flags = 0) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#mkdir).");
    ADD_CLASS_STATICMETHOD(Rmdir,"bool wxFileName::Rmdir(wxString const & dir) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#rmdir).");
    ADD_CLASS_STATICMETHOD(IsCaseSensitive,"bool wxFileName::IsCaseSensitive(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#iscasesensitive).");
    ADD_CLASS_STATICMETHOD(GetForbiddenChars,"wxString wxFileName::GetForbiddenChars(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getforbiddenchars).");
    ADD_CLASS_STATICMETHOD(GetVolumeSeparator,"wxString wxFileName::GetVolumeSeparator(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getvolumeseparator).");
    ADD_CLASS_STATICMETHOD(GetPathSeparators,"wxString wxFileName::GetPathSeparators(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpathseparators).");
    ADD_CLASS_STATICMETHOD(GetPathTerminators,"wxString wxFileName::GetPathTerminators(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpathterminators).");
    ADD_CLASS_STATICMETHOD(GetPathSeparator,"wxChar wxFileName::GetPathSeparator(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpathseparator).");
    ADD_CLASS_STATICMETHOD(IsPathSeparator,"bool wxFileName::IsPathSeparator(wxChar ch, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#ispathseparator).");
    ADD_CLASS_STATICMETHOD(GetFormat,"wxPathFormat wxFileName::GetFormat(wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getformat).");
    ADD_CLASS_STATICMETHOD(SplitPath_1,"void wxFileName::SplitPath(wxString const & fullpath, wxString * volume, wxString * path, wxString * name, wxString * ext, bool * hasExt = 0l, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#splitpath).");
    ADD_CLASS_STATICMETHOD(SplitPath,"wxFileName::SplitPath() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#splitpath).");
    ADD_CLASS_STATICMETHOD(SplitPath_2,"void wxFileName::SplitPath(wxString const & fullpath, wxString * volume, wxString * path, wxString * name, wxString * ext, wxPathFormat format) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#splitpath).");
    ADD_CLASS_STATICMETHOD(SplitPath_3,"void wxFileName::SplitPath(wxString const & fullpath, wxString * path, wxString * name, wxString * ext, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#splitpath).");
    ADD_CLASS_STATICMETHOD(SplitVolume,"void wxFileName::SplitVolume(wxString const & fullpathWithVolume, wxString * volume, wxString * path, wxPathFormat format = wxPATH_NATIVE) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#splitvolume).");
    ADD_CLASS_STATICMETHOD(StripExtension,"wxString wxFileName::StripExtension(wxString const & fullpath) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#stripextension).");
    /* The following types are missing: wxULongLongNative
    ADD_CLASS_STATICMETHOD(GetSize,"wxULongLong wxFileName::GetSize(wxString const & file) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getsize).");
    */
    /* The following types are missing: wxULongLongNative
    ADD_CLASS_STATICMETHOD(GetHumanReadableSize,"wxString wxFileName::GetHumanReadableSize(wxULongLong const & sz, wxString const & nullsize = wxGetTranslation(((const wchar_t*)'Not available'), 0u), int precision = 1) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#gethumanreadablesize).");
    */



    // Standard methods
    
    // Adding copy method
    ADD_CLASS_METHOD(__copy__,"Copy method, uses the copy constructor.");
    // Adding standard methods
    ADD_CLASS_METHOD(Assign_1,"void wxFileName::Assign(wxFileName const & filepath)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign,"wxFileName::Assign()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign_2,"void wxFileName::Assign(wxString const & fullpath, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign_3,"void wxFileName::Assign(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, bool hasExt, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign_4,"void wxFileName::Assign(wxString const & volume, wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign_5,"void wxFileName::Assign(wxString const & path, wxString const & name, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(Assign_6,"void wxFileName::Assign(wxString const & path, wxString const & name, wxString const & ext, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assign)")
    ADD_CLASS_METHOD(AssignDir,"void wxFileName::AssignDir(wxString const & dir, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigndir)")
    ADD_CLASS_METHOD(Clear,"void wxFileName::Clear()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#clear)")
    ADD_CLASS_METHOD(IsOk,"bool wxFileName::IsOk()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isok)")
    ADD_CLASS_METHOD(FileExists,"bool wxFileName::FileExists()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#fileexists)")
    ADD_CLASS_METHOD(DirExists,"bool wxFileName::DirExists()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#direxists)")
    ADD_CLASS_METHOD(IsDirWritable,"bool wxFileName::IsDirWritable()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isdirwritable)")
    ADD_CLASS_METHOD(IsDirReadable,"bool wxFileName::IsDirReadable()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isdirreadable)")
    ADD_CLASS_METHOD(IsFileWritable,"bool wxFileName::IsFileWritable()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfilewritable)")
    ADD_CLASS_METHOD(IsFileReadable,"bool wxFileName::IsFileReadable()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfilereadable)")
    ADD_CLASS_METHOD(IsFileExecutable,"bool wxFileName::IsFileExecutable()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isfileexecutable)")
/* The following types are missing: wxDateTime, wxDateTime, wxDateTime
    ADD_CLASS_METHOD(SetTimes,"bool wxFileName::SetTimes(wxDateTime const * dtAccess, wxDateTime const * dtMod, wxDateTime const * dtCreate)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#settimes)")
*/
    ADD_CLASS_METHOD(Touch,"bool wxFileName::Touch()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#touch)")
/* The following types are missing: wxDateTime, wxDateTime, wxDateTime
    ADD_CLASS_METHOD(GetTimes,"bool wxFileName::GetTimes(wxDateTime * dtAccess, wxDateTime * dtMod, wxDateTime * dtCreate)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#gettimes)")
*/
/* The following types are missing: wxDateTime
    ADD_CLASS_METHOD(GetModificationTime,"wxDateTime wxFileName::GetModificationTime()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getmodificationtime)")
*/
    ADD_CLASS_METHOD(AssignCwd,"void wxFileName::AssignCwd(wxString const & volume = wxEmptyString)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigncwd)")
    ADD_CLASS_METHOD(SetCwd,"bool wxFileName::SetCwd()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setcwd)")
    ADD_CLASS_METHOD(AssignHomeDir,"void wxFileName::AssignHomeDir()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assignhomedir)")
    ADD_CLASS_METHOD(AssignTempFileName_1,"void wxFileName::AssignTempFileName(wxString const & prefix)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigntempfilename)")
    ADD_CLASS_METHOD(AssignTempFileName,"wxFileName::AssignTempFileName()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigntempfilename)")
/* The following types are missing: wxFile
    ADD_CLASS_METHOD(AssignTempFileName_2,"void wxFileName::AssignTempFileName(wxString const & prefix, wxFile * fileTemp)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigntempfilename)")
*/
/* The following types are missing: wxFFile
    ADD_CLASS_METHOD(AssignTempFileName_3,"void wxFileName::AssignTempFileName(wxString const & prefix, wxFFile * fileTemp)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#assigntempfilename)")
*/
    ADD_CLASS_METHOD(Mkdir,"bool wxFileName::Mkdir(int perm = 511, int flags = 0)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#mkdir)")
    ADD_CLASS_METHOD(Rmdir,"bool wxFileName::Rmdir()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#rmdir)")
    ADD_CLASS_METHOD(Normalize,"bool wxFileName::Normalize(int flags = wxPATH_NORM_ALL, wxString const & cwd = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#normalize)")
    ADD_CLASS_METHOD(MakeRelativeTo,"bool wxFileName::MakeRelativeTo(wxString const & pathBase = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#makerelativeto)")
    ADD_CLASS_METHOD(MakeAbsolute,"bool wxFileName::MakeAbsolute(wxString const & cwd = wxEmptyString, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#makeabsolute)")
    ADD_CLASS_METHOD(SameAs,"bool wxFileName::SameAs(wxFileName const & filepath, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#sameas)")
    ADD_CLASS_METHOD(IsAbsolute,"bool wxFileName::IsAbsolute(wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isabsolute)")
    ADD_CLASS_METHOD(IsRelative,"bool wxFileName::IsRelative(wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isrelative)")
    ADD_CLASS_METHOD(GetDirCount,"size_t wxFileName::GetDirCount()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getdircount)")
    ADD_CLASS_METHOD(AppendDir,"void wxFileName::AppendDir(wxString const & dir)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#appenddir)")
    ADD_CLASS_METHOD(PrependDir,"void wxFileName::PrependDir(wxString const & dir)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#prependdir)")
    ADD_CLASS_METHOD(InsertDir,"void wxFileName::InsertDir(size_t before, wxString const & dir)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#insertdir)")
    ADD_CLASS_METHOD(RemoveDir,"void wxFileName::RemoveDir(size_t pos)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#removedir)")
    ADD_CLASS_METHOD(RemoveLastDir,"void wxFileName::RemoveLastDir()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#removelastdir)")
    ADD_CLASS_METHOD(SetExt,"void wxFileName::SetExt(wxString const & ext)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setext)")
    ADD_CLASS_METHOD(ClearExt,"void wxFileName::ClearExt()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#clearext)")
    ADD_CLASS_METHOD(SetEmptyExt,"void wxFileName::SetEmptyExt()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setemptyext)")
    ADD_CLASS_METHOD(GetExt,"wxString wxFileName::GetExt()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getext)")
    ADD_CLASS_METHOD(HasExt,"bool wxFileName::HasExt()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#hasext)")
    ADD_CLASS_METHOD(SetName,"void wxFileName::SetName(wxString const & name)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setname)")
    ADD_CLASS_METHOD(GetName,"wxString wxFileName::GetName()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getname)")
    ADD_CLASS_METHOD(HasName,"bool wxFileName::HasName()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#hasname)")
    ADD_CLASS_METHOD(SetVolume,"void wxFileName::SetVolume(wxString const & volume)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setvolume)")
    ADD_CLASS_METHOD(GetVolume,"wxString wxFileName::GetVolume()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getvolume)")
    ADD_CLASS_METHOD(HasVolume,"bool wxFileName::HasVolume()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#hasvolume)")
    ADD_CLASS_METHOD(SetFullName,"void wxFileName::SetFullName(wxString const & fullname)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setfullname)")
    ADD_CLASS_METHOD(GetFullName,"wxString wxFileName::GetFullName()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getfullname)")
/* The following types are missing: wxArrayString
    ADD_CLASS_METHOD(GetDirs,"wxArrayString const & wxFileName::GetDirs()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getdirs)")
*/
    ADD_CLASS_METHOD(GetPath_1,"wxString wxFileName::GetPath(int flags = wxPATH_GET_VOLUME, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpath)")
    ADD_CLASS_METHOD(SetPath,"void wxFileName::SetPath(wxString const & path, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#setpath)")
    ADD_CLASS_METHOD(GetFullPath,"wxString wxFileName::GetFullPath(wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getfullpath)")
    ADD_CLASS_METHOD(GetShortPath,"wxString wxFileName::GetShortPath()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getshortpath)")
    ADD_CLASS_METHOD(GetLongPath,"wxString wxFileName::GetLongPath()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getlongpath)")
    ADD_CLASS_METHOD(IsDir,"bool wxFileName::IsDir()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#isdir)")
/* The following types are missing: wxULongLongNative
    ADD_CLASS_METHOD(GetSize,"wxULongLong wxFileName::GetSize()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getsize)")
*/
    ADD_CLASS_METHOD(GetHumanReadableSize,"wxString wxFileName::GetHumanReadableSize(wxString const & nullsize = wxGetTranslation(((const wchar_t*)'Not available'), 0u), int precision = 1)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#gethumanreadablesize)")
    ADD_CLASS_METHOD(GetPath,"wxFileName::GetPath()  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpath)")
    ADD_CLASS_METHOD(GetPath_2,"wxString wxFileName::GetPath(bool withSep, wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpath)")
    ADD_CLASS_METHOD(GetPathWithSep,"wxString wxFileName::GetPathWithSep(wxPathFormat format = wxPATH_NATIVE)  (http://docs.wxwidgets.org/stable/wx_wxfilename.html#getpathwithsep)")

    // Operators:
    ADD_CLASS_METHOD(__assign___1,            "wxFileName & wxFileName::operator =(wxFileName const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__assign__)")
    ADD_CLASS_METHOD(__assign__,            "wxFileName::operator =() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__assign__)")
    ADD_CLASS_METHOD(__assign___2,            "wxFileName & wxFileName::operator =(wxString const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__assign__)")
    ADD_CLASS_METHOD(__equal___1,            "bool wxFileName::operator ==(wxFileName const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal___1,            "bool wxFileName::operator !=(wxFileName const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__not_equal__)")
    ADD_CLASS_METHOD(__equal__,            "wxFileName::operator ==() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__equal__)")
    ADD_CLASS_METHOD(__equal___2,            "bool wxFileName::operator ==(wxString const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__equal__)")
    ADD_CLASS_METHOD(__not_equal__,            "wxFileName::operator !=() (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__not_equal__)")
    ADD_CLASS_METHOD(__not_equal___2,            "bool wxFileName::operator !=(wxString const & filename) (http://docs.wxwidgets.org/stable/wx_wxfilename.html#__not_equal__)")




    void AddMethods(WrapClass<wxFileName>::ptr this_ptr );
    
    /*
     * Adds the constructor and the static methods to the given context
     */
    static void AddStaticMethods( Variables::ptr& context);

};


#endif // _wrap_wxFileName_h
