/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/

#ifndef AMI_CLASS_H
#define AMI_CLASS_H

#define MAX_PARAM 20

#include <string>
#include <boost/shared_ptr.hpp>
#include "DefineClass.hpp"
#include "AmiInstructionBlock.h"

using namespace boost;


class AMIClass {

  DEFINE_CLASS(AMIClass)

private:
  AmiInstructionBlock::ptr   _body;
  std::string               _name;
  std::string               _filename;

 public:

  AMIClass()
    {
      _name     = "";
      _filename = "";
    }

  virtual ~AMIClass() 
    {
    }


  void SetName( const string& fname) { _name = fname; }

  const string& GetName() const { return _name; }

  void SetFileName( const string& fname) { _filename = fname; }

  const string& GetFileName() const { return _filename; }

  void SetBody( const AmiInstructionBlock::ptr& b) 
    { 
      //if (GB_debug)  printf("SetBody : [%s] \n",st);
      _body=b;
    }

  AmiInstructionBlock::ptr GetBody() const 
  { 
    return _body; 
  }

  const char* GetString() const 
  { 
    return  _body->GetBody().c_str(); 
  }

}; // AMIClass


#endif // AMI_CLASS_H
