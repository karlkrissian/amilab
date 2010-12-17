#!/usr/bin/python
# -*- coding: utf-8 -*-

from xml.sax import saxutils,handler
from xml.sax import make_parser
from xml.sax.handler import feature_namespaces

import sys
import shutil
import fileinput
#import os
import glob
import re
import os.path
import datetime

# configuration, containing the global variables
import config

# load command line arguments
import args

# type substitution
import typesubst

# type argument information
from argtypes import *

import utils

import findtypesvars
import findfiles
import wx_lib

import arginfo
import parse_class
import wrap_class
import parse_function
import wrap_function


  
def FindAvailableClasses():
  for dir in args.val.wrap_includes:
    utils.WarningMessage( "looking for classes in {0}".format(dir))
    # add files of type wx/wrap_wx**.h
    for name in glob.glob(dir+'/wrap_*.h'):
      #print name
      m = re.match(dir+r"wrap_(?P<class_name>\w+)\.h", name)
      if (m!=None):
        classname= m.group('class_name')
        if not(classname in config.available_classes):
          utils.WarningMessage("  adding {0}".format(classname))
          config.available_classes.append(classname)


#-------------------------------------------------------------
# Parse methods and field members
#-------------------------------------------------------------






#----------------------------------------------------------------------
#  WrapMethodTypePointer
#----------------------------------------------------------------------
def WrapMethodTypePointer(typedefname,include_file):
  # Create the handler
  #dh = FindMethodTypePointer(typedefname)

  ## Tell the parser to use our handler
  #parser.setContentHandler(dh)
  ## Parse the input
  #inputfile.seek(0)
  #parser.parse(inputfile)

  #
  #if dh.found:
  #utils.WarningMessage( "{0} id= {1}".format(typedefname,dh.typedefid))

  # Create Header File
  header_filename=args.val.outputdir+"/wrap_{0}.h".format(typedefname)
  shutil.copyfile(args.val.templatefile_dir+"/wrap_class.h.in",header_filename)
  
  # should be named available typedefs or something like this?
  # add the class to the available ones
  if typedefname not in config.available_classes:
    config.available_classes.append(typedefname)


  # now output the results:
  constructors_decl='\n'

  # Static Methods:
  staticmethods_decl='\n'

  class_decl='\n'

            
  # in place replace TEMPLATE by classname
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  for line in fileinput.FileInput(header_filename,inplace=1):
    line = line.replace("${INCLUDE_BASES}",     "")
    line = line.replace("${INHERIT_BASES}",     "")
    line = line.replace("${CONSTRUCTOR_BASES}", "")
    line = line.replace("${TEMPLATE}",          typedefname)
    line = line.replace("${INCLUDEFILE}",       include_file)
    line = line.replace("${ADD_CLASS_CONSTRUCTORS}","")
    line = line.replace("${ADD_CLASS_STATIC_METHODS}","")
    line = line.replace("${ADD_CLASS_METHOD_ALL}",class_decl)
    print line,
        

  implement_type="\n"
  implement_type += "AMI_DEFINE_WRAPPEDTYPE_NOCOPY({0});\n".format(typedefname)
  # need to implement CreateVar ...
  implement_type += "AMI_DEFINE_VARFROMSMTPTR({0});\n".format(typedefname)
  implement_type += "\n"
  implement_type += "// Implementing CreateVar for AMILabType\n"
  implement_type += "BasicVariable::ptr AMILabType<{0}>::CreateVar( {0}* val, bool nodeleter)\n".format(typedefname)
  implement_type += "{ \n"
  implement_type += "  boost::shared_ptr<{0}> obj_ptr(val,smartpointer_nodeleter<{0}>());\n".format(typedefname)
  implement_type += "  return AMILabType<{0}>::CreateVarFromSmtPtr(obj_ptr);\n".format(typedefname)
  implement_type += "}\n"
  
  # Implement CreateVar
  implement_createvar=''
  implement_createvar += "  // No variable creation for methodtype ...\n"
  implement_createvar += "  return BasicVariable::ptr();\n"

  # Create Implementation File
  impl_filename=args.val.outputdir+"/wrap_{0}.cpp".format(typedefname)
  shutil.copyfile(args.val.templatefile_dir+"wrap_class.cpp.in",impl_filename)
  
  # arguments
  impl = ""
  
  # in place replace TEMPLATE by classname
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  # in place replace ${ADD_CLASS_METHOD_ALL} by class_decl
  for line in fileinput.FileInput(impl_filename,inplace=1):
    line = line.replace("${TEMPLATE}",          typedefname)
    line = line.replace("${INCLUDES}",           "")
    line = line.replace("${IMPLEMENT_TYPE}",     implement_type)
    line = line.replace("${IMPLEMENT_CREATEVAR}",implement_createvar)
    line = line.replace("${METHODS_BASES}",     "")
    line = line.replace("${AddVar_method_all}",  "")
    line = line.replace("${AddPublicFields}",    "")
    line = line.replace("${AddPublicEnums}",    "")
    line = line.replace("${AddVar_constructor}",  "")
    line = line.replace("${AddVar_static_methods}",  "")
    line = line.replace("${WRAP_PUBLIC_METHODS}",impl)
    print line,


