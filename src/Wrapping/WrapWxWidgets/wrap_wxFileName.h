//
// C++ Interface: wrap_wxFileName
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _wrap_wxFileName_h_
#define _wrap_wxFileName_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include <wx/filename.h>


class WrapClass_wxFileName : public WrapClassBase
{
  DEFINE_CLASS(WrapClass_wxFileName);

  protected:
    // for nested classes
    typedef WrapClass_wxFileName::ptr _parentclass_ptr;
    typedef wxFileName _obj_type;

  public:
    boost::shared_ptr<_obj_type> _obj;
    const boost::shared_ptr<_obj_type>& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_wxFileName(boost::shared_ptr<wxFileName> si): _obj(si)
    {}

    ADD_CLASS_METHOD(AppendDir,          "Appends a directory component to the path. This component should contain a single directory name level, i.e. not contain any path or volume separators nor should it be empty, otherwise the function does nothing (and generates an assert failure in debug build).");
    ADD_CLASS_METHOD(Assign,             "Creates the file name from the parameters.");
    ADD_CLASS_METHOD(AssignCwd,          "Makes this object refer to the current working directory on the specified volume (or current volume if volume is empty).");
    ADD_CLASS_METHOD(AssignDir,          "Sets this file name object to the given directory name.");
    ADD_CLASS_METHOD(AssignHomeDir,      "Sets this file name object to the home directory.");
    ADD_CLASS_METHOD(AssignTempFileName, "Create a temporary file and sets this object to the name of the file. If a temporary file couldn't be created, the object is put into an invalid state.");
    ADD_CLASS_METHOD(GetHomeDir,         "Returns the home directory.");
    ADD_CLASS_METHOD(GetTempDir,         "Returns the directory used for temporary files..");
    ADD_CLASS_METHOD(SetEmptyExt,        "Sets the extension of the file name to be an empty extension.");
    ADD_CLASS_METHOD(SetExt,             "Sets the extension of the file name.");
    ADD_CLASS_METHOD(SetFullName,        "The full name is the file name and extension (but without the path).");
    ADD_CLASS_METHOD(SetName,            "Sets the name part (without extension).");
    ADD_CLASS_METHOD(SetPath,            "Sets the full path.");
    ADD_CLASS_METHOD(SetVolume,          "Sets the volume specifier.");
    ADD_CLASS_METHOD(SetCwd,             "Changes the current working directory.");
    ADD_CLASS_METHOD(GetExt,             "Returns the file name extension.");
    ADD_CLASS_METHOD(GetFullName,        "Returns the full name (including extension but excluding directories).");
    ADD_CLASS_METHOD(GetFullPath,        "Returns the full path with name and extension.");
    ADD_CLASS_METHOD(GetCwd,             "Retrieves the value of the current working directory on the specified volume.");
    ADD_CLASS_METHOD(GetName,            "Returns the name part of the filename (without extension).");
    ADD_CLASS_METHOD(GetPath,            "Returns the path part of the filename (without the name or extension).");
    ADD_CLASS_METHOD(GetShortPath,       "Return the short form of the path (returns identity on non-Windows platforms).");
    ADD_CLASS_METHOD(GetVolume,          "Returns the string containing the volume for this file name, empty if it doesn't have one or if the file system doesn't support volumes at all (for example, Unix).");
    ADD_CLASS_METHOD(GetPathSeparator,   "Returns the usually used path separator for this format.");
    ADD_CLASS_METHOD(GetPathSeparators,  "Returns the string containing all the path separators for this format.");
    ADD_CLASS_METHOD(GetPathTerminators, "Returns the string of characters which may terminate the path part.");
    ADD_CLASS_METHOD(GetVolumeSeparator, "Returns the string separating the volume from the path for this format.");
    ADD_CLASS_METHOD(ReplaceHomeDir,     "Replaces, if present in the path, the home directory for the given user (see wxGetHomeDir) with a tilde (~).");
    ADD_CLASS_METHOD(Clear,              "Reset all components to default, uninitialized state.");
    ADD_CLASS_METHOD(ClearExt,           "Removes the extension from the file name resulting in a file name with no trailing dot.");
    ADD_CLASS_METHOD(HasExt,             "Returns true if an extension is present.");
    ADD_CLASS_METHOD(HasName,            "Returns true if a name is present.");
    ADD_CLASS_METHOD(HasVolume,          "Returns true if a volume specifier is present.");
    ADD_CLASS_METHOD(DirExists,          "Returns true if the directory with this name exists.");
    ADD_CLASS_METHOD(FileExists,         "Returns true if the file with this name exists.");
    ADD_CLASS_METHOD(IsAbsolute,         "Returns true if this filename is absolute.");
    ADD_CLASS_METHOD(IsDir,              "Returns true if this object represents a directory, false otherwise. Note that this method doesn't test whether the directory or file really exists, you should use DirExists() or FileExists() for this.");
    ADD_CLASS_METHOD(IsDirReadable,      "Returns true if the directory component of this instance is an existing directory and this process has read permissions on it.");
    ADD_CLASS_METHOD(IsDirWritable,      "Returns true if the directory component of this instance is an existing directory and this process has write permissions on it.");
    ADD_CLASS_METHOD(IsFileExecutable,   "Returns true if a file with this name exists and if this process has execute permissions on it.");
    ADD_CLASS_METHOD(IsFileReadable,     "Returns true if a file with this name exists and if this process has read permissions on it.");
    ADD_CLASS_METHOD(IsFileWritable,     "Returns true if a file with this name exists and if this process has write permissions on it.");
    ADD_CLASS_METHOD(IsOk,               "Returns true if the filename is valid, false if it is not initialized yet.");
    ADD_CLASS_METHOD(IsRelative,         "Returns true if this filename is not absolute.");
    ADD_CLASS_METHOD(IsCaseSensitive,    "Returns true if the file names of this type are case-sensitive");
    ADD_CLASS_METHOD(Touch,              "Sets the access and modification times to the current moment.");
    ADD_CLASS_METHOD(ReplaceEnvVariable, "If the path contains the value of the environment variable named envname then this function replaces it with the string obtained from wxString::Format(replacementFmtString, value_of_envname_variable).");
    ADD_CLASS_METHOD(MakeAbsolute,       "Make the file name absolute.");
    ADD_CLASS_METHOD(MakeRelativeTo,     "This function tries to put this file name in a form relative to pathBase.");
    ADD_CLASS_METHOD(Mkdir,              "Creates a directory.");
    ADD_CLASS_METHOD(Rmdir,              "Deletes the specified directory from the file system.");
    ADD_CLASS_METHOD(copy,               "wxFileName copy constructor.");
    ADD_CLASS_METHOD(assign_operator,    "Operator =, copy assignment.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      AddVar_AppendDir(          this_ptr);
      AddVar_Assign(             this_ptr);
      AddVar_AssignCwd(          this_ptr);
      AddVar_AssignDir(          this_ptr);
      AddVar_AssignHomeDir(      this_ptr);
      AddVar_AssignTempFileName( this_ptr);
      AddVar_GetHomeDir(         this_ptr);
      AddVar_GetTempDir(         this_ptr);
      AddVar_SetEmptyExt(        this_ptr);
      AddVar_SetExt(             this_ptr);
      AddVar_SetFullName(        this_ptr);
      AddVar_SetName(            this_ptr);
      AddVar_SetPath(            this_ptr);
      AddVar_SetVolume(          this_ptr);
      AddVar_SetCwd(             this_ptr);
      AddVar_GetExt(             this_ptr);
      AddVar_GetFullName(        this_ptr);
      AddVar_GetFullPath(        this_ptr);
      AddVar_GetCwd(             this_ptr);
      AddVar_GetName(            this_ptr);
      AddVar_GetPath(            this_ptr);
      AddVar_GetShortPath(       this_ptr);
      AddVar_GetVolume(          this_ptr);
      AddVar_GetPathSeparators(  this_ptr);
      AddVar_GetPathTerminators( this_ptr);
      AddVar_GetVolumeSeparator( this_ptr);
      AddVar_ReplaceHomeDir(     this_ptr);
      AddVar_Clear(              this_ptr);
      AddVar_ClearExt(           this_ptr);
      AddVar_HasExt(             this_ptr);
      AddVar_HasName(            this_ptr);
      AddVar_HasVolume(          this_ptr);
      AddVar_DirExists(          this_ptr);
      AddVar_FileExists(         this_ptr);
      AddVar_IsAbsolute(         this_ptr);
      AddVar_IsDir(              this_ptr);
      AddVar_IsDirReadable(      this_ptr);
      AddVar_IsDirWritable(      this_ptr);
      AddVar_IsFileExecutable(   this_ptr);
      AddVar_IsFileReadable(     this_ptr);
      AddVar_IsFileWritable(     this_ptr);
      AddVar_IsOk(               this_ptr);
      AddVar_IsRelative(         this_ptr);
      AddVar_IsCaseSensitive(    this_ptr);
      AddVar_Touch(              this_ptr);
      AddVar_ReplaceEnvVariable( this_ptr);
      AddVar_MakeAbsolute(       this_ptr);
      AddVar_MakeRelativeTo(     this_ptr);
      AddVar_Mkdir(              this_ptr);
      AddVar_Rmdir(              this_ptr);

      // Operators
      AddVar_copy(               this_ptr);
      AddVar_assign_operator(    this_ptr);
    }

};

/**
 * Create a Wrapped object around wxFileName
 * @param objectptr input smart pointer to a WrapClass_wxFileName
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_wxFileName(  WrapClass_wxFileName::ptr& objectptr);

/**
 * Create a Wrapped object around wxFileName
 * @param si_ptr input smart pointer to a wxFileName
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_wxFileName( wxFileName* si);

/** Method that adds wrapping of wxFileName
 */
ADD_CLASS_FUNCTION( wxFileName, "Wrapping of wxFileName (see http://docs.wxwidgets.org/)." );

#endif // _wrap_wxFileName_h_
