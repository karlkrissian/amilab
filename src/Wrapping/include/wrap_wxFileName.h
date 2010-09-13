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
#include "wrap_wxString.h"

#include <wx/filename.h>

AMI_DECLARE_TYPE(wxFileName)

class WrapClass_wxFileName : public WrapClass<wxFileName>
{
  DEFINE_CLASS(WrapClass_wxFileName);

  public:

    /// Constructor
    WrapClass_wxFileName(boost::shared_ptr<wxFileName> si): WrapClass<wxFileName>(si)
    {}

/*
    /// Create a variable from a standard pointer
    static Variable<AMIObject>::ptr CreateVar( wxFileName* sp);
*/

    ADD_CLASS_CONSTRUCTOR( wxFileName, "Wrapping of wxFileName (see http://docs.wxwidgets.org/)." );

    ADD_CLASS_METHOD(Assign,             "Creates the file name from the parameters.");
    ADD_CLASS_METHOD(AssignCwd,          "Makes this object refer to the current working directory on the specified volume (or current volume if volume is empty).");
    ADD_CLASS_METHOD(AssignDir,          "Sets this file name object to the given directory name. The name and extension will be empty.");
    ADD_CLASS_METHOD(AssignHomeDir,      "Sets this file name object to the home directory.");
    ADD_CLASS_METHOD(GetHomeDir,         "Returns the home directory.");
    ADD_CLASS_METHOD(AppendDir,          "Appends a directory component to the path. This component should contain a single directory name level, i.e. not contain any path or volume separators nor should it be empty, otherwise the function does nothing (and generates an assert failure in debug build).");

    ADD_CLASS_METHOD(SetVolume,          "Sets the volume specifier.");
    ADD_CLASS_METHOD(SetName,            "Sets the name part (without extension).");
    ADD_CLASS_METHOD(SetExt,             "Sets the extension of the file name.");
    ADD_CLASS_METHOD(SetEmptyExt,        "Sets the extension of the file name to be an empty extension.");
    ADD_CLASS_METHOD(SetFullName,        "The full name is the file name and extension (but without the path).");
    ADD_CLASS_METHOD(SetCwd,             "Changes the current working directory.");

    ADD_CLASS_METHOD(GetVolume,          "Returns the string containing the volume for this file name, empty if it doesn't have one or if the file system doesn't support volumes at all (for example, Unix).");
    ADD_CLASS_METHOD(GetName,            "Returns the name part of the filename (without extension).");
    ADD_CLASS_METHOD(GetExt,             "Returns the file name extension.");
    ADD_CLASS_METHOD(GetPath,            "Returns the path part of the filename (without the name or extension).");
    ADD_CLASS_METHOD(GetFullName,        "Returns the full name (including extension but excluding directories).");
    ADD_CLASS_METHOD(GetFullPath,        "Returns the full path with name and extension.");
    ADD_CLASS_METHOD(GetCwd,             "Retrieves the value of the current working directory on the specified volume.");

    ADD_CLASS_METHOD(Clear,              "Reset all components to default, uninitialized state.");
    ADD_CLASS_METHOD(ClearExt,           "Removes the extension from the file name resulting in a file name with no trailing dot.");
    ADD_CLASS_METHOD(Touch,              "Sets the access and modification times to the current moment.");
    ADD_CLASS_METHOD(Mkdir,              "Creates a directory.");
    ADD_CLASS_METHOD(Rmdir,              "Deletes a directory from the file system.");
    ADD_CLASS_METHOD(MakeAbsolute,       "Make the file name absolute.");
    ADD_CLASS_METHOD(MakeRelativeTo,     "This function tries to put this file name in a form relative to pathBase.");

    ADD_CLASS_METHOD(IsAbsolute,         "Returns true if this filename is absolute.");
    ADD_CLASS_METHOD(IsRelative,         "Returns true if this filename is not absolute.");
    ADD_CLASS_METHOD(IsCaseSensitive,    "Returns true if the file names of this type are case-sensitive");