#----------------------------------------------------------------------
# main
#----------------------------------------------------------------------
if __name__ == '__main__':
  

    # add the user defined classes
    for cl in args.val.available_classes:
      config.available_classes.append(cl)
    FindAvailableClasses()
    #print config.available_classes

    if not(os.path.exists(args.val.outputdir)):
      os.mkdir(args.val.outputdir)

    # Create a parser
    parser = make_parser()

    if args.val.libname=="wx":
      import wx_lib
      config.libmodule = wx_lib.config
    if args.val.libname=="vtk":
      import vtk_lib
      config.libmodule = vtk_lib.config

    headerfile="{0}_includes.h".format(args.val.libname)
    
    if args.val.libname != None:
      args.val.filter = config.libmodule.get_var_filter()

    # Tell the parser we are not interested in XML namespaces
    parser.setFeature(feature_namespaces, 0)

    inputfile = open(args.val.xmlfilename,'r')
    
    # Create the handler
    ft = findtypesvars.FindTypesAndVariables()
    parser.setContentHandler(ft)
    # Parse the input
    inputfile.seek(0)
    parser.parse(inputfile)

    #print "Number of classes matching the filter : {0}".format(ft.number_of_libclasses)

    if args.val.ancestors != []:

      # 1 create dictionnary of classes to speed-up ...
      print "Creating classes dict"
      classes_dict = dict()
      for f in config.types.keys():
        if config.types[f].GetType()=="Class":
          classes_dict[f] = config.types[f].GetFullString()
      
      print "Creating ancestors"
      # 2. create list of classes
      ancestors = args.val.ancestors[:]
      for b in args.val.ancestors:
        #print "b=",b
        # find the id of the class
        for f in classes_dict.keys():
          if classes_dict[f] == b:
            # recursively add the ancestors to the list
            bases=config.types[f].GetBases()
            f_anc=[]
            if bases!=None:
              f_anc = bases.split()
            newlist=[]
            while f_anc != []:
              anc_id = f_anc.pop()
              if anc_id in classes_dict.keys():
                if  classes_dict[anc_id] not in ancestors and  \
                    classes_dict[anc_id] not in config.classes_blacklist and\
                    not parse_class.IsTemplate(classes_dict[anc_id]):
                  ancestors.append(classes_dict[anc_id])
                  newlist.append(classes_dict[anc_id])
                  bases=config.types[anc_id].GetBases()
                  if bases!=None:
                    for newanc in bases.split():
                      f_anc.append(newanc)
            #print "New ancestors of {0} are {1}".format(b,newlist)
      #print "All ancestors are   {0} ".format(ancestors)
      # write ancestors file
      print args.val.ancestors_file
      f = open (args.val.ancestors_file, "w")
      # first sort
      ancestors.sort()
      for a in ancestors:
        f.write(a+"\n")
      sys.exit(0)

    # Parse the input again, TODO: avoid 2 parses here ...
    inputfile.seek(0)
    parser.parse(inputfile)

    # Create the handler
    ff = findfiles.FindFiles()
    parser.setContentHandler(ff)
    # Parse the input
    inputfile.seek(0)
    parser.parse(inputfile)
    utils.WarningMessage( "Number of files found : {0}".format(ff.number_of_files))
    
    #for id in config.types.keys():
    #  print id,"\t",config.types[id].GetFullString()

    #include_file="wx/aui/aui.h"
    include_file=headerfile
    
    if args.val.methodpointers!=None:
      for mp in args.val.methodpointers:
        WrapMethodTypePointer(mp,include_file)
    #WrapMethodTypePointer("wxCommandEventFunction",include_file)
    #WrapMethodTypePointer("wxObjectEventFunction",include_file)
    
    config.needed_classes = args.val.classes
    # in case of update option, add all the classes found in the files
    # and that match the library filter
    if args.val.update:
      for cl in config.available_classes:
        m = re.match(args.val.filter, cl)
        if m != None:
          config.needed_classes.append(cl)
    
    number_of_newclasses = 0
    
    n=0
    nmax=args.val.max
    while (len(config.needed_classes)>0) and (n<nmax):
      #print "\n\n needed classes:", config.needed_classes, "\n\n"
      cl = config.needed_classes.pop()
      #print "Class: {0} \t usedname: {1}".format(cl,parse_class.ClassUsedName(cl))
      config.include_list = []
      config.declare_list = []
      wrap_class.WrapClass(cl,include_file,inputfile)
      config.wrapped_classes.append(cl)
      if args.val.r:
        for c in config.new_needed_classes:
          # check if templates are discarded
          if (not parse_class.IsTemplate(c)) or args.val.templates:
            if (c != cl) and (c not in config.incomplete_classes) and (c not in config.needed_classes):
              m = re.match(args.val.filter, c)
              if m != None:
                if c not in config.available_classes: number_of_newclasses = number_of_newclasses + 1
                config.needed_classes.append(c)
        config.new_needed_classes=[]
      #print "*** "
      utils.WarningMessage( "*** Wrapped Class Number: {0}".format(n))
      #print "*** "
      n = n+1

    utils.WarningMessage( "new classes: {0}".format(number_of_newclasses))
    if number_of_newclasses > 0:
      if not args.val.update:
        # Re-wrap the wrapped classes to be sure to include all the members
        for cl in config.wrapped_classes:
          config.include_list = []
          config.declare_list = []
          wrap_class.WrapClass(cl,include_file,inputfile)

    utils.WarningMessage( "Wrapped classes: {0}".format(config.wrapped_classes))
    
    # now create the library context
    if args.val.libname!=None and args.val.addwrap:
      # header
      createcontextname = args.val.outputdir+"/addwrap_{0}.h".format(args.val.libname)
      f = open (createcontextname, "w")
      # 1. write some doc
      f.write("/*\n")
      f.write(" * Automatic wrapping of '{0}' library for AMILab.\n".format(args.val.libname))
      f.write(" * File: {0}\n".format(createcontextname))
      f.write(" * Generated by the script '{0}'\n".format(sys.argv[0]))
      f.write(" * Date: '{0}'\n".format(datetime.date.today().strftime('%d-%m-%Y')))
      f.write(" */\n")
      f.write("\n")
      f.write("#ifndef _addwrap_{0}_h_\n".format(args.val.libname))
      f.write("#define _addwrap_{0}_h_\n".format(args.val.libname))
      f.write("\n")
      f.write('#include "Variables.hpp"\n')
      f.write("\n")
      f.write("void wrap_{0}_classes( Variables::ptr& context);\n".format(args.val.libname))
      f.write("\n")
      f.write("#endif // _addwrap_{0}_h_\n".format(args.val.libname))

      # implementation
      createcontextname = args.val.outputdir+"/addwrap_{0}.cpp".format(args.val.libname)
      f = open (createcontextname, "w")
      # 1. write some doc
      f.write("/*\n")
      f.write(" * Automatic wrapping of '{0}' library for AMILab.\n".format(args.val.libname))
      f.write(" * File: {0}\n".format(createcontextname))
      f.write(" * Generated by the script '{0}'\n".format(sys.argv[0]))
      f.write(" * Date: '{0}'\n".format(datetime.date.today().strftime('%d-%m-%Y')))
      f.write(" */\n")
      f.write("\n")

      # 2. write all needed includes
      # -- list the library classes (based on the filter)
      lib_classes = []
      for cl in config.available_classes:
        m = re.match(args.val.filter, cl)
        if m != None:
          lib_classes.append(cl)

      # sort alphabetically
      lib_classes.sort()

      f.write('#include "addwrap_{0}.h"\n'.format(args.val.libname))
      f.write('#include "{0}"\n'.format(include_file))
      f.write('\n')
      f.write("// Currently {0} objects (classes,structures,typedefs,...) are wrapped \n".format(len(lib_classes)))
      for cl in lib_classes:
        #f.write('#include "wrap_{0}.h"\n'.format(cl))
        f.write('extern void WrapClass{0}_AddStaticMethods( Variables::ptr&);\n'.format(cl))
      f.write("\n")

      # Wrap all classes in a context
      f.write("/*\n")
      f.write(" * Adding all the wrapped classes to the library context.\n")
      f.write(" * @param context the library context.\n")
      f.write(" */\n")
      f.write("void wrap_{0}_classes( Variables::ptr& context)\n".format(args.val.libname))
      f.write("{\n")
      f.write("\n")

      f.write("\n")
      for cl in lib_classes:
        f.write("  WrapClass{0}_AddStaticMethods( context);\n".format(cl))
        
      f.write("\n")
      
      
      f.write("\n")
      f.write( "  #define ADD_{0}_ENUMVAL(enum,name,val) \\\n".format(args.val.libname.upper()))
      f.write( "    {\\\n")
      f.write( "    BasicVariable::ptr var = AMILabType<int >::CreateVar(val);\\\n")
      f.write( "    if (var.get()) {\\\n")
      f.write( '      var->Rename(#name);\\\n')
      f.write( '       obj_##enum->GetContext()->AddVar(var,obj_##enum->GetContext());\\\n')
      f.write( "    }}\n")
      f.write("\n")
            
      # Add global enumerations
      for t in config.types.keys():
        if config.types[t].GetType()=="Enumeration":
          enumkeys=config.types[t]._values.keys()
          # check if values starts with libname to avoid adding everything (valid for wxWidgets I think), but must be changed
          if enumkeys[0].startswith(args.val.libname):
            # 1. add the context
            # 2. add the values
            # 3. set as default

            enum_usedname = config.types[t]._name.replace('.','enum')
            # Create an amiobject
            f.write( "\n")
            f.write( "  // New enumeration {0}\n".format(enum_usedname))
            f.write( "  AMIObject::ptr obj_{0}(new AMIObject);\n".format(enum_usedname))
            f.write( '  obj_{0}->SetName("{0}");\n'.format(enum_usedname))
            # add all the values
            f.write( "\n")
            for ev in enumkeys:
              f.write( "  ADD_{0}_ENUMVAL({1},{2},{3});\n".format(\
                args.val.libname.upper(),\
                enum_usedname,ev,config.types[t]._values[ev]))
              #BasicVariable::ptr var_{0} = AMILabType<int >::CreateVar({1});\n".format(ev,config.types[t]._values[ev]))
              #f.write( "  if (var_{0}.get()) ".format(ev)+'{\n')
              #f.write( '    var_{0}->Rename("{0}");\n'.format(ev))
              #f.write( '  obj_{0}->GetContext()->AddVar(var_{1},obj_{0}->GetContext());\n'.format(enum_usedname,ev))
              #f.write( "  }\n")
            f.write( "\n")
            f.write( "  // Add enum to context, and add to default contexts\n")
            f.write( "  context->AddVar<AMIObject>(obj_{0}->GetName().c_str(),obj_{0},context);\n".format(enum_usedname))
            f.write( "  context->AddDefault(obj_{0}->GetContext());\n".format(enum_usedname))
            

      f.write("  #undef ADD_{0}_ENUMVAL\n".format(args.val.libname.upper()))

      # Add variables and macros
      if args.val.libname=="wx":
        wx_lib.create_variables.CreateVariables(f,config)
        wx_lib.create_macros.CreateMacros(inputfile,f)

      f.write("}\n")
      
      f.write("\n")

    # deal with functions
    needed_functions = args.val.functions
    wrapped_functions=[]
    while len(needed_functions)>0:
      print "\n\n needed functions:", needed_functions, "\n\n"
      func = needed_functions.pop()
      print "Function: {0} ".format(func)
      config.include_list = []
      config.declare_list = []
      wrap_function.WrapFunction(func,include_file,inputfile)
      wrapped_functions.append(func)
        
