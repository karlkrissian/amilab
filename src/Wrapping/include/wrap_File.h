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

AMI_DECLARE_TYPE(FILE);

class WrapClass_File: public WrapClass<FILE>
{
  DEFINE_CLASS(WrapClass_File);

  public:

    /// Constructor
    WrapClass_File(FILE_ptr si): WrapClass<FILE>(si) { }

    /// Constructor const
    WrapClass_File(boost::shared_ptr<FILE const> si, bool): 
      WrapClass<FILE>(si,true) 
    { }

    /// Wrapping of the constructor
    ADD_CLASS_CONSTRUCTOR( File, "Wrapping of File." );

    // wrapping of other methods
    ADD_CLASS_METHOD(rewind,      "Sets the position indicator to the beginning of the file.");
    ADD_CLASS_METHOD(print,       "Write the contents of a variable in a file.");
    ADD_CLASS_METHOD(printn,      "Write the contents of a variable in a file (generates a line break).");
    ADD_CLASS_METHOD(close,       "Closes the open file.");
    ADD_CLASS_METHOD(scan_float,  "Scans a float number in the given file and based on the given formatting expression.");
    ADD_CLASS_METHOD(read,        "Reads a float of a string from a file.");
    ADD_CLASS_METHOD(read_float,  "Read a float number from a file.");
    ADD_CLASS_METHOD(read_string, "Read a string from a file.");
    ADD_CLASS_METHOD(read_line,   "Read a line from a file.");
    ADD_CLASS_METHOD(eof,         "Check End-of-File.");

    void AddMethods(WrapClass<FILE>::ptr this_ptr )
    {
      AddVar_rewind(      this_ptr);
      AddVar_print(       this_ptr, "_print");
      AddVar_printn(      this_ptr, "_printn");
      AddVar_close(       this_ptr);
      AddVar_scan_float(  this_ptr);
      AddVar_read(        this_ptr);
      AddVar_read_float(  this_ptr);
      AddVar_read_string( this_ptr);
      AddVar_read_line(   this_ptr);
      AddVar_eof(         this_ptr);
    };

};


#endif // _wrap_File_h