    ADD_CLASS_METHOD(HasExt,             "Returns true if an extension is present.");
    ADD_CLASS_METHOD(HasName,            "Returns true if a name is present.");
    ADD_CLASS_METHOD(HasVolume,          "Returns true if a volume specifier is present.");
    ADD_CLASS_METHOD(DirExists,          "Returns true if the directory with this name exists.");
    ADD_CLASS_METHOD(FileExists,         "Returns true if the file with this name exists.");

    ADD_CLASS_METHOD(IsDir,              "Returns true if this object represents a directory, false otherwise. Note that this method doesn't test whether the directory or file really exists, you should use DirExists() or FileExists() for this.");
    ADD_CLASS_METHOD(IsDirReadable,      "Returns true if the directory component of this instance is an existing directory and this process has read permissions on it. Read permissions on a directory mean that you can list the directory contents but it doesn't imply that you have read permissions on the files contained.");
    ADD_CLASS_METHOD(IsDirWritable,      "Returns true if the directory component of this instance is an existing directory and this process has write permissions on it. Write permissions on a directory mean that you can create new files in the directory.");
    ADD_CLASS_METHOD(IsFileExecutable,   "Returns true if a file with this name exists and if this process has execute permissions on it.");
    ADD_CLASS_METHOD(IsFileReadable,     "Returns true if a file with this name exists and if this process has read permissions on it.");
    ADD_CLASS_METHOD(IsFileWritable,     "Returns true if a file with this name exists and if this process has write permissions on it.");
    ADD_CLASS_METHOD(IsOk,               "Returns true if the filename is valid, false if it is not initialized yet.");

    ADD_CLASS_METHOD(SameAs,             "Compares the filename.");

    ADD_CLASS_METHOD(copy,               "wxFileName copy constructor.");
    ADD_CLASS_METHOD(assign_operator,    "Operator =, copy assignment.");
    ADD_CLASS_METHOD(equal,              "Operator ==, compare a wxFileName objects with the current.");
    ADD_CLASS_METHOD(not_equal,          "Operator !=, compare a wxFileName objects with the current.");

    void AddMethods( WrapClass<wxFileName>::ptr this_ptr )
    {
      AddVar_AppendDir(          this_ptr);
      AddVar_Assign(             this_ptr);
      AddVar_AssignCwd(          this_ptr);
      AddVar_AssignDir(          this_ptr);
      AddVar_AssignHomeDir(      this_ptr);

      AddVar_GetHomeDir(         this_ptr);

      AddVar_SetEmptyExt(        this_ptr);
      AddVar_SetExt(             this_ptr);
      AddVar_SetFullName(        this_ptr);
      AddVar_SetName(            this_ptr, "_SetName");
      AddVar_SetVolume(          this_ptr);
      AddVar_SetCwd(             this_ptr);
      AddVar_GetExt(             this_ptr);
      AddVar_GetFullName(        this_ptr);
      AddVar_GetFullPath(        this_ptr);
      AddVar_GetCwd(             this_ptr);
      AddVar_GetName(            this_ptr, "_GetName");
      AddVar_GetPath(            this_ptr);

      AddVar_GetVolume(          this_ptr);
      AddVar_Clear(              this_ptr);
      AddVar_ClearExt(           this_ptr);
      AddVar_HasExt(             this_ptr);
      AddVar_HasName(            this_ptr);
      AddVar_HasVolume(          this_ptr);
      AddVar_DirExists(          this_ptr);
      AddVar_FileExists(         this_ptr, "_FileExists");
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
      AddVar_MakeAbsolute(       this_ptr);
      AddVar_MakeRelativeTo(     this_ptr);
      AddVar_Mkdir(              this_ptr);
      AddVar_Rmdir(              this_ptr);
      AddVar_SameAs(             this_ptr);

      // Operators
      AddVar_copy(               this_ptr);
      AddVar_assign_operator(    this_ptr);
      AddVar_equal(              this_ptr);
      AddVar_not_equal(          this_ptr);
    }

};

#endif // _wrap_wxFileName_h_
