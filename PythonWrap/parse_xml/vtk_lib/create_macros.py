# -*- coding: utf-8 -*-
#
# Create macro variables
#

from xml.sax import saxutils,handler
from xml.sax import make_parser
import re
# load command line arguments
import args

import logging

# 1. find the event.h file

# 2. register event macros

# 3. add event macros


def CreateHeaderFileMacros(inputfilename_macros,outputfile):
  res = ""
  headerfile = open(inputfilename_macros,"r")
  found_macros=[]
  for line in headerfile:
    # limited to macros of type #define VTKXXXX 0x9999 for the moment
    findmacro = re.match(r"^\s*#define\s+(VTK[_0-9a-zA-Z]+)\s*((0x[0-9]+)|([0-9]+))\s(//.*)*$",line)
    if (findmacro!=None):
      found_macros.append(findmacro.group(1))
      #print "Found macro : ", findmacro.group(1), " = ", findmacro.group(2)
    
  if len(found_macros)>0:
    # add all the values
    res += "\n"
    res += "  // MACROS from file {0}.h\n".format(inputfilename_macros)
    for m in found_macros:
      logging.debug( "processing macro {0}".format(m))
      res += "  #ifdef {0}\n".format(m)
      res += "    ADD_{0}_MACRO({1});\n".format(args.val.libname.upper(), m)
      res += "  #endif\n"
    res += "\n"
  else:
    res += "  // No macro found in {0}\n".format(inputfilename_macros)
  return res


def CreateMacros(inputfilename_macros,outputfile):
  logging.debug( "**** CreateMacros ****")
  wrapped_macros=""
  wrapped_macros += CreateHeaderFileMacros(inputfilename_macros,outputfile)

  if wrapped_macros!="":
    # Create the macros context
    outputfile.write("\n")
    outputfile.write( "  #define ADD_{0}_MACRO(name) \\\n".format(args.val.libname.upper()))
    outputfile.write( "    {\\\n")
    outputfile.write( "      BasicVariable::ptr var = AMILabType<int >::CreateVar(name);\\\n")
    outputfile.write( "      if (var.get()) {\\\n")
    outputfile.write( '        var->Rename(#name);\\\n')
    outputfile.write( '        macros_context->AddVar(var,macros_context);\\\n')
    outputfile.write( "      }\\\n")
    outputfile.write( "    }\\\n")
    outputfile.write("\n")

    # Create an amiobject
    outputfile.write( "\n")
    outputfile.write( "  // Macros context\n")
    outputfile.write( "  AMIObject::ptr obj_macros(new AMIObject);\n")
    outputfile.write( '  obj_macros->SetName("_vtk_macros");\n')
    outputfile.write( '  Variables::ptr macros_context = obj_macros->GetContext();\n')

    outputfile.write( wrapped_macros)
    
    outputfile.write( "  // Add macros to context, and add to default contexts\n")
    outputfile.write( "  context->AddVar<AMIObject>(obj_macros->GetName().c_str(),obj_macros,context);\n")
    outputfile.write( "  context->AddDefault(macros_context);\n")
    
    outputfile.write("  #undef ADD_{0}_MACRO\n".format(args.val.libname.upper()))
