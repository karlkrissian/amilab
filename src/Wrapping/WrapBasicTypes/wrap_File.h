/**
 * C++ Interface: wrap_File
 *
 * Description: wrapping File
 *
 *
 * Author: Karl Krissian \<krissian@dis.ulpgc.es\>, (C) 2010
 *
 * Copyright: See COPYING file that comes with this distribution
 *
 **/

#ifndef _wrap_File_h_
#define _wrap_File_h_

#include "wrapfunction_class.h"
#include "wrapfunctions.hpp"
#include "Variable.hpp"
#include "paramlist.h"
#include "ami_object.h"

#include "amilab_boost.h"

//TO_STRING(File);

class WrapClass_File: public WrapClassBase
{
  DEFINE_CLASS(WrapClass_File);

  protected:
    // for nested classes
    typedef WrapClass_File::ptr _parentclass_ptr;

  public:
    /// Stores a pointer to an object of type File.
    FILE_ptr _obj;
    const FILE_ptr& GetObj() const { return _obj; }

    /// Constructor
    WrapClass_File(FILE_ptr si):  _obj(si)
    {}

    ADD_CLASS_METHOD(open,        "Open the file passed by parameter.");
    ADD_CLASS_METHOD(rewind,      "Sets the position indicator to the beginning of the file.");
    ADD_CLASS_METHOD(print,       "Write a text file that has been opened previously.");
    ADD_CLASS_METHOD(printn,      "Write a text file that has been opened previously (generates a line break).");
    ADD_CLASS_METHOD(printvar,    "Write the contents of a variable in a file.");
    ADD_CLASS_METHOD(printnvar,   "Write the contents of a variable in a file (generates a line break).");
    ADD_CLASS_METHOD(close,       "Closes the open file.");
    ADD_CLASS_METHOD(scan_float,  "Scans a float number in the given file and based on the given formatting expression.");
    ADD_CLASS_METHOD(read_float,  "Read a float number of a file.");
    ADD_CLASS_METHOD(read_string, "Read a string of a file.");

    void AddMethods(_parentclass_ptr& this_ptr )
    {
      AddVar_open(        this_ptr, "_open");
      AddVar_rewind(      this_ptr, "_rewind");
      AddVar_print(       this_ptr, "_print");
      AddVar_printn(      this_ptr, "_printn");
      AddVar_printvar(    this_ptr);
      AddVar_printnvar(   this_ptr);
      AddVar_close(       this_ptr, "_close");
      AddVar_scan_float(  this_ptr, "_scan_float");
      AddVar_read_float(  this_ptr);
      AddVar_read_string( this_ptr);
    };

};

/**
 * Create a Wrapped object around File
 * @param objectptr input smart pointer to a WrapClass_File
 * @return smart pointer to an AMIObject class
 */
AMIObject::ptr AddWrap_File(  WrapClass_File::ptr& objectptr);

/**
 * Create a Wrapped object around File
 * @param si_ptr input smart pointer to a File
 * @return smart pointer to an AMIObject class
 */
Variable<AMIObject>::ptr CreateVar_File( FILE* si);

/** Method that adds wrapping of File
 */
ADD_CLASS_FUNCTION( File, "Wrapping of File." );

#endif // _wrap_File_